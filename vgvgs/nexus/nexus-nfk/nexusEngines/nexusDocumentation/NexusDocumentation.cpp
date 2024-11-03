#include "NexusDocumentation.h"


using namespace NSLIB_DOCUMENTATION;


NexusDocumentation::NexusDocumentation() {

  this->loadSettings ( "" );
}

NexusDocumentation::~NexusDocumentation () {}

QString NexusDocumentation::createAttributeComment ( QRegularExpressionMatch match ) {

  QString comment;
  comment += match.captured ( "first_spaces" ) + "/**\n";
  comment += match.captured ( "first_spaces" ) + " * @name " + match.captured ( "identifier" ).trimmed () + "\n";
  comment += match.captured ( "first_spaces" ) + " * @type " + match.captured ( "data_type" ).trimmed () + "\n";
  if ( !match.captured ( "namespace" ).isEmpty () ) {

    comment += match.captured ( "first_spaces" ) + " * @namespace " + match.captured ( "namespace" ).trimmed () + "\n";
  }
  comment += match.captured ( "first_spaces" ) + " *\n";
  comment += match.captured ( "first_spaces" ) + " * @details\n";
  comment += match.captured ( "first_spaces" ) + " *\n";
  if ( !match.captured ( "assignment" ).isEmpty () ) {

    comment += match.captured ( "first_spaces" ) + " * @value" + match.captured ( "assignment" ).trimmed () + " (Default value).\n";
  }
  comment = this->createFinalComment ( comment, match.captured ( "first_spaces" ) );
  return comment;
}

QString NexusDocumentation::createClassComment ( QRegularExpressionMatch match ) {

  QString comment;
  comment += match.captured ( "first_spaces" ) + "/**\n";
  comment += match.captured ( "first_spaces" ) + " * @class " + match.captured ( "identifier" ).trimmed () + "\n";
  comment += match.captured ( "first_spaces" ) + " *\n";
  comment += match.captured ( "first_spaces" ) + " * @brief\n";
  comment += match.captured ( "first_spaces" ) + " *\n";
  comment += match.captured ( "first_spaces" ) + " * @details\n";
  comment += match.captured ( "first_spaces" ) + " *\n";

  QString extends = match.captured ( "extend" ).remove ( ":" );
  extends = extends.trimmed ();
  if ( !extends.isEmpty () ) {

    if ( extends.contains ( "," ) ) {

      QStringList extendList = extends.split ( "," );
      for ( int i = 0; i < extendList.size (); ++i ) {

        QString extendClass = extendList [ i ].remove ( "public" );
        extendClass = extendClass.trimmed ();
        comment += match.captured ( "first_spaces" ) + " * @extends " + extendClass + "\n";
      }
    } else {

      QString extendClass = extends.remove ( "public" );
      extendClass = extendClass.trimmed ();
      comment += match.captured ( "first_spaces" ) + " * @extends " + extendClass + "\n";
    }
  }
  comment = this->createFinalComment ( comment, match.captured ( "first_spaces" ) );
  return comment;
}

QString NexusDocumentation::createComment ( QRegularExpression regExp, QString line, std::function<QString ( QRegularExpressionMatch )> commentFunction ) {

  QRegularExpressionMatch match = regExp.match ( line );
  if ( match.hasMatch () ) {

    return commentFunction ( match );
  }
  return QString ();
}

QString NexusDocumentation::createFinalComment ( QString comment, QString indent ) {

  QDateTime dateTime = dateTime.currentDateTime ();
  comment += indent + " *\n";
  comment += indent + " * @date " + dateTime.toString ( "yyyy-MM-dd" ) + "\n";
  comment += indent + " * @version\n";
  comment += indent + " * @since\n";
  comment += indent + " * @author " + NSLIB_UTILS::System::getNameUser () + "\n";
  comment += indent + " * @copyright " + dateTime.toString ( "yyyy" ) + "\n";
  comment += indent + " *\n";
  comment += indent + " */";
  return comment;
}

