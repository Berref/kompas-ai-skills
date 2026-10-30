////////////////////////////////////////////////////////////////////////////////
//
// UserSymbol.cpp - класс пользовательского обозначения
//
////////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "UserSymbol.h"

#define   MIN_LENGTH        1.0E-4  // минимальная  длина объекта

UserSymbol * obj = NULL;

//-------------------------------------------------------------------------------------
// Конструктор
//---
UserSymbol::UserSymbol()
  : m_x     ( 0 ),
    m_y     ( 0 ),
    m_endX  ( 0 ),
    m_endY  ( 0 ),
    m_repeat( true ),
    m_firstPoint( true ),
    m_edit( false ),
    m_editLeader( false ),
    m_leader( NULL )
{
  
}


//-------------------------------------------------------------------------------
//  Получить контейнер объектов 2D
// ---
IDrawingContainerPtr GetDrawingContainer()
{
  IDrawingContainerPtr res = NULL;
  // Получаем активный документ
  IKompasDocumentPtr doc( newKompasAPI->ActiveDocument );

  if ( doc )
  {
    // Получаем документ 2D 
    IKompasDocument2DPtr document2D( doc );

    if ( document2D ) 
    {
      // Получим менеджер для работы с видами и слоями
      IViewsAndLayersManagerPtr viewsMng ( document2D->GetViewsAndLayersManager() );

      if ( viewsMng )
      {
        // Получим коллекцию видов
        IViewsPtr views ( viewsMng->GetViews() );

        if ( views )
          res = views->GetActiveView(); //  Получаем контейнер
      }
    }
  }
  return res;
}


//-----------------------------------------------------------------------------
/**
  Создать отрезок по начальной точке, длине и углу
  \param lineSegCol - коллекция отрезков
  \param annCont    - контейнер аннотационных объектов
  \param x, y       - координаты начала отрезка
  \param len        - длина отрезка
  \param ang        - угол наклона отрезка
  \param style      - стиль линии отрезка
  \param x2         - координата Х конца отрезка
*/
//---
void CreateLineSeg( ILineSegmentsPtr & lineSegCol,
                    IAnnotativeContainerPtr & annCont, 
                    double x, double y, 
                    double len, double ang, long style, double * x2 )
{
  if ( lineSegCol )
  {
    // Добавляем отрезок в коллекцию
    ILineSegmentPtr lineSeg = lineSegCol->Add();

    if ( lineSeg )
    {
      lineSeg->X1 = x;
      lineSeg->Y1 = y;
      lineSeg->Length = len;
      lineSeg->Angle = ang;
      lineSeg->Style = style;
      lineSeg->Update();
      
      // Для вычисления точки привязки текста
      if ( x2 )
        *x2 = lineSeg->X2;
      
      // Преобразуем отрезок в аннотационный и удаляем исходный
      annCont->CreateByGeomObject( lineSeg );
      lineSeg->Delete();
    }
  }
}

      
//-----------------------------------------------------------------------------
/**
  Создать отрезок по двум точкам
  \param lineSegCol - коллекция отрезков
  \param x1, y1     - координаты начала отрезка
  \param x2, y2     - координаты конца отрезка
  \return указатель на отрезок
*/
//---
ILineSegmentPtr CreateLineSegmentByPoints(  ILineSegmentsPtr & lineSegCol, 
                                            double x1, double y1, 
                                            double x2, double y2 )
{
  ILineSegmentPtr lineSeg = NULL;
  
  if ( lineSegCol )
  { 
    lineSeg = lineSegCol->Add();
    
    if ( lineSeg )
    {
      lineSeg->X1 = x1;
      lineSeg->Y1 = y1;
      lineSeg->X2 = x2;
      lineSeg->Y2 = y2;
      lineSeg->Style = ksCSNormal;
      lineSeg->Update();
    }  
  }
  return lineSeg;
}


//-----------------------------------------------------------------------------
/**
  Создать текст
  \param textsCol - коллекция текстов
  \param annCont  - контейнер аннотационных объектов
  \param x, y     - координаты точки привязки текста
  \param str      - строка текста
*/
//---
void CreateText(  IDrawingTextsPtr & textsCol, 
                  IAnnotativeContainerPtr & annCont, 
                  double x, double y, 
                  _bstr_t str )
{
  if ( textsCol )
  {
    // Добавляем текст в коллекцию
    IDrawingTextPtr drawText( textsCol->Add() );
    
    if ( drawText )
    {
      // Залаем точку привязки
      drawText->X = x;
      drawText->Y = y;
      
      ITextPtr txt( drawText );
      
      if ( txt )
        txt->Str = str;
        
      drawText->Update();
      if ( annCont )
      {
        // Преобразуем текст в аннотационный и удаляем исходный
        annCont->CreateByGeomObject( drawText );
        drawText->Delete();
      }
    }
  }
}


