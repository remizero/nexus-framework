# Se definen las rutas de construcción del proyecto.
# The project construction routes are defined.
include(../../../../../qmakeBuilders/buildPaths.prf)

QT       -= gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets xml

TARGET = nexusDocumentation

# Normalización del nombre de proyecto.
# Project name normalization.
include (../../../../../qmakeBuilders/normalizeProjectName.prf)
TARGET = $$PROJECT_NAME

# Definiciones particulares del tipo de proyecto.
# Particular definitions of the project type.
include (../../../../../qmakeBuilders/projectLibConfiguration.prf)

# Se definen los parámetros de configuración del compilador.
# Compiler configuration parameters are defined.
include(../../../../../qmakeBuilders/buildConfiguration.prf)

SOURCES += \
    NexusDocumentation.cpp \
    Version.cpp

HEADERS += \
    Documentation_global.h \
    NexusDocumentation.h \
    Version.h

win32:CONFIG(release, debug|release): LIBS += \
  -L$$LIB_PATH/ -lNexusMacros \
  -L$$LIB_PATH/ -lNexusPatternify \
  -L$$LIB_PATH/ -lNexusResources \
  -L$$LIB_PATH/ -lNexusUtils \
  -L$$LIB_PATH/ -lNexusCore
else:win32:CONFIG(debug, debug|release): LIBS += \
  -L$$LIB_PATH/ -lNexusMacros \
  -L$$LIB_PATH/ -lNexusPatternify \
  -L$$LIB_PATH/ -lNexusResources \
  -L$$LIB_PATH/ -lNexusUtils \
  -L$$LIB_PATH/ -lNexusCore
else:unix: LIBS += \
  -L$$LIB_PATH/ -lNexusMacros \
  -L$$LIB_PATH/ -lNexusPatternify \
  -L$$LIB_PATH/ -lNexusResources \
  -L$$LIB_PATH/ -lNexusUtils \
  -L$$LIB_PATH/ -lNexusCore

INCLUDEPATH += \
  $$PWD/../../nexusMacros \
  $$PWD/../../nexusPatternify \
  $$PWD/../../nexusResources \
  $$PWD/../../nexusUtils \
  $$PWD/../../nexusCore

DEPENDPATH += \
  $$PWD/../../nexusMacros \
  $$PWD/../../nexusPatternify \
  $$PWD/../../nexusResources \
  $$PWD/../../nexusUtils \
  $$PWD/../../nexusCore

DISTFILES += \

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../../../../opt/xerces-c/lib/release/ -lxerces-c-3.2
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../../../../opt/xerces-c/lib/debug/ -lxerces-c-3.2
else:unix: LIBS += -L$$PWD/../../../../../../../../../opt/xerces-c/lib/ -lxerces-c-3.2

INCLUDEPATH += $$PWD/../../../../../../../../../opt/xerces-c/lib
DEPENDPATH += $$PWD/../../../../../../../../../opt/xerces-c/lib

# Se copia la librería en la ruta destino del proyecto final.
# The library is copied to the destination path of the final project.
include (../../../../../qmakeBuilders/copyLibraries.prf)

# Se copia los archivos cabecera en la ruta destino del proyecto final.
# Copy the header files to the destination path of the final project.
HEADER_FILE_LIST = $$files($$PWD/*.h,true)
include (../../../../../qmakeBuilders/copyIncludeFiles.prf)

# Se definen las reglas y rutas de instalación del proyecto para las diferentes plataformas.
# The rules and installation paths of the project are defined for the different platforms.
include (../../../../../qmakeBuilders/deploymentRulesLib.prf)
