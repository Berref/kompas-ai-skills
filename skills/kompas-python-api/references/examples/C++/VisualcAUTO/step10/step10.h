// step10.h : main header file for the STEP10 DLL
//

#if !defined(AFX_STEP10_H__8C423F64_D0EF_11D4_872B_0050BADDB58C__INCLUDED_)
#define AFX_STEP10_H__8C423F64_D0EF_11D4_872B_0050BADDB58C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
  #error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"    // main symbols

/////////////////////////////////////////////////////////////////////////////
// CStep10App
// See step10.cpp for the implementation of this class
//

class CStep10App : public CWinApp
{
public:
  CStep10App();

// Overrides
  // ClassWizard generated virtual function overrides
  //{{AFX_VIRTUAL(CStep10App)
  //}}AFX_VIRTUAL

  //{{AFX_MSG(CStep10App)
    // NOTE - the ClassWizard will add and remove member functions here.
    //    DO NOT EDIT what you see in these blocks of generated code !
  //}}AFX_MSG
  DECLARE_MESSAGE_MAP()
};

struct BOLT {
  float dr;   /*диаметр резьбы*/
  float p;   /*шаг резьбы */
  float s;    /*размер под ключ*/
  float h;    /*высота головки */
  float D;    /* диаметр описанной окружности*/
  float d3;   /*диаметр отв. в стержне*/
  float h2;   /*высота подголовка*/
  float  L;   /*длина стержня*/
  float l1;   /*расстояние до отверстия в стержне*/
  float b;    /*длина резьбовой части*/
  float d2;   /*диаметр под головкой*/
  float z4;   /*величина фаски конца*/
  short    k;    // 1 длина резьбы ниже ломманной(резьба только на b) ; 2 - выше ломанной (резьба до головки и  на в )
  unsigned short f;       /*битовые маски*/
  short klass;   /*класс точности*/
  unsigned short gost;    /*номер госта*/
};

#define ISPOLN       0x80   // исполнение 1 >0 исполнение 2
#define PITCH        0x2    // крупный шаг >0 мелкий шаг
#define SPC_NAME 5
/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STEP10_H__8C423F64_D0EF_11D4_872B_0050BADDB58C__INCLUDED_)
