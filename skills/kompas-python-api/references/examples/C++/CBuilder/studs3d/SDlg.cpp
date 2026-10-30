////////////////////////////////////////////////////////////////////////////////
//
// sdlg.cpp - Диалог шпильки
//
////////////////////////////////////////////////////////////////////////////////
#ifndef VCL_H
#include <vcl.h>
#endif

#ifndef __WINDOWS_
#include <windows.h>
#endif

#ifndef __STDIO_H
#include <stdio.h>
#endif

#ifndef  __MATH_H
#include <math.h>
#endif

#pragma hdrstop

#ifndef __STUDS3D_RH
#include "studs3D.rh"
#endif

#ifndef SDlgH
#include "SDlg.h"
#endif

#pragma package(smart_init)
#pragma resource "*.dfm"
TShpeelDlg *ShpeelDlg;

#define MAX_LENGTH 1000        // Максимальная длина стержня
#define MIN_LENGTH 0           // Минимальная длина стержня

extern HINSTANCE _hinst;


//-------------------------------------------------------------------------------
// Загрузить строку из ресурса
// ---
LPTSTR _LoadStr( int id );


//-------------------------------------------------------------------------------
// Диалог редактирования параметров
// ---
int	Shpeel::MacroElementParam() 
{
	int res = 0;
	Shpeel* bufS = Dublicate();
	if ( bufS && bufS->OpenBase() ) 
  {
    TShpeelDlg * dlg  = new TShpeelDlg( Application, *bufS );
		if ( dlg ) 
    {
			EnableTaskAccess( 0 ); // Закрыть доступ к компасу
 			res = dlg->ShowModal();	// Вывод диалога
			EnableTaskAccess( 1 ); // Открыть доступ к компасу
			delete dlg;
		}
		if ( res == mrOk ) 
			Assign( *bufS );
		bufS->CloseBase();
		delete bufS;
	}
	return res;
}


//------------------------------------------------------------------------------
// Выбор слайда
// ---
static UINT ChoiceBMP( short gost, short f ) 
{
	UINT bmp = 0;
  if ( gost > 22041 ) 
		bmp = f & ALLST ? SH22042_3 : f & ISPOLN ? SH22042_2 : SH22042_1;
  else 
		bmp = f & ISPOLN ? SH22032_2 : SH22032_1;
	return bmp;
}


