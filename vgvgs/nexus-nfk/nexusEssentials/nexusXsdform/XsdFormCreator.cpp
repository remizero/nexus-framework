#include "XsdFormCreator.h"
#include <QDebug>

using namespace NSLIB_XSDFORM;

XsdFormCreator::XsdFormCreator () {}

void XsdFormCreator::createForm ( NSLIB_XSD::XsdElement *xsdElement, QWidget *parent ) {

  this->tabsDialog = new QTabWidget ( parent );
  this->tabsDialog->setObjectName ( this->getNameInput ( xsdElement ) + "Input" );
  const int tabsCount = xsdElement->getElementsList ().count ();
  if ( tabsCount > 0 ) {

    this->createTabs ( xsdElement->getElementsList () );
  }
}

void XsdFormCreator::createGroup ( QWidget *widget, NSLIB_XSD::XsdElement *xsdElement ) {

  QGroupBox *groupBoxElement = new QGroupBox ( widget );
  groupBoxElement->setObjectName ( this->getNameInput ( xsdElement ) + "Input" );
  groupBoxElement->setTitle ( ( ( NSLIB_XSD::NameProperty * ) xsdElement->getProperty ( "NameProperty" ) )->getValue () );
  QGridLayout *groupBoxElementLayout = new QGridLayout ( groupBoxElement );
  groupBoxElement->setLayout ( groupBoxElementLayout );
  ( ( QGridLayout * ) widget->layout () )->addWidget ( groupBoxElement, ( ( QGridLayout * ) widget->layout () )->rowCount (), 0, 6, 6, Qt::AlignBaseline );

  const int paramsCount = xsdElement->getElementsList ().count ();
  if ( paramsCount > 0 ) {

    this->createParams ( groupBoxElement, xsdElement->getElementsList () );
    groupBoxElementLayout->setRowStretch ( groupBoxElementLayout->rowCount (), 1 );
    groupBoxElementLayout->setColumnStretch ( groupBoxElementLayout->columnCount (), 1 );
  }
}

void XsdFormCreator::createHexbinaryInput ( QWidget *widget, NSLIB_XSD::XsdElement *xsdElement ) {

  const int facetsCount = xsdElement->getFacets ().count ();
  for ( int i = 0; i < facetsCount; i++ ) {

    if ( xsdElement->isEnumerate () ) {

      ( ( QComboBox * ) widget )->addItem ( ( ( NSLIB_XSD::EnumerationFacet * ) xsdElement->getFacets ().at ( i ) )->getValue () );

    } else {

      if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "NSLIB_XSD::AssertionsFacet" ) == 0 ) {

        // TODO: No implementado aun
        //( ( QSpinBox * ) widget )->

      } else if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "NSLIB_XSD::LengthFacet" ) == 0 ) {

        ( ( QLineEdit * ) widget )->setMaxLength ( ( ( NSLIB_XSD::LengthFacet * ) xsdElement->getFacets ().at ( i ) )->getValue ().toInt () );

      } else if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "NSLIB_XSD::MaxLengthFacet" ) == 0 ) {

        ( ( QLineEdit * ) widget )->setMaxLength ( ( ( NSLIB_XSD::MaxLengthFacet * ) xsdElement->getFacets ().at ( i ) )->getValue ().toInt () );

      } else if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "NSLIB_XSD::MinLengthFacet" ) == 0 ) {

        // TODO: No implementado aun
        //( ( QLineEdit * ) widget )->setMaxLength ( ( ( NSLIB_XSD::MinLengthFacet * ) xsdElement->getFacets ().at ( i ) )->getValue ().toInt () );

      } else if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "NSLIB_XSD::PatternFacet" ) == 0 ) {

        ( ( QLineEdit * ) widget )->setInputMask ( ( ( NSLIB_XSD::PatternFacet * ) xsdElement->getFacets ().at ( i ) )->getValue ()  );

      }
    }
  }
}

