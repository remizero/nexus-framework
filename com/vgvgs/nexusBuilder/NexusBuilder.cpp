#include "NexusBuilder.h"


using namespace NSLIB_BUILDER;


const char *NexusBuilder::getProjectClassName ( ProjectId projectId ) {

  static const char *projectClassNames [ NUM_PROJECTS ] = {
    "BlankAppProject",
    "BlankLibraryProject",
    "ConsoleAppProject",
    "GuiAppProject",
    "NexusAppProject",
    "PluginProject",
    "ShareLibraryProject",
    "SimpleGuiAppProject",
    "StaticLibraryProject"
  };
  return projectClassNames [ projectId ];
}

NexusBuilder::ProjectId NexusBuilder::stringToProjectId ( const QString &projectType ) {

  static const QMap<QString, ProjectId> projectIdMap {
    {   "blankapp", ProjectId::BLANKAPP     },
    {   "blanklib", ProjectId::BLANKLIBRARY },
    {    "console", ProjectId::CONSOLE      },
    {        "gui", ProjectId::GUI          },
    {      "nexus", ProjectId::NEXUS        },
    {     "plugin", ProjectId::PLUGIN       },
    {      "share", ProjectId::SHARE        },
    {  "simplegui", ProjectId::SIMPLEGUI    },
    {     "static", ProjectId::STATIC       }
  };
  return projectIdMap.value ( projectType.toLower (), ProjectId::NUM_PROJECTS );
}
