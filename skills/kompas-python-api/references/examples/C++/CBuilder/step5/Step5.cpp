//////////////////////////////////////////////////////////////////////////////// 
// 
// step5.cpp - Редактирование
// 
// 1.  Трансформация объекта по матрице        - DrawTransform
// 2.  Копирование объекта                     - DrawCopy
// 3.  Симметрия объекта                       - DrawSymmetry
// 4.  Редактирование допуска формы            - EditTolerance
// 5.  Редактирование таблицы                  - EditTable
// 6.  Взять тексты граф и редактировать штамп - EditStamp
// 7.  Получить текст ТТ                       - GetTextTT
// 8.  Редактирование техничеческих требований - ChangeTechnicalDemand
// 9.  Вставка фрагмента                       - ShowInsertFragment
// 10. Работа с библиотекой фрагментов         - EditFragmentLibrary
// 11. Вставка фрагмента россыпью              - ShowInsertFragment1
// 12. Редактирование таблиц                   - EditTable1
// 13. Редактирование допуска формы            - EditTolerance1
// 
////////////////////////////////////////////////////////////////////////////////
#include <vcl.h>
#pragma hdrstop

#include <tchar.h>

#include <math.h>
#include <stdio.h>

#include "libtool.h"

#include "step5.rh"


//------------------------------------------------------------------------------
// в Win32 линкуется SDK/lib/kAPI2D5bc.lib
// в x64 линкуется SDK/lib64/kAPI2D5bc.a
// ---
#pragma comment(lib, "kAPI2D5bc")

//-------------------------------------------------------------------------------
// Задать идентификатор ресурсов
// ---
extern "C" unsigned int __export __stdcall LIBRARYID()
{
  return IDR_LIBID;
}


//-------------------------------------------------------------------------------
// Описания используемых функций
// ---
void DrawTransform();
void DrawCopy();
void DrawSymmetry();
void EditTolerance();
void EditTable();
void EditStamp();
void GetTextTT();
void ShowInsertFragment ();
void ShowInsertFragment1 ();
void EditFragmentLibrary();
void ChangeTechnicalDemand ();
void EditTable1();
void EditTolerance1();


//-------------------------------------------------------------------------------
// Головная функция библиотеки
// ---
extern "C" void __export __stdcall LIBRARYENTRY( unsigned int comm )
{
  if ( ksGetCurrentDocument( 1 ) )
  {
    switch ( comm )
    {
      case 1  : DrawTransform();         break; // Трансформация объекта по матрице
      case 2  : DrawCopy();              break; // Копирование объекта
      case 3  : DrawSymmetry();          break; // Симметрия объекта
      case 4  : EditTolerance();         break; // Редактирование допуска формы
      case 5  : EditTable();             break; // Редактирование таблицы
      case 6  : EditStamp();             break; // Взять тексты граф и редактировать штамп
      case 7  : GetTextTT();             break; // Получить текст ТТ
      case 8  : ChangeTechnicalDemand(); break; // Редактирование техничеческих требований
      case 9  : ShowInsertFragment();    break; // Вставка фрагмента
      case 10 : EditFragmentLibrary();   break; // Работа с библиотекой фрагментов
      case 11 : ShowInsertFragment1();   break; // Вставка фрагмента россыпью
      case 12 : EditTable1();            break; // Редактирование таблиц
      case 13 : EditTolerance1();        break; // Редактирование допуска формы
    }
  }
  else
		ErrorT( _T("Документ не активизирован или\nне является листом/фрагментом") );
}


//-------------------------------------------------------------------------------
// Трансформация объектов
// ---
void DrawTransform()
{
  // Создание объекта для трансформации
  reference rObject;
  
  // Создание группы объектов, type - тип группы ( 0 - определяет модельный, 1 - временный )
  rObject = NewGroup( 0 );
    // Стороны квадрата
    LineSeg( 30, 30, 60, 30, 1 );
    LineSeg( 60, 30, 60, 60, 1 );
    LineSeg( 60, 60, 30, 60, 1 );
    LineSeg( 30, 60, 30, 30, 1 );
    // Штриховка квадрата
    Hatch( 0, 45, 2, 0, 0, 0 );
      LineSeg( 30, 30, 60, 30, 1 );
      LineSeg( 60, 30, 60, 60, 1 );
      LineSeg( 60, 60, 30, 60, 1 );
      LineSeg( 30, 60, 30, 30, 1 );
    EndObj(); // Завершить создание штриховки
  EndGroup(); // Завершить создание группы объектов
 
  /*
  // Создать простой объект - дугу 
  rObject = ArcBy3Points( 20, 60, 40, 70, 20, 80, 1 );
  */

  /*
  // Вид номер 1 - должен быть создан ранее
  if ( !( rObject = GetViewReference( 1 ) ) )
  {
    MessageBoxResult(); // Выдать сообщение об ошибке на экран 
    return;
  }
  */
 
  /*
  // Слой номер 1 должен быть создан ранее
  if ( !( rObject = GetLayerReference( 1 ) ) )
  {
    MessageBoxResult(); // Выдать сообщение об ошибке на экран 
    return;
  }
  */
 
  /*
  // Трансформация группы селектирования
  rObject = NULL;
  */
 
	MessageT( _T("Cоздали матрицу 20, 20, 45, 2") );

	Mtr( 20, 20, 45, 2 );    // Матрица преобразования координат ( 20 по оси OX, 20 по оси OY, поворот на 45 градусов, маштаб 2:1 )
	TransformObj( rObject ); // Преобразование объекта по установленной матрице
	DeleteMtr();             // Отключение матрицы преобразования координат

	MessageT( _T("Вернем обратно") );

  Mtr( -20, -20, 0, 1 );   // Матрица преобразования координат ( -20 по оси OX, -20 по оси OY )
  TransformObj( rObject ); // Преобразование объекта по установленной матрице
  DeleteMtr();             // Отключение матрицы преобразования координат

  Mtr( 0, 0, 0, 0.5 );     // Матрица преобразования координат ( маштаб 1:2 )
  TransformObj( rObject ); // Преобразование объекта по установленной матрице
  DeleteMtr();             // Отключение матрицы преобразования координат

  Mtr( 0, 0, -45, 1 );     // Матрица преобразования координат ( поворот на -45 градусов )
  TransformObj( rObject ); // Преобразование объекта по установленной матрице
  DeleteMtr();             // Отключение матрицы преобразования координат
}


