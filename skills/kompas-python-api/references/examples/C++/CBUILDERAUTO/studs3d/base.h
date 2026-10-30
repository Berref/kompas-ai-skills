// studs3d.h : main header file for the STUDS3D DLL
//

#include "studs3d.rh"
#include <ldefin2d.h>
#include <ldefin3d.h>

typedef UINT uint;

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#define AXIS_OFF     0x1    // 0 рисовать >0 не рисовать
#define PITCH        0x2    // крупный шаг >0 мелкий шаг
#define ALLST        0x4    // резьба на b >0 резьба до головки
#define KONTR        0x8    // обычная головка  >0 головка под контровочное отв
#define SIMPLE       0x10   // нормальная отрисовка >0 упрощенная отрисовка
#define SECOFF       0x10   // 0 сечение работает 1>сечение засерить, для винтов, для трубопроводов
#define TAKEKONTR    0x20   // не учитывать контровку >0 учитыварь контровку
#define REVERCE_ON   0x20   // включить прямую\обратную отрисовку >0;
#define TAKEPODG     0x40   // не учитывать подголовку >0 учитыварь бодголовку
#define LEFT_DRAW    0x40   // рисовать слева >0;
#define ISPOLN       0x80   // исполнение 1 >0 исполнение 2
#define TAKEISPOLN   0x100  // 0 не учитывать исполнение  >0 учитывать исполнение
#define FLAGLENGTH   0x200  // длина болта подобрана правильно  >0 не правильно
#define ISPOLN3      0x200  // для штифтов 0 -исполнений 2 > 0 исполнений 3
#define REVERCE_DRAW 0x200  // обратная отрисовка  >0 ;  0- прямая отрисовка
#define SBORSHAYBA   0x400  // гайка без шайбы  >0 гайка вместе с шайбой
#define PITCHOFF     0x800  // есть крупный и мелкий шаг >0 есть только крупный
#define LENLEN       0x1000 // 0 нормальная длина резьбы 1 удлиненная
#define LENLENOFF    0x2000 // 0 не учитывать 1 учитывать
#define ALLST_OF     0x4000 // > 0 засерить checkbox резьба на всю длину
//#define DRAW_ST_OF   0x8000 // 0 стержень у болта рисуется > 0 - рисовать только головку


//дополнитеоьные маски
#define KEY_S_ON     0x1 // 0- выключены дополнитеоьные размеры под ключ > 0 - включены
#define KEY_S        0x2 // 0-обычный размер под ключ; > 0 дополнительный
#define KOEFF_MAT_ON 0x4 // 0- только металл, >0 другие материалы
#define KEY_S_GRAY   0x8 // > 0 греить checkbox "дополнитеоьные размеры под ключ"
#define DRAW_ST_OF   0x10 // 0 стержень у болта рисуется > 0 - рисовать только головку

#define  COUNT_MASSA 1000

////////////////////////////////////////////////////////////////////////////////
//
//  Структура параметров и класс шпилек
//
////////////////////////////////////////////////////////////////////////////////
//-------------------------------------------------------------------------------
//
// ---
struct BaseMakroParam {
  float          ang;
  unsigned short flagAttr;
  short          drawType;
  BYTE           typeSwitch;  // тип запроса положения базовой точки элемента 0 Placement 1 Curso
                              //   0 - точка + направление оси 0X ( Placement );
                              //   1 - точка, направление совпадает с осью 0X текущей СК ( Cursor ).
};

//------------------------------------------------------------------------------
// Структура параметров
// ---
struct SHPEEL {
  float d;          // диаметр резьбы
  float p1;         // шаг резьбы
  float p2;         // шаг резьбы
  float b1;         // ввинчиваемый конец  l1
  float c;          // размер фаски
  float l;          // длина шпильки
  float b;          // гаечный конец  l0
  short f;          // битовые маски
  short klass;      // класс точности
  short gost;       // номер госта
  short ver;        // версия макро
  float m1;         // масса 1 исполнение
  float m2;         // масса 2 исполнение
  short indexMassa; // 0-металл 1- алюмин сплав 3-бронза 2-латунь
};

//------------------------------------------------------------------------------
//
// ---
struct ShpeelBase {
  reference bg, rg1, rg2;
  reference bs, rs1, rs2;
};

