// gayka.h : main header file for the GAYKA DLL
//

#if !defined(AFX_GAYKA_H__E5BADD45_D4CD_11D4_BF5E_0050BADBD5F5__INCLUDED_)
#define AFX_GAYKA_H__E5BADD45_D4CD_11D4_BF5E_0050BADBD5F5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
  #error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"    // main symbols

#define SPCOBJ_CREATE true                 //признак подключения объекта к спецификации

#define AXIS_OFF     0x1    // 0 рисовать >0 не рисовать
#define PITCH        0x2    // крупный шаг >0 мелкий шаг
#define SIMPLE       0x10   // нормальная отрисовка >0 упрощенная отрисовка
#define ISPOLN       0x80   // исполнение 1 >0 исполнение 2
#define TAKEISPOLN   0x100  // 0 не учитывать исполнение  >0 учитывать исполнение

//дополнитеоьные маски
#define KEY_S_ON     0x1 // 0- выключены дополнитеоьные размеры под ключ > 0 - включены
#define KOEFF_MAT_ON 0x4 // 0- только металл, >0 другие материалы
#define KEY_S        0x2 // 0-обычный размер под ключ; > 0 дополнительный
#define KEY_S_GRAY   0x8 // > 0 греить checkbox "дополнитеоьные размеры под ключ"
#define PITCHOFF     0x800  // есть крупный и мелкий шаг >0 есть только крупный
// коэффициент для расчета диаметра резьбы по шагу резьбы
#define MODSTEP_REAL 0.5412765877

/////////////////////////////////////////////////////////////////////////////
// CGaykaApp
// See gayka.cpp for the implementation of this class
//

class CGaykaApp : public CWinApp
{
public:
  CGaykaApp();

// Overrides
  // ClassWizard generated virtual function overrides
  //{{AFX_VIRTUAL(CGaykaApp)
  //}}AFX_VIRTUAL

  //{{AFX_MSG(CGaykaApp)
    // NOTE - the ClassWizard will add and remove member functions here.
    //    DO NOT EDIT what you see in these blocks of generated code !
  //}}AFX_MSG
  DECLARE_MESSAGE_MAP()
};


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

//-------------------------------------------------------------------------------
// параметры гайки ГОСТ 5915
// ---
struct GAYKA5915{
  float  dr;
  float  s;
  float  D;
  float  da;
  float  h;
  float  d2;
  float  p;
  short  f;          // битовые маски
  short  klass;      // класс точности
  short  gost;       // номер госта
  float  hatchAng;
  float  hatchShag;
  short  ver;        // версия макро
  float  massa;
  short  indexMassa; // 0-металл 1- алюмин сплав 2-латунь
  short  f1;          // битовые маски
};

//-------------------------------------------------------------------------------
// указатели на отношения к БД
// ---
struct SimpleBase {
  reference bg;  // указатель базы
  reference rg; // указатель отношения
};

struct HotPointDescription;

//-------------------------------------------------------------------------------
// класс гайки ГОСТ 5915
// ---
class  Gayka5915 {
protected :
  reference            refMacr;
  UINT                countObj;
  int                  flagMode;
  ksUserParamPtr       paramTmp; // параметры для чтения БД
  ksUserParamPtr      param;    // параметры для Get/SetMacroParam
  ksDataBaseObjectPtr  data;     // интерфейс БД
  SimpleBase          base;     // указатели на отношения к БД
  BaseMakroParam      par;
  GAYKA5915            tmp;

public :
  Gayka5915();
  Gayka5915( Gayka5915& other ); 

  operator void* () { return &par.ang; }  //оператор приведения по умолчанию к  void*
  
  void        Assign( Gayka5915& other );
  Gayka5915*  Dublicate();

           UINT        GetObjCount() { return countObj; }
           short&      GetDrawType() { return par.drawType; }
  unsigned short&      GetFlagAttr() { return par.flagAttr; }
           void        SetAttr() { par.flagAttr = par.flagAttr ? false : true; }
           int        GetFlagMode() { return flagMode; }

           BaseMakroParam&    GetParam() { return par; }   
           GAYKA5915&          GetGaykaParam() { return tmp; } 
           ksDataBaseObjectPtr&  GetDataBase() { return data; }
           SimpleBase&        GetBase() { return base; }
           ksUserParamPtr&       GetParamTmp() { return paramTmp; }

  void      SetSimple()    {};
  void      SetDimension() {};
  int        ServiceObj() { return 1;};
  void      ServiceObj1( float , float ) {};
  int        Size() { return sizeof(BaseMakroParam) + sizeof(GAYKA5915); }
  bool      IsSpcObjCreate() { return SPCOBJ_CREATE;}; //функция проверки подключения атрибутов или нет
  void      CalkPaket() {} ; //  измерить высоту пакета

  void      InitUserParamTmp();
  void      GetUserParamTmp();
  void      InitUserParam();
  void      SetUserParam();
  void      GetUserParam();
  int        ChoiceMenuId();
  void      SetHatchAngl();
  void      SetHatchShag();
  void      SetParam();
  reference  EditSpcObj( reference *spcObj, reference geom );
  void      GetGroup( reference &gr );
  void      gayka_sverhu();
  void      gayka_p_k( int j );
  bool      DrawSpcObj( reference group );
  void      Draw1();
  int        MacroElementParam();
  int        _ConnectDB( reference bd, LPCTSTR name );
  int        OpenGaykaBase();
  void      CloseGaykaBase();
  int        ReadGaykaBase( float d = 0 );
  void      SetPlacement( double x, double y, double angl );

// HOT_POINTS ##################################################################
            bool        GetHotPoints( HotPointDescription* point,  int index );
            int         SetHotPoint ( HotPointDescription* point,  int index );
            bool        GetCursorText( int index, char** text );
            int         GetMenu();
            bool        ExecuteCommand( int id );
            bool        EditComplete( int index, BOOL success );
            bool        ChangeHotPointParam( double d );
// HOT_POINTS ##################################################################
};
/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GAYKA_H__E5BADD45_D4CD_11D4_BF5E_0050BADBD5F5__INCLUDED_)
