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
//---------------------------------------------------------------------------

//------------------------------------------------------------------------------
// в Win32 линкуется SDK/lib/kAPI5bc.lib
// в x64 линкуется SDK/lib64/kAPI5bc.a
// ---
#pragma comment(lib, "kAPI5bc")
extern "C" IDispatch* far __export WINAPI CreateKompasObject();


KompasObjectPtr kompas;

extern "C" unsigned int __export __stdcall LIBRARYID()
{
  return 100;
}


void CreateExtrusion       ( ksDocument3DPtr & doc );
void OperationRotated      ( ksDocument3DPtr & doc );
void OperationLoft         ( ksDocument3DPtr & doc );
void CreateFilletAndChamfer( ksDocument3DPtr & doc );

//------------------------------------------------------------------------------
//
// ---
extern "C" void far __export __stdcall  LIBRARYENTRY( unsigned int comm )
{
	kompas.Bind( (KompasObject*)::CreateKompasObject(), false/*AddRef*/ );
	if ( kompas ) {
		ksDocument3DPtr doc( (ksDocument3D*)kompas->ActiveDocument3D(), false/*AddRef*/ );
		if ( doc )
			switch ( comm ) {
				case 1: CreateExtrusion( doc );        break; // базовая операция выдавливания
				case 2: OperationRotated( doc );       break; // Операции вращения
				case 3: OperationLoft( doc );          break; // Операции по сечениям
				case 4: CreateFilletAndChamfer( doc ); break; // создание фаски и скругления
			}
		else
			kompas->ksError( TO_OLE(L"3D документ не активизирован") );
		kompas.Unbind();
  }
}

//-------------------------------------------------------------------------------
// удалить все объекты из текущего эскиза
// ---

void ClearCurrentSketch( ksDocument2DPtr & sketchEdit ) {
  // создаим итератор и удалим все существующие объекты в эскизе
  ksIteratorPtr iter( (ksIterator*)kompas->GetIterator(), false/*AddRef*/ );
  if ( iter ) {
    if ( iter->ksCreateIterator(ALL_OBJ, 0) ) {
      reference ref = iter->ksMoveIterator(L"F");
      if ( ref ) { // сместить указатель на первый элемент в списке
        // в цикле сместить указатель на следующий элемент в списке пока не дойдем до последнего
        do {
          if ( sketchEdit->ksExistObj(ref) )
            sketchEdit->ksDeleteObj( ref );      // если объект существует удалить его
          ref = iter->ksMoveIterator(L"N");
        } while ( ref );
      }

      iter->ksDeleteIterator(); // удалим итератор
    }
  }
}


