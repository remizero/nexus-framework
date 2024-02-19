# Se definen las rutas de construcción del proyecto.
# The project construction routes are defined.
include(../../../../../../qmakeBuilders/buildPaths.prf)

QT       -= gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets xml

TARGET = nexusMenuRibbon

# Normalización del nombre de proyecto.
# Project name normalization.
include (../../../../../../qmakeBuilders/normalizeProjectName.prf)
TARGET = $$PROJECT_NAME

# Definiciones particulares del tipo de proyecto.
# Particular definitions of the project type.
include (../../../../../../qmakeBuilders/projectLibConfiguration.prf)

# Se definen los parámetros de configuración del compilador.
# Compiler configuration parameters are defined.
include(../../../../../../qmakeBuilders/buildConfiguration.prf)

SOURCES += \

HEADERS += \
  MenuRibbon_global.h

win32:CONFIG(release, debug|release): LIBS += \
  -L$$LIB_PATH/ -lNexusMacros \
  -L$$LIB_PATH/ -lNexusPatternify \
  -L$$LIB_PATH/ -lNexusResources \
  -L$$LIB_PATH/ -lNexusUtils \
  -L$$LIB_PATH/ -lNexusCore \
  -L$$LIB_PATH/ -lNexusXsd \
  -L$$LIB_PATH/ -lNexusColorpicker \
  -L$$LIB_PATH/ -lNexusColorbox \
  -L$$LIB_PATH/ -lNexusXsdform \
  -L$$LIB_PATH/ -lNexusActions
else:win32:CONFIG(debug, debug|release): LIBS += \
  -L$$LIB_PATH/ -lNexusMacros \
  -L$$LIB_PATH/ -lNexusPatternify \
  -L$$LIB_PATH/ -lNexusResources \
  -L$$LIB_PATH/ -lNexusUtils \
  -L$$LIB_PATH/ -lNexusCore \
  -L$$LIB_PATH/ -lNexusXsd \
  -L$$LIB_PATH/ -lNexusColorpicker \
  -L$$LIB_PATH/ -lNexusColorbox \
  -L$$LIB_PATH/ -lNexusXsdform \
  -L$$LIB_PATH/ -lNexusActions
else:unix: LIBS += \
  -L$$LIB_PATH/ -lNexusMacros \
  -L$$LIB_PATH/ -lNexusPatternify \
  -L$$LIB_PATH/ -lNexusResources \
  -L$$LIB_PATH/ -lNexusUtils \
  -L$$LIB_PATH/ -lNexusCore \
  -L$$LIB_PATH/ -lNexusXsd \
  -L$$LIB_PATH/ -lNexusColorpicker \
  -L$$LIB_PATH/ -lNexusColorbox \
  -L$$LIB_PATH/ -lNexusXsdform \
  -L$$LIB_PATH/ -lNexusActions

INCLUDEPATH += \
  $$PWD/../../../nexusMacros \
  $$PWD/../../../nexusPatternify \
  $$PWD/../../../nexusResources \
  $$PWD/../../../nexusUtils \
  $$PWD/../../../nexusCore \
  $$PWD/../../../nexusEngines/nexusXsd \
  $$UI_DIR \
  $$PWD/../../nexusColorpicker \
  $$PWD/../../nexusColorbox \
  $$PWD/../../nexusXsdform \
  $$PWD/../../nexusActions

DEPENDPATH += \
  $$PWD/../../../nexusMacros \
  $$PWD/../../../nexusPatternify \
  $$PWD/../../../nexusResources \
  $$PWD/../../../nexusUtils \
  $$PWD/../../../nexusCore \
  $$PWD/../../../nexusEngines/nexusXsd \
  $$UI_DIR \
  $$PWD/../../nexusColorpicker \
  $$PWD/../../nexusColorbox \
  $$PWD/../../nexusXsdform \
  $$PWD/../../nexusActions

# Se copia la librería en la ruta destino del proyecto final.
# The library is copied to the destination path of the final project.
include (../../../../../../qmakeBuilders/copyLibraries.prf)

# Se definen las reglas y rutas de instalación del proyecto para las diferentes plataformas.
# The rules and installation paths of the project are defined for the different platforms.
include (../../../../../../qmakeBuilders/deploymentRulesLib.prf)
