//////////////////////////////////////////////////////////////////////////////// 
// 
// slideWrk.cpp - Тест слайд
// 
// 1. Сдвинуть слайд   - MoveSlide         - <testmov.cpp> 
// 2. Записать слайд   - WriteSlideStep 
// 3. Разбить слайд    - DecomposeSlideStep
// 4. Отрисовать слайд - TestShowDialog 
// 
//////////////////////////////////////////////////////////////////////////////// 
#include "stdafx.h"
#include <afxdllx.h> 
#include "resource.h"

#ifndef  _INC_MATH
#include "math.h"
#endif 

#ifndef __LIBTOOL_H
#include <libtool.h>
#endif

#ifndef __LDEFIN2D_H
#include <ldefin2d.h>
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


//-------------------------------------------------------------------------------
// Специальная структура используемая в течении инициализации DLL
// ---
static AFX_EXTENSION_MODULE StepDLL = { NULL, NULL };


//-------------------------------------------------------------------------------
// Стандартная точка входа
// Инициализация и завершение DLL
// ---
extern "C" int APIENTRY
DllMain( HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved )
{
  UNREFERENCED_PARAMETER( lpReserved );

  if ( dwReason == DLL_PROCESS_ATTACH )
  {
    TRACE0( "DLL Initializing!" );
 
    if ( !AfxInitExtensionModule( StepDLL, hInstance ) )
      return 0;

    new CDynLinkLibrary( StepDLL );
  }
  else if ( dwReason == DLL_PROCESS_DETACH )
  {
    TRACE0( "DLL Terminating!" );
    AfxTermExtensionModule( StepDLL );
  }
  return 1;
}


//-------------------------------------------------------------------------------
// Задать идентификатор ресурсов
// ---
unsigned int WINAPI LIBRARYID()
{
  return IDR_LIBID;
}


//-------------------------------------------------------------------------------
// Описания используемых функций
// ---
void MoveSlide();    
void WriteSlideStep();
void TestShowDialog();
void DecomposeSlideStep();


//-------------------------------------------------------------------------------
// Головная функция библиотеки
// ---
void WINAPI LIBRARYENTRY( unsigned int comm )
{
  switch ( comm )
  {
    // Отрисовать слайд
    case 4 :
      TestShowDialog();
      break;
    
    default:  
    {
      if ( ksGetCurrentDocument( 1 ) ) // Получить активный 2D документ
      {
        switch ( comm )
        {
          // Сдвинуть слайд
          case 1 :
            MoveSlide();
            break;

          // Записать слайд
          case 2 :
            WriteSlideStep();  
            break;

          // Разбить слайд
          case 3 :
            DecomposeSlideStep();    
            break;
        }
      }
      else
        MessageT( _T("Документ не активизирован или\nне является листом/фрагментом") );        
    }
  }
}


//-------------------------------------------------------------------------------
// Записать слайд
// ---
void WriteSlideStep()
{
  TCHAR name[255];
  // Выберем файл для записи
  if ( ksSaveFileT( _T("*.rc"), NULL, NULL, name, 255, 0 ) )
  {
    // Структура параметров запроса к системе
    RequestInfoT info;
    memset( &info, 0, sizeof( info ) );
    
    // Строка или идентификатор меню состава команд 
    info.commands = _T("Укажите точку привязки слайда");

    double x, y; // Точка привязки слайда - верхний левый угол габаритного прямоугольника слайда
    
    // Интерактивный ввод точки или комманды
    if ( CursorExT( &info,   // Указатель на структуру параметров запроса к системе	
                    &x,      // Координаты введенной точки	
                    &y, 
                    NULL, NULL ) ) // Указатель на структуру управления фантомом, определяющую тип	движения курсора
    {
      int slideId;
      // Ввод целого числа
      if ( ReadIntT( _T("Введите идентификатор слайда"), 100, 0, 32000, &slideId ) )
      {
        // Записать слайд
        if ( !WriteSlideT( name,    // Имя файла для записи 
                          slideId, // Идентификатор слайда в файле ресурсов
                          x, y ) ) // Базовая точка
          ErrorT( _T("Группа селектирования пуста") );
        ClearGroup( 0 ); // Очистить группу объектов, если 0, то очистится группа селектирования 
      }
    }
  }
}


//////////////////////////////////////////////////////////////////////////////// 
// 
// Диалог отрисовки слайда
// 
//////////////////////////////////////////////////////////////////////////////// 
class TestShowDlg : public CDialog
{
public:
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
  afx_msg void OnPaint();
  // }}AFX_MSG

  DECLARE_MESSAGE_MAP()
};


