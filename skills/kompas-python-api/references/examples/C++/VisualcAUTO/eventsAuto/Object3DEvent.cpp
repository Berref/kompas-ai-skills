////////////////////////////////////////////////////////////////////////////////
//
// Object3DEvent - обработчик событий объектов 3D документа
//
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "eventsAuto.h"

#ifndef _OBJECT3DEVENT_H
#include "Object3DEvent.h"
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

////////////////////////////////////////////////////////////////////////////////
//
// Object3DEvent - обработчик событий объектов 3D документа
//
////////////////////////////////////////////////////////////////////////////////

//-------------------------------------------------------------------------------
//
// ---
Object3DEvent::Object3DEvent( LPUNKNOWN object, 
                              LPDISPATCH doc, 
                              long objType,
                              LPDISPATCH obj3D,
                              ksObject3DNotifyResultPtr res, 
                              bool selfAdvise /*true*/ )
  : BaseEvent( object, DIID_ksObject3DNotify, doc, objType, obj3D, selfAdvise ),
    m_res( res )
{
}


//-------------------------------------------------------------------------------
//
// ---
Object3DEvent::~Object3DEvent()
{
}
      

//-------------------------------------------------------------------------------
//
// ---
BEGIN_EVENTSINK_MAP(Object3DEvent, BaseEvent)
  ON_EVENT (Object3DEvent, (unsigned int)-1, o3BeginDelete,           BeginDelete,           VTS_DISPATCH)
  ON_EVENT (Object3DEvent, (unsigned int)-1, o3Delete,                Delete,                VTS_DISPATCH)
  ON_EVENT (Object3DEvent, (unsigned int)-1, o3Excluded,              Excluded,              VTS_DISPATCH VTS_VARIANT)
  ON_EVENT (Object3DEvent, (unsigned int)-1, o3Hidden,                Hidden,                VTS_DISPATCH VTS_VARIANT)
  ON_EVENT (Object3DEvent, (unsigned int)-1, o3BeginPropertyChanged,  BeginPropertyChanged,  VTS_DISPATCH) 
  ON_EVENT (Object3DEvent, (unsigned int)-1, o3PropertyChanged,       PropertyChanged,       VTS_DISPATCH)
  ON_EVENT (Object3DEvent, (unsigned int)-1, o3BeginPlacementChanged, BeginPlacementChanged, VTS_DISPATCH)
  ON_EVENT (Object3DEvent, (unsigned int)-1, o3PlacementChanged,      PlacementChanged,      VTS_DISPATCH)
  ON_EVENT (Object3DEvent, (unsigned int)-1, o3BeginProcess,          BeginProcess,          VTS_I4 VTS_DISPATCH)
  ON_EVENT (Object3DEvent, (unsigned int)-1, o3EndProcess,            EndProcess,            VTS_I4)
  ON_EVENT (Object3DEvent, (unsigned int)-1, o3CreateObject,          CreateObject,          VTS_DISPATCH)
  ON_EVENT (Object3DEvent, (unsigned int)-1, o3UpdateObject,          UpdateObject,          VTS_DISPATCH)
  ON_EVENT (Object3DEvent, (unsigned int)-1, o3BeginLoadStateChange,  BeginLoadStateChange,  VTS_DISPATCH VTS_I4)
  ON_EVENT (Object3DEvent, (unsigned int)-1, o3LoadStateChange,       LoadStateChange,       VTS_DISPATCH VTS_I4)
END_EVENTSINK_MAP()

//-------------------------------------------------------------------------------
// 
// ---
CString Object3DEvent::OutRes()
{
  CString str;
  if( m_res )
  {
    long notifyType = m_res->GetNotifyType();
    ksFeatureCollectionPtr featureCollection = m_res->GetFeatureCollection();
    ksPlacementPtr placement = m_res->GetPlacement();
    double x = -1, y = -1, z = -1;
    if ( placement )
      placement->GetOrigin( &x, &y, &z );
    str.Format( _T("Object3DNotifyResult: GetNotifyType=%i,\nGetFeatureCollection->GetCount()=%i\nGetPlacement->GetOrigin( %f, %f, %f )"), 
                 notifyType, 
                 featureCollection ? featureCollection->GetCount() : 0,
                 x, y, z );
  }
  return str;
}


