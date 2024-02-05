#ifndef NEXUSCONSOLE_H
#define NEXUSCONSOLE_H

// Librerías Internas
// Internal Libraries
#include "Console_global.h"

// Librerías Externas
// External Libraries
#include "creational/Singleton.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QObject>
#include <QProcess>

// Librerías C++
// C++ Libraries


namespace NS_LEVEL_1 {

  namespace NS_LEVEL_2 {

    namespace NS_NEXUS {
      
      namespace NS_ESSENTIALS {
        
        namespace NS_CONSOLE {

          class CONSOLE_EXPORT NexusConsole : public QObject, public NSLIB_PATTERNIFY::Singleton<NexusConsole> {

              Q_OBJECT

            public :
              void execute ( QString command, QStringList arguments );
              QProcess::ProcessError getError () const;
              QString getOutputShell () const;
              QString getOutputShellError () const;

            signals :
                void processFinished ( int exitCode, QProcess::ExitStatus exitStatus );

            private slots :
              void catchError ();
              void catchOutput ();
              void processFinishedSlot ( int exitCode, QProcess::ExitStatus exitStatus );

            private :
              void clear ();
              QProcess *exec;
               QString outputShell;
               QString outputShellError;
              NexusConsole ( QObject *parent = nullptr );
              friend class NSLIB_PATTERNIFY::Singleton<NexusConsole>;
          };
        }
      }
    }
  }
}

#endif // NEXUSCONSOLE_H
