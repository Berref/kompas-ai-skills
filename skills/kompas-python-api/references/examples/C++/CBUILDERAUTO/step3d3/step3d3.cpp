//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <windows.h>
#include <stdio.h>

#include <ldefin2d.h>
#include <ldefin3d.h>
#include <ksConstants.h>

#ifdef __LIGHT_VERSION__
#include <Kl_TLB.h>
#else
#include <Ks_TLB.h>
#endif

#ifdef _WIN64
 #define __TODO__ " TODO: "
 #define __WARN__ " warning: "
#else
#define __ANYTOSTR__(x) #x
#define __DEFTOSTR__(x) __ANYTOSTR__(x)
#define __TODO__ __FILE__ "("__DEFTOSTR__(__LINE__)") : TODO: "
#define __WARN__ __FILE__ "("__DEFTOSTR__(__LINE__)") : warning: "
#endif

#ifdef VARIANT_COPIES_BSTR
  inline wchar_t * TO_OLE(wchar_t *x) { return x; }
  inline wchar_t * TO_OLE(char    *x) { return WideString(x).c_bstr(); }
  inline wchar_t * TO_OLE(WideString & x) { return x.c_bstr(); }
#else
#pragma message(  __TODO__ "Рекомендуется добавить в настройки проекта определение VARIANT_COPIES_BSTR\n" )
// подробнее см http://sites.google.com/site/akxsolutions/articles/borland-c-dicom
  inline wchar_t * TO_OLE(wchar_t *x) { return WideString(x).Copy(); }
  inline wchar_t * TO_OLE(char    *x) { return WideString(x).Copy(); }
  inline wchar_t * TO_OLE(WideString & x) { return x.Copy(); }
#endif


//---------------------------------------------------------------------------
//   Important note about DLL memory management when your DLL uses the
//   static version of the RunTime Library:
//
//   If your DLL exports any functions that pass String objects (or structs/
//   classes containing nested Strings) as parameter or function results,
//   you will need to add the library MEMMGR.LIB to both the DLL project and
//   any other projects that use the DLL.  You will also need to use MEMMGR.LIB
//   if any other projects which use the DLL will be performing new or delete
//   operations on any non-TObject-derived classes which are exported from the
//   DLL. Adding MEMMGR.LIB to your project will change the DLL and its calling
//   EXE's to use the BORLNDMM.DLL as their memory manager.  In these cases,
//   the file BORLNDMM.DLL should be deployed along with your DLL.
//
//   To avoid using BORLNDMM.DLL, pass string information using "char *" or
//   ShortString parameters.
//
//   If your DLL uses the dynamic version of the RTL, you do not need to
//   explicitly add MEMMGR.LIB as this will be done implicitly for you
//---------------------------------------------------------------------------

#pragma argsused
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void* lpReserved)
{
  return 1;
}

//------------------------------------------------------------------------------
// в Win32 линкуется SDK/lib/kAPI5bc.lib
// в x64 линкуется SDK/lib64/kAPI5bc.a
// ---
#pragma comment(lib, "kAPI5bc")
extern "C" IDispatch* far __export WINAPI CreateKompasObject();

KompasObjectPtr kompas;

//------------------------------------------------------------------------------
//
// ---
extern "C" unsigned int __export __stdcall LIBRARYID()
{
  return 100;
}

void ConstrAxisOperations( ksDocument3DPtr & doc );
void ConstrAxis2Point    ( ksDocument3DPtr & doc );
void ConstrAxisEdge      ( ksDocument3DPtr & doc );
void ConstrPlane3Point   ( ksDocument3DPtr & doc );
void CreateConstrElem    ( ksDocument3DPtr & doc );
void ConstrAxisConeface  ( ksDocument3DPtr & doc );
char buf[MAX_TEXT_LENGTH];

//------------------------------------------------------------------------------
//
// ---
extern "C" void far __export __stdcall  LIBRARYENTRY( unsigned int comm )
{
  kompas.Bind( (KompasObject*)::CreateKompasObject(), false/*AddRef*/ );
  if ( kompas ) {
    ksDocument3DPtr doc( (ksDocument3D*)kompas->ActiveDocument3D(), false/*AddRef*/ );
    if ( doc ) {
      switch ( comm ) {
        case 1  : ::ConstrAxisOperations( doc ); break; // Конструктивная ось операции
        case 2  : ::ConstrAxis2Point    ( doc ); break; // Конструктивная ось по двум точкам
        case 3  : ::ConstrAxisEdge      ( doc ); break; // Конструктивная ось, проходящая через ребро
        case 4  : ::ConstrAxisConeface  ( doc ); break; // Конструктивная ось конической грани
        case 5  : ::CreateConstrElem    ( doc ); break; // Смещенная плоскость, ось по двум плоскостям, плоскость под углом к другой пло-ти
        case 6  : ::ConstrPlane3Point   ( doc ); break; // Плоскость через три вершины
      }
    }
    else
      kompas->ksError( TO_OLE(L"3D документ не активизирован") );
    kompas.Unbind();
  }
}

//------------------------------------------------------------------------------
// Конструктивная ось операции
// ---
void ConstrAxisOperations( ksDocument3DPtr & doc ) {
  ksPartPtr part( (ksPart*)doc->GetPart(pTop_Part), false/*AddRef*/ ); // новый компонент
  if ( part ) {
    ksEntityPtr entitySketch( (ksEntity*)part->NewEntity(o3d_sketch), false/*AddRef*/ );
    if ( entitySketch ) {
      // интерфейс свойств эскиза
      ksSketchDefinitionPtr sketchDef( (ksSketchDefinition*)entitySketch->GetDefinition(), false/*AddRef*/ );
      if ( sketchDef ) {
        // получим интерфейс базовой плоскости XOY
        ksEntityPtr basePlane( (ksEntity*)part->GetDefaultEntity(o3d_planeXOY), false/*AddRef*/ );
        sketchDef->SetPlane( basePlane ); // установим плоскость XOY базовой для эскиза
        entitySketch->Create();           // создадим эскиз

        // интерфейс редактора эскиза
        ksDocument2DPtr sketchEdit( (ksDocument2D*)sketchDef->BeginEdit(), false/*AddRef*/ );
          sketchEdit->ksCircle ( 20, 0, 10, 1  );
          sketchEdit->ksLineSeg( 0, 0, 0, 5, 3 );
        sketchDef->EndEdit();                   // завершение редактирования эскиза

        ksEntityPtr entityRotate( (ksEntity*)part->NewEntity(o3d_bossRotated), false/*AddRef*/ );
        if ( entityRotate ) {
          ksBossRotatedDefinitionPtr rotateDef( (ksBossRotatedDefinition*)entityRotate->GetDefinition(), false/*AddRef*/ ); // интерфейс базовой операции вращения
          if ( rotateDef ) {
            ksRotatedParamPtr rotproperty( (ksRotatedParam*)rotateDef->RotatedParam(), false/*AddRef*/ );
            if ( rotproperty ) {
              rotproperty->direction   = dtBoth;
              rotproperty->toroidShape = false;
            }

            rotateDef->SetThinParam( true, dtBoth, 1, 1 ); // тонкая стенка в два направления
            rotateDef->SetSideParam( true, 180 );
            rotateDef->SetSideParam( false, 180 );
            rotateDef->SetSketch( entitySketch );          // эскиз операции вращения
            entityRotate->Create();                        // создать операцию
          }
        }
        // создадим операцию вырезания по сечениям
        ksEntityPtr entityAxisOperation( (ksEntity*)part->NewEntity(o3d_axisOperation), false/*AddRef*/ );
        if ( entityAxisOperation ) {
          ksAxisOperationsDefinitionPtr axisOperation( (ksAxisOperationsDefinition*)entityAxisOperation->GetDefinition(), false/*AddRef*/ );
          if ( axisOperation ) {
            axisOperation->SetOperation(entityRotate);
            entityAxisOperation->Create();                        // создать операцию
          }
        }
        kompas->ksMessage( TO_OLE(L"Ось операции") );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Конструктивная ось по двум точкам
// ---
void ConstrAxis2Point( ksDocument3DPtr & doc ) {
  ksPartPtr part( (ksPart*)doc->GetPart(pTop_Part), false/*AddRef*/ ); // новый компонент
  if ( part ) {
    ksEntityPtr entitySketch( (ksEntity*)part->NewEntity(o3d_sketch), false/*AddRef*/ );
    if ( entitySketch ) {
      // интерфейс свойств эскиза
      ksSketchDefinitionPtr sketchDef( (ksSketchDefinition*)entitySketch->GetDefinition(), false/*AddRef*/ );
      if ( sketchDef ) {
        // получим интерфейс базовой плоскости XOY
        ksEntityPtr basePlane( (ksEntity*)part->GetDefaultEntity(o3d_planeXOY), false/*AddRef*/ );
        sketchDef->SetPlane( basePlane ); // установим плоскость XOY базовой для эскиза
  //      sketchDef.SetAngle( 45 );        // угол поворота эскиза
        entitySketch->Create();           // создадим эскиз

        // интерфейс редактора эскиза
        ksDocument2DPtr sketchEdit( (ksDocument2D*)sketchDef->BeginEdit(), false/*AddRef*/ );
          // введем новый эскиз - квадрат
          sketchEdit->ksLineSeg(  50,  50, -50,  50, 1 );
          sketchEdit->ksLineSeg(  50, -50, -50, -50, 1 );

          sketchEdit->ksLineSeg(  50, -50,  50,  50, 1 );
          sketchEdit->ksLineSeg( -50, -50, -50,  50, 1 );
        sketchDef->EndEdit();                   // завершение редактирования эскиза

        ksEntityPtr entityExtr( (ksEntity*)part->NewEntity(o3d_bossExtrusion), false/*AddRef*/ );
        if ( entityExtr ) {
          // интерфейс свойств базовой операции выдавливания
          ksBossExtrusionDefinitionPtr extrusionDef( (ksBossExtrusionDefinition*)entityExtr->GetDefinition(), false/*AddRef*/ ); // интерфейс базовой операции выдавливания
          if ( extrusionDef ) {
            extrusionDef->directionType = dtNormal;             // направление выдавливания
            extrusionDef->SetSideParam( true/*прямое направление*/, etBlind/*строго на глубину*/, 20, 0, false );
            extrusionDef->SetThinParam( true, dtBoth, 20, 20 ); // тонкая стенка в два направления
            extrusionDef->SetSketch( entitySketch );            // эскиз операции выдавливания
            entityExtr->Create();                               // создать операцию
          }
        }
      }
    }

    ksEntityCollectionPtr entityCollection( (ksEntityCollection*)part->EntityCollection( o3d_vertex ), false/*AddRef*/ );

    // создадим ось по двум точкам
    ksEntityPtr entityAxis2Point( (ksEntity*)part->NewEntity(o3d_axis2Points), false/*AddRef*/ );
    if ( entityAxis2Point ) {
      ksAxis2PointsDefinitionPtr axis2Point( (ksAxis2PointsDefinition*)entityAxis2Point->GetDefinition(), false/*AddRef*/ );
      if ( axis2Point ) {
        axis2Point->SetPoint( 1, IDispatchPtr( entityCollection->GetByIndex(0), false/*AddRef*/) );
        axis2Point->SetPoint( 2, IDispatchPtr( entityCollection->GetByIndex(9), false/*AddRef*/) );
        entityAxis2Point->Create();
      }
    }
    kompas->ksMessage( TO_OLE(L"Ось через две точки") );
  }
}

//------------------------------------------------------------------------------
// Конструктивная ось, проходящая через ребро
// ---
void ConstrAxisEdge( ksDocument3DPtr & doc ) {
  ksPartPtr part( (ksPart*)doc->GetPart(pTop_Part), false/*AddRef*/ ); // новый компонент
  if ( part ) {
    ksEntityPtr entitySketch( (ksEntity*)part->NewEntity(o3d_sketch), false/*AddRef*/ );
    if ( entitySketch ) {
      // интерфейс свойств эскиза
      ksSketchDefinitionPtr sketchDef( (ksSketchDefinition*)entitySketch->GetDefinition(), false/*AddRef*/ );
      if ( sketchDef ) {
        // получим интерфейс базовой плоскости XOY
        ksEntityPtr basePlane( (ksEntity*)part->GetDefaultEntity(o3d_planeXOY), false/*AddRef*/ );
        sketchDef->SetPlane( basePlane ); // установим плоскость XOY базовой для эскиза
//          sketchDef.angle = 45;        // угол поворота эскиза
        entitySketch->Create();           // создадим эскиз

        // интерфейс редактора эскиза
        ksDocument2DPtr sketchEdit( (ksDocument2D*)sketchDef->BeginEdit(), false/*AddRef*/ );
          // введем новый эскиз - квадрат
          sketchEdit->ksLineSeg(  50,  50, -50,  50, 1 );
          sketchEdit->ksLineSeg(  50, -50, -50, -50, 1 );

          sketchEdit->ksLineSeg(  50, -50,  50,  50, 1 );
          sketchEdit->ksLineSeg( -50, -50, -50,  50, 1 );
        sketchDef->EndEdit();                   // завершение редактирования эскиза

        ksEntityPtr entityExtr( (ksEntity*)part->NewEntity(o3d_bossExtrusion), false/*AddRef*/ );
        if ( entityExtr ) {
          // интерфейс свойств базовой операции выдавливания
          ksBossExtrusionDefinitionPtr extrusionDef( (ksBossExtrusionDefinition*)entityExtr->GetDefinition(), false/*AddRef*/ ); // интерфейс базовой операции выдавливания
          if ( extrusionDef ) {
            extrusionDef->directionType = dtNormal;         // направление выдавливания
            extrusionDef->SetSideParam( true/*прямое направление*/, etBlind/*строго на глубину*/, 20, 0, false );
            extrusionDef->SetThinParam( true, dtBoth, 20, 20 ); // тонкая стенка в два направления
            extrusionDef->SetSketch( entitySketch ); // эскиз операции выдавливания
            entityExtr->Create();                    // создать операцию
          }
        }
      }
    }

    ksEntityCollectionPtr entityCollection( (ksEntityCollection*)part->EntityCollection( o3d_edge ), false/*AddRef*/ );

    if ( (bool)entityCollection && entityCollection->GetCount() > 1 ) {
      // создадим ось через грань
      ksEntityPtr entityAxisEdge( (ksEntity*)part->NewEntity(o3d_axisEdge), false/*AddRef*/ );
      if ( entityAxisEdge ) {
        ksAxisEdgeDefinitionPtr axisEdge( (ksAxisEdgeDefinition*)entityAxisEdge->GetDefinition(), false/*AddRef*/ );
        if ( axisEdge ) {
          axisEdge->SetEdge( IDispatchPtr(entityCollection->GetByIndex(0), false/*AddRef*/) );
          entityAxisEdge->Create();
        }
      }
      kompas->ksMessage( TO_OLE(L"Ось через грань") );

      // создадим еще ось через грань
      ksEntityPtr entityAxisEdge2( (ksEntity*)part->NewEntity(o3d_axisEdge), false/*AddRef*/ );
      if ( entityAxisEdge2 ) {
        ksAxisEdgeDefinitionPtr axisEdge( (ksAxisEdgeDefinition*)entityAxisEdge2->GetDefinition(), false/*AddRef*/ );
        if ( axisEdge ) {
          axisEdge->SetEdge( IDispatchPtr(entityCollection->GetByIndex(1), false/*AddRef*/) );
          entityAxisEdge2->Create();
        }
      }
      kompas->ksMessage( TO_OLE(L"Другая ось через грань") );
    }
  }
}


//------------------------------------------------------------------------------
// Конструктивная ось конической грани
// ---
void ConstrAxisConeface( ksDocument3DPtr & doc ) {
  ksPartPtr part( (ksPart *)doc->GetPart(pTop_Part), false/*AddRef*/ ); // новый компонент
  if ( part ) {
    ksEntityPtr entitySketch( (ksEntity*)part->NewEntity(o3d_sketch), false/*AddRef*/ );
    if ( entitySketch ) {
      // интерфейс свойств эскиза
      ksSketchDefinitionPtr sketchDef( (ksSketchDefinition*)entitySketch->GetDefinition(), false/*AddRef*/ );
      if ( sketchDef ) {
        // получим интерфейс базовой плоскости XOY
        ksEntityPtr basePlane( (ksEntity*)part->GetDefaultEntity(o3d_planeXOY), false/*AddRef*/ );
        sketchDef->SetPlane( basePlane ); // установим плоскость XOY базовой для эскиза
        entitySketch->Create();           // создадим эскиз

        // интерфейс редактора эскиза
        ksDocument2DPtr sketchEdit( (ksDocument2D*)sketchDef->BeginEdit(), false/*AddRef*/ );
          sketchEdit->ksCircle( 0, 0, 50, 1 );
        sketchDef->EndEdit();                   // завершение редактирования эскиза

        ksEntityPtr entityExtr( (ksEntity*)part->NewEntity(o3d_bossExtrusion), false/*AddRef*/ );
        if ( entityExtr ) {
          // интерфейс свойств базовой операции выдавливания
          ksBossExtrusionDefinitionPtr extrusionDef( (ksBossExtrusionDefinition*)entityExtr->GetDefinition(), false/*AddRef*/ ); // интерфейс базовой операции выдавливания
          if ( extrusionDef ) {
            extrusionDef->directionType = dtNormal;         // направление выдавливания
            extrusionDef->SetSideParam( true , etBlind, 20, 30, false );
            extrusionDef->SetThinParam( true, dtBoth, 10, 10 ); // тонкая стенка в два направления
            extrusionDef->SetSketch( entitySketch ); // эскиз операции выдавливания
            entityExtr->Create();                    // создать операцию
          }
        }
      }
    }

    ksEntityCollectionPtr entityCollection( (ksEntityCollection*)part->EntityCollection( o3d_face ), false/*AddRef*/ );
    ksEntityPtr entityConFace;

    for ( int i = 0, count = entityCollection->GetCount(); i < count; i++ ) {
      entityConFace.Bind( (ksEntity*)entityCollection->GetByIndex(i), false/*AddRef*/ );
      ksFaceDefinitionPtr face( (ksFaceDefinition *)entityConFace->GetDefinition(), false/*AddRef*/ );
      if ( face->IsCone() ) // если поверхность не коническая, берем следующую из массива
        break;
      entityConFace.Unbind();
    }


    // создадим ось через коническую поверхность
    ksEntityPtr entityAxisConFace( (ksEntity*)part->NewEntity(o3d_axisConeFace), false/*AddRef*/ );
    if ( entityAxisConFace ) {
      ksAxisConefaceDefinitionPtr axisConFace( (ksAxisConefaceDefinition*)entityAxisConFace->GetDefinition(), false/*AddRef*/ );
      if ( axisConFace ) {
        axisConFace->SetFace( entityConFace );
        entityAxisConFace->Create();
      }
    }
    kompas->ksMessage( TO_OLE(L"Ось через коническую поверхность") );
  }
}


//------------------------------------------------------------------------------
// Смещенная плоскость, ось по двум плоскостям, плоскость под углом к другой пло-ти
// ---
void CreateConstrElem( ksDocument3DPtr & doc ) {
  ksPartPtr part( (ksPart *)doc->GetPart(pTop_Part), false/*AddRef*/ ); // новый компонент
  if ( part ) {
    ksEntityPtr entity( (ksEntity*)part->NewEntity(o3d_planeOffset), false/*AddRef*/ );
    if ( entity ) {
      // интерфейс свойств смещенной плоскости
      ksPlaneOffsetDefinitionPtr offsetDef( (ksPlaneOffsetDefinition*)entity->GetDefinition(), false/*AddRef*/ );
      if ( offsetDef ) {
        offsetDef->offset = 150; // расстояние от базовой плоскости
        ksEntityPtr basePlane( (ksEntity*)part->GetDefaultEntity(o3d_planeXOY), false/*AddRef*/ );
        basePlane->name = TO_OLE(L"XOY"); // название для плоскости
        basePlane->_Update();         // обновить параметры

        offsetDef->SetPlane( basePlane );      // базовая плоскость
        offsetDef->direction = false;          // направление смещения от базовой плоскости
        entity->name = TO_OLE(L"Смещенная плоскость"); // имя для смещенной плоскости
        entity->Create();                      // создать смещенную плоскость

        kompas->ksMessage( TO_OLE(L"Изменим параметры смещенной плоскости") );

        offsetDef->offset = 50;       // изменим расстояние до базовой плоскости
        // возьмем другую базовую плоскость
        basePlane.Bind( (ksEntity*)part->GetDefaultEntity(o3d_planeYOZ), false/*AddRef*/ );
        basePlane->name =  TO_OLE(L"YOZ");
        basePlane->_Update();              // обновить параметры

        offsetDef->direction = true;        // изменим направления смещения относительно базовой плоскости
        offsetDef->SetPlane( basePlane );
        entity->_Update();                 // обновить параметры

        // возьмем другую базовую плоскость
        basePlane.Bind( (ksEntity*)part->GetDefaultEntity(o3d_planeXOY), false/*AddRef*/ );

        basePlane->name = TO_OLE(L"XOY");

        kompas->ksMessage( TO_OLE(L"На пересечении плоскостей построим ось") );

        // Ось на пересечении двух плоскостей
        ksEntityPtr entityAxis( (ksEntity*)part->NewEntity(o3d_axis2Planes), false/*AddRef*/ );
        if ( entityAxis ) {
          ksAxis2PlanesDefinitionPtr axis2PlanesDef( (ksAxis2PlanesDefinition*)entityAxis->GetDefinition(), false/*AddRef*/ );
          if ( axis2PlanesDef ) {
            axis2PlanesDef->SetPlane( 1, entity );    // Базовая плоскость 1
            axis2PlanesDef->SetPlane( 2, basePlane ); // Базовая плоскость 2
            entityAxis->name = TO_OLE(L"Ось по двум плоскостям"); // имя для оси
            entityAxis->Create();                   // создаем ось

            kompas->ksMessage( TO_OLE(L"Поменяем одну из базовых плоскостей для построения оси") );

            // возьмем другую базовую плоскость
            basePlane.Bind( (ksEntity*)part->GetDefaultEntity(o3d_planeXOZ), false/*AddRef*/ );
            basePlane->name = TO_OLE(L"XOZ");

            axis2PlanesDef->SetPlane( 2,basePlane ); // Базовая плоскость 2
            entityAxis->_Update();

            kompas->ksMessage( TO_OLE(L"Через смещенную плоскость и построенную ось \n проведем плоскость под углом 45") );

            ksEntityPtr entityAnglePlane( (ksEntity*)part->NewEntity(o3d_planeAngle), false/*AddRef*/ );
            if ( entityAnglePlane )  {
              // интерфейс свойств плоскости под углом к другой плоскости
              ksPlaneAngleDefinitionPtr planeAngleDef( (ksPlaneAngleDefinition*)entityAnglePlane->GetDefinition(), false/*AddRef*/ );
              if ( planeAngleDef ) {
                planeAngleDef->angle = 45;        // угол наклона к базовой плоскости
                planeAngleDef->SetPlane( entity );    // базовая плоскость
                planeAngleDef->SetAxis( entityAxis ); // базовая ось
                entityAnglePlane->name = TO_OLE(L"Плоскость под углом к другой плоскости");
                entityAnglePlane->Create();           // создать плоскость под углом

                kompas->ksMessage( TO_OLE(L"Изменим одну из базовых плоскостей") );

                planeAngleDef->SetPlane( basePlane ); // базовая плоскость
                entityAnglePlane->_Update();           // обновить параметры плоскости
              }
            }
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Плоскость через три вершины
// ---
void ConstrPlane3Point( ksDocument3DPtr & doc ) {
  ksPartPtr part( (ksPart *)doc->GetPart(pTop_Part), false/*AddRef*/ ); // новый компонент
  if ( part ) {
    ksEntityPtr entitySketch( (ksEntity*)part->NewEntity(o3d_sketch), false/*AddRef*/ );
    if ( entitySketch ) {
      // интерфейс свойств эскиза
      ksSketchDefinitionPtr sketchDef( (ksSketchDefinition*)entitySketch->GetDefinition(), false/*AddRef*/ );
      if ( sketchDef ) {
        // получим интерфейс базовой плоскости XOY
        ksEntityPtr basePlane( (ksEntity*)part->GetDefaultEntity(o3d_planeXOY), false/*AddRef*/ );
        sketchDef->SetPlane( basePlane ); // установим плоскость XOY базовой для эскиза
        entitySketch->Create();           // создадим эскиз

        // интерфейс редактора эскиза
        ksDocument2DPtr sketchEdit( (ksDocument2D*)sketchDef->BeginEdit(), false/*AddRef*/ );
          // введем новый эскиз - квадрат
          sketchEdit->ksLineSeg(  50,  50, -50,  50, 1 );
          sketchEdit->ksLineSeg(  50, -50, -50, -50, 1 );

          sketchEdit->ksLineSeg(  50, -50,  50,  50, 1 );
          sketchEdit->ksLineSeg( -50, -50, -50,  50, 1 );
        sketchDef->EndEdit();                   // завершение редактирования эскиза

        ksEntityPtr entityExtr( (ksEntity*)part->NewEntity(o3d_bossExtrusion), false/*AddRef*/ );
        if ( entityExtr ) {
          // интерфейс свойств базовой операции выдавливания
          ksBossExtrusionDefinitionPtr extrusionDef( (ksBossExtrusionDefinition*)entityExtr->GetDefinition(), false/*AddRef*/ ); // интерфейс базовой операции выдавливания
          if ( extrusionDef ) {
            extrusionDef->directionType = dtNormal;         // направление выдавливания
            extrusionDef->SetSideParam( true/*прямое направление*/, etBlind/*строго на глубину*/, 20, 30, false );
            extrusionDef->SetThinParam( true, dtBoth, 10, 10 ); // тонкая стенка в два направления
            extrusionDef->SetSketch( entitySketch ); // эскиз операции выдавливания
            entityExtr->Create();                    // создать операцию
          }
        }
      }
    }

    ksEntityCollectionPtr entityCollection( (ksEntityCollection*)part->EntityCollection( o3d_vertex ), false/*AddRef*/ );

    // Плоскость через три вершины
    ksEntityPtr entityConstrPlane3Point( (ksEntity*)part->NewEntity( o3d_plane3Points ), false/*AddRef*/ );
    if ( entityConstrPlane3Point ) {
      ksPlane3PointsDefinitionPtr constrPlane3Point( (ksPlane3PointsDefinition*)entityConstrPlane3Point->GetDefinition(), false/*AddRef*/ );
      if ( constrPlane3Point ) {
        constrPlane3Point->SetPoint(1, IDispatchPtr(entityCollection->GetByIndex(0), false/*AddRef*/ ));
        constrPlane3Point->SetPoint(2, IDispatchPtr(entityCollection->GetByIndex(1), false/*AddRef*/ ));
        constrPlane3Point->SetPoint(3, IDispatchPtr(entityCollection->GetByIndex(2), false/*AddRef*/ ));
        entityConstrPlane3Point->Create();
      }
    }
    kompas->ksMessage( TO_OLE(L"Плоскость через три вершины") );
  }
}



