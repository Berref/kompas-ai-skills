//////////////////////////////////////////////////////////////////////////////// 
// 
// step10.cpp - Работа с объектами спецификации
// 
// 1. Cоздадим тип атрибута болта             - TypeAttrBolt
// 2. Cоздать объект спецификации деталь      - CreateDet
// 3. Cоздать стандартный объект              - CreateStandart
// 4. Конвертировать спецификацию во фрагмент - DecomposeSpc
// 5. Просмотреть спецификацию                - ShowSpc
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
void TypeAttrBolt();
void CreateDet();
void CreateStandart();
void DecomposeSpc();
void ShowSpc();


//-------------------------------------------------------------------------------
// Головная функция библиотеки
// ---
void WINAPI LIBRARYENTRY( unsigned int comm )
{
  if ( comm == 2 || comm == 3 )
  {
    if ( ksGetCurrentDocument( 1 ) ) // Получить указатель на текущий графический документ
    {
      switch ( comm )
      {
        case 2 : CreateDet();      break; // Cоздать объект спецификации деталь
        case 3 : CreateStandart(); break; // Cоздать стандартный объект
      }
    }
    else
      ErrorT( _T("Документ не активизирован или\nне является листом/фрагментом") );
  }
  else
  {
    switch ( comm )
    {
      case 1 : TypeAttrBolt(); break; // Cоздадим тип атрибута болта
      case 4 : DecomposeSpc(); break; // Конвертировать спецификацию во фрагмент
      case 5 : ShowSpc();      break; // Просмотреть спецификацию
    }
  }
}


//-------------------------------------------------------------------------------
// Пример создания шаблона обозначения для стандартного изделия "Болт"
// Шаблон обозначения можно создать визуальными средствами, предоставленными графиком для
// создания типа атрибута. Этот способ не требует непосредственного программирования, 
// но влечет к затратам времени на создание шалона, а при потере данных в библиотеке
// потребует повторного создания утраченного шаблона.
// Можно создать шаблон обозначения средствами apptool из библиотеки.

// Полное обозначение болта :
//   Болт 1 М12 х 1.25 -6g x 60.58.35X.16 ГОСТ 7808 - 70

// Представим это обозначение в виде компонент :

// Номер | Имя компоненты | Умолчательное значение | Тип     | Очередность сортировки
//       |                |                        |         |
// 1     | Имя элем.      | Болт                   | строка  | 1
// 2     | Исполнение     | 1                      | uint    | 3
// 3     | Резьба         | М                      | строка  | 0       ( не сортируется )
// 4     | Диаметр        | 12                     | uint    | 4 или 3 ( сортирует подряд )
// 5     | Разделитель    | х                      | строка  | 0       ( не сортируется )
// 6     | Шаг            | 1.25                   | float   | 5 или 3 ( сортирует подряд )
// 7     | Поле допуска   | -6g                    | строка  | 6 или 3 ( сортирует подряд )
// 8     | Разделитель    | х                      | строка  | 0       ( не сортируется )
// 9     | Длина          | 60                     | uint    | 7 или 3 ( сортирует подряд )
// 10    | Кл. прочности  | .58                    | строка  | 0       ( не сортируется )
// 11    | Материал       | .35Х                   | строка  | 0       ( не сортируется )
// 12    | Покрытие       | .16                    | строка  | 0       ( не сортируется )
// 13    | ГОСТ           | ГОСТ                   | строка  | 0       ( не сортируется )
// 14    | Номер          | 7808                   | uint    | 2
// 15    | Разделитель    | -                      | строка  | 0       ( не сортируется )
// 16    | Год            | 70                     | строка  | 0       ( не сортируется )


//-------------------------------------------------------------------------------
// Структура для хранения информации о болте
// ---
struct BOLT
{
  float          dr;    // Диаметр резьбы
  float          p;     // Шаг резьбы 
  float          s;     // Размер под ключ
  float          h;     // Высота головки 
  float          D;     // Диаметр описанной окружности
  float          d3;    // Диаметр отверстия в стержне
  float          h2;    // Высота подголовка
  float          L;     // Ддлина стержня
  float          l1;    // Расстояние до отверстия в стержне
  float          b;     // Длина резьбовой части
  float          d2;    // Диаметр под головкой
  float          z4;    // Величина фаски конца
  short          k;     // Расположение резьбы ( 1 - длина резьбы ниже ломманной( резьба только на b ), 2 - выше ломанной ( резьба до головки и на в ) )
  unsigned short f;     // Битовые маски
  short          klass; // Класс точности
  unsigned short gost;  // Номер госта
};


