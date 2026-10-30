////////////////////////////////////////////////////////////////////////////////
//
// Object2DEvent.cpp
// Object2DEvent - обработчик событий от приложения (COM)
//
////////////////////////////////////////////////////////////////////////////////

#include <vcl.h>
#pragma hdrstop

#ifndef _OBJECT2DEVENT_H
#include "Object2DEvent.h"
#endif

#include <ksConstants.h>

#ifndef __IUPTR_H
#include <iuptr.h>
#endif
#ifndef __LIBTOOL_H
#include <libtool.h>
#endif

extern int LibMessage( char* str, int flags = MB_OK );

//-------------------------------------------------------------------------------
//
// ---
Object2DEvent::Object2DEvent( reference refDoc, long objType ) :
  TBaseEvent<IObject2DNotify, & IID_IObject2DNotify>( ntObject2DNotify, refDoc, refDoc, objType ),
  m_refDoc( refDoc )
{

}

//-------------------------------------------------------------------------------
//
// ---
Object2DEvent::~Object2DEvent()
{
}

//-----------------------------------------------------------------------------
//Обрабатывается ли библиотекой событие с номером notifyType
// ---
VARIANT_BOOL STDMETHODCALLTYPE Object2DEvent::IsNotifyProcess( int notifyType )
{
//	METHOD_PROLOGUE_EX_(Obj2DEvent, Object2DNotify)
	return  notifyType >= koChangeActive && notifyType <= koUpdateObject;
}

//-------------------------------------------------------------------------------
//
// ---
void Object2DEvent::GetResultParam( String title )
{
  IUEnv<IObject2DNotifyResult> m_res( ksGetObject2DNotifyResult(refDoc) );
  long type = m_res->GetNotifyType();
  bool isCopy = m_res->IsCopy();
  bool from = TRUE;
  double x = -1;
  double y = -1;
  bool sheetPoint = m_res->GetSheetPoint( from, &x, &y );
  bool from2 = FALSE;
  double x2 = -1;
  double y2 = -1;
  bool sheetPoint2 = m_res->GetSheetPoint( from2, &x2, &y2 );
  long copyObject = m_res->GetCopyObject();
  double angle = m_res->GetAngle();
  double sx = -1;
  double sy = -1;
  bool scale = m_res->GetScale( &sx, &sy );

  AnsiString str( "Object2DEvent - GetResultParam\n" );
  str += title;             str += "\n";
  str += "type : ";         str += type;
  str += " isCopy : ";      str += isCopy ? "TRUE" : "FALSE";
  str += "\nfrom : ";       str += from ? "TRUE" : "FALSE";
  str += " sheetPoint : ";  str += sheetPoint ? "TRUE" : "FALSE";
  str += " x : ";           str += x;
  str += " y : ";           str += y;
  str += "\nfrom2 : ";      str += from2 ? "TRUE" : "FALSE";
  str += " sheetPoint2 : "; str += sheetPoint2 ? "TRUE" : "FALSE";
  str += " x2 : ";          str += x2;
  str += " y2 : ";          str += y2;
  str += "\ncopyObject : "; str += copyObject;
  str += "\nangle : ";      str += angle;
  str += "\nscale : ";      str += scale ? "TRUE" : "FALSE";
  str += " sx : ";          str += sx;
  str += " sy : ";          str += sy;

  LibMessage( str.c_str() );
}


//-------------------------------------------------------------------------------
// Переключение активности объекта( вид, слой )
// ---
VARIANT_BOOL STDMETHODCALLTYPE Object2DEvent::ChangeActive( long objRef )
{
//  GetResultParam( "Переключение активности объекта( вид, слой )" );
  LibMessage( "Object2DEvent - Переключение активности объекта( вид, слой )" );
  return TRUE;
}


//-------------------------------------------------------------------------------
// Начало удаления объекта
// ---
VARIANT_BOOL STDMETHODCALLTYPE Object2DEvent::BeginDelete( long objRef )
{
//  GetResultParam( "Начало удаления объекта" );
  return LibMessage( "Object2DEvent - Начало удаления объекта\nУдалить объект?", MB_YESNO ) == IDYES;
}


//-------------------------------------------------------------------------------
// Удаление объекта
// ---
VARIANT_BOOL STDMETHODCALLTYPE Object2DEvent::Delete( long objRef )
{
//  GetResultParam( "Удаление объекта" );

  LibMessage( "Object2DEvent - Удаление объекта" );
  return TRUE;
}


//-------------------------------------------------------------------------------
// Начало редактирования объекта
// ---
VARIANT_BOOL STDMETHODCALLTYPE Object2DEvent::BeginEdit( long objRef )
{
//  GetResultParam( "Начало редактирования объекта" );
  return LibMessage( "Object2DEvent - Начало редактирования объекта\nРедактировать объект?", MB_YESNO ) == IDYES;
}


//-------------------------------------------------------------------------------
// Объкт отредактирован
// ---
VARIANT_BOOL STDMETHODCALLTYPE Object2DEvent::EditObject( long objRef )
{
//  GetResultParam( "Объект отредактирован" );

  LibMessage( "Object2DEvent - Объект отредактирован" );
  return TRUE;
}


//-------------------------------------------------------------------------------
// Начало сдвига объекта
// ---
VARIANT_BOOL STDMETHODCALLTYPE Object2DEvent::BeginMove( long objRef )
{
//  GetResultParam( "Начало сдвига объекта" );

  return LibMessage( "Object2DEvent - Начало сдвига объекта\nПереместить объект?", MB_YESNO ) == IDYES;
}


