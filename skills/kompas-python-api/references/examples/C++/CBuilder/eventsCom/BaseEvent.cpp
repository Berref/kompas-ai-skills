////////////////////////////////////////////////////////////////////////////////
//
// BaseEvent.cpp
// Базовый класс для обработчиков событий (COM)
//
////////////////////////////////////////////////////////////////////////////////

#include <vcl.h>
#pragma hdrstop

#ifndef _BASEEVENT_H
#include "BaseEvent.h"
#endif
       
//---------------------------------------------------------------------------
// Список обработчиков событий
// ---
TList * EventListObject::m_pEventList = NULL;


//---------------------------------------------------------------------------
// Отписать все события
// Вызывается по выходу из библиотеки
// ---
void EventListObject::TerminateEvents()
{
  while( m_pEventList )
  {
    EventListObject * pEventListing = (EventListObject*)m_pEventList->First();
    delete pEventListing; // В деструкторе будет удален из списка и будет удален сам список
 	}
}


//-------------------------------------------------------------------------------
// Класс счетчик - добавить себя в список, если списка не было,
// то нада его создать
// ---
EventListObject::EventListObject()
{
  if( !m_pEventList )
    m_pEventList = new TList();
  if( m_pEventList )
    m_pEventList->Add( this );
}


//-------------------------------------------------------------------------------
// Класс счетчик - удалить себя из списока, если элемент последний,
// то удалить сам список
// ---
EventListObject::~EventListObject()
{
  if( m_pEventList )
  {
    m_pEventList->Remove( this );
    if( !m_pEventList->Count )
    {
      delete m_pEventList;
      m_pEventList = NULL;
    }
  }
}

//-------------------------------------------------------------------------------
// Конструктор с подключением к серверу сообщений
// ---
BaseEvent::BaseEvent( int ifType, reference container, reference objType,  reference doc  ) :
  m_Advise( false ),
  refDoc( doc )
{
  memset( &m_Params, 0, sizeof( m_Params ) );
  m_Params.pContainer = container;
  m_Params.ifType     = ifType;
  m_Params.objType    = objType;
}

BaseEvent::~BaseEvent()
{
  Unadvise();
  if ( m_Params.iContainer )        // Освободить контейнер
  {
    m_Params.iContainer->Release();
    m_Params.iContainer = NULL;
  }
}

//-------------------------------------------------------------------------------
// Подключение к серверу сообщений
// ---
bool BaseEvent::Advise()
{
  if( !m_Advise && m_Params.ifType ) {
    LPUNKNOWN obj = GetUnknown();
    m_Advise = !!::ksConnectionAdvise( &m_Params, obj );
    obj->Release();
  }
  return m_Advise;
}


//-------------------------------------------------------------------------------
// Отключение от сервера сообщений
// ---
void BaseEvent::Unadvise()
{
  if( m_Advise ) {
    ::ksConnectionUnadvise( &m_Params );
    m_Advise = false;
  }
}

void BaseEvent::TerminateEvents( long eventType, reference doc, int objType, LPUNKNOWN iObj ) {
  if ( !eventType && !doc )
		EventListObject::TerminateEvents();
	else {
  	for ( int i = m_pEventList->Count - 1; i >= 0; i-- ) {
	  	BaseEvent* evnt = (BaseEvent*)m_pEventList->Items[i];
			if ( evnt && ( !eventType    || eventType == evnt->m_Params.ifType  )
				        && ( !doc          || doc       == evnt->refDoc           )
								&& ( objType == -1 || objType   == evnt->m_Params.objType )
								&& ( !iObj         || iObj      == evnt->m_Params.iObj    ) ) {

		    evnt->Disconnect();			// в деструкторе будет удален из списка RemoveAt(pos)
      }
		}
	}
}

void BaseEvent::Disconnect()
{
  Unadvise();
  Clear();
  __Release();
}

void BaseEvent::Clear()
{
  if ( m_Params.iContainer )        // Освободить контейнер
  {
    m_Params.iContainer->Release();
    m_Params.iContainer = NULL;
  }
}

BaseEvent* BaseEvent::FindEvents( long eventType, reference doc, int objType, LPUNKNOWN iObj ) {
	BaseEvent* res = NULL;
	for ( int i = m_pEventList->Count - 1; i >= 0; i-- ) {
	  BaseEvent* evnt = (BaseEvent*) m_pEventList->Items[i];
		if (    (   !eventType                                 ||   eventType == evnt->GetType()        )
			   && ( ( !doc          && !evnt->refDoc           ) || ( doc       == evnt->refDoc           ) )
			   && ( ( objType == -1 && !evnt->m_Params.objType ) || ( objType   == evnt->m_Params.objType ) )
			   && ( ( !iObj         && !evnt->m_Params.iObj    ) || ( iObj      == evnt->m_Params.iObj    ) ) ) {
		  res = evnt;			// в деструкторе будет удален из списка RemoveAt(pos)
      break;
		}
	}
	return res;
}

