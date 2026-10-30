////////////////////////////////////////////////////////////////////////////////
//
// step3D3.cpp - Конструктивные оси и плоскости
// 
// 1. Конструктивная ось операции                  - ConstrAxisOperations 
// 2. Конструктивная ось по двум точкам            - ConstrAxis2Point    
// 3. Конструктивная ось, проходящая через ребро   - ConstrAxisEdge      
// 4. Смещенная плоскость, ось по двум плоскостям, 
//    плоскость под углом к другой плоскости       - ConstrElem   
// 5. Плоскость через три вершины                  - ConstrPlane3Point   
//
////////////////////////////////////////////////////////////////////////////////
#ifndef VCL_H
#include <vcl.h>
#endif

#ifndef __WINDOWS_
#include <windows.h>
#endif

#ifndef __STDIO_H
#include <stdio.h>
#endif

#ifndef  __MATH_H
#include <math.h>
#endif

#pragma hdrstop

#include <objbase.h>
#include <initguid.h>

#ifndef __STEP3D3_RH
#include "step3D3.rh"
#endif

#ifndef __STEP3D3_H
#include "step3D3.h"
#endif

#include "ksConstants.h"


#if !defined(_IFUNC)
# define _IFUNC STDMETHODCALLTYPE
#endif

HINSTANCE _hinst;

//------------------------------------------------------------------------------
// в Win32 линкуется SDK/lib/kAPI2D5bc.lib и kAPI3D5bc.lib
// в x64 линкуется SDK/lib64/kAPI2D5bc.a и kAPI3D5bc.a
// ---
#pragma comment(lib, "kAPI2D5bc")
#pragma comment(lib, "kAPI3D5bc")

//------------------------------------------------------------------------------
// Загрузить строку из ресурса
// ---
LPTSTR _LoadStr( int id )
{
	static TCHAR buf[512];
	// Конвертировать строку в соответствии с текущим словарем
	ksConvertLangStrExT( _hinst, id, buf, 512 );
	return buf;
}


//-------------------------------------------------------------------------------
// Задать идентификатор ресурсов
// ---
extern "C" unsigned int far __export __stdcall LIBRARYID()
{
	return IDR_LIBID;
}


//-------------------------------------------------------------------------------
// Описания используемых функций
// ---
void ConstrAxisOperations( Kompas6api3d5com_tlb::IPartPtr & part );
void ConstrAxis2Point    ( Kompas6api3d5com_tlb::IPartPtr & part );
void ConstrAxisEdge      ( Kompas6api3d5com_tlb::IPartPtr & part );
void ConstrPlane3Point   ( Kompas6api3d5com_tlb::IPartPtr & part );
void ConstrElem          ( Kompas6api3d5com_tlb::IPartPtr & part );


//-------------------------------------------------------------------------------
// Головная функция библиотеки
// ---
extern "C" void far __export __stdcall LIBRARYENTRY( unsigned int comm )
{
  Kompas6api3d5com_tlb::IDocument3DPtr pDocument3d( ksGetActive3dDocument(), false/*AddRef*/ ); // Получить указатель на активный документ трехмерной модели
  if ( pDocument3d )
  {
    // Получить указатель на интерфейс компонента в соответствии с заданным типом ( pNew_Part - новая деталь,
    // pEdit_Part - редактируемая деталь, pTop_Part  - верхний компонент )
    Kompas6api3d5com_tlb::IPartPtr part( pDocument3d->GetPart( pTop_Part ), false/*AddRef*/ );
    if ( part )
    {
      switch ( comm )
      {
        case 1  : ConstrAxisOperations( part ); break; // Конструктивная ось операции
        case 2  : ConstrAxis2Point    ( part ); break; // Конструктивная ось по двум точкам
        case 3  : ConstrAxisEdge      ( part ); break; // Конструктивная ось, проходящая через ребро
        case 4  : ConstrElem          ( part ); break; // Смещенная плоскость, ось по двум плоскостям, плоскость под углом к другой пло-ти
        case 5  : ConstrPlane3Point   ( part ); break; // Плоскость через три вершины
      }
    }
  }
  else
  {
    ErrorT( _LoadStr( STR_3DDOCERROR ) ); // Документ не активизирован или не является 3D-моделью
  }
  if ( ReturnResult() == etError10 ) // Ошибка! Вырожденный объект
    ResultNULL(); // Обнулить ошибки
}


