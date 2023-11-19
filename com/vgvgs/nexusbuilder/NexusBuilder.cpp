#include "NexusBuilder.h"


using namespace NAMESPACE_LIBRARY_NEXUSBUILDER;


NexusBuilder::NexusBuilder () {

  qRegisterMetaType<ConsoleProject> ( "ConsoleProject" );
  qRegisterMetaType<GuiProject> ( "GuiProject" );
  qRegisterMetaType<NexusProject> ( "NexusProject" );
  qRegisterMetaType<PluginProject> ( "PluginProject" );
  qRegisterMetaType<ShareLibraryProject> ( "ShareLibraryProject" );
  qRegisterMetaType<StaticLibraryProject> ( "StaticLibraryProject" );
}

ProjectInterface *NexusBuilder::create ( ProjectId projectId ) {

  const char *className = getProjectClassName ( projectId );
  QMetaType typeId = QMetaType::fromName ( className );
  if ( typeId.isValid () ) {

    ProjectInterface *project = static_cast<ProjectInterface *> ( typeId.create () );
    return project;
  }
  return nullptr;
}

const char *NexusBuilder::getProjectClassName ( ProjectId projectId ) {

  static const char *projectClassNames [ NUM_PROJECTS ] = {
    "ConsoleProject",
    "GuiProject",
    "NexusProject",
    "PluginProject"
    "ShareProject",
    "StaticProject"
  };
  return projectClassNames [ projectId ];
}

NexusBuilder::ProjectId NexusBuilder::stringToProjectId ( const QString &projectType ) {

  static const QMap<QString, ProjectId> projectIdMap {
    { "console", ProjectId::CONSOLE },
    { "gui",     ProjectId::GUI     },
    { "nexus",   ProjectId::NEXUS   },
    { "plugin",  ProjectId::PLUGIN  },
    { "share",   ProjectId::SHARE   },
    { "static",  ProjectId::STATIC  }
  };
  return projectIdMap.value ( projectType.toLower (), ProjectId::NUM_PROJECTS );
}
