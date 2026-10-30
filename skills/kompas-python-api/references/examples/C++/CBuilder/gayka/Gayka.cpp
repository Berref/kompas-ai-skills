////////////////////////////////////////////////////////////////////////////////
//
// gayka.cpp - Конструкторский элемент на Borland C - гайка
//
////////////////////////////////////////////////////////////////////////////////
#ifndef __DHEAD_H
#include  "dhead.h"
#endif

#pragma hdrstop

#ifndef __GAYKA_RH
#include "gayka.rh"
#endif

#ifndef __LIBHPPAR_H
#include "libhppar.h"
#endif

#ifndef __BASE_H
#include "base.h"
#endif

#ifndef GDlgH
#include "gdlg.h"
#endif

extern HINSTANCE _hinst;


//-------------------------------------------------------------------------------
// Отрисовка геометрии гайки ( вид )
// ---
void gayka_k( float ls, float l, float d1, float s, float D, float l1, float H, short j, int j1, float d2, int j2 )
{
  float x[9], y[9];
  float c, h1, rb;
  float xc2, yc2, xcbl, ycbl, xcbp, ycbp, ycml;
  // Координаты контура рез_части
  // j1=1 - контровочное отверстие, j1=0 - контровочного отверстия нет
  // j2=1 - исполнение 1, j2=2 - исполнение 2

  D  = (float)( s / CosD( 30 ) );
  c  = (float)( ( D - d2 ) / 2 * TanD( 30 ) );
  h1 = (float)( D * 0.5 * SinD( 30 ) );

  rb = ( h1 * h1 + c * c ) / 2 / c;

  x[1] = ls; y[1] = 0;
  if ( j2 == 1 )
  {
    x[2] = ls;       y[2] = (float)( j * ( d2 * 0.5 ) );
    x[3] = (ls + c); y[3] = (float)( j * ( D * 0.5 ) );
    x[7] = ls + c;   y[7] = j * h1;
  }
  else 
  {
    x[2] = ls; y[2] = (float)( j * ( D * 0.5 ) );
    x[7] = ls; y[7] = j * h1;
  }
  x[4] = ls + H - c; y[4] = (float)( j * ( D * 0.5 ) );
  x[5] = ls + H;     y[5] = (float)( j * ( d2 * 0.5 ) );
  x[6] = ls + H;     y[6] = 0;

  x[8] = ls + H - c; y[8] = j * h1;
  xc2  = ls + l;     yc2 = (float)( j * ( D * 0.5 - l1 ) );

  xcbl = ls + rb; ycbl = 0;
  xcbp = ls + H - rb; ycbp = 0;
  ycml = (float)( j * ( (D *0.5 - h1) / 2 + h1 ) );

  if ( j2 == 1) 
  {
	LineSeg( x[1], y[1], x[2], y[2], 1 );
	LineSeg( x[2], y[2], x[3], y[3], 1 );
	LineSeg( x[3], y[3], x[4], y[4], 1 );
	LineSeg( x[4], y[4], x[5], y[5], 1 );
	LineSeg( x[5], y[5], x[6], y[6], 1 );
	LineSeg( x[7], y[7], x[8], y[8], 1 );
	ArcByPoint( xcbl, ycbl, rb, x[1], y[1], x[7], y[7],(short) -j, 1 );
	ArcByPoint( xcbp, ycbp, rb, x[6], y[6], x[8], y[8], j, 1 );
	ArcBy3Points( ls + c * 0.5, (D * 0.5 - (D - d2) / 4) * j,
                  ls, ycml, x[7], y[7], 1 );
    ArcBy3Points( ls + H - c * 0.5, (D * 0.5 - (D - d2) / 4) * j, ls + H,
                  ycml, x[8], y[8], 1 );
  }
  else 
  {
	LineSeg( x[1], y[1], x[2], y[2], 1 );
	LineSeg( x[2], y[2], x[4], y[4], 1 );
	LineSeg( x[4], y[4], x[5], y[5], 1 );
	LineSeg( x[5], y[5], x[6], y[6], 1 );
	LineSeg( x[7], y[7], x[8], y[8], 1 );
	ArcByPoint( xcbp, ycbp, rb, x[6], y[6], x[8], y[8], j, 1 );
    ArcBy3Points( ls + H - c * 0.5, (D * 0.5 - (D - d2) / 4) * j,
                  ls + H, ycml, x[8], y[8], 1 );
  }

  if ( j1 == 1) 
  {
	Circle( xc2, yc2, d1 * 0.5, 1 );
	LineSeg( xc2 - 2, yc2, xc2 + 2, yc2, 2 );
	LineSeg( xc2, yc2 - 2, xc2, yc2 + 2, 2 );
  }
} 


