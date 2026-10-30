// GaykaDlg.cpp : implementation file
//

#include "stdafx.h"
#include "gayka.h"
#include "GaykaDlg.h"
#include <math.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern KompasObjectPtr kompas;
extern CGaykaApp theApp;
//-------------------------------------------------------------------------------
//
// ---
int  Gayka5915::MacroElementParam() {
  // по умолчанию ресурсы берутся из .exe файла, для того чтобы их достать
  // из нашей dll вызовем этот define
  AFX_MANAGE_STATE(AfxGetStaticModuleState());

  int res = 0;
  Gayka5915* bufG = Dublicate();
  if ( bufG && bufG->OpenGaykaBase() ) {
    GaykaDlg* dlg = new GaykaDlg( *bufG );
    if ( dlg ) {
      kompas->ksEnableTaskAccess( 0 ); // закрыть доступ к компасу
      res = dlg->DoModal() == IDOK;    // вывод диалога
      kompas->ksEnableTaskAccess( 1 ); // открыть доступ к компасу
      delete dlg;
    }
    if ( res ) 
      Assign( *bufG );
    bufG->CloseGaykaBase();
    delete bufG;
  }
  return res;
}

//-------------------------------------------------------------------------------
//
// ---
static int ChoiceBMP( int drawType, int f ) {
  int bmpId = 0;
  switch ( drawType ) {
    case ID_VID     : bmpId = f & SIMPLE ? G5915_5 : f & ISPOLN ? G5915_9  : G5915_1; break;
    case ID_SIDEVID : bmpId = f & SIMPLE ? G5915_6 : f & ISPOLN ? G5915_10 : G5915_2; break;
    case ID_TOPVID  : bmpId = f & SIMPLE ? G5915_7 : G5915_3;                         break;
    case ID_VIDSEC  : bmpId = f & SIMPLE ? G5915_8 : f & ISPOLN ? G5915_11 : G5915_4; break;
  }
  return bmpId;
}

/////////////////////////////////////////////////////////////////////////////
// GaykaDlg dialog


GaykaDlg::GaykaDlg(Gayka5915& _gayka, CWnd* pParent /*=NULL*/)
  : CDialog(GaykaDlg::IDD, pParent),
    gayka  (_gayka)
{
  //{{AFX_DATA_INIT(GaykaDlg)
  m_stepHatch = gayka.GetGaykaParam().hatchShag;
  m_angHatch = gayka.GetGaykaParam().hatchAng;
  //}}AFX_DATA_INIT

  bitMapId = 0;
}


