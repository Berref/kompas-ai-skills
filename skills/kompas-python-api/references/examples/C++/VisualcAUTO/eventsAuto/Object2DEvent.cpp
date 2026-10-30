////////////////////////////////////////////////////////////////////////////////
//
// Object2DEvent - обработчик событий объектов 2D документа
//
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "eventsAuto.h"

#ifndef _OBJECT2DEVENT_H
#include "Object2DEvent.h"
#endif
/*
#ifndef __LDEFIN2D_H
#include <ldefin2d.h>
#endif
*/
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

////////////////////////////////////////////////////////////////////////////////
//
// Object2DEvent - обработчик событий объектов 2D документа
//
////////////////////////////////////////////////////////////////////////////////

//-------------------------------------------------------------------------------
//
// ---
Object2DEvent::Object2DEvent( LPUNKNOWN object, 
                              LPDISPATCH doc, 
                              long objType,
                              ksObject2DNotifyResultPtr res, 
                              bool selfAdvise /*true*/ )
  : BaseEvent( object, DIID_ksObject2DNotify, doc, objType, NULL, selfAdvise ),
    m_res( res )
{
}


//-------------------------------------------------------------------------------
//
// ---
Object2DEvent::~Object2DEvent()
{
}
 
//-------------------------------------------------------------------------------
//
// ---
BEGIN_EVENTSINK_MAP(Object2DEvent, BaseEvent)
  ON_EVENT (Object2DEvent, (unsigned int)-1, koChangeActive,        ChangeActive,         VTS_I4)
  ON_EVENT (Object2DEvent, (unsigned int)-1, koBeginDelete,         BeginDelete,          VTS_I4)
  ON_EVENT (Object2DEvent, (unsigned int)-1, koDelete,              Delete,               VTS_I4)
  ON_EVENT (Object2DEvent, (unsigned int)-1, koBeginMove,           BeginMove,            VTS_I4)
  ON_EVENT (Object2DEvent, (unsigned int)-1, koMove,                Move,                 VTS_I4)
  ON_EVENT (Object2DEvent, (unsigned int)-1, koBeginRotate,         BeginRotate,          VTS_I4)
  ON_EVENT (Object2DEvent, (unsigned int)-1, koRotate,              Rotate,               VTS_I4)
  ON_EVENT (Object2DEvent, (unsigned int)-1, koBeginScale,          BeginScale,           VTS_I4)
  ON_EVENT (Object2DEvent, (unsigned int)-1, koScale,               Scale,                VTS_I4)
                                                                                          
  ON_EVENT (Object2DEvent, (unsigned int)-1, koBeginTransform,      BeginTransform,       VTS_I4)
  ON_EVENT (Object2DEvent, (unsigned int)-1, koTransform,           Transform,            VTS_I4)
  ON_EVENT (Object2DEvent, (unsigned int)-1, koBeginCopy,           BeginCopy,            VTS_I4)
  ON_EVENT (Object2DEvent, (unsigned int)-1, koCopy,                Copy,                 VTS_I4)
  ON_EVENT (Object2DEvent, (unsigned int)-1, koBeginSymmetry,       BeginSymmetry,        VTS_I4)
  ON_EVENT (Object2DEvent, (unsigned int)-1, koSymmetry,            Symmetry,             VTS_I4)
                                                                                          
  ON_EVENT (Object2DEvent, (unsigned int)-1, koBeginProcess,        BeginProcess,         VTS_I4 VTS_I4)
  ON_EVENT (Object2DEvent, (unsigned int)-1, koEndProcess,          EndProcess,           VTS_I4)
                                                                                          
  ON_EVENT (Object2DEvent, (unsigned int)-1, koCreateObject,        CreateObject,         VTS_I4)
  ON_EVENT (Object2DEvent, (unsigned int)-1, koUpdateObject,        UpdateObject,         VTS_I4)
                                                                                          
  ON_EVENT (Object2DEvent, (unsigned int)-1, koBeginDestroyObject,  BeginDestroyObject,   VTS_I4)
  ON_EVENT (Object2DEvent, (unsigned int)-1, koDestroyObject,       DestroyObject,        VTS_I4)

  ON_EVENT( Object2DEvent, (unsigned int)-1, koBeginPropertyChanged,BeginPropertyChanged, VTS_I4 )
  ON_EVENT( Object2DEvent, (unsigned int)-1, koPropertyChanged,     PropertyChanged,      VTS_I4 )

