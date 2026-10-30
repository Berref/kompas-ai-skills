////////////////////////////////////////////////////////////////////////////////
//
// Step1_API7_2D.cpp.cpp - Обозначения для ПСП
//
//   1: NewDocument();                - Создать документ
//   2: NewMark();                    - Создать марку без линии-выноски
//   3: NewUnitMarking();             - Создать обозначение узла 
//   4: AddStrAxis();                 - Прямая ось
//   5: AddCircleAxis();              - Круговая ось
//   6: NewMarkOnLeader();            - Создать марку с линией-выноскойоской
//   7: NewMarkOnLine();              - Марка/поз.обозначение
//   8: NewBrace();                   - Фигурная скобка
//   9: NewMultiTextLeader();         - Выносная надпись к многослойным конструкциям
//
////////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <afxdllx.h>
#include "Step1_API7_2D.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

class LpSelfText;

//-------------------------------------------------------------------------------
// Специальная структура используемая в течении инициализации DLL
// ---
static AFX_EXTENSION_MODULE DocCollectionDLL = { NULL, NULL };
HINSTANCE g_hInstance = NULL;

ksAPI7::IApplicationPtr newKompasAPI( NULL );               

void OnProcessDetach();                            // Отключение библиотеки

//-------------------------------------------------------------------------------
// Стандартная точка входа
// Инициализация и завершение DLL
// ---
extern "C" int APIENTRY
DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
  g_hInstance = hInstance;

	if (dwReason == DLL_PROCESS_ATTACH)
	{
		TRACE0("DOCCOLLECTION.AWX Initializing!\n");

		AfxInitExtensionModule(DocCollectionDLL, hInstance);

		new CDynLinkLibrary(DocCollectionDLL);
	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		TRACE0("DOCCOLLECTION.AWX Terminating!\n");
    OnProcessDetach();
		AfxTermExtensionModule(DocCollectionDLL);
	}
	return 1;   // ok
}

//-------------------------------------------------------------------------------
// Получить доступ к новому API
// ---
void GetNewKompasAPI() 
{
	if ( !(bool)newKompasAPI ) 
  {
		CString filename;
	
    if( ::GetModuleFileName(NULL, filename.GetBuffer(255), 255) ) 
    {
			filename.ReleaseBuffer( 255 );
			CString libname;

      libname = LoadStr( IDR_API7 );    // kAPI7.dll
			filename.Replace( filename.Right(filename.GetLength() - (filename.ReverseFind('\\') + 1)), 
												libname );

			HINSTANCE hAppAuto = LoadLibrary( filename ); // идентификатор kAPI7.dll
		
      if(  hAppAuto ) 
      {
				// Указатель на функцию, возвращающую интерфейс KompasApplication  
        typedef LPDISPATCH ( WINAPI * FCreateKompasApplication )(); 
				 
        FCreateKompasApplication pCreateKompasApplication = 
					(FCreateKompasApplication)GetProcAddress( hAppAuto, "CreateKompasApplication" );	
				
        if ( pCreateKompasApplication )
					newKompasAPI = IDispatchPtr( pCreateKompasApplication(), false ); // Получаем интерфейс Application
				FreeLibrary( hAppAuto );  
			}
		}
	}
}

//-------------------------------------------------------------------------------
// Задать идентификатор ресурсов
// ---
unsigned int WINAPI LIBRARYID()
{
  return IDR_LIBID;
}


//-------------------------------------------------------------------------------
// _1_ Создать документ
// ---
void NewDocument()
{
  if( !(bool)newKompasAPI )
    return;

  //Получить указатель на интерфейс коллекции документов
  ksAPI7::IDocumentsPtr pDocuments( newKompasAPI->Documents );

  if( !(bool)pDocuments )
    return;

  //Получить указатель на интерфейс IKompasDocument
  //Вызов Add создаёт документ, (тип указан в списке параметров) и добавляет его в коллекцию
  ksAPI7::IKompasDocumentPtr pKompasDocument( pDocuments->AddWithDefaultSettings(ksDocumentDrawing, true) );
}