//-------------------------------------------------------------------------------
// Пример использования симметрии объектов
// ---
void DrawSymmetry()
{
  // Создание группы с использованием симметрии. Так как при использовании орерации
  // симметрии группа не закрыта, объекты созданные в результате симметрии попадают в
  // группу. В результате группа будет состоять из 8 объектов
  
  // Создание группы объектов, type - тип группы ( 0 - определяет модельный, 1 - временный )
  reference rGroup = NewGroup( 0 );
    LineSeg( 20, 10, 20, 30, 1 );
    LineSeg( 20, 30, 40, 30, 1 );
    LineSeg( 40, 30, 40, 10, 1 );
    LineSeg( 40, 10, 20, 10, 1 );
    // Осевая симметрия объекта
    ksSymmetryObj( rGroup, // Указатель на объект
                   80, 10, // Первая точка оси
                   80, 20, // Вторая точка оси
                   1 );    // Режим копирования ( 0 - исходные объекты удаляются, 1 - исходные объекты оставляются )
  EndGroup(); // Завершить создание группы объектов
}


//-------------------------------------------------------------------------------
// Пример использования копии объектов
// ---
void DrawCopy()
{
	ViewParamT parView; // Структура параметров вида
 
  parView.x     = 20;                  // Точка привязки вида
  parView.y     = 60;
  parView.scale = 1;                   // Масштаб вида
  parView.ang   = 0;                   // Угол поворота вида
  parView.color = RGB( 10, 20, 10 );   // Цвет вида в активном состоянии
  parView.state = stACTIVE;            // Состояние вида
	_tcscpy( parView.name, _T("User view") ); // Имя вида
  // Создадим вид с номером 5, масштабом 0.5, под углом 45 гр.
  int number = 5;
	reference rView = CreateSheetViewT( &parView, &number );

  LineSeg( 20, 10, 20, 30, 1 );
  LineSeg( 20, 30, 40, 30, 1 );
  LineSeg( 40, 30, 40, 10, 1 );
  LineSeg( 40, 10, 20, 10, 1 );

  // Копируем вид ( для вида точки задаются в листовых координатах )
  CopyObj( rView,  // Указатель на объект
           20, 60, // Базовая точка
           40, 80, // Новое положение базовой точки
           1,      // Масштаб
           0 );    // Угол поворота в градусах 
}


