TEMPLATE = subdirs

SUBDIRS += \
  nexusBuilder \
  nexusCore \
  nexusEngines \
  nexusEssentials \
  nexusMacros \
  nexusPatternify \
  nexusResources \
  nexusUtils

# Se definen las rutas, archivos pro y dependencias de los subproyectos.
# The paths, pro files and dependencies of the subprojects are defined.
nexusMacros.subdir = nexusMacros

nexusUtils.subdir = nexusUtils
nexusUtils.depends = nexusMacros

nexusPatternify.subdir = nexusPatternify
nexusPatternify.depends = nexusMacros

nexusResources.subdir = nexusResources
nexusResources.depends = nexusMacros

nexusCore.subdir = nexusCore
nexusCore.depends = nexusMacros nexusPatternify nexusUtils

nexusBuilder.subdir = nexusBuilder
nexusBuilder.depends = nexusMacros nexusPatternify nexusUtils nexusResources nexusCore

nexusEngines.subdir = nexusEngines
nexusEngines.depends = nexusMacros nexusPatternify nexusUtils nexusResources nexusCore

nexusEssentials.subdir = nexusEssentials
nexusEssentials.depends = nexusMacros nexusPatternify nexusUtils nexusResources nexusCore nexusEngines