//-----------------------------------------------------------------------------
/**
  Создать выносную линию
  \param macroObj       - макроэлемент
  \param beginX, beginY - координаты начала полки
  \param endX, endY     - координаты конечной точки ответвления
*/
//---
IBaseLeaderPtr CreateLeader(  IMacroObjectPtr & macroObj, 
                              double beginX, double beginY, 
                              double endX,   double endY )
{
  IBaseLeaderPtr baseLeader;
  
  if ( macroObj )
  {
    // Получаем коллекцию присоединенных линий-выносок
    ILeadersPtr leadersCol( macroObj->AttachedLeaders );

    if ( leadersCol )
    {
      // Добавляем линию-выноску
      ILeaderPtr leader( leadersCol->Add(ksDrLeader) );

      if ( leader )
      {
        // Добавляем ответвление
        IBranchsPtr branches( leader );

        if ( branches )
        {
          branches->X0 = beginX;
          branches->Y0 = beginY;
          branches->AddBranchByPoint( -1, endX, endY );
        }

        baseLeader = leader;

        if ( baseLeader )
        {
          baseLeader->Update();
        }   
      }
    }
  }
  return baseLeader;
}


//-----------------------------------------------------------------------------
/**
  Создать заливку
  \param drawCont - контейнер графических объектов
  \param annCont  - контейнер аннотационных объектов
  \param x, y     - координаты базовой точки для отрисовки заливки
*/
//---
void CreateColouring( IDrawingContainerPtr & drawCont, IAnnotativeContainerPtr & annCont, double x, double y )
{
  // Получаем коллекцию заливок
  IColouringsPtr colouringsCol( drawCont->Colourings );
  
  if ( colouringsCol )
  {
    // Добавляем новую заливку
    IColouringPtr colouring( colouringsCol->Add() );
    
    if ( colouring )
    {
      // Добавляем границу
      IBoundariesObjectPtr boundObj( colouring );
      {
        // Создаем отрезки границы
        ILineSegmentsPtr lineSegsCol( drawCont->LineSegments );
        
        if ( lineSegsCol )
        {
          ILineSegmentPtr lineSeg1( CreateLineSegmentByPoints(lineSegsCol, x, y + 5, x, y + 10) );
          ILineSegmentPtr lineSeg2( CreateLineSegmentByPoints(lineSegsCol, x, y + 10, x - 10, y + 7) );
          ILineSegmentPtr lineSeg3( CreateLineSegmentByPoints(lineSegsCol, x - 10, y + 7, x, y + 5) );
          
          if ( lineSeg1 && lineSeg2 && lineSeg3 )
          {
            IAnnotativeObjectPtr annLineSeg1( annCont->CreateByGeomObject(lineSeg1) );
            IAnnotativeObjectPtr annLineSeg2( annCont->CreateByGeomObject(lineSeg2) );
            IAnnotativeObjectPtr annLineSeg3( annCont->CreateByGeomObject(lineSeg3) );
            lineSeg1->Delete();
            lineSeg2->Delete();
            lineSeg3->Delete();
            boundObj->AddBoundaries( (LPDISPATCH)annLineSeg1, TRUE );
            boundObj->AddBoundaries( (LPDISPATCH)annLineSeg2, TRUE );
            boundObj->AddBoundaries( (LPDISPATCH)annLineSeg3, TRUE );
            colouring->Color1 = RGB( 0, 0, 0 );
            colouring->Update();
          }
        }
      }
    }
  }
}


