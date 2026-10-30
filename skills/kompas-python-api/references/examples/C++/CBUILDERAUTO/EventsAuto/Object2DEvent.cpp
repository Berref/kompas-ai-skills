////////////////////////////////////////////////////////////////////////////////
//
// Object2DEvent.cpp
// Object2DEvent - обработчик событий от документа (Auto)
//
////////////////////////////////////////////////////////////////////////////////

#include <vcl.h>
#pragma hdrstop

#include <ksConstants.h>

#ifndef _OBJECT2DEVENT_H
#include "Object2DEvent.h"
#endif

//-------------------------------------------------------------------------------
//
// ---
HRESULT Object2DEvent::InvokeEvent(DISPID id, BOOL & resEvent, TVariant *params)
{
  HRESULT hr = E_NOTIMPL;
  switch(id)
  {
    case koChangeActive   : // Переключение активности объекта( вид, слой)
      resEvent = ChangeActive( (long)params[0] );
      hr = S_OK;
      break;
    case koBeginDelete    : // Начало удаления объекта
      resEvent = BeginDelete( (long)params[0] );
      hr = S_OK;
      break;
    case koDelete         : // Удаление объекта
      resEvent = Delete( (long)params[0] );
      hr = S_OK;
      break;
    case koBeginMove      : // Начало сдвига объекта
      resEvent = BeginMove( (long)params[0] );
      hr = S_OK;
      break;
    case koMove           : // Сдвиг объекта
      resEvent = Move( (long)params[0] );
      hr = S_OK;
      break;
    case koBeginRotate    : // Начало поворота объекта
      resEvent = BeginRotate( (long)params[0] );
      hr = S_OK;
      break;
    case koRotate         : // Поворот объекта
      resEvent = Rotate( (long)params[0] );
      hr = S_OK;
      break;
    case koBeginScale     : // Начало масштабирования объекта
      resEvent = BeginScale( (long)params[0] );
      hr = S_OK;
      break;
    case koScale          : // Масштабирования объекта
      resEvent = Scale( (long)params[0] );
      hr = S_OK;
      break;
    case koBeginTransform : // Начало трансформации объекта
      resEvent = BeginTransform( (long)params[0] );
      hr = S_OK;
      break;
    case koTransform      : // Трансформация объекта
      resEvent = Transform( (long)params[0] );
      hr = S_OK;
      break;
    case koBeginCopy      : // Начало копирования объекта
      resEvent = BeginCopy( (long)params[0] );
      hr = S_OK;
      break;
    case koCopy           : // Копирование объекта
      resEvent = Copy( (long)params[0] );
      hr = S_OK;
      break;
    case koBeginSymmetry  : // Начало симметрии  объекта
      resEvent = BeginSymmetry( (long)params[0] );
      hr = S_OK;
      break;
    case koSymmetry       : // Симметрия  объекта
      resEvent = Symmetry( (long)params[0] );
      hr = S_OK;
      break;
    case koBeginProcess   : // Начало редактирования\создания объекта
      resEvent = BeginProcess( (long)params[0], (long)params[1] );
      hr = S_OK;
      break;
    case koEndProcess     : // Конец редактирования\создания объекта
      resEvent = EndProcess( (long)params[0] );
      hr = S_OK;
      break;
    case koCreateObject   : // Создание объекта
      resEvent = CreateObject( (long)params[0] );
      hr = S_OK;
      break;
    case koUpdateObject   : // Редактирование объекта
      resEvent = UpdateObject( (long)params[0] );
      hr = S_OK;
      break;
  }
  return hr;
}


//-------------------------------------------------------------------------------
// Переключение активности объекта( вид, слой )
// ---
BOOL Object2DEvent::ChangeActive( long objRef )
{
  LibMessage( _T("Object2DEvent - Переключение активности объекта( вид, слой )") );
  return TRUE;
}


//-------------------------------------------------------------------------------
// Начало удаления объекта
// ---
BOOL Object2DEvent::BeginDelete( long objRef )
{
  return LibMessage( _T("Object2DEvent - Начало удаления объекта\nУдалить объект?"), MB_YESNO ) == IDYES;
}


//-------------------------------------------------------------------------------
// Удаление объекта
// ---
BOOL Object2DEvent::Delete( long objRef )
{
  LibMessage( _T("Object2DEvent - Удаление объекта") );
  return TRUE;
}


