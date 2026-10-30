//////////////////////////////////////////////////////////////////////////////// 
// 
// step2a.cpp - Массив неопределенной длины
// 
// 1. Массив строк                           - StrIndefiniteArray 
// 2. Массив математических точек            - PointIndefiniteArray 
// 3. Массив строк объекта "текст"           - TextIndefiniteArray 
// 4. Массив колонок типа атрибута           - AttrIndefiniteArray 
// 5. Массив полилиний                       - PolyLineArray 
// 6. Массив габаритных прямоугольников      - RectArray
// 7. Массив структур пользователя           - UserDataArray
// 8. Массив экземпляров класса пользователя - UserClassArray
// 
////////////////////////////////////////////////////////////////////////////////
#include <vcl.h>
#pragma hdrstop

#include <tchar.h>

#ifndef __STDIO_H
#include <stdio.h>
#endif

#ifndef __LIBTOOL_H
#include "libtool.h"
#endif

#ifndef __STEP2A_RH
#include "step2a.rh"
#endif 


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
void PointIndefiniteArray();
void TextIndefiniteArray();
void StrIndefiniteArray();
void AttrIndefiniteArray();
void PolyLineArray();
void RectArray();
void UserDataArray();
void UserClassArray();


//-------------------------------------------------------------------------------
// Головная функция библиотеки
// ---
extern "C" void __export __stdcall LIBRARYENTRY( unsigned int comm )
{
  switch ( comm )
	{
    case 1 : StrIndefiniteArray();   break; // Массив строк
    case 2 : PointIndefiniteArray(); break; // Массив математических точек
    case 3 : TextIndefiniteArray();  break; // Массив строк объекта "текст"
    case 4 : AttrIndefiniteArray();  break; // Массив колонок типа атрибута
    case 5 : PolyLineArray();        break; // Массив полилиний
    case 6 : RectArray();            break; // Массив габаритных прямоугольников
    case 7 : UserDataArray();        break; // Массив структур пользователя
    case 8 : UserClassArray();       break; // Массив экземпляров класса пользователя
  }
}


