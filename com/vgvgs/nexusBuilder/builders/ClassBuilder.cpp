#include "ClassBuilder.h"


using namespace NSLIB_BUILDER;


ClassBuilder::ClassBuilder ( QString className, NexusBuilder::FileClasses fileClass, bool interface ) :
  className ( className ),
  fileClasses ( fileClass ),
  isInterface ( interface ) {

  this->indentation = "";
}

void ClassBuilder::build () {

  switch ( this->fileClasses ) {
    case NexusBuilder::FileClasses::HEADERSONLY :

      this->createHeaderFile ();
      break;

    case NexusBuilder::FileClasses::SOURCESONLY :

      this->createSourceFile ();
      break;

    default :

      this->createHeaderFile ();
      this->createSourceFile ();
      break;
  }
}

void ClassBuilder::alignStrings ( QStringList &stringList ) {

  // Encuentra la longitud máxima
  int maxLength = 0;
  for ( const QString &str : stringList ) {

    maxLength = std::max ( maxLength, static_cast<int>( str.length () ) );
  }
  // Agrega espacios en blanco a las cadenas más cortas
  for ( QString& str : stringList ) {

    int padding = maxLength - str.length ();
    str.append ( QString ( padding, ' ' ) );
  }
}

void ClassBuilder::closeClass () {

  this->decreaseIndentation ();
  this->headerBody += this->indentation + "};\n";
  this->decreaseIndentation ();
}

void ClassBuilder::closeClassFile () {

  this->headerBody += this->indentation + "\n";
  this->headerBody += this->indentation + "#endif // " + this->className.toUpper () + "_H\n";
}

void ClassBuilder::createAccessibilitySection ( NexusBuilder::Accessibility accessibility ) {

  this->headerBody += this->indentation;
  switch ( accessibility ) {

    case NexusBuilder::Accessibility::PRIVATE :

      this->headerBody += "private";
      break;

    case NexusBuilder::Accessibility::PROTECTED :

      this->headerBody += "protected";
      break;

    default :

      this->headerBody += "public";
      break;
  }
  this->headerBody += " :\n";
  this->indentation += "  ";
  QStringList attributeListAux;
  for ( AttributeBuilder *attribute : this->attributeList ) {

    if ( attribute->getAccessibility () == accessibility ) {

      attribute->build ();
      attributeListAux.append ( attribute->getParam () );
    }
  }
  this->alignStrings ( attributeListAux );
  for ( const QString &attribute : attributeListAux ) {

    this->headerBody += this->indentation + attribute + "\n";
  }
  // TODO indicar la creación del codigo dependiendo de si es en headers o sources.
  for ( MethodBuilder *method : this->methodList ) {

    if ( method->getAccessibility () == accessibility ) {

      this->headerBody += this->indentation + method->build ( this->fileClasses, NexusBuilder::TypeBuild::DEFINITION, this->className ) + "\n";
    }
  }
  this->decreaseIndentation ();
}

void ClassBuilder::createClassDefinition () {

  // TODO Como obtener la macro _EXPORT
  this->headerBody += this->indentation + "class BUILDER_EXPORT " + this->className;
  if ( this->inheritsFrom.length () > 0 ) {

    this->headerBody += " :";
    for ( int i = 0; i < this->inheritsFrom.size (); ++i ) {

      this->headerBody += this->inheritsFrom.at ( i );
      if ( i < this->inheritsFrom.size () - 1 ) {

        this->headerBody += ", ";
      }
    }
  }
  this->headerBody += " {\n\n";
  this->indentation += "    ";
}

void ClassBuilder::createHeaderFile () {

  this->createIncludeGuard ();
  this->createLibsSection ();
  this->createNamespacesOpening ();
  this->createClassDefinition ();
  this->createMetadataSection ();
  this->createPublicSection ();
  this->createProtectedSection ();
  this->createPrivateSection ();
  this->closeClass ();
  this->createNamespacesClosing ();
  this->closeClassFile ();
}

void ClassBuilder::createIncludeGuard () {

  this->headerBody = this->indentation + "#ifndef " + this->className.toUpper () + "_H\n";
  this->headerBody += this->indentation + "#define " + this->className.toUpper () + "_H\n";
  this->headerBody += "\n";
}

void ClassBuilder::createLibsSection () {

  // TODO Como agregar las librerías requeridas?
  this->headerBody += this->indentation + "// Librerías Internas\n";
  this->headerBody += this->indentation + "// Internal Libraries\n";
  this->headerBody += "\n";
  this->headerBody += this->indentation + "// Librerías Externas\n";
  this->headerBody += this->indentation + "// External Libraries\n";
  this->headerBody += "\n";
  this->headerBody += this->indentation + "// Librerías de terceros\n";
  this->headerBody += this->indentation + "// third-party Library\n";
  this->headerBody += "\n";
  this->headerBody += this->indentation + "// Librerías Qt\n";
  this->headerBody += this->indentation + "// Qt Libraries\n";
  this->headerBody += this->indentation + "#include <QDebug>\n";
  this->headerBody += this->indentation + "#include <QObject>\n";
  this->headerBody += "\n";
  this->headerBody += this->indentation + "// Librerías C++\n";
  this->headerBody += this->indentation + "// C++ Libraries\n";
  this->headerBody += "\n";
  this->headerBody += "\n";
}

void ClassBuilder::createMetadataSection () {

  // TODO Como crear esta sección?
  //this->headerBody += this->indentation + "// C++ Libraries\n";
  // this->headerBody += "\n";
  this->decreaseIndentation ();
}

