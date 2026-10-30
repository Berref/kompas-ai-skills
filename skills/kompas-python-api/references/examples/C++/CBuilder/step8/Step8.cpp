////////////////////////////////////////////////////////////////////////////////
//
// step8.cpp - Работа с атрибутами
//
// 1.  Создать тип атрибута                      - FuncTypeAttr
// 2.  Удалить тип атрибута                      - DelTypeAttr
// 3.  Получить тип атрибута                     - ShowTypeAttr
// 4.  Заменить тип атрибута                     - ChangeType
// 5.  Создать атрибут определенного типа        - NewAttr
// 6.  Удалить атрибут                           - DelObjAttr
// 7.  Считать атрибут                           - ReadObjAttr
// 8.  Просмотреть атрибут                       - ShowObjAttr
// 9.  Просмотреть библиотеку                    - ShowLib
// 10. Просмотреть тип                           - ShowType
// 11. Просмотреть атрибут                       - WalkFromObjWithAttr
// 12. Создать атрибут документа                 - CreateDocumentAttr
// 13. Удалить атрибут документа                 - DeleteDocumentAttr
// 14. Просмотреть атрибут документа             - ShowDocumentAttr
// 15. Создать атрибут 3D документа              - CreateDocument3DAttr
// 16. Удалить атрибут 3D документа              - DeleteDocument3DAttr
// 17. Просмотреть атрибут документа             - ShowDocument3DAttr
// 18. Просмотреть атрибут объектов 3D документа - ShowObjects3DAttr
//
////////////////////////////////////////////////////////////////////////////////
#include <vcl.h>
#pragma hdrstop

#include <tchar.h>
#include <stdio.h>
#include <stdlib.h>

#include <objbase.h>
#include <initguid.h>

#include <libtool.h>
#include <Ltool3d.h>

#include <iuptr.h>

#include "step8.rh"

//------------------------------------------------------------------------------
// в Win32 линкуется SDK/lib/kAPI2D5bc.lib и kAPI3D5bc.lib
// в x64 линкуется SDK/lib64/kAPI2D5bc.a и kAPI3D5bc.a
// ---
#pragma comment(lib, "kAPI2D5bc")
#pragma comment(lib, "kAPI3D5bc")

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
void FuncTypeAttr();
void DelTypeAttr();
void ChangeType();
void NewAttr();
void ShowTypeAttr();
void DelObjAttr();
void ReadObjAttr();
void ShowObjAttr();
void ShowLib();
void ShowType();
void WalkFromObjWithAttr();
void CreateDocumentAttr();
void DeleteDocumentAttr();
void ShowDocumentAttr();
void CreateDocument3DAttr();
void DeleteDocument3DAttr();
void ShowDocument3DAttr();
void ShowObjects3DAttr();


int       docType = 0; // Тип документа
reference doc     = 0; // reference документа


