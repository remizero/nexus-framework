#ifndef ATTRIBUTEBUILDER_H
#define ATTRIBUTEBUILDER_H

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
#include <QObject>
#include <QString>

// Librerías C++
// C++ Libraries


namespace NS_LEVEL_1 {

  namespace NS_LEVEL_2 {

    namespace NS_NEXUS {

      namespace NS_BUILDER {

        class BUILDER_EXPORT AttributeBuilder : public ParamBuilder {

          public :
            AttributeBuilder ( QString paramName, QString paramType, bool paramDynamic, bool paramNullPointer, QString paramDefaultValue = "" );

            void build ();

            NexusBuilder::Accessibility getAccessibility ();
            const NexusBuilder::GetterAndSetter &getGetterAndSetter () const;
            void setAccessibility ( NexusBuilder::Accessibility newAccessibility );
            void setGetterAndSetter(const NexusBuilder::GetterAndSetter &newGetterAndSetter);

          private :
              NexusBuilder::Accessibility accessibility;
            NexusBuilder::GetterAndSetter getterAndSetter;
        };
      }
    }
  }
}

#endif // ATTRIBUTEBUILDER_H