void ClassBuilder::createNamespacesClosing () {

  for ( const QString &namespaceDefinition : this->namespaceList ) {

    this->headerBody += this->indentation + "}\n";
    this->decreaseIndentation ();
  }
}

void ClassBuilder::createNamespacesOpening () {

  // TODO Como manejar los namespace de este tipo?
  // NS_LEVEL_1, NS_LEVEL_2, NEXUS y el namespace correspondiente a la librería.
  for ( const QString &namespaceDefinition : this->namespaceList ) {

    this->headerBody += this->indentation + "namespace " + namespaceDefinition + " {\n";
    this->headerBody += "\n";
    this->indentation += "  ";
  }
}

void ClassBuilder::createPrivateSection () {

  this->createAccessibilitySection ( NexusBuilder::Accessibility::PRIVATE );
}

void ClassBuilder::createProtectedSection () {

  this->createAccessibilitySection ( NexusBuilder::Accessibility::PROTECTED );
  this->headerBody += "\n";
}

void ClassBuilder::createPublicSection () {

  this->createAccessibilitySection ( NexusBuilder::Accessibility::PUBLIC );
  this->headerBody += "\n";
}

void ClassBuilder::createSourceFile () {

  this->sourceBody = this->indentation + "#include " + this->className + ".h\n\n\n";
  QString namespaceUsing;
  for ( const QString &namespaceDefinition : this->namespaceList ) {

    namespaceUsing.append ( namespaceDefinition + "::" );
  }
  namespaceUsing.chop ( 2 );
  this->sourceBody += this->indentation + "using namespace " + namespaceUsing + ";\n\n\n";
  // TODO indicar la creación del codigo dependiendo de si es en headers o sources.
  for ( MethodBuilder *method : this->methodList ) {

    this->headerBody += this->indentation + method->build ( this->fileClasses, NexusBuilder::TypeBuild::IMPLEMENTATION, this->className ) + "\n";
  }
  qDebug () << "createSourceFile";
}

void ClassBuilder::decreaseIndentation () {

  if ( this->indentation.length () >= 2 ) {

    this->indentation.chop ( 2 );

  } else {

    this->indentation.clear ();
  }
}

const QList<AttributeBuilder *> &ClassBuilder::getAttributeList () const {

  return this->attributeList;
}

const QString &ClassBuilder::getClassName () const {

  return this->className;
}

const NexusBuilder::FileClasses &ClassBuilder::getFileClasses () const {

  return this->fileClasses;
}

const QStringList &ClassBuilder::getInheritsFrom () const {

  return this->inheritsFrom;
}

const QList<MethodBuilder *> &ClassBuilder::getMethodList () const {

  return this->methodList;
}

const QStringList &ClassBuilder::getNamespaceList () const {

  return this->namespaceList;
}

void ClassBuilder::setAttributeList ( AttributeBuilder *attribute ) {

  this->attributeList.append ( attribute );
  std::sort ( this->attributeList.begin (), this->attributeList.end (),
    [] ( const AttributeBuilder *a, const AttributeBuilder *b ) {

      return a->getName ().compare ( b->getName (), Qt::CaseInsensitive ) < 0;
    }
  );
}

void ClassBuilder::setInheritsFrom ( const QStringList &newInheritsFrom ) {

  this->inheritsFrom.append ( newInheritsFrom );
}

void ClassBuilder::setMethodList ( MethodBuilder *method ) {

  this->methodList.append ( method );
  std::sort ( this->methodList.begin (), this->methodList.end (),
    [] ( const MethodBuilder *a, const MethodBuilder *b ) {

      return a->getName ().compare ( b->getName (), Qt::CaseInsensitive ) < 0;
    }
  );
}

void ClassBuilder::setNamespaceList ( QString nameSpace ) {

  this->namespaceList.append ( nameSpace );
}

bool ClassBuilder::toFile ( QString path ) {

  bool toReturn = false;
  QString newPath = path + QDir::separator () + this->getClassName ();
  switch ( this->getFileClasses () ) {

    case NexusBuilder::FileClasses::HEADERSONLY :

      if ( ( toReturn = NSLIB_UTILS::Strings::save ( newPath + ".h", this->headerBody ) ) ) {

        qDebug () << "Archivo header creado satisfactoriamente.";

      } else {

        qDebug () << "El archivo header no se pudo crear satisfactoriamente.";
      }
      break;

    case NexusBuilder::FileClasses::SOURCESONLY :

      if ( ( toReturn = NSLIB_UTILS::Strings::save ( newPath + ".cpp", this->sourceBody ) ) ) {

        qDebug () << "Archivo source creado satisfactoriamente.";

      } else {

        qDebug () << "El archivo source no se pudo crear satisfactoriamente.";
      }
      break;

    default :

      if ( ( toReturn = NSLIB_UTILS::Strings::save ( newPath + ".h", this->headerBody ) ) ) {

        qDebug () << "Archivo header creado satisfactoriamente.";
        if ( ( toReturn = NSLIB_UTILS::Strings::save ( newPath + ".cpp", this->sourceBody ) ) ) {

          qDebug () << "Archivo source creado satisfactoriamente.";

        } else {

          qDebug () << "El archivo source no se pudo crear satisfactoriamente.";
        }
      } else {

        qDebug () << "El archivo header no se pudo crear satisfactoriamente.";
      }
      break;
  }
  return toReturn;
}
