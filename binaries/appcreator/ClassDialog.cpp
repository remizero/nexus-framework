#include "ClassDialog.h"
#include "ui/ui_ClassDialog.h"

ClassDialog::ClassDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::ClassDialog)
  {
    ui->setupUi(this);
  }

ClassDialog::~ClassDialog()
  {
    delete ui;
  }
