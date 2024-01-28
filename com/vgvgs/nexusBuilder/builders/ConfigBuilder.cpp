#include "ConfigBuilder.h"


using namespace NSLIB_BUILDER;


ConfigBuilder::ConfigBuilder ( QObject *parent ) : QObject ( parent ) {}

QDomDocument *ConfigBuilder::build ( QString resource, const QString &projectName, NexusBuilder::ProjectId projectType ) {

  this->resource = NSLIB_UTILS::Xml::load ( resource, true );
  qDebug () << this->resource->toString ();
  QDomElement root = this->resource->documentElement ();
  if ( root.tagName () != "settings") {

    qDebug () << "Error: El documento XML debe tener un elemento raíz 'settings'.";
    return nullptr;
  }
  // QDomElement appElement = xmlDoc.firstChildElement ( "settings" ).firstChildElement ( "app" );
  // modifyXmlElement ( appElement, "applicationdisplayname", "Nuevo Nombre" );

  return this->resource;
}

void ConfigBuilder::modifyXmlElement ( QDomElement &parent, const QString &elementName, const QString &newValue ) {

  QDomNodeList nodeList = parent.elementsByTagName ( elementName );
  if ( nodeList.size () == 1 ) {

    QDomElement element = nodeList.at ( 0 ).toElement ();
    element.firstChild ().setNodeValue ( newValue );
  }
}