//-------------------------------------------------------------------------------
// Пример редактирования допуска формы
// ---
void EditTolerance()
{
  // Поиск объекта для редактирования

  // Структура параметров запроса к системе
	RequestInfoT info;
  memset( &info, 0, sizeof( info ) );

  // Строка или идентификатор приглашения  
	info.prompt = _T("Укажите допуск формы");
  
  // Координаты точки ввода  
  double x, y; 

  // Интерактивный ввод точки или команды
	if ( CursorExT( &info, &x, &y, 0, NULL ) )
  {
    // Найти ближайший к заданной точке объект вида
    reference rObject = FindObj( x, y,  // Координаты точки
                                 1e6 ); // Размер стороны квадрата-ловушки с центром в точке x,y
    if ( rObject )
    {
      // Узнать тип полученного графического объекта
      int type = GetObjParam( rObject, 0, 0, 0 );   
      if ( type == TOLERANCE_OBJ ) 
      {
        // Открыть допуск формы для редактирования
        ksOpenTolerance( rObject );

				ToleranceParam parTolerance; // Параметры допуска формы
        
        // Получить параметры допуска формы
				GetObjParam( rObject,                // Указатель на графический объект
                     &parTolerance,          // Указатель на структуру параметров
                     sizeof( parTolerance ), // Размер структуры параметров
										 ALLPARAM_T );             // Тип считывания параметров
                   
				TCHAR buf[255];
				_stprintf( buf, _T("tBase = %d, style = %d, расположение - %s,\nx = %4.2f, y = %4.2f"),
								 parTolerance.tBase, parTolerance.style, parTolerance.type ? _T("вертикальное") : _T("горизонтальное"), parTolerance.x, parTolerance.y );
				MessageT( buf );

        TextLineParam parTextLine; // Структура параметров строки текста
				TextItemParamT parTextItem; // Структура параметров компоненты строки текста

        // В цикле будем брать все существующие ячейки
        unsigned int number; // Номер ячейки
        // Функция выдает текст ячейки и смещается на следующую ячейку
        while ( ksGetToleranceColumnText( &number, &parTextLine ) )
        {
					_stprintf( buf, _T("number = %d, style = %d"), number, parTextLine.style );
					MessageT( buf );

          // Количество элементов в массиве
          int count = GetArrayCount( parTextLine.pTextItem );

          // Цикл по компонентам строки
          for ( int i = 0; i < count; i++ )
          {
            // Получить значение элемента массива
            GetArrayItem( parTextLine.pTextItem, i, &parTextItem, sizeof( parTextItem ) );

            // Тип компоненты строки ( SPECIAL_SYMBOL, FONT_SYMBOL, FRACTION_TYPE, SUM_TYPE или 0 )
            if ( !parTextItem.tip )
							_stprintf( buf, _T("i = %d, font.height = %4.2f,\ns = %s,\nfont.fontName = %s,\nfont.bitVector = %d"),
                       i, parTextItem.font.height, parTextItem.s, parTextItem.font.fontName, parTextItem.font.bitVector );
            else
							_stprintf( buf, _T("i = %d, tip = %d, iSNumb = %d"), i, parTextItem.tip, parTextItem.iSNumb );
						MessageT( buf );
          }
        }

        // Заменим параметры допуска формы
        parTolerance.x += 10;
        parTolerance.y += 10;
        SetObjParam(  rObject,                 // Указатель на графический объект
                      &parTolerance,           // Указатель на структуру параметров
                      sizeof( parTolerance  ), // Размер структуры параметров
											ALLPARAM_T );              // Тип считывания параметров

        // Разделить ячейку таблицы или допуска формы
        ksDivideTableItem( 3,   // Индекс ячейки
                           1,   // Расположение ( 1 - вертикально 0 - горизонтально )
                           2 ); // Стиль линии ( 0 - невидимая, 1 - основная, 2 - тонкая,	7 - утолщенная )
        // Изменить стиль ребра таблицы или допуска формы
        ksSetTableBorderStyle( 1,   // Индекс ячейки
                               2,   // Тип ребра ( 0 - левое,	1 - правое,	2 - верхнеее,	3 - нижнее )
                               1 ); // Стиль линии ( 0 - невидимая, 1 - основная, 2 - тонкая,	7 - утолщенная )
        // Очистить ячейку таблицы или допуска формы
        ksClearTableColumnText( 0 ); // Индекс ячейки, если 0 очищаем всю таблицу
        // Добавить новые строки
        ColumnNumber( 2 );
					TextLineT ( NEW_LINE, 0, 0, _T("Вторая ячейка") );
        ColumnNumber( 4 );
					TextLineT ( NEW_LINE, 0, 0, _T("4") );
  
        EndObj(); // Закрыть допуск формы для редактирования
      }
      else
				ErrorT( _T("Объект не допуск формы") );
    }
    else
			ErrorT( _T("Нет объекта") );
  }
}


//-------------------------------------------------------------------------------
// Пример редактирования допуска формы
// ---
void EditTolerance1()
{
  // Поиск объекта для редактирования

  // Структура параметров запроса к системе
	RequestInfoT info;
  memset( &info, 0, sizeof( info ) );

  // Строка или идентификатор приглашения  
	info.prompt = _T("Укажите допуск формы");
  
  // Координаты точки ввода  
  double x, y; 

  // Интерактивный ввод точки или команды
	if ( CursorExT( &info, &x, &y, 0, NULL ) )
  {
    // Найти ближайший к заданной точке объект вида
    reference rObject = FindObj( x, y,  // Координаты точки
                                 1e6 ); // Размер стороны квадрата-ловушки с центром в точке x,y
    if ( rObject )
    {
      // Узнать тип полученного графического объекта
      int type = GetObjParam( rObject, 0, 0, 0 );   
      if ( type == TOLERANCE_OBJ ) 
      {
        // Открыть допуск формы для редактирования
        ksOpenTolerance( rObject );       
        
        TextLineParam parTextLine; // Структура параметров строки текста
				TextItemParamT parTextItem; // Структура параметров компоненты строки текста
                  
        // В цикле будем брать все существующие ячейки
        unsigned int number; // Номер ячейки
        // Функция выдает текст ячейки и смещается на следующую ячейку
        while ( ksGetToleranceColumnText( &number, &parTextLine ) ) 
        {
          // Количество элементов в массиве
          int count = GetArrayCount( parTextLine.pTextItem );
          
          // Цикл по компонентам строки
          for ( int i = 0; i < count; i++ ) 
          {
            // Получить значение элемента массива
            GetArrayItem( parTextLine.pTextItem, i, &parTextItem, sizeof( parTextItem ) );
            
            // Если в ячейке что-то есть, то заменим текст на "!!!"
						if ( *parTextItem.s )
            {
							_tcscat( parTextItem.s, _T("!!!") );
              SetArrayItem( parTextLine.pTextItem, i, &parTextItem, sizeof( parTextItem ) );
            }
          }  
          // Установить текст ячейки допуска формы         
          ksSetToleranceColumnText( number, &parTextLine ); 
        }
        EndObj(); // Закрыть допуск формы для редактирования
      }
      else
				ErrorT( _T("Объект не допуск формы") );
		}
		else
			ErrorT( _T("Нет объекта") );
  }
}