END_EVENTSINK_MAP()


//-------------------------------------------------------------------------------
// 
// ---
CString Object2DEvent::OutRes()
{
  CString str;
  if ( m_res )
  {
    long notifyType = m_res->GetNotifyType();
    double angle = m_res->GetAngle();
    long copyObject = m_res->GetCopyObject();
    double sx = -1, sy = -1;
    m_res->GetScale( &sx, &sy );
    double x = -1, y = -1, x1 = -1, y1 = -1;
    m_res->GetSheetPoint( 0, &x, &y );
    m_res->GetSheetPoint( 1, &x1, &y1 );
    long copy = m_res->IsCopy();
    str.Format( _T("Object2DNotifyResult: GetNotifyType=%i,\nGetAngle=%f, GetCopyObject=%i,\nGetScale( %f, %f ),\nGetSheetPoint( 1, %f, %f ),\nGetSheetPoint( 0, %f, %f ),\nIsCopy=%i"), 
                notifyType,
                angle, 
                copyObject,               
                sx, sy,
                x1, y1,     
                x, y,
                copy );
  }
  return str;
}


//-------------------------------------------------------------------------------
// kdChangeActive - Переключение вида/слоя в текущий
// ---
VARIANT_BOOL Object2DEvent::ChangeActive( long viewRef )
{
  if ( IsSelfAdvise() && theApp.m_mes_OBJ_2DDOC )
  {
    ksDocument2DPtr doc2D( m_doc );
    if( doc2D != NULL && viewRef ) 
      doc2D->ksLightObj( viewRef, true );

    CString str;
    str.Format( _T("%s --> Object2DEvent::ChangeActive\nviewRef = %i\n"), (LPCTSTR)m_libName, viewRef );
    str += OutRes();
    str += _T("\nИмя документа = ") + GetDocName();
    CString strType;
    strType.Format( _T("\nТип/указатель объекта = %i"), m_objType );
    str += strType;
    kompas->ksMessage( (LPCTSTR)str );

    if( doc2D != NULL && viewRef ) 
      doc2D->ksLightObj( viewRef, false );
  }
  return true;
}


//-------------------------------------------------------------------------------
// koBeginDelete - Попытка удаления объекта
// ---
VARIANT_BOOL Object2DEvent::BeginDelete( long objRef )
{
  bool res = true;
  if ( IsSelfAdvise() && theApp.m_mes_OBJ_2DDOC )
  {
    ksDocument2DPtr doc2D( m_doc );
    if( doc2D != NULL && objRef ) 
      doc2D->ksLightObj( objRef, true );

    CString str;
    str.Format( _T("%s --> Object2DEvent::BeginDelete\nobjRef = %i\n"), (LPCTSTR)m_libName, objRef );
    str += OutRes();
    str += _T("\nИмя документа = ") + GetDocName();
    CString strType;
    strType.Format( _T("\nТип/указатель объекта = %i"), m_objType );
    str += strType;                    
    res = !!kompas->ksYesNo( (LPCTSTR)str ); 

    if( doc2D != NULL && objRef ) 
      doc2D->ksLightObj( objRef, false );
  }
  return res;
}


