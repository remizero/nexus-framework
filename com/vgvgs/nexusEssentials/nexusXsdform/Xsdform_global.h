#ifndef XSDFORM_GLOBAL_H
#define XSDFORM_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(XSDFORM_LIBRARY)
#  define XSDFORM_EXPORT Q_DECL_EXPORT
#else
#  define XSDFORM_EXPORT Q_DECL_IMPORT
#endif

#define NS_XSDFORM    Xsdform
#define NSLIB_XSDFORM Com::Vgvgs::NexusFramework::Essentials::Xsdform

#endif // XSDFORM_GLOBAL_H