void GaykaDlg::DoDataExchange(CDataExchange* pDX)
{
  CDialog::DoDataExchange(pDX);
  //{{AFX_DATA_MAP(GaykaDlg)
  DDX_Control(pDX, IDC_DIAM, m_diam);
  DDX_Control(pDX, IDC_ADDKEY, m_key);
  DDX_Control(pDX, IDD_H_SHAG, m_stepEdit);
  DDX_Control(pDX, IDD_H_ANG, m_angEdit);
  DDX_Control(pDX, IDC_SLIMSTEP, m_slimStep);
  DDX_Control(pDX, IDC_SIMPLE, m_simple);
  DDX_Control(pDX, IDC_SPCOBJ, m_spcObj);
  DDX_Control(pDX, IDD_SHOW, m_showStatic);
  DDX_Control(pDX, IDC_PERF1, m_perf1);
  DDX_Text(pDX, IDD_H_SHAG, m_stepHatch);
  DDV_MinMaxFloat(pDX, m_stepHatch, 1.e-002f, 100.f);
  DDX_Text(pDX, IDD_H_ANG, m_angHatch);
  DDV_MinMaxFloat(pDX, m_angHatch, -360.f, 360.f);
  //}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(GaykaDlg, CDialog)
  //{{AFX_MSG_MAP(GaykaDlg)
  ON_WM_PAINT()
  ON_BN_CLICKED(IDC_SPCOBJ, OnSpcobj)
  ON_BN_CLICKED(IDC_VIEW, OnView)
  ON_BN_CLICKED(IDC_SECVIEW, OnSecview)
  ON_BN_CLICKED(IDC_SIDEVIEW, OnSideview)
  ON_BN_CLICKED(IDC_TOPVIEW, OnTopview)
  ON_BN_CLICKED(IDC_PERF1, OnPerf1)
  ON_BN_CLICKED(IDC_PERF2, OnPerf2)
  ON_BN_CLICKED(IDC_DRAWAXIS, OnDrawaxis)
  ON_BN_CLICKED(IDC_SIMPLE, OnSimple)
  ON_BN_CLICKED(IDC_SLIMSTEP, OnSlimstep)
  ON_EN_CHANGE(IDD_H_ANG, OnChangeHAng)
  ON_EN_CHANGE(IDD_H_SHAG, OnChangeHShag)
  ON_BN_CLICKED(IDC_ADDKEY, OnAddkey)
  ON_CBN_SELCHANGE(IDC_DIAM, OnSelchangeDiam)
  ON_BN_CLICKED(IDC_HELP_BUTTON, OnHelpButton)
  //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// GaykaDlg message handlers

//-------------------------------------------------------------------------------
//
// ---
BOOL GaykaDlg::OnInitDialog() 
{
  CDialog::OnInitDialog();
  
  CString buf;

  m_spcObj.SetCheck( gayka.GetFlagAttr() );              // объект СП
  m_simple.SetCheck( gayka.GetGaykaParam().f & SIMPLE ); // упрощенно
  m_slimStep.SetCheck( gayka.GetGaykaParam().f & PITCH );  // шаг мелкий
  if ( gayka.GetGaykaParam().f & PITCHOFF )
    m_slimStep.EnableWindow( false );
  
  if ( gayka.GetGaykaParam().f & TAKEISPOLN ) {  // исполнение
    m_perf1.EnableWindow();
    int check = gayka.GetGaykaParam().f & ISPOLN;
    CheckDlgButton( IDC_PERF1, !check );
    CheckDlgButton( IDC_PERF2, check  );
  }
  else
    m_perf1.EnableWindow( false );
  
  CheckDlgButton( IDC_SECVIEW,  gayka.GetDrawType() == ID_VIDSEC  );
  CheckDlgButton( IDC_TOPVIEW,  gayka.GetDrawType() == ID_TOPVID  );
  CheckDlgButton( IDC_SIDEVIEW, gayka.GetDrawType() == ID_SIDEVID );
  CheckDlgButton( IDC_VIEW,      gayka.GetDrawType() == ID_VID     );

  m_stepHatch = gayka.GetGaykaParam().hatchShag;
  m_angHatch  = gayka.GetGaykaParam().hatchAng;
  SetHatchWindowEnable( gayka.GetDrawType() == ID_VIDSEC );

  if ( !(gayka.GetGaykaParam().f1 & KEY_S_ON) )
    m_key.ShowWindow( SW_HIDE );
  else {
    m_key.SetCheck( gayka.GetGaykaParam().f1 & KEY_S );
    m_key.EnableWindow( gayka.GetGaykaParam().f1 & KEY_S_GRAY );
  }

  ksLtVariantPtr      item( kompas->GetParamStruct(ko_LtVariant) );
  ksDynamicArrayPtr  arr  ( gayka.GetParamTmp()->GetUserArray() );
  if ( item && arr ) {
    int i = 1;
    while ( i ) {
      i = gayka.GetDataBase()->ksReadRecord( gayka.GetBase().bg, gayka.GetBase().rg, 
                                             gayka.GetParamTmp() );

      if ( i ) {
        arr->ksGetArrayItem( 0, item );
        buf.Format( _T("%g"), item->floatVal );
        m_diam.AddString( buf );
      }
    }
    buf.Format( _T("%g"), gayka.GetGaykaParam().dr );
    m_diam.SelectString( -1, buf );
  }

  CheckDlgButton( IDC_DRAWAXIS, !(gayka.GetGaykaParam().f & AXIS_OFF) );   // ось рисовать
  CalcMassa();

  bitMapId = ChoiceBMP( gayka.GetDrawType(), gayka.GetGaykaParam().f );
  m_showStatic.Invalidate();
  UpdateData( FALSE );
  kompas->ksConvertLangWindow( (long)m_hWnd/*HWND*/ );

  return TRUE;  // return TRUE unless you set the focus to a control
                // EXCEPTION: OCX Property Pages should return FALSE
}

//-------------------------------------------------------------------------------
//
// ---
void GaykaDlg::OnPaint() 
{
  CPaintDC dc(this); // device context for painting
  
  kompas->ksDrawSlide( (long)m_showStatic.m_hWnd, bitMapId );

  // Do not call CDialog::OnPaint() for painting messages
}

//-------------------------------------------------------------------------------
// нажатие на создать объект СП
// ---
void GaykaDlg::OnSpcobj() 
{
  gayka.GetFlagAttr() = !!m_spcObj.GetCheck();  
}

//-------------------------------------------------------------------------------
// нажатие на Вид
// ---
void GaykaDlg::OnView() 
{
  if ( IsDlgButtonChecked(IDC_VIEW) ) {
    gayka.GetDrawType() = ID_VID;  
    SetHatchWindowEnable( false );
    bitMapId = ChoiceBMP( gayka.GetDrawType(), gayka.GetGaykaParam().f );
    OnPaint();
  }
}

//-------------------------------------------------------------------------------
// нажатие на Вид/разрез
// ---
void GaykaDlg::OnSecview() 
{
  if ( IsDlgButtonChecked(IDC_SECVIEW) ) {
    gayka.GetDrawType() = ID_VIDSEC;  
    SetHatchWindowEnable( true );
    bitMapId = ChoiceBMP( gayka.GetDrawType(), gayka.GetGaykaParam().f );
    OnPaint();
  }
}

//-------------------------------------------------------------------------------
// нажатие на Вид сбоку
// ---
void GaykaDlg::OnSideview() 
{
  if ( IsDlgButtonChecked(IDC_SIDEVIEW) ) {
    gayka.GetDrawType() = ID_SIDEVID;  
    SetHatchWindowEnable( false );
    bitMapId = ChoiceBMP( gayka.GetDrawType(), gayka.GetGaykaParam().f );
    OnPaint();
  }
}

//-------------------------------------------------------------------------------
// нажатие на Вид сверху
// ---
void GaykaDlg::OnTopview() 
{
  if ( IsDlgButtonChecked(IDC_TOPVIEW) ) {
    gayka.GetDrawType() = ID_TOPVID;  
    SetHatchWindowEnable( false );
    bitMapId = ChoiceBMP( gayka.GetDrawType(), gayka.GetGaykaParam().f );
    OnPaint();
  }
}

//-------------------------------------------------------------------------------
// нажатие на Исполнение 1
// ---
void GaykaDlg::OnPerf1() 
{
  if ( IsDlgButtonChecked(IDC_PERF1) ) {
    gayka.GetGaykaParam().f &= ~ISPOLN;  
  }
  else
    gayka.GetGaykaParam().f |= ISPOLN;
  bitMapId = ChoiceBMP( gayka.GetDrawType(), gayka.GetGaykaParam().f );
  OnPaint();
}

//-------------------------------------------------------------------------------
// нажатие на Исполнение 2
// ---
void GaykaDlg::OnPerf2() 
{
  if ( IsDlgButtonChecked(IDC_PERF2) ) 
    gayka.GetGaykaParam().f |= ISPOLN;
  else
    gayka.GetGaykaParam().f &= ~ISPOLN;  
  bitMapId = ChoiceBMP( gayka.GetDrawType(), gayka.GetGaykaParam().f );
  OnPaint();
}

//-------------------------------------------------------------------------------
// изменение состояния параметров штриховки
// ---
void GaykaDlg::SetHatchWindowEnable(bool enable)
{
  m_stepEdit.EnableWindow( enable );
  m_angEdit.EnableWindow ( enable );
}

//-------------------------------------------------------------------------------
//
// ---
void GaykaDlg::OnDrawaxis() 
{
  if ( !IsDlgButtonChecked(IDC_DRAWAXIS) )
    gayka.GetGaykaParam().f |= AXIS_OFF;
  else
    gayka.GetGaykaParam().f &=~ AXIS_OFF;
}

//-------------------------------------------------------------------------------
//
// ---
void GaykaDlg::OnSimple() 
{
  !!m_simple.GetCheck() ? gayka.GetGaykaParam().f |= SIMPLE 
                        : gayka.GetGaykaParam().f &= ~SIMPLE;
  bitMapId = ChoiceBMP( gayka.GetDrawType(), gayka.GetGaykaParam().f );
  OnPaint();
}

//-------------------------------------------------------------------------------
//
// ---
void GaykaDlg::OnSlimstep() 
{
  if ( !!m_slimStep.GetCheck() )
    gayka.GetGaykaParam().f |= PITCH;
  else
    gayka.GetGaykaParam().f &= ~PITCH;

  if ( !gayka.ReadGaykaBase() )
    OnCancel();

  CalcMassa();
}

//-------------------------------------------------------------------------------
//
// ---
void GaykaDlg::OnChangeHAng() 
{
  UpdateData();
  if ( ::fabs(m_angHatch - gayka.GetGaykaParam().hatchAng) > 0.001 ) 
    gayka.GetGaykaParam().hatchAng = m_angHatch;
}

//-------------------------------------------------------------------------------
//
// ---
void GaykaDlg::OnChangeHShag() 
{
  UpdateData();
  if ( ::fabs(m_stepHatch - gayka.GetGaykaParam().hatchShag) > 0.001 ) 
    gayka.GetGaykaParam().hatchShag = m_stepHatch;
}

//-------------------------------------------------------------------------------
//
// ---
void GaykaDlg::CalcMassa()
{
  massa = (float)(gayka.GetGaykaParam().massa * (!gayka.GetGaykaParam().indexMassa 
                                                   ? 1 : gayka.GetGaykaParam().indexMassa == 1 
                                                          ? 0.356 : 1.08) );
}

//-------------------------------------------------------------------------------
//
// ---
void GaykaDlg::OnAddkey() 
{
  if ( !!m_key.GetCheck() )
    gayka.GetGaykaParam().f1 |= KEY_S;
  else
    gayka.GetGaykaParam().f1 &=~ KEY_S;

  if ( !gayka.ReadGaykaBase() ) {
    OnCancel();  return;
  }

  CalcMassa();
}

//-------------------------------------------------------------------------------
// изменение в списке Диаметров
// ---
void GaykaDlg::OnSelchangeDiam() 
{
  CString str;
  m_diam.GetLBText( m_diam.GetCurSel(), str.GetBuffer(20) );
  str.ReleaseBuffer();
  float diam = (float)::_tcstod( str, NULL );
  if ( ::fabs(diam - gayka.GetGaykaParam().dr) > 0.001 ) {
    gayka.GetGaykaParam().dr = diam;

    if ( !gayka.ReadGaykaBase() ) {
      OnCancel();  return;
    }

    m_key.EnableWindow( gayka.GetGaykaParam().f1 & KEY_S_GRAY );

    if ( gayka.GetGaykaParam().f & PITCHOFF )
      m_slimStep.EnableWindow( false );
    else
      m_slimStep.EnableWindow( true );

    CalcMassa();

    bitMapId = ChoiceBMP( gayka.GetDrawType(), gayka.GetGaykaParam().f );
    OnPaint();
  }
}

#define LIB_HELPFILE          _T("gayka.chm") // имя файла помощи

//-------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------
int GetHelpFileName( LPTSTR fileName ) {
  if ( ::GetModuleFileName( theApp.m_hInstance, fileName, 255) ) {
    TCHAR * c = ::_tcschr( fileName, _T('\\') );
    if ( c ) {
      *(c + 1) = '\0';
      ::_tcscat_s( fileName, 255, LIB_HELPFILE );
      OFSTRUCT ofs;
      if ( ::OpenFile(_bstr_t(fileName), &ofs, OF_EXIST) != HFILE_ERROR )
        return 1;
    }
  }
  return 0;
}

//-------------------------------------------------------------------------------
// вызов справки
// ---
void GaykaDlg::OnHelpButton() 
{
  TCHAR fName[255];
  if ( GetHelpFileName(fName) )
    kompas->ksOpenHelpFile( fName, HELP_CONTEXT, 1 );
  else
    kompas->ksError( _T("Файл gayka.chm не найден") );
}
