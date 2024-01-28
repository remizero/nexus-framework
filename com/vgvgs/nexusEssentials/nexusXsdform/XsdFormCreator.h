#ifndef XSDFORMCREATOR_H
#define XSDFORMCREATOR_H

// Librerías Internas
// Internal Libraries
#include "Xsdform_global.h"

// Librerías Externas
// External Libraries
#include "Macros_global.h"
#include "ColorBox.h"
#include "XsdElement.h"
#include "core/FacetAbs.h"
#include "core/PropertyAbs.h"
#include "core/TypeAbs.h"
#include "core/facets/AssertionsFacet.h"
#include "core/facets/EnumerationFacet.h"
#include "core/facets/ExplicitTimeZoneFacet.h"
#include "core/facets/FractionDigitsFacet.h"
#include "core/facets/LengthFacet.h"
#include "core/facets/MaxExclusiveFacet.h"
#include "core/facets/MaxInclusiveFacet.h"
#include "core/facets/MaxLengthFacet.h"
#include "core/facets/MinExclusiveFacet.h"
#include "core/facets/MinInclusiveFacet.h"
#include "core/facets/MinLengthFacet.h"
#include "core/facets/PatternFacet.h"
#include "core/facets/TotalDigitsFacet.h"
#include "core/facets/WhitespaceFacet.h"
#include "core/properties/NameProperty.h"
#include "core/properties/TypeProperty.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QColor>
#include <QComboBox>
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QObject>
#include <QScrollArea>
#include <QSpinBox>
#include <QTabWidget>
#include <QVBoxLayout>

// Librerías C++
// C++ Libraries


namespace NS_LEVEL_1 {

  namespace NS_LEVEL_2 {

    namespace NS_NEXUS {

      namespace NS_ESSENTIALS {

        namespace NS_XSDFORM {

          class XSDFORM_EXPORT XsdFormCreator {

            public :
              XsdFormCreator ();

              void createForm ( NSLIB_XSD::XsdElement *xsdElement, QWidget *parent );
              QTabWidget *getForm () const;

            private :
              QTabWidget *tabsDialog;

              void createGroup ( QWidget *widget, NSLIB_XSD::XsdElement *xsdElement );
              void createHexbinaryInput ( QWidget *widget, NSLIB_XSD::XsdElement *xsdElement );
              void createInputType ( QWidget *widget, NSLIB_XSD::XsdElement *xsdElement );
              void createIntegerInput ( QWidget *widget, NSLIB_XSD::XsdElement *xsdElement );
              void createParam ( QWidget *widget, NSLIB_XSD::XsdElement *xsdElement );
              void createParams ( QWidget *widget, QList<NSLIB_XSD::XsdElement *> xsdElementList );
              void createStringInput ( QWidget *widget, NSLIB_XSD::XsdElement *xsdElement );
              void createTab ( NSLIB_XSD::XsdElement *tabElement );
              void createTabs ( QList<NSLIB_XSD::XsdElement *> xsdElementList );
              QString getNameInput ( NSLIB_XSD::XsdElement *xsdElement );
          };
        }
      }
    }
  }
}

#endif // XSDFORMCREATOR_H
