////////////////////////////////////////////////////////////////////////////////
//
// studs3d.h - Крепежный элемент на Visual C++ - шпилька
// Структуры параметров и класс шпилек
//
////////////////////////////////////////////////////////////////////////////////
#ifndef __STUDS3D_H
#define __STUDS3D_H

#if !defined( __SYSTYPES_H )
#include <systypes.h>
#endif

#ifndef __LDEFIN2D_H
#include "ldefin2d.h"
#endif

#ifndef __ksConstants3D_h__
#include "ksConstants3D.h"
#endif

#ifndef  __Kompas6API3D5COM_TLB_h__
#include "Kompas6API3D5COM_TLB.h"
#endif

namespace Kompas6api2d5com_tlb
{
#ifndef __LIBTOOL_H
#include "libtool.h"
#endif

};

namespace Kompas6api3d5com_tlb
{
#ifndef __LHEAD3D_H
#include "lhead3d.h"
#endif
};

#ifndef __LIBDB_H
#include "libdb.h"
#endif



//-------------------------------------------------------------------------------
// Маски настройки
// ---
#define AXIS_OFF     0x1    // FALSE - рисовать, TRUE - не рисовать
#define PITCH        0x2    // FALSE - крупный шаг, TRUE - мелкий шаг
#define SIMPLE       0x10   // FALSE - нормальная отрисовка, TRUE - упрощенная отрисовка
#define ISPOLN       0x80   // FALSE - исполнение 1, TRUE - исполнение 2
#define TAKEISPOLN   0x100  // FALSE - не учитывать исполнение, TRUE - учитывать исполнение
#define ALLST        0x4    // FALSE - резьба на b, TRUE - резьба до головки
#define KONTR        0x8    // FALSE - обычная головка, TRUE - головка под контровочное отверстие
#define SECOFF       0x10   // FALSE - сечение работает, TRUE - сечение засерить, для винтов, для трубопроводов
#define TAKEKONTR    0x20   // FALSE - не учитывать контровку, TRUE - учитыварь контровку
#define REVERCE_ON   0x20   // FALSE - включить прямую, TRUE - обратную отрисовку
#define TAKEPODG     0x40   // FALSE - не учитывать подголовку, TRUE - учитыварь бодголовку
#define LEFT_DRAW    0x40   // TRUE - рисовать слева
#define FLAGLENGTH   0x200  // FALSE - длина болта подобрана правильно, TRUE - не правильно
#define ISPOLN3      0x200  // Для штифтов FALSE - исполнений 2, TRUE - исполнений 3
#define REVERCE_DRAW 0x200  // TRUE - обратная отрисовка, FALSE - прямая отрисовка
#define SBORSHAYBA   0x400  // FALSE - гайка без шайбы, TRUE - гайка вместе с шайбой
#define PITCHOFF     0x800  // FALSE - есть крупный и мелкий шаг, TRUE - есть только крупный
#define LENLEN       0x1000 // FALSE - нормальная длина резьбы, TRUE - удлиненная
#define LENLENOFF    0x2000 // FALSE - не учитывать, TRUE - учитывать
#define ALLST_OF     0x4000 // TRUE - засерить checkbox резьба на всю длину

//-------------------------------------------------------------------------------
// Дополнительные маски 
// ---
#define KEY_S_ON     0x1   // TRUE - включены дополнитеоьные размеры под ключ, FALSE - выключены
#define KOEFF_MAT_ON 0x4   // FALSE - только металл, TRUE другие материалы
#define KEY_S        0x2   // TRUE - дополнительный размер под ключ, FALSE - обычный размер под ключ 
#define KEY_S_GRAY   0x8   // TRUE - греить "Дополнитеоьные размеры под ключ"
#define DRAW_ST_OF   0x10  // FALSE - стержень у болта рисуется TRUE - рисовать только головку

//-------------------------------------------------------------------------------
// Насроечная информация
// ---
#define COUNT_MASSA      1000 // Количество деталей масса которых лежит в ГОСТ-е
#define STANDART_SECTION 25   // Номер раздела и подраздела спецификации
#define SPC_NAME       	 5    // Колонка наименования

#define EPSILON          0.001  

#define STUDS_FILE       "stud.l3d"           // Библиотека моделей
#define STUDS_INPUT_PATH "|Шпильки|Шпилька_1" // Путь внутри библиотеки моделей

#define SPCOBJ_CREATE    TRUE // Признак подключения объекта к спецификации


////////////////////////////////////////////////////////////////////////////////
//
// Структуры параметров и класс шпилек
//
////////////////////////////////////////////////////////////////////////////////


//------------------------------------------------------------------------------
// Структура параметров шпилек
// ---                      
struct SHPEEL 
{
  float d;          // Диаметр резьбы
  float p1;         // Шаг резьбы
  float p2;         // Шаг резьбы
  float b1;         // Винчиваемый конец 
  float c;          // Размер фаски
  float l;          // Длина шпильки
  float b;          // Гаечный конец 
  short f;          // Битовые маски
  short klass;      // Класс точности
  short gost;       // Номер ГОСТа
  short ver;        // Версия макро
  float m1;         // Масса 1 исполнение
  float m2;         // Масса 2 исполнение
  short indexMassa; // 0 - металл 1 - алюмин сплав 3 - бронза 2 - латунь
};