//-------------------------------------------------------------------------------
// Головная функция библиотеки
// ---
extern "C" void __export __stdcall LIBRARYENTRY( unsigned int comm )
{
  doc     = ksGetCurrentDocument( 0 );
  docType = ksGetDocumentType( doc );

  switch ( docType ) {
    case lt_DocTxtStandart:        //               7- текстовый документ стандартный
    case lt_DocTxtUser:            //               8- текстовый документ нестандартный
    {
			int res = YesNoT( _T("В текстовом документе работа с атрибутами не реализована\nХотите работать с библиотекой атрибутов?") );
      if ( res )
      {
        doc     = 0;
        docType = 0;
      }
      else
        break;
    }
    case 0:                        // Нет документа (работаем с библиотекой атрибутов)
    case lt_DocSheetStandart:      // Тип документа 1- чертеж стандартный
    case lt_DocSheetUser:          //               2- чертеж нестандартный
    case lt_DocFragment:           //               3- фрагмент
    case lt_DocSpc:                //               4- спецификация
    case lt_DocPart3D:             //               5- 3d-документ модель
    case lt_DocAssemble3D:         //               6- 3d-документ сборка
    case lt_DocSpcUser:            //               9- спецификация нестандартный формат
    switch ( comm )
    {
        case 1  : FuncTypeAttr();        break; // Создать тип атрибута
        case 2  : DelTypeAttr();         break; // Удалить тип атрибута
        case 3  : ShowTypeAttr();        break; // Получить тип атрибута
        case 4  : ChangeType();          break; // Заменить тип атрибута
        case 5  : NewAttr();             break; // Создать атрибут определенного типа
        case 6  : DelObjAttr();          break; // Удалить атрибут
        case 7  : ReadObjAttr();         break; // Считать атрибут
        case 8  : ShowObjAttr();         break; // Просмотреть атрибут
        case 9  : ShowLib();             break; // Просмотреть библиотеку
        case 10 : ShowType();            break; // Просмотреть тип
        case 11 : WalkFromObjWithAttr(); break; // Просмотреть атрибут
        case 12 : CreateDocumentAttr();  break; // Создать атрибут документа
        case 13 : DeleteDocumentAttr();  break; // Удалить атрибут документа
        case 14 : ShowDocumentAttr();    break; // Просмотреть атрибут документа
        case 15 : CreateDocument3DAttr();break; // Создать атрибут 3D документа
        case 16 : DeleteDocument3DAttr();break; // Удалить атрибут 3D документа
        case 17 : ShowDocument3DAttr();  break; // Просмотреть атрибут документа
        case 18 : ShowObjects3DAttr();   break; // Просмотреть атрибут объектов 3D документа
    }
  }
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
              MessageBoxResult();     // Выдать сообщение об ошибке на экран 
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


//-------------------------------------------------------------------------------
// Создать тип атрибута
// ---
void FuncTypeAttr()
{
	TCHAR nameFile[255] = _T("");
 
  // Запросить имя библиотеки
	ksChoiceFileT( _T("*.lat"), NULL, nameFile, 255, 0 );
  
  if ( !nameFile[0] && !doc )  // если не выбрана библиотека и нет документа
    return;

  // Создадим массив из 3 колонок
  // Первая колонка - описывает int с перечисленными значениями ( 100, 200, 300 )
  // Вторая колонка - запись соответствует структуре double ( умолчательное значение 123456789 )
  //                                                 long   ( умолчательное значение 1000000 )
  //                                                 TCHAR   ( умолчательное значение 10 )
  // Третья колонка - строка символов ( умолчательное значение "text" )

	ColumnInfoT parColumn,  // Структура параметров колонки
              parStruct;  // Структура параметров колонки табличного атрибута
  
  // Создать динамические массивы
  reference rArColumn = CreateArray( ATTR_COLUMN_ARR, 0 ); // Динамический массив колонок
  reference rArStruct = CreateArray( ATTR_COLUMN_ARR, 0 ); // Динамический массив колонок записи
  reference rArEnum   = CreateArray( CHAR_STR_ARR, 0 );    // Динамический массив перечисленных значений

  // Первая колонка
  lstrcpy( parColumn.header, _T("int") ); // Заголовoк-комментарий столбца
  parColumn.type = INT_ATTR_TYPE;    // Тип данных в столбце - см.ниже
  parColumn.key = 0;                 // Дополнительный признак, который позволит отличить две переменные с одинаковым типом
	lstrcpy( parColumn.def, _T("100") );    // Значение по умолчанию
  parColumn.flagEnum = 1;            // Флаг включающий режим, когда значение поля атрибута будет заполнятся
                                     // из массива перечисленных значений 1 и 0 отключен
  parColumn.fieldEnum = rArEnum;     // Массив строк неопределенной длины для хранения перечислений 
  parColumn.columns = 0;             // Массив неопределенной длины информации о колонках для записи

  // Заполним массив перечисленных значений для первой колонки, элементы добавляется в конец массива
  TCHAR buf[255];
	lstrcpy( buf, _T("100") );
  // Добавим 1-е значение, элемент добавляется в конец массива
  AddArrayItem( rArEnum,         // Указатель на массив
                -1,              // Индекс в массиве
                &buf,            // Указатель на структуру элемента
                sizeof( buf ) ); // Размер структуры элемента  
                  
	lstrcpy( buf, _T("200") );
  // Добавим 2-е значение, элемент добавляется в конец массива
  AddArrayItem( rArEnum,         // Указатель на массив
                -1,              // Индекс в массиве
                &buf,            // Указатель на структуру элемента
                sizeof( buf ) ); // Размер структуры элемента  
  
	lstrcpy( buf, _T("300") );
  // Добавим 3-е значение, элемент добавляется в конец массива
  AddArrayItem( rArEnum,         // Указатель на массив
                -1,              // Индекс в массиве
                &buf,            // Указатель на структуру элемента
                sizeof( buf ) ); // Размер структуры элемента  

  // Добавим первую колонку, элемент добавляется в конец массива
  AddArrayItem( rArColumn,             // Указатель на массив
                -1,                    // Индекс в массиве
                &parColumn,            // Указатель на структуру элемента
                sizeof( parColumn ) ); // Размер структуры элемента  
                
  // Если тип данных в колонке - запись( RECORD ), то массив columns в свою очередь
  // содержит структуры, определяющие поля этой записи. 
      
  // Вторая колонка
  lstrcpy( parColumn.header, _T("struct") ); // Заголовoк-комментарий столбца
  parColumn.type = RECORD_ATTR_TYPE;    // Тип данных в столбце - см.ниже
  parColumn.key = 0;                    // Дополнительный признак, который позволит отличить две переменные с одинаковым типом
  memset( parColumn.def, 0, sizeof(parColumn.def) );
  parColumn.flagEnum  = 0;              // Флаг включающий режим, когда значение поля атрибута будет заполнятся
                                        // из массива перечисленных значений 1 и 0 отключен
  parColumn.fieldEnum = 0;              // Массив строк неопределенной длины для хранения перечислений 
  parColumn.columns   = rArStruct;      // Массив неопределенной длины информации о колонках для записи
 
  // Заполним массив колонок для структуры
  // Первая колонка структуры
  lstrcpy( parStruct.header, _T("double") ); // Заголовoк-комментарий столбца
  parStruct.type = DOUBLE_ATTR_TYPE;    // Тип данных в столбце - см.ниже
  parStruct.key  = 0;                   // Дополнительный признак, который позволит отличить две переменные с одинаковым типом
  lstrcpy( parStruct.def, _T("123456789") ); // Значение по умолчанию
  parStruct.flagEnum  = 0;              // Флаг включающий режим, когда значение поля атрибута будет заполнятся
                                        // из массива перечисленных значений 1 и 0 отключен
  parStruct.fieldEnum = 0;              // Массив строк неопределенной длины для хранения перечислений 
  parStruct.columns   = 0;              // Массив неопределенной длины информации о колонках для записи  
  // Добавим первую колонку структуры, элемент добавляется в конец массива
  AddArrayItem( rArStruct,             // Указатель на массив
                -1,                    // Индекс в массиве
                &parStruct,            // Указатель на структуру элемента
                sizeof( parStruct ) ); // Размер структуры элемента  
                
  // Вторая колонка структуры
  lstrcpy( parStruct.header, _T("long") ); // Заголовoк-комментарий столбца
  parStruct.type = LINT_ATTR_TYPE;    // Тип данных в столбце - см.ниже
  parStruct.key  = 0;                 // Дополнительный признак, который позволит отличить две переменные с одинаковым типом
  lstrcpy( parStruct.def, _T("1000000") ); // Значение по умолчанию
  parStruct.flagEnum  = 0;            // Флаг включающий режим, когда значение поля атрибута будет заполнятся
                                      // из массива перечисленных значений 1 и 0 отключен
  parStruct.fieldEnum = 0;            // Массив строк неопределенной длины для хранения перечислений 
  parStruct.columns   = 0;            // Массив неопределенной длины информации о колонках для записи
  // Добавим вторую колонку структуры, элемент добавляется в конец массива
  AddArrayItem( rArStruct,             // Указатель на массив
                -1,                    // Индекс в массиве
                &parStruct,            // Указатель на структуру элемента
                sizeof( parStruct ) ); // Размер структуры элемента  
                
  // Третья колонка структуры
  lstrcpy( parStruct.header, _T("TCHAR") ); // Заголовoк-комментарий столбца
  parStruct.type = CHAR_ATTR_TYPE;    // Тип данных в столбце - см.ниже
  parStruct.key  = 0;                 // Дополнительный признак, который позволит отличить две переменные с одинаковым типом
  lstrcpy( parStruct.def, _T("10") );      // Значение по умолчанию
  parStruct.flagEnum = 0;             // Флаг включающий режим, когда значение поля атрибута будет заполнятся
                                      // из массива перечисленных значений 1 и 0 отключен
  parStruct.fieldEnum = 0;            // Массив строк неопределенной длины для хранения перечислений 
  parStruct.columns   = 0;            // Массив неопределенной длины информации о колонках для записи
  // Добавим третью колонку структуры, элемент добавляется в конец массива
  AddArrayItem( rArStruct,             // Указатель на массив
                -1,                    // Индекс в массиве
                &parStruct,            // Указатель на структуру элемента
                sizeof( parStruct ) ); // Размер структуры элемента  
                  
  // Добавим вторую колонку, элемент добавляется в конец массива
  AddArrayItem( rArColumn,             // Указатель на массив
                -1,                    // Индекс в массиве
                &parColumn,            // Указатель на структуру элемента
                sizeof( parColumn ) ); // Размер структуры элемента  
                
  // Третья  колонка
  lstrcpy( parColumn.header, _T("string") ); // Заголовoк-комментарий столбца
  parColumn.type = STRING_ATTR_TYPE;    // Тип данных в столбце - см.ниже
  parColumn.key  = 0;                   // Дополнительный признак, который позволит отличить две переменные с одинаковым типом
  lstrcpy( parColumn.def, _T("text") );      // Значение по умолчанию
  parColumn.flagEnum  = 0;              // Флаг включающий режим, когда значение поля атрибута будет заполнятся
                                        // из массива перечисленных значений 1 и 0 отключен
  parColumn.fieldEnum = 0;              // Массив строк неопределенной длины для хранения перечислений 
  parColumn.columns   = 0;              // Массив неопределенной длины информации о колонках для записи
  
  // Добавим третью колонку, элемент добавляется в конец массива
  AddArrayItem( rArColumn,             // Указатель на массив
                -1,                    // Индекс в массиве
                &parColumn,            // Указатель на структуру элемента
                sizeof( parColumn ) ); // Размер структуры элемента  

  ksAttributeTypeT parAttributeType; // Структура параметров типа табличного атрибута
  
  // Заполним структуру типа атрибута
  lstrcpy( parAttributeType.header, _T("int_struct_string") ); // Заголовoк-комментарий типа
  parAttributeType.rowsCount   = 1;                       // Кол-во строк в таблице
  parAttributeType.flagVisible = 1;                       // Видимый, невидимый   в таблице
  lstrcpy( parAttributeType.password, _T("") );                // Пароль, если не пустая строка  - защищает от несанкционированного изменения типа
  parAttributeType.columns     = rArColumn;               // Массив неопределенной длины информации о колонках
  parAttributeType.key1        = 10;                      // Рекомендуется как код разработчика
  parAttributeType.key2        = 20;                      // Рекомендуется как код атрибута
  parAttributeType.key3        = 30;                      // Рекомендуется как код разработчика
  parAttributeType.key4        = 0;                       // Системный код атрибута  

  // Cоздать тип атрибута
	double numbType = ksCreateAttrTypeT( &parAttributeType, // Информация о типе атрибута
                                      nameFile );        // Имя библиотеки типов атрибутов
  if ( numbType > 1 )  
  {
    TCHAR buf[255];
    _stprintf( buf, _T("numbType = %f"), numbType );
    MessageT( buf );
  }
  else
    MessageBoxResult(); // Выдать сообщение об ошибке на экран   

  // Удалить динамические массивы
  DeleteArray( rArColumn ); // Динамический массив колонок
  DeleteArray( rArStruct ); // Динамический массив колонок записи
  DeleteArray( rArEnum   ); // Динамический массив перечисленных значений  
}


//-------------------------------------------------------------------------------
// Удалить тип атрибута
// ---
void DelTypeAttr()
{
	TCHAR nameFile[255] = _T("");
  // Запросить имя библиотеки
	ksChoiceFileT( _T("*.lat"), NULL, nameFile, 255, 0 );

  if ( nameFile[0] || doc ) // Если выбрана библиотека или есть документ
  {   
		TCHAR password[255] = _T("");
		double numbType    = ChoiceAttrTypesT( nameFile ); // Выбор типа атрибута
  
    if ( numbType > 1 ) 
    { 
      // ReadDouble( _T("Ввести номер типа атрибута"), 1000., 0, 1e12, &numbType ) )
      if ( ReadStringT( _T("Ввести пароль типа атрибута"), password, 255 ) )
        // Удалить описание атрибута
				if ( !DeleteAttrTypeT( numbType,    // Информация о типе атрибута
                              nameFile,    // Имя библиотеки типов атрибутов
                              password ) ) // Пароль описания атрибута
          MessageBoxResult(); // Выдать сообщение об ошибке на экран
    }
  }
}


//-------------------------------------------------------------------------------
// Получить тип атрибута 
// ---
void ShowTypeAttr() 
{
	TCHAR nameFile[255] = _T("");
  // Запросить имя библиотеки
	ksChoiceFileT( _T("*.lat"), NULL, nameFile, 255, 1 );

  if ( nameFile[0] || doc ) // Если выбрана библиотека или есть документ 
  { 
		double numbType = ChoiceAttrTypesT( nameFile ); // Выбор типа атрибута
    if ( numbType > 1 )
    {
      ksAttributeTypeT rAttributeType; // Структура параметров типа табличного атрибута
      rAttributeType.columns = CreateArray( ATTR_COLUMN_ARR, 0 ); // Динамический массив неопределенной длины информации о колонках записи

      // Получить описание типа табличного атрибута из библиотеки
			if ( !ksGetAttrTypeT( numbType, nameFile, &rAttributeType ) )
        MessageBoxResult(); // Выдать сообщение об ошибке на экран   
      else 
      {
        TCHAR buf[500];
        _stprintf( buf, _T("key1 = %d, key2 = %d, key3 = %d, key4 = %d,\nheader = %s, rowsCount = %d, flagVisible = %d, password = %s"),
                rAttributeType.key1, rAttributeType.key2, rAttributeType.key3, rAttributeType.key4,
                rAttributeType.header, rAttributeType.rowsCount, rAttributeType.flagVisible, rAttributeType.password );
        MessageT( buf );
     
        ShowColumns( rAttributeType.columns, FALSE ); // Функция для отображения массива колонок
      }
      // Удалить динамический массив колонок
      DeleteArray( rAttributeType.columns );
    }
  }
}


//-------------------------------------------------------------------------------
// Заменить тип атрибута
// ---
void ChangeType()
{
	TCHAR nameFile[255] = _T("");
  
  // Запросить имя библиотеки
	ksChoiceFileT( _T("*.lat"), NULL, nameFile, 255, 1 );

  if ( nameFile[0] || doc )  // если выбрана библиотека или есть документ
  {
		TCHAR password[255] = _T("");
    // double numbType;
		double numbType = ChoiceAttrTypesT( nameFile );
    if ( numbType > 1000 ) 
    {
      if ( ReadStringT( _T("Ввести пароль типа атрибута"), password, 255 ) )
      {
				ksAttributeTypeT rAttributeType; // Структура параметров типа табличного атрибута
        rAttributeType.columns = CreateArray( ATTR_COLUMN_ARR, 0 ); // Динамический массив неопределенной длины информации о колонках записи

        // Получить описание типа табличного атрибута из библиотеки
				if ( !ksGetAttrTypeT( numbType,           // Номер типа атрибута
                             nameFile,           // Имя библиотеки типов атрибутов
                             &rAttributeType ) ) // Структура параметров типа табличного атрибута
          MessageBoxResult(); // Выдать сообщение об ошибке на экран   
        else
        {
          // Поменяем местами первую колонку и последнюю
          ColumnInfo parColumn1; // Структура параметров колонки табличного атрибута для первой колонки
          parColumn1.columns   = CreateArray( ATTR_COLUMN_ARR, 0 ); // Динамический массив неопределенной длины информации о колонках записи
					parColumn1.fieldEnum = CreateArray( CHAR_STR_ARR_T, 0 );    // Массив строк неопределенной длины для хранения перечислений

          ColumnInfo parColumnN; // Структура параметров колонки табличного атрибута для последней колонки  
          parColumnN.columns   = CreateArray( ATTR_COLUMN_ARR, 0 ); // Динамический массив неопределенной длины информации о колонках записи
          parColumnN.fieldEnum = CreateArray( CHAR_STR_ARR_T, 0 );    // Массив строк неопределенной длины для хранения перечислений

          lstrcpy( rAttributeType.password, password );
          // Количество колонок
          int count = GetArrayCount( rAttributeType.columns );
        
          // Считаем параметры первой колонки
          GetArrayItem( rAttributeType.columns, 0, &parColumn1, sizeof( parColumn1 ) );
          // Считаем параметры последней колонки
          GetArrayItem( rAttributeType.columns, count - 1, &parColumnN, sizeof( parColumnN ) );
        
          // Заменим первую колонку ( изменим параметры )
          SetArrayItem( rAttributeType.columns, 0, &parColumnN, sizeof( parColumnN ) );
          // Заменим последнюю колонку ( изменим параметры )
          SetArrayItem( rAttributeType.columns, count - 1, &parColumn1, sizeof( parColumn1 ) );

          // Заменим  тип атрибута на новый
					numbType = ksSetAttrTypeT( numbType,        // Номер типа атрибута
                                    nameFile,        // Имя библиотеки типов атрибутов
                                    &rAttributeType, // Структура параметров типа табличного атрибута
                                    password );      // Пароль описания атрибута
          if ( numbType > 1 )  
          {
            TCHAR buf[255];
            _stprintf( buf, _T("numbType = %f"), numbType );
            MessageT( buf );
          }
          else
            MessageBoxResult(); // Выдать сообщение об ошибке на экран  
          
            // Удалить динамические массивы
          DeleteArray( parColumn1.columns );   // Динамический массив неопределенной длины информации о колонках записи
          DeleteArray( parColumn1.fieldEnum ); // Массив строк неопределенной длины для хранения перечислений 

          DeleteArray( parColumnN.columns );   // Динамический массив неопределенной длины информации о колонках записи
          DeleteArray( parColumnN.fieldEnum ); // Массив строк неопределенной длины для хранения перечислений 

        }
        DeleteArray( rAttributeType.columns );  // Динамический массив колонок
      }
    }
  }
}


//-------------------------------------------------------------------------------
// Создание атрибута
// ---
void LibCreateAttr( reference obj, LPFEATURE fObj )
{
	ksAttributeT parAttribute; // Структура параметров табличного атрибута
  memset( &parAttribute, 0, sizeof(parAttribute) );
  parAttribute.key1 = 1;                  // Рекомендуется как код разработчика
  parAttribute.key2 = 10;                 // Рекомендуется как код атрибута
  parAttribute.key3 = 100;                // Рекомендуется как код разработчика
  lstrcpy( parAttribute.password, _T("111") ); // Пароль, если не пустая строка - защищает от несанкционированного изменения информации в атрибуте

	TCHAR nameFile[255] = _T("");

	ksChoiceFileT( _T("*.lat"), NULL, nameFile, 255, 0 );    // Запросить имя библиотеки
	double numbType = ChoiceAttrTypesT( nameFile ); // Запросить тип атрибута из библиотеки

  if ( numbType > 1 )
  {
    // Создать атрибут объекта
    reference attr = 0;
    if ( obj )
			attr = ksCreateAttrT( obj,          // Указатель на объект
                           &parAttribute,// Структура параметров табличного атрибута
                           numbType,     // Номер типа атрибута
                           nameFile );   // Имя библиотеки
    else
    {
			IUEnv<IAttribute3D> attr3D ( ksCreateAttr3DExT( fObj, NULL, // Указатель на объект дерева 3D документа
																									 &parAttribute, // Структура параметров табличного атрибута
																									 numbType,      // Номер типа атрибута
																									 nameFile ) );  // Имя библиотеки
      if ( attr3D )
        attr = attr3D->GetReference();
    }
    if ( attr )     
      ViewEditAttrT( attr, 2, parAttribute.password ); // Редактирование атрибута
  }
  if ( ReturnResult() ) 
  {
    MessageBoxResult(); // Выдать сообщение об ошибке на экран
    ResultNULL();
  }
}


//-------------------------------------------------------------------------------
// Выбор листа дерева 3D документа
// ---
LPFEATURE Select3DFeature() 
{
  LPFEATURE obj = NULL;
  reference doc = ::ksGetCurrentDocument( 3 );
  if ( doc )
  {
    IUEnv<IDocument3D> doc3D( ksGet3dDocumentFromReference(doc) );
    IUEnv<IEntity> selEnt(NULL);
    if ( doc3D ) 
    { 
			selEnt.SetI( doc3D->UserSelectEntity( 0, 0, L"Укажите объект" ) );
      if ( !ReturnResult() ) 
      {
				if ( selEnt.GetI() )
        {
          obj = selEnt->GetFeature();
        }
      }
    }
  }
  return obj;
}


//-------------------------------------------------------------------------------
// Создать атрибут определенного типа
// ---
void NewAttr()
{
  if ( !doc ) 
  { 
    MessageT( _T("Не возможно создать новый атрибут") );
    return;
  }
       
  switch ( docType ) 
  {
    case lt_DocSheetStandart: // Тип документа 1- чертеж стандартный
    case lt_DocSheetUser:     //               2- чертеж нестандартный
    case lt_DocFragment:      //               3- фрагмент
    {         
      // Структура параметров запроса к системе
			RequestInfoT info;
      memset( &info, 0, sizeof( info ) );
  
      // Строка или идентификатор приглашения  
			info.prompt = _T("Укажите объект");
  
      // Координаты точки ввода  
      double x, y; 

      // Интерактивный ввод точки или команды
      if ( CursorExT( &info, &x, &y, 0, NULL ) )
      {
        // Найти ближайший к заданной точке объект вида
        reference rObject = FindObj( x, y,  // Координаты точки
                                     ksGetCursorLimit() ); // Размер стороны квадрата-ловушки с центром в точке x,y
        if ( rObject )
        {
          // Подсветить полученный объект
          LightObj( rObject, 1 );
          LibCreateAttr( rObject, NULL ); // Создание атрибута
          LightObj( rObject, 0 );
        }
      }
      break;
    }
    case lt_DocPart3D:             // 5- 3d-документ модель
    case lt_DocAssemble3D:         // 6- 3d-документ сборка
    {
      IUPTR (Feature) feature3D ( Select3DFeature() );
      if ( feature3D ) 
      {
        LibCreateAttr( NULL, feature3D ); 
      }
      break;
    }
  }
}


//-------------------------------------------------------------------------------
// Удалить атрибут
// ---
void DeleteAttributes( reference rObject )
{
  if ( rObject ) 
  {
    // Создадим итератор для хождения по атрибутам объекта
    reference rIterator = CreateAttrIterator( rObject, // Указатель на объект, если 0, то перебор всех объектов с таким атрибутом
                                                       // Если указатель на документ, то создается итератор для перебора атрибутов документа
                                              0,       // Ключи для поиска по ключам либо 0 
                                              0, 
                                              0, 
                                              0, 
                                              0 );     // Номер типа атрибута для поиска по номеру либо 0       
    if ( rIterator )
    {
      // Встали на первый атрибут
      reference rAttribute = MoveAttrIterator( rIterator, // Указатель на итератор
                                               'F',       // Тип движения 'F'/'N' 
                                                0 );      // Указатель на объект с данным атрибутом, если NULL, не заполняется
      while ( rAttribute )
      {
				TCHAR password[255] = _T("");
         
        if ( ReadStringT( _T("Ввести пароль типа атрибута"), password, 10 ) )
        {  
          // Удалить атрибут
					if ( !DeleteAttrT( rObject,     // Указатель на объект
                            rAttribute,  // Указатель на атрибут
                            password ) ) // Пароль описания атрибута
            MessageBoxResult(); // Выдать сообщение об ошибке на экран   
        }
         
        // Перебирать атрибуты по итератору, следущий объект заданного типа
        rAttribute = MoveAttrIterator( rIterator, // Указатель на итератор
                                      'N',        // Тип движения 'F'/'N'
																			 0 );       // Указатель на объект с данным атрибутом, если NULL, не заполняется
      }  
      DeleteIterator( rIterator );  
    }
  }
}


//-------------------------------------------------------------------------------
// Удалить атрибут
// ---
void DelObj2DAttr()
{
  // Структура параметров запроса к системе
	RequestInfoT info;
  memset( &info, 0, sizeof( info ) );
  
  // Строка или идентификатор приглашения  
	info.prompt = _T("Укажите объект");
  
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
      // Подсветить полученный объект
      LightObj( rObject, 1 );
      DeleteAttributes( rObject ); // Удалить атрибут
      LightObj( rObject, 0 );
    }
  }
}


