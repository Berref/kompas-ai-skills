////////////////////////////////////////////////////////////////////////////////
//
// 
//
////////////////////////////////////////////////////////////////////////////////
#ifndef __eventsAuto_H
#define __eventsAuto_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"

#ifndef CIniFile_H
#include "iniFile.h"
#endif


//-------------------------------------------------------------------------------
// 
// ---
extern KompasObjectPtr kompas;


////////////////////////////////////////////////////////////////////////////////
//
// 
//
////////////////////////////////////////////////////////////////////////////////
class CeventsAutoApp : public CWinApp
{
public:
  CeventsAutoApp();
  virtual int ExitInstance();

  void ConfigDlg();

  CIniFile m_iniFile;
  bool  m_auto;
  bool  m_mes_3DDOC;
  bool  m_mes_2DDOC;
  bool  m_mes_APP;
  bool  m_mes_DOC;
  bool  m_mes_OBJ_2DDOC;
  bool  m_mes_OBJ_3DDOC;
  bool  m_mes_OBJ_SPC;
  bool  m_mes_SELECT;
  bool  m_mes_SPC;
  bool  m_mes_SPCDOC;
  bool  m_mes_STAMP;

  //{{AFX_VIRTUAL(CeventsAutoApp)
  public:
  virtual BOOL InitInstance();
  //}}AFX_VIRTUAL

  //{{AFX_MSG(CeventsAutoApp)
  //}}AFX_MSG
  DECLARE_MESSAGE_MAP()
};


// Объект приложение
extern CeventsAutoApp theApp;


//-------------------------------------------------------------------------------
//
// ---
void AdviseDoc( LPDISPATCH doc, long docType, 
                bool fSelectMng = true, 
                bool fObject = true, 
                bool fStamp = true,
                bool fDocument = true,
                bool fSpecification = true,
                bool fSpcObject = true,
                long objType = -1);


/////////////////////////////////////////////////////////////////////////////

#endif // !defined(__eventsAuto_H)