//-------------------------------------------------------------------------------
// Получить указатель на коллекцию отрезков (Auto)
// ---
ksAPI7::ILineSegmentsPtr GetILineSegments()
{
  ksAPI7::ILineSegmentsPtr pLineSegments;
  ksAPI7::IKompasDocument2DPtr pKompasDocument2D( newKompasAPI->GetActiveDocument() );
   
  if ( pKompasDocument2D )
  {
    //Получить указатель на интерфейс менеджера видов и слоёв     
    ksAPI7::IViewsAndLayersManagerPtr pViewsAndLayersManager = pKompasDocument2D->GetViewsAndLayersManager();
    
    if( pViewsAndLayersManager )
    { 
      //Получить указатель на интерфейс коллекции видов
      ksAPI7::IViewsPtr pViews = pViewsAndLayersManager->GetViews();
  
      if( pViews )
      {
        //Получить указатель на интерфейс вида
        //Свойство View- возвращает указатель на вид, заданный по индексу( в данном случае )  
        ksAPI7::IViewPtr pView =  pViews->GetActiveView();  
        ksAPI7::IDrawingContainerPtr pDrawingContainer( pView );
  
        if( pDrawingContainer )
        {
          //Получить указатель на коллекцию отрезков
          pLineSegments = pDrawingContainer->GetLineSegments();
  
        }
      }      
    } 
  }
  return pLineSegments;
}


//-------------------------------------------------------------------------------
// Получить указатель на интерфейс коллекции видов (COM)
// ---
ksAPI7::IViewsPtr GetViewsPtr()
{
  ksAPI7::IViewsPtr res;
  
  if ( newKompasAPI )
  {
    //Получить указатель на интерфейс документа Компас
    ksAPI7::IKompasDocument2DPtr pKompasDocument2D;
    pKompasDocument2D = newKompasAPI->ActiveDocument;
      
    if ( (bool)pKompasDocument2D )
    {          
      //Получить указатель на интерфейс менеджера видов и слоёв
      ksAPI7::IViewsAndLayersManagerPtr pViewsAndLayersManager;
      pViewsAndLayersManager = pKompasDocument2D->GetViewsAndLayersManager();
      
      if ( pViewsAndLayersManager )
        res = pViewsAndLayersManager->GetViews();
    }  
  }
  return res;
}


//-------------------------------------------------------------------------------
// _2_ Создать марку без линии-выноски
// ---
void NewMark()
{
  ksAPI7::IViewsPtr pViews = GetViewsPtr();
  if( !(bool)pViews )
    return;
  
  //Получить указатель на интерфейс вида
  //Свойство ActiveView- возвращает указатель на активный вид
  ksAPI7::IViewPtr pView( pViews->ActiveView );  
  
  
  //Получить указатель на контейнер объектов СПДС
  ksAPI7::IBuildingContainerPtr pBuildingContainer( pView );
  
  if( !(bool)pBuildingContainer )
    return;
  
  //Получить указатель на коллекцию марок
  ksAPI7::IMarksPtr pMarks( pBuildingContainer->Marks );
  
  if( !(bool)pMarks )
    return;
  //Получить указатель на марку 
  ksAPI7::IMarkInsideFormPtr pMarkInF( pMarks->Add(ksDrMarkInsideForm) );      
  if ( !(bool)pMarkInF )
    return;  
  
  pMarkInF->X = 250;
  pMarkInF->Y = 250;
  pMarkInF->Form = ksMFormRectangle	;
  pMarkInF->FormGabarit = 45;
  pMarkInF->FormHeight = 50;
  pMarkInF->Angle = 45;
  pMarkInF->FormStyle = ksCSAxial;

              
  pMarkInF->Update(); 
 
  //Взять координаты точки привязки
  double x = pMarkInF->X;
  double y = pMarkInF->Y;
  TCHAR buf[255];
  _stprintf_s( buf, _T("Координаты точки привязки:/nX = %g, Y = %g"), x, y);
  MessageT( buf );
}


