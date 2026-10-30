// vcprjDlg.cpp : implementation file
//

#include "stdafx.h"
#include "vcprj.h"
#include "vcprjDlg.h"
#include <ldefin2d.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CString g_szError;
CDialog * dlg;
KompasObjectPtr kompas(NULL);
bool usesIvisible = false;
int  libraryId;   // HANDLE загруженной библиотеки

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
class CAboutDlg : public CDialog
{
public:
  CAboutDlg();

// Dialog Data
  //{{AFX_DATA(CAboutDlg)
  enum { IDD = IDD_ABOUTBOX };
  //}}AFX_DATA

  // ClassWizard generated virtual function overrides
  //{{AFX_VIRTUAL(CAboutDlg)
  protected:
  virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
  //}}AFX_VIRTUAL

// Implementation
protected:
  //{{AFX_MSG(CAboutDlg)
  //}}AFX_MSG
  DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
  //{{AFX_DATA_INIT(CAboutDlg)
  //}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
  CDialog::DoDataExchange(pDX);
  //{{AFX_DATA_MAP(CAboutDlg)
  //}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
  //{{AFX_MSG_MAP(CAboutDlg)
    // No message handlers
  //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVcprjDlg dialog

CVcprjDlg::CVcprjDlg(CWnd* pParent /*=NULL*/)
  : CDialog(CVcprjDlg::IDD, pParent)
{
  //{{AFX_DATA_INIT(CVcprjDlg)
    // NOTE: the ClassWizard will add member initialization here
  //}}AFX_DATA_INIT
  // Note that LoadIcon does not require a subsequent DestroyIcon in Win32
  m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CVcprjDlg::DoDataExchange(CDataExchange* pDX)
{
  CDialog::DoDataExchange(pDX);
  //{{AFX_DATA_MAP(CVcprjDlg)
    // NOTE: the ClassWizard will add DDX and DDV calls here
  //}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CVcprjDlg, CDialog)
  //{{AFX_MSG_MAP(CVcprjDlg)
  ON_WM_SYSCOMMAND()
  ON_WM_PAINT()
  ON_WM_QUERYDRAGICON()
  ON_BN_CLICKED(IDC_GRAPHIC_LOAD, OnGraphicLoad)
  ON_BN_CLICKED(IDC_BUTTON1, OnQuitUnload)
  ON_BN_CLICKED(IDC_BUTTON2, OnQuitWOUnload)
  ON_BN_CLICKED(IDC_BUTTON3, OnLoadFile)
  ON_BN_CLICKED(IDC_BUTTON4, OnNewFile)
  ON_BN_CLICKED(IDC_BUTTON5, OnExecuteCommand)
  ON_BN_CLICKED(IDC_BUTTON6, OnUnloadGraphic)
  ON_BN_CLICKED(IDC_BUTTON7, OnLoadLibrary)
  ON_BN_CLICKED(IDC_BUTTON8, OnRunLibraryCommand)
  ON_BN_CLICKED(IDC_BUTTON9, OnUnloadLibrary)
  ON_BN_CLICKED(IDC_BUTTON10, OnSaveFile)
  ON_BN_CLICKED(IDC_BUTTON11, OnCloseFile)
  ON_BN_CLICKED(IDC_GRAPHIC_LOAD2, OnGraphicLoad2)
  ON_BN_CLICKED(IDC_BUTTON12, OnVisible)
  //}}AFX_MSG_MAP
 
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVcprjDlg message handlers

BOOL CVcprjDlg::OnInitDialog()
{
  CDialog::OnInitDialog();

  // Add "About..." menu item to system menu.

  // IDM_ABOUTBOX must be in the system command range.
  ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
  ASSERT(IDM_ABOUTBOX < 0xF000);

  CMenu* pSysMenu = GetSystemMenu(FALSE);
  if (pSysMenu != NULL)
  {
    CString strAboutMenu;
    strAboutMenu.LoadString(IDS_ABOUTBOX);
    if (!strAboutMenu.IsEmpty())
    {
      pSysMenu->AppendMenu(MF_SEPARATOR);
      pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
    }
  }

  // Set the icon for this dialog.  The framework does this automatically
  //  when the application's main window is not a dialog
  SetIcon(m_hIcon, TRUE);			// Set big icon
  SetIcon(m_hIcon, FALSE);		// Set small icon
  
  //Инициируем COM
  CoInitialize( NULL );
  g_szError.LoadString(IDS_ERROR);
  CheckDlgButton( IDC_CHECK1, usesIvisible );
  dlg = this;
  return TRUE;  // return TRUE  unless you set the focus to a control
}

void CVcprjDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
  if ((nID & 0xFFF0) == IDM_ABOUTBOX)
  {
    CAboutDlg dlgAbout;
    dlgAbout.DoModal();
  }
  else
  {
    CDialog::OnSysCommand(nID, lParam);
  }
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.
void CVcprjDlg::OnPaint() 
{
  if (IsIconic())
  {
    CPaintDC dc(this); // device context for painting

    SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

    // Center icon in client rectangle
    int cxIcon = GetSystemMetrics(SM_CXICON);
    int cyIcon = GetSystemMetrics(SM_CYICON);
    CRect rect;
    GetClientRect(&rect);
    int x = (rect.Width() - cxIcon + 1) / 2;
    int y = (rect.Height() - cyIcon + 1) / 2;

    // Draw the icon
    dc.DrawIcon(x, y, m_hIcon);
  }
  else
  {
    CDialog::OnPaint();
  }
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CVcprjDlg::OnQueryDragIcon()
{
  return (HCURSOR) m_hIcon;
}

//---------------------------------------------------------------------------
//Загрузить Компас как сервер автоматизации
//---------------------------------------------------------------------------
void CVcprjDlg::OnGraphicLoad() 
{
  if ( !kompas ) {
    usesIvisible = !!IsDlgButtonChecked(IDC_CHECK1);
    if ( usesIvisible )
      kompas.CreateInstance( _T("KSINVISIBLE.Application.5") );
    else
      kompas.CreateInstance( _T("KOMPAS.Application.5") );
    
      
    if ( kompas && !usesIvisible ) {
//      kompas.LoadDSK();
      kompas->Visible = true; 
    }
  }
}

//---------------------------------------------------------------------------
//закрытие окна диалога
//---------------------------------------------------------------------------
BOOL CVcprjDlg::DestroyWindow() 
{
  //закрываем COM
  OnQuitWOUnload(); 
  CoUninitialize();	
  return CDialog::DestroyWindow();
}

//---------------------------------------------------------------------------
//закрыть Компас и закрыть приложение
//---------------------------------------------------------------------------
void CVcprjDlg::OnQuitUnload() 
{
  if ( kompas ) {  
    kompas->Quit();  
    kompas = NULL;
  }
  EndDialog(IDOK); //завершить работу
}

//---------------------------------------------------------------------------
//Разконектироваться с Компас и закрыть приложение
//---------------------------------------------------------------------------
void CVcprjDlg::OnQuitWOUnload() 
{
  if ( kompas ) {
    kompas = NULL;
  }
  EndDialog(IDOK); //завершить работу
}

//---------------------------------------------------------------------------
//  открыть документ
//---------------------------------------------------------------------------
void CVcprjDlg::OnLoadFile() 
{
  try {
    if ( kompas ) {	
      CFileDialog openFileDialog( TRUE/* bOpenFileDialog*/,
        NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, 
      CString("Чертежи(*.cdw)|*.cdw|Фрагменты(*.frw)|*.frw|Модели(*.m3d)|*.m3d|Сборки(*.a3d)|*.a3d|Спецификации(*.spw)|*.spw|") );
      if( openFileDialog.DoModal() == IDOK ) {
        //    Открыть документ с диска
        //    первый параметр - имя открываемого файла
        //    второй параметр указывает на необходимость выдачи запроса "Файл изменен. Сохранять?" при закрытии файла
        //    третий параметр - указатель на IDispatch, по которому График вызывает уведомления об изменении своего состояния
        //    ф-ия возвращает HANDLE открытого документа
       long type =  kompas->ksGetDocumentTypeByName((LPCTSTR)openFileDialog.GetPathName());
       ksDocument3DPtr doc3D;
       ksDocument2DPtr doc2D;
       ksSpcDocumentPtr docSpc;
       ksDocumentTxtPtr docTxt;
       switch (type) {
         case lt_DocPart3D:    //3d документы
         case lt_DocAssemble3D:
           doc3D = kompas->Document3D();
           if ( doc3D )
            doc3D->Open( (LPCTSTR)openFileDialog.GetPathName(), 0 );
         break;
         case lt_DocSheetStandart : //2d документы
         case lt_DocFragment:
           doc2D = kompas->Document2D();
           if ( doc2D )
            doc2D->ksOpenDocument( (LPCTSTR)openFileDialog.GetPathName(), 0 );
         break;
         case lt_DocSpc:          //спецификации
           docSpc = kompas->SpcDocument();
           if ( docSpc )
            docSpc->ksOpenDocument( (LPCTSTR)openFileDialog.GetPathName(), 0 );

         break;
         case lt_DocTxtStandart:  //текстовые документы
           docTxt = kompas->DocumentTxt();
           if ( docTxt )
            docTxt->ksOpenDocument( (LPCTSTR)openFileDialog.GetPathName(), 0 );

         break;

       }
       long err = kompas->ksReturnResult();
       if (err)
         kompas->ksResultNULL();

       //  kompas->ksMessageBoxResult();
      }
    }
    else
      AfxMessageBox(_T("Объект не захвачен"));
  }
  catch (... ) 
  {
    AfxMessageBox(_T("Ошибка, нужно связаться с сервером")); 
    kompas = NULL;
  }
}

//---------------------------------------------------------------------------
//создать новый документ
//---------------------------------------------------------------------------
void CVcprjDlg::OnNewFile() 
{
  if ( kompas ) {
//      создать новый документ
//      первый параметр - тип открываемого файла
//        0 - лист чертежа
//        1 - фрагмент
//        2 - текстовый документ
//        3 - спецификация
//        4 - 3D-модель
//      второй параметр указывает на необходимость выдачи запроса "Файл изменен. Сохранять?" при закрытии файла
//      третий параметр - указатель на IDispatch, по которому Графие вызывает уведомления об изенении своего состояния
//      ф-ия возвращает HANDLE открытого документа
    ksDocument2DPtr doc = kompas->Document2D();    
    if ( doc ) {
      ksDocumentParamPtr docPar( kompas->GetParamStruct(ko_DocumentParam) );
      if ( docPar ) {
        docPar->Init();
        docPar->type = lt_DocSheetStandart;
        doc->ksCreateDocument( docPar ); 
      }
    }
  }
}

//---------------------------------------------------------------------------
//Выплнить команду с помощью API Компас
//---------------------------------------------------------------------------
void CVcprjDlg::OnExecuteCommand() 
{
  if ( kompas ) {
    ksDocument2DPtr doc = kompas->Document2D();
    if ( doc ) {
      doc->ksCircle( 50, 50, 20, 1);
      doc->ksCircle( 50, 50, 50, 2 );
      kompas->ksMessage( _T("Привет") );
    }
  }
}

//---------------------------------------------------------------------------
//закрыть Компас
//---------------------------------------------------------------------------
void CVcprjDlg::OnUnloadGraphic() 
{
  if ( kompas ) {
    kompas->Quit(); 
    kompas = NULL;
  }
}

//---------------------------------------------------------------------------
// загрузить библиотку
//---------------------------------------------------------------------------
void CVcprjDlg::OnLoadLibrary() 
{
  if ( kompas ) {
    CFileDialog openFileDialog( TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, 
                                 CString("Библиотеки(*.rtw)|*.rtw|") );
    if( openFileDialog.DoModal() == IDOK ) 
    {
      //    загрузить библиотеку
      //    ф-ия возвращает HANDLE загруженной библиотеки
      libraryId = kompas->ksAttachKompasLibrary( (LPCTSTR)openFileDialog.GetPathName() );
    }
  }
}

//---------------------------------------------------------------------------
// выполнить библиотечную команду
//---------------------------------------------------------------------------
void CVcprjDlg::OnRunLibraryCommand() 
{
  if ( kompas ) {
    if ( !libraryId )
      OnLoadLibrary();
//      выполнить команду у загруженной библиотеки
//      первй параметр - HANDLE библиотеки
//      второй параметр - идентификатор выполняемой команды
    kompas->ksExecuteKompasLibraryCommand( libraryId, 1 );
  }
}

//---------------------------------------------------------------------------
//выгрузить библиотеку
//---------------------------------------------------------------------------
void CVcprjDlg::OnUnloadLibrary() 
{
  if ( kompas && libraryId ) {
    kompas->ksDetachKompasLibrary( libraryId );
    libraryId = 0;
  }
}

//---------------------------------------------------------------------------
//Сохранить документ
//---------------------------------------------------------------------------
void CVcprjDlg::OnSaveFile() 
{
  if ( kompas ) {
    ksDocument2DPtr doc = kompas->ActiveDocument2D();
    if ( doc ) 
      doc->ksSaveDocument(_T(""));
  }
}

//---------------------------------------------------------------------------
//Закрыть документ
//---------------------------------------------------------------------------
void CVcprjDlg::OnCloseFile() 
{
  if ( kompas ) {
    ksDocument2DPtr doc = kompas->ActiveDocument2D();
    if ( doc ) 
      doc->ksCloseDocument();
    else
    {
      ksDocument3DPtr doc3D = kompas->ActiveDocument3D();
      if ( doc3D )
        doc3D->close();

    }
  }
}

void CVcprjDlg::OnGraphicLoad2() 
{
  // TODO: Add your control notification handler code here
  if ( !kompas ) {
    usesIvisible = !!IsDlgButtonChecked(IDC_CHECK1);
    if ( usesIvisible )
      kompas.GetActiveObject( _T("KSINVISIBLE.Application.5") );
    else
      kompas.GetActiveObject( _T("KOMPAS.Application.5") );
    
    if ( kompas )
    {
      if (!usesIvisible && !kompas->Visible )
      kompas->Visible = true; 
    }
    else
      AfxMessageBox(_T("Не нашли активный объект"));
  }
  else
    AfxMessageBox(_T("Объект уже захвачен"));	
  
}

void CVcprjDlg::OnVisible() 
{
  // TODO: Add your control notification handler code here
  try
  {
    if ( kompas )
    {
      if (!usesIvisible)
      kompas->Visible = !kompas->Visible; 
    }
    else
      AfxMessageBox(_T("Объект не захвачен"));
  }
  catch (... ) 
  {
    AfxMessageBox(_T("Ошибка, нужно связаться с сервером ")); 
    kompas = NULL; 
  }

}

