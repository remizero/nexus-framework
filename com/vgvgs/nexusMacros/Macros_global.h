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
#define NS_ESSENTIALS     Essentials
#define NS_ENGINES        Engines

#endif // MACROS_GLOBAL_H
