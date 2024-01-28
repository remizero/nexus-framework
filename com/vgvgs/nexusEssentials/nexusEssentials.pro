TEMPLATE = subdirs

SUBDIRS += \
  nexusActions \
  nexusColorbox \
  nexusColorpicker \
  nexusMainwindow \
  nexusMenubar \
  nexusSingleinstance \
  nexusSplashscreen \
  nexusStatusbar \
  nexusSystemtrayicon \
  nexusXsdform

# Se definen las rutas, archivos pro y dependencias de los subproyectos.
# The paths, pro files and dependencies of the subprojects are defined.
nexusColorpicker.subdir = nexusColorpicker
#nexusColorpicker.depends =

nexusSingleinstance.subdir = nexusSingleinstance
#nexusSingleinstance.depends =

nexusSplashscreen.subdir = nexusSplashscreen
#nexusSplashscreen.depends =

nexusStatusbar.subdir = nexusStatusbar
#nexusStatusbar.depends =

nexusSystemtrayicon.subdir = nexusSystemtrayicon
#nexusSystemtrayicon.depends =

nexusColorbox.subdir = nexusColorbox
nexusColorbox.depends = nexusColorpicker

nexusXsdform.subdir = nexusXsdform
nexusXsdform.depends = nexusColorpicker nexusColorbox

nexusActions.subdir = nexusActions
nexusActions.depends = nexusColorpicker nexusColorbox nexusXsdform

nexusMenubar.subdir = nexusMenubar
nexusMenubar.depends = nexusColorpicker nexusColorbox nexusXsdform nexusActions

nexusMainwindow.subdir = nexusMainwindow
nexusMainwindow.depends = nexusStatusbar nexusSystemtrayicon nexusColorpicker nexusColorbox nexusXsdform nexusActions nexusMenubar