//-------------------------------------------------------------------------------
// o3BeginDelete - Начало удаления объектов
// ---
afx_msg VARIANT_BOOL Object3DEvent::BeginDelete( LPDISPATCH obj)
{
  bool res = true; 
  if ( IsSelfAdvise() && theApp.m_mes_OBJ_3DDOC )
  {
    ksDocument3DPtr doc3D( m_doc );
    ksChooseMngPtr chooseMng;
    if( doc3D != NULL  && m_obj3D != NULL && 
        ( chooseMng = doc3D->GetChooseMng() ) != NULL )         
      chooseMng->Choose( obj ); 

    CString str;
    str.Format( _T("%s --> Object3DEvent::BeginDelete\nobj = %i\n"), (LPCTSTR)m_libName, obj );
    str += OutRes();
    str += _T("\nИмя документа = ") + GetDocName();
    CString strType;
    strType.Format( _T("\nТип объекта = %i"), m_objType );
    str += strType;
    CString strObj3DName;
    if( m_obj3D )
       strObj3DName = (LPCTSTR)m_obj3D->Getname();
    str += _T("\nИмя объекта = ");
    str += strObj3DName;
    res = !!kompas->ksYesNo( (LPCTSTR)str ); 

    if( chooseMng != NULL )
      chooseMng->UnChoose( obj );  
  }
  return res;
}


//-------------------------------------------------------------------------------
// o3Delete - Oбъекты удалены
// ---
afx_msg VARIANT_BOOL Object3DEvent::Delete( LPDISPATCH obj )
{
  if ( IsSelfAdvise() && theApp.m_mes_OBJ_3DDOC )
  {
    ksDocument3DPtr doc3D( m_doc );
    ksChooseMngPtr chooseMng;
    if( doc3D != NULL  && m_obj3D != NULL && 
        ( chooseMng = doc3D->GetChooseMng() ) != NULL )         
      chooseMng->Choose( obj ); 

    CString str;
    str.Format( _T("%s --> Object3DEvent::Delete\nobj = %i\n"),(LPCTSTR) m_libName, obj );
    str += OutRes();
    str += _T("\nИмя документа = ") + GetDocName();
    CString strType;
    strType.Format( _T("\nТип объекта = %i"), m_objType );
    str += strType;
    CString strObj3DName;
    if( m_obj3D )
       strObj3DName = (LPCTSTR)m_obj3D->Getname();
    str += _T("\nИмя объекта = ");
    str += strObj3DName;  
    kompas->ksMessage( (LPCTSTR)str );

    if( chooseMng != NULL )
      chooseMng->UnChoose( obj );
  }
  // Если удаляется объект удаляем и подписку на его события
  if ( obj != NULL && m_obj3D == obj )
    delete this; 
  return true;     
}


//-------------------------------------------------------------------------------
// o3Excluded - Oбъект исключен/включен в расчет
// --- 
afx_msg VARIANT_BOOL Object3DEvent::Excluded( LPDISPATCH obj, VARIANT_BOOL excluded )
{
  if ( IsSelfAdvise() && theApp.m_mes_OBJ_3DDOC )
  {
    ksDocument3DPtr doc3D( m_doc );
    ksChooseMngPtr chooseMng;
    if( doc3D != NULL  && m_obj3D != NULL && 
        ( chooseMng = doc3D->GetChooseMng() ) != NULL )         
      chooseMng->Choose( obj ); 

    CString str;
    str.Format( _T("%s --> Object3DEvent::Excluded\nobj = %i\nexcluded = %i\n"), (LPCTSTR)m_libName, obj, excluded );
    str += OutRes();
    str += _T("\nИмя документа = ") + GetDocName();
    CString strType;
    strType.Format( _T("\nТип объекта = %i"), m_objType );
    str += strType;
    CString strObj3DName;
    if( m_obj3D )
       strObj3DName = (LPCTSTR)m_obj3D->Getname();
    str += _T("\nИмя объекта = ");
    str += strObj3DName;
    kompas->ksMessage( (LPCTSTR)str );

    if( chooseMng != NULL )
      chooseMng->UnChoose( obj );
  }
  return true;
}


//-------------------------------------------------------------------------------
// o3Hidden - Oбъект скрыт/показан
// ---
afx_msg VARIANT_BOOL Object3DEvent::Hidden(LPDISPATCH obj, VARIANT_BOOL _hidden)
{
  if ( IsSelfAdvise() && theApp.m_mes_OBJ_3DDOC )
  {
    ksDocument3DPtr doc3D( m_doc );
    ksChooseMngPtr chooseMng;
    if( doc3D != NULL  && m_obj3D != NULL && 
        ( chooseMng = doc3D->GetChooseMng() ) != NULL )         
      chooseMng->Choose( obj ); 

    CString str;
    str.Format( _T("%s --> Object3DEvent::Hidden\nobj = %i\n_hidden = %i\n"), (LPCTSTR)m_libName, obj, _hidden );
    str += OutRes(); 
    str += _T("\nИмя документа = ") + GetDocName();
    CString strType;
    strType.Format( _T("\nТип объекта = %i"), m_objType );
    str += strType;
    CString strObj3DName;
    if( m_obj3D )
       strObj3DName = (LPCTSTR)m_obj3D->Getname();
    str += _T("\nИмя объекта = ");
    str += strObj3DName;
    kompas->ksMessage( (LPCTSTR)str );

    if( chooseMng != NULL )
      chooseMng->UnChoose( obj );
  }
  return true;
}