//-------------------------------------------------------------------------------
// _7_ Создать марку с линией-выноской
// ---
void NewMarkOnLeader()
{
  ksAPI7::IViewsPtr ppViews = GetViewsPtr();
  if ( !(bool)ppViews )
    return;

  //Получить указатель на интерфейс вида
  //Свойство ActiveView- возвращает указатель на активный вид
  ksAPI7::IViewPtr ppView( ppViews->ActiveView );  
  
 
  //Получить указатель на контейнер объектов СПДС
  ksAPI7::IBuildingContainerPtr ppBuildingContainer( ppView );
  
  if ( !(bool)ppBuildingContainer )
    return;
  
  //Получить указатель на коллекцию марок
  ksAPI7::IMarksPtr ppMarks( ppBuildingContainer->Marks );
  
  if( !(bool)ppMarks )
    return;
  
  //Получить указатель на марку 
  ksAPI7::IMarkOnLeaderPtr pMarkOnL( ppMarks->Add( ksDrMarkOnLeader	) );      
  if ( !(bool)pMarkOnL )
    return;  

  pMarkOnL->X = 150;
  pMarkOnL->Y = 150;
  pMarkOnL->ArrowType = ksLeaderArrow;
  pMarkOnL->ShelfDirection = ksLSLeft;
  pMarkOnL->AddBranchByPoint( 1, FALSE, 100, 100);
  pMarkOnL->Update();

  ksAPI7::ITextPtr pTextAfter( pMarkOnL->GetTextAfter() );   
  _bstr_t strAfter = _T("  текст после");
  pTextAfter->PutStr( strAfter );

  ksAPI7::ITextPtr pTextBefore( pMarkOnL->GetTextBefore() );
  _bstr_t strBefore = _T("Текст до  ");
  pTextBefore->PutStr( strBefore );    

   ksAPI7::ITextPtr pTextUnder( pMarkOnL->GetTextUnder() );
  _bstr_t strUnder = _T("Текст под полкой  ");
  pTextUnder->PutStr( strUnder );    

  pMarkOnL->Update();
  MessageT( _T("Марка с линией-выноской") );
  
}

//-------------------------------------------------------------------------------
// _9_ Создать марку/позиционное обозначение
// ---
void NewMarkOnLine()
{
  ksAPI7::IViewsPtr pViews = GetViewsPtr();
  if ( !(bool)pViews )
    return;
  //Получить указатель на интерфейс вида
  //Свойство ActiveView- возвращает указатель на активный вид
  ksAPI7::IViewPtr pView( pViews->ActiveView );  
  
 
  //Получить указатель на контейнер объектов СПДС
  ksAPI7::IBuildingContainerPtr ppBuildingContainer( pView );
  
  if ( !(bool)ppBuildingContainer )
    return;
  
  //Получить указатель на коллекцию марок
  ksAPI7::IMarksPtr pMarks( ppBuildingContainer->Marks );
  
  if( !(bool)pMarks )
    return;
  
  //Получить указатель на марку 
  ksAPI7::IMarkOnLinePtr pMarkOnLine( pMarks->Add( ksDrMarkOnLine	) );      
  if ( !(bool)pMarkOnLine )
    return;  
    //марка над объектом     
       
  ksAPI7::ITextPtr pTextAfter( pMarkOnLine->GetTextAfter() );   
  _bstr_t strAfter = _T("  текст после");
  pTextAfter->PutStr( strAfter );

      
  //построение отрезка - объект для размещения марки

  ksAPI7::ILineSegmentsPtr pLineSegments = GetILineSegments();
  ksAPI7::ILineSegmentPtr pLineSegment( pLineSegments->Add()); 
  
  if ( !(bool)pLineSegment )
    return;
  
  pLineSegment->PutX1   ( 100 );
  pLineSegment->PutY1   ( 100 );
  pLineSegment->PutX2   ( 150 );
  pLineSegment->PutY2   ( 110 );
  // Установить стиль линии
  pLineSegment->PutStyle( 1 );
  pLineSegment->Update  ();  
          
  pMarkOnLine->Line = pLineSegment;
  pMarkOnLine->Position = ksMTextOnLine	;
     

  pMarkOnLine->Update();
  MessageT( _T("Марка/позиционное обозначение") ); 
}


//-------------------------------------------------------------------------------
// _10_ Создать выносную надпись к многослойным конструкциям
// ---
void NewMultiTextLeader()
{
  ksAPI7::IViewsPtr ppViews = GetViewsPtr();
  if ( !(bool)ppViews )
    return;
  
  //Получить указатель на интерфейс вида
  //Свойство ActiveView- возвращает указатель на активный вид
  ksAPI7::IViewPtr ppView( ppViews->ActiveView );  
  
 
  //Получить указатель на контейнер объектов СПДС
  ksAPI7::IBuildingContainerPtr ppBuildingContainer( ppView );
  
  if( !(bool)ppBuildingContainer )
    return;
  //Получить указатель на коллекцию выносных линий к многослойным объектам (ВЛКМО)
  ksAPI7::IMultiTextLeadersPtr pMTLs( ppBuildingContainer->MultiTextLeaders );
  
  if ( !(bool)pMTLs )
    return;
  
  //Получить указатель на ВЛКМО 
  ksAPI7::IMultiTextLeaderPtr pMTL( pMTLs->Add() );      
  if ( !(bool)pMTL )
    return;  

  pMTL->Form = TRUE;
  pMTL->ArrowType = ksLeaderArrow;
  pMTL->ShelfX = 150;
  pMTL->ShelfY = 150;
  pMTL->TextDirection = TRUE;
  pMTL->ShelfDirection = ksLSRight;
  pMTL->AddBranchByPoint(  1, 100, 100);
  pMTL->AddBranchByPoint( -1, 120, 100);
  pMTL->AddBranchByPoint( -1, 130, 100);
  pMTL->Update();

  ksAPI7::ITextPtr pText1( pMTL->GetText() );   
  _bstr_t strTxt1 = _T("текст выносной надписи1");
  pText1->PutStr( strTxt1 );

  pMTL->Update();
  MessageT(_T("Выносная надпись к многослойным конструкциям") );
}


