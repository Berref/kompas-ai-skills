//////////////////////////////////////////////////////////////////////////////// 
// 
// step9.cpp - Размеры и другие технологические объекты
// 
// 1.  Линейный размер             - DrawLinDim
// 2.  Угловой размер              - DrawAngDim
// 3.  Шероховатость               - DrawRough
// 4.  Линия выноски               - DrawLeader
// 5.  Позиционная линия выноски   - DrawPosLeader
// 6.  Клеймение                   - DrawBrandLeader
// 7.  Маркирование                - DrawMarkerLeader
// 8.  Обозначение базы            - DrawBase
// 9.  Линия разреза/cечения       - DrawCutLine
// 10. Диаметральный размер        - DrawDiamDim
// 11. Радиальный размер           - DrawRadDimt
// 12. Радиальный размер c изломом - DrawRadBreakDimt
// 13. Стрелка вида                - DrawViewPointer  
// 
//////////////////////////////////////////////////////////////////////////////// 
#include "stdafx.h"
#include <afxdllx.h> 
#include "resource.h"

#ifndef __LIBTOOL_H
#include <libtool.h>
#endif

#ifndef __LDEFIN2D_H
#include <ldefin2d.h>
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


//-------------------------------------------------------------------------------
// Специальная структура используемая в течении инициализации DLL
// ---
static AFX_EXTENSION_MODULE StepDLL = { NULL, NULL };


//-------------------------------------------------------------------------------
// Стандартная точка входа
// Инициализация и завершение DLL
// ---
extern "C" int APIENTRY
DllMain( HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved )
{
  UNREFERENCED_PARAMETER( lpReserved );

  if ( dwReason == DLL_PROCESS_ATTACH )
  {
    TRACE0( "DLL Initializing!" );
 
    if ( !AfxInitExtensionModule( StepDLL, hInstance ) )
      return 0;

    new CDynLinkLibrary( StepDLL );
  }
  else if ( dwReason == DLL_PROCESS_DETACH )
  {
    TRACE0( "DLL Terminating!" );
    AfxTermExtensionModule( StepDLL );
  }
  return 1;
}


//-------------------------------------------------------------------------------
// Задать идентификатор ресурсов
// ---
unsigned int WINAPI LIBRARYID()
{
  return IDR_LIBID;
}


//-------------------------------------------------------------------------------
// Описания используемых функций
// ---
void DrawLinDim();
void DrawAngDim();
void DrawRough();
void DrawLeader();
void DrawPosLeader();
void DrawBrandLeader();
void DrawMarkerLeader();
void DrawBase();
void DrawCutLine();
void DrawDiamDim();
void DrawRadDimt();
void DrawRadBreakDimt();
void DrawViewPointer();


//-------------------------------------------------------------------------------
// Головная функция библиотеки
// ---
void WINAPI LIBRARYENTRY( unsigned int comm )
{
  if ( ksGetCurrentDocument( 1 ) ) // Получить активный 2D документ
  {
    switch ( comm )
    {
      case 1  : DrawLinDim();       break; // Линейный размер
      case 2  : DrawAngDim();       break; // Угловой размер
      case 3  : DrawRough();        break; // Шероховатость
      case 4  : DrawLeader();       break; // Линия выноски
      case 5  : DrawPosLeader();    break; // Позиционная линия выноски
      case 6  : DrawBrandLeader();  break; // Клеймение
      case 7  : DrawMarkerLeader(); break; // Маркирование
      case 8  : DrawBase();         break; // Обозначение базы
      case 9  : DrawCutLine();      break; // Линия разреза/cечения
      case 10 : DrawDiamDim();      break; // Диаметральный размер
      case 11 : DrawRadDimt();      break; // Радиальный размер
      case 12 : DrawRadBreakDimt(); break; // Радиальный размер c изломом
      case 13 : DrawViewPointer();  break; // Стрелка вида
    }
  }
  else
    ErrorT( _T("Документ не активизирован или\nне является листом/фрагментом") );
}


//-------------------------------------------------------------------------------
// Функция для отображения параметров размера ( 0 - линейный размер, 1 - угловой размер,
// 2 - диаметральный и радиальный размер, 3 - радиальный размер c изломом )
// ---
static void ShowDimParam( LPCTSTR title, void *pParam, int typeParam, int typeDim )
{
  DimText * pParDimText             = NULL; // Структура параметров размерной надписи
  DimDrawing * pParDimDrawing       = NULL; // Структура параметров отрисовки линейного и углового размеров
  RDimDrawing  * pParRDimDrawing    = NULL; // Структура параметров отрисовки диаметрального и радиального размеров
  RBreakDrawing * pParRBreakDrawing = NULL; // Структура параметров изображения радиального размера с изломом
  LDimSource * pParLDimSource       = NULL; // Структура параметров привязки линейного размера
  ADimSource * pParADimSource       = NULL; // Структура параметров привязки углового размера
  RDimSource * pParRDimSource       = NULL; // Структура параметров привязки диаметрального и радиального размеров
  
  switch ( typeParam ) 
  {
    // Отображение всех параметров
    case ALLPARAM_W :  
    case ALLPARAM   :  
    {
      switch ( typeDim )
      {
        case 0 :
        {
          LDimParam * pParLDim = ( LDimParam * )pParam;
          pParDimText    = &pParLDim->tPar;
          pParLDimSource = &pParLDim->sPar;
          pParDimDrawing = &pParLDim->dPar;
          break;
        }
        case 1 :
        {
          ADimParam * pParADim = ( ADimParam * )pParam;
          pParDimText    = &pParADim->tPar;
          pParADimSource = &pParADim->sPar;
          pParDimDrawing = &pParADim->dPar;
          break;
        }
        case 2 :  
        {
          RDimParam * pParRDim = ( RDimParam * )pParam;
          pParDimText     = &pParRDim->tPar;
          pParRDimSource  = &pParRDim->sPar;
          pParRDimDrawing = &pParRDim->dPar;
          break;
        }
        case 3 :  
        {
          RBreakDimParam * pParRBreakDim = ( RBreakDimParam * )pParam;
          pParDimText       = &pParRBreakDim->tPar;
          pParRDimSource    = &pParRBreakDim->sPar;
          pParRBreakDrawing = &pParRBreakDim->dPar;
          break; 
        }
      }  
      break;
    }
    // Отображение параметров размерной надписи
    case DIM_TEXT_PARAM :
      pParDimText = ( DimText * )pParam;
      break;
    // Отображение параметров привязки
    case DIM_SOURSE_PARAM :
    {
      switch ( typeDim )
      {
        case 0 :
          pParLDimSource = ( LDimSource * ) pParam;
          break;
        case 1 :
          pParADimSource = ( ADimSource * ) pParam;
          break;
        case 2 :
        case 3 :   
          pParRDimSource = ( RDimSource * ) pParam;
          break;
      }  
      break;
    }    
    // Отображение параметров отрисовки
    case DIM_DRAW_PARAM : 
    {
      switch ( typeDim )
      {
        case 0 :
        case 1 :
          pParDimDrawing = ( DimDrawing * ) pParam;
          break;
        case 2 :
          pParRDimDrawing = ( RDimDrawing * ) pParam;
          break;
        case 3 :            
          pParRBreakDrawing = ( RBreakDrawing * ) pParam;
          break;
      }  
      break;
    }    
  }
  
  TCHAR buf[255];   
   
  // Размерная надпись  
  if ( pParDimText ) 
  {
    TCHAR buf1[255], buf2[255];
    buf1[0] = _T('\0');
    
    // Количество элементов в массиве
    int count = GetArrayCount( pParDimText->pText );
    
    // Цикл по строкам
    for ( int i = 0; i < count; i++ ) 
    {
      // Получить значение элемента массива
      GetArrayItem( pParDimText->pText, i, buf2, 255 ); 
      _tcscat_s( buf1, buf2 );
      _tcscat_s( buf1, _T(" ") );
    }

    _stprintf_s( buf, _T("%s\n%s\nПараметры надписи\nsign = %d,\nbitFlag = %d"), 
             title, buf1, pParDimText->sign, pParDimText->bitFlag );
    MessageT( buf );
  }  
  
  // Параметры привязки размера
  if ( pParLDimSource ) 
  {
    _stprintf_s( buf, _T("%s\nПараметры привязки\nx1 = %3.2f, y1 = %3.2f,\nx2 = %3.2f, y2 = %3.2f,\ndx = %3.2f, dy = %3.2f,\nbasePoint = %d, ps = %d"), 
             title, pParLDimSource->x1, pParLDimSource->y1, pParLDimSource->x2, pParLDimSource->y2, 
             pParLDimSource->dx, pParLDimSource->dy, pParLDimSource->basePoint, pParLDimSource->ps  );
    MessageT( buf );
  }
  if ( pParADimSource ) 
  {
    _stprintf_s( buf, _T("%s\nПараметры привязки\nxc = %3.2f, yc = %3.2f,\nx1 = %3.2f, y1 = %3.2f,\nx2 = %3.2f, y2 = %3.2f,\nang1 = %3.2f, ang2 = %3.2f,\nrad = %3.2f, dir = %d"), 
             title, pParADimSource->xc, pParADimSource->yc, pParADimSource->x1, pParADimSource->y1, 
             pParADimSource->x2, pParADimSource->y2, pParADimSource->ang1, pParADimSource->ang2, 
             pParADimSource->rad, pParADimSource->dir );
    MessageT( buf );
  }  
  if ( pParRDimSource ) 
  {
    _stprintf_s( buf, _T("%s\nПараметры привязки\nxc = %3.2f, yc = %3.2f,\nrad = %3.2f"), 
             title, pParRDimSource->xc, pParRDimSource->yc, pParRDimSource->rad );
    MessageT( buf );
  } 
  
  // Параметры изображения размера 
  if ( pParDimDrawing ) 
  {
    _stprintf_s( buf, _T("%s\nПараметры отрисовки\npl1 = %d, pl2 = %d,\npt1 = %d, pt2 = %d,\ntextPos = %d, textBase = %d,\nshelfDir = %d, ang = %3.2f, length = %d"), 
             title, pParDimDrawing->pl1, pParDimDrawing->pl2, pParDimDrawing->pt1, pParDimDrawing->pt2, 
             pParDimDrawing->textPos, pParDimDrawing->textBase, pParDimDrawing->shelfDir,
             pParDimDrawing->ang, pParDimDrawing->length );
    MessageT( buf );
  }
  if ( pParRDimDrawing ) 
  {
    _stprintf_s( buf, _T("%s\nПараметры отрисовки\npl1 = %d, pl2 = %d,\n\ntextPos = %d, shelfDir = %d,\n ang = %3.2f"), 
             title, pParRDimDrawing->pt1, pParRDimDrawing->pt2, 
             pParRDimDrawing->textPos, pParRDimDrawing->shelfDir, 
             pParRDimDrawing->ang );
    MessageT( buf );
  }
  if ( pParRBreakDrawing ) 
  {
    _stprintf_s( buf, _T("%s\nПараметры отрисовки\npt = %d,\nang = %3.2f, pb = %d"), 
             title, pParRBreakDrawing->pt, pParRBreakDrawing->ang, pParRBreakDrawing->pb );
    MessageT( buf );
  }    
}


