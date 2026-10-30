////////////////////////////////////////////////////////////////////////////////
//
// gdlg.cpp - Диалог гайки
//
////////////////////////////////////////////////////////////////////////////////
#ifndef __DHEAD_H
#include  "dhead.h"
#endif

#pragma hdrstop

#include <tchar.h>
#include "GDlg.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TGaykaDlg *GaykaDlg;


//-------------------------------------------------------------------------------
//
// ---
__fastcall TGaykaDlg::TGaykaDlg(TComponent* Owner,Gayka5915 & _g )
        : TForm(Owner), G( _g)
{
 char buf[128];

  struct StTmpL {
    char s[20];
    float dr;
  } tmpL;

  cboxSpcObj->Checked =  G.par.flagAttr !=0 ;
  switch (G.par.drawType)
  {
    case ID_VID    : RadioButton1->Checked = true; break;
    case ID_SIDEVID: RadioButton2->Checked = true; break;
    case ID_TOPVID : RadioButton3->Checked = true; break;
    case ID_VIDSEC : RadioButton4->Checked = true; break;
  }
  cboxPitch->Checked  = G.tmp.f & PITCH;
  cboxSimple->Checked = G.tmp.f & SIMPLE;
  cboxAxis->Checked   = !(G.tmp.f & AXIS_OFF);
  rbIspoln1->Checked  = !(G.tmp.f & ISPOLN);
  rbIspoln2->Checked  = G.tmp.f & ISPOLN;
  cboxKey->Checked    = G.tmp.f1 & KEY_S;
  cboxKey->Enabled    = G.tmp.f1 & KEY_S_GRAY;

  if ( G.OpenGaykaBase() )
  {
    int i = 1;
    while( i!=0 )
    {
      i=::ReadRecord(  G.base.bg, G.base.rg1, &tmpL );
      if ( i!=0 )
      {
        CheckDecimelPart( tmpL.s );
        ComboBox->Items->Add( String(tmpL.s) );
      }
    }
    sprintf( buf, "%.1f", G.tmp.dr );
    CheckDecimelPart( buf );
    ComboBox->ItemIndex = ComboBox->Items->IndexOf( buf );
    ::sprintf( buf, "%g", G.tmp.hatchAng );
    angleEdit->Text = buf;
    ::sprintf( buf, "%g", G.tmp.hatchShag );
    stepEdit->Text = buf;
  }
  PaintBox1->Repaint();
}


//-------------------------------------------------------------------------------
//
// ---
__fastcall TGaykaDlg::~TGaykaDlg()
{
  G.CloseGaykaBase();
}


//-------------------------------------------------------------------------------
// Объект спецификации
// ---
void __fastcall TGaykaDlg::cboxSpcObjClick(TObject *)
{
  G.par.flagAttr = cboxSpcObj->Checked ? 1 :0;
}


//-------------------------------------------------------------------------------
// Отрисовка слайда
// ---
void __fastcall TGaykaDlg::PaintBox1Click(TObject *)
{
  DrawSlide(Panel1->Handle, G.ChoiceBMP());
}


//-------------------------------------------------------------------------------
// Сменился вид
// ---
void TGaykaDlg::ChangeVid( int _type)
{
  switch ( _type)
  {
    case 0 : G.par.drawType = ID_VID;     break;
    case 1 : G.par.drawType = ID_SIDEVID; break;
    case 2 : G.par.drawType = ID_TOPVID;  break;
    case 3 : G.par.drawType = ID_VIDSEC;  break;
  }
  angleEdit->Enabled = G.par.drawType == ID_VIDSEC;
  stepEdit ->Enabled = G.par.drawType == ID_VIDSEC;
  PaintBox1->Repaint();
}


//-------------------------------------------------------------------------------
// Вид
// ---
void __fastcall TGaykaDlg::RadioButton1Click(TObject *)
{
  ChangeVid( 0 );
}


//-------------------------------------------------------------------------------
// Вид сбоку
// ---
void __fastcall TGaykaDlg::RadioButton2Click(TObject *)
{
  ChangeVid( 1 );
}


//-------------------------------------------------------------------------------
// Вид сверху
// ---
void __fastcall TGaykaDlg::RadioButton3Click(TObject *)
{
  ChangeVid( 2 );
}


