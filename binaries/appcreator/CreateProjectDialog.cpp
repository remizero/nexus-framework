#include "CreateProjectDialog.h"
#include "ui/ui_CreateProjectDialog.h"

CreateProjectDialog::CreateProjectDialog ( QWidget *parent )
  : QDialog ( parent ),
    ui ( new Ui::CreateProjectDialog ) {

  this->ui->setupUi ( this );

  this->projectModels = { "Select Project Model", "Nexus", "Emooge" };
  this->categoryNexusModels = { "Select Project Category", "App", "Library" };
  this->typeNexusAppModels = { "Select Project Type", "BlankApp", "ConsoleApp", "GuiApp", "NexusApp", "SimpleGuiApp", "StandaloneNexusApp" };
  this->typeNexusLibraryModels = { "Select Project Type", "BlankLibrary", "Plugin", "ShareLibrary", "StaticLibrary" };
  this->categoryEmoogeModels = { "Select Project Category", "FPS", "TP", "Platform" };
  this->typeEmoogeFpsModels = { "Select Project Type", "FPS_1", "FPS_2" };
  this->typeEmoogeTpModels = { "Select Project Type", "TP_1", "TP_2" };
  this->typeEmoogePlatformModels = { "Select Project Type", "SideScrolling", "MultidirectionalScrolling", "Isometric", "metroidvania", "fight" };
  this->ui->projectModelCmb->addItems ( this->projectModels );
  connect ( this->ui->projectModelCmb, &QComboBox::currentIndexChanged, this, &CreateProjectDialog::onProjectModelCmbChange );
  connect ( this->ui->projectCategoryCmb, &QComboBox::currentIndexChanged, this, &CreateProjectDialog::onProjectCategoryCmbChange );
}

CreateProjectDialog::~CreateProjectDialog () {

  delete ui;
}

void CreateProjectDialog::onProjectModelCmbChange ( int index ) {

  if ( index > 0 ) {

    QString selectedItem = this->ui->projectModelCmb->itemText ( index );
    QString currentItem = this->ui->projectModelCmb->currentText ();
    qDebug () << "selectedItem" << selectedItem;
    qDebug () << "currentItem" << currentItem;
    if ( selectedItem == "Nexus" ) {

      this->ui->projectCategoryCmb->clear ();
      this->ui->projectCategoryCmb->setEnabled ( true );
      this->ui->projectCategoryCmb->addItems ( this->categoryNexusModels );

    } else if ( selectedItem == "Emooge" ) {

      this->ui->projectCategoryCmb->clear ();
      this->ui->projectCategoryCmb->setEnabled ( true );
      this->ui->projectCategoryCmb->addItems ( this->categoryEmoogeModels );
    }
  } else {

    this->ui->projectTypeCmb->clear ();
    this->ui->projectTypeCmb->setEnabled ( false );
    this->ui->projectCategoryCmb->clear ();
    this->ui->projectCategoryCmb->setEnabled ( false );
  }
}

void CreateProjectDialog::onProjectCategoryCmbChange ( int index ) {

  if ( index > 0 ) {

    QString selectedItem = this->ui->projectCategoryCmb->itemText ( index );
    QString currentItem = this->ui->projectCategoryCmb->currentText ();
    qDebug () << "selectedItem" << selectedItem;
    qDebug () << "currentItem" << currentItem;
    if ( selectedItem == "App" ) {

      this->ui->projectTypeCmb->clear ();
      this->ui->projectTypeCmb->setEnabled ( true );
      this->ui->projectTypeCmb->addItems ( this->typeNexusAppModels );

    } else if ( selectedItem == "Library" ) {

      this->ui->projectTypeCmb->clear ();
      this->ui->projectTypeCmb->setEnabled ( true );
      this->ui->projectTypeCmb->addItems ( this->typeNexusLibraryModels );

    } else if ( selectedItem == "FPS" ) {

      this->ui->projectTypeCmb->clear ();
      this->ui->projectTypeCmb->setEnabled ( true );
      this->ui->projectTypeCmb->addItems ( this->typeEmoogeFpsModels );

    } else if ( selectedItem == "TP" ) {

      this->ui->projectTypeCmb->clear ();
      this->ui->projectTypeCmb->setEnabled ( true );
      this->ui->projectTypeCmb->addItems ( this->typeEmoogeTpModels );

    } else if ( selectedItem == "Platform" ) {

      this->ui->projectTypeCmb->clear ();
      this->ui->projectTypeCmb->setEnabled ( true );
      this->ui->projectTypeCmb->addItems ( this->typeEmoogePlatformModels );
    }
  } else {

    this->ui->projectTypeCmb->clear ();
    this->ui->projectTypeCmb->setEnabled ( false );
  }
}
