#ifndef LOGGER_H
#define LOGGER_H

// Librerías Internas
// Internal Libraries
#include "core_global.h"
#include "appsystem/AppManager.h"
#include "appsystem/AppPaths.h"
#include "Exception.h"

// Librerías Externas
// External Libraries
#include "macros_global.h"
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
#include <QMessageBox>
#include <QMessageLogContext>
#include <QScopedPointer>
#include <QString>
#include <QStringLiteral>
#include <QTextStream>

// Librerías C++
// C++ Libraries


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_CORE {

      class CORE_EXPORT Logger : public NAMESPACE_LIBRARY_PATTERNIFY::Singleton<Logger> {

        public :

          enum LogOutput {

            Standard,
            File
          };

          virtual ~Logger ();
          void exception ( const Exception &exception );
          void init ( Logger::LogOutput output = File, QString outputFormat = STR(FILE_OUTPUT_QT_MESSAGE_PATTERN) );
          void installMessageHandler ();
          void reinstallMessageHandler ();
          void uninstallMessageHandler ();

        private :
                           QString filePath;
                           QString outputFormat;
           QIODeviceBase::OpenMode openMode;
                 Logger::LogOutput output;
          QScopedPointer < QFile > logFile;

          Logger ();
          friend class NAMESPACE_LIBRARY_PATTERNIFY::Singleton<Logger>;
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

#endif // LOGGER_H
