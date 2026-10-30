////////////////////////////////////////////////////////////////////////////////
//
// Bolt.h - Конструкторский элемент на Visual C++ - Болт 
//
////////////////////////////////////////////////////////////////////////////////
#ifndef __BOLT_H
#define __BOLT_H

#include "CPar.h"

#define MAX_LENGTH        260    // максимальная длина стержня
#define MIN_LENGTH        12     // мигнимальная длина стержня
#define LENGTH_STR        20     // длина строки принимаемой из базы данных
#define ADD_DIM           0.05
#define STR_SIZE_STD      32

#define AXIS_OFF          0x1    // 0 рисовать >0 не рисовать
#define DRAW_ST_OF        0x10   // 0 стержень у болта рисуется > 0 - рисовать только головку


////////////////////////////////////////////////////////////////////////////////
//
// Основная структура данных болта
//
////////////////////////////////////////////////////////////////////////////////
struct BoltMainStruct 
{
  ushort gost;   // номер госта
  ushort perf;   // исполнение
  ushort f;      // битовые маски
  float  z4;     // Величина фаски
  float  dp;     // диаметр конца болта
  float  l;      // длина болта (стержня)
  float  dr;     // диаметр резьбы
  float  b;      // длина резьбы
  float  m;      // масса 1000 штук
  float  d;      // диаметр головки
  float  k;      // высота головки и/или подголовка
  short  kr;     // 1 длина резьбы ниже ломманной(резьба только на b) ; 0 - выше ломанной (резьба до головки и  на в )
  float  p;      // шаг резьбы
  float  param1; // высота уса или сторона квадратного подголовка
  float  param2; // радиус сферы или угол Alpha
  float  v;      // ширина уса
  float  h;      // высота подголовка
  float  d1;     // диаметр подголовка или стержня
  float  rp;     // радиус под головкой
  float  b1;     // Длина при l>120 для ГОСТ 7783-81

  BoltMainStruct() {}
  BoltMainStruct( ushort _gost );           // Конструктор
  BoltMainStruct( const BoltMainStruct & ); // Конструктор копий

  const BoltMainStruct & operator = ( const BoltMainStruct & );

  void Init();
};


///////////////////////////////////////////////////////////////////////////////
//
// Cтруктура BoltMainBase
//
////////////////////////////////////////////////////////////////////////////////
struct BoltMainBase 
{
  reference bg;  // База данных
  reference rs1; // Отношение для получения из базы диаметров резьбы
  reference rs2; // Отношение для получения из базы длин
  reference rs3; // Отношение для получения всех данных из базы
  reference bs;  // База данных R_sh_k.loa
  reference r1;  // Отношение для получения диаметра конца болта и фаски из базы
};


////////////////////////////////////////////////////////////////////////////////
//
// Класс BoltMain
// Болт ГОСТ 7787-81
//
////////////////////////////////////////////////////////////////////////////////
class BoltMain : public CPar 
{
private :
  struct TmpStruct 
  {
    char  s[LENGTH_STR];
    float dr;
  };

public :
  BoltMainStruct bolt;         // Структура данных
  BoltMainBase   bBase;        // База и отношения

public :
  BoltMain( ushort gost );
  BoltMain( const BoltMain& other ); // конструктор копий
  BoltMain( reference ref = 0, bool fromDataBase = false );
  ~BoltMain();

  void       Assign   ( const BoltMain& other ); // оператор присваивания
  //  BoltMain * Dublicate();                        // оператор копирования

  BoltMainStruct & GetParam       () { return bolt; }       // параметры элемента

  virtual CPar & DublicateObj    (); 
  virtual int    Size            () { return CPar::Size() + sizeof(BoltMainStruct); }

  virtual double AttrNumber();                      // Номер атрибута
  virtual bool   _EditSpcObj( ksAPI7::ISpecificationBaseObjectPtr & obj1 );                     // Заполнение объекта СП
  virtual bool   IsSpcObjCreate() { return true; }; // функция проверки подключения атрибутов или нет

  // Получить парметры для элемента XML дерева
  virtual void   GetXMLPartFamilyParam( CString & name, CString & id );