//-------------------------------------------------------------------------------
// Линейный размер
// ---
void DrawLinDim()
{
  LDimParam parLDim; // Структура параметров линейного размера
  memset( &parLDim, 0, sizeof( parLDim ) );
  
  // Параметры изображения размера
  parLDim.dPar.textPos  = 10;  // Положение текста ( 0 - автоматическое размещение текста,
		                           // > 0 - на указанное расстояние в направлении от первой точки ко второй,
		                           // < 0 - на указанное расстояние в направлении от второй точки к первой )
  parLDim.dPar.textBase = 2;   // Параметр отрисовки текста ( 0 - в центре, 1 - textPos относительно 1 точки, 
		                           // 2 - textPos относительно 2 точки, 3 - общая размерная линия )
  parLDim.dPar.pl1      = 0;   // Признак отрисовки первой выносной линии ( 0 - включена, 1 - выключена )
  parLDim.dPar.pl2      = 0;   // Признак отрисовки второй выносной линии ( 0 - включена, 1 - выключена )
  parLDim.dPar.pt1      = 2;   // Тип стрелки у первой выносной линии ( 0 - стрелки нет, 1 - внутри, 2 - снаружи, 3 - засечка, 4 - точка )
  parLDim.dPar.pt2      = 2;   // Тип стрелки у второй выносной линии ( 0 - стрелки нет, 1 - внутри, 2 - снаружи, 3 - засечка, 4 - точка )
  parLDim.dPar.shelfDir = 0;   // Наличие выносной полки ( 0 - нет выносной полки, -1 - полка направлена влево,
                               // 1 - полка направлена вправо, 2 - полка направлена вверх, 3 - полка направлена вниз )
  parLDim.dPar.ang      = -30; // Угол наклона ножки выносной полки
  parLDim.dPar.length   = 20;  // Длина ножки выносной полки
  
  // Параметры размерной надписи
  parLDim.tPar.style   = 0; // Cтиль текста размера, ( 0 - стиль по умолчанию )
  parLDim.tPar.sign    = 0; // Номер условного значка перед номиналом ( 0 - нет значка, 1 - диаметр, 2 - квадрат,
                            // 3 - радиус, > 3 - номер значка из шрифта Symbol type A )
  // Признаки размерной надписи ( набор битовых полей, 0 - ручное задание ) 
  // Должны быть строки PREFIX, номинал ставится auto ( ставить не нужно ), TOLERANCE, отклонения
  // ставятся auto ( ставить не нужно ), UNIT, SUFFIX ( 4 строки )
  parLDim.tPar.bitFlag = _AUTONOMINAL|_PREFIX|_DEVIATION|_UNIT|_SUFFIX; 
  parLDim.tPar.pText   = CreateArray( CHAR_STR_ARR_T, 0 ); // Динамический массив строк
  
  // Добавить элементы динамического массива
  AddArrayItem( parLDim.tPar.pText, -1, _T("prefix"), 8 );
  AddArrayItem( parLDim.tPar.pText, -1, _T("+0.5"),  5 );
  AddArrayItem( parLDim.tPar.pText, -1, _T("-0.5"),  5 );
  AddArrayItem( parLDim.tPar.pText, -1, _T("mm"),     5 );
  AddArrayItem( parLDim.tPar.pText, -1, _T("suffics"), 13 );

  // Привязка линейного размера
  parLDim.sPar.ps        = 0;   // Признак ориентации размерной линии ( 0 - горизонтально, 1 - вертикально,
                                // 2 - параллельно отрезку, соединяющему точки привязки, 3 - по dx, dy,
                                // 4 - параллельно отрезку с выносными линиями по dx, dy.
  parLDim.sPar.x1        = 50;  // Координаты первой точки привязки
  parLDim.sPar.y1        = 50; 
  parLDim.sPar.x2        = 70;  // Координаты второй точки привязки
  parLDim.sPar.y2        = 60; 
  parLDim.sPar.dy        = -20; // Вектор, определяющий положение размерной линии 
  parLDim.sPar.dx        = 0;
  parLDim.sPar.basePoint = 1;   // Признак, указывающий, от какой точки откладывать dx, dy
                                // ( 1 - от первой точки, 2 - от второй точки )
  // Создание линейного размера 
  reference rLinDimension = LinDimension( &parLDim );
  
  GetObjParam( rLinDimension,     // Указатель на графический объект
               &parLDim,          // Указатель на структуру параметров
               sizeof( parLDim ), // Размер структуры параметров
               ALLPARAM_T );        // Тип считывания параметров  
  
  // Функция для отображения параметров размера ( 0 - линейный размер, 1 - угловой размер,
  // 2 - диаметральный и радиальный размер, 3 - радиальный размер c изломом )
  ShowDimParam( _T("Cоздание размера"), &parLDim, ALLPARAM_T, 0 );
  
  // Изменение параметров изображения размера
  parLDim.dPar.textPos  = 1; // Положение текста
  parLDim.dPar.textBase = 2; // Параметр отрисовки текста
  parLDim.dPar.pl1      = 1; // Признак отрисовки первой выносной линии
  parLDim.dPar.pl2      = 1; // Признак отрисовки второй выносной линии 
  parLDim.dPar.pt1      = 1; // Тип стрелки у первой выносной линии
  parLDim.dPar.pt2      = 1; // Тип стрелки у второй выносной линии
  parLDim.dPar.shelfDir = 0; // Наличие выносной полки
  
  SetObjParam( rLinDimension,          // Указатель на графический объект
               &parLDim.dPar,          // Указатель на структуру параметров
               sizeof( parLDim.dPar ), // Размер структуры параметров
               DIM_DRAW_PARAM );       // Тип считывания параметров

  GetObjParam( rLinDimension,          // Указатель на графический объект
               &parLDim.dPar,          // Указатель на структуру параметров
               sizeof( parLDim.dPar ), // Размер структуры параметров
               DIM_DRAW_PARAM );       // Тип считывания параметров

  // Функция для отображения параметров размера ( 0 - линейный размер, 1 - угловой размер,
  // 2 - диаметральный и радиальный размер, 3 - радиальный размер c изломом )
  ShowDimParam( _T("Редактирование размера"), &parLDim.dPar, DIM_DRAW_PARAM, 0 );

  // Удалить динамический массив строк
  DeleteArray( parLDim.tPar.pText );
}


