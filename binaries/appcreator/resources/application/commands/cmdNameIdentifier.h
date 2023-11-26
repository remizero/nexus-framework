#ifndef TYPECMD_H
#define TYPECMD_H

// Librerías Internas
// Internal Libraries

// Librerías Externas
// External Libraries
#include "macros_global.h"
#include "Core_global.h"
#include "commandsystem/CommandInterface.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QCommandLineOption>
#include <QDebug>
#include <QObject>
#include <QString>

// Librerías C++
// C++ Libraries


class cmdNameIdentifier : public NSLIB_CORE::CommandInterface {

    Q_INTERFACES ( NSLIB_CORE::CommandInterface )

  public :
    cmdNameIdentifier ();
    ~cmdNameIdentifier () override {}
    QCommandLineOption commandOption () const override;
    QString description () const override;
    void execute () override;
    QString name () const override;
};

Q_DECLARE_METATYPE ( cmdNameIdentifier )

#endif // TYPECMD_H
