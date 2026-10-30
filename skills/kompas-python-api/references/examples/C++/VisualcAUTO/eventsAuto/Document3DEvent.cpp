////////////////////////////////////////////////////////////////////////////////
//
// Document3DEvent - обработчик событий от 3D документа
//
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "eventsAuto.h"

#ifndef _DOCUMENT3DEVENT_H
#include "Document3DEvent.h"
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif  


////////////////////////////////////////////////////////////////////////////////
//
// Document3DEvent - обработчик событий от 3D документа
//
////////////////////////////////////////////////////////////////////////////////

//-------------------------------------------------------------------------------
//
// ---
Document3DEvent::Document3DEvent( LPUNKNOWN pObject, LPDISPATCH doc, bool selfAdvise /*true*/ )
: BaseEvent( pObject, DIID_ksDocument3DNotify, doc, -1, NULL, selfAdvise )
{
}


//-------------------------------------------------------------------------------
//
// ---
Document3DEvent::~Document3DEvent()
{
}


//-------------------------------------------------------------------------------
//
// ---
BEGIN_EVENTSINK_MAP(Document3DEvent, BaseEvent)
  ON_EVENT (Document3DEvent, (unsigned int)-1, d3BeginRebuild,               BeginRebuild,               VTS_NONE)
  ON_EVENT (Document3DEvent, (unsigned int)-1, d3Rebuild,                    Rebuild,                    VTS_NONE)
  ON_EVENT (Document3DEvent, (unsigned int)-1, d3BeginChoiceMaterial,        BeginChoiceMaterial,        VTS_NONE)
  ON_EVENT (Document3DEvent, (unsigned int)-1, d3ChoiceMaterial,             ChoiceMaterial,             VTS_BSTR VTS_R8)
  ON_EVENT (Document3DEvent, (unsigned int)-1, d3BeginChoiceMarking,         BeginChoiceMarking,         VTS_NONE)
  ON_EVENT (Document3DEvent, (unsigned int)-1, d3ChoiceMarking,              ChoiceMarking,              VTS_BSTR)
  ON_EVENT (Document3DEvent, (unsigned int)-1, d3BeginSetPartFromFile,       BeginSetPartFromFile,       VTS_NONE)
  ON_EVENT (Document3DEvent, (unsigned int)-1, d3BeginCreatePartFromFile,    BeginCreatePartFromFile,    VTS_BOOL VTS_DISPATCH)
  ON_EVENT (Document3DEvent, (unsigned int)-1, d3CreateEmbodiment,           CreateEmbodiment,           VTS_BSTR)
  ON_EVENT (Document3DEvent, (unsigned int)-1, d3DeleteEmbodiment,           DeleteEmbodiment,           VTS_BSTR)
  ON_EVENT (Document3DEvent, (unsigned int)-1, d3ChangeCurrentEmbodiment,    ChangeCurrentEmbodiment,    VTS_BSTR)
  ON_EVENT (Document3DEvent, (unsigned int)-1, d3BeginChoiceProperty,        BeginChoiceProperty,        VTS_DISPATCH VTS_R8)
  ON_EVENT (Document3DEvent, (unsigned int)-1, d3ChoiceProperty,             ChoiceProperty,             VTS_DISPATCH VTS_R8)
  ON_EVENT (Document3DEvent, (unsigned int)-1, d3BeginRollbackFeatures,      BeginRollbackFeatures,      VTS_NONE)
  ON_EVENT (Document3DEvent, (unsigned int)-1, d3RollbackFeatures,           RollbackFeatures,           VTS_NONE)
  ON_EVENT (Document3DEvent, (unsigned int)-1, d3BedinLoadCombinationChange, BedinLoadCombinationChange, VTS_I4)
  ON_EVENT (Document3DEvent, (unsigned int)-1, d3LoadCombinationChange,      LoadCombinationChange,      VTS_I4)
  ON_EVENT (Document3DEvent, (unsigned int)-1, d3BeginDeleteMaterial,        BeginDeleteMaterial,        VTS_NONE)
  ON_EVENT (Document3DEvent, (unsigned int)-1, d3DeleteMaterial,             DeleteMaterial,             VTS_NONE)
  ON_EVENT( Document3DEvent, (unsigned int)-1, d3BeginDeleteProperty,        BeginDeleteProperty,        VTS_DISPATCH VTS_R8 )
  ON_EVENT( Document3DEvent, (unsigned int)-1, d3DeleteProperty,             DeleteProperty,             VTS_DISPATCH VTS_R8 )

