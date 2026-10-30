////////////////////////////////////////////////////////////////////////////////
//
// Step2_API7_2D.cpp - Размеры 2D
//
//	1:	CreateLineDimension( doc );				- Создать линейный размер
//	2:	LineDimensionNavigation( doc );		- Навигация по коллекции линейных размеров
//	3:	EditLineDimension( doc );					- Редактирование линейного размера
// 	4:	RadialDimensionWork( doc );				- Создание и редактирование радиального размера
//	5:	DiamrtralDimensionWork( doc );		- Создание и редактирование диаметрального размера
//	6:	AngleDimensionWork( doc );				- Создание и редактирование углового размера
// 	7:	ArcDimensionWork( doc );					- Создание и редактирование размера дуги окружности
// 	8:	BreakLineDimensionWork( doc );		- Создание и редактирование линейного размера с обрывом
// 	9:	BreakRadialDimensionWork( doc );	- Создание и редактирование радиального размера с изломом
// 	10:	BreakAngleDimensionWork( doc );		- Создание и редактирование углового размера с обрывом
// 	11:	HeightDimensionWork( doc );				- Создание и редактирование размера высоты
// 
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include <afxdllx.h>
#include "Step2_API7_2D.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


//-------------------------------------------------------------------------------
// Специальная структура используемая в течении инициализации DLL
// ---
static AFX_EXTENSION_MODULE Step2_API7_2DDLL = { NULL, NULL };
HINSTANCE g_hInstance = NULL;

// Интерфейс приложения
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
		TRACE0("STEP2_API7_2D.AWX Initializing!\n");

		AfxInitExtensionModule(Step2_API7_2DDLL, hInstance);

		new CDynLinkLibrary(Step2_API7_2DDLL);
	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		TRACE0("STEP2_API7_2D.AWX Terminating!\n");
    OnProcessDetach();
		AfxTermExtensionModule(Step2_API7_2DDLL);
	}
	return 1;   // ok
}


