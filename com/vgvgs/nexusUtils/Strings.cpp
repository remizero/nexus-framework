#include "Strings.h"


using namespace NSLIB_UTILS;


QString Strings::capitalize ( QString string ) {

  return string.replace ( 0, 1, string [ 0 ].toUpper () );
}

QString Strings::load ( QString fileName, bool readOnly ) {

  QFile *ioDeviceFile = Files::load ( fileName, readOnly ? QIODevice::ReadOnly : QIODevice::ReadWrite | QIODevice::Text );
  if ( ioDeviceFile ) {

    QTextStream textStream ( ioDeviceFile );
    QString ioDeviceFileContent = textStream.readAll ();
    ioDeviceFile->close ();
    return ioDeviceFileContent;

  }
  qDebug () << "El archivo de texto no puedo ser cargado o no existe.";
  return nullptr;
}

QString Strings::normalizeClassName ( QString string ) {

  int pos = string.indexOf ( ":" );
  return string.remove ( 0, pos + 1 );
}

bool Strings::save ( QString *text, QString fileName ) {

  return Files::save ( fileName, QVariant::fromValue ( text ), QIODevice::WriteOnly | QIODevice::Text );
}
