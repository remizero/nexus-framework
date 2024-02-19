#include "UserConfig.h"


using namespace NSLIB_CORE;


UserConfig::UserConfig ( const QString userConfigFormat ) {

  QSettings::ReadFunc readFunction = nullptr;
  QSettings::WriteFunc writeFunction = nullptr;
  if ( userConfigFormat == "xml" ) {

    readFunction = ( QSettings::ReadFunc ) AppSettings::readXmlFile;
    writeFunction = ( QSettings::WriteFunc ) AppSettings::writeXmlFile;

  } else if ( userConfigFormat == "json" ) {

    readFunction = ( QSettings::ReadFunc ) AppSettings::readJsonFile;
    writeFunction = ( QSettings::WriteFunc ) AppSettings::writeJsonFile;
  }
  this->configFormat = QSettings::registerFormat ( userConfigFormat, readFunction, writeFunction );
  this->settings = new QSettings ( AppPaths::getInstance ()->getApplicationConfigPath () + "config." + userConfigFormat, this->configFormat );
}
