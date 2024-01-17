#include "Files.h"


using namespace NSLIB_UTILS;


QFile *Files::load ( const QString fileName, QIODeviceBase::OpenMode openMode ) {

  QFile *ioDeviceFile = new QFile ( fileName );
  // if ( ioDeviceFile->exists () ) {

    if ( ioDeviceFile->open ( openMode ) ) {

      return ioDeviceFile;
      // if ( ioDeviceFile->isReadable () ) {

      //   return ioDeviceFile;

      // } else {

      //   qDebug () << "El archivo seleccionado \"" + fileName + "\" no se puede leer o está dañado.";
      // }
    } else {

      qDebug () << "El archivo seleccionado \"" + fileName + "\" no se puede abrir o está dañado.";
    }
  // } else {

  //   qDebug () << "El archivo seleccionado \"" + fileName + "\" no existe o no se encuentra.";
  // }
  delete ioDeviceFile;
  return nullptr;
}

bool Files::save ( const QString fileName, const QVariant &contentToSave, QIODeviceBase::OpenMode openMode ) {

  return Files::save ( Files::load ( fileName, openMode ), contentToSave );
}

bool Files::save ( QFile *ioDeviceFile, const QVariant &contentToSave ) {

  bool success = false;
  if ( ioDeviceFile->isWritable () ) {

    QTextStream stream ( ioDeviceFile );
    if ( contentToSave.canConvert<QString> () ) {

      stream << contentToSave.toString ();
      success = true;
      qDebug () << "Datos guardados satisfactoriamente. Archivo: " + ioDeviceFile->fileName ();

    } else if ( contentToSave.canConvert<QDomDocument *> () ) {

      stream << contentToSave.value<QDomDocument *> ()->toString ();
      success = true;
      qDebug () << "Datos guardados satisfactoriamente. Archivo: " + ioDeviceFile->fileName ();

    } else if ( contentToSave.canConvert<QJsonDocument> () ) {

      stream << contentToSave.value<QJsonDocument> ().toJson ();
      success = true;
      qDebug () << "Datos guardados satisfactoriamente. Archivo: " + ioDeviceFile->fileName ();

    } else {

      qDebug () << "Tipo de dato no admitido para guardar en archivo.";
    }
  } else {

    qDebug () << "El dispositivo de entrada/salida no permite el modo de escritura.";
  }
  ioDeviceFile->close ();
  delete ioDeviceFile;
  return success;
}
