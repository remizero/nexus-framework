# Se definen las rutas de construcción del proyecto.
# The project construction routes are defined.
include(../../qmakeBuilders/buildPaths.prf)

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 6): QT += widgets

TARGET = projectNameIdentifier

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
  RegisterClasses.cpp \
  commands/InfoCmd.cpp \
  commands/TypeCmd.cpp \
  main.cpp \
  MainWindow.cpp

HEADERS += \
  CommandProcessor.h \
  MainWindow.h \
  RegisterClasses.h \
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
  -L$$LIB_PATH/ -lNexusCore \
  -L$$LIB_PATH/ -lNexusPatternify
else:win32:CONFIG(debug, debug|release): LIBS += \
  -L$$LIB_PATH/ -lNexusMacros \
  -L$$LIB_PATH/ -lNexusCore \
  -L$$LIB_PATH/ -lNexusPatternify
else:unix: LIBS += \
  -L$$LIB_PATH/ -lNexusMacros \
  -L$$LIB_PATH/ -lNexusCore \
  -L$$LIB_PATH/ -lNexusPatternify

INCLUDEPATH += \
  $$PWD/../../com/vgvgs/nexusMacros \
  $$PWD/../../com/vgvgs/nexusCore \
  $$PWD/../../com/vgvgs/nexusPatternify

DEPENDPATH += \
  $$PWD/../../com/vgvgs/nexusMacros \
  $$PWD/../../com/vgvgs/nexusCore \
  $$PWD/../../com/vgvgs/nexusPatternify

# Se copia la librería en la ruta destino del proyecto final.
# The library is copied to the destination path of the final project.
include (../../qmakeBuilders/copyBinaries.prf)

# Se definen las reglas y rutas de instalación del proyecto para las diferentes plataformas.
# The rules and installation paths of the project are defined for the different platforms.
include (../../qmakeBuilders/deploymentRulesBin.prf)
