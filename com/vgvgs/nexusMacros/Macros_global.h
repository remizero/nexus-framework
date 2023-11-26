#ifndef MACROS_GLOBAL_H
#define MACROS_GLOBAL_H


#include <QtCore/qglobal.h>


#if defined(MACROS_LIBRARY)
#  define MACROS_EXPORT Q_DECL_EXPORT
#else
#  define MACROS_EXPORT Q_DECL_IMPORT
#endif

#define BASIC_STR(x) #x
#define STR(x) BASIC_STR(x)

#define notImplemented() static_assert(false, "Método no implementado.");

#define DEFAULT_QT_MESSAGE_PATTERN \033[0;34m[ %{time yyyy-MM-ddThh:mm:ss t} ] \033[1;31m[ %{if-critical}CRITICAL%{endif}%{if-debug}DEBUG%{endif}%{if-fatal}FATAL%{endif}%{if-info}INFO%{endif}%{if-warning}WARNING%{endif} ] \033[1;36m[ PID - %{pid} ] [ THREAD_ID - %{threadid} ] [ QT_THREAD_PTR - %{qthreadptr} ] \033[1;33m[ APPNAME - %{appname} ] [ FILE - %{file} ] [ FUNCTION - %{function} ] [ LINE - %{line} ] [ MESSAGE_ERROR - %{message} ] \033[1;37m[ BACKTRACE - %{backtrace depth=10} ] \033[0m
#define FILE_OUTPUT_QT_MESSAGE_PATTERN [ %{time yyyy-MM-ddThh:mm:ss t} ] [ %{if-critical}CRITICAL%{endif}%{if-debug}DEBUG%{endif}%{if-fatal}FATAL%{endif}%{if-info}INFO%{endif}%{if-warning}WARNING%{endif} ] [ PID - %{pid} ] [ THREAD_ID - %{threadid} ] [ QT_THREAD_PTR - %{qthreadptr} ] [ APPNAME - %{appname} ] [ FILE - %{file} ] [ FUNCTION - %{function} ] [ LINE - %{line} ] [ MESSAGE_ERROR - %{message} ] [ BACKTRACE - %{backtrace depth=10} ]


// Se definen las macros comunes para todos los espacios de nombre de las librerías.
// Common macros are defined for all library namespaces.
#define TOKEN_SEPARATOR   ::
#define NS_LEVEL_1        Com
#define NS_LEVEL_2        Vgvgs
#define NS_MACROS         Macros
#define NSLIB_MACROS      Com::Vgvgs::NexusFramework::Macros
#define NS_NEXUS          NexusFramework
#define NS_NEXUSFRAMEWORK Com::Vgvgs::NexusFramework

// Se definen las macros particulares para todos los espacios de nombre de las librerías.
// Particular macros are defined for all library namespaces.
//#define NS_CONSOLE        Console
//#define NS_ENGINES        Engines
//#define NS_XSD            Xsd
//#define NS_XSDFORM        XsdForm
//#define NS_LOGGER         Logger
//#define NS_UTILS          Utils
//#define NS_WINDOW         Window
//#define NS_COMPONENTS     Components
//#define NS_ACTIONS        Actions
//#define NS_COLORBOX       ColorBox
//#define NS_COLORPICKER    ColorPicker
//#define NS_MENUBAR        MenuBar
//#define NS_STATUSBAR      StatusBar
//#define NS_SYSTEMTRAYICON SystemTrayIcon
//#define NS_MAINWINDOW     MainWindow


// Se definen las macros con los nombres completos para todos los espacios de nombre de las librerías.
// Macros with fully qualified names are defined for all library namespaces.
// #define NSLIB_APP            Com::Vgvgs::App
//#define NSLIB_CONSOLE        Com::Vgvgs::Console
//#define NSLIB_XSD            Com::Vgvgs::Engines::Xsd
//#define NSLIB_LOGGER         Com::Vgvgs::Logger
//#define NSLIB_UTILS          Com::Vgvgs::Utils
//#define NSLIB_ACTONS         Com::Vgvgs::Window::Components::Actions
//#define NSLIB_COLORBOX       Com::Vgvgs::Window::Components::ColorBox
//#define NSLIB_COLORPICKER    Com::Vgvgs::Window::Components::ColorPicker
//#define NSLIB_MENUBAR        Com::Vgvgs::Window::Components::MenuBar
//#define NSLIB_STATUSBAR      Com::Vgvgs::Window::Components::StatusBar
//#define NSLIB_SYSTEMTRAYICON Com::Vgvgs::Window::Components::SystemTrayIcon
//#define NSLIB_XSDFORM        Com::Vgvgs::Window::Components::XsdForm
//#define NSLIB_MAINWINDOW     Com::Vgvgs::Window::MainWindow


#endif // MACROS_GLOBAL_H
