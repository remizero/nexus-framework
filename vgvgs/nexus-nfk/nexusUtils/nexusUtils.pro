# Se definen las rutas de construcción del proyecto.
# The project construction routes are defined.
include(../../../qmakeBuilders/buildPaths.prf)

QT       -= gui

greaterThan(QT_MAJOR_VERSION, 5): QT += widgets xml

TARGET = nexusUtils

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
  Enumeration.cpp \
  Hash.cpp \
  Json.cpp \
  Utils.cpp \
  Strings.cpp \
  Files.cpp \
  Xml.cpp \
  Version.cpp

HEADERS += \
  Hash.h \
  Json.h \
  Utils_global.h \
  Enumeration.h \
  Utils.h \
  Strings.h \
  Files.h \
  Xml.h \
  Version.h

win32:CONFIG(release, debug|release): LIBS += \
  -L$$LIB_PATH/ -lNexusMacros
else:win32:CONFIG(debug, debug|release): LIBS += \
  -L$$LIB_PATH/ -lNexusMacros
else:unix: LIBS += \
  -L$$LIB_PATH/ -lNexusMacros

INCLUDEPATH += \
  $$PWD/../nexusMacros

DEPENDPATH += \
  $$PWD/../nexusMacros

# Se copia la librería en la ruta destino del proyecto final.
# The library is copied to the destination path of the final project.
include (../../../qmakeBuilders/copyLibraries.prf)

# Se definen las reglas y rutas de instalación del proyecto para las diferentes plataformas.
# The rules and installation paths of the project are defined for the different platforms.
include (../../../qmakeBuilders/deploymentRulesLib.prf)