//-------------------------------------------------------------------------
// Ключи определены в стиле спецификации
// ---
#define ST_KEY1                 100       // Ключи для стандапртных изделий
#define ST_KEY2_GOST            5         
#define ST_KEY3                 1
#define ATTR_TYPE_LIB_NAME_KEY3 _T("spc.lat") // Имя библиотеки типов атрибутов
#define SPC_NAME                5         // Наименование

#define ISPOLN                  0x80      // Исполнение 1 ( > 0 ), исполнение 2
#define PITCH                   0x2       // Крупный шаг ( > 0 ), мелкий шаг


//-------------------------------------------------------------------------
// Cоздадим тип атрибута болта
// ---
void TypeAttrBolt()
{
  // Инициализация данных для создания шаблона
    
  ksAttributeTypeT parAttributeType; // Структура параметров типа табличного атрибута

  // Заполним структуру типа атрибута  
  _tcscpy_s( parAttributeType.header, _T("Болт") );   // Заголовoк-комментарий типа
  _tcscpy_s( parAttributeType.password, _T("") );     // Пароль, если не пустая строка - защищает от несанкционированного изменения типа
  parAttributeType.rowsCount   = 1;            // Количество строк в таблице
  parAttributeType.flagVisible = 1;            // флаг видимости атрибута в таблице ( видимый, невидимый в таблице )
  parAttributeType.columns     = CreateArray( ATTR_COLUMN_ARR, 0 ); // Динамический массив компонент записи
  parAttributeType.key1        = ST_KEY1;      // Рекомендуется как код разработчика
  parAttributeType.key2        = ST_KEY2_GOST; // Рекомендуется как код атрибута
  parAttributeType.key3        = ST_KEY3;      // Рекомендуется как код разработчика
  parAttributeType.key4        = 0;            // Системный код атрибута
  
  ColumnInfoT parColumnInfo; // Структура параметров одного столбца табличного атрибута

  // Массив полей записи
  // Колонка 1 "Имя элем."
  _tcscpy_s( parColumnInfo.header, _T("Имя элем.") ); // Заголовoк-комментарий столбца
  _tcscpy_s( parColumnInfo.def, _T("Болт") );         // Значение по умолчанию
  parColumnInfo.type      = STRING_ATTR_TYPE;  // Тип данных в столбце - <ltdefine.h>
  parColumnInfo.key       = 1;                 // Дополнительный признак, очередность сортировки
  parColumnInfo.flagEnum  = 0;                 // Флаг включающий режим, когда значение поля атрибута
                                               // будет заполнятся из массива перечисленных значений 1 и 0 отключон
  parColumnInfo.fieldEnum = 0;                 // Массив неопределенной длины перечислений ( строки )
  parColumnInfo.columns   = 0;                 // Массив неопределенной длины информации о колонках для записи

  // Добавим компоненту в массив компонент
  AddArrayItem( parAttributeType.columns, -1, &parColumnInfo, sizeof( parColumnInfo ) );

  // Колонка 2 "Исполнение"
  _tcscpy_s( parColumnInfo.header, _T("Исполнение") ); // Заголовoк-комментарий столбца
  parColumnInfo.type = UINT_ATTR_TYPE;          // Тип данных в столбце - <ltdefine.h>
  parColumnInfo.key = 3;                        // Дополнительный признак,  очередность сортировки
  _tcscpy_s( parColumnInfo.def, _T("1") );             // Значение по умолчанию

  // Добавим компоненту в массив компонент
  AddArrayItem( parAttributeType.columns, -1, &parColumnInfo, sizeof( parColumnInfo ) );

  // Колонка 3 "Резьба"
  _tcscpy_s( parColumnInfo.header, _T("Резьба") ); // Заголовoк-комментарий столбца
  parColumnInfo.type = STRING_ATTR_TYPE;    // Тип данных в столбце - <ltdefine.h>
  parColumnInfo.key = 0;                    // Очередность сортировки
  _tcscpy_s( parColumnInfo.def, _T("М") );         // Значение по умолчанию

  // Добавим компоненту в массив компонент
  AddArrayItem( parAttributeType.columns, -1, &parColumnInfo, sizeof( parColumnInfo ) );

  // Колонка 4 "Диаметр"
  _tcscpy_s( parColumnInfo.header, _T("Диаметр") ); // Заголовoк-комментарий столбца
  parColumnInfo.type = UINT_ATTR_TYPE;       // Тип данных в столбце - <ltdefine.h>
  parColumnInfo.key = 3;                     // Очередность сортировки
  _tcscpy_s( parColumnInfo.def, _T("12") );         // Значение по умолчанию

  // Добавим компоненту в массив компонент
  AddArrayItem( parAttributeType.columns, -1, &parColumnInfo, sizeof( parColumnInfo ) );

  // Колонка 5 "Разделитель"
  _tcscpy_s( parColumnInfo.header, _T("") );    // Заголовoк-комментарий столбца
  parColumnInfo.type = STRING_ATTR_TYPE; // Тип данных в столбце - <ltdefine.h>
  parColumnInfo.key = 0;                 // Очередность сортировки
  _tcscpy_s( parColumnInfo.def, _T("х") );      // Значение по умолчанию

  // Добавим компоненту в массив компонент
  AddArrayItem( parAttributeType.columns, -1, &parColumnInfo, sizeof( parColumnInfo ) );

  // Колонка 6 "Шаг"
  _tcscpy_s( parColumnInfo.header, _T("Шаг") ); // Заголовoк-комментарий столбца
  parColumnInfo.type = FLOAT_ATTR_TYPE;  // Тип данных в столбце - <ltdefine.h>
  parColumnInfo.key = 3;                 // Очередность сортировки
  _tcscpy_s( parColumnInfo.def, _T("1.25") );   // Значение по умолчанию

  // Добавим компоненту в массив компонент
  AddArrayItem( parAttributeType.columns, -1, &parColumnInfo, sizeof( parColumnInfo ) );

  // Колонка 7 "Поле допуска"
  _tcscpy_s( parColumnInfo.header, _T("Поле допуска") ); // Заголовoк-комментарий столбца
  parColumnInfo.type = STRING_ATTR_TYPE;          // Тип данных в столбце - <ltdefine.h>
  parColumnInfo.key = 3;                          // Очередность сортировки
  _tcscpy_s( parColumnInfo.def, _T("-6g") );             // Значение по умолчанию

  // Добавим компоненту в массив компонент
  AddArrayItem( parAttributeType.columns, -1, &parColumnInfo, sizeof( parColumnInfo ) );

  // Колонка 8 "Разделитель"
  _tcscpy_s( parColumnInfo.header, _T("") );    // Заголовoк-комментарий столбца
  parColumnInfo.type = STRING_ATTR_TYPE; // Тип данных в столбце - <ltdefine.h>
  parColumnInfo.key = 0;                 // Очередность сортировки
  _tcscpy_s( parColumnInfo.def, _T("х") );      // Значение по умолчанию

  // Добавим компоненту в массив компонент
  AddArrayItem( parAttributeType.columns, -1, &parColumnInfo, sizeof( parColumnInfo ) );

  // Колонка 9 "Длина"
  _tcscpy_s( parColumnInfo.header, _T("Длина") ); // Заголовoк-комментарий столбца
  parColumnInfo.type = UINT_ATTR_TYPE;     // Тип данных в столбце - <ltdefine.h>
  parColumnInfo.key = 3;                   // Очередность сортировки
  _tcscpy_s( parColumnInfo.def, _T("60") );       // Значение по умолчанию

  // Добавим компоненту в массив компонент
  AddArrayItem( parAttributeType.columns, -1, &parColumnInfo, sizeof( parColumnInfo ) );

  // Колонка 10 "Кл. прочности"
  _tcscpy_s( parColumnInfo.header, _T("Кл. прочности") ); // Заголовoк-комментарий столбца
  parColumnInfo.type = STRING_ATTR_TYPE;           // Тип данных в столбце - <ltdefine.h>
  parColumnInfo.key = 0;                           // Очередность сортировки
  _tcscpy_s( parColumnInfo.def, _T(".58") );              // Значение по умолчанию

  // Добавим компоненту в массив компонент
  AddArrayItem( parAttributeType.columns, -1, &parColumnInfo, sizeof( parColumnInfo ) );

  // Колонка 11 "Материал"
  _tcscpy_s( parColumnInfo.header, _T("Материал") ); // Заголовoк-комментарий столбца
  parColumnInfo.type = STRING_ATTR_TYPE;      // Тип данных в столбце - <ltdefine.h>
  parColumnInfo.key = 0;                      // Очередность сортировки
  _tcscpy_s( parColumnInfo.def, _T(".35Х") );        // Значение по умолчанию

  // Добавим компоненту в массив компонент
  AddArrayItem( parAttributeType.columns, -1, &parColumnInfo, sizeof( parColumnInfo ) );

  // Колонка 12 "Покрытие"
  _tcscpy_s( parColumnInfo.header, _T("Покрытие") ); // Заголовoк-комментарий столбца
  parColumnInfo.type = STRING_ATTR_TYPE;      // Тип данных в столбце - <ltdefine.h>
  parColumnInfo.key = 0;                      // Очередность сортировки
  _tcscpy_s( parColumnInfo.def, _T(".16") );         // Значение по умолчанию

  // Добавим компоненту в массив компонент
  AddArrayItem( parAttributeType.columns, -1, &parColumnInfo, sizeof( parColumnInfo ) );

  // Колонка 13 "ГОСТ"
  _tcscpy_s( parColumnInfo.header, _T("ГОСТ") ); // Заголовoк-комментарий столбца
  parColumnInfo.type = STRING_ATTR_TYPE;  // Тип данных в столбце - <ltdefine.h>
  parColumnInfo.key = 0;                  // Очередность сортировки
  _tcscpy_s( parColumnInfo.def, _T("ГОСТ") );    // Значение по умолчанию

  // Добавим компоненту в массив компонент
  AddArrayItem( parAttributeType.columns, -1, &parColumnInfo, sizeof( parColumnInfo ) );

  // Колонка 14 "Номер"
  _tcscpy_s( parColumnInfo.header, _T("Номер") ); // Заголовoк-комментарий столбца
  parColumnInfo.type = UINT_ATTR_TYPE;     // Тип данных в столбце - <ltdefine.h>
  parColumnInfo.key = 2;                   // Очередность сортировки
  _tcscpy_s( parColumnInfo.def, _T("7808") );     // Значение по умолчанию

  // Добавим компоненту в массив компонент
  AddArrayItem( parAttributeType.columns, -1, &parColumnInfo, sizeof( parColumnInfo ) );

  // Колонка 15 "Разделитель"
  _tcscpy_s( parColumnInfo.header, _T("") );    // Заголовoк-комментарий столбца
  parColumnInfo.type = STRING_ATTR_TYPE; // тип данных в столбце - <ltdefine.h>
  parColumnInfo.key = 0;                 // Очередность сортировки
  _tcscpy_s( parColumnInfo.def, _T("-") );      // Значение по умолчанию

  // Добавим компоненту в массив компонент
  AddArrayItem( parAttributeType.columns, -1, &parColumnInfo, sizeof( parColumnInfo ) );

  // Колонка 16 "Год"
  _tcscpy_s( parColumnInfo.header, _T("Год") ); // Заголовoк-комментарий столбца
  parColumnInfo.type = STRING_ATTR_TYPE; // Тип данных в столбце - <ltdefine.h>
  parColumnInfo.key = 0;                 // Очередность сортировки
  _tcscpy_s( parColumnInfo.def, _T("70") );     // Значение по умолчанию

  // Добавим компоненту в массив компонент
  AddArrayItem( parAttributeType.columns, -1, &parColumnInfo, sizeof( parColumnInfo ) );

  // Создать шаблон обозначения
  ksCreateAttrTypeT( &parAttributeType,         // Информация о типе атрибута
                     ATTR_TYPE_LIB_NAME_KEY3 ); // Имя библиотеки типов атрибутов

  // Удалим массив колонок
  DeleteArray( parAttributeType.columns );
}


