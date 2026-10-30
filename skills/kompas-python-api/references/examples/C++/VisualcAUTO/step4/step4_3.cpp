// step4_3.cpp : implementation file
//

#include "stdafx.h"
#include <afxwin.h>
#include "step4.h"
#include "step4_3.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern KompasObjectPtr kompas;

/////////////////////////////////////////////////////////////////////////////
// TestShowDlg dialog


TestShowDlg::TestShowDlg( ksDocument2DPtr& _doc, CWnd* pParent /*=NULL*/ )
  : CDialog(TestShowDlg::IDD, pParent),
  doc      (_doc)
{
  //{{AFX_DATA_INIT(TestShowDlg)
  //}}AFX_DATA_INIT
  
  kompasDocName = "c:\\1.frw";
  IdSlide  = 100;
  
// Для отрисовки слайда из файла ресурса
// resurs = kompas.ksReadString( "Введите имя *.rc файла", "c:\\libVC\\st4.rc", 255 );
}


void TestShowDlg::DoDataExchange(CDataExchange* pDX)
{
  CDialog::DoDataExchange(pDX);
  //{{AFX_DATA_MAP(TestShowDlg)
  DDX_Control(pDX, IDC_SHOW_STATIC, m_ShowStatic);
  //}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(TestShowDlg, CDialog)
  //{{AFX_MSG_MAP(TestShowDlg)
  ON_WM_PAINT()
  //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// TestShowDlg message handlers

BOOL TestShowDlg::OnInitDialog() 
{
  CDialog::OnInitDialog();

  if ( IdSlide == 0 && !(doc && doc->reference)  ) 
  {
    kompas->ksError(_T("Графический документ не активен"));
     return FALSE;
  }   
  return TRUE;
}

void TestShowDlg::OnPaint() 
{
  CPaintDC dc(this); 
  
//  kompas.ksDrawBitmap( (long)m_ShowStatic.m_hWnd, IdSlide );
//  doc.ksDrawKompasDocument( (long)m_ShowStatic.m_hWnd, kompasDocName );

  if( IdSlide != 0 )
    kompas->ksDrawSlide ( PtrToLong(m_ShowStatic.m_hWnd), IdSlide ); // Отрисовка слайда
  else {
    reference gr = doc->ksNewGroup( 1 );
      doc->ksMtr( 20, 15, 45, 1, 1 );
      doc->ksLineSeg( -10, 0,  10,  0,  1 );
      doc->ksLineSeg( 10,  0,  10,  20, 1 );
      doc->ksLineSeg( 10,  20, -10, 20, 1 );
      doc->ksLineSeg( -10, 20, -10, 0,  1 );
      doc->ksDeleteMtr();
    doc->ksEndGroup();
    doc->ksDrawKompasGroup( PtrToLong(m_ShowStatic.m_hWnd)/*Несущее окно*/, gr/*Группа*/);
    doc->ksDeleteObj( gr );
  }

//  Для отладки слайда можно использовать функцию: при изменении файла .rc не нужно
//  перекомпилировать библиотеку
//  if ( !resurs.IsEmpty() )
//    kompas.ksDrawSlideFromFile( (long)m_ShowStatic.m_hWnd, resurs );
}

//-------------------------------------------------------------------------------
//
// ---
void TestShowDialog( ksDocument2DPtr& doc ) {
  // По умолчанию ресурсы берутся из .exe файла, для того чтобы их достать
  // из нашей dll вызовем этот define
  AFX_MANAGE_STATE(AfxGetStaticModuleState());

  TestShowDlg* dlg = new TestShowDlg( doc );
  if ( dlg ) {
    kompas->ksEnableTaskAccess( 0 ); // Закрыть доступ к компасу
    dlg->DoModal();                  // Вывод диалога
    kompas->ksEnableTaskAccess( 1 ); // Открыть доступ к компасу
    delete dlg;
  }
}

