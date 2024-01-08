#include "ProjectDirector.h"


using namespace NSLIB_BUILDER;


bool ProjectDirector::create ( ProjectInterface *project ) {

  if ( project->createProjectDir () ) {

    if ( project->createDirStruct () ) {

      if ( project->createProFile () ) {

        if ( project->createProjectFiles () ) {

        //   if ( project->createResourceFiles () ) {

        //     if ( project->createCommandFiles () ) {

              return true;

    //         } else {

    //           qDebug () << "No se pudo crear los archivos de comandos.";
    //         }
    //       } else {

    //         qDebug () << "No se pudo crear los archivos de recursos.";
    //       }
        } else {

          qDebug () << "No se pudo crear los archivos del proyecto.";
        }
      } else {

        qDebug () << "No se pudo crear el archivo .pro del proyecto.";
      }
    } else {

      qDebug () << "No se pudo crear la estructura de directorios del proyecto.";
    }
  } else {

    qDebug () << "The project directory could not be created.";
  }
  return false;
}
