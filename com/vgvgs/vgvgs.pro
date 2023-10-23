TEMPLATE = subdirs

SUBDIRS += \
  macros \
  core \
  patternify

macros.subdir = macros
patternify.subdir = patternify
patternify.depends = macros
core.subdir = core
core.depends = macros patternify