//-------------------------------------------------------------------------------
// Угловой размер 
// --- 
void DrawAngDim()
{
  ADimParam parADim; // Структура параметров углового размера 
  memset( &parADim, 0, sizeof( parADim ) );
  
  // Параметры изображения размера
  parADim.dPar.textPos  = -10; // Положение текста ( 0 - автоматическое размещение текста,
		                           // > 0 - на указанное расстояние в направлении от первой точки ко второй,
		                           // < 0 - на указанное расстояние в направлении от второй точки к первой )
  parADim.dPar.textBase = 0;   // Параметр отрисовки текста ( 0 - в центре, 1 - textPos относительно 1 точки, 
		                           // 2 - textPos относительно 2 точки, 3 - общая размерная линия )
  parADim.dPar.pl1      = 0;   // Признак отрисовки первой выносной линии ( 0 - включена, 1 - выключена )
  parADim.dPar.pl2      = 0;   // Признак отрисовки второй выносной линии ( 0 - включена, 1 - выключена )
  parADim.dPar.pt1      = 1;   // Тип стрелки у первой выносной линии ( 0 - стрелки нет, 1 - внутри, 2 - снаружи, 3 - засечка, 4 - точка )
  parADim.dPar.pt2      = 1;   // Тип стрелки у второй выносной линии ( 0 - стрелки нет, 1 - внутри, 2 - снаружи, 3 - засечка, 4 - точка )
  parADim.dPar.shelfDir = 0;   // Наличие выносной полки ( 0 - нет выносной полки, -1 - полка направлена влево,
                               // 1 - полка направлена вправо, 2 - полка направлена вверх, 3 - полка направлена вниз )
  parADim.dPar.ang      = 30;  // Угол наклона ножки выносной полки
  parADim.dPar.length   = 20;  // Длина ножки выносной полки
  
  // Параметры размерной надписи
  parADim.tPar.style   = 0; // Cтиль текста размера, ( 0 - стиль по умолчанию )
  parADim.tPar.sign    = 0; // Номер условного значка перед номиналом ( 0 - нет значка, 1 - диаметр, 2 - квадрат,
                            // 3 - радиус, > 3 - номер значка из шрифта Symbol type A )
  // Признаки размерной надписи ( набор битовых полей, 0 - ручное задание ) 
  // Должны быть строки PREFIX, номинал ставится auto ( ставить не нужно ), TOLERANCE, отклонения
  // ставятся auto ( ставить не нужно ), UNIT, SUFFIX ( 4 строки )
  parADim.tPar.bitFlag = _AUTONOMINAL|_PREFIX|_DEVIATION|_UNIT|_SUFFIX; 
  parADim.tPar.pText   = CreateArray( CHAR_STR_ARR_T, 0 ); // Динамический массив строк
  
  // Добавить элементы динамического массива
  AddArrayItem( parADim.tPar.pText, -1, _T("prefix"), 8 );
  AddArrayItem( parADim.tPar.pText, -1, _T("+0.3"),  5 );
  AddArrayItem( parADim.tPar.pText, -1, _T("-0.3"),  5 );
  AddArrayItem( parADim.tPar.pText, -1, _T("гр"),    5 );
  AddArrayItem( parADim.tPar.pText, -1, _T("suffics"), 8 );

  // Привязка углового размера
  parADim.sPar.xc   = 40; // Координаты центра размерной дуги
  parADim.sPar.yc   = 0;   
  parADim.sPar.x1   = 40; // Координаты точки выхода первой выносной линии
  parADim.sPar.y1   = 40;     
  parADim.sPar.x2   = 60; // Координаты точки выхода второй выносной линии
  parADim.sPar.y2   = 20;   
  parADim.sPar.ang1 = 0;  // Начальный угол размерной дуги ( используются точки выхода выносной линии )
  parADim.sPar.ang2 = 0;  // Конечный угол размерной дуги ( используются точки выхода выносной линии )
  parADim.sPar.rad  = 50; // Радиус размерной дуги
  parADim.sPar.dir  = 1;  // Направление ( 1 - размерная линия против часовой стрелки, -1 - по часовой стрелке )

  // Создание углового размера
  reference rAngDimension = AngDimension( &parADim );

  GetObjParam( rAngDimension,     // Указатель на графический объект
               &parADim,          // Указатель на структуру параметров
               sizeof( parADim ), // Размер структуры параметров
               ALLPARAM_T );        // Тип считывания параметров
 
  // Функция для отображения параметров размера ( 0 - линейный размер, 1 - угловой размер,
  // 2 - диаметральный и радиальный размер, 3 - радиальный размер c изломом )
  ShowDimParam( _T("Создание размера"), &parADim, ALLPARAM_T, 1 );

  // Привязка углового размера
  parADim.sPar.xc   = 40; // Координаты центра размерной дуги
  parADim.sPar.yc   = 60;   
  parADim.sPar.x1   = 10; // Координаты точки выхода первой выносной линии
  parADim.sPar.y1   = 60;     
  parADim.sPar.x2   = 20; // Координаты точки выхода второй выносной линии
  parADim.sPar.y2   = 80;   
  parADim.sPar.ang1 = 0;  // Начальный угол размерной дуги ( используются точки выхода выносной линии )
  parADim.sPar.ang2 = 0;  // Конечный угол размерной дуги ( используются точки выхода выносной линии )
  parADim.sPar.rad  = 50; // Радиус размерной дуги
  parADim.sPar.dir  = -1; // Направление ( 1 - размерная линия против часовой стрелки, -1 - по часовой стрелке )

  SetObjParam( rAngDimension,          // Указатель на графический объект
               &parADim.sPar,          // Указатель на структуру параметров
               sizeof( parADim.sPar ), // Размер структуры параметров
               DIM_SOURSE_PARAM	);     // Тип считывания параметров

  GetObjParam( rAngDimension,          // Указатель на графический объект
               &parADim.sPar,          // Указатель на структуру параметров
               sizeof( parADim.sPar ), // Размер структуры параметров
               DIM_SOURSE_PARAM );     // Тип считывания параметров
               
  // Функция для отображения параметров размера ( 0 - линейный размер, 1 - угловой размер,
  // 2 - диаметральный и радиальный размер, 3 - радиальный размер c изломом )
  ShowDimParam( _T("Редактирование размера"), &parADim.sPar, DIM_SOURSE_PARAM, 1 );

  // Удалить динамический массив строк
  DeleteArray( parADim.tPar.pText );
}


//-------------------------------------------------------------------------------
// Шероховатость
// ---
void DrawRough()
{
  RoughParam parRougham; // Структура параметров обозначения шероховатости с выносной полкой
  memset( &parRougham, 0, sizeof( parRougham ) );

  // Параметры выносной полки
  parRougham.shPar.psh    = 0;   // Направление полки параллельно оси X ( 0 - нет выносной полки,
                                 // -1 - полка направлена влево, 1 - полка направлена вправо,	
                                 // 2 - полка направлена вверх, 3 - полка направлена вниз )
  parRougham.shPar.ang    = 130; // Угол наклона размерной линии
  parRougham.shPar.length = 20;  // Длина ножки

  // Параметры знака шероховатости
  parRougham.rPar.type  = 0;   // Тип шероховатости ( 0 - вид обработки не устанавливается, 1 - обработка удалением слоя материала,
                               // 2 - обработка без удаления слоя материала )
  parRougham.rPar.around = 0;  // 1 - шероховатость по контуру
  parRougham.rPar.x      = 50; // Координаты точки привязкиопараметры первого отрезка
  parRougham.rPar.y      = 50;       
  parRougham.rPar.ang    = 90; // Угол наклона оси значка шероховатости с осью X
  parRougham.rPar.cText0 = 2;  // Количество строк в тексте над знаком ( параметры шер-ти по ГОСТ 2789-73 )
  parRougham.rPar.cText1 = 2;  // Количество строк в тексте над полкой ( вид обработки и дополнительные указания )
  parRougham.rPar.cText2 = 2;  // Количество строк в тексте под полкой ( базовая длина по ГОСТ 2789-73 ) ( не более двух строк )
  parRougham.rPar.cText3 = 1;  // Количество строк в тексте под полкой ( условное обозначение направления неровностей ) ( не более одной строки )  
 
  // Режим, когда тексты задаются массивом модельных строк текста
  parRougham.rPar.style = INDICATIN_TEXT_LINE_ARR; // Стиль текста ( 0 - то стиль умолчательный, INDICATIN_TEXT_LINE_ARR - массив TEXT_LINE_ARR )
    
  TextLineParam parTextLine; // Структура параметров строки текста  
  
  parTextLine.style     = 0;                               // Номер стиля строки текста
  parTextLine.pTextItem = CreateArray( TEXT_ITEM_ARR, 0 ); // Массив неопределенной длины компонент строки текста

  TextItemFontT parItemFont; // Структура параметров шрифта компоненты строки текста
  memset( &parItemFont, 0, sizeof( parItemFont ) );

  TextItemParamT parTextItem; // Структура параметров компоненты строки текста  
  
  parTextItem.tip    = 0;           // SPECIAL_SYMBOL, FONT_SYMBOL, FRACTION_TYPE, SUM_TYPE или 0
  parTextItem.font   = parItemFont; // Параметры шрифта компоненты строки текста
  parTextItem.iSNumb = 0;           // Номер спецсимвола, символа из произвольного фонта или тип отрисовки дроби или выражения типа суммы или 0

  parRougham.rPar.pText = CreateArray( TEXT_LINE_ARR, 0 ); // Массив неопределенной длины строк текста шероховатости
  // Различают 4 разных текста для шероховатости ( строки лежат в следующей последовательности ) 
  // 1. текст над знаком ( параметры шер-ти по ГОСТ 2789-73 )
  // 2. текст над полкой ( вид обр-ки и доп, указания )   
  // 3. текст под полкой ( базовая длина по ГОСТ 2789-73 ) 
  // 4. текст под полкой ( усл.обозн.направления неровностей )
  // Если cText0 = 0 или cText1 = 0 или cText2 = 0 или cText3 = 0, то соответствующий текст в обозначении шероховатости отсутствует

  // Заполнение массива строк текста шероховатости
  _tcscpy_s( parTextItem.s, _T("00_1") );   
  AddArrayItem( parTextLine.pTextItem, -1, &parTextItem, sizeof( parTextItem ) );
  AddArrayItem( parRougham.rPar.pText, -1, &parTextLine, sizeof( parTextLine ) );
  ClearArray( parTextLine.pTextItem ); // Очистить массив
  _tcscpy_s( parTextItem.s, _T("00_2") );   
  AddArrayItem( parTextLine.pTextItem, -1, &parTextItem, sizeof( parTextItem ) );
  AddArrayItem( parRougham.rPar.pText, -1, &parTextLine, sizeof( parTextLine ) );
  ClearArray( parTextLine.pTextItem ); // Очистить массив
  _tcscpy_s( parTextItem.s, _T("11_1") );   
  AddArrayItem( parTextLine.pTextItem, -1, &parTextItem, sizeof( parTextItem ) );
  AddArrayItem( parRougham.rPar.pText, -1, &parTextLine, sizeof( parTextLine ) );
  ClearArray( parTextLine.pTextItem ); // Очистить массив
  _tcscpy_s( parTextItem.s, _T("11_2") );   
  AddArrayItem( parTextLine.pTextItem, -1, &parTextItem, sizeof( parTextItem ) );
  AddArrayItem( parRougham.rPar.pText, -1, &parTextLine, sizeof( parTextLine ) );
  ClearArray( parTextLine.pTextItem ); // Очистить массив
  _tcscpy_s( parTextItem.s, _T("22_1") ); 
  AddArrayItem( parTextLine.pTextItem, -1, &parTextItem, sizeof( parTextItem ) );
  AddArrayItem( parRougham.rPar.pText, -1, &parTextLine, sizeof( parTextLine ) );
  ClearArray( parTextLine.pTextItem ); // Очистить массив
  _tcscpy_s( parTextItem.s, _T("22_2") );   
  AddArrayItem( parTextLine.pTextItem, -1, &parTextItem, sizeof( parTextItem ) );
  AddArrayItem( parRougham.rPar.pText, -1, &parTextLine, sizeof( parTextLine ) );
  ClearArray( parTextLine.pTextItem ); // Очистить массив
  _tcscpy_s( parTextItem.s, _T("33_1") );
  AddArrayItem( parTextLine.pTextItem, -1, &parTextItem, sizeof( parTextItem ) );
  AddArrayItem( parRougham.rPar.pText, -1, &parTextLine, sizeof( parTextLine ) );  
   
  /*
  // Режим, когда тексты задаются массивом строк символов
  parRougham.rPar.style = 0; // Стиль текста ( 0 - то стиль умолчательный, INDICATIN_TEXT_LINE_ARR - массив TEXT_LINE_ARR )    
  parRougham.rPar.pText = CreateArray( CHAR_STR_ARR_T, 0 ); // Массив неопределенной длины строк текста шероховатости
  // Различают 4 разных текста для шероховатости ( строки лежат в следующей последовательности ) 
  // 1. текст над знаком ( параметры шер-ти по ГОСТ 2789-73 )
  // 2. текст над полкой ( вид обр-ки и доп, указания )   
  // 3. текст под полкой ( базовая длина по ГОСТ 2789-73 ) 
  // 4. текст под полкой ( усл.обозн.направления неровностей )
  // Если cText0 = 0 или cText1 = 0 или cText2 = 0 или cText3 = 0, то соответствующий текст в обозначении шероховатости отсутствует
  
  // Заполнение массива строк текста шероховатости
  AddArrayItem( parRougham.rPar.pText, -1, _T("00_1"), 5 );
  AddArrayItem( parRougham.rPar.pText, -1, _T("00_2"), 5 );
  AddArrayItem( parRougham.rPar.pText, -1, _T("11_1"), 5 );
  AddArrayItem( parRougham.rPar.pText, -1, _T("11_2"), 5 );
  AddArrayItem( parRougham.rPar.pText, -1, _T("22_1"), 5 );
  AddArrayItem( parRougham.rPar.pText, -1, _T("22_2"), 5 );
  AddArrayItem( parRougham.rPar.pText, -1, _T("33_1"), 5 );
  */

  // Создание шероховатости
  reference rRough = Rough( &parRougham );
 
  // Подсветить полученный объект
  LightObj( rRough, 1 );
  MessageT( _T("Снять выделение объекта") );
  LightObj( rRough, 0 );

  // Режим, когда тексты задаются массивом модельных строк текста
  // Удалить динамические массивы
  DeleteArray( parRougham.rPar.pText ); // Массив строк текста 
  DeleteArray( parTextLine.pTextItem ); // Массив компонент строки текста
  
  /* 
  // Режим, когда тексты задаются массивом строк символов 
  // Удалить динамический массив строк текста 
  DeleteArray( parRougham.rPar.pText ); 
  */
}


