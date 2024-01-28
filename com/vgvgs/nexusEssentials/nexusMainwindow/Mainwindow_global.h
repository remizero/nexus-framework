#ifndef MAINWINDOW_GLOBAL_H
#define MAINWINDOW_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(MAINWINDOW_LIBRARY)
#  define MAINWINDOW_EXPORT Q_DECL_EXPORT
#else
#  define MAINWINDOW_EXPORT Q_DECL_IMPORT
#endif

#define NS_MAINWINDOW    Mainwindow
#define NSLIB_MAINWINDOW Com::Vgvgs::NexusFramework::Essentials::Mainwindow

#endif // MAINWINDOW_GLOBAL_H
