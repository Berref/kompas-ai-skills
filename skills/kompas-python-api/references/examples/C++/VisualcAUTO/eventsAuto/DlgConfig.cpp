// DlgConfig.cpp : implementation file
//

#include "stdafx.h"
#include "eventsAuto.h"
#include "DlgConfig.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgConfig dialog


DlgConfig::DlgConfig(CWnd* pParent /*=NULL*/)
  : CDialog(DlgConfig::IDD, pParent)
{
  //{{AFX_DATA_INIT(DlgConfig)
  m_auto = FALSE;
  m_mes_2DDOC = TRUE;
  m_mes_3DDOC = TRUE;
  m_mes_APP = TRUE;
  m_mes_DOC = TRUE;
  m_mes_OBJ_2DDOC = TRUE;
  m_mes_OBJ_3DDOC = TRUE;
  m_mes_OBJ_SPC = TRUE;
  m_mes_SELECT = TRUE;
  m_mes_SPC = TRUE;
  m_mes_SPCDOC = TRUE;
  m_mes_STAMP = TRUE;
  //}}AFX_DATA_INIT
}


void DlgConfig::DoDataExchange(CDataExchange* pDX)
{
  CDialog::DoDataExchange(pDX);
  //{{AFX_DATA_MAP(DlgConfig)
  DDX_Check(pDX, IDC_CHECK_AUTO, m_auto);
  DDX_Check(pDX, IDC_CHECK_MESSAGE_2DDOC, m_mes_2DDOC);
  DDX_Check(pDX, IDC_CHECK_MESSAGE_3DDOC, m_mes_3DDOC);
  DDX_Check(pDX, IDC_CHECK_MESSAGE_APP, m_mes_APP);
  DDX_Check(pDX, IDC_CHECK_MESSAGE_DOC, m_mes_DOC);
  DDX_Check(pDX, IDC_CHECK_MESSAGE_OBJ_2DDOC, m_mes_OBJ_2DDOC);
  DDX_Check(pDX, IDC_CHECK_MESSAGE_OBJ_3DDOC, m_mes_OBJ_3DDOC);
  DDX_Check(pDX, IDC_CHECK_MESSAGE_OBJ_SPC, m_mes_OBJ_SPC);
  DDX_Check(pDX, IDC_CHECK_MESSAGE_SELECT, m_mes_SELECT);
  DDX_Check(pDX, IDC_CHECK_MESSAGE_SPC, m_mes_SPC);
  DDX_Check(pDX, IDC_CHECK_MESSAGE_SPCDOC, m_mes_SPCDOC);
  DDX_Check(pDX, IDC_CHECK_MESSAGE_STAMP, m_mes_STAMP);
  //}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgConfig, CDialog)
  //{{AFX_MSG_MAP(DlgConfig)
  //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgConfig message handlers