//-------------------------------------------------------------------------------
// Отрисовка геометрии гайки ( вид сбоку )
// ---
void gayka_k_side( float ls, float s, float D, float d2, float H, int j, int j2 ) 
{
  float x, y;
  float x2, y2;
  // j2=1 - исполнение 1, j2=2 - упрощенное

  float c = (float)( ( D - d2 ) / 2 * TanD( 30 ) );

  y = (float)( j * s * 0.5 );
  if (j2 == 1)  
  {
    x = ls + c;
	LineSeg( ls, 0, ls, j * d2 * 0.5, 1 );
	LineSeg( ls, j * d2 * 0.5, x, y, 1 );
    ArcBy3Points( ls + c, j * (s * 0.5), ls, s * 0.25 * j, ls + c, 0, 1 );
  }
  else 
  {
    x = ls;
	LineSeg( x, 0, x, y, 1 );
  }

  if ( j2 == 3 ) 
  {
    x2 =ls + H;
    y2 = y;
  }
  else 
  {
    x2 = ls + H - c;
    y2 = (float)( j * d2 * 0.5 );
  }
  LineSeg( x, y, x2, y, 1 );
  if ( j2 != 3 )  
  {
	LineSeg( x2, y, ls + H, y2 , 1 );
    ArcBy3Points( ls + H - c, j * (s * 0.5), ls + H,s * 0.25 * j,
                  ls + H - c, 0, 1 );
  }
  LineSeg( ls + H, y2, ls + H, 0, 1 );
  if ( j > 0 )
	LineSeg( x, 0, x2, 0, 1 );
}


//-------------------------------------------------------------------------------
// Отрисовка геометрии гайки ( вид - упрощенно )
// ---
void gayka_k_y( float ls, GAYKA5915 *tmp, int j ) 
{
  float h1;
  tmp->D = (float)( tmp->s / CosD( 30 ) );

  h1 = (float)( tmp->D * 0.5 * SinD( 30 ) );

  LineSeg( ls, 0, ls, j * (tmp->D * 0.5 ), 1 );
  LineSeg( ls, j * ( tmp->D * 0.5), ls + tmp->h, j * (tmp->D * 0.5), 1 );
  LineSeg( ls + tmp->h, j * (tmp->D * 0.5), ls + tmp->h, 0, 1 );
  LineSeg( ls, j * h1, ls + tmp->h, j * h1, 1 );
} 


