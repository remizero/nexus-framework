#include "Json.h"


using namespace NSLIB_UTILS;


QJsonDocument *Json::load ( QString fileName, bool readOnly ) {

  QFile *ioDeviceFile = Files::load ( fileName, readOnly ? QIODevice::ReadOnly : QIODevice::ReadWrite | QIODevice::Text );
  if ( ioDeviceFile ) {

    QByteArray jsonData = ioDeviceFile->readAll ();
    ioDeviceFile->close ();
    QJsonParseError error;
    QJsonDocument *jsonDoc = new QJsonDocument ( QJsonDocument::fromJson ( jsonData, &error ) );
    if ( jsonDoc->isNull () && error.error != QJsonParseError::NoError ) {

      qDebug () << "El archivo JSON no puedo ser leido o está dañado.";
      qDebug() << "Error al parsear el JSON:" << error.errorString ();
      delete jsonDoc;
      return nullptr;
    }
    return jsonDoc;
  }
  qDebug () << "El archivo JSON no puedo ser cargado o no existe.";
  return nullptr;
}

bool Json::save ( QString fileName, QJsonDocument *jsonDocument ) {

  return Files::save ( fileName, QVariant::fromValue ( jsonDocument ), QIODevice::WriteOnly | QIODevice::Text );
}