//-----------------------------------------------------------------------------------------------
// Cоздадим объект спецификации для раздела "Детали"
// ---
reference EditSpcObjDet( reference rGeom )
{
  reference rSpcObject = 0;
  
  // Если редактируем макро объект, то ввойдем в режим редактирования объекта
  if ( EditMacroMode() ) 
  {
    // Получить указатель  объекта СП по геометрии для текущего графического документа 
    rSpcObject = ksGetSpcObjForGeomWithLimitT( _T("graphic.lyt"), // Имя библиотеки типов
                                               1,                 // Номер типа спецификации
                                               0,                 // Указатель на геометрию - группа или объект, если 0 - для макрообъекта редактирования
                                               1,                 // 1 - присланная геометрия идентична геометрии объекта СП, 0 - входит в объект СП
                                               1, 0, 0 );         // 1 - первый объект, 0 - следующий объект
    // Ввойдем в режим редактирования
    if ( !ksSpcObjectEdit( rSpcObject ) )
      rSpcObject  = 0;
  }

  // Если объекта нет, создать объект спецификации в графическом документе
  if ( rSpcObject || ksSpcObjectCreateT( _T("graphic.lyt"), // Имя библиотеки типов
                                         1,             // Номер типа спецификации
                                         20,            // Номер раздела
                                         0,             // Номер подраздела
                                         0,             // Для базового объекта - тип атрибута, который задан по ключам или 0, 
                                                        // для вспомогательного объекта - номер базового объекта либо 0
                                         0 ) )          // Тип строки спецификации 
  {
    // Изменить значение компоненты - наименование
    ksSpcChangeValueT( SPC_NAME,            // Номер колонки, начиная с единицы
                       1,                   // Номер компоненты, начиная с единицы
                       _T("Втулка"),        // Указатель на значение
                       STRING_ATTR_TYPE  ); // Тип значения компоненты - <ltdefine.h>

    // Подключим геометрию
    if ( rGeom )
      ksSpcIncludeReference( rGeom, 1 );

    rSpcObject = ksSpcObjectEnd(); // Завершить объект спецификации
    
    // Если объект спецификации создан дадим возможность пользователю на него посмотреть и
    // отредактировать функцию нужно запускать вне Cursor и Placement
    if ( rSpcObject )
      if ( ksEditWindowSpcObject( rSpcObject ) ) // Редактирование объекта спецификации, запускает окно редактирования
                                                 // для объекта спецификации, расположенного в графическом документе
        return rSpcObject;
  }
  return 0;
}


