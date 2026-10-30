//////////////////////////////////////////////////////////////////////////////// 
// 
// step7.cpp - Hавигация по модели
// 
// 1. Хождение по виду                                         - WalkFromView 
// 2. Хождение по макроэлементу                                - WalkFromMacro 
// 3. Хождение по документам                                   - WalkFromDoc
// 4. Хождение по видам                                        - WalkViewDoc 
// 5. Хождение по именнованным и рабочим группам               - WalkGroup 
// 6. Хождение по слоям                                        - WalkLayer 
// 7. Хождение по группе                                       - WalkFromGroup 
// 8. Хождение по элементам документа с определенным атрибутом - WalkFromDocWithAttr 
// 9. Хождение по атрибутам объекта                            - WalkFromObjWithAttr 
// 10.Хождение по квалитетам                                   - WalkFromQuality
// 11.Получить отклонения                                      - QualityDefects
// 
//////////////////////////////////////////////////////////////////////////////// 
#include "stdafx.h"
#include <afxdllx.h> 
#include "resource.h"

#include <string>

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
void WalkFromView();
void WalkFromMacro();
void WalkFromDoc();
void WalkViewDoc();
void WalkGroup();
void WalkLayer();
void WalkFromGroup();
void WalkFromDocWithAttr();
void WalkFromObjWithAttr();
void WalkFromQuality();// Хождение по квалитетам
void QualityDefects();


//-------------------------------------------------------------------------------
// Головная функция библиотеки
// ---
void WINAPI LIBRARYENTRY( unsigned int comm )
{
  if ( comm == 3 )
    WalkFromDoc(); // Хождение по документам
  else
  {
    if ( ksGetCurrentDocument( 1 ) )
    {
      switch ( comm )
      {
        case 1  : WalkFromView();        break; // Хождение по виду
        case 2  : WalkFromMacro();       break; // Хождение по макроэлементу
        case 4  : WalkViewDoc();         break; // Хождение по видам
        case 5  : WalkGroup();           break; // Хождение по именнованным и рабочим группам
        case 6  : WalkLayer();           break; // Хождение по слоям
        case 7  : WalkFromGroup();       break; // Хождение по группе
        case 8  : WalkFromDocWithAttr(); break; // Хождение по элементам документа с определенным атрибутом
        case 9  : WalkFromObjWithAttr(); break; // Хождение по атрибутам объекта
        case 10 : WalkFromQuality();     break; // Хождение по квалитетам
        case 11 : QualityDefects();      break; // Получить отклонения
      }
    }
    else
        ErrorT( _T("Документ не активизирован или\nне является листом/фрагментом") );
  }
}


//-------------------------------------------------------------------------------
// Хождение по виду
// ---
void WalkFromView()
{
  // В текущем документе и виде создадим итератор для хождения по всем элементам
  reference rItObject = CreateIterator( ALL_OBJ, // Тип поиска объекта 
                                        0 );     // Указатель на объект ( для движения по группе и внутри макро )
  if ( rItObject )  
  {
    int count = 0;
    reference rObject = MoveIterator( rItObject, 'F' ); // Переместить итератор ( F - на первый объект заданного типа )  
        
    while ( rObject ) 
    {
      // Подсветить полученный объект
      LightObj( rObject, 1 );
      MessageT( _T("Снять выделение объекта") );
      LightObj( rObject, 0 );
      
      count ++;      
      rObject = MoveIterator( rItObject, 'N' ); // Переместить итератор ( N - на следущий объект заданного типа )
    }
    
    DeleteIterator( rItObject ); // Удалить блок параметров навигации по модели
      
    TCHAR buf[255];
    _stprintf_s( buf, _T("count = %d"), count );
    MessageT( buf );    
  }
}


