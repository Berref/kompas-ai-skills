//---------------------------------------------------------------------------

#ifndef SDlgH
#define SDlgH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include "base.h"
//---------------------------------------------------------------------------
class TShpeelDlg : public TForm
{
__published:	// IDE-managed Components
  TButton *Ok;
  TCheckBox *cboxSpcObj;   //
  TPanel *Panel1;
  TPaintBox *PaintBox1;
  TGroupBox *GroupBox1;
  TButton *canselButton;
  TComboBox *ComboBox;
  TButton *helpButton;
  TComboBox *ComboBox1;
  TLabel *Label4;
  TStringGrid *StringGrid1;
  TComboBox *ComboBox2;
  TLabel *Label1;
  TLabel *Label2;
  TLabel *Label3;
  TComboBox *ComboBox3;
  TLabel *Label5;
  TComboBox *ComboBox4;
  TLabel *Label6;
  TComboBox *ComboBox5;
  TCheckBox *CheckBox1;
  TCheckBox *CheckBox2;
  TRadioGroup *RadioGroup1;
  
  void __fastcall cboxSpcObjClick(TObject *Sender);
  void __fastcall PaintBox1Click(TObject *Sender);
  void __fastcall ComboBoxChange(TObject *Sender);
  void __fastcall helpButtonClick(TObject *Sender);
  void __fastcall ComboBox2Change(TObject *Sender);
  void __fastcall ComboBox1Change(TObject *Sender);
  void __fastcall FormShow(TObject *Sender);
  void __fastcall ComboBox5Change(TObject *Sender);
  void __fastcall ComboBox4Change(TObject *Sender);
  void __fastcall CheckBox2Click(TObject *Sender);
  void __fastcall ComboBox3Change(TObject *Sender);
  void __fastcall CheckBox1Click(TObject *Sender);
  void __fastcall RadioGroup1Click(TObject *Sender);

private:	// User declarations
  float p;              // шаг - вспомогательное поле
  float massa;          // масса - вспомогательное поле
  UINT bitMapId;        // идентификатор слайда
  Shpeel& S;
  
  void CalcMassa();
  void ChoicePitch();
  void InitControls();
  void ListParamShow();
  void ErrorDialog( int id );
  void FillDiametr();
  void FillLenght();
  void ViewParamShow();
public:// User declarations
    __fastcall TShpeelDlg(TComponent* Owner, Shpeel & _g );
    __fastcall ~TShpeelDlg();
};
//---------------------------------------------------------------------------
extern PACKAGE TShpeelDlg *ShpeelDlg;
//---------------------------------------------------------------------------

#endif
