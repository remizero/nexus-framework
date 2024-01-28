#ifndef METHODDIALOG_H
#define METHODDIALOG_H

#if QT_VERSION >= 0x050000
#include <QtWidgets/QDialog>
#else
#include <QDialog>
#endif

namespace Ui {
    class MethodDialog;
  }

class MethodDialog : public QDialog
  {
    Q_OBJECT

  public:
    explicit MethodDialog(QWidget *parent = nullptr);
    ~MethodDialog();

  private:
    Ui::MethodDialog *ui;
  };

#endif // METHODDIALOG_H
