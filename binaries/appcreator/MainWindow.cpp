#include "MainWindow.h"
#include "ui/ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
  {
  this->ui->setupUi ( this );

    connect ( this->ui->actionCreateProject, &QAction::triggered, this, &MainWindow::onCreateProject );

  this->setCentralWidget ( new NSLIB_CONSOLE::NexusConsoleGui ( this ) );
}

MainWindow::~MainWindow () {

  delete ui;
}

void MainWindow::onCreateProject () {

  // CreateProjectDialog *asdf = new CreateProjectDialog ( this );
  // asdf->show ();

  CreateProjectDialog dialog; // Crear una instancia del diálogo
  int result = dialog.exec(); // Mostrar el diálogo y esperar a que se cierre
  if (result == QDialog::Accepted) {
      // Código para manejar la aceptación del diálogo
  } else {
      // Código para manejar el rechazo o cierre del diálogo
  }
}

void MainWindow::show () {

  this->show ();
}