//-------------------------------------------------------------------------------
// koDelete - Объект удален
// ---
VARIANT_BOOL Object2DEvent::Delete( long objRef )
{
  if ( IsSelfAdvise() && theApp.m_mes_OBJ_2DDOC )
  {
    ksDocument2DPtr doc2D( m_doc );
    if( doc2D != NULL && objRef ) 
      doc2D->ksLightObj( objRef, true );

    CString str;
    str.Format( _T("%s --> Object2DEvent::Delete\nobjRef = %i\n"), (LPCTSTR)m_libName, objRef );
    str += OutRes();
    str += _T("\nИмя документа = ") + GetDocName();
    CString strType;
    strType.Format( _T("\nТип/указатель объекта = %i"), m_objType );
    str += strType;
    kompas->ksMessage( (LPCTSTR)str );

    if( doc2D != NULL && objRef ) 
      doc2D->ksLightObj( objRef, false );
  }
  // Если удаляется объект удаляем и подписку на его события
  // Либо тип объекта : ALL_OBJ...AXISLINE_OBJ, VIEW_OBJ, либо указатель на объект
  if ( objRef && objRef == m_objType )
    delete this; 
  return true;
}
       

//-------------------------------------------------------------------------------
// koBeginMove - Начало смещения объекта
// ---
VARIANT_BOOL Object2DEvent::BeginMove( long objRef )
{
  bool res = true;
  if ( IsSelfAdvise() && theApp.m_mes_OBJ_2DDOC )
  {
    ksDocument2DPtr doc2D( m_doc );
    if( doc2D != NULL && objRef) 
      doc2D->ksLightObj( objRef, true );

    CString str;
    str.Format( _T("%s --> Object2DEvent::BeginMove\nobjRef = %i\n"), (LPCTSTR)m_libName, objRef );
    str += OutRes();
    str += _T("\nИмя документа = ") + GetDocName();
    CString strType;
    strType.Format( _T("\nТип/указатель объекта = %i"), m_objType );
    str += strType;
    res = !!kompas->ksYesNo( (LPCTSTR)str ); 

    if( doc2D != NULL && objRef) 
      doc2D->ksLightObj( objRef, false );
  }
  return res;
}


//-------------------------------------------------------------------------------
// koMove - Объект смещен
// ---
VARIANT_BOOL Object2DEvent::Move( long objRef )
{
  if ( IsSelfAdvise() && theApp.m_mes_OBJ_2DDOC )
  {
    ksDocument2DPtr doc2D( m_doc );
    if( doc2D != NULL && objRef) 
      doc2D->ksLightObj( objRef, true );

    CString str;
    str.Format( _T("%s --> Object2DEvent::Move\nobjRef = %i\n"), (LPCTSTR)m_libName, objRef );
    str += OutRes();
    str += _T("\nИмя документа = ") + GetDocName();
    CString strType;
    strType.Format( _T("\nТип/указатель объекта = %i"), m_objType );
    str += strType;
    kompas->ksMessage( (LPCTSTR)str );

    if( doc2D != NULL && objRef) 
      doc2D->ksLightObj( objRef, false );
  }
  return true;
}

//-------------------------------------------------------------------------------
// koBeginRotate - Поворот объекта
// ---
VARIANT_BOOL Object2DEvent::BeginRotate( long objRef )
{
  bool res = true;
  if ( IsSelfAdvise() && theApp.m_mes_OBJ_2DDOC )
  {
    ksDocument2DPtr doc2D( m_doc );
    if( doc2D != NULL && objRef) 
      doc2D->ksLightObj( objRef, true );

    CString str;
    str.Format( _T("%s --> Object2DEvent::BeginRotate\nobjRef = %i\n"), (LPCTSTR)m_libName, objRef );
    str += OutRes();
    str += _T("\nИмя документа = ") + GetDocName();
    CString strType;
    strType.Format( _T("\nТип/указатель объекта = %i"), m_objType );
    str += strType;
    res = !!kompas->ksYesNo( (LPCTSTR)str ); 

    if( doc2D != NULL && objRef) 
      doc2D->ksLightObj( objRef, false );
  }
  return res;
}


//-------------------------------------------------------------------------------
// koRotate - Поворот объекта
// ---
VARIANT_BOOL Object2DEvent::Rotate( long objRef )
{
  if ( IsSelfAdvise() && theApp.m_mes_OBJ_2DDOC )
  {
    ksDocument2DPtr doc2D( m_doc );
    if( doc2D != NULL && objRef) 
      doc2D->ksLightObj( objRef, true );

    CString str;
    str.Format( _T("%s --> Object2DEvent::Rotate\nobjRef = %i\n"), (LPCTSTR)m_libName, objRef );
    str += OutRes();
    str += _T("\nИмя документа = ") + GetDocName();
    CString strType;
    strType.Format( _T("\nТип/указатель объекта = %i"), m_objType );
    str += strType;
    kompas->ksMessage( (LPCTSTR)str );

    if( doc2D != NULL && objRef) 
      doc2D->ksLightObj( objRef, false );
  }
  return true;
}