//-------------------------------------------------------------------------------
// Удалить атрибут объекта 3
// ---
void DelObj3DAttr() 
{
  IUPTR (Feature) feature3D ( Select3DFeature() );
  if ( feature3D ) 
  {
    IUEnv<IAttribute3DCollection> attrColl( feature3D->AttributeCollection( 0, 0, 0, 0, 0) ); 
    int count = attrColl->GetCount();
    if ( count ) 
    {
      TCHAR buf[255];
      _stprintf( buf, _T("Количество атрибутов=%i"), count );
      MessageT( buf );

      for ( int i = count - 1; i >= 0; i-- ) 
      {
        IUEnv<IAttribute3D> attr3D( attrColl->GetByIndex(i) );
        if ( attr3D ) 
        {
					TCHAR password[255] = _T("");
           
          if ( ReadStringT( _T("Ввести пароль типа атрибута"), password, 10 ) )
          {  
            // Удалить атрибут
            if ( !ksDeleteAttr3DT( feature3D,     // Указатель на объект
                                  attr3D.GetI(), // Указатель на атрибут
                                  password ) )   // Пароль описания атрибута
              MessageBoxResult(); // Выдать сообщение об ошибке на экран   
          }            
        }  
      }
    }
  }
}


//-------------------------------------------------------------------------------
// Удалить атрибут
// ---
void DelObjAttr() {
  switch ( docType ) {
    case lt_DocSheetStandart:      // тип документа 1- чертеж стандартный
    case lt_DocSheetUser:          //               2- чертеж нестандартный
    case lt_DocFragment:           //               3- фрагмент
      DelObj2DAttr();
      break;
    case lt_DocPart3D:             //               5- 3d-документ модель
    case lt_DocAssemble3D:         //               6- 3d-документ сборка
      DelObj3DAttr();
      break;
  }
}


