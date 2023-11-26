#ifndef MAINWINDOWINTERFACE_H
#define MAINWINDOWINTERFACE_H

class MainWindowInterface {
  public :
    virtual ~MainWindowInterface () {}
    virtual void show () = 0;
};

#endif // MAINWINDOWINTERFACE_H
