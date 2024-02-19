#include "NexusConsolePrompt.h"


using namespace NSLIB_CONSOLE;


NexusConsolePrompt::NexusConsolePrompt ( QObject *parent ) : QObject ( parent ) {

  QFont font = this->promptFormat.font ();
  font.setFamily ( "Liberation Mono" );
  font.setBold ( true );
  font.setItalic ( false );
  font.setPointSize ( 10 );
  this->promptFormat.setFont ( font );
  this->promptFormat.setForeground ( QBrush ( QColor ( 0, 255, 0 ) ) );
  // this->initialPrompt ();
  this->prompt = "user_name@pc_server:$ ";
}

QTextCharFormat NexusConsolePrompt::getFormat () const {

  return this->promptFormat;
}

QString NexusConsolePrompt::getPrompt () const {

  return this->prompt;
}

void NexusConsolePrompt::initialPrompt () {

  QProcess userProcess;
  userProcess.start ( "whoami" );
  userProcess.waitForFinished ();
  QString userName = userProcess.readAllStandardOutput ().trimmed ();
  QString hostName = QSysInfo::machineHostName ();
  QProcess uidProcess;
  uidProcess.start ( "id", QStringList () << "-u" );
  uidProcess.waitForFinished ();
  QString uid = uidProcess.readAllStandardOutput ().trimmed ();
  QString promptSymbol = ( uid == "0" ) ? "#" : "$";
  this->prompt = QString ( "%1@%2:%3 " ).arg ( userName, hostName, promptSymbol );
  // QString prompt = QString("<span style=\"color:#00ff00; font-weight:bold;\">%1@%2:</span><span style=\"color:#ffffff; font-weight:bold;\">%3</span> ")
  //                         .arg(userName, hostName, promptSymbol);
}

void NexusConsolePrompt::updatePrompt ( const QString &newPrompt ) {

  if ( this->prompt != newPrompt ) {

    this->prompt = newPrompt;
    emit promptUpdated ( this->prompt );
  }
}
