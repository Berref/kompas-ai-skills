#ifndef _DLGCONFIG_H
#define _DLGCONFIG_H  

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgConfig.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DlgConfig dialog

class DlgConfig : public CDialog
{
// Construction
public:
  DlgConfig(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
  //{{AFX_DATA(DlgConfig)
  enum { IDD = IDD_DIALOG_CFG };
  BOOL  m_auto;
  BOOL  m_mes_2DDOC;
  BOOL  m_mes_3DDOC;
  BOOL  m_mes_APP;
  BOOL  m_mes_DOC;
  BOOL  m_mes_OBJ_2DDOC;
  BOOL  m_mes_OBJ_3DDOC;
  BOOL  m_mes_OBJ_SPC;
  BOOL  m_mes_SELECT;
  BOOL  m_mes_SPC;
  BOOL  m_mes_SPCDOC;
  BOOL  m_mes_STAMP;
  //}}AFX_DATA


// Overrides
  // ClassWizard generated virtual function overrides
  //{{AFX_VIRTUAL(DlgConfig)
  protected:
  virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
  //}}AFX_VIRTUAL

// Implementation
protected:

  // Generated message map functions
  //{{AFX_MSG(DlgConfig)
  //}}AFX_MSG
  DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
#endif // _DLGCONFIG_H