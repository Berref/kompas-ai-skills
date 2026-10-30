#pragma once


#include <QIcon>


// Тип цвета рисования иконки
enum class IconColorType
{
  undef,
  monochome, ///< Монохромная иконка
  color,     ///< Одноцветная иконка
  colorFonts ///< Цветная иконка, составленная из комбинации шрифтов разного цвета
};


////////////////////////////////////////////////////////////////////////////////
//
///
/** Параметры рисования иконки
*/
////////////////////////////////////////////////////////////////////////////////
class IconParams
{
public:
  IconParams();

  /// Проинициалировать монохромные цвета для MenuItem
  void InitMonochomeMenuItem();
  /// Проинициалировать монохромные цвета для ToolButton
  void InitMonochomeToolButton();
  /// Проинициалировать многоцветные для ToolButton ленты и тулбара
  void InitColorToolButton();
  /// Проинициализировать определенным цветом для всех состояний
  void InitColor(const QColor *);

  /// Установить размер иконки
  void SetIconSize(const QSize & size) { m_iconSize = size; }
  /// Получить размер иконки
  const QSize & GetIconSize() const { return m_iconSize; }

  /// Установить символ иконки (общий, если не заданы символы для Check/Uncheck состояния)
  void SetIconSymbol(QChar symbol) { m_iconSymbol = symbol; }
  /// Получить символ иконки (общий, если не заданы символы для Check/Uncheck состояния)
  QChar GetIconSymbol() const { return m_iconSymbol; }

  /// Установить символ Uncheck состояния
  void SetUncheckSymbol(QChar symbol) { m_uncheckSymbol = symbol; }
  /// Получить символ Uncheck состояния
  QChar GetUncheckSymbol() const { return m_uncheckSymbol; }

  /// Установить символ Check состояния
  void SetCheckSymbol(QChar symbol) { m_checkSymbol = symbol; }
  /// Получить символ Check состояния
  QChar GetCheckSymbol() const { return m_checkSymbol; }

  /// Установить тип цвета рисования иконки
  void SetColorType(IconColorType type) { m_colorType = type; }
  /// Получить тип цвета рисования иконки
  IconColorType GetColorType() const { return m_colorType; }

  /// Установить цвет Uncheck состояния
  void SetUncheckColor(const QColor * color) { m_uncheckColor = color; }
  /// Установить цвет Uncheck состояния при наведении мышкой
  void SetUncheckHoverColor(const QColor * color) { m_uncheckHoverColor = color; }
  /// Установить цвет Check состояния
  void SetCheckColor(const QColor * color) { m_checkColor = color; }
  /// Установить цвет Check состояния при наведении мышкой
  void SetCheckHoverColor(const QColor * color) { m_checkHoverColor = color; }
  /// Получить цвет Uncheck состояния
  const QColor * GetUncheckColor() const { return m_uncheckColor; }
  /// Получить цвет Uncheck состояния при наведении мышкой
  const QColor * GetUncheckHoverColor() const { return m_uncheckHoverColor; }
  /// Получить цвет Check состояния
  const QColor * GetCheckColor() const { return m_checkColor; }
  /// Получить цвет Check состояния при наведении мышкой
  const QColor * GetCheckHoverColor() const { return m_checkHoverColor; }
  /// Установить цвет фона
  void SetBackgroundColor(const QColor * color) { m_backgroundColor = color; }
  /// Получить цвет фона
  const QColor * GetBackgroundColor() const { return m_backgroundColor; }
  /// Получить цвет недоступного состояния
  const QColor * GetDisableColor() const;

