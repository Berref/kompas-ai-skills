////////////////////////////////////////////////////////////////////////////////
//
// gayka.cpp - Конструкторский элемент на Visual C++ - гайка
//
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "Gayka.h"
#include "math.h"
#include <Libhppar.h>
#include <SafeArrayUtils.h>
#include "CPar.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

bool messCommand = false;
bool messPrepare = false;
bool messSelect = false;
bool commandChange = false;

extern ksAPI7::IApplicationPtr newKompasAPI; // Интерфейс Приложения Компас

//-------------------------------------------------------------------------------
// Отрисовка геометрии гайки ( вид )
// ---
void Gayka_K( float ls, float l, float d1, float s, 
              float l1, float H, short j,  int j1, float d2, int j2, bool apl ) 
{
  double x[9], y[9];
  double c, h1, rb;
  double xc2, yc2, xcbl, ycbl, xcbp, ycbp, ycml;
  // Координаты контура рез_части
  // j1=1 - контровочное отверстие, j1=0 - контровочного отверстия нет
  // j2=1 - исполнение 1, j2=2 - исполнение 2

  double D  = s / CosD( 30 );
  double D2 = D  * 0.5;
  double d22 = d2 * 0.5;
  
  c  = ( D2 - d22 ) * TanD( 30 );
  h1 = D2 * SinD( 30 );

  rb = ( h1 * h1 + c * c ) * 0.5 / c;

  x[1] = ls; y[1] = 0;
  if ( j2 == 1 )
  {
    x[2] = ls;         y[2] = j * d22;
    x[3] = ( ls + c ); y[3] = j * D2;
    x[7] = ls + c;     y[7] = j * h1;
  }
  else
  {
    x[2] = ls; y[2] = j * D2;
    x[7] = ls; y[7] = j * h1;
  }
  x[4] = ls + H - c; y[4] = j * D2;
  x[5] = ls + H;     y[5] = j * d22;
  x[6] = ls + H;     y[6] = 0;

  x[8] = ls + H - c; y[8] = j * h1;
  xc2  = ls + l;     yc2 =  j * ( D2 - l1 );

  xcbl = ls + rb; ycbl = 0;
  xcbp = ls + H - rb; ycbp = 0;
  ycml = j * ( ( D2 - h1 ) * 0.5 + h1 );

  if ( j2 == 1)
  {
    LineSeg( x[1], y[1], x[2], y[2], 1 );
    LineSeg( x[2], y[2], x[3], y[3], 1 );
    LineSeg( x[3], y[3], x[4], y[4], 1 );
    LineSeg( x[4], y[4], x[5], y[5], 1 );
    LineSeg( x[5], y[5], x[6], y[6], 1 );
    if ( !apl )
    {
      LineSeg( x[7], y[7], x[8], y[8], 1 );
      ArcByPoint( xcbl, ycbl, rb, x[1], y[1], x[7], y[7],(short) -j, 1 );
      ArcByPoint( xcbp, ycbp, rb, x[6], y[6], x[8], y[8], j, 1 );
      ArcBy3Points( ls + c * 0.5,     (D2 - (D2 - d22) * 0.5) * j, ls + H * 0.01, ycml, x[7], y[7], 1 );
      ArcBy3Points( ls + H - c * 0.5, (D2 - (D2 - d22) * 0.5) * j, ls + H * 0.99, ycml, x[8], y[8], 1 );
    }
  }
  else
  {
    LineSeg( x[1], y[1], x[2], y[2], 1 );
    LineSeg( x[2], y[2], x[4], y[4], 1 );
    LineSeg( x[4], y[4], x[5], y[5], 1 );
    LineSeg( x[5], y[5], x[6], y[6], 1 );
    if ( !apl ) 
    {
      LineSeg( x[7], y[7], x[8], y[8], 1 );
      ArcByPoint( xcbp, ycbp, rb, x[6], y[6], x[8], y[8], j, 1 );
      ArcBy3Points( ls + H - c * 0.5, (D2 - (D2 - d22) * 0.5) * j, ls + H * 0.99, ycml, x[8], y[8], 1 );
    }
  }

  if ( !apl && ( j1 == 1 ) ) 
  {
    Circle(  xc2, yc2, d1 * 0.5, 1 );
    LineSeg( xc2  - 2, yc2, xc2 + 2, yc2, 2 );
    LineSeg( xc2, yc2 - 2, xc2, yc2 + 2, 2 );
  }
}


//-------------------------------------------------------------------------------
// Отрисовка геометрии гайки ( вид сбоку )
// ---
void Gayka_K_Side( float ls, float s, float D, float d2, float H, int j, int j2, bool appl ) 
{
  float x, y;
  float x2, y2;
  // j2=1 - исполнение 1, j2=2 - упрощенное

  float c = (float)( ( D - d2 ) / 2 * TanD( 30 ) );

  y = (float)( j * s * 0.5 );
  if ( j2 == 1 )  
  {
    x = ls + c;
    LineSeg( ls, 0, ls, j * d2 * 0.5, 1 );
    LineSeg( ls, j * d2 * 0.5, x, y, 1 );
    if ( !appl )
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
    if ( !appl )
      ArcBy3Points( ls + H - c, j * (s * 0.5), ls + H,s * 0.25 * j,
                    ls + H - c, 0, 1 );
  }
  LineSeg( ls + H, y2, ls + H, 0, 1 );
  if ( !appl && j > 0 )
    LineSeg( x, 0, x2, 0, 1 );
}


//-------------------------------------------------------------------------------
// Отрисовка геометрии гайки ( вид - упрощенно )
// ---
void Gayka_K_Y( float ls, GAYKA5915 *tmp, int j, bool appl ) 
{
  float h1;
  tmp->D = (float)( tmp->s / CosD( 30 ) );

  h1 = (float)( tmp->D * 0.5 * SinD( 30 ) );

  LineSeg( ls, 0, ls, j * (tmp->D * 0.5 ), 1 );
  LineSeg( ls, j * ( tmp->D * 0.5), ls + tmp->h, j * (tmp->D * 0.5), 1 );
  LineSeg( ls + tmp->h, j * (tmp->D * 0.5), ls + tmp->h, 0, 1 );
  if ( !appl )
    LineSeg( ls, j * h1, ls + tmp->h, j * h1, 1 );
} 