void XsdFormCreator::createInputType ( QWidget *widget, NSLIB_XSD::XsdElement *xsdElement ) {

  NSLIB_XSD::TypeProperty *objTypeProperty = ( NSLIB_XSD::TypeProperty * ) xsdElement->getProperty ( "TypeProperty" );
  switch ( objTypeProperty->getValue () ) {

    case NSLIB_XSD::TypeAbs::ANYURI:


      break;

    case NSLIB_XSD::TypeAbs::BASE64BINARY:


      break;

    case NSLIB_XSD::TypeAbs::BOOLEAN:


      break;

    case NSLIB_XSD::TypeAbs::BYTE:


      break;

    case NSLIB_XSD::TypeAbs::DATETIMESTAMP:


      break;

    case NSLIB_XSD::TypeAbs::DATETIME:


      break;

    case NSLIB_XSD::TypeAbs::DATE:


      break;

    case NSLIB_XSD::TypeAbs::DAYTIMEDURATION:


      break;

    case NSLIB_XSD::TypeAbs::DECIMAL:


      break;

    case NSLIB_XSD::TypeAbs::DOUBLE:


      break;

    case NSLIB_XSD::TypeAbs::DURATION:


      break;

    case NSLIB_XSD::TypeAbs::ENTITIES:


      break;

    case NSLIB_XSD::TypeAbs::ENTITY:


      break;

    case NSLIB_XSD::TypeAbs::FLOAT:


      break;

    case NSLIB_XSD::TypeAbs::GDAY:


      break;

    case NSLIB_XSD::TypeAbs::GMONTHDAY:


      break;

    case NSLIB_XSD::TypeAbs::GMONTH:


      break;

    case NSLIB_XSD::TypeAbs::GYEARMONTH:


      break;

    case NSLIB_XSD::TypeAbs::GYEAR:


      break;

    case NSLIB_XSD::TypeAbs::HEXBINARY:

      this->createHexbinaryInput ( widget, xsdElement );
      break;

    case NSLIB_XSD::TypeAbs::IDREFS:


      break;

    case NSLIB_XSD::TypeAbs::IDREF:


      break;

    case NSLIB_XSD::TypeAbs::ID:


      break;

    case NSLIB_XSD::TypeAbs::INTEGER:

      this->createIntegerInput ( widget, xsdElement );
      break;

    case NSLIB_XSD::TypeAbs::INT:

      this->createIntegerInput ( widget, xsdElement );
      break;

    case NSLIB_XSD::TypeAbs::LANGUAGE:


      break;

    case NSLIB_XSD::TypeAbs::LONG:


      break;

    case NSLIB_XSD::TypeAbs::NAME:


      break;

    case NSLIB_XSD::TypeAbs::NCNAME:


      break;

    case NSLIB_XSD::TypeAbs::NEGATIVEINTEGER:


      break;

    case NSLIB_XSD::TypeAbs::NMTOKENS:


      break;

    case NSLIB_XSD::TypeAbs::NMTOKEN:


      break;

    case NSLIB_XSD::TypeAbs::NONNEGATIVEINTEGER:


      break;

    case NSLIB_XSD::TypeAbs::NONPOSITIVEINTEGER:


      break;

    case NSLIB_XSD::TypeAbs::NORMALIZEDSTRING:


      break;

    case NSLIB_XSD::TypeAbs::NOTATION:


      break;

    case NSLIB_XSD::TypeAbs::POSITIVEINTEGER:


      break;

    case NSLIB_XSD::TypeAbs::QNAME:


      break;

    case NSLIB_XSD::TypeAbs::SHORT:


      break;

    case NSLIB_XSD::TypeAbs::STRING:

      this->createStringInput ( widget, xsdElement );
      break;

    case NSLIB_XSD::TypeAbs::TIME:


      break;

    case NSLIB_XSD::TypeAbs::TOKEN:


      break;

    case NSLIB_XSD::TypeAbs::UNSIGNEDBYTE:


      break;

    case NSLIB_XSD::TypeAbs::UNSIGNEDINT:


      break;

    case NSLIB_XSD::TypeAbs::UNSIGNEDLONG:


      break;

    case NSLIB_XSD::TypeAbs::UNSIGNEDSHORT:


      break;

    case NSLIB_XSD::TypeAbs::YEARMONTHDURATION:


      break;

    default:

      break;
  }
}

