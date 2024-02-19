#ifndef COLORSELECTOR_H
#define COLORSELECTOR_H

// Librerías Internas
// Internal Libraries
#include "Colorpicker_global.h"

// Librerías Externas
// External Libraries
#include "Macros_global.h"

/*
 *  the slider has a range of 0-360, sane as hue range
 *  so there is no need to convert the hue value passed to it
 *  It has a margin of 5 to give sapce for the triangle poniter
 */

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QMouseEvent>
#include <QPainter>
#include <QSlider>
#include <QStyleOptionSlider>
#include <QWidget>

// Librerías C++
// C++ Libraries


  namespace NS_VGVGS {

    namespace NS_NEXUS {

      namespace NS_ESSENTIALS {

        namespace NS_COLORPICKER {

          class COLORPICKER_EXPORT ColorSelector : public QSlider {

              Q_OBJECT

            public :
              QPoint currentColorPosition;
              QColor currentColor;
              ColorSelector ( QWidget *parent = nullptr );

              void grabCurrentColor ();

            signals :
              void colorChanged ( QColor color );

            protected :
              void paintEvent ( QPaintEvent *event );
              void mousePressEvent ( QMouseEvent *event ) override;
          };
        }
      }
    }
  }

#endif // COLORSELECTOR_H
