#include "NexusConsoleGui.h"


using namespace NSLIB_CONSOLE;


NexusConsoleGui::NexusConsoleGui ( QWidget *parent ) : QPlainTextEdit ( parent ) {

  QFont font = this->consoleFormat.font ();
  font.setFamily ( "Liberation Mono" );
  font.setBold ( false );
  font.setItalic ( false );
  font.setPointSize ( 10 );
  this->consoleFormat.setFont ( font );
  this->consoleFormat.setForeground ( QBrush ( QColor ( 255, 255, 255 ) ) );  // Color blanco

  this->historyIndex = 0;
  this->consolePrompt.reset ( new NexusConsolePrompt () );
  this->initialPrompt ();
  // connect ( this, &NexusConsoleGui::textChanged, this, &NexusConsoleGui::updateHistory );
  // connect ( NexusConsole::getInstance (), &NexusConsole::processFinished, this, &NexusConsoleGui::processFinishedSlot );
}

void NexusConsoleGui::processFinishedSlot ( int exitCode, QProcess::ExitStatus exitStatus ) {

  Q_UNUSED ( exitCode )
  if ( exitStatus == QProcess::NormalExit ) {

    this->updateOutputText ( NexusConsole::getInstance ()->getOutputShell () );

  } else {

    this->updateOutputText ( NexusConsole::getInstance ()->getOutputShellError () );
  }
}

void NexusConsoleGui::keyPressEvent ( QKeyEvent *event ) {

  if ( event->key () == Qt::Key_Backspace ) {

    this->handleBackspaceKey ( event );

  } else if ( event->key () == Qt::Key_Enter || event->key () == Qt::Key_Return ) {

    this->handleEnterKey ();
    this->updatePrompt ();

  } else if ( event->key () == Qt::Key_Up ) {

    this->handleUpArrowKey ();

  } else if ( event->key () == Qt::Key_Down ) {

    this->handleDownArrowKey ();

  } else if ( event->modifiers () == ( Qt::ControlModifier | Qt::ShiftModifier ) && event->key () == Qt::Key_C ) {

    this->handleCopy ();

  } else if ( event->modifiers () == ( Qt::ControlModifier | Qt::ShiftModifier ) && event->key () == Qt::Key_V ) {

    this->handlePaste ();

  } else {

    QPlainTextEdit::keyPressEvent ( event );
  }
}

QTextCursor NexusConsoleGui::cleanCurrentLine () {

  QTextCursor cursor = this->textCursor ();
  cursor.movePosition ( QTextCursor::StartOfBlock, QTextCursor::KeepAnchor );
  cursor.removeSelectedText ();
  return cursor;
  }

void NexusConsoleGui::getCommandAndArguments () {

  const QString &commandLine = this->getCommandLine ();
  QStringList commandLineSplit = commandLine.split ( " " );
  if ( !commandLineSplit.isEmpty () ) {

    this->command = commandLineSplit.first ();
    commandLineSplit.removeFirst ();
    this->arguments = commandLineSplit;
  }
}

QString NexusConsoleGui::getCommandLine () {

  QTextCursor cursor = this->textCursor ();
  QString currentLine = cursor.block ().text ();
  return currentLine.mid ( this->consolePrompt->getPrompt ().length () ).trimmed ();
}

void NexusConsoleGui::handleBackspaceKey ( QKeyEvent *event ) {

  QTextCursor cursor = this->textCursor ();
  int promptLength = this->consolePrompt.data ()->getPrompt ().length ();
  int lineStart = cursor.positionInBlock () - promptLength;
  if ( lineStart > 0 ) {

    QPlainTextEdit::keyPressEvent ( event );
  }
  this->updateConsoleFormat ();
}

void NexusConsoleGui::handleCopy () {

  QClipboard *clipboard = QApplication::clipboard ();
  clipboard->setText ( this->textCursor ().selectedText () );
}

void NexusConsoleGui::handleEnterKey () {

  const QString &commandLine = this->getCommandLine ();
  if ( !commandLine.isEmpty () ) {

    this->updateHistory ();
    this->getCommandAndArguments ();
    NexusConsole::getInstance ()->execute ( this->command, this->arguments );
    if ( NexusConsole::getInstance ()->getError () == QProcess::UnknownError ) {

      this->updateOutputText ( NexusConsole::getInstance ()->getOutputShell () );

    } else {

      this->updateOutputText ( NexusConsole::getInstance ()->getOutputShellError () );
    }
  }
}

