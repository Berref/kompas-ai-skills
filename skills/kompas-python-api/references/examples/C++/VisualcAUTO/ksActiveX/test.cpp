// test.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "test.h"

#include "MainFrm.h"
#include "testDoc.h"
#include "testView.h"
#include "afxole.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestApp

BEGIN_MESSAGE_MAP(CTestApp, CWinApp)
	//{{AFX_MSG_MAP(CTestApp)
//OV K6 	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
//	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestApp construction

CTestApp::CTestApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CTestApp object

CTestApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CTestApp initialization

BOOL CTestApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

//#ifdef _AFXDLL
//	Enable3dControls();			// Call this when using MFC in a shared DLL
//#else
//	Enable3dControlsStatic();	// Call this when linking to MFC statically
//#endif

	// Change the registry key under which our settings are stored.
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization.
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	LoadStdProfileSettings();  // Load standard INI file options (including MRU)

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CTestDoc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(CTestView));
	AddDocTemplate(pDocTemplate);

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

  CWinThread* pThread = AfxGetThread();

  // Create the new message filter object.
  pThread->m_pMessageFilter->EnableBusyDialog( FALSE ); 
  pThread->m_pMessageFilter->EnableNotRespondingDialog( FALSE );

	// The one and only window has been initialized, so show and update it.
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();

	return TRUE;
}


//OV K6 /////////////////////////////////////////////////////////////////////////////
//OV K6 // CAboutDlg dialog used for App About
//OV K6 
//OV K6 class CAboutDlg : public CDialog
//OV K6 {
//OV K6 public:
//OV K6 	CAboutDlg();
//OV K6 
//OV K6 // Dialog Data
//OV K6 	//{{AFX_DATA(CAboutDlg)
//OV K6 	enum { IDD = IDD_ABOUTBOX };
//OV K6 	CKGAX	m_KompasCtrl;
//OV K6 	//}}AFX_DATA
//OV K6 
//OV K6 	// ClassWizard generated virtual function overrides
//OV K6 	//{{AFX_VIRTUAL(CAboutDlg)
//OV K6 	protected:
//OV K6 	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
//OV K6 	//}}AFX_VIRTUAL
//OV K6 
//OV K6 // Implementation
//OV K6 protected:
//OV K6 	//{{AFX_MSG(CAboutDlg)
//OV K6 		// No message handlers
//OV K6 	//}}AFX_MSG
//OV K6 	DECLARE_MESSAGE_MAP()
//OV K6 };
//OV K6 
//OV K6 CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
//OV K6 {
//OV K6 	//{{AFX_DATA_INIT(CAboutDlg)
//OV K6 	//}}AFX_DATA_INIT
//OV K6 }
//OV K6 
//OV K6 void CAboutDlg::DoDataExchange(CDataExchange* pDX)
//OV K6 {
//OV K6 	CDialog::DoDataExchange(pDX);
//OV K6 	//{{AFX_DATA_MAP(CAboutDlg)
//OV K6 	DDX_Control(pDX, IDC_KGAXCTRL1, m_KompasCtrl);
//OV K6 	//}}AFX_DATA_MAP
//OV K6 }
//OV K6 
//OV K6 BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
//OV K6 	//{{AFX_MSG_MAP(CAboutDlg)
//OV K6 		// No message handlers
//OV K6 	//}}AFX_MSG_MAP
//OV K6 END_MESSAGE_MAP()
//OV K6 
//OV K6 // App command to run the dialog
//OV K6 void CTestApp::OnAppAbout()
//OV K6 {
//OV K6 	CAboutDlg aboutDlg;
//OV K6 	aboutDlg.DoModal();
//OV K6 }
//OV K6 
//OV K6 /////////////////////////////////////////////////////////////////////////////
//OV K6 // CTestApp message handlers
//OV K6 
//OV K6 