//-------------------------------------------------------------------------------
// Отрисовка геометрии гайки ( пол-вида/пол-разреза )
// ---
void Gayka5915::Gayka_P_K( int j, bool appl ) 
{
  double  c, dd, c1 = 0, c2 = 0;
  double  y, x = 0, x1, x2, x3, y3, y2;
  double D2 = m_paramGayka.s / CosD( 30 ) * 0.5;
  double d2 = m_paramGayka.d2 * 0.5;
  c = ( D2 - d2) * TanD( 30 );

  if ( !m_paramGayka.flags.isp && !m_baseParam.flags.flagSimp )
    y = j > 0 ? d2 : -d2;
  else
    y = j > 0 ? D2 : -D2;

  LineSeg( 0, 0, 0, y, 1 );

  if ( !m_paramGayka.flags.isp && !m_baseParam.flags.flagSimp ) 
  {
    x = c;
    LineSeg( 0, y, x, j * D2, 1 );
  }
  dd = ( m_paramGayka.dr - 2 * MODSTEP_REAL * m_paramGayka.p );

  if ( !m_baseParam.flags.flagSimp ) 
  {
    x3 = m_paramGayka.h - c ;
    y3 = j * d2;
    y2 = j * m_paramGayka.da * 0.5;
  }
  else 
  {
    x3 = m_paramGayka.h;
    y3 = j * D2;
    y2 = j * dd * 0.5;
  }

  LineSeg( x, j * D2, x3, j * D2, 1 );
  
  if ( !m_baseParam.flags.flagSimp )
    LineSeg( x3, j * D2, m_paramGayka.h, y3, 1 );

  LineSeg( m_paramGayka.h, y3, m_paramGayka.h, 0, 1 );

  x1 = m_paramGayka.h;
  x2 = x1;
  if ( !(m_baseParam.flags.flagSimp) ) 
  {
    c1 = (m_paramGayka.da - dd) * 0.5;
    c2 = ( m_paramGayka.da - m_paramGayka.dr ) * 0.5;
    if ( !m_paramGayka.flags.isp )
      x2 = x2 - c2;
  }

  
  if ( !appl ) 
  {
    if ( !m_paramGayka.flags.isp && !m_baseParam.flags.flagSimp ) 
    {
      x1 = x1 - c1;
      LineSeg ( m_paramGayka.h, j * m_paramGayka.da * 0.5, x1, j * 0.5 * dd, 1 ); //+
      LineSeg( x1, j * dd * 0.5, x1, 0, 1 );
    }

    if ( !m_baseParam.flags.flagSimp ) 
    {
      LineSeg( c1, j * 0.5 * dd, 0, j * 0.5 * m_paramGayka.da, 1); //+
      LineSeg( c1, j * dd * 0.5, c1, 0, 1 );                       //+ 
    }
 
    LineSeg( x1, j * 0.5 * dd, c1, j * 0.5 * dd, 1 ); //+
    
    Hatch( 0, m_paramGayka.hatchAngle, m_paramGayka.hatchStep, 0, 0, 0 );
      LineSeg( 0, y2, 0, y, 1 );

      if ( x != x3 )
        LineSeg( x,  j * D2, x3, j * D2, 1 );
      if ( !(m_baseParam.flags.flagSimp) )
        LineSeg( x3, j * D2, m_paramGayka.h, y3, 1 );

      if ( !m_paramGayka.flags.isp && !m_baseParam.flags.flagSimp )
      {
        LineSeg( 0, y, x, j * D2, 1 );
        LineSeg( m_paramGayka.h, y3, m_paramGayka.h, j * m_paramGayka.da * 0.5, 1 );
        LineSeg( m_paramGayka.h, j * m_paramGayka.da * 0.5, x1, j * 0.5 * dd, 1 );
      }
      else
        LineSeg( m_paramGayka.h, y3, m_paramGayka.h, j * dd * 0.5, 1 );

      LineSeg( x1, j * 0.5 * dd, c1, j * 0.5 * dd, 1 );
      if ( !m_baseParam.flags.flagSimp )
        LineSeg( c1, j * 0.5 * dd, 0, j * 0.5 * m_paramGayka.da, 1 );
    EndObj();

    LineSeg( c2, j * 0.5 * m_paramGayka.dr, x2, j * 0.5 * m_paramGayka.dr, 2 );
  } 
} 


//-------------------------------------------------------------------------------
// Отрисовка геометрии гайки (Сверху)
// ---
void Gayka5915::Gayka_Sverhu( bool appl ) 
{
 
  float D, s;
  float h1, dd;

  s  = (float)( m_paramGayka.s * 0.5 );
  D  = (float)( s / CosD( 30 ) );
  dd = (float)( m_paramGayka.dr - 2 * MODSTEP_REAL * m_paramGayka.p );

  h1 = (float)( D * SinD( 30 ) ); 

  LineSeg( -s, h1, 0, D, 1 );
  LineSeg( 0, D, s, h1, 1 );
  LineSeg( s, h1, s, -h1, 1 );
  LineSeg( s, -h1, 0, -D, 1 );
  LineSeg( 0, -D, -s, -h1, 1 );
  LineSeg( -s, -h1, -s, h1, 1 );

  if( !appl && !(m_baseParam.flags.flagSimp) )
    Circle( 0, 0, m_paramGayka.d2 * 0.5, 1 );
  Circle( 0, 0, dd * 0.5, 1 );
  if ( !appl ) 
  {
    ArcByPoint( 0, 0, m_paramGayka.dr * 0.5, m_paramGayka.dr * 0.5 * SinD(15),
         m_paramGayka.dr * 0.5 * CosD(15), m_paramGayka.dr * 0.5 * CosD(15),
        -m_paramGayka.dr * 0.5 * SinD(15), 1, 2 );
  }
  
  if ( !appl && m_baseParam.flags.flagAxis ) 
  {
    if ( D >= 6 )  
    {
      LineSeg( -AXIS_END - s, 0, s + AXIS_END, 0, AXIS_LINE );
      LineSeg( 0, -AXIS_END - D, 0, AXIS_END + D, AXIS_LINE );
    }
    else  
    {
      LineSeg( -AXIS_END - s, 0, s + AXIS_END, 0, AXIS_LINE );
      LineSeg( 0, -AXIS_END - D, 0, AXIS_END + D, AXIS_LINE );
    }
  }
}


