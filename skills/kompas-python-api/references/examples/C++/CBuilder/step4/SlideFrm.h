////////////////////////////////////////////////////////////////////////////////
//
// slidefrm.h - Диалог отрисовки слайда
//
// Для отрисовки слайда или Bitmap c ID из ресурса
// Для отрисовки слайда из файла ресурса
// Отрисовка текущего документа
// Для отрисовки фрагмента из файла
// Для отрисовки группы
//
////////////////////////////////////////////////////////////////////////////////
#ifndef SlideFrmH
#define SlideFrmH

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>

#include <tchar.h>
//-------------------------------------------------------------------------------
//
// ---
class TSlideForm : public TForm
{
__published:	
  TPanel *pPreviewPanel;
  TPaintBox *pPreviewBox;
  TButton *closeButton;
  void __fastcall pPreviewBoxPaint(TObject *Sender);
public:
  __fastcall TSlideForm(TComponent* Owner);
  __fastcall ~TSlideForm(); 

	TCHAR m_fileName[255];  // Для отрисовки фрагмента из файла документа
                         // или из файла ресурса
  int  m_slideId;        // Для отрисовки слайда или Bitmap c ID из ресурса
  reference rGroup;
};


//-------------------------------------------------------------------------------
//
// ---
extern PACKAGE TSlideForm *SlideForm;

#endif