//-------------------------------------------------------------------------------
// Хождение по макроэлементу
// ---
void WalkFromMacro()
{
  // В текущем документе и виде создадим итератор для хождения по макроэлементам
  reference rItMacro = CreateIterator( MACRO_OBJ, // Тип поиска объекта
                                       0 );       // Указатель на объект ( для движения по группе и внутри макро )
  if ( rItMacro )
  {   
    int count  = 0;
    int count1 = 0;
    reference rMacro = MoveIterator( rItMacro, 'F' ); // Переместить итератор ( F - на первый объект заданного типа ) 
     
    while ( rMacro )
    {
      // Подсветить полученный макроэлемент
      LightObj( rMacro, 1 );
      MessageT( _T("Снять выделение макроэлемента") );
      LightObj( rMacro, 0 );
       
      // Cоздаем итератор для хождения по объектам в макроэлементе
      reference rItMacroObject = CreateIterator( ALL_OBJ,  // Тип поиска объекта
                                                 rMacro ); // Указатель на объект ( для движения по группе и внутри макро )
      if ( rItMacroObject )
      {
        reference rObject = MoveIterator( rItMacroObject, 'F' ); // Переместить итератор ( F - на первый объект заданного типа )
         
        while ( rObject ) 
        {
          // Подсветить полученный в макро объект
          LightObj( rObject, 1 );
          MessageT( _T("Снять выделение объекта") );
          LightObj( rObject, 0 );
          
          count1++;          
          rObject = MoveIterator( rItMacroObject, 'N' ); // Переместить итератор ( N - на следущий объект заданного типа )
        }
         
        DeleteIterator( rItMacroObject ); // Удалить блок параметров навигации по модели
      }
      
      count++;      
      rMacro = MoveIterator( rItMacro, 'N' ); // Переместить итератор ( N - на следущий объект заданного типа )
    }
    
    DeleteIterator( rItMacro ); // Удалить блок параметров навигации по модели
   
    TCHAR buf[255];
    _stprintf_s( buf, _T("count = %d, count1 = %d"), count, count1 );
    MessageT( buf );
  }
}


//-------------------------------------------------------------------------------
// Хождение по документам
// ---
void WalkFromDoc()
{
  DocumentParamT parDocument; // Структура параметров документа 

  lstrcpy( parDocument.comment, _T("Create document") ); // Комментарий к документу
  lstrcpy( parDocument.author, _T("User") );   // Автор документа
  parDocument.regim                = 0;    // Режим ( 0 - видимый, 1 - слепой )
  parDocument.type                 = 1;    // Тип документа
  parDocument.sheet.stPar.format   = 3;    // Формат листа  0 (А0) ... 4(А4)
  parDocument.sheet.stPar.multiply = 1;    // Кратность формата
  parDocument.sheet.stPar.direct   = 0;    // Расположение штампа ( 0 - вдоль короткой стороны, 1 - вдоль длинной )
  parDocument.sheet.shtType        = 1;    // Тип штампа из указанной библиотеки			
  parDocument.sheet.layoutName[0]  = _T('\0'); // Имя библиотеки оформления, пустая строка - библиотека "Graphic.lyt"

  // Создать три документа КОМПАС-ГРАФИК
  lstrcpy( parDocument.fileName, _T("a.cdw") ); // Имя  файла документа
  CreateDocumentT( &parDocument ); 
  lstrcpy( parDocument.fileName, _T("b.cdw") ); 
  CreateDocumentT( &parDocument ); 
  lstrcpy( parDocument.fileName, _T("c.cdw") ); 
  CreateDocumentT( &parDocument );  

  // Cоздаем итератор для хождения по документам
  reference rItDocument = CreateIterator( DOCUMENT_OBJ, // Тип поиска объекта
                                          0 );          // Указатель на объект ( для движения по группе и внутри макро )  
  if ( rItDocument ) 
  {
    int count = 0;
    reference rDocument = MoveIterator( rItDocument, 'F' ); // Переместить итератор ( F - на первый объект заданного типа )
    
    while ( rDocument )
    {
      // Активизируем документ
      SetObjParam( rDocument, 0, 0, DOCUMENT_STATE );
      switch ( count ) 
      {
        case 1: // В первом документе создадим отрезок
          LineSeg( 20, 10, 40, 10, 1 );
          break;
        case 2: // Во втором документе создадим окружность
          Circle ( 50, 50, 20, 1 );
          break;
        case 3: // В третьем документе создадим  дугу
          ArcByAngle( 50, 50, 20, 45, 135, 1, 1 );
      }
      
      count ++;
      rDocument = MoveIterator( rItDocument, 'N' ); // Переместить итератор ( N - на следущий объект заданного типа )
    }
    
    DeleteIterator( rItDocument ); // Удалить блок параметров навигации по модели
   
    TCHAR buf[255];
    _stprintf_s( buf, _T("count = %d"), count );
    MessageT( buf );   
  }
}


