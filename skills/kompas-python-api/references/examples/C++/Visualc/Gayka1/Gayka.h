////////////////////////////////////////////////////////////////////////////////
//
// gayka.h - Конструкторский элемент на Visual C++ - гайка 
//
////////////////////////////////////////////////////////////////////////////////
#ifndef __GAYKA_H
#define __GAYKA_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CPar.h"


//-------------------------------------------------------------------------------
// Флаги гайки ГОСТ 5915
// ---
struct G5915Flags {
  bool isp       : 1; // FALSE - исполнение 1,            TRUE - исполнение 2
  bool pitch     : 1; // FALSE - крупный шаг,             TRUE - мелкий шаг
  bool pitch_on  : 1; // FALSE - есть только крупный шаг, TRUE - есть крупный и мелкий шаг 
  bool key_s     : 1; // FALSE - обычный размер под ключ, TRUE - дополнительный размер под ключ,  
  bool key_s_on  : 1; // FALSE - греить "Дополнитеоьные размеры под ключ"
};

//-------------------------------------------------------------------------------
// Параметры гайки ГОСТ 5915
// ---
struct GAYKA5915
{
  float  dr;             // Диаметр резьбы  
  float  s;              // Шаг резьбы ()
  float  D;              // Размер под ключ 
  float  da;             //   
  float  h;              // Высота головки
  float  d2;
  float  p;              // Шаг резьбы  
  short  classAccuracy;  // Класс точности
  float  hatchAngle;     // Угол штриховки  
  float  hatchStep;      // Шаг штриховки
  short  version;        // Версия макрообъекта
  float  massa;          // Масса
  short  indexMassa;     // 0 - металл, 1 - алюмин сплав, 2 - латунь
  union {
    uint8      iFlags;    
    G5915Flags flags;   // Флаги  
  };
  GAYKA5915() { memset(&dr, 0, sizeof(GAYKA5915) ); } 
};

////////////////////////////////////////////////////////////////////////////////
//
// Класс гайки ГОСТ 5915
//
////////////////////////////////////////////////////////////////////////////////
class Gayka5915: public CPar 
{
protected :
  GAYKA5915       m_paramGayka;   // Параметры гайки ГОСТ 5915

public :

  Gayka5915( reference ref = 0, bool fromDataBase = false );
  Gayka5915( Gayka5915& other ); 

  virtual ~Gayka5915();

  virtual   CPar & DublicateObj() { return *new Gayka5915(*this); }

  void      InitParam(); 
  void      Assign( Gayka5915& other );      // Копирование

  GAYKA5915&  GetParamGayka() { return m_paramGayka; } // Возврашает параметры гайки
 
  void      Gayka_Sverhu( bool appl );                 // Отрисовка геометрии гайки ( сверху )
  void      Gayka_P_K( int j, bool appl );             // Отрисовка геометрии гайки ( пол-вида/пол-разреза )

//*******************ЭТИ ФУКЦИИ НЕОБХОДИМЫ ЭЛЕМЕНТУ*****************************
  // виртуальные функции для работы  с элементом
  virtual  bool      OpenBase();    // открыть БД
//  virtual  void      CloseBase();   // закрыть БД
           bool      GetDiamList( SArray<double> & diam ); // Список диаметров для комбобокса

  virtual  void      GetGroup();        // создание геометрии элемента
                                        // в процессе постановки эл-та в документ
  virtual  int       Size() { return CPar::Size() + sizeof(GAYKA5915); } // Размер параметров
  virtual  bool     _EditSpcObj( ksAPI7::ISpecificationBaseObjectPtr & obj1 );      // заполнение объекта СП
  // позволяет использовать аттрибут уже существующего объекта СП - возвращает номер
  // команды элемента для которого этот объект СП определён в CfgDlg
  virtual  bool      IsSpcGostSection() { return true;  }
  
  // Получить парметры для элемента XML дерева
  virtual void       GetXMLPartFamilyParam( CString & name, CString & id );

  // выводит диалог параметров эл-та: работает также и в меню при постановке

  // функции вызываемые из меню в процессе постановки эл-та в документ
  virtual  double    AttrNumber();

