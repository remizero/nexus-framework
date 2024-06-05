#include "AttributeDialog.h"
#include "ui/ui_AttributeDialog.h"

AttributeDialog::AttributeDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::AttributeDialog)
  {
    ui->setupUi(this);
  }

AttributeDialog::~AttributeDialog()
  {
    delete ui;
  }
