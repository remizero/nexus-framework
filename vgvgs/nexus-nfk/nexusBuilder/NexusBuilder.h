#ifndef NEXUSBUILDER_H
#define NEXUSBUILDER_H

// Librerías Internas
// Internal Libraries
#include "Builder_global.h"

// Librerías Externas
// External Libraries

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QMetaEnum>
#include <QMetaType>
#include <QObject>

// Librerías C++
// C++ Libraries


  namespace NS_VGVGS {

    namespace NS_NEXUS {

      namespace NS_BUILDER {

        class BUILDER_EXPORT NexusBuilder : public QObject {

            Q_OBJECT

          public :

            enum Accessibility {

              PRIVATE,
              PROTECTED,
              PUBLIC
            };
            Q_ENUM ( Accessibility )

            enum FileClasses {

              HEADERSONLY,
              SOURCESONLY,
              HEADERSANDSOURCESBOTH
            };
            Q_ENUM ( FileClasses )

            enum GetterAndSetter {

              GETTERONLY,
              SETTERONLY,
              GETTERANDSETTERBOTH
            };
            Q_ENUM ( GetterAndSetter )

            enum ProjectId {

              BLANKAPP,
              BLANKLIBRARY,
              CONSOLE,
              GUI,
              NEXUS,
              PLUGIN,
              SHARE,
              SIMPLEGUI,
              STANDALONE,
              STATIC,
              NUM_PROJECTS
            };
            Q_ENUM ( ProjectId )

            enum TypeBuild {

              DEFINITION,
              IMPLEMENTATION
            };
            Q_ENUM ( TypeBuild )
            static const char *getProjectClassName ( ProjectId projectId );
            static ProjectId stringToProjectId ( const QString &projectType );
        };
      }
    }
  }

#endif // NEXUSBUILDER_H