//-------------------------------------------------------------------------------
// koBeginScale - Маштабирование объекта
// ---
VARIANT_BOOL Object2DEvent::BeginScale( long objRef )
{
  bool res = true;
  if ( IsSelfAdvise() && theApp.m_mes_OBJ_2DDOC )
  {
    ksDocument2DPtr doc2D( m_doc );
    if( doc2D != NULL && objRef) 
      doc2D->ksLightObj( objRef, true );

    CString str;
    str.Format( _T("%s --> Object2DEvent::BeginScale\nobjRef = %i\n"), (LPCTSTR)m_libName, objRef );
    str += OutRes();
    str += _T("\nИмя документа = ") + GetDocName();
    CString strType;
    strType.Format( _T("\nТип объекта/указатель = %i"), m_objType );
    str += strType;
    res = !!kompas->ksYesNo( (LPCTSTR)str ); 

    if( doc2D != NULL && objRef) 
      doc2D->ksLightObj( objRef, false );
  }
  return res;
}


//-------------------------------------------------------------------------------
// koScale - Маштабирование объекта
// ---
VARIANT_BOOL Object2DEvent::Scale( long objRef )
{
  if ( IsSelfAdvise() && theApp.m_mes_OBJ_2DDOC )
  {
    ksDocument2DPtr doc2D( m_doc );
    if( doc2D != NULL && objRef) 
      doc2D->ksLightObj( objRef, true );

    CString str;
    str.Format( _T("%s --> Object2DEvent::Scale\nobjRef = %i\n"), (LPCTSTR)m_libName, objRef );
    str += OutRes();
    str += _T("\nИмя документа = ") + GetDocName();
    CString strType;
    strType.Format( _T("\nТип объекта/указатель = %i"), m_objType );
    str += strType;
    kompas->ksMessage( (LPCTSTR)str );

    if( doc2D != NULL && objRef) 
      doc2D->ksLightObj( objRef, false );
  }
  return true;
}

//-------------------------------------------------------------------------------
// koBeginTransform - Трансформация объекта
// ---
VARIANT_BOOL Object2DEvent::BeginTransform( long objRef )
{
  bool res = true;
  if ( IsSelfAdvise() && theApp.m_mes_OBJ_2DDOC )
  {    
    ksDocument2DPtr doc2D( m_doc );
    if( doc2D != NULL && objRef) 
      doc2D->ksLightObj( objRef, true );

    CString str;
    str.Format( _T("%s --> Object2DEvent::BeginTransform\nobjRef = %i\n"), (LPCTSTR)m_libName, objRef );
    str += OutRes();
    str += _T("\nИмя документа = ") + GetDocName();
    CString strType;
    strType.Format( _T("\nТип объекта/указатель = %i"), m_objType );
    str += strType;
    res = !!kompas->ksYesNo( (LPCTSTR)str ); 

    if( doc2D != NULL && objRef) 
      doc2D->ksLightObj( objRef, false );
  }
  return res;
}


//-------------------------------------------------------------------------------
// koTransform - Трансформация объекта
// ---
VARIANT_BOOL Object2DEvent::Transform( long objRef )
{
  if ( IsSelfAdvise() && theApp.m_mes_OBJ_2DDOC )
  {
    ksDocument2DPtr doc2D( m_doc );
    if( doc2D != NULL && objRef) 
      doc2D->ksLightObj( objRef, true );

    CString str;
    str.Format( _T("%s --> Object2DEvent::Transform\nobjRef = %i\n"), (LPCTSTR)m_libName, objRef );
    str += OutRes();
    str += _T("\nИмя документа = ") + GetDocName();
    CString strType;
    strType.Format( _T("\nТип объекта/указатель = %i"), m_objType );
    str += strType;
    kompas->ksMessage( (LPCTSTR)str );

    if( doc2D != NULL && objRef) 
      doc2D->ksLightObj( objRef, false );
  }
  return true;
}

