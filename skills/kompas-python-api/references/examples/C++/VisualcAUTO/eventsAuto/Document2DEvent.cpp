////////////////////////////////////////////////////////////////////////////////
//
// Document2DEvent - обработчик событий от 2D документа
//
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "eventsAuto.h"

#ifndef _DOCUMENT2DEVENT_H
#include "Document2DEvent.h"
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif  

////////////////////////////////////////////////////////////////////////////////
//
// Document2DEvent - обработчик событий от 2D документа
//
////////////////////////////////////////////////////////////////////////////////

//-------------------------------------------------------------------------------
//
// ---
Document2DEvent::Document2DEvent( LPUNKNOWN pObject, LPDISPATCH doc, bool selfAdvise /*true*/ )
: BaseEvent( pObject, DIID_ksDocument2DNotify, doc, -1, NULL, selfAdvise )
{
}


//-------------------------------------------------------------------------------
//
// ---
Document2DEvent::~Document2DEvent()
{
}


//-------------------------------------------------------------------------------
//
// ---
BEGIN_EVENTSINK_MAP(Document2DEvent, BaseEvent)
  ON_EVENT (Document2DEvent, (unsigned int)-1, d2BeginRebuild,        BeginRebuild,        VTS_NONE)
  ON_EVENT (Document2DEvent, (unsigned int)-1, d2Rebuild,             Rebuild,             VTS_NONE)
  ON_EVENT (Document2DEvent, (unsigned int)-1, d2BeginChoiceMaterial, BeginChoiceMaterial, VTS_NONE)
  ON_EVENT (Document2DEvent, (unsigned int)-1, d2ChoiceMaterial,      ChoiceMaterial,      VTS_BSTR VTS_R8)
  ON_EVENT (Document2DEvent, (unsigned int)-1, d2BeginInsertFragment, BeginInsertFragment, VTS_NONE)
  ON_EVENT (Document2DEvent, (unsigned int)-1, d2LocalFragmentEdit,   LocalFragmentEdit,   VTS_DISPATCH VTS_BOOL)
  ON_EVENT (Document2DEvent, (unsigned int)-1, d2BeginChoiceProperty, BeginChoiceProperty, VTS_I4 VTS_R8)
  ON_EVENT (Document2DEvent, (unsigned int)-1, d2ChoiceProperty,      ChoiceProperty,      VTS_I4 VTS_R8)
  ON_EVENT (Document2DEvent, (unsigned int)-1, d2BeginDeleteProperty, BeginDeleteProperty, VTS_I4 VTS_R8)
  ON_EVENT (Document2DEvent, (unsigned int)-1, d2BeginDeleteProperty, DeleteProperty,      VTS_I4 VTS_R8)
END_EVENTSINK_MAP()


//-------------------------------------------------------------------------------
// d3BeginRebuild - Начало перестроения модели
// ---
afx_msg VARIANT_BOOL Document2DEvent::BeginRebuild()
{ 
  if ( IsSelfAdvise() && theApp.m_mes_2DDOC )
  {
    CString str( m_libName + " --> Document2DEvent::BeginRebuild" );
    str += "\nИмя документа = " + GetDocName();
    return !!kompas->ksYesNo( str.GetBuffer(0) );
  }
  return true;
}


//-------------------------------------------------------------------------------
// d3Rebuild - Модель перестроена
// ---
afx_msg VARIANT_BOOL Document2DEvent::Rebuild()
{   
  if ( IsSelfAdvise() && theApp.m_mes_2DDOC )
  {
    CString str( m_libName + " --> Document2DEvent::Rebuild" );
    str += "\nИмя документа = " + GetDocName();
    kompas->ksMessage( str.GetBuffer(0) );
  }
  return true;
}


//-------------------------------------------------------------------------------
// d3BeginChoiceMaterial - Начало выбора материала
// ---
afx_msg VARIANT_BOOL Document2DEvent::BeginChoiceMaterial()
{ 
  bool res = true;
  if ( IsSelfAdvise() && theApp.m_mes_2DDOC )
  {
    CString str( m_libName + " --> Document2DEvent::BeginChoiceMaterial" );
    str += "\nИмя документа = " + GetDocName();
    res = !!kompas->ksYesNo( str.GetBuffer(0) );

    if( !res )
    {   
      ksTextLineParamPtr parLine ( kompas->GetParamStruct(ko_TextLineParam) );
      ksTextItemParamPtr parItem( kompas->GetParamStruct(ko_TextItemParam) );

      // Cоздали массив строк текста
      ksDynamicArrayPtr arMaterial( kompas->GetDynamicArray(TEXT_LINE_ARR) );
      if( (bool)arMaterial && (bool)parLine && (bool)parItem )
      {
        parLine->Init();
        parItem->Init();

        // Массив компонент строки текста
        ksDynamicArrayPtr item( parLine->GetTextItemArr() );
        if ( item ) 
        {
          ksTextItemFontPtr font( parItem->GetItemFont() );
          if ( font ) 
          {
            // Создаем первую строку текста
            font->height = 10;   // Высота текста
            font->ksu = 1;       // Сужение текста
            font->color = 1000;  // Цвет
            font->bitVector = 1; // Битовый вектор (наклон, толщина, подчеркивание, тип составной части(дробь, отклонение, выражение типа суммы))
            parItem->s = "(1-я компонента)";
            // Добавили 1-ю компоненту  в массив компонент
            item->ksAddArrayItem( -1, parItem );

            font->height = 20;   // Высота текста
            font->ksu = 2;       // Сужение текста
            font->color = 2000;  // Цвет
            font->bitVector = 2; // Битовый вектор (наклон, толщина, подчеркивание, тип составной части(дробь, отклонение, выражение типа суммы))
            parItem->s = "(2-я компонента)";
            // Добавили 2-ю компоненту  в массив компонент
            item->ksAddArrayItem( -1, parItem );
            
            parLine->style = 1;

            // 1-я строка текста состоит из двух компонент добавим 
            // строку текста в массив строк текста
            arMaterial->ksAddArrayItem( -1, parLine );

            ksDocument2DPtr doc2D;
            m_doc->QueryInterface( DIID_ksDocument2D, (LPVOID*)&doc2D );
            if( doc2D ) 
            {
              doc2D->ksSetMaterialParam( arMaterial, 36.6 );
            }
          }
        }
      }
    }
  }
  return res;
}


