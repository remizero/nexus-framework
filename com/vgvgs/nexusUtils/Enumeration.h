#ifndef ENUMERATION_H
#define ENUMERATION_H

// Librerías Internas
// Internal Libraries
#include "Utils_global.h"

// Librerías Externas
// External Libraries

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QMetaEnum>
#include <QMetaObject>

// Librerías C++
// C++ Libraries


namespace NS_LEVEL_1 {

  namespace NS_LEVEL_2 {

    namespace NS_NEXUS {

      namespace NS_UTILS {

        class UTILS_EXPORT Enumeration {

          public :
            /**
             * @brief indexOf
             *        Busca el valor asociado a una clave de enumerado (enumKey) dentro del enumerado especificado por enumerate dentro de un objeto QMetaObject.
             * @param staticMetaObject Objeto meta en el que se busca el enumerado.
             * @param enumerate Nombre del enumerado que se busca dentro del objeto staticMetaObject.
             * @param enumKey Valor del enumerado en formato de cadena.
             * @return int
             */
            static int indexOf ( const QMetaObject staticMetaObject, QString enumerate, QString enumKey );// LISTO

            /**
             * @brief inEnum
             *        Verifica si un valor de enumerado (enumKey) está presente en el enumerado especificado (enumerate) dentro de un objeto QMetaObject.
             * @param staticMetaObject Objeto meta en el que se busca el enumerado.
             * @param enumerate Nombre del enumerado que se busca dentro del objeto staticMetaObject.
             * @param enumKey Valor del enumerado en formato de cadena.
             * @return bool
             */
            static bool inEnum ( const QMetaObject staticMetaObject, QString enumerate, QString enumKey );

            /**
             * @brief inEnum
             *        Verifica si un valor de enumerado representado por un entero (enumValue) está presente en el enumerado especificado (enumerate) dentro de un objeto QMetaObject.
             * @param staticMetaObject Objeto meta en el que se busca el enumerado.
             * @param enumerate Nombre del enumerado que se busca dentro del objeto staticMetaObject.
             * @param enumValue Valor del enumerado en formato de entero.
             * @return bool
             */
            static bool inEnum ( const QMetaObject staticMetaObject, QString enumerate, int enumValue );

            /**
             * @brief normalizeEnumValue
             *         Utilidad para normalizar y formatear consistentemente los valores de enumerados en mayúsculas.
             * @param enumKey Valor del enumerado en formato de cadena.
             * @return QString
             */
            static QString normalizeEnumValue ( QString enumKey );

          private :
            /**
             * @brief getMetaEnum
             *        Buscar y retorna un QMetaEnum (enumerate) dentro de un objeto QMetaObject (staticMetaObject).
             * @param staticMetaObject Objeto meta en el que se busca el enumerado.
             * @param enumerate Nombre del enumerado que se busca dentro del objeto staticMetaObject.
             * @return const QMetaEnum
             */
            static const QMetaEnum getMetaEnum ( const QMetaObject staticMetaObject, QString enumerate );
        };
      }
    }
  }
}

#endif // ENUMERATION_H