//-------------------------------------------------------------------------------
// Пример редактирования таблицы
// ---
void EditTable()
{
  // Поиск объекта для редактирования

  // Структура параметров запроса к системе
	RequestInfoT info;
  memset( &info, 0, sizeof( info ) );

  // Строка или идентификатор приглашения
	info.prompt = _T("Укажите таблицу");

  // Координаты точки ввода 
  double x, y;
  
  // Интерактивный ввод точки или команды
	if ( CursorExT( &info, &x, &y, 0, NULL ) )
  {
    // Найти ближайший к заданной точке объект вида
    reference rObject = FindObj( x, y,  // Координаты точки
                                 1e6 ); // Размер стороны квадрата-ловушки с центром в точке x,y
    if ( rObject )
    {
      // Узнать тип полученного графического объекта
      int type = GetObjParam( rObject, 0, 0, 0 );   
      if ( type == TABLE_OBJ )
      {
        // Открыть таблицу для редактирования
        ksOpenTable( rObject );

				TextParam parText;         // Структура параметров текста
        TextLineParam parTextLine; // Структура параметров строки текста
				TextItemParamT parTextItem; // Структура параметров компоненты строки текста

        // В цикле будем брать все существующие ячейки
        unsigned int number; // Номер ячейки
        // Функция выдает текст ячейки и смещается на следующую ячейку        
				while ( ksGetTableColumnText( &number, &parText ) )
        {
					TCHAR buf[255];
					_stprintf( buf, _T("number = %d"), number );
					MessageT( buf );
          
          // Количество элементов в массиве
          int count = GetArrayCount( parText.pTextLine );
     
          // Цикл по строкам
          for ( int i = 0; i < count; i++ )
          {
            // Получить значение элемента массива
            GetArrayItem( parText.pTextLine, i, &parTextLine, sizeof( parTextLine ) );
            
						_stprintf( buf, _T("i = %d style = %d"), i, parTextLine.style );
						MessageT( buf );

            // Количество элементов в массиве
            int count = GetArrayCount( parTextLine.pTextItem );
          
            // Цикл по компонентам строки
            for ( int j = 0; j < count; j++ ) 
            {
              // Получить значение элемента массива
              GetArrayItem( parTextLine.pTextItem, j, &parTextItem, sizeof( parTextItem ) );
            
              // Тип компоненты строки ( SPECIAL_SYMBOL, FONT_SYMBOL, FRACTION_TYPE, SUM_TYPE или 0 )
              if ( !parTextItem.tip )
								_stprintf( buf, _T("j = %d, font.height = %4.2f,\ns = %s,\nfont.fontName = %s,\nfont.bitVector = %d"),
                         j, parTextItem.font.height, parTextItem.s, parTextItem.font.fontName, parTextItem.font.bitVector );
              else
								_stprintf( buf, _T("j = %d, tip = %d, iSNumb = %d"), j, parTextItem.tip, parTextItem.iSNumb );
							MessageT( buf );
            }  
          }
        } 
        
        // Разделить ячейку таблицы или допуска формы
        ksDivideTableItem( 3,   // Индекс ячейки 
                           1,   // Расположение ( 1 - вертикально 0 - горизонтально )
                           2 ); // Стиль линии ( 0 - невидимая, 1 - основная, 2 - тонкая,	7 - утолщенная )                
        // Изменить стиль ребра таблицы или допуска формы  
        ksSetTableBorderStyle( 1,   // Индекс ячейки  
                               2,   // Тип ребра ( 0 - левое,	1 - правое,	2 - верхнеее,	3 - нижнее )
                               1 ); // Стиль линии ( 0 - невидимая, 1 - основная, 2 - тонкая,	7 - утолщенная ) 
        // Очистить ячейку таблицы или допуска формы                       
        ksClearTableColumnText( 0 ); // Индекс ячейки, если 0 очищаем всю таблицу
        // Добавить новые строки
        ColumnNumber( 2 );
					TextT( 0, 0, 0, 5, 1 ,0, _T("Вторая ячейка") );
				ColumnNumber( 4 );
					TextT( 0, 0, 0, 5, 1 ,0, _T("4") );
  
        EndObj(); // Закрыть таблицу для редактирования 
      }
      else
				ErrorT( _T("Объект не таблица") );
    }
    else
			ErrorT( _T("Нет объекта") );
  }
}


