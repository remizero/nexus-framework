#ifndef RESOURCESMANAGER_H
#define RESOURCESMANAGER_H

// Librerías Internas
// Internal Libraries
#include "Core_global.h"

// Librerías Externas
// External Libraries
#include "Files.h"
#include "Json.h"
#include "Strings.h"
#include "Xml.h"
#include "creational/Singleton.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QByteArray>
#include <QDebug>
#include <QFile>
#include <QImage>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QObject>
#include <QString>
#include <QtXml/QDomDocument>

// Librerías C++
// C++ Libraries


  namespace NS_VGVGS {

    namespace NS_NEXUS {

      namespace NS_CORE {

        class CORE_EXPORT ResourcesManager : public QObject, public NSLIB_PATTERNIFY::Singleton<ResourcesManager> {

            Q_OBJECT

          public :
            QJsonDocument *loadJson ( const QString &resourcePath );
            QImage loadImage ( const QString &resourcePath, QString imageType ); // TODO Manejar imageType como un enumerado.
            QString loadIni ( const QString &resourcePath );
            QString loadTextFile ( const QString &resourcePath );
            QDomDocument *loadXml ( const QString &resourcePath );

          private :
            ResourcesManager ( QObject *parent = nullptr );
            friend class NSLIB_PATTERNIFY::Singleton<ResourcesManager>;
        };
      }
    }
  }

#endif // RESOURCESMANAGER_H
