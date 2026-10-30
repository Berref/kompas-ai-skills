// ShDial.cpp : implementation file
//

#include "stdafx.h"
#include <math.h>
#include "ShDial.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define MAX_LENGTH 1000        // максимальная длина стержня
#define MIN_LENGTH 0           // минимальная длина стержня

extern KompasObjectPtr kompas;

//-------------------------------------------------------------------------------
//
// ---
int  Shpeel::MacroElementParam() {
  // по умолчанию ресурсы берутся из .exe файла, для того чтобы их достать
  // из нашей dll вызовем этот define
  AFX_MANAGE_STATE(AfxGetStaticModuleState());

  int res = 0;
  Shpeel* bufS = Dublicate();
  if ( bufS && bufS->OpenBase() ) {
    ShpeelDial* dlg = new ShpeelDial( *bufS );
    if ( dlg ) {
      kompas->ksEnableTaskAccess( 0 ); // закрыть доступ к компасу
      res = dlg->DoModal() == IDOK;    // вывод диалога
      kompas->ksEnableTaskAccess( 1 ); // открыть доступ к компасу
      delete dlg;
    }
    if ( res ) 
      Assign( *bufS );
    bufS->CloseBase();
    delete bufS;
  }
  return res;
}

//------------------------------------------------------------------------------
// Выбор слайда
// ---
static UINT ChoiceBMP( short gost, short f ) {
  UINT bmp = 0;
  if ( gost > 22041 ) 
    bmp = f & ALLST ? SH22042_3 : f & ISPOLN ? SH22042_2 : SH22042_1;
  else 
    bmp = f & ISPOLN ? SH22032_2 : SH22032_1;
  return bmp;
}

//------------------------------------------------------------------------------
// определяет длину ввинчиваемого конца по ГОСТу
// ---
int GetTypeForGost( short gost ) {
  int n;
  switch ( gost ) {
    case 22032 :
    case 22033 :  n = 0;  break; // 1d
    case 22034 :
    case 22035 :  n = 1;  break; // 1,25d
    case 22036 :
    case 22037 :  n = 2;  break; // 1,6d
    case 22038 :
    case 22039 :  n = 3;  break; // 2d
    case 22040 :
    case 22041 :  n = 4;  break; // 2,5d
    case 22042 :
    case 22043 :  n = 5;  break; // l0
  }
  return n;
}

//------------------------------------------------------------------------------
// определяет класс точности по ГОСТу
// ---
int GetKlassForGost( short gost ) {
  int n;
  switch ( gost ) {
    case 22032 :
    case 22034 :
    case 22036 :
    case 22038 :
    case 22040 :
    case 22042 :  n = 1;  break;  // B

    case 22033 :
    case 22035 :
    case 22037 :
    case 22039 :
    case 22041 :
    case 22043 :  n = 0;  break; // A
  }
  return n;
}

//------------------------------------------------------------------------------
// определяет класс точности по ГОСТу
// ---
int GetGostForTypeAndKlass( int type, int klass ) {
  int n;
  switch ( type ) {
    case 0 : n = klass ? 0  : 1;  break; // 22032 : 22033
    case 1 : n = klass ? 2  : 3;  break; // 22034 : 22035
    case 2 : n = klass ? 4  : 5;  break; // 22036 : 22037
    case 3 : n = klass ? 6  : 7;  break; // 22038 : 22039
    case 4 : n = klass ? 8  : 9;  break; // 22040 : 22041
    case 5 : n = klass ? 10 : 11; break; // 22042 : 22043
  }
  return n;
}

//------------------------------------------------------------------------------
//
// ---
static  int NumberStr( int gost ) {
  int n;
  switch ( gost ) {
    case 22032 :  n = STR59;  break;
    case 22033 :  n = STR60;  break;
    case 22034 :  n = STR61;  break;
    case 22035 :  n = STR62;  break;
    case 22036 :  n = STR63;  break;
    case 22037 :  n = STR64;  break;
    case 22038 :  n = STR65;  break;
    case 22039 :  n = STR66;  break;
    case 22040 :  n = STR67;  break;
    case 22041 :  n = STR68;  break;
    case 22042 :  n = STR69;  break;
    case 22043 :  n = STR70;  break;
  }
  return n;
}

/////////////////////////////////////////////////////////////////////////////
// ShpeelDial dialog


