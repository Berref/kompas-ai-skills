////////////////////////////////////////////////////////////////////////////////
//
// base.h - Базовые классы, структуры, функции  
//
////////////////////////////////////////////////////////////////////////////////
#ifndef __BASE_H
#define __BASE_H

#if !defined( __SYSTYPES_H )
#include <systypes.h>
#endif

#include <Forms.hpp>

#ifndef __LIBTOOL_H
#include <libtool.h>
#endif

#ifndef __KONSTR_RH
#include "gayka.rh"
#endif

typedef UINT uint;

// Используемая структура
struct HotPointDescription;

//-------------------------------------------------------------------------------
// Название колонок для спецификации
// ---
#define SPC_FORMAT   1 // Формат
#define SPC_ZONA     2 // Зона
#define SPC_POSITION 3 // Позиция
#define SPC_MARKER   4 // Обозначение
#define SPC_NAME     5 // Наименование
#define SPC_COUNT    6 // Количество
#define SPC_NOTE     7 // Примечание

//-------------------------------------------------------------------------------
// Маски настройки
// ---
#define AXIS_OFF   0x1   // FALSE - рисовать, TRUE - не рисовать
#define PITCH      0x2   // FALSE - крупный шаг, TRUE - мелкий шаг
#define SIMPLE     0x10  // FALSE - нормальная отрисовка, TRUE - упрощенная отрисовка
#define ISPOLN     0x80  // FALSE - исполнение 1, TRUE - исполнение 2
#define TAKEISPOLN 0x100 // FALSE - не учитывать исполнение, TRUE - учитывать исполнение

//-------------------------------------------------------------------------------
// Дополнительные маски 
// ---
#define KEY_S_ON     0x1   // TRUE - включены дополнитеоьные размеры под ключ, FALSE - выключены
#define KOEFF_MAT_ON 0x4   // FALSE - только металл, TRUE другие материалы
#define KEY_S        0x2   // TRUE - дополнительный размер под ключ, FALSE - обычный размер под ключ 
#define KEY_S_GRAY   0x8   // TRUE - греить "Дополнитеоьные размеры под ключ"
#define PITCHOFF     0x800 // TRUE - есть только крупный шаг, FALSE - есть крупный и мелкий шаг

//-------------------------------------------------------------------------------
// Насроечная информация
// ---
#define SPC_CLEAR_GEOM   FALSE       // Очищать геометрию при редактировании объекта спецификации
#define STANDART_SECTION 25          // Номер раздела и подраздела спецификации
#define COUNT_MASSA      1000        // Количество деталей масса которых лежит в ГОСТ-е
#define LIB_HELPFILE     "gayka.chm" // Имя файла помощи
#define SPCOBJ_CREATE    TRUE        // Признак подключения объекта к спецификации
#define MIN_H_ANG        -90
#define MAX_H_ANG        90
#define MIN_H_SHAG       0.1
#define MAX_H_SHAG       1000
#define KONSTR_TXT       "konstr.txt"
#define SPC_LIB          "graphic.lyt"
#define MAX_COUNT_SPCOBJ 4           // Максимальное число объектов СП за раз 4
// коэффициент для расчета диаметра резьбы по шагу резьбы
#define MODSTEP_REAL 0.5412765877

//-------------------------------------------------------------------------------
// Параметры макрообъекта
// ---
struct BaseMacroParam 
{
  float angle;      // Угол поворота
  bool  flagAttr;   // Создать объект спецификации
  short drawType;   // Тип отрисовки 
  bool  typeSwitch; // Тип запроса положения базовой точки элемента 0 - Placement, 1 - Cursor
                    // Placement - точка и направление оси 0X,
                    // Cursor - точка ( направление совпадает с осью 0X текущей СК )
};

////////////////////////////////////////////////////////////////////////////////
//
// Базовый класс параметров 
//
////////////////////////////////////////////////////////////////////////////////
class  CPar 
{
protected :
  reference    * refMacr;
  static reference spcObj[MAX_COUNT_SPCOBJ];
  uint           countObj;
  int            flagMode;
public:
  BaseMacroParam par;

public:
  CPar();
  virtual  ~CPar();

  virtual  void              GetGroup( reference &gr ) = 0; // Получение геометрии
  virtual  int               ChoiceMenuId()            = 0; // Идентификатор меню
  virtual  void              SetParam()                = 0; // Смена параметров

