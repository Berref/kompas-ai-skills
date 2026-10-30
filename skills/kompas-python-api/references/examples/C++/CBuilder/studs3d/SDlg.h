////////////////////////////////////////////////////////////////////////////////
//
// sdlg.h - Диалог шпильки
//
////////////////////////////////////////////////////////////////////////////////
#ifndef SDlgH
#define SDlgH

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>

#ifndef __STUDS3D_H
#include "studs3D.h"
#endif

//-------------------------------------------------------------------------------
//
// ---
class TShpeelDlg : public TForm
{
__published:
        TButton *Ok;
        TCheckBox *cboxSpcObj;  
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
        
        void __fastcall cboxSpcObjClick(TObject *Sender);  // Создавать объект спецификации
        void __fastcall PaintBox1Click(TObject *Sender);   // Вывод слайда
        void __fastcall ComboBoxChange(TObject *Sender);   // Изменение в списке диаметров - обновляем список длин и считываем новые параметры из БД
        void __fastcall helpButtonClick(TObject *Sender);  // Вызов справки
        void __fastcall ComboBox2Change(TObject *Sender);  // Изменение в списке длин - считываем новые параметры из БД
        void __fastcall ComboBox1Change(TObject *Sender);  // Шаг
        void __fastcall FormShow(TObject *Sender);         // Инициализация диалога
        void __fastcall ComboBox5Change(TObject *Sender);  // Изменение госта в списке ГОСТов
        void __fastcall ComboBox4Change(TObject *Sender);  // Изменение в списке "Класс точности"
        void __fastcall CheckBox2Click(TObject *Sender);   // Изменение состояния "Упрощенно"
        void __fastcall ComboBox3Change(TObject *Sender);  // Изменение в списке "Длина ввинчиваемого конца"
        void __fastcall CheckBox1Click(TObject *Sender);   // Материал
        void __fastcall RadioGroup1Click(TObject *Sender); // Исполнение
private:
  float p;              // Шаг - вспомогательное поле
	float massa;          // Масса - вспомогательное поле
	UINT bitMapId;        // Идентификатор слайда
	Shpeel& S;            // Шпилька

public:
             __fastcall TShpeelDlg(TComponent* Owner, Shpeel & _g );
             __fastcall ~TShpeelDlg();

private:	
        // Расчет массы
        void CalcMassa() { massa =  S.GetShpeelParam().f & ISPOLN ? 
                                    S.GetShpeelParam().m2 : S.GetShpeelParam().m1;
                           massa *= (float)( !S.GetShpeelParam().indexMassa ?
                                             1 : S.GetShpeelParam().indexMassa == 1 ?
                                                 0.356 : S.GetShpeelParam().indexMassa == 3 ?
                                                         0.97 : 1.08 ); }
        // Выбор шага
        void ChoicePitch() { p = S.GetShpeelParam().f & PITCH ?
                                 S.GetShpeelParam().p2 : S.GetShpeelParam().p1; }
        void FillDiametr();   // Заполняет список диаметров
        void FillLenght();    // Заполняет список длин
        void InitControls();  // Инициализация контролов
        void ViewParamShow(); // Отображение параметров
        void ListParamShow(); // Отображение параметров в таблице
};


//-------------------------------------------------------------------------------
//
// ---
extern PACKAGE TShpeelDlg *ShpeelDlg;

#endif