//-------------------------------------------------------------------------------
// Линия выноски
// ---
void DrawLeader()
{
  TextLineParam parTextLine; // Структура параметров строки текста

  parTextLine.style = 0; // Номер стиля строки текста
  parTextLine.pTextItem = CreateArray( TEXT_ITEM_ARR, 0 ); // Массив неопределенной длины компонент строки текста

  TextItemFontT parItemFont; // Структура параметров шрифта компоненты строки текста
  memset( &parItemFont, 0, sizeof( parItemFont ) );

  TextItemParamT parTextItem; // Структура параметров компоненты строки текста  
  
  parTextItem.tip    = 0;           // SPECIAL_SYMBOL, FONT_SYMBOL, FRACTION_TYPE, SUM_TYPE или 0
  parTextItem.font   = parItemFont; // Параметры шрифта компоненты строки текста
  parTextItem.iSNumb = 0;           // Номер спецсимвола, символа из произвольного фонта или тип отрисовки дроби или выражения типа суммы или 0

  LeaderParam parLeader; // Структура параметров линии-выноски 
  memset( &parLeader, 0, sizeof( parLeader ) );
  
  parLeader.x         = 50; // Координаты базовой точки ( начало полки )
  parLeader.y         = 50;             
  parLeader.arrowType = 1;  // Тип стрелки ( 0 - стрелка отсутствует, 1 - точка, 2 - стрелка,
                            // 3 - верхняя половина стрелки, 4 - нижняя половина стрелки )
  parLeader.dirX      = 1;  // Направление полки по X ( 0 - нет полки, -1 - полка влево,
                            // 1 - полка вправо, 2 - полка вверх, 3 - полка вниз )
  parLeader.signType  = 0;  // Тип знака ( 0 - знак отсутствует, 1 - знак склеивания, 2 - знак пайки, 3 - знак сшивания,
                            // 4 - знак соединения внахлестку металлическими скобами,
                            // 5 - знак углового соединения металлическими скобами, 6 - знак монтажного шва )
  parLeader.around    = 0;  // Знак обработки по контуру ( 0 - выключен, 1 - включен )
  parLeader.cText0    = 1;  // Количество строк текста над полкой ( 0 - текст отсутствует )
  parLeader.cText1    = 1;  // Количество строк текста под полкой ( 0 - текст отсутствует )
  parLeader.cText2    = 1;  // Количество строк текста над ножкой ( не более 1 строки ) ( 0 - текст отсутствует )
  parLeader.cText3    = 1;  // Количество строк текста под ножкой ( не более 1 строки ) ( 0 - текст отсутствует )

  parLeader.pTextline = CreateArray( TEXT_LINE_ARR, 0 ); // Массив неопределенной длины строк текста

  // Заполнение массива строк текста линии выноски
  _tcscpy_s( parTextItem.s, _T("00_1") );   
  AddArrayItem( parTextLine.pTextItem, -1, &parTextItem, sizeof( parTextItem ) );
  AddArrayItem( parLeader.pTextline, -1, &parTextLine, sizeof( parTextLine ) );
  ClearArray( parTextLine.pTextItem ); // Очистить массив
  _tcscpy_s( parTextItem.s, _T("11_1") ); 
  AddArrayItem( parTextLine.pTextItem, -1, &parTextItem, sizeof( parTextItem ) );
  AddArrayItem( parLeader.pTextline, -1, &parTextLine, sizeof( parTextLine ) );
  ClearArray( parTextLine.pTextItem ); // Очистить массив
  _tcscpy_s( parTextItem.s, _T("22_1") );   
  AddArrayItem( parTextLine.pTextItem, -1, &parTextItem, sizeof( parTextItem ) );
  AddArrayItem( parLeader.pTextline, -1, &parTextLine, sizeof( parTextLine ) );
  ClearArray( parTextLine.pTextItem ); // Очистить массив
  _tcscpy_s( parTextItem.s, _T("33_1") );
  AddArrayItem( parTextLine.pTextItem, -1, &parTextItem, sizeof( parTextItem ) );
  AddArrayItem( parLeader.pTextline, -1, &parTextLine, sizeof( parTextLine ) );

  parLeader.pPolyline  = CreateArray( POLYLINE_ARR, 0 ); // Массив неопределенной длины ответвлений линии выноски
  reference rArPoint = CreateArray( POINT_ARR, 0 ); // Массив неопределенной длины математических точек

  MathPointParam parMathPoint; // Структура параметров математической точки
  
  // Заполнение массива ответвлений линии выноски
  parMathPoint.x = 10; // Координата точки
  parMathPoint.y = 10; 
  AddArrayItem( rArPoint, -1, &parMathPoint, sizeof( parMathPoint ) );
  AddArrayItem( parLeader.pPolyline, -1, &rArPoint, sizeof( rArPoint ) );
  parMathPoint.x = 30; // Координата точки
  parMathPoint.y = 10;
  ClearArray( rArPoint ); // Очистить массив 
  AddArrayItem( rArPoint, -1, &parMathPoint, sizeof( parMathPoint ) );
  AddArrayItem( parLeader.pPolyline, -1, &rArPoint, sizeof( rArPoint ) );

  // Создание линии выноски
  reference rLeader = Leader( &parLeader );
  
  // Подсветить полученный объект
  LightObj( rLeader, 1 );
  MessageT( _T("Снять выделение объекта") );
  LightObj( rLeader, 0 );
 
  // Удалить динамические массивы
  DeleteArray( parLeader.pTextline ); // Массив строк текста 
  DeleteArray( parLeader.pPolyline ); // Массив ответвлений линии выноски
  DeleteArray( rArPoint );            // Массив математических точек
}