          bool   FillStruct( bool forAssmElem = false, float d = 0, float l = 0 ); // Перезаполняет структуру
  virtual bool   OpenBase  ();                                                     // открытие БД и создание отношений
  virtual void   CloseBase ();                                                     // закрыть БД

protected:
          void   InitBolt();                                       // Инициализация параметров болта
  virtual void   GetGroup();                                       // Получить группу
  virtual void   TopDraw();                                        // Рисует вид сверху
  virtual void   ViewDraw();                                       // Рисует основной вид
  virtual void   ViewHalfDraw( bool downHalf, bool apl = false );  // Рисует половину основного вида
  virtual void   BottomDraw();                                     // рисует вид снизу

  // HOT_POINTS ##################################################################
  virtual bool     GetHotPoints   ( HotPointDescription * point, int index );
  virtual bool     GetHotPointsEx ( HotPointDescription1* point, int index );
  virtual bool     SetHotPoint    ( HotPointDescription * point, int index );
  virtual bool     GetCursorText  ( int index, char** text );
  virtual LPOLESTR GetCursorTextEx( int index );
          bool     ChangeHotPointParam( double d, double l, int index );
  // ША K8   virtual int    GetMenu();
  virtual bool     DrawSpcWithIndex( int index ) { return index == 2 || index == 3; }
  // HOT_POINTS ##################################################################

  // Окно свойств ##################################################################
  virtual int      GetPropertyID ( int index );
  virtual BOOL     GetProperty   ( int index, PropertyParam & param );
  virtual BOOL     UpdateProperty( PropertyParam & param );
  virtual int      ApplyProperty ( PropertyParam & param );
  virtual LPOLESTR GetGroupName  ();
  virtual LPCTSTR  GetObjName    ();
  // Окно свойств ##################################################################

  // Панель свойств ##################################################################
  virtual CString   GetProcessName () { return ::LoadStr( IDS_BOLT7787_CAPTION ); }
  virtual long      GetFirstTabID  () { return IDS_BOLT7787_CAPTION; }
  virtual void      SetAxis        ( bool );                           // рисовать ось 
  virtual bool      GetAxis        () { return !(bolt.f & AXIS_OFF); } // рисовать ось 
  virtual int       ParamCount     () { return 4; }  // Количество параметров выводимых в гриде 
  virtual void      ShowParam      ();               // Заполнение грида параметров 
  virtual reference GetPreviewGroup();

  virtual void      ShowControls        ();                                      // Виртуальная функция наполнения контролов элемента
  virtual bool      OnChangeControlValue( long ctrlID, const VARIANT & newVal ); // prChangeControlValue - Изменение значения контрола
  virtual bool      OnButtonClick       ( long buttonID );                       // prButtonClick - Нажатие кнопки.
  // Панель свойств ##################################################################

  // AssmObject
  virtual bool      ReadElemBase       ( float d, float l, bool forAssmElem = true ); // чтение БД
  virtual float     GetDiamThread      () { return bolt.dr; }                         // возвращает диаметр резьбы
  virtual void      GetDiamArray       ( SArray<float> & diamArr );                   // заполняет массив диаметров
  virtual float     GetToleranceLength () { return 2 * bolt.p; }                      // допуск длины базового элемента = 2p(p - шаг резьба)
  virtual void      SetDrawType        ( short drawType );
  virtual float     GetLengthBaseElem  () { return bolt.l; }
  virtual void      CreateClearGroup   ();                                            // создание контура для очистки области под элементом
  virtual float     GetFaceDiam        () { return bolt.z4; }                         // Получить диаметр фаски базового элемента
  virtual float     GetCurStep         () { return bolt.p;  }                         // Получить текущий шаг базового элемента

private :
  void FillDiamList  (ksAPI7::IPropertyListPtr & diamList   ); // Заполнение списка диаметров резьбы
  void FillLengthList(ksAPI7::IPropertyListPtr & lengthList ); // Заполнение списка длин
  bool GetDiamList   ( SArray<double>   & diamList   ); // Получить массив диаметров
  bool GetLengthList ( SArray<double>   & lengthList ); // Получить массив длин
};

#endif // __BOLT_H