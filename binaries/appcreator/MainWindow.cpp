#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
  {
  ui->setupUi(this);

  this->setCentralWidget ( new NSLIB_CONSOLE::NexusConsoleGui ( this ) );
}

MainWindow::~MainWindow()
  {
    delete ui;
  }

void MainWindow::show () {

  this->show ();
}
