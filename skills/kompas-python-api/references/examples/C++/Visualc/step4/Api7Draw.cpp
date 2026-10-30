#include "stdafx.h"
#include "Api7Draw.h"


extern ksAPI7::IApplicationPtr appl;


#define IDB_RECT               0xE6E9l
#define IDB_CIRCLE             0xE584l
#define IDB_TRIANGLE           0xEA99l

//---------------------------------------------------------------------------
// Построить геометрию
//---
void Api7Draw::GetGroup()
{
  switch ( m_PhantomType )
  {
    case DrawType::DrawRect: 
    {
      LineSeg(-10,  0,  10,  0, 1);
      LineSeg( 10,  0,  10, 20, 1);
      LineSeg( 10, 20, -10, 20, 1);
      LineSeg(-10, 20, -10,  0, 1);
      break;
    }
    case DrawType::DrawCircle:
    {
      Circle( 0, 0, 20, 1);
      break;
    }
    case DrawType::DrawTreangle:
    {
      LineSeg(-10,  0,  10,  0, 1);
      LineSeg( 10,  0,   0, 20, 1);
      LineSeg(  0, 20, -10,  0, 1);
      break;
    }
  }
}


//---------------------------------------------------------------------------
// Отрисовка фантома
//---
void Api7Draw::DrawPhantom( double x, double y, double angle, BOOL dynamic )
{
  if ( !dynamic )
  {
    // Создание временной группы
    reference gr1 = NewGroup(1);
    EndGroup();

    // Меняем местами две группы
    AddObjGroup( gr1, m_refMacr );

    ::ksSetMacroPlacementEx( m_refMacr, x, y, angle, 0, 0 );

    ::StoreTmpGroup( gr1 );

    RedrawPhantom();
  }
}


//----------------------------------------------------------------------------
// Изменение фантома
//---
void Api7Draw::RedrawPhantom()
{
    ksAPI7::IProcess2DPtr process2D( m_Process );

    if (process2D)
    {
      ksAPI7::IPhantom2DPtr phantom( process2D->Phantom2D );
      if ( phantom )
      {
        bool newPh = !m_phantomGroup;
        if ( newPh )
        {
          phantom->PhantomType = ksMoveGroupPhantom;
          reference gr = NewGroup(1);
          EndGroup();
          m_phantomGroup = IUnknownPtr(ksTransferReference( gr, 0 ), false );
          phantom->PhantomGroup = m_phantomGroup;
        }

        if (m_phantomGroup)
        {
          m_phantomGroup->Clear( VARIANT_TRUE );
          m_phantomGroup->Open();
          ::Macro(0);
          m_refMacr = ::EndObj();
          ksOpenMacro( m_refMacr );
          GetGroup();
          m_refMacr = ::EndObj();
          m_phantomGroup->Close();
        }

        if ( !newPh )
        {
          phantom->Update();
        }
      }
    }
  }


//------------------------------------------------------------------------------
// Отображение кнопок спецпанели
//---
void Api7Draw::ShowControls()
{
  m_procParam->AddSpecToolbarButton(ID_Button1, IDB_RECT,     (LPCTSTR)LoadStr(IDS_RECT)    ,  "");
  m_procParam->AddSpecToolbarButton(ID_Button2, IDB_CIRCLE,   (LPCTSTR)LoadStr(IDS_CIRCLE)  ,  "");
  m_procParam->AddSpecToolbarButton(ID_Button3, IDB_TRIANGLE, (LPCTSTR)LoadStr(IDS_TRIANGLE),  "");
}


//------------------------------------------------------------------------------
// ksProcess2DPlacementChanged  -Изменение положения 
//---
BOOL Api7Draw::PlacementChanged(double x, double y, double angle, BOOL dynamic)
{
  DrawPhantom( x, y,angle, dynamic );

  return TRUE;
}


//----------------------------------------------------------------------------------
// prButtonUpdate        - Установка состояния кнопки спецпанели.
//---
BOOL Api7Draw::ButtonUpdate( long buttonID, long * check, VARIANT_BOOL  * _enable )
{
  switch (buttonID) 
  {
    case ID_Button1:
    case ID_Button2:
    case ID_Button3:
    {
      if ( m_PhantomType == static_cast<DrawType>(buttonID) )
        *check = TRUE;
      else
        *check = FALSE;
      break;
    }
  }
  return TRUE;
}


//-----------------------------------------------------------------------------
// prButtonClick - Нажатие кнопки
// ---
BOOL Api7Draw::ButtonClick( long buttonID )
{
  BOOL res = FALSE;

  switch (buttonID) 
  {
    case ID_Button1:
    case ID_Button2:
    case ID_Button3:
    {
      m_PhantomType = static_cast<DrawType>(buttonID);
      RedrawPhantom();
      res = TRUE;
      break;
    }
  }
  return res;
}


//-----------------------------------------------------------------------------
// Запуск процесса
// ---
void Api7Draw::ChoicePlacement()
{
  ksAPI7::IKompasDocument2D1Ptr doc2D( appl->ActiveDocument );

  if ( doc2D )
  {
    ksAPI7::IProcess2DPtr process2D( doc2D->LibProcess[ksProcess2DPlacement] );
    ksAPI7::IProcessPtr   process( process2D );

    if ( process )
    {
      process->ProcessParam = m_procParam;
      m_Process = process;
      new Process2DEvent( process2D, *this );
      RedrawPhantom();
      process->Run( true, false );
    }
  }
}