//-------------------------------------------------------------------------------
// o3BeginPropertyChanged - Начало изменения свойств объета
// ---
afx_msg VARIANT_BOOL Object3DEvent::BeginPropertyChanged(LPDISPATCH obj)
{
  bool res = true;
  if ( IsSelfAdvise() && theApp.m_mes_OBJ_3DDOC )
  {
    ksDocument3DPtr doc3D( m_doc );
    ksChooseMngPtr chooseMng;
    if( doc3D != NULL  && m_obj3D != NULL && 
        ( chooseMng = doc3D->GetChooseMng() ) != NULL )         
      chooseMng->Choose( obj ); 

    CString str;
    str.Format( _T("%s --> Object3DEvent::BeginPropertyChanged\nobj = %i\n"), (LPCTSTR)m_libName, obj );
    str += OutRes();
    str += _T("\nИмя документа = ") + GetDocName();
    CString strType;
    strType.Format( _T("\nТип объекта = %i"), m_objType );
    str += strType;
    CString strObj3DName;
    if( m_obj3D )
       strObj3DName = (LPCTSTR)m_obj3D->Getname();
    str += _T("\nИмя объекта = ");
    str += strObj3DName;
    res = !!kompas->ksYesNo( (LPCTSTR)str ); 

    if( chooseMng != NULL )
      chooseMng->UnChoose( obj );
  }
  return res;
}


//-------------------------------------------------------------------------------
// o3PropertyChanged - Изменены свойства объета
// ---
afx_msg VARIANT_BOOL Object3DEvent::PropertyChanged(LPDISPATCH obj)
{
  if ( IsSelfAdvise() && theApp.m_mes_OBJ_3DDOC )
  {
    ksDocument3DPtr doc3D( m_doc );
    ksChooseMngPtr chooseMng;
    if( doc3D != NULL  && m_obj3D != NULL && 
        ( chooseMng = doc3D->GetChooseMng() ) != NULL )         
      chooseMng->Choose( obj ); 

    CString str;
    str.Format( _T("%s --> Object3DEvent::PropertyChanged\nobj = %i\n"), (LPCTSTR)m_libName, obj );
    str += OutRes();
    str += _T("\nИмя документа = ") + GetDocName();
    CString strType;
    strType.Format( _T("\nТип объекта = %i"), m_objType );
    str += strType;
    CString strObj3DName;
    if( m_obj3D )
       strObj3DName = (LPCTSTR)m_obj3D->Getname();
    str += "\nИмя объекта = ";
    str += strObj3DName;
    kompas->ksMessage( (LPCTSTR)str );

    if( chooseMng != NULL )
      chooseMng->UnChoose( obj );
  }
  return true;
}


//-------------------------------------------------------------------------------
// o3BeginPlacementChanged - Начало изменения положения объета
// ---
afx_msg VARIANT_BOOL Object3DEvent::BeginPlacementChanged(LPDISPATCH obj)
{
  bool res = true;
  if ( IsSelfAdvise() && theApp.m_mes_OBJ_3DDOC )
  {
    ksDocument3DPtr doc3D( m_doc );
    ksChooseMngPtr chooseMng;
    if( doc3D != NULL  && m_obj3D != NULL && 
        ( chooseMng = doc3D->GetChooseMng() ) != NULL )         
      chooseMng->Choose( obj ); 

    CString str;
    str.Format( _T("%s --> Object3DEvent::BeginPlacementChanged\nobj = %i\n"), (LPCTSTR)m_libName, obj );
    str += OutRes();
    str += _T("\nИмя документа = ") + GetDocName();
    CString strType;
    strType.Format( _T("\nТип объекта = %i"), m_objType );
    str += strType;
    CString strObj3DName;
    if( m_obj3D )
       strObj3DName = (LPCTSTR)m_obj3D->Getname();
    str += _T("\nИмя объекта = ");
    str += strObj3DName;
    res = !!kompas->ksYesNo( (LPCTSTR)str ); 

    if( chooseMng != NULL )
      chooseMng->UnChoose( obj );
  }
  return res;
}


