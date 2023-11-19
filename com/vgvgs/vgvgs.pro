TEMPLATE = subdirs

SUBDIRS += \
  macros \
  core \
  nexusbuilder \
  patternify \
  resources

macros.subdir = macros
patternify.subdir = patternify
patternify.depends = macros
resources.subdir = resources
resources.depends = macros
core.subdir = core
core.depends = macros patternify
nexusbuilder.subdir = nexusbuilder
nexusbuilder.depends = macros patternify resources core