//----------------------------------------------------------------------------------------------
// Отрисовать позиционную линию выноски
// Уже проверено, что объект спецификации есть
// Функцию нужно запускать вне Cursor и Placement
// ---
void DrawPosLeader( reference rSpcObject )
{
  // Структура параметров запроса к системе
  RequestInfoT info;
    
  // Координаты точки ввода
  double x, y;

  // Позиционная линия выноски
  reference rPosLeater = 0;

  // Повторить запрос к системе
  bool repeat;
  
  do
  {
    repeat = false;    
    memset( &info, 0, sizeof( info ) );
    // Строка или идентификатор меню состава команд 
    info.commands = ( LPTSTR )MENU_POS_LEADER;
    // Cтрока или идентификатор приглашения
    info.prompt = _T("Укажите позиционную линию выноски");
    // Интерактивный ввод точки или команды
    int comm = CursorExT( &info, &x, &y, NULL, NULL );
    switch ( comm ) 
    {
      case 1: // Создать новую линию выноски
        rPosLeater = ksCreateViewObject( POSLEADER_OBJ );
        break;
      case 2: // Подключить существующую
        memset( &info, 0, sizeof( info ) );
        // Строка или идентификатор меню состава команд 
        info.prompt = _T("Укажите линию выноски");
        // Интерактивный ввод точки или команды
        if ( CursorExT( &info, &x, &y, NULL, NULL ) )
        {
          // Найти ближайший к заданной точке объект вида
          rPosLeater = FindObj( x, y,  // Координаты точки
                                100 ); // Размер стороны квадрата-ловушки с центром в точке x,y
          // Узнать тип полученного графического объекта
          if ( !( rPosLeater && GetObjParam( rPosLeater, 0, 0, 0 ) == POSLEADER_OBJ ) ) 
          {
            ErrorT( _T("Объект не позиционная линия выноски!") );
            rPosLeater = 0;
            repeat = true;
          }
        }
        break;
      case -1:
        // Найти ближайший к заданной точке объект вида
        rPosLeater = FindObj( x, y,  // Координаты точки
                              100 ); // Размер стороны квадрата-ловушки с центром в точке x,y
        // Узнать тип полученного графического объекта
        if ( !( rPosLeater && GetObjParam( rPosLeater, 0, 0, 0 ) == POSLEADER_OBJ ) ) 
        {
          ErrorT( _T("Объект не позиционная линия выноски!") );
          rPosLeater = 0;
          repeat = true;
        }
        break;
    }
  }  while ( repeat );
 
  // Линия выноски есть, подключим ее к объекту спецификации
  if ( rPosLeater ) 
  {
    // Ввойдем в режим редактирования объекта спецификации и подключим линию выноски
    if ( ksSpcObjectEdit( rSpcObject ) ) // Принять объект спецификации для редактирования
    {
      // Добавить или изменить геометрию или линии-выноски в объекте спецификации
      ksSpcIncludeReference( rPosLeater, // Группа объектов или объект вида 
                             true );     // 1 - очистить предыдущую геометрию, 0 - добавить к предыдущей      
      ksSpcObjectEnd(); // Завершить объект спецификации
    }
  }
}


