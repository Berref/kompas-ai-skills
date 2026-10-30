//---------------------------------------------------------------------------

#ifndef KGAXFormH
#define KGAXFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <KGAXLib_OCX.h>
#include <ExtCtrls.hpp>
#include <OleCtrls.hpp>
#include "KGAXLib_TLB.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
  TPanel *Panel1;

  TButton *Button1;
  TButton *Button2;
  TRadioGroup *RadioGroup1;
  TKGAX *KGAX1;
  void __fastcall RadioGroup1Click(TObject *Sender);
  void __fastcall Button2Click(TObject *Sender);
  void __fastcall Button1Click(TObject *Sender);
  void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
  __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