//-------------------------------------------------------------------------------------
// Создать макроэлеменет - обозначение
//---
void UserSymbol::CreateMacro()
{
  ViewParamT viewPar;
  // Пересчет координат для масштабированных видов
  reference viewRef = GetReferenceDocumentPart( 3/*текущий вид*/ );
  GetObjParam( viewRef, &viewPar, sizeof(viewPar), ALLPARAM_T );
  ksMtr( 0, 0, 0, viewPar.scale, viewPar.scale );
  double x = m_x, y = m_y;
  double len1 = 52, len2 = 2, len3 = 8;
  ksPointFromMtr( m_x, m_y, &x, &y );
  ksLengthIntoMtr( &len1 );
  ksLengthIntoMtr( &len2 );
  ksLengthIntoMtr( &len3 );
  DeleteMtr();
  
  // Получаем контейнер графических объектов
  IDrawingContainerPtr drawCont( ::GetDrawingContainer() );

  if ( drawCont )
  {
    // Получаем коллекцию макрообектов
    IMacroObjectsPtr macroCol( drawCont->MacroObjects );

    if ( macroCol )
    {
      // Добавляем новый макрообъект
      IMacroObjectPtr macroObj( macroCol->Add(FALSE/*MultyLayer*/) );
      
      if ( macroObj )
      {
        ksSetMacroParamT( macroObj->Reference, NULL, 0, NULL, NULL, 1, 0 /*MP_HOTPOINTS*/  );
        macroObj->BreakObjectsEnabled = VARIANT_FALSE;
        // Получаем контейнер графических объектов макроэлемента
        IDrawingContainerPtr macroCont( macroObj );
        // Получаем контейнер аннотационных объектов макроэлемента
        IAnnotativeContainerPtr annCont( macroObj );
        
        if ( macroCont && annCont )
        {
          // Для вычисления точки привязки текста
          double textX;
          // Строим отрезки
          ILineSegmentsPtr lineSegCol( macroCont->LineSegments );
          
          if ( lineSegCol )
          {
            CreateLineSeg( lineSegCol, annCont, x, y, 90, 0, ksCSThin, NULL );
            CreateLineSeg( lineSegCol, annCont, x, y, 10, 90, ksCSThin, NULL );
            CreateLineSeg( lineSegCol, annCont, x + 2, y - 1, 88, 0, ksCSDashed, NULL );
            CreateLineSeg( lineSegCol, annCont, x + 40, y - 10, 5, 0, ksCSNormal, NULL );
            CreateLineSeg( lineSegCol, annCont, x + 50, y + 10, 5, 180, ksCSNormal, NULL );
            CreateLineSeg( lineSegCol, annCont, x + 90, y, 5, 45, ksCSThin, NULL );
            // Вычисляем точку привязки текста
            CreateLineSeg( lineSegCol, annCont, x + 90, y, 5, 315, ksCSThin, &textX );
            textX += 2;
            
            ILineSegmentPtr lineSeg1( CreateLineSegmentByPoints(lineSegCol, x + 40, y - 10, x + 50, y + 10) );
            
            if ( lineSeg1 )
            {
              annCont->CreateByGeomObject( lineSeg1 );
              lineSeg1->Delete();
            }
          }
          
          // Пересчет координат для масштабированных видов
          ksMtr( 0, 0, 0, viewPar.scale, viewPar.scale );
          double textDx = textX, textDy = 0;
          ksPointIntoMtr( textX, m_x + 2, &textDx, &textDy );
          DeleteMtr();
          
          // Создаем тексты
          IDrawingTextsPtr textsCol( macroCont->DrawingTexts );
          
          if ( textsCol )
          {
            CreateText( textsCol, annCont, m_x + len1, m_y + len2, _T("Текст1") );
            CreateText( textsCol, annCont, m_x + len1, m_y - len3, _T("Текст2") );
            CreateText( textsCol, annCont, textDx, m_y + len2, _T("Текст3") );
            CreateText( textsCol, annCont, textDx, m_y - len3, _T("Текст4") );
          }
        }
        // Создаем заливку
        CreateColouring( macroCont, annCont, x, y );
        // Добавляем к макроэлементу линию-выноску
        m_leader = CreateLeader( macroObj, m_x, m_y, m_endX, m_endY );
        macroObj->Update();
      }
    }
  }
}


