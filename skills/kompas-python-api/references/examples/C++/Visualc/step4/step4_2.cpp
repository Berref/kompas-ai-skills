//////////////////////////////////////////////////////////////////////////////// 
// 
// step4_2.cpp - Описание диалога отрисовки слайда
// 
//////////////////////////////////////////////////////////////////////////////// 
#include "stdafx.h"
#include "resource.h"

#ifndef __LIBTOOL_H
#include <libtool.h>
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


//////////////////////////////////////////////////////////////////////////////// 
// 
// Диалог отрисовки слайда
// 
// Для отрисовки слайда или Bitmap c ID из ресурса
// Для отрисовки слайда из файла ресурса
// Отрисовка текущего документа
// Для отрисовки фрагмента из файла
// Для отрисовки группы
// 
//////////////////////////////////////////////////////////////////////////////// 
class TestShowDlg : public CDialog
{
public:
  TCHAR m_fileName[255];  // Для отрисовки фрагмента из файла документа
                         // или из файла ресурса
  int  m_slideId;        // Для отрисовки слайда или Bitmap c ID из ресурса
  reference rGroup;
  TestShowDlg( CWnd* pParent = NULL );
  
  // {{AFX_DATA( TestShowDlg )
  enum { IDD = IDD_TESTDIALOG };
  CStatic m_StaticShow;
  // }}AFX_DATA

  // {{AFX_VIRTUAL( TestShowDlg )
protected:
  virtual void DoDataExchange( CDataExchange* pDX );
  // }}AFX_VIRTUAL

protected:
  // {{AFX_MSG( TestShowDlg )
  virtual BOOL OnInitDialog();
  afx_msg void OnPaint();
  // }}AFX_MSG

  DECLARE_MESSAGE_MAP()
};


//-------------------------------------------------------------------------------
// Консруктор
// ---
TestShowDlg::TestShowDlg( CWnd* pParent /*=NULL*/ )
  : CDialog( TestShowDlg::IDD, pParent ),
  m_slideId( 0 ),
  rGroup   ( 0 )
{ 
  m_fileName[0] = '\0';
  // {{AFX_DATA_INIT( TestShowDlg )
  // }}AFX_DATA_INIT
}


//-------------------------------------------------------------------------------
// Создание и инициализация контролов
// ---
void TestShowDlg::DoDataExchange( CDataExchange* pDX )
{
  CDialog::DoDataExchange( pDX );
  // {{AFX_DATA_MAP( TestShowDlg )
  DDX_Control( pDX, IDC_SHOW_STATIC, m_StaticShow );
  // }}AFX_DATA_MAP
}


//-------------------------------------------------------------------------------
// Карта сообщений
// ---
BEGIN_MESSAGE_MAP( TestShowDlg, CDialog )
  // {{AFX_MSG_MAP( TestShowDlg )
  ON_WM_PAINT()
  // }}AFX_MSG_MAP
END_MESSAGE_MAP()


//-------------------------------------------------------------------------------
// Инициализация диалога отрисовки слайда
// ---
BOOL TestShowDlg::OnInitDialog()
{
  CDialog::OnInitDialog();

  // Для отрисовки слайда или Bitmap c ID из ресурса
  m_slideId = 100;
/* 
  // Для отрисовки фрагмента из файла
  _tcscpy( m_fileName, _T("c:\\Example.frw") );
  ReadStringT( _T("Введите имя *.frw файла"), m_fileName, 255 );
*/

  /*
  // Для отрисовки слайда из файла ресурса
  _tcscpy( m_fileName, _T("c:\\Example.rc") );
  ReadStringT( _T("Введите имя *.rc файла"), m_fileName, 255 );
  */
  
 /*
  // Для отрисовки группы
  if ( ksGetCurrentDocument( 1 ) )
  {
    // Создание группы объектов, type - тип группы ( 0 - определяет модельный, 1 - временный )
    rGroup = NewGroup( 1 );
      Mtr( 20, 15, 45, 1 ); // Матрица преобразования координат ( 20 по оси OX, 15 по оси OY, поворот на 45 градусов )
        LineSeg( -10, 0,   10, 0,  1 );
        LineSeg(  10, 0,   10, 20, 1 );
        LineSeg(  10, 20, -10, 20, 1 );
        LineSeg( -10, 20, -10, 0,  1 );
      DeleteMtr(); // Отключение матрицы преобразования координат
    EndGroup(); // Завершить создание группы объектов
  }
  else
    MessageT( _T("Документ не активизирован или\nне является листом/фрагментом") );  
  */
  return TRUE;
}


//-------------------------------------------------------------------------------
// Отрисовка слайда
// ---
void TestShowDlg::OnPaint()
{
  CPaintDC dc( this );

  // Для отрисовки слайда из ресурса
  if ( m_slideId != 0 )
    DrawSlide( m_StaticShow.m_hWnd, // Несущее окно
               m_slideId );                          // Идентификатор слайда в файле ресурсов приложения

  /*
  // Для отрисовки Bitmap из ресурса
  if ( m_slideId != 0 )
    DrawBitmap( m_StaticShow.m_hWnd, // Несущее окно
                m_slideId );                          // Идентификатор BMP в файле ресурсов приложения
  */

  /*
  // Для отрисовки слайда из файла ресурса
  // При изменении файла .rc не нужно перекомпилировать библиотеку
  if ( m_fileName[0] != '\0' )
    ksDrawSlideFromFileT( m_StaticShow.m_hWnd, // Несущее окно
                          m_fileName );     // Полное имя файла
  */

/*  
  // Отрисовка текущего документа
  reference doc = ksGetCurrentDocument( 1 );
  if ( doc )
    ksDrawKompasDocumentByReference( m_StaticShow.m_hWnd, // Несущее окно
                                     doc );                                // Указатель на документ
*/  

  /*
  // Для отрисовки фрагмента из файла
  if ( m_fileName[0] != '\0' )
    ksDrawKompasDocumentT( m_StaticShow.m_hWnd, // Несущее окно
                           m_fileName );     // Полное имя файла документа
  */

  /*
  // Для отрисовки группы
  if ( ksGetCurrentDocument( 1 ) )
  {
    ksDrawKompasGroup( m_StaticShow.m_hWnd, // Несущее окно
                       rGroup );                             // Группа
  }
  */
}


//-------------------------------------------------------------------------------
// Создание диалога отрисовки слайда
// ---
void TestShowDialog()
{
  TestShowDlg* dlg = new TestShowDlg();
  if ( dlg )
  {
    EnableTaskAccess( 0 ); // Закрыть доступ к компасу
    dlg->DoModal();        // Вывод диалога
    EnableTaskAccess( 1 ); // Открыть доступ к компасу
    delete dlg;
  }
}

