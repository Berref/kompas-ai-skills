// ResourceModuleChanger.h: interface for the ResourceModuleChanger class.
//
//////////////////////////////////////////////////////////////////////

#ifndef __RESOURCEMODULECHANGER_H
#define __RESOURCEMODULECHANGER_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

///////////////////////////////////////////////////////////////////////////////
// 
// ИР K6 класс для управления значением модуля ресурсов
//
///////////////////////////////////////////////////////////////////////////////
class ResourceModuleChanger 
{
  HINSTANCE defModule;

public:
  // запоминает предыдущее значение модуля ресурсов
  // и устанавливает новое
  ResourceModuleChanger( HINSTANCE mod ) 
    : defModule( ::AfxGetResourceHandle() ) 
  { 
    ::AfxSetResourceHandle( mod ); 
  }

  // восстанавливает предыдущее значение модуля ресурсов
  ~ResourceModuleChanger() 
  { 
    ::AfxSetResourceHandle( defModule );  
  }

private:
  ResourceModuleChanger( const ResourceModuleChanger & rc ); // не реализован
  void operator =      ( const ResourceModuleChanger & rc ); // не реализован
};


//-----------------------------------------------------------------------------
// управлениt значением модуля ресурсов
//---
#define RESOURCE_MODULE_CHANGE(mod) ResourceModuleChanger def_resourceModuleChanger(mod)

#endif // !defined(__RESOURCEMODULECHANGER_H)
