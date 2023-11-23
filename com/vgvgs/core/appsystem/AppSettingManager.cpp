#include "AppSettingManager.h"


using namespace NSLIB_CORE;


AppSettingManager::AppSettingManager ( QObject *parent ) : QObject ( parent ) {}

void AppSettingManager::initialize () {

  this->appConfigFormat = QSettings::registerFormat ( "xml", ( QSettings::ReadFunc ) AppSettings::readXmlFile, ( QSettings::WriteFunc ) AppSettings::writeXmlFile );
  QString type;
  QSettings::ReadFunc readFunction = nullptr;
  QSettings::WriteFunc writeFunction = nullptr;
  if ( type == "xml" ) {

    readFunction = ( QSettings::ReadFunc ) AppSettings::readXmlFile;
    writeFunction = ( QSettings::WriteFunc ) AppSettings::writeXmlFile;

  } else   if ( type == "json" ) {

//    readFunction = ( QSettings::ReadFunc ) AppSettings::readJsonFile;
//    writeFunction = ( QSettings::WriteFunc ) AppSettings::writeJsonFile;
  }
  QSettings::registerFormat ( type, readFunction, writeFunction );
}

const QSettings::Format &AppSettingManager::getUserConfigFormat () const {

  return this->userConfigFormat;
}

void AppSettingManager::setUserConfigFormat ( const QSettings::Format &newUserConfigFormat ) {

  this->userConfigFormat = newUserConfigFormat;
}
