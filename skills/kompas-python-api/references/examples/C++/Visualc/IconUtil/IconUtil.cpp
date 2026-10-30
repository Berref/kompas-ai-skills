#include "IconUtil.h"

#include <QApplication>
#include <QFont>
#include <QFontMetrics>
#include <QGlyphRun>
#include <QPainter>
#include <QRawFont>
#include <QScreen>

#include "FontDatabase.h" 




QRawFont * IconUtil::m_baseFont = nullptr;
QRawFont * IconUtil::m_accentFont = nullptr;
QRawFont * IconUtil::m_color1Font = nullptr;
QRawFont * IconUtil::m_color2Font = nullptr;
QRawFont * IconUtil::m_color3Font = nullptr;


//------------------------------------------------------------------------------
/** Создать иконку по параметрам
*/
//---
QIcon IconUtil::Create(const IconParams & params)
{
  QIcon icon;

  auto & fontDatabase = FontDatabase::Instance();
  m_baseFont = fontDatabase.GetIconFont(params.GetAppId(), IconFontType::base);
  m_accentFont = fontDatabase.GetIconFont(params.GetAppId(), IconFontType::accent);
  m_color1Font = fontDatabase.GetIconFont(params.GetAppId(), IconFontType::color1);
  m_color2Font = fontDatabase.GetIconFont(params.GetAppId(), IconFontType::color2);
  m_color3Font = fontDatabase.GetIconFont(params.GetAppId(), IconFontType::color3);

  if (m_baseFont == nullptr || params.GetColorType() == IconColorType::undef)
    return icon;

  QSize iconSize = params.GetIconSize();
  // Вычислить размер шрифта для размера иконки
  double fontSize = CalcFontSize(iconSize);
  SetFontPixelSize(fontSize);

  QChar symbol = params.GetIconSymbol();
  QChar uncheckSymbol = symbol;
  QChar checkSymbol = symbol;

  if (!params.GetUncheckSymbol().isNull())
    uncheckSymbol = params.GetUncheckSymbol();

  if (!params.GetCheckSymbol().isNull())
    checkSymbol = params.GetCheckSymbol();

  IconColorType iconColorType = params.GetColorType();

  // Если нет символа в цветных шрифтах, то отображать монохромным
  if (iconColorType == IconColorType::colorFonts && !IsExistColorFonts(symbol))
    iconColorType = IconColorType::monochome;

  if (iconColorType == IconColorType::colorFonts)
  {
    if (!symbol.isNull() && m_accentFont && m_color1Font && m_color2Font && m_color3Font)
    {
      AddIconState(icon, QIcon::Disabled, QIcon::Off, symbol, m_baseFont, iconSize, nullptr, params.GetDisableColor());
      AddIconState(icon, QIcon::Disabled, QIcon::On, symbol, m_baseFont, iconSize, nullptr, params.GetDisableColor());

      QPixmap pixNormal{CalcPixmapSize(iconSize)};
      pixNormal.fill(Qt::transparent);
      DrawColorFontPixmap(pixNormal, symbol);
      icon.addPixmap(pixNormal, QIcon::Normal, QIcon::On);
      icon.addPixmap(pixNormal, QIcon::Normal, QIcon::Off);
    }
  }
  else if (iconColorType == IconColorType::color || iconColorType == IconColorType::monochome)
  {
    if (!checkSymbol.isNull() && !uncheckSymbol.isNull())
    {
      AddIconState(icon, QIcon::Disabled, QIcon::Off, uncheckSymbol, m_baseFont, iconSize, params.GetBackgroundColor(),
                   params.GetDisableColor());
      AddIconState(icon, QIcon::Disabled, QIcon::On, checkSymbol, m_baseFont, iconSize, params.GetBackgroundColor(),
                   params.GetDisableColor());
      AddIconState(icon, QIcon::Normal, QIcon::Off, uncheckSymbol, m_baseFont, iconSize, params.GetBackgroundColor(),
                   params.GetUncheckColor());
      AddIconState(icon, QIcon::Normal, QIcon::On, checkSymbol, m_baseFont, iconSize, params.GetBackgroundColor(),
                   params.GetCheckColor());
      AddIconState(icon, QIcon::Active, QIcon::Off, uncheckSymbol, m_baseFont, iconSize, params.GetBackgroundColor(),
                   params.GetUncheckHoverColor());
      AddIconState(icon, QIcon::Active, QIcon::On, checkSymbol, m_baseFont, iconSize, params.GetBackgroundColor(),
                   params.GetCheckHoverColor());
    }
  }

  return icon;
}