//------------------------------------------------------------------------------
// класс шпилек
// ---
class Shpeel {
private :
  bool                  openBase;
  ksDocument3DPtr       doc;            // интерфейс текущего 3D-документа
  ksSpecificationPtr    specification;  // интерфейс спецификации
  ksPartPtr             part;           // деталь
  ksEntityCollectionPtr collect;        // массив всех entity детали
  bool                  collectChanged; // true - массив изменился
  WideString            fileName;
  UINT                  countObj;
  int                   flagMode;

  ksUserParamPtr        paramSTmp; // параметры для чтения БД
  ksUserParamPtr        paramTmp;  // параметры для чтения БД
  ksUserParamPtr        param;     // параметры для Get/SetMacroParam
  ksDataBaseObjectPtr   data;      // интерфейс БД

  BaseMakroParam        par;
  SHPEEL                tmp;
  ShpeelBase            base;      // работа с БД

public :
  Shpeel();
  Shpeel( const Shpeel& other );                // конструктор копий

  operator void* () { return &par.ang; }  //оператор приведения по умолчанию к  void*

static bool DrawSpcObj();

  void              Init();
  void              Assign( const Shpeel& other );    // оператор присваивания
  Shpeel*           Dublicate();                      // оператор копирования

  ksDataBaseObjectPtr & GetDataBase()  { return data;      }
  ksUserParamPtr &      GetParamTmp()  { return paramTmp;  }
  ksUserParamPtr &      GetParamSTmp() { return paramSTmp; }

  ShpeelBase &          GetShpeelBase() { return base; } // возвращает параметры БД
  SHPEEL&               GetShpeelParam(){ return tmp; }
  BaseMakroParam&       GetBaseParam()  { return par; }
  bool&                 GetCollectChanged() { return collectChanged; }
  ksPartPtr &           GetPart()     { return part; }
  short &               GetDrawType() { return par.drawType; }
  unsigned short&       GetFlagAttr() { return par.flagAttr; }
  void                  SetAttr()     { par.flagAttr = par.flagAttr ? false : true; }
  bool                  IsBaseOpen()  { return openBase; }

  UINT      GetObjCount() { return countObj; }
  int       Size() { return sizeof(BaseMakroParam) + sizeof(SHPEEL); }
  bool      ReadElemBase( double d/*новый диаметр*/ ) { return false; } // подобрать диаметр
  bool      OpenElemBase() { return OpenBase(); }  // открыть БД на чтение
  void      CloseElemBase() { CloseBase(); }       // закрыть БД
  bool      GetDirectionElem() { return true; } //
            // устанавливает сопряжения
  void      SetMates( ksDocument3DPtr & doc, ksRequestInfo3DPtr & info, bool delMates = false );
            // заполняет адреса функций фильтра и обратной связи
  void      SetCallBackAndFilterFunction( ksRequestInfo3DPtr & info );
  int       GetParam();
  // находит у детали поверхность с заданным именем
  // planar = true - плоскость, false - коническая поверхность
  ksEntityPtr GetEntityByName( wchar_t* name );
  bool      IsCollectionEmpty( ksRequestInfo3DPtr & info ); // массив пуст - указали placement
  bool      IsCollectionChange( ksRequestInfo3DPtr & info );
  void      _MessageBoxResult();
  void      InitUserParamTmp();
  void      GetUserParamTmp();
  void      InitUserParamSTmp();
  void      GetUserParamSTmp();
  void      InitUserParam();
  void      SetUserParam();
  void      GetUserParam();
  void      Draw3D( ksDocument3DPtr & doc ); // рисование 3D объектов
  int       _ConnectDB( reference bd, char *name );
  bool      OpenBase( bool initParam = true );  // открытие БД
  void      CloseBase();                        // закрытие БД
  int       ReadShpeelBase( float d );
  int       ReadShpeelStBase();
  int       ChoiceMenuId();
  void      SetParam();
  WideString & SetFileName();

  reference EditSpcObj( reference * );
  int       MacroElementParam();
};


wchar_t * TO_OLE(wchar_t *x);
wchar_t * TO_OLE(char    *x);
wchar_t * TO_OLE(WideString & x);
/////////////////////////////////////////////////////////////////////////////