//--------------------------------------------------------------------------
// Массив предназначен для создания и получения параетров параграфа текста, 
// состоящего из   нескольких строк, которые в свою очередь
// состоят из компонент, с разными параметрами
// ( с наклоном, с утолщением, спецзнаки и т. д. )
// ---
void TextIndefiniteArray()
{
	TextItemParamT parTextItem; // Структура параметров компоненты строки текста
	TextLineParam  parTextLine; // Структура параметров строки текста
  
  // Создали массив строк текста
  reference rArTextLine = CreateArray( TEXT_LINE_ARR, 0 );

  // Массив компонент строки текста
  reference rArTextItem = CreateArray( TEXT_ITEM_ARR, 0 );

  // Создаем первую строку текста
  // Создаем 1-ю компоненту текста
  parTextItem.font.height    = 10;   // Высота текста
  parTextItem.font.ksu       = 1;    // Cужение текста
  parTextItem.font.color     = 1000; // Цвет
  parTextItem.font.bitVector = 1;    // Битовый вектор ( наклон, толщина, подчеркивание, тип составной части( дробь, отклонение, выражение типа суммы ) )
	lstrcpy( parTextItem.s, _T("1 компонента 1 строка") ); // Строка компоненты
  // Добавим 1-ю компоненту в массив компонент, элемент добавляется в конец массива
  AddArrayItem( rArTextItem,             // Указатель на массив
                -1,                      // Индекс в массиве
                &parTextItem,            // Указатель на структуру элемента
                sizeof( parTextItem ) ); // Размер структуры элемента
  
  // Создаем 2-ю компоненту текста
  parTextItem.font.height    = 20;   // Высота текста
  parTextItem.font.ksu       = 2;    // Сужение текста
  parTextItem.font.color     = 2000; // Цвет
  parTextItem.font.bitVector = 2;    // Битовый вектор ( наклон, толщина, подчеркивание, тип составной части( дробь, отклонение, выражение типа суммы ) )
	lstrcpy( parTextItem.s, _T("2 компонента 1 строка") ); // Строка компоненты
  // Добавим 2-ю компоненту в массив компонент, элемент добавляется в конец массива
  AddArrayItem( rArTextItem,             // Указатель на массив
                -1,                      // Индекс в массиве
                &parTextItem,            // Указатель на структуру элемента
                sizeof( parTextItem ) ); // Размер структуры элемента
  // 1-я строка текста состоит из двух компонент добавим строку текста в массив строк текста
  parTextLine.style     = 1;           // Номер стиля строки текста	
  parTextLine.pTextItem = rArTextItem; // Указатель на динамический массив компонент строки текста
  // Добавим строку текста, элемент добавляется в конец массива
  AddArrayItem( rArTextLine,             // Указатель на массив
                -1,                      // Индекс в массиве
                &parTextLine,            // Указатель на структуру элемента
                sizeof( parTextLine ) ); // Размер структуры элемента  

  // Очистили массив компонент, чтобы использовать для создания 2-й строки текста
  ClearArray( rArTextItem );

  // Создаем вторую строку текста
  // Создаем 1-ю компоненту текста
  parTextItem.font.height    = 30;   // Высота текста
  parTextItem.font.ksu       = 3;    // Сужение текста
  parTextItem.font.color     = 3000; // Цвет
  parTextItem.font.bitVector = 3;    // Битовый вектор ( наклон, толщина, подчеркивание, тип составной части( дробь, отклонение, выражение типа суммы ) )
	lstrcpy( parTextItem.s, _T("1 компонента 2 строка") ); // Строка компоненты
  // Добавим 1-ю компоненту в массив компонент, элемент добавляется в конец массива
  AddArrayItem( rArTextItem,             // Указатель на массив
                -1,                      // Индекс в массиве
                &parTextItem,            // Указатель на структуру элемента
                sizeof( parTextItem ) ); // Размер структуры элемента    

  // Создаем 2-ю компоненту текста
  parTextItem.font.height    = 40;   // Высота текста
  parTextItem.font.ksu       = 4;    // Сужение текста
  parTextItem.font.color     = 4000; // Цвет
  parTextItem.font.bitVector = 4;    // Битовый вектор ( наклон, толщина, подчеркивание, тип составной части( дробь, отклонение, выражение типа суммы ) )
	lstrcpy( parTextItem.s, _T("2 компонента 2 строка") ); // Строка компоненты
  // Добавим 2-ю компоненту в массив компонент, элемент добавляется в конец массива
  AddArrayItem( rArTextItem,             // Указатель на массив
                -1,                      // Индекс в массиве
                &parTextItem,            // Указатель на структуру элемента
                sizeof( parTextItem ) ); // Размер структуры элемента  
                
  // 2-я строка текста состоит из двух компонент добавим строку текста в массив строк текста
  parTextLine.style     = 2;           // Номер стиля строки текста	
  parTextLine.pTextItem = rArTextItem; // Указатель на динамический массив компонент строки текста
  // Добавим строку текста, элемент добавляется в конец массива
  AddArrayItem( rArTextLine,             // Указатель на массив
                -1,                      // Индекс в массиве
                &parTextLine,            // Указатель на структуру элемента
                sizeof( parTextLine ) ); // Размер структуры элемента  
                
  // Количество элементов в массиве строки
  int count = GetArrayCount( rArTextLine );
	TCHAR buf[255];
	_stprintf( buf, _T("count = %d"), count );
	MessageT( buf );

  // Просмотрим массив строк текста
  // Цикл по строкам текста
  for ( int i = 0; i < count; i++ )
  {
    // Получить значение элемента массива
    GetArrayItem( rArTextLine,             // Указатель на массив
                  i,                       // Индекс в массиве
                  &parTextLine,            // Указатель на структуру элемента
                  sizeof( parTextLine ) ); // Размер структуры элемента  
		_stprintf( buf, _T("i = %d, style = %d"), i, parTextLine.style );
		MessageT( buf );

    // Количество элементов в массиве компонент
    int count1 = GetArrayCount( rArTextItem );
    
    // Цикл по компонентам строки текста
    for ( int j = 0; j < count1; j++ )
    {
      // Получить значение элемента массива
      GetArrayItem( rArTextItem,             // Указатель на массив
                    j,                       // Индекс в массиве
                    &parTextItem,            // Указатель на структуру элемента
                    sizeof( parTextItem ) ); // Размер структуры элемента  
			_stprintf( buf, _T("j = %d, font.height = %4.2f, s = %s"), j, parTextItem.font.height, parTextItem.s );
			MessageT( buf );
    }
  }
  
  // Заменим вторую компоненту у первой строки
  // Получить значение элемента массива
  GetArrayItem( rArTextLine,             // Указатель на массив
                0,                       // Индекс в массиве
                &parTextLine,            // Указатель на структуру элемента
                sizeof( parTextLine ) ); // Размер структуры элемента  
  parTextItem.font.height    = 50;   // Высота текста
  parTextItem.font.ksu       = 1;    // Сужение текста
  parTextItem.font.color     = 1000; // Цвет
  parTextItem.font.bitVector = 1;    // Битовый вектор ( наклон, толщина, подчеркивание, тип составной части( дробь, отклонение, выражение типа суммы ) )
  lstrcpy( parTextItem.s, _T("2 комп. 1 стр.") ); // Строка компоненты
  // Установить значение элемента динамического массива компонент
  SetArrayItem( rArTextItem,             // Указатель на массив
                1,                       // Индекс в массиве
                &parTextItem,            // Указатель на структуру элемента
                sizeof( parTextItem ) ); // Размер структуры элемента  
                
  parTextLine.style = 3; // Номер стиля строки текста	
  // Установить значение элемента динамического массива строк текста
  SetArrayItem( rArTextLine,             // Указатель на массив
                0,                       // Индекс в массиве
                &parTextLine,            // Указатель на структуру элемента
                sizeof( parTextLine ) ); // Размер структуры элемента  

  // Заменим первую компоненту у второй строки
  // Получить значение элемента массива
  GetArrayItem( rArTextLine,             // Указатель на массив
                1,                       // Индекс в массиве
                &parTextLine,            // Указатель на структуру элемента
                sizeof( parTextLine ) ); // Размер структуры элемента  
  parTextItem.font.height    = 60;   // Высота текста
  parTextItem.font.ksu       = 1;    // Сужение текста
  parTextItem.font.color     = 1000; // Цвет
  parTextItem.font.bitVector = 1;    // Битовый вектор ( наклон, толщина, подчеркивание, тип составной части( дробь, отклонение, выражение типа суммы ) )
	lstrcpy( parTextItem.s, _T("1 комп. 2 стр.") ); // Строка компоненты
  // Установить значение элемента динамического массива компонент
  SetArrayItem( rArTextItem,             // Указатель на массив
                0,                       // Индекс в массиве
                &parTextItem,            // Указатель на структуру элемента
                sizeof( parTextItem ) ); // Размер структуры элемента  
                
  parTextLine.style = 4; // Номер стиля строки текста	
  // Установить значение элемента динамического массива строк текста
  SetArrayItem( rArTextLine,             // Указатель на массив
                1,                       // Индекс в массиве
                &parTextLine,            // Указатель на структуру элемента
                sizeof( parTextLine ) ); // Размер структуры элемента  

  // Количество элементов в массиве строки
  count = GetArrayCount( rArTextLine );
  
  // Просмотрим массив строк текста
  // Цикл по строкам текста
  for ( int i = 0; i < count; i++ )
  {
    // Получить значение элемента массива
    GetArrayItem( rArTextLine,             // Указатель на массив
                  i,                       // Индекс в массиве
                  &parTextLine,            // Указатель на структуру элемента
                  sizeof( parTextLine ) ); // Размер структуры элемента  
		_stprintf( buf, _T("i = %d, style = %d"), i, parTextLine.style );
		MessageT( buf );

    // Количество элементов в массиве компонент
    int count1 = GetArrayCount( rArTextItem );
    
    // Цикл по компонентам строки текста
    for ( int j = 0; j < count1; j++ )
    {
      // Получить значение элемента массива
      GetArrayItem( rArTextItem,             // Указатель на массив
                    j,                       // Индекс в массиве
                    &parTextItem,            // Указатель на структуру элемента
                    sizeof( parTextItem ) ); // Размер структуры элемента  
			_stprintf( buf, _T("j = %d, font.height = %4.2f, s = %s"), j, parTextItem.font.height, parTextItem.s );
      MessageT( buf );
    }
  }

  DeleteArray( rArTextItem ); // Удалить динамический массив компонент
  DeleteArray( rArTextLine ); // Удалить динамический массив строк текста
}


