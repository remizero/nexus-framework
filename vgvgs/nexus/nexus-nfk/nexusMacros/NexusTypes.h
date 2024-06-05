#ifndef NEXUSTYPES_H
#define NEXUSTYPES_H

// Librerías Internas
// Internal Libraries

// Librerías Externas
// External Libraries

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QString>

// Librerías C++
// C++ Libraries
#include <exception>
#include <functional>
#include <stdexcept>


typedef std::function<bool()> CallbackBoolFunction;
typedef std::function<bool( const QString & )> CallbackBoolFunctionOneStringParam;
typedef std::function<void()> CallbackVoidFunction;

bool checkInitialization ( bool initialized, CallbackVoidFunction callbackFunction ) {
  
  if ( initialized ) {
    
    callbackFunction ();
    
  } else {

    throw std::runtime_error ( "La clase no se ha inicializado correctamente." );
    std::terminate ();
  }
}


#endif // NEXUSTYPES_H
