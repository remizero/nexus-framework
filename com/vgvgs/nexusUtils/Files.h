#ifndef FILES_H
#define FILES_H

// Librerías Internas
// Internal Libraries
#include "Utils_global.h"

// Librerías Externas
// External Libraries

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QIODeviceBase>
#include <QJsonDocument>
#include <QtWidgets/QMessageBox>
#include <QString>
#include <QTextStream>
#include <QVariant>
#include <QtWidgets/QWidget>
#include <QtXml/QDomDocument>

// Librerías C++
// C++ Libraries


namespace NS_LEVEL_1 {

  namespace NS_LEVEL_2 {

    namespace NS_NEXUS {

      namespace NS_UTILS {

        class UTILS_EXPORT Files {

          public :
            static QFile *load ( const QString fileName, QIODeviceBase::OpenMode openMode = QIODevice::ReadOnly | QIODevice::Text );
            static bool save ( const QString fileName, const QVariant &contentToSave, QIODeviceBase::OpenMode openMode = QIODevice::WriteOnly | QIODevice::Text );
            static bool save ( QFile *ioDeviceFile, const QVariant &contentToSave );
        };
      }
    }
  }
}

#endif // FILES_H