//-------------------------------------------------------------------------------
// Пример редактирования таблицы
// ---
void EditTable1()
{
  // Поиск объекта для редактирования

  // Структура параметров запроса к системе
	RequestInfoT info;
  memset( &info, 0, sizeof( info ) );

  // Строка или идентификатор приглашения
	info.prompt = _T("Укажите таблицу");
    
  // Координаты точки ввода  
  double x, y;
 
  // Интерактивный ввод точки или команды
	if ( CursorExT( &info, &x, &y, 0, NULL ) )
  {
    // Найти ближайший к заданной точке объект вида
    reference rObject = FindObj( x, y,  // Координаты точки
                                 1e6 ); // Размер стороны квадрата-ловушки с центром в точке x,y
    if ( rObject )
    {
      // Узнать тип полученного графического объекта
      int type = GetObjParam( rObject, 0, 0, 0 );  
      if ( type == TABLE_OBJ )
      {
        // Открыть таблицу для редактирования
        ksOpenTable( rObject );

        TextParam parText;         // Структура параметров текста
        TextLineParam parTextLine; // Структура параметров строки текста
				TextItemParamT parTextItem; // Структура параметров компоненты строки текста
        
        // В цикле будем брать все существующие ячейки
        unsigned int number; // Номер ячейки
        // Функция выдает текст ячейки и смещается на следующую ячейку        
        while ( ksGetTableColumnText( &number, &parText ) ) 
        {
          // Количество элементов в массиве
          int count = GetArrayCount( parText.pTextLine );
     
          // Цикл по строкам
          for ( int i = 0; i < count; i++ )
          {
            // Получить значение элемента массива
            GetArrayItem( parText.pTextLine, i, &parTextLine, sizeof( parTextLine ) );

            // Количество элементов в массиве
            int count = GetArrayCount( parTextLine.pTextItem );
          
            // Цикл по компонентам строки
            for ( int j = 0; j < count; j++ ) 
            {
              // Получить значение элемента массива
              GetArrayItem( parTextLine.pTextItem, j, &parTextItem, sizeof( parTextItem ) );

              // Если в ячейке что-то есть, то заменим текст на "!!!"
							if ( *parTextItem.s )
              {
								_tcscat( parTextItem.s, _T("!!!") );
                SetArrayItem( parTextLine.pTextItem, j, &parTextItem, sizeof( parTextItem ) );
              }
            }  
            SetArrayItem( parText.pTextLine, i, &parTextLine, sizeof( parTextLine ) );
          }
          // Установить текст ячейки таблицы         
          ksSetTableColumnText( number, &parText ); 
        }  
        EndObj(); // Закрыть таблицу для редактирования 
      }
      else
				ErrorT( _T("Объект не таблица") );
    }
    else
			ErrorT( _T("Нет объекта") );
  }
}


//-------------------------------------------------------------------------------
// Пример взять тексты граф и редактировать штамп
// ---
void EditStamp()
{
  if( OpenStamp() ) // Открыть штамп чертежа/текстового документа
  {
		TextLineParam parTextLine;  // Структура параметров строки текста
		TextItemParamT parTextItem; // Структура параметров компоненты строки текста

    // В цикле будем брать все существующие ячейки
    unsigned int number;   // Номер ячейки
    reference rColumnText; // Ячейка штампа
    // Функция выдает текст ячейки и смещается на следующую ячейку
    while ( 0 != ( rColumnText = GetStampColumnText( &number ) ) )
    {
			TCHAR buf[255];
			_stprintf( buf, _T("number = %d"), number );
			MessageT( buf );

      // Количество элементов в массиве
      int count = GetArrayCount( rColumnText );

      // Цикл по строкам
      for ( int i = 0; i < count; i++ )
      {
        // Получить значение элемента массива
        GetArrayItem( rColumnText, i, &parTextLine, sizeof( parTextLine ) );

				_stprintf( buf, _T("i = %d style = %d"), i, parTextLine.style );
				MessageT( buf );

        // Количество элементов в массиве
        int count = GetArrayCount( parTextLine.pTextItem );

        // Цикл по компонентам строки
        for ( int j = 0; j < count; j++ )
        {
          // Получить значение элемента массива
          GetArrayItem( parTextLine.pTextItem, j, &parTextItem, sizeof( parTextItem ) );

          // Тип компоненты строки ( SPECIAL_SYMBOL, FONT_SYMBOL, FRACTION_TYPE, SUM_TYPE или 0 )
          if ( !parTextItem.tip )
						_stprintf( buf, _T("j = %d, font.height = %4.2f,\ns = %s,\nfont.fontName = %s,\nfont.bitVector = %d"),
                     j, parTextItem.font.height, parTextItem.s, parTextItem.font.fontName, parTextItem.font.bitVector );
          else
						_stprintf( buf, _T("j = %d, tip = %d, iSNumb = %d"), j, parTextItem.tip, parTextItem.iSNumb );
					MessageT( buf );
        }
      }
    }
    // Очистить графу штампа чертежа/текстового документа
    ClearStamp( 0 ); // Индекс ячейки, если 0 очищаем весь штамп
    // Заменим 2-ю графу
    ColumnNumber( 2 );
			TextLineT( NEW_LINE, 0, 0, _T("Графа 2") );

    CloseStamp(); // Закрыть штамп чертежа/текстового документа
  }
  else
		ErrorT( _T("Штамп не найден") );
}