//-------------------------------------------------------------------------------
// Хождение по видам
// ---
void WalkViewDoc()
{ 
  ViewParamT par; // Структура параметров вида
 
  par.x     = 10; // Точка привязки вида
  par.y     = 20; 
  par.scale = 1;  // Масштаб вида
  par.ang   = 0;  // Угол поворота вида
  par.color = RGB( 10, 20, 10 );   // Цвет вида в активном состоянии
  par.state = stACTIVE;            // Состояние вида
  _tcscpy_s( par.name, _T("User view") ); // Имя вида
 
  // Создадим 3 вида, если они не были созданы ранее
  for ( int i = 1; i < 4; i++ ) 
    CreateSheetViewT( &par, &i ); // Создание нового вида чертежа, если вид с данным
                                 // номером существует, ничего не создается 

  
  // Создадим итератор для навигации по видам в документе
  reference rItView = CreateIterator( VIEW_OBJ, // Тип поиска объекта
                                      0 );      // Указатель на объект ( для движения по группе и внутри макро )
  if ( rItView ) 
  {
    int count = 0;
    reference rView = MoveIterator ( rItView, 'F' ); // Переместить итератор ( F - на первый объект заданного типа )
    
    while ( rView )
    {
      // Активизируем вид
      int state = stCURRENT;
      SetObjParam( rView, &state, sizeof( int ), VIEW_LAYER_STATE );

      switch ( count )
      {
        case 1: // В первом виде создадим отрезок
          LineSeg( 20, 20, 40, 20, 1 );
          break;
        case 2: // Во втором виде создадим окружность
          Circle( 40, 20, 30, 1 );
          break;
        case 3: // В третьем виде создадим  дугу
          ArcByAngle( 50, 50, 20, 45, 135, 1, 1 );
          break;
      } 
      
      count++;
      rView = MoveIterator ( rItView, 'N' ); // Переместить итератор ( N - на следущий объект заданного типа )
    }
    
    DeleteIterator( rItView ); // Удалить блок параметров навигации по модели
   
    TCHAR buf[255];
    _stprintf_s( buf, _T("count = %d"), count );
    MessageT( buf );   
  }
}