//-------------------------------------------------------------------------------
// Считать атрибут
// ---
void ReadObjAttr()
{
  // Структура для хранения значения ячееки таблицы атрибутов
  struct 
  {
    double d; 
    TCHAR s[MAX_TEXT_LENGTH];
    long l;
	} bufStruct;
  
  // Структура параметров запроса к системе
	RequestInfoT info;
  memset( &info, 0, sizeof( info ) );
  
  // Строка или идентификатор приглашения  
	info.prompt = _T("Укажите объект");
  
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
      // Подсветить полученный объект
      LightObj( rObject, 1 );
      MessageT( _T("Снять выделение объекта") );
      LightObj( rObject, 0 );
        
      // Создадим итератор для хождения по атрибутам объекта
      reference rIterator = CreateAttrIterator( rObject, // Указатель на объект, если 0, то перебор всех объектов с таким атрибутом
                                                         // если указатель на документ, то создается итератор для перебора атрибутов документа
                                                0,       // Ключи для поиска по ключам либо 0 
                                                0, 
                                                0, 
                                                0, 
                                                0 );     // Номер типа атрибута для поиска по номеру либо 0           
      if ( rIterator )
      {
        // Встали на первый атрибут
        reference rAttribute = MoveAttrIterator( rIterator, // Указатель на итератор
                                                 'F',       // Тип движения 'F'/'N' 
                                                 0 );       // Указатель на объект с данным атрибутом, если NULL, не заполняется        
        while ( rAttribute )
        {
          // Тип и ключи атрибута
          unsigned int key1, key2, key3, key4;
          double numbType;         
          // Получить информацию для поиска
					GetAttrKeysInfo( rAttribute,                 // Указатель на атрибут
                           &key1, &key2, &key3, &key4, // Ключи для поиска по значению 
                           &numbType );                // Номер типа атрибута для поиска по типу                          
          TCHAR buf[255];
          _stprintf( buf, _T("key1 = %d, key2 = %d, key3 = %d, key4 = %d, numbType = %f"), key1, key2, key3, key4, numbType );
          MessageT( buf );
 

          // Количество колонок
          unsigned int countColums;        
          // Получить информацию по табличному атрибуту
          GetAttrTabInfo( rAttribute,     // Указатель на атрибут
                          0,              // Количество строк
                          &countColums ); // Количество колонок       
          _stprintf ( buf, _T("countColums = %d"), countColums );
          MessageT( buf );
 
          // Информация о колонках
          ColumnInfoT parColumn; // Структура параметров колонки табличного атрибута
          // Создать динамические массивы
          parColumn.columns   = CreateArray( ATTR_COLUMN_ARR, 0 ); // Динамический массив неопределенной длины информации о колонках записи
          parColumn.fieldEnum = CreateArray( CHAR_STR_ARR_T, 0 );    // Массив строк неопределенной длины для хранения перечислений
          for ( unsigned int i = 0; i < countColums; i++ ) 
          {
            // Получить информацию по столбцу
						GetAttrColumnInfoT( rAttribute,   // Указатель на атрибут
                               0,            // Номер колоноки    
                               &parColumn ); // Структура параметров колонки табличного атрибута
              
            // Выдадим информацию о колонке
            _stprintf( buf, _T("i = %d, header = %s,\ntype = %d, def = %s, flagEnum = %d"),
                     i, parColumn.header, parColumn.type, parColumn.def, parColumn.flagEnum );
            MessageT( buf );
          }
          // Удалить динамические массивы
          DeleteArray( parColumn.columns );   // Динамический массив неопределенной длины информации о колонках записи
          DeleteArray( parColumn.fieldEnum ); // Массив строк неопределенной длины для хранения перечислений 

          // Получить строку табличного атрибута
					GetAttrRow( rAttribute,            // Указатель на атрибут
                      0,                     // Номер строки   
                      0,                     // Указатель на массив флагов видимости ячеек строки
                      &bufStruct,            // Адрес памяти для записи результата
                      sizeof( bufStruct ) ); // Длина результата
          _stprintf ( buf, _T("d = %f, s = %s, l = %ld"), bufStruct.d, bufStruct.s, bufStruct.l );
          MessageT( buf );

          // Заменим строку атрибута
          bufStruct.d = 123.123;
					lstrcpy( bufStruct.s, _T("1234567\nasdfgh\nzxcvb") );
          bufStruct.l = 88888l;
          
					ksSetAttrRowT( rAttribute,            // Указатель на атрибут
											0,                     // Номер строки
											0,                     // Указатель на массив флагов видимости ячеек строки
											0,
											&bufStruct,            // Адрес памяти содержащей значение
											sizeof( bufStruct ),   // Длина значения
											_T("111") );               // Пароль данного типа атрибута

					memset( &buf, 0, sizeof( bufStruct ) );

					// Получить строку табличного атрибута
					GetAttrRow( rAttribute,            // Указатель на атрибут
											0,                     // Номер строки
											0,                     // Указатель на массив флагов видимости ячеек строки
											&bufStruct,            // Адрес памяти для записи результата
											sizeof( bufStruct ) ); // Длина результата
          _stprintf ( buf, _T("d = %f, s = %s, l = %ld"), bufStruct.d, bufStruct.s, bufStruct.l );
          MessageT( buf );
        
          // Перебирать атрибуты по итератору, следущий объект заданного типа
          rAttribute = MoveAttrIterator( rIterator, // Указатель на итератор
                                          'N',       // Тип движения 'F'/'N' 
                                          0 );       // Указатель на объект с данным атрибутом, если NULL, не заполняется
        }
        DeleteIterator( rIterator ); 
      }  
    }
  }  
}