//-------------------------------------------------------------------------------
// Отрисовка геометрии гайки ( пол-вида/пол-разреза )
// ---
void Gayka5915::gayka_p_k( int j ) 
{
  float c, dd, c1 = 0, c2 = 0;
  float y, x = 0, x1, x2, x3, y3, y2;

  c = (float)( ( tmp.D - tmp.d2 ) / 2 * TanD( 30 ) );

  if ( !(tmp.f & ISPOLN) && !(tmp.f & SIMPLE) )
    y = (float)( j * tmp.d2 * 0.5 );
  else
    y = (float)( j * tmp.D * 0.5 );

  LineSeg( 0, 0, 0, y, 1 );

  if ( !(tmp.f & ISPOLN) && !(tmp.f & SIMPLE) ) 
  {
    x = c;
	LineSeg( 0, y, x, j * (tmp.D * 0.5), 1 );
  }
  dd = (float)( tmp.dr - 2 * MODSTEP_REAL * tmp.p );

  if ( !(tmp.f & SIMPLE) )
  {
    x3 = tmp.h - c ;
    y3 = (float)( j * tmp.d2 * 0.5 );
    y2 = (float)( j * tmp.da * 0.5 );
  }
  else
  {
    x3 = tmp.h;
    y3 = (float)( j * tmp.D * 0.5 );
    y2 = (float)( j * dd * 0.5 );
  }

  LineSeg( x, j * (tmp.D * 0.5), x3, j * tmp.D * 0.5, 1 );
  if ( !(tmp.f & SIMPLE) )
	LineSeg( x3, j * tmp.D * 0.5, tmp.h, y3, 1 );
  LineSeg( tmp.h, y3, tmp.h, 0, 1 );

  x1 = tmp.h;
  x2 = x1;
  if ( !(tmp.f & SIMPLE) ) 
  {
    c1 = (float)( (tmp.da - dd) * 0.5 );
    c2 = (float)( ( tmp.da - tmp.dr ) * 0.5 );
    if ( !(tmp.f & ISPOLN) )
      x2 = x2 - c2;
  }

  if ( !(tmp.f & ISPOLN) && !(tmp.f & SIMPLE) ) 
  {
    x1 = x1 - c1;
	LineSeg ( tmp.h, j * tmp.da * 0.5, x1, j * 0.5 * dd, 1 );
	LineSeg( x1, j * dd * 0.5, x1, 0, 1 );
  }

  LineSeg( x1, j * 0.5 * dd, c1, j * 0.5 * dd, 1 );

  if ( !(tmp.f & SIMPLE) ) 
  {
	LineSeg( c1, j * 0.5 * dd, 0, j * 0.5 * tmp.da, 1);
	LineSeg( c1, j * dd * 0.5, c1, 0, 1 );
  }

  Hatch( 0, tmp.hatchAng, tmp.hatchShag, 0, 0, 0 );
	  LineSeg( 0, y2, 0, y, 1 );
    if ( !(tmp.f & ISPOLN) && !(tmp.f & SIMPLE) )
	  LineSeg( 0, y, x, j * (tmp.D * 0.5), 1 );
	LineSeg( x, j * (tmp.D * 0.5), x3, j * tmp.D * 0.5, 1 );
    if ( !(tmp.f & SIMPLE) )
	  LineSeg( x3, j * tmp.D * 0.5, tmp.h, y3, 1 );

    if ( !(tmp.f & ISPOLN) && !(tmp.f & SIMPLE) )
	  LineSeg( tmp.h, y3, tmp.h, j * tmp.da * 0.5, 1 );
    else
	  LineSeg( tmp.h, y3, tmp.h, j * dd * 0.5, 1 );


    if ( !(tmp.f & ISPOLN) && !(tmp.f & SIMPLE) )
	  LineSeg( tmp.h, j * tmp.da * 0.5, x1, j * 0.5 * dd, 1 );
	LineSeg( x1, j * 0.5 * dd, c1, j * 0.5 * dd, 1 );
    if ( !(tmp.f & SIMPLE) )
	  LineSeg( c1, j * 0.5 * dd, 0, j * 0.5 * tmp.da, 1 );
  EndObj();
  LineSeg( c2, j * 0.5 * tmp.dr, x2, j * 0.5 * tmp.dr, 2 );
}