//-------------------------------------------------------------------------------
// Cоздать объект спецификации деталь  
// ---
void CreateDet()
{
  // Создание группы объектов, type - тип группы ( 0 - определяет модельный, 1 - временный )
  reference rGroup = NewGroup( 0 );
    LineSeg ( 20, 30, 70, 30, 2 );
    LineSeg ( 70, 30, 70, 80, 2 );
    LineSeg ( 70, 80, 20, 80, 2 );
    LineSeg ( 20, 80, 20, 30, 2 );
  EndGroup(); // Завершить создание группы объектов
 
  // Создать объект спецификации
  reference rSpcObject = EditSpcObjDet( rGroup ); // Cоздадим объект спецификации для раздела "Детали"
  if ( rSpcObject )
    DrawPosLeader( rSpcObject ); // Отрисовать позиционную линию выноски
}


//-----------------------------------------------------------------------------------------------
// Cоздадим объект спецификации для раздела "Стандартные изделия"
// ---
reference EditStandartSpcObj( BOLT &bolt, reference rGeom )
{
  reference rSpcObject = 0;
  
  // Если редактируем макро объект, то ввойдем в режим редактирования объекта
  if ( EditMacroMode() ) 
  {
    // Получить указатель  объекта СП по геометрии для текущего графического документа 
    rSpcObject = ksGetSpcObjForGeomWithLimitT( _T("graphic.lyt"), // Имя библиотеки типов
                                               1,             // Номер типа спецификации
                                               0,             // Указатель на геометрию - группа или объект, если 0 - для макрообъекта редактирования
                                               1,             // 1 - присланная геометрия идентична геометрии объекта СП, 0 - входит в объект СП
                                               1, 0, 0 );           // 1 - первый объект, 0 - следующий объект
    // Ввойдем в режим редактирования
    if ( !ksSpcObjectEdit( rSpcObject ) )
      rSpcObject  = 0;
  }

  // Если объекта нет, создать объект спецификации в графическом документе
  if ( rSpcObject || ksSpcObjectCreateT( _T("graphic.lyt"),  // Имя библиотеки типов
                                         1,              // Номер типа спецификации
                                         25,             // Номер раздела
                                         0,              // Номер подраздела
                                         313277777065.0, // Для базового объекта - тип атрибута, который задан по ключам или 0, 
                                                        // для вспомогательного объекта - номер базового объекта либо 0,
                                                        // определен в библиотеке типов атрибутов spc.lat
                                         0 ) )           // Тип строки спецификации 
  {
    unsigned int uBuf;
   
    // Исполнение
    if ( !( bolt.f & ISPOLN ) )       // Если исполнения нет
      ksSpcVisible( SPC_NAME, 2, 0 ); // Выключим исполнение
    else 
    {
      uBuf = ( unsigned int ) 2;
      ksSpcVisible( SPC_NAME, 2, 1 ); // Включить исполнение
      // Изменить значение компоненты - исполнение
      ksSpcChangeValueT( SPC_NAME,          // Номер колонки, начиная с единицы
                         2,                 // Номер компоненты, начиная с единицы
                         &uBuf,             // Указатель на значение
                         UINT_ATTR_TYPE  ); // Тип значения компоненты - <ltdefine.h>
    }  

    // Изменить значение компоненты - диаметр
    ksSpcChangeValueT( SPC_NAME, 4, &bolt.dr, FLOAT_ATTR_TYPE  );

    // Мелкий шаг
    if ( !( bolt.f & PITCH ) ) // Если мелкого шага нет
    {
      // Выключить шаг и его разделитель
      ksSpcVisible( SPC_NAME, 5, 0 ); 
      ksSpcVisible( SPC_NAME, 6, 0 ); // Шаг 
    }
    else 
    {
      // Включить шаг и его разделитель
      ksSpcVisible( SPC_NAME, 5, 1 ); 
      ksSpcVisible( SPC_NAME, 6, 1 ); // Шаг
      // Изменить значение компоненты - шаг
      ksSpcChangeValueT( SPC_NAME, 6, &bolt.p, FLOAT_ATTR_TYPE );
    }

    // Выключить поле допуска
    ksSpcVisible( SPC_NAME, 7, 0 );

    // Изменить длину
    uBuf = ( unsigned int ) bolt.L;
    // Изменить значение компоненты - длина
    ksSpcChangeValueT( SPC_NAME, 9, &uBuf, UINT_ATTR_TYPE  );

    // Выключить класс прочности
    ksSpcVisible( SPC_NAME, 10, 0 );

    // Выключить материал
    ksSpcVisible( SPC_NAME, 11, 0 );

    // Выключить покрытие
    ksSpcVisible( SPC_NAME, 12, 0 );

    // Изменить ГОСТ
    uBuf = ( unsigned int ) bolt.gost;
    // Изменить значение компоненты - ГОСТ
    ksSpcChangeValueT( SPC_NAME, 14, &uBuf, UINT_ATTR_TYPE  );

    // Подключим геометрию
    if ( rGeom )
      ksSpcIncludeReference( rGeom, 1 );

    rSpcObject = ksSpcObjectEnd(); // Завершить объект спецификации
    
    // Если объект спецификации создан дадим возможность пользователю на него посмотреть и
    // отредактировать функцию нужно запускать вне Cursor и Placement
    if ( rSpcObject )
      if ( ksEditWindowSpcObject( rSpcObject ) ) // Редактирование объекта спецификации, запускает окно редактирования
                                                 // для объекта спецификации, расположенного в графическом документе
         return rSpcObject;
  }
  return 0;
}


