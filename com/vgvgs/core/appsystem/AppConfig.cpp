#include "AppConfig.h"


using namespace NAMESPACE_LIBRARY_CORE;


AppConfig::AppConfig () {

  QSettings::ReadFunc readFunction = ( QSettings::ReadFunc ) AppSettings::readXmlFile;
  QSettings::WriteFunc writeFunction = ( QSettings::WriteFunc ) AppSettings::writeXmlFile;
  this->configFormat = QSettings::registerFormat ( "xml", readFunction, writeFunction );
  this->settings = new QSettings ( ":/mainapp/config.xml", this->configFormat );
}
