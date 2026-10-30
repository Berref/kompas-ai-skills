#pragma once

#include <QRawFont>
#include <QString>


// Тип шрифта для иконок
enum class IconFontType
{
  base,   // шрифт для монохромных иконок
  accent, // accent шрифт (компонент цветных иконок)
  color1, // color1 шрифт (компонент цветных иконок)
  color2, // color2 шрифт (компонент цветных иконок)
  color3  // color3 шрифт (компонент цветных иконок)
};


////////////////////////////////////////////////////////////////////////////////
//
/// Данные шрифтов иконок приложения (имена, QRawFont)
/**
*/
////////////////////////////////////////////////////////////////////////////////
class AppFonts
{
public:
  /// Конструктор
  AppFonts(const QString & appId);
  /// Получить идентификатор приложения
  const QString & GetAppId() const { return m_appId; }
  /// Добавить шрифт и связать с типом шрифта иконки
  void Add(IconFontType type, const QString & fileName, const QString & fontName);
  /// Связать тип шрифта иконки с реальным именем шрифта приложения
  void Assign(IconFontType type, const QString & name);
  /// Получить QRawFont для типа шрифта
  QRawFont * GetRawFont(IconFontType);
  /// Приложение содержит шрифт?
  bool ContainsFont(const QString & fontName);

private:
  QString m_appId;          ///< Идентификатор приложения
  QString m_base;           ///< Имя монохромного шрифта
  QString m_accent;         ///< Имя accent шрифта
  QString m_color1;         ///< Имя color1 шрифта
  QString m_color2;         ///< Имя color2 шрифта
  QString m_color3;         ///< Имя color3 шрифта
  QRawFont m_baseRawFont;   ///< RawFont для монохромного шрифта
  QRawFont m_accentRawFont; ///< RawFont для accent шрифта
  QRawFont m_color1RawFont; ///< RawFont для color1 шрифта
  QRawFont m_color2RawFont; ///< RawFont для color2 шрифта
  QRawFont m_color3RawFont; ///< RawFont для color3 шрифта
};


////////////////////////////////////////////////////////////////////////////////
//
/// Хранилище шрифтов
/**
*/
////////////////////////////////////////////////////////////////////////////////
class FontDatabase
{
public:
  /// Конструктор
  FontDatabase();

  /// Получить FontDatabase
  static FontDatabase & Instance();

  /// Создать AppFonts для приложения
  const std::shared_ptr<AppFonts> & CreateAppFonts(const QString & appId);
  /// Добавить шрифты приложения из его папки в базу QFontDatabase
  const std::shared_ptr<AppFonts> & AddAppFonts(const QString & appId, const QString & dirPath);
  /// Получить AppFonts для приложения
  const std::shared_ptr<AppFonts> GetAppFonts(const QString & appId) const;
  /// Получить QRawFont для типа шрифта иконок приложения
  QRawFont * GetIconFont(const QString & appId, IconFontType) const;
  /// Найти идентификатор приложения по имени шрифта
  QString FindAppId(const QString & fontName);

private:
  std::unordered_map<QString, std::shared_ptr<AppFonts>> m_appFontsDictionary; ///< Словарь AppFonts для приложений
};
