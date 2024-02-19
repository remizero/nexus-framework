# Se definen las rutas de construcción del proyecto.
# The project construction routes are defined.
include(../../qmakeBuilders/buildPaths.prf)

QT += core gui

greaterThan(QT_MAJOR_VERSION, 5): QT += widgets

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
  ACRegisterClasses.cpp \
  AttributeDialog.cpp \
  MethodDialog.cpp \
  commands/TypeCmd.cpp \
  CommandProcessor.cpp \
  main.cpp \
  MainWindow.cpp

HEADERS += \
  ACRegisterClasses.h \
  AttributeDialog.h \
  MethodDialog.h \
  commands/TypeCmd.h \
  CommandProcessor.h \
  MainWindow.h

RESOURCES += \
  resources.qrc

FORMS += \
  AttributeDialog.ui \
  MethodDialog.ui \
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
  -L$$LIB_PATH/ -lNexusBuilder \
  -L$$LIB_PATH/ -lNexusConsole
else:win32:CONFIG(debug, debug|release): LIBS += \
  -L$$LIB_PATH/ -lNexusMacros \
  -L$$LIB_PATH/ -lNexusPatternify \
  -L$$LIB_PATH/ -lNexusUtils \
  -L$$LIB_PATH/ -lNexusCore \
  -L$$LIB_PATH/ -lNexusResources \
  -L$$LIB_PATH/ -lNexusBuilder \
  -L$$LIB_PATH/ -lNexusConsole
else:unix: LIBS += \
  -L$$LIB_PATH/ -lNexusMacros \
  -L$$LIB_PATH/ -lNexusPatternify \
  -L$$LIB_PATH/ -lNexusUtils \
  -L$$LIB_PATH/ -lNexusCore \
  -L$$LIB_PATH/ -lNexusResources \
  -L$$LIB_PATH/ -lNexusBuilder \
  -L$$LIB_PATH/ -lNexusConsole

INCLUDEPATH += \
  $$PWD/../../vgvgs/nexus/nexus-nfk/nexusCore \
  $$PWD/../../vgvgs/nexus/nexus-nfk/nexusBuilder \
  $$PWD/../../vgvgs/nexus/nexus-nfk/nexusMacros \
  $$PWD/../../vgvgs/nexus/nexus-nfk/nexusPatternify \
  $$PWD/../../vgvgs/nexus/nexus-nfk/nexusResources \
  $$PWD/../../vgvgs/nexus/nexus-nfk/nexusUtils \
  $$PWD/../../vgvgs/nexus/nexus-nfk/nexusEssentials/nexusConsole \
  $$UI_DIR

DEPENDPATH += \
  $$PWD/../../vgvgs/nexus/nexus-nfk/nexusCore \
  $$PWD/../../vgvgs/nexus/nexus-nfk/nexusBuilder \
  $$PWD/../../vgvgs/nexus/nexus-nfk/nexusMacros \
  $$PWD/../../vgvgs/nexus/nexus-nfk/nexusPatternify \
  $$PWD/../../vgvgs/nexus/nexus-nfk/nexusResources \
  $$PWD/../../vgvgs/nexus/nexus-nfk/nexusUtils \
  $$PWD/../../vgvgs/nexus/nexus-nfk/nexusEssentials/nexusConsole \
  $$UI_DIR

# Se copia la librería en la ruta destino del proyecto final.
# The library is copied to the destination path of the final project.
include (../../qmakeBuilders/copyBinaries.prf)

# Se definen las reglas y rutas de instalación del proyecto para las diferentes plataformas.
# The rules and installation paths of the project are defined for the different platforms.
include (../../qmakeBuilders/deploymentRulesBin.prf)