//-------------------------------------------------------------------------------
// Cоздать стандартный объект
// ---
void  CreateStandart()
{
  BOLT bolt; // Структура для хранения информации о болте
  memset( &bolt, 0, sizeof( bolt ) );
 
  bolt.gost  = 7808;  // Номер госта 
  bolt.s     = 27;    // Размер под ключ
  bolt.h     = 11;    // Высота головки 
  bolt.D     = 30.1f; // Диаметр описанной окружности
  bolt.L     = 55;    // Ддлина стержня
  bolt.l1    = 49;    // Расстояние до отверстия в стержне
  bolt.b     = 46;    // Длина резьбовой части
  bolt.h2    = 10;    // Высота подголовка
  bolt.klass = 1;     // Класс точности ( klass = B )
  bolt.d2    = 22.5;  // Диаметр под головкой
  bolt.k     = 2;     // Расположение резьбы ( 1 - длина резьбы ниже ломманной( резьба только на b ), 2 - выше ломанной ( резьба до головки и на в ) )
  bolt.dr    = 20;    // Диаметр резьбы

  // Создать объект спецификации
  reference rSpcObject = EditStandartSpcObj( bolt, 0 ); // Cоздадим объект спецификации для раздела "Стандартные изделия"
  if ( rSpcObject )
    DrawPosLeader( rSpcObject  ); // Отрисовать позиционную линию выноски
}