//-------------------------------------------------------------------------------
// koBeginCopy - Копирование объекта
// ---
VARIANT_BOOL Object2DEvent::BeginCopy( long objRef )
{
  bool res = true;
  if ( IsSelfAdvise() && theApp.m_mes_OBJ_2DDOC )
  {
    ksDocument2DPtr doc2D( m_doc );
    if( doc2D != NULL && objRef) 
      doc2D->ksLightObj( objRef, true );

    CString str;
    str.Format( _T("%s --> Object2DEvent::BeginCopy\nobjRef = %i\n"), (LPCTSTR)m_libName, objRef );
    str += OutRes();
    str += _T("\nИмя документа = ") + GetDocName();
    CString strType;
    strType.Format( _T("\nТип объекта/указатель = %i"), m_objType );
    str += strType;
    res = !!kompas->ksYesNo( (LPCTSTR)str ); 

    if( doc2D != NULL && objRef) 
      doc2D->ksLightObj( objRef, false );
  }
  return res;
}


//-------------------------------------------------------------------------------
// koCopy - Копирование объекта
// ---
VARIANT_BOOL Object2DEvent::Copy( long objRef )
{
  if ( IsSelfAdvise() && theApp.m_mes_OBJ_2DDOC )
  {
    ksDocument2DPtr doc2D( m_doc );
    if( doc2D != NULL && objRef) 
      doc2D->ksLightObj( objRef, true );

    CString str;
    str.Format( _T("%s --> Object2DEvent::Copy\nobjRef = %i\n"), (LPCTSTR)m_libName, objRef );
    str += _T("\nИмя документа = ") + GetDocName();
    CString strType;
    strType.Format( _T("\nТип объекта/указатель = %i"), m_objType );
    str += strType;
    kompas->ksMessage( (LPCTSTR)str );

    if( doc2D != NULL && objRef) 
      doc2D->ksLightObj( objRef, false );
  }
  return true;
}

//-------------------------------------------------------------------------------
// koBeginSymmetry - Симметрия объекта
// ---
VARIANT_BOOL Object2DEvent::BeginSymmetry( long objRef )
{
  bool res = true;
  if ( IsSelfAdvise() && theApp.m_mes_OBJ_2DDOC )
  {
    ksDocument2DPtr doc2D( m_doc );
    if( doc2D != NULL && objRef) 
      doc2D->ksLightObj( objRef, true );

    CString str;
    str.Format( _T("%s --> Object2DEvent::BeginSymmetry\nobjRef = %i\n"), (LPCTSTR)m_libName, objRef );
    str += OutRes();
    str += _T("\nИмя документа = ") + GetDocName();
    CString strType;
    strType.Format( _T("\nТип объекта/указатель = %i"), m_objType );
    str += strType;
    res = !!kompas->ksYesNo( (LPCTSTR)str );
    
    if( doc2D != NULL && objRef) 
      doc2D->ksLightObj( objRef, false );
  }
  return res;
}


//-------------------------------------------------------------------------------
// koSymmetry - Симметрия объекта
// ---
VARIANT_BOOL Object2DEvent::Symmetry( long objRef )
{
  if ( IsSelfAdvise() && theApp.m_mes_OBJ_2DDOC )
  {
    ksDocument2DPtr doc2D( m_doc );
    if( doc2D != NULL && objRef) 
      doc2D->ksLightObj( objRef, true );

    CString str;
    str.Format( _T("%s --> Object2DEvent::Symmetry\nobjRef = %i\n"), (LPCTSTR)m_libName, objRef );
    str += OutRes();
    str += _T("\nИмя документа = ") + GetDocName();
    CString strType;
    strType.Format( _T("\nТип объекта/указатель = %i"), m_objType );
    str += strType;
    kompas->ksMessage( (LPCTSTR)str );

    if( doc2D != NULL && objRef) 
      doc2D->ksLightObj( objRef, false );
  }
  return true;
}


