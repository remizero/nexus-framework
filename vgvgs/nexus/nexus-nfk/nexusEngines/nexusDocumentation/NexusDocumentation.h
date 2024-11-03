#ifndef NEXUSDOCUMENTATION_H
#define NEXUSDOCUMENTATION_H

// Librerías Internas
// Internal Libraries
#include "Documentation_global.h"

// Librerías Externas
// External Libraries
#include "Files.h"
#include "System.h"

// Librerías de terceros
// third-party Library

// Librerías Qt
// Qt Libraries
#include <QDateTime>
#include <QDir>
#include <QFile>
#include <QObject>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QSettings>
#include <QString>
#include <QStringList>
#include <QTextStream>
#include <QVariant>

// Librerías C++
// C++ Libraries


namespace NS_VGVGS {

  namespace NS_NEXUS {

    namespace NS_DOCUMENTATION {

      class DOCUMENTATION_EXPORT NexusDocumentation : public QObject {

          Q_OBJECT

        public :
          NexusDocumentation ();
          ~NexusDocumentation ();

          QString createAttributeComment ( QRegularExpressionMatch match );
          QString createClassComment ( QRegularExpressionMatch match );
          QString createComment ( QRegularExpression regExp, QString line, std::function<QString ( QRegularExpressionMatch )> commentFunction );
          QString createFinalComment ( QString comment, QString indent );
          QString createFunctionComment ( QRegularExpressionMatch match );
          void getContentFromFile ( const QString &path );
          void getFileList ( const QString &path );
          bool isValidDirectory ( const QString &path );
          bool isValidPattern ( QRegularExpression &pattern );
          void iterateFileList ();
          void loadSettings ( const QString &path );
          QString parseParam ( QString comment, QString param, QString indent );
          void parseFiles ();

        private :
                 QStringList fileList;
                 QStringList currentContent;
                     QString currentFile;
                     QString beginningOfExpression   = R"((?<first_spaces>\s*))";
                     QString storageModifierGroup    = R"((?<storage_modifier>(?:static|extern|auto|register|thread_local|mutable)\s+)?)";
                     QString qualifiersModifierGroup = R"((?<qualifiers_modifier>(?:(?:const|volatile)\s+)*)?)";
                     QString signModifierGroup       = R"((?<sign_modifier>(?:signed|unsigned)\s+)?)";
                     QString sizeModifierGroup       = R"((?<size_modifier>(?:(?:short|long)\s+)?)?)";
                     QString namespaceGroup          = R"((?<namespace>(?:[A-Za-z_][A-Za-z0-9_]*::)*)?)";
                     QString dataTypeGroup           = R"((?<data_type>(?:bool|int|short|float|double|char|long|[A-Za-z_][A-Za-z0-9_]*)\s+){1})";
                     QString refPointerGroup         = R"((?<ref_pointer>(?:\*|\&|\~)\s*)?)";
                     QString identifierGroup         = R"((?<identifier>[A-Za-z_][A-Za-z0-9_]*\s*))";
                     QString arrayDeclarationGroup   = R"((?<array_declaration>(?:\[\s*\d*\s*\]\s*)*)?)";
                     QString assignmentGroup         = R"((?<assignment>(?:=\s*(?:\{(?:[^{}]*|(?:\{(?:[^{}]*|(?:\{[^{}]*\}))*\}))*\})|\s*\{(?:[^{}]*|(?:\{(?:[^{}]*|(?:\{[^{}]*\}))*\}))*\}|=\s*[^,;{}]+)?))";
                     QString extraVarsGroup          = R"((?<extra_vars>(?:,\s*(?:\*\s*|\&\s*)?(?:[A-Za-z_][A-Za-z0-9_]*\s*)(?:=\s*(?:[^,;{}]+|\{(?:[^{}]*|(?1))*\})\s*)?)*)?)";
                     QString endDefinitionGroup      = R"((?<end_definition>;))";
                     QString virtuaGroup             = R"((?<virtual>(?:extern|static|inline|virtual)\s+)?)";
                     QString returnTypeGroup         = R"((?<return_type>(?:void|bool|int|short|float|double|char|long|[A-Za-z0-9_]+)\s+)?)";
                     QString paramsGroup             = R"((?<params>\(\s*(?:(?:(?:const\s+)?(?:(?:signed|unsigned)\s+)?(?:(?:short|long)\s+)?(?:(?:[A-Za-z_][A-Za-z0-9_]*::)*)?(?:(?:bool|int|short|float|double|char|long|[A-Za-z0-9_]+)\s+)(?:(?:\*|\&)\s*)?(?:[A-Za-z_][A-Za-z0-9_]*\s*)(?:=\s*[^,)]*)?\s*)(?:,\s*)?)*\s*\)\s*))";
                     QString virtualPureGroup        = R"((?<virtual_pure>\s*=\s*0\s*)?)";
                     QString finalModifiersGroup     = R"((?<final_modifiers>(?:\s+(?:const|override|final)\s*)*)?)";
                     QString bodyFunctionGroup       = R"((?<body>\s*{[^{}]*})?)";
                     QString privateSection          = R"(\s*(private)\s*(\:))";
                     QString protectedSection        = R"(\s*(protected)\s*(\:))";
                     QString publicSection           = R"(\s*(public)\s*(\:))";
                     QString classDefinition         = R"((?<class>class\s+))";
                     QString extendSeccion           = R"((?<extend>\:\s*(?:(?:public\s+(?:[A-Za-z_][A-Za-z0-9_]+::)?(?:[A-Za-z_][A-Za-z0-9_]+)\s*)(?:,\s*)?)*)?)";
                     QString exportSeccion           = R"((?<export>[A-Z_][A-Z0-9_]+\s+))";
                     QString endClassDefinitionGroup = R"((?<end_class_definition>\{))";
                     QString namespaceSeccion        = R"((?:<namespace>namespace\s+))";
                     QString namespaceNameSeccion    = R"((?:<namespace_name>[A-Za-z_][a-zA-Z0-9_]+\s*))";
                     QString startCommentBlock       = R"((/\*\*|/\*!))";
                     QString endCommentBlock         = R"((\*/))";
                     QString lineCommentBlock        = R"((///))";
                     QString patternAttribute;
                     QString patternClass;
                     QString patternFunction;
                     QString patternNamespace;
                     QString patternCommentStart;
                     QString patterncommentEnd;
                     QString patternCommentLine;
          QRegularExpression patternAttributes;
          QRegularExpression patternFunctions;
          QRegularExpression patternPrivateSection;
          QRegularExpression patternProtectedSection;
          QRegularExpression patternPublicSection;
          QRegularExpression patternClassDefinition;
          QRegularExpression patternNamespaceSeccion;
          QRegularExpression patternCommentStartBlock;
          QRegularExpression patterncommentEndBlock;
          QRegularExpression patternCommentLineBlock;
      };
    }
  }
}

#endif // NEXUSDOCUMENTATION_H
