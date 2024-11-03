#include "Files.h"


using namespace NSLIB_UTILS;


QStringList Files::findFiles ( const QString &searchPath, const QString &filters ) {

  QStringList filesFound;
  // QDir searchDir ( searchPath );
  // QStringList filterList;
  // filterList << filters;
  // searchDir.setNameFilters ( filterList );
  // QFileInfoList fileInfoList = searchDir.entryInfoList ( QDir::Files );
  // for ( const QFileInfo &fileInfo : fileInfoList ) {

  //   filesFound.append ( fileInfo.absoluteFilePath () );
  // }

  QDirIterator it ( searchPath, QStringList () << filters, QDir::NoFilter, QDirIterator::Subdirectories );
  while ( it.hasNext () ) {

    filesFound.append ( it.nextFileInfo ().absoluteFilePath () );
  }
  return filesFound;
}

QFile *Files::load ( const QString fileName, QIODeviceBase::OpenMode openMode ) {

    // TODO Ver como aplicar https://doc.qt.io/qt-6/qfiledevice.html#Permission-enum
  if ( QFile::exists ( fileName ) ) {

    QFile *ioDeviceFile = new QFile ( fileName );
    if ( ioDeviceFile->open ( openMode ) ) {

      return ioDeviceFile;
      // if ( ioDeviceFile->isReadable () ) {

      //   return ioDeviceFile;

      // } else {

      //   qDebug () << "El archivo seleccionado \"" + fileName + "\" no se puede leer o está dañado.";
      // }
    } else {

      qDebug () << "El archivo seleccionado \"" + fileName + "\" no se puede abrir o está dañado.";
      // qDebug () << "Error al abrir el archivo:" << ioDeviceFile->errorString ();
      delete ioDeviceFile;
    }
  } else {

    qDebug () << "El archivo seleccionado \"" + fileName + "\" no existe o no se encuentra.";
  }
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

      stream << contentToSave.toString ().toUtf8 ();
      success = true;

    } else if ( contentToSave.canConvert<QDomDocument *> () ) {

      stream << contentToSave.value<QDomDocument *> ()->toString ().toUtf8 ();
      success = true;

    } else if ( contentToSave.canConvert<QJsonDocument> () ) {

      stream << contentToSave.value<QJsonDocument> ().toJson ();
      success = true;

    } else {

      qDebug () << "Tipo de dato no admitido para guardar en archivo.";
    }
    if ( success ) {

      qDebug () << "Datos guardados satisfactoriamente. Archivo: " + ioDeviceFile->fileName ();
    }
  } else {

    qDebug () << "El dispositivo de entrada/salida no permite el modo de escritura.";
  }
  if ( ioDeviceFile->isOpen () ) {

    ioDeviceFile->close ();
  }
  delete ioDeviceFile;
  return success;
}