//-------------------------------------------------------------------------------
// o3PlacementChanged - Изменено положения объета
// ---
afx_msg VARIANT_BOOL Object3DEvent::PlacementChanged(LPDISPATCH obj)
{
  if ( IsSelfAdvise() && theApp.m_mes_OBJ_3DDOC )
  {
    ksDocument3DPtr doc3D( m_doc );
    ksChooseMngPtr chooseMng;
    if( doc3D != NULL  && m_obj3D != NULL && 
        ( chooseMng = doc3D->GetChooseMng() ) != NULL )         
      chooseMng->Choose( obj ); 

    CString str;
    str.Format( _T("%s --> Object3DEvent::PlacementChanged\nobj = %i\n"), (LPCTSTR)m_libName, obj );
    str += OutRes();
    str += _T("\nИмя документа = ") + GetDocName();
    CString strType;
    strType.Format( _T("\nТип объекта = %i"), m_objType );
    str += strType;
    CString strObj3DName;
    if( m_obj3D )
       strObj3DName = (LPCTSTR)m_obj3D->Getname();
    str += _T("\nИмя объекта = ");
    str += strObj3DName;
    kompas->ksMessage( (LPCTSTR)str );

    if( chooseMng != NULL )
      chooseMng->UnChoose( obj );
  }
  return true;
}


//-------------------------------------------------------------------------------
// o3BeginProcess - Начало редактирования\создания объекта
// ---
afx_msg VARIANT_BOOL Object3DEvent::BeginProcess( long pType, LPDISPATCH obj )
{
  bool res = true;
  if ( IsSelfAdvise() && theApp.m_mes_OBJ_3DDOC )
  {
    ksDocument3DPtr doc3D( m_doc );
    ksChooseMngPtr chooseMng;
    if( doc3D != NULL  && m_obj3D != NULL && 
        ( chooseMng = doc3D->GetChooseMng() ) != NULL )         
      chooseMng->Choose( obj ); 

    CString str;
    str.Format( _T("%s --> Object3DEvent::BeginProcess\npType = %i\nobj = %i\n"), (LPCTSTR)m_libName, pType, obj );
    str += OutRes();
    str += _T("\nИмя документа = ") + GetDocName();
    CString strType;
    strType.Format( _T("\nТип объекта = %i"), m_objType );
    str += strType;
    CString strObj3DName;
    if( m_obj3D )
       strObj3DName = (LPCTSTR)m_obj3D->Getname();
    str += "\nИмя объекта = ";
    str += strObj3DName;
    res = !!kompas->ksYesNo( (LPCTSTR)str ); 

    if( chooseMng != NULL )
      chooseMng->UnChoose( obj );
  }
  return res;
}


//-------------------------------------------------------------------------------
// o3EndProcess - Конец редактирования\создания объекта
// ---
afx_msg VARIANT_BOOL Object3DEvent::EndProcess( long pType )
{
  if ( IsSelfAdvise() && theApp.m_mes_OBJ_3DDOC )
  {
    ksDocument3DPtr doc3D( m_doc );

    CString str;
    str.Format( _T("%s --> Object3DEvent::EndProcess\npType = %i\n"), (LPCTSTR)m_libName, pType );
    str += OutRes();
    str += _T("\nИмя документа = ") + GetDocName();
    CString strType;
    strType.Format( _T("\nТип объекта = %i"), m_objType );
    str += strType;
    CString strObj3DName;
    if( m_obj3D )
       strObj3DName = (LPCTSTR)m_obj3D->Getname();
    str += _T("\nИмя объекта = ");
    str += strObj3DName;
    kompas->ksMessage( (LPCTSTR)str );
  }
  return true;
}


//-------------------------------------------------------------------------------
// o3CreateObject - Создание объекта
// ---
afx_msg VARIANT_BOOL Object3DEvent::CreateObject( LPDISPATCH obj )
{
  if ( IsSelfAdvise() && theApp.m_mes_OBJ_3DDOC )
  {
    ksDocument3DPtr doc3D( m_doc );
    ksChooseMngPtr chooseMng;
    if( doc3D != NULL  && m_obj3D != NULL && 
        ( chooseMng = doc3D->GetChooseMng() ) != NULL )         
      chooseMng->Choose( obj ); 

    CString str;
    str.Format( _T("%s --> Object3DEvent::CreateObject\nobj = %i\n"), (LPCTSTR)m_libName, obj );
    str += OutRes();
    str += _T("\nИмя документа = ") + GetDocName();
    CString strType;
    strType.Format( _T("\nТип объекта = %i"), m_objType );
    str += strType;
    CString strObj3DName;
    if( m_obj3D )
       strObj3DName = (LPCTSTR)m_obj3D->Getname();
    str += _T("\nИмя объекта = ");
    str += strObj3DName;
    kompas->ksMessage( (LPCTSTR)str ); 

    if( chooseMng != NULL )
      chooseMng->UnChoose( obj );
  }
  return true;
}