//------------------------------------------------------------------------------
/**
  Нарисовать Pixmap и добавить в иконку как состояние
  \param icon иконка в которую будет добавляться состояние
  \param mode режим
  \param state состояние
  \param symbol символ шрифта
  \param font шрифт
  \param fontSize размер шрифта
  \param color цвет иконки
*/
//---
void IconUtil::AddIconState(QIcon & icon, QIcon::Mode mode, QIcon::State state, const QChar & symbol, const QRawFont * font,
                            QSize iconSize, const QColor * backColor, const QColor * color)
{
  if (font && color)
  {
    QPixmap pixmap{CalcPixmapSize(iconSize)};

    if (backColor)
      pixmap.fill(*backColor);
    else
      pixmap.fill(Qt::transparent);

    DrawPixmap(pixmap, symbol, font, color);
    icon.addPixmap(pixmap, mode, state);
  }
}

//------------------------------------------------------------------------------
/** Создать Pixmap по параметрам
*/
//---
QPixmap IconUtil::Create(const PixmapParams & params)
{
  QPixmap pixmap;

  if (params.GetColorType() == IconColorType::undef)
    return pixmap;

  auto & fontDatabase = FontDatabase::Instance();
  m_baseFont = fontDatabase.GetIconFont(params.GetAppId(), IconFontType::base);
  m_accentFont = fontDatabase.GetIconFont(params.GetAppId(), IconFontType::accent);
  m_color1Font = fontDatabase.GetIconFont(params.GetAppId(), IconFontType::color1);
  m_color2Font = fontDatabase.GetIconFont(params.GetAppId(), IconFontType::color2);
  m_color3Font = fontDatabase.GetIconFont(params.GetAppId(), IconFontType::color3);

  QChar symbol = params.GetIconSymbol();
  int fontSize = 0;
  QSize iconSize = {};

  PixmapParams::CalcParamType calcParamType = params.GetCalcParamType();

  // Вычислить размер шрифта по размеру иконки
  if (calcParamType == PixmapParams::CalcParamType::font)
  {
    iconSize = params.GetIconSize();
    if (!iconSize.isEmpty())
    {
      fontSize = std::round(CalcFontSize(iconSize));
      const_cast<PixmapParams &>(params).UpdateFontSize(fontSize);
    }
  }
  // Вычислить размер иконки по размеру шрифта
  else if (calcParamType == PixmapParams::CalcParamType::size)
  {
    fontSize = params.GetFontSize();
    if (fontSize > 0)
    {
      if (params.GetIconShape() == PixmapParams::IconShape::square)
        iconSize = CalcIconSize(fontSize);
      else if (params.GetIconShape() == PixmapParams::IconShape::calculated)
        iconSize = CalcIconSize(symbol, fontSize);

      const_cast<PixmapParams &>(params).UpdateIconSize(iconSize);
    }
  }

  if (fontSize > 0 && !iconSize.isEmpty())
  {
    SetFontPixelSize(fontSize);

    QSize pixmapSize;

    if (calcParamType == PixmapParams::CalcParamType::size)
    {
      if (params.GetIconShape() == PixmapParams::IconShape::square)
        pixmapSize = CalcPixmapSize(params.GetFontSize());
      else if (params.GetIconShape() == PixmapParams::IconShape::calculated)
        pixmapSize = CalcPixmapSize(symbol);
    }
    else if (calcParamType == PixmapParams::CalcParamType::font)
    {
      pixmapSize = CalcPixmapSize(iconSize);
    }

    if (!pixmapSize.isEmpty())
    {
      pixmap = QPixmap{pixmapSize};
      pixmap.fill(Qt::transparent);

      if (params.GetBackgroundColor())
        pixmap.fill(*params.GetBackgroundColor());
      else
        pixmap.fill(Qt::transparent);

      IconColorType iconColorType = params.GetColorType();

      // Если нет символа в цветных шрифтах, то отображать монохромным
      if (iconColorType == IconColorType::colorFonts && !IsExistColorFonts(symbol))
        iconColorType = IconColorType::monochome;

      if (iconColorType == IconColorType::colorFonts)
      {
        DrawColorFontPixmap(pixmap, symbol);
      }
      else if (iconColorType == IconColorType::color || iconColorType == IconColorType::monochome)
      {
        DrawPixmap(pixmap, symbol, m_baseFont, params.GetColor());
      }
    }
  }

  // для корректного рисования при devicePixelRatio > 1
  pixmap.setDevicePixelRatio(qApp->primaryScreen()->devicePixelRatio());
  return pixmap;
}


