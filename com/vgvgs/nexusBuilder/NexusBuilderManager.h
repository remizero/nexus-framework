#ifndef NEXUSBUILDERMANAGER_H
#define NEXUSBUILDERMANAGER_H

// Librerías Internas
// Internal Libraries
#include "Builder_global.h"
#include "NexusBuilder.h"
#include "ProjectDirector.h"
#include "RegisterClasses.h"
#include "ProjectAbs.h"

// Librerías Externas
// External Libraries
#include "creational/Singleton.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QObject>

// Librerías C++
// C++ Libraries


// TODO Completar los cambios de variables para los tipos de proyectos Console, Gui, Nexus, Share y Static
// TODO Redefinir las aplicaciones de tipo console a que solo sean de tipo console.
// TODO Redefinir las aplicaciones de tipo gui a que solo sean de tipo gui.
// TODO Redefinir las aplicaciones de tipo gui a SimpleGui.
// TODO Crear un nuevo tipo de proyecto de tipo Gui que solo sean de tipo gui pero con el llamado de la clase MainWindow de la librería qtrcp.
// TODO El proyecto de tipo Nexus debe contener las capacidades de los proyectos de tipo console y gui pero con el llamado de la clase MainWindow de la librería qtrcp.
namespace NS_LEVEL_1 {

  namespace NS_LEVEL_2 {

    namespace NS_NEXUS {

      namespace NS_BUILDER {

        class BUILDER_EXPORT NexusBuilderManager : public QObject, public NSLIB_PATTERNIFY::Singleton<NexusBuilderManager> {

            Q_OBJECT

          public :
            void createProject ( QString projectName, QString projectPath, QString projecType, bool verboseMode = false );

          private :
            NexusBuilderManager ();
            friend class NSLIB_PATTERNIFY::Singleton<NexusBuilderManager>;
        };
      }
    }
  }
}

#endif // NEXUSBUILDERMANAGER_H