//-------------------------------------------------------------------------------
// Хождение по именнованным и рабочим группам
// ---
void WalkGroup()
{
  // Создадим итератор для движения по именнованным группам в документе
  reference rItNameGroup = CreateIterator( NAME_GROUP_OBJ, // Тип поиска объекта
                                         0 );            // Указатель на объект ( для движения по группе и внутри макро )
  if ( rItNameGroup ) 
  {
    int count = 0;
    reference rNameGrp = MoveIterator( rItNameGroup, 'F' ); // Переместить итератор ( F - на первый объект заданного типа ) 
    
    while ( rNameGrp ) 
    {
      // Подсветить полученную группу
      LightObj( rNameGrp, 1 );
      MessageT( _T("Снять выделение группы") );
      LightObj( rNameGrp, 0 );
      
      count ++;
      rNameGrp = MoveIterator( rItNameGroup, 'N' ); // Переместить итератор ( N - на следущий объект заданного типа )
    }
    
    DeleteIterator( rItNameGroup ); // Удалить блок параметров навигации по модели
    
    TCHAR buf[255];
    _stprintf_s( buf, _T("count = %d"), count );
    MessageT( buf );     
  }
  
  // Создание группы объектов, type - тип группы ( 0 - определяет модельный, 1 - временный )
  NewGroup( 0 );
    Circle( 30, 30, 20, 1 );
    Circle( 30, 30, 10, 1 );
    // Штриховка окружностей
    Hatch( 0, 45, 2, 0, 0, 0 );
      Circle( 30, 30, 20, 1 );
      Circle( 30, 30, 10, 1 );
    EndObj(); 
  EndGroup(); // Завершить создание группы объектов
  
  // Все именнованные группы ложатся в массив рабочих групп
  // Создадим итератор для движения по рабочим группам в документе
  reference rItWorkGroup = CreateIterator( WORK_GROUP_OBJ, // Тип поиска объекта
                                           0 );            // Указатель на объект ( для движения по группе и внутри макро )
  if ( rItWorkGroup ) 
  {
    int count1 = 0;
    reference rWorkGrp = MoveIterator( rItWorkGroup, 'F' ); // Переместить итератор ( F - на первый объект заданного типа ) 
    
    while ( rWorkGrp )
    {
      // Подсветить полученную группу
      LightObj( rWorkGrp, 1 );
      MessageT( _T("Снять выделение группы") );
      LightObj( rWorkGrp, 0 );
      
      count1 ++;
      rWorkGrp = MoveIterator( rItWorkGroup, 'N' ); // Переместить итератор ( N - на следущий объект заданного типа )
    }
    
    DeleteIterator( rItWorkGroup ); // Удалить блок параметров навигации по модели
    
    TCHAR buf[255];
    _stprintf_s( buf, _T("count1 = %d"), count1 );
    MessageT( buf );     
  }
}


//-------------------------------------------------------------------------------
// Хождение по слоям
// ---
void WalkLayer()
{
  // Создадим 3 слоя, если они не были созданы ранее
  for ( int i = 0; i < 5; i++ )
  {
    Layer( i ); // Переопределение текущего слоя, если слоя с заданным номером нет, такой слой создается.
    Circle( 30, 30, 5 + i * 10, 1 ); // На каждом слое создадим окружность
  }

  // Создаем итератор по слоям
  reference rItLayer = CreateIterator( LAYER_OBJ, // Тип поиска объекта
                                       0 );       // Указатель на объект ( для движения по группе и внутри макро )
  if ( rItLayer ) 
  {
    int count = 0;
    reference rLayer = MoveIterator( rItLayer, 'F' ); // Переместить итератор ( F - на первый объект заданного типа )
    
    while ( rLayer )
    {
      // Подсветить полученный слой
      LightObj( rLayer, 1 );
      MessageT( _T("Снять выделение слоя") );
      LightObj( rLayer, 0 );
      
      count ++;
      rLayer = MoveIterator ( rItLayer, 'N' ); // Переместить итератор ( N - на следущий объект заданного типа )
    }
    
    DeleteIterator( rItLayer ); // Удалить блок параметров навигации по модели
   
    TCHAR buf[255];
    _stprintf_s( buf, _T("count = %d"), count );
    MessageT( buf );   
  }
}


//-------------------------------------------------------------------------------
// Хождение по группе
// ---
void WalkFromGroup()
{
  // Создание группы объектов, type - тип группы ( 0 - определяет модельный, 1 - временный )
  reference rGroup = NewGroup( 0 );
    LineSeg( 10, 50, 50, 50, 1 );
    LineSeg( 10, 10, 50, 10, 1 );
    LineSeg( 10, 10, 10, 50, 1 );
    LineSeg( 50, 10, 50, 50, 1 );
    Circle( 30, 30, 20, 1 );
    Circle( 30, 30, 10, 1 );
    // Штриховка окружностей
    Hatch( 0, 45, 2, 0, 0, 0 );  
      Circle( 30, 30, 20, 1 );
      Circle( 30, 30, 10, 1 );
    EndObj();
  EndGroup(); // Завершить создание группы объектов

  // Создать итератор для хождения по группе
  reference rItObject = CreateIterator( ALL_OBJ,  // Тип поиска объекта
                                        rGroup ); // Указатель на объект ( для движения по группе и внутри макро )
  
  if ( rItObject ) 
  {
    int count = 0;
    reference rObject = MoveIterator ( rItObject, 'F' ); // Переместить итератор ( F - на первый объект заданного типа )
    
    while ( rObject )
    {
      // Подсветить полученный объект
      LightObj( rObject, 1 );
      MessageT( _T("Снять выделение объекта") );
      LightObj( rObject, 0 );
      
      count ++;
      rObject = MoveIterator( rItObject, 'N' ); // Переместить итератор ( N - на следущий объект заданного типа )
    }
    
    DeleteIterator( rItObject ); // Удалить блок параметров навигации по модели
   
    TCHAR buf[255];
    _stprintf_s( buf, _T("count = %d"), count );
    MessageT( buf );   
  }
}


