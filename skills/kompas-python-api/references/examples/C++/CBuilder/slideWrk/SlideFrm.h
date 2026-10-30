////////////////////////////////////////////////////////////////////////////////
//
// slidefrm.h - Диалог отрисовки слайда
//
////////////////////////////////////////////////////////////////////////////////
#ifndef SlideFrmH
#define SlideFrmH

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>

//-------------------------------------------------------------------------------
//
// ---
class TSlideForm : public TForm
{
__published:	
  TPanel *pPreviewPanel;
  TPaintBox *pPreviewBox;
  TButton *closeButton;
  void __fastcall pPreviewBoxPaint(TObject *Sender); // Отрисовка слайда

private:	
  unsigned int IdSlide;

public:	
  __fastcall TSlideForm(TComponent* Owner);
};


//-------------------------------------------------------------------------------
//
// ---
extern PACKAGE TSlideForm *SlideForm;

#endif
