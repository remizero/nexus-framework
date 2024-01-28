/**
 * Basado en el ejemplo Custom splashscreen with text de
 * https://wiki.qt.io/Custom_splashscreen_with_text
 */
#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

// Librerías Internas
// Internal Libraries
#include "Splashscreen_global.h"

// Librerías Externas
// External Libraries
#include "appsystem/AppPaths.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QDebug>
#include <QDir>
#include <QPainter>
#include <QtWidgets/QProgressBar>
#include <QSettings>
#include <QtWidgets/QSplashScreen>

// TODO https://amin-ahmadi.com/2016/03/15/how-to-add-a-splash-screen-for-your-qt-application/

// Librerías C++
// C++ Libraries


namespace NS_LEVEL_1 {

  namespace NS_LEVEL_2 {

    namespace NS_NEXUS {

      namespace NS_SPLASHSCREEN {

        class SPLASHSCREEN_EXPORT SplashScreen : public QSplashScreen {

            Q_OBJECT

          public :
            explicit SplashScreen ( QSettings *settings );
            ~SplashScreen ();
            void showStatusMessage ( const QString &message );

          public slots :
            void updateProgressValue ( int value );

          signals:
            void updateProgressValueSignal ( int value );

          private :
                     int alignement;
                  QColor textColor;
                 QString message;
                   QRect rect;
            QProgressBar *progressBar;
            void configFont ( QString family, bool bold, int fontSize, int fontStretch );
            void configProgressBar ( bool textvisible, QString textalignment, bool invertedappearance, int x, int y, int w, int h, QString orientation, int textdirection, QString format, int max, int min, QString backgroundcolor );
            void setMessageRect ( QRect rect, int alignement = Qt::AlignLeft );
            virtual void drawContents ( QPainter *painter );
        };
      }
    }
  }
}

#endif // SPLASHSCREEN_H
