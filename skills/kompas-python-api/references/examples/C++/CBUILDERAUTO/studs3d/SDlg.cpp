//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <stdio.h>
#include <math.h>
#include <Ks_TLB.h>
#include <ldefin2d.h>
#include <ldefin3d.h>
#include <ksConstants.h>

#include "SDlg.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TShpeelDlg *ShpeelDlg;

#define MAX_LENGTH 1000        // максимальная длина стержня
#define MIN_LENGTH 0           // минимальная длина стержня

extern KompasObjectPtr kompas;
extern HINSTANCE _hinst;

//-------------------------------------------------------------------------------
//
// ---
int	Shpeel::MacroElementParam() {

  int res = 0;
      Shpeel* bufS = Dublicate();
  if ( bufS && bufS->OpenBase() ) {
    TShpeelDlg * dlg  = new TShpeelDlg( Application, *bufS );
    if ( dlg ) {
      kompas->ksEnableTaskAccess( 0 ); // закрыть доступ к компасу
                        
                        res = dlg->ShowModal();

      kompas->ksEnableTaskAccess( 1 ); // открыть доступ к компасу
      delete dlg;
    }
    if ( res ==mrOk )
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
    case 22032 :  n = STR59;	break;
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

//---------------------------------------------------------------------------
__fastcall TShpeelDlg::TShpeelDlg(TComponent* Owner, Shpeel & _s )
        : TForm(Owner), S( _s) {

  bitMapId = 0;

    StringGrid1->ColCount = 5;
    int colW = StringGrid1->Width/StringGrid1->ColCount;
    StringGrid1->ColWidths[0] = colW-1;
    StringGrid1->ColWidths[1] = colW-1;
    StringGrid1->ColWidths[2] = colW-1;
    StringGrid1->ColWidths[3] = colW-1;
    StringGrid1->ColWidths[4] = colW-1;

    char buf[128];
		LoadStringA( _hinst, STR247, buf, 128 );   //l0 Гаечный конец
		StringGrid1->Cells[0][0] = buf;
		LoadStringA( _hinst, STR248, buf, 128 );   //l1 Ввинчиваемый конец
		StringGrid1->Cells[1][0] = buf;
		LoadStringA( _hinst, STR231, buf, 128 );   //"Шаг резьбы"
		StringGrid1->Cells[2][0] = buf;
		LoadStringA( _hinst, STR236, buf, 128 );   //"Фаска"
		StringGrid1->Cells[3][0] = buf;
    LoadStringA( _hinst, STR237, buf, 128 );   //"Масса 1000 шт"
    StringGrid1->Cells[4][0] = buf;
}

//---------------------------------------------------------------------------
__fastcall TShpeelDlg::~TShpeelDlg() {
  S.CloseBase();
}

//---------------------------------------------------------------------------

void __fastcall TShpeelDlg::helpButtonClick(TObject *Sender)
{
	WideString fileName;
  fileName = kompas->ksSystemPath( sptLIBS_FILES );
  fileName +=L"\\constr.chm";
  kompas->ksOpenHelpFile( TO_OLE(fileName), HELP_CONTEXT, 1 );
}
//---------------------------------------------------------------------------


/////////////////////////////////////////////////////////////////////////////
// ShpeelDial message handlers

//---------------------------------------------------------------------------
// инициализация диалога
// ---
void __fastcall TShpeelDlg::FormShow(TObject *Sender)
{
  char buf[128];

  // заполнение списка ГОСТов
  static int idGOST[] = { STR59, STR60, STR61, STR62, STR63, STR64, STR65, STR66, STR67,
          STR68, STR69, STR70 };
  ComboBox5->Clear();
  for ( UINT i = 0; i < 12; i++ ) {
    LoadStringA( _hinst, idGOST[i], buf, 128 );
    ComboBox5->Items->Add( buf );
  }
	LoadStringA( _hinst, ::NumberStr(S.GetShpeelParam().gost), buf, 128 );
  int ind = ComboBox5->Items->IndexOf( buf );
  ComboBox5->ItemIndex = ind;      // выделяем его в списке

  // заполнение списка "Длина ввинчиваемого конца l1 ="
  for ( UINT i = 0; i < 6; i++ ) {
		LoadStringA( _hinst, IDS_STUD_1D + i, buf, 128 );
    ComboBox3->Items->Add( buf );
  }
  ComboBox3->ItemIndex = ::GetTypeForGost(S.GetShpeelParam().gost);  // выделение длины ввинчиваемого конца l1

  static int idMat[] = { STR238, STR239, STR240, STR246 };
  for ( UINT i = 0; i < 4; i++ ) {
		LoadStringA( _hinst, idMat[i], buf, 128 );
    ComboBox1->Items->Add( buf );
  }
  ComboBox1->ItemIndex = S.GetShpeelParam().indexMassa;

  // заполнение списка "Класс точности"
	LoadStringA( _hinst, IDS_STUD_A, buf, 128 );  // "A"
	ComboBox4->Items->Add( buf );
	LoadStringA( _hinst, IDS_STUD_B, buf, 128 );  // "B"
	ComboBox4->Items->Add( buf );
	ComboBox4->ItemIndex = ::GetKlassForGost(S.GetShpeelParam().gost); // выделение класса точности

	// изменение состояния checkbox'а "Упрощенно"
	CheckBox2->Checked = S.GetShpeelParam().f & SIMPLE;

	InitControls();
	cboxSpcObj->Checked = S.GetFlagAttr();

	ListParamShow();

}
//---------------------------------------------------------------------------
// вывод слайда
// ---
void __fastcall TShpeelDlg::PaintBox1Click(TObject *Sender)
{
  kompas->ksDrawSlide( (long)Panel1->Handle, bitMapId );
}

//------------------------------------------------------------------------------
// Выдаёт сообщение о ошибке, закрывает диалог
// ---
void TShpeelDlg::ErrorDialog( int id ) {
 char buf[128];

  LoadStringA( _hinst, id, buf, 128 );  // строка из ресутса
  kompas->ksError( TO_OLE(buf) );  // сообщение об ошибке
  ModalResult = mrCancel;       // закрыть диалог
}

//------------------------------------------------------------------------------
// заполняет список диаметров
// ---
void TShpeelDlg::FillDiametr() {
  bool  failDB       = true;        // предполагаем ошибку
  ksUserParamPtr tmpL( (ksUserParam*)kompas->GetParamStruct(ko_UserParam), false/*AddRef*/ );
  ksLtVariantPtr item( (ksLtVariant*)kompas->GetParamStruct(ko_LtVariant), false/*AddRef*/ );
  ksDynamicArrayPtr arr( (ksDynamicArray*)kompas->GetDynamicArray(LTVARIANT_ARR), false/*AddRef*/ );
  if ( tmpL && item && arr ) {
    tmpL->Init();
    tmpL->SetUserArray( arr );
    item->Init();
    item->shortVal = 0;
    arr->ksAddArrayItem( -1, item );
		item->strVal = TO_OLE(L"\0");
    arr->ksAddArrayItem( -1, item );

    ComboBox->Clear();               // очищаем список

    float lMin         = MAX_LENGTH;  // минимальное значение в списке
    float lMax         = MIN_LENGTH;  // максимальное значение в списке
    bool  enterInRange = false;       // Текущее значение диаметра не входит в новые значения

    if ( S.GetDataBase()->ksCondition(S.GetShpeelBase().bg,
                                      S.GetShpeelBase().rg1,
																			TO_OLE(L"t = 1")) )
		{
      int i = 1;
      while ( i ) {                                     // Просматриваем все записи базы данных
        i = S.GetDataBase()->ksReadRecord( S.GetShpeelBase().bg,
                         S.GetShpeelBase().rg1,
                         tmpL ); // Считываем данное
        if ( i ) {                                     // если запись найдена
          arr->ksGetArrayItem( 1, item );
          ComboBox->Items->Add( item->strVal );        // Заносим его в список

          char *c;
          float ln = (float)::strtod( AnsiString(item->strVal).c_str(), &c ); // Преобразуем его в число
          if ( S.GetShpeelParam().d == ln )
            enterInRange = true;                       // Текущее значение диаметра входит в новые значения
          if ( ln < lMin )
            lMin = ln;                                 // находим минимальное значение
          if ( ln > lMax )
            lMax = ln;                                 // находим максимальное значение

          failDB = false;                              // ошибки нет
        }
      }
      if ( !enterInRange )          // если текущее значение диаметра не входит в в новые значения
        S.GetShpeelParam().d = lMin;         // присваиваем диаметру минимальное значение
      if ( S.GetShpeelParam().d < lMin )     // если диаметр выходит за минимальную границу новых значений
        S.GetShpeelParam().d = lMin;         // присваиваем ему минимальное значение
      if ( S.GetShpeelParam().d > lMax )     // если диаметр выходит за максимальную границу новых значений
        S.GetShpeelParam().d = lMax;         // присваиваем ему максимальное значение

      char s[128];
      ::sprintf( s, "%g", S.GetShpeelParam().d ); // преобразуем текущее значение диаметра в строку
                        int ind = ComboBox->Items->IndexOf( s );    // выделяем его в списке
                        ComboBox->ItemIndex = ind;
    }
  }
  if ( failDB )                 // если работа с БД не была удачной
    ErrorDialog( DIAM_ERROR );  // сообщаем об ошибке
}

//------------------------------------------------------------------------------
// заполняет список длин
// ---
void TShpeelDlg::FillLenght() {

  char buf[128],buf1[128];
  bool failDB = true;        // предполагаем ошибку

  ksUserParamPtr tmpL( (ksUserParam*)kompas->GetParamStruct(ko_UserParam), false/*AddRef*/ );
  ksLtVariantPtr item( (ksLtVariant*)kompas->GetParamStruct(ko_LtVariant), false/*AddRef*/ );
  ksDynamicArrayPtr arr( (ksDynamicArray*)kompas->GetDynamicArray(LTVARIANT_ARR), false/*AddRef*/ );
  if ( tmpL && item && arr ) {
    tmpL->Init();
    tmpL->SetUserArray( arr );
    item->Init();
    item->shortVal = 0;
    arr->ksAddArrayItem( -1, item );
    item->strVal = TO_OLE(L"\0");
    arr->ksAddArrayItem( -1, item );
    item->floatVal = 0;
    arr->ksAddArrayItem( -1, item );

    // формируем условие запроса к БД
		LoadStringA( _hinst, STR_245, buf, 128 );  //
    ::sprintf( buf1, buf, S.GetShpeelParam().d ); //"d=%.0f"
    if ( S.GetDataBase()->ksCondition(S.GetShpeelBase().bs,
                                      S.GetShpeelBase().rs1,
																			TO_OLE(buf1)) )
		{
			ComboBox2->Clear();                    // очищаем список

      float lMin         = MAX_LENGTH;  // минимальное значение в списке
      float lMax         = MIN_LENGTH;  // максимальное значение в списке
      bool  enterInRange = false;       // Текущее значение длины не входит в новые значения

      int i = 1;
      while ( i ) {                                     // Просматриваем все записи базы данных
        i = S.GetDataBase()->ksReadRecord( S.GetShpeelBase().bs,
                 S.GetShpeelBase().rs1,
                   tmpL ); // Считываем данное
        if ( i ) {                                     // если запись найдена
          arr->ksGetArrayItem( 1, item );
          ComboBox2->Items->Add( item->strVal );         // Заносим его в список

          char *c;
          float ln = (float)::strtod( AnsiString(item->strVal).c_str(), &c ); // Преобразуем его в число
          if ( S.GetShpeelParam().l == ln )
            enterInRange = true;                       // Текущее значение длины входит в новые значения
          if ( ln < lMin )
            lMin = ln;                                 // находим минимальное значение
          if ( ln > lMax )
            lMax = ln;                                 // находим максимальное значение

          failDB = false;                              // ошибки нет
        }
      }
      if ( !enterInRange )          // если текущее значение длины не входит в в новые значения
        S.GetShpeelParam().l = lMin;         // присваиваем длине минимальное значение
      if ( S.GetShpeelParam().l < lMin )     // если диаметр выходит за минимальную границу новых значений
        S.GetShpeelParam().l = lMin;         // присваиваем ему минимальное значение
      if ( S.GetShpeelParam().l > lMax )     // если диаметр выходит за максимальную границу новых значений
        S.GetShpeelParam().l = lMax;         // присваиваем ему максимальное значение

      ::sprintf( buf1, "%g", S.GetShpeelParam().l ); // преобразуем текущее значение длины в строку
      int ind = ComboBox2->Items->IndexOf( buf1 );    // выделяем его в списке
      ComboBox2->ItemIndex = ind;
    }
  }

  if ( failDB )               // если работа с БД не была удачной
    ErrorDialog( LEN_ERROR ); // сообщаем об ошибке
}

//------------------------------------------------------------------------------
// инициализация контролов
// ---
void TShpeelDlg::InitControls() {
  if ( S.GetShpeelParam().gost > 22041 ) {
    if ( ::fabs(S.GetShpeelParam().b) > 0.001 )
      S.GetShpeelParam().f &=~ ALLST;
    else
      S.GetShpeelParam().f |= ALLST;
  }
  else
    S.GetShpeelParam().f &=~ ALLST;

  CheckBox1->Checked = S.GetShpeelParam().f & PITCH;
  RadioGroup1->ItemIndex = S.GetShpeelParam().f & ISPOLN;

  FillDiametr(); // заполнение списка диаметра
  FillLenght();  // заполнение списка длин

  RadioGroup1->Controls[1]->Enabled = S.GetShpeelParam().f & ALLST ? false : true;
  if ( S.GetShpeelParam().f & ALLST )
    RadioGroup1->ItemIndex = 0;

  CalcMassa();
  ChoicePitch();
  bitMapId = ChoiceBMP( S.GetShpeelParam().gost, S.GetShpeelParam().f );
  PaintBox1->Repaint();  // перерисовываем слайд
//  Update();
}

//------------------------------------------------------------------------------
// изменение госта в списке ГОСТов
// ---
void __fastcall TShpeelDlg::ComboBox5Change(TObject *Sender)
{
  AnsiString Str;

  Str = ComboBox5->Text; // считываем строку

  int index = Str.Pos( "-" );
  if ( index > 0 )                   // удаляем из ГОСТа год
    Str.SetLength( index-1 );
  short gost = (short)::atoi( Str.c_str() ); // преобразуем в число
  if ( gost != S.GetShpeelParam().gost ) {
    S.GetShpeelParam().gost = gost;

  ComboBox3->ItemIndex = ::GetTypeForGost(S.GetShpeelParam().gost);   // выделение длины ввинчиваемого конца l1
  ComboBox4->ItemIndex = ::GetKlassForGost(S.GetShpeelParam().gost); // выделение класса точности

    if ( S.IsBaseOpen() )                    // если БД открыта
      S.CloseBase();                         // закрываем старую БД

    // Открываем новую БД и считываем текущие параметры
    if ( !S.OpenBase(false/*initParam*/) )              { ModalResult = mrCancel; return; }
    if ( !S.ReadShpeelBase(S.GetShpeelParam().d) )      { ModalResult = mrCancel; return; }
    if ( S.ReadShpeelStBase() == -1 )                   { ModalResult = mrCancel; return; }

    InitControls();                                 // инициализация контролов
    ListParamShow();                                // обновляем список параметров
  }
}

//------------------------------------------------------------------------------
// изменение в списке "Класс точности"
// ---
void __fastcall TShpeelDlg::ComboBox4Change(TObject *Sender)
{
  int k = ComboBox4->ItemIndex;
  int k1 = ComboBox3->ItemIndex;
  if ( (k > -1) && (k1 > -1) ) {
    ComboBox5->ItemIndex = ::GetGostForTypeAndKlass(k1, k);
    ComboBox5Change(Sender);
  }
}
//------------------------------------------------------------------------------
// изменение состояния checkbox'а "Упрощенно"
// ---
void __fastcall TShpeelDlg::CheckBox2Click(TObject *Sender)
{
  if (CheckBox2->Checked)
    S.GetShpeelParam().f |= SIMPLE;
  else
    S.GetShpeelParam().f &= ~SIMPLE;
}
//---------------------------------------------------------------------------
// изменение в списке "Длина ввинчиваемого конца"
// ---
void __fastcall TShpeelDlg::ComboBox3Change(TObject *Sender)
{
  int k = ComboBox3->ItemIndex;
  int k1 = ComboBox4->ItemIndex;
  if ( (k > -1) && (k1 > -1) ) {
    ComboBox5->ItemIndex = ::GetGostForTypeAndKlass(k, k1);
    ComboBox5Change(Sender);
  }
}

//------------------------------------------------------------------------------
//
// ---
void TShpeelDlg::ViewParamShow() {
  CalcMassa();
  ChoicePitch();
  ListParamShow();
}

//------------------------------------------------------------------------------
// изменение в списке диаметров - обновляем список длин и считываем новые параметры из БД
// ---
void __fastcall TShpeelDlg::ComboBoxChange(TObject *Sender)
{
  AnsiString Str;

  Str = ComboBox->Text;
  char *c;
  float dr = (float)::strtod( Str.c_str(), &c ); // преобразуем в число
  if ( ::fabs(dr - S.GetShpeelParam().d) > 0.001 ) {
    if ( !S.ReadShpeelBase(dr) ) { ModalResult = mrCancel; return ; } // Чтение БД

    FillLenght();                  // заполнение списка длин

    if ( S.ReadShpeelStBase() == -1 ) {  ModalResult = mrCancel; return; }   // Чтение БД

                RadioGroup1->Controls[1]->Enabled = S.GetShpeelParam().f & ALLST ? false : true;
                if ( S.GetShpeelParam().f & ALLST )
            RadioGroup1->ItemIndex = 0;

    bitMapId = ::ChoiceBMP( S.GetShpeelParam().gost, S.GetShpeelParam().f ); // выбор слайда
    ViewParamShow();                        // обновляем список параметров
    PaintBox1->Repaint();                   // перерисовываем слайд
  }
}

//---------------------------------------------------------------------------
// изменение в списке длин - считываем новые параметры из БД
// ---
void __fastcall TShpeelDlg::ComboBox2Change(TObject *Sender)
{
  AnsiString Str;

  Str = ComboBox2->Text;  // считываем строку
  char *c;
  float l = (float)::strtod( Str.c_str(), &c ); // преобразуем в число
  if ( ::fabs(l - S.GetShpeelParam().l) > 0.001 ) {
    S.GetShpeelParam().l = l; //нашли длину для k индекса в списке длин
    if ( S.ReadShpeelStBase() == -1 ) { ModalResult = mrCancel; return; } // Чтение БД

    RadioGroup1->Controls[1]->Enabled = S.GetShpeelParam().f & ALLST ? false : true;
                if ( S.GetShpeelParam().f & ALLST )
            RadioGroup1->ItemIndex = 0;

    bitMapId = ::ChoiceBMP( S.GetShpeelParam().gost, S.GetShpeelParam().f ); // выбор слайда
    ViewParamShow();                        // обновляем список параметров
    PaintBox1->Repaint();                   // перерисовываем слайд
  }

}

//---------------------------------------------------------------------------
//
// ---
void __fastcall TShpeelDlg::CheckBox1Click(TObject *Sender)
{
  if (CheckBox1->Checked)
    S.GetShpeelParam().f |= PITCH;
  else
    S.GetShpeelParam().f &= ~PITCH;
  ViewParamShow();
}

//---------------------------------------------------------------------------
//
// ---
void __fastcall TShpeelDlg::ComboBox1Change(TObject *Sender)
{
  int k = ComboBox1->ItemIndex;
  if ( k > -1 ) {
    S.GetShpeelParam().indexMassa =(byte) k;
    ViewParamShow();
  }
}

//---------------------------------------------------------------------------
//
// ---
void __fastcall TShpeelDlg::cboxSpcObjClick(TObject *Sender)
{
  S.GetFlagAttr() = cboxSpcObj->Checked == 1/*вкл.*/ ? true : false;
}

//---------------------------------------------------------------------------
//
// ---
void TShpeelDlg::ListParamShow()
{
  char buf[128];

    sprintf(buf,"%.0f",S.GetShpeelParam().b);      //l0 Гаечный конец
    StringGrid1->Cells[0][1] = buf;
    sprintf(buf,"%.0f",S.GetShpeelParam().b1);             //l1 Ввинчиваемый конец
    StringGrid1->Cells[1][1] = buf;
    sprintf(buf,"%.1f",p);                    //"Шаг резьбы"
    StringGrid1->Cells[2][1] = buf;
    sprintf(buf,"%.1f",S.GetShpeelParam().c);              //"Фаска"
    StringGrid1->Cells[3][1] = buf;
    sprintf(buf,"%.1f",massa);                //"Масса 1000 шт"
    StringGrid1->Cells[4][1] = buf;
}
//---------------------------------------------------------------------------

void __fastcall TShpeelDlg::RadioGroup1Click(TObject *Sender)
{
      if ( RadioGroup1->ItemIndex ==0 )
    S.GetShpeelParam().f &=~ ISPOLN;
  else
    S.GetShpeelParam().f |= ISPOLN;

  bitMapId = ::ChoiceBMP( S.GetShpeelParam().gost, S.GetShpeelParam().f ); // выбор слайда
  ViewParamShow();                        // обновляем список параметров
  PaintBox1->Repaint();                   // перерисовываем слайд
}
//---------------------------------------------------------------------------

void TShpeelDlg::CalcMassa() 
{ 
  massa =  S.GetShpeelParam().f & ISPOLN ? S.GetShpeelParam().m2 
                                         : S.GetShpeelParam().m1;
  massa *= (float)( ! S.GetShpeelParam().indexMassa      ? 1 
                    : S.GetShpeelParam().indexMassa == 1 ? 0.356 
                    : S.GetShpeelParam().indexMassa == 3 ? 0.97 : 1.08 ); 
}

//---------------------------------------------------------------------------
void TShpeelDlg::ChoicePitch() 
{ 
  p = S.GetShpeelParam().f & PITCH ? S.GetShpeelParam().p2 : S.GetShpeelParam().p1; 
}

