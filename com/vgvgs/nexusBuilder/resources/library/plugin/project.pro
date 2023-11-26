# Se definen las rutas de construcción del proyecto.
# The project construction routes are defined.
include(../../../../qmakeBuilders/buildPaths.prf)

# QT -= gui

greaterThan(QT_MAJOR_VERSION, 6): QT += gui

TARGET = {{project}}
CONFIG       += plugin

# Normalización del nombre de proyecto.
# Project name normalization.
include (../../../../qmakeBuilders/normalizeProjectName.prf)
TARGET = $$PROJECT_NAME

# Definiciones particulares del tipo de proyecto.
# Particular definitions of the project type.
include (../../../../qmakeBuilders/projectLibShareConfiguration.prf)

# Se definen los parámetros de configuración del compilador.
# Compiler configuration parameters are defined.
include(../../../../qmakeBuilders/buildConfiguration.prf)

SOURCES += \
  CLASSNAME.cpp \
  Version.cpp

HEADERS += \
  CLASSNAME_global.h \
  CLASSNAME.h \
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
  $$PWD/../../nexusMacros \
  $$PWD/../../nexusPatternify \
  $$PWD/../../nexusCore

DEPENDPATH += \
  $$PWD/../../nexusMacros \
  $$PWD/../../nexusPatternify \
  $$PWD/../../nexusCore

# Se copia la librería en la ruta destino del proyecto final.
# The library is copied to the destination path of the final project.
include (../../../../qmakeBuilders/copyPlugins.prf)

# Se definen las reglas y rutas de instalación del proyecto para las diferentes plataformas.
# The rules and installation paths of the project are defined for the different platforms.
include (../../../../qmakeBuilders/deploymentRulesLib.prf)

DISTFILES += \
  CLASSNAME.json