//-------------------------------------------------------------------------------
// Начало сдвига объекта
// ---
BOOL Object2DEvent::BeginMove( long objRef )
{
  return LibMessage( _T("Object2DEvent - Начало сдвига объекта\nПереместить объект?"), MB_YESNO ) == IDYES;;
}


//-------------------------------------------------------------------------------
// Сдвиг объекта
// ---
BOOL Object2DEvent::Move( long objRef )
{
  LibMessage( _T("Object2DEvent - Сдвиг объекта") );
  return TRUE;
}


//-------------------------------------------------------------------------------
// Начало поворота объекта
// ---
BOOL Object2DEvent::BeginRotate( long objRef )
{
   return LibMessage( _T("Object2DEvent - Начало поворота объекта\nПовернуть объект?"), MB_YESNO ) == IDYES;
}


//-------------------------------------------------------------------------------
// Поворот объекта
// ---
BOOL Object2DEvent::Rotate( long objRef )
{
  LibMessage( _T("Object2DEvent - Поворот объекта") );
  return TRUE;
}


//-------------------------------------------------------------------------------
// Начало масштабирования объекта
// ---
BOOL Object2DEvent::BeginScale( long objRef )
{
  return LibMessage( _T("Object2DEvent - Начало масштабирования объекта\nМасштабировать объект?"), MB_YESNO ) == IDYES;
}


//-------------------------------------------------------------------------------
// Масштабирования объекта
// ---
BOOL Object2DEvent::Scale( long objRef )
{
  LibMessage( _T("Object2DEvent - Масштабирования объекта") );
  return TRUE;
}


//-------------------------------------------------------------------------------
// Начало трансформации объекта
// ---
BOOL Object2DEvent::BeginTransform( long objRef )
{
	return LibMessage( _T("Object2DEvent - Начало трансформации объекта\nТрансформировать объект?"), MB_YESNO ) == IDYES;
}


//-------------------------------------------------------------------------------
// Трансформация объекта
// ---
BOOL Object2DEvent::Transform( long objRef )
{
  LibMessage( _T("Object2DEvent - Трансформация объекта") );
  return TRUE;
}


//-------------------------------------------------------------------------------
// Начало копирования объекта
// ---
BOOL Object2DEvent::BeginCopy( long objRef )
{
  return LibMessage( _T("Object2DEvent - Начало копирования объекта\nКопировать объект?"), MB_YESNO ) == IDYES;
}


//-------------------------------------------------------------------------------
// Копирование объекта
// ---
BOOL Object2DEvent::Copy( long objRef )
{
  LibMessage( _T("Object2DEvent - Копирование объекта") );
  return TRUE;
}


//-------------------------------------------------------------------------------
// Начало симметрии объекта
// ---
BOOL Object2DEvent::BeginSymmetry( long objRef )
{
  return LibMessage( _T("Object2DEvent - Начало создания симметрии объекта\nСоздать симметрию объекта?"), MB_YESNO ) == IDYES;
}


//-------------------------------------------------------------------------------
// Симметрия  объекта
// ---
BOOL Object2DEvent::Symmetry( long objRef )
{
  LibMessage( _T("Object2DEvent - Симметрия  объекта") );
  return TRUE;
}


//-------------------------------------------------------------------------------
// Начало редактирования\создания объекта
// ---
BOOL Object2DEvent::BeginProcess( long pType, long objRef )
{
	return LibMessage( _T("Object2DEvent - Начало редактирования\\создания объекта\nПродолжить?"), MB_YESNO ) == IDYES;
}


//-------------------------------------------------------------------------------
// Конец редактирования\создания объекта
// ---
BOOL Object2DEvent::EndProcess( long objRef )
{
	LibMessage( _T("Object2DEvent - Конец редактирования\\создания объекта") );
  return TRUE;
}


//-------------------------------------------------------------------------------
// Создание объекта
// ---
BOOL Object2DEvent::CreateObject( long objRef )
{
  LibMessage( _T("Object2DEvent - Создание объекта") );
  return TRUE;
}


//-------------------------------------------------------------------------------
// Редактирование объекта
// ---
BOOL Object2DEvent::UpdateObject( long objRef )
{
  LibMessage( _T("Object2DEvent - Редактирование объекта") );
  return TRUE;
}