END_EVENTSINK_MAP()


//-------------------------------------------------------------------------------
// d3BeginRebuild - Начало перестроения модели
// ---
afx_msg VARIANT_BOOL Document3DEvent::BeginRebuild()
{ 
  if ( IsSelfAdvise() && theApp.m_mes_3DDOC )
  {
    CString str( m_libName + " --> Document3DEvent::BeginRebuild" );
    str += "\nИмя документа = " + GetDocName();
    return !!kompas->ksYesNo( str.GetBuffer(0) );
  }
  else
    return true;
}


//-------------------------------------------------------------------------------
// d3Rebuild - Модель перестроена
// ---
afx_msg VARIANT_BOOL Document3DEvent::Rebuild()
{   
  if ( IsSelfAdvise() && theApp.m_mes_3DDOC )
  {
    CString str( m_libName + " --> Document3DEvent::Rebuild" );
    str += "\nИмя документа = " + GetDocName();
    kompas->ksMessage( str.GetBuffer(0) );
  }
  return true;
}


//-------------------------------------------------------------------------------
// d3BeginChoiceMaterial - Начало выбора материала
// ---
afx_msg VARIANT_BOOL Document3DEvent::BeginChoiceMaterial()
{
  bool res = true;
  if ( IsSelfAdvise() && theApp.m_mes_3DDOC )
  {
    CString str( m_libName + " --> Document3DEvent::BeginChoiceMaterial" );
    str += "\nИмя документа = " + GetDocName();
    res = !!kompas->ksYesNo( str.GetBuffer(0) );

    if( !res )
    {   
      ksDocument3DPtr doc3D;
      m_doc->QueryInterface( DIID_ksDocument3D, (LPVOID*)&doc3D );
      if( doc3D ) 
      {  
        ksPartPtr partObj( doc3D->GetPart( pTop_Part ) );
        partObj->SetMaterial( "Material", 36.6 );
        partObj->Update();
      }
    }
  }
  return res;
}


//-------------------------------------------------------------------------------
// d3СhoiceMaterial - Закончен выбор материала
// ---
afx_msg VARIANT_BOOL Document3DEvent::ChoiceMaterial( LPCTSTR material, double density )
{
  if ( IsSelfAdvise() && theApp.m_mes_3DDOC )
  {
    CString str;
    str.Format( _T("%s --> Document3DEvent::ChoiceMaterial\nmaterial = %s\ndensity = %f"), (LPCTSTR)m_libName, material, density );
    str += "\nИмя документа = " + GetDocName();
    kompas->ksMessage( str.GetBuffer(0) );
  }
  return true;
}


//-------------------------------------------------------------------------------
// d3BeginChoiceMarking - Начало выбора обозначения
// ---
afx_msg VARIANT_BOOL Document3DEvent::BeginChoiceMarking()
{
  bool res = true;
  if ( IsSelfAdvise() && theApp.m_mes_3DDOC )
  {
    CString str( m_libName + _T(" --> Document3DEvent::BeginChoiceMarking") );
    str += _T("\nИмя документа = ") + GetDocName();
    res = !!kompas->ksYesNo( str.GetBuffer(0) );

    if( !res )
    {   
      ksDocument3DPtr doc3D;
      m_doc->QueryInterface( DIID_ksDocument3D, (LPVOID*)&doc3D );
      if( doc3D ) 
      {  
        ksPartPtr partObj( doc3D->GetPart( pTop_Part ) );
        partObj->marking = _T("Marking");
        partObj->Update();
      }
    }
  }
  return res;
}


//-------------------------------------------------------------------------------
// d3СhoiceMarking - Закончен выбор обозначения
// ---
afx_msg VARIANT_BOOL Document3DEvent::ChoiceMarking( LPCTSTR marking )
{
  if ( IsSelfAdvise() && theApp.m_mes_3DDOC )
  {
    CString str;
    str.Format( _T("%s --> Document3DEvent::ChoiceMarking\nmarking = %s"), (LPCTSTR)m_libName, marking );
    str += _T("\nИмя документа = ") + GetDocName();
    kompas->ksMessage( str.GetBuffer(0) );
  }
  return true;
}


