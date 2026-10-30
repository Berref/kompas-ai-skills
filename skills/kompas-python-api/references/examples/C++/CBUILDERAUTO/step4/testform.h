//---------------------------------------------------------------------------

#ifndef testformH
#define testformH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>

#ifdef __LIGHT_VERSION__
#include <Kl_TLB.h>
#else
#include <Ks_TLB.h>
#endif

//---------------------------------------------------------------------------
class TTestSlideDlg : public TForm
{
__published: // IDE-managed Components
  TPanel *pPreviewPanel;
  TPaintBox *pPreviewBox;
  TButton *OkButton;
  TButton *canselButton;
  void __fastcall pPreviewBoxPaint(TObject *Sender);
private: // User declarations
  WideString    kompasDocName;
  unsigned int  IdSlide;
  WideString    resurs;
  long          gr;
  ksDocument2DPtr & doc;
public: // User declarations
  __fastcall TTestSlideDlg(TComponent* Owner, ksDocument2DPtr & _doc);
  __fastcall virtual ~TTestSlideDlg();
};
//---------------------------------------------------------------------------
extern PACKAGE TTestSlideDlg *TestSlideDlg;
//---------------------------------------------------------------------------
#endif
