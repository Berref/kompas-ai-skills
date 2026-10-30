////////////////////////////////////////////////////////////////////////////////
//
// step1.cpp - Тест использования событий окна документа для отрисовки с помощью OpenGL
// TestDocumentFrameNotify        - тест для нового документа
// TestCurrentDocumentFrameNotify - тест для текущего документа
// 
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include <afxdllx.h> 

#include "resource.h"

#ifndef _ABASEEVENT_H
#include "abaseEvent.h"
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//-------------------------------------------------------------------------------
// Специальная структура используемая в течении инициализации DLL
// ---
static AFX_EXTENSION_MODULE StepDLL = { NULL, NULL };

IApplicationPtr newKompasAPI;            // Компас Application 7     

void TestDocumentFrameNotify();          // Тест использования событий 
void TestCurrentDocumentFrameNotify( int redrawType );


extern cBaseEvent * NewDocumentFrameEvent( IDocumentFrame* documentFrame, reference doc, int redrawType = 0 );

//-------------------------------------------------------------------------------
// Стандартная точка входа
// Инициализация и завершение DLL
// ---
extern "C" int APIENTRY
DllMain( HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved )
{
  UNREFERENCED_PARAMETER( lpReserved );

  if ( dwReason == DLL_PROCESS_ATTACH )
  {
    TRACE0( "DLL Initializing!" );
 
    if ( !AfxInitExtensionModule( StepDLL, hInstance ) )
      return 0;

    new CDynLinkLibrary( StepDLL );
  }
  else if ( dwReason == DLL_PROCESS_DETACH )
  {
    cBaseEvent::TerminateEvents();
    cBaseEvent::DestroyList();
    if ( newKompasAPI )
      newKompasAPI = NULL;
    TRACE0( "DLL Terminating!" );
    AfxTermExtensionModule( StepDLL );
  }
  return 1;
}


//-------------------------------------------------------------------------------
//
// ---
CString _LoadStr( int id )
{
  TCHAR buf[255];
  LoadString( StepDLL.hModule, id, buf, 255 );
  return buf;
}


//----------------------------------------------------------------------------------------------
// Зогрузить локализованную строку из ресурсов
//---
LPTSTR LoadStr( int ID ) {
  static TCHAR buf[255];
  ksConvertLangStrExT( StepDLL.hModule, ID, buf, 255 );
  return buf;
}


//-------------------------------------------------------------------------------
// Получить доступ к новому API
// ---
void GetNewKompasAPI() {
	if ( !( IApplication* )newKompasAPI ) {
		CString filename;
		if( ::GetModuleFileName(NULL, filename.GetBuffer(255), 255) ) {
			filename.ReleaseBuffer( 255 );
			CString libname;

      #ifdef __LIGHT_VERSION__
        libname = _LoadStr( IDS_API7LT );  // klAPI7.dll
      #else
        libname = _LoadStr( IDS_API7 );    // kAPI7.dll
      #endif

			filename.Replace( filename.Right(filename.GetLength() - (filename.ReverseFind(_T('\\')) + 1)), 
												libname );

			HINSTANCE hAppAuto = LoadLibrary( filename ); // идентификатор kAPI7.dll
			if(  hAppAuto ) {
				// Указатель на функцию возвращающую интерфейс KompasApplication  
        typedef LPDISPATCH ( WINAPI *FCreateKompasApplication )(); 
				 
        FCreateKompasApplication pCreateKompasApplication = 
					(FCreateKompasApplication)GetProcAddress( hAppAuto, "CreateKompasApplication" );	
				if ( pCreateKompasApplication )
					newKompasAPI = IDispatchPtr( pCreateKompasApplication(), false/*AddRef*/ ); // Получаем интерфейс Application
				FreeLibrary( hAppAuto );  
			}
		}
	}
}


//------------------------------------------------------------------------------
// Вывод сообщения
// ---
int LibMessage( LPCTSTR str, int flags = MB_OK ) {
  int res = 0;

  if ( str && str[0] ) {                  // строка передана
    int enabse = ::IsEnableTaskAccess();  // проверка доступа
    if ( enabse )                         // если доступ к задаче разрешен
      ::EnableTaskAccess(0);              // запрещаем доступ

    //                         текст сообщения  заголовок          параметры
    res = MessageBox( (HWND) GetHWindow(), str, LoadStr(IDR_LIB), flags );

    if ( enabse )                         // если доступ к задаче был запрещен
      ::EnableTaskAccess(1);              // разрешаем доступ к задаче
  }

  return res;
}

//------------------------------------------------------------------------------
// Вывод сообщения
// ---
int LibMessage( int strId, int flags = MB_OK ) {
  return ::LibMessage( LoadStr(strId), flags );
}

//-------------------------------------------------------------------------------
// Определить имя библиотеки
// ---
int WINAPI LIBRARYID()
{
  return IDR_LIB;
}


//-------------------------------------------------------------------------------
// Головная функция библиотеки
// ---
void WINAPI LIBRARYENTRY( unsigned int comm )
{
  // Выдача сообщения пользователю
  switch ( comm ) 
  {       
    case 1 :
      TestDocumentFrameNotify();
      break;
    case 2 :
    case 3 :
    case 4 :
    case 5 :
      TestCurrentDocumentFrameNotify( comm - 2 ); // Обход по граням компанента
      break;
  }
}