//-------------------------------------------------------------------------------
// d3СhoiceMaterial - Закончен выбор материала
// ---
afx_msg VARIANT_BOOL Document2DEvent::ChoiceMaterial( LPCTSTR material, double density )
{
  if ( IsSelfAdvise() && theApp.m_mes_2DDOC )
  {
    CString str;
    str.Format( _T("%s --> Document2DEvent::ChoiceMaterial\nmaterial = %s\ndensity = %f"), (LPCTSTR)m_libName, material, density );
    str += _T("\nИмя документа = ") + GetDocName();
    kompas->ksMessage( str.GetBuffer(0) );
  }
  return true;
}


//-------------------------------------------------------------------------------
// d2BeginInsertFragment - Начало вставки фрагмента (до диалога выбора имени)
// ---
afx_msg VARIANT_BOOL Document2DEvent::BeginInsertFragment()
{
  if ( IsSelfAdvise() && theApp.m_mes_2DDOC )
  {
    CString str( m_libName + _T(" --> Document2DEvent::BeginInsertFragment") );
    str += _T("\nИмя документа = ") + GetDocName();
    return !!kompas->ksYesNo( str.GetBuffer(0) );
  }
  return true;
}

//-------------------------------------------------------------------------------
// d2LocalFragmentEdit - Редактирование локального фрагмента
// ---
VARIANT_BOOL Document2DEvent::LocalFragmentEdit( LPDISPATCH pDoc, VARIANT_BOOL newFrw )
{
  if ( IsSelfAdvise() && theApp.m_mes_2DDOC )
  {
    CString str;
    str.Format( _T( "%s --> Document2DEvent::LocalFragmentEdit\npDoc = %i" ), (LPCTSTR)m_libName, pDoc );
    str += _T( "\nИмя документа = " ) + GetDocName();
    kompas->ksMessage( str.GetBuffer(0) );
  }
  return true;
}

//-------------------------------------------------------------------------------
// d2BeginChoiceProperty - Начало выбора свойства
// ---
VARIANT_BOOL Document2DEvent::BeginChoiceProperty( long objRef, double propID )
{
  if ( IsSelfAdvise() && theApp.m_mes_2DDOC )
  {
    CString str;
    str.Format( _T( "%s --> Document2DEvent::BeginChoiceProperty\nobjRef = %i\npropID = %f" ), (LPCTSTR)m_libName, objRef, propID );
    str += _T( "\nИмя документа = " ) + GetDocName();
    return !!kompas->ksYesNo( str.GetBuffer(0) );
  }
  return true;
}

//-------------------------------------------------------------------------------
// d2ChoiceProperty - Закончен выбор свойства
// ---
VARIANT_BOOL Document2DEvent::ChoiceProperty( long objRef, double propID )
{
  if ( IsSelfAdvise() && theApp.m_mes_2DDOC )
  {
    CString str;
    str.Format( _T( "%s --> Document2DEvent::ChoiceProperty\nobjRef = %i\npropID = %f" ), (LPCTSTR)m_libName, objRef, propID );
    str += _T( "\nИмя документа = " ) + GetDocName();
    kompas->ksMessage( str.GetBuffer( 0 ) );
  }
  return true;
}

//-------------------------------------------------------------------------------
// d2BeginDeleteProperty - Начало удаления значения свойства
// ---
VARIANT_BOOL Document2DEvent::BeginDeleteProperty( long objRef, double propID )
{
  if ( IsSelfAdvise() && theApp.m_mes_2DDOC )
  {
    CString str;
    str.Format( _T( "%s --> Document2DEvent::BeginDeleteProperty\nobjRef = %i\npropID = %f" ), (LPCTSTR)m_libName, objRef, propID );
    str += _T( "\nИмя документа = " ) + GetDocName();
    return !!kompas->ksYesNo( str.GetBuffer( 0 ) );
  }
  return true;
}

//-------------------------------------------------------------------------------
// d2DeleteProperty - Завершение удаления свойства
// ---
VARIANT_BOOL Document2DEvent::DeleteProperty( long objRef, double propID )
{
  if ( IsSelfAdvise() && theApp.m_mes_2DDOC )
  {
    CString str;
    str.Format( _T( "%s --> Document2DEvent::DeleteProperty\nobjRef = %i\npropID = %f" ), (LPCTSTR)m_libName, objRef, propID );
    str += _T( "\nИмя документа = " ) + GetDocName();
    kompas->ksMessage( str.GetBuffer( 0 ) );
  }
  return true;
}