//------------------------------------------------------------------------------
/** Вычислить размер Pixmap для символа
*/
//---
QSize IconUtil::CalcPixmapSize(QChar glyph)
{
  if (m_baseFont)
  {
    QFont qFont(m_baseFont->familyName(), m_baseFont->pixelSize());
    QFontMetrics fontMetrics(qFont);
    QRect rect = fontMetrics.boundingRect(glyph);
    return QSize(rect.width() + rect.x(), rect.height() - rect.y());
  }
  return QSize();
}


//------------------------------------------------------------------------------
/** Вычислить размер Pixmap для размера шрифта
*/
//---
QSize IconUtil::CalcPixmapSize(int fontSize)
{
  if (m_baseFont)
  {
    auto primaryScreenScale = qApp->primaryScreen()->devicePixelRatio();
    auto coefficient = (m_baseFont->ascent() + m_baseFont->descent()) / m_baseFont->pixelSize();
    int size = std::round(fontSize * coefficient * primaryScreenScale);
    return QSize(size, size);
  }
  return QSize();
}


//------------------------------------------------------------------------------
/** Вычислить размер Pixmap для размера иконки
*/
//---
QSize IconUtil::CalcPixmapSize(QSize iconSize)
{
  auto primaryScreenScale = qApp->primaryScreen()->devicePixelRatio();
  int w = std::round(iconSize.width() * primaryScreenScale);
  int h = std::round(iconSize.height() * primaryScreenScale);
  return QSize(w, h);
}


//------------------------------------------------------------------------------
/** Вычислить размер иконки для размера шрифта (для IconShape::square)
*/
//---
QSize IconUtil::CalcIconSize(int fontSize)
{
  auto coefficient = (m_baseFont->ascent() + m_baseFont->descent()) / m_baseFont->pixelSize();
  int size = std::round(fontSize * coefficient);
  return QSize(size, size);
}


//------------------------------------------------------------------------------
/** Вычислить размер области рисования Pixmap для размера шрифта (для IconShape::calculated)
*/
//---
QSize IconUtil::CalcIconSize(QChar glyph, int fontSize)
{
  if (m_baseFont)
  {
    QFont font(m_baseFont->familyName(), fontSize);
    QFontMetrics fontMetrics(font);
    QRect rect = fontMetrics.boundingRect(glyph);
    return QSize(rect.width() + rect.x(), rect.height() - rect.y());
  }
  return QSize();
}


//------------------------------------------------------------------------------
/** Вычислить размер шрифта по размеру иконки
*/
//---
double IconUtil::CalcFontSize(QSize iconSize)
{
  auto coefficient = (m_baseFont->ascent() + m_baseFont->descent()) / m_baseFont->pixelSize();
  int minSize = std::min(iconSize.width(), iconSize.height());
  return minSize / coefficient;
}


