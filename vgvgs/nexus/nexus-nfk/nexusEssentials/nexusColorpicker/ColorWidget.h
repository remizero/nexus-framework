#ifndef COLORWIDGET_H
#define COLORWIDGET_H

// Librerías Internas
// Internal Libraries
#include "Colorpicker_global.h"

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

          class COLORPICKER_EXPORT ColorWidget : public QWidget {

              Q_OBJECT

            protected :
              const int maxH          = 360;
              const int maxSV         = 255;
              const int pointerR      = 5;
              const int pointerBorder = 2;

            protected :
              bool middlePresed;
              bool selectorDrawn;
              bool shiftHeld;
              bool ctrlHeld;
              QPixmap hSelectorPixmap;
              QImage hueLayerImage;
              QColor color;
              int h, s, v;
              qreal hf, sf, vf;
              int pointerX;
              int pointerY;

            public :
              explicit ColorWidget ( QWidget *parent = nullptr );

            protected :
              void drawCircle ( QPainter &p );
              void hideCursor ( QMouseEvent *event );
              void restoreCursor ();

            signals :
              void middlePressedSignal ( QMouseEvent *event );

            public slots :
              void shiftPressed ();
              void shiftReleased ();
              void ctrlPressed ();
              void ctrlReleased ();
          };
        }
      }
    }
  }

#endif // COLORWIDGET_H
