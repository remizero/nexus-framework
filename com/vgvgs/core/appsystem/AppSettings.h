#ifndef APPSETTINGS_H
#define APPSETTINGS_H

// Librerías Internas
// Internal Libraries
#include "core_global.h"
#include "appsystem/AppPaths.h"

// Librerías Externas
// External Libraries
#include "macros_global.h"

// Librerías Qt
// Qt Libraries
#include <QDebug>
#include <QIODevice>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QMap>
#include <QSettings>
#include <QString>
#include <QStringView>
#include <QStringList>
#include <QVariant>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>


namespace NAMESPACE_LEVEL_1 {

  namespace NAMESPACE_LEVEL_2 {

    namespace NAMESPACE_CORE {

      class CORE_EXPORT AppSettings {

        public :
          static void parseJsonObject ( QJsonObject &json, QString prefix, QMap<QString, QVariant> &map );
          static bool readJsonFile ( QIODevice &device, QMap<QString, QVariant> &map );
          static bool readXmlFile ( QIODevice &device, QSettings::SettingsMap &map );
          static QJsonObject restoreJsonObject ( QMap<QString, QVariant> &map );
          static void saveRecentFile ( const QString &value );
          static void saveRecentProject ( const QString &value );
          static bool writeJsonFile ( QIODevice &device, const QMap<QString, QVariant> &map );
          static bool writeXmlFile ( QIODevice &device, const QSettings::SettingsMap &map );

        private :
          // static QJsonObject restoreJsonObject ( QMap<QString, QVariant> &map );
          static void saveRecent ( const QString &recentGroup, int maxItemsRecentGroup, const QString &key, const QString &value );
      };
    }
  }
}

#endif // APPSETTINGS_H
