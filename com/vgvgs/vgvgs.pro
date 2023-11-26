TEMPLATE = subdirs

SUBDIRS += \
  nexusBuilder \
  nexusCore \
  nexusEssentials \
  nexusMacros \
  nexusPatternify \
  nexusResources

nexusBuilder.subdir = nexusBuilder
nexusBuilder.depends = nexusMacros nexusPatternify nexusResources nexusCore
nexusCore.subdir = nexusCore
nexusCore.depends = nexusMacros nexusPatternify
nexusEssentials.subdir = nexusEssentials
nexusEssentials.depends = nexusMacros nexusCore
nexusMacros.subdir = nexusMacros
nexusPatternify.subdir = nexusPatternify
nexusPatternify.depends = nexusMacros
nexusResources.subdir = nexusResources
nexusResources.depends = nexusMacros