//------------------------------------------------------------------------------
// базовая операция выдавливания
// ---
void CreateExtrusion( ksDocument3DPtr & doc ) {
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
        sketchDef->angle = 45;        // угол поворота эскиза
        entitySketch->Create();           // создадим эскиз

        // интерфейс редактора эскиза
        ksDocument2DPtr sketchEdit( (ksDocument2D*)sketchDef->BeginEdit(), false/*AddRef*/ );
        if ( sketchEdit ) {
          // введем новый эскиз - квадрат
          sketchEdit->ksCircle( 0, 0, 100, 1 );
          sketchDef->EndEdit();                   // завершение редактирования эскиза
        }

        ksEntityPtr entityExtr( (ksEntity*)part->NewEntity(o3d_bossExtrusion), false/*AddRef*/ );
        if ( entityExtr ) {
          // интерфейс свойств базовой операции выдавливания
		  ksBossExtrusionDefinitionPtr extrusionDef( (ksBossExtrusionDefinition*)entityExtr->GetDefinition(), false/*AddRef*/ ); // интерфейс базовой операции выдавливания
          if ( extrusionDef ) {
            extrusionDef->directionType = dtNormal;         // направление выдавливания
            extrusionDef->SetSideParam( true/*прямое направление*/, etBlind/*строго на глубину*/, 200, 0, false );
            extrusionDef->SetThinParam( true, dtBoth, 10, 10 ); // тонкая стенка в два направления
            extrusionDef->SetSketch( entitySketch ); // эскиз операции выдавливания
            entityExtr->Create();                    // создать операцию

            kompas->ksMessage( TO_OLE(L"Изменим параметры операции выдавливания") );

            extrusionDef->SetSideParam( false/*обратное направление*/, etBlind/*строго на глубину*/, 150, 0, false );
            extrusionDef->directionType = dtBoth; // направление выдавливания - в оба направления
            entityExtr->_Update();                // обновить параметры

            kompas->ksMessage( TO_OLE(L"Поменяем эскиз") );

            // режим редактирования эскиза
            sketchEdit.Bind( (ksDocument2D*)sketchDef->BeginEdit(), false/*AddRef*/ );

              // создаим итератор и удалим все существующие объекты в эскизе
              ClearCurrentSketch( sketchEdit );
              // введем в эскиз окружность
              sketchEdit->ksCircle( 0, 0, 100, 1 );

            sketchDef->EndEdit();   // завершение редактирования эскиза
            entitySketch->_Update(); // обновить параметры эскиза
            entityExtr->_Update();   // обновить параметры операции выдавливания

            kompas->ksMessage( TO_OLE(L"Приклеем выдавливанием") );

            // создадим новый эскиз
            ksEntityPtr entitySketch2( (ksEntity*)part->NewEntity(o3d_sketch), false/*AddRef*/ );
            if ( entitySketch2 ) {
              // интерфейс свойств эскиза
              ksSketchDefinitionPtr sketchDef2( (ksSketchDefinition*)entitySketch2->GetDefinition(), false/*AddRef*/ );
              if ( sketchDef2 ) {
                sketchDef2->SetPlane( basePlane ); // установим плоскость
                sketchDef2->angle = 45;            // повернем эскиз на 45 град.
                entitySketch2->Create();           // создадим эскиз

                // интерфейс редактора эскиза
                ksDocument2DPtr sketchEdit2( (ksDocument2D*)sketchDef2->BeginEdit(), false/*AddRef*/ );
                  sketchEdit2->ksCircle( 0, 0, 150, 1 );
                sketchDef2->EndEdit(); // завершение редактирования эскиза

                // приклеим выдавливанием
                ksEntityPtr entityBossExtr( (ksEntity*)part->NewEntity(o3d_bossExtrusion), false/*AddRef*/ );
                if ( entityBossExtr ) {
                  ksBossExtrusionDefinitionPtr bossExtrDef( (ksBossExtrusionDefinition*)entityBossExtr->GetDefinition(), false/*AddRef*/ );
                  if ( bossExtrDef ) {
                    ksExtrusionParamPtr extrProp( (ksExtrusionParam*)bossExtrDef->ExtrusionParam(), false/*AddRef*/ ); // интерфейс структуры параметров выдавливания
                    ksThinParamPtr thinProp( (ksThinParam*)bossExtrDef->ThinParam(), false/*AddRef*/ );      // интерфейс структуры параметров тонкой стенки
                    if ( (bool)extrProp && (bool)thinProp ) {
                      bossExtrDef->SetSketch( entitySketch2 ); // эскиз операции выдавливания

                      extrProp->direction   = dtNormal;    // направление выдавливания (прямое)
                      extrProp->typeNormal  = etBlind;     // тип выдавливания ( строго на глубину )
                      extrProp->depthNormal = 100;         // глубина выдавливания

                      thinProp->thin        = false;       // без тонкой стенки

                      entityBossExtr->Create();            // создадим операцию
                    }
                  }
                }

                // создадим новый эскиз
                ksEntityPtr entitySketch3( (ksEntity*)part->NewEntity(o3d_sketch), false/*AddRef*/ );
                if ( entitySketch3 ) {
                  // интерфейс свойств эскиза
                  ksSketchDefinitionPtr sketchDef3( (ksSketchDefinition*)entitySketch3->GetDefinition(), false/*AddRef*/ );
                  if ( sketchDef3 ) {
                    sketchDef3->SetPlane( basePlane ); // установим плоскость
                    sketchDef3->angle = 45;        // повернем эскиз на 45 град.
                    entitySketch3->Create();           // создадим эскиз

                    // интерфейс редактора эскиза
                    ksDocument2DPtr sketchEdit3( (ksDocument2D *)sketchDef3->BeginEdit(), false/*AddRef*/ );
                      // введем новый эскиз - квадрат
                      sketchEdit3->ksLineSeg(  50,  50, -50,  50, 1 );
                      sketchEdit3->ksLineSeg(  50, -50, -50, -50, 1 );

                      sketchEdit3->ksLineSeg(  50, -50,  50,  50, 1 );
                      sketchEdit3->ksLineSeg( -50, -50, -50,  50, 1 );
                    sketchDef3->EndEdit(); // завершение редактирования эскиза

                    // вырежим выдавливанием
                    ksEntityPtr entityCutExtr( (ksEntity*)part->NewEntity(o3d_cutExtrusion), false/*AddRef*/ );
                    if ( entityCutExtr ) {
                      ksCutExtrusionDefinitionPtr cutExtrDef( (ksCutExtrusionDefinition*)entityCutExtr->GetDefinition(), false/*AddRef*/ );
                      if ( cutExtrDef ) {
                        cutExtrDef->SetSketch( entitySketch3 ); // установим эскиз операции
                        cutExtrDef->directionType = dtNormal;
                        cutExtrDef->SetSideParam( true/*прямое направление*/,  etBlind/*etThroughAll*/, 50, 0, false );
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

//------------------------------------------------------------------------------
// Операции вращения
// ---
void OperationRotated( ksDocument3DPtr & doc ) {
  ksPartPtr part( (ksPart*)doc->GetPart(pTop_Part), false/*AddRef*/ ); // новый компонент
  if ( part ) {
    ksEntityPtr entitySketch( (ksEntity*)part->NewEntity(o3d_sketch), false/*AddRef*/ );
    if ( entitySketch ) {
      ksSketchDefinitionPtr sketchDef( (ksSketchDefinition*)entitySketch->GetDefinition(), false/*AddRef*/ ); // интерфейс свойств эскиза
      if ( sketchDef ) {
        ksEntityPtr basePlane( (ksEntity*)part->GetDefaultEntity(o3d_planeXOY), false/*AddRef*/ ); // получим интерфейс базовой плоскости XOY
        if ( basePlane ) {
          sketchDef->SetPlane( basePlane ); // установим плоскость XOY базовой для эскиза
          entitySketch->Create();           // создадим эскиз

          // интерфейс редактора эскиза
          ksDocument2DPtr sketchEdit( (ksDocument2D*)sketchDef->BeginEdit(), false/*AddRef*/ );
          if ( sketchEdit ) {
            sketchEdit->ksArcByAngle( 0, 0, 20, -90, 90, 1, 1 );
            sketchEdit->ksLineSeg( 0, -20, 0, 20, 3 );
            sketchDef->EndEdit();                   // завершение редактирования эскиза
          }

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
        }
      }
    }
    kompas->ksMessage( TO_OLE(L"Базовая операция вращения") );

    ksEntityPtr entitySketch2( (ksEntity*)part->NewEntity(o3d_sketch), false/*AddRef*/ );
    if ( entitySketch2 ) {
      ksSketchDefinitionPtr sketchDef2( (ksSketchDefinition*)entitySketch2->GetDefinition(), false/*AddRef*/ );
      if ( sketchDef2 ) {
        ksEntityPtr basePlane( (ksEntity*)part->GetDefaultEntity(o3d_planeXOY), false/*AddRef*/ );
        if ( basePlane ) {
          sketchDef2->SetPlane( basePlane ); // установим плоскость XOY базовой для эскиза
          entitySketch2->Create();           // создадим эскиз
          // интерфейс редактора эскиза
          ksDocument2DPtr sketchEdit2( (ksDocument2D*)sketchDef2->BeginEdit(), false/*AddRef*/ );
          if ( sketchEdit2 ) {
            sketchEdit2->ksArcByAngle( 15, 0, 10, -90, 90, 1, 1 );
            sketchEdit2->ksLineSeg( 15, -10, 15, 10, 3 );
            sketchDef2->EndEdit();                   // завершение редактирования эскиза
          }

          ksEntityPtr entityBossRotate( (ksEntity*)part->NewEntity(o3d_bossRotated), false/*AddRef*/ );
          if ( entityBossRotate ) {
            ksBossRotatedDefinitionPtr bossRotateDef( (ksBossRotatedDefinition*)entityBossRotate->GetDefinition(), false/*AddRef*/ );
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
    kompas->ksMessage( TO_OLE(L"Операция приклеивания вращением") );

    ksEntityPtr entitySketch3( (ksEntity*)part->NewEntity(o3d_sketch), false/*AddRef*/ );
    if ( entitySketch3 ) {
      ksSketchDefinitionPtr sketchDef( (ksSketchDefinition*)entitySketch3->GetDefinition(), false/*AddRef*/ );
      if ( sketchDef ) {
        ksEntityPtr basePlane( (ksEntity*)part->GetDefaultEntity(o3d_planeXOY), false/*AddRef*/ );
        if ( basePlane ) {
          sketchDef->SetPlane( basePlane ); // установим плоскость XOY базовой для эскиза
          entitySketch3->Create();           // создадим эскиз
          // интерфейс редактора эскиза
          ksDocument2DPtr sketchEdit3( (ksDocument2D*)sketchDef->BeginEdit(), false/*AddRef*/ );
          if ( sketchEdit3 ) {
            sketchEdit3->ksArcByAngle( 20, 0, 20, 90, 270, 1, 1 );
            sketchEdit3->ksLineSeg( 20, -20, 20, 20, 3 );
            sketchDef->EndEdit();                   // завершение редактирования эскиза
          }

          ksEntityPtr entityCutRotate( (ksEntity*)part->NewEntity(o3d_cutRotated), false/*AddRef*/ );
          if ( entityCutRotate ) {
            ksCutRotatedDefinitionPtr cutRotateDef( (ksCutRotatedDefinition*)entityCutRotate->GetDefinition(), false/*AddRef*/ );
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
    kompas->ksMessage( TO_OLE(L"Операция вырезания вращением") );
  }
}

//------------------------------------------------------------------------------
// Операции по сечениям
// ---
void OperationLoft( ksDocument3DPtr & doc ) {
  ksPartPtr part( (ksPart*)doc->GetPart(pTop_Part), false/*AddRef*/ ); // новый компонент
  if ( part ) {
    // создадим эскиз
    ksEntityPtr entitySketch( (ksEntity*)part->NewEntity(o3d_sketch), false/*AddRef*/ );
    if ( entitySketch ) {
      ksSketchDefinitionPtr sketchDef( (ksSketchDefinition*)entitySketch->GetDefinition(), false/*AddRef*/ );
      if ( sketchDef ) {
        ksEntityPtr basePlane( (ksEntity*)part->GetDefaultEntity(o3d_planeXOY), false/*AddRef*/ ); // получим интерфейс базовой плоскости XOY
        sketchDef->SetPlane( basePlane ); // установим плоскость XOY базовой для эскиза
        entitySketch->Create();           // создадим эскиз
        entitySketch->hidden = true;

        // интерфейс редактора эскиза
        ksDocument2DPtr sketchEdit( (ksDocument2D*)sketchDef->BeginEdit(), false/*AddRef*/ );
          sketchEdit->ksCircle( 0, 0, 4.5, 1 );
        sketchDef->EndEdit();                   // завершение редактирования эскиза
      }
    }

    // создадим смещенную плоскость, а в ней эскиз
    ksEntityPtr entityOffsetPlane( (ksEntity*)part->NewEntity(o3d_planeOffset), false/*AddRef*/ );
    ksEntityPtr entitySketch2    ( (ksEntity*)part->NewEntity(o3d_sketch)     , false/*AddRef*/ );
    if ( entityOffsetPlane ) {
      // интерфейс свойств смещенной плоскости
      ksPlaneOffsetDefinitionPtr offsetDef( (ksPlaneOffsetDefinition*)entityOffsetPlane->GetDefinition(), false/*AddRef*/ );
      if ( offsetDef ) {
        offsetDef->offset = 30; // расстояние от базовой плоскости
        ksEntityPtr basePlane( (ksEntity*)part->GetDefaultEntity(o3d_planeXOY), false/*AddRef*/ );

        offsetDef->SetPlane( basePlane ); // базовая плоскость
        entityOffsetPlane->hidden = true;
        entityOffsetPlane->Create();                 // создать смещенную плоскость

        if ( entitySketch2 ) {
          ksSketchDefinitionPtr sketchDef2( (ksSketchDefinition*)entitySketch2->GetDefinition(), false/*AddRef*/ );
          if ( sketchDef2 ) {
            sketchDef2->SetPlane( entityOffsetPlane ); // установим плоскость XOY базовой для эскиза
            entitySketch2->Create();           // создадим эскиз

            // интерфейс редактора эскиза
            ksDocument2DPtr sketchEdit2( (ksDocument2D*)sketchDef2->BeginEdit(), false/*AddRef*/ );
            if ( sketchEdit2 )
              sketchEdit2->ksCircle( 0, 0, 8, 1 );
            sketchDef2->EndEdit();                   // завершение редактирования эскиза
          }
        }
      }
    }

    // создадим смещенную плоскость, а в ней эскиз
    ksEntityPtr entityOffsetPlane2( (ksEntity*)part->NewEntity(o3d_planeOffset), false/*AddRef*/ );
    ksEntityPtr entitySketch3     ( (ksEntity*)part->NewEntity(o3d_sketch),      false/*AddRef*/ );
    if ( entityOffsetPlane2 ) {
      // интерфейс свойств смещенной плоскости
      ksPlaneOffsetDefinitionPtr offsetDef( (ksPlaneOffsetDefinition*)entityOffsetPlane2->GetDefinition(), false/*AddRef*/ );
      if ( offsetDef ) {
        offsetDef->offset = 60; // расстояние от базовой плоскости
        ksEntityPtr basePlane( (ksEntity*)part->GetDefaultEntity(o3d_planeXOY), false/*AddRef*/ );
        basePlane->name = TO_OLE(L"Смещенная плоскость"); // название для плоскости

        offsetDef->SetPlane( basePlane ); // базовая плоскость
        entityOffsetPlane2->name = TO_OLE(L"Смещенная плоскость 2"); // имя для смещенной плоскости
        entityOffsetPlane2->hidden = true;
        entityOffsetPlane2->Create();                 // создать смещенную плоскость

        if ( entitySketch3 ) {
          ksSketchDefinitionPtr sketchDef2( (ksSketchDefinition*)entitySketch3->GetDefinition(), false/*AddRef*/ );
          if ( sketchDef2 ) {
            sketchDef2->SetPlane( entityOffsetPlane2 ); // установим плоскость XOY базовой для эскиза
            entitySketch3->Create();           // создадим эскиз

            // интерфейс редактора эскиза
            ksDocument2DPtr sketchEdit2( (ksDocument2D*)sketchDef2->BeginEdit(), false/*AddRef*/ );
            if ( sketchEdit2 )
              sketchEdit2->ksCircle( 0, 0, 1.5, 1 );
            sketchDef2->EndEdit();                   // завершение редактирования эскиза
          }
        }
      }
    }

    // создадим базовую операцию по сечениям
    ksEntityPtr entityBaseLoft( (ksEntity*)part->NewEntity(o3d_bossLoft), false/*AddRef*/ );
    if ( entityBaseLoft ) {
	  ksBossLoftDefinitionPtr baseLoft( (ksBossLoftDefinition*)entityBaseLoft->GetDefinition(), false/*AddRef*/ );
      if ( baseLoft ) {
        ksEntityCollectionPtr entCol( (ksEntityCollection*)baseLoft->Sketchs(), false/*AddRef*/ );
        if ( entCol ) {
          entCol->Add(entitySketch);
          entCol->Add(entitySketch2);
          entCol->Add(entitySketch3);
        }
        entityBaseLoft->name = TO_OLE(L"Ручка");
        entityBaseLoft->SetAdvancedColor( 12345678, .8, .8, .8, .8, 1, .8 );

        entityBaseLoft->Create();                        // создать операцию
      }
    }
    kompas->ksMessage( TO_OLE(L"Операция по сечениям") );

    // создадим смещенную плоскость, а в ней эскиз
    ksEntityPtr entitySketch7( (ksEntity*)part->NewEntity(o3d_sketch), false/*AddRef*/ );
    if ( entitySketch7 ) {
      // интерфейс свойств смещенной плоскости
      ksSketchDefinitionPtr sketchDef( (ksSketchDefinition*)entitySketch7->GetDefinition(), false/*AddRef*/ );
      if ( sketchDef ) {
        sketchDef->SetPlane( entityOffsetPlane2 ); // установим плоскость XOY базовой для эскиза
        entitySketch7->Create();           // создадим эскиз

        // интерфейс редактора эскиза
        ksDocument2DPtr sketchEdit( (ksDocument2D*)sketchDef->BeginEdit(), false/*AddRef*/ );
          sketchEdit->ksCircle( 0, 0, 1.5, 1 );
        sketchDef->EndEdit();                   // завершение редактирования эскиза
      }
    }

    // создадим смещенную плоскость, а в ней эскиз
    ksEntityPtr entityOffsetPlane3( (ksEntity*)part->NewEntity(o3d_planeOffset), false/*AddRef*/ );
    ksEntityPtr entitySketch4     ( (ksEntity*)part->NewEntity(o3d_sketch)     , false/*AddRef*/ );
    if ( entityOffsetPlane3 ) {
      // интерфейс свойств смещенной плоскости
      ksPlaneOffsetDefinitionPtr offsetDef( (ksPlaneOffsetDefinition*)entityOffsetPlane3->GetDefinition(), false/*AddRef*/ );
      if ( offsetDef ) {
        offsetDef->offset = 120; // расстояние от базовой плоскости
        ksEntityPtr basePlane( (ksEntity*)part->GetDefaultEntity(o3d_planeXOY), false/*AddRef*/ );
        basePlane->name = TO_OLE(L"Смещенная плоскость"); // название для плоскости

        offsetDef->SetPlane( basePlane ); // базовая плоскость
        entityOffsetPlane3->name = TO_OLE(L"Смещенная плоскость"); // имя для смещенной плоскости
        entityOffsetPlane3->hidden = true;
        entityOffsetPlane3->Create();                 // создать смещенную плоскость

        if ( entitySketch4 ) {
          ksSketchDefinitionPtr sketchDef( (ksSketchDefinition*)entitySketch4->GetDefinition(), false/*AddRef*/ );
          if ( sketchDef ) {
            sketchDef->SetPlane( entityOffsetPlane3 ); // установим плоскость XOY базовой для эскиза
            entitySketch4->Create();           // создадим эскиз

            // интерфейс редактора эскиза
            ksDocument2DPtr sketchEdit3( (ksDocument2D*)sketchDef->BeginEdit(), false/*AddRef*/ );
            if ( sketchEdit3 )
              sketchEdit3->ksCircle( 0, 0, 1.8, 1 );
            sketchDef->EndEdit();                   // завершение редактирования эскиза
          }
        }
      }
    }


    // создадим операцию приклеивания по сечениям
    ksEntityPtr entityBossLoft( (ksEntity*)part->NewEntity(o3d_bossLoft), false/*AddRef*/ );
    if ( entityBossLoft ) {
      ksBossLoftDefinitionPtr bossLoft( (ksBossLoftDefinition*)entityBossLoft->GetDefinition(), false/*AddRef*/ );
      if ( bossLoft ) {
        ksEntityCollectionPtr entCol( (ksEntityCollection*)bossLoft->Sketchs(), false/*AddRef*/ );
        if ( entCol ) {
          entCol->Add(entitySketch7);
          entCol->Add(entitySketch4);
        }
        entityBossLoft->name = TO_OLE(L"Цивьё");
        entityBossLoft->SetAdvancedColor( 1234567890, .8, .8, .8, .8, 1, .8 );

        entityBossLoft->Create();                        // создать операцию
      }
    }
    kompas->ksMessage( TO_OLE(L"Операция приклеивание по сечениям") );

    // создадим эскиз в уже созданной смещенной плоскости
    ksEntityPtr entitySketch5( (ksEntity *)part->NewEntity(o3d_sketch), false/*AddRef*/ );
    if ( entitySketch5 ) {
      ksSketchDefinitionPtr sketchDef( (ksSketchDefinition*)entitySketch5->GetDefinition(), false/*AddRef*/ );
      if ( sketchDef ) {
        sketchDef->SetPlane( entityOffsetPlane3 ); // установим плоскость XOY базовой для эскиза
        entitySketch5->Create();           // создадим эскиз

        // интерфейс редактора эскиза
        ksDocument2DPtr sketchEdit3( (ksDocument2D*)sketchDef->BeginEdit(), false/*AddRef*/ );
          ksRectangleParamPtr recPar( (ksRectangleParam *)kompas->GetParamStruct(ko_RectangleParam), false/*AddRef*/ );
          recPar->Init();
          if ( recPar ) {
            recPar->x      = -1.8;
            recPar->y      = - .4;
            recPar->height =  .8;
            recPar->width  = 3.6;
            recPar->style  = 1;
          }
          sketchEdit3->ksRectangle( recPar, 0 );
        sketchDef->EndEdit();                   // завершение редактирования эскиза
      }
    }

    // создадим смещенную плоскость, а в ней эскиз
    ksEntityPtr entityOffsetPlane4( (ksEntity*)part->NewEntity(o3d_planeOffset), false/*AddRef*/ );
    ksEntityPtr entitySketch6     ( (ksEntity*)part->NewEntity(o3d_sketch)     , false/*AddRef*/ );
    if ( entityOffsetPlane4 ) {
      // интерфейс свойств смещенной плоскости
      ksPlaneOffsetDefinitionPtr offsetDef( (ksPlaneOffsetDefinition*)entityOffsetPlane4->GetDefinition(), false/*AddRef*/ );
      if ( offsetDef ) {
        offsetDef->offset = 110; // расстояние от базовой плоскости
        ksEntityPtr basePlane( (ksEntity*)part->GetDefaultEntity(o3d_planeXOY), false/*AddRef*/ );
        basePlane->name = TO_OLE(L"Смещенная плоскость"); // название для плоскости

        offsetDef->SetPlane( basePlane ); // базовая плоскость
        entityOffsetPlane4->name   = TO_OLE(L"Смещенная плоскость"); // имя для смещенной плоскости
        entityOffsetPlane4->hidden = true;
        entityOffsetPlane4->Create();                 // создать смещенную плоскость

        if ( entitySketch6 ) {
          ksSketchDefinitionPtr sketchDef( (ksSketchDefinition*)entitySketch6->GetDefinition(), false/*AddRef*/ );
          if ( sketchDef ) {
            sketchDef->SetPlane( entityOffsetPlane4 ); // установим плоскость XOY базовой для эскиза
            entitySketch6->Create();           // создадим эскиз

            // интерфейс редактора эскиза
            ksDocument2DPtr sketchEdit4( (ksDocument2D*)sketchDef->BeginEdit(), false/*AddRef*/ );
              ksRectangleParamPtr recPar ( (ksRectangleParam *)kompas->GetParamStruct(ko_RectangleParam), false/*AddRef*/ );
              recPar->Init();
              if ( recPar ) {
                recPar->x      = -1.8;
                recPar->y      = -1.8;
                recPar->height =  3.6;
                recPar->width  =  3.6;
                recPar->style  =  1;
              }
              sketchEdit4->ksRectangle( recPar, 0 );
            sketchDef->EndEdit();                   // завершение редактирования эскиза
          }
        }
      }
    }


    // создадим операцию вырезания по сечениям
    ksEntityPtr entityCutLoft( (ksEntity *)part->NewEntity(o3d_cutLoft), false/*AddRef*/ );
    if ( entityCutLoft ) {
      ksCutLoftDefinitionPtr cutLoft( (ksCutLoftDefinition*)entityCutLoft->GetDefinition(), false/*AddRef*/ );
      if ( cutLoft ) {
        ksEntityCollectionPtr entCol( (ksEntityCollection*)cutLoft->Sketchs(), false/*AddRef*/ );
        if ( entCol ) {
          entCol->Add(entitySketch5);
          entCol->Add(entitySketch6);
        }
        cutLoft->SetThinParam( true, dtNormal, 3, 0 );
        entityCutLoft->name = TO_OLE(L"Рабочая поверхность");
        entityCutLoft->SetAdvancedColor( 1234, .8, .8, .8, .8, 1, .8 );

        entityCutLoft->Create();                        // создать операцию
      }
    }
    kompas->ksMessage( TO_OLE(L"Операция вырезания по сечениям") );
  }
}

//------------------------------------------------------------------------------
// создание фаски и скругления
// ---
void CreateFilletAndChamfer( ksDocument3DPtr & doc ) {
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
        sketchDef->angle = 45;        // угол поворота эскиза
        entitySketch->Create();           // создадим эскиз

        // интерфейс редактора эскиза
        ksDocument2DPtr sketchEdit( (ksDocument2D*)sketchDef->BeginEdit(), false/*AddRef*/ );
          // введем новый эскиз - квадрат
          sketchEdit->ksLineSeg(  50,  50, -50,  50, 1 );
          sketchEdit->ksLineSeg(  50, -50, -50, -50, 1 );

          sketchEdit->ksLineSeg(  50, -50,  50,  50, 1 );
          sketchEdit->ksLineSeg( -50, -50, -50,  50, 1 );
        sketchDef->EndEdit();             // завершение редактирования эскиза

        ksEntityPtr entityExtr( (ksEntity*)part->NewEntity(o3d_bossExtrusion), false/*AddRef*/ );
        if ( entityExtr ) {
          // интерфейс свойств базовой операции выдавливания
          ksBossExtrusionDefinitionPtr extrusionDef( (ksBossExtrusionDefinition*)entityExtr->GetDefinition(), false/*AddRef*/ ); // интерфейс базовой операции выдавливания
          if ( extrusionDef ) {
            extrusionDef->directionType = dtNormal;   // направление выдавливания
            extrusionDef->SetSideParam( true/*прямое направление*/, etBlind/*строго на глубину*/, 100, 0, false );
            extrusionDef->SetThinParam( false, 0, 0, 0 ); // без тонкой стенки
            extrusionDef->SetSketch( entitySketch );      // эскиз операции выдавливания
            entityExtr->Create();                         // создать операцию

            ksEntityCollectionPtr collect( (ksEntityCollection*)part->EntityCollection(o3d_face), false/*AddRef*/ );
            if ( collect ) {
              bool res = collect->SelectByPoint(0, 0, 0);
              int count = collect->GetCount();
              if ( count && res  ) {
                kompas->ksMessage( TO_OLE(L"Создание скругления") );
                ksEntityPtr entityFillet( (ksEntity*)part->NewEntity(o3d_fillet), false/*AddRef*/ );
                if ( entityFillet ) {
                  ksFilletDefinitionPtr filletDef( (ksFilletDefinition*)entityFillet->GetDefinition(), false/*AddRef*/ );
                  if ( filletDef ) {
                    filletDef->radius  = 10;      // радиус скругления
                    filletDef->tangent = false;  // продолжить по касательной
                    ksEntityCollectionPtr arr( (ksEntityCollection*)filletDef->array(), false/*AddRef*/ ); // динамический массив объектов
                    if ( arr ) {
                      for ( int i = 0; i < count; i++ )
                        arr->Add( ksEntityPtr((ksEntity*)collect->GetByIndex(i), false/*AddRef*/) );

                      entityFillet->Create();
                    }
                  }
                }
              }
            }

            ksEntityCollectionPtr collect2( (ksEntityCollection*)part->EntityCollection(o3d_face), false/*AddRef*/ );
            if ( collect2 ) {
              bool res = collect2->SelectByPoint(0, 0, 100);
              int count = collect2->GetCount();
              if ( count && res  ) {
                kompas->ksMessage( TO_OLE(L"Создание фаски") );
                ksEntityPtr entityChamfer( (ksEntity*)part->NewEntity(o3d_chamfer), false/*AddRef*/ );
                if ( entityChamfer ) {
                  ksChamferDefinitionPtr ChamferDef( (ksChamferDefinition*)entityChamfer->GetDefinition(), false/*AddRef*/ );
                  if ( ChamferDef ) {
                    ChamferDef->tangent = false;
                    ChamferDef->SetChamferParam( true, 10, 10 );
                    ksEntityCollectionPtr arr( (ksEntityCollection*)ChamferDef->array(), false/*AddRef*/ ); // динамический массив объектов
                    if ( arr ) {
                      for ( int i = 0; i < count; i++ )
                        arr->Add( ksEntityPtr((ksEntity*)collect2->GetByIndex(i), false/*AddRef*/) );

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
}