//-------------------------------------------------------------------------------
// Хождение по элементам документа с определенным атрибутом
// Пройтись по объектам документа, у которых есть атрибут с ключом
// key1 = 10 и выдать количество колонок и строк для данного атрибута
// ---
void WalkFromDocWithAttr()
{
  // Создадим итератор для поиска объектов по ключу 10
  reference rIterator = CreateAttrIterator( 0,   // Указатель на объект, если 0, то перебор всех объектов с таким атрибутом
                                                 // если указатель на документ, то создается итератор для перебора атрибутов документа
                                            10,  // Ключи для поиска по ключам либо 0 
                                            0, 
                                            0, 
                                            0, 
                                            0 ); // Номер типа атрибута для поиска по номеру либо 0  
  // Неудачное завершение - выдадим результат работы нашей функции
  if ( rIterator ) 
  {
  
    reference rObject; 
    // Перебирать атрибуты по итератору ( F - на первый объект заданного типа )
    reference rAttribute = MoveAttrIterator( rIterator,  // Указатель на итератор
                                             'F',        // Тип движения 'F'/'N'
                                             &rObject ); // Указатель на объект с данным атрибутом, если NULL, не заполняется
    int count = 0;
    TCHAR buf[255];

    while ( rAttribute && rObject )
    {
      count ++;       
      // Подсветить полученный объект
      LightObj( rObject, 1 );
       
      unsigned int countRows, countColumns;  
      
      // Узнаем количество строк и колонок табличного атрибута
      if ( GetAttrTabInfo( rAttribute, &countRows, &countColumns ) )
      {
        _stprintf_s( buf, _T("count = %d, countRows = %d, columnsCount = %d"), count, countRows, countColumns );
        MessageT( buf );
      }
      else
        // Неудачное завершение - выдадим результат работы нашей функции
        MessageBoxResult(); // Выдать сообщение об ошибке на экран   

      LightObj( rObject, 0 );
      
      // Перебирать атрибуты по итератору ( N - на следущий объект заданного типа )
      rAttribute = MoveAttrIterator( rIterator,  // Указатель на итератор
                                     'N',        // Тип движения 'F'/'N'
                                     &rObject ); // Указатель на объект с данным атрибутом, если NULL, не заполняется
    }
    DeleteIterator( rIterator ); // Удалить блок параметров навигации по модели
 
    _stprintf_s( buf, _T("count = %d"), count );
    MessageT( buf );   
  }
}