//------------------------------------------------------------------------------
// Отрисовка геометрии гайки (Сверху)
// ---
void Gayka5915::gayka_sverhu() 
{
  float D, s;
  float h1, dd;

  s  = (float)( tmp.s * 0.5 );
  D  = (float)( s / CosD( 30 ) );
  dd = (float)( tmp.dr - 2 * MODSTEP_REAL * tmp.p );

  h1 = (float)( D * SinD( 30 ) );

  LineSeg( -s, h1, 0, D, 1 );
  LineSeg( 0, D, s, h1, 1 );
  LineSeg( s, h1, s, -h1, 1 );
  LineSeg( s, -h1, 0, -D, 1 );
  LineSeg( 0, -D, -s, -h1, 1 );
  LineSeg( -s, -h1, -s, h1, 1 );

  if( !(tmp.f & SIMPLE) )
	Circle( 0, 0, tmp.d2 * 0.5, 1 );
  Circle( 0, 0, dd * 0.5, 1 );
  ArcByPoint( 0, 0, tmp.dr * 0.5, tmp.dr * 0.5 * SinD(15),
	   tmp.dr * 0.5 * CosD(15), tmp.dr * 0.5 * CosD(15),
	   -tmp.dr * 0.5 * SinD(15), 1, 2 );

  if ( !(tmp.f & AXIS_OFF ) )
  {
    if ( D >= 6 )  
    {
	  LineSeg( -3 - s, 0, s + 3, 0, 3 );
	  LineSeg( 0, -3 - D, 0, 3 + D, 3 );
    }
    else  
    {
	  LineSeg( -1 - s, 0, s + 1, 0, 3 );
      LineSeg( 0, -1 - D, 0, 1 + D, 3 );
    }
  }
}


//------------------------------------------------------------------------------
// Геометрия гайки
// ---
void Gayka5915::GetGroup( reference &gr ) 
{
  int k2;
  if ( !(tmp.f & ISPOLN) )
    k2=1;
  else
    k2=2;

  if ( gr )
    DeleteObj( gr );
  gr = NewGroup( 1 );
  Macro( 0 );
  switch (par.drawType)
  {
    case ID_VID : // Вид
      if ( !(tmp.f & SIMPLE) ) 
      {
       gayka_k( 0, 0, 0, tmp.s, tmp.D, 0, tmp.h, 1, 0, tmp.d2, k2 );
       gayka_k( 0, 0, 0, tmp.s, tmp.D, 0, tmp.h, -1, 0, tmp.d2, k2 );
      }
      else 
      {
       gayka_k_y( 0,&tmp,  1 );
       gayka_k_y( 0,&tmp, -1 );
      }
      if ( !(tmp.f & AXIS_OFF ) )
		LineSeg( -3, 0, tmp.h + 3, 0, 3 );
    break;
    case ID_SIDEVID : // Вид сбоку
	  if ( !(tmp.f & AXIS_OFF ) )
		LineSeg( -3, 0, tmp.h + 3, 0, 3 );
      if ( tmp.f & SIMPLE )
        k2 = 3;
      gayka_k_side( 0, tmp.s, tmp.D, tmp.d2, tmp.h, 1, k2 );
      gayka_k_side( 0, tmp.s, tmp.D, tmp.d2, tmp.h, -1, k2 );
    break;
    case ID_TOPVID    : // Вид сверху
    case ID_BOTTOMVID : // Вид снизу
      gayka_sverhu( );
    break;
    case ID_VIDSEC: // Пол-вида/пол-разреза
      if( !(tmp.f & SIMPLE) ) 
      {
        gayka_k( 0, 0, 0, tmp.s, tmp.D, 0, tmp.h, 1, 0, tmp.d2, k2 );
        gayka_p_k( -1 );
      }
      else 
      {
        gayka_k_y( 0, &tmp, 1 );
        gayka_p_k( -1 );
      }
      if ( !( tmp.f & AXIS_OFF ) )
		LineSeg( -3, 0, tmp.h + 3, 0, 3 );
    break;
  }

  *refMacr =EndObj();
  EndGroup();
}


//------------------------------------------------------------------------------
// Инициализация флагов
// ---
void InitGaykaFlag ( unsigned short gost, unsigned short &f1 ) 
{
  switch ( gost ) 
  {
    case 5915 :
      f1 |= KEY_S_ON;
      f1 |= KOEFF_MAT_ON;
      break;
  }
}