//-------------------------------------------------------------------------------
// Конструктивная ось операции
// ---
void ConstrAxisOperations( Kompas6api3d5com_tlb::IPartPtr & part )
{
  // Создадим новый эскиз
  Kompas6api3d5com_tlb::IEntityPtr entitySketch( part->NewEntity( o3d_sketch ), false/*AddRef*/ );
  if ( entitySketch )
  {
    // Получить указатель на интерфейс параметров объектов и элементов
    IUnknownPtr pDefinitionSketch( entitySketch->GetDefinition(), false/*AddRef*/ );
    // Интерфейс свойств эскиза
    Kompas6api3d5com_tlb::ISketchDefinitionPtr sketchDefinition( pDefinitionSketch );
    if ( sketchDefinition )
    {
      // Получим интерфейс базовой плоскости XOY
      Kompas6api3d5com_tlb::IEntityPtr basePlane( part->GetDefaultEntity( o3d_planeXOY ), false/*AddRef*/ );

      // Установка параметров эскиза
      sketchDefinition->SetPlane( basePlane ); // Установим плоскость XOY базовой для эскиза

      // Создадим эскиз
      entitySketch->Create();

      // Войти в режим редактирования эскиза
      if ( sketchDefinition->BeginEdit() )
      {
        // Введем новый эскиз
        Circle( 20, 0, 10, 1 );
        LineSeg( 0, 0, 0, 5, 3 );
        // Выйти из режима редактирования эскиза
        sketchDefinition->EndEdit();
      }

      // Операция вращения
      Kompas6api3d5com_tlb::IEntityPtr entityRotate( part->NewEntity( o3d_bossRotated ), false/*AddRef*/ );
      if ( entityRotate )
      {
        // Получить указатель на интерфейс параметров объектов и элементов
        IUnknownPtr pDefinitionRotate( entityRotate->GetDefinition(), false /*AddRef*/ );
        // Интерфейс базовой операции вращения
        Kompas6api3d5com_tlb::IBossRotatedDefinitionPtr baseRotatedDefinition( pDefinitionRotate );
        if ( baseRotatedDefinition )
        {
          // Параметры базовой операции вращения
          Kompas6api3d5com_tlb::IRotatedParamPtr rotatedParam( baseRotatedDefinition->RotatedParam(), false/*AddRef*/ );
          if ( rotatedParam )
          {
            rotatedParam->SetDirection( dtBoth );  // Направление вращения ( dtNormal	- прямое направление,
                                                   // dtReverse - обратное направление, dtBoth - в обе стороны,
                                                   // dtMiddlePlane - от средней плоскости )
            rotatedParam->SetToroidShape( false ); // Признак тороида ( TRUE - тороид, FALSE - сфероид )
          }
          // Изменить параметры тонкой стенки элемента
          baseRotatedDefinition->SetThinParam( true,   // Признак тонкостенной операции
                                               dtBoth, // Направление построения тонкой стенки ( dtNormal	- прямое направление,
                                                       // dtReverse - обратное направление, dtBoth - в обе стороны,
                                                       // dtMiddlePlane - от средней плоскости )
                                               1,      // Толщина стенки в прямом направлении
                                               1 );    // Толщина стенки в обратном направлении
          // Изменить параметры вращения в одном направлении
          baseRotatedDefinition->SetSideParam( true,   // Направление вращения ( TRUE - прямое, FALSE - обратное )
                                               180 );  // Угол вращения
          baseRotatedDefinition->SetSideParam( false, 180 );
          baseRotatedDefinition->SetSketch( entitySketch ); // Эскиз операции вращения
          entityRotate->Create(); // Создать операцию вращения
        }
      }

      // Создадим ось операции
      Kompas6api3d5com_tlb::IEntityPtr entityAxisOperation( part->NewEntity( o3d_axisOperation ), false/*AddRef*/  );
      if ( entityAxisOperation )
      {
        // Получить указатель на интерфейс параметров объектов и элементов
        IUnknownPtr pDefinitionAxisOperation( entityAxisOperation->GetDefinition(), false/*AddRef*/  );
        // Интерфейс оси операции
        Kompas6api3d5com_tlb::IAxisOperationsDefinitionPtr axisOperationsDefinition( pDefinitionAxisOperation );
        if ( axisOperationsDefinition )
        {
          axisOperationsDefinition->SetOperation( entityRotate ); // Изменить базовый формообразующий элемент
          entityAxisOperation->Create(); // Cоздать ось операции
        }
      }
      MessageT( _T("Ось операции") );
    }
  }
}