//--------------------------------------------------------------------------
// Массив предназначен для хранения математических точек типа MathPointParam
// ---
void PointIndefiniteArray()
{
  MathPointParam parMathPoint; // Структура параметров математической точки    
  
  // Cоздать массив для хранения математических точек
  reference rArMathPoint = CreateArray( POINT_ARR, 0 );
  
  // Наполнить массив математических точек
  parMathPoint.x = 10; 
  parMathPoint.y = 10;
  // Добавим 1-ю точку, элемент добавляется в конец массива
  AddArrayItem( rArMathPoint,             // Указатель на массив
                -1,                       // Индекс в массиве
                &parMathPoint,            // Указатель на структуру элемента
                sizeof( parMathPoint ) ); // Размер структуры элемента    
  
  parMathPoint.x = 20;
  parMathPoint.y = 20;
  // Добавим 2-ю точку, элемент добавляется в конец массива
  AddArrayItem( rArMathPoint,             // Указатель на массив
                -1,                       // Индекс в массиве
                &parMathPoint,            // Указатель на структуру элемента
                sizeof( parMathPoint ) ); // Размер структуры элемента  
                  
  parMathPoint.x = 30;
  parMathPoint.y = 30;
  // Добавим 3-ю точку, элемент добавляется в конец массива
  AddArrayItem( rArMathPoint,             // Указатель на массив
                -1,                       // Индекс в массиве
                &parMathPoint,            // Указатель на структуру элемента
                sizeof( parMathPoint ) ); // Размер структуры элемента    
  
  // Количество элементов в массиве математических точек 
  int count = GetArrayCount( rArMathPoint );
	TCHAR buf[255];
	_stprintf( buf, _T("count = %d"), count );
	MessageT( buf );
 
  // Просмотрим массив математических точек
  for ( int i = 0; i < count; i++ )
  {
    // Получить значение элемента массива
    GetArrayItem( rArMathPoint,             // Указатель на массив
                  i,                        // Индекс в массиве
                  &parMathPoint,            // Указатель на структуру элемента
                  sizeof( parMathPoint ) ); // Размер структуры элемента  
		_stprintf( buf, _T("i = %d, x = %4.2f, y = %4.2f"), i, parMathPoint.x, parMathPoint.y );
		MessageT( buf );
  }
  
  // Заменим параметры 1-го элемента массива математических точек
  parMathPoint.x = 50; 
  parMathPoint.y = 50;
  SetArrayItem( rArMathPoint,             // Указатель на массив 
                1,                        // Индекс в массиве
                &parMathPoint,            // Указатель на структуру элемента
                sizeof( parMathPoint ) ); // Размер структуры элемента  
 
  // Заменим параметры 0-го элемента массива математических точек
  parMathPoint.x = 60; 
  parMathPoint.y = 60;
  SetArrayItem( rArMathPoint,             // Указатель на массив
                0,                        // Индекс в массиве
                &parMathPoint,            // Указатель на структуру элемента
                sizeof( parMathPoint ) ); // Размер структуры элемента  
 
  // Количество элементов в массиве математических точек 
  count = GetArrayCount( rArMathPoint );
  
  // Просмотрим массив математических точек
  for ( int i = 0; i < count; i++ )
  {
    // Получить значение элемента массива
    GetArrayItem( rArMathPoint,             // Указатель на массив
                  i,                        // Индекс в массиве
                  &parMathPoint,            // Указатель на структуру элемента
                  sizeof( parMathPoint ) ); // Размер структуры элемента  
		_stprintf( buf, _T("i = %d, x = %4.2f, y = %4.2f"), i, parMathPoint.x, parMathPoint.y );
		MessageT( buf );
  }

  DeleteArray( rArMathPoint ); // Удалить динамический массив математических точек
}


//--------------------------------------------------------------------------
// Массив предназначен для хранения строк
// ---
void StrIndefiniteArray()
{
  // Создать массив для хранения строк
	reference rArString = CreateArray( CHAR_STR_ARR_T, 0 );
  
  // Наполним массив строк
	TCHAR buf[255];
	_tcscpy( buf, _T("12345") );
  // Добавим 1-ю строку, элемент добавляется в конец массива
  AddArrayItem( rArString,       // Указатель на массив
                -1,              // Индекс в массиве
                &buf,            // Указатель на структуру элемента
                sizeof( buf ) ); // Размер структуры элемента  
                  
	_tcscpy( buf, _T("67890") );
	// Добавим 2-ю строку, элемент добавляется в конец массива
  AddArrayItem( rArString,       // Указатель на массив
                -1,              // Индекс в массиве
                &buf,            // Указатель на структуру элемента
                sizeof( buf ) ); // Размер структуры элемента   
  
	_tcscpy( buf, _T("qwerty") );
  // Добавим 3-ю строку, элемент добавляется в конец массива
  AddArrayItem( rArString,       // Указатель на массив
                -1,              // Индекс в массиве
                &buf,            // Указатель на структуру элемента
                sizeof( buf ) ); // Размер структуры элемента  
 
  // Количество элементов в массиве строк
  int count = GetArrayCount( rArString );
	_stprintf( buf, _T("count = %d"), count );
	MessageT( buf );
 
  // Просмотрим массив строк
  for ( int i = 0; i < count; i++ )
  {
    // Получить значение элемента массива
    GetArrayItem( rArString,       // Указатель на массив
                  i,               // Индекс в массиве
                  buf,             // Указатель на структуру элемента
                  sizeof( buf ) ); // Размер структуры элемента  
		MessageT( buf );
  }
 
  // Исключить из массива 1-й элемент
  ExcludeArrayItem( rArString, 1 );
  
  // Количество элементов в массиве строк
  count = GetArrayCount( rArString );
  
  // Просмотрим массив строк
  for ( int i = 0; i < count; i++ )
  {
    // Получить значение элемента массива
		GetArrayItem( rArString,       // Указатель на массив
                  i,               // Индекс в массиве
                  buf,             // Указатель на структуру элемента
                  sizeof( buf ) ); // Размер структуры элемента  
		MessageT( buf );
  }

  DeleteArray( rArString ); // Удалить динамический массив строк
}


