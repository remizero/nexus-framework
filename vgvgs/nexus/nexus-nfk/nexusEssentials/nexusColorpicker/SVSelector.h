#ifndef SATVALUESELECTOR_H
#define SATVALUESELECTOR_H

// Librerías Internas
// Internal Libraries
#include "Colorpicker_global.h"
#include "ColorWidget.h"

// Librerías Externas
// External Libraries
#include "Macros_global.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QtWidgets>

// Librerías C++
// C++ Libraries


  namespace NS_VGVGS {

    namespace NS_NEXUS {

      namespace NS_ESSENTIALS {

        namespace NS_COLORPICKER {

          class COLORPICKER_EXPORT SVSelector : public ColorWidget {

              Q_OBJECT

            public :
              explicit SVSelector ( QWidget *parent = nullptr );
              void setS ( QColor color );
              void setV ( QColor color );
              void setSV ( int s, int v );

            protected :
              void paintEvent ( QPaintEvent *event );
              void mousePressEvent ( QMouseEvent *event );
              void mouseMoveEvent ( QMouseEvent *event );
              void mouseReleaseEvent ( QMouseEvent *event );
              void wheelEvent ( QWheelEvent *event );

            private :
              void updateColor ();
              void drawPointer ( QPainter &p );
              void correctPointer ();
              void movePointer ( int x, int y );
              void incPointerX ( int val );
              void decPointerX ( int val );
              void decPointerY ( int val );
              void incPointerY ( int val );
              void drawBorder ( QPainter &p );

            signals :
              void colorChanged ( QColor );
              void saturationChanged ( QColor );
              void valueChanged ( QColor );

            public slots :
              void changeHue ( QColor color );
          };
        }
      }
    }
  }

#endif // SATVALUESELECTOR_H
