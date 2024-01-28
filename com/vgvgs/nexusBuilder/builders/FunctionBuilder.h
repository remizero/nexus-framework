#ifndef FUNCTIONBUILDER_H
#define FUNCTIONBUILDER_H

// Librerías Internas
// Internal Libraries
#include "Builder_global.h"
#include "NexusBuilder.h"
#include "ParamBuilder.h"

// Librerías Externas
// External Libraries

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QDebug>
#include <QList>
#include <QObject>
#include <QString>

// Librerías C++
// C++ Libraries


namespace NS_LEVEL_1 {

  namespace NS_LEVEL_2 {

    namespace NS_NEXUS {

      namespace NS_BUILDER {

        class BUILDER_EXPORT FunctionBuilder {

          public :
            FunctionBuilder ();

            QString build ( NexusBuilder::TypeBuild typeBuild, QString memberScope );

            void createDefinition ( NexusBuilder::TypeBuild typeBuild, QString memberScope = "" );
            void createParams ();
            void createSectionedDefinition ( NexusBuilder::TypeBuild typeBuild, QString memberScope, bool begin = true );

            const QString &getBody () const;
            const QString &getFunction () const;
            const QString &getName () const;
            const QString &getType () const;
            const QList<ParamBuilder *> &getParamList () const;
            bool isPointer () const;
            void setBody ( const QString &newBody );
            void setFunction ( const QString &newFunction );
            void setIsPointer ( bool newIsPointer );
            void setName ( const QString &newName );
            void setType ( const QString &newType );
            void setParamList ( ParamBuilder *param );

          protected :
                          QString body;
                          QString function;
                             bool pointer;
                          QString name;
                          QString type;
            QList<ParamBuilder *> paramList;
        };
      }
    }
  }
}

#endif // FUNCTIONBUILDER_H
