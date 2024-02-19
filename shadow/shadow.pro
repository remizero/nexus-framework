# Se definen las rutas de construcción del proyecto.
# The project construction routes are defined.
include(../qmakeBuilders/buildPaths.prf)

# Se define la estructura de directorios del proyecto final compilado.
# The directory structure of the final compiled project is defined.
include(../qmakeBuilders/createDirectoryStructure.prf)

QT -= gui

greaterThan(QT_MAJOR_VERSION, 5): QT +=

TARGET = shadow

# Normalización del nombre de proyecto.
# Project name normalization.
include (../qmakeBuilders/normalizeProjectName.prf)
TARGET = $$PROJECT_NAME

# Definiciones particulares del tipo de proyecto.
# Particular definitions of the project type.
include (../qmakeBuilders/projectLibConfiguration.prf)

# Se definen los parámetros de configuración del compilador.
# Compiler configuration parameters are defined.
include(../qmakeBuilders/buildConfiguration.prf)

SOURCES += \
  Shadow.cpp

HEADERS += \
  shadow_global.h \
  Shadow.h

# Se copia la librería en la ruta destino del proyecto final.
# The library is copied to the destination path of the final project.
include (../qmakeBuilders/copyLibraries.prf)

# Se definen las reglas y rutas de instalación del proyecto para las diferentes plataformas.
# The rules and installation paths of the project are defined for the different platforms.
include (../qmakeBuilders/deploymentRulesLib.prf)

# include (../qmakeBuilders/copyConfigFiles.prf)
# include (../qmakeBuilders/copyDataFiles.prf)
# include (../qmakeBuilders/copyIncludeFiles.prf)
# include (../qmakeBuilders/copyMediaFiles.prf)
# include (../qmakeBuilders/copyResourcesFiles.prf)
# include (../qmakeBuilders/copyTranslationFiles.prf)