//-------------------------------------------------------------------------------
// Функция для отображения массива колонок
// ---
void ShowColumns( reference rArColumn, bool record )
{
	ColumnInfoT parColumn; // Структура параметров колонки табличного атрибута
    
  // Создать динамические массивы
  parColumn.columns   = CreateArray( ATTR_COLUMN_ARR, 0 ); // Динамический массив неопределенной длины информации о колонках записи
	parColumn.fieldEnum = CreateArray( CHAR_STR_ARR_T, 0 );    // Массив строк неопределенной длины для хранения перечислений

	// Количество элементов в массиве колонок
  int count = GetArrayCount( rArColumn );
	TCHAR buf[255];
	_stprintf( buf, _T("count = %d"), count );
	MessageT( buf );
  
  // Просмотрим массив колонок
  for ( int i = 0; i < count; i++ )
  {
    // Получить значение элемента массива
    if ( !GetArrayItem( rArColumn,              // Указатель на массив
                        i,                      // Индекс в массиве
                        &parColumn,             // Указатель на структуру элемента
                        sizeof( parColumn ) ) ) // Размер структуры элемента  
      MessageBoxResult(); // Выдать сообщение об ошибке на экран 
    else
    {
      // Выдадим информацию о колонке
			_stprintf( buf, record ? _T("RECORD, i = %d, header = %s,\ntype = %d, def = %s, flagEnum = %d") :
															 _T("i = %d, header = %s,\ntype = %d, def = %s, flagEnum = %d"),
               i, parColumn.header, parColumn.type, parColumn.def, parColumn.flagEnum );
      MessageT( buf );
      
      // Если тип данных в колонки - запись( RECORD ), то массив columns в свою очередь
      // содержит структуры, определяющие поля этой записи. 
      
      if ( parColumn.type == RECORD_ATTR_TYPE ) // Если структура 
        ShowColumns( parColumn.columns, TRUE );
      else
      {
        // Выдадим массив перечислений
        if ( parColumn.flagEnum )
        {
          // Количество элементов в массиве перечислений
          int count1 = GetArrayCount( parColumn.fieldEnum );
          
					MessageT( _T("Массив перечислений") );
          for ( int j = 0; j < count1; j++ )
          {
            // Получить значение элемента массива
            if ( !GetArrayItem( parColumn.fieldEnum, // Указатель на массив
                                j,                   // Индекс в массиве
                                &buf,                // Указатель на структуру элемента
                                sizeof( buf ) ) )    // Размер структуры элемента  
							MessageBoxResult(); // Выдать сообщение об ошибке на экран
            else
							MessageT( buf );
          }
        }
      }
    }
  }
  
  // Удалить динамические массивы
  DeleteArray( parColumn.columns );   // Динамический массив неопределенной длины информации о колонках записи
  DeleteArray( parColumn.fieldEnum ); // Массив строк неопределенной длины для хранения перечислений 
}


