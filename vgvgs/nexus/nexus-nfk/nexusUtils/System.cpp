#include "System.h"


using namespace NSLIB_UTILS;


QString System::getNameUser () {

  QProcess processWhoami;
  processWhoami.start ( "whoami" );
  processWhoami.waitForFinished ();
  return processWhoami.readAllStandardOutput ().trimmed ();
}

QString System::getUser () {

  QString fullName;
  QString username = System::getNameUser ();

  // Usar "getent passwd" para obtener la información del usuario
  QProcess process;
  process.start ( "getent", QStringList () << "passwd" << username );
  process.waitForFinished ();

  QString userInfo = process.readAllStandardOutput ().trimmed ();
  if ( !userInfo.isEmpty () ) {

    // Dividir la información del usuario en campos
    QStringList userFields = userInfo.split ( ':' );
    if ( userFields.size () > 4 ) {

      QStringList nameSplit = userFields [ 4 ].split ( ',' );  // El quinto campo contiene el nombre completo
      fullName = nameSplit [ 0 ];

    } else {

      fullName = "No se pudo obtener el nombre completo del usuario.";
    }
  } else {

    fullName = "No se encontró información para el usuario: " + username;
  }
  return fullName;
}