//------------------------------------------------------------------------------
//
// ---
Gayka5915::Gayka5915( unsigned short gost_ )  
{
  if( !::_GetMacroParam( *this, Size()) ) 
  {
    tmp.gost = gost_;
    par.angle     = 0;
    par.drawType  = ID_VID;
    tmp.hatchAng  = 45;
    tmp.hatchShag = 2;
    tmp.f = 0; tmp.dr=20;  tmp.p=2.5;
    tmp.f1=0;
    tmp.ver = 1;
    tmp.indexMassa =0;
    switch (gost_) 
    {
      case 5915 :
        tmp.s=30; tmp.D=33;  tmp.da=21.6;  tmp.h=16;
        tmp.d2=27.7;  tmp.klass=2;   // Класс точности
        tmp.f|=TAKEISPOLN;
        tmp.f1 |= KEY_S_ON;
        tmp.f1 |= KOEFF_MAT_ON;
        tmp.massa = 71.44;
        break;
    }
  }
  else 
  {
    if ( !tmp.ver ) 
    {
      tmp.ver = 1;
      InitGaykaFlag ( gost_, tmp.f1 );
    }
  }
}


//------------------------------------------------------------------------------
//
// ---
Gayka5915::Gayka5915(const Gayka5915 &other )
{
  ::memset( &base, 0, sizeof(SimpleBase) );
  Assign(other);
}


//-------------------------------------------------------------------------------
// Оператор присваивания
// ---
void  Gayka5915::Assign ( const Gayka5915 &other )
{
  CPar::Assign( other );
  memcpy( &tmp, &other.tmp, sizeof( GAYKA5915 ) );
}


//------------------------------------------------------------------------------
// Редактирование объекта спецификации
// ---
reference Gayka5915::StaticEditSpcObj( bool flagMode, GAYKA5915 &tmp,
                                       reference *spcObj, reference geom, uint16 flagAttr ) 
{
 if ( !flagMode && !flagAttr  )
    return 0;

  if( flagMode ) 
  {
    *spcObj = ksGetSpcObjForGeomWithLimit( NULL,             // Имя библиотеки типов
                                           0,                // Номер типа спецификации
                                           geom,
                                           0,                // 1 - присланная геометрия идентична геометрии объекта СП, 0 - входит в объект СП
                                           1,                // 1 - первый объект, 0- следующий объект
                                           STANDART_SECTION, // Номер раздела
                                           297327484710.0 );
    if( !flagAttr )
      return *spcObj; 

    if ( *spcObj && !::ksSpcObjectEdit( *spcObj ) )
      *spcObj  = 0;
  }

  flagMode  = *spcObj; 
  // Создаем объект спецификации для умолчательногостиля СП
  if( flagMode || ksSpcObjectCreate( NULL ,               // Имя библиотеки типов
                                     0,                   // Номер типа спецификации
                                     STANDART_SECTION, 0, // Номер раздела и подраздела
                                     297327484710.0,0 ) ) // Тип атрибута
  {
    uint uBuf;
    // Исполнение
    if( !(tmp.f & ISPOLN) )
      ::ksSpcVisible( SPC_NAME, 2, 0 );
    else 
    {
      uBuf = (uint) 2;
      ::ksSpcVisible( SPC_NAME, 2, 1 );
      ::ksSpcChangeValue( SPC_NAME , 2, &uBuf, UINT_ATTR_TYPE  );
    }

    //Изменим диаметр
    ::ksSpcChangeValue( SPC_NAME , 4, &tmp.dr, FLOAT_ATTR_TYPE  );

    // Отследим мелкий шаг
    if( !(tmp.f &PITCH) ) // Выключить шаг и его разделитель
    {
      ::ksSpcVisible( SPC_NAME, 5, 0 );
      ::ksSpcVisible( SPC_NAME, 6, 0 ); // Шаг
    }
    else 
    {
      ::ksSpcVisible( SPC_NAME, 5, 1 );
      ::ksSpcVisible( SPC_NAME, 6, 1 ); // Шаг
     ::ksSpcChangeValue( SPC_NAME , 6, &tmp.p, FLOAT_ATTR_TYPE );
    }

    // Выключим поле допуска
    if( !flagMode  )
      ::ksSpcVisible( SPC_NAME, 7, 0 );

    // Выключим класс прочности
    if( !flagMode  )
      ::ksSpcVisible( SPC_NAME, 8, 0 );

   // Выключим материал
   if( !flagMode  )
     ::ksSpcVisible( SPC_NAME, 9, 0 );

   // Выключим покрытие
   if( !flagMode  )
     ::ksSpcVisible( SPC_NAME, 10, 0 );

   // Изменим ГОСТ
   uBuf = (uint) tmp.gost;
   ::ksSpcChangeValue( SPC_NAME , 12, &uBuf, UINT_ATTR_TYPE  );

   float  massa = tmp.massa*( !tmp.indexMassa ? 1 : tmp.indexMassa==1 ? 0.356 : 1.08 )/COUNT_MASSA;
   char buf[128];
   sprintf( buf, "%f" , massa );
   ksSpcMassa ( buf ); // Масса детали

   // Подключим геометрию
   if ( geom )
     ::ksSpcIncludeReference( geom, SPC_CLEAR_GEOM  );

   return ::ksSpcObjectEnd( );
 }
 return 0;
}