//-------------------------------------------------------------------------------
// Конструктивная ось по двум точкам
// ---
void ConstrAxis2Point( Kompas6api3d5com_tlb::IPartPtr & part )
{
  // Создадим новый эскиз
  Kompas6api3d5com_tlb::IEntityPtr entitySketch( part->NewEntity( o3d_sketch ), false/*AddRef*/ );
  if ( entitySketch )
  {
    // Получить указатель на интерфейс параметров объектов и элементов
    IUnknownPtr pDefinitionSketch( entitySketch->GetDefinition(), false/*AddRef*/ );
    // Интерфейс свойств эскиза
    Kompas6api3d5com_tlb::ISketchDefinitionPtr sketchDefinition( pDefinitionSketch );
    if ( sketchDefinition )
    {
      // Получим интерфейс базовой плоскости XOY
      Kompas6api3d5com_tlb::IEntityPtr basePlane( part->GetDefaultEntity( o3d_planeXOY ), false/*AddRef*/ );

      // Установка параметров эскиза
      sketchDefinition->SetPlane( basePlane ); // Установим плоскость XOY базовой для эскиза

      // Создадим эскиз
      entitySketch->Create();

      // Войти в режим редактирования эскиза
      if ( sketchDefinition->BeginEdit() )
      {
        // Введем новый эскиз - квадрат
        LineSeg(  50,  50, -50,  50, 1 );
        LineSeg(  50, -50, -50, -50, 1 );
        LineSeg(  50, -50,  50,  50, 1 );
        LineSeg( -50, -50, -50,  50, 1 );
        // Выйти из режима редактирования эскиза
        sketchDefinition->EndEdit();
      }

      // Базовая операция выдавливания
      Kompas6api3d5com_tlb::IEntityPtr entityExtrusion( part->NewEntity( o3d_bossExtrusion ), false/*AddRef*/ );
      if ( entityExtrusion )
      {
        // Получить указатель на интерфейс параметров объектов и элементов
        IUnknownPtr pDefinitionExtrusion( entityExtrusion->GetDefinition(), false/*AddRef*/ );
        // Интерфейс базовой операции выдавливания
        Kompas6api3d5com_tlb::IBossExtrusionDefinitionPtr baseExtrusionDefinition( pDefinitionExtrusion );
        if ( baseExtrusionDefinition )
        {
          baseExtrusionDefinition->SetDirectionType( dtNormal );  // Направление выдавливания ( dtNormal	- прямое направление,
                                                                  // dtReverse - обратное направление, dtBoth - в обе стороны,
                                                                  // dtMiddlePlane - от средней плоскости )
          // Изменить параметры выдавливания в одном направлении
          baseExtrusionDefinition->SetSideParam( true,    // Направление выдавливания ( TRUE - прямое направление, FALSE - обратное направление )
                                                 etBlind, // Тип выдавливания ( etBlind	- строго на глубину,
                                                          // etThroughAll - через всю деталь, etUpToVertexTo - на расстояние до вершины,
                                                          // etUpToVertexFrom - на расстояние за вершину, etUpToSurfaceTo	- на расстояние до поверхности,
                                                          // etUpToSurfaceFrom	- на расстояние за поверхность, etUpToNearSurface	- до ближайшей поверхности )
                                                 20,      // Глубина выдавливания
                                                 0,       // Угол уклона
                                                 false ); // Направление уклона ( TRUE - уклон наружу, FALSE - уклон внутрь )
          // Изменить параметры тонкой стенки элемента
          baseExtrusionDefinition->SetThinParam( true,   // Признак тонкостенной операции
                                                 dtBoth, // Направление построения тонкой стенки ( dtNormal	- прямое направление,
                                                         // dtReverse - обратное направление, dtBoth - в обе стороны,
                                                         // dtMiddlePlane - от средней плоскости )
                                                 20,     // Толщина стенки в прямом направлении
                                                 20 );   // Толщина стенки в обратном направлении
          baseExtrusionDefinition->SetSketch( entitySketch ); // Эскиз операции выдавливания
          entityExtrusion->Create(); // Создать операцию выдавливания
        }
      }
    }

    // Ось по двум точкам
    // Формирует массив объектов и возвращает указатель на его интерфейс - массив вершин компонента
    Kompas6api3d5com_tlb::IEntityCollectionPtr entityCollection( part->EntityCollection( o3d_vertex ), false/*AddRef*/ );
    if ( (bool)entityCollection && entityCollection->GetCount() )
    {
      // Создадим ось по двум точкам
      Kompas6api3d5com_tlb::IEntityPtr entityAxis2Point( part->NewEntity( o3d_axis2Points ), false/*AddRef*/ );
      if ( entityAxis2Point )
      {
        // Получить указатель на интерфейс параметров объектов и элементов
        IUnknownPtr pDefinitionAxis2Point( entityAxis2Point->GetDefinition(), false/*AddRef*/ );
        // Интерфейс вспомогательной оси, проходящей через две точки
        Kompas6api3d5com_tlb::IAxis2PointsDefinitionPtr axis2PointsDefinition( pDefinitionAxis2Point );
        if ( axis2PointsDefinition )
        {
          // Изменить указатель на интерфейс точки с указанным номером
          axis2PointsDefinition->SetPoint( 1,                                   // Номер точки (1 или 2)
                                              Kompas6api3d5com_tlb::IEntityPtr(entityCollection->GetByIndex( 0 ), false/*AddRef*/) ); // Указатель на интерфейс точки
          axis2PointsDefinition->SetPoint( 2, Kompas6api3d5com_tlb::IEntityPtr(entityCollection->GetByIndex( entityCollection->GetCount()- 1 ), false/*AddRef*/) );
          entityAxis2Point->Create(); // Создать вспомогательную ось, проходящюю через две точки
        }
      }
    }
  }
}