void XsdFormCreator::createIntegerInput ( QWidget *widget, NSLIB_XSD::XsdElement *xsdElement ) {

  const int facetsCount = xsdElement->getFacets ().count ();
  for ( int i = 0; i < facetsCount; i++ ) {

    if ( xsdElement->isEnumerate () ) {

      ( ( QComboBox * ) widget )->addItem ( ( ( NSLIB_XSD::EnumerationFacet * ) xsdElement->getFacets ().at ( i ) )->getValue () );

    } else {

      if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "NSLIB_XSD::AssertionsFacet" ) == 0 ) {

        // TODO: No implementado aun
        //( ( QSpinBox * ) widget )->

      } else if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "NSLIB_XSD::MaxExclusiveFacet" ) == 0 ) {

        ( ( QSpinBox * ) widget )->setMaximum ( ( ( NSLIB_XSD::MaxExclusiveFacet * ) xsdElement->getFacets ().at ( i ) )->getValue ().toInt () - 1 );

      } else if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "NSLIB_XSD::MaxInclusiveFacet" ) == 0 ) {

        ( ( QSpinBox * ) widget )->setMaximum ( ( ( NSLIB_XSD::MaxExclusiveFacet * ) xsdElement->getFacets ().at ( i ) )->getValue ().toInt () );

      } else if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "NSLIB_XSD::MinExclusiveFacet" ) == 0 ) {

        ( ( QSpinBox * ) widget )->setMinimum ( ( ( NSLIB_XSD::MaxExclusiveFacet * ) xsdElement->getFacets ().at ( i ) )->getValue ().toInt () + 1 );

      } else if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "NSLIB_XSD::MinInclusiveFacet" ) == 0 ) {

        ( ( QSpinBox * ) widget )->setMinimum ( ( ( NSLIB_XSD::MaxExclusiveFacet * ) xsdElement->getFacets ().at ( i ) )->getValue ().toInt ()  );

      } else if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "NSLIB_XSD::TotalDigitsFacet" ) == 0 ) {

        // TODO: No implementado aun
        //( ( QSpinBox * ) widget )->
      }
    }
  }
}

void XsdFormCreator::createParam ( QWidget *widget, NSLIB_XSD::XsdElement *xsdElement ) {

  QLabel *paramLabel = new QLabel ( widget );
  paramLabel->setText ( ( ( NSLIB_XSD::NameProperty * ) xsdElement->getProperty ( "NameProperty" ) )->getValue () );
  ( ( QGridLayout * ) widget->layout () )->addWidget ( paramLabel, ( ( QGridLayout * ) widget->layout () )->rowCount (), 0, 1, 1, Qt::AlignRight );
  NSLIB_XSD::TypeProperty *objTypeProperty = ( NSLIB_XSD::TypeProperty * ) xsdElement->getProperty ( "TypeProperty" );

  if ( xsdElement->isEnumerate () ) {

    QComboBox *comboBox = new QComboBox ( widget );
    comboBox->setMaximumHeight ( 18 );
    comboBox->setObjectName ( this->getNameInput ( xsdElement ) + "Input" );
    ( ( QGridLayout * ) widget->layout () )->addWidget ( comboBox, ( ( QGridLayout * ) widget->layout () )->rowCount () - 1, 1, 1, 1, Qt::AlignLeft );
    this->createInputType ( comboBox, xsdElement );

  } else {

    if ( objTypeProperty->getValue () == NSLIB_XSD::TypeAbs::INTEGER ) {

      QSpinBox *spinBox = new QSpinBox ( widget );
      spinBox->setMaximumHeight ( 18 );
      spinBox->setObjectName ( this->getNameInput ( xsdElement ) + "Input" );
      this->createInputType ( spinBox, xsdElement );
      ( ( QGridLayout * ) widget->layout () )->addWidget ( spinBox, ( ( QGridLayout * ) widget->layout () )->rowCount () - 1, 1, 1, 1, Qt::AlignLeft );

    } else {

      if ( objTypeProperty->getValue () == NSLIB_XSD::TypeAbs::HEXBINARY ) {

        NSLIB_COLORBOX::ColorBox *colorBox = new NSLIB_COLORBOX::ColorBox ();
        colorBox->setMaximumHeight ( 18 );
        colorBox->setObjectName ( this->getNameInput ( xsdElement ) + "Input" );
        this->createInputType ( colorBox, xsdElement );
        ( ( QGridLayout * ) widget->layout () )->addWidget ( colorBox, ( ( QGridLayout * ) widget->layout () )->rowCount () - 1, 1, 1, 1, Qt::AlignLeft );

      } else {

        QLineEdit *lineEdit = new QLineEdit ();
        lineEdit->setMaximumHeight ( 18 );
        lineEdit->setObjectName ( this->getNameInput ( xsdElement ) + "Input" );
        this->createInputType ( lineEdit, xsdElement );
        //connect ( lineEdit, SIGNAL (  ), this, SLOT (  ) );
        ( ( QGridLayout * ) widget->layout () )->addWidget ( lineEdit, ( ( QGridLayout * ) widget->layout () )->rowCount () - 1, 1, 1, 1, Qt::AlignLeft );
      }
    }
  }
}

void XsdFormCreator::createParams ( QWidget *widget, QList<NSLIB_XSD::XsdElement *> xsdElementList ) {

  const int paramsCount = xsdElementList.count ();
  for ( int i = 0; i < paramsCount; i++ ) {

    NSLIB_XSD::XsdElement *xsdElement = xsdElementList.at ( i );
    if ( xsdElement->getElementLevel () == NSLIB_XSD::Xsd::GROUPFORM ) {

      this->createGroup ( widget, xsdElement );

    } else {

      this->createParam ( widget, xsdElement );
      ( ( QGridLayout * ) widget->layout () )->setColumnStretch ( ( ( QGridLayout * ) widget->layout () )->columnCount (), 1 );
    }
  }
}

