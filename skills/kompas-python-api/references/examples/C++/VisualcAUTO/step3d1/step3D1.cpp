//

#include "stdafx.h"
#include "step3D1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

ksPartPtr part;
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
// CStep3D1App

BEGIN_MESSAGE_MAP(CStep3D1App, CWinApp)
  //{{AFX_MSG_MAP(CStep3D1App)
    // NOTE - the ClassWizard will add and remove mapping macros here.
    //    DO NOT EDIT what you see in these blocks of generated code!
  //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStep3D1App construction

CStep3D1App::CStep3D1App()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CStep3D1App object

CStep3D1App theApp;


//-------------------------------------------------------------------------------
//
// ---
unsigned int WINAPI LIBRARYID() {
  return IDS_LIBID;
}


//-------------------------------------------------------------------------------
//
// ---
KompasObjectPtr kompas( NULL );


void CreateExtrusion( ksDocument3DPtr& doc );
void OperationRotated( ksDocument3DPtr& doc );
void OperationLoft( ksDocument3DPtr& doc );
void CreateFilletAndChamfer( ksDocument3DPtr& doc );
void CreateNextOper( ksDocument3DPtr& doc );

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
          kompas = pCreateKompasObject();
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
    ksDocument3DPtr doc( kompas->ActiveDocument3D() );
    if ( !doc ) {
               // Если не является 3D деталью, то создаю его
      doc = kompas->Document3D();
      if ( doc->Create(false, true) ) {
        doc->author = _T("");
        doc->comment = _T("3D");
        doc->UpdateDocumentParam();
      }
    }
    if ( doc ) {
      switch ( comm ) {
        case 1  : ::CreateExtrusion( doc );          break; // базовая операция выдавливания
        case 2  : ::OperationRotated( doc );        break; // Операции вращения
        case 3  : ::OperationLoft( doc );            break; // Операции по сечениям
        case 4  : ::CreateFilletAndChamfer( doc );  break; // создание фаски и скругления
        case 5  : ::CreateNextOper( doc );          break; // Операции : оболочка, уклон, сечение плоскостью, сечение эскизом
      }
      kompas->ksMessageBoxResult();
    }
    else
      kompas->ksError( _T("3D документ не активизирован") );
  }
}



//-------------------------------------------------------------------------------
// удалить все объекты из текущего эскиза
// ---
void ClearCurrentSketch( ksDocument2DPtr& sketchEdit ) {
  // создаим итератор и удалим все существующие объекты в эскизе          
  ksIteratorPtr iter( kompas->GetIterator() );
  if ( iter ) {
    if ( iter->ksCreateIterator(ALL_OBJ, 0) ) {
      reference ref;
      if ( ref = iter->ksMoveIterator(_T("F")) ) { // сместить указатель на первый элемент в списке
        // в цикле сместить указатель на следующий элемент в списке пока не дойдем до последнего
        do {
          if ( sketchEdit->ksExistObj(ref) )
            sketchEdit->ksDeleteObj( ref );      // если объект существует удалить его 
        } while ( ref = iter->ksMoveIterator(_T("N")) ); 
      }

      iter->ksDeleteIterator(); // удалим итератор
    }
  }
}