//------------------------------------------------------------------------------
// Редактирование объекта спецификации
// ---
reference  Gayka5915::EditSpcObj( reference *spcObj, reference geom )
{
  return  Gayka5915::StaticEditSpcObj ( flagMode, tmp,  spcObj, geom, par.flagAttr );
}


//------------------------------------------------------------------------------
// Выбор меню
// ---
int Gayka5915::ChoiceMenuId() 
{
  if ( !par.typeSwitch )
    return par.drawType == ID_VID ?  MENU_G5915_1 : par.drawType == ID_TOPVID  ? MENU_G5915_2 :
           par.drawType == ID_SIDEVID ? MENU_G5915_4 : MENU_G5915_3;
  else
    return par.drawType == ID_VID ?  MENU_G5915_5 : par.drawType == ID_TOPVID  ? MENU_G5915_6 :
           par.drawType == ID_SIDEVID ? MENU_G5915_8 : MENU_G5915_7;
}


//------------------------------------------------------------------------------
// Изменение угла штриховки
// ---
void Gayka5915::SetHatchAngl()
{
  tmp.hatchAng = ::SetHatchAngl( tmp.hatchAng );
}


//------------------------------------------------------------------------------
// Изменение шага штриховки
// ---
void Gayka5915::SetHatchShag()
{
  tmp.hatchShag = ::SetHatchShag( tmp.hatchShag );
}


//------------------------------------------------------------------------------
// Установка параметров
// ---
void Gayka5915::SetParam() 
{
  ::ksSetMacroParam( *refMacr, *this, Size(),0,0,-1, MP_HOTPOINTS );
}


// HOT_POINTS ##################################################################

//------------------------------------------------------------------------------
// Работа с Hot точками
// ---
BOOL Gayka5915::GetHotPoints( HotPointDescription* point, int index ) 
{
  bool rez = false;
	switch ( index ) 
  {
  	case 0 :   // Точка привязки
    {
      point->x = 0;
      point->y = 0;
      point->text = "0";
      rez = true;
      break;
    }
    case 1 :  // Изменение диаметра
    {
      point->x = 0;
      point->y = tmp.dr / 2.0;
      point->cursorInst = _hinst;
      point->cursorId   = CURSOR_DIAMETER;
      point->text       = "Dr";
      rez = true;
      break;
    }
    case 2 : // Угол поворота
    {
      static char textForHP_2[255]; // Обязательно должен быть описан как static
      ::sprintf( textForHP_2, "A = %.2f", ::fmod(par.angle, 360.0) );

      point->x = par.drawType == ID_TOPVID ? (tmp.s / 2.0) : tmp.h;
      point->y = 0;
      point->cursorInst = _hinst;
      point->cursorId   = CURSOR_ROTATE;
      point->text       = textForHP_2;
      rez = true;
      break;
    }
  }
  return rez;
}


