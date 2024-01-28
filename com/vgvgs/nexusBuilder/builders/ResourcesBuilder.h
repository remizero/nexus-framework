#ifndef RESOURCESBUILDER_H
#define RESOURCESBUILDER_H

// Librerías Internas
// Internal Libraries
#include "Builder_global.h"
#include "NexusBuilderUtils.h"

// Librerías Externas
// External Libraries
#include "Xml.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QDebug>
#include <QtXml/QDomDocument>
#include <QtXml/QDomElement>
#include <QObject>
#include <QString>
#include <QStringList>

// Librerías C++
// C++ Libraries


namespace NS_LEVEL_1 {

  namespace NS_LEVEL_2 {

    namespace NS_NEXUS {

      namespace NS_BUILDER {

        class BUILDER_EXPORT ResourcesBuilder : public QObject {

            Q_OBJECT

          public :
            ResourcesBuilder ( QObject *parent = nullptr );
            QDomDocument *build ( QString resource, QMap<QString, QStringList> prefixFileMap );

            QDomElement createResourceElement ( QDomDocument *doc, const QString &prefix = "/" );
            QDomElement createFileElement ( QDomElement &resourceElement, const QString &filePath );
            void init ( QString resource );

          protected :
            QDomDocument *resource;
            bool initialized;
        };
      }
    }
  }
}

#endif // RESOURCESBUILDER_H
