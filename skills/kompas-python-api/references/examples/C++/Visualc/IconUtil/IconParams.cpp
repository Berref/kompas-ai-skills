#include "IconParams.h"



namespace
{
const QSize c_defaultIconSize = QSize(19, 19);
// LightTheme Colors
const QColor c_color1 = QColor(51, 51, 51);
const QColor c_color_Disable = QColor(204, 204, 204);
const QColor c_color_MenuItem_Icon_Uncheck = QColor(0xFF4C4C4C);
const QColor c_color_MenuItem_Icon_Uncheck_Hover = QColor(0xFF333333);
const QColor c_color_MenuItem_Icon_Check = QColor(0xFFFFFFFF);
const QColor c_color_MenuItem_Icon_Check_Hover = QColor(0xFFFFFFFF);
const QColor c_color_ToolButton_Icon_Uncheck = QColor(0xFF333333);
const QColor c_color_ToolButton_Icon_Uncheck_Hover = QColor(0xFF333333);
const QColor c_color_ToolButton_Icon_Check = QColor(0xFFFFFFFF);
const QColor c_color_ToolButton_Icon_Check_Hover = QColor(0xFFFFFFFF);
} // namespace


//------------------------------------------------------------------------------
/** Конструктор
*/
//---
IconParams::IconParams()
{
  m_colorType = IconColorType::monochome;
  //m_appId = "Идентификатор приложения";
  m_iconSize = c_defaultIconSize;
  m_uncheckColor = &c_color1;
  m_uncheckHoverColor = &c_color1;
  m_checkColor = &c_color1;
  m_checkHoverColor = &c_color1;
}

//------------------------------------------------------------------------------
/** Проинициалировать монохромные цвета для MenuItem
*/
//---
void IconParams::InitMonochomeMenuItem()
{
  m_colorType = IconColorType::monochome;
  m_uncheckColor = &c_color_MenuItem_Icon_Uncheck;
  m_uncheckHoverColor = &c_color_MenuItem_Icon_Uncheck_Hover;
  m_checkColor = &c_color_MenuItem_Icon_Check;
  m_checkHoverColor = &c_color_MenuItem_Icon_Check_Hover;
}

//------------------------------------------------------------------------------
/** Проинициалировать монохромные цвета для ToolButton
*/
//---
void IconParams::InitMonochomeToolButton()
{
  m_colorType = IconColorType::monochome;
  m_uncheckColor = &c_color_ToolButton_Icon_Uncheck;
  m_uncheckHoverColor = &c_color_ToolButton_Icon_Uncheck_Hover;
  m_checkColor = &c_color_ToolButton_Icon_Check;
  m_checkHoverColor = &c_color_ToolButton_Icon_Check_Hover;
}


//------------------------------------------------------------------------------
/** Проинициалировать цвета для ToolButton
*/
//---
void IconParams::InitColorToolButton()
{
  m_colorType = IconColorType::colorFonts;
  m_uncheckColor = &c_color_ToolButton_Icon_Uncheck;
  m_uncheckHoverColor = &c_color_ToolButton_Icon_Uncheck_Hover;
  m_checkColor = &c_color_ToolButton_Icon_Check;
  m_checkHoverColor = &c_color_ToolButton_Icon_Check_Hover;
}

//------------------------------------------------------------------------------
/** Получить цвет недоступного состояния
*/
//---
const QColor * IconParams::GetDisableColor() const
{
  return &c_color_Disable;
}

//------------------------------------------------------------------------------
/** Проинициализировать определенным цветом для всех состояний
*/
//---
void IconParams::InitColor(const QColor * color)
{
  m_colorType = IconColorType::color;
  m_uncheckColor = color;
  m_uncheckHoverColor = color;
  m_checkColor = color;
  m_checkHoverColor = color;
}


//------------------------------------------------------------------------------
/** Конструктор
*/
//---
PixmapParams::PixmapParams()
{
  m_colorType = IconColorType::monochome;
  //m_appId = "Идентификатор приложения";
  m_color = &c_color1;
  SetIconSize(c_defaultIconSize);
}


//------------------------------------------------------------------------------
/** Установить размер шрифта (размер иконки будет вычисляться при рисовании)
*/
//---
void PixmapParams::SetFontSize(int size, IconShape shape)
{
  m_fontSize = size;
  m_iconSize = QSize();
  m_calcParamType = CalcParamType::size;
  m_shape = shape;
}


//------------------------------------------------------------------------------
/** Установить размер иконки (размер шрифта будет вычисляться при рисовании)
*/
//---
void PixmapParams::SetIconSize(QSize size)
{
  m_iconSize = size;
  m_fontSize = 0;
  m_calcParamType = CalcParamType::font;
  m_shape = IconShape::square;
}