//-------------------------------------------------------------------------------
// оперция выдавливания, работа с экизом
// ---
void CreateExtrusion( ksDocument3DPtr& doc ) {
  part = doc->GetPart( pTop_Part ); // новый компонент
  if ( part ) {
    ksEntityPtr entitySketch( part->NewEntity(o3d_sketch) );
    if ( entitySketch ) {
      // интерфейс свойств эскиза
      ksSketchDefinitionPtr sketchDef( entitySketch->GetDefinition() );
      if ( sketchDef ) {
        // получим интерфейс базовой плоскости XOY
        ksEntityPtr basePlane( part->GetDefaultEntity(o3d_planeXOY) );
        sketchDef->SetPlane( basePlane ); // установим плоскость XOY базовой для эскиза
        sketchDef->angle = 45;        // угол поворота эскиза
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
            extrusionDef->SetSideParam( true,    // прямое направление
                                       etBlind, // строго на глубину
                                       200, 0, false );
            extrusionDef->SetThinParam( true, dtBoth, 10, 10 ); // тонкая стенка в два направления
            extrusionDef->SetSketch( entitySketch ); // эскиз операции выдавливания
            entityExtr->Create();                    // создать операцию

            kompas->ksMessage( _T("Изменим параметры операции выдавливания") );

            extrusionDef->SetSideParam( false,   // обратное направление
                                       etBlind, // строго на глубину
                                       150, 0, false );
            extrusionDef->directionType = dtBoth; // направление выдавливания dtBoth - в оба направления
            entityExtr->Update(); // обновить параметры

            kompas->ksMessage( _T("Поменяем эскиз") );

            // режим редактирования эскиза
            sketchEdit = sketchDef->BeginEdit();

              // создаим итератор и удалим все существующие объекты в эскизе
              ClearCurrentSketch( sketchEdit );
              // введем в эскиз окружность
               sketchEdit->ksCircle( 0, 0, 100, 1 );

            sketchDef->EndEdit();   // завершение редактирования эскиза
            entitySketch->Update(); // обновить параметры эскиза
            entityExtr->Update();   // обновить параметры операции выдавливания

            kompas->ksMessage( _T("Приклеем выдавливанием") );

            // создадим новый эскиз
            ksEntityPtr entitySketch2( part->NewEntity(o3d_sketch) );
            if ( entitySketch2 ) {
              // интерфейс свойств эскиза
              ksSketchDefinitionPtr sketchDef2( entitySketch2->GetDefinition() );
              if ( sketchDef2 ) {
                sketchDef2->SetPlane( basePlane ); // установим плоскость
                sketchDef2->angle = 45;        // повернем эскиз на 45 град.
                entitySketch2->Create();           // создадим эскиз

                // интерфейс редактора эскиза
                ksDocument2DPtr sketchEdit2( sketchDef2->BeginEdit() );
                  sketchEdit2->ksCircle( 0, 0, 150, 1 );
                sketchDef2->EndEdit(); // завершение редактирования эскиза

                // приклеим выдавливанием
                ksEntityPtr entityBossExtr( part->NewEntity(o3d_bossExtrusion) );
                if ( entityBossExtr ) {
                  ksBossExtrusionDefinitionPtr bossExtrDef( entityBossExtr->GetDefinition() );
                  if ( bossExtrDef ) {
                    ksExtrusionParamPtr extrProp( bossExtrDef->ExtrusionParam() ); // интерфейс структуры параметров выдавливания
                    ksThinParamPtr      thinProp( bossExtrDef->ThinParam() );      // интерфейс структуры параметров тонкой стенки
                    if ( extrProp && thinProp ) {
                      bossExtrDef->SetSketch( entitySketch2 ); // эскиз операции выдавливания

                      extrProp->direction = dtNormal;      // направление выдавливания (прямое)
                      extrProp->typeNormal = etBlind;      // тип выдавливания ( строго на глубину )
                      extrProp->depthNormal = 100;         // глубина выдавливания

                      thinProp->thin = false;              // без тонкой стенки

                      entityBossExtr->Create();                // создадим операцию
                    }
                  }
                }

                // создадим новый эскиз
                ksEntityPtr entitySketch3( part->NewEntity(o3d_sketch) );
                if ( entitySketch3 ) {
                  // интерфейс свойств эскиза
                  ksSketchDefinitionPtr sketchDef3( entitySketch3->GetDefinition() );
                  if ( sketchDef3 ) {
                    sketchDef3->SetPlane( basePlane ); // установим плоскость
                    sketchDef3->angle = 45;            // повернем эскиз на 45 град.
                    entitySketch3->Create();            // создадим эскиз

                    // интерфейс редактора эскиза
                    ksDocument2DPtr sketchEdit3( sketchDef3->BeginEdit() );
                      // введем новый эскиз - квадрат
                      sketchEdit3->ksLineSeg(  50,  50, -50,  50, 1 );
                      sketchEdit3->ksLineSeg(  50, -50, -50, -50, 1 );
                      sketchEdit3->ksLineSeg(  50, -50,  50,  50, 1 );
                      sketchEdit3->ksLineSeg( -50, -50, -50,  50, 1 );
                    sketchDef3->EndEdit(); // завершение редактирования эскиза

                    // вырежим выдавливанием
                    ksEntityPtr entityCutExtr( part->NewEntity(o3d_cutExtrusion) );
                    if ( entityCutExtr ) {
                      ksCutExtrusionDefinitionPtr cutExtrDef( entityCutExtr->GetDefinition() );
                      if ( cutExtrDef ) {
                        cutExtrDef->SetSketch( entitySketch3 ); // установим эскиз операции
                        cutExtrDef->directionType = dtReverse; //прямое направление
                        cutExtrDef->SetSideParam( false, etBlind, 50, 0, false );
                        cutExtrDef->SetThinParam( false, 0, 0, 0 );
                      }

                      entityCutExtr->Create(); // создадим операцию вырезание выдавливанием
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}


//-------------------------------------------------------------------------------
// создание фаски и скругления
// ---
void CreateFilletAndChamfer( ksDocument3DPtr& doc ) {
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
        sketchDef->angle = 45;        // угол поворота эскиза
        entitySketch->Create();           // создадим эскиз

        // интерфейс редактора эскиза
        ksDocument2DPtr sketchEdit( sketchDef->BeginEdit() );
          // введем новый эскиз - квадрат
          sketchEdit->ksLineSeg(  50,  50, -50,  50, 1 );
          sketchEdit->ksLineSeg(  50, -50, -50, -50, 1 );

          sketchEdit->ksLineSeg(  50, -50,  50,  50, 1 );
          sketchEdit->ksLineSeg( -50, -50, -50,  50, 1 );
        sketchDef->EndEdit();             // завершение редактирования эскиза

        ksEntityPtr entityExtr( part->NewEntity(o3d_bossExtrusion) );
        if ( entityExtr ) {
          // интерфейс свойств базовой операции выдавливания
          ksBossExtrusionDefinitionPtr extrusionDef( entityExtr->GetDefinition() ); // интерфейс базовой операции выдавливания
          if ( extrusionDef ) {
            extrusionDef->directionType = dtNormal;   // направление выдавливания
            extrusionDef->SetSideParam( true/*прямое направление*/, etBlind/*строго на глубину*/, 100, 0, false );
            extrusionDef->SetThinParam( false, 0, 0, 0 ); // без тонкой стенки
            extrusionDef->SetSketch( entitySketch );      // эскиз операции выдавливания
            entityExtr->Create();                         // создать операцию

            ksEntityCollectionPtr collect( part->EntityCollection(o3d_face) );
            if ( collect && collect->SelectByPoint(0, 0, 0) && collect->GetCount() ) {

              kompas->ksMessage( _T("Создание скругления") );

              ksEntityPtr entityFillet( part->NewEntity(o3d_fillet) );
               if ( entityFillet ) {
                ksFilletDefinitionPtr filletDef( entityFillet->GetDefinition() );
                if ( filletDef ) {
                  filletDef->radius = 10;      // радиус скругления
                  filletDef->tangent = false;  // продолжить по касательной
                  ksEntityCollectionPtr arr( filletDef->array() ); // динамический массив объектов
                  if ( arr ) {
                    for ( int i = 0, count = collect->GetCount(); i < count; i++ )
                      arr->Add( collect->GetByIndex(i) );

                    entityFillet->Create();
                  }
                }
              }
            }

            ksEntityCollectionPtr collect2( part->EntityCollection(o3d_face) );
            if ( collect2 && collect2->SelectByPoint(0, 0, 100) && collect2->GetCount() ) {

              kompas->ksMessage( _T("Создание фаски") );
              ksEntityPtr entityChamfer( part->NewEntity(o3d_chamfer) );
               if ( entityChamfer ) {
                ksChamferDefinitionPtr ChamferDef( entityChamfer->GetDefinition() );
                if ( ChamferDef ) {
                  ChamferDef->tangent = false;
                  ChamferDef->SetChamferParam( true, 10, 10 );
                  ksEntityCollectionPtr arr( ChamferDef->array() ); // динамический массив объектов
                  if ( arr ) {
                    for ( int i = 0, count = collect2->GetCount(); i < count; i++ )
                      arr->Add( collect2->GetByIndex(i) );

                    entityChamfer->Create();
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}



//-------------------------------------------------------------------------------
// Операции вращения
// ---
void OperationRotated( ksDocument3DPtr& doc ) {
  ksPartPtr part( doc->GetPart(pTop_Part) ); // новый компонент
  if ( part ) {
    ksEntityPtr entitySketch( part->NewEntity(o3d_sketch) );
    if ( entitySketch ) {
      // интерфейс свойств эскиза
      ksSketchDefinitionPtr sketchDef( entitySketch->GetDefinition() );
      if ( sketchDef ) {
        // получим интерфейс базовой плоскости XOY
        ksEntityPtr basePlane( part->GetDefaultEntity(o3d_planeXOY) );
        if ( basePlane ) {
          sketchDef->SetPlane( basePlane ); // установим плоскость XOY базовой для эскиза
          entitySketch->Create();           // создадим эскиз

          // интерфейс редактора эскиза
          ksDocument2DPtr sketchEdit( sketchDef->BeginEdit() );
          if ( sketchEdit ) {
            sketchEdit->ksArcByAngle( 0, 0, 20, -90, 90, 1, 1 );
            sketchEdit->ksLineSeg( 0, -20, 0, 20, 3 );
            sketchDef->EndEdit();                   // завершение редактирования эскиза
          }

          ksEntityPtr entityRotate( part->NewEntity(o3d_bossRotated) );
          if ( entityRotate ) {
            ksBossRotatedDefinitionPtr rotateDef( entityRotate->GetDefinition() ); // интерфейс базовой операции вращения
            if ( rotateDef ) {
               ksRotatedParamPtr rotproperty( rotateDef->RotatedParam() );
              if ( rotproperty ) {
                rotproperty->direction = dtBoth;
                rotproperty->toroidShape = false;
              }

//            rotateDef->torShapeType = false;
//             rotateDef->directionType = dtNormal;       // направление вращения
              rotateDef->SetThinParam( true, dtBoth, 1, 1 ); // тонкая стенка в два направления
              rotateDef->SetSideParam( true, 180 );
              rotateDef->SetSideParam( false, 180 );
              rotateDef->SetSketch( entitySketch );          // эскиз операции вращения
              entityRotate->Create();                        // создать операцию
            }
          }
        }
      }
    }
    kompas->ksMessage( _T("Базовая операция вращения") );

    ksEntityPtr entitySketch2( part->NewEntity(o3d_sketch) );
    if ( entitySketch2 ) {
      ksSketchDefinitionPtr sketchDef2( entitySketch2->GetDefinition() );
      if ( sketchDef2 ) {
        ksEntityPtr basePlane( part->GetDefaultEntity(o3d_planeXOY) );
        if ( basePlane ) {
          sketchDef2->SetPlane( basePlane ); // установим плоскость XOY базовой для эскиза
          entitySketch2->Create();           // создадим эскиз
          // интерфейс редактора эскиза
          ksDocument2DPtr sketchEdit2( sketchDef2->BeginEdit() );
          if ( sketchEdit2 ) {
            sketchEdit2->ksArcByAngle( 15, 0, 10, -90, 90, 1, 1 );
            sketchEdit2->ksLineSeg( 15, -10, 15, 10, 3 );
            sketchDef2->EndEdit();                   // завершение редактирования эскиза
          }

          ksEntityPtr entityBossRotate( part->NewEntity(o3d_bossRotated) );
          if ( entityBossRotate ) {
            ksBossRotatedDefinitionPtr bossRotateDef( entityBossRotate->GetDefinition() );
            if ( bossRotateDef ) {
              bossRotateDef->directionType = dtNormal;
              bossRotateDef->SetSideParam( true, 360 );
              bossRotateDef->SetSketch( entitySketch2 );          // эскиз операции вращения
              entityBossRotate->Create();                        // создать операцию
            }
          }
        }
      }
    }
    kompas->ksMessage( _T("Операция приклеивания вращением") );

    ksEntityPtr entitySketch3( part->NewEntity(o3d_sketch) );
    if ( entitySketch3 ) {
      ksSketchDefinitionPtr sketchDef( entitySketch3->GetDefinition() );
      if ( sketchDef ) {
        ksEntityPtr basePlane( part->GetDefaultEntity(o3d_planeXOY) );
        if ( basePlane ) {
          sketchDef->SetPlane( basePlane ); // установим плоскость XOY базовой для эскиза
          entitySketch3->Create();           // создадим эскиз
          // интерфейс редактора эскиза
          ksDocument2DPtr sketchEdit3( sketchDef->BeginEdit() );
          if ( sketchEdit3 ) {
            sketchEdit3->ksArcByAngle( 20, 0, 20, 90, 270, 1, 1 );
            sketchEdit3->ksLineSeg( 20, -20, 20, 20, 3 );
            sketchDef->EndEdit();                   // завершение редактирования эскиза
          }

          ksEntityPtr entityCutRotate( part->NewEntity(o3d_cutRotated) );
          if ( entityCutRotate ) {
            ksCutRotatedDefinitionPtr cutRotateDef( entityCutRotate->GetDefinition() );
            if ( cutRotateDef ) {
              cutRotateDef->directionType = dtNormal;
              cutRotateDef->SetSideParam( true, 90 );
              cutRotateDef->SetThinParam( true, dtBoth, 5, 7 );   // тонкая стенка в два направления
              cutRotateDef->SetSketch( entitySketch3 );        // эскиз операции вращения
              entityCutRotate->Create();                       // создать операцию
            }
          }
        }
      }
    }
    kompas->ksMessage( _T("Операция вырезания вращением") );
  }
}


//-------------------------------------------------------------------------------
// операции по сечениям
// ---
void OperationLoft(ksDocument3DPtr& doc)
{
  ksPartPtr part( doc->GetPart(pTop_Part) ); // новый компонент
  if (part)
  {
    // создадим эскиз
    ksEntityPtr entitySketch1(part->NewEntity(o3d_sketch));
    if (entitySketch1)
    {
      ksSketchDefinitionPtr sketchDefinition1(entitySketch1->GetDefinition());
      if (sketchDefinition1)
      {
        ksEntityPtr basePlane( part->GetDefaultEntity(o3d_planeXOY) ); // получим интерфейс базовой плоскости XOY
        sketchDefinition1->SetPlane(basePlane); // установим плоскость XOY базовой для эскиза
//        sketchDef->SetPoint( 20, 0 );
        entitySketch1->Create();           // создадим эскиз
        entitySketch1->hidden = false;

        // интерфейс редактора эскиза
        ksDocument2DPtr sketchEdit(sketchDefinition1->BeginEdit());
          if ( sketchEdit )
            sketchEdit->ksCircle( 0, 0, 4.5, 1 );
        sketchDefinition1->EndEdit();                   // завершение редактирования эскиза
          }
      }

    // создадим смещенную плоскость, а в ней эскиз
    ksEntityPtr entityOffsetPlane2(part->NewEntity(o3d_planeOffset));
    ksEntityPtr entitySketch2( part->NewEntity(o3d_sketch) );
    if (entityOffsetPlane2 && entitySketch2)
    {
      // интерфейс свойств смещенной плоскости
      ksPlaneOffsetDefinitionPtr planeOffsetDefinition2(entityOffsetPlane2->GetDefinition());
      if (planeOffsetDefinition2)
      {
        planeOffsetDefinition2->offset = 30; // расстояние от базовой плоскости
        ksEntityPtr basePlane( part->GetDefaultEntity(o3d_planeXOY) );

        planeOffsetDefinition2->SetPlane(basePlane); // базовая плоскость
        entityOffsetPlane2->name = _T("Смещенная плоскость 2"); // имя для смещенной плоскости
        entityOffsetPlane2->hidden = true;
        entityOffsetPlane2->Create();                 // создать смещенную плоскость

        ksSketchDefinitionPtr sketchDefinition2(entitySketch2->GetDefinition());
        if (sketchDefinition2)
        {
          sketchDefinition2->SetPlane(entityOffsetPlane2); // установим плоскость XOY базовой для эскиза
//            sketchDef2->SetPoint( 0, 20 );
            entitySketch2->Create();           // создадим эскиз

            // интерфейс редактора эскиза
          ksDocument2DPtr sketchEdit(sketchDefinition2->BeginEdit());
              sketchEdit->ksCircle( 0, 0, 8, 1 );
          sketchDefinition2->EndEdit();                   // завершение редактирования эскиза
          }
        }
      }

    // создадим смещенную плоскость, а в ней эскиз
    ksEntityPtr entityPlaneOffset3(part->NewEntity(o3d_planeOffset));
    ksEntityPtr entitySketch3( part->NewEntity(o3d_sketch) );
    if (entityPlaneOffset3 && entitySketch3)
    {
      // интерфейс свойств смещенной плоскости
      ksPlaneOffsetDefinitionPtr planeOffsetDefinition3(entityPlaneOffset3->GetDefinition());
      if (planeOffsetDefinition3)
      {
        planeOffsetDefinition3->offset = 60; // расстояние от базовой плоскости
        ksEntityPtr basePlane( part->GetDefaultEntity(o3d_planeXOY) );
        
        planeOffsetDefinition3->SetPlane(basePlane); // базовая плоскость
        entityPlaneOffset3->name = _T("Смещенная плоскость 3"); // имя для смещенной плоскости
        entityPlaneOffset3->hidden = true;
        entityPlaneOffset3->Create();                 // создать смещенную плоскость 

        ksSketchDefinitionPtr sketchDefinition3(entitySketch3->GetDefinition());
        if (sketchDefinition3)
        {
          sketchDefinition3->SetPlane(entityPlaneOffset3); // установим плоскость XOY базовой для эскиза
          entitySketch3->Create();           // создадим эскиз

          // интерфейс редактора эскиза
          ksDocument2DPtr sketchEdit(sketchDefinition3->BeginEdit());
            sketchEdit->ksCircle( 0, 0, 1.5, 1 );
          sketchDefinition3->EndEdit();                   // завершение редактирования эскиза
        }
      }
    }

    // создадим базовую операцию по сечениям
    ksEntityPtr entityBaseLoft( part->NewEntity(o3d_bossLoft) ); 
    if (entityBaseLoft)
    {
      ksBossLoftDefinitionPtr baseLoft( entityBaseLoft->GetDefinition() );
      if (baseLoft)
      {
        ksEntityCollectionPtr entCol( baseLoft->Sketchs() );
        if (entCol)
        {
          entCol->Add(entitySketch1);
          entCol->Add(entitySketch2);
          entCol->Add(entitySketch3);
        }
        entityBaseLoft->name = _T("Ручка");
        entityBaseLoft->SetAdvancedColor( 12345678, .8, .8, .8, .8, 1, .8 );

        entityBaseLoft->Create();                        // создать операцию
      }
    }
    kompas->ksMessage( _T("Базовая операция по сечениям") );

    // создадим смещенную плоскость, а в ней эскиз
    ksEntityPtr entitySketch4(part->NewEntity(o3d_sketch));
    if (entitySketch4)
    {
      // интерфейс свойств смещенной плоскости
      ksSketchDefinitionPtr sketchDefinition4(entitySketch4->GetDefinition());
      if (sketchDefinition4)
      {
        sketchDefinition4->SetPlane(entityPlaneOffset3); // установим плоскость XOY базовой для эскиза
        entitySketch4->Create();           // создадим эскиз

        // интерфейс редактора эскиза
        ksDocument2DPtr sketchEdit(sketchDefinition4->BeginEdit());
          sketchEdit->ksCircle( 0, 0, 1.5, 1 );
        sketchDefinition4->EndEdit();                   // завершение редактирования эскиза                
      }
    }

    // создадим смещенную плоскость, а в ней эскиз
    ksEntityPtr entityPlaneOffset5(part->NewEntity(o3d_planeOffset));
    ksEntityPtr entitySketch5(part->NewEntity(o3d_sketch));
    if (entityPlaneOffset5 && entitySketch5)
    {
      // интерфейс свойств смещенной плоскости
      ksPlaneOffsetDefinitionPtr planeOffsetDefinition5(entityPlaneOffset5->GetDefinition());
      if (planeOffsetDefinition5)
      {
        planeOffsetDefinition5->offset = 120; // расстояние от базовой плоскости
        ksEntityPtr basePlane( part->GetDefaultEntity(o3d_planeXOY) );
        
        planeOffsetDefinition5->SetPlane(basePlane); // базовая плоскость
        entityPlaneOffset5->name = _T("Смещенная плоскость 5"); // имя для смещенной плоскости
        entityPlaneOffset5->hidden = true;
        entityPlaneOffset5->Create();                 // создать смещенную плоскость 

        ksSketchDefinitionPtr sketchDefinition5(entitySketch5->GetDefinition());
        if (sketchDefinition5)
        {
          sketchDefinition5->SetPlane(entityPlaneOffset5); // установим плоскость XOY базовой для эскиза

          entitySketch5->Create();           // создадим эскиз

          // интерфейс редактора эскиза
          ksDocument2DPtr sketchEdit(sketchDefinition5->BeginEdit());
            sketchEdit->ksCircle( 0, 0, 1.8, 1 );
          sketchDefinition5->EndEdit();                   // завершение редактирования эскиза                
        }
      }
    }


    // создадим операцию приклеивания по сечениям
    ksEntityPtr entityBossLoft( part->NewEntity(o3d_bossLoft) ); 
    if ( entityBossLoft ) {
      ksBossLoftDefinitionPtr bossLoft( entityBossLoft->GetDefinition() );
      if ( bossLoft ) {
        ksEntityCollectionPtr entCol( bossLoft->Sketchs() );
        if ( entCol ) {
          entCol->Add(entitySketch4);
          entCol->Add(entitySketch5);
        }
        entityBossLoft->name = _T("Цивьё");
        entityBossLoft->SetAdvancedColor( 1234567890, .8, .8, .8, .8, 1, .8 );

        entityBossLoft->Create();                        // создать операцию
      }
    }
    kompas->ksMessage( _T("Операция приклеивание по сечениям") );

    // создадим эскиз в уже созданной смещенной плоскости
    ksEntityPtr entitySketch6(part->NewEntity(o3d_sketch));
    if (entitySketch6)
    {
      ksSketchDefinitionPtr sketchDefinition6(entitySketch6->GetDefinition());
      if (sketchDefinition6)
      {
        sketchDefinition6->SetPlane(entityPlaneOffset5); // установим плоскость XOY базовой для эскиза
        entitySketch6->Create();           // создадим эскиз

        // интерфейс редактора эскиза
        ksDocument2DPtr sketchEdit(sketchDefinition6->BeginEdit());
          ksRectangleParamPtr recPar( kompas->GetParamStruct(ko_RectangleParam) );
          recPar->Init();
          if ( recPar ) 
          {
            recPar->x = -1.8;
          recPar->y = -0.4;
            recPar->height = 0.8;
            recPar->width  = 3.6;
            recPar->style  = 1;
          }
          sketchEdit->ksRectangle( recPar, 0 ); 
        sketchDefinition6->EndEdit();                   // завершение редактирования эскиза                
      }
    }

    // создадим смещенную плоскость, а в ней эскиз
    ksEntityPtr entityPlaneOffset7(part->NewEntity(o3d_planeOffset));
    ksEntityPtr entitySketch7(part->NewEntity(o3d_sketch));
    if (entityPlaneOffset7 && entitySketch7)
    {
      // интерфейс свойств смещенной плоскости
      ksPlaneOffsetDefinitionPtr planeOffsetDefinition7(entityPlaneOffset7->GetDefinition());
      if (planeOffsetDefinition7)
      {
        planeOffsetDefinition7->offset = 110; // расстояние от базовой плоскости
        ksEntityPtr basePlane( part->GetDefaultEntity(o3d_planeXOY) );
        
        planeOffsetDefinition7->SetPlane(basePlane); // базовая плоскость
        entityPlaneOffset7->name = _T("Смещенная плоскость 7"); // имя для смещенной плоскости
        entityPlaneOffset7->hidden = true;
        entityPlaneOffset7->Create();                 // создать смещенную плоскость 

        ksSketchDefinitionPtr sketchDefinition7(entitySketch7->GetDefinition());
        if (sketchDefinition7)
        {
          sketchDefinition7->SetPlane(entityPlaneOffset7); // установим плоскость XOY базовой для эскиза
//            sketchDef->SetPoint( -20, 0 );
          entitySketch7->Create();           // создадим эскиз

          // интерфейс редактора эскиза
          ksDocument2DPtr sketchEdit(sketchDefinition7->BeginEdit());
            ksRectangleParamPtr recPar( kompas->GetParamStruct(ko_RectangleParam) );
            recPar->Init();
            if ( recPar ) {
              recPar->x = -1.8;
              recPar->y = -1.8;
              recPar->height = 3.6;
              recPar->width  = 3.6;
              recPar->style  = 1;
            }
            sketchEdit->ksRectangle( recPar, 0 ); 
          sketchDefinition7->EndEdit();                   // завершение редактирования эскиза                
        }
      }
    }


    // создадим операцию вырезания по сечениям
    ksEntityPtr entityCutLoft( part->NewEntity(o3d_cutLoft) ); 
    if ( entityCutLoft ) {
      ksCutLoftDefinitionPtr cutLoft( entityCutLoft->GetDefinition() );
      if ( cutLoft ) {
        ksEntityCollectionPtr entCol( cutLoft->Sketchs() );
        if ( entCol ) {
          entCol->Add(entitySketch6);
          entCol->Add(entitySketch7);
        }

        cutLoft->SetThinParam( true, dtNormal, 3, 0 );
        entityCutLoft->name = _T("Рабочая поверхность");
        entityCutLoft->SetAdvancedColor( 1234, .8, .8, .8, .8, 1, .8 );

        entityCutLoft->Create();                        // создать операцию
      }
    }

    kompas->ksMessage( _T("Операция вырезания по сечениям") );    
  }
}


//-----------------------------------------------------------------------------------
// Операции : оболочка, уклон, сечение плоскостью, сечение эскизом
//---
void CreateNextOper( ksDocument3DPtr& doc )
{
  // создадим новую деталь
  ksPartPtr part( doc->GetPart(pTop_Part) );                       
  if ( part ) {
    // создадим эскиз для базовой операции
    ksEntityPtr entitySketch( part->NewEntity(o3d_sketch) );
    if ( entitySketch ) {
      // получим интерфейс свойств эскиза
      ksSketchDefinitionPtr sketchDef( entitySketch->GetDefinition() );
      if ( sketchDef ) {
        // получим интерфейс базовой плоскости XOY
        ksEntityPtr basePlane( part->GetDefaultEntity(o3d_planeXOY) );
        sketchDef->SetPlane( basePlane );    // установим плоскость XOY базовой для эскиза
        sketchDef->angle = 0;            // угол поворота эскиза
        entitySketch->Create();              // создадим эскиз

        // интерфейс редактора эскиза
        ksDocument2DPtr sketchEdit( sketchDef->BeginEdit() ); 
          // введем новый эскиз - квадрат
          sketchEdit->ksLineSeg(  50,  50, -50,  50, 1 );
          sketchEdit->ksLineSeg(  50, -50, -50, -50, 1 ); 
          sketchEdit->ksLineSeg(  50, -50,  50,  50, 1 );
          sketchEdit->ksLineSeg( -50, -50, -50,  50, 1 );
        sketchDef->EndEdit();                   // завершение редактирования эскиза                

        kompas->ksMessage( _T("Создаем операцию выдавливания") );
        // Создаем операцию выдавливания
        ksEntityPtr entityExtr( part->NewEntity(o3d_bossExtrusion) );
        if ( entityExtr ) {
          // интерфейс свойств базовой операции выдавливания
          ksBossExtrusionDefinitionPtr extrusionDef( entityExtr->GetDefinition() ); 
          if ( extrusionDef ) {
            extrusionDef->directionType = dtNormal;         // направление выдавливания
            extrusionDef->SetSideParam( true/*прямое направление*/, etBlind/*строго на глубину*/, 200, 0, false ); 
            extrusionDef->SetThinParam( true, dtBoth, 10, 10 ); // тонкая стенка в два направления
            extrusionDef->SetSketch( entitySketch );            // эскиз операции выдавливания
            entityExtr->Create();                               // создать операцию
          }

          bool update = false;                                 // если update = true, то параметры операции изменены 
          if ( MessageBox( ::GetActiveWindow(), _T("Создать операцию оболочка?"), 
               _T("Сообщение библиотеки"), MB_ICONQUESTION | MB_YESNO ) == IDYES ) {
            // Создаем операцию оболочка
            ksEntityPtr entShell( part->NewEntity(o3d_shellOperation) );
            if ( entShell ) {
              // интерфейс свойств базовой операции выдавливания
              ksShellDefinitionPtr incDef( entShell->GetDefinition() );
              if ( incDef ) {
                ksEntityCollectionPtr entCol( incDef->FaceArray() );               // заведем массив граней для операции оболочка
                ksEntityCollectionPtr collect( part->EntityCollection(o3d_face) ); // массив всех граней
                if ( entCol && collect ) {
                  incDef->thickness = 8;                      // толщиина оболочки
                  incDef->thinType = true;                    // направление оболочки внутрь
                  collect->SelectByPoint( 50, 0, 0 );             // выделим точку на детале для заполнения массива всех граней, рпоходяших через эту точку
                  entCol->Add( collect->GetByIndex(0) );           // добавим в массив граней для операции грань с индексом = 0 
                  collect->refresh();                             // очистим массив
                  entShell->Create();                             // создать операцию

                  if ( MessageBox( ::GetActiveWindow(), _T("Изменить параметры операци оболочка?"), 
                    _T("Сообщение библиотеки"), MB_ICONQUESTION | MB_YESNO ) == IDYES ) {

                    incDef->thickness = 25;                   // толщиина оболочки
                    incDef->thinType = false;                 // направление оболочки наружу
                    collect->SelectByPoint( 60, 0, 10 );          // выделим точку на детале для заполнения массива всех граней, рпоходяших через эту точку
                    entCol->Add( collect->GetByIndex(0) );         // добавим в массив граней для операции грань с индексом = 0 
                    collect->refresh();                           // очистим массив
                    entShell->Update();                           // перестроим операцию
                    update = true;
                  }
                }
              }
            }
          }

          if ( MessageBox( ::GetActiveWindow(), _T("Создать операцию уклон?"), 
               _T("Сообщение библиотеки"), MB_ICONQUESTION | MB_YESNO ) == IDYES ) {
            // создадим операцию уклон
            ksEntityPtr entInc( part->NewEntity(o3d_incline) );
            if ( entInc ) {
              // интерфейс свойств базовой операции уклона
              ksInclineDefinitionPtr incDef( entInc->GetDefinition() );
              ksEntityCollectionPtr collect( part->EntityCollection(o3d_face) ); // массив всех граней
              if ( incDef && collect ) {
                incDef->direction = true;                         // Направление уклона - наружу  
                incDef->angle = 3;                                // Угол уклона  
                incDef->SetPlane( basePlane );                        // базовая плоскость  
                ksEntityCollectionPtr entColInc( incDef->FaceArray() );  // заведем массив граней для операции уклон
                if ( entColInc ) {
                  collect->SelectByPoint( 0, update ? 85 : 60, 10 );  // выделим точку на детале для заполнения массива всех граней, проходяших через эту точку
                  entColInc->Add( collect->GetByIndex(0) );            // добавим в массив граней для операции грань с индексом = 0 
                  collect->refresh();                                 // очистим массив
                  entInc->Create();                                   // создать операцию

                  if ( MessageBox( ::GetActiveWindow(), _T("Изменить параметры операци уклон?"), 
                    _T("Сообщение библиотеки"), MB_ICONQUESTION | MB_YESNO ) == IDYES ) {
                    incDef->direction = false;                        // Направление уклона - внутрь
                    incDef->angle = 25;                               // Угол уклона  
                    collect->SelectByPoint( 0, update ? -85 : -60, 10 );  // выделим точку на детале для заполнения массива всех граней, проходяших через эту точку
                    entColInc->Add( collect->GetByIndex(0) );              // добавим в массив граней для операции грань с индексом = 0 
                    collect->refresh();                                   // очистим массив
                    entInc->Update();
                  }
                }
              }
            }
          }

          if ( MessageBox( ::GetActiveWindow(), _T("Создать операцию сечение плоскостью?"), 
               _T("Сообщение библиотеки"), MB_ICONQUESTION | MB_YESNO ) == IDYES ) {
            // создадим операцию сечение плоскостью
            ksEntityPtr entityOpr( part->NewEntity(o3d_cutByPlane) );
            if ( entityOpr ) {
              // интерфейс свойств операции сечение плоскостью
              ksCutByPlaneDefinitionPtr incOpr( entityOpr->GetDefinition() ); // интерфейс операции
              if ( incOpr ) {
                 // получим интерфейс базовой плоскости XOZ, которая будет являться плоскостью сечения
                ksEntityPtr basePlaneXOZ( part->GetDefaultEntity(o3d_planeXOZ) );
                incOpr->SetPlane( basePlaneXOZ );               // задаем плоскость сечения
                incOpr->direction = false;                  // направление сечения - обратное
                entityOpr->Create();                             // создать операцию

                if ( MessageBox( ::GetActiveWindow(), _T("Изменить параметры операци сечение плоскостью?"), 
                  _T("Сообщение библиотеки"), MB_ICONQUESTION | MB_YESNO ) == IDYES ) {
                  incOpr->direction = true;                 // направление сечения - прямое
                  entityOpr->Update();                           // перестроить операцию
                }
              }
            }
          }

          if ( MessageBox( ::GetActiveWindow(), _T("Создать операцию сечение эскизом?"), 
               _T("Сообщение библиотеки"), MB_ICONQUESTION | MB_YESNO ) == IDYES ) {
            // создадим эскиз для операции сечение эскизом
            ksEntityPtr entitySketch2( part->NewEntity(o3d_sketch) );  
            if ( entitySketch2 ) {
              // интерфейс свойств эскиза
              ksSketchDefinitionPtr sketchDef2( entitySketch2->GetDefinition() );
              if ( sketchDef2 ) {
                 // получим интерфейс базовой плоскости YOZ
                ksEntityPtr basePlaneYOZ( part->GetDefaultEntity(o3d_planeYOZ) );
                sketchDef2->SetPlane( basePlaneYOZ ); // установим плоскость yoz базовой для эскиза
                sketchDef2->angle = 45;            // угол поворота эскиза
                entitySketch2->Create();               // создадим эскиз

                // интерфейс редактора эскиза
                ksDocument2DPtr sketchEdit2( sketchDef2->BeginEdit() ); 
                // введем новый эскиз
                sketchEdit2->ksArcBy3Points( -200, 45, -150, 10, -50, 10, 1 );
                sketchEdit2->ksLineSeg     ( -200, 45, -300, 20, 1 );
                sketchEdit2->ksLineSeg     (  -50, 10,   60, 10, 1 );
                sketchDef2->EndEdit();                   // завершение редактирования эскиза
              
                // создадаим Операцию сечение эскизом
                ksEntityPtr entityOpr( part->NewEntity(o3d_cutBySketch) );
                if ( entityOpr ) {
                  // интерфейс операции сечение эскизом
                  ksCutBySketchDefinitionPtr incOpr( entityOpr->GetDefinition() ); 
                  if ( incOpr ) {
                    incOpr->SetSketch( entitySketch2 );             // задаем эскиз
                    incOpr->direction = true;                   // задаем направление сечения
                    entityOpr->Create();                             // создать операцию
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}
