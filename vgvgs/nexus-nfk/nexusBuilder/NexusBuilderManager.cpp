#include "NexusBuilderManager.h"


using namespace NSLIB_BUILDER;


NexusBuilderManager::NexusBuilderManager () {

  RegisterClasses::getInstance ()->addTypeClass ();
}

void NexusBuilderManager::createProject ( QString projectName, QString projectPath, QString projectType, bool verboseMode ) {

  NexusBuilder::ProjectId projectId = NexusBuilder::stringToProjectId ( projectType );
  if ( projectId != NexusBuilder::NUM_PROJECTS ) {

    const char *className = NexusBuilder::getProjectClassName ( projectId );
    QMetaType typeId = QMetaType::fromName ( className );
    if ( typeId.isValid () ) {

      ProjectAbs *project = static_cast<ProjectAbs *> ( typeId.create () );
      if ( project ) {

        project->init ( projectName, projectPath, projectType, verboseMode );
        ProjectDirector::create ( project );

      } else {

        qDebug () << "Error al crear el objeto generador del proyecto.";
        delete project;
        return;
      }
    } else {

      qDebug () << "Tipo de dato \"QMetaType typeId\" no válido.";
      return;
    }
  } else {

    qDebug () << "Tipo de proyecto desconocido.";
    return;
  }
}