//-------------------------------------------------------------------------------
// Просмотреть атрибут
// ---
void ShowObj2DAttr()
{
  // Структура параметров запроса к системе
	RequestInfoT info;
  memset( &info, 0, sizeof( info ) );
  
  // Строка или идентификатор приглашения  
  info.prompt = _T("Укажите объект");
  
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
      // Подсветить полученный объект
      LightObj( rObject, 1 );        
      ChoiceAttr( rObject ); // Вывести диалог просмотра атрибутов объекта
      LightObj( rObject, 0 );
    }
  }
}


//-------------------------------------------------------------------------------
// Просмотреть атрибут 3D объекта
// ---
void ShowObj3DAttr()
{
  IUPTR (Feature) feature3D ( Select3DFeature() );
  if ( feature3D )
  {
    ksChoiceAttr3D( feature3D );
  }
}


//-------------------------------------------------------------------------------
// Просмотреть атрибут
// ---
void ShowObjAttr() {
  switch ( docType ) {
    case lt_DocSheetStandart:      // тип документа 1- чертеж стандартный
    case lt_DocSheetUser:          //               2- чертеж нестандартный
    case lt_DocFragment:           //               3- фрагмент
      ShowObj2DAttr();
      break;
    case lt_DocPart3D:             //               5- 3d-документ модель
    case lt_DocAssemble3D:         //               6- 3d-документ сборка
      ShowObj3DAttr();
      break;
  }
}