//-------------------------------------------------------------------------------
// Конструктивная ось, проходящая через ребро
// ---
void ConstrAxisEdge( Kompas6api3d5com_tlb::IPartPtr & part )
{
  // Создадим новый эскиз
  Kompas6api3d5com_tlb::IEntityPtr entitySketch( part->NewEntity( o3d_sketch ), false/*AddRef*/ );
  if ( entitySketch )
  {
    // Получить указатель на интерфейс параметров объектов и элементов
    IUnknownPtr pDefinitionSketch( entitySketch->GetDefinition(), false/*AddRef*/ );
    // Интерфейс свойств эскиза
    Kompas6api3d5com_tlb::ISketchDefinitionPtr sketchDefinition( pDefinitionSketch );
    if ( sketchDefinition )
    {
      // Получим интерфейс базовой плоскости XOY
      Kompas6api3d5com_tlb::IEntityPtr basePlane( part->GetDefaultEntity( o3d_planeXOY ), false/*AddRef*/ );

      // Установка параметров эскиза
      sketchDefinition->SetPlane( basePlane ); // Установим плоскость XOY базовой для эскиза

      // Создадим эскиз
      entitySketch->Create();

      // Войти в режим редактирования эскиза
      if ( sketchDefinition->BeginEdit() )
      {
        // Введем новый эскиз - квадрат
        LineSeg(  50,  50, -50,  50, 1 );
        LineSeg(  50, -50, -50, -50, 1 );
        LineSeg(  50, -50,  50,  50, 1 );
        LineSeg( -50, -50, -50,  50, 1 );
        // Выйти из режима редактирования эскиза
        sketchDefinition->EndEdit();
      }

      // Базовая операция выдавливания
      Kompas6api3d5com_tlb::IEntityPtr entityExtrusion( part->NewEntity( o3d_bossExtrusion ), false/*AddRef*/ );
      if ( entityExtrusion )
      {
        // Получить указатель на интерфейс параметров объектов и элементов
        IUnknownPtr pDefinitionExtrusion( entityExtrusion->GetDefinition(), false/*AddRef*/ );
        // Интерфейс базовой операции выдавливания
        Kompas6api3d5com_tlb::IBossExtrusionDefinitionPtr baseExtrusionDefinition( pDefinitionExtrusion );
        if ( baseExtrusionDefinition )
        {
          baseExtrusionDefinition->SetDirectionType( dtNormal );  // Направление выдавливания ( dtNormal	- прямое направление,
                                                                  // dtReverse - обратное направление, dtBoth - в обе стороны,
                                                                  // dtMiddlePlane - от средней плоскости )
          // Изменить параметры выдавливания в одном направлении
          baseExtrusionDefinition->SetSideParam( true,    // Направление выдавливания ( TRUE - прямое направление, FALSE - обратное направление )
                                                 etBlind, // Тип выдавливания ( etBlind	- строго на глубину,
                                                          // etThroughAll - через всю деталь, etUpToVertexTo - на расстояние до вершины,
                                                          // etUpToVertexFrom - на расстояние за вершину, etUpToSurfaceTo	- на расстояние до поверхности,
                                                          // etUpToSurfaceFrom	- на расстояние за поверхность, etUpToNearSurface	- до ближайшей поверхности )
                                                 20,      // Глубина выдавливания
                                                 0,       // Угол уклона
                                                 false ); // Направление уклона ( TRUE - уклон наружу, FALSE - уклон внутрь )
          // Изменить параметры тонкой стенки элемента
          baseExtrusionDefinition->SetThinParam( true,   // Признак тонкостенной операции
                                                 dtBoth, // Направление построения тонкой стенки ( dtNormal	- прямое направление,
                                                         // dtReverse - обратное направление, dtBoth - в обе стороны,
                                                         // dtMiddlePlane - от средней плоскости )
                                                 20,     // Толщина стенки в прямом направлении
                                                 20 );   // Толщина стенки в обратном направлении
          baseExtrusionDefinition->SetSketch( entitySketch ); // Эскиз операции выдавливания
          entityExtrusion->Create(); // Создать операцию выдавливания
        }
      }
    }

    // Ось через грань
    // Формирует массив объектов и возвращает указатель на его интерфейс - массив граней компонента
    Kompas6api3d5com_tlb::IEntityCollectionPtr entityCollection( part->EntityCollection( o3d_edge ), false/*AddRef*/ );
    if ( (bool)entityCollection && entityCollection->GetCount() )
    {
      // Создадим ось через грань
      Kompas6api3d5com_tlb::IEntityPtr entityAxisEdge( part->NewEntity( o3d_axisEdge ), false/*AddRef*/ );
      if ( entityAxisEdge )
      {
        // Получить указатель на интерфейс параметров объектов и элементов
        IUnknownPtr pDefinitionAxisEdge( entityAxisEdge->GetDefinition(), false/*AddRef*/ );
        // Интерфейс вспомогательной оси, проходящей через прямолинейное ребро
        Kompas6api3d5com_tlb::IAxisEdgeDefinitionPtr axisEdgeDefinition( pDefinitionAxisEdge );
        if ( axisEdgeDefinition )
        {
          // Изменить указатель на интерфейс базового ребра
          axisEdgeDefinition->SetEdge( Kompas6api3d5com_tlb::IEntityPtr(entityCollection->GetByIndex( 0 ), false/*Addef*/) );
          entityAxisEdge->Create(); // Создать вспомогательную ось, проходящюю через прямолинейное ребро
        }
      }
    }
  }
}