void NexusConsoleGui::handleUpArrowKey () {

  if ( this->historyIndex > 0 && this->historyIndex <= this->commandHistory.size () ) {

    this->historyIndex--;
    QTextCursor cursor = this->cleanCurrentLine ();
    this->getPrompt ( cursor );
    this->updateConsoleFormat ();
    cursor.mergeCharFormat ( this->consoleFormat );
    cursor.insertText ( this->commandHistory.at ( this->historyIndex ) );
  }
}

void NexusConsoleGui::handleDownArrowKey () {

  if ( this->historyIndex >= 0 && this->historyIndex < this->commandHistory.size () ) {

    this->historyIndex++;
    QTextCursor cursor = this->cleanCurrentLine ();
    this->getPrompt ( cursor );
    this->updateConsoleFormat ();
    cursor.mergeCharFormat ( this->consoleFormat );
    if ( this->historyIndex != this->commandHistory.size () ) {

      cursor.insertText ( this->commandHistory.at ( this->historyIndex ) );
    }
  }
}

void NexusConsoleGui::handlePaste () {

  QClipboard *clipboard = QApplication::clipboard ();
  this->insertPlainText ( clipboard->text () );
}

void NexusConsoleGui::initialPrompt () {

  this->getPrompt ( this->textCursor () );
  this->updateConsoleFormat ();
}

void NexusConsoleGui::updateHistory () {

  const QString &command = this->getCommandLine ();
  if ( !command.isEmpty () && ( this->commandHistory.isEmpty () || this->commandHistory.last () != command ) ) {

    this->commandHistory.append ( command );
    this->historyIndex = this->commandHistory.size ();
  }
}

void NexusConsoleGui::updateOutputText ( const QString &outputText ) {

  QTextCursor cursor = this->textCursor ();
  cursor.movePosition ( QTextCursor::End );
  cursor.insertText ( "\n" );
  cursor.insertText ( outputText );
  this->setTextCursor ( cursor );
  this->verticalScrollBar ()->setValue ( this->verticalScrollBar ()->maximum () );
}

void NexusConsoleGui::updatePrompt () {

  QTextCursor cursor = this->textCursor ();
  cursor.insertText ( "\n" );
  this->getPrompt ( cursor );
  this->updateConsoleFormat ();
}

void NexusConsoleGui::getPrompt ( QTextCursor cursor ) {

  cursor.movePosition ( QTextCursor::End );
  cursor.insertText ( this->consolePrompt.data ()->getPrompt (), this->consolePrompt.data ()->getFormat () );
  this->moveCursor ( QTextCursor::End );


  // QProcess userProcess;
  // userProcess.start ( "whoami" );
  // userProcess.waitForFinished ();
  // QString userName = userProcess.readAllStandardOutput ().trimmed ();
  // QString hostName = QSysInfo::machineHostName ();
  // QProcess uidProcess;
  // uidProcess.start ( "id", QStringList () << "-u" );
  // uidProcess.waitForFinished ();
  // QString uid = uidProcess.readAllStandardOutput ().trimmed ();
  // QString promptSymbol = ( uid == "0" ) ? "#" : "$";
  // QString prompt = QString ( "%1@%2:%3 " ).arg ( userName, hostName, promptSymbol );
  // // QString prompt = QString("<span style=\"color:#00ff00; font-weight:bold;\">%1@%2:</span><span style=\"color:#ffffff; font-weight:bold;\">%3</span> ")
  // //                         .arg(userName, hostName, promptSymbol);

  // // Aplicar estilos al prompt
  // QTextCharFormat promptFormat;
  // promptFormat.setForeground ( QColor ( "#00ff00" ) );  // Color verde
  // promptFormat.setFontWeight ( QFont::Bold );

  // // Obtener el cursor
  // QTextCursor cursor = this->textCursor ();

  // // Mover el cursor al final del texto actual
  // cursor.movePosition ( QTextCursor::End );

  // // Agregar el texto del prompt con los estilos
  // cursor.insertText ( prompt, promptFormat );

  // // Establecer el nuevo cursor
  // this->setTextCursor ( cursor );

  // this->prompt = prompt;
  // //this->appendPlainText ( this->prompt );
    // this->moveCursor ( QTextCursor::End );
}

void NexusConsoleGui::updateConsoleFormat () {

  this->setCurrentCharFormat ( this->consoleFormat );
}