//-------------------------------------------------------------------------------
// Позиционная линия выноски
// --- 
void DrawPosLeader()
{  
  PosLeaderParam parPosLeader; // Структура параметров позиционной линии-выноски
  memset( &parPosLeader, 0, sizeof( parPosLeader ) );

  parPosLeader.x         = 50; // Координаты базовой точки ( начало полки )
  parPosLeader.y         = 50;             
  parPosLeader.arrowType = 1;  // Тип стрелки ( 0 - стрелка отсутствует, 1 - точка, 2 - стрелка,
                               // 3 - верхняя половина стрелки, 4 - нижняя половина стрелки )
  parPosLeader.dirX      = -1; // Направление полки по X ( 0 - нет полки, -1 - полка влево,
                               // 1 - полка вправо, 2 - полка вверх, 3 - полка вниз )

  // Режим, когда тексты задаются массивом модельных строк текста
  parPosLeader.style = INDICATIN_TEXT_LINE_ARR; // Стиль текста ( 0 - то стиль умолчательный, INDICATIN_TEXT_LINE_ARR - массив TEXT_LINE_ARR )
  
  TextLineParam parTextLine; // Структура параметров строки текста
  
  parTextLine.style     = 0;                               // Номер стиля строки текста
  parTextLine.pTextItem = CreateArray( TEXT_ITEM_ARR, 0 ); // Массив неопределенной длины компонент строки текста

  TextItemFontT  parItemFont; // Структура параметров шрифта компоненты строки текста
  memset( &parItemFont, 0, sizeof( parItemFont ) );

  TextItemParamT parTextItem; // Структура параметров компоненты строки текста
  
  parTextItem.tip    = 0;           // SPECIAL_SYMBOL, FONT_SYMBOL, FRACTION_TYPE, SUM_TYPE или 0
  parTextItem.font   = parItemFont; // Параметры шрифта компоненты строки текста
  parTextItem.iSNumb = 0;           // Номер спецсимвола, символа из произвольного фонта или тип отрисовки дроби или выражения типа суммы или 0

  parPosLeader.pText = CreateArray( TEXT_LINE_ARR, 0 ); // Массив неопределенной длины строк текста
 
  // Заполнение массива строк линии выноски
  _tcscpy_s( parTextItem.s, _T("1") );   
  AddArrayItem( parTextLine.pTextItem, -1, &parTextItem, sizeof( parTextItem ) );
  AddArrayItem( parPosLeader.pText, -1, &parTextLine, sizeof( parTextLine ) );
  ClearArray( parTextLine.pTextItem ); // Очистить массив
  _tcscpy_s( parTextItem.s, _T("2") );  
  AddArrayItem( parTextLine.pTextItem, -1, &parTextItem, sizeof( parTextItem ) );
  AddArrayItem( parPosLeader.pText, -1, &parTextLine, sizeof( parTextLine ) );

  /*
  // Режим, когда тексты задаются массивом строк символов 
  parPosLeader.style = 0; // Стиль текста ( 0 - то стиль умолчательный, INDICATIN_TEXT_LINE_ARR - массив TEXT_LINE_ARR )                   
  
  parPosLeader.pText = CreateArray( CHAR_STR_ARR, 0 ); // Массив неопределенной длины строк текста
  
  // Заполнение массива строк текста 
  AddArrayItem( parPosLeader.pText, -1, _T("1"), 3 );
  AddArrayItem( parPosLeader.pText, -1, _T("2"), 3 );
  */

  parPosLeader.pPolyline  = CreateArray( POLYLINE_ARR, 0 ); // Массив неопределенной длины ответвлений линии выноски
  reference rArPoint = CreateArray( POINT_ARR, 0 ); // Массив неопределенной длины математических точек

  MathPointParam parMathPoint; // Структура параметров математической точки
  
  // Заполнение массива ответвлений линии выноски
  parMathPoint.x = 10; // Координата точки
  parMathPoint.y = 10; 
  AddArrayItem( rArPoint, -1, &parMathPoint, sizeof( parMathPoint ) );
  AddArrayItem( parPosLeader.pPolyline, -1, &rArPoint, sizeof( rArPoint ) );
  parMathPoint.x = 30; // Координата точки
  parMathPoint.y = 10;
  ClearArray( rArPoint ); // Очистить массив 
  AddArrayItem( rArPoint, -1, &parMathPoint, sizeof( parMathPoint ) );
  AddArrayItem( parPosLeader.pPolyline, -1, &rArPoint, sizeof( rArPoint ) );

  // Создание линии выноски
  reference rPositionLeader = PositionLeader( &parPosLeader );
 
  // Подсветить полученный объект
  LightObj( rPositionLeader, 1 );
  MessageT( _T("Снять выделение объекта") );
  LightObj( rPositionLeader, 0 );
  
  // Удалить динамические массивы
  DeleteArray( parPosLeader.pPolyline ); // Массив ответвлений линии выноски
  DeleteArray( rArPoint );               // Массив математических точек    
  
  // Режим, когда тексты задаются массивом модельных строк текста
  DeleteArray( parPosLeader.pText ); // Массив строк текста 
  DeleteArray( parTextLine.pTextItem );   // Массив компонент строки текста 
   
  /* 
  // Режим, когда тексты задаются массивом строк символов 
  // Удалить динамический массив строк текста 
  DeleteArray( parPosLeader.rPar.pText ); 
  */
}


//-------------------------------------------------------------------------------
// Клеймение 
// --- 
void DrawBrandLeader()
{  
  BrandLeaderParam  parBrandLeader; // Указатель на временную группу границ штриховки
  memset( &parBrandLeader, 0, sizeof( parBrandLeader ) );
  
  parBrandLeader.cText0    = 1;  // Количество строк текста в знаке ( не более 1 строки ) ( 0 - текст отсутствует )
  parBrandLeader.cText1    = 1;  // Количество строк текста над ножкой ( не более 1 строки ) ( 0 - текст отсутствует )
  parBrandLeader.cText2    = 1;  // Количество строк текста под ножкой ( не более 1 строки ) ( 0 - текст отсутствует )
  parBrandLeader.x         = 50; // Координаты базовой точки ( начало полки )
  parBrandLeader.y         = 50;   
  parBrandLeader.arrowType = 1;  // Тип стрелки ( 0 - стрелка отсутствует, 1 - точка, 2 - стрелка,
                                 // 3 - верхняя половина стрелки, 4 - нижняя половина стрелки )
  parBrandLeader.dirX      = -1; // Направление полки по X ( 0 - нет полки, -1 - полка влево,
                                 // 1 - полка вправо, 2 - полка вверх, 3 - полка вниз )
  
  // Режим, когда тексты задаются массивом модельных строк текста
  parBrandLeader.style1 = INDICATIN_TEXT_LINE_ARR; // Стиль текста ( 0 - то стиль умолчательный, INDICATIN_TEXT_LINE_ARR - массив TEXT_LINE_ARR )    

  TextLineParam parTextLine; // Структура параметров строки текста
  
  parTextLine.style     = 0;                               // Номер стиля строки текста
  parTextLine.pTextItem = CreateArray( TEXT_ITEM_ARR, 0 ); // Массив неопределенной длины компонент строки текста

  TextItemFontT  parItemFont; // Структура параметров шрифта компоненты строки текста
  memset( &parItemFont, 0, sizeof( parItemFont ) );

  TextItemParamT parTextItem; // Структура параметров компоненты строки текста
  
  parTextItem.tip    = 0;           // SPECIAL_SYMBOL, FONT_SYMBOL, FRACTION_TYPE, SUM_TYPE или 0
  parTextItem.font   = parItemFont; // Параметры шрифта компоненты строки текста
  parTextItem.iSNumb = 0;           // Номер спецсимвола, символа из произвольного фонта или тип отрисовки дроби или выражения типа суммы или 0
  
  parBrandLeader.pText = CreateArray( TEXT_LINE_ARR, 0 ); // Массив неопределенной длины строк текста

  // Заполнение массива строк клеймения
  _tcscpy_s( parTextItem.s, _T("п.11") );   
  AddArrayItem( parTextLine.pTextItem, -1, &parTextItem, sizeof( parTextItem ) );
  AddArrayItem( parBrandLeader.pText, -1, &parTextLine, sizeof( parTextLine ) );
  ClearArray( parTextLine.pTextItem ); // Очистить массив
  _tcscpy_s( parTextItem.s, _T("Ну") );   
  AddArrayItem( parTextLine.pTextItem, -1, &parTextItem, sizeof( parTextItem ) );
  AddArrayItem( parBrandLeader.pText, -1, &parTextLine, sizeof( parTextLine ) );
  ClearArray( parTextLine.pTextItem ); // Очистить массив
  _tcscpy_s( parTextItem.s, _T("Tу") );   
  AddArrayItem( parTextLine.pTextItem, -1, &parTextItem, sizeof( parTextItem ) );
  AddArrayItem( parBrandLeader.pText, -1, &parTextLine, sizeof( parTextLine ) );

  /*
  // Режим, когда тексты задаются массивом строк символов 
  parBrandLeader.style1 = 0; // Стиль текста ( 0 - то стиль умолчательный, INDICATIN_TEXT_LINE_ARR - массив TEXT_LINE_ARR )    
  
  parBrandLeader.pText = CreateArray( CHAR_STR_ARR_T, 0 ); // Массив неопределенной длины строк текста

  // Заполнение массива строк текста 
  AddArrayItem( parBrandLeader.pText, -1, _T("п.11"), 5 );
  AddArrayItem( parBrandLeader.pText, -1, _T("Ну"), 3 );
  AddArrayItem( parBrandLeader.pText, -1, _T("Ту"), 3 );
  */

  parBrandLeader.pPolyline  = CreateArray( POLYLINE_ARR, 0 ); // Массив неопределенной длины ответвлений линии выноски
  reference rArPoint = CreateArray( POINT_ARR, 0 ); // Массив неопределенной длины математических точек

  MathPointParam parMathPoint; // Структура параметров математической точки

  // Заполнение массива ответвлений линии выноски
  parMathPoint.x = 10; // Координата точки
  parMathPoint.y = 10; 
  AddArrayItem( rArPoint, -1, &parMathPoint, sizeof( parMathPoint ) );
  AddArrayItem( parBrandLeader.pPolyline, -1, &rArPoint, sizeof( rArPoint ) );
  parMathPoint.x = 30; // Координата точки
  parMathPoint.y = 10;
  ClearArray( rArPoint ); // Очистить массив 
  AddArrayItem( rArPoint, -1, &parMathPoint, sizeof( parMathPoint ) );
  AddArrayItem( parBrandLeader.pPolyline, -1, &rArPoint, sizeof( rArPoint ) );

  // Создание клеймения
  reference rBrandLeader = BrandLeader( &parBrandLeader );
 
  // Подсветить полученный объект
  LightObj( rBrandLeader, 1 );
  MessageT( _T("Снять выделение объекта") );
  LightObj( rBrandLeader, 0 );
  
  // Удалить динамические массивы
  DeleteArray( parBrandLeader.pPolyline ); // Массив ответвлений линии выноски
  DeleteArray( rArPoint );                 // Массив математических точек    
  
  // Режим, когда тексты задаются массивом модельных строк текста
  DeleteArray( parBrandLeader.pText );  // Массив строк текста 
  DeleteArray( parTextLine.pTextItem ); // Массив компонент строки текста 
   
  /* 
  // Режим, когда тексты задаются массивом строк символов 
  // Удалить динамический массив строк текста 
  DeleteArray( parBrandLeader.pText ); 
  */
}