//-------------------------------------------------------------------------------
// Открыть базу данных
// ---
bool Gayka5915::OpenBase() 
{
  return OpenGaykaBase( base );
}


//-------------------------------------------------------------------------------
// Открыть базу данных
// ---
bool OpenGaykaBase( SimpleBase & base ) 
{
  bool res = false;
  base.bg = CreateDBT(_T("TXT_DB"));

  if( _ConnectDB(base.bg, _T("5915.loa")) ) 
  {
    // Первое отношение
    base.rg1 = Relation( base.bg );
      RChar( "", 20, 0 );
      RFloatT(_T("dr"));
    EndRelation(); 
    if ( DoStatementT(base.bg, base.rg1, _T("1 1") ) ) 
    {
      // Второе отношение
      base.rg2 = Relation( base.bg );
        RFloatT(_T("dr"));
        RFloatT(_T(""));
        RFloatT(_T(""));
        RFloatT(_T(""));
        RFloatT(_T(""));
        RFloatT(_T(""));
        RFloatT(_T(""));
        RFloatT(_T(""));
        RFloatT(_T(""));
        RFloatT(_T(""));
        RFloatT(_T(""));
        RFloatT(_T(""));
      EndRelation();
      if ( DoStatementT( base.bg, base.rg2, _T("")) ) 
        res = true;
    }
  }
  return res;
}


//--------------------------------------------------------------------------
// Читать параметры гайки по диаметру
// ---
bool ReadGaykaBase( float d, SimpleBase & base, GAYKA5915 * pGayka )
{
  bool res = false;

  struct { float dr;
           float p1;
           float p2;
           float s;
           float D;
           float da;
           float h;
           float d2;
           float m;
           float s1;
           float D1;
           float m1; } tmpGayka;

  TCHAR s[256];
  _stprintf_s( s, _T("dr=%.1f"), d );
  if ( ConditionT(base.bg, base.rg2, s) )
  {
    bool read = !!ReadRecord( base.bg, base.rg2, &tmpGayka );
    if ( read )
    {
      pGayka->dr = tmpGayka.dr;
      pGayka->da = tmpGayka.da;
      pGayka->h  = tmpGayka.h;
      pGayka->d2 = tmpGayka.d2;

      if ( pGayka->flags.pitch )
        pGayka->p = tmpGayka.p2;
      else
        pGayka->p = tmpGayka.p1;
      
      pGayka->flags.pitch_on = fabs( tmpGayka.p2 - tmpGayka.p1 ) > 0.001;
      pGayka->flags.key_s_on = fabs( tmpGayka.s1 ) > 0.001;
      
      if ( !pGayka->flags.key_s_on )
        pGayka->flags.key_s = false;
     
      if ( pGayka->flags.key_s )
      {
        pGayka->s     = tmpGayka.s1; // Размер под ключ
        pGayka->D     = tmpGayka.D1; // Диаметр описанной окружности
        pGayka->massa = tmpGayka.m1; // Масса
      }
      else 
      {
        pGayka->s     = tmpGayka.s; // Рразмер под ключ
        pGayka->D     = tmpGayka.D; // Диаметр описанной окружности
        pGayka->massa = tmpGayka.m; // Масса
      }

      res = true;
    }
  }
  return res;
}

// HOT_POINTS ################################################################## 

//------------------------------------------------------------------------------
// Параметры для Hot точек
// ---
bool Gayka5915::GetHotPoints( HotPointDescription* point, int index )
{
  bool res = false;
  switch ( index ) 
  {
    case 0 : // Точка привязки
    {  
      point->x    =  0;
      point->y    =  0;
      point->text = "0";
      res = true;
      break;
    }
    
    case 1 : // Угол поворота 
    {  
      point->x          = m_baseParam.drawType == ID_TOP ?
                         (m_paramGayka.s * 0.5 ) : m_paramGayka.h;
      point->y          = 0;
      point->cursorInst = StepDLL.hModule;
      point->cursorId   = CURSOR_ROTATE;
      point->text       = "A";
      res = true;
      break;
    }

    case 2 : // Изменение диаметра
    {  
      point->x          = 0;
      point->y          = m_paramGayka.dr / 2.0;
      point->cursorInst = StepDLL.hModule;
      point->cursorId   = CURSOR_DIAMETER;
      point->text       = "Dr";
      res = true;
      break;
    }
  }
  return res;
}

//-------------------------------------------------------------------------------
// Параметры для Hot точек. Расширенное представление 
// ---
bool Gayka5915::GetHotPointsEx( HotPointDescription1* point, int index )
{ 
  bool res = false;

  if ( point ) {
    CString name;

    switch ( index )
    {
      case 0 : // Точка привязки
      {  
        name = _T("0");
        point->text = name.AllocSysString();
        res = true;
        if ( !commandChange ) {
          point->bitmapInst = 0;
          point->bitmapId   = 1;
          point->bitmapIdMove   = 0;
          point->bitmapIdSelect = 0;
        }
        else {
          point->bitmapInst     = StepDLL.hModule;
          point->bitmapId       = IDP_HOTPNT3_BMP;
          point->bitmapIdMove   = IDP_HOTPNT3C_BMP;
          point->bitmapIdSelect = IDP_HOTPNT3S_BMP;
        }
        break;
      }
    
      case 1 : // Угол поворота
      {
        point->bitmapInst     = StepDLL.hModule;
        if ( !commandChange ) {
          point->bitmapId       = IDP_HOTPNT1_BMP;
          point->bitmapIdMove   = IDP_HOTPNT1C_BMP;
          point->bitmapIdSelect = IDP_HOTPNT1S_BMP;
        }
        else {
          point->bitmapId       = IDP_HOTPNT4_BMP;
          point->bitmapIdMove   = IDP_HOTPNT4C_BMP;
          point->bitmapIdSelect = IDP_HOTPNT4S_BMP;

        }
        name = _T("A");
        point->text       = name.AllocSysString();;
        res = true;
        break;
      }

      case 2 : // Изменение диаметра  
      {  
        point->bitmapInst = StepDLL.hModule;
        if ( !commandChange ) {
          point->bitmapId       = IDP_HOTPNT2_BMP;
          point->bitmapIdMove   = IDP_HOTPNT2C_BMP;
          point->bitmapIdSelect = IDP_HOTPNT2S_BMP;
        }
        else {
          point->bitmapInst = 0;
          point->bitmapId   = 2;
          point->bitmapIdMove   = 0;
          point->bitmapIdSelect = 0;

        }
        name = _T("Dr");
        point->text = name.AllocSysString();
        res = true;
        break;
      }
    }
  }
  return res;
}


