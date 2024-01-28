#ifndef ACTIONS_GLOBAL_H
#define ACTIONS_GLOBAL_H

// Librerías Internas
// Internal Libraries

// Librerías Externas
// External Libraries
#include "Macros_global.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QtCore/qglobal.h>

// Librerías C++
// C++ Libraries

#if defined(ACTIONS_LIBRARY)
#  define ACTIONS_EXPORT Q_DECL_EXPORT
#else
#  define ACTIONS_EXPORT Q_DECL_IMPORT
#endif

#define NS_ACTIONS    Actions
#define NSLIB_ACTIONS Com::Vgvgs::NexusFramework::Essentials::Actions

// TODO: Definir un enumerado para indicar la prioridad de las acciones del menú.
// Esto es, que las acciones definidas predeterminadas para el sistema deben
// mostrarse en la posición y sección indicada y las acciones de plugins serán
// mostradas en las mismas secciones indicadas pero posterior a las acciones
// predeterminadas para el sistema.

// TODO: Darle nombre a los objetos de las acciones con el nombre de las acciones
// colocando siempre el sufijo Act.

// TODO: esto puede ser en este archivo o en la clase ActionAbs.h

#endif // ACTIONS_GLOBAL_H