//--------------------------------------------------------------------------
// Массив предназначен для создания и получения типа атрибута, 
// который может состоять из нескольких колонок
// ---
void AttrIndefiniteArray()
{
  // Создадим массив из 3 колонок
  // Первая колонка - описывает int с перечисленными значениями ( 100, 200, 300 )
  // Вторая колонка - запись соответствует структуре double ( умолчательное значение 123456789 )
  //                                                 long   ( умолчательное значение 1000000 )
  //                                                 char   ( умолчательное значение 10 )
  // Третья колонка - строка символов ( умолчательное значение "text" )

	ColumnInfoT parColumn1, // Структура параметров первой колонки
							parColumn2, // Структура параметров второй колонки
							parColumn3, // Структура параметров третьей колонки
							parStruct;  // Структура параметров колонки табличного атрибута
  
  // Создать динамические массивы
  reference rArColumn = CreateArray( ATTR_COLUMN_ARR, 0 ); // Динамический массив колонок
  reference rArStruct = CreateArray( ATTR_COLUMN_ARR, 0 ); // Динамический массив колонок записи
	reference rArEnum   = CreateArray( CHAR_STR_ARR_T, 0 );    // Динамический массив перечисленных значений

  // Первая колонка
	_tcscpy( parColumn1.header,_T("int") ); // Заголовoк-комментарий столбца
	parColumn1.type = INT_ATTR_TYPE;    // Тип данных в столбце - см.ниже
	parColumn1.key = 0;                 // Дополнительный признак, который позволит отличить две переменные с одинаковым типом
	_tcscpy( parColumn1.def,_T("100") );    // Значение по умолчанию
	parColumn1.flagEnum = 1;            // Флаг включающий режим, когда значение поля атрибута будет заполнятся
																			// из массива перечисленных значений 1 и 0 отключен
	parColumn1.fieldEnum = rArEnum;     // Массив строк неопределенной длины для хранения перечислений
	parColumn1.columns = 0;             // Массив неопределенной длины информации о колонках для записи

	// Заполним массив перечисленных значений для первой колонки, элементы добавляется в конец массива
	TCHAR buf[255];
	_tcscpy( buf, _T("100") );
	// Добавим 1-е значение, элемент добавляется в конец массива
	AddArrayItem( rArEnum,         // Указатель на массив
								-1,              // Индекс в массиве
								&buf,            // Указатель на структуру элемента
								sizeof( buf ) ); // Размер структуры элемента

	_tcscpy( buf, _T("200") );
	// Добавим 2-е значение, элемент добавляется в конец массива
	AddArrayItem( rArEnum,         // Указатель на массив
								-1,              // Индекс в массиве
								&buf,            // Указатель на структуру элемента
								sizeof( buf ) ); // Размер структуры элемента

	_tcscpy( buf, _T("300") );
	// Добавим 3-е значение, элемент добавляется в конец массива
	AddArrayItem( rArEnum,         // Указатель на массив
								-1,              // Индекс в массиве
								&buf,            // Указатель на структуру элемента
								sizeof( buf ) ); // Размер структуры элемента

	// Добавим первую колонку, элемент добавляется в конец массива
	AddArrayItem( rArColumn,              // Указатель на массив
								-1,                     // Индекс в массиве
								&parColumn1,            // Указатель на структуру элемента
								sizeof( parColumn1 ) ); // Размер структуры элемента

	// Если тип данных в колонке - запись( RECORD ), то массив columns в свою очередь
	// содержит структуры, определяющие поля этой записи.

	// Вторая колонка
	_tcscpy( parColumn2.header,_T("struct") ); // Заголовoк-комментарий столбца
	parColumn2.type = RECORD_ATTR_TYPE;    // Тип данных в столбце - см.ниже
	parColumn2.key = 0;                    // Дополнительный признак, который позволит отличить две переменные с одинаковым типом
	parColumn2.def[0] = '\0';              // Значение по умолчанию
	parColumn2.flagEnum = 0;               // Флаг включающий режим, когда значение поля атрибута будет заполнятся
																				 // из массива перечисленных значений 1 и 0 отключен
	parColumn2.fieldEnum = 0;              // Массив строк неопределенной длины для хранения перечислений
	parColumn2.columns = rArStruct;        // Массив неопределенной длины информации о колонках для записи

	// Заполним массив колонок для структуры
	// Первая колонка структуры
	_tcscpy( parStruct.header,_T("double") ); // Заголовoк-комментарий столбца
	parStruct.type = DOUBLE_ATTR_TYPE;    // Тип данных в столбце - см.ниже
	parStruct.key = 0;                    // Дополнительный признак, который позволит отличить две переменные с одинаковым типом
	_tcscpy( parStruct.def,_T("123456789") ); // Значение по умолчанию
	parStruct.flagEnum = 0;               // Флаг включающий режим, когда значение поля атрибута будет заполнятся
																				// из массива перечисленных значений 1 и 0 отключен
	parStruct.fieldEnum = 0;              // Массив строк неопределенной длины для хранения перечислений
	parStruct.columns = 0;                // Массив неопределенной длины информации о колонках для записи
	// Добавим первую колонку структуры, элемент добавляется в конец массива
	AddArrayItem( rArStruct,             // Указатель на массив
								-1,                    // Индекс в массиве
								&parStruct,            // Указатель на структуру элемента
								sizeof( parStruct ) ); // Размер структуры элемента

	// Вторая колонка структуры
	_tcscpy( parStruct.header,_T("long") ); // Заголовoк-комментарий столбца
	parStruct.type = LINT_ATTR_TYPE;    // Тип данных в столбце - см.ниже
	parStruct.key = 0;                  // Дополнительный признак, который позволит отличить две переменные с одинаковым типом
	_tcscpy( parStruct.def,_T("1000000") ); // Значение по умолчанию
	parStruct.flagEnum = 0;             // Флаг включающий режим, когда значение поля атрибута будет заполнятся
																			// из массива перечисленных значений 1 и 0 отключен
	parStruct.fieldEnum = 0;            // Массив строк неопределенной длины для хранения перечислений
	parStruct.columns = 0;              // Массив неопределенной длины информации о колонках для записи
	// Добавим вторую колонку структуры, элемент добавляется в конец массива
	AddArrayItem( rArStruct,             // Указатель на массив
								-1,                    // Индекс в массиве
								&parStruct,            // Указатель на структуру элемента
								sizeof( parStruct ) ); // Размер структуры элемента

	// Третья колонка структуры
	_tcscpy( parStruct.header,_T("char") ); // Заголовoк-комментарий столбца
	parStruct.type = CHAR_ATTR_TYPE;    // Тип данных в столбце - см.ниже
	parStruct.key = 0;                  // Дополнительный признак, который позволит отличить две переменные с одинаковым типом
	_tcscpy( parStruct.def,_T("10") );      // Значение по умолчанию
	parStruct.flagEnum = 0;             // Флаг включающий режим, когда значение поля атрибута будет заполнятся
																			// из массива перечисленных значений 1 и 0 отключен
	parStruct.fieldEnum = 0;            // Массив строк неопределенной длины для хранения перечислений
	parStruct.columns = 0;              // Массив неопределенной длины информации о колонках для записи
	// Добавим третью колонку структуры, элемент добавляется в конец массива
  AddArrayItem( rArStruct,             // Указатель на массив
                -1,                    // Индекс в массиве
                &parStruct,            // Указатель на структуру элемента
                sizeof( parStruct ) ); // Размер структуры элемента  
                  
  // Добавим вторую колонку, элемент добавляется в конец массива
  AddArrayItem( rArColumn,              // Указатель на массив
                -1,                     // Индекс в массиве
                &parColumn2,            // Указатель на структуру элемента
                sizeof( parColumn2 ) ); // Размер структуры элемента  
                
  // Третья  колонка
  _tcscpy( parColumn3.header,_T("string") ); // Заголовoк-комментарий столбца
  parColumn3.type = STRING_ATTR_TYPE;    // Тип данных в столбце - см.ниже
  parColumn3.key = 0;                    // Дополнительный признак, который позволит отличить две переменные с одинаковым типом
	_tcscpy( parColumn3.def,_T("text") );      // Значение по умолчанию
  parColumn3.flagEnum = 0;               // Флаг включающий режим, когда значение поля атрибута будет заполнятся
                                         // из массива перечисленных значений 1 и 0 отключен
  parColumn3.fieldEnum = 0;              // Массив строк неопределенной длины для хранения перечислений 
  parColumn3.columns = 0;                // Массив неопределенной длины информации о колонках для записи
  
  // Добавим третью колонку, элемент добавляется в конец массива
  AddArrayItem( rArColumn,              // Указатель на массив
                -1,                     // Индекс в массиве
                &parColumn3,            // Указатель на структуру элемента
                sizeof( parColumn3 ) ); // Размер структуры элемента  
                
  // Просмотрим массив колонок
  ShowColumns( rArColumn, FALSE ); 

  // Поменяем колонки местами 2->1, 1->3, 3->2 ( изменим параметры )
  SetArrayItem( rArColumn,              // Указатель на массив
                0,                      // Индекс в массиве
                &parColumn2,            // Указатель на структуру элемента
                sizeof( parColumn2 ) ); // Размер структуры элемента  
                
  SetArrayItem( rArColumn,              // Указатель на массив
                2,                      // Индекс в массиве
                &parColumn1,            // Указатель на структуру элемента
                sizeof( parColumn1 ) ); // Размер структуры элемента  
                
  SetArrayItem( rArColumn,              // Указатель на массив
                1,                      // Индекс в массиве
                &parColumn3,            // Указатель на структуру элемента
                sizeof( parColumn3 ) ); // Размер структуры элемента  

  // Просмотрим массив колонок
  ShowColumns( rArColumn, FALSE );

  // Удалить динамические массивы
  DeleteArray( rArColumn ); // Динамический массив колонок
  DeleteArray( rArStruct ); // Динамический массив колонок записи
  DeleteArray( rArEnum );   // Динамический массив перечисленных значений  
}


//-------------------------------------------------------------------------------
// Структура пользователя
// ---
struct UserData 
{
  int i;
	TCHAR * c;
  float f;
};


//-------------------------------------------------------------------------------
// Функция удаляет элемент UserData - структура пользователя
// ---
void __stdcall DelFuncUserData( void * val )
{
  UserData * tmp = ( UserData * )val;
	TCHAR buf[255];
	_stprintf( buf,_T("Удаляем элемент\nc = %s"), tmp->c );
	MessageT( buf );
  delete [] tmp->c;
  delete tmp;
}
 

//-------------------------------------------------------------------------------
// Функция добавляет элемент UserData - структура пользователя
// ---
int AddUserData( reference rArray, int i, const TCHAR * c, float f )
{
  UserData * tmp = new UserData;
	tmp->i = i;
	tmp->c = ::_tcsdup( c );
	_tcscpy( tmp->c, c );
  tmp->f = f;
	// Добавим структуру пользователя в массив
  return AddArrayItem( rArray,               // Указатель на массив
                       -1,                   // Индекс в массиве
                       tmp,                  // Указатель на структуру элемента
                       sizeof( UserData ) ); // Размер структуры элемента  
}