//-------------------------------------------------------------------------------
// Маркирование
// --- 
void DrawMarkerLeader()
{  
  MarkerLeaderParam  parMarkerLeader; // Структура параметров линии-выноски для обозначения маркировки
  memset( &parMarkerLeader, 0, sizeof( parMarkerLeader ) );
  
  parMarkerLeader.cText0    = 1;  // Количество строк текста в знаке ( не более 1 строки ) ( 0 - текст отсутствует )
  parMarkerLeader.cText1    = 1;  // Количество строк текста над ножкой ( не более 1 строки ) ( 0 - текст отсутствует )
  parMarkerLeader.cText2    = 1;  // Количество строк текста под ножкой ( не более 1 строки ) ( 0 - текст отсутствует )
  parMarkerLeader.x         = 50; // Координаты базовой точки ( начало полки )
  parMarkerLeader.y         = 50;
  parMarkerLeader.arrowType = 2;  // Тип стрелки ( 0 - стрелка отсутствует, 1 - точка, 2 - стрелка,
                                  // 3 - верхняя половина стрелки, 4 - нижняя половина стрелки )
 
  // Режим, когда тексты задаются массивом модельных строк текста
  parMarkerLeader.style1 = INDICATIN_TEXT_LINE_ARR; // Стиль текста ( 0 - то стиль умолчательный, INDICATIN_TEXT_LINE_ARR - массив TEXT_LINE_ARR )     

  TextLineParam parTextLine; // Структура параметров строки текста
  
  parTextLine.style     = 0;                               // Номер стиля строки текста
  parTextLine.pTextItem = CreateArray( TEXT_ITEM_ARR, 0 ); // Массив неопределенной длины компонент строки текста

  TextItemFontT  parItemFont; // Структура параметров шрифта компоненты строки текста
  memset( &parItemFont, 0, sizeof( parItemFont ) );

  TextItemParamT parTextItem; // Структура параметров компоненты строки текста
  parTextItem.tip    = 0;           // SPECIAL_SYMBOL, FONT_SYMBOL, FRACTION_TYPE, SUM_TYPE или 0
  parTextItem.font   = parItemFont; // Параметры шрифта компоненты строки текста
  parTextItem.iSNumb = 0;           // Номер спецсимвола, символа из произвольного фонта или тип отрисовки дроби или выражения типа суммы или 0

  parMarkerLeader.pText = CreateArray( TEXT_LINE_ARR, 0 ); // Массив неопределенной длины строк текста

  _tcscpy_s( parTextItem.s, _T("п.11") );  
  AddArrayItem( parTextLine.pTextItem, -1, &parTextItem, sizeof( parTextItem ) );
  AddArrayItem( parMarkerLeader.pText, -1, &parTextLine, sizeof( parTextLine ) );
  ClearArray( parTextLine.pTextItem ); // Очистить массив
  _tcscpy_s( parTextItem.s, _T("Ну") );  
  AddArrayItem( parTextLine.pTextItem, -1, &parTextItem, sizeof( parTextItem ) );
  AddArrayItem( parMarkerLeader.pText, -1, &parTextLine, sizeof( parTextLine ) );
  ClearArray( parTextLine.pTextItem ); // Очистить массив
  _tcscpy_s( parTextItem.s, _T("Tу") ); 
  AddArrayItem( parTextLine.pTextItem, -1, &parTextItem, sizeof( parTextItem ) );
  AddArrayItem( parMarkerLeader.pText, -1, &parTextLine, sizeof( parTextLine ) );

  /* 
  // Режим, когда тексты задаются массивом строк символов 
  parMarkerLeader.style1 = 0; // Стиль текста ( 0 - то стиль умолчательный, INDICATIN_TEXT_LINE_ARR - массив TEXT_LINE_ARR )    
  
  parMarkerLeader.pText = CreateArray( CHAR_STR_ARR_T, 0 ); // Массив неопределенной длины строк текста

  // Заполнение массива строк текста 
  AddArrayItem( parMarkerLeader.pText, -1, _T("п.11"), 5 );
  AddArrayItem( parMarkerLeader.pText, -1, _T("Ну"), 3 );
  AddArrayItem( parMarkerLeader.pText, -1, _T("Ту"), 3 );
  */
  
  parMarkerLeader.pPolyline  = CreateArray( POLYLINE_ARR, 0 ); // Массив неопределенной длины ответвлений линии выноски
  reference rArPoint = CreateArray( POINT_ARR, 0 ); // Массив неопределенной длины математических точек

  MathPointParam parMathPoint; // Структура параметров математической точки

  // Заполнение массива ответвлений линии выноски
  parMathPoint.x = 10; // Координата точки
  parMathPoint.y = 10; 
  AddArrayItem( rArPoint, -1, &parMathPoint, sizeof( parMathPoint ) );
  AddArrayItem( parMarkerLeader.pPolyline, -1, &rArPoint, sizeof( rArPoint ) );
  parMathPoint.x = 30; // Координата точки
  parMathPoint.y = 10;
  ClearArray( rArPoint ); // Очистить массив 
  AddArrayItem( rArPoint, -1, &parMathPoint, sizeof( parMathPoint ) );
  AddArrayItem( parMarkerLeader.pPolyline, -1, &rArPoint, sizeof( rArPoint ) );

  // Создание маркирования
  reference rMarkerLeader = MarkerLeader( &parMarkerLeader );
  
  // Подсветить полученный объект
  LightObj( rMarkerLeader, 1 );
  MessageT( _T("Снять выделение объекта") );
  LightObj( rMarkerLeader, 0 );
  
  // Удалить динамические массивы
  DeleteArray( parMarkerLeader.pPolyline ); // Массив ответвлений линии выноски
  DeleteArray( rArPoint );                  // Массив математических точек    
  
  // Режим, когда тексты задаются массивом модельных строк текста
  DeleteArray( parMarkerLeader.pText ); // Массив строк текста 
  DeleteArray( parTextLine.pTextItem ); // Массив компонент строки текста 
   
  /* 
  // Режим, когда тексты задаются массивом строк символов 
  // Удалить динамический массив строк текста 
  DeleteArray( parMarkerLeader.pText ); 
  */
}


//-------------------------------------------------------------------------------
// Обозначение базы
// ---
void DrawBase()
{
  BaseParamT basePar; // Структура параметров обозначения базы
  memset( &basePar, 0, sizeof( basePar ) );
  
  basePar.x1 = 50; // Координаты базовой точки ( начало ножки )
  basePar.y1 = 50;             
  basePar.x2 = 50; // Координаты конечной точки ножки
  basePar.y2 = 30;             
  _tcscpy_s( basePar.str, _T("ABC") ); // Надпись

  // Создание обозначения базы
  reference rBase = BaseT( &basePar );
  
  // Подсветить полученный объект
  LightObj( rBase, 1 );
  MessageT( _T("Снять выделение объекта") );
  LightObj( rBase, 0 );
}


