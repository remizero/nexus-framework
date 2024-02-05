#ifndef CLASSBUILDER_H
#define CLASSBUILDER_H

// Librerías Internas
// Internal Libraries
#include "Builder_global.h"
#include "AttributeBuilder.h"
#include "MethodBuilder.h"
#include "NexusBuilder.h"

// Librerías Externas
// External Libraries
#include "Strings.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QDebug>
#include <QDir>
#include <QList>
#include <QObject>
#include <QString>
#include <QStringList>

// Librerías C++
// C++ Libraries
#include <algorithm>
#include <functional>


namespace NS_LEVEL_1 {

  namespace NS_LEVEL_2 {

    namespace NS_NEXUS {

      namespace NS_BUILDER {

        class BUILDER_EXPORT ClassBuilder {

          public :
            ClassBuilder ( QString className, NexusBuilder::FileClasses fileClass, bool interface = false );

            void build ();

            void alignStrings ( QStringList &stringList );
            void closeClass ();
            void closeClassFile ();
            void createAccessibilitySection ( NexusBuilder::Accessibility accessibility );
            void createClassDefinition ();
            void createHeaderFile ();
            void createIncludeGuard ();
            void createLibsSection ();
            void createMetadataSection ();
            void createNamespacesClosing ();
            void createNamespacesOpening ();
            void createPrivateSection ();
            void createProtectedSection ();
            void createPublicSection ();
            void createSourceFile ();
            void decreaseIndentation ();
            const QList<AttributeBuilder *> &getAttributeList () const;
            const QString &getClassName () const;
            const NexusBuilder::FileClasses &getFileClasses () const;
            const QStringList &getInheritsFrom () const;
            const QList<MethodBuilder *> &getMethodList () const;
            const QStringList &getNamespaceList () const;
            void setAttributeList ( AttributeBuilder *attribute );
            void setInheritsFrom ( const QStringList &newInheritsFrom );
            void setMethodList ( MethodBuilder *method );
            void setNamespaceList ( const QString &nameSpace );
            bool toFile ( const QString &path );

          private :
                                 QList<AttributeBuilder *> attributeList;
                                                   QString className;
                                 NexusBuilder::FileClasses fileClasses;
                                                   QString headerBody;
                                                   QString indentation;
                                               QStringList inheritsFrom;
                                    QList<MethodBuilder *> methodList;
                                               QStringList namespaceList;
            typedef std::function<bool( const QString & )> SaveFunction;
                                                   QString sourceBody;

                                                   QString interfaceSection;
                                                   QString pluginSection;
                                                      bool isInterface;

            bool saveHeaderFile ( const QString &path, SaveFunction saveFunction = nullptr );
            bool saveSourceFile ( const QString &path );
        };
      }
    }
  }
}

#endif // CLASSBUILDER_H
