#ifndef CONFIGBUILDER_H
#define CONFIGBUILDER_H

// Librerías Internas
// Internal Libraries
#include "Builder_global.h"
#include "NexusBuilder.h"
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

// Librerías C++
// C++ Libraries


  namespace NS_VGVGS {

    namespace NS_NEXUS {

      namespace NS_BUILDER {

        class BUILDER_EXPORT ConfigBuilder : QObject {

            Q_OBJECT

          public :
            ConfigBuilder ( QObject *parent = nullptr );
            QDomDocument *build ( QString resource, const QString &projectName, NexusBuilder::ProjectId projectType );
            void modifyXmlElement ( QDomElement &parent, const QString &elementName, const QString &newValue );

          protected :
            QDomDocument *resource;
            bool initialized;
        };
      }
    }
  }

#endif // CONFIGBUILDER_H