//-------------------------------------------------------------------------------
// Линия разреза/cечения
// --- 
void DrawCutLine()
{
  CutLineParamT parCutLine; // Структура параметров линии разреза/сечения
  memset( &parCutLine, 0, sizeof( parCutLine ) );
  
  parCutLine.right = 1; // Признак положения стрелок ( 0 - слева, 1 - справа по направлению ломаной ) 
  _tcscpy_s ( parCutLine.str, _T("A$;1$") ); // Надпись
  parCutLine.x1 = 30; // Координаты надписи у первого участка
  parCutLine.y1 = 65;
  parCutLine.x2 = 95; // Координаты надписи у второго участка
  parCutLine.y2 = 15;
  parCutLine.pMathPoint = CreateArray( POINT_ARR, 0 ); // Массив неопределенной длины математических точек
 
  MathPointParam parMathPoint; // Структура параметров математической точки
  
  // Первая точка
  parMathPoint.x = 50; 
  parMathPoint.y = 50;
  AddArrayItem( parCutLine.pMathPoint, -1, &parMathPoint, sizeof( parMathPoint ) );
  // Вторая  точка
  parMathPoint.x = 50;
  parMathPoint.y = 30;
  AddArrayItem( parCutLine.pMathPoint, -1, &parMathPoint, sizeof( parMathPoint ) );
  // Третья точка
  parMathPoint.x = 80; 
  parMathPoint.y = 30;
  AddArrayItem( parCutLine.pMathPoint, -1, &parMathPoint, sizeof( parMathPoint ) );

  // Создание линии разреза/cечения
  reference rCutLine = CutLineT( &parCutLine );
  
  // Подсветить полученный объект
  LightObj( rCutLine, 1 );
  MessageT( _T("Снять выделение объекта") );
  LightObj( rCutLine, 0 );
  
  // Удалить динамический массив математических точек
  DeleteArray( parCutLine.pMathPoint );   
}


//-------------------------------------------------------------------------------
// Стрелка вида
// ---
void DrawViewPointer()
{
  ViewPointerParamT parViewPointer; // Структура параметров стрелки направления взгляда
  memset( &parViewPointer, 0, sizeof( parViewPointer ) );
  
  parViewPointer.x1 = 50; // Координаты вершины стрелки
  parViewPointer.y1 = 50;             
  parViewPointer.x2 = 20, // Координаты конечной точки стрелки
  parViewPointer.y2 = 50;             
  parViewPointer.xt = 25; // Координаты текста
  parViewPointer.yt = 55;             
  
  // Режим, когда тексты задаются в виде динамического массива компонент текста
  parViewPointer.type = 1; // Способ задания надписи на линии ( 0 - текст в виде строки, 1 - динамический массив компонент текста )
  parViewPointer.pTextItem = CreateArray( TEXT_ITEM_ARR, 0 );
 
  TextItemParamT parTextItem; // Структура параметров компоненты текста
  memset( &parTextItem, 0, sizeof( parTextItem ) );
   
  // Заполнение массива компонент текста
  _tcscpy_s( parTextItem.s, _T("AAA") ); 
  AddArrayItem( parViewPointer.pTextItem, -1, &parTextItem, sizeof( parTextItem ) );
  
  /*
  // Режим, когда тексты задаются в виде строки
  parViewPointer->type = 0; // Способ задания надписи на линии ( 0 - текст в виде строки, 1 - динамический массив компонент текста )
  _tcscpy( parViewPointer->str, _T("AAA") ); // Надпись
  */

  reference rViewPointer = ViewPointerT( &parViewPointer );// параметры линейного размера
  
  // Подсветить полученный объект
  LightObj( rViewPointer, 1 );
  MessageT( _T("Снять выделение объекта") );
  LightObj( rViewPointer, 0 );
  
  // Режим, когда тексты задаются в виде динамического массива компонент текста
  // Удалить динамический массив компонент текста
  DeleteArray( parViewPointer.pTextItem );   
}


//-------------------------------------------------------------------------------
// Диаметральный размер 
// --- 
void DrawDiamDim()
{
  RDimParam parRDim; // Структура параметров диаметрального и обычного радиального размера
  memset( &parRDim, 0, sizeof( parRDim ) );
  
  // Параметры изображения размера
  parRDim.dPar.textPos  = 75;  // Параметр отрисовки текста или длина ножки - аннотационный ( не зависит от масштаба )
  parRDim.dPar.pt1      = 2;   // Тип стрелки у первой выносной линии ( 0 - стрелки нет, 1 - внутри, 2 - снаружи, 3 - засечка, 4 - точка )
  parRDim.dPar.pt2      = 2;   // Тип стрелки у второй выносной линии ( 0 - стрелки нет, 1 - внутри, 2 - снаружи, 3 - засечка, 4 - точка )
  parRDim.dPar.shelfDir = 1;   // Наличие выносной полки ( 0 - нет выносной полки, -1 - полка направлена влево,
                               // 1 - полка направлена вправо, 2 - полка направлена вверх, 3 - полка направлена вниз )
  parRDim.dPar.ang      = -30; // Угол наклона ножки выносной полки
  
  // Параметры размерной надписи
  parRDim.tPar.style   = 0; // Cтиль текста размера, ( 0 - стиль по умолчанию )
  parRDim.tPar.sign    = 0; // Номер условного значка перед номиналом ( 0 - нет значка, 1 - диаметр, 2 - квадрат,
                            // 3 - радиус, > 3 - номер значка из шрифта Symbol type A )
  // Признаки размерной надписи ( набор битовых полей, 0 - ручное задание ) 
  // Должны быть строки PREFIX, номинал ставится auto ( ставить не нужно ), TOLERANCE, отклонения
  // ставятся auto ( ставить не нужно ), UNIT, SUFFIX ( 4 строки )
  parRDim.tPar.bitFlag = _AUTONOMINAL|_PREFIX|_DEVIATION|_UNIT|_SUFFIX; 
  parRDim.tPar.pText   = CreateArray( CHAR_STR_ARR_T, 0 ); // Динамический массив строк
  
  // Добавить элементы динамического массива
  AddArrayItem( parRDim.tPar.pText, -1, _T("prefix"), 8 );
  AddArrayItem( parRDim.tPar.pText, -1, _T("+0.5"),  5 );
  AddArrayItem( parRDim.tPar.pText, -1, _T("-0.5"),  5 );
  AddArrayItem( parRDim.tPar.pText, -1, _T("mm"),     5 );
  AddArrayItem( parRDim.tPar.pText, -1, _T("suffics"), 13 );

  // Привязка диаметрального размера
  parRDim.sPar.xc  = 50; // Координаты центра
  parRDim.sPar.yc  = 50; 
  parRDim.sPar.rad = 70; // Радиус
  
  // Создание диаметрального размера
  reference rDiamDimension = DiamDimension( &parRDim );
 
  GetObjParam( rDiamDimension,    // Указатель на графический объект
               &parRDim,          // Указатель на структуру параметров
               sizeof( parRDim ), // Размер структуры параметров
               ALLPARAM_T );        // Тип считывания параметров
               
  // Функция для отображения параметров размера ( 0 - линейный размер, 1 - угловой размер,
  // 2 - диаметральный и радиальный размер, 3 - радиальный размер c изломом ) 
  ShowDimParam( _T("Cоздание размера"), &parRDim, ALLPARAM_T, 2 );

  // Параметры изображения размера
  parRDim.dPar.textPos  = 0; // Параметр отрисовки текста или длина ножки - аннотационный ( не зависит от масштаба )
  parRDim.dPar.pt1      = 1; // Тип стрелки у первой выносной линии ( 0 - стрелки нет, 1 - внутри, 2 - снаружи, 3 - засечка, 4 - точка )
  parRDim.dPar.pt2      = 1; // Тип стрелки у второй выносной линии ( 0 - стрелки нет, 1 - внутри, 2 - снаружи, 3 - засечка, 4 - точка )
  parRDim.dPar.shelfDir = 0; // Наличие выносной полки ( 0 - нет выносной полки, -1 - полка направлена влево,
                             // 1 - полка направлена вправо, 2 - полка направлена вверх, 3 - полка направлена вниз )
  parRDim.dPar.ang      = 0; // Угол наклона ножки выносной полки
  
  // Параметры размерной надписи
  parRDim.tPar.sign    = 1; // Номер условного значка перед номиналом ( 0 - нет значка, 1 - диаметр, 2 - квадрат,
                            // 3 - радиус, > 3 - номер значка из шрифта Symbol type A )
 
  // Привязка диаметрального размера
  parRDim.sPar.xc  = 30; // Координаты центра
  parRDim.sPar.yc  = 30; 
  parRDim.sPar.rad = 20; // Радиус

  SetObjParam( rDiamDimension,    // Указатель на графический объект
               &parRDim,          // Указатель на структуру параметров
               sizeof( parRDim ), // Размер структуры параметров
               ALLPARAM_T );        // Тип считывания параметров  
  
  GetObjParam( rDiamDimension,    // Указатель на графический объект
               &parRDim,          // Указатель на структуру параметров
               sizeof( parRDim ), // Размер структуры параметров
               ALLPARAM_T );        // Тип считывания параметров
               
  // Функция для отображения параметров размера ( 0 - линейный размер, 1 - угловой размер,
  // 2 - диаметральный и радиальный размер, 3 - радиальный размер c изломом )
  ShowDimParam( _T("Редактирование размера"), &parRDim, ALLPARAM_T, 2 );
  
  // Удалить динамический массив строк
  DeleteArray( parRDim.tPar.pText );  
}


