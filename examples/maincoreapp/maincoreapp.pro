# Se definen las rutas de construcción del proyecto.
# The project construction routes are defined.
include(../../qmakeBuilders/buildPaths.prf)

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 5): QT += widgets

TARGET = maincoreapp

# Normalización del nombre de proyecto.
# Project name normalization.
include (../../qmakeBuilders/normalizeProjectName.prf)
TARGET = $$PROJECT_NAME

# Definiciones particulares del tipo de proyecto.
# Particular definitions of the project type.
include (../../qmakeBuilders/projectBinConfiguration.prf)

# Se definen los parámetros de configuración del compilador.
# Compiler configuration parameters are defined.
include(../../qmakeBuilders/buildConfiguration.prf)

SOURCES += \
  CommandProcessor.cpp \
  MCARegisterClasses.cpp \
  commands/InfoCmd.cpp \
  commands/TypeCmd.cpp \
  main.cpp \
  MainWindow.cpp

HEADERS += \
  CommandProcessor.h \
  MCARegisterClasses.h \
  MainWindow.h \
  commands/InfoCmd.h \
  commands/TypeCmd.h

RESOURCES += \
  resources.qrc

FORMS += \
  MainWindow.ui

DEF_FILE += \
  export.def

DISTFILES += \
  export.def

win32:CONFIG(release, debug|release): LIBS += \
  -L$$LIB_PATH/ -lNexusMacros \
  -L$$LIB_PATH/ -lNexusPatternify \
  -L$$LIB_PATH/ -lNexusUtils \
  -L$$LIB_PATH/ -lNexusCore \
  -L$$LIB_PATH/ -lNexusResources \
  -L$$LIB_PATH/ -lNexusBuilder
else:win32:CONFIG(debug, debug|release): LIBS += \
  -L$$LIB_PATH/ -lNexusMacros \
  -L$$LIB_PATH/ -lNexusPatternify \
  -L$$LIB_PATH/ -lNexusUtils \
  -L$$LIB_PATH/ -lNexusCore \
  -L$$LIB_PATH/ -lNexusResources \
  -L$$LIB_PATH/ -lNexusBuilder
else:unix: LIBS += \
  -L$$LIB_PATH/ -lNexusMacros \
  -L$$LIB_PATH/ -lNexusPatternify \
  -L$$LIB_PATH/ -lNexusUtils \
  -L$$LIB_PATH/ -lNexusCore \
  -L$$LIB_PATH/ -lNexusResources \
  -L$$LIB_PATH/ -lNexusBuilder

INCLUDEPATH += \
  $$PWD/../../com/vgvgs/nexusMacros \
  $$PWD/../../com/vgvgs/nexusCore \
  $$PWD/../../com/vgvgs/nexusPatternify \
  $$PWD/../../com/vgvgs/nexusResources \
  $$PWD/../../com/vgvgs/nexusBuilder \
  $$PWD/../../com/vgvgs/nexusUtils

DEPENDPATH += \
  $$PWD/../../com/vgvgs/nexusMacros \
  $$PWD/../../com/vgvgs/nexusCore \
  $$PWD/../../com/vgvgs/nexusPatternify \
  $$PWD/../../com/vgvgs/nexusResources \
  $$PWD/../../com/vgvgs/nexusBuilder \
  $$PWD/../../com/vgvgs/nexusUtils

# Se copia la librería en la ruta destino del proyecto final.
# The library is copied to the destination path of the final project.
include (../../qmakeBuilders/copyBinaries.prf)

# Se definen las reglas y rutas de instalación del proyecto para las diferentes plataformas.
# The rules and installation paths of the project are defined for the different platforms.
include (../../qmakeBuilders/deploymentRulesBin.prf)