//------------------------------------------------------------------------------
// Работа с Hot точками
// ---
BOOL Gayka5915::GetCursorText( int index, char** text ) 
{
  static char cursorText[255]; // Обязательно должен быть описан как static
  switch ( index ) 
  {
    case 2 :
			::sprintf( cursorText, "A = %.2f", ::fmod(par.angle, 360.0) );
      *text = cursorText;
      return true;
    case 1 :
			::sprintf( cursorText, "D = %.2f\nH = %.2f", tmp.dr, tmp.h );
      *text = cursorText;
      return true;
  }
  return false;
}


//------------------------------------------------------------------------------
// Работа с Hot точками
// ---
BOOL Gayka5915::ChangeHotPointParam( double d ) 
{
  struct {  char s[20];  float dr; } tmpL;

  // Подобрать ближайший dR по d
  double dR = 0.0;
  double oldDR = tmp.dr;

  SimpleBase base;
  OpenGaykaBase();

  while( true ) 
  {
    if ( ::ReadRecord(  base.bg, base.rg1, &tmpL ) ) 
    {
      if ( dR <= d )
        dR = tmpL.dr;
      else
        break;
    }
    else
      break;
  }

  bool retVal = false;
  if ( ::fabs( dR - oldDR ) > 0.01 )
    retVal = ReadGaykaBase( dR );

  CloseGaykaBase();

  return retVal;
}


//------------------------------------------------------------------------------
// Работа с Hot точками
// ---  
int Gayka5915::SetHotPoint( HotPointDescription* point, int index ) 
{
  double x;
  double y;
  double alpha;
  if ( ::GetMacroPlacement( 0, &x, &y, &alpha ) ) 
  {                  
    reference gr=0;
    switch ( index ) 
    {
      case 0 :
        *refMacr = 0;
        SetParam();
        ::SetMacroPlacement( *refMacr, point->x, point->y, 0.0, 1 );
        break;
      case 1 :
        if ( ChangeHotPointParam( ::fabs(point->y * 2) ) ) 
        {
          GetGroup( gr );
        	SetParam();
        	::SetMacroPlacement( *refMacr, 0., 0., 0., 1 );
          ::StoreTmpGroup( gr );
          ClearGroup( gr );
        }
        break;
      case 2 : 
      {
        *refMacr = 0;
        double ang;
        if ( point->y == 0 )
          ang = 0.0;
        else if ( point->x == 0 )
          ang = 90.0;
        else
          ang = AtanD( point->y/point->x  );

        par.angle += ang;
        SetParam();
        ::SetMacroPlacement( *refMacr, 0., 0., ang, 1 );
      }
      break;
    } 
  }
  return TRUE;
}


//------------------------------------------------------------------------------
// Работа с Hot точками
// ---
int Gayka5915::GetMenu()
{
  HMENU menu = ::LoadMenu( _hinst, MAKEINTRESOURCE( GAIKA_POPUPMENU ) );
  ::CheckMenuItem( menu, par.drawType, MF_BYCOMMAND | MF_CHECKED );
  if ( par.drawType != ID_VIDSEC ) 
  {
  	::EnableMenuItem( menu, ID_HATCH_ANG,  MF_BYCOMMAND | MF_GRAYED );
  	::EnableMenuItem( menu, ID_HATCH_SHAG, MF_BYCOMMAND | MF_GRAYED );
  }
  return int(menu);
}

// HOT_POINTS ##################################################################


//-------------------------------------------------------------------------------
// Выбор слайда
// ---
int Gayka5915::ChoiceBMP()
{
  switch ( par.drawType )
  {
    case ID_VID :
      if ( tmp.f & SIMPLE )
        return G5915_5;
      if ( tmp.f & ISPOLN )
        return G5915_9;

      return G5915_1;
    case ID_SIDEVID :
      if ( tmp.f & SIMPLE )
        return G5915_6;
      if ( tmp.f & ISPOLN )
        return G5915_10;

      return G5915_2;

    case ID_TOPVID :
    case ID_BOTTOMVID :
      if ( tmp.f & SIMPLE )
        return G5915_7;
      else
        return G5915_3;

    case ID_VIDSEC :
      if ( tmp.f & SIMPLE )
        return G5915_8;
      if ( tmp.f & ISPOLN )
        return G5915_11;

      return G5915_4;
  }
  return 0;
}


//------------------------------------------------------------------------------
// Название по ГОСТу
// ---
static int NumberStr( int gost ) 
{
  int n = 0;
  switch (gost) 
  {
    case 5915 :
      n = STR11;
      break;
  }
  return n;
}


//-------------------------------------------------------------------------------
// Параметры макро объекта
// ---
int  Gayka5915::MacroElementParam()
{
  Gayka5915 buf( *this );
  TGaykaDlg * dlg  = new TGaykaDlg( Application, buf );
  int rez = dlg->ShowModal();
  if ( rez == mrOk )
  {
    Assign(buf);
  }
  delete dlg;
  return rez;
}


//-------------------------------------------------------------------------------
// Открыть базу данных  
// ---
bool Gayka5915::OpenGaykaBase()
{
  base.bg = CreateDB("TXT_DB");

  if( !_ConnectDB(base.bg, "5915.loa") )
    return 0;
  else
  {
    base.rg1 = Relation( base.bg );
      RChar( "", 20,0 );
      RFloat("dr");
    EndRelation();
    if ( !DoStatement(base.bg, base.rg1, "1 1" ) )
      return 0;
    else
    {
      base.rg2 = Relation( base.bg );
        RFloat("dr");
        RFloat("");
        RFloat("");
        RFloat("");
        RFloat("");
        RFloat("");
        RFloat("");
        RFloat("");
        RFloat("");
        RFloat("");
        RFloat("");
        RFloat("");
      EndRelation();
      if ( !DoStatement( base.bg, base.rg2, "") ) 
        return 0;
      else
        return 1;
    }
  }
}


//-------------------------------------------------------------------------------
// Читать параметры гайки по диаметру
// возвращает 1 - успех 0 - не найдено записи , ошибка связи с БД
// ---
bool Gayka5915::ReadGaykaBase( float d )
{
  char s[128];
  GaykaTMP gTmp;
  sprintf( s, "dr=%.1f", d );
  if ( !Condition(base.bg, base.rg2, s) ) { return 0;}
  int i = ReadRecord( base.bg, base.rg2, &gTmp );
  if ( i ) 
  {
    tmp.dr = gTmp.dr;
    tmp.da = gTmp.da;
    tmp.h  = gTmp.h;
    tmp.d2 = gTmp.d2;

    if ( tmp.f & PITCH )
      tmp.p = gTmp.p2;
    else
      tmp.p = gTmp.p1;

    if (fabs( gTmp.p2 - gTmp.p1 ) < 0.001 )
      tmp.f |= PITCHOFF;
    else
      tmp.f &=~PITCHOFF;
    if( tmp.f1 & KEY_S_ON && fabs(gTmp.s1)> 0.001 )
      tmp.f1 |= KEY_S_GRAY;
    else 
    {
      tmp.f1 &=~ KEY_S_GRAY;
      tmp.f1 &=~ KEY_S;
    }
    if ( tmp.f1 & KEY_S_ON && tmp.f1 & KEY_S )
    {
      tmp.s  = gTmp.s1; // Размер под ключ
      tmp.D  = gTmp.D1; // Диаметр описанной окружности
      tmp.massa  = gTmp.m1;
    }
    else 
    {
      tmp.s  = gTmp.s; // Размер под ключ
      tmp.D  = gTmp.D; // Диаметр описанной окружности
      tmp.massa  = gTmp.m;
    }  
    return 1;
  }
  return 0;
}


//-------------------------------------------------------------------------------
// Закрыть базу данных
// ---
void Gayka5915::CloseGaykaBase()
{
  DeleteDB( base.bg );
}