  virtual  double    HatchAngle() { return m_paramGayka.hatchAngle; } 
  virtual  double    HatchStep() { return m_paramGayka.hatchStep; } 
  virtual  void      SetHatchAngle(double hatch ) { m_paramGayka.hatchAngle = (float)hatch; }                     // угол штриховки
  virtual  void      SetHatchStep(double step ) { m_paramGayka.hatchStep = (float) step;}                      // шаг штриховки
  // (для панели инструментов)
  // Если штриховка в одном из режимов есть то нужно вернуть true  
  virtual  bool      IsHatchObject() { return true; }
  // true - в текущем режиме штриховка есть
  virtual  bool      IsSpcObjCreate() { return true;}; // функция проверки подключения атрибутов или нет
  virtual  void      ShowParam();

//******************************************************************************

// HOT_POINTS ##################################################################
  // Работа с Hot точками
  /* ILibHPObject */            
  virtual bool GetHotPoints( HotPointDescription* point, int index ); // Параметры для Hot точек
  virtual bool SetHotPoint( HotPointDescription* point, int index );  // Изменение положения Hot точек
  virtual bool GetCursorText( int index, TCHAR** text );              // Текст для Hot точек
  virtual bool ExecuteCommand( int id );                              // Выполнение команды
  virtual bool EditComplete( int index, BOOL success );               // Редактирование и вставка объекта спецификации, если он был создан
  virtual bool Prepare();
  virtual int  GetMenu(int index = -1 );                              // Меню
  virtual bool ChangeHotPointParam( double d );                       // Параметры для Hot точек

  /* ILibHPObject1 */            
  virtual bool GetHotPointsEx( HotPointDescription1* point, int index ); // Параметры для Hot точек
// КВН K10   virtual bool GetViewData( HotPointDescription1 * point, int index );
  virtual LPOLESTR GetCursorTextEx ( int index );
  virtual bool     UpdateCommand   ( int id    );                            
  virtual bool     SelectHotPoint  ( int index );
  virtual bool     UnselectHotPoint( int index );
// HOT_POINTS ##################################################################
// Менеджер свойств ##################################################################
    // События     
    // prButtonClick - Нажатие кнопки.
  virtual bool OnButtonClick( long buttonID );
    
    //prChangeControlValue - Изменение значения контрола
  virtual bool OnChangeControlValue( /*IPropertyControl* cntrl,*/ long ctrlID, const VARIANT& newVal );

//    //prControlCommand Нажатие кнопки контрола
//  virtual bool OnControlCommand(LPUNKNOWN  ctrl);

//    //prButtonUpdate        - Установка состояния кнопки спецпанели.
//  virtual bool OnButtonUpdate(long buttonID, long* check, BOOL* _enable);
          // Инициализация параметров процесса 
  
  // Виртуальная функция наполнения контролов элемента
  virtual void  ShowControls();
  // Отрисовать группу
  virtual void  RedrawPreview();
  // Количество параметров выводимых в гриде
  virtual int   ParamCount() { return 4; }
// Менеджер свойств ##################################################################
// Окно свойств ##################################################################
  virtual int      GetPropertyID ( int index );
  virtual BOOL     GetProperty   ( int index, PropertyParam & param );
  virtual BOOL     UpdateProperty( PropertyParam & param );
  virtual int      ApplyProperty ( PropertyParam & param );
  virtual LPOLESTR GetGroupName  ();
  virtual LPCTSTR  GetObjName    ();

// Окно свойств ##################################################################
};


//-------------------------------------------------------------------------------
// Вспомогательные функции
// ---
// Отрисовка геометрии гайки ( вид сбоку )
void Gayka_K_Side  ( float ls, float s, float D, float d2, float H, int j, int j2, bool appl );
// Отрисовка геометрии гайки ( вид - упрощенно )
void Gayka_K_Y     ( float ls, GAYKA5915 *tmp, int j, bool appl );
// Отрисовка геометрии гайки ( вид )
void Gayka_K       ( float ls, float l, float d1, float s, float l1, float H, short j, int j1, float d2, int j2, bool appl );
// Загрузить строку из ресурса
LPTSTR LoadStr     ( int id );

// Открыть базу данных
bool OpenGaykaBase ( SimpleBase &base );
// Читать параметры гайки по диаметру
bool ReadGaykaBase ( float d, SimpleBase &base, GAYKA5915 *pGayka );
// Закрыть базу данных
void CloseGaykaBase( SimpleBase &base );

//-------------------------------------------------------------------------------
// 
// ---
// КВН K10 extern AFX_EXTENSION_MODULE StepDLL;

//CPar* NewGayka5915( reference obj );

#endif // !defined(__GAYKA_H)