//-------------------------------------------------------------------------------
// Получить доступ к новому API
// ---
void GetNewKompasAPI() 
{
  if ( !( ksAPI7::IApplication * )newKompasAPI ) 
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
        // Указатель на функцию возвращающую интерфейс KompasApplication  
        typedef LPDISPATCH ( WINAPI * FCreateKompasApplication )(); 
        
        FCreateKompasApplication pCreateKompasApplication = 
          (FCreateKompasApplication)GetProcAddress( hAppAuto, "CreateKompasApplication" );	
        
        if ( pCreateKompasApplication )
          newKompasAPI = IDispatchPtr ( pCreateKompasApplication(), false /*AddRef*/); // Получаем интерфейс Application
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
// Получить текущий документ
// ---
ksAPI7::IKompasDocument2DPtr GetCurrentDocument()
{
	ksAPI7::IKompasDocument2DPtr doc = NULL;

	// Если не получен интерфейс приложения IApplication в СОМ
  if ( !(bool)newKompasAPI )
		// Получить интерфейс приложения 
    GetNewKompasAPI();

	// Если получен интерфейс приложения IApplication в СОМ
  if ( newKompasAPI ) 
		// Получить активный документ
    doc = newKompasAPI->GetActiveDocument();
	
	return doc;
}


//-------------------------------------------------------------------------------
// Описания используемых функций
// ---
void CreateLineDimension( ksAPI7::IKompasDocument2DPtr & doc );
void LineDimensionNavigation( ksAPI7::IKompasDocument2DPtr & doc );
void EditLineDimension( ksAPI7::IKompasDocument2DPtr & doc );
void RadialDimensionWork( ksAPI7::IKompasDocument2DPtr & doc );
void DiamrtralDimensionWork( ksAPI7::IKompasDocument2DPtr & doc );
void AngleDimensionWork( ksAPI7::IKompasDocument2DPtr & doc );
void ArcDimensionWork( ksAPI7::IKompasDocument2DPtr & doc );
void BreakLineDimensionWork( ksAPI7::IKompasDocument2DPtr & doc );
void BreakRadialDimensionWork( ksAPI7::IKompasDocument2DPtr & doc );
void BreakAngleDimensionWork( ksAPI7::IKompasDocument2DPtr & doc );
void HeightDimensionWork( ksAPI7::IKompasDocument2DPtr & doc );


//-------------------------------------------------------------------------------
// Головная функция библиотеки
// ---
void WINAPI LIBRARYENTRY( unsigned int comm )
{
	// Получить текущий документ
	ksAPI7::IKompasDocument2DPtr doc( GetCurrentDocument() );
	
	if ( doc )
	{
		switch ( comm )
		{
			case 1:		CreateLineDimension( doc );				break;	// Создать линейный размер
			case 2:		LineDimensionNavigation( doc );		break;	// Навигация по коллекции линейных размеров
			case 3:		EditLineDimension( doc );					break;	// Редактирование линейного размера
			case 4:		RadialDimensionWork( doc );				break;	// Создание и редактирование радиального размера
			case 5:		DiamrtralDimensionWork( doc );		break;	// Создание и редактирование диаметрального размера
			case 6:		AngleDimensionWork( doc );				break;	// Создание и редактирование углового размера
			case 7:		ArcDimensionWork( doc );					break;	// Создание и редактирование размера дуги окружности
			case 8:		BreakLineDimensionWork( doc );		break;	// Создание и редактирование линейного размера с обрывом
			case 9:		BreakRadialDimensionWork( doc );	break;	// Создание и редактирование радиального размера с изломом
			case 10:	BreakAngleDimensionWork( doc );		break;	// Создание и редактирование углового размера с обрывом
			case 11:	HeightDimensionWork( doc );				break;	// Создание и редактирование размера высоты
		}
	}
	else
	{
		MessageT( (LPTSTR)(LPCTSTR)LoadStr(IDS_NODOC) );
	}
}


//-------------------------------------------------------------------------------
//  Получить контейнер обозначений 2D
// ---
ksAPI7::ISymbols2DContainerPtr GetSymbols2DContainer( ksAPI7::IKompasDocument2DPtr & doc )
{
  if ( doc )
  {
    // Получим менеджер для работы с видами и слоями
    ksAPI7::IViewsAndLayersManagerPtr viewsMng( doc->GetViewsAndLayersManager() );
		
    if ( viewsMng )
    {
      // Получим коллекцию видов
      ksAPI7::IViewsPtr views( viewsMng->GetViews() );
			
      if ( views )
      {
        // Получаем контейнер 
        return views->GetActiveView();
      }
    }
  }
  return NULL;
}


//-------------------------------------------------------------------------------
// Создать линейный размер
// ---
void CreateLineDimension( ksAPI7::IKompasDocument2DPtr & doc )
{
	// Получить контейнер условных обозначений
  ksAPI7::ISymbols2DContainerPtr symbCont( GetSymbols2DContainer(doc) );

	if ( symbCont )
	{
		// Получить коллекцию линейных размеров
    ksAPI7::ILineDimensionsPtr dimCol( symbCont->GetLineDimensions() );

		if ( dimCol )
		{
			//Добавить объект в коллекцию
      ksAPI7::ILineDimensionPtr newDim( dimCol->Add() );

			if ( newDim )
			{
				// Координаты первой точки привязки размера
				newDim->X1 = 50;
				newDim->Y1 = 150;
				// Координаты второй точки привязки размера
				newDim->X2 = 100;
				newDim->Y2 = 150;
				// Положение размерной линии
				newDim->X3 = 75;
				newDim->Y3 = 180;
				// Тип ориентации линейного размера
				newDim->Orientation = ksLinDHorizontal;
				// Применить параметры
				newDim->Update();
			}
		}
	}
}


//-------------------------------------------------------------------------------
// Выдать сообщение с параметрами линейного размера
// ---
void GetLineDimensionParam( ksAPI7::ILineDimensionPtr & dim )
{
	if ( dim )
	{
		// Координаты первой точки привязки размера
		double x1 = dim->X1;
		double y1 = dim->Y1;
		// Координаты второй точки привязки размера
		double x2 = dim->X2;
		double y2 = dim->Y2;
		// Выдать сообщение с параметрами объекта
		TCHAR buf[255];
		_stprintf_s( buf, (LPTSTR)(LPCTSTR)LoadStr(IDS_COORDS), x1, y1, x2, y2 );
		MessageT( buf );
	}
}


//-------------------------------------------------------------------------------
// Навигация по коллекции линейных размеров
// ---
void LineDimensionNavigation( ksAPI7::IKompasDocument2DPtr & doc )
{
	// Получить контейнер условных обозначений
  ksAPI7::ISymbols2DContainerPtr symbCont( GetSymbols2DContainer(doc) );

	if ( symbCont )
	{
		// Получить коллекцию линейных размеров
    ksAPI7::ILineDimensionsPtr dimCol( symbCont->GetLineDimensions() );

		if ( dimCol )
		{
			for ( long i = 0; i < dimCol->Count; i++ )
			{
				_variant_t index = (long)i;
				// Получить объект из коллекции по индексу
				ksAPI7::ILineDimensionPtr lineDim( dimCol->GetLineDimension(index) );

				if ( lineDim )
				{
					reference dimRef = lineDim->Reference;
					// Подсветить объект
					LightObj( dimRef, 1/*включить подсветку*/ );
					// Выдать сообщение с параметрами линейного размера
					GetLineDimensionParam( lineDim );
					// Погасить объект
					LightObj( dimRef, 0/*выключить подсветку*/ );
				}
			}
		}
	}
}


//-------------------------------------------------------------------------------
// Изменить параметры у линейного размера
// ---
void ChangeLineDimensionParam( ksAPI7::ILineDimensionPtr & dim )
{
	if ( dim )
	{
		// Получить интерфейс параметров размера
		ksAPI7::IDimensionParamsPtr dimPar( dim );
		
		if ( dimPar )
		{
			// Направление полки - влево
			dimPar->ShelfDirection = ksLSLeft;
			// Типы стрелок - Угол 90 град.
			dimPar->ArrowType1 = ksRightAngle;
			dimPar->ArrowType2 = ksRightAngle;
		}
		
		// Координаты точки начала полки
		dim->ShelfX = 60;
		dim->ShelfY = 200;
	}
}


//-------------------------------------------------------------------------------
// Изменить текст у линейного размера
// ---
void ChangeLineDimensionText( ksAPI7::ILineDimensionPtr & dim )
{
	if ( dim )
	{
		// Получить интерфейс текста размера
		ksAPI7::IDimensionTextPtr dimText( dim );
		
		if ( dimText )
		{
			// Текст в рамке
			dimText->Rectangle = TRUE;
			// Подчеркнуть текст
			dimText->Underline = TRUE;
			
			// Получить интерфейс текста до значения размера
			ksAPI7::ITextLinePtr prefix( dimText->Prefix );
			
			// Изменить текст
			if ( prefix )
				prefix->Str = (LPTSTR)(LPCTSTR)LoadStr( IDS_DIM );
		}
	}
}


//-------------------------------------------------------------------------------
// Изменить линейный размер
// ---
void LineDimChange( ksAPI7::ILineDimensionPtr & dim )
{
	if ( dim )
	{
		// Изменить параметры размера
		ChangeLineDimensionParam( dim );
		// Изменить текст размера
		ChangeLineDimensionText( dim );
		// Применить изменения
		dim->Update();
	}
}


//-------------------------------------------------------------------------------
// Редактирование линейного размера
// ---
void EditLineDimension( ksAPI7::IKompasDocument2DPtr & doc )
{
	// Структура параметров запроса к системе
	RequestInfoT info;
  memset( &info, 0, sizeof(info) );
  info.commands = (LPTSTR)IDS_COMMAND1;
  double x, y;
	
	// Указать объект в документе
	if ( CursorExT(&info, &x, &y, NULL, NULL) )
  {
		// Найти объект по указанным координатам
    reference pObj = FindObj( x, y, ksGetCursorLimit() );
		
		// Если это линейный размер, редактировать
    if ( GetObjParam(pObj, 0, 0, 0) == LDIMENSION_OBJ )
    {
			// Получить интерфейс линейного размера из референса объекта
			ksAPI7::ILineDimensionPtr lineDim( IUnknownPtr(ksTransferReference(pObj, ksGetCurrentDocument(0/*любой документ*/)), false/*AddRef*/) );
			// Изменить линейный размер
			LineDimChange( lineDim );
    }
    else
      MessageT( (LPTSTR)(LPCTSTR)LoadStr(IDS_NOTDIM) );
  } 
}


//-------------------------------------------------------------------------------
// Создать радиальный размер
// ---
void CreateRadDimension( ksAPI7::IRadialDimensionPtr & dim )
{
	if ( dim )
	{
		// Структура параметров запроса к системе
		RequestInfoT info;
		memset( &info, 0, sizeof(info) );
		info.commands = (LPTSTR)IDS_COMMAND2;
		double x, y;
		
		// Указать объект в документе
		if ( CursorExT(&info, &x, &y, NULL, NULL) )
		{
			// Найти объект по указанным координатам
			reference pObj = FindObj( x, y, ksGetCursorLimit() );
			// Структура параметров окружности
			CircleParam par;
			
			// Является ли объект окружностью
			if ( GetObjParam(pObj, &par, sizeof(par), ALLPARAM_T ) == CIRCLE_OBJ )
			{
				// Получить интерфейс графического объекта из референса
				ksAPI7::IDrawingObjectPtr circle( IUnknownPtr(ksTransferReference(pObj, ksGetCurrentDocument(0)), false/*AddRef*/) );
				
				if ( circle )
				{
					// Задать базовый объект размера
					dim->BaseObject = circle;
					// Задать координаты центра размера, совпадающие с центром указанной окружности
					dim->Xc = par.xc;
					dim->Yc = par.yc;
					// Задать радиус размера, совпадающий с радиусом указанной окружности
					dim->Radius = par.rad;
					// Тип размера - от центра
					dim->DimensionType = TRUE;
					// Угол наклона размерной линии
					dim->Angle = 30;
					// Применить параметры
					dim->Update();
				}
				else
					MessageT( (LPTSTR)(LPCTSTR)LoadStr(IDS_NOOBJ) );
			}
			else
				MessageT( (LPTSTR)(LPCTSTR)LoadStr(IDS_NOTCREATE1) );
		} 
	}
}


//-------------------------------------------------------------------------------
// Изменить параметры и текст у радиального размера
// ---
void ChangeRadialDimensionParamText( ksAPI7::IRadialDimensionPtr & dim )
{
	if ( dim )
	{
		// Получить интерфейс параметров размера
		ksAPI7::IDimensionParamsPtr dimPar( dim );

		if ( dimPar )
		{
			// Направление полки - вправо
			dimPar->ShelfDirection = ksLSRight;
			// Угол наклона полки
			dimPar->ShelfAngle = 180;
			// Длина полки
			dimPar->ShelfLength = 30;
			// Тип стрелки - засечка
			dimPar->ArrowType1 = ksNotch;
		}

		// Получить интерфейс текстов размера
		ksAPI7::IDimensionTextPtr dimText( dim );

		if ( dimText )
		{
			// Значок перед номиналом - радиус
			dimText->Sign = 3;

			// Получить интерфейс текста единицы измерения
			ksAPI7::ITextLinePtr unit( dimText->Unit );

			// Задать текстовую строку
			if ( unit )
				unit->Str = (LPTSTR)(LPCTSTR)LoadStr( IDS_UNIT );
		}
	}
}


//-------------------------------------------------------------------------------
// Редактировать радиальный размер
// ---
void EditRadialDimension( ksAPI7::IRadialDimensionPtr & dim )
{
	if ( dim )
	{
		// Тип размера - не от центра
		dim->DimensionType = FALSE;
		// Изменить параметры и текст размера
		ChangeRadialDimensionParamText( dim );
		// Применить изменения
		dim->Update();
	}
}


//-------------------------------------------------------------------------------
// Создание и редактирование радиального размера
// ---
void RadialDimensionWork( ksAPI7::IKompasDocument2DPtr & doc )
{
	// Получить контейнер условных обозначений
	ksAPI7::ISymbols2DContainerPtr symbCont( GetSymbols2DContainer(doc) );

	if ( symbCont )
	{
		// Получить коллекцию радиальных размеров
		ksAPI7::IRadialDimensionsPtr radCol( symbCont->GetRadialDimensions() );

		if ( radCol )
		{
			// Добавить радиальный размер в коллекцию
			ksAPI7::IRadialDimensionPtr radDim( radCol->Add() );

			if ( radDim )
			{
				// Создать радиальный размер
				CreateRadDimension( radDim );
				// Получить референс размера
				reference dimRef = radDim->Reference;

				if ( YesNoT((LPTSTR)(LPCTSTR)LoadStr(IDS_EDIT)) )
				{
					_variant_t index = (long)dimRef;
					// Получить объект из коллекции по референсу
					ksAPI7::IRadialDimensionPtr radDimension( radCol->GetRadialDimension( index ) );
					// Редактировать радиальный размер
					EditRadialDimension( radDimension );
				}
			}
		}
	}
}


//-------------------------------------------------------------------------------
// Создать диаметральный размер
// ---
void CreateDiamrtralDimension( ksAPI7::IDiametralDimensionPtr & dim )
{
	if ( dim )
	{
		// Структура параметров запроса к системе
		RequestInfoT info;
		memset( &info, 0, sizeof(info) );
		info.commands = (LPTSTR)IDS_COMMAND2;
		double x, y;
		
		// Указать объект в документе
		if ( CursorExT(&info, &x, &y, NULL, NULL) )
		{
			// Найти объект по указанным координатам
			reference pObj = FindObj( x, y, ksGetCursorLimit() );
			// Структура параметров окружности
			CircleParam par;
			
			// Является ли объект окружностью
			if ( GetObjParam(pObj, &par, sizeof(par), ALLPARAM_T ) == CIRCLE_OBJ )
			{
				// Получить интерфейс графического объекта из референса
				ksAPI7::IDrawingObjectPtr circle( IUnknownPtr(ksTransferReference(pObj, ksGetCurrentDocument(0)), false/*AddRef*/) );
				
				if ( circle )
				{
					// Задать базовый объект размера
					dim->BaseObject = circle;
					// Задать координаты центра размера, совпадающие с центром указанной окружности
					dim->Xc = par.xc;
					dim->Yc = par.yc;
					// Задать радиус размера, совпадающий с радиусом указанной окружности
					dim->Radius = par.rad;
					// Тип размера - полная размерная линия
					dim->DimensionType = TRUE;
					// Угол наклона размерной линии
					dim->Angle = 45;
					// Применить параметры
					dim->Update();
				}
				else
					MessageT( (LPTSTR)(LPCTSTR)LoadStr(IDS_NOOBJ) );
			}
			else
				MessageT( (LPTSTR)(LPCTSTR)LoadStr(IDS_NOTCREATE2) );
		}
	}
}


//-------------------------------------------------------------------------------
// Изменить параметры и текст у диаметрального размера
// ---
void ChangeDiametralDimensionParamText( ksAPI7::IDiametralDimensionPtr & dim )
{
	if ( dim )
	{
		// Получить интерфейс параметров размера
		ksAPI7::IDimensionParamsPtr dimPar( dim );
		
		if ( dimPar )
		{
			// Направление полки - вправо
			dimPar->ShelfDirection = ksLSRight;
			// Длина полки
			dimPar->ShelfLength = 20;
			// Тип стрелок - точка
			dimPar->ArrowType1 = ksPoint;
			dimPar->ArrowType2 = ksPoint;
		}
		
		// Получить интерфейс текстов размера
		ksAPI7::IDimensionTextPtr dimText( dim );
		
		if ( dimText )
		{
			// Значок перед номиналом - диаметр
			dimText->Sign = 1;
			// Подчеркнуть
			dimText->Underline = TRUE;
			
			// Получить интерфейс текста единицы измерения
			ksAPI7::ITextLinePtr suffix( dimText->Suffix );
			
			// Задать текстовую строку
			if ( suffix )
				suffix->Str = (LPTSTR)(LPCTSTR)LoadStr( IDS_UNIT );
		}
	}
}


//-------------------------------------------------------------------------------
// Редактировать диаметральный размер
// ---
void EditDiametralDimension( ksAPI7::IDiametralDimensionPtr & dim )
{
	if ( dim )
	{
		// Тип размера - размерная линия с обрывом
		dim->DimensionType = FALSE;
		// Угол наклона размерной линии
		dim->Angle = 90;
		// Изменить параметры и текст размера
		ChangeDiametralDimensionParamText( dim );
		// Применить изменения
		dim->Update();
	}
}


//-------------------------------------------------------------------------------
// Создание и редактирование диаметрального размера
// ---
void DiamrtralDimensionWork( ksAPI7::IKompasDocument2DPtr & doc )
{
	// Получить контейнер условных обозначений
	ksAPI7::ISymbols2DContainerPtr symbCont( GetSymbols2DContainer(doc) );

	if ( symbCont )
	{
		// Получить коллекцию диаметральных размеров
		ksAPI7::IDiametralDimensionsPtr diamCol( symbCont->GetDiametralDimensions() );
		
		if ( diamCol )
		{
			// Добавить диаметральный размер в коллекцию
			ksAPI7::IDiametralDimensionPtr diamDim( diamCol->Add() );
			
			if ( diamDim )
			{
				// Создать диаметральный размер
				CreateDiamrtralDimension( diamDim );
				// Получить референс размера
				reference dimRef = diamDim->Reference;
				
				if ( YesNoT((LPTSTR)(LPCTSTR)LoadStr(IDS_EDIT)) )
				{
					_variant_t index = (long)dimRef;
					// Получить объект из коллекции по референсу
					ksAPI7::IDiametralDimensionPtr diamDimension( diamCol->GetDiametralDimension( index ) );
					// Редактировать диаметральный размер
					EditDiametralDimension( diamDimension );
				}
			}
		}
	}
}


//-------------------------------------------------------------------------------
// Создать угловой размер
// ---
void CreateAngleDimension( ksAPI7::IAngleDimensionPtr & dim )
{
	if ( dim )
	{
		// Построение размера на объектах, указанных в чертеже
	/*	// Структура параметров запроса к системе
		RequestInfoT info;
		memset( &info, 0, sizeof(info) );
		info.commands = (LPTSTR)IDS_COMMAND3;
		double x, y;
		
		// Указать первый базовый объект в документе
		if ( CursorExT(&info, &x, &y, NULL, NULL) )
		{
			// Найти объект по указанным координатам
			reference pObj1 = FindObj( x, y, 1 );
			// Получить тип первого объекта
			long type1 = GetObjParam( pObj1, 0, 0, 0 );

			if ( type1 == LINESEG_OBJ || type1 == POLYLINE_OBJ || type1 == RECTANGLE_OBJ )
			{
				// Подсветить указанный объект
				LightObj( pObj1, 1 );
				info.commands = (LPTSTR)IDS_COMMAND4;
				
				// Указать второй базовый объект в документе
				if ( CursorExT(&info, &x, &y, NULL, NULL) )
				{
					// Найти объект по указанным координатам
					reference pObj2 = FindObj( x, y, 1 );
					// Получить тип второго объекта
					long type2 = GetObjParam( pObj2, 0, 0, 0 );

					if ( type1 == LINESEG_OBJ || type1 == POLYLINE_OBJ || type1 == RECTANGLE_OBJ )
					{
						// Подсветить указанный объект
						LightObj( pObj2, 1 );
						// Получить интерфейс графического объекта из референса
						ksAPI7::IDrawingObjectPtr baseObj1( IUnknownPtr(ksTransferReference(pObj1, ksGetCurrentDocument(0))), false );
						ksAPI7::IDrawingObjectPtr baseObj2( IUnknownPtr(ksTransferReference(pObj2, ksGetCurrentDocument(0))), false );

						if ( (bool)baseObj1 && (bool)baseObj2 )
						{
							// Задать базовые объекты размера
							dim->BaseObject1 = baseObj1;
							dim->BaseObject2 = baseObj2;
							// Радиус дуги
							dim->Radius = 20;
							// Применить параметры
							dim->Update();
							// Убрать подсветку объекта
							LightObj( pObj2, 0 );
						}
						else
							MessageT( (LPTSTR)(LPCTSTR)LoadStr(IDS_NOOBJS) );
						
						// Убрать подсветку объекта
						LightObj( pObj1, 0 );
					}
					else
						MessageT( (LPTSTR)(LPCTSTR)LoadStr(IDS_NOTCREATE3) );
				}
			}
			else
				MessageT( _T("Невозможно создать угловой размер для данного объекта.") );
		}*/
		
		// Построение размера на двух отрезках		
		// Построить первый опорный объект
		reference line1 = LineSeg( 80, 120, 100, 120, 1 );
		ksAPI7::IDrawingObjectPtr baseObj1 = IUnknownPtr( ksTransferReference(line1, ksGetCurrentDocument(0)), false/*AddRef*/ );
		// Построить второй опорный объект
		reference line2 = LineSeg( 80, 120, 120, 160, 1 );
		ksAPI7::IDrawingObjectPtr baseObj2 = IUnknownPtr( ksTransferReference(line2, ksGetCurrentDocument(0)),false/*AddRef*/ );
		
		if ( (bool)baseObj1 && (bool)baseObj2 )
		{
			// Задать опорные объекты
			dim->BaseObject1 = baseObj1;
			dim->BaseObject2 = baseObj2;
			// Координаты центра
			dim->Xc = 90;
			dim->Yc = 150;
			// Радиус дуги
			dim->Radius = 25;
			// Начальный угол  размерной дуги
			dim->Angle1 = 45;
			// Конечный угол  размерной дуги
			dim->Angle2 = 30;
			// Координаты точки выхода первой выносной линии
			dim->X1 = 80;
			dim->Y1 = 120;
			// Координаты точки выхода второй выносной линии
			dim->X2 = 100;
			dim->Y2 = 160;
			// Тип размера - на минимальный (острый) угол
			dim->DimensionType = ksADMinAngle;
			
			// Включить полку
			ksAPI7::IDimensionParamsPtr dimPar( dim );
			
			if ( dimPar )
				// Направление полки - вправо
				dimPar->ShelfDirection = ksLSRight;
					
			// Точка начала полки
			dim->ShelfX = 160;
			dim->ShelfY = 140;
			// Направление размерной дуги - против часовой стрелки
			dim->Direction = FALSE;
			// Начало ножки или точка на дуге
			dim->X3 = 140;
			dim->Y3 = 120;
			// Применить параметры
			dim->Update();
		}	
	}
}


//-------------------------------------------------------------------------------
// Редактирование углового размера
// ---
void EditAngleDimension( ksAPI7::IAngleDimensionPtr & dim )
{
	if (dim )
	{
		// Тип размера - На максимальный (тупой) угол
		dim->DimensionType = ksADMaxAngle;
		// Направление размерной дуги  - по часовой стрелке
		dim->Direction = TRUE;
		// Точка начала полки
		dim->ShelfX = 150;
		dim->ShelfY = 170;
		// Радиус дуги
		dim->Radius = 40;
		// Применить изменения
		dim->Update();
	}
}


//-------------------------------------------------------------------------------
// Создание и редактирование углового размера
// ---
void AngleDimensionWork( ksAPI7::IKompasDocument2DPtr & doc )
{
	// Получить контейнер условных обозначений
	ksAPI7::ISymbols2DContainerPtr symbCont( GetSymbols2DContainer(doc) );
	
	if ( symbCont )
	{
		// Получить коллекцию угловых размеров
		ksAPI7::IAngleDimensionsPtr angCol( symbCont->GetAngleDimensions() );
		
		if ( angCol )
		{
			// Добавить угловой размер в коллекцию
			ksAPI7::IAngleDimensionPtr angDim( angCol->Add(ksDrADimension) );
			
			if ( angDim )
			{
				// Создать угловой размер
				CreateAngleDimension( angDim );
				// Получить референс размера
				reference dimRef = angDim->Reference;
				
				if ( YesNoT((LPTSTR)(LPCTSTR)LoadStr(IDS_EDIT)) )
				{
					_variant_t index = (long)dimRef;
					// Получить объект из коллекции по референсу
					ksAPI7::IAngleDimensionPtr angDimension( angCol->GetAngleDimension( index ) );
					// Редактировать угловой размер
					EditAngleDimension( angDimension );
				}
			}
		}
	}
}


//-------------------------------------------------------------------------------
// Создание размера дуги окружности
// ---
void CreateArcDimension( ksAPI7::IArcDimensionPtr & dim )
{
	if ( dim )
	{
		// Структура параметров запроса к системе
		RequestInfoT info;
		memset( &info, 0, sizeof(info) );
		info.commands = (LPTSTR)IDS_COMMAND5;
		double x, y;
		
		// Указать объект в документе
		if ( CursorExT(&info, &x, &y, NULL, NULL) )
		{
			// Найти объект по указанным координатам
			reference pObj = FindObj( x, y, 1 );
			// Подсветить указанный объект
			LightObj( pObj, 1 );
			// Структура параметров дуги
			ArcParam1 par;
			
			// Является ли объект дугой
			if ( GetObjParam(pObj, &par, sizeof(par), POINT_ARC_PARAM ) == ARC_OBJ )
			{
				// Получить интерфейс графического объекта из референса
				ksAPI7::IDrawingObjectPtr arc( IUnknownPtr(ksTransferReference(pObj, ksGetCurrentDocument(0)), false/*AddRef*/) );
				
				if ( arc )
				{
					// Базовый объект
					dim->BaseObject = arc;
					// Координаты центра
					dim->Xc = par.xc;
					dim->Yc = par.yc;
					// Координаты первой точки дуги
					dim->X1 = par.x1;
					dim->Y1 = par.y1;
					// Координаты второй точки дуги
					dim->X2 = par.x2;
					dim->Y2 = par.y2;
					
					info.commands = (LPTSTR)IDS_COMMAND6;					
					// Указать положение размерной линии
					if ( CursorExT(&info, &x, &y, NULL, NULL) )
					{
						dim->X3 = x;
						dim->Y3 = y;
					}

					// Направление размерной дуги
					dim->Direction = TRUE;
					// Тип размера - параллельные выносные линии
					dim->DimensionType = FALSE;
					// Указатель от текста к дуге
					dim->TextPointer = TRUE;
					// Применить параметры
					dim->Update();
				}
				else
					MessageT( (LPTSTR)(LPCTSTR)LoadStr(IDS_NOOBJ) );
			}
			else
				MessageT( (LPTSTR)(LPCTSTR)LoadStr(IDS_NOTCREATE4) );

			// Убрать подсветку объекта
			LightObj( pObj, 0 );
		}
	}	
}


//-------------------------------------------------------------------------------
// Редактирование размера дуги окружности
// ---
void EditArcDimension( ksAPI7::IArcDimensionPtr & dim )
{
	if ( dim )
	{
		// Тип размера - выносные линии от центра
		dim->DimensionType = TRUE;
		// Указатель от текста к дуге
		dim->TextPointer = FALSE;
		// Направление размерной дуги - поменять на противоположное
		dim->Direction = !dim->Direction;

		// Получить интерфейс параметров размера
		ksAPI7::IDimensionParamsPtr dimPar( dim );

		if ( dimPar )
		{
			// Тип стрелок
			dimPar->ArrowType1 = ksLeaderPoint;
			dimPar->ArrowType2 = ksLeaderPoint;
			// Направление полки - вниз
			dimPar->ShelfDirection = ksLSDown;
			// Угол наклона полки
			dimPar->ShelfAngle = 180;
		}

		dim->Update();

		// Получить интерфейс текста размера
		ksAPI7::IDimensionTextPtr dimText( dim );

		if ( dimText )
		{
			// Отключить автоматическое определение номанального значения
			dimText->AutoNominalValue = FALSE;
			// Установить новое номинальное значение
			dimText->NominalValue = 50;
			
			// Получить интерфейс текста единицы измерения
			ksAPI7::ITextLinePtr unit( dimText->Unit );
			
			// Задать текстовую строку
			if ( unit )
				unit->Str = (LPTSTR)(LPCTSTR)LoadStr( IDS_UNIT2 );
		}
		// Применить изменения
		dim->Update();
	}
}


//-------------------------------------------------------------------------------
// Создание и редактирование размера дуги окружности
// ---
void ArcDimensionWork( ksAPI7::IKompasDocument2DPtr & doc )
{
	// Получить контейнер условных обозначений
	ksAPI7::ISymbols2DContainerPtr symbCont( GetSymbols2DContainer(doc) );
	
	if ( symbCont )
	{
		// Получить коллекцию размеров дуги окружности
		ksAPI7::IArcDimensionsPtr arcCol( symbCont->GetArcDimensions() );
		
		if ( arcCol )
		{
			// Добавить размер дуги окружности в коллекцию
			ksAPI7::IArcDimensionPtr arcDim( arcCol->Add() );
			
			if ( arcDim )
			{
				// Создать размер дуги окружности
				CreateArcDimension( arcDim );
				// Получить референс размера
				reference dimRef = arcDim->Reference;
				
				if ( YesNoT((LPTSTR)(LPCTSTR)LoadStr(IDS_EDIT)) )
				{
					_variant_t index = (long)dimRef;
					// Получить объект из коллекции по референсу
					ksAPI7::IArcDimensionPtr arcDimension( arcCol->GetArcDimension( index ) );
					// Редактировать размер дуги окружности
					EditArcDimension( arcDimension );
				}
			}
		}
	}	
}


//-------------------------------------------------------------------------------
// Создание линейного размера с обрывом
// ---
void CreateBreakLineDim( ksAPI7::IBreakLineDimensionPtr & dim )
{
	if ( dim )
	{
		// Структура параметров запроса к системе
		RequestInfoT info;
		memset( &info, 0, sizeof(info) );
		info.commands = (LPTSTR)IDS_COMMAND7;
		double x, y;
		
		// Указать объект в документе
		if ( CursorExT(&info, &x, &y, NULL, NULL) )
		{
			// Найти объект по указанным координатам
			reference pObj = FindObj( x, y, ksGetCursorLimit() );
			// Структура параметров отрезка
			LineSegParam par;
			
			// Является ли объект отрезком
			if ( GetObjParam(pObj, &par, sizeof(par), ALLPARAM_T ) == LINESEG_OBJ )
			{
				// Подсветить указанный объект
				LightObj( pObj, 1 );
				// Получить интерфейс графического объекта из референса
				ksAPI7::IDrawingObjectPtr lineSeg( IUnknownPtr(ksTransferReference(pObj, ksGetCurrentDocument(0)), false/*AddRef*/) );
				
				if ( lineSeg )
				{
					// Базовый объект
					dim->BaseObject = lineSeg;
					info.commands = (LPTSTR)IDS_COMMAND6;					
					
					// Указать положение размерной линии
					if ( CursorExT(&info, &x, &y, NULL, NULL) )
					{
						// Координаты первой точки привязки - координаты первого конца отрезка
						dim->X1 = par.x1;
						dim->Y1 = par.y1;
						// Координаты второй точки привязки - координаты второго конца отрезка
						dim->X2 = par.x2;
						dim->Y2 = par.y2;
						// Положение размерной линии - указанные координаты
						dim->X3 = x;
						dim->Y3 = y;
					}
					// Применить параметры
					dim->Update();
				}
				else
					MessageT( (LPTSTR)(LPCTSTR)LoadStr(IDS_NOOBJ) );
			}
			else
				MessageT( (LPTSTR)(LPCTSTR)LoadStr(IDS_NOTCREATE5) );
			
			// Убрать подсветку объекта
			LightObj( pObj, 0 );
		}
	}	
}


//-------------------------------------------------------------------------------
// Редактирование линейного размера с обрывом
// ---
void EditBreakLineDim( ksAPI7::IBreakLineDimensionPtr & dim )
{
	if ( dim )
	{
		// Получить интерфейс параметров размера
		ksAPI7::IDimensionParamsPtr dimPar( dim );

		if ( dimPar )
		{
			// Тип стрелки			
			dimPar->ArrowType1 = ksLeftNotch;
		}

		// Получить интерфейс текста размера
		ksAPI7::IDimensionTextPtr dimText( dim );

		if ( dimText )
		{
			// Получить текст перед размером
			ksAPI7::ITextLinePtr prefix = dimText->Prefix;

			if ( prefix )
				// Изменить текст
				prefix->Str = (LPTSTR)(LPCTSTR)LoadStr( IDS_DIM );

			// Получить текст номинального значения
			ksAPI7::ITextLinePtr nominal = dimText->NominalText;
			
			if ( nominal )
				// Изменить текст
				nominal->Str = (LPTSTR)(LPCTSTR)LoadStr( IDS_NOMINAL );
		}
		// Применить изменения
		dim->Update();
	}
}


//-------------------------------------------------------------------------------
// Создание и редактирование линейного размера с обрывом
// ---
void BreakLineDimensionWork( ksAPI7::IKompasDocument2DPtr & doc )
{
	// Получить контейнер условных обозначений
	ksAPI7::ISymbols2DContainerPtr symbCont( GetSymbols2DContainer(doc) );
	
	if ( symbCont )
	{
		// Получить коллекцию линейных размеров с обрывом
		ksAPI7::IBreakLineDimensionsPtr breakCol( symbCont->GetBreakLineDimensions() );
		
		if ( breakCol )
		{
			// Добавить линейный размер с обрывом в коллекцию
			ksAPI7::IBreakLineDimensionPtr breakDim( breakCol->Add() );
			
			if ( breakDim )
			{
				// Создать линейный размер с обрывом
				CreateBreakLineDim( breakDim );
				// Получить референс размера
				reference dimRef = breakDim->Reference;
				
				if ( YesNoT((LPTSTR)(LPCTSTR)LoadStr(IDS_EDIT)) )
				{
					_variant_t index = (long)dimRef;
					// Получить объект из коллекции по референсу
					ksAPI7::IBreakLineDimensionPtr breakDimension( breakCol->GetBreakLineDimension( index ) );
					// Редактировать линейный размер с обрывом
					EditBreakLineDim( breakDimension );
				}
			}
		}
	}	
}


//-------------------------------------------------------------------------------
// Создание радиального размера с изломом
// ---
void CreateBreakRadialDim( ksAPI7::IBreakRadialDimensionPtr & dim )
{
	if ( dim )
	{
		// Структура параметров запроса к системе
		RequestInfoT info;
		memset( &info, 0, sizeof(info) );
		info.commands = (LPTSTR)IDS_COMMAND2;
		double x, y;
		
		// Указать объект в документе
		if ( CursorExT(&info, &x, &y, NULL, NULL) )
		{
			// Найти объект по указанным координатам
			reference pObj = FindObj( x, y, ksGetCursorLimit() );
			// Структура параметров окружности
			CircleParam par;
			
			// Является ли объект окружностью
			if ( GetObjParam(pObj, &par, sizeof(par), ALLPARAM_T ) == CIRCLE_OBJ )
			{
				// Получить интерфейс графического объекта из референса
				ksAPI7::IDrawingObjectPtr circle( IUnknownPtr(ksTransferReference(pObj, ksGetCurrentDocument(0)), false/*AddRef*/) );
				
				if ( circle )
				{
					// Задать базовый объект размера
					dim->BaseObject = circle;
					// Задать координаты центра размера, совпадающие с центром указанной окружности
					dim->Xc = par.xc;
					dim->Yc = par.yc;
					// Задать радиус размера, совпадающий с радиусом указанной окружности
					dim->Radius = par.rad;
					// Угол наклона размерной линии
					dim->Angle = 45;
					// Длина излома
					dim->BreakLength = 3;
					// Положение размерной надписи
					dim->TextOnLine = ksDimTextParallelOnLine;
					// Применить параметры
					dim->Update();
				}
				else
					MessageT( (LPTSTR)(LPCTSTR)LoadStr(IDS_NOOBJ) );
			}
			else
				MessageT( (LPTSTR)(LPCTSTR)LoadStr(IDS_NOTCREATE1) );
		} 
	}
}


//-------------------------------------------------------------------------------
// Редактировать радиальный размер с изломом
// ---
void EditBreakRadialDim( ksAPI7::IBreakRadialDimensionPtr & dim )
{
	if ( dim )
	{
		// Угол наклона размерной линии
		dim->Angle = 90;
		// Длина излома
		dim->BreakLength = 1;
		// Положение размерной надписи
		dim->TextOnLine = ksDimTextParallelInCut;
	
		// Получить интерфейс текста размера
		ksAPI7::IDimensionTextPtr dimText( dim );

		if ( dimText )
		{
			// Убрать значок радиуса
			dimText->Sign = 0;
		}
		// Применить изменения
		dim->Update();
	}
}


//-------------------------------------------------------------------------------
// Создание и редактирование радиального размера с изломом
// ---
void BreakRadialDimensionWork( ksAPI7::IKompasDocument2DPtr & doc )
{
	// Получить контейнер условных обозначений
	ksAPI7::ISymbols2DContainerPtr symbCont( GetSymbols2DContainer(doc) );
	
	if ( symbCont )
	{
		// Получить коллекцию радиальных размеров с изломом
		ksAPI7::IBreakRadialDimensionsPtr breakCol( symbCont->GetBreakRadialDimensions() );
		
		if ( breakCol )
		{
			// Добавить радиальный размер с изломом в коллекцию
			ksAPI7::IBreakRadialDimensionPtr breakDim( breakCol->Add() );
			
			if ( breakDim )
			{
				// Создать радиальный размер с изломом
				CreateBreakRadialDim( breakDim );
				// Получить референс размера
				reference dimRef = breakDim->Reference;
				
				if ( YesNoT((LPTSTR)(LPCTSTR)LoadStr(IDS_EDIT)) )
				{
					_variant_t index = (long)dimRef;
					// Получить объект из коллекции по референсу
					ksAPI7::IBreakRadialDimensionPtr breakDimension( breakCol->GetBreakRadialDimension( index ) );
					// Редактировать радиальный размер с изломом
					EditBreakRadialDim( breakDimension );
				}
			}
		}
	}		
}


//-------------------------------------------------------------------------------
// Создание углового размера с обрывом
// ---
void CreateBreakAngleDim( ksAPI7::IBreakAngleDimensionPtr & dim )
{
	if ( dim )
	{
		// Построить первый опорный объект
		reference line1 = LineSeg( 80, 120, 120, 160, 1 );
		ksAPI7::IDrawingObjectPtr baseObj1 = IUnknownPtr( ksTransferReference(line1, ksGetCurrentDocument(0)), false/*AddRef*/ );
		// Построить второй опорный объект
		reference line2 = LineSeg( 80, 120, 100, 120, 1 );
		ksAPI7::IDrawingObjectPtr baseObj2 = IUnknownPtr( ksTransferReference(line2, ksGetCurrentDocument(0)),false/*AddRef*/ );
		
		if ( (bool)baseObj1 && (bool)baseObj2 )
		{
			// Задать опорные объекты
			dim->BaseObject1 = baseObj1;
			dim->BaseObject2 = baseObj2;
			// Координаты центра
			dim->Xc = 80;
			dim->Yc = 120;
			// Радиус дуги
			dim->Radius = 20;
			// Начальный угол  размерной дуги
			dim->Angle1 = 45;
			// Конечный угол  размерной дуги
			dim->Angle2 = 30;
			// Координаты точки выхода первой выносной линии
			dim->X1 = 120;
			dim->Y1 = 160;
			// Координаты точки выхода второй выносной линии
			dim->X2 = 100;
			dim->Y2 = 160;
			// Тип размера - на минимальный (острый) угол
			dim->DimensionType = ksADMinAngle;
			// Направление размерной дуги - против часовой стрелки
			dim->Direction = TRUE;
			// Начало ножки или точка на дуге
			dim->X3 = 165;
			dim->Y3 = 140;
			// Применить параметры
			dim->Update();
		}	
	}
}


//-------------------------------------------------------------------------------
// Редактирование углового размера с обрывом
// ---
void EditBreakAngleDim( ksAPI7::IBreakAngleDimensionPtr & dim )
{
	if ( dim )
	{
		// Включить полку
		ksAPI7::IDimensionParamsPtr dimPar( dim );
		
		if ( dimPar )
			// Направление полки - вправо
			dimPar->ShelfDirection = ksLSRight;
		
		// Точка начала полки
		dim->ShelfX = 167;
		dim->ShelfY = 177;

		// Получить интерфейс текстов размера
		ksAPI7::IDimensionTextPtr dimText( dim );

		if ( dimText )
		{
			// Выравнивание размерной надписи
			dimText->TextAlign = ksDimALowerBoundary;
			// Текст в круглых скобках
			dimText->Brackets = ksDimBrackets;
		}
		// Применить изменения
		dim->Update();
	}
}


//-------------------------------------------------------------------------------
// Создание и редактирование углового размера с обрывом
// ---
void BreakAngleDimensionWork( ksAPI7::IKompasDocument2DPtr & doc )
{
	// Получить контейнер условных обозначений
	ksAPI7::ISymbols2DContainerPtr symbCont( GetSymbols2DContainer(doc) );
	
	if ( symbCont )
	{
		// Получить коллекцию угловых размеров с обрывом
		ksAPI7::IAngleDimensionsPtr breakCol( symbCont->GetAngleDimensions() );
		
		if ( breakCol )
		{
			// Добавить угловой размер с обрывом в коллекцию
			ksAPI7::IBreakAngleDimensionPtr breakDim( breakCol->Add(ksDrABreakDimension) );
			
			if ( breakDim )
			{
				// Создать угловой размер с обрывом
				CreateBreakAngleDim( breakDim );
				// Получить референс размера
				reference dimRef = breakDim->Reference;
				
				if ( YesNoT((LPTSTR)(LPCTSTR)LoadStr(IDS_EDIT)) )
				{
					_variant_t index = (long)dimRef;
					// Получить объект из коллекции по референсу
					ksAPI7::IBreakAngleDimensionPtr breakDimension( breakCol->GetAngleDimension( index ) );
					// Редактировать угловой размер с обрывом
					EditBreakAngleDim( breakDimension );
				}
			}
		}
	}	
}


//-------------------------------------------------------------------------------
// Создать размер высоты
// ---
void CreateHeightDimension( ksAPI7::IHeightDimensionPtr & dim )
{
	if ( dim )
	{
		// Структура параметров запроса к системе
		RequestInfoT info;
		memset( &info, 0, sizeof(info) );
		info.commands = (LPTSTR)IDS_COMMAND8;
		double x, y;
		
		// Указать точку нулевого уровня
		if ( CursorExT(&info, &x, &y, NULL, NULL) )
		{
			info.commands = (LPTSTR)IDS_COMMAND9;
			double x1, y1;

			// Указать точку измеряемого уровня
			if ( CursorExT(&info, &x1, &y1, NULL, NULL) )
			{
				info.commands = (LPTSTR)IDS_COMMAND10;
				double x2, y2;
				
				// Указать положение размерной надписи
				if ( CursorExT(&info, &x2, &y2, NULL, NULL) )
				{
					// Точка нулевого уровня
					dim->X = x;
					dim->Y = y;
					// Точка измеряемого уровня
					dim->X1 = x1;
					dim->Y1 = y1;
					// Положение размерной надписи
					dim->X2 = x2;
					dim->Y2 = y2;
					// Применить параметры
					dim->Update();
				}
			}
		}
	}
}


//-------------------------------------------------------------------------------
// Редактировать размер высоты
// ---
void EditHeightDimension( ksAPI7::IHeightDimensionPtr & dim )
{
	if ( dim )
	{
		// Тип размера
		dim->DimensionType = ksHDTopViewLeader;

		// Получить интерфейс текста размера
		ksAPI7::IDimensionTextPtr dimText( dim );

		if ( dimText )
		{
			// Условный значок - квадрат
			dimText->Sign = 2;
			// Получить текст номинального значения
			ksAPI7::ITextLinePtr nominal = dimText->NominalText;
			
			if ( nominal )
				// Изменить текст
				nominal->Str = (LPTSTR)(LPCTSTR)LoadStr( IDS_NOMINAL );
		}
		// Применить изменения
		dim->Update();
	}
}


//-------------------------------------------------------------------------------
// Создание и редактирование размера высоты
// ---
void HeightDimensionWork( ksAPI7::IKompasDocument2DPtr & doc )
{
	// Получить контейнер условных обозначений
	ksAPI7::ISymbols2DContainerPtr symbCont( GetSymbols2DContainer(doc) );
	
	if ( symbCont )
	{
		// Получить коллекцию размеров высоты
		ksAPI7::IHeightDimensionsPtr heightCol( symbCont->GetHeightDimensions() );
		
		if ( heightCol )
		{
			// Добавить размер высоты в коллекцию
			ksAPI7::IHeightDimensionPtr heightDim( heightCol->Add() );
			
			if ( heightDim )
			{
				// Создать размер высоты
				CreateHeightDimension( heightDim );
				// Получить референс размера
				reference dimRef = heightDim->Reference;
				
				if ( YesNoT((LPTSTR)(LPCTSTR)LoadStr(IDS_EDIT)) )
				{
					_variant_t index = (long)dimRef;
					// Получить объект из коллекции по референсу
					ksAPI7::IHeightDimensionPtr heightDimension( heightCol->GetHeightDimension( index ) );
					// Редактировать размер высоты
					EditHeightDimension( heightDimension );
				}
			}
		}
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
	TCHAR temp[_MAX_PATH];
	LoadString( Step2_API7_2DDLL.hModule, strID, temp, _MAX_PATH ); 
	return temp;
}