//-------------------------------------------------------------------------------
// Плоскость через три вершины
// ---
void ConstrPlane3Point( Kompas6api3d5com_tlb::IPartPtr & part )
{
  // Создадим новый эскиз
  Kompas6api3d5com_tlb::IEntityPtr entitySketch( part->NewEntity( o3d_sketch ), false/*Addef*/ );
  if ( entitySketch )
  {
    // Получить указатель на интерфейс параметров объектов и элементов
    IUnknownPtr pDefinitionSketch( entitySketch->GetDefinition(), false/*Addef*/ );
    if ( pDefinitionSketch )
    {
      // Интерфейс свойств эскиза
      Kompas6api3d5com_tlb::ISketchDefinitionPtr sketchDefinition( pDefinitionSketch );
      if ( sketchDefinition )
      {
        // Получим интерфейс базовой плоскости XOY
        Kompas6api3d5com_tlb::IEntityPtr basePlane( part->GetDefaultEntity( o3d_planeXOY ), false/*Addef*/ );

        // Установка параметров эскиза
        sketchDefinition->SetPlane( basePlane ); // Установим плоскость XOY базовой для эскиза

        // Создадим эскиз
        entitySketch->Create();

        // Войти в режим редактирования эскиза
        if ( sketchDefinition->BeginEdit() )
        {
          // Введем новый эскиз - квадрат
          LineSeg(  50,  50, -50,  50, 1 );
          LineSeg(  50, -50, -50, -50, 1 );
          LineSeg(  50, -50,  50,  50, 1 );
          LineSeg( -50, -50, -50,  50, 1 );
          // Выйти из режима редактирования эскиза
          sketchDefinition->EndEdit();
        }

        // Базовая операция выдавливания
        Kompas6api3d5com_tlb::IEntityPtr entityExtrusion( part->NewEntity( o3d_bossExtrusion ), false/*Addef*/ );
        if ( entityExtrusion )
        {
          // Получить указатель на интерфейс параметров объектов и элементов
          IUnknownPtr pDefinitionExtrusion( entityExtrusion->GetDefinition(), false/*Addef*/ );
          // Интерфейс базовой операции выдавливания
          Kompas6api3d5com_tlb::IBossExtrusionDefinitionPtr baseExtrusionDefinition( pDefinitionExtrusion );
          if ( baseExtrusionDefinition )
          {
            baseExtrusionDefinition->SetDirectionType( dtNormal );  // Направление выдавливания ( dtNormal	- прямое направление,
                                                                    // dtReverse - обратное направление, dtBoth - в обе стороны,
                                                                    // dtMiddlePlane - от средней плоскости )
            // Изменить параметры выдавливания в одном направлении
            baseExtrusionDefinition->SetSideParam( true,    // Направление выдавливания ( TRUE - прямое направление, FALSE - обратное направление )
                                                   etBlind, // Тип выдавливания ( etBlind	- строго на глубину,
                                                            // etThroughAll - через всю деталь, etUpToVertexTo - на расстояние до вершины,
                                                            // etUpToVertexFrom - на расстояние за вершину, etUpToSurfaceTo	- на расстояние до поверхности,
                                                            // etUpToSurfaceFrom	- на расстояние за поверхность, etUpToNearSurface	- до ближайшей поверхности )
                                                   20,      // Глубина выдавливания
                                                   30,      // Угол уклона
                                                   false ); // Направление уклона ( TRUE - уклон наружу, FALSE - уклон внутрь )
            // Изменить параметры тонкой стенки элемента
            baseExtrusionDefinition->SetThinParam( true,   // Признак тонкостенной операции
                                                   dtBoth, // Направление построения тонкой стенки ( dtNormal	- прямое направление,
                                                           // dtReverse - обратное направление, dtBoth - в обе стороны,
                                                           // dtMiddlePlane - от средней плоскости )
                                                   10,     // Толщина стенки в прямом направлении
                                                   10 );   // Толщина стенки в обратном направлении
            baseExtrusionDefinition->SetSketch( entitySketch ); // Эскиз операции выдавливания
            entityExtrusion->Create(); // Создать операцию выдавливания
          }
        }
      }
    }

    // Плоскость через три вершины
    // Формирует массив объектов и возвращает указатель на его интерфейс - массив вершин компонента
    Kompas6api3d5com_tlb::IEntityCollectionPtr entityCollection( part->EntityCollection( o3d_vertex ), false/*Addef*/ );
    if ( (bool)entityCollection && entityCollection->GetCount() > 2 )
    {
      // Создадим плоскость, проходящюю через три вершины
      Kompas6api3d5com_tlb::IEntityPtr entityPlane3Point( part->NewEntity( o3d_plane3Points ), false/*Addef*/ );
      if ( entityPlane3Point )
      {
        // Получить указатель на интерфейс параметров объектов и элементов
        IUnknownPtr pDefinitionPlane3Point( entityPlane3Point->GetDefinition(), false/*Addef*/ );
        // Интерфейс плоскости, проходящей через три вершины
        Kompas6api3d5com_tlb::IPlane3PointsDefinitionPtr plane3PointDefinition( pDefinitionPlane3Point );
        if ( plane3PointDefinition )
        {
          // Изменить указатель на интерфейс точки с указанным номером
          plane3PointDefinition->SetPoint( 1,                                    // Номер точки (от 1 до 3)
                                              Kompas6api3d5com_tlb::IEntityPtr(entityCollection->GetByIndex( 0 ), false/*AddRef*/) );  // Указатель на интерфейс точки
          plane3PointDefinition->SetPoint( 2, Kompas6api3d5com_tlb::IEntityPtr(entityCollection->GetByIndex( 1 ), false/*AddRef*/) );
          plane3PointDefinition->SetPoint( 3, Kompas6api3d5com_tlb::IEntityPtr(entityCollection->GetByIndex( 2 ), false/*AddRef*/) );
          entityPlane3Point->Create(); // Создать плоскость, проходящюю через три вершины
        }
      }
    }
  }
}


