#ifndef COLORPICKERDIALOG_H
#define COLORPICKERDIALOG_H

// Librerías Internas
// Internal Libraries
#include "Colorpicker_global.h"
#include "ui_ColorPickerDialog.h"
#include "SVSelector.h"

// Librerías Externas
// External Libraries
#include "Macros_global.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QDialog>
#include <QtWidgets>

// Librerías C++
// C++ Libraries


namespace Ui {
  class ColorPickerDialog;
}

  namespace NS_VGVGS {

    namespace NS_NEXUS {

      namespace NS_ESSENTIALS {

        namespace NS_COLORPICKER {

          class COLORPICKER_EXPORT ColorPickerDialog : public QDialog {

              Q_OBJECT

            public :
              explicit ColorPickerDialog ( QWidget *parent = nullptr, QColor color = QColor ( "#ffffff" ) );
              ~ColorPickerDialog ();
              void updateHSV ( QColor color );
              void updateRGB ( QColor color );
              void updateCMY ( QColor color );
              void updateHexLabel ( QColor color );
              void CMYKUpdatesColor ( QColor color );
              QColor getColor ();

            private slots :
              void onHexLineEditTextEdited ( const QString &arg1 );
              void onSaveNewColorBtnClicked ();
              void onPickScreenColorBtnClicked ();
              void setNewColor ( QColor color );
              void setColorUnderCursor ( QColor color );
              void onCancelBtnClicked ();
              void onCurrentColorLabelClicked ();

            signals :
              void saveNewColor ( QColor color );
              void newColorUnderCursor ( QColor color );

            private :
              Ui::ColorPickerDialog *ui;
              QDialog *dummyWidget;
              QColor currentColor;

            protected :
              bool eventFilter ( QObject *obj, QEvent *event ) override;
              void resizeEvent ( QResizeEvent *event ) override;
          };
        }
      }
    }
  }

#endif // COLORPICKERDIALOG_H
