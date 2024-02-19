#ifndef NEXUSCONSOLEGUI_H
#define NEXUSCONSOLEGUI_H

// Librerías Internas
// Internal Libraries
#include "Console_global.h"
#include "NexusConsole.h"
#include "NexusConsolePrompt.h"

// Librerías Externas
// External Libraries
#include "creational/Singleton.h"
#include "loggersystem/Logger.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QApplication>
#include <QBrush>
#include <QClipboard>
#include <QColor>
#include <QFont>
#include <QKeyEvent>
#include <QObject>
#include <QPlainTextEdit>
#include <QProcess>
#include <QScrollBar>
#include <QScopedPointer>
#include <QStringList>
#include <QTextBlock>
#include <QTextCharFormat>
#include <QTextCursor>
#include <QWidget>

// Librerías C++
// C++ Libraries


  namespace NS_VGVGS {

    namespace NS_NEXUS {

      namespace NS_ESSENTIALS {

        namespace NS_CONSOLE {

          class CONSOLE_EXPORT NexusConsoleGui : public QPlainTextEdit {

              Q_OBJECT

            public :
              NexusConsoleGui ( QWidget *parent = nullptr );

            public slots :
              void processFinishedSlot ( int exitCode, QProcess::ExitStatus exitStatus );

            protected :
              void keyPressEvent( QKeyEvent *event ) override;

            private :
                                     QStringList arguments;
                                         QString command;
                                     QStringList commandHistory;
              QScopedPointer<NexusConsolePrompt> consolePrompt;
                                 QTextCharFormat consoleFormat;
                                             int historyIndex;
              QTextCursor cleanCurrentLine ();
              void getCommandAndArguments ();
              QString getCommandLine ();
              void getPrompt ( QTextCursor cursor );
              void handleBackspaceKey ( QKeyEvent *event );
              void handleCopy ();
              void handleEnterKey ();
              void handleUpArrowKey ();
              void handleDownArrowKey ();
              void handlePaste ();
              void initialPrompt ();
              void updateHistory ();
              void updateOutputText ( const QString &outputText );
              void updatePrompt ();
              void updateConsoleFormat ();
          };
        }
      }
    }
  }

#endif // NEXUSCONSOLEGUI_H