//-------------------------------------------------------------------------------
// d3BeginSetPartFromFile    - Начало установки компонента в сборку (до диалога выбора имени)
afx_msg VARIANT_BOOL Document3DEvent::BeginSetPartFromFile()
{
  if ( IsSelfAdvise() && theApp.m_mes_3DDOC )
  {
    CString str( m_libName + _T(" --> Document3DEvent::BeginSetPartFromFile") );
    str += _T("\nИмя документа = ") + GetDocName();
    return !!kompas->ksYesNo( str.GetBuffer(0) );
  }
  return true;
}


//-------------------------------------------------------------------------------
// d3BeginCreatePartFromFile - Начало создания компонента в сборке (до диалога выбора имени)
// ---
afx_msg VARIANT_BOOL Document3DEvent::BeginCreatePartFromFile( BOOL part, ksEntity * plane )
{
  if ( IsSelfAdvise() && theApp.m_mes_3DDOC )
  {
    CString str( m_libName + _T(" --> Document3DEvent::BeginCreatePartFromFile") );
    str += _T("\nИмя документа = ") + GetDocName();
    return !!kompas->ksYesNo( str.GetBuffer(0) );
  }
  return true;
}

//-------------------------------------------------------------------------------
// d3CreateEmbodiment - Добавлено новое исполнение
// ---
VARIANT_BOOL Document3DEvent::CreateEmbodiment( LPCTSTR marking )
{
  if ( IsSelfAdvise() && theApp.m_mes_3DDOC )
  {
    CString str;
    str.Format( _T( "%s --> Document3DEvent::CreateEmbodiment\nmarking = %s" ), (LPCTSTR)m_libName, marking );
    str += _T( "\nИмя документа = " ) + GetDocName();
    kompas->ksMessage( str.GetBuffer( 0 ) );
  }
  return true;
}

//-------------------------------------------------------------------------------
// d3DeleteEmbodiment - Удалено исполнение
// ---
VARIANT_BOOL Document3DEvent::DeleteEmbodiment( LPCTSTR marking )
{
  if ( IsSelfAdvise() && theApp.m_mes_3DDOC )
  {
    CString str;
    str.Format( _T( "%s --> Document3DEvent::DeleteEmbodiment\nmarking = %s" ), (LPCTSTR)m_libName, marking );
    str += _T( "\nИмя документа = " ) + GetDocName();
    kompas->ksMessage( str.GetBuffer( 0 ) );
  }
  return true;
}

//-------------------------------------------------------------------------------
// d3ChangeCurrentEmbodiment - Исполение установлено текущим
// ---
VARIANT_BOOL Document3DEvent::ChangeCurrentEmbodiment( LPCTSTR marking )
{
  if ( IsSelfAdvise() && theApp.m_mes_3DDOC )
  {
    CString str;
    str.Format( _T( "%s --> Document3DEvent::ChangeCurrentEmbodiment\nmarking = %s" ), (LPCTSTR)m_libName, marking );
    str += _T( "\nИмя документа = " ) + GetDocName();
    kompas->ksMessage( str.GetBuffer( 0 ) );
  }
  return true;
}

//-------------------------------------------------------------------------------
// d3BeginChoiceProperty - Начало выбора свойства
// ---
VARIANT_BOOL Document3DEvent::BeginChoiceProperty( LPDISPATCH obj, double propID )
{
  if ( IsSelfAdvise() && theApp.m_mes_3DDOC )
  {
    CString str;
    str.Format( _T( "%s --> Document3DEvent::BeginChoiceProperty\npropID = %f" ), (LPCTSTR)m_libName, propID );
    str += _T( "\nИмя документа = " ) + GetDocName();
    return !!kompas->ksYesNo( str.GetBuffer(0) );
  }
  return true;
}

//-------------------------------------------------------------------------------
// d3ChoiceProperty - Закончен выбор свойства
// ---
VARIANT_BOOL Document3DEvent::ChoiceProperty( LPDISPATCH obj, double propID )
{
  if ( IsSelfAdvise() && theApp.m_mes_3DDOC )
  {
    CString str;
    str.Format( _T( "%s --> Document3DEvent::ChoiceProperty\npropID = %f" ), (LPCTSTR)m_libName, propID );
    str += _T( "\nИмя документа = " ) + GetDocName();
    kompas->ksMessage( str.GetBuffer( 0 ) );
  }
  return true;
}

//-------------------------------------------------------------------------------
// d3BeginRollbackFeatures - Начало отката дерева модели
// ---
VARIANT_BOOL Document3DEvent::BeginRollbackFeatures()
{
  if ( IsSelfAdvise() && theApp.m_mes_3DDOC )
  {
    CString str;
    str.Format( _T( "%s --> Document3DEvent::BeginRollbackFeatures" ), (LPCTSTR)m_libName );
    str += _T( "\nИмя документа = " ) + GetDocName();
    return !!kompas->ksYesNo( str.GetBuffer( 0 ) );
  }
  return true;
}

