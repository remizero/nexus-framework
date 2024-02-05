#ifndef NEXUSCONSOLEPROMPT_H
#define NEXUSCONSOLEPROMPT_H

// Librerías Internas
// Internal Libraries
#include "Console_global.h"
#include "NexusConsole.h"

// Librerías Externas
// External Libraries
#include "creational/Singleton.h"
#include "loggersystem/Logger.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QBrush>
#include <QColor>
#include <QFont>
#include <QObject>
#include <QProcess>
#include <QString>
#include <QTextCharFormat>

// Librerías C++
// C++ Libraries


namespace NS_LEVEL_1 {

  namespace NS_LEVEL_2 {

    namespace NS_NEXUS {

      namespace NS_ESSENTIALS {

        namespace NS_CONSOLE {

          class CONSOLE_EXPORT NexusConsolePrompt : QObject {

              Q_OBJECT

            public :
              NexusConsolePrompt ( QObject *parent = nullptr );

              QTextCharFormat getFormat () const;
              QString getPrompt () const;

            public slots :
              void updatePrompt ( const QString &newPrompt );

            signals :
                void promptUpdated ( const QString &newPrompt );

            private :
                      QString prompt;
              QTextCharFormat promptFormat;
              void initialPrompt ();
          };
        }
      }
    }
  }
}

#endif // NEXUSCONSOLEPROMPT_H