//-----------------------------------------------------------------------------------------------
// Конвертировать спецификацию во фрагмент
// ---
void DecomposeSpc()
{
  // Берем текущий документ спецификацию
  reference rDocument = ksGetCurrentDocument( 2 );
  if ( rDocument ) 
  {
    // Получим количество листов спецификации
    int pageCount = ksGetSpcDocumentPagesCount( rDocument );
    
    // Получим габариры одного листа спецификации
    RectParam parRect; // Структура параметров прямоугольника по диагональным точкам
    GetObjGabaritRect( rDocument, &parRect );

    // Создадим фрагмент
    DocumentParamT parDocument; // Структура параметров документа
    memset( &parDocument, 0, sizeof( parDocument ) );
    
    parDocument.regim = 0;
    parDocument.type = 3;
    CreateDocumentT( &parDocument ); // Создадим фрагмент
    
    for ( int i = 0; i < pageCount; i++ ) 
    {
      // Разбить объект
      // Функция возвращает указатель на временную группу объектов
      reference rGroup = DecomposeObj( rDocument,                    // Указатель на объект
                                       0,                            // Уровень разбиения ( 0 - отрезки, дуги, тексты, точки, 
                                                                     // 1 - отрезки, тексты, точки, 2 - отрезки, дуги, тексты,
                                                                     // 4 - отрезки, дуги, точки )
                                       0.4,                          // Стрелка прогиба
                                       ( unsigned char )( i + 1 ) ); // Признак выбранной системы координат ( 0 - разбиение
                                                                     // объекта в СК вида, 1 - разбиение объекта в СК листа ) 
      if ( rGroup ) 
      {
        // Расчет координат
        int column = i % 3;
        double x = ( parRect.pTop.x - parRect.pBot.x + 5 ) * column;
        int row = i / 3;
        double y = ( parRect.pTop.y - parRect.pBot.y + 5 ) * row;
        
        // Cдвинули группу
        MoveObj( rGroup, x, -y );
        
        // Поставить временную группу в вид
        StoreTmpGroup( rGroup ); 
        // Очистить группу объектов 
        ClearGroup( rGroup );
      }
    }
    TCHAR buf[255];
    _stprintf_s( buf, _T("Декомпозировано %d листов спецификации"), pageCount );
    MessageT( buf );
  }
  else
    ErrorT( _T("Спецификация должна быть текущей") );
}