//-------------------------------------------------------------------------------
// koBeginProcess - Начало редактирования\создания объекта
// ---
VARIANT_BOOL Object2DEvent::BeginProcess( long pType, long objRef )
{
  bool res = true;
  if ( IsSelfAdvise() && theApp.m_mes_OBJ_2DDOC )
  {
    ksDocument2DPtr doc2D( m_doc );
    if( doc2D != NULL && objRef) 
      doc2D->ksLightObj( objRef, true );

    CString str;
    str.Format( _T("%s --> Object2DEvent::BeginProcess\npType = %i\nobjRef = %i\n"), (LPCTSTR)m_libName, pType, objRef ); 
    str += OutRes();
    str += _T("\nИмя документа = ") + GetDocName();
    CString strType;
    strType.Format( _T("\nТип объекта/указатель = %i"), m_objType );
    str += strType;
    res = !!kompas->ksYesNo( (LPCTSTR)str ); 

    if( doc2D != NULL && objRef) 
      doc2D->ksLightObj( objRef, false );
  }
  return res;
}
     

//-------------------------------------------------------------------------------
// koEndProcess - Конец редактирования\создания объекта
// ---
VARIANT_BOOL Object2DEvent::EndProcess( long pType )
{
  if ( IsSelfAdvise() && theApp.m_mes_OBJ_2DDOC )
  {
    ksDocument2DPtr doc2D( m_doc );
    CString str;
    str.Format( _T("%s --> Object2DEvent::EndProcess\npType = %i\n"), (LPCTSTR)m_libName, pType ); 
    str += OutRes();
    str += _T("\nИмя документа = ") + GetDocName();
    CString strType;
    strType.Format( _T("\nТип объекта/указатель = %i"), m_objType );
    str += strType;
    kompas->ksMessage( (LPCTSTR)str );
  }
  return true;
}

//-------------------------------------------------------------------------------
// koCreate - Создание объектов
// ---
VARIANT_BOOL Object2DEvent::CreateObject( long objRef )
{
  if ( IsSelfAdvise() && theApp.m_mes_OBJ_2DDOC )
  {
    ksDocument2DPtr doc2D( m_doc );
    if( doc2D != NULL && objRef) 
      doc2D->ksLightObj( objRef, true );

    CString str;
    str.Format( _T("%s --> Object2DEvent::CreateObject\nobjRef = %i\n"), (LPCTSTR)m_libName, objRef ); 
    str += OutRes();
    str += _T("\nИмя документа = ") + GetDocName();
    CString strType;
    strType.Format( _T("\nТип объекта/указатель = %i"), m_objType );
    str += strType;
    kompas->ksMessage( (LPCTSTR)str );

    if( doc2D != NULL && objRef) 
      doc2D->ksLightObj( objRef, false );
  }  
  return true;
}

    
//-------------------------------------------------------------------------------
// koUpdateObject - Редактирование объекта
// ---
VARIANT_BOOL Object2DEvent::UpdateObject( long objRef )
{
  if ( IsSelfAdvise() && theApp.m_mes_OBJ_2DDOC )
  {
    ksDocument2DPtr doc2D( m_doc );
    if( doc2D != NULL && objRef) 
      doc2D->ksLightObj( objRef, true );

    CString str;
    str.Format( _T("%s --> Object2DEvent::UpdateObject\nobjRef = %i\n"), (LPCTSTR)m_libName, objRef ); 
    str += OutRes();
    str += _T("\nИмя документа = ") + GetDocName();
    CString strType;
    strType.Format( _T("\nТип объекта/указатель = %i"), m_objType );
    str += strType;
    kompas->ksMessage( (LPCTSTR)str );

    if( doc2D != NULL && objRef) 
      doc2D->ksLightObj( objRef, false );
  }
  return true;
}

