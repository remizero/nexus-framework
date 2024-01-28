#include "MethodDialog.h"
#include "ui_MethodDialog.h"

MethodDialog::MethodDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::MethodDialog)
  {
    ui->setupUi(this);
  }

MethodDialog::~MethodDialog()
  {
    delete ui;
  }