//------------------------------------------------------------------------------
/**
  Нарисовать цветную иконку символа с помощью комбинации шрифтов
  \param pixmap QPixmap представление изображения для рисования
  \param glyph символ
*/
//---
void IconUtil::DrawColorFontPixmap(QPixmap & pixmap, QChar glyph)
{
  static auto accentColor = QColor::fromRgb(0xFF930D);
  static auto color1 = QColor::fromRgb(0xA5D3EB);
  static auto color2 = QColor::fromRgb(0x3498D8);
  static auto color3 = QColor::fromRgb(0x2980B9);
  DrawPixmap(pixmap, glyph, m_accentFont, &accentColor);
  DrawPixmap(pixmap, glyph, m_color1Font, &color1);
  DrawPixmap(pixmap, glyph, m_color2Font, &color2);
  DrawPixmap(pixmap, glyph, m_color3Font, &color3);
}


//------------------------------------------------------------------------------
/**
  Нарисовать иконку символа из шрифта
  \param pixmap QPixmap представление изображения для рисования
  \param font шрифт
  \param offset смещение иконки
  \param color цвет иконки
  \return Иконка QIcon
*/
//---
void IconUtil::DrawPixmap(QPixmap & pixmap, QChar glyph, const QRawFont * font, const QColor * color)
{
  if (!font || !color)
    return;

  auto const glyphIndices = font->glyphIndexesForString(glyph);
  if (glyphIndices.size() != 1)
    return;

  QFont qfont(font->familyName(), font->pixelSize());
  QFontMetrics fontMetrics(qfont);
  QRect rect = fontMetrics.boundingRect(glyph);

  auto baseline = font->ascent();

  QGlyphRun glyphRun;
  glyphRun.setRawFont(*font);
  glyphRun.setGlyphIndexes(glyphIndices);
  glyphRun.setPositions({QPointF{}});

  QPainter painter{&pixmap};
  painter.setRenderHint(QPainter::RenderHint::Antialiasing);
  painter.setPen(*color);
  painter.setBrush(*color);
  painter.drawGlyphRun({0, baseline}, glyphRun);
#ifdef Q_OS_WIN
  // add more contrast
  painter.drawGlyphRun({0, baseline}, glyphRun);
#endif // Q_OS_WIN
}

//------------------------------------------------------------------------------
/** Установить PixelSize шрифтам
*/
//---
void IconUtil::SetFontPixelSize(double size)
{
  auto primaryScreenScale = qApp->primaryScreen()->devicePixelRatio();
  size *= primaryScreenScale;

  if (m_baseFont)
    m_baseFont->setPixelSize(size);
  if (m_accentFont)
    m_accentFont->setPixelSize(size);
  if (m_color1Font)
    m_color1Font->setPixelSize(size);
  if (m_color2Font)
    m_color2Font->setPixelSize(size);
  if (m_color3Font)
    m_color3Font->setPixelSize(size);
}

//------------------------------------------------------------------------------
/** Проверяет, есть ли символ в цветных шрифтах
*/
//---
bool IconUtil::IsExistColorFonts(QChar glyph)
{
  return IsExistSymbol(m_accentFont, glyph) || IsExistSymbol(m_color1Font, glyph) || IsExistSymbol(m_color2Font, glyph) ||
         IsExistSymbol(m_color3Font, glyph);
}

//------------------------------------------------------------------------------
/**
  Проверяет, есть ли символ в шрифте
  \param font Шрифт
  \param glyph символ шрифта
  \return true, если символ найден в шрифте
*/
//---
bool IconUtil::IsExistSymbol(const QRawFont * font, QChar glyph)
{
  if (!font || !font->isValid())
    return false;

  auto const glyphIndices = font->glyphIndexesForString(glyph);
  if (glyphIndices.size() == 1)
  {
    auto bound = font->boundingRect(glyphIndices[0]);
    if (bound.width() > 1 && bound.height() > 1)
      return true;
  }

  return false;
}

