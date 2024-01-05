TEMPLATE = subdirs

SUBDIRS += \
  nexusBuilder \
  nexusCore \
  nexusEssentials \
  nexusMacros \
  nexusPatternify \
  nexusResources \
  nexusUtils

nexusBuilder.subdir = nexusBuilder
nexusBuilder.depends = nexusMacros nexusPatternify nexusUtils nexusCore nexusResources
nexusCore.subdir = nexusCore
nexusCore.depends = nexusMacros nexusPatternify nexusUtils
nexusEssentials.subdir = nexusEssentials
nexusEssentials.depends = nexusMacros nexusCore
nexusMacros.subdir = nexusMacros
nexusPatternify.subdir = nexusPatternify
nexusPatternify.depends = nexusMacros
nexusResources.subdir = nexusResources
nexusResources.depends = nexusMacros
nexusUtils.subdir = nexusUtils
nexusUtils.depends = nexusMacros
