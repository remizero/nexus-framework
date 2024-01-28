#ifndef ATTRIBUTEDIALOG_H
#define ATTRIBUTEDIALOG_H

#if QT_VERSION >= 0x050000
#include <QtWidgets/QDialog>
#else
#include <QDialog>
#endif

namespace Ui {
    class AttributeDialog;
  }

class AttributeDialog : public QDialog
  {
    Q_OBJECT

  public:
    explicit AttributeDialog(QWidget *parent = nullptr);
    ~AttributeDialog();

  private:
    Ui::AttributeDialog *ui;
  };

#endif // ATTRIBUTEDIALOG_H
