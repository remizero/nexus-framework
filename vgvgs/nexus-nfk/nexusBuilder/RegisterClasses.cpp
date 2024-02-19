#include "RegisterClasses.h"


using namespace NSLIB_BUILDER;


RegisterClasses::RegisterClasses () {}

void RegisterClasses::addTypeClass () {

  qRegisterMetaType<BlankAppProject>      ( "BlankAppProject"      );
  qRegisterMetaType<BlankLibraryProject>  ( "BlankLibraryProject"  );
  qRegisterMetaType<ConsoleAppProject>    ( "ConsoleAppProject"    );
  qRegisterMetaType<GuiAppProject>        ( "GuiAppProject"        );
  qRegisterMetaType<NexusAppProject>      ( "NexusAppProject"      );
  qRegisterMetaType<PluginProject>        ( "PluginProject"        );
  qRegisterMetaType<ShareLibraryProject>  ( "ShareLibraryProject"  );
  qRegisterMetaType<SimpleGuiAppProject>  ( "SimpleGuiAppProject"  );
  qRegisterMetaType<StaticLibraryProject> ( "StaticLibraryProject" );
}
