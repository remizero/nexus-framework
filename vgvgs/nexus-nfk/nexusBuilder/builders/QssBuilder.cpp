#include "QssBuilder.h"


using namespace NSLIB_BUILDER;


QssBuilder::QssBuilder ( QObject *parent ) : QObject ( parent ) {}

QString QssBuilder::build ( QString resource ) {

  // TODO Revisar https://github.com/GTRONICK/QSS/blob/master/ConsoleStyle.qss
    // https://doc.qt.io/qt-6/stylesheet-reference.html
    // https://doc.qt.io/qt-6/stylesheet-syntax.html
    // https://github.com/Jihadist/qt-stylesheets
    // https://doc.qt.io/qtforpython-6/tutorials/basictutorial/widgetstyling.html
    // https://stackoverflow.com/questions/67246448/how-to-change-frame-style-using-qss
  QString fileContent = NexusBuilderUtils::loadFileContent ( resource );
  // for ( const QString &resourceFile : resourceList ) {

  //   QStringList resourceFileSplit = resourceFile.split ( QDir::separator () );
  //   fileContent += QString ( "  qInitResources_" ) + resourceFileSplit.last ();
  // }
  // fileContent += QString ( "\n" );
  return fileContent;
}
