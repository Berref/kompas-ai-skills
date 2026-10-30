#include "FontDatabase.h"

#include <QDir>
#include <QFileInfo>
#include <QFontDatabase>




//------------------------------------------------------------------------------
/** Конструктор
*/
//---
AppFonts::AppFonts(const QString & appId)
  : m_appId(appId)
{
}

//------------------------------------------------------------------------------
/** Добавить шрифт и связать с типом шрифта иконки
*/
//---
void AppFonts::Add(IconFontType type, const QString & fileName, const QString & fontName)
{
  QFontDatabase::addApplicationFont(fileName);
  Assign(type, fontName);
}

//------------------------------------------------------------------------------
/** Задать шрифт
*/
//---
void AppFonts::Assign(IconFontType type, const QString & name)
{
  QFont font = QFontDatabase::font(name, QString(), 0);
  font.setHintingPreference(QFont::PreferFullHinting);
  QRawFont rawFont = QRawFont::fromFont(font);

  switch (type)
  {
    case IconFontType::base:
      m_base = name;
      m_baseRawFont = rawFont;
      break;
    case IconFontType::accent:
      m_accent = name;
      m_accentRawFont = rawFont;
      break;
    case IconFontType::color1:
      m_color1 = name;
      m_color1RawFont = rawFont;
      break;
    case IconFontType::color2:
      m_color2 = name;
      m_color2RawFont = rawFont;
      break;
    case IconFontType::color3:
      m_color3 = name;
      m_color3RawFont = rawFont;
      break;
    default:
      break;
  }
}

//------------------------------------------------------------------------------
/** Получить QRawFont для типа шрифта
*/
//---
QRawFont * AppFonts::GetRawFont(IconFontType part)
{
  switch (part)
  {
    case IconFontType::base:
      return &m_baseRawFont;
      break;
    case IconFontType::accent:
      return &m_accentRawFont;
      break;
    case IconFontType::color1:
      return &m_color1RawFont;
      break;
    case IconFontType::color2:
      return &m_color2RawFont;
      break;
    case IconFontType::color3:
      return &m_color3RawFont;
      break;
    default:
      break;
  }

  return nullptr;
}

//------------------------------------------------------------------------------
/** Приложение содержит шрифт?
*/
//---
bool AppFonts::ContainsFont(const QString & fontName)
{
  return (fontName == m_base || fontName == m_accent || fontName == m_color1 || fontName == m_color2 || fontName == m_color3)
         ? true
         : false;
}


//------------------------------------------------------------------------------
/** Получить FontDatabase
*/
//---
FontDatabase & FontDatabase::Instance()
{
  static FontDatabase instance;
  return instance;
}

//------------------------------------------------------------------------------
/** Конструктор
*/
//---
FontDatabase::FontDatabase()
{
  // Добавить шрифты иконок Компаса
  std::shared_ptr<AppFonts> kompasFonts = CreateAppFonts(u8"Kompas");
  kompasFonts->Assign(IconFontType::base, u8"Ascon Icons Base");
  kompasFonts->Assign(IconFontType::accent, u8"Ascon Icons Accent");
  kompasFonts->Assign(IconFontType::color1, u8"Ascon Icons Color1");
  kompasFonts->Assign(IconFontType::color2, u8"Ascon Icons Color2");
  kompasFonts->Assign(IconFontType::color3, u8"Ascon Icons Color3");
}

//------------------------------------------------------------------------------
/** Создать AppFonts для приложения
*/
//---
const std::shared_ptr<AppFonts> & FontDatabase::CreateAppFonts(const QString & appId)
{
  if (!m_appFontsDictionary.contains(appId))
    m_appFontsDictionary[appId] = std::make_shared<AppFonts>(appId);

  return m_appFontsDictionary[appId];
}

//------------------------------------------------------------------------------
/** Добавить шрифты приложения из его папки в базу QFontDatabase
*/
//---
const std::shared_ptr<AppFonts> & FontDatabase::AddAppFonts(const QString & appId, const QString & dirPath)
{
  QDir qDir(dirPath);
  // фильтр для файлов шрифтов
  QStringList filters;
  filters << "*.ttf"
          << "*.otf";
  // получить список файлов шрифтов
  QStringList fontFiles = qDir.entryList(filters, QDir::Files);
  for (const QString & file : fontFiles)
  {
    QString path = dirPath + "/" + file;
    QFontDatabase::addApplicationFont(path);
  }

  return CreateAppFonts(appId);
}

//------------------------------------------------------------------------------
/** Получить QRawFont для типа шрифта иконок приложения
*/
//---
QRawFont * FontDatabase::GetIconFont(const QString & appId, IconFontType fontPart) const
{
  if (m_appFontsDictionary.contains(appId))
    return m_appFontsDictionary.at(appId)->GetRawFont(fontPart);

  return nullptr;
}

//------------------------------------------------------------------------------
/** Получить AppFonts для приложения
*/
//---
const std::shared_ptr<AppFonts> FontDatabase::GetAppFonts(const QString & appId) const
{
  if (m_appFontsDictionary.contains(appId))
    return m_appFontsDictionary.at(appId);
  return nullptr;
}

//------------------------------------------------------------------------------
/** Найти идентификатор приложения по имени шрифта
*/
//---
QString FontDatabase::FindAppId(const QString & fontName)
{
  for (auto & item : m_appFontsDictionary)
  {
    if (item.second->ContainsFont(fontName))
      return item.first;
  }
  return QString();
}
