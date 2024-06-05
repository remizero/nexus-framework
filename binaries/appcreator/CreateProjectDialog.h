#ifndef CREATEPROJECTDIALOG_H
#define CREATEPROJECTDIALOG_H

#if QT_VERSION >= 0x050000
#include <QtWidgets/QDialog>
#else
#include <QDialog>
#endif

#include <QComboBox>
#include <QDebug>
#include <QStringList>

namespace Ui {

  class CreateProjectDialog;
}

class CreateProjectDialog : public QDialog {

    Q_OBJECT

  public :
    explicit CreateProjectDialog ( QWidget *parent = nullptr );
    ~CreateProjectDialog ();

  public slots :
    void onProjectModelCmbChange ( int index );
    void onProjectCategoryCmbChange ( int index );

  private :
    Ui::CreateProjectDialog *ui;
    QStringList projectModels;
    QStringList categoryNexusModels;
    QStringList typeNexusAppModels;
    QStringList typeNexusLibraryModels;
    QStringList categoryEmoogeModels;
    QStringList typeEmoogeFpsModels;
    QStringList typeEmoogeTpModels;
    QStringList typeEmoogePlatformModels;
};

#endif // CREATEPROJECTDIALOG_H
