//---------------------------------------------------------------------------
#include <vcl.h>

#pragma hdrstop

#include "KGAXForm.h"

#include <ldefin2d.h>
#include <ldefin3d.h>
#include <ks_Tlb.h>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "KGAXLib_TLB"
#pragma link "KGAXLib_TLB"
#pragma resource "*.dfm"

TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioGroup1Click(TObject *Sender)
{
  KGAX1->Document3DDrawMode = RadioGroup1->ItemIndex;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
  KGAX1->ZoomEntireDocument();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
  KompasObjectPtr pKompas = KGAX1->GetKompasObject();
  ksDocument3DPtr pDoc    = pKompas->ActiveDocument3D();
  if ( !pDoc )
    return;

  ksPartPtr part = pDoc->GetPart(pTop_Part);
  ksEntityPtr entitySketch = part->NewEntity(o3d_sketch);
  ksSketchDefinitionPtr sketchDef = entitySketch->GetDefinition();

  ksEntityPtr basePlane = part->GetDefaultEntity(o3d_planeXOY);
   sketchDef->SetPlane(basePlane);
   sketchDef->angle = 45;
  entitySketch->Create();

  ksDocument2DPtr sketchEdit = sketchDef->BeginEdit();
    sketchEdit->ksLineSeg(50, 50, -50, 50, 1);
    sketchEdit->ksLineSeg(50, -50, -50, -50, 1);
    sketchEdit->ksLineSeg(50, -50, 50, 50, 1);
    sketchEdit->ksLineSeg(-50, -50, -50, 50, 1);
  sketchDef->EndEdit();

  ksEntityPtr entityExtr = part->NewEntity(o3d_bossExtrusion);
    ksBossExtrusionDefinitionPtr extrusionDef = entityExtr->GetDefinition();
    extrusionDef->directionType = dtNormal;
    extrusionDef->SetSideParam(TRUE, etBlind, 200, 0, FALSE);
    extrusionDef->SetThinParam(TRUE, dtBoth, 10, 10);
    extrusionDef->SetSketch(entitySketch);
  entityExtr->Create();
  KGAX1->ZoomEntireDocument();

}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
  KompasObjectPtr pKompas = KGAX1->GetKompasObject();
  if (pKompas) {
    KGAX1->CloseAll();
    pKompas->Quit();
  }
}
//---------------------------------------------------------------------------