//-------------------------------------------------------------------------------
// Просмотреть библиотеку 
// ---
void ShowLib()
{
  TCHAR nameFile[255] = _T("");
  
  // Запросить имя библиотеки
	if ( !ksChoiceFileT( _T("*.lat"), NULL, nameFile, 255, 0 ) )
		nameFile[0] = '\0'; // Если библиотека не задана, то типы атрибутов берутся из документа

	// Выдать диалог для просмотра в библиотеке атрибутов списка типов атрибутов и выбора нужного типа
  double numbType = ChoiceAttrTypesT( nameFile );

  if ( numbType > 1 )  
  {
    TCHAR buf[255];
    _stprintf( buf, _T("numbType = %f"), numbType );
		MessageT( buf );
  }
}


//-------------------------------------------------------------------------------
// Просмотреть тип
// ---
void ShowType()
{
	TCHAR nameFile[255] = _T("");

	// Запросить имя библиотеки
	ksChoiceFileT( _T("*.lat"), NULL, nameFile, 255, 0 );

	double numbType = ChoiceAttrTypesT( nameFile );
	if ( numbType > 1000 ) {

		TCHAR password[255] = _T("");
    if ( ReadStringT( _T("Ввести пароль типа атрибута"), password, 255 ) )
      // Установить строку табличного атрибута
			ViewEditAttrTypeT( nameFile,   // Имя библиотеки типов атрибутов
												 2,          // Интерактивный режим ( 1 - просмотр, 2 - редактирование )
												 numbType,   // Номер типа атрибута
                         password ); // Пароль описания атрибута
  }
}


