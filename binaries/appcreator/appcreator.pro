# Se definen las rutas de construcción del proyecto.
# The project construction routes are defined.
include(../../qmakeBuilders/buildPaths.prf)

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = appCreator

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
  commands/TypeCmd.cpp \
  CommandProcessor.cpp \
  main.cpp \
  MainWindow.cpp \
  RegisterClasses.cpp

HEADERS += \
  commands/TypeCmd.h \
  CommandProcessor.h \
  MainWindow.h \
  RegisterClasses.h

RESOURCES += \
  resources.qrc

FORMS += \
  MainWindow.ui

DEF_FILE += \
  export.def

DISTFILES += \
  export.def

win32:CONFIG(release, debug|release): LIBS += \
  -L$$LIB_PATH/ -lMacros \
  -L$$LIB_PATH/ -lCore \
  -L$$LIB_PATH/ -lPatternify \
  -L$$LIB_PATH/ -lResources \
  -L$$LIB_PATH/ -lNexusbuilder
else:win32:CONFIG(debug, debug|release): LIBS += \
  -L$$LIB_PATH/ -lMacros \
  -L$$LIB_PATH/ -lCore \
  -L$$LIB_PATH/ -lPatternify \
  -L$$LIB_PATH/ -lResources \
  -L$$LIB_PATH/ -lNexusbuilder
else:unix: LIBS += \
  -L$$LIB_PATH/ -lMacros \
  -L$$LIB_PATH/ -lCore \
  -L$$LIB_PATH/ -lPatternify \
  -L$$LIB_PATH/ -lResources \
  -L$$LIB_PATH/ -lNexusbuilder

INCLUDEPATH += \
  $$PWD/../../com/vgvgs/macros \
  $$PWD/../../com/vgvgs/core \
  $$PWD/../../com/vgvgs/patternify \
  $$PWD/../../com/vgvgs/resources \
  $$PWD/../../com/vgvgs/nexusbuilder

DEPENDPATH += \
  $$PWD/../../com/vgvgs/macros \
  $$PWD/../../com/vgvgs/core \
  $$PWD/../../com/vgvgs/patternify \
  $$PWD/../../com/vgvgs/resources \
  $$PWD/../../com/vgvgs/nexusbuilder

# Se copia la librería en la ruta destino del proyecto final.
# The library is copied to the destination path of the final project.
include (../../qmakeBuilders/copyBinaries.prf)

# Se definen las reglas y rutas de instalación del proyecto para las diferentes plataformas.
# The rules and installation paths of the project are defined for the different platforms.
include (../../qmakeBuilders/deploymentRulesBin.prf)
