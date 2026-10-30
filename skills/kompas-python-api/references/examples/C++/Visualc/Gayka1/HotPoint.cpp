////////////////////////////////////////////////////////////////////////////////
//
// Класс для работы с хот точками
// ILibHPObject - Интерфейс хот точек
//
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"

#include "resource.h"

#include <objbase.h>
#include <initguid.h> //  -  Definitions for controlling GUID initialization
                      // Include after compobj.h to enable GUID initialization.  This
                      //              must be done once per exe/dll.
                      // After this file, include one or more of the GUID definition files.
                      //
#include "libhppar.h"
#include <parray.h>
#include "mfcdual.h"
#include "AFXWIN.H"
#include "CPar.h"
#include <SafeArrayUtils.h>
#include <iuptr.h>

#if !defined(_IFUNC)
# define _IFUNC STDMETHODCALLTYPE
#endif

extern ksAPI7::IApplicationPtr newKompasAPI; // Интерфейс Приложения Компас 

//-------------------------------------------------------------------------------
// Оболочка для работы с Hot-точками
// ---
class LibPropObj : public ILibPropertyObject  
{
protected :
  CPar* obj;
  int   count;
public :
  LibPropObj( CPar* _obj ) : count (0), obj( _obj ) {}
  ~LibPropObj();

  CPar* GetObj()  { return obj; }
public:
  /* IUnknown */
  virtual unsigned long _IFUNC AddRef();
  virtual unsigned long _IFUNC Release();
  virtual HRESULT        _IFUNC QueryInterface(const GUID far& iid, void far*far* iface);
  virtual HRESULT       _IFUNC LtQueryInterface( int idType, void far*far* iface );

  // ILibPropertyObject
  // Имя группы объектов по умолчанию макроэлементы
  virtual LPOLESTR _IFUNC GetGroupName()  { return obj ? obj->GetGroupName() : NULL; }
  // Добавить свойство в список свойств
  virtual BOOL     _IFUNC GetProperty     ( int index, PropertyParam * param ) { return obj && param ? obj->GetProperty( index, *param ) : FALSE; }
  // Обновить параметры свойства
  virtual BOOL     _IFUNC UpdateProperty  ( PropertyParam * param ) { return obj && param ? obj->UpdateProperty( *param ) : FALSE; }
  // Изменить свойойство
  virtual int     _IFUNC ApplyProperty   ( PropertyParam * param ) 
  {
    BOOL res = FALSE;
    if ( obj )
    {
      if ( param ) 
        res = obj->ApplyProperty( *param );
      else
      {
        if ( obj->Changed() ) // Завершение изменения параметров
          obj->RedrawMacro();
        res = TRUE;
      }
    }
    return res;
  }
  // Событие запуска внешнего редактирования для пользовательского свойсва /*ksOPControlExternalEdit*/  
  virtual BOOL     _IFUNC OnChoiceProperty( PropertyParam * param ) { return FALSE; }
  // Обновить параметры свойства
  virtual BOOL     _IFUNC EndEditProperty () { return TRUE; }

      // Запрос параметров точек для визуального определения места применения параметра
  virtual BOOL     _IFUNC GetMouseEnterLeavePoint( int propertyId, long pointIndex, LPUNKNOWN parameters ) { return FALSE; }
};

//-------------------------------------------------------------------------------
// Оболочка для работы с Hot-точками
// ---
class HPObj : public LibPropObj
            , public ILibHPObject
            , public ILibHPObject1
{
  protected :
  public :
    HPObj( CPar* _obj ) : LibPropObj( _obj ) {}
   ~HPObj();
  public:
    /* IUnknown */
    virtual unsigned long _IFUNC AddRef();
    virtual unsigned long _IFUNC Release();
    virtual HRESULT        _IFUNC QueryInterface(const GUID far& iid, void far*far* iface);
    virtual HRESULT       _IFUNC LtQueryInterface( int idType, void far*far* iface );

    /* ILibHPObject */            
    // Меню
    virtual int  _IFUNC LibHotPnt_GetMenu       ()                                        { return obj ? obj->GetMenu() : 0;     }
    // Подготовка к редактированию
    virtual BOOL _IFUNC LibHotPnt_Prepare       ( int index )                             { return  obj ? obj->Prepare() : true;  }
    // Завершение перемешения хот-точек
    virtual BOOL _IFUNC LibHotPnt_Complete      ( int index, BOOL success )               { return obj ? obj->EditComplete( index,  success ) : TRUE;  }
    // Запрос списка хот точек
    virtual BOOL _IFUNC LibHotPnt_Get           ( HotPointDescription* point, int index ) { return obj ? obj->GetHotPoints( point,  index )   : TRUE;  }
    // Установка нового положения хот точек
    virtual BOOL _IFUNC LibHotPnt_Set           ( HotPointDescription* point, int index ) { return obj ? obj->SetHotPoint( point, index  )    : TRUE;  }
    // Текст курсора для хот-точки
    virtual BOOL _IFUNC LibHotPnt_GetCursorText ( int index, char** text )                { return obj ? obj->GetCursorText( index, text )    : FALSE; }
    // Выполнение команды из меню хот-точек
    virtual BOOL _IFUNC LibHotPnt_ExecuteCommand( int id )                                { return obj ? obj->ExecuteCommand( id ) : FALSE; }

    /* ILibHPObject1 */            
    // Запрос списка хот точек
    virtual BOOL _IFUNC LibHotPnt_GetEx         ( HotPointDescription1* point, int index ) { return obj ? obj->GetHotPointsEx( point,  index )   : TRUE;  }

    // Получить popup-меню ассоциированое с данным библиотечным элементом
    // Внимание!!! Присланное меню будет модифицированно в системе.
    //             Присланное меню будет уничтожено вызовом функции DestroyMenu()
    // На самом деле ф-ия должна возвращать HMENU
    virtual int _IFUNC LibHotPnt_GetMenuEx      ( int index ) { return obj ? obj->GetMenu(index) : 0;     }

  // получить текст для отображения курсором  текст для UNICODE вместо ILibHPObject::LibHotPnt_GetCursorText
    virtual LPOLESTR _IFUNC  LibHotPnt_GetCursorTextEx( int index ) { return obj ? obj->GetCursorTextEx( index ) : NULL; }

    virtual BOOL _IFUNC LibHotPnt_UpdateCommand ( int id )                                { return obj ? obj->UpdateCommand( id ) : FALSE; }

    // Селектировали hot point
    virtual BOOL _IFUNC LibHotPnt_Select        ( int index ) { return obj ? obj->SelectHotPoint( index )   : TRUE;  }

    // Расселектировали hot point
    virtual BOOL _IFUNC LibHotPnt_Unselect      ( int index ) { return obj ? obj->UnselectHotPoint( index ) : TRUE;  }

};