//-------------------------------------------------------------------------------
// Радиальный размер
// --- 
void DrawRadDimt()
{
  RDimParam parRDim; // Структура параметров диаметрального и обычного радиального размера
  memset( &parRDim, 0, sizeof( parRDim ) );
  
  // Параметры изображения размера
  parRDim.dPar.textPos  = 75; // Параметр отрисовки текста или длина ножки - аннотационный ( не зависит от масштаба )
  parRDim.dPar.pt1      = 2;  // Тип стрелки у первой выносной линии ( 0 - стрелки нет, 1 - внутри, 2 - снаружи, 3 - засечка, 4 - точка )
  parRDim.dPar.pt2      = 1;  // Тип размерной линии ( 0 - размер от центра, 1 - не от центра )
  parRDim.dPar.shelfDir = 1;  // Наличие выносной полки ( 0 - нет выносной полки, -1 - полка направлена влево,
                              // 1 - полка направлена вправо, 2 - полка направлена вверх, 3 - полка направлена вниз )
  parRDim.dPar.ang      = 30; // Угол наклона ножки выносной полки
  
  // Параметры размерной надписи
  parRDim.tPar.style   = 0; // Cтиль текста размера, ( 0 - стиль по умолчанию )
  parRDim.tPar.sign    = 0; // Номер условного значка перед номиналом ( 0 - нет значка, 1 - диаметр, 2 - квадрат,
                            // 3 - радиус, > 3 - номер значка из шрифта Symbol type A )
  // Признаки размерной надписи ( набор битовых полей, 0 - ручное задание ) 
  // Должны быть строки PREFIX, номинал ставится auto ( ставить не нужно ), TOLERANCE, отклонения
  // ставятся auto ( ставить не нужно ), UNIT, SUFFIX ( 4 строки )
  parRDim.tPar.bitFlag = _AUTONOMINAL|_PREFIX|_DEVIATION|_UNIT|_SUFFIX; 
  parRDim.tPar.pText   = CreateArray( CHAR_STR_ARR_T, 0 ); // Динамический массив строк
  
  // Добавить элементы динамического массива
  AddArrayItem( parRDim.tPar.pText, -1, _T("prefix"), 8 );
  AddArrayItem( parRDim.tPar.pText, -1, _T("+0.5"),  5 );
  AddArrayItem( parRDim.tPar.pText, -1, _T("-0.5"),  5 );
  AddArrayItem( parRDim.tPar.pText, -1, _T("mm"),     5 );
  AddArrayItem( parRDim.tPar.pText, -1, _T("suffics"), 13 );

  // Привязка радиального размера
  parRDim.sPar.xc  = 50; // Координаты центра
  parRDim.sPar.yc  = 50; 
  parRDim.sPar.rad = 70; // Радиус
  
  // Создание радиального размера
  reference rDiamDimension = RadDimension( &parRDim );
 
  GetObjParam( rDiamDimension,    // Указатель на графический объект
               &parRDim,          // Указатель на структуру параметров
               sizeof( parRDim ), // Размер структуры параметров
               ALLPARAM_T );        // Тип считывания параметров
               
  // Функция для отображения параметров размера ( 0 - линейный размер, 1 - угловой размер,
  // 2 - диаметральный и радиальный размер, 3 - радиальный размер c изломом ) 
  ShowDimParam( _T("Cоздание размера"), &parRDim, ALLPARAM_T, 2 );

  // Параметры изображения размера
  parRDim.dPar.textPos  = 0; // Параметр отрисовки текста или длина ножки - аннотационный ( не зависит от масштаба )
  parRDim.dPar.pt1      = 1; // Тип стрелки у первой выносной линии ( 0 - стрелки нет, 1 - внутри, 2 - снаружи, 3 - засечка, 4 - точка )
  parRDim.dPar.pt2      = 1; // Тип размерной линии ( 0 - размер от центра, 1 - не от центра )
  parRDim.dPar.shelfDir = 0; // Наличие выносной полки ( 0 - нет выносной полки, -1 - полка направлена влево,
                             // 1 - полка направлена вправо, 2 - полка направлена вверх, 3 - полка направлена вниз )
  parRDim.dPar.ang      = 0; // Угол наклона ножки выносной полки
  
  // Параметры размерной надписи 
  parRDim.tPar.sign = 3; // Номер условного значка перед номиналом ( 0 - нет значка, 1 - диаметр, 2 - квадрат,
                         // 3 - радиус, > 3 - номер значка из шрифта Symbol type A )
 
  // Привязка радиального размера
  parRDim.sPar.xc  = 30; // Координаты центра
  parRDim.sPar.yc  = 30; 
  parRDim.sPar.rad = 30; // Радиус

  SetObjParam( rDiamDimension,    // Указатель на графический объект
               &parRDim,          // Указатель на структуру параметров
               sizeof( parRDim ), // Размер структуры параметров
               ALLPARAM_T );        // Тип считывания параметров  
  
  GetObjParam( rDiamDimension,    // Указатель на графический объект
               &parRDim,          // Указатель на структуру параметров
               sizeof( parRDim ), // Размер структуры параметров
               ALLPARAM_T );        // Тип считывания параметров
               
  // Функция для отображения параметров размера ( 0 - линейный размер, 1 - угловой размер,
  // 2 - диаметральный и радиальный размер, 3 - радиальный размер c изломом )
  ShowDimParam( _T("Редактирование размера"), &parRDim, ALLPARAM_T, 2 );
  
  // Удалить динамический массив строк
  DeleteArray( parRDim.tPar.pText );  

}


//-------------------------------------------------------------------------------
// Радиальный размер c изломом
// --- 
void DrawRadBreakDimt()
{
  RBreakDimParam parRBreakDim; // Структура параметров радиального размера с изломом
  memset( &parRBreakDim, 0, sizeof( parRBreakDim ) );
  
  // Параметры изображения размера
  parRBreakDim.dPar.pt  = 2;  // Тип стрелки ( 0 - стрелки нет, 1 - внутри, 2 - снаружи, 3 - засечка, 4 - точка )
  parRBreakDim.dPar.ang = 30; // Угол
  parRBreakDim.dPar.pb  = 20; // Длина излома
  
  // Параметры размерной надписи
  parRBreakDim.tPar.style   = 0; // Cтиль текста размера, ( 0 - стиль по умолчанию )
  parRBreakDim.tPar.sign    = 0; // Номер условного значка перед номиналом ( 0 - нет значка, 1 - диаметр, 2 - квадрат,
                                 // 3 - радиус, > 3 - номер значка из шрифта Symbol type A )
  // Признаки размерной надписи ( набор битовых полей, 0 - ручное задание ) 
  // Должны быть строки PREFIX, номинал ставится auto ( ставить не нужно ), TOLERANCE, отклонения
  // ставятся auto ( ставить не нужно ), UNIT, SUFFIX ( 4 строки )
  parRBreakDim.tPar.bitFlag = _AUTONOMINAL|_PREFIX|_DEVIATION|_UNIT|_SUFFIX; 
  parRBreakDim.tPar.pText   = CreateArray( CHAR_STR_ARR_T, 0 ); // Динамический массив строк
  
  // Добавить элементы динамического массива
  AddArrayItem( parRBreakDim.tPar.pText, -1, _T("prefix"), 8 );
  AddArrayItem( parRBreakDim.tPar.pText, -1, _T("+0.5"),  5 );
  AddArrayItem( parRBreakDim.tPar.pText, -1, _T("-0.5"),  5 );
  AddArrayItem( parRBreakDim.tPar.pText, -1, _T("mm"),     5 );
  AddArrayItem( parRBreakDim.tPar.pText, -1, _T("suffics"), 13 );

  // Привязка радиального размера
  parRBreakDim.sPar.xc  = 50; // Координаты центра
  parRBreakDim.sPar.yc  = 50; 
  parRBreakDim.sPar.rad = 70; // Радиус
  
  // Создание радиального размера
  reference rRadBreakDimension = RadBreakDimension( &parRBreakDim );
 
  GetObjParam( rRadBreakDimension,     // Указатель на графический объект
               &parRBreakDim,          // Указатель на структуру параметров
               sizeof( parRBreakDim ), // Размер структуры параметров
               ALLPARAM_T );             // Тип считывания параметров
               
  // Функция для отображения параметров размера ( 0 - линейный размер, 1 - угловой размер,
  // 2 - диаметральный и радиальный размер, 3 - радиальный размер c изломом ) 
  ShowDimParam( _T("Cоздание размера"), &parRBreakDim, ALLPARAM_T, 3 );

  // Параметры изображения размера
  parRBreakDim.dPar.pt  = 1;  // Тип стрелки ( 0 - стрелки нет, 1 - внутри, 2 - снаружи, 3 - засечка, 4 - точка )
  parRBreakDim.dPar.pb  = 10; // Длина излома
  
  // Параметры размерной надписи
  parRBreakDim.tPar.sign = 3; // Номер условного значка перед номиналом ( 0 - нет значка, 1 - диаметр, 2 - квадрат,
                              // 3 - радиус, > 3 - номер значка из шрифта Symbol type A )
 
  // Привязка радиального размера
  parRBreakDim.sPar.xc  = 30; // Координаты центра
  parRBreakDim.sPar.yc  = 30; 
  parRBreakDim.sPar.rad = 40; // Радиус 
 
  SetObjParam( rRadBreakDimension,     // Указатель на графический объект
               &parRBreakDim,          // Указатель на структуру параметров
               sizeof( parRBreakDim ), // Размер структуры параметров
               ALLPARAM_T );             // Тип считывания параметров 
 
  GetObjParam( rRadBreakDimension,      // Указатель на графический объект
               &parRBreakDim,           // Указатель на структуру параметров
               sizeof( parRBreakDim ),  // Размер структуры параметров
               ALLPARAM_T );              // Тип считывания параметров
               
  // Функция для отображения параметров размера ( 0 - линейный размер, 1 - угловой размер,
  // 2 - диаметральный и радиальный размер, 3 - радиальный размер c изломом )
  ShowDimParam( _T("Редактирование размера"), &parRBreakDim, ALLPARAM_T, 3 );
  
  // Удалить динамический массив строк
  DeleteArray( parRBreakDim.tPar.pText ); 
}
