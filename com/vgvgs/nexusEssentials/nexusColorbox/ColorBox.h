#ifndef COLORBOX_H
#define COLORBOX_H

// Librerías Internas
// Internal Libraries
#include "Colorbox_global.h"

// Librerías Externas
// External Libraries
#include "Macros_global.h"
#include "ColorPickerDialog.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QColor>
#include <QColorDialog>
#include <QEvent>
#include <QKeyEvent>
#include <QLineEdit>

// Librerías C++
// C++ Libraries


namespace NS_LEVEL_1 {

  namespace NS_LEVEL_2 {

    namespace NS_NEXUS {

      namespace NS_ESSENTIALS {

        namespace NS_COLORBOX {

          class COLORBOX_EXPORT ColorBox : public QLineEdit {

              Q_OBJECT
              Q_PROPERTY ( QColor color READ getColor WRITE setColor USER true NOTIFY colorChanged )

            public :
              ColorBox ( QWidget *parent = nullptr );

              QColor getColor () const;
              QString getTextColor ();
              void setColor ( const QColor &color );

            public slots :
              void launchColorDialog ();

            signals :
              bool colorChanged ();

            protected :
              void keyPressEvent ( QKeyEvent *event ) override;

            private :
               QColor m_color;
              QAction *action;
              const QIcon getIcon ( const QColor &color );
          };
        }
      }
    }
  }
}

#endif // COLORBOX_H