//------------------------------------------------------------------------------
// Определяет длину ввинчиваемого конца по ГОСТу
// ---
int GetTypeForGost( short gost ) 
{
	int n;
  switch ( gost ) 
  {
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
// Определяет класс точности по ГОСТу
// ---
int GetKlassForGost( short gost ) 
{
	int n;
  switch ( gost ) 
  {
    case 22032 :
    case 22034 :
    case 22036 :
    case 22038 :
    case 22040 :
    case 22042 : n = 1;  break; // B 
    case 22033 :
    case 22035 :
    case 22037 :
    case 22039 :
    case 22041 :
    case 22043 : n = 0;  break; // A
  }
  return n;
}


//------------------------------------------------------------------------------
// Определяет класс точности по ГОСТу
// ---
int GetGostForTypeAndKlass( int type, int klass ) 
{
	int n;
  switch ( type ) 
  {
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
static int NumberStr( int gost ) 
{
	int n;
  switch ( gost ) 
  {
    case 22032 :	n = STR59;	break;
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

//-------------------------------------------------------------------------------
// Диалог шпильки
// ---
__fastcall TShpeelDlg::TShpeelDlg(TComponent* Owner, Shpeel & _s )
        : TForm(Owner), S( _s)
{
  bitMapId = 0;

  StringGrid1->ColCount = 5;
  int colW = StringGrid1->Width/StringGrid1->ColCount;
  StringGrid1->ColWidths[0] = colW-1;
  StringGrid1->ColWidths[1] = colW-1;
  StringGrid1->ColWidths[2] = colW-1;
  StringGrid1->ColWidths[3] = colW-1;
  StringGrid1->ColWidths[4] = colW-1;

  char buf[128];
  LoadString( _hinst, STR247, buf, 128 ); // Гаечный конец
  StringGrid1->Cells[0][0] = buf;
  LoadString( _hinst, STR248, buf, 128 ); // Ввинчиваемый конец
  StringGrid1->Cells[1][0] = buf;
  LoadString( _hinst, STR231, buf, 128 ); // Шаг резьбы
  StringGrid1->Cells[2][0] = buf;         
  LoadString( _hinst, STR236, buf, 128 ); // Фаска
  StringGrid1->Cells[3][0] = buf;
  LoadString( _hinst, STR237, buf, 128 ); // Масса 1000 шт
  StringGrid1->Cells[4][0] = buf;
}


//-------------------------------------------------------------------------------
//
// ---
__fastcall TShpeelDlg::~TShpeelDlg() 
{
  S.CloseBase();
}


//-------------------------------------------------------------------------------
// Вызов справки
// ---
void __fastcall TShpeelDlg::helpButtonClick(TObject *)
{
  Message( _LoadStr( STR_NOREALIZE ) );
}


//---------------------------------------------------------------------------
// Инициализация диалога
// ---
void __fastcall TShpeelDlg::FormShow(TObject *)
{
  char buf[128];

  // Заполнение списка ГОСТов
  static int idGOST[] = { STR59, STR60, STR61, STR62, STR63, STR64, STR65, STR66, STR67, STR68, STR69, STR70 };
  ComboBox5->Clear();
  for ( UINT i = 0; i < 12; i++ ) 
  {
    LoadString( _hinst, idGOST[i], buf, 128 );
    ComboBox5->Items->Add( buf );
  }
  LoadString( _hinst, ::NumberStr(S.GetShpeelParam().gost), buf, 128 );
  int ind = ComboBox5->Items->IndexOf( buf );
  ComboBox5->ItemIndex = ind; // Выделяем его в списке

  // Заполнение списка "Длина ввинчиваемого конца"
  for ( UINT i = 0; i < 6; i++ ) 
  {
    LoadString( _hinst, STR_STUD_1D + i, buf, 128 );
    ComboBox3->Items->Add( buf );
  }
  ComboBox3->ItemIndex = ::GetTypeForGost(S.GetShpeelParam().gost);  // Выделение длины ввинчиваемого конца

  static int idMat[] = { STR238, STR239, STR240, STR246 };
  for ( UINT i = 0; i < 4; i++ ) 
  {
    LoadString( _hinst, idMat[i], buf, 128 );
    ComboBox1->Items->Add( buf );
  }
  ComboBox1->ItemIndex = S.GetShpeelParam().indexMassa;

  // Заполнение списка "Класс точности"
  LoadString( _hinst, STR_STUD_A, buf, 128 );  // "A"
  ComboBox4->Items->Add( buf );
  LoadString( _hinst, STR_STUD_B, buf, 128 );  // "B"
  ComboBox4->Items->Add( buf );
  ComboBox4->ItemIndex = ::GetKlassForGost(S.GetShpeelParam().gost); // выделение класса точности

  // Изменение состояния "Упрощенно"
  CheckBox2->Checked = S.GetShpeelParam().f & SIMPLE;

  InitControls();
  cboxSpcObj->Checked = S.GetFlagAttr();

  ListParamShow(); 
}


//---------------------------------------------------------------------------
// Вывод слайда
// ---
void __fastcall TShpeelDlg::PaintBox1Click(TObject *)
{
  DrawSlide( (void *)Panel1->Handle, bitMapId );
}


//------------------------------------------------------------------------------
// Заполняет список диаметров
// ---
void TShpeelDlg::FillDiametr()
{
  struct {
    short t;
    char s[128];
  } tmpL;

  ComboBox->Clear();                // Очищаем список

  float lMin         = MAX_LENGTH;  // Минимальное значение в списке
  float lMax         = MIN_LENGTH;  // Максимальное значение в списке
  bool  enterInRange = false;       // Текущее значение диаметра не входит в новые значения
  bool  failDB       = true;        // Предполагаем ошибку

  if ( !::Condition(S.GetShpeelBase().bg, S.GetShpeelBase().rg1, "t = 1") )
  {
    Error( _LoadStr( STR_KONSTR_ERROR ) ); // Сообщаем об ошибке
    return;
  }

  int i = 1;
  while( i ) // Просматриваем все записи базы данных
  {
    i = ::ReadRecord( S.GetShpeelBase().bg, S.GetShpeelBase().rg1, &tmpL );// Считываем данное
    if ( i ) // Если запись найдена
    {
      ComboBox->Items->Add( tmpL.s ); // Заносим в список

      char *c;
      float ln = ::strtod( tmpL.s, &c ); // Преобразуем его в число
      if ( S.GetShpeelParam().d == ln )
        enterInRange = true;             // Текущее значение диаметра входит в новые значения
      if ( ln < lMin )
        lMin = ln;                       // Находим минимальное значение
      if ( ln > lMax )
        lMax = ln;                       // Находим максимальное значение

      failDB = false;                    // Ошибки нет
    }
  }
  if ( !enterInRange )                   // Если текущее значение диаметра не входит в в новые значения
    S.GetShpeelParam().d = lMin;         // Присваиваем диаметру минимальное значение
  if ( S.GetShpeelParam().d < lMin )     // Если диаметр выходит за минимальную границу новых значений
    S.GetShpeelParam().d = lMin;         // Присваиваем ему минимальное значение
  if ( S.GetShpeelParam().d > lMax )     // Если диаметр выходит за максимальную границу новых значений
    S.GetShpeelParam().d = lMax;         // Присваиваем ему максимальное значение

  ::sprintf( tmpL.s, "%g", S.GetShpeelParam().d ); // Преобразуем текущее значение диаметра в строку
  int ind = ComboBox->Items->IndexOf( tmpL.s ); // Выделяем в списке
  ComboBox->ItemIndex = ind;

  if ( failDB ) // Если работа с БД не была удачной
    Error( _LoadStr( STR_DIAM_ERROR ) ); // Сообщаем об ошибке
}


//------------------------------------------------------------------------------
// Заполняет список длин
// ---
void TShpeelDlg::FillLenght()
{
  struct {
    short t;
    char s[128];
    float dr;
  } tmpL;

  // Формируем условие запроса к БД
  ::sprintf( tmpL.s, "t = 1 and d=%.1f", S.GetShpeelParam().d );
  if ( !::Condition(S.GetShpeelBase().bs, S.GetShpeelBase().rs1, tmpL.s) )
  {
    Error( _LoadStr( STR_KONSTR_ERROR ) ); // Сообщаем об ошибке
    return;
  }

  ComboBox2->Clear(); // Очищаем список

  float lMin         = MAX_LENGTH; // Минимальное значение в списке
  float lMax         = MIN_LENGTH; // Максимальное значение в списке
  bool  enterInRange = false;      // Текущее значение длины не входит в новые значения
  bool  failDB       = true;       // Предполагаем ошибку

  int i = 1;
  while( i ) 
  {                                // Просматриваем все записи базы данных
    i = ::ReadRecord( S.GetShpeelBase().bs, S.GetShpeelBase().rs1, &tmpL ); // Считываем данное
    if ( i ) // Если запись найдена 
    {                                     
      ComboBox2->Items->Add( tmpL.s ); // Заносим в список

      char *c;
      float ln = ::strtod( tmpL.s, &c ); // Преобразуем его в число
      if ( S.GetShpeelParam().l == ln )
        enterInRange = true; // Текущее значение длины входит в новые значения
      if ( ln < lMin )
        lMin = ln; // Находим минимальное значение
      if ( ln > lMax )
        lMax = ln; // Находим максимальное значение

      failDB = false; // Ошибки нет
    }
  }
  if ( !enterInRange )                      // Если текущее значение длины не входит в в новые значения
    S.GetShpeelParam().l = lMin;     // Присваиваем длине минимальное значение
  if ( S.GetShpeelParam().l < lMin ) // Если диаметр выходит за минимальную границу новых значений
    S.GetShpeelParam().l = lMin;     // Присваиваем ему минимальное значение
  if ( S.GetShpeelParam().l > lMax ) // Если диаметр выходит за максимальную границу новых значений
    S.GetShpeelParam().l = lMax;     // Присваиваем ему максимальное значение

  ::sprintf( tmpL.s, "%g", S.GetShpeelParam().l ); // Преобразуем текущее значение длины в строку
	int ind = ComboBox2->Items->IndexOf( tmpL.s ); // Выделяем его в списке
  ComboBox2->ItemIndex = ind;

  if ( failDB )                     // Если работа с БД не была удачной
    Error( _LoadStr( STR_LEN_ERROR ) ); // Сообщаем об ошибке
}


//------------------------------------------------------------------------------
// Инициализация контролов
// ---
void TShpeelDlg::InitControls() 
{
  if ( S.GetShpeelParam().gost > 22041 ) 
  {
    if ( ::fabs(S.GetShpeelParam().b) > 0.001 )
      S.GetShpeelParam().f &=~ ALLST;
    else
      S.GetShpeelParam().f |= ALLST;
  }
  else
    S.GetShpeelParam().f &=~ ALLST;

	CheckBox1->Checked = S.GetShpeelParam().f & PITCH;
	RadioGroup1->ItemIndex = S.GetShpeelParam().f & ISPOLN;

  FillDiametr(); // Заполнение списка диаметра
  FillLenght();  // Заполнение списка длин

  RadioGroup1->Controls[1]->Enabled = S.GetShpeelParam().f & ALLST ? false : true;
  if ( S.GetShpeelParam().f & ALLST )
		RadioGroup1->ItemIndex = 0;

  CalcMassa();
  ChoicePitch();
  bitMapId = ChoiceBMP( S.GetShpeelParam().gost, S.GetShpeelParam().f );
  PaintBox1->Repaint(); // Перерисовываем слайд
}


//------------------------------------------------------------------------------
// Изменение госта в списке ГОСТов
// ---
void __fastcall TShpeelDlg::ComboBox5Change(TObject *)
{
  AnsiString Str;

    Str = ComboBox5->Text; // Считываем строку

	int index = Str.Pos( "-" );
	if ( index > 0 ) // Удаляем из ГОСТа год
		Str.SetLength( index-1 );
	short gost = (short)::atoi( Str.c_str() ); // Преобразуем в число
	if ( gost != S.GetShpeelParam().gost ) 
  {
		S.GetShpeelParam().gost = gost;

	  ComboBox3->ItemIndex = ::GetTypeForGost(S.GetShpeelParam().gost);  // Выделение длины ввинчиваемого конца l1
	  ComboBox4->ItemIndex = ::GetKlassForGost(S.GetShpeelParam().gost); // Выделение класса точности

    if ( S.IsBaseOpen() ) // Если БД открыта
      S.CloseBase();      // Закрываем старую БД

    // Открываем новую БД и считываем текущие параметры
    if ( !S.OpenBase() )
      { ModalResult = mrCancel; return; }
    if ( !S.ReadShpeelBase(S.GetShpeelParam().d) )
      { ModalResult = mrCancel; return; }
    if ( S.ReadShpeelStBase() == -1 )              
      { ModalResult = mrCancel; return; }

    InitControls();  // Инициализация контролов
    ListParamShow(); // Обновляем список параметров
  }
}


//------------------------------------------------------------------------------
// Изменение в списке "Класс точности"
// ---
void __fastcall TShpeelDlg::ComboBox4Change(TObject *Sender)
{
  int k = ComboBox4->ItemIndex;
  int k1 = ComboBox3->ItemIndex;
  if ( (k > -1) && (k1 > -1) ) 
  {
    ComboBox5->ItemIndex = ::GetGostForTypeAndKlass(k1, k);
    ComboBox5Change(Sender);
  }
}


//------------------------------------------------------------------------------
// Изменение состояния "Упрощенно"
// ---
void __fastcall TShpeelDlg::CheckBox2Click(TObject *)
{
  if (CheckBox2->Checked)
    S.GetShpeelParam().f |= SIMPLE;
  else
    S.GetShpeelParam().f &= ~SIMPLE;
}


//---------------------------------------------------------------------------
// Изменение в списке "Длина ввинчиваемого конца"
// ---
void __fastcall TShpeelDlg::ComboBox3Change(TObject *Sender)
{
  int k = ComboBox3->ItemIndex;
  int k1 = ComboBox4->ItemIndex;
  if ( (k > -1) && (k1 > -1) ) 
  {
    ComboBox5->ItemIndex = ::GetGostForTypeAndKlass(k, k1);
    ComboBox5Change(Sender);
  }
}


//------------------------------------------------------------------------------
// Отображение параметров
// ---
void TShpeelDlg::ViewParamShow() 
{
  CalcMassa();
  ChoicePitch();
  ListParamShow();
}


//------------------------------------------------------------------------------
// Изменение в списке диаметров - обновляем список длин и считываем новые параметры из БД
// ---
void __fastcall TShpeelDlg::ComboBoxChange(TObject *)
{
  AnsiString Str;

  Str = ComboBox->Text;
  char *c;
  float dr = (float)::strtod( Str.c_str(), &c ); // Преобразуем в число
  if ( ::fabs(dr - S.GetShpeelParam().d) > 0.001 ) 
  {
    if ( !S.ReadShpeelBase(dr) ) 
      { ModalResult = mrCancel; return ; } // Чтение БД

    FillLenght(); // Заполнение списка длин

    if ( S.ReadShpeelStBase() == -1 ) 
      {  ModalResult = mrCancel; return; } // Чтение БД

                RadioGroup1->Controls[1]->Enabled = S.GetShpeelParam().f & ALLST ? false : true;
                if ( S.GetShpeelParam().f & ALLST )
	          RadioGroup1->ItemIndex = 0;

    bitMapId = ::ChoiceBMP( S.GetShpeelParam().gost, S.GetShpeelParam().f ); // Выбор слайда
    ViewParamShow();      // Обновляем список параметров
    PaintBox1->Repaint(); // Перерисовываем слайд
  }
}


//---------------------------------------------------------------------------
// Изменение в списке длин - считываем новые параметры из БД
// ---
void __fastcall TShpeelDlg::ComboBox2Change(TObject *)
{
  AnsiString Str;

  Str = ComboBox2->Text;  // Cчитываем строку
  char *c;
  float l = (float)::strtod( Str.c_str(), &c ); // Преобразуем в число
  if ( ::fabs(l - S.GetShpeelParam().l) > 0.001 ) 
  {
    S.GetShpeelParam().l = l; // Нашли длину для k индекса в списке длин
    if ( S.ReadShpeelStBase() == -1 ) 
      { ModalResult = mrCancel; return; } // Чтение БД

		RadioGroup1->Controls[1]->Enabled = S.GetShpeelParam().f & ALLST ? false : true;
    if ( S.GetShpeelParam().f & ALLST )
	    RadioGroup1->ItemIndex = 0;

    bitMapId = ::ChoiceBMP( S.GetShpeelParam().gost, S.GetShpeelParam().f ); // Выбор слайда
    ViewParamShow();      // Обновляем список параметров
    PaintBox1->Repaint(); // Перерисовываем слайд
  }   
}


//---------------------------------------------------------------------------
// Шаг
// ---
void __fastcall TShpeelDlg::CheckBox1Click(TObject *)
{
  if (CheckBox1->Checked)
    S.GetShpeelParam().f |= PITCH;
  else
    S.GetShpeelParam().f &= ~PITCH;
  ViewParamShow();
}


//---------------------------------------------------------------------------
// Материал
// ---
void __fastcall TShpeelDlg::ComboBox1Change(TObject *)
{
  int k = ComboBox1->ItemIndex;
  if ( k > -1 ) 
  {
    S.GetShpeelParam().indexMassa =(byte) k;
    ViewParamShow();
  }
}


//---------------------------------------------------------------------------
// Создавать объект спецификации
// ---
void __fastcall TShpeelDlg::cboxSpcObjClick(TObject *)
{
	S.GetFlagAttr() = cboxSpcObj->Checked == 1 ? true : false;
}


//---------------------------------------------------------------------------
// Отображение параметров в таблице
// ---
void TShpeelDlg::ListParamShow()
{
  char buf[128];
  sprintf(buf,"%.0f",S.GetShpeelParam().b);  // Гаечный конец
  StringGrid1->Cells[0][1] = buf;
  sprintf(buf,"%.0f",S.GetShpeelParam().b1); // Ввинчиваемый конец
  StringGrid1->Cells[1][1] = buf;
  sprintf(buf,"%.1f",p);                     // Шаг резьбы
  StringGrid1->Cells[2][1] = buf;
  sprintf(buf,"%.1f",S.GetShpeelParam().c);  // Фаска
  StringGrid1->Cells[3][1] = buf;
  sprintf(buf,"%.1f",massa);                 // Масса 1000 шт
  StringGrid1->Cells[4][1] = buf;
}


//---------------------------------------------------------------------------
// Исполнение
// ---
void __fastcall TShpeelDlg::RadioGroup1Click(TObject *)
{
  if ( RadioGroup1->ItemIndex ==0 )
		S.GetShpeelParam().f &=~ ISPOLN;
	else
		S.GetShpeelParam().f |= ISPOLN;

  bitMapId = ::ChoiceBMP( S.GetShpeelParam().gost, S.GetShpeelParam().f ); // Выбор слайда
  ViewParamShow();      // Обновляем список параметров
  PaintBox1->Repaint(); // Перерисовываем слайд
} 
