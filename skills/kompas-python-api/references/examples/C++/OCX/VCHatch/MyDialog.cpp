////////////////////////////////////////////////////////////////////////////////
//
// Пример создания ActiveX Control-а
// Диалог - Параметры штриховки
// <VCHatch.h>
//
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "VCHatch.h"
#include "MyDialog.h"
#include "VCHatchCtl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

char buf[20];

/////////////////////////////////////////////////////////////////////////////
// MyDialog dialog
MyDialog::MyDialog(CVCHatchCtrl &ctrl, double &ang, double &step, BOOL& enable, CWnd* pParent /*=NULL*/)
	: CDialog(MyDialog::IDD, pParent),
    m_dAngle(ang ),
    m_dStep (step),
    m_ctrl  (ctrl),
    m_enable(enable), 
    focusInEdit( false ) 
{
	//{{AFX_DATA_INIT(MyDialog)
	
	//}}AFX_DATA_INIT
}



void MyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(MyDialog)
	DDX_Control(pDX, IDC_TEXT_STEP,  m_TextStep  );
	DDX_Control(pDX, IDC_TEXT_ANGLE, m_TextAngle );
	DDX_Control(pDX, IDC_STEP,       m_step      );
	DDX_Control(pDX, IDC_ANGLE,      m_angle     );
	DDX_Text(pDX, IDC_STEP, m_dStep);
	DDV_MinMaxDouble(pDX, m_dStep, 1.e-002, 100.);
	DDX_Text(pDX, IDC_ANGLE, m_dAngle);
	DDV_MinMaxDouble(pDX, m_dAngle, -360, 360 );
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(MyDialog, CDialog)
	//{{AFX_MSG_MAP(MyDialog)
	ON_EN_KILLFOCUS(IDC_ANGLE, OnKillfocusAngle)
	ON_EN_KILLFOCUS(IDC_STEP, OnKillfocusStep)
	//}}AFX_MSG_MAP
  ON_WM_GETDLGCODE()
END_MESSAGE_MAP()

UINT MyDialog::OnGetDlgCode()
{
  return DLGC_WANTARROWS | DLGC_WANTALLKEYS | DLGC_WANTCHARS | DLGC_WANTTAB;
}

BOOL MyDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	sprintf(buf, "%g", m_dAngle);
  m_angle.SetWindowText(CString(buf));
  sprintf(buf, "%g", m_dStep);
	m_step.SetWindowText(CString(buf));
  SetEnable( m_enable );
	return TRUE; // return TRUE unless you set the focus to a control
	             // EXCEPTION: OCX Property Pages should return FALSE
}

void MyDialog::OnKillfocusAngle() 
{
  if ( UpdateData() ) {
    m_ctrl.FireChangeAngle();
  	focusInEdit = FALSE;
  }
}

void MyDialog::OnKillfocusStep() 
{
  if ( UpdateData() ) {
    m_ctrl.FireChangeStep();
  }
}

void MyDialog::SetEnable( BOOL enable ) {
  if ( m_hWnd ) { 
    EnableWindow( enable );
    m_angle.EnableWindow( enable );
    m_step.EnableWindow( enable );
    m_TextStep.EnableWindow( enable );
	  m_TextAngle.EnableWindow( enable );
  }
}

BOOL MyDialog::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo) 
{
	return CDialog::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

