# Se definen las rutas de construcción del proyecto.
# The project construction routes are defined.
include(../../../qmakeBuilders/buildPaths.prf)

# QT -= gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets core

TARGET = nexusbuilder

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
  AppCreator.cpp \
  AppProject.cpp \
  LibraryProject.cpp \
  NexusBuilder.cpp \
  ProjectAbs.cpp \
  Version.cpp \
  projectType/ConsoleProject.cpp \
  projectType/GuiProject.cpp \
  projectType/NexusProject.cpp \
  projectType/PluginProject.cpp \
  projectType/ShareLibraryProject.cpp \
  projectType/StaticLibraryProject.cpp

HEADERS += \
  AppCreator.h \
  AppProject.h \
  LibraryProject.h \
  nexusbuilder_global.h \
  NexusBuilder.h \
  ProjectAbs.h \
  ProjectInterface.h \
  Version.h \
  projectType/ConsoleProject.h \
  projectType/GuiProject.h \
  projectType/NexusProject.h \
  projectType/PluginProject.h \
  projectType/ShareLibraryProject.h \
  projectType/StaticLibraryProject.h

win32:CONFIG(release, debug|release): LIBS += \
  -L$$LIB_PATH/ -lMacros \
  -L$$LIB_PATH/ -lPatternify \
  -L$$LIB_PATH/ -lResources \
  -L$$LIB_PATH/ -lCore
else:win32:CONFIG(debug, debug|release): LIBS += \
  -L$$LIB_PATH/ -lMacros \
  -L$$LIB_PATH/ -lPatternify \
  -L$$LIB_PATH/ -lResources \
  -L$$LIB_PATH/ -lCore
else:unix: LIBS += \
  -L$$LIB_PATH/ -lMacros \
  -L$$LIB_PATH/ -lPatternify \
  -L$$LIB_PATH/ -lResources \
  -L$$LIB_PATH/ -lCore

INCLUDEPATH += \
  $$PWD/../core \
  $$PWD/../macros \
  $$PWD/../patternify \
  $$PWD/../resources

DEPENDPATH += \
  $$PWD/../core \
  $$PWD/../macros \
  $$PWD/../patternify \
  $$PWD/../resources

DEF_FILE += \
  export.def

DISTFILES += \
  export.def
#  resources/PluginJsonStructure.json

RESOURCES += \
  resources.qrc

# Se copia la librería en la ruta destino del proyecto final.
# The library is copied to the destination path of the final project.
include (../../../qmakeBuilders/copyLibraries.prf)

# Se definen las reglas y rutas de instalación del proyecto para las diferentes plataformas.
# The rules and installation paths of the project are defined for the different platforms.
include (../../../qmakeBuilders/deploymentRulesLib.prf)