//-------------------------------------------------------------------------------
// Оперция выдавливания, работа с экизом
// ---
BOOL CreateExtrusion( IPartPtr& part )
{
  BOOL res = FALSE;
  // Создадим новый эскиз
  IEntityPtr entitySketch( part->NewEntity( o3d_sketch ), false /*AddRef*/ );
  if ( entitySketch )
  {
    // Получить указатель на интерфейс параметров объектов и элементов
    ISketchDefinitionPtr sketchDefinition( IUnknownPtr( entitySketch->GetDefinition(), false/*AddRef*/ ) );
    if ( sketchDefinition )
    {
      // Получим интерфейс базовой плоскости XOY
      IEntityPtr basePlane( part->GetDefaultEntity( o3d_planeXOY ), false /*AddRef*/ );
 
      // Установка параметров эскиза
      sketchDefinition->SetPlane( basePlane ); // Установим плоскость XOY базовой для эскиза
      sketchDefinition->SetAngle( 45 );        // Угол поворота эскиза
 
      // Создадим эскиз
      entitySketch->Create();

      // Войти в режим редактирования эскиза
      if ( sketchDefinition->BeginEdit() )
      {
        // Введем новый эскиз - квадрат
        LineSeg(  50,  50, -50,  50, 1 );
        LineSeg(  50, -50, -50, -50, 1 );
        LineSeg(  50, -50,  50,  50, 1 );
        LineSeg( -50, -50, -50,  50, 1 );
        // Выйти из режима редактирования эскиза
        sketchDefinition->EndEdit();
      }

      // Оперция выдавливани
      IEntityPtr entityExtrusion( part->NewEntity( o3d_bossExtrusion ), false /*AddRef*/ );
      if ( entityExtrusion )
      {
        // Интерфейс базовой операции выдавливания
        IBossExtrusionDefinitionPtr extrusionDefinition( IUnknownPtr( entityExtrusion->GetDefinition(), false/*AddRef*/ ) );
        if ( extrusionDefinition )
        {
          // Установка параметров операции выдавливания
          extrusionDefinition->SetDirectionType( dtNormal );     // Направление выдавливания ( dtNormal	- прямое
                                                                 // направление, для тонкой стенки - наружу,
                                                                 // dtReverse	- обратное направление, для тонкой стенки - внутрь
                                                                 // dtBoth - в обе стороны, dtMiddlePlane от средней плоскости )
          // Изменить параметры выдавливания в одном направлении
          extrusionDefinition->SetSideParam( true,               // Направление выдавливания ( TRUE - прямое направление,
                                                                 // FALSE - обратное направление )
                                             etBlind,            // Тип выдавливания ( etBlind - строго на глубину,
                                                                 // etThroughAll - через всю деталь, etUpToVertexTo - на расстояние до вершины,
                                                                 // etUpToVertexFrom - на расстояние за вершину, etUpToSurfaceTo - на
                                                                 // расстояние до поверхности, etUpToSurfaceFrom - на расстояние за поверхность,
                                                                 // etUpToNearSurface	- до ближайшей поверхности )
                                             100,                // Глубина выдавливания
                                             0,                  // Угол уклона
                                             true );             // Направление уклона ( TRUE - уклон наружу, FALSE - уклон внутрь )
          // Изменить параметры тонкой стенки
          extrusionDefinition->SetThinParam( false,              // Признак тонкостенной операции
                                             dtBoth,             // Направление построения тонкой стенки
                                             10,                 // Толщина стенки в прямом направлении
                                             10 );               // Толщина стенки в обратном направлении
          extrusionDefinition->SetSketch( entitySketch );        // Эскиз операции выдавливания
          entityExtrusion->SetName( _bstr_t(_T("Операция - Кубик")) );

          // Создать операцию выдавливания
          res = !!entityExtrusion->Create();
        }
      }
    }
  }
  return res;
}

//-----------------------------------------------------------------------------
//
// ---
void TestDocumentFrameNotify() {
  IDocument3DPtr doc3D( ksGet3dDocument(), false/*AddRef*/ );
  if ( doc3D ) {
    doc3D->Create( FALSE, 1 ); // Создаем документ модель
    doc3D->SetDrawMode( vm_Shaded );
    doc3D->SetShadedWireframe( TRUE );
    IPartPtr part( doc3D->GetPart( pTop_Part ), false/*AddRef*/ );
    if ( part ) {
      if ( CreateExtrusion( part ) ) {
        part->SetName( _bstr_t(_T("Кубик")) );
        part->Update();
        GetNewKompasAPI();
        if ( newKompasAPI ) {
          
          IKompasDocumentPtr komDoc( newKompasAPI->GetActiveDocument() );
          if ( komDoc ) {
            IDocumentFramesPtr docFrames( komDoc->GetDocumentFrames() );
            if ( docFrames ) {
              IDocumentFramePtr documentFrame( docFrames->GetItem( _variant_t( (long)0 ) ) );
              if ( documentFrame ) {
	              NewDocumentFrameEvent( documentFrame, komDoc->GetReference() );
                documentFrame->SetGabaritModifying();
                documentFrame->RefreshWindow();
              }
            }
          }
        }
      }
    }
  }
}


//-----------------------------------------------------------------------------
//
// ---
void TestCurrentDocumentFrameNotify( int redrawType ) 
{
  GetNewKompasAPI();
  if ( newKompasAPI ) {
    
    IKompasDocumentPtr komDoc( newKompasAPI->GetActiveDocument() );
    if ( komDoc ) {
      IDocumentFramesPtr docFrames( komDoc->GetDocumentFrames() );
      if ( docFrames ) {
        IDocumentFramePtr documentFrame( docFrames->GetItem( _variant_t( (long)0 ) ) );
        if ( documentFrame ) {
	        NewDocumentFrameEvent( documentFrame, komDoc->GetReference(), redrawType );
          documentFrame->SetGabaritModifying();
          documentFrame->RefreshWindow();
        }
      }
    }
  }
}