QString NexusDocumentation::createFunctionComment ( QRegularExpressionMatch match ) {

  QString comment;
  comment += match.captured ( "first_spaces" ) + "/**\n";
  if ( match.captured ( "return_type" ).isEmpty () ) {

    if ( !match.captured ( "ref_pointer" ).isEmpty () ) {

      if ( match.captured ( "ref_pointer" ).contains ( "~" ) ) {

        comment += match.captured ( "first_spaces" ) + " * Destructor\n";
      }
    } else {

      comment += match.captured ( "first_spaces" ) + " * Constructor\n";
    }
  } else {

    comment += match.captured ( "first_spaces" ) + " * Function\n";
  }
  if ( !match.captured ( "virtual" ).isEmpty () ) {

    comment += match.captured ( "first_spaces" ) + " * " + match.captured ( "virtual" ).trimmed ();
    if ( !match.captured ( "virtual_pure" ).isEmpty () ) {

      comment += " Pure";
    }
    comment += "\n";
  }
  if ( !match.captured ( "final_modifiers" ).isEmpty () ) {

    if ( match.captured ( "final_modifiers" ).contains ( "const" ) ) {

      comment += match.captured ( "first_spaces" ) + " * Const\n";
    }
    if ( match.captured ( "final_modifiers" ).contains ( "override" ) ) {

      comment += match.captured ( "first_spaces" ) + " * @overload\n";
    }
    if ( match.captured ( "final_modifiers" ).contains ( "final" ) ) {

      comment += match.captured ( "first_spaces" ) + " * Final\n";
    }
  }
  comment += match.captured ( "first_spaces" ) + " *\n";
  comment += match.captured ( "first_spaces" ) + " * @name " + match.captured ( "identifier" ).trimmed () + "\n";
  if ( !match.captured ( "return_type" ).isEmpty () ) {

    comment += match.captured ( "first_spaces" ) + " * @return " + match.captured ( "return_type" ).trimmed ();
    if ( !match.captured ( "ref_pointer" ).isEmpty () ) {

      comment += " " + match.captured ( "ref_pointer" ).trimmed ();
      if ( match.captured ( "ref_pointer" ).contains ( "*" ) ) {

        comment += " (pointer)";
      } else if ( match.captured ( "ref_pointer" ).contains ( "&" ) ) {

        comment += " (reference)";
      }
    }
    comment += " \n";
  }
  comment += match.captured ( "first_spaces" ) + " *\n";
  comment += match.captured ( "first_spaces" ) + " * @details\n";
  comment += match.captured ( "first_spaces" ) + " *\n";

  QString params = match.captured ( "params" ).remove ( "(" ).remove ( ")" );
  params = params.trimmed ();
  if ( !params.isEmpty () ) {

    if ( params.contains ( "," ) ) {

      QStringList paramList = params.split ( "," );
      for ( int i = 0; i < paramList.size (); ++i ) {

        comment = this->parseParam ( comment, paramList [ i ], match.captured ( "first_spaces" ) );
      }
    } else {

      comment = this->parseParam ( comment, params, match.captured ( "first_spaces" ) );
    }
  }
  comment = this->createFinalComment ( comment, match.captured ( "first_spaces" ) );
  return comment;
}

void NexusDocumentation::getContentFromFile ( const QString &path ) {

  QFile *ioDeviceFile = NSLIB_UTILS::Files::load ( path );
  QTextStream in ( ioDeviceFile );
  this->currentContent.clear ();
  while ( !in.atEnd () ) {

    this->currentContent << in.readLine ();
  }
  ioDeviceFile->close();
  delete ioDeviceFile;
}

void NexusDocumentation::getFileList ( const QString &path ) {

  this->fileList = NSLIB_UTILS::Files::findFiles ( path, "*.h" );
}

bool NexusDocumentation::isValidDirectory ( const QString &path ) {

  QDir dir ( path );
  return dir.exists () && dir.isReadable () && dir.isAbsolute ();
}

bool NexusDocumentation::isValidPattern ( QRegularExpression &pattern ) {

  return pattern.isValid ();
}