//-------------------------------------------------------------------------------
// Получить текст технических трбований
// ---
void GetTextTT()
{
  // Получить указатель на основную надпись или технические требования или
  // неуказанную шероховатость или текущий вид или спецификацию на листе
  reference rTechnicalDemand = GetReferenceDocumentPart( 1 ); // Определяет какой объект оформления нужно получить
                                                              // ( 0 -на основную надпись, 1 - на технические требования,
                                                              // 2 - на неуказанную шероховатость, 3 - на текущий вид,
                                                              // 4 - на спецификацию на листе )
  if ( rTechnicalDemand ) 
  {
    TechnicalDemandParam parTechnicalDemand; // Структура параметров технических требований
    
    // Получить параметры описания технических трбований
    GetObjParam( rTechnicalDemand, &parTechnicalDemand, sizeof( parTechnicalDemand ), TECHNICAL_DEMAND_PAR );
    
    // Количество элементов в массиве
    int count = GetArrayCount( parTechnicalDemand.pGab );
    
		TCHAR buf[255];
		_stprintf( buf, _T("style = %d, число страниц = %d"), parTechnicalDemand.style, count );
		MessageT( buf );
    
    // Cоздадим массив текстовых строк
    reference rArTextLine = CreateArray( TEXT_LINE_ARR, 0 ) ;
    
    TextLineParam parTextLine; // Структура параметров строки текста
		TextItemParamT parTextItem; // Структура параметров компоненты строки текста
    
    // Пройдемся по листам технических трбований и получим текст
    for ( int i = 0; i < count; i++ ) 
    {
      GetObjParam( rTechnicalDemand, &rArTextLine, sizeof( rArTextLine ), i );
 
      // Количество элементов в массиве
      int count = GetArrayCount( rArTextLine );
     
      // Цикл по строкам
      for ( int j = 0; j < count; j++ )
      {
        // Получить значение элемента массива
        GetArrayItem( rArTextLine, j, &parTextLine, sizeof( parTextLine ) );
            
				_stprintf( buf, _T("j = %d style = %d"), j, parTextLine.style );
				MessageT( buf );

        // Количество элементов в массиве
        int count = GetArrayCount( parTextLine.pTextItem );
          
        // Цикл по компонентам строки
        for ( int k = 0; k < count; k++ ) 
        {
          // Получить значение элемента массива
          GetArrayItem( parTextLine.pTextItem, k, &parTextItem, sizeof( parTextItem ) );
            
					// Тип компоненты строки ( SPECIAL_SYMBOL, FONT_SYMBOL, FRACTION_TYPE, SUM_TYPE или 0 )
					if ( !parTextItem.tip )
						_stprintf( buf, _T("k = %d, font.height = %4.2f,\ns = %s,\nfont.fontName = %s,\nfont.bitVector = %d"),
                     k, parTextItem.font.height, parTextItem.s, parTextItem.font.fontName, parTextItem.font.bitVector );
          else
						_stprintf( buf, _T("k = %d, tip = %d, iSNumb = %d"), k, parTextItem.tip, parTextItem.iSNumb );
					MessageT( buf );
        }  
      }
    }  
    // Очистим массив текстовых строк
    DeleteArray( rArTextLine );
  }
  else
		ErrorT( _T("Технические требования отсутствуют") );
}


//-------------------------------------------------------------------------------
// Редактирование техничеческих требований
// ---
void ChangeTechnicalDemand()
{
  // Получить указатель на основную надпись или технические требования или
  // неуказанную шероховатость или текущий вид или спецификацию на листе
  reference rTechnicalDemand = GetReferenceDocumentPart( 1 ); // Определяет какой объект оформления нужно получить
                                                              // ( 0 -на основную надпись, 1 - на технические требования,
                                                              // 2 - на неуказанную шероховатость, 3 - на текущий вид,
                                                              // 4 - на спецификацию на листе )
  if ( rTechnicalDemand ) 
  {
    TechnicalDemandParam parTechnicalDemand; // Структура параметров технических требований

    // Получить параметры описания технических трбований
    GetObjParam( rTechnicalDemand, &parTechnicalDemand, sizeof( parTechnicalDemand ), TECHNICAL_DEMAND_PAR );

    TCHAR buf[255];
		_stprintf( buf, _T("Число строк = %d"), parTechnicalDemand.strCount );
		MessageT( buf );
      
    // Открываем технические требования на редактирование, технические требования должны быть открыты, чтобы менять тексты
    OpenTechnicalDemand( parTechnicalDemand.pGab,    // Динамический массив листов технических требований, если 0 технические
                                                     // требования размещаются на одной странице автоматически
                         parTechnicalDemand.style ); // Стиль текста для технических требований, если 0 умолчательное значение
      
    TextLineParam parTextLine; // Структура параметров строки текста
    TextItemParamT parTextItem; // Структура параметров компоненты строки текста
    
    // Пройдемся по листам технических трбований и получим текст
    for ( int i = 0; i < parTechnicalDemand.strCount; i++ ) 
    {
      GetObjParam( rTechnicalDemand, &parTextLine, sizeof( parTextLine ), TT_FIRST_STR + i );
 
      // Количество элементов в массиве
      int count = GetArrayCount( parTextLine.pTextItem );
          
      // Цикл по компонентам строки
      for ( int j = 0; j < count; j++ ) 
      {
        // Получить значение элемента массива
        GetArrayItem( parTextLine.pTextItem, j, &parTextItem, sizeof( parTextItem ) );
        
        // Если в ячейке что-то есть, то заменим текст на "!!!"
				if ( *parTextItem.s )
        {
					_tcscat( parTextItem.s, _T("!!!") );
          SetArrayItem( parTextLine.pTextItem, j, &parTextItem, sizeof( parTextItem ) );
        }
      }
      SetObjParam( rTechnicalDemand, &parTextLine, sizeof( parTextLine ), TT_FIRST_STR + i );  
    }      
    CloseTechnicalDemand(); // Закрыть технические требования
  }
  else
		ErrorT( _T("Технические требования отсутствуют") );
}


