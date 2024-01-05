#include "ProjectDirector.h"


using namespace NSLIB_BUILDER;


bool ProjectDirector::create ( ProjectInterface *project ) {

  if ( project->createProjectDir () ) {

      return true;
    // if ( project->createProFile () ) {

    //   if ( project->createDirStruct () ) {

    //     if ( project->createProjectFiles () ) {

    //       if ( project->createResourceFiles () ) {

    //         if ( project->createCommandFiles () ) {

    //           return true;

    //         } else {

    //           qDebug () << "No se pudo crear los archivos de comandos.";
    //         }
    //       } else {

    //         qDebug () << "No se pudo crear los archivos de recursos.";
    //       }
    //     } else {

    //       qDebug () << "No se pudo crear la estructura de directorios del proyecto.";
    //     }
    //   } else {

    //     qDebug () << "No se pudo crear los archivos del proyecto.";
    //   }
    // } else {

    //   qDebug () << "No se pudo crear el archivo .pro del proyecto.";
    // }
  } else {

    qDebug () << "No se pudo crear el directorio del proyecto.";
  }
  return false;
}