void NexusDocumentation::iterateFileList () {

  for ( int i = 0; i < this->fileList.size (); i++ ) {

    this->currentFile = this->fileList [ i ];
    this->getContentFromFile ( this->currentFile );
    bool insideCommentBlock = false;
    bool insideCommentLine  = false;
    bool hasComment         = false;
    bool previousComment    = false;
    QString newComment      = "";
    for ( int n = 0; n < this->currentContent.size (); ++n ) {

      if ( insideCommentBlock ) {

        if ( this->patterncommentEndBlock.match ( this->currentContent [ n ] ).hasMatch () ) {

          insideCommentBlock = false;
        }
      } else if ( this->patternCommentStartBlock.match ( this->currentContent [ n ] ).hasMatch () ) {

        insideCommentBlock = true;
        hasComment = true;
      }
      if ( this->patternCommentLineBlock.match ( this->currentContent [ n ] ).hasMatch () ) {

        insideCommentLine = true;
        hasComment = true;

      } else {
        if ( insideCommentLine ) {

          insideCommentLine = false;
        }
      }
      if ( !insideCommentBlock && !insideCommentLine && !hasComment && !previousComment ) {

        newComment = createComment ( this->patternFunctions, this->currentContent [ n ], [this](QRegularExpressionMatch match) { return this->createFunctionComment ( match ); } );
        if ( newComment.isEmpty () ) {

          newComment = createComment ( this->patternAttributes, this->currentContent [ n ], [this](QRegularExpressionMatch match) { return this->createAttributeComment ( match ); } );
          if ( newComment.isEmpty () ) {

            newComment = createComment ( this->patternClassDefinition, this->currentContent [ n ], [this](QRegularExpressionMatch match) { return this->createClassComment ( match ); } );
          }
        }
        if ( !newComment.isEmpty () ) {

          this->currentContent.insert ( n, newComment );
          ++n;
        }
        newComment.clear ();
      }
      previousComment = hasComment;
      hasComment = false;
    }
    NSLIB_UTILS::Files::save ( this->currentFile, QVariant ( this->currentContent.join ( "\n" )) );
  }
}