//-------------------------------------------------------------------------------
// Текст для Hot точек
// ---
bool Gayka5915::GetCursorText( int index, TCHAR ** text )
{
  bool res = false;
  static TCHAR cursorText[255]; // Изменяемый текст обязательно должен быть static
  switch ( index ) 
  {
    case 1 :
    {
      _stprintf_s( cursorText, _T("A = %.2f"), fmod(angle, 360.0) );
      *text = cursorText;
      res = true;
      break;
    }
    case 2 :
    {
      _stprintf_s( cursorText, _T("D = %.2f\nH = %.2f"), m_paramGayka.dr, m_paramGayka.h );
      *text = cursorText;
      res = true;
      break;
    }
  }   
  return res;
}


//-------------------------------------------------------------------------------
// Параметры для Hot точек
// ---
bool Gayka5915::ChangeHotPointParam( double d )
{
  bool res = false;

  if ( OpenBase() ) 
  {
    struct { char s[20]; float dr; } record;

    // Подобрать ближайший dR по d
    float dr    = 0.0;
    float drOld = m_paramGayka.dr;

    while( true ) 
    {
      if ( ReadRecord(  base.bg, base.rg1, &record ) ) 
      {
        if ( dr <= d )
          dr = record.dr;
        else
          break;
      }
      else
        break;
    }

    // Дочитать все параметры
    if ( fabs( dr - drOld ) > 0.01 )
      res = ReadGaykaBase( dr, base, &m_paramGayka );

    CloseBase();
  }
  return res;
}


//------------------------------------------------------------------------------
// Изменение положения Hot точек
// ---
bool Gayka5915::SetHotPoint( HotPointDescription * point, int index )
{ 
  switch ( index )
  {
    case 0 : // Хотточка перемещения
    case 1 :
      CPar::SetHotPoint( point, index );
      break;
    case 2 :
    {
      if ( ChangeHotPointParam( fabs(point->y * 2) ) )
      {
        RedrawMacro();
//        reference group = 0;
//        DrawGroup( group );
//        SetParam();
//        SetPlacement( 0., 0., 0. );
//        StoreTmpGroup( group );
//        ClearGroup( group );
      }
      break;
    }
    
  }
  return TRUE;
}


//------------------------------------------------------------------------------
// Редактирование и вставка объекта спецификации, если он был создан
// ---
bool Gayka5915::EditComplete( int index, BOOL success )
{
  if ( index == 2 && success )
  {
    DrawSpcObj(0);
  }
  if (messPrepare) {
    ::LibMessage(L"EditComplete");
  }
  return true;
}

//-------------------------------------------------------------------------------
// Меню
// ---
int Gayka5915::GetMenu( int index ) {

  HMENU res = nullptr;
  if (index == -1 )
    res = ::LoadMenu( StepDLL.hModule, (TCHAR*)MENU_G5915_1 );
  else
    switch ( index )
    {
      case 1 :
      {
        res = ::LoadMenu( StepDLL.hModule, (TCHAR*)MENU_G5915_2 );
        break;
      }
      case 2 :
      {
        res = ::LoadMenu( StepDLL.hModule, (TCHAR*)MENU_G5915_3 );
        break;
      }
    }   

    return PtrToUint(res);
}

//-------------------------------------------------------------------------------
// Выполнение команды
// ---
bool Gayka5915::ExecuteCommand( int id )
{
  if (messCommand) {
    TCHAR buf[128];
    _stprintf_s( buf, ::LoadStr(IDS_COMMAND_NUMBER), id );
    LibMessage(buf);
  }

  switch (id) {
    case 1: messCommand = !messCommand; break;
    case 2: messPrepare = !messPrepare; break;
    case 3: messSelect = !messSelect; break;
    case 4: messSelect =  messCommand = messPrepare = false; break;
    case 7: commandChange =  !commandChange; break;
  }



  return true;
}


//-------------------------------------------------------------------------------
//
// ---
LPOLESTR Gayka5915::GetCursorTextEx( int index ) { 
  
  CString name;
    
  wchar_t cursorText[255]; // Изменяемый текст обязательно должен быть static

  switch ( index ) 
  {
    case 0 : // Точка привязки
    {  
      break;
    }
    case 1 : // Угол поворота
    {
      swprintf_s( cursorText, L"A = %.2f", fmod(angle, 360.0) );
      name = cursorText;
      break;
    }
    case 2 : // Изменение диаметра
    {
      swprintf_s( cursorText, L"D = %.2f\nH = %.2f", m_paramGayka.dr, m_paramGayka.h );
      name = cursorText;
      break;
    }
  }
  return name.AllocSysString();
};


//-------------------------------------------------------------------------------
//
// ---
bool Gayka5915::UpdateCommand( int id ){
  bool res = false;
//    if ( id == 2 || id == 3  || id == 5 || id == 30 ) 
//    {
    res = id < 5 || id == 7;
//    }   
  return res;
}

//-------------------------------------------------------------------------------
//
// ---
bool Gayka5915::Prepare() {
  if (messPrepare) {
    ::LibMessage(L"Prepare");
  }
  return true;

}

//-------------------------------------------------------------------------------
//
// ---
bool Gayka5915::SelectHotPoint( int index )
{
  if (messSelect) {
    TCHAR buf[128];
    ::_stprintf_s( buf, _T("Select Index HotPoint = %d"), index  );
    ::LibMessage(buf);
  }
  return true;
}