  /// Получить идентификатор приложения
  void SetAppId(const QString & appId) { m_appId = appId; }
  /// Получить идентификатор приложения
  const QString & GetAppId() const { return m_appId; }

private:
  QChar m_iconSymbol;                               ///< Символ иконки (общий, если не заданы символы для Check/Uncheck состояния)
  QChar m_uncheckSymbol;                            ///< Символ Check состояния
  QChar m_checkSymbol;                              ///< Символ Uncheck состояния
  QSize m_iconSize;                                 ///< Размер иконки
  IconColorType m_colorType = IconColorType::undef; ///< Тип цвета рисования иконки
  const QColor * m_uncheckColor = nullptr;          ///< Цвет Uncheck состояния
  const QColor * m_uncheckHoverColor = nullptr;     ///< Цвет Uncheck состояния при наведении мышкой
  const QColor * m_checkColor = nullptr;            ///< Цвет Check состояния
  const QColor * m_checkHoverColor = nullptr;       ///< Цвет Check состояния при наведении мышкой
  const QColor * m_backgroundColor = nullptr;       ///< Цвет фона
  QString m_appId;                                  ///< Идентификатор приложения
};


////////////////////////////////////////////////////////////////////////////////
//
///
/** Параметры рисования Pixmap
*/
////////////////////////////////////////////////////////////////////////////////
class PixmapParams
{
public:
  // Тип вычисляемого параметра
  enum CalcParamType
  {
    undef,
    font, // Вычислять размер шрифта по размеру иконки
    size  // Вычислять размер иконки по размеру шрифта
  };

  // Тип формы рисования иконки
  enum class IconShape
  {
    square,    ///< Иконка квадратной формы
    calculated ///< Размер иконки рассчитывается по размеру символа
  };

public:
  PixmapParams();

  /// Установить символ иконки (общий, если не заданы символы для Check/Uncheck состояния)
  void SetIconSymbol(QChar symbol) { m_iconSymbol = symbol; }
  /// Получить символ иконки (общий, если не заданы символы для Check/Uncheck состояния)
  QChar GetIconSymbol() const { return m_iconSymbol; }

  /// Установить размер шрифта (размер иконки будет вычисляться при рисовании)
  void SetFontSize(int size, IconShape shape = IconShape::square);
  /// Получить размер шрифта
  int GetFontSize() const { return m_fontSize; }

  /// Установить размер иконки (размер шрифта будет вычисляться при рисовании)
  void SetIconSize(QSize size);
  /// Получить размер иконки
  QSize GetIconSize() const { return m_iconSize; }

  /// Получить тип вычисляемого параметра
  CalcParamType GetCalcParamType() const { return m_calcParamType; }
  /// Получить тип формы рисования иконки
  IconShape GetIconShape() const { return m_shape; }

  /// Установить тип цвета рисования иконки
  void SetColorType(IconColorType type) { m_colorType = type; }
  /// Получить тип цвета рисования иконки
  IconColorType GetColorType() const { return m_colorType; }

  /// Установить цвет символа
  void SetColor(const QColor * color) { m_color = color; }
  /// Получить цвет символа
  const QColor * GetColor() const { return m_color; }
  /// Установить цвет фона
  void SetBackgroundColor(const QColor * color) { m_backgroundColor = color; }
  /// Получить цвет фона
  const QColor * GetBackgroundColor() const { return m_backgroundColor; }

  /// Получить идентификатор приложения
  void SetAppId(const QString & appId) { m_appId = appId; }
  /// Получить идентификатор приложения
  const QString & GetAppId() const { return m_appId; }

private:
  friend class IconUtil;
  /// Установить вычисленный размер шрифта из IconUtil
  void UpdateFontSize(int fontSize) { m_fontSize = fontSize; }
  /// Установить вычисленный размер иконки из IconUtil
  void UpdateIconSize(const QSize & size) { m_iconSize = size; }

private:
  QChar m_iconSymbol;                                   ///< Символ
  int m_fontSize = 0;                                   ///< Размер шрифта
  QSize m_iconSize;                                     ///< Размер иконки
  IconColorType m_colorType = IconColorType::undef;     ///< Тип цвета рисования иконки
  const QColor * m_color = nullptr;                     ///< Цвет символа
  const QColor * m_backgroundColor = nullptr;           ///< Цвет фона
  CalcParamType m_calcParamType = CalcParamType::undef; ///< Вычисляемый параметр (размер шрифта или иконки)
  IconShape m_shape = IconShape::square;                ///< Тип формы рисования иконки
  QString m_appId;                                      ///< Идентификатор приложения
};
