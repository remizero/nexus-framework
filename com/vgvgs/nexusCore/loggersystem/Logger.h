#ifndef LOGGER_H
#define LOGGER_H

// Librerías Internas
// Internal Libraries
#include "Core_global.h"
#include "appsystem/AppManager.h"
#include "appsystem/AppPaths.h"
#include "Exception.h"

// Librerías Externas
// External Libraries
#include "Files.h"
#include "creational/Singleton.h"

// Librerías de terceros
// third-party Library
// #include "SmtpMime"

// Librerías Qt
// Qt Libraries
#include <QDateTime>
#include <QDebug>
#include <QFile>
#include <QFileInfo>
#include <QIODeviceBase>
#include <QMessageLogContext>
#include <QScopedPointer>
#include <QString>
#include <QStringLiteral>
#include <QTextStream>
#include <QtWidgets/QMessageBox>

// Librerías C++
// C++ Libraries


namespace NS_LEVEL_1 {

  namespace NS_LEVEL_2 {

    namespace NS_NEXUS {

      namespace NS_CORE {

        class CORE_EXPORT Logger : public QObject, public NSLIB_PATTERNIFY::Singleton<Logger> {

            Q_OBJECT

          public :

            enum LogOutput {

              Standard,
              File
            };
            Q_ENUM ( LogOutput )

            virtual ~Logger ();
            void exception ( const Exception &exception );
            void init ( Logger::LogOutput output = File, QString outputFormat = STR(FILE_OUTPUT_QT_MESSAGE_PATTERN) );
            void installMessageHandler ();
            bool isGuiApp ();
            void reinstallMessageHandler ();
            void setGuiApp ( bool guiApp );
            void uninstallMessageHandler ();

          private :
                             QString filePath;
                                bool guiApp;
                             QString outputFormat;
             QIODeviceBase::OpenMode openMode;
                   Logger::LogOutput output;
            QScopedPointer < QFile > logFile;

            Logger ();
            friend class NSLIB_PATTERNIFY::Singleton<Logger>;
            void checkAndRotateLog ();
            void close ();
            void configMessagePatternOutput ();
            void handleMessage ( QtMsgType type, const QMessageLogContext &context, const QString &msg );
            static void messageHandler ( QtMsgType type, const QMessageLogContext &context, const QString &msg );
            void open ();
            void sendEmail ( QString message );
            void writeToLog ( const QString &message );
        };
      }
    }
  }
}

#endif // LOGGER_H