//-------------------------------------------------------------------------------
//
// ---
bool Gayka5915::UnselectHotPoint( int index )
{
  if (messSelect) {
    TCHAR buf[128];
    ::_stprintf_s( buf, _T("Unselect Index HotPoint = %d"), index );
    ::LibMessage(buf);
  }
  return true;
}

// HOT_POINTS ################################################################## 

//-------------------------------------------------------------------------------
// Конструктор
// ---
Gayka5915::Gayka5915( reference ref, bool fromDataBase )
  : CPar( CM_GAYKA5915, ref, fromDataBase )
{
  if ( fromDataBase || !GetMacroParam(ref, *this, Size()) )
  {
    m_paramGayka.hatchAngle = 45;
    m_paramGayka.hatchStep  = 2;
    InitParam();
    m_paramGayka.iFlags     = 0;
  }
  else
  {
    if ( !m_baseParam.version )
    {
      m_baseParam.version = 1;
    }
  }
}

Gayka5915::~Gayka5915()
{
  CloseBase();
}

//-------------------------------------------------------------------------------
// Инициализация параметров
// ---
void Gayka5915::InitParam()
{
  m_paramGayka.dr            = 20;
  m_paramGayka.p             = (float)2.5;
  m_paramGayka.version       = 1;
  m_paramGayka.indexMassa    = 0;
  m_paramGayka.s             = 30;
  m_paramGayka.D             = 33;
  m_paramGayka.da            = (float)21.6;
  m_paramGayka.h             = 16;
  m_paramGayka.d2            = (float)27.7;
  m_paramGayka.classAccuracy = 2; 
  m_paramGayka.massa         = (float)71.44;
}


//-------------------------------------------------------------------------------
// Копирование
// ---
void Gayka5915::Assign( Gayka5915& other ) 
{         
  memcpy( &m_baseParam,  &other.m_baseParam,  sizeof(m_baseParam)  ); // Параметры макрообъекта
  memcpy( &m_paramGayka, &other.m_paramGayka, sizeof(m_paramGayka) ); // Параметры гайки ГОСТ 5915
  flagMode = other.flagMode;
}


//-------------------------------------------------------------------------------
// Конструктор копирования
// ---
Gayka5915::Gayka5915( Gayka5915& other )
  : CPar( CM_GAYKA5915 )
{
  Assign( other );
}


//-------------------------------------------------------------------------------
// Номер атрибута
// ---
double Gayka5915::AttrNumber()
{
  return 297327484710.0;
}


//-------------------------------------------------------------------------------
// Редактирование объекта спецификации
// ---
bool Gayka5915::_EditSpcObj( ksAPI7::ISpecificationBaseObjectPtr & obj1)
{
  ksAPI7::ISpecificationColumnsPtr columns = obj1->GetColumns();
  ksAPI7::ISpecificationColumnPtr column = columns->GetColumn( ksSColumnName, 1, 0 );
  ksAPI7::ISpecificationColumnItemsPtr columnItems = column->GetColumnItems();
  ksAPI7::ISpecificationColumnItemPtr Item;
  int spcValue;

  if ( columnItems ) {

    Item = columnItems->GetItem( 1 );
    if ( Item )
    {
      // Исполнение
      if ( !m_paramGayka.flags.isp )
      {
        Item->Visible = FALSE;
      }
      else
      {
        spcValue = 2;
        Item->Visible = TRUE;
        Item->Value = spcValue;
      }
    }

    Item = columnItems->GetItem( 3 );

    if ( Item )
      Item->Value = m_paramGayka.dr;

    // Отследим мелкий шаг
    if ( !m_paramGayka.flags.pitch )
    {
      // Выключить шаг и его разделитель
      Item = columnItems->GetItem( 4 );
      if ( Item )
        Item->Visible = FALSE;

      Item = columnItems->GetItem( 5 );
      if ( Item )
        Item->Visible = FALSE; // Шаг
    }
    else
    {
      Item = columnItems->GetItem( 4 );
      if ( Item )
        Item->Visible = TRUE;

      Item = columnItems->GetItem( 5 );
      if ( Item )
      {
        Item->Visible = TRUE; // Шаг
        Item->Value = m_paramGayka.p;
      }
    }

    Item = columnItems->GetItem( 6 );
    if ( Item )
      Item->Visible = FALSE;

    // Выключим класс прочности
    Item = columnItems->GetItem( 7 );
    if ( Item )
      Item->Visible = FALSE;

    Item = columnItems->GetItem( 8 );
    if ( Item )
      Item->Visible = FALSE;

    // Выключим покрытие
    Item = columnItems->GetItem( 9 );
    if ( Item )
      Item->Visible = FALSE;

    spcValue = 5915;

    // ГОСТ
    Item = columnItems->GetItem( 11 );
    if ( Item )
      Item->Value = spcValue;

    columns = obj1->AdditionalColumns;

    if ( columns )
    {
      // Масса детали
      double massa = m_paramGayka.massa * (!m_paramGayka.indexMassa ? 1 :
                                            m_paramGayka.indexMassa == 1 ?
                                            0.356 : 1.08) / COUNT_MASSA;

      column = columns->GetColumn( ksSColumnMass, 1, 0 );
      if ( column )
      {
        columnItems = column->GetColumnItems();
        if ( columnItems )
          columnItems->GetItem( 0 )->PutValue( massa );
      }
    }
  }

  return true;
}


//-------------------------------------------------------------------------------
// Получить парметры для элемента XML дерева
// ---
void Gayka5915::GetXMLPartFamilyParam( CString & name, CString & id )
{
  name = ::LoadStr( IDS_GAYKA5915 );
  id   = ::LoadStr( IDS_GAYKA5915_ID );
}


