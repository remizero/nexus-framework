#include "Hash.h"


using namespace NSLIB_UTILS;


QString Hash::generate ( const QString &inputString, QCryptographicHash::Algorithm algorithm ) {

  QByteArray byteArray = inputString.toUtf8 ();
  QByteArray hashArray = QCryptographicHash::hash ( byteArray, algorithm );
  QString hashString = QString ( hashArray.toHex () );
  return hashString;
}