//-------------------------------------------------------------------------------
// Хождение по атрибутам объекта
// Пройтись у объекта, по атрибутам с ключом
// key1 = 10 и выдать количество колонок и строк для данного атрибута
// ---
void WalkFromObjWithAttr()
{
  // Структура параметров запроса к системе
  RequestInfoT info;
  memset( &info, 0, sizeof( info ) );
  
  // Строка или идентификатор меню состава команд 
  info.prompt = _T("Укажите объект");
  
  // Координаты точки ввода
  double x, y;  
  
  reference rObject;
  
  // Интерактивный ввод точки или команды
  while( CursorExT( &info, &x, &y, 0, NULL ) )
  {
    // Найти ближайший к заданной точке объект вида
    rObject = FindObj( x, y,  // Координаты точки
                       1e6 ); // Размер стороны квадрата-ловушки с центром в точке x,y
    // Проверить существование объекта
    if ( rObject )
    { 
      // Создадим итератор для движения по атрибутам с ключом 10
      reference rIterator = CreateAttrIterator( rObject, // Указатель на объект, если 0, то перебор всех объектов с таким атрибутом
                                                         // если указатель на документ, то создается итератор для перебора атрибутов документа
                                                10,      // Ключи для поиска по ключам либо 0 
                                                0, 
                                                0, 
                                                0, 
                                                0 );     // Номер типа атрибута для поиска по номеру либо 0        
      // Неудачное завершение - выдадим результат работы нашей функции
      if ( rIterator ) 
      {
        // Подсветить полученный объект
        LightObj( rObject, 1 );
     
        // Перебирать атрибуты по итератору ( F - на первый объект заданного типа ) 
        reference rAttribute = MoveAttrIterator( rIterator, // Указатель на итератор
                                                 'F',       // Тип движения 'F'/'N'
                                                 0 );       // Указатель на объект с данным атрибутом, если NULL, не заполняется
        int count = 0;
        TCHAR buf[255];

        while ( rAttribute ) 
        {
          unsigned int countRows, countColumns;  
                  
          count ++;            
          // Узнаем количество строк и колонок табличного атрибута
          if ( GetAttrTabInfo( rAttribute, &countRows, &countColumns ) )
          {
            _stprintf_s( buf, _T("count = %d, countRows = %d, columnsCount = %d"), count, countRows, countColumns );
            MessageT( buf );
          }
          else
            // Неудачное завершение - выдадим результат работы нашей функции
            MessageBoxResult(); // Выдать сообщение об ошибке на экран  
          
          // Перебирать атрибуты по итератору ( N - на следущий объект заданного типа )
          rAttribute = MoveAttrIterator( rIterator, // Указатель на итератор
                                         'N',       // Тип движения 'F'/'N'
                                          0 );      // Указатель на объект с данным атрибутом, если NULL, не заполняется
        }
        DeleteIterator( rIterator ); // Удалить блок параметров навигации по модели

        // Снять подсветку объекта
        LightObj( rObject, 0 );
      }
    }  
  }
}


