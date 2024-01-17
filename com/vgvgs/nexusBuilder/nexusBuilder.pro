# Se definen las rutas de construcción del proyecto.
# The project construction routes are defined.
include(../../../qmakeBuilders/buildPaths.prf)

# QT -= gui

greaterThan(QT_MAJOR_VERSION, 5): QT += core xml

TARGET = nexusBuilder

# Normalización del nombre de proyecto.
# Project name normalization.
include (../../../qmakeBuilders/normalizeProjectName.prf)
TARGET = $$PROJECT_NAME

# Definiciones particulares del tipo de proyecto.
# Particular definitions of the project type.
include (../../../qmakeBuilders/projectLibShareConfiguration.prf)

# Se definen los parámetros de configuración del compilador.
# Compiler configuration parameters are defined.
include(../../../qmakeBuilders/buildConfiguration.prf)

SOURCES += \
  AppProject.cpp \
  Builders.cpp \
  LibraryProject.cpp \
  NexusBuilder.cpp \
  NexusBuilderManager.cpp \
  NexusBuilderUtils.cpp \
  ProjectAbs.cpp \
  ProjectDirector.cpp \
  RegisterClasses.cpp \
  Version.cpp \
  builders/AttributeBuilder.cpp \
  builders/ClassBuilder.cpp \
  builders/CommandBuilder.cpp \
  builders/ConfigBuilder.cpp \
  builders/ExportsBuilder.cpp \
  builders/FunctionBuilder.cpp \
  builders/GlobalBuilder.cpp \
  builders/MainBuilder.cpp \
  builders/MethodBuilder.cpp \
  builders/ParamBuilder.cpp \
  builders/ProBuilder.cpp \
  builders/ResourcesBuilder.cpp \
  builders/VersionBuilder.cpp \
  projectType/BlankAppProject.cpp \
  projectType/BlankLibraryProject.cpp \
  projectType/ConsoleAppProject.cpp \
  projectType/GuiAppProject.cpp \
  projectType/NexusAppProject.cpp \
  projectType/PluginProject.cpp \
  projectType/ShareLibraryProject.cpp \
  projectType/SimpleGuiAppProject.cpp \
  projectType/StandaloneNexusAppProject.cpp \
  projectType/StaticLibraryProject.cpp

HEADERS += \
  AppProject.h \
  Builder_global.h \
  Builders.h \
  LibraryProject.h \
  NexusBuilderManager.h \
  NexusBuilderUtils.h \
  ProjectDirector.h \
  NexusBuilder.h \
  ProjectAbs.h \
  ProjectInterface.h \
  RegisterClasses.h \
  Version.h \
  builders/AttributeBuilder.h \
  builders/ClassBuilder.h \
  builders/CommandBuilder.h \
  builders/ConfigBuilder.h \
  builders/ExportsBuilder.h \
  builders/FunctionBuilder.h \
  builders/GlobalBuilder.h \
  builders/MainBuilder.h \
  builders/MethodBuilder.h \
  builders/ParamBuilder.h \
  builders/ProBuilder.h \
  builders/ResourcesBuilder.h \
  builders/VersionBuilder.h \
  projectType/BlankAppProject.h \
  projectType/BlankLibraryProject.h \
  projectType/ConsoleAppProject.h \
  projectType/GuiAppProject.h \
  projectType/NexusAppProject.h \
  projectType/PluginProject.h \
  projectType/ShareLibraryProject.h \
  projectType/SimpleGuiAppProject.h \
  projectType/StandaloneNexusAppProject.h \
  projectType/StaticLibraryProject.h

win32:CONFIG(release, debug|release): LIBS += \
  -L$$LIB_PATH/ -lNexusMacros \
  -L$$LIB_PATH/ -lNexusPatternify \
  -L$$LIB_PATH/ -lNexusUtils \
  -L$$LIB_PATH/ -lNexusCore \
  -L$$LIB_PATH/ -lNexusResources
else:win32:CONFIG(debug, debug|release): LIBS += \
  -L$$LIB_PATH/ -lNexusMacros \
  -L$$LIB_PATH/ -lNexusPatternify \
  -L$$LIB_PATH/ -lNexusUtils \
  -L$$LIB_PATH/ -lNexusCore \
  -L$$LIB_PATH/ -lNexusResources
else:unix: LIBS += \
  -L$$LIB_PATH/ -lNexusMacros \
  -L$$LIB_PATH/ -lNexusPatternify \
  -L$$LIB_PATH/ -lNexusUtils \
  -L$$LIB_PATH/ -lNexusCore \
  -L$$LIB_PATH/ -lNexusResources

INCLUDEPATH += \
  $$PWD/../nexusCore \
  $$PWD/../nexusMacros \
  $$PWD/../nexusPatternify \
  $$PWD/../nexusResources \
  $$PWD/../nexusUtils

DEPENDPATH += \
  $$PWD/../nexusCore \
  $$PWD/../nexusMacros \
  $$PWD/../nexusPatternify \
  $$PWD/../nexusResources \
  $$PWD/../nexusUtils

DEF_FILE += \
  export.def

DISTFILES += \
  export.def
#  resources/PluginJsonStructure.json

RESOURCES += \
  builder_resources.qrc

# Se copia la librería en la ruta destino del proyecto final.
# The library is copied to the destination path of the final project.
include (../../../qmakeBuilders/copyLibraries.prf)

# Se definen las reglas y rutas de instalación del proyecto para las diferentes plataformas.
# The rules and installation paths of the project are defined for the different platforms.
include (../../../qmakeBuilders/deploymentRulesLib.prf)