//-------------------------------------------------------------------------------
// Функция выбора и простановки в текущий документ фрагмента из библиотки фрагментов
// ---
void ShowInsertFragment()
{
  TCHAR libName[255];
	// Выберем библиотеку фрагментов
	if ( ksChoiceFileT( _T("*.lfr"), // Предопределенный тип файла
									 // Фильтр поиска ( если не задан, то формируется автоматически )
									 _T("Библиотки фрагментов( *.lfr )|*.lfr|Все файлы ( *.* )|*.*|"),
									 libName, // Результат выбора
                   255, 1 ) )  // Длина строки выбора
  {
    TCHAR buf[500];
    // Выбрать фрагмент в библиотеке фрагментов
		while ( ksChoiceFragmentFromLibT( libName, buf, 500 ) )
    {
      // Выделим имя вставки
			TCHAR * insertName = _tcsrchr( buf, _T('|') );
			if ( insertName )
      {
				// Подготовим структуры фанома и запросов для Placement
        
        Phantom phantom; // Структура параметров фантома
  
        phantom.phType      = 1; // Тип фантома ( type1, type2, ... type7 )
        phantom.type1.xBase = 0; // Координаты начальной точки группы
        phantom.type1.yBase = 0;
        phantom.type1.scale = 1; // Масштаб
        phantom.type1.gr    = 0; // Указатель на группу
        phantom.type1.ang   = 0; // Угол поворота группы 

        // Определить данные для вставки фрагмента
        reference rDefinitionFragment = FragmentDefinitionT( buf,          // Имя файла фрагмента
                                                            insertName+1, // Имя вставки
                                                            1 );          // Тип вставки ( 0 - взять
                                                                          // в документ, 1 - внешней ссылкой )

        // Во временную группу положим вставку фрагмента, взятую из библиотеки фрагментов
        PlacementParam parPlacement; // Параметры привязки
  
        parPlacement.xBase = 0; // Координаты базовой точки в системе координат вида
        parPlacement.yBase = 0;
        parPlacement.ang   = 0; // Угол поворота в системе координат вида
        parPlacement.scale = 1; // Масштаб
        
        // Создание группы объектов, type - тип группы ( 0 - определяет модельный, 1 - временный )
        phantom.type1.gr = NewGroup( 1 );
          // Вставить ссылку на фрагмент
          reference rInsertFragment = InsertFragment( rDefinitionFragment, // Указатель определения фрагмента
                                                      0,                   // Тип размещения по слоям ( 0 - на свои слои 1 - в текущий слой )
                                                      &parPlacement );     // Параметры привязки
        EndGroup(); // Завершить создание группы объектов
            
        // Координата вставки
        double x = 0, y = 0;

        int comm = 1; // Пришедшая команда
        while ( comm )
        {
          phantom.type1.ang = 0;
          
          // Задание точки, угла или комманды
					comm = PlacementExT( NULL,               // Указатель на структуру параметров запроса к системе
                            &x, &y,             // Координаты введенной точки	
                            &phantom.type1.ang, // Введенный угол
														&phantom, NULL );         // Указатель на структуру управления фантомом, определяющую тип	движения курсора
          
          if ( comm != 0 ) // Поставить в модель
            CopyObj ( rInsertFragment,        // Указатель на графический объект
                      0, 0,                   // Базовая точка объекта
                      x, y,                   // Точка куда копировать
                      1, phantom.type1.ang ); // Масштаб и угол поворота а градусах
        }
        // Очистить группу объектов
        ClearGroup( phantom.type1.gr );
      }
      else
				ErrorT( _T("Имя вставки не определено") );
    }
  }
}


