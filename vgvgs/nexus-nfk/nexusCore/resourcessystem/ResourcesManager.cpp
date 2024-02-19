#include "ResourcesManager.h"


using namespace NSLIB_CORE;


ResourcesManager::ResourcesManager ( QObject *parent ) : QObject ( parent ) {}

QJsonDocument *ResourcesManager::loadJson ( const QString &resourcePath ) {

  return NSLIB_UTILS::Json::load ( resourcePath, true );
}

QImage ResourcesManager::loadImage ( const QString &resourcePath, QString imageType ) {

  // TODO Implementar.
  return QImage ();
}

QString ResourcesManager::loadIni ( const QString &resourcePath ) {

  // TODO Implementar.
  return QString ( "" );
}

QString ResourcesManager::loadTextFile ( const QString &resourcePath ) {

  return NSLIB_UTILS::Strings::load ( resourcePath, true );
}

QDomDocument *ResourcesManager::loadXml ( const QString &resourcePath ) {

  return NSLIB_UTILS::Xml::load ( resourcePath, true );
}