//-------------------------------------------------------------------------------
// koBeginDestroyObject - Начало разрушения объекта
// ---
VARIANT_BOOL Object2DEvent::BeginDestroyObject( long objRef )
{
  bool res = true;
  if ( IsSelfAdvise() && theApp.m_mes_OBJ_2DDOC )
  {
    ksDocument2DPtr doc2D( m_doc );
    if ( doc2D != NULL && objRef )
      doc2D->ksLightObj( objRef, true );

    CString str;
    str.Format( _T( "%s --> Object2DEvent::BeginDestroyObject\nobjRef = %i\n" ), (LPCTSTR)m_libName, objRef );
    str += OutRes();
    str += _T( "\nИмя документа = " ) + GetDocName();
    CString strType;
    strType.Format( _T( "\nТип/указатель объекта = %i" ), m_objType );
    str += strType;
    res = !!kompas->ksYesNo( (LPCTSTR)str );

    if ( doc2D != NULL && objRef )
      doc2D->ksLightObj( objRef, false );
  }
  return res;
}

//-------------------------------------------------------------------------------
// koUpdateObject - Разрушение объекта
// ---
VARIANT_BOOL Object2DEvent::DestroyObject( long objRef )
{
  if ( IsSelfAdvise() && theApp.m_mes_OBJ_2DDOC )
  {
    ksDocument2DPtr doc2D( m_doc );
    if ( doc2D != NULL && objRef )
      doc2D->ksLightObj( objRef, true );

    CString str;
    str.Format( _T( "%s --> Object2DEvent::DestroyObject\nobjRef = %i\n" ), (LPCTSTR)m_libName, objRef );
    str += OutRes();
    str += _T( "\nИмя документа = " ) + GetDocName();
    CString strType;
    strType.Format( _T( "\nТип/указатель объекта = %i" ), m_objType );
    str += strType;
    kompas->ksMessage( (LPCTSTR)str );

    if ( doc2D != NULL && objRef )
      doc2D->ksLightObj( objRef, false );
  }
  // Если разрушается объект удаляем и подписку на его события
  // Либо тип объекта : ALL_OBJ...AXISLINE_OBJ, VIEW_OBJ, либо указатель на объект
  if ( objRef && objRef == m_objType )
    delete this;
  return true;
}

//-------------------------------------------------------------------------------
// koUpdateObject - Начало изменения свойств объекта
// ---
VARIANT_BOOL Object2DEvent::BeginPropertyChanged( long objRef )
{
  bool res = true;
  if ( IsSelfAdvise() && theApp.m_mes_OBJ_2DDOC )
  {
    ksDocument2DPtr doc2D( m_doc );
    if ( doc2D != NULL && objRef )
      doc2D->ksLightObj( objRef, true );

    CString str;
    str.Format( _T( "%s --> Object2DEvent::BeginPropertyChanged\nobjRef = %i\n" ), (LPCTSTR)m_libName, objRef );
    str += OutRes();
    str += _T( "\nИмя документа = " ) + GetDocName();
    CString strType;
    strType.Format( _T( "\nТип/указатель объекта = %i" ), m_objType );
    str += strType;
    res = !!kompas->ksYesNo( (LPCTSTR)str );

    if ( doc2D != NULL && objRef )
      doc2D->ksLightObj( objRef, false );
  }
  return res;
}

//-------------------------------------------------------------------------------
// koUpdateObject - Изменены свойства объета
// ---
VARIANT_BOOL Object2DEvent::PropertyChanged( long objRef )
{
  if ( IsSelfAdvise() && theApp.m_mes_OBJ_2DDOC )
  {
    ksDocument2DPtr doc2D( m_doc );
    if ( doc2D != NULL && objRef )
      doc2D->ksLightObj( objRef, true );

    CString str;
    str.Format( _T( "%s --> Object2DEvent::PropertyChanged\nobjRef = %i\n" ), (LPCTSTR)m_libName, objRef );
    str += OutRes();
    str += _T( "\nИмя документа = " ) + GetDocName();
    CString strType;
    strType.Format( _T( "\nТип объекта/указатель = %i" ), m_objType );
    str += strType;
    kompas->ksMessage( (LPCTSTR)str );

    if ( doc2D != NULL && objRef )
      doc2D->ksLightObj( objRef, false );
  }
  return true;
}
