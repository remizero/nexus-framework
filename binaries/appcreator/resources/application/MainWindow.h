#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore/qglobal.h>
#if QT_VERSION >= 0x050000
#include <QtWidgets/QMainWindow>
#else
#include <QtGui/QMainWindow>
#endif

#include "MainWindowInterface.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public MainWindowInterface
  {
    Q_OBJECT

  public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void show () override;

    MainWindow &operator= ( const QMainWindow &other ) {

      if ( this != &other ) {
        // Implementa la asignación adecuada de recursos y datos si es necesario
      }
      return *this;
    }

  private:
    Ui::MainWindow *ui;
  };
#endif // MAINWINDOW_H