//-------------------------------------------------------------------------------
// Консруктор
// ---
TestShowDlg::TestShowDlg( CWnd* pParent /*=NULL*/ )
  : CDialog( TestShowDlg::IDD, pParent )
{ 
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
// Отрисовка слайда
// ---
void TestShowDlg::OnPaint()
{
  CPaintDC dc( this );

  TCHAR  fName[_MAX_PATH];
  ::GetModuleFileName( StepDLL.hModule, fName, _MAX_PATH);
  LPTSTR c = ::_tcsrchr( fName, _T('\\') );
  if ( c )
    *( c + 1 ) = _T('\0');
  ::_tcscat_s( fName, _T("Example.rc") );

  ::ksDrawSlideFromFileT( m_StaticShow.GetSafeHwnd(), fName );
}


//-------------------------------------------------------------------------------
// Создание диалога отрисовки слайда
// ---
void TestShowDialog()
{
  TestShowDlg* dlg = new TestShowDlg();         
  if ( dlg )
  {         
    EnableTaskAccess( 0 ); // Запретить доступ к задаче со стороны пользователя
    dlg->DoModal();        // Вывод диалога
    EnableTaskAccess( 1 ); // Разрешить доступ к задаче со стороны пользователя

    delete dlg;
  }   
}


//-------------------------------------------------------------------------------
// Глобальные переменные
// ---
static double g_x1, g_y1, g_x2, g_y2;
static int g_flag;


//-------------------------------------------------------------------------------
// Отросовка рамки
// ---
static void DrawRamka() 
{
  if( fabs( g_y1 - g_y2 ) >0 ) 
  {
    LineSeg( g_x1, g_y1, g_x1, g_y2, 1 );
    LineSeg( g_x2, g_y1, g_x2, g_y2, 1 );
  }
  if( fabs( g_x1 - g_x2 ) >0 ) 
  {
    LineSeg( g_x1, g_y1, g_x2, g_y1, 1 );
    LineSeg( g_x1, g_y2, g_x2, g_y2, 1 );
  }
}


//-------------------------------------------------------------------------------
// Функция обратной связи, вызываемая из Cursor
// ---
int WINAPI CallBackC( int comm,             // Пришедшая команда
                      double *x, double *y, // Положение фантома
                      RequestInfoT *info,    // Структура параметров запроса к системе
                      void *phantom,        // Структура параметров фантома
                      int dynamic )
{
  Phantom *pPhantom = ( Phantom * )phantom;

  if( !dynamic ) // Фиксация
  { 
    if( !g_flag ) // Фиксируется 1 точка
    {
      g_flag++;
      g_x1 = *x; 
      g_y1= *y;
      info->commands = _T("Укажите вторую точку окна");
    }
    else 
    {
      g_flag++;
      g_x2 = *x; 
      g_y2 = *y;
      return 0;
    }
  }
  else  
  {
    if( g_flag > 0 )
    {
      g_x2 = *x; 
      g_y2 = *y;
      pPhantom->type1.xBase = g_x2; 
      pPhantom->type1.yBase = g_y2;
      if ( pPhantom->type1.gr)
        DeleteObj( pPhantom->type1.gr );
      
      pPhantom->type1.gr = NewGroup( 1 ); // Временная группа
        DrawRamka();
      EndGroup();
    }
  }
  return 1;
}


//-------------------------------------------------------------------------------
// Разбить слайд
// ---
void DecomposeSlideStep() 
{
  double x, y;
  RequestInfoT  info;
  memset( &info, 0, sizeof(info));
  info.commands   = _T("Укажите первую точку окна");
  info.dynamic    = 1;
  info.callBack   = CallBackC; // Указываем адрес обратной функции для Cursor
  Phantom par;
  par.phType      = 1;
  par.type1.gr    = NewGroup( 1 );
  EndGroup();
  par.type1.xBase = 0; 
  par.type1.yBase = 0;
  par.type1.scale = 1;
  par.type1.ang   = 0;
  g_flag          = 0;

  CursorExT(&info,&x,&y,&par, NULL);
  if ( par.type1.gr)
    DeleteObj( par.type1.gr );
  if( g_flag == 2 )
  {
    ClearGroup(0);
    if(SelectGroup( 0, 1, g_x1, g_y1, g_x2, g_y2 ) ) 
    {
      reference iGrp = CreateIterator ( SELECT_GROUP_OBJ, 0 );
      if ( iGrp )
      {
        par.type1.gr = NewGroup( 1 );
        EndGroup();
        reference rObj;
        reference gr;
        if ( ExistObj( rObj = MoveIterator ( iGrp, 'F' )) ) 
        {
          do 
          {
            gr = DecomposeObj( rObj, 0, 0.2, 0 );
            AddObjGroup( par.type1.gr, gr );
            ksClearGroup( gr, false );
            DeleteObj( gr );
          } while( ExistObj ( rObj = MoveIterator( iGrp, 'N' )) );
        }

        memset( &info, 0, sizeof(info));
        par.type1.xBase = g_x1; 
        par.type1.yBase = g_y1;
        info.commands = _T("Укажите базовую точку группы");
        if( CursorExT( &info, &x, &y, &par, NULL) ) 
        {
          Mtr( x - g_x1, y - g_y1, 0, 1 );
            TransformObj( par.type1.gr );
          DeleteMtr();
          StoreTmpGroup( par.type1.gr );
        }
        ClearGroup( par.type1.gr );
        DeleteObj( par.type1.gr );
      }
      ClearGroup(0);
    }
    else
      ErrorT(_T("Ошибка"));
  }
}