////////////////////////////////////////////////////////////////////////////////
//
//  Структуры для работы с БД
//
////////////////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------------
// Для считывания из баз st22032.loa ... st22043.loa
// ---
struct ShpeelSTmp 
{
  short t;   // Флаг использовать запись или нет
  float l;   // Длина шпильки
  float d;   // Диаметр резьбы
  float b;   // Гаечный конец
  float m1;  // Масса исполнения 1
  float m2;  // Масса исполнения 2
};


//------------------------------------------------------------------------------
// Для считывания  из  баз 22032.loa ... 22043.loa
// ---
struct ShpeelTmp 
{
  short t;   // Флаг использовать запись или нет
  float d;   // Диаметр резьбы
  float p1;  // Шаг резьбы
  float p2;  // Шаг резьбы
  float b1;  // Ввинчиваемый конец
  float c;   // Размер фаски
};


//------------------------------------------------------------------------------
// Работа с БД
// ---
struct ShpeelBase 
{
  reference bg, rg1, rg2;
  reference bs, rs1, rs2;
};


//-------------------------------------------------------------------------------
// Макро параметры
// ---
struct BaseMakroParam 
{
  float          ang;
  unsigned short flagAttr;
  short          drawType;
  BYTE           typeSwitch;  // Тип запроса положения базовой точки элемента
                              // 0 - точка и направление оси 0X ( Placement )
                              // 1 - точка, направление совпадает с осью 0X текущей СК ( Cursor )
};


////////////////////////////////////////////////////////////////////////////////
//
// Класс шпилек
//
////////////////////////////////////////////////////////////////////////////////
class Shpeel 
{
private :
  Kompas6api3d5com_tlb::IDocument3DPtr           doc;            // Указатель на интерфейс текущего 3D-документа
  Kompas6api3d5com_tlb::IPartPtr                 part;           // Деталь
  Kompas6api3d5com_tlb::IEntityCollectionPtr     collect;        // Массив всех entity детали
  bool                                           collectChanged; // true - массив изменился
  String                                         fileName;       // Имя файла
  int                                            flagMode;       // Тип редактирования
  ShpeelBase                                     bBase;          // Работа с БД
  bool                                           openBase;       // Состояние базы

  // Структуры par и tmp записываемые как UserParam
  BaseMakroParam                                 par;            // Макро параметры
  SHPEEL                                         tmp;            // Структура параметров шпилек

public :
  Shpeel();
  Shpeel( const Shpeel& other );                // Конструктор копий

  void        Init();                           // Инициализация
  void        Assign( const Shpeel& other );    // Оператор присваивания
  Shpeel*     Dublicate();                      // Оператор копирования
  ShpeelBase& GetShpeelBase() { return bBase; } // Возвращает параметры БД
  SHPEEL&     GetShpeelParam(){ return tmp; }   // Возвращает параметры
  bool&       GetCollectChanged() { return collectChanged; } // Возвращает изменился ли массив
  unsigned short & GetFlagAttr() { return par.flagAttr; }    // Возвращает создавать ли объект спецификации

  int       ChoiceMenuId();                                  // Выбор меню
  void      SetParam();                                      // Редактируем переменные
  int       Size() { return sizeof(tmp) + sizeof(par); }     // Размер данных
  int       MacroElementParam();                             // Диалог редактирования параметров
  reference EditSpcObj( reference spcObj );                  // Редактирование объекта спецификации
  bool      IsSpcObjCreate() { return SPCOBJ_CREATE; };      // Функция проверки подключения атрибутов или нет
  String&   SetFileName();                                   // При вставке из библиотеки моделей указывается полный путь к файлу библиотеки и путь внутри библиотеки моделей
  void      Draw3D( Kompas6api3d5com_tlb::IDocument3DPtr & );                          // Рисование 3D объектов
  int       OpenBase();                                      // Открытие БД и построение отношений
  void      CloseBase();                                     // Закрытие БД
  int       GetParam();                                      // Получить параметры
  void      SetCallBackAndFilterFunction( Kompas6api3d5com_tlb::IRequestInfoPtr & info ); // Заполняет адреса функций фильтра и обратной связи
  bool      DrawSpcObj();                                    // Отрисовка объекта спецификации
  Kompas6api3d5com_tlb::IPartPtr & GetPart() { return part; }                       // AddRef - не делает
  bool      IsCollectionChange( Kompas6api3d5com_tlb::IRequestInfoPtr & info ); // Проверяет содержимое массива - возвращает true если нужно перестроить Mate'ы
  // Устанавливает сопряжения
  void      SetMates( Kompas6api3d5com_tlb::IDocument3DPtr & doc, Kompas6api3d5com_tlb::IRequestInfoPtr & info, bool delMates = false );
  // Находит у детали поверхность с заданным именем
  Kompas6api3d5com_tlb::IEntityPtr  GetEntityByName( wchar_t * name );
  bool      GetDirectionElem() { return true; }
  bool      IsCollectionEmpty( Kompas6api3d5com_tlb::IRequestInfoPtr & info ); // Массив пуст - указали placement
	bool      IsBaseOpen() { return openBase; }                    // Состояние базы
	int       ReadShpeelBase( float d );                    // Чтение БД по диаметру
	int       ReadShpeelStBase();                           // Читать параметры стержня
};


#endif // !defined(___STUDS3D_H)

