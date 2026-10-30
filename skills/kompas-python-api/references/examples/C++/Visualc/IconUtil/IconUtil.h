#pragma once

#include <QIcon>

#include "IconParams.h" 

class QRawFont;


////////////////////////////////////////////////////////////////////////////////
//
/// Класс для работы с иконками
/**
*/
////////////////////////////////////////////////////////////////////////////////
class IconUtil
{
public:
  /// Создать иконку по параметрам
  static QIcon Create(const IconParams & params);
  /// Создать Pixmap по параметрам
  static QPixmap Create(const PixmapParams & params);

protected:
  /// Нарисовать цветную иконку символа с помощью комбинации шрифтов
  static void DrawColorFontPixmap(QPixmap & pixmap, QChar glyph);
  /// Нарисовать иконку символа из шрифта
  static void DrawPixmap(QPixmap & pixmap, QChar glyph, const QRawFont * font, const QColor * color);

  /// Вычислить размер Pixmap для символа
  static QSize CalcPixmapSize(QChar glyph);
  /// Вычислить размер Pixmap для размера шрифта
  static QSize CalcPixmapSize(int fontSize);
  /// Вычислить размер Pixmap для размера иконки
  static QSize CalcPixmapSize(QSize iconSize);

  /// Вычислить размер иконки для размера шрифта (для IconShape::square)
  static QSize CalcIconSize(int fontSize);
  /// Вычислить размер области рисования Pixmap для размера шрифта (для IconShape::calculated)
  static QSize CalcIconSize(QChar glyph, int fontSize);
  /// Вычислить размер шрифта по размеру иконки
  static double CalcFontSize(QSize iconSize);

  /// Нарисовать Pixmap и добавить в иконку как состояние
  static void AddIconState(QIcon & icon, QIcon::Mode mode, QIcon::State state, const QChar & symbol, const QRawFont * font,
                           QSize iconSize, const QColor * backColor, const QColor * color);

  /// Проверяет, есть ли символ в цветных шрифтах
  static bool IsExistColorFonts(QChar glyph);
  /// Проверяет, есть ли символ в шрифте
  static bool IsExistSymbol(const QRawFont * font, QChar glyph);

  /// Установить PixelSize шрифтам
  static void SetFontPixelSize(double size);

  static QRawFont * m_baseFont;
  static QRawFont * m_accentFont;
  static QRawFont * m_color1Font;
  static QRawFont * m_color2Font;
  static QRawFont * m_color3Font;
};