void XsdFormCreator::createStringInput ( QWidget *widget, NSLIB_XSD::XsdElement *xsdElement ) {

  const int facetsCount = xsdElement->getFacets ().count ();
  for ( int i = 0; i < facetsCount; i++ ) {

    if ( xsdElement->isEnumerate () ) {

      ( ( QComboBox * ) widget )->addItem ( ( ( NSLIB_XSD::EnumerationFacet * ) xsdElement->getFacets ().at ( i ) )->getValue () );

    } else {

      if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "NSLIB_XSD::AssertionsFacet" ) == 0 ) {

        // TODO: No implementado aun
        //( ( QSpinBox * ) widget )->

      } else if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "NSLIB_XSD::LengthFacet" ) == 0 ) {

        ( ( QLineEdit * ) widget )->setMaxLength ( ( ( NSLIB_XSD::LengthFacet * ) xsdElement->getFacets ().at ( i ) )->getValue ().toInt () );

      } else if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "NSLIB_XSD::MaxLengthFacet" ) == 0 ) {

        ( ( QLineEdit * ) widget )->setMaxLength ( ( ( NSLIB_XSD::MaxLengthFacet * ) xsdElement->getFacets ().at ( i ) )->getValue ().toInt () );

      } else if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "NSLIB_XSD::MinLengthFacet" ) == 0 ) {

        // TODO: No implementado aun
        //( ( QLineEdit * ) widget )->setMaxLength ( ( ( NSLIB_XSD::MinLengthFacet * ) xsdElement->getFacets ().at ( i ) )->getValue ().toInt () );

      } else if ( QString::compare ( xsdElement->getFacets ().at ( i )->metaObject ()->className (), "NSLIB_XSD::PatternFacet" ) == 0 ) {

        ( ( QLineEdit * ) widget )->setInputMask ( ( ( NSLIB_XSD::PatternFacet * ) xsdElement->getFacets ().at ( i ) )->getValue ()  );

      }
    }
  }
}

void XsdFormCreator::createTab ( NSLIB_XSD::XsdElement *xsdElement ) {

  QWidget *tabWidget = new QWidget ( this->tabsDialog );
  tabWidget->setObjectName ( this->getNameInput ( xsdElement ) + "Input" );
  tabWidget->setSizePolicy ( QSizePolicy::Expanding, QSizePolicy::Expanding );
  QVBoxLayout *tabWidgetLayout = new QVBoxLayout ( tabWidget );
  tabWidget->setLayout ( tabWidgetLayout );
  QScrollArea *scrollArea = new QScrollArea ( tabWidget );
  scrollArea->setWidgetResizable ( true );
  tabWidgetLayout->addWidget ( scrollArea );
  QWidget *internalTabWidget = new QWidget ( scrollArea );
  internalTabWidget->setSizePolicy ( QSizePolicy::Expanding, QSizePolicy::Expanding );
  QGridLayout *internalTabWidgetLayout = new QGridLayout ( internalTabWidget );
  internalTabWidget->setLayout ( internalTabWidgetLayout );
  scrollArea->setWidget ( internalTabWidget );
  this->tabsDialog->addTab ( tabWidget, ( ( NSLIB_XSD::NameProperty * ) xsdElement->getProperty ( "NameProperty" ) )->getValue () );
  const int tabsCount = xsdElement->getElementsList ().count ();
  if ( tabsCount > 0 ) {

    this->createParams ( internalTabWidget, xsdElement->getElementsList () );
    internalTabWidgetLayout->setRowStretch ( internalTabWidgetLayout->rowCount (), 1 );
  }
}

void XsdFormCreator::createTabs ( QList<NSLIB_XSD::XsdElement *> xsdElementList ) {

  const int tabsCount = xsdElementList.count ();
  for ( int i = 0; i < tabsCount; i++ ) {

    this->createTab ( xsdElementList.at ( i ) );
  }
}

QTabWidget *XsdFormCreator::getForm () const {

  return this->tabsDialog;
}

QString XsdFormCreator::getNameInput ( NSLIB_XSD::XsdElement *xsdElement ) {

  QString nameInputAux = "";
  if ( xsdElement->getParent () != nullptr ) {

    nameInputAux = this->getNameInput ( xsdElement->getParent () );
  }
  return nameInputAux + ( ( NSLIB_XSD::NameProperty * ) xsdElement->getProperty ( "NameProperty" ) )->getValue ();
}
