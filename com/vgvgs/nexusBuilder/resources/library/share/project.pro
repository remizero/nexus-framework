# Se definen las rutas de construcción del proyecto.
# The project construction routes are defined.
include(../../../qmakeBuilders/buildPaths.prf)

# QT -= gui

greaterThan(QT_MAJOR_VERSION, 5): QT += widgets core

TARGET = {{project}}

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
  Version.cpp

HEADERS += \
  CLASSNAME_global.h \
  Version.h

win32:CONFIG(release, debug|release): LIBS += \
  -L$$LIB_PATH/ -lNexusMacros \
  -L$$LIB_PATH/ -lNexusPatternify \
  -L$$LIB_PATH/ -lNexusCore
else:win32:CONFIG(debug, debug|release): LIBS += \
  -L$$LIB_PATH/ -lNexusMacros \
  -L$$LIB_PATH/ -lNexusPatternify \
  -L$$LIB_PATH/ -lNexusCore
else:unix: LIBS += \
  -L$$LIB_PATH/ -lNexusMacros \
  -L$$LIB_PATH/ -lNexusPatternify \
  -L$$LIB_PATH/ -lNexusCore

INCLUDEPATH += \
  $$PWD/../nexusCore \
  $$PWD/../nexusMacros \
  $$PWD/../nexusPatternify

DEPENDPATH += \
  $$PWD/../nexusCore \
  $$PWD/../nexusMacros \
  $$PWD/../nexusPatternify

# Se copia la librería en la ruta destino del proyecto final.
# The library is copied to the destination path of the final project.
include (../../../qmakeBuilders/copyLibraries.prf)

# Se definen las reglas y rutas de instalación del proyecto para las diferentes plataformas.
# The rules and installation paths of the project are defined for the different platforms.
include (../../../qmakeBuilders/deploymentRulesLib.prf)
