#ifndef INFOCMD_H
#define INFOCMD_H

// Librerías Internas
// Internal Libraries

// Librerías Externas
// External Libraries
#include "macros_global.h"
#include "core_global.h"
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


class InfoCmd : public NAMESPACE_LIBRARY_CORE::CommandInterface {

    Q_INTERFACES ( NAMESPACE_LIBRARY_CORE::CommandInterface )

  public :
    InfoCmd ();
    ~InfoCmd () override {}
    QCommandLineOption commandOption () const override;
    QString description () const override;
    void execute () override;
    QString name () const override;
};

Q_DECLARE_METATYPE ( InfoCmd )

#endif // INFOCMD_H
