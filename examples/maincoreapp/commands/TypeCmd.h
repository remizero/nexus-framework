#ifndef TYPECMD_H
#define TYPECMD_H

// Librerías Internas
// Internal Libraries

// Librerías Externas
// External Libraries
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


class TypeCmd : public NSLIB_CORE::CommandInterface {

    Q_INTERFACES ( NSLIB_CORE::CommandInterface )

  public :
    TypeCmd ();
    ~TypeCmd () override {}
    QCommandLineOption commandOption () const override;
    QString description () const override;
    void execute () override;
    QString name () const override;
};

Q_DECLARE_METATYPE ( TypeCmd )

#endif // TYPECMD_H