//-------------------------------------------------------------------------------
// Пример работы с библиотекарем фрагментов
// ---
void  EditFragmentLibrary()
{
  TCHAR libName[255];
  
  // Выберем библиотеку фрагментов
	if ( ksChoiceFileT( _T("*.lfr"), // Предопределенный тип файла
									 // Фильтр поиска ( если не задан, то формируется автоматически )
									 _T("Библиотки фрагментов( *.lfr )|*.lfr|Все файлы ( *.* )|*.*|"),
									 libName, // Результат выбора
									 255, 1 ) )  // Длина строки выбора
  {    
    // Структура параметров запроса к системе
    RequestInfoT info;
    memset( &info, 0, sizeof( info ) );
    
    // Строка или идентификатор меню состава команд 
		info.commands = _T("!Новый_фрагмент !Редактировать_фрагмент !Удалить_фрагмент");
  
    int comm = 1; // Пришедшая команда
    while ( comm != -1 )
    {
			WideString strNameFragment;
      TCHAR buf[255];
    
      // Создание меню в диалоговом окне
			comm = CommandWindowT( &info );
      switch ( comm )
      {
        case 1:  // Новый фрагмент
					_tcscpy( buf, _T("Фрагмент") );
					if ( ReadStringT( _T("Введите имя нового фрагмента"), // Строка приглашения
                            buf,                           // Возвращаемая строка
                            255 ) )                        // Допустимая длина строки
          {  
            strNameFragment = libName;
						if ( buf[0] != _T('|') )
							strNameFragment += _T("|");
            strNameFragment += buf;
            comm = 2;
          }
          else
            comm = 0;            
          break;
        case 2 : // Редактировать фрагмент
        case 3 : // Удалить фрагмент
          // Выберем имя фрагмента
					if ( ksChoiceFragmentFromLibT( libName, buf, 255 ) )
            strNameFragment = buf;
					else
            comm = 0;  
          break;
      }

      if ( comm > 0 )
      {
        // Открыть библиотекарь фрагментов
				if ( ksFragmentLibraryW( strNameFragment.c_bstr(), // Имя файла библиотеки фрагментов
																comm ) )                          // Флаг работы с библиотекой ( -1 - закрыть без сохранения,
                                                                  // 0 - закрыть с сохранением, 1 - открыть, 2 - редактировать
                                                                  // фрагмент, 3 - удалить фрагмент из библиотеки, 4 - минимизировать
                                                                  // окно библиотекаря, 5 - создать файл библиотеки фрагментов.
        {
          if ( comm == 2 ) 
          {
						ksFragmentLibraryT( strNameFragment.c_bstr(), 4 ); // Мнимизировать окно библиотекаря
						// Редактируем фрагмент из библиотеки
						TextT( 0, 100, // Точка привязки текста
									0,      // Угол наклона текста
									5,      // Высота текста
									1,      // Сужение текста
									0,      // Свойства строки, которые задаются вкл/выкл
									_T("Редактируем фрагмент из библиотеки") ); // Строка символов

            LineSeg ( 0, 0, 100, 100, 1 );

            // Редактируем фрагмент в интерактивном режиме - после выбора в меню "Сервис"
            // команды "Закончить редактирование фрагмента" возвращаемся в библиотеку
						SystemControlStartT( _T("Закончить редактирование фрагмента") );
						ksFragmentLibraryT( strNameFragment.c_bstr(), 0 ); // Закрыть c сохранением
          }
        }
        else
          MessageBoxResult(); // Выдать сообщение об ошибке на экран 
      }
    } 
  }
}


//-------------------------------------------------------------------------------
// Вставка фрагмента россыпью 
// ---
void ShowInsertFragment1()
{
	TCHAR frwName[255];
  
  // Выберем  фрагмент
	while(  ksChoiceFileT( _T("*.frw"), // Предопределенный тип файла
                        // Фильтр поиска ( если не задан, то формируется автоматически ) 
												_T("фрагменты( *.frw )|*.frw|Все файлы ( *.* )|*.*|"),
                        frwName, // Результат выбора
                        255,     // Длина строки выбора
                        1 ) )    // Окна предварительного просмотра ( - 1 - с подключением
                                 // окна, 0 - без подключения окна предварительного просмотра )
  {
    // Подготовим структуры фанома и запросов для Placement
        
    Phantom phantom; // Структура параметров фантома
  
    phantom.phType      = 1; // Тип фантома ( type1, type2, ... type7 )
    phantom.type1.xBase = 0; // Координаты начальной точки группы
    phantom.type1.yBase = 0;
    phantom.type1.scale = 1; // Масштаб
    phantom.type1.gr    = 0; // Указатель на группу
    phantom.type1.ang   = 0; // Угол поворота группы 
    
    // Во временную группу положим вставку фрагмента, взятую из библиотеки фрагментов
    PlacementParam parPlacement; // Параметры привязки
  
    parPlacement.xBase = 0; // Координаты базовой точки в системе координат вида
    parPlacement.yBase = 0;
    parPlacement.ang   = 0; // Угол поворота в системе координат вида
    parPlacement.scale = 1; // Масштаб
    
    int comm = 1; // Пришедшая команда
    while ( comm )
    {
      // Если нужно вставить несколько фрагментов, группу лучше порождать новую, так как вместе с
      // геометрией могут придти атрибуты, объекты спецификации, стили, которые связаны с геометрией
			phantom.type1.gr = ksReadFragmentToGroupExT( frwName,         // Имя фрагмента
                                                0,               // Тип размещения по слоям ( 0 - на свои слои, 1 - в текущий слой )
                                                &parPlacement, 1 ); // Параметры привязки
     
      // Координаты точки ввода  
      double x =0, y = 0; 
  
      // Задание точки, угла или комманды
			if ( phantom.type1.gr && ( comm = PlacementExT( NULL,               // Указатель на структуру параметров запроса к системе
                                                   &x, &y,             // Координаты введенной точки	
                                                   &phantom.type1.ang, // Введенный угол
                                                   &phantom, NULL ) ) != 0 ) // Указатель на структуру управления фантомом, определяющую тип	движения курсора
      {
        // Cдвигаем группу
        MoveObj( phantom.type1.gr, x, y );
        // Поворачиваем группу
        if ( fabs( phantom.type1.ang ) > 0.001 )
          RotateObj( phantom.type1.gr, x, y, phantom.type1.ang );
      
        // Поставить временную группу в вид
        StoreTmpGroup( phantom.type1.gr );
        // Очистить группу объектов
        ClearGroup( phantom.type1.gr );
      }
      else 
      {
        // Очистить группу объектов 
        if ( phantom.type1.gr )
          ClearGroup( phantom.type1.gr );
        comm = 0;
      }
    }
  }
}