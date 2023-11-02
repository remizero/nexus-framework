# Se definen las rutas de construcción del proyecto.
# The project construction routes are defined.
include(../../../qmakeBuilders/buildPaths.prf)

# QT -= gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets core

TARGET = core

# Normalización del nombre de proyecto.
# Project name normalization.
include (../../../qmakeBuilders/normalizeProjectName.prf)
TARGET = $$PROJECT_NAME

# Definiciones particulares del tipo de proyecto.
# Particular definitions of the project type.
include (../../../qmakeBuilders/projectLibConfiguration.prf)

# Se definen los parámetros de configuración del compilador.
# Compiler configuration parameters are defined.
include(../../../qmakeBuilders/buildConfiguration.prf)

SOURCES += \
  Core.cpp \
  Exception.cpp \
  Version.cpp \
  actionsystem/ActionAbs.cpp \
  actionsystem/ActionManager.cpp \
  appsystem/App.cpp \
  appsystem/AppConfig.cpp \
  appsystem/AppExit.cpp \
  appsystem/AppInit.cpp \
  appsystem/AppManager.cpp \
  appsystem/AppPaths.cpp \
  appsystem/AppSettingManager.cpp \
  appsystem/AppSettings.cpp \
  appsystem/AppUtils.cpp \
  appsystem/ConfigAbs.cpp \
  appsystem/UserConfig.cpp \
  commandsystem/CommandManager.cpp \
  loggersystem/Logger.cpp \
  menusystem/MenuManager.cpp \
  pluginsystem/PluginAbs.cpp \
  pluginsystem/PluginActionInfo.cpp \
  pluginsystem/PluginActionLocationInfo.cpp \
  pluginsystem/PluginCreator.cpp \
  pluginsystem/PluginDependenciesInfo.cpp \
  pluginsystem/PluginInfo.cpp \
  pluginsystem/PluginManager.cpp

HEADERS += \
  MainWindowInterface.h \
  appsystem/ConfigAbs.h \
  commandsystem/CommandManager.h \
  core_global.h \
  Core.h \
  Exception.h \
  Version.h \
  actionsystem/ActionAbs.h \
  actionsystem/ActionInterface.h \
  actionsystem/ActionManager.h \
  appsystem/App.h \
  appsystem/AppConfig.h \
  appsystem/AppExit.h \
  appsystem/AppInit.h \
  appsystem/AppManager.h \
  appsystem/AppPaths.h \
  appsystem/AppSettingManager.h \
  appsystem/AppSettings.h \
  appsystem/AppUtils.h \
  appsystem/UserConfig.h \
  loggersystem/Logger.h \
  menusystem/MenuManager.h \
  pluginsystem/PluginAbs.h \
  pluginsystem/PluginActionInfo.h \
  pluginsystem/PluginActionLocationInfo.h \
  pluginsystem/PluginCreator.h \
  pluginsystem/PluginDependenciesInfo.h \
  pluginsystem/PluginInfo.h \
  pluginsystem/PluginInterface.h \
  pluginsystem/PluginManager.h

win32:CONFIG(release, debug|release): LIBS += \
  -L$$LIB_PATH/ -lMacros \
  -L$$LIB_PATH/ -lPatternify
else:win32:CONFIG(debug, debug|release): LIBS += \
  -L$$LIB_PATH/ -lMacros \
  -L$$LIB_PATH/ -lPatternify
else:unix: LIBS += \
  -L$$LIB_PATH/ -lMacros \
  -L$$LIB_PATH/ -lPatternify

INCLUDEPATH += \
  $$PWD/../macros \
  $$PWD/../patternify

DEPENDPATH += \
  $$PWD/../macros \
  $$PWD/../patternify

DEF_FILE += \
  export.def

DISTFILES += \
  export.def \
  resources/PluginJsonStructure.json

RESOURCES += \
  coreResources.qrc

# Se copia la librería en la ruta destino del proyecto final.
# The library is copied to the destination path of the final project.
include (../../../qmakeBuilders/copyLibraries.prf)

# Se definen las reglas y rutas de instalación del proyecto para las diferentes plataformas.
# The rules and installation paths of the project are defined for the different platforms.
include (../../../qmakeBuilders/deploymentRulesLib.prf)