//-------------------------------------------------------------------------------
// Отрисовка геометрии
// ---
void Gayka5915::GetGroup()
{
  int k2 = int(m_paramGayka.flags.isp) + 1;

  switch (m_baseParam.drawType) 
  {
    case ID_VIEW :  // Вид
      if ( !(m_baseParam.flags.flagSimp) ) 
      {
        // Отрисовка апликативной заливки
        ksColouring( WORKWINDOWCOLOR );
          Gayka_K( 0, 0, 0, m_paramGayka.s, 0, m_paramGayka.h,  1, 0, m_paramGayka.d2, k2, true );
          Gayka_K( 0, 0, 0, m_paramGayka.s, 0, m_paramGayka.h, -1, 0, m_paramGayka.d2, k2, true );
        EndObj();
        // Отрисовка основной графики
        Gayka_K( 0, 0, 0, m_paramGayka.s, 0, m_paramGayka.h,  1, 0, m_paramGayka.d2, k2, false );
        Gayka_K( 0, 0, 0, m_paramGayka.s, 0, m_paramGayka.h, -1, 0, m_paramGayka.d2, k2, false );
        
      }
      else 
      {
        // Отрисовка апликативной заливки
        ksColouring( WORKWINDOWCOLOR );
          Gayka_K_Y( 0, &m_paramGayka,  1, true );
          Gayka_K_Y( 0, &m_paramGayka, -1, true );
        EndObj();
        // Отрисовка основной графики
        Gayka_K_Y( 0, &m_paramGayka,  1, false );
        Gayka_K_Y( 0, &m_paramGayka, -1, false );
      }
      if ( m_baseParam.flags.flagAxis )
        LineSeg( -AXIS_END, 0, m_paramGayka.h + AXIS_END, 0, AXIS_LINE );
    break;
    case ID_LEFT: // Вид сбоку
      if ( m_baseParam.flags.flagAxis )
        LineSeg( -AXIS_END, 0, m_paramGayka.h + AXIS_END, 0, AXIS_LINE );
      if ( m_baseParam.flags.flagSimp )
        k2 = 3;
      // Отрисовка апликативной заливки
      ksColouring( WORKWINDOWCOLOR );
        Gayka_K_Side( 0, m_paramGayka.s, m_paramGayka.D, m_paramGayka.d2, m_paramGayka.h,  1, k2, true );
        Gayka_K_Side( 0, m_paramGayka.s, m_paramGayka.D, m_paramGayka.d2, m_paramGayka.h, -1, k2, true );
      EndObj();
      // Отрисовка основной графики
      Gayka_K_Side( 0, m_paramGayka.s, m_paramGayka.D, m_paramGayka.d2, m_paramGayka.h,  1, k2, false );
      Gayka_K_Side( 0, m_paramGayka.s, m_paramGayka.D, m_paramGayka.d2, m_paramGayka.h, -1, k2, false );
    break;
    case ID_TOP : // Вид ссверху
      // Отрисовка апликативной заливки
      ksColouring( WORKWINDOWCOLOR );
        Gayka_Sverhu( true );
      EndObj();
      // Отрисовка основной графики
      Gayka_Sverhu( false );
    break;
    case ID_SEC : // Пол-вида/пол-разреза
      if( !(m_baseParam.flags.flagSimp) ) 
      {
        // Отрисовка апликативной заливки
        ksColouring( WORKWINDOWCOLOR );
          Gayka_K( 0, 0, 0, m_paramGayka.s, 0, m_paramGayka.h, 1, 0, m_paramGayka.d2, k2, true );
          Gayka_P_K( -1, true );
        EndObj();
        // Отрисовка основной графики
        Gayka_K( 0, 0, 0, m_paramGayka.s, 0, m_paramGayka.h, 1, 0, m_paramGayka.d2, k2, false );
        Gayka_P_K( -1, false );
      }
      else 
      {
        // Отрисовка апликативной заливки
        ksColouring( WORKWINDOWCOLOR );
          Gayka_K_Y( 0, &m_paramGayka, 1, true );
          Gayka_P_K( -1, true );
        EndObj();
        // Отрисовка основной графики
        Gayka_K_Y( 0, &m_paramGayka, 1, false );
        Gayka_P_K( -1, false );
      }
      if ( m_baseParam.flags.flagAxis )
        LineSeg( -AXIS_END, 0, m_paramGayka.h + AXIS_END, 0, AXIS_LINE );
      else
        LineSeg( 0, 0, m_paramGayka.h, 0, 1 );

    break;
  }
}


//-------------------------------------------------------------------------------
// Перерисовка изображения в окне предварительного просмотра
// ---
void Gayka5915::RedrawPreview() 
{
  Gayka5915 tmp(*this);
  tmp.InitParam();
  tmp.GetGroup();
}

// Список диаметров для комбобокса
bool Gayka5915::GetDiamList( SArray<double> & diam )
{
  if ( OpenBase() )
  {
    struct { char s[20]; float dr; } record;
    bool flagRepeat = true;
    while ( flagRepeat ) 
    {
      flagRepeat = !!ReadRecord( base.bg, base.rg1, &record );
      if ( flagRepeat ) 
        diam.Add( record.dr );
    }
    CloseBase();
  }
  return diam.Count() > 0;
}


