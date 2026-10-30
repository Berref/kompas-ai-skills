////////////////////////////////////////////////////////////////////////////////
//
// SpcDocumentEvent  - обрабокчик событий от документа спецификации
//
////////////////////////////////////////////////////////////////////////////////
#ifndef _SPCDOCUMENTEVENT_H
#define _SPCDOCUMENTEVENT_H

#ifndef _BASEEVENT_H
#include "baseEvent.h"
#endif

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000     

/*
enum ksSpcDocumentNotifyEnum
{
  sdDocumentBeginAdd = 1,
  sdDocumentAdd = 2,
  sdDocumentBeginRemove = 3,
  sdDocumentRemove = 4,
  sdSpcStyleBeginChange = 5,
  sdSpcStyleChange = 6
};
*/

////////////////////////////////////////////////////////////////////////////////
//
// SpcDocumentEvent  - обрабокчик событий от документа спецификации
// 
////////////////////////////////////////////////////////////////////////////////
class SpcDocumentEvent : public BaseEvent
{
public:
  SpcDocumentEvent( LPUNKNOWN pObject, 
                    LPDISPATCH doc, 
                    bool m_selfAdvise = true );           
  virtual ~SpcDocumentEvent();

protected:
  // sdDocumentBeginAdd - Начало добавления документа сборочного чертежа
  afx_msg VARIANT_BOOL DocumentBeginAdd();
  // sdDocumentAdd - Добавление документа сборочного чертежа
  afx_msg VARIANT_BOOL DocumentAdd( LPCTSTR docName );
  // sdDocumentBeginRemove - Начало удаления документа сборочного чертежа
  afx_msg VARIANT_BOOL DocumentBeginRemove( LPCTSTR docName);
  // sdDocumentRemove - Удаление документа сборочного чертежа
  afx_msg VARIANT_BOOL DocumentRemove( LPCTSTR docName );
  // sdSpcStyleBeginChange - Начало изменения стиля спецификации
  afx_msg VARIANT_BOOL SpcStyleBeginChange( LPCTSTR libName, long numb );
  // sdSpcStyleChange - Стиль спецификации изменился
  afx_msg VARIANT_BOOL SpcStyleChange( LPCTSTR libName, long numb );

  DECLARE_EVENTSINK_MAP()
};

/////////////////////////////////////////////////////////////////////////////

#endif 
