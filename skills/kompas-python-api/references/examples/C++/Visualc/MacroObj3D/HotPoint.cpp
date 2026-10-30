////////////////////////////////////////////////////////////////////////////////
//
// Класс для работы с хот точками
// ILibHPObject - Интерфейс хот точек
// ILibExternalObject - Интерфейс событий внешнего редактирования
//
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "resource.h"

#include <objbase.h>
#include <initguid.h> //  -  Definitions for controlling GUID initialization
                      // Include after compobj.h to enable GUID initialization.  This
                      //              must be done once per exe/dll.
                      // After this file, include one or more of the GUID definition files.
#include "libhppar.h"

#if !defined(_IFUNC)
# define _IFUNC STDMETHODCALLTYPE
#endif


//-------------------------------------------------------------------------------
// Оболочка для работы с Hot-точками
// ---
class HPObj : 
  public ILibExternalObject
{
  protected :
    int   count;
  public :
    HPObj() : count (0) {}
   ~HPObj();
  public:
    /* IUnknown */
    virtual unsigned long _IFUNC AddRef();
    virtual unsigned long _IFUNC Release();
    virtual HRESULT				_IFUNC QueryInterface(const GUID far& iid, void far*far* iface);
    // ILibExternalObject
    virtual BOOL _IFUNC Lib_Move()        { return TRUE; }  
    virtual BOOL _IFUNC Lib_Rotate()      { return TRUE; }
    virtual BOOL _IFUNC Lib_Transform()   { return TRUE; } 
    virtual BOOL _IFUNC Lib_Delete()      { return TRUE; }
    virtual BOOL _IFUNC Lib_Restore()     { return TRUE; }
    virtual BOOL _IFUNC Lib_Deform()      { return TRUE; } 
    virtual BOOL _IFUNC Lib_AddToModel()  { return TRUE; }
};


//------------------------------------------------------------------------------
// AddRef
// ---
unsigned long _IFUNC HPObj::AddRef() 
{
  count++;
  return count;
}


//------------------------------------------------------------------------------
// Release
// ---
unsigned long _IFUNC HPObj::Release() 
{
  if ( count ) 
    count--;
  if( !count )
    delete this;
  return count;
}


//------------------------------------------------------------------------------
// QueryInterface
// ---
HRESULT _IFUNC HPObj::QueryInterface( const GUID far& iid, void far*far* iface )
{
  if ( iid == IID_ILibHPObject ) 
  {
    *iface = this;
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


//-------------------------------------------------------------------------------
// Создает соответствующий объект для работы с Hot точками
// ---
void WINAPI LibObjInterfaceEntry( int idType, unsigned int comm, ILibHPObject** object ) 
{
  if ( object ) 
  {
    if ( idType == 1 || idType == 2 )  // Если не Hot точки обнулить
    { 

    }
  }
}  
