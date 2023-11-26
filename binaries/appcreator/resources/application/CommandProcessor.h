#ifndef COMMANDPROCESSOR_H
#define COMMANDPROCESSOR_H

// Librerías Internas
// Internal Libraries

// Librerías Externas
// External Libraries
#include "macros_global.h"
#include "Core_global.h"
#include "commandsystem/CommandProcessorInterface.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QDebug>
#include <QDir>
#include <QStringList>

// Librerías C++
// C++ Libraries


class CommandProcessor : public NSLIB_CORE::CommandProcessorInterface {

  public :
    CommandProcessor ();
    ~CommandProcessor () override {}

    void processCommands ( QCommandLineParser &parser, QMap<QString, NSLIB_CORE::CommandInterface *> commandMap ) override;
    // TODO Puede agregar nuevos métodos para ser llamados dentro del método "processCommands".
};

Q_DECLARE_METATYPE ( CommandProcessor )

#endif // COMMANDPROCESSOR_H
