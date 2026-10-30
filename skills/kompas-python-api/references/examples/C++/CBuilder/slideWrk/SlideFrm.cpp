////////////////////////////////////////////////////////////////////////////////
//
// slidefrm.cpp - Диалог отрисовки слайда
//
////////////////////////////////////////////////////////////////////////////////
#include <vcl.h>
#pragma hdrstop

#include "SlideFrm.h"

#ifndef __LIBTOOL_H
#include "libtool.h"
#endif

#pragma package(smart_init)
#pragma resource "*.dfm"
TSlideForm *SlideForm;

extern  HINSTANCE _hinst;

//-------------------------------------------------------------------------------
//
// ---
__fastcall TSlideForm::TSlideForm(TComponent* Owner)
  : TForm(Owner)
{
}


//-------------------------------------------------------------------------------
// Отрисовка слайда
// ---
void __fastcall TSlideForm::pPreviewBoxPaint(TObject *Sender)
{
  char fName[_MAX_PATH];
  ::GetModuleFileName( _hinst, fName, _MAX_PATH);
  char *c = ::strrchr( fName, '\\' );
  if ( c )
    *( c + 1 ) = '\0';
  ::strcat( fName, "Example.rc" );

  ::ksDrawSlideFromFile( pPreviewPanel->Handle, fName );
}


//-------------------------------------------------------------------------------
// Функция, вызывающая диалог с отрисовкой слайда или битмапа
//-------------------------------------------------------------------------------
void TestShowDialog() 
{
	TSlideForm* pDialog = new TSlideForm( Application );
  if( pDialog )
  {
    EnableTaskAccess( 0 ); // Запретить доступ к задаче со стороны пользователя
	  pDialog->ShowModal();
    EnableTaskAccess( 1 ); // Разрешить доступ к задаче со стороны пользователя

   	delete pDialog;
  }
}
