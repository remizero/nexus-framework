#include "ProjectAbs.h"


using namespace NSLIB_BUILDER;


ProjectAbs::ProjectAbs ( QObject *parent ) : QObject ( parent ) {

  this->verboseMode = false;
  this->status = Status::NOT_INITIALIZED;
  this->projectType = NexusBuilder::ProjectId::NUM_PROJECTS;
  this->proBuilder = new ProBuilder ();
}

void ProjectAbs::init ( QString projectName, QString projectPath, QString projectType, bool verboseMode ) {

  this->name                  = projectName;
  this->path                  = projectPath;
  this->prefix                = "nexus";
  this->projectType           = NexusBuilder::stringToProjectId ( projectType );
  this->verboseMode           = verboseMode;
  this->normalizedProjectName = NexusBuilderUtils::normalizeProjectName ( projectName );
  this->resource              = ":/templates/resources/projects/";
  NexusBuilderUtils::getQmakeBuildersPath ();
  this->status                = Status::INITIALIZED;
}

bool ProjectAbs::createProjectDir () {

  if ( this->isInitialized () ) {

    if ( NexusBuilderUtils::createDirectory ( this->path, this->normalizedProjectName ) ) {

      this->path.append ( this->normalizedProjectName );
      return true;
    }
  }
  return false;
}

bool ProjectAbs::createProFile () {

  if ( this->isInitialized () ) {

    if ( NSLIB_UTILS::Strings::save ( this->path + QDir::separator () + this->normalizedProjectName + ".pro",
                                      this->proBuilder->build ( this->path, this->resource, this->normalizedProjectName, this->projectType ) ) ) {

      return true;
    }
  }
  return false;
}

ProjectAbs::Status ProjectAbs::getStatus () const {

  return this->status;
}

bool ProjectAbs::isInitialized () const {

  bool done = this->status == Status::INITIALIZED;
  if ( !done ) {

    qDebug () << "La clase no ha sido inicializada correctamente.";
  }
  return done;
}
