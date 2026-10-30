// step3d3.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "step3d3.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//
//  Note!
//
//    If this DLL is dynamically linked against the MFC
//    DLLs, any functions exported from this DLL which
//    call into MFC must have the AFX_MANAGE_STATE macro
//    added at the very beginning of the function.
//
//    For example:
//
//    extern "C" BOOL PASCAL EXPORT ExportedFunction()
//    {
//      AFX_MANAGE_STATE(AfxGetStaticModuleState());
//      // normal function body here
//    }
//
//    It is very important that this macro appear in each
//    function, prior to any calls into MFC.  This means that
//    it must appear as the first statement within the 
//    function, even before any object variable declarations
//    as their constructors may generate calls into the MFC
//    DLL.
//
//    Please see MFC Technical Notes 33 and 58 for additional
//    details.
//

/////////////////////////////////////////////////////////////////////////////
// CStep3d3App

BEGIN_MESSAGE_MAP(CStep3d3App, CWinApp)
  //{{AFX_MSG_MAP(CStep3d3App)
    // NOTE - the ClassWizard will add and remove mapping macros here.
    //    DO NOT EDIT what you see in these blocks of generated code!
  //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStep3d3App construction

CStep3d3App::CStep3d3App()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CStep3d3App object

CStep3d3App theApp;

//-------------------------------------------------------------------------------
//
// ---
unsigned int WINAPI LIBRARYID(){
  return IDR_LIB3D3;
}

KompasObjectPtr kompas;

char buf[MAX_TEXT_LENGTH];


void ConstrAxisOperations( ksDocument3DPtr & doc );
void ConstrAxis2Point( ksDocument3DPtr & doc );
void ConstrAxisEdge( ksDocument3DPtr & doc );
void ConstrPlane3Point( ksDocument3DPtr & doc );
void CreateConstrElem( ksDocument3DPtr & doc );
void ConstrAxisConeface( ksDocument3DPtr & doc );

//-------------------------------------------------------------------------------
//
// ---
void GetKompas() {
  if ( !kompas ) {
    CString filename;
    if( ::GetModuleFileName(NULL, filename.GetBuffer(255), 255) ) {
      filename.ReleaseBuffer( 255 );
      CString libname;

      #ifdef __LIGHT_VERSION__
        libname.LoadString( IDS_STRING5 );  //klAPI5.dll
      #else
        libname.LoadString( IDS_STRING4 );  //kAPI5.dll
      #endif
      
      filename.Replace( filename.Right(filename.GetLength() - (filename.ReverseFind('\\') + 1)), 
                        libname );

      HINSTANCE hAppAuto = LoadLibrary( filename ); // идентификатор kAPI5.dll
      if(  hAppAuto ) {
        typedef LPDISPATCH ( WINAPI *FCreateKompasObject )(); 
        FCreateKompasObject pCreateKompasObject = 
          (FCreateKompasObject)GetProcAddress( hAppAuto, "CreateKompasObject" );  
        if ( pCreateKompasObject ) 
          kompas = IDispatchPtr( pCreateKompasObject(), false );
        FreeLibrary( hAppAuto );
      }
    }
  }
}

//-------------------------------------------------------------------------------
//
// ---
void WINAPI LIBRARYENTRY( unsigned int comm ) {
  // по умолчанию ресурсы берутся из .exe файла, для того чтобы их достать
  // из нашей dll вызовем этот define
  AFX_MANAGE_STATE(AfxGetStaticModuleState());

  GetKompas();
  if ( kompas ) {
    ksDocument3DPtr  doc( kompas->ActiveDocument3D() );
    if ( doc  ) {
      switch ( comm ) {
        case 1  : ::ConstrAxisOperations( doc ); break; // Конструктивная ось операции
        case 2  : ::ConstrAxis2Point( doc );     break; // Конструктивная ось по двум точкам
        case 3  : ::ConstrAxisEdge( doc );       break; // Конструктивная ось, проходящая через ребро
        case 4  : ::ConstrAxisConeface( doc );   break; // Конструктивная ось конической грани
        case 5  : ::CreateConstrElem( doc );     break; // Создание смещенной плоскости, оси по двум плоскостям и плоскости под углом к заданной
        case 6  : ::ConstrPlane3Point( doc );    break; // Плоскость через три вершины
      }
    }
  }
}


