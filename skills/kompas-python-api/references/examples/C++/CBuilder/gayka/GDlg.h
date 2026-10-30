////////////////////////////////////////////////////////////////////////////////
//
// gdlg.h - Диалог гайки
//
////////////////////////////////////////////////////////////////////////////////
#ifndef GDlgH
#define GDlgH

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "gayka.h"

//-------------------------------------------------------------------------------
//
// ---
class TGaykaDlg : public TForm
{
__published:
  TButton *Ok;
  TCheckBox *cboxSpcObj;
  TPanel *Panel1;
  TPaintBox *PaintBox1;
  TGroupBox *GroupBox1;
  TRadioButton *RadioButton1;
  TRadioButton *RadioButton2;
  TRadioButton *RadioButton3;
  TRadioButton *RadioButton4;
  TButton *canselButton;
  TComboBox *ComboBox;
  TLabel *Label1;
  TCheckBox *cboxPitch;
  TCheckBox *cboxSimple;
  TCheckBox *cboxAxis;
  TCheckBox *cboxKey;
  TGroupBox *GroupBox2;
  TRadioButton *rbIspoln1;
  TRadioButton *rbIspoln2;
  TGroupBox *GroupBox3;
  TLabel *Label2;
  TLabel *Label3;
  TEdit *angleEdit;
  TEdit *stepEdit;
  TButton *helpButton;

  void __fastcall cboxSpcObjClick(TObject *Sender);   // Объект спецификации
  void __fastcall PaintBox1Click(TObject *Sender);    // Отрисовка слайда
  void __fastcall RadioButton1Click(TObject *Sender); // Вид
  void __fastcall RadioButton2Click(TObject *Sender); // Вид сбоку
  void __fastcall RadioButton3Click(TObject *Sender); // Вид сверху
  void __fastcall RadioButton4Click(TObject *Sender); // Вид/разрез
  void __fastcall ComboBoxChange(TObject *Sender);    // Изменение в списке диаметров
  void __fastcall cboxPitchClick(TObject *Sender);    // Шаг мелкий
  void __fastcall cboxSimpleClick(TObject *Sender);   // Упрощенно
  void __fastcall cboxAxisClick(TObject *Sender);     // Оси симетрии
  void __fastcall rbIspoln1Click(TObject *Sender);    // Исполнение 1
  void __fastcall rbIspoln2Click(TObject *Sender);    // Исполнение 2
  void __fastcall cboxKeyClick(TObject *Sender);      // Дополнительный размер под ключ
  void __fastcall angleEditChange(TObject *Sender);   // Параметры штриховки - угол
  void __fastcall stepEditChange(TObject *Sender);    // Параметры штриховки - шаг
  void __fastcall helpButtonClick(TObject *Sender);   // Вызов справки
  void __fastcall FormActivate(TObject *Sender);      // Активация

public:
  Gayka5915 & G;
  __fastcall TGaykaDlg(TComponent* Owner, Gayka5915 & _g );
  __fastcall ~TGaykaDlg();
  void ChangeVid( int _type); // Сменился вид
  void CheckIspoln();                    // Сменилось исполнение
};


//-------------------------------------------------------------------------------
//
// ---
extern PACKAGE TGaykaDlg *GaykaDlg;

#endif
