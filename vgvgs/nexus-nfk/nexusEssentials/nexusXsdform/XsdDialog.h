#ifndef XSDDIALOG_H
#define XSDDIALOG_H

// Librerías Internas
// Internal Libraries
#include "Xsdform_global.h"
#include "XsdFormCreator.h"

// Librerías Externas
// External Libraries
#include "Macros_global.h"
#include "ColorBox.h"
#include "Files.h"
#include "Xml.h"
#include "XsdElement.h"
#include "XsdEngine.h"
#include "appsystem/AppPaths.h"
#include "core/PropertyAbs.h"
#include "core/TypeAbs.h"
#include "core/properties/NameProperty.h"
#include "core/properties/TypeProperty.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QComboBox>
#include <QDialog>
#include <QDialogButtonBox>
#include <QtXml/QDomDocument>
#include <QtXml/QDomElement>
#include <QtXml/QDomNode>
#include <QFile>
#include <QGridLayout>
#include <QLineEdit>
#include <QObject>
#include <QPushButton>
#include <QSpinBox>
#include <QVBoxLayout>

// Librerías C++
// C++ Libraries


  namespace NS_VGVGS {

    namespace NS_NEXUS {

      namespace NS_ESSENTIALS {

        namespace NS_XSDFORM {

          class XSDFORM_EXPORT XsdDialog : public QObject {

              Q_OBJECT

            public :
              XsdDialog ( QWidget *parent );

              QDialog *getFormDialog () const;

            public slots :
              void acceptSlot ();
              void applySlot ();

            private :
                   QDialogButtonBox *buttonBox;
                       QDomDocument *domDocument;
                            QDialog *formDialog;
                        QVBoxLayout *formDialogLayout;
                        QGridLayout *mainLayout;
              NSLIB_XSD::XsdElement *xsdElement;
                     XsdFormCreator *xsdFormCreator;

              QString getNameInput ( QDomElement element );
              QWidget *getWidget ( QString objectName, QWidget *widget );
              NSLIB_XSD::XsdElement *getXsdElement ( QDomElement element , NSLIB_XSD::XsdElement *xsdElement );
              void loadData ( QDomNode element, QWidget *widget );
              QDomDocument loadXml ();
              void saveData ( QDomNode element, QWidget *widget );
          };
        }
      }
    }
  }

#endif // XSDDIALOG_H