//-------------------------------------------------------------------------------
// Просмотреть атрибут 3D объекта
// ---
void WalkFromObj3DWithAttr()
{
  IUPTR (Feature) feature3D ( Select3DFeature() );             // Выбор листа дерева
  if ( feature3D )
  {
    // Получаем атрибуты листа
    IUEnv<IAttribute3DCollection> attrColl( feature3D->AttributeCollection( 0, 0, 0, 0, 0) ); 
    int count = attrColl->GetCount();                          // Количество атрибутов
    if ( count ) {
      TCHAR buf[255];
      _stprintf( buf, _T("Количество атрибутов=%i"), count );
      MessageT( buf );

      for ( int i = count - 1; i >= 0; i-- )
      {
        IUEnv<IAttribute3D> attr3D( attrColl->GetByIndex(i) ); // Получаем атрибут по индексу 
        if ( attr3D )
        {
					TCHAR* password = _T("");
					if ( ReadStringT( _T("Ввести пароль типа атрибута"), password, 255 ) )
          {
            // Подсветить группу объектов к которому прикреплен атрибут 
//            IUEnv<IChooseMng> cMng ( doc3D->GetChooseMng() );
//            IUEnv<IFeatureCollection> ifColl ( attr3D->FeatureCollection( o3d_unknown ) );
//            if ( cMng && ifColl ) {
//              for ( int i = 0, count = ifColl->GetCount(); i < count; i++ )
//                cMng->Choose( ifColl->GetByIndex(i) );
//           }
            ViewEditAttrT( attr3D->GetReference(), 1, password ); // Редактирование атрибута
//            if ( YesNo( _T("Удалить атрибут?" ) == 1 )
//              ksDeleteAttr3D( feature3D, attr3D.GetI(), password );
//            if ( cMng )
//              cMng->UnChooseAll();
          }
        }
      }
    }
  }
}


//-------------------------------------------------------------------------------
// Просмотреть атрибут
// ---
void WalkFromObj2DWithAttr()
{
  // Структура параметров запроса к системе
	RequestInfoT info;
  memset( &info, 0, sizeof( info ) );
  
  // Строка или идентификатор приглашения  
  info.prompt = _T("Укажите объект");
  
  // Координаты точки ввода  
  double x, y; 

  // Интерактивный ввод точки или команды
	if ( CursorExT( &info, &x, &y, NULL, NULL ) )
  {
    // Найти ближайший к заданной точке объект вида
    reference rObject = FindObj( x, y,  // Координаты точки
                                 1e6 ); // Размер стороны квадрата-ловушки с центром в точке x,y
    if ( rObject )
    {
      // Подсветить полученный объект
      LightObj( rObject, 1 );
			MessageT( _T("Снять выделение объекта") );
      LightObj( rObject, 0 );
        
      // Создадим итератор для поиска объектов по ключу 10
      reference rIterator = CreateAttrIterator( rObject,   // Указатель на объект, если 0, то перебор всех объектов с таким атрибутом
                                                     // если указатель на документ, то создается итератор для перебора атрибутов документа
                                                10,  // Ключи для поиска по ключам либо 0 
                                                0, 
                                                0, 
                                                0, 
                                                0 ); // Номер типа атрибута для поиска по номеру либо 0    
      if ( rIterator )
      {
        // Встали на первый атрибут
        reference rAttribute = MoveAttrIterator( rIterator, // Указатель на итератор
                                                 'F',       // Тип движения 'F'/'N'
                                                 0 );       // Указатель на объект с данным атрибутом, если NULL, не заполняется
        while ( rAttribute )
        {
          // Установить строку табличного атрибута
          ViewEditAttrT( rAttribute, // Указатель на атрибут
                        1,          // Интерактивный режим ( 1 - просмотр, 2 - редактирование )
                        0 );        // Пароль описания атрибута
          
          // Перебирать атрибуты по итератору, следущий объект заданного типа
          rAttribute = MoveAttrIterator( rIterator, // Указатель на итератор
                                        'N',        // Тип движения 'F'/'N' 
                                         0 );       // Указатель на объект с данным атрибутом, если NULL, не заполняется
        } 
        DeleteIterator( rIterator );
      }
    }
  }
}