//-------------------------------------------------------------------------------------
// Функция обратной связи для редактирования элемента
//---
int WINAPI UserSymbol::CallBack( int           com,                          // Номер команды
                                 double      * x, double * y,                // Координаты курсора
                                 RequestInfo * info,                         // Параметры запроса
                                 void        * phantom,                      // Фантом
                                 int           dynamic )
{
  // Указываем точку конца ответвления
  if ( obj->GetFirstPoint() && !dynamic )
  {
    obj->SetEndX( *x );
    obj->SetEndY( *y );
    obj->SetFirstPoint( false );
  }
  // Указываем базовую точку
  else
  {
    if ( !obj->GetFirstPoint() )
    {
      Phantom * ph = (Phantom*)phantom;
      if ( dynamic ) 
      {
        // Запоминаем координаты курсора
        obj->SetX( *x );
        obj->SetY( *y );

        // Пересчет координат для масштабированных видов
        ViewParamT viewPar;
        reference viewRef = GetReferenceDocumentPart( 3/*текущий вид*/ );
        GetObjParam( viewRef, &viewPar, sizeof(viewPar), ALLPARAM_T );
        ksMtr( 0, 0, 0, viewPar.scale, viewPar.scale );
        double beginX = *x, beginY = *y, endX = obj->GetEndX(), endY = obj->GetEndY();
        ksPointFromMtr( *x, *y, &beginX, &beginY );
        ksPointFromMtr( obj->GetEndX(), obj->GetEndY(), &endX, &endY );
        DeleteMtr();

        if ( phantom && DistancePntPnt(beginX, beginY, endX, endY) > MIN_LENGTH )
        {
          // Перерисовываем фантом
          if ( ph->type6.gr )
            DeleteObj( ph->type6.gr );
          reference gr = NewGroup( 1 );
          Macro( 0 );
          // Отрисовываем стрелку
          AnnLineSeg( beginX, beginY, endX, endY, 0/*без значка*/, 1/*стрелка*/, 1 );
          // Отрисовываем габаритный прямоугольник
          double baseX = beginX - 10, baseY = beginY - 10;
          AnnLineSeg( beginX, beginY, beginX, beginY + 20, 0/*без значка*/, 0/*без значка*/, 1 );
          AnnLineSeg( beginX, beginY + 20, beginX + 125, beginY + 20, 0/*без значка*/, 0/*без значка*/, 1 );
          AnnLineSeg( beginX + 125, beginY + 20, beginX + 125, beginY, 0/*без значка*/, 0/*без значка*/, 1 );
          AnnLineSeg( beginX + 125, beginY, beginX, beginY, 0/*без значка*/, 0/*без значка*/, 1 );
          EndObj();
          EndGroup();
          ph->type6.gr = gr;
        }
      }
      else // Указали вторую точку
      {
        if ( ph->type6.gr )
        {
          DeleteObj( ph->type6.gr );
          ph->type6.gr = 0;
        } 
        obj->CreateMacro();
        // Здесь создать объект в документе
        obj->SetFirstPoint( true );
      }
    }
  }
  return 1;
}


//-------------------------------------------------------------------------------------
// Создать или отредактировать обозначение
//---
void UserSymbol::Draw()
{ 
  if ( InitProcessParam() )
  {
    RequestInfoT info;
    memset(&info, 0, sizeof(info) );
    info.dynamic = 1;
    double x = 0, y = 0, x1 = 0, y1 = 0;
    m_repeat = true;
    Phantom phant;
    memset( &phant, 0, sizeof(phant) );
    phant.phType = 6;

    info.callBack = &CallBack;
    obj = this;

    while ( m_repeat )
    {
      m_repeat = false;
      reference macroRef = EditMacroMode();
      m_edit = !!macroRef;
      
      if ( m_edit )
        info.callBack = NULL;
        
      // Указываем базовую точку или точку конца ответвления
      CursorExT( &info, &x, &y, &phant, m_procParam);
      
      // Если редактируем
      if ( m_editLeader )
      {
        IMacroObjectPtr macroObj = ksTransferReference( macroRef, ksGetCurrentDocument(0) );
        
        if ( macroObj )
        {
          // Получаем коллекцию присоединенных линий-выносок
          ILeadersPtr leadersCol( macroObj->AttachedLeaders );
          
          if ( leadersCol )
          {
            ILeaderPtr leader( leadersCol->GetItem((long)0) );
            
            if ( leader )
            {
              IBaseLeaderPtr baseLeader( leader );
              
              // Запускаем процесс редактирования выносной линии
              if ( baseLeader )
                ksEditViewObject( baseLeader->Reference );
            }
          }
        }
        m_editLeader = false;
      }
      info.callBack = NULL;
    }
  }
}


//-------------------------------------------------------------------------------------
//
//---
bool UserSymbol::OnButtonClick( long buttonID )
{
  if ( buttonID == pbEnter )
  {
    m_repeat = true;
    m_firstPoint = true;
  }  
    
  else if ( buttonID == 500 )
  {
    m_repeat = true;
    m_editLeader = true;
    newKompasAPI->StopCurrentProcess( TRUE, newKompasAPI->ActiveDocument );
  }
  return true;
}


//-----------------------------------------------------------------------------
// prButtonUpdate        - Установка состояния кнопки спецпанели.
// ---
bool UserSymbol::OnButtonUpdate( long buttonID, long * check, VARIANT_BOOL * _enable ) 
{
  if ( buttonID == pbEnter )
    *_enable = m_edit;
    
  if ( buttonID == 500 )
    *_enable = m_edit;
       
  return true;
}