//-------------------------------------------------------------------------------
// d3RollbackFeatures - Завершение отката дерева модели
// ---
VARIANT_BOOL Document3DEvent::RollbackFeatures()
{
  if ( IsSelfAdvise() && theApp.m_mes_3DDOC )
  {
    CString str;
    str.Format( _T( "%s --> Document3DEvent::RollbackFeatures" ), (LPCTSTR)m_libName );
    str += _T( "\nИмя документа = " ) + GetDocName();
    kompas->ksMessage( str.GetBuffer( 0 ) );
  }
  return true;
}

//-------------------------------------------------------------------------------
// d3BedinLoadCombinationChange - Начало переключения типа загрузки
// ---
VARIANT_BOOL Document3DEvent::BedinLoadCombinationChange( long index )
{
  if ( IsSelfAdvise() && theApp.m_mes_3DDOC )
  {
    CString str;
    str.Format( _T( "%s --> Document3DEvent::BedinLoadCombinationChange\npropID = %i" ), (LPCTSTR)m_libName, index );
    str += _T( "\nИмя документа = " ) + GetDocName();
    return !!kompas->ksYesNo( str.GetBuffer( 0 ) );
  }
  return true;
}

//-------------------------------------------------------------------------------
// d3LoadCombinationChange - Завершение переключения типа загрузки
// ---
VARIANT_BOOL Document3DEvent::LoadCombinationChange( long index )
{
  if ( IsSelfAdvise() && theApp.m_mes_3DDOC )
  {
    CString str;
    str.Format( _T( "%s --> Document3DEvent::LoadCombinationChange\npropID = %i"  ), (LPCTSTR)m_libName, index );
    str += _T( "\nИмя документа = " ) + GetDocName();
    kompas->ksMessage( str.GetBuffer( 0 ) );
  }
  return true;
}

//-------------------------------------------------------------------------------
// d3BeginDeleteMaterial - Начало удаления материала
// ---
VARIANT_BOOL Document3DEvent::BeginDeleteMaterial()
{
  if ( IsSelfAdvise() && theApp.m_mes_3DDOC )
  {
    CString str;
    str.Format( _T( "%s --> Document3DEvent::BeginDeleteMaterial" ), (LPCTSTR)m_libName );
    str += _T( "\nИмя документа = " ) + GetDocName();
    return !!kompas->ksYesNo( str.GetBuffer( 0 ) );
  }
  return true;
}

//-------------------------------------------------------------------------------
// d3DeleteMaterial - Материал удален
// ---
VARIANT_BOOL Document3DEvent::DeleteMaterial()
{
  if ( IsSelfAdvise() && theApp.m_mes_3DDOC )
  {
    CString str;
    str.Format( _T( "%s --> Document3DEvent::DeleteMaterial" ), (LPCTSTR)m_libName );
    str += _T( "\nИмя документа = " ) + GetDocName();
    kompas->ksMessage( str.GetBuffer( 0 ) );
  }
  return true;
}

//-------------------------------------------------------------------------------
// d3BeginDeleteProperty - Начало удаления значения свойства
// ---
VARIANT_BOOL Document3DEvent::BeginDeleteProperty( LPDISPATCH obj, double propID )
{
  if ( IsSelfAdvise() && theApp.m_mes_3DDOC )
  {
    CString str;
    str.Format( _T( "%s --> Document3DEvent::BeginDeleteProperty\npropID = %f" ), (LPCTSTR)m_libName, propID );
    str += _T( "\nИмя документа = " ) + GetDocName();
    return !!kompas->ksYesNo( str.GetBuffer( 0 ) );
  }
  return true;
}

//-------------------------------------------------------------------------------
// d3DeleteProperty - Завершение удаления свойства
// ---
VARIANT_BOOL Document3DEvent::DeleteProperty( LPDISPATCH obj, double propID )
{
  if ( IsSelfAdvise() && theApp.m_mes_3DDOC )
  {
    CString str;
    str.Format( _T( "%s --> Document3DEvent::DeleteProperty\npropID = %f" ), (LPCTSTR)m_libName, propID );
    str += _T( "\nИмя документа = " ) + GetDocName();
    kompas->ksMessage( str.GetBuffer( 0 ) );
  }
  return true;
}