void NexusDocumentation::loadSettings ( const QString &path ) {

  QSettings settings ( path, QSettings::IniFormat );

  this->beginningOfExpression   = settings.value ( "General/beginningOfExpression",     this->beginningOfExpression ).toString ();
  this->endDefinitionGroup      = settings.value ( "General/endDefinitionGroup",        this->endDefinitionGroup ).toString ();
  this->privateSection          = settings.value ( "General/privateSection",            this->privateSection ).toString ();
  this->protectedSection        = settings.value ( "General/protectedSection",          this->protectedSection ).toString ();
  this->publicSection           = settings.value ( "General/publicSection",             this->publicSection ).toString ();
  this->classDefinition         = settings.value ( "General/classDefinition",           this->classDefinition ).toString ();
  this->namespaceSeccion        = settings.value ( "General/namespaceSeccion",          this->namespaceSeccion ).toString ();

  this->storageModifierGroup    = settings.value ( "Attribute/storageModifierGroup",    this->storageModifierGroup ).toString ();
  this->qualifiersModifierGroup = settings.value ( "Attribute/qualifiersModifierGroup", this->qualifiersModifierGroup ).toString ();
  this->signModifierGroup       = settings.value ( "Attribute/signModifierGroup",       this->signModifierGroup ).toString ();
  this->sizeModifierGroup       = settings.value ( "Attribute/sizeModifierGroup",       this->sizeModifierGroup ).toString ();
  this->namespaceGroup          = settings.value ( "Attribute/namespaceGroup",          this->namespaceGroup ).toString ();
  this->dataTypeGroup           = settings.value ( "Attribute/dataTypeGroup",           this->dataTypeGroup ).toString ();
  this->refPointerGroup         = settings.value ( "Attribute/refPointerGroup",         this->refPointerGroup ).toString ();
  this->identifierGroup         = settings.value ( "Attribute/identifierGroup",         this->identifierGroup ).toString ();
  this->arrayDeclarationGroup   = settings.value ( "Attribute/arrayDeclarationGroup",   this->arrayDeclarationGroup ).toString ();
  this->assignmentGroup         = settings.value ( "Attribute/assignmentGroup",         this->assignmentGroup ).toString ();
  this->extraVarsGroup          = settings.value ( "Attribute/extraVarsGroup",          this->extraVarsGroup ).toString ();

  this->virtuaGroup             = settings.value ( "Function/virtuaGroup",              this->virtuaGroup ).toString ();
  this->returnTypeGroup         = settings.value ( "Function/returnTypeGroup",          this->returnTypeGroup ).toString ();
  this->paramsGroup             = settings.value ( "Function/paramsGroup",              this->paramsGroup ).toString ();
  this->virtualPureGroup        = settings.value ( "Function/virtualPureGroup",         this->virtualPureGroup ).toString ();
  this->finalModifiersGroup     = settings.value ( "Function/finalModifiersGroup",      this->finalModifiersGroup ).toString ();
  this->bodyFunctionGroup       = settings.value ( "Function/bodyFunctionGroup",        this->bodyFunctionGroup ).toString ();

  this->patternAttribute        = QString ( R"(%1%2%3%4%5%6%7%8%9%10%11%12%13)" ).
                                          arg ( this->beginningOfExpression ).
                                          arg ( this->storageModifierGroup ).
                                          arg ( this->qualifiersModifierGroup ).
                                          arg ( this->signModifierGroup ).
                                          arg ( this->sizeModifierGroup ).
                                          arg ( this->namespaceGroup ).
                                          arg ( this->dataTypeGroup ).
                                          arg ( this->refPointerGroup ).
                                          arg ( this->identifierGroup ).
                                          arg ( this->arrayDeclarationGroup ).
                                          arg ( this->assignmentGroup ).
                                          arg ( this->extraVarsGroup ).
                                          arg ( this->endDefinitionGroup );

  this->patternClass            = QString ( R"(%1%2%3%4%5%6)" ).
                                          arg ( this->beginningOfExpression ).
                                          arg ( this->classDefinition ).
                                          arg ( this->exportSeccion ).
                                          arg ( this->identifierGroup ).
                                          arg ( this->extendSeccion ).
                                          arg ( this->endClassDefinitionGroup );

  this->patternFunction         = QString ( R"(%1%2%3%4%5%6%7%8%9%10%11%12%13%14%15)" ).
                                          arg ( this->beginningOfExpression ).
                                          arg ( this->virtuaGroup ).
                                          arg ( this->storageModifierGroup ).
                                          arg ( this->qualifiersModifierGroup ).
                                          arg ( this->signModifierGroup ).
                                          arg ( this->sizeModifierGroup ).
                                          arg ( this->namespaceGroup ).
                                          arg ( this->returnTypeGroup ).
                                          arg ( this->refPointerGroup ).
                                          arg ( this->identifierGroup ).
                                          arg ( this->paramsGroup ).
                                          arg ( this->finalModifiersGroup ).
                                          arg ( this->virtualPureGroup ).
                                          arg ( this->bodyFunctionGroup ).
                                          arg ( this->endDefinitionGroup );

  this->patternNamespace        = QString ( R"(%1%2%3%4)" ).
                                          arg ( this->beginningOfExpression ).
                                          arg ( this->namespaceSeccion ).
                                          arg ( this->namespaceNameSeccion ).
                                          arg ( this->endClassDefinitionGroup );

  this->patternCommentStart     = QString ( R"(%1%2)" ).
                                          arg ( this->beginningOfExpression ).
                                          arg ( this->startCommentBlock );

  this->patterncommentEnd       = QString ( R"(%1%2)" ).
                                          arg ( this->beginningOfExpression ).
                                          arg ( this->endCommentBlock );

  this->patternCommentLine      = QString ( R"(%1%2)" ).
                                          arg ( this->beginningOfExpression ).
                                          arg ( this->lineCommentBlock );

  this->patternAttributes.setPattern        ( this->patternAttribute );
  this->patternFunctions.setPattern         ( this->patternFunction );
  this->patternPrivateSection.setPattern    ( QString ( R"(%1)" ).arg ( this->privateSection ) );
  this->patternProtectedSection.setPattern  ( QString ( R"(%1)" ).arg ( this->protectedSection ) );
  this->patternPublicSection.setPattern     ( QString ( R"(%1)" ).arg ( this->publicSection ) );
  this->patternClassDefinition.setPattern   ( this->patternClass );
  this->patternNamespaceSeccion.setPattern  ( this->patternNamespace );
  this->patternCommentStartBlock.setPattern ( this->patternCommentStart );
  this->patterncommentEndBlock.setPattern   ( this->patterncommentEnd );
  this->patternCommentLineBlock.setPattern  ( this->patternCommentLine );
}

QString NexusDocumentation::parseParam ( QString comment, QString param, QString indent ) {

  QStringList paramValue;
  QString paramIdentifier;
  QStringList identifierSplit;
  if ( param.contains ( "=" ) ) {

    paramValue = param.split ( "=" );
    paramIdentifier = paramValue [ 0 ].trimmed ();
    identifierSplit = paramIdentifier.split ( R"(\s)" );
    comment += indent + " * @param " + identifierSplit.last ().trimmed () + " \n";
    comment += indent + " * @value " + paramValue [ 1 ].trimmed () + " (Default value).\n";

  } else {

    paramIdentifier = param.trimmed ();
    identifierSplit = paramIdentifier.split ( R"(\s)" );
    comment += indent + " * @param " + identifierSplit.last ().trimmed () + " \n";
  }
  return comment;
}
