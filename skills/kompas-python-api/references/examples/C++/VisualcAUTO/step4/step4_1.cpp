////////////////////////////////////////////////////////////////////////////////
//
// step4_1.cpp - процессы Cursor и Placement
//
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include <math.h>
#include "step4.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern KompasObjectPtr kompas;
extern CStep4App theApp;

ksDocument2DPtr docActive;

int type, flag=1;


//------------------------------------------------------------------------------
// Функция обратной связи, вызываемая из Cursor
// ---
int WINAPI CALLBACKPROCCURSOR( int comm, 
                               double* x, double*y, 
                               LPDISPATCH rInfo, LPDISPATCH rPhan, 
                               int dynamic ) 
{
  ksRequestInfoPtr info( rInfo );
  ksPhantomPtr     phan( rPhan );

  if ( info && phan ) 
  {
    phan->phantom = 1;
    ksType1Ptr t1( phan->GetPhantomParam() );
    switch ( comm ) 
    {
      case 1 : 
      case 2 : 
        type = comm; 
        break;
      case -1 : // Поставить в модель
      { 
        docActive->ksMoveObj( t1->gr, *x, *y );
        if ( ::fabs(t1->angle) > 0.001 )
          docActive->ksRotateObj( t1->gr, *x, *y, t1->angle );
        docActive->ksStoreTmpGroup( t1->gr );
        docActive->ksClearGroup( t1->gr, true );
      }
      break;
    }

    // Группа для фантома должна быть временная и обновляться при изменении вида отрисовки
    if ( t1->gr ) 
      docActive->ksDeleteObj( t1->gr );
    t1->gr = docActive->ksNewGroup(1); // Временная группа

    if ( (flag == 1 && comm == 1) || (flag == 2 && comm == 2) )
      type = 3;

    // Обновляется не только изображение но и меню для запроса
    switch ( type  ) 
    {
      case 1:
        docActive->ksCircle( 0, 0, 20, 1 );
        info->commandsString = _T("!Квадрат !Треугольник ");
        flag = 1;
        break;
      case 2:
        docActive->ksLineSeg( -10, 0,  10,  0,  1 );
        docActive->ksLineSeg( 10,  0,  0,   20, 1 );
        docActive->ksLineSeg( 0,   20, -10, 0,  1 );
        info->commandsString = _T("!Окружность !Квадрат ");
        flag = 2;
        break;
      case 3:
        docActive->ksLineSeg( -10, 0,  10,  0,  1 );
        docActive->ksLineSeg( 10,  0,  10,  20, 1 );
        docActive->ksLineSeg( 10,  20, -10, 20, 1 );
        docActive->ksLineSeg( -10, 20, -10, 0,  1 );
        info->commandsString = _T("!Окружность !Треугольник ");
        flag = 0;
        break;
    }
    docActive->ksEndGroup();
  }  
  return 1;
}


//------------------------------------------------------------------------------
// Функция обратной связи, вызываемая из Placement
// ---
int WINAPI CALLBACKPROCPLACEMENT( int comm, 
                                  double* x, double* y, double* ang, 
                                  LPDISPATCH rInfo,  LPDISPATCH rPhan, 
                                  int dynamic ) 
{
  ksRequestInfoPtr info( rInfo );
  ksPhantomPtr     phan( rPhan );

  if ( info && phan ) 
  {
    phan->phantom = 1;
    ksType1Ptr t1( phan->GetPhantomParam() );
    switch ( comm ) 
    {
      case 1 :
      case 2 : 
        type = comm; 
        break;
      case -1 : // Поставить в модель
      {                 
        docActive->ksMoveObj( t1->gr, *x, *y );
        // Отлтчте от Cursor угол приходит в виде параметра функции
        if ( ::fabs(*ang) > 0.001 )
          docActive->ksRotateObj( t1->gr, *x, *y, *ang );
        docActive->ksStoreTmpGroup( t1->gr );   
        // Поставить временную группу в вид
        docActive->ksClearGroup( t1->gr, true );
        break;
      }
    }

    // Группа для фантома должна быть временная и обновляться при изменении вида отрисовки
    if ( t1->gr ) 
      docActive->ksDeleteObj( t1->gr );
    t1->gr = docActive->ksNewGroup(1); // Временная группа

    // Обновляется не только изображение но и меню для запроса
    if ( (flag == 1 && comm == 1) || (flag == 2 && comm == 2) )
      type = 3;

    switch ( type ) 
    {
      case 1:
        docActive->ksCircle( 0, 0, 20, 1 );
        info->commandsString = _T("!Квадрат !Треугольник ");
        flag = 1;
        break;
      case 2:
        docActive->ksLineSeg( -10, 0,  10,  0,  1 );
        docActive->ksLineSeg( 10,  0,  0,   20, 1 );
        docActive->ksLineSeg( 0,   20, -10, 0,  1 );
        info->commandsString = _T("!Окружность !Квадрат ");
        flag = 2;
        break;
      case 3:
        docActive->ksLineSeg( -10, 0,  10,  0,  1 );
        docActive->ksLineSeg( 10,  0,  10,  20, 1 );
        docActive->ksLineSeg( 10,  20, -10, 20, 1 );
        docActive->ksLineSeg( -10, 20, -10, 0,  1 );
        info->commandsString = _T("!Окружность !Треугольник ");
        flag = 0;
        break;
    }

    docActive->ksEndGroup();
  }
  return 1;
}


