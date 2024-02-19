#include "NexusConsole.h"


using namespace NSLIB_CONSOLE;


//NexusConsole *NexusConsole::instance = nullptr;

NexusConsole::NexusConsole ( QObject *parent ) : QObject ( parent ) {

  this->exec = new QProcess ( this );
  // connect ( this->exec, SIGNAL ( readyReadStandardOutput () ), this, SLOT ( catchOutput () ) );
  connect ( this->exec, &QProcess::readyReadStandardOutput, this, &NexusConsole::catchOutput );
  // connect ( this->exec, SIGNAL ( readyReadStandardError () ), this, SLOT ( catchError () ) );
  connect ( this->exec, &QProcess::readyReadStandardError, this, &NexusConsole::catchError );
  // connect ( this->exec, SIGNAL ( finished ( int, QProcess::ExitStatus ) ), this, SLOT ( processFinishedSlot ( int, QProcess::ExitStatus ) ) );
  connect ( this->exec, &QProcess::finished, this, &NexusConsole::processFinishedSlot );
}

void NexusConsole::execute ( QString command, QStringList arguments ) {

  this->clear ();
  this->exec->start ( command, arguments );
    this->exec->waitForFinished ();
  }

QProcess::ProcessError NexusConsole::getError () const {

  return this->exec->error ();
}

void NexusConsole::catchError () {

  this->outputShellError.append ( this->exec->readAllStandardError () );
}

void NexusConsole::catchOutput () {

    this->outputShell.append ( this->exec->readAllStandardOutput () );
  }

void NexusConsole::processFinishedSlot ( int exitCode, QProcess::ExitStatus exitStatus ) {

  emit processFinished ( exitCode, exitStatus );
}

void NexusConsole::clear () {

  this->outputShell.clear ();
  this->outputShellError.clear ();
}

QString NexusConsole::getOutputShell () const {

  return this->outputShell;
}

QString NexusConsole::getOutputShellError () const {

  return this->outputShellError;
}