//-----------------------------------------------------------------------------------------------
// Просмотреть текущую спецификацию
// ---
void ShowSpc()
{
  // Создаем итератор для навигации по текущей спецификации
  // Если функция вызывается в графическом документе, то итератор создается для объектов, образованных по описанию,
  // определяемому именем библиотеки стилей спецификации и номером стиля.
  // В документе-спецификации параметры nameLib и styleNumb не используются ( т.к. все объекты в ней создаются по
  // единственному описанию, однозначно определяемому текущим стилем )
  reference rIterator = CreateSpcIterator( 0,   // Имя библиотеки стилей спецификации 
                                           0,   // Номер стиля спецификации в этой библиотеке 
                                           0 ); // Тип объектов ( 0 - базовые объекты, 1 - вспомогательные объекты,
                                                // 2 - базовые и вспомогательные объекты из сортированного массива, 
                                                // 3 - все строки спецификации, в том числе заголовки разделов, резервные и т.д. )
  
  if ( rIterator ) 
  {
    // Встаем на первый объект спецификации
    reference rSpcObject = MoveIterator( rIterator, 'F' );

    TCHAR buf[255];
    TCHAR buf1[255];
    while( ExistObj( rSpcObject ) ) // Проверить существование объекта
    {
      // Узнаем количество колонок у базового объекта спецификации
      int columnCount = ksGetSpcTableColumnT( NULL,  // Имя библиотеки стилей спецификации 
                                              0,     // Номер стиля спецификации в этой библиотеке 
                                              0 );   // Признак колонок ( 0 - колонки таблицы спецификации, 1 - дополнительные колонки )
      // Пройдем по всем колонкам
      for ( int i = 1; i <= columnCount; i++ ) 
      {
        // Для текущего номера определим тип колонки, номер исполнения и блок
        SpcColumnParamT parSpcColumn; // Структура параметров колонки спецификации
        
        // По номеру колонки для данного объекта спецификации получить тип колонки, номер колонки данного типа, номер блока.
        if ( ksGetSpcColumnTypeT( rSpcObject,       // Объект спецификации
                                 i,                // Номер колонки, начиная с 1
                                 &parSpcColumn ) ) // Параметры колонки
        {
          
          // Выдать текст из определенной колонки объекта спецификации
          ksGetSpcObjectColumnTextT( rSpcObject,              // Объект спецификации
                                     parSpcColumn.columnType, // Тип колонки ( SPC_CLM_FORMAT - формат, SPC_CLM_ZONE - зона, SPC_CLM_POS - позиция,
                                                             // SPC_CLM_MARK - обозначение, SPC_CLM_NAME - наименование, SPC_CLM_COUNT - количество,
                                                             // SPC_CLM_NOTE - примечание, SPC_CLM_MASSA - масса, SPC_CLM_MATERIAL - материал,
                                                             // SPC_CLM_USER - пользовательская, SPC_CLM_KOD - код,
                                                             // SPC_CLM_FACTORY - предприятие-изготовитель )
                                     parSpcColumn.ispoln,     // Номер исполнения данного типа
                                     parSpcColumn.block,      // Номер блока, начиная с 0
                                     buf,                     // Указатель на строку, в которую требуется положить полученный текст 
                                     255 );                   // Длина строки
          
          _stprintf_s( buf1, _T(",\ncolumnType = %d, ispoln = %d, block = %d"), 
                   parSpcColumn.columnType, parSpcColumn.ispoln, parSpcColumn.block );
          _tcscat_s( buf, buf1 );

          // Для данного объекта спецификации по типу колонки и номеру блока получить номер колонки
          int colNumb = ksGetSpcColumnNumb( rSpcObject,              // Объект спецификации
                                            parSpcColumn.columnType, // Тип колонки
                                            parSpcColumn.ispoln,     // Исполнение данного типа начиная
                                            parSpcColumn.block );    // Номер блока
          _stprintf_s( buf1, _T(",\ni = %d, colNumb = %d"), i, colNumb );
          _tcscat_s( buf, buf1 );
          MessageT( buf );
        }
      }
      // Встаем на следующий объект спецификации
      rSpcObject = MoveIterator( rIterator, 'N' );
    }
    
    DeleteIterator( rIterator ); // Удалить блок параметров навигации по модели
  }
}