//-------------------------------------------------------------------------------
// Вид/разрез
// ---
void __fastcall TGaykaDlg::RadioButton4Click(TObject *Sender)
{
  ChangeVid( 3 );
}


//-------------------------------------------------------------------------------
// Изменение в списке диаметров
// ---
void __fastcall TGaykaDlg::ComboBoxChange(TObject *Sender)
{
  float value;
  int code;
  AnsiString s = ComboBox->Items->Strings[ComboBox->ItemIndex];
  float d =  ::atof( s.c_str() );
  G.tmp.dr = d;
  if ( !G.ReadGaykaBase ( G.tmp.dr ) )
    Close();
  cboxKey->Checked = G.tmp.f1 & KEY_S;
  cboxKey->Enabled = G.tmp.f1 & KEY_S_GRAY;
}


//-------------------------------------------------------------------------------
// Шаг мелкий
// ---
void __fastcall TGaykaDlg::cboxPitchClick(TObject *Sender)
{
 if ( cboxPitch->Checked )
   G.tmp.f |= PITCH;
 else
   G.tmp.f &=~PITCH;
 if ( !G.ReadGaykaBase ( G.tmp.dr ) )
   Close();
}


//-------------------------------------------------------------------------------
// Упрощенно
// ---
void __fastcall TGaykaDlg::cboxSimpleClick(TObject *Sender)
{
  if (cboxSimple->Checked)
  {
    G.tmp.f |= SIMPLE;
    rbIspoln2->Enabled = False;
  }
  else
  {
    G.tmp.f &=~SIMPLE;
    rbIspoln2->Enabled = True;
  }
  PaintBox1->Repaint();

}


//-------------------------------------------------------------------------------
// Оси симетрии
// ---
void __fastcall TGaykaDlg::cboxAxisClick(TObject *Sender)
{
 if (cboxAxis->Checked)
   G.tmp.f &=~AXIS_OFF;
 else
   G.tmp.f |=AXIS_OFF;
}


//-------------------------------------------------------------------------------
// Сменилось исполнение
// ---
void  TGaykaDlg::CheckIspoln()
{
if( rbIspoln2->Checked )
  G.tmp.f |= ISPOLN;
else
  G.tmp.f &=~ISPOLN;
  PaintBox1->Repaint();
}


//-------------------------------------------------------------------------------
// Исполнение 1
// ---
void __fastcall TGaykaDlg::rbIspoln1Click(TObject *Sender)
{
  CheckIspoln();
}


//-------------------------------------------------------------------------------
// Исполнение 2
// ---
void __fastcall TGaykaDlg::rbIspoln2Click(TObject *Sender)
{
  CheckIspoln();
}


//-------------------------------------------------------------------------------
// Дополнительный размер под ключ
// ---
void __fastcall TGaykaDlg::cboxKeyClick(TObject *Sender)
{
  if (cboxKey->Checked)
    G.tmp.f1|=KEY_S ;
  else
    G.tmp.f1 &=~KEY_S ;
  if ( !G.ReadGaykaBase ( G.tmp.dr ) )
    Close();
}


//-------------------------------------------------------------------------------
// Параметры штриховки - угол
// ---
void __fastcall TGaykaDlg::angleEditChange(TObject *Sender)
{
  AnsiString text = angleEdit->Text;
  G.tmp.hatchAng = ::atof( text.c_str() );
}


//-------------------------------------------------------------------------------
// Параметры штриховки - шаг
// ---
void __fastcall TGaykaDlg::stepEditChange(TObject *Sender)
{
  AnsiString text = stepEdit->Text;
  G.tmp.hatchShag = ::atof( text.c_str() );
}


//-------------------------------------------------------------------------------
// Вызов справки
// ---
void __fastcall TGaykaDlg::helpButtonClick(TObject *Sender)
{
  char fileName[255];
  if ( GetFullName("gayka.chm",  fileName) )
    ksOpenHelpFile( fileName, HELP_CONTEXT, 1 );
  else
    Error( "Файл gayka.chm не найден" );
}


//-------------------------------------------------------------------------------
// Активация
// ---
void __fastcall TGaykaDlg::FormActivate(TObject *Sender)
{
  ::ConvertLangForm( this );
}