//-------------------------------------------------------------------------------
// _11_ Создать фигурную скобку
// ---
void NewBrace()
{
  ksAPI7::IViewsPtr ppViews = GetViewsPtr();
  if ( !(bool)ppViews )
    return;
  
  //Получить указатель на интерфейс вида
  //Свойство ActiveView- возвращает указатель на активный вид
  ksAPI7::IViewPtr ppView( ppViews->ActiveView );  
  
 
  //Получить указатель на контейнер объектов СПДС
  ksAPI7::IBuildingContainerPtr ppBuildingContainer( ppView );
  
  if ( !(bool)ppBuildingContainer )
    return;
  
  //Получить указатель на коллекцию фигурных скобок
  ksAPI7::IBracesPtr pBraces( ppBuildingContainer->Braces );
  
  if ( !(bool)pBraces )
    return;
  
  //Получить указатель на фигурную скобку 
  ksAPI7::IBracePtr pBrace( pBraces->Add() );      
  if ( !(bool)pBrace )
    return;  
         
  pBrace->X1 = 50;
  pBrace->Y1 = 200;   
  pBrace->Alignment = ksATArbitrary;
  pBrace->Angle = 200;
  pBrace->ShelfDirection = ksLSRight;
  pBrace->Direction = TRUE;
  pBrace->Length = 100;
  pBrace->Radius = 25;
  pBrace->ShelfDirection = ksLSRight;
  pBrace->Style = 7;
  pBrace->Update();

  ksAPI7::ITextPtr pText1( pBrace->GetText() );   
  _bstr_t strTxt1 = _T("текст фигурной скобки");
  pText1->PutStr( strTxt1 );

  pBrace->Update();
  MessageT(_T("Фигурная скобка"));
}


//-------------------------------------------------------------------------------
// _3_ Проверить свойства интерфейса обозначения узла (Auto)
// ---
void UnitMarkingksParam()
{
  ksAPI7::IKompasDocument2DPtr pKompasDocument2D = newKompasAPI->GetActiveDocument();
   
  if ( pKompasDocument2D )
  {
    //Получить указатель на интерфейс менеджера видов и слоёв     
    ksAPI7::IViewsAndLayersManagerPtr pViewsAndLayersManager = pKompasDocument2D->GetViewsAndLayersManager();
    
    if( pViewsAndLayersManager )
    { 
      //Получить указатель на интерфейс коллекции видов
      ksAPI7::IViewsPtr pViews = pViewsAndLayersManager->GetViews();
  
      if( pViews )
      {
        //Получить указатель на интерфейс вида
        //Свойство View- возвращает указатель на вид, заданный по индексу( в данном случае )  
        ksAPI7::IViewPtr pView =  pViews->GetActiveView();  
  
          //Получить указатель на контейнер объектов СПДС
        ksAPI7::IBuildingContainerPtr pBuildingContainer( pView );
        if( pBuildingContainer )
        {
            //Получить указатель на коллекцию обозначений узла 
          ksAPI7::IUnitMarkingsPtr pUnitMarkings( pBuildingContainer->GetUnitMarkings() );
          
          if( pUnitMarkings )
          {
            //Получить указатель на обозначение узла 
            _variant_t v = (long)0;
            ksAPI7::IUnitMarkingPtr pUnitMarking( pUnitMarkings->GetUnitMarking(v) );
             
            if( pUnitMarkings )
            {
            
              double Radius = pUnitMarking->GetRadius();
              double Height = pUnitMarking->GetHeight();
              double Width  = pUnitMarking->GetWidth();
            }
          } 
        }
      }
    }  
  }
}


    

//-------------------------------------------------------------------------------
// _19_ Создание прямой координационной оси..
//      
// --- 
void AddStrAxis()
{
  if ( newKompasAPI )
  {  
    // получить 2D документ
    ksAPI7::IKompasDocument2DPtr doc2D = newKompasAPI->GetActiveDocument();

    if ( doc2D )
    {
      // получить менеджер видов и слоев
      ksAPI7::IViewsAndLayersManagerPtr view_men = doc2D->GetViewsAndLayersManager();
      
      if ( view_men )
      {       
        // получить коллекцию видов
        ksAPI7::IViewsPtr views = view_men->GetViews();
        
        if ( views )
        {
          // Здесь делается QueryInterface с вида на контейнер СПДС
          // (это видно под отладчиком)
          ksAPI7::IBuildingContainerPtr pBuildContainer( views->GetActiveView() );
          
          if ( pBuildContainer )
          {
            // получить коллекцию строительных осей
            ksAPI7::IBuildingAxesPtr axes;
            pBuildContainer->get_BuildingAxes(&axes);
          
            if ( axes )
            {
              // получить прямую ось
              ksAPI7::IStraightAxisPtr ax1( axes->Add(ksDrStraightAxis) );
              //ksAPI7::IBuildingAxisPtr ax1 = axes->Add(ksDrStraightAxis);
              if (ax1)
              {
                ax1->Angle = 45;
                ax1->Length = 100;
              
                ax1->Update(); 
              }

            }
          }
        }
      }
    }
  }
}


//-------------------------------------------------------------------------------
// _20_ создание круговой координационной оси..
// 
// --- 
void AddCircleAxis()
{
  if ( newKompasAPI )
  {  
    // получить 2D документ
    ksAPI7::IKompasDocument2DPtr doc2D = newKompasAPI->GetActiveDocument();

    if ( doc2D )
    {
      // получить менеджер видов и слоев
      ksAPI7::IViewsAndLayersManagerPtr view_men = doc2D->GetViewsAndLayersManager();
      
      if ( view_men )
      {       
        // получить коллекцию видов
        ksAPI7::IViewsPtr views = view_men->GetViews();
        
        if ( views )
        {
          // Здесь делается QueryInterface с вида на контейнер СПДС
          // (это видно под отладчиком)
          ksAPI7::IBuildingContainerPtr pBuildContainer( views->GetActiveView() );
          
          if ( pBuildContainer )
          {
            // получить коллекцию строительных осей
            ksAPI7::IBuildingAxesPtr axes;
            pBuildContainer->get_BuildingAxes(&axes);
          
            if ( axes )
            {
              // получить круговую ось
              ksAPI7::ICircleAxisPtr axC( axes->Add(ksDrCircleAxis) );
              //ksAPI7::IBuildingAxisPtr ax1 = axes->Add(ksDrStraightAxis);
              if (axC)
              {
                axC->Xc = 100;
                axC->Yc = 100;
                axC->Radius = 100;
                axC->MarkOn = TRUE;
                axC->MarkAngle	= 45;
                 
                axC->Update(); 
              }
            }
          }
        }
      }
    }
  }
}


//-------------------------------------------------------------------------------
// Головная функция библиотеки
// ---
void WINAPI LIBRARYENTRY( unsigned int comm )
{  
  GetNewKompasAPI(); 

  switch ( comm )
  {  
    case  1: NewDocument();           break; // Создать документ
    case  2: NewMark();               break; // Создать марку без линии-выноски
    case  3: AddStrAxis();            break; // Прямая ось
    case  4: AddCircleAxis();         break; // Круговая ось
    case  5: NewMarkOnLeader();       break; // Создать марку с линией-выноской
    case  6: NewMarkOnLine();         break; // Марка/поз.обозначение
    // БП в меню стоят наоборот
	// case  7: NewBrace();              break; // Фигурная скобка
    //case  8: NewMultiTextLeader();    break; // Выносная надпись к многослойным конструкциям  
	// переставляю
	case  7: NewMultiTextLeader();    break; // Выносная надпись к многослойным конструкциям 
    case  8: NewBrace();              break; // Фигурная скобка		
  }
}


//-------------------------------------------------------------------------------
// Завершение приложения
// ---
void OnProcessDetach()
{
  newKompasAPI = NULL;
}


//------------------------------------------------------------------------------
// Загрузить строку из ресурса
// ---
CString LoadStr( int strID ) 
{
	TCHAR temp[512];
	LoadString( DocCollectionDLL.hModule, strID, temp, _MAX_PATH ); 
	return temp;
}