ShpeelDial::ShpeelDial( Shpeel& _shpeel, CWnd* pParent /*=NULL*/)
  : CDialog(ShpeelDial::IDD, pParent),
  shpeel   (_shpeel)
{
  //{{AFX_DATA_INIT(ShpeelDial)
  m_perfGroup = -1;
  //}}AFX_DATA_INIT
  bitMapId = 0;

  m_listParam.AddParItem( &shpeel.GetShpeelParam().b,  pmFloat, STR247 ); //l0 Гаечный конец
  m_listParam.AddParItem( &shpeel.GetShpeelParam().b1, pmFloat, STR248 ); //l1 Ввинчиваемый конец
  m_listParam.AddParItem( &p,                           pmFloat, STR231 ); //"Шаг резьбы"
  m_listParam.AddParItem( &shpeel.GetShpeelParam().c,  pmFloat, STR236 ); //"Фаска"
  m_listParam.AddParItem( &massa,                       pmFloat, STR237 ); //"Масса 1000 шт"
}


void ShpeelDial::DoDataExchange(CDataExchange* pDX)
{
  CDialog::DoDataExchange(pDX);
  //{{AFX_DATA_MAP(ShpeelDial)
  DDX_Control(pDX, IDC_MAT_COMBO, m_tMatt);
  DDX_Control(pDX, IDC_ATTR_CHECK, m_cAttr);
  DDX_Control(pDX, IDC_LISTVIEWPARAM, m_listParam);
  DDX_Control(pDX, IDC_STUD_KLASS_COMBO, m_klass);
  DDX_Control(pDX, IDC_STUD_TYPE_COMBO, m_type);
  DDX_Control(pDX, IDC_GOST_COMBO, m_gost);
  DDX_Control(pDX, IDD_PITCH, m_pitch);
  DDX_Control(pDX, IDC_SHOW_ST, m_showStatic);
  DDX_Control(pDX, IDD_LEN, m_len);
  DDX_Control(pDX, IDD_DIAM, m_diam);
  DDX_Radio(pDX, IDC_PERFORMANCE1, m_perfGroup);
  //}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ShpeelDial, CDialog)
  //{{AFX_MSG_MAP(ShpeelDial)
  ON_WM_PAINT()
  ON_CBN_SELCHANGE(IDC_GOST_COMBO, OnSelchangeGostCombo)
  ON_CBN_SELCHANGE(IDC_STUD_KLASS_COMBO, OnSelchangeStudKlassCombo)
  ON_BN_CLICKED(IDC_STUD_SIMPL_CHECK, OnStudSimplCheck)
  ON_CBN_SELCHANGE(IDC_STUD_TYPE_COMBO, OnSelchangeStudTypeCombo)
  ON_CBN_SELCHANGE(IDD_DIAM, OnSelchangeDiam)
  ON_CBN_SELCHANGE(IDD_LEN, OnSelchangeLen)
  ON_BN_CLICKED(IDD_PITCH, OnPitch)
  ON_BN_CLICKED(IDC_PERFORMANCE1, OnPerformance1)
  ON_BN_CLICKED(IDC_PERFORMANCE2, OnPerformance2)
  ON_BN_CLICKED(IDC_HELP_BUT, OnHelpBut)
  ON_CBN_SELCHANGE(IDC_MAT_COMBO, OnSelchangeMatCombo)
  ON_BN_CLICKED(IDC_ATTR_CHECK, OnAttrCheck)
  //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ShpeelDial message handlers

//-------------------------------------------------------------------------------
// инициализация диалога
// ---
BOOL ShpeelDial::OnInitDialog() 
{
  CDialog::OnInitDialog();

  CString buf;
  // заполнение списка ГОСТов
  static int idGOST[] = { STR59, STR60, STR61, STR62, STR63, STR64, STR65, STR66, STR67,
                          STR68, STR69, STR70 };
  for ( UINT i = 0; i < 12; i++ ) {
    buf.LoadString( idGOST[i] );
    m_gost.AddString( buf );
  }
  buf.LoadString( ::NumberStr(shpeel.GetShpeelParam().gost) );
  m_gost.SelectString( -1, buf );              // выделяем его в списке

  // заполнение списка "Длина ввинчиваемого конца l1 ="
  for ( UINT i = 0; i < 6; i++ ) {
    buf.LoadString( IDS_STUD_1D + i );
    m_type.AddString( buf );
  }
  m_type.SetCurSel( ::GetTypeForGost(shpeel.GetShpeelParam().gost) ); // выделение длины ввинчиваемого конца l1

  static int idMat[] = { STR238, STR239, STR240, STR246 };
  for ( UINT i = 0; i < 4; i++ ) {
    buf.LoadString( idMat[i] );
    m_tMatt.AddString( buf );
  }
  m_tMatt.SetCurSel( shpeel.GetShpeelParam().indexMassa );

  // заполнение списка "Класс точности"
  buf.LoadString( IDS_STUD_A ); // "A"
  m_klass.AddString( buf );
  buf.LoadString( IDS_STUD_B ); // "B"
  m_klass.AddString( buf );
  m_klass.SetCurSel( ::GetKlassForGost(shpeel.GetShpeelParam().gost) ); // выделение класса точности

  // изменение состояния checkbox'а "Упрощенно"
  CheckDlgButton( IDC_STUD_SIMPL_CHECK, shpeel.GetShpeelParam().f & SIMPLE );

  InitControls();
  m_cAttr.SetCheck( shpeel.GetFlagAttr() ? 1/*вкл*/ : 0/*выкл*/ );

  m_listParam.SetupWiew();
  
  return TRUE;  // return TRUE unless you set the focus to a control
                // EXCEPTION: OCX Property Pages should return FALSE
}

//-------------------------------------------------------------------------------
// вывод слайда
// ---
void ShpeelDial::OnPaint() 
{
  CPaintDC dc(this); // device context for painting
  
  kompas->ksDrawSlide( (long)m_showStatic.m_hWnd, bitMapId );
  
  // Do not call CDialog::OnPaint() for painting messages
}

//------------------------------------------------------------------------------
// Выдаёт сообщение о ошибке, закрывает диалог
// ---
void ShpeelDial::ErrorDialog( int id ) {
  CString buf;
  buf.LoadString( id ); // строка из ресутса
  kompas->ksError( (LPCTSTR)buf );   // сообщение об ошибке
  OnCancel();       // закрыть диалог
}

//------------------------------------------------------------------------------
// заполняет список диаметров
// ---
void ShpeelDial::FillDiametr() {
  bool  failDB       = true;        // предполагаем ошибку
  ksUserParamPtr    tmpL( kompas->GetParamStruct(ko_UserParam) );
  ksLtVariantPtr    item( kompas->GetParamStruct(ko_LtVariant) );
  ksDynamicArrayPtr  arr  ( kompas->GetDynamicArray(LTVARIANT_ARR) );
  if ( tmpL && item && arr ) {
    tmpL->Init();
    tmpL->SetUserArray( arr );
    item->Init();
    item->shortVal = 0;
    arr->ksAddArrayItem( -1, item );
    item->strVal = _T("\0");
    arr->ksAddArrayItem( -1, item );

    m_diam.ResetContent();               // очищаем список

    float lMin         = MAX_LENGTH;  // минимальное значение в списке
    float lMax         = MIN_LENGTH;  // максимальное значение в списке
    bool  enterInRange = false;       // Текущее значение диаметра не входит в новые значения

    if ( shpeel.GetDataBase()->ksCondition(shpeel.GetShpeelBase().bg, 
                                          shpeel.GetShpeelBase().rg1, 
                                          _T("t = 1")) ) { 
      int i = 1;
      while ( i ) {                                     // Просматриваем все записи базы данных
        i = shpeel.GetDataBase()->ksReadRecord( shpeel.GetShpeelBase().bg, 
                                               shpeel.GetShpeelBase().rg1, 
                                               tmpL ); // Считываем данное
        if ( i ) {                                     // если запись найдена
          arr->ksGetArrayItem( 1, item );
          m_diam.AddString( item->strVal );        // Заносим его в список

          float ln = (float)::_tcstod( item->strVal, NULL ); // Преобразуем его в число
          if ( shpeel.GetShpeelParam().d == ln )
            enterInRange = true;                       // Текущее значение диаметра входит в новые значения
          if ( ln < lMin )
            lMin = ln;                                 // находим минимальное значение
          if ( ln > lMax )
            lMax = ln;                                 // находим максимальное значение

          failDB = false;                              // ошибки нет
        }
      }
      if ( !enterInRange )          // если текущее значение диаметра не входит в в новые значения
        shpeel.GetShpeelParam().d = lMin;         // присваиваем диаметру минимальное значение
      if ( shpeel.GetShpeelParam().d < lMin )     // если диаметр выходит за минимальную границу новых значений
        shpeel.GetShpeelParam().d = lMin;         // присваиваем ему минимальное значение
      if ( shpeel.GetShpeelParam().d > lMax )     // если диаметр выходит за максимальную границу новых значений
        shpeel.GetShpeelParam().d = lMax;         // присваиваем ему максимальное значение

      TCHAR s[128];
      ::_stprintf_s( s, _T("%g"), shpeel.GetShpeelParam().d ); // преобразуем текущее значение диаметра в строку
      m_diam.SelectString( -1, s );                // выделяем его в списке
    }
  }
  if ( failDB )                 // если работа с БД не была удачной
    ErrorDialog( DIAM_ERROR );  // сообщаем об ошибке
}

//------------------------------------------------------------------------------
// заполняет список длин
// ---
void ShpeelDial::FillLenght() {
  CString buf;
  TCHAR    buf1[128];
  bool    failDB = true;        // предполагаем ошибку
  
  ksUserParamPtr  tmpL( kompas->GetParamStruct(ko_UserParam) );
  ksLtVariantPtr  item( kompas->GetParamStruct(ko_LtVariant) );
  ksDynamicArrayPtr arr( kompas->GetDynamicArray(LTVARIANT_ARR) );
  if ( tmpL && item && arr ) {
    tmpL->Init();
    tmpL->SetUserArray( arr );
    item->Init();
    item->shortVal = 0;
    arr->ksAddArrayItem( -1, item );
    item->strVal = _T("\0");
    arr->ksAddArrayItem( -1, item );
    item->floatVal = 0;
    arr->ksAddArrayItem( -1, item );

    // формируем условие запроса к БД
    buf.LoadString( STR_245 ); //
    ::_stprintf_s( buf1, buf, shpeel.GetShpeelParam().d ); //"d=%.0f"
    if ( shpeel.GetDataBase()->ksCondition(shpeel.GetShpeelBase().bs, 
                                          shpeel.GetShpeelBase().rs1, 
                                          buf1) ) {
      m_len.ResetContent();                    // очищаем список

      float lMin         = MAX_LENGTH;  // минимальное значение в списке
      float lMax         = MIN_LENGTH;  // максимальное значение в списке
      bool  enterInRange = false;       // Текущее значение длины не входит в новые значения

      int i = 1;
      while ( i ) {                                     // Просматриваем все записи базы данных
        i = shpeel.GetDataBase()->ksReadRecord( shpeel.GetShpeelBase().bs, 
                                               shpeel.GetShpeelBase().rs1, 
                                               tmpL ); // Считываем данное
        if ( i ) {                                     // если запись найдена
          arr->ksGetArrayItem( 1, item );
          m_len.AddString( item->strVal );         // Заносим его в список

          float ln = (float)::_tcstod( item->strVal, NULL ); // Преобразуем его в число
          if ( shpeel.GetShpeelParam().l == ln )
            enterInRange = true;                       // Текущее значение длины входит в новые значения
          if ( ln < lMin )
            lMin = ln;                                 // находим минимальное значение
          if ( ln > lMax )
            lMax = ln;                                 // находим максимальное значение

          failDB = false;                              // ошибки нет
        }
      }
      if ( !enterInRange )          // если текущее значение длины не входит в в новые значения
        shpeel.GetShpeelParam().l = lMin;         // присваиваем длине минимальное значение
      if ( shpeel.GetShpeelParam().l < lMin )     // если диаметр выходит за минимальную границу новых значений
        shpeel.GetShpeelParam().l = lMin;         // присваиваем ему минимальное значение
      if ( shpeel.GetShpeelParam().l > lMax )     // если диаметр выходит за максимальную границу новых значений
        shpeel.GetShpeelParam().l = lMax;         // присваиваем ему максимальное значение

      ::_stprintf_s( buf1, _T("%g"), shpeel.GetShpeelParam().l ); // преобразуем текущее значение длины в строку
      m_len.SelectString( -1, buf1 );              // выделяем его в списке
    }
  }

  if ( failDB )               // если работа с БД не была удачной
    ErrorDialog( LEN_ERROR ); // сообщаем об ошибке
}

//------------------------------------------------------------------------------
// инициализация контролов
// ---
void ShpeelDial::InitControls() {
  if ( shpeel.GetShpeelParam().gost > 22041 ) {
    if ( ::fabs(shpeel.GetShpeelParam().b) > 0.001 )
      shpeel.GetShpeelParam().f &=~ ALLST;
    else
      shpeel.GetShpeelParam().f |= ALLST;
  }
  else
    shpeel.GetShpeelParam().f &=~ ALLST;

  m_pitch.SetCheck( shpeel.GetShpeelParam().f & PITCH ? 1/*вкл*/ : 0/*выкл*/ );
  m_perfGroup = shpeel.GetShpeelParam().f & ISPOLN ? 1 : 0;

  FillDiametr(); // заполнение списка диаметра
  FillLenght();  // заполнение списка длин

  ::EnableWindow( GetDlgItem(IDC_PERFORMANCE2)->m_hWnd, 
                  shpeel.GetShpeelParam().f & ALLST ? false : true );
  if ( shpeel.GetShpeelParam().f & ALLST ) 
    m_perfGroup = 0;

  CalcMassa();
  ChoicePitch();
  bitMapId = ChoiceBMP( shpeel.GetShpeelParam().gost, shpeel.GetShpeelParam().f );
  m_showStatic.Invalidate();
  UpdateData( FALSE );
}


//-------------------------------------------------------------------------------
// изменение госта в списке ГОСТов
// ---
void ShpeelDial::OnSelchangeGostCombo() 
{
  CString str;
  m_gost.GetLBText( m_gost.GetCurSel(), str.GetBuffer(20) ); // считываем строку
  str.ReleaseBuffer();
  int index = str.Find( _T('-'), 0 );
  if ( index > 0 )                   // удаляем из ГОСТа год
    str = str.Left( index );      
  short gost = (short)::_ttoi( str ); // преобразуем в число
  if ( gost != shpeel.GetShpeelParam().gost ) {
    shpeel.GetShpeelParam().gost = gost;

    m_type.SetCurSel( ::GetTypeForGost(shpeel.GetShpeelParam().gost) );   // выделение длины ввинчиваемого конца l1
    m_klass.SetCurSel( ::GetKlassForGost(shpeel.GetShpeelParam().gost) ); // выделение класса точности

    if ( shpeel.IsBaseOpen() )                    // если БД открыта
      shpeel.CloseBase();                         // закрываем старую БД

    // Открываем новую БД и считываем текущие параметры
    if ( !shpeel.OpenBase(false/*initParam*/) )              { OnCancel(); return; }
    if ( !shpeel.ReadShpeelBase(shpeel.GetShpeelParam().d) ) { OnCancel(); return; }
    if ( shpeel.ReadShpeelStBase() == -1 )                   { OnCancel(); return; }

    InitControls();                                 // инициализация контролов
    m_listParam.Show();                              // обновляем список параметров
  }
}

//-------------------------------------------------------------------------------
// изменение в списке "Класс точности"
// ---
void ShpeelDial::OnSelchangeStudKlassCombo() 
{
  int k = m_klass.GetCurSel();
  int k1 = m_type.GetCurSel();
  if ( (k > -1) && (k1 > -1) ) {
    m_gost.SetCurSel( ::GetGostForTypeAndKlass(k1, k) );
    OnSelchangeGostCombo();
  }
}

//-------------------------------------------------------------------------------
// изменение состояния checkbox'а "Упрощенно"
// ---
void ShpeelDial::OnStudSimplCheck() 
{
  if ( IsDlgButtonChecked(IDC_STUD_SIMPL_CHECK) )
    shpeel.GetShpeelParam().f |= SIMPLE;
  else
    shpeel.GetShpeelParam().f &= ~SIMPLE;
}

//-------------------------------------------------------------------------------
// изменение в списке "Длина ввинчиваемого конца"
// ---
void ShpeelDial::OnSelchangeStudTypeCombo() 
{
  int k = m_type.GetCurSel();
  int k1 = m_klass.GetCurSel();
  if ( (k > -1) && (k1 > -1) ) {
    m_gost.SetCurSel( ::GetGostForTypeAndKlass(k, k1) );
    OnSelchangeGostCombo();
  }
}

//------------------------------------------------------------------------------
//
// ---
void ShpeelDial::ViewParamShow() {
  CalcMassa();
  ChoicePitch();
  m_listParam.Show();
}

//-------------------------------------------------------------------------------
// изменение в списке диаметров - обновляем список длин и считываем новые параметры из БД
// ---
void ShpeelDial::OnSelchangeDiam() 
{
  CString str;
  m_diam.GetLBText( m_diam.GetCurSel(), str.GetBuffer(20) ); // считываем строку
  str.ReleaseBuffer();

  float dr = (float)::_tcstod( str, NULL ); // преобразуем в число
  if ( ::fabs(dr - shpeel.GetShpeelParam().d) > 0.001 ) {
    if ( !shpeel.ReadShpeelBase(dr) ) { OnCancel(); return ; } // Чтение БД

    FillLenght();                  // заполнение списка длин

    if ( shpeel.ReadShpeelStBase() == -1 ) {  OnCancel(); return; }   // Чтение БД

    ::EnableWindow( GetDlgItem(IDC_PERFORMANCE2)->m_hWnd, 
                    shpeel.GetShpeelParam().f & ALLST ? false : true );
    if ( shpeel.GetShpeelParam().f & ALLST ) 
      m_perfGroup = 0;

    bitMapId = ::ChoiceBMP( shpeel.GetShpeelParam().gost, shpeel.GetShpeelParam().f ); // выбор слайда
    ViewParamShow();                        // обновляем список параметров
    m_showStatic.Invalidate();              // перерисовываем слайд
  }
}

//-------------------------------------------------------------------------------
// изменение в списке длин - считываем новые параметры из БД
// ---
void ShpeelDial::OnSelchangeLen() 
{
  CString str;
  m_len.GetLBText( m_len.GetCurSel(), str.GetBuffer(20) ); // считываем строку
  str.ReleaseBuffer();

  float l = (float)::_tcstod( str, NULL ); // преобразуем в число
  if ( ::fabs(l - shpeel.GetShpeelParam().l) > 0.001 ) {
    shpeel.GetShpeelParam().l = l; //нашли длину для k индекса в списке длин
    if ( shpeel.ReadShpeelStBase() == -1 ) { OnCancel(); return; } // Чтение БД

    ::EnableWindow( GetDlgItem(IDC_PERFORMANCE2)->m_hWnd, 
                    shpeel.GetShpeelParam().f & ALLST ? false : true );
    if ( shpeel.GetShpeelParam().f & ALLST ) 
      m_perfGroup = 0;

    bitMapId = ::ChoiceBMP( shpeel.GetShpeelParam().gost, shpeel.GetShpeelParam().f ); // выбор слайда
    ViewParamShow();                        // обновляем список параметров
    m_showStatic.Invalidate();              // перерисовываем слайд
  }
}

//-------------------------------------------------------------------------------
//
// ---
void ShpeelDial::OnPitch() 
{
  if ( m_pitch.GetCheck() == 1 )
    shpeel.GetShpeelParam().f |= PITCH;
  else
    shpeel.GetShpeelParam().f &= ~PITCH;
  ViewParamShow();
}

//-------------------------------------------------------------------------------
//
// ---
void ShpeelDial::OnPerformance1() 
{
  if ( IsDlgButtonChecked(IDC_PERFORMANCE1) )
    shpeel.GetShpeelParam().f &=~ ISPOLN;
  else
    shpeel.GetShpeelParam().f |= ISPOLN;

  bitMapId = ::ChoiceBMP( shpeel.GetShpeelParam().gost, shpeel.GetShpeelParam().f ); // выбор слайда
  ViewParamShow();                        // обновляем список параметров
  m_showStatic.Invalidate();              // перерисовываем слайд
}

//-------------------------------------------------------------------------------
//
// ---
void ShpeelDial::OnPerformance2() 
{
  if ( IsDlgButtonChecked(IDC_PERFORMANCE2) )
    shpeel.GetShpeelParam().f |= ISPOLN;
  else
    shpeel.GetShpeelParam().f &=~ ISPOLN;

  bitMapId = ::ChoiceBMP( shpeel.GetShpeelParam().gost, shpeel.GetShpeelParam().f ); // выбор слайда
  ViewParamShow();                        // обновляем список параметров
  m_showStatic.Invalidate();              // перерисовываем слайд
}

//-------------------------------------------------------------------------------
// вызов справки
// ---
void ShpeelDial::OnHelpBut() 
{
  CString err;
  err.LoadString( STR230 ); // "Файл constr.chm не найден"
  kompas->ksError( (LPCTSTR)err );
}

//-------------------------------------------------------------------------------
//
// ---
void ShpeelDial::OnSelchangeMatCombo() 
{
  int k = m_tMatt.GetCurSel();
  if ( k > -1 ) {
    shpeel.GetShpeelParam().indexMassa =(byte) k;
    ViewParamShow();
  }
}

//-------------------------------------------------------------------------------
//
// ---
void ShpeelDial::OnAttrCheck() 
{
  shpeel.GetFlagAttr() = m_cAttr.GetCheck() == 1/*вкл.*/ ? true : false;
}
