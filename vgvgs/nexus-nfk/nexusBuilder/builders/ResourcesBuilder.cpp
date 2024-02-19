#include "ResourcesBuilder.h"


using namespace NSLIB_BUILDER;


ResourcesBuilder::ResourcesBuilder ( QObject *parent ) : QObject ( parent ) {}

QDomDocument *ResourcesBuilder::build ( QString resource, QMap<QString, QStringList> prefixFileMap ) {

  this->resource = NSLIB_UTILS::Xml::load ( resource, true );
  QDomElement root = this->resource->documentElement ();
  if ( root.tagName () != "RCC") {

    qDebug () << "Error: El documento XML debe tener un elemento raíz 'RCC'.";
    return nullptr;
  }
  for ( auto iterator = prefixFileMap.begin (); iterator != prefixFileMap.end (); ++iterator ) {

    QString prefix = iterator.key ();
    QStringList fileList = iterator.value ();
    QDomElement resourceElement = this->createResourceElement ( this->resource, prefix );
    for ( const QString &file : fileList ) {

      resourceElement.appendChild ( this->createFileElement ( resourceElement, file ) );
    }
    root.appendChild ( resourceElement );
  }
  return this->resource;
}

QDomElement ResourcesBuilder::createResourceElement ( QDomDocument *doc, const QString &prefix ) {

  QDomElement root = this->resource->documentElement ();
  QDomElement qResourceElement = doc->createElement ( "qresource" );
  qResourceElement.setAttribute ( "prefix", prefix );
  root.appendChild ( qResourceElement );
  return qResourceElement;
}

QDomElement ResourcesBuilder::createFileElement ( QDomElement &resourceElement, const QString &filePath ) {

  QDomElement fileElement = this->resource->createElement ( "file" );
  QDomText fileText = this->resource->createTextNode ( filePath );
  fileElement.appendChild ( fileText );
  resourceElement.appendChild ( fileElement );
  return fileElement;
}

void ResourcesBuilder::init ( QString resource ) {

  this->resource = NSLIB_UTILS::Xml::load ( resource );
  this->initialized = true;
}