  // Работа с Hot точками
  virtual  BOOL              GetHotPoints( HotPointDescription* point, int index ) = 0;
  virtual  int               SetHotPoint ( HotPointDescription* point, int index ) = 0;

  virtual  int               Size()                       { return sizeof(par); }  // Размер данных
  virtual  void              SetHatchAngl()               {}                       // Изменение угла штриховки
  virtual  void              SetHatchShag()               {}                       // Изменение шага штриховки
  virtual  void              SetSimple()                  {}                       // Упрошенно
  virtual  void              SetDimension()               {}                       // Размер
  virtual  int               MacroElementParam()          { return IDCANCEL; }     // Параметры макро объекта
  virtual  void              FuncAfteDrawType()           {}                       // Функция вызываемая после смены типа отрисовки
  virtual  int               ServiceObj()                 { return 1; }            // Сервисный объект
  virtual  void              ServiceObj1( float , float ) {}                       // Сервисный объект 1

  virtual  reference         EditSpcObj( reference*, reference ) { return 0; }     // Редактирование объекта спецификации
  virtual  bool              IsSpcObjCreate()             { return false;}         // Функция проверки подключения атрибутов или нет
  virtual  void              CalkPaket()                  {} ;                     // Измерить высоту пакета
  virtual  void              SetPlacement( double x, double y, double angl );      // Изменение положения макро объекта
           void              Assign ( const CPar &other );                         // Оператор присваивания
           void              Draw1();                                              // Отрисовка геометрии
           void              Draw();                                               // Отрисовка геометрии 1
           uint              GetObjCount()                { return countObj; }     // Колличество объектов спецификации
           short &           GetDrawType()                { return par.drawType; } // Тип отрисовки
           // Создать объект спецификации
           bool &            GetFlagAttr()                { return par.flagAttr; }
           void              SetAttr()                    { par.flagAttr = par.flagAttr ? false : true; }

           operator void* ()                              { return &par.angle; }   // Оператор приведения по умолчанию к  void*

public:
  // Функции обратной связи, вызываемые из Cursor и Placement
	static int  far __export __stdcall CallBackP ( int com, double *x, double *y, double *angl, RequestInfo *info, void *phantom, int dynamic );
  static int  far __export __stdcall CallBackC ( int com, double *x, double *y, RequestInfo *info, void *phantom, int dynamic );
  static bool        DrawSpcObj( reference group ); // Отрисовка объекта спецификации
  static void        _MessageBoxResult();           // Вывод ошибки если она возникла
  static void DrawPosLeader( reference _spcObj );   // Отрисовать позиционную линию выноски
};


////////////////////////////////////////////////////////////////////////////////
//
// Параметры помощи
// commandHelp - false - по умолчанию, помощь вызывается по идентификатору диалога
//               true  - помощь вызывается по номеру команды ( взводить в конструкторе объекта)
//
////////////////////////////////////////////////////////////////////////////////
class  ConstrHelp  
{
  public :
    static  char helpName[250];
    static  uint command;
    static  bool commandHelp;
    static  bool helpErr;
    static  int  GetHelpFileName(); // Имя файла помощи
    static  void SetCommandHelp( bool f = true ) { ConstrHelp::commandHelp = f; };
    static  void SetCommand( uint c ) { ConstrHelp::commandHelp = false; ConstrHelp::command = c; };
    static  bool IsCommandHelp( ) { return ConstrHelp::commandHelp; }
};


//-------------------------------------------------------------------------------
// Вспомогательные функции
// ---
float     SetHatchAngl( float ang );                        // Изменение угла штриховки
float     SetHatchShag( float shag);                        // Изменение шага штриховки
void      CheckDecimelPart(char *s,unsigned int pointToComma = 0 ); // Отбросить дробную часть у строки если после "." нули
int       pr_str(char *vh, char *rez, int t);               // Убрать пробелы у строки
void      ErrorKonstr();                                    // Ошибка в konstr.txt
reference _OpenTextFile( char *name );                      // Открытие текстового файла
int       _ConnectDB(reference bd, char *name );            // Подключение к базе
int       _GetMacroParam( void *value, unsigned int size ); // Получение параметров у макро
double    GetViewScale();                                   // Маштаб вида
char*     LoadStr( int id, char *str, int size );           // Загрузить строку из ресурса
void      ConvertLangForm( TForm* form );                   // Функция перевода формы
int       GetFullName( char *name, char *fName );           // Получить полное имя файла базы данных

#endif