//-------------------------------------------------------------------------------
// Функция выдает содержимое элемента UserData - структура пользователя
// ---
void ShowUserData( UserData & tmp )
{
	TCHAR buf[255];
  _stprintf( buf,_T("i = %d,\nf = %f,\nc = %s"), tmp.i, tmp.f, tmp.c );
  MessageT( buf );
}


//------------------------------------------------------------------------------
// Массива для хранения структур пользователя
// ---
void UserDataArray()
{
  // Указатель на структуру пользователя
  UserData * tmp;
  
  // Создать массив для хранения структур пользователя, DelFuncUserData 
	// функция удаления элемента динамического массива
  reference rArUserData = CreateArray( USER_ARR, DelFuncUserData );

  // Наполним массив структур пользователя 
	if ( !AddUserData( rArUserData, 1,_T("Январь"), 31. ) )
		MessageBoxResult(); // Выдать сообщение об ошибке на экран
  if ( !AddUserData( rArUserData, 2,_T("Февраль"), 29. ) )
    MessageBoxResult(); // Выдать сообщение об ошибке на экран 
  if ( !AddUserData( rArUserData, 3,_T("Март"), 31. ) )
    MessageBoxResult(); // Выдать сообщение об ошибке на экран 

  // Количество элементов в массиве структур пользователя
  int count = GetArrayCount( rArUserData );
	TCHAR buf[255];
  _stprintf( buf,_T("count = %d"), count );
  MessageT( buf );
  
  // Просмотрим массив структур пользователя
  for ( int i = 0; i < count; i++ )
  {
    // Получить значение элемента массива
    if ( !GetUserArrayItem( rArUserData, i, ( void** )&tmp ) )
      MessageBoxResult(); // Выдать сообщение об ошибке на экран 
    else 
      ShowUserData( *tmp );
  }
  
  // Удалить динамический массив структур пользователя
  DeleteArray( rArUserData );
}


//-------------------------------------------------------------------------------
// Пользовательский класс
// ---
class UserClass
{
private :
  int *i;
	TCHAR *c;
  double *d;
public :
  UserClass(): i( NULL ), c( NULL ), d( NULL ){};
	UserClass( int _i, const TCHAR *_c, double _d );
  ~UserClass();
  void Show();
};


//-------------------------------------------------------------------------------
// Пользовательский класс - конструктор
// ---
UserClass::UserClass( int _i, const TCHAR *_c, double _d )
{
  i = new int;
  *i = _i;
	c = _tcsdup( _c );
	d = new double;
  *d = _d;
}


//-------------------------------------------------------------------------------
// Пользовательский класс - деструктор
// ---
UserClass::~UserClass()
{
  delete i;
	TCHAR buf[255];
	_stprintf( buf,_T("Деструктор элемента\nc = %s"), c );
  MessageT( buf );
  delete [] c;
  delete d;
}


//-------------------------------------------------------------------------------
// Пользовательский класс - отображение параметров
// ---
void UserClass::Show()
{
	TCHAR buf[255];
	_stprintf( buf,_T("i = %d,\nd = %f,\nc = %s"), *i, *d, c );
	MessageT( buf );
}


//-------------------------------------------------------------------------------
// Функция удаляет элемент UserClass - пользовательский класс
// ---
void __stdcall DelFuncUserClass( void * val )
{
  UserClass * tmp = ( UserClass * ) val;
  delete tmp;
}


//-------------------------------------------------------------------------------
// Функция добавляет элемент UserClass - пользовательский класс
// ---
int AddUserClass( reference rArray, int i, const TCHAR *c, double d )
{
  UserClass * tmp = new UserClass( i, c, d );
  // Добавим экземпляр класса пользователя в массив
  return AddArrayItem( rArray,                // Указатель на массив
                       -1,                    // Индекс в массиве
                       tmp,                   // Указатель на структуру элемента
                       sizeof( UserClass ) ); // Размер структуры элемента   
}


//------------------------------------------------------------------------------
// Массива для хранения экземпляров класса пользователя
// ---
void UserClassArray()
{
  // Указатель на пользовательский класс
  UserClass * tmp;
  
  // Создание массива экземпляров класса пользователя, DelFuncUserClass 
  // функция удаления элемента динамического массива
  reference rArUserClass = CreateArray( USER_ARR, DelFuncUserClass );
  // Наполним массив экземпляров класса пользователя
  if ( !AddUserClass( rArUserClass, -10,_T("First"),  10031. ) )
    MessageBoxResult(); // Выдать сообщение об ошибке на экран 
  if ( !AddUserClass( rArUserClass, -20,_T("Second"), 10029. ) )
    MessageBoxResult(); // Выдать сообщение об ошибке на экран 
  if ( !AddUserClass( rArUserClass, -30,_T("Third"),  10031. ) )
    MessageBoxResult(); // Выдать сообщение об ошибке на экран 

  // Количество элементов в массиве экземпляров класса пользователя
  int count = GetArrayCount( rArUserClass );
	TCHAR buf[255];
  _stprintf( buf,_T("count = %d"), count );
  MessageT( buf );
    
  // Просмотрим массив экземпляров класса пользователя
  for ( int i = 0; i < count; i++ )
  {
    // Получить значение элемента массива
    if ( !GetUserArrayItem( rArUserClass, i, ( void** )&tmp ) )
      MessageBoxResult(); // Выдать сообщение об ошибке на экран 
    else 
      tmp->Show();
  }

  // Удалить динамический массив экземпляров класса пользователя
  DeleteArray( rArUserClass );
}