//-------------------------------------------------------------------------------
//
// ---
void DrawRectCallBack( ksDocument2DPtr& doc ) {
  docActive = doc;
  type      = 1;
  ksPhantomPtr phan( kompas->GetParamStruct(ko_Phantom) );
  if ( phan ) {
    phan->Init();
    phan->phantom = 1;
    ksType1Ptr t1( phan->GetPhantomParam() );
    if ( t1 ) {
      t1->Init();
      t1->scale_ = 1;
      t1->gr = doc->ksNewGroup(1);   // временная группа
        doc->ksCircle( 0, 0, 20, 1 );
      doc->ksEndGroup();

      double x, y, ang;
      ksRequestInfoPtr info( kompas->GetParamStruct(ko_RequestInfo) );
      if ( info ) {
        info->Init();
        info->commandsString = _T("!Квадрат !Треугольник");
        // указываем адрес обратной функции для Placement
        info->SetCallBackP( _T("CALLBACKPROCPLACEMENT"), PtrToLong(theApp.m_hInstance), 0 );
        doc->ksPlacement( info, &x, &y, &ang, phan );

        t1->gr = doc->ksNewGroup(1);   // временная группа
          doc->ksCircle( 0, 0, 20, 1 );
        doc->ksEndGroup();

        // указываем адрес обратной функции для Cursor
        info->SetCallBackC( _T("CALLBACKPROCCURSOR"), PtrToLong(theApp.m_hInstance), 0 );
        doc->ksCursor( info, &x, &y, phan );
      }
    }
  }
}

//-------------------------------------------------------------------------------
//
// ---
void DrawRectNULL( ksDocument2DPtr& doc ) {
  int type = 1, flag=1;
  int j = 1;
  ksPhantomPtr phan( kompas->GetParamStruct(ko_Phantom) );
  if ( phan ) {
    phan->Init();
    phan->phantom = 1;
    ksType1Ptr t1( phan->GetPhantomParam() );
    if ( t1 ) {
      t1->Init();
      t1->scale_ = 1;
      t1->gr = 0;   // временная группа

      double x, y, ang;
      ksRequestInfoPtr info( kompas->GetParamStruct(ko_RequestInfo) );
      if ( info ) {
        info->Init();
        while ( j ) {

          if ( t1->gr )
            doc->ksDeleteObj( t1->gr );

          t1->gr = doc->ksNewGroup(1); // временная группа
          if ( (flag == 1 && j == 1) || (flag == 2 && j == 2) )
            type = 3;

          switch ( type ) {
            case 1:
              doc->ksCircle( 0, 0, 20, 1 );
              info->commandsString = _T("!Квадрат !Треугольник ");
              flag = 1;
              break;
            case 2:
              doc->ksLineSeg( -10, 0,  10,  0,  1 );
              doc->ksLineSeg( 10,  0,  0,   20, 1 );
              doc->ksLineSeg( 0,   20, -10, 0,  1 );
              info->commandsString = _T("!Окружность !Квадрат ");
              flag = 2;
              break;
            case 3:
              doc->ksLineSeg( -10, 0,  10,  0,  1 );
              doc->ksLineSeg( 10,  0,  10,  20, 1 );
              doc->ksLineSeg( 10,  20, -10, 20, 1 );
              doc->ksLineSeg( -10, 20, -10, 0,  1 );
              info->commandsString = _T("!Окружность !Треугольник ");
              flag = 0;
              break;
          }

          doc->ksEndGroup();

          j = doc->ksPlacement( info, &x, &y, &ang, phan );
//          j = doc->ksCursor( info, &x, &y, phan );
          switch ( j ) {
            case 1:
            case 2:  type = j; break;
            case -1: //поставить в модель
              doc->ksMoveObj( t1->gr, x, y );
              if ( ::fabs(t1->angle) > 0.001 )
                doc->ksRotateObj( t1->gr, x, y, ang /*t1.GetAngle()*/ );
              doc->ksStoreTmpGroup( t1->gr );    // поставить временную группу в вид
              doc->ksClearGroup( t1->gr, true );
              break;
          }
        }
      }
    }
  }
}
