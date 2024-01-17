#include "Xml.h"


using namespace NSLIB_UTILS;


QDomDocument *Xml::load ( QString fileName, bool readOnly ) {

  QFile *ioDeviceFile = Files::load ( fileName, readOnly ? QIODevice::ReadOnly : QIODevice::ReadWrite | QIODevice::Text );
  QDomDocument *doc = new QDomDocument ();
  if ( ioDeviceFile == nullptr ) {

    return doc;
  }
  if ( !doc->setContent ( ioDeviceFile ) ) {

    qDebug () << "No se pudo cargar el archivo XML.";
    ioDeviceFile->close ();
    return doc;
  }
  ioDeviceFile->close ();
  doc->normalize ();
  return doc;
}

bool Xml::save ( QString fileName, QDomDocument *domDocument ) {

  return Files::save ( fileName, QVariant::fromValue ( domDocument ), QIODevice::WriteOnly | QIODevice::Text );
}