//-------------------------------------------------------------------------------
// Массив полилиний это массив массивов математических точек
// ---
void PolyLineArray()
{
  MathPointParam parMathPoint; // Структура параметров математической точки    
  
  reference rArMathPoint = CreateArray( POINT_ARR, 0 );    // Массив для хранения математических точек
  reference rArPolyLine  = CreateArray( POLYLINE_ARR, 0 ); // Массив полилиний - массивы математических точек

  // Наполнить массив математических точек
  parMathPoint.x = 10; 
  parMathPoint.y = 10;
  // Добавим 1-ю точку, элемент добавляется в конец массива
  AddArrayItem( rArMathPoint,             // Указатель на массив
                -1,                       // Индекс в массиве
                &parMathPoint,            // Указатель на структуру элемента
                sizeof( parMathPoint ) ); // Размер структуры элемента 
                         
  parMathPoint.x = 100;
  parMathPoint.y = 100;
  // Добавим 2-ю точку, элемент добавляется в конец массива
  AddArrayItem( rArMathPoint,             // Указатель на массив
                -1,                       // Индекс в массиве
                &parMathPoint,            // Указатель на структуру элемента
                sizeof( parMathPoint ) ); // Размер структуры элемента 
  
  parMathPoint.x = 1000;
  parMathPoint.y = 1000;
  // Добавим 3-ю точку, элемент добавляется в конец массива
  AddArrayItem( rArMathPoint,             // Указатель на массив
                -1,                       // Индекс в массиве
                &parMathPoint,            // Указатель на структуру элемента
                sizeof( parMathPoint ) ); // Размер структуры элемента 

  // Добавим 1-й массив математических точек в массив полилиний, элемент добавляется в конец массива
  AddArrayItem( rArPolyLine,              // Указатель на массив
                -1,                       // Индекс в массиве
                &rArMathPoint,            // Указатель на структуру элемента
                sizeof( rArMathPoint ) ); // Размер структуры элемента 
                
  // Очистили массив математических точек, чтобы использовать для создания 2-й полилинии
  ClearArray( rArMathPoint );

  // Наполнить массив математических точек
  parMathPoint.x = 20; 
  parMathPoint.y = 20;
  // Добавим 1-ю точку, элемент добавляется в конец массива
  AddArrayItem( rArMathPoint,             // Указатель на массив
                -1,                       // Индекс в массиве
                &parMathPoint,            // Указатель на структуру элемента
                sizeof( parMathPoint ) ); // Размер структуры элемента 
                  
  parMathPoint.x = 200;
  parMathPoint.y = 200;
  // Добавим 2-ю точку, элемент добавляется в конец массива
  AddArrayItem( rArMathPoint,             // Указатель на массив
                -1,                       // Индекс в массиве
                &parMathPoint,            // Указатель на структуру элемента
                sizeof( parMathPoint ) ); // Размер структуры элемента 
  
  parMathPoint.x = 2000;
  parMathPoint.y = 2000;
  // Добавим 3-ю точку, элемент добавляется в конец массива
  AddArrayItem( rArMathPoint,             // Указатель на массив
                -1,                       // Индекс в массиве
                &parMathPoint,            // Указатель на структуру элемента
                sizeof( parMathPoint ) ); // Размер структуры элемента 
  
  // Добавим 2-й массив математических точек в массив полилиний, элемент добавляется в конец массива
  AddArrayItem( rArPolyLine,              // Указатель на массив
                -1,                       // Индекс в массиве
                &rArMathPoint,            // Указатель на структуру элемента
                sizeof( rArMathPoint ) ); // Размер структуры элемента   

  // Очистили массив математических точек, чтобы использовать для создания 3-й полилинии
  ClearArray( rArMathPoint );
  
  // Наполнить массив математических точек
  parMathPoint.x = 30; 
  parMathPoint.y = 30;
  // Добавим 1-ю точку, элемент добавляется в конец массива
  AddArrayItem( rArMathPoint,             // Указатель на массив
                -1,                       // Индекс в массиве
                &parMathPoint,            // Указатель на структуру элемента
                sizeof( parMathPoint ) ); // Размер структуры элемента 
  
  parMathPoint.x = 300;
  parMathPoint.y = 300;
  // Добавим 2-ю точку, элемент добавляется в конец массива
  AddArrayItem( rArMathPoint,             // Указатель на массив
                -1,                       // Индекс в массиве
                &parMathPoint,            // Указатель на структуру элемента
                sizeof( parMathPoint ) ); // Размер структуры элемента 
  
  parMathPoint.x = 3000;
  parMathPoint.y = 3000;
  // Добавим 3-ю точку, элемент добавляется в конец массива
  AddArrayItem( rArMathPoint,             // Указатель на массив
                -1,                       // Индекс в массиве
                &parMathPoint,            // Указатель на структуру элемента
                sizeof( parMathPoint ) ); // Размер структуры элемента 
  
  // Добавим 3-й массив математических точек в массив полилиний, элемент добавляется в конец массива
  AddArrayItem( rArPolyLine,              // Указатель на массив
                -1,                       // Индекс в массиве
                &rArMathPoint,            // Указатель на структуру элемента
                sizeof( rArMathPoint ) ); // Размер структуры элемента 

  // Количество элементов в массиве полилиний
  int count = GetArrayCount( rArPolyLine );
	TCHAR buf[255];
  _stprintf( buf,_T("count = %d"), count );
  MessageT( buf );
 
  // Просмотрим массив полилиний
  // Цикл по полилиниям - массивы математических точек
  for ( int i = 0; i < count; i++ )
  {
    // Получить значение элемента массива
    GetArrayItem( rArPolyLine,              // Указатель на массив
                  i,                        // Индекс в массиве
                  &rArMathPoint,            // Указатель на структуру элемента
                  sizeof( rArMathPoint ) ); // Размер структуры элемента  

    // Количество элементов в массиве математических точек 
    int count1 = GetArrayCount( rArMathPoint );
    
    // Цикл по полилинии - массиву математических точек
    for ( int j = 0; j < count1; j++ )
		{
      // Получить значение элемента массива
      GetArrayItem( rArMathPoint,             // Указатель на массив
                    j,                        // Индекс в массиве
                    &parMathPoint,            // Указатель на структуру элемента
                    sizeof( parMathPoint ) ); // Размер структуры элемента  
			_stprintf( buf, _T("i = %d, x = %4.2f, y = %4.2f"), i, parMathPoint.x, parMathPoint.y );
      MessageT( buf );
    }
  }

  // Заменим у второго элемента массива полилиний( массива математических точек ) второй элемент
  // Получить значение элемента массива полилиний
  GetArrayItem( rArPolyLine,              // Указатель на массив
                1,                        // Индекс в массиве
                &rArMathPoint,            // Указатель на структуру элемента
                sizeof( rArMathPoint ) ); // Размер структуры элемента  
  
  // Получить значение элемента массива математических точек
  GetArrayItem( rArMathPoint,             // Указатель на массив
                1,                        // Индекс в массиве
                &parMathPoint,            // Указатель на структуру элемента
                sizeof( parMathPoint ) ); // Размер структуры элемента    
  
  parMathPoint.x = 500;
  parMathPoint.y = 500;
  // Установить значение элемента динамического массива математических точек 
  SetArrayItem( rArMathPoint,             // Указатель на массив
                1,                        // Индекс в массиве
                &parMathPoint,            // Указатель на структуру элемента
                sizeof( parMathPoint ) ); // Размер структуры элемента  

  // Установить значение элемента динамического массива полилиний
  SetArrayItem( rArPolyLine,              // Указатель на массив
                1,                        // Индекс в массиве
                &rArMathPoint,            // Указатель на структуру элемента
                sizeof( rArMathPoint ) ); // Размер структуры элемента  

  // Количество элементов в массиве полилиний
  count = GetArrayCount( rArPolyLine );
 
  // Просмотрим массив полилиний
  // Цикл по полилиниям - массивы математических точек
  for ( int i = 0; i < count; i++ )
  {
    // Получить значение элемента массива
    GetArrayItem( rArPolyLine,              // Указатель на массив
                  i,                        // Индекс в массиве
                  &rArMathPoint,            // Указатель на структуру элемента
                  sizeof( rArMathPoint ) ); // Размер структуры элемента  

    // Количество элементов в массиве математических точек 
    int count1 = GetArrayCount( rArMathPoint );
    
    // Цикл по полилинии - массиву математических точек
    for ( int j = 0; j < count1; j++ )
    {
      // Получить значение элемента массива
      GetArrayItem( rArMathPoint,             // Указатель на массив
                    j,                        // Индекс в массиве
                    &parMathPoint,            // Указатель на структуру элемента
                    sizeof( parMathPoint ) ); // Размер структуры элемента  
      _stprintf( buf,_T("i = %d, x = %4.2f, y = %4.2f"), i, parMathPoint.x, parMathPoint.y );
      MessageT( buf );
    }
  }

  // Удалить динамические массивы
  DeleteArray( rArMathPoint ); // Массив для хранения математических точек
  DeleteArray( rArPolyLine );  // Массив полилиний - массивы математических точек
}


