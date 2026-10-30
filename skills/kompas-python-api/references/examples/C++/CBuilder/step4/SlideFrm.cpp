////////////////////////////////////////////////////////////////////////////////
//
// slidefrm.cpp - Диалог отрисовки слайда
//
// Для отрисовки слайда или Bitmap c ID из ресурса
// Для отрисовки слайда из файла ресурса
// Отрисовка текущего документа
// Для отрисовки фрагмента из файла
// Для отрисовки группы
//
////////////////////////////////////////////////////////////////////////////////
#include <vcl.h>
#pragma hdrstop

#ifndef __LIBTOOL_H
#include <libtool.h>
#endif

#include "SlideFrm.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TSlideForm *SlideForm;


//-------------------------------------------------------------------------------
//
// ---
__fastcall TSlideForm::TSlideForm(TComponent* Owner)
  : TForm (Owner)
  , rGroup( 0   ) 
{
  EnableTaskAccess( 0 ); // Запретить доступ к задаче со стороны пользователя
  
  // Для отрисовки слайда или Bitmap c ID из ресурса
  m_slideId = 100;
 
  /*
  // Для отрисовки фрагмента из файла
	_tcscpy( m_fileName, _T("c:\\Example.frw") );
	ReadStringT( _T("Введите имя *.frw файла"), m_fileName, 255 );
	*/

	/*
	// Для отрисовки слайда из файла ресурса
	_tcscpy( m_fileName, _T("c:\\Example.rc") );
	ReadStringT( "Введите имя *.rc файла", m_fileName, 255 );
  */
  /*
  // Для отрисовки группы
  if ( ksGetCurrentDocument( 1 ) )
  {
    // Создание группы объектов, type - тип группы ( 0 - определяет модельный, 1 - временный )
    rGroup = NewGroup( 1 );
      Mtr( 20, 15, 45, 1 ); // Матрица преобразования координат ( 20 по оси OX, 15 по оси OY, поворот на 45 градусов )
        LineSeg( -10, 0,   10, 0,  1 );
        LineSeg(  10, 0,   10, 20, 1 );
        LineSeg(  10, 20, -10, 20, 1 );
        LineSeg( -10, 20, -10, 0,  1 );
      DeleteMtr(); // Отключение матрицы преобразования координат
    EndGroup(); // Завершить создание группы объектов
  }
  else
		MessageT( _T("Документ не активизирован или\nне является листом/фрагментом") );
  */
}


//-------------------------------------------------------------------------------
//
// ---
__fastcall TSlideForm::~TSlideForm()
{
  if ( rGroup )
    DeleteObj( rGroup );
  EnableTaskAccess( 1 ); // Разрешить доступ к задаче со стороны пользователя
}


//-------------------------------------------------------------------------------
// Отрисовка 
// ---
void __fastcall TSlideForm::pPreviewBoxPaint(TObject *Sender)
{
  // Для отрисовки слайда из ресурса
  if ( m_slideId != 0 )
    DrawSlide( pPreviewPanel->Handle, // Несущее окно
               m_slideId );           // Идентификатор слайда в файле ресурсов приложения

  /*
  // Для отрисовки Bitmap из ресурса
  if ( m_slideId != 0 )
    DrawBitmap( pPreviewPanel->Handle, // Несущее окно
                m_slideId );           // Идентификатор BMP в файле ресурсов приложения
  */

  /*
  // Для отрисовки слайда из файла ресурса
  // При изменении файла .rc не нужно перекомпилировать библиотеку
  if ( m_fileName[0] != '\0' )
    ksDrawSlideFromFile( pPreviewPanel->Handle,            // Несущее окно
                         ( char* )( LPCTSTR )m_fileName ); // Полное имя файла
  */

  /*
  // Отрисовка текущего документа
  reference doc = ksGetCurrentDocument( 1 );
  if ( doc )
    ksDrawKompasDocumentByReference( pPreviewPanel->Handle, // Несущее окно
                                     doc );                 // Указатель на документ
  */

  /*
  // Для отрисовки фрагмента из файла
  if ( m_fileName[0] != '\0' )
    ksDrawKompasDocument( pPreviewPanel->Handle,            // Несущее окно
                          ( char* )( LPCTSTR )m_fileName ); // Полное имя файла документа
  */

  /*
  // Для отрисовки группы
  if ( ksGetCurrentDocument( 1 ) )
  {
    ksDrawKompasGroup( pPreviewPanel->Handle, // Несущее окно
                       rGroup );              // Группа
  }
  */
}


//-------------------------------------------------------------------------------
// Функция, вызывающая диалог с отрисовкой слайда или битмапа
// ---
void TestShowDialog() 
{
	TSlideForm* pDialog = new TSlideForm( Application );
	pDialog->ShowModal();
	delete pDialog;
}