//-------------------------------------------------------------------------------
// Наполнить панель контролами
// ---
void Gayka5915::ShowControls() 
{
  // Комбобокс диаметров резьбы
  ksAPI7::IPropertyListPtr diamList( CreateList() );
  if ( diamList ) 
  {
    InitPropertyControl( diamList, IDP_DIAM, IDS_DIAM_HINT/*hint*/, IDS_DIAM_TIPS/*tips*/ );
    bool flagRepeat = true;
    struct { char s[20]; float dr; } record;
    while ( flagRepeat ) 
    {
      flagRepeat = !!ReadRecord( base.bg, base.rg1, &record );
      if ( flagRepeat ) 
      {
        diamList->Add( _variant_t(record.dr, VT_R8 ) );
      }
    }
    diamList->Value = _variant_t(m_paramGayka.dr);
  }

  // Отображение
  ksAPI7::IPropertySeparatorPtr sep( CreateSeparator(ksSeparatorDownName) );
  if ( sep ) 
  {
    sep->Name = ::LoadStr( IDS_REFLECTION_SEP );
  }

  ksAPI7::IPropertyMultiButtonPtr buttons( CreateMultiButton(ksRadioButton) );
  if ( buttons ) 
  {
    InitPropertyControl( buttons, IDP_REFLECTION, IDS_REFLECTION_HINT/*hint*/, IDS_REFLECTION_TIPS/*tips*/, TRUE, ksNameVerticalVisible );
    // Кнопка вид
    AddButton2( buttons, ID_VIEW, IDF_VIEW, m_baseParam.drawType == ID_VIEW );
    // Кнопка сбоку 
    AddButton2( buttons, ID_LEFT, IDF_LEFT, m_baseParam.drawType == ID_LEFT );
    // Кнопка сверху 
    AddButton2( buttons, ID_TOP,  IDF_TOP,  m_baseParam.drawType == ID_TOP  );
    // Кнопка Вид/разрез 
    AddButton2( buttons, ID_SEC,  IDF_SEC,  m_baseParam.drawType == ID_SEC  );
  }
  
  // Исполнение
  ksAPI7::IPropertyMultiButtonPtr ispButtons( CreateMultiButton(ksRadioButton) );
  if ( ispButtons ) 
  {
    InitPropertyControl( ispButtons, IDP_ISP, IDS_ISP_HINT/*hint*/, IDS_ISP_TIPS/*tips*/, TRUE, ksNameVerticalVisible );
    // Кнопка исполнение 1
    AddButton2( ispButtons, IDP_ICO_G_I1, IDF_G_I1, !m_paramGayka.flags.isp );
    // Кнопка исполнение 2
    AddButton2( ispButtons, IDP_ICO_G_I2, IDF_G_I2,  m_paramGayka.flags.isp );
  }
  
  // Упрощенно
  ksAPI7::IPropertyMultiButtonPtr simpleButtons( CreateMultiButton(ksCheckButton) );
  if ( simpleButtons ) 
  {
    InitPropertyControl( simpleButtons, IDP_SIMPLE, IDS_SIMPLE_HINT/*hint*/, IDS_SIMPLE_TIPS/*tips*/, TRUE, ksNameVerticalVisible );
    AddButton2( simpleButtons, ID_SIMPLE, IDF_SIMPLE, m_baseParam.flags.flagSimp );
    AddButton2( simpleButtons, ID_AXIS, IDF_AXIS, m_baseParam.flags.flagAxis );
  }

  sep = CreateSeparator( ksSeparatorDownName );

  // Дополнительные параметры
  ksAPI7::IPropertyMultiButtonPtr paramButtons( CreateMultiButton(ksCheckButton) );
  if ( paramButtons ) 
  {
    InitPropertyControl( paramButtons, IDP_FLAGS, IDS_FLAGS_TIPS/*hint*/, IDS_FLAGS_TIPS/*tips*/, TRUE, ksNameVerticalVisible );
    // Шаг мелкий
    AddButton2( paramButtons, IDP_ICO_G_STEP, IDF_G_STEP, m_paramGayka.flags.pitch, m_paramGayka.flags.pitch_on );
    // Размер под ключ
    AddButton2( paramButtons, IDP_ICO_KEY, IDF_KEY, !m_paramGayka.flags.key_s, m_paramGayka.flags.key_s_on );
  }

  // Параметры штриховки
  CPar::ShowControls();
} 


//---------------------------------------------------------------------------------------------------- 
// Выдать идентификатор свойства по индексу
// ---
int Gayka5915::GetPropertyID ( int index )
{
  int res = 0;
  switch ( index )
  {
    case 0 : res = ID_PROP_ELEMENT_PARAM; break; // Параметры элемента
    case 1 : res = ID_PROP_DIAM         ; break; // Диаметр резьбы
    case 2 : res = ID_PROP_ISPOLN       ; break; // Исполнение
    case 3 : res = ID_PROP_VIEW_PARAM   ; break; // Параметры отображения
    case 4 : res = ID_PROP_VIEW         ; break; // Вид
    case 5 : res = ID_PROP_SIMPLE       ; break; // Упрощенное отображение
    case 6 : res = ID_PROP_AXIS         ; break; // Рисовать ось
    case 7 : res = ID_PROP_HATCH_PARAM  ; break; // Параметры штриховки
    case 8 : res = ID_PROP_HATCH_STEP   ; break; // Шаг штриховки
    case 9 : res = ID_PROP_HATCH_ANGLE  ; break; // Угол штриховки
    case 10: res = ID_PROP_OTHER_PARAM  ; break; // Группа Дополнительные параметры
    // Для примера свойств не описанных в ресурсах
    case 11: res = ID_PROP_OTHER_PARAM + 1; break; // IDS_PITCH      Шаг резьбы
    case 12: res = ID_PROP_OTHER_PARAM + 2; break; // IDS_DIM_KEY    Размер под ключ
    case 13: res = ID_PROP_OTHER_PARAM + 3; break; // IDS_HEAD_H     Высота головки
    case 14: res = ID_PROP_MASSA_1000;      break; // IDS_MASSA_1000 Масса 1000 шт
  }
  return res;
}


//---------------------------------------------------------------------------------------------------- 
// Значение контрола изменились нужно передать в гайку
// ---
bool Gayka5915::OnChangeControlValue(  long               ctrlID, 
                                       const VARIANT&     newVal ) 
{
  bool res = CPar::OnChangeControlValue( ctrlID, newVal );
  if ( !res ) 
  {
    
    switch ( ctrlID ) 
    {
      case IDP_DIAM: // Диаметр 
      { 
        float diam = (float)newVal.dblVal; 
        if ( ::fabs(diam - m_paramGayka.dr ) > 0.001 ) 
        {
          res = true;
          m_paramGayka.dr = diam;  
          if ( ReadGaykaBase ( m_paramGayka.dr, base, &m_paramGayka ) ) 
          {
            ksAPI7::IPropertyMultiButtonPtr control( GetPropertyControl(IDP_FLAGS) );
            if ( control ) 
            {
              control->ButtonEnable [ IDP_ICO_G_STEP] = m_paramGayka.flags.pitch_on;
              control->ButtonEnable [ IDP_ICO_KEY   ] = m_paramGayka.flags.key_s_on;
              control->ButtonChecked[ IDP_ICO_KEY   ] = m_paramGayka.flags.key_s; 
            }
          }
        }
        break; 
      }
    }
    if ( res ) 
      changed = true; // надо перерисовать
  }
  return res;  
} 