//--------------------------------------------------------------------------------
// Массив неопределенной длины габаритных прямоугольников( структура RectParam )
// ---
void RectArray()
{
  RectParam parRect; // Структура параметров прямоугольника по диагональным точкам
  
  // Создать динамический массив габаритных прямоугольников
  reference rArRect = CreateArray( RECT_ARR, 0 );
  
  // Наполнить динамический массив габаритных прямоугольников
  parRect.pBot.x =  20; // Параметры левой нижней точки прямоугольника 
  parRect.pBot.y = -10;
  parRect.pTop.x =  10; // Параметры правой верхней точки прямоугольника
  parRect.pTop.y =  10;
  // Добавим 1-й прямоугольник, элемент добавляется в конец массива
  AddArrayItem( rArRect,             // Указатель на массив
                -1,                  // Индекс в массиве
                &parRect,            // Указатель на структуру элемента
                sizeof( parRect ) ); // Размер структуры элемента   

  parRect.pBot.x = 50; // Параметры левой нижней точки прямоугольника 
  parRect.pBot.y = 10;  
  parRect.pTop.x = 20; // Параметры правой верхней точки прямоугольника
  parRect.pTop.y = 50;
  // Добавим 2-й прямоугольник, элемент добавляется в конец массива
  AddArrayItem( rArRect,             // Указатель на массив
                -1,                  // Индекс в массиве
                &parRect,            // Указатель на структуру элемента
                sizeof( parRect ) ); // Размер структуры элемента   
  
  parRect.pTop.x = 20;  // Параметры левой нижней точки прямоугольника 
  parRect.pTop.y = 150;
  parRect.pBot.x = 50;  // Параметры правой верхней точки прямоугольника
  parRect.pBot.y = 110;
  // Добавим 3-й прямоугольник, элемент добавляется в конец массива
  AddArrayItem( rArRect,             // Указатель на массив
                -1,                  // Индекс в массиве
                &parRect,            // Указатель на структуру элемента
                sizeof( parRect ) ); // Размер структуры элемента   

  // Количество элементов в массиве габаритных прямоугольников
  int count = GetArrayCount( rArRect );
  TCHAR buf[255];
	_stprintf( buf,_T("count = %d"), count );
  MessageT( buf );

  // Просмотрим массив габаритных прямоугольников
  for ( int i = 0; i < count; i++ )
  {
    // Получить значение элемента массива
    GetArrayItem( rArRect,             // Указатель на массив
                  i,                   // Индекс в массиве
                  &parRect,            // Указатель на структуру элемента
                  sizeof( parRect ) ); // Размер структуры элемента  
    _stprintf( buf,_T("i = %d, pTop.x = %4.2f, pTop.y = %4.2f,\npBot.x = %4.2f, pBot.y = %4.2f"),
             i, parRect.pTop.x, parRect.pTop.y, parRect.pBot.x, parRect.pBot.y );
    MessageT( buf );
  }
  
  // Редактируем массив габаритных прямоугольников
  parRect.pBot.x =  10; // Параметры левой нижней точки прямоугольника  
  parRect.pBot.y = -20;
  parRect.pTop.x =  0;  // Параметры правой верхней точки прямоугольника
  parRect.pTop.y =  0;  
  // Установить значение 1-го элемента динамического массива габаритных прямоугольников
  SetArrayItem( rArRect,             // Указатель на массив
                0,                   // Индекс в массиве
                &parRect,            // Указатель на структуру элемента
                sizeof( parRect ) ); // Размер структуры элемента  
  
  parRect.pBot.x =  20; // Параметры левой нижней точки прямоугольника 
  parRect.pBot.y = -10;
  parRect.pTop.x = -20; // Параметры правой верхней точки прямоугольника
  parRect.pTop.y = -50;  
  // Установить значение 2-го элемента динамического массива габаритных прямоугольников
  SetArrayItem( rArRect,             // Указатель на массив
                1,                   // Индекс в массиве
                &parRect,            // Указатель на структуру элемента
                sizeof( parRect ) ); // Размер структуры элемента  

  parRect.pBot.x = 25; // Параметры левой нижней точки прямоугольника 
  parRect.pBot.y = 0;
  parRect.pTop.x = 5;  // Параметры правой верхней точки прямоугольника
  parRect.pTop.y = 5;  
  // Добавим 4-й прямоугольник, элемент добавляется в конец массива
  AddArrayItem( rArRect,             // Указатель на массив
                -1,                  // Индекс в массиве
                &parRect,            // Указатель на структуру элемента
                sizeof( parRect ) ); // Размер структуры элемента   

  // Количество элементов в массиве габаритных прямоугольников
  count = GetArrayCount( rArRect );

  // Просмотрим массив габаритных прямоугольников
  for ( int i = 0; i < count; i++ )
  {
    // Получить значение элемента массива
    GetArrayItem( rArRect,             // Указатель на массив
                  i,                   // Индекс в массиве
                  &parRect,            // Указатель на структуру элемента
                  sizeof( parRect ) ); // Размер структуры элемента  
		_stprintf( buf,_T("i = %d, pTop.x = %4.2f, pTop.y = %4.2f,\npBot.x = %4.2f, pBot.y = %4.2f"),
             i, parRect.pTop.x, parRect.pTop.y, parRect.pBot.x, parRect.pBot.y );
		MessageT( buf );
  }

  // Удалить динамический массив габаритных прямоугольников
  DeleteArray( rArRect );
}