//-------------------------------------------------------------------------------
// Создание смещенной плоскости, оси по двум плоскостям и плоскости под углом к заданной
// ---
void ConstrElem( Kompas6api3d5com_tlb::IPartPtr & part )
{
  // Создадим смещенную плоскость
  Kompas6api3d5com_tlb::IEntityPtr entityPlaneOffset( part->NewEntity( o3d_planeOffset ), false/*AddRef*/ );
  if ( entityPlaneOffset )
  {
    // Получить указатель на интерфейс параметров объектов и элементов
    IUnknownPtr pDefinitionPlaneOffset( entityPlaneOffset->GetDefinition(), false/*AddRef*/ );
    // Интерфейс свойств смещенной плоскости
    Kompas6api3d5com_tlb::IPlaneOffsetDefinitionPtr planeOffsetDefinition( pDefinitionPlaneOffset );
    if ( planeOffsetDefinition )
    {
      // Установка параметров смещенной плоскости
      planeOffsetDefinition->SetOffset( 150 ); // Расстояние от базовой плоскости

      // Получим интерфейс базовой плоскости XOY
      Kompas6api3d5com_tlb::IEntityPtr basePlane( part->GetDefaultEntity( o3d_planeXOY ), false/*AddRef*/ );
      basePlane->SetName( L"XOY" ); // Название для базовой плоскости
      basePlane->_Update(); // Обновить параметры базовой плоскости

      planeOffsetDefinition->SetPlane( basePlane ); // Установим плоскость XOY базовой для плоскости

      planeOffsetDefinition->SetDirection( false ); // Направление смещения от базовой плоскости ( TRUE - прямое направление, FALSE - обратное направление )
      entityPlaneOffset->SetName( L"Смещенная плоскость" ); // Имя для смещенной плоскости

      entityPlaneOffset->Create(); // Создать смещенную плоскость

      MessageT( _T("Изменим параметры смещенной плоскости") );
      planeOffsetDefinition->SetOffset( 50 ); // Изменим расстояние до базовой плоскости
      // Возьмем другую базовую плоскость YOZ
      basePlane.Bind( part->GetDefaultEntity( o3d_planeYOZ ), false/*AddRef*/ );
      basePlane->SetName( L"YOZ" ); // Название для базовой плоскости
      basePlane->_Update(); // Обновить параметры базовой плоскости

      planeOffsetDefinition->SetPlane( basePlane ); // Установим плоскость YOZ базовой для плоскости
      planeOffsetDefinition->SetDirection( true );        // Изменим направления смещения относительно базовой плоскости

      entityPlaneOffset->_Update(); // Обновить параметры смещенной плоскости

			MessageT( _T("На пересечении плоскостей построим ось") );

      // Возьмем другую базовую плоскость XOY
      basePlane.Bind( part->GetDefaultEntity( o3d_planeXOY ), false/*AddRef*/ );
      basePlane->SetName( L"XOY" ); // Название для базовой плоскости
      basePlane->_Update(); // Обновить параметры базовой плоскости

      // Ось на пересечении двух плоскостей
      Kompas6api3d5com_tlb::IEntityPtr entityAxis2Planes( part->NewEntity( o3d_axis2Planes ), false/*AddRef*/ );
      if ( entityAxis2Planes )
      {
        // Получить указатель на интерфейс параметров объектов и элементов
        IUnknownPtr pDefinitionAxis2Planes( entityAxis2Planes->GetDefinition(), false/*AddRef*/ );
        // Интерфейс вспомогательной оси, проходящей через две плоскости
        Kompas6api3d5com_tlb::IAxis2PlanesDefinitionPtr axis2PlanesDefinition( pDefinitionAxis2Planes );
        if ( axis2PlanesDefinition )
        {
          axis2PlanesDefinition->SetPlane( 1, entityPlaneOffset ); // Первая базовая плоскость - смещенная плоскость
          axis2PlanesDefinition->SetPlane( 2, basePlane         ); // Вторая базовая плоскость - плоскость XOY
          entityAxis2Planes->SetName( L"Ось по двум плоскостям" ); // Имя вспомогательной оси
          entityAxis2Planes->Create();  // Создать ось, проходящюю через две плоскости

					MessageT( _T("Поменяем одну из базовых плоскостей для построения оси") );

          // Возьмем другую базовую плоскость XOZ
          basePlane.Bind( part->GetDefaultEntity( o3d_planeXOZ ), false/*AddRef*/ );
          basePlane->SetName( L"XOZ" ); // Название для базовой плоскости
          basePlane->_Update(); // Обновить параметры базовой плоскости

          axis2PlanesDefinition->SetPlane( 2, basePlane ); // Вторая базовая плоскость - плоскость XOZ
          entityAxis2Planes->_Update(); // Обновить параметры вспомогательной оси

					MessageT( _T("Через смещенную плоскость и построенную ось\nпроведем плоскость под углом 45") );

          // Создадим плоскость под углом к другой плоскости
          Kompas6api3d5com_tlb::IEntityPtr entityPlaneAngle( part->NewEntity( o3d_planeAngle ), false/*AddRef*/ );
          if ( entityPlaneAngle )
          {
            // Получить указатель на интерфейс параметров объектов и элементов
            IUnknownPtr pDefinitionPlaneAngle( entityPlaneAngle->GetDefinition(), false/*AddRef*/ );
            // Интерфейс плоскости под углом к другой плоскости
            Kompas6api3d5com_tlb::IPlaneAngleDefinitionPtr planeAngleDefinition( pDefinitionPlaneAngle );
            if ( planeAngleDefinition )
            {
              planeAngleDefinition->SetAngle( 45 ); // Угол наклона к базовой плоскости
              planeAngleDefinition->SetPlane( entityPlaneOffset ); // Базовая плоскость - смещенная плоскость
              planeAngleDefinition->SetAxis ( entityAxis2Planes ); // Базовая ось - ось, проходящей через две плоскости
              entityPlaneAngle->SetName( L"Плоскость под углом к другой плоскости" );  // Имя вспомогательной плоскости
              entityPlaneAngle->Create(); // Создать плоскость под углом к другой плоскости

							MessageT( _T("Изменим одну из базовых плоскостей") );

              planeAngleDefinition->SetPlane( basePlane ); // Установим плоскость XOZ базовой для плоскости
              entityPlaneAngle->_Update(); // Обновить параметры вспомогательной плоскости
            }
          }
        }
      }
    }
  }
}