//-------------------------------------------------------------------------------
// Просмотреть атрибут
// ---
void WalkFromObjWithAttr() 
{
  switch ( docType ) 
  {
    case lt_DocSheetStandart:  // Тип документа 1- чертеж стандартный
    case lt_DocSheetUser:      //               2- чертеж нестандартный
    case lt_DocFragment:       //               3- фрагмент
      WalkFromObj2DWithAttr();
      break;
    case lt_DocPart3D:         //               5- 3d-документ модель
    case lt_DocAssemble3D:     //               6- 3d-документ сборка
      WalkFromObj3DWithAttr();
      break;
  }
}


//-------------------------------------------------------------------------------
// Создать атрибут документа
// ---
void CreateDocumentAttr() 
{
  if ( doc ) 
    LibCreateAttr( doc, NULL );
}


//-------------------------------------------------------------------------------
// Удалить атрибуты документа
// ---
void DeleteDocumentAttr() 
{
  if ( doc ) 
    DeleteAttributes( doc ); // Удалить атрибут
}


//-------------------------------------------------------------------------------
// Просмотреть атрибут документа
// ---
void ShowDocumentAttr() 
{
  if ( doc ) 
    ChoiceAttr( doc );
}


//-------------------------------------------------------------------------------
// Создать атрибут документа
// ---
void CreateDocument3DAttr() // Создать атрибут 3D документа
{  
	if ( doc && (docType == lt_DocAssemble3D || docType == lt_DocPart3D) )
    LibCreateAttr( 0, NULL );
}
  

//-------------------------------------------------------------------------------
// Удалитьть атрибут 3D документа
// ---
void DeleteDocument3DAttr() 
{
	if ( doc && (docType == lt_DocAssemble3D || docType == lt_DocPart3D) )
  {
    IUEnv<IDocument3D> doc3D( ksGetActive3dDocument() ); // Активный 3D документ
    if ( doc3D ) 
    {
      // Атрибуты 3D документа
      IUEnv<IAttribute3DCollection> attrColl( doc3D->AttributeCollection( 0, 0, 0, 0, 0, doc3D.GetI() ) ); 
      int count = attrColl->GetCount();                  // Количество атрибутов
      if ( count ) 
      {
        TCHAR buf[255];
        _stprintf( buf, _T("Количество атрибутов=%i"), count );
        MessageT( buf );

        for ( int i = count - 1; i >= 0; i-- ) 
        {
          IUEnv<IAttribute3D> attr3D( attrColl->GetByIndex(i) ); // Следующий атрибут
          if ( attr3D ) 
          {
						TCHAR password[255] = _T("");
						if ( ReadStringT( _T("Ввести пароль типа атрибута"), password, 255 ) )
            {
              // Подсветить объекты
              IUEnv<IChooseMng> cMng ( doc3D->GetChooseMng() );
              IUEnv<IFeatureCollection> ifColl ( attr3D->FeatureCollection( o3d_unknown ) );
              if ( cMng && ifColl ) 
              {
                for ( int i = 0, count = ifColl->GetCount(); i < count; i++ )
                  cMng->Choose( ifColl->GetByIndex(i) );
              }
              // Просмотр атрибутов
              ViewEditAttrT( attr3D->GetReference(), 1, password );
              // Удаление атрибутов
							if ( YesNoT( _T("Удалить атрибут?") ) == 1 )
								ksDeleteAttr3DT( doc3D.GetI(), attr3D.GetI(), password );
							if ( cMng )
                cMng->UnChooseAll(); // Снять подсветку
            }
          }
        }
        
        attrColl->Refresh();
        count = attrColl->GetCount();
				_stprintf( buf, _T("Осталось атрибутов=%i"), count );
				MessageT( buf );
      }
    }
  }
}


//-------------------------------------------------------------------------------
// Просмотреть атрибут документа
// ---
void ShowDocument3DAttr() 
{  
	if ( doc && (docType == lt_DocAssemble3D || docType == lt_DocPart3D) )
  {
//    IUEnv<IDocument3D> doc3D( ksGetActive3dDocument() );
//    if ( doc3D ) 
			ksChoiceAttr3D( NULL ); // doc3D.GetI() );
  }
}


//-------------------------------------------------------------------------------
// Просмотреть атрибуты документа и детали сборки
// ---
void ShowObjects3DAttr() 
{  
	if ( doc && (docType == lt_DocAssemble3D || docType == lt_DocPart3D) )
  {
    IUEnv<IDocument3D> doc3D( ksGetActive3dDocument() );
    if ( doc3D ) 
    {
      // атрибуты документа
      IUEnv<IFeatureCollection> fColl ( doc3D->FeatureCollection( 0, 0, 0, 0, 0, o3d_unknown ) );
      if ( fColl )
        ksChoiceAttr3D( fColl.GetI() );                     // Просмотр атрибутов документа
    }
    if ( docType == lt_DocAssemble3D ) 
    {
      IUEnv<IPart> part0( doc3D->GetPart(0) );              // Первая деталь
      if ( part0 ) 
      {
        IUEnv<IFeature> iFeatureP0 ( part0->GetFeature() ); // Лист первой детали
        if ( iFeatureP0 )
        {
          // Листы элеменов детали
          IUEnv<IFeatureCollection> fCollP0 ( iFeatureP0->SubFeatureCollection( true, true ) );
          if ( fCollP0 )
            ksChoiceAttr3D( fCollP0.GetI() );               // Просмотр атрибутов
        }
      }
    }
  }
}