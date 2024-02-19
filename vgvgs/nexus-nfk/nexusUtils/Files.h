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
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QFileInfoList>
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


  namespace NS_VGVGS {

    namespace NS_NEXUS {

      namespace NS_UTILS {

        class UTILS_EXPORT Files {

          public :
            static QStringList findFiles ( const QString &searchPath, const QString &filters );
            static QFile *load ( const QString fileName, QIODeviceBase::OpenMode openMode = QIODevice::ReadOnly | QIODevice::Text );
            static bool save ( const QString fileName, const QVariant &contentToSave, QIODeviceBase::OpenMode openMode = QIODevice::WriteOnly | QIODevice::Text );
            static bool save ( QFile *ioDeviceFile, const QVariant &contentToSave );
        };
      }
    }
  }

#endif // FILES_H