//-------------------------------------------------------------------------------
// o3UpdateObject - Редактирование объекта
// ---
afx_msg VARIANT_BOOL Object3DEvent::UpdateObject( LPDISPATCH obj )
{
  if ( IsSelfAdvise() && theApp.m_mes_OBJ_3DDOC )
  {
    ksDocument3DPtr doc3D( m_doc );
    ksChooseMngPtr chooseMng;
    if( doc3D != NULL  && m_obj3D != NULL && 
        ( chooseMng = doc3D->GetChooseMng() ) != NULL )         
      chooseMng->Choose( obj ); 

    CString str;
    str.Format( _T("%s --> Object3DEvent::UpdateObject\nobj = %i\n"), (LPCTSTR)m_libName, obj );
    str += OutRes();
    str += _T("\nИмя документа = ") + GetDocName();
    CString strType;
    strType.Format( _T("\nТип объекта = %i"), m_objType );
    str += strType;
    CString strObj3DName;
    if( m_obj3D )
       strObj3DName = (LPCTSTR)m_obj3D->Getname();
    str += _T("\nИмя объекта = ");
    str += strObj3DName;
    kompas->ksMessage( (LPCTSTR)str );

    if( chooseMng != NULL )
      chooseMng->UnChoose( obj );
  }
  return true;
}

//-------------------------------------------------------------------------------
// o3BeginLoadStateChange - Начало изменения типа загрузки
// ---
VARIANT_BOOL Object3DEvent::BeginLoadStateChange( LPDISPATCH obj, long loadState )
{
  bool res = true;
  if ( IsSelfAdvise() && theApp.m_mes_OBJ_3DDOC )
  {
    ksDocument3DPtr doc3D( m_doc );
    ksChooseMngPtr chooseMng;
    if ( doc3D != NULL && m_obj3D != NULL &&
         (chooseMng = doc3D->GetChooseMng()) != NULL )
      chooseMng->Choose( obj );

    CString str;
    str.Format( _T( "%s --> Object3DEvent::BeginLoadStateChange\nobj = %i\n" ), (LPCTSTR)m_libName, obj );
    str += OutRes();
    str += _T( "\nИмя документа = " ) + GetDocName();
    CString strType;
    strType.Format( _T( "\nТип объекта = %i" ), m_objType );
    str += strType;
    CString strObj3DName;
    if ( m_obj3D )
      strObj3DName = (LPCTSTR)m_obj3D->Getname();
    str += _T( "\nИмя объекта = " );
    str += strObj3DName;
    CString strloadState;
    strloadState.Format( _T( "\nИндекс набора загрузки = %i" ), loadState );
    str += strloadState;

    res = !!kompas->ksYesNo( (LPCTSTR)str );

    if ( chooseMng != NULL )
      chooseMng->UnChoose( obj );
  }
  return res;
}

//-------------------------------------------------------------------------------
// o3LoadStateChange - Завершение изменения типа загрузки
// ---
VARIANT_BOOL Object3DEvent::LoadStateChange( LPDISPATCH obj, long loadState )
{
  if ( IsSelfAdvise() && theApp.m_mes_OBJ_3DDOC )
  {
    ksDocument3DPtr doc3D( m_doc );
    ksChooseMngPtr chooseMng;
    if ( doc3D != NULL && m_obj3D != NULL &&
         (chooseMng = doc3D->GetChooseMng()) != NULL )
      chooseMng->Choose( obj );

    CString str;
    str.Format( _T( "%s --> Object3DEvent::LoadStateChange\nobj = %i\n" ), (LPCTSTR)m_libName, obj );
    str += OutRes();
    str += _T( "\nИмя документа = " ) + GetDocName();
    CString strType;
    strType.Format( _T( "\nТип объекта = %i" ), m_objType );
    str += strType;
    CString strObj3DName;
    if ( m_obj3D )
      strObj3DName = (LPCTSTR)m_obj3D->Getname();
    str += "\nИмя объекта = ";
    str += strObj3DName;
    CString strloadState;
    strloadState.Format( _T( "\nИндекс набора загрузки = %i" ), loadState );
    str += strloadState;
    kompas->ksMessage( (LPCTSTR)str );

    if ( chooseMng != NULL )
      chooseMng->UnChoose( obj );
  }
  return true;
}