//-------------------------------------------------------------------------------
// Хождение по квалитетам
// ---
void WalkFromQuality()
{
  TCHAR name[20];            // поле допуска
  ::_tcscpy(name, _T("H7")); // умолчательное значение

  if ( ReadStringT(_T("Укажите поле допуска"), name, 5) ) 
  { 
    // запрос поля допуска у пользователя
    TCHAR        buf[255]; // буфер
    std::wstring s;        // строка сообщения
    
    // пустая строка - идём итератором
    if ( !::_tcscmp(name, _T("")) ) 
    { 
      // итератор по системе отверстия с учётом ограничений наложеных в системе
      reference iter = ::ksCreateQualityIterator( 1/*system*/, 1/*withLimitation*/ );
      
      // итератор создан
      if ( iter ) 
      {
        QualityContensParamT param;     // структура параметров квалитета
        int                  first = 0; // начало чтения

        // продолжаем чтение пока не считаем все квалитеты
        int countMove = 0;

        while ( ::ksMoveQualityIteratorT(iter, &param, false/*inMM*/, !first ? _T('F') : _T('N')) && countMove < 5 ) 
        {
          countMove++;
          // формируем строку для текущего квалитета
          ::_stprintf( buf, _T("Система %s, Тип квалитета %i, Поле допуска %s\n"),
                       (param.systemQuality == 1 ? _T("Вала") : _T("Отверстия")), param.kindQuality,
                       param.name); 

          s += buf; // добавляем к сообщению
          
          int count = ::GetArrayCount( param.pQualityItems ); // кол-во интервалов
          int countMove1 = count/5;

          // проходим по всем интервалам
          for ( int i = 0; i < count; i = i + countMove1 ) 
          { 
            QualityItemParam item; // запись об одном интервале для какого-то квалитета

            // считываем текущюю запись
            if ( ::GetArrayItem(param.pQualityItems, i, &item, sizeof(QualityItemParam)) ) 
            {
              // выводим параметры интервала в строку
              ::_stprintf( buf, _T("Значение: %i < X < %i, high = %g, low = %g\n"),
                           item.minLimit, item.maxLimit, item.high, item.low );

              s += buf; // добавляем к сообщению
            }
          }
          
          ::MessageT( (LPWSTR)s.c_str() ); // выводим сообщение
          s = _T(""); // очищаем строку сообщения
          ::DeleteArray( param.pQualityItems ); // удаляем массив интервалов
          param.pQualityItems = 0;

          if ( !first ) // пришли первый раз
            first = 1; // взводим флаг
        }
        ::DeleteIterator( iter ); // удалить итератор
      }
    }

    // имя есть
    else 
    { 
      //!!!!!!!!!!!!!!!!!!!!!!
      
      //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

      s = _T(""); // очищаем строку сообщения

      QualityContensParamT param; // структура параметров квалитета

      // считываем параметры указанного квалитета
      if ( ::ksGetQualityContensParamT(name, &param, false/*inMM*/) ) 
      {
        ::_stprintf( buf, _T("Система %s, Тип квалитета %i, Поле допуска %s\n"),
                     (param.systemQuality == 1 ? _T("Вала") : _T("Отверстия")), param.kindQuality,
                     param.name); // формируем строку для текущего квалитета

        s += buf; // добавляем к сообщению
        int count = ::GetArrayCount(param.pQualityItems); // кол-во интервалов
        int countMove1 = count/5;

        // проходим по всем интервалам
        for ( int i = 0; i < count; i = i + countMove1 ) 
        { 
          QualityItemParam item; // запись об одном интервале для какого-то квалитета

          // считываем текущюю запись
          if ( ::GetArrayItem(param.pQualityItems, i, &item, sizeof(QualityItemParam)) ) 
          {
            // выводим параметры интервала в строку
            ::_stprintf( buf, _T("Значение: %i < X < %i, high = %g, low = %g\n"),
                         item.minLimit, item.maxLimit, item.high, item.low);

            s += buf; // добавляем к сообщению
          }
        }
        ::MessageT( (LPWSTR)s.c_str() ); // выводим сообщение
        s = _T(""); // очищаем строку сообщения
        ::DeleteArray(param.pQualityItems); // удаляем массив интервалов
        param.pQualityItems = 0;
      }
    }
  }
}


//-------------------------------------------------------------------------------
// Получить отклонения
// ---
void QualityDefects()
{
  TCHAR name[20];            // поле допуска
  ::_tcscpy(name, _T("H7")); // умолчательное значение

  if ( ReadStringT(_T("Укажите поле допуска"), name, 5) ) 
  { 
    TCHAR        buf[255]; // буфер
    std::wstring s;        // строка сообщения

    reference names = CreateArray( CHAR_STR_ARR_T, 0 /*DeleteFunc*/ );
    // Получить массив полей допусков, которые поддерживают размер dimValue и не превышают
    // указанных отклонений
    ksGetQualityNames( names, 100, 0.2/*high*/, 0.1 /*low*/,
                       0/*system*/, 1/*withLimitation*/ );

    // Количество элементов в массиве
    int jcount = GetArrayCount( names );
    int countMove2 = jcount/5;

    // Цикл по строкам
    for ( int j = 0; j < jcount; j = j + countMove2 )
    {
      // Получить значение элемента массива
      GetArrayItem( names, j, buf, 255 );
      s += buf; // добавляем к сообщению
      s += _T("\n");
    }
    MessageT( (LPWSTR)s.c_str() );
    DeleteArray( names );

    double  high, low;
    // Получить отклонения
    ksGetQualityDefectsW( name, 100.0/*dimValue*/, &high, &low,1/*inMM*/ );
    ::_stprintf(buf, _T("dimValue = %g, high = %g, low = %g"), 100.0, high,low); 
    MessageT( buf );
  }
}