//-------------------------------------------------------------------------------
// конструктивная ось операции
// ---
void ConstrAxisOperations( ksDocument3DPtr & doc ) {
  ksPartPtr part( doc->GetPart(pTop_Part) ); // новый компонент
  if ( part ) {
    ksEntityPtr entitySketch( part->NewEntity(o3d_sketch) );
    if ( entitySketch ) {
      // интерфейс свойств эскиза
      ksSketchDefinitionPtr sketchDef( entitySketch->GetDefinition() );
      if ( sketchDef ) {
        // получим интерфейс базовой плоскости XOY
        ksEntityPtr basePlane( part->GetDefaultEntity(o3d_planeXOY) );
        sketchDef->SetPlane( basePlane ); // установим плоскость XOY базовой для эскиза
        entitySketch->Create();           // создадим эскиз

        // интерфейс редактора эскиза
        ksDocument2DPtr sketchEdit( sketchDef->BeginEdit() );
          sketchEdit->ksCircle( 20, 0, 10, 1 );
          sketchEdit->ksLineSeg( 0, 0, 0, 5, 3 );
        sketchDef->EndEdit();                   // завершение редактирования эскиза

        ksEntityPtr entityRotate( part->NewEntity(o3d_bossRotated) );
        bool res = false;
        if ( entityRotate ) {
          ksBossRotatedDefinitionPtr rotateDef( entityRotate->GetDefinition() ); // интерфейс базовой операции вращения
          if ( rotateDef ) {
             ksRotatedParamPtr rotproperty( rotateDef->RotatedParam() );
            if ( rotproperty ) {
              rotproperty->direction = dtBoth;
              rotproperty->toroidShape = false;
            }

//          rotateDef.SetTorShapeType(false);
//          rotateDef.SetDirectionType( dtNormal );       // направление вращения
            rotateDef->SetThinParam( true, dtBoth, 1, 1 ); // тонкая стенка в два направления
            rotateDef->SetSideParam( true, 180 );
            rotateDef->SetSideParam( false, 180 );
            rotateDef->SetSketch( entitySketch );          // эскиз операции вращения
            res = !!entityRotate->Create();                        // создать операцию
          }
        }
        if ( res ) {
          // создадим операцию вырезания по сечениям
          ksEntityPtr entityAxisOperation( part->NewEntity(o3d_axisOperation) );
          if ( entityAxisOperation ) {
            ksAxisOperationsDefinitionPtr axisOperation( entityAxisOperation->GetDefinition() );
            if ( axisOperation ) {
              axisOperation->SetOperation(entityRotate);
              entityAxisOperation->Create();                        // создать операцию
            }
          }
          kompas->ksMessage( _T("Ось операции") );
        }
        else
          kompas->ksMessage( _T("Ошибка создания операции") );
      }
    }
  }
}

//-------------------------------------------------------------------------------
// Конструктивная ось по двум точкам
// ---
void ConstrAxis2Point( ksDocument3DPtr & doc ) {
  ksPartPtr part( doc->GetPart(pTop_Part) ); // новый компонент
  if ( part ) {
    ksEntityPtr entitySketch( part->NewEntity(o3d_sketch) );
    if ( entitySketch ) {
      // интерфейс свойств эскиза
      ksSketchDefinitionPtr sketchDef( entitySketch->GetDefinition() );
      if ( sketchDef ) {
        // получим интерфейс базовой плоскости XOY
        ksEntityPtr basePlane( part->GetDefaultEntity(o3d_planeXOY) );
        sketchDef->SetPlane( basePlane ); // установим плоскость XOY базовой для эскиза
  //          sketchDef.SetAngle( 45 );        // угол поворота эскиза
        entitySketch->Create();           // создадим эскиз

        // интерфейс редактора эскиза
        ksDocument2DPtr sketchEdit( sketchDef->BeginEdit() ); 
          // введем новый эскиз - квадрат
          sketchEdit->ksLineSeg(  50,  50, -50,  50, 1 );
          sketchEdit->ksLineSeg(  50, -50, -50, -50, 1 ); 
          sketchEdit->ksLineSeg(  50, -50,  50,  50, 1 );
          sketchEdit->ksLineSeg( -50, -50, -50,  50, 1 );
        sketchDef->EndEdit();                   // завершение редактирования эскиза                
        
        ksEntityPtr entityExtr( part->NewEntity(o3d_bossExtrusion) );
        if ( entityExtr ) {
          // интерфейс свойств базовой операции выдавливания
          ksBossExtrusionDefinitionPtr extrusionDef( entityExtr->GetDefinition() ); // интерфейс базовой операции выдавливания
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

    ksEntityCollectionPtr entityCollection( part->EntityCollection( o3d_vertex ) );

    if ( entityCollection && entityCollection->GetCount() ) {
      // создадим ось по двум точкам
      ksEntityPtr entityAxis2Point( part->NewEntity(o3d_axis2Points) ); 
      if ( entityAxis2Point ) {
        ksAxis2PointsDefinitionPtr axis2Point( entityAxis2Point->GetDefinition() );
        if ( axis2Point ) {
          axis2Point->SetPoint( 1, entityCollection->GetByIndex(0) );
          axis2Point->SetPoint( 2, entityCollection->GetByIndex(entityCollection->GetCount() - 1) );
          entityAxis2Point->Create();
        }
      }
      kompas->ksMessage( _T("Ось через две точки") );
    }
  }
}

//-------------------------------------------------------------------------------
// Конструктивная ось, проходящая через ребро
// ---
void ConstrAxisEdge( ksDocument3DPtr & doc ) {
  ksPartPtr part( doc->GetPart(pTop_Part) ); // новый компонент
  if ( part ) {
    ksEntityPtr entitySketch( part->NewEntity(o3d_sketch) );
    if ( entitySketch ) {
      // интерфейс свойств эскиза
      ksSketchDefinitionPtr sketchDef( entitySketch->GetDefinition() );
      if ( sketchDef ) {
        // получим интерфейс базовой плоскости XOY
        ksEntityPtr basePlane( part->GetDefaultEntity(o3d_planeXOY) );
        sketchDef->SetPlane( basePlane ); // установим плоскость XOY базовой для эскиза
  //          sketchDef->angle = 45;        // угол поворота эскиза
        entitySketch->Create();           // создадим эскиз

        // интерфейс редактора эскиза
        ksDocument2DPtr sketchEdit( sketchDef->BeginEdit() ); 
          // введем новый эскиз - квадрат
          sketchEdit->ksLineSeg(  50,  50, -50,  50, 1 );
          sketchEdit->ksLineSeg(  50, -50, -50, -50, 1 ); 

          sketchEdit->ksLineSeg(  50, -50,  50,  50, 1 );
          sketchEdit->ksLineSeg( -50, -50, -50,  50, 1 );
        sketchDef->EndEdit();                   // завершение редактирования эскиза                
        
        ksEntityPtr entityExtr( part->NewEntity(o3d_bossExtrusion) );
        if ( entityExtr ) {
          // интерфейс свойств базовой операции выдавливания
          ksBossExtrusionDefinitionPtr extrusionDef( entityExtr->GetDefinition() ); // интерфейс базовой операции выдавливания
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

    ksEntityCollectionPtr entityCollection( part->EntityCollection( o3d_edge ) );

    if ( entityCollection && entityCollection->GetCount() > 1 ) {
      // создадим ось через грань
      ksEntityPtr entityAxisEdge( part->NewEntity(o3d_axisEdge) ); 
      if ( entityAxisEdge ) {
        ksAxisEdgeDefinitionPtr axisEdge( entityAxisEdge->GetDefinition() );
        if ( axisEdge ) {
          axisEdge->SetEdge( entityCollection->GetByIndex(0) );
          entityAxisEdge->Create();
        }
      }
      kompas->ksMessage( _T("Ось через грань") );

      // создадим еще ось через грань
      ksEntityPtr entityAxisEdge2( part->NewEntity(o3d_axisEdge) ); 
      if ( entityAxisEdge2 ) {
        ksAxisEdgeDefinitionPtr axisEdge( entityAxisEdge2->GetDefinition() );
        if ( axisEdge ) {
          axisEdge->SetEdge( entityCollection->GetByIndex(1) );
          entityAxisEdge2->Create();
        }
      }
      kompas->ksMessage( _T("Другая ось через грань") );
    }
  }
}


//-------------------------------------------------------------------------------
// Конструктивная ось конической грани
// ---
void ConstrAxisConeface( ksDocument3DPtr & doc ) {
  ksPartPtr part( doc->GetPart(pTop_Part) ); // новый компонент
  if ( part ) {
    ksEntityPtr entitySketch( part->NewEntity(o3d_sketch) );
    if ( entitySketch ) {
      // интерфейс свойств эскиза
      ksSketchDefinitionPtr sketchDef( entitySketch->GetDefinition() );
      if ( sketchDef ) {
        // получим интерфейс базовой плоскости XOY
        ksEntityPtr basePlane( part->GetDefaultEntity(o3d_planeXOY) );
        sketchDef->SetPlane( basePlane ); // установим плоскость XOY базовой для эскиза
        entitySketch->Create();           // создадим эскиз

        // интерфейс редактора эскиза
        ksDocument2DPtr sketchEdit( sketchDef->BeginEdit() ); 
          sketchEdit->ksCircle( 0, 0, 50, 1 );
        sketchDef->EndEdit();                   // завершение редактирования эскиза                
        
        ksEntityPtr entityExtr( part->NewEntity(o3d_bossExtrusion) );
        if ( entityExtr ) {
          // интерфейс свойств базовой операции выдавливания
          ksBossExtrusionDefinitionPtr extrusionDef( entityExtr->GetDefinition() ); // интерфейс базовой операции выдавливания
          if ( extrusionDef ) {
            extrusionDef->directionType = dtNormal;         // направление выдавливания
            extrusionDef->SetSideParam( true, etBlind, 20, 30, false ); 
            extrusionDef->SetThinParam( true, dtBoth, 10, 10 ); // тонкая стенка в два направления
            extrusionDef->SetSketch( entitySketch ); // эскиз операции выдавливания
            entityExtr->Create();                    // создать операцию
          }
        }
      }
    }

    ksEntityCollectionPtr entityCollection( part->EntityCollection( o3d_face ) );
    ksEntityPtr entityConFace;

    for ( int i = 0, count = entityCollection->GetCount(); i < count; i++ ) 
    {
      entityConFace = entityCollection->GetByIndex(i);
      ksFaceDefinitionPtr face( entityConFace->GetDefinition() );
      if ( face->IsCone() ) // если поверхность не коническая, берем следующую из массива
        break;
    }


    // создадим ось через коническую поверхность
    ksEntityPtr entityAxisConFace( part->NewEntity(o3d_axisConeFace) ); 
    if ( entityAxisConFace ) {
      ksAxisConefaceDefinitionPtr axisConFace( entityAxisConFace->GetDefinition() );
      if ( axisConFace ) {
        axisConFace->SetFace( entityConFace );
        entityAxisConFace->Create();
      }
    }
    kompas->ksMessage( _T("Ось через коническую поверхность") );
  }
}

//-------------------------------------------------------------------------------
// Плоскость через три вершины
// ---
void ConstrPlane3Point( ksDocument3DPtr & doc ) {
  ksPartPtr part( doc->GetPart(pTop_Part) ); // новый компонент
  if ( part ) {
    ksEntityPtr entitySketch( part->NewEntity(o3d_sketch) );
    if ( entitySketch ) {
      // интерфейс свойств эскиза
      ksSketchDefinitionPtr sketchDef( entitySketch->GetDefinition() );
      if ( sketchDef ) {
        // получим интерфейс базовой плоскости XOY
        ksEntityPtr basePlane( part->GetDefaultEntity(o3d_planeXOY) );
        sketchDef->SetPlane( basePlane ); // установим плоскость XOY базовой для эскиза
        entitySketch->Create();           // создадим эскиз

        // интерфейс редактора эскиза
        ksDocument2DPtr sketchEdit( sketchDef->BeginEdit() ); 
          // введем новый эскиз - квадрат
          sketchEdit->ksLineSeg(  50,  50, -50,  50, 1 );
          sketchEdit->ksLineSeg(  50, -50, -50, -50, 1 ); 

          sketchEdit->ksLineSeg(  50, -50,  50,  50, 1 );
          sketchEdit->ksLineSeg( -50, -50, -50,  50, 1 );
        sketchDef->EndEdit();                   // завершение редактирования эскиза                
        
        ksEntityPtr entityExtr( part->NewEntity(o3d_bossExtrusion) );
        if ( entityExtr ) {
          // интерфейс свойств базовой операции выдавливания
          ksBossExtrusionDefinitionPtr extrusionDef( entityExtr->GetDefinition() ); // интерфейс базовой операции выдавливания
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

    ksEntityCollectionPtr entityCollection( part->EntityCollection( o3d_vertex ) );
    if ( entityCollection->GetCount() > 2 ) {
      // Плоскость через три вершины
      ksEntityPtr entityConstrPlane3Point( part->NewEntity(o3d_plane3Points) ); 
      if ( entityConstrPlane3Point ) {
        ksPlane3PointsDefinitionPtr constrPlane3Point( entityConstrPlane3Point->GetDefinition() );
        if ( constrPlane3Point ) {
          constrPlane3Point->SetPoint( 1, entityCollection->GetByIndex(0) );
          constrPlane3Point->SetPoint( 2, entityCollection->GetByIndex(1) );
          constrPlane3Point->SetPoint( 3, entityCollection->GetByIndex(2) );
          entityConstrPlane3Point->Create();
        }
      }
      kompas->ksMessage( _T("Плоскость через три вершины") );
    }
  }
}


//-------------------------------------------------------------------------------
// Создание смещенной плоскости, оси по двум плоскостям и плоскости под углом к заданной
// ---
void CreateConstrElem( ksDocument3DPtr & doc ) {
  ksPartPtr part( doc->GetPart(pTop_Part) ); // новый компонент
  if ( part ) {
    ksEntityPtr entity( part->NewEntity(o3d_planeOffset) );
    if ( entity ) {
      // интерфейс свойств смещенной плоскости
      ksPlaneOffsetDefinitionPtr offsetDef( entity->GetDefinition() );
      if ( offsetDef ) {
        offsetDef->offset = 150; // расстояние от базовой плоскости
        ksEntityPtr basePlane( part->GetDefaultEntity(o3d_planeXOY) );
        basePlane->name = _T("XOY"); // название для плоскости
        basePlane->Update();         // обновить параметры
      
        offsetDef->SetPlane( basePlane ); // базовая плоскость
        offsetDef->direction = false;       // направление смещения от базовой плоскости
        entity->name = _T("Смещенная плоскость"); // имя для смещенной плоскости
        entity->Create();                 // создать смещенную плоскость 
        
        kompas->ksMessage( _T("Изменим параметры смещенной плоскости") );
     
        offsetDef->offset = 50;       // изменим расстояние до базовой плоскости
        // возьмем другую базовую плоскость
        basePlane = part->GetDefaultEntity(o3d_planeYOZ);
        basePlane->name = _T("YOZ");
        basePlane->Update();              // обновить параметры

        offsetDef->direction = true;        // изменим направления смещения относительно базовой плоскости
        offsetDef->SetPlane( basePlane ); 
        entity->Update();                 // обновить параметры

        // возьмем другую базовую плоскость
        basePlane = part->GetDefaultEntity(o3d_planeXOY);
        basePlane->name = _T("XOY");
        
        kompas->ksMessage( _T("На пересечении плоскостей построим ось") );

        // Ось на пересечении двух плоскостей
        ksEntityPtr entityAxis( part->NewEntity(o3d_axis2Planes) );
        if ( entityAxis ) {
          ksAxis2PlanesDefinitionPtr axis2PlanesDef( entityAxis->GetDefinition() );
          if ( axis2PlanesDef ) {
            axis2PlanesDef->SetPlane( 1, entity );    // Базовая плоскость 1
            axis2PlanesDef->SetPlane( 2, basePlane ); // Базовая плоскость 2
            entityAxis->name = _T("Ось по двум плоскостям"); // имя для оси
            entityAxis->Create();                   // создаем ось  

            kompas->ksMessage( _T("Поменяем одну из базовых плоскостей для построения оси") );
            
            // возьмем другую базовую плоскость
            basePlane = part->GetDefaultEntity(o3d_planeXOZ);
            basePlane->name = _T("XOZ");
            
            axis2PlanesDef->SetPlane( 2, basePlane ); // Базовая плоскость 2
            entityAxis->Update();

            kompas->ksMessage( _T("Через смещенную плоскость и построенную ось \n проведем плоскость под углом 45") );

            ksEntityPtr entityAnglePlane( part->NewEntity(o3d_planeAngle) ); 
            if ( entityAnglePlane )  {
              // интерфейс свойств плоскости под углом к другой плоскости
              ksPlaneAngleDefinitionPtr planeAngleDef( entityAnglePlane->GetDefinition() );
              if ( planeAngleDef ) {
                planeAngleDef->angle = 45;        // угол наклона к базовой плоскости
                planeAngleDef->SetPlane( entity );    // базовая плоскость
                planeAngleDef->SetAxis( entityAxis ); // базовая ось
                entityAnglePlane->name = _T("Плоскость под углом к другой плоскости");
                entityAnglePlane->Create();           // создать плоскость под углом 

                kompas->ksMessage( _T("Изменим одну из базовых плоскостей") );

                planeAngleDef->SetPlane( basePlane ); // базовая плоскость
                entityAnglePlane->Update();           // обновить параметры плоскости
              }
            }
          }
        }
      }     
    }
  }
}