//---------------------------------------------------------------------------------------------------- 
// Обработка нажатия кнопок
// ---
bool Gayka5915::OnButtonClick( long buttonID ) 
{ 
    changed=false;

  switch ( buttonID ) 
  { 

    case IDP_ICO_G_I1: // Исполнение 1
      m_paramGayka.flags.isp = 0;
      Draw1();
      changed = true;  // Нужно перерисовать и перезаполнить грид
      break;
       
    case IDP_ICO_G_I2: // Исполнение 2
      m_paramGayka.flags.isp = 1;
      Draw1();
      changed = true;  // Нужно перерисовать и перезаполнить грид
      break;
 
    case IDP_ICO_G_STEP: // Шаг 
      m_paramGayka.flags.pitch = !m_paramGayka.flags.pitch;
      changed = true;  // Нужно перерисовать и перезаполнить грид
      break; 

    case IDP_ICO_KEY:  // Размер поз ключ 
      m_paramGayka.flags.key_s = !m_paramGayka.flags.key_s;
      changed = true;  // Нужно перерисовать и перезаполнить грид 
      break;

    case ID_LEADER_CREATE: // Создать новую линию выноски
    {
      if (newKompasAPI)
      {
        // Остановка текущего процесса.
        newKompasAPI->StopCurrentProcess(TRUE, NULL);// Должно быть true
        processState = ProcessState::processCreateLeader;
      }
    }
  }
  return changed ? 
         changed :                        // Обработали ButtonClick
         CPar::OnButtonClick( buttonID ); // Обработчик кнопки в базовом классе
}


//---------------------------------------------------------------------------------------------------- 
// Вывод параметров гайки
// ---
void Gayka5915::ShowParam() 
{
  AddDoubleToGrig( IDS_PITCH,      m_paramGayka.p     ); // Шаг резьбы
  AddDoubleToGrig( IDS_DIM_KEY,    m_paramGayka.s     ); // Размер под ключ
  AddDoubleToGrig( IDS_HEAD_H,     m_paramGayka.h     ); // Высота головки
  AddDoubleToGrig( IDS_MASSA_1000, m_paramGayka.massa ); // Масса 1000 шт
}


//--------------------------------------------------------------------------
// Добавить свойство в список свойств
//---
BOOL Gayka5915::GetProperty( int index, PropertyParam & param )
{
  BOOL res = CPar::GetProperty( index, param );
  if ( param.propertyId > ID_PROP_OTHER_PARAM && param.propertyId < ID_PROP_OTHER_PARAM_END )
  {
    param.propertyType  = ksOPControlEditDouble;   // Вещественный комбобокс
    param.propertyValue.vt = VT_R8;
    param.propertyValue.dblVal = 0.0;
    param.enable = false;                          // Не редактируется

    int nameId = 0;
    switch ( param.propertyId )
    {
      case (ID_PROP_OTHER_PARAM + 1): nameId = IDS_PITCH;      break; // Шаг резьбы 
      case (ID_PROP_OTHER_PARAM + 2): nameId = IDS_DIM_KEY;    break; // Размер под ключ
      case (ID_PROP_OTHER_PARAM + 3): nameId = IDS_HEAD_H;     break; // Высота головки
      case ID_PROP_MASSA_1000       : nameId = IDS_MASSA_1000; break; // Масса 1000 шт
    }

    param.displayPropertyName = CString(LoadStr(nameId)).AllocSysString();
  }
  return res;
}


//--------------------------------------------------------------------------
// Обновить параметры свойства
//---
BOOL Gayka5915::UpdateProperty( PropertyParam & param )
{
  BOOL res = CPar::UpdateProperty( param );
  if ( !res )
  {
    switch ( param.propertyId )
    {
      case ID_PROP_DIAM:   // Диаметр резьбы
      {
        param.propertyValue.dblVal = (double)GetParamGayka().dr;
        if ( param.additionData.vt != (VT_ARRAY | VT_R8) ) // Повторно не перенакачиваем
        {
          SArray<double> diam;
          GetDiamList( diam );
          CopySArrayToVariant( diam, param.additionData );
        }
        res = TRUE;
        break;
      }
      case ID_PROP_ISPOLN: // Исполнение
      {
        param.propertyValue.lVal = GetParamGayka().flags.isp ? IDP_ICO_G_I2 : IDP_ICO_G_I1;
        res = TRUE;
        break;
      }
      // Для примера свойств не описанных в ресурсах
      case (ID_PROP_OTHER_PARAM + 1): param.propertyValue.dblVal = m_paramGayka.p;     break; // IDS_PITCH       Шаг резьбы
      case (ID_PROP_OTHER_PARAM + 2): param.propertyValue.dblVal = m_paramGayka.s;     break; // IDS_DIM_KEY     Размер под ключ
      case (ID_PROP_OTHER_PARAM + 3): param.propertyValue.dblVal = m_paramGayka.h;     break; // IDS_HEAD_H      Высота головки
      case ID_PROP_MASSA_1000       : param.propertyValue.dblVal = m_paramGayka.massa; break; // IDS_MASSA_1000  Масса 1000 шт

    }
  }
  return res;
}

//--------------------------------------------------------------------------
// Изменить свойойство
//---
BOOL Gayka5915::ApplyProperty( PropertyParam & param )
{
  BOOL res = CPar::ApplyProperty( param );
  if ( !res )
  {
    switch ( param.propertyId )
    {
      case ID_PROP_DIAM:   // Диаметр резьбы
      {
        OpenBase();
        res = !!OnChangeControlValue( IDP_DIAM, param.propertyValue );
        CloseBase();
        break;
      }
      case ID_PROP_ISPOLN: // Исполнение
      {
        GetParamGayka().flags.isp = param.propertyValue.lVal == IDP_ICO_G_I2;
        res = TRUE;
        break;
      }
    }

    if ( res )
      changed = true;
  }
  return res;
}

//---------------------------------------------------------------------------------------------------- 
// Имя группы
// ---
LPOLESTR Gayka5915::GetGroupName()
{
  CString name( LoadStr(IDP_GAYKA5915) );
  return name.AllocSysString();
}


//---------------------------------------------------------------------------------------------------- 
// Имя группы
// ---
LPCTSTR Gayka5915::GetObjName()
{
  return LoadStr(IDP_GAYKA5915);
}


//---------------------------------------------------------------------------------------------------- 
// Новая гайка
// ---
CPar * NewGayka5915( reference obj, bool fromDataBase ) 
{
  return new Gayka5915( obj, fromDataBase );
}