//-------------------------------------------------------------------------------
// Сдвиг объекта
// ---
VARIANT_BOOL STDMETHODCALLTYPE Object2DEvent::Move( long objRef )
{
  GetResultParam( "Object2DEvent - Сдвиг объекта" );
  return TRUE;
}


//-------------------------------------------------------------------------------
// Начало поворота объекта
// ---
VARIANT_BOOL STDMETHODCALLTYPE Object2DEvent::BeginRotate( long objRef )
{
//  GetResultParam( "Начало поворота объекта" );
  return LibMessage( "Object2DEvent - Начало поворота объекта\nПовернуть объект?", MB_YESNO ) == IDYES;
}


//-------------------------------------------------------------------------------
// Поворот объекта
// ---
VARIANT_BOOL STDMETHODCALLTYPE Object2DEvent::Rotate( long objRef )
{
//  GetResultParam( "Поворот объекта" );

  LibMessage( "Object2DEvent - Поворот объекта" );
  return TRUE;
}


//-------------------------------------------------------------------------------
// Начало масштабирования объекта
// ---
VARIANT_BOOL STDMETHODCALLTYPE Object2DEvent::BeginScale( long objRef )
{
//  GetResultParam( "Начало масштабирования объекта" );
  return LibMessage( "Object2DEvent - Начало масштабирования объекта\nМасштабировать объект?", MB_YESNO ) == IDYES;
}


//-------------------------------------------------------------------------------
// Масштабирования объекта
// ---
VARIANT_BOOL STDMETHODCALLTYPE Object2DEvent::Scale( long objRef )
{
  GetResultParam( "Object2DEvent - Масштабирование объекта" );
  return TRUE;
}


//-------------------------------------------------------------------------------
// Начало трансформации объекта
// ---
VARIANT_BOOL STDMETHODCALLTYPE Object2DEvent::BeginTransform( long objRef )
{
//  GetResultParam( "Начало трансформации объекта" );
  return LibMessage( "Object2DEvent - Начало трансформации объекта\nТрансформировать объект?", MB_YESNO ) == IDYES;
}


//-------------------------------------------------------------------------------
// Трансформация объекта
// ---
VARIANT_BOOL STDMETHODCALLTYPE Object2DEvent::Transform( long objRef )
{
  GetResultParam( "Object2DEvent -Трансформация объекта" );
  return TRUE;
}


//-------------------------------------------------------------------------------
// Начало копирования объекта
// ---
VARIANT_BOOL STDMETHODCALLTYPE Object2DEvent::BeginCopy( long objRef )
{
  return LibMessage( "Object2DEvent - Начало копирования объекта\nКопировать объект?", MB_YESNO ) == IDYES;
}


//-------------------------------------------------------------------------------
// Копирование объекта
// ---
VARIANT_BOOL STDMETHODCALLTYPE Object2DEvent::Copy( long objRef )
{
  GetResultParam( "Object2DEvent - Копирование объекта" );
  return TRUE;
}


//-------------------------------------------------------------------------------
// Начало симметрии объекта
// ---
VARIANT_BOOL STDMETHODCALLTYPE Object2DEvent::BeginSymmetry( long objRef )
{
  return LibMessage( "Object2DEvent - Начало создания симметрии объекта\nСоздать симметрию объекта?", MB_YESNO ) == IDYES;
}


//-------------------------------------------------------------------------------
// Симметрия  объекта
// ---
VARIANT_BOOL STDMETHODCALLTYPE Object2DEvent::Symmetry( long objRef )
{
  GetResultParam( "Object2DEvent -Симметрия  объекта" );
  return TRUE;
}


//-------------------------------------------------------------------------------
// Начало редактирования\создания объекта
// ---
VARIANT_BOOL STDMETHODCALLTYPE Object2DEvent::BeginProcess( long pType, long objRef )
{
  return LibMessage( "Object2DEvent - Начало редактирования\\создания объекта\nПродолжить?", MB_YESNO ) == IDYES;
}


//-------------------------------------------------------------------------------
// Конец редактирования\создания объекта
// ---
VARIANT_BOOL STDMETHODCALLTYPE Object2DEvent::EndProcess( long pType )
{
	LibMessage( "Object2DEvent - Конец редактирования\\создания объекта" );
  return TRUE;
}


//-------------------------------------------------------------------------------
// Создание объекта
// ---
VARIANT_BOOL STDMETHODCALLTYPE Object2DEvent::CreateObject( long objRef )
{
  LibMessage( "Object2DEvent - Создан новый объект" );
  return TRUE;
}


//-------------------------------------------------------------------------------
// Редактирование объекта
// ---
VARIANT_BOOL STDMETHODCALLTYPE Object2DEvent::UpdateObject( long objRef )
{
  GetResultParam( "Object2DEvent - Объект отредактирован" );
  return TRUE;
}

//-------------------------------------------------------------------------------
// Создание объекта
// ---
VARIANT_BOOL STDMETHODCALLTYPE Object2DEvent::BeginDestroyObject( long objRef )
{
  return TRUE;
}


//-------------------------------------------------------------------------------
// Редактирование объекта
// ---
VARIANT_BOOL STDMETHODCALLTYPE Object2DEvent::DestroyObject( long objRef )
{
  return TRUE;
}