//-------------------------------------------------------------------------------
// 
// ---
LibPropObj::~LibPropObj()
{
  // Объект болше не нужен
  // Удаляет его
  if ( obj )
    delete obj;
}

//------------------------------------------------------------------------------
// AddRef
// ---
unsigned long _IFUNC LibPropObj::AddRef() 
{
  count++;
  return count;
}

//------------------------------------------------------------------------------
// Release
// ---
unsigned long _IFUNC LibPropObj::Release() 
{
  if ( count ) 
    count--;
  if( !count )
  {
    delete this;
    return 0;
  }
  return count;
}

//------------------------------------------------------------------------------
// QueryInterface
// ---
HRESULT _IFUNC LibPropObj::QueryInterface( const GUID far& iid, void far*far* iface )
{
  if ( iid == IID_ILibraryObject ) 
  {
    *iface = static_cast<ILibraryObject*>(this);
    AddRef();
    return S_OK;
  }
  if ( iid == IID_ILibPropertyObject ) 
  {
    *iface = static_cast<ILibPropertyObject*>(this);
    AddRef();
    return S_OK;
  }

  *iface = NULL;
  return E_NOINTERFACE;
}

//------------------------------------------------------------------------------
// QueryInterface
// ---
HRESULT _IFUNC LibPropObj::LtQueryInterface( int idType, void far*far* iface )
{
  if ( idType == idd_ILibPropertyObject ) 
  {
    *iface = static_cast<ILibPropertyObject*>(this);
    AddRef();
    return S_OK;
  }

  *iface = NULL;
  return E_NOINTERFACE;
}

//-------------------------------------------------------------------------------
// 
// ---
HPObj::~HPObj() 
{
}   

//------------------------------------------------------------------------------
// AddRef
// ---
unsigned long _IFUNC HPObj::AddRef() 
{
  return LibPropObj::AddRef();
}

//------------------------------------------------------------------------------
// Release
// ---
unsigned long _IFUNC HPObj::Release() 
{
  return LibPropObj::Release();
}


//------------------------------------------------------------------------------
// QueryInterface
// ---
HRESULT _IFUNC HPObj::QueryInterface( const GUID far& iid, void far*far* iface )
{
  if ( iid == IID_IUnknown || iid == IID_ILibHPObject ) 
  {
    *iface = static_cast<ILibHPObject*>(this);
    AddRef();
    return S_OK;
  }
  if ( iid == IID_ILibHPObject1 ) 
  {
    *iface = static_cast<ILibHPObject1*>(this);
    AddRef();
    return S_OK;
  }
  return LibPropObj::QueryInterface( iid,  iface );
}


//------------------------------------------------------------------------------
// QueryInterface
// ---
HRESULT _IFUNC HPObj::LtQueryInterface( int idType, void far*far* iface )
{
  if ( idType == idd_ILibHPObject ) 
  {
    *iface = static_cast<ILibHPObject*>(this);
    AddRef();
    return S_OK;
  }
  return LibPropObj::LtQueryInterface( idType,  iface );
}


//-------------------------------------------------------------------------------
// Создает соответствующий объект для работы с Hot точками
// ---
void WINAPI LibObjInterfaceEntry( int idType, unsigned int comm, void** object ) 
{
  if ( object ) 
  {
    if ( idType == 1 || idType == 3 ) { // Если не Hot точки обнулить
      CPar* obj = NewCParObject( comm, EditMacroMode() );
      if ( obj ) {  
        HPObj * hpObj = new HPObj( obj );
          
        hpObj->LtQueryInterface( idType, object );
      } 
    }
  }
}



