///////////////////////////////////////////////////////////////////////////////
//
// PropDlg.cpp - класс окна диалога параметров конвертации
//
///////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "myconverter.h"
#include "PropDlg.h"
#include "LibConverter.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//-----------------------------------------------------------------------------
// Конструктор
// ---
PropDlg::PropDlg(CWnd* pParent /*=NULL*/)
	: CDialog(PropDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(PropDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


//-----------------------------------------------------------------------------
//
// ---
void PropDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PropDlg)
	DDX_Control(pDX, IDC_LINES, m_LinesStyle);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PropDlg, CDialog)
	//{{AFX_MSG_MAP(PropDlg)
	ON_WM_CANCELMODE()
	ON_BN_CLICKED(IDC_LINES, OnLines)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PropDlg message handlers

//-----------------------------------------------------------------------------
// Инициализация диалога
// ---
BOOL PropDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
  m_LinesStyle.SetCheck( ::GetLibConverter().GetSaveLineStyle() );

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


//-----------------------------------------------------------------------------
// 
// ---
void PropDlg::OnCancelMode() 
{
	CDialog::OnCancelMode();
	
	// TODO: Add your message handler code here
	
}


//-----------------------------------------------------------------------------
// При выборе сохранения стиля линии
// ---
void PropDlg::OnLines() 
{
  // Галочка снята - стиль линий не сохранять
  ::GetLibConverter().SetSaveLineStyle( !!m_LinesStyle.GetCheck() );
}


//-------------------------------------------------------------------------------
// Ввывод диалога параметров конвертации
// ---
BOOL ShowPropDlg( CWnd * pParent = NULL )
{
  BOOL res = FALSE;
  PropDlg * m_dlg = new PropDlg( pParent /*=NULL*/ );
  if ( m_dlg ) 
  {
    EnableTaskAccess( 0 );          // Закрыть доступ к компасу
    res = m_dlg->DoModal() == IDOK; // Вывод окна диалога
    EnableTaskAccess( 1 );          // Открыть доступ к компасу
    delete m_dlg;
  }
  return res;
}

