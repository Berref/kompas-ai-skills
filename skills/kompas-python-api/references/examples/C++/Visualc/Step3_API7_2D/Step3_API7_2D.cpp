////////////////////////////////////////////////////////////////////////////////
//
// Step3_API7_2D.cpp - Обозначения 2D
//
// 	1:	LeaderWork( doc );				- Создание и редактирование простой линии выноски
// 	2:	MarkLeaderWork( doc );		- Создание и редактирование знака маркировки
// 	3:	ChangeLeaderWork( doc );	- Создание и редактирование знака изменения
// 	4:	BrandLeaderWork( doc );		- Создание и редактирование знака клеймения
// 	5:	RoughWork( doc );					- Создание и редактирование обозначения шероховатости
// 	6:	BaseWork( doc );					- Создание и редактирование обозначения базы
// 	7:	CutLineWork( doc );				- Создание и редактирование линии разреза/сечения
// 	8:	ViewPointerWork( doc );		- Создание и редактирование стрелки направления взгляда
// 	9:	ToleranceWork( doc );			- Создание и редактирование допуска формы
// 	10:	ObjectsNavigation( doc );	- Навигация по массиву объектов
//
////////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <afxdllx.h>
#include "Step3_API7_2D.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


//-------------------------------------------------------------------------------
// Специальная структура используемая в течении инициализации DLL
// ---
static AFX_EXTENSION_MODULE Step3_API7_2DDLL = { NULL, NULL };
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
		TRACE0("STEP3_API7_2D.AWX Initializing!\n");

		AfxInitExtensionModule(Step3_API7_2DDLL, hInstance);

		new CDynLinkLibrary(Step3_API7_2DDLL);
	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		TRACE0("STEP3_API7_2D.AWX Terminating!\n");
    OnProcessDetach();
		AfxTermExtensionModule(Step3_API7_2DDLL);
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
// Используемые функции
// ---
void LeaderWork( ksAPI7::IKompasDocument2DPtr & doc );
void MarkLeaderWork( ksAPI7::IKompasDocument2DPtr & doc );
void ChangeLeaderWork( ksAPI7::IKompasDocument2DPtr & doc );
void BrandLeaderWork( ksAPI7::IKompasDocument2DPtr & doc );
void RoughWork( ksAPI7::IKompasDocument2DPtr & doc );
void BaseWork( ksAPI7::IKompasDocument2DPtr & doc );
void CutLineWork( ksAPI7::IKompasDocument2DPtr & doc );
void ViewPointerWork( ksAPI7::IKompasDocument2DPtr & doc );
void ToleranceWork( ksAPI7::IKompasDocument2DPtr & doc );
void ObjectsNavigation( ksAPI7::IKompasDocument2DPtr & doc );


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
			case 1:		LeaderWork( doc );				break;	// Создание и редактирование простой линии выноски
			case 2:		MarkLeaderWork( doc );		break;	// Создание и редактирование знака маркировки
			case 3:		ChangeLeaderWork( doc );	break;	// Создание и редактирование знака изменения
			case 4:		BrandLeaderWork( doc );		break;	// Создание и редактирование знака клеймения
			case 5:		RoughWork( doc );					break;	// Создание и редактирование обозначения шероховатости
			case 6:		BaseWork( doc );					break;	// Создание и редактирование обозначения базы
			case 7:		CutLineWork( doc );				break;	// Создание и редактирование линии разреза/сечения
			case 8:		ViewPointerWork( doc );		break;	// Создание и редактирование стрелки направления взгляда
			case 9:		ToleranceWork( doc );			break;	// Создание и редактирование допуска формы
			case 10:	ObjectsNavigation( doc );	break;	// Навигация по массиву объектов
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
// Создать массив SAFEARRAY типа double
// ---
bool NewSafeArray( double * dv, int count, _variant_t & buf )
{
  bool res = false;
  SAFEARRAYBOUND sabNewArray;
	
  sabNewArray.cElements = count;
  sabNewArray.lLbound = 0;
	
  SAFEARRAY * pSafe = ::SafeArrayCreate( VT_R8, 1, &sabNewArray );
	
  if( pSafe )
  {
    for ( long i = 0; i < count; i++ )
    {
      HRESULT  hr = ::SafeArrayPutElement( pSafe, (long*)&i, (void*)&dv[i] );
			
      if ( FAILED(hr) ) 
        break;
    }
		
    V_VT(&buf) = VT_ARRAY | VT_R8;
    V_ARRAY(&buf) = pSafe;
    res = true;
  }
  return res;
}


//-------------------------------------------------------------------------------
// Создание простой линии выноски
// ---
void CreateLeader( ksAPI7::ILeaderPtr & leader )
{
	if ( leader )
	{
		// Направление полки - вправо
		leader->ShelfDirection = ksLSRight;

		// Получаем интерфейс ответвлений
		ksAPI7::IBranchsPtr branchs( leader );

		if ( branchs )
		{
			// Координаты начала полки или точка привязки
			branchs->X0 = 100;
			branchs->Y0 = 150;
			// Добавить прямолинейные ответвления
			branchs->AddBranchByPoint( -1, 60, 120 );
			branchs->AddBranchByPoint( -1, 65, 105 );
		}

		// Получить интерфейс текста над полкой
		ksAPI7::ITextPtr txtOnSh( leader->TextOnShelf );

		if ( txtOnSh )
			// Изменить текст
			txtOnSh->Str = _T("1");

		// Получить интерфейс текста под полкой
		ksAPI7::ITextPtr txtUnderSh( leader->TextUnderShelf );

		if ( txtUnderSh )
			// Изменить текст
			txtUnderSh->Str = _T("2");

		// Получить интерфейс текста над ножкой
		ksAPI7::ITextPtr txtOnBr( leader->TextOnBranch );
		
		if ( txtOnBr )
			// Изменить текст
			txtOnBr->Str = _T("3");

		// Получить интерфейс текста под ножкой
		ksAPI7::ITextPtr txtUnderBr( leader->TextUnderBranch );
		
		if ( txtUnderBr )
			// Изменить текст
			txtUnderBr->Str = _T("4");

		// Получить интерфейс текста за полкой
		ksAPI7::ITextPtr txtAfterSh( leader->TextAfterShelf );
		
		if ( txtAfterSh )
			// Изменить текст
			txtAfterSh->Str = _T("5");

		ksAPI7::IBaseLeaderPtr baseLeader( leader );

		if ( baseLeader )
			// Применить параметры
			baseLeader->Update();
	}
}


//-------------------------------------------------------------------------------
// Задать компоненту текста
// ---
void AddTextItem( ksAPI7::ITextLinePtr & line, _bstr_t str, ksTextItemEnum type )
{
	if ( line )
	{
		// Получить интерфейс компоненты текста
		ksAPI7::ITextItemPtr item( line->Add() );
		
		if ( item )
		{
			// Задать строковое значение
			item->Str = str;
			// Задать тип
			item->ItemType = type;
			// Применить параметры
			item->Update();
		}
	}
}


//-------------------------------------------------------------------------------
// Редактирование линии выноски
// ---
void EditLeader( ksAPI7::ILeaderPtr & leader )
{
	if ( leader )
	{
		// Тип значка - знак склеивания
		leader->SignType = ksLGlueSign;
		// Включить признак обоработки по контуру
		leader->Arround = TRUE;

		// Получаем интерфейс ответвлений
		ksAPI7::IBranchsPtr branchs( leader );
		
		if ( branchs )
			// Добавить прямолинейное ответвление
			branchs->AddBranchByPoint( -1, 140, 120 );

		// Начало созданного ответвления - от конца полки
		leader->BranchBegin[2] = FALSE;

		// Получить текст над полкой
		ksAPI7::ITextPtr txt( leader->TextOnShelf );

		if ( txt )
		{
			txt->Str = _T("");

			ksAPI7::ITextLinePtr line( txt->Add() );

			if ( line )
			{
				// Добавить строку
				AddTextItem( line, _T("1"), ksTItString );
				// Добавить числитель дроби
				AddTextItem( line, _T("1"), ksTItNumerator );
				// Добавить знаментатель дроби
				AddTextItem( line, _T("1"), ksTItDenominator );
				// Закончить дробь
				AddTextItem( line, _T("1"), ksTItFractionEnd );
			}
		}

		ksAPI7::IBaseLeaderPtr baseLeader( leader );
		
		if ( baseLeader )
			// Применить параметры
			baseLeader->Update();
	}
}


//-------------------------------------------------------------------------------
// Создание и редактирование простой линии выноски
// ---
void LeaderWork( ksAPI7::IKompasDocument2DPtr & doc )
{
	// Получить контейнер условных обозначений
	ksAPI7::ISymbols2DContainerPtr symbCont( GetSymbols2DContainer(doc) );

	if ( symbCont )
	{
		// Получить коллекцию линий выноски
		ksAPI7::ILeadersPtr leadersCol( symbCont->GetLeaders() );

		if ( leadersCol )
		{
			// Добавить простую линию выноски
			ksAPI7::ILeaderPtr leader( leadersCol->Add(ksDrLeader) );

			if ( leader )
			{
				// Создать линию выноски
				CreateLeader( leader );

				// Получить референс объекта
				ksAPI7::IBaseLeaderPtr bLeader( leader );
				reference refr = 0;

				if ( bLeader )
					refr = bLeader->Reference; 
				
				// Подсветить созданный объект
				LightObj( refr, 1/*включить подсветку*/ );

				if ( YesNoT((LPTSTR)(LPCTSTR)LoadStr(IDS_EDIT)) == 1 )
				{		
					_variant_t index = (long)refr;
					// Получить объект из коллекции по референсу
					ksAPI7::ILeaderPtr lead( leadersCol->GetLeader( index ) );				
					// Редактировать линию выноски
					EditLeader( lead );
				}
				LightObj( refr, 0/*выключить подсветку*/ );
			}
		}
	}
}


//-------------------------------------------------------------------------------
// Создание знака маркировки
// ---
void CreateMarkLeader( ksAPI7::IMarkLeaderPtr & markLeader )
{
	if ( markLeader )
	{
		// Получить интерфейс ответвлений
		ksAPI7::IBranchsPtr branchs( markLeader );
		
		if ( branchs )
		{
			// Точка привязки 
			branchs->X0 = 100;
			branchs->Y0 = 190;
			// Добавить прямолинейное ответвление
			branchs->AddBranchByPoint( -1, 60, 120 );
		}

		// Получить интерфейс текста обозначения
		ksAPI7::ITextPtr des( markLeader->Designation );

		if ( des )
			// Изменить текст
			des->Str = (LPTSTR)(LPCTSTR)LoadStr( IDS_MARK );

		// Получить интерфейс текста над ножкой
		ksAPI7::ITextPtr textOnBranch( markLeader->TextOnBranch );

		if ( textOnBranch )
			// Изменить текст
			textOnBranch->Str = _T("2");

		// Получить интерфейс текста под ножкой
		ksAPI7::ITextPtr textUnderBranch( markLeader->TextUnderBranch );
		
		if ( textUnderBranch )
			// Изменить текст
			textUnderBranch->Str = _T("3");

		// Получить базовый интерфейс линии выноски
		ksAPI7::IBaseLeaderPtr baseLeader( markLeader );

		if ( baseLeader )
			// Применить параметры
			baseLeader->Update();
	}
}


//-------------------------------------------------------------------------------
// Редактирование знака маркировки
// ---
void EditMarkLeader( ksAPI7::IMarkLeaderPtr & markLeader )
{
	if ( markLeader )
	{
		// Получить интерфейс ответвлений
		ksAPI7::IBranchsPtr branchs( markLeader );

		if ( branchs )
			// Добавить прямолинейное ответвление
			branchs->AddBranchByPoint( -1, 70, 110 );

		// Получить базовый интерфейс линии выноски
		ksAPI7::IBaseLeaderPtr baseLeader( markLeader );

		if ( baseLeader )
		{
			// Тип стрелки
			baseLeader->ArrowType = ksLeaderArrow;
			// Применить изменения
			baseLeader->Update();
		}
	}
}


//-------------------------------------------------------------------------------
// Создание и редактирование знака маркировки
// ---
void MarkLeaderWork( ksAPI7::IKompasDocument2DPtr & doc )
{
	// Получить контейнер условных обозначений
	ksAPI7::ISymbols2DContainerPtr symbCont( GetSymbols2DContainer(doc) );
	
	if ( symbCont )
	{
		// Получить коллекцию линий выноски
		ksAPI7::ILeadersPtr leadersCol( symbCont->GetLeaders() );
		
		if ( leadersCol )
		{
			// Добавить знак маркировки
			ksAPI7::IMarkLeaderPtr mLeader( leadersCol->Add(ksDrMarkerLeader) );
			
			if ( mLeader )
			{
				// Создать знак маркировки
				CreateMarkLeader( mLeader );
				
				// Получить референс объекта
				ksAPI7::IBaseLeaderPtr bLeader( mLeader );
				reference refr = 0;
				
				if ( bLeader )
					refr = bLeader->Reference;
				
				// Подсветить созданный объект
				LightObj( refr, 1/*включить подсветку*/ );
				
				if ( YesNoT((LPTSTR)(LPCTSTR)LoadStr(IDS_EDIT)) == 1 )
				{
					_variant_t index = (long)refr;
					// Получить объект из коллекции по референсу
					ksAPI7::IMarkLeaderPtr markLead( leadersCol->GetLeader( index ) );				
					// Редактировать знак маркировки
					EditMarkLeader( markLead );
				}
				LightObj( refr, 0/*выключить подсветку*/ );
			}
		}
	}
}


//-------------------------------------------------------------------------------
// Создание знака изменения
// ---
void CreateChangeLeader( ksAPI7::IChangeLeaderPtr & changeLeader )
{
	if ( changeLeader )
	{
		// Тип значка - квадрат
		changeLeader->SignType = ksCLSSquare;

		// Получить интерфейс ответвлений
		ksAPI7::IBranchsPtr branchs( changeLeader );

		if ( branchs )
		{
			// Точка привязки
			branchs->X0 = 70;
			branchs->Y0 = 150;
			// Добавить ответвление
			branchs->AddBranchByPoint( -1, 40, 130 );
		}

		// Получить интерфейс текста обозначения
		ksAPI7::ITextPtr des( changeLeader->Designation );
		
		if ( des )
			// Изменить текст
			des->Str = _T("1");

		// Получить базовый интерфейс линии выноски
		ksAPI7::IBaseLeaderPtr baseLeader( changeLeader );

		if ( baseLeader )
			// Применить параметры
			baseLeader->Update();
	}
}


//-------------------------------------------------------------------------------
// Редактирование знака изменения
// ---
void EditChangeLeader( ksAPI7::IChangeLeaderPtr & changeLeader )
{
	if ( changeLeader )
	{
		// Тип значка - круг
		changeLeader->SignType = ksCLSCircle;
		// Полная длина выноски отключена
		changeLeader->FullLeaderLength = FALSE;
		// Длина выноски
		changeLeader->LeaderLength = 5;

		// Получить базовый интерфейс линии выноски
		ksAPI7::IBaseLeaderPtr baseLeader( changeLeader );
		
		if ( baseLeader )
			// Применить изменения
			baseLeader->Update();
	}
}


//-------------------------------------------------------------------------------
// Создание и редактирование знака изменения
// ---
void ChangeLeaderWork( ksAPI7::IKompasDocument2DPtr & doc )
{
	// Получить контейнер условных обозначений
	ksAPI7::ISymbols2DContainerPtr symbCont( GetSymbols2DContainer(doc) );
	
	if ( symbCont )
	{
		// Получить коллекцию линий выноски
		ksAPI7::ILeadersPtr leadersCol( symbCont->GetLeaders() );
		
		if ( leadersCol )
		{
			// Добавить знак изменения
			ksAPI7::IChangeLeaderPtr chLeader( leadersCol->Add(ksDrChangeLeader) );
			
			if ( chLeader )
			{
				// Создать знак изменения
				CreateChangeLeader( chLeader );
				
				// Получить референс объекта
				ksAPI7::IBaseLeaderPtr bLeader( chLeader );
				reference refr = 0;
				
				if ( bLeader )
					refr = bLeader->Reference;
				
				// Подсветить созданный объект
				LightObj( refr, 1/*включить подсветку*/ );
				
				if ( YesNoT((LPTSTR)(LPCTSTR)LoadStr(IDS_EDIT)) )
				{
					_variant_t index = (long)refr;
					// Получить объект из коллекции по референсу
					ksAPI7::IChangeLeaderPtr changeLead( leadersCol->GetLeader( index ) );				
					// Редактировать знак изменения
					EditChangeLeader( changeLead );
				}
				LightObj( refr, 0/*выключить подсветку*/ );
			}
		}
	}
}


//-------------------------------------------------------------------------------
// Создание знака клеймения
// ---
void CreateBrandLeader( ksAPI7::IBrandLeaderPtr & brandLeader )
{
	if ( brandLeader )
	{
		// Направление
		brandLeader->Direction = FALSE;

		// Получить интерфейс текста обозначения
		ksAPI7::ITextPtr des( brandLeader->Designation );

		if ( des )
			// Изменить текст
			des->Str = (LPTSTR)(LPCTSTR)LoadStr( IDS_MARK2 );

		// Получить интерфейс ответвлений
		ksAPI7::IBranchsPtr branchs( brandLeader );

		if ( branchs )
		{
			// Точка привязки
			branchs->X0 = 100;
			branchs->Y0 = 150;
			// Добавить ответвление
			branchs->AddBranchByPoint( -1, 60, 110 );
		}

		// Получить базовый интерфейс линии выноски
		ksAPI7::IBaseLeaderPtr baseLeader( brandLeader );
		
		if ( baseLeader )
			// Применить параметры
			baseLeader->Update();
	}
}


//-------------------------------------------------------------------------------
// Редактирование знака изменения
// ---
void EditBrandLeader( ksAPI7::IBrandLeaderPtr & brandLeader )
{
	if ( brandLeader )
	{
		// Направление
		brandLeader->Direction = TRUE;

		// Получить интерфейс текста над ножкой
		ksAPI7::ITextPtr textOn( brandLeader->TextOnBranch );
		
		if ( textOn )
			// Изменить текст
			textOn->Str = _T("2");
		
		// Получить интерфейс текста под ножкой
		ksAPI7::ITextPtr textUnder( brandLeader->TextUnderBranch );
		
		if ( textUnder )
			// Изменить текст
			textUnder->Str = _T("3");

		// Получить интерфейс текста обозначения
		ksAPI7::ITextPtr des( brandLeader->Designation );
		
		if ( des )
			// Изменить текст
			des->Str = (LPTSTR)(LPCTSTR)LoadStr( IDS_MARK3 );

		// Получить базовый интерфейс линии выноски
		ksAPI7::IBaseLeaderPtr baseLeader( brandLeader );
		
		if ( baseLeader )
			// Применить параметры
			baseLeader->Update();
	}
}


//-------------------------------------------------------------------------------
// Создание и редактирование знака клеймения
// ---
void BrandLeaderWork( ksAPI7::IKompasDocument2DPtr & doc )
{
	// Получить контейнер условных обозначений
	ksAPI7::ISymbols2DContainerPtr symbCont( GetSymbols2DContainer(doc) );
	
	if ( symbCont )
	{
		// Получить коллекцию линий выноски
		ksAPI7::ILeadersPtr leadersCol( symbCont->GetLeaders() );
		
		if ( leadersCol )
		{
			// Добавить знак клеймения
			ksAPI7::IBrandLeaderPtr brLeader( leadersCol->Add(ksDrBrandLeader) );
			
			if ( brLeader )
			{
				// Создать знак клеймения
				CreateBrandLeader( brLeader );
				
				// Получить референс объекта
				ksAPI7::IBaseLeaderPtr bLeader( brLeader );
				reference refObj = 0;
				
				if ( bLeader )
					refObj = bLeader->Reference;
				
				// Подсветить созданный объект
				LightObj( refObj, 1/*включить подсветку*/ );
				
				if ( YesNoT((LPTSTR)(LPCTSTR)LoadStr(IDS_EDIT)) == 1 )
				{
					_variant_t index = (long)refObj;
					// Получить объект из коллекции по референсу
					ksAPI7::IBrandLeaderPtr brandLead( leadersCol->GetLeader( index ) );				
					// Редактировать знак клеймения
					EditBrandLeader( brandLead );
				}
				LightObj( refObj, 0/*выключить подсветку*/ );
			}
		}
	}
}


//-------------------------------------------------------------------------------
// Создание обозначения шероховатости
// ---
bool CreateRough( ksAPI7::IRoughPtr & rough )
{
	bool res = false;

	if ( rough )
	{
		// Структура параметров запроса к системе
		RequestInfoT info;
		memset( &info, 0, sizeof(info) );
		info.commands = MAKEINTRESOURCE( IDS_COMMAND1 );
		info.cursor   = MAKEINTRESOURCE( OCR_CATCH    );
		double x, y;

		// Отключить привязки
		SnapOptions sOpt;
		ksGetSysOptions( SNAP_OPTIONS, &sOpt, sizeof(sOpt) );
		sOpt.commonOpt = FALSE;
		ksSetSysOptions( SNAP_OPTIONS, &sOpt, sizeof(sOpt) );

		// Указать базовый объект
		if ( CursorExT(&info, &x, &y, NULL, NULL) )
		{
			// Найти объект по указанным координатам
			reference pObj = FindObj( x, y, ksGetCursorLimit() );
			// Подсветить объект
			LightObj( pObj, 1/*включить подсветку*/ );
			// Получить интерфейс графического объекта из референса
			ksAPI7::IDrawingObjectPtr baseObj( IUnknownPtr(ksTransferReference(pObj, ksGetCurrentDocument(0)), false/*AddRef*/) );
			info.commands = MAKEINTRESOURCE( IDS_COMMAND2 );
			info.cursor = 0;

			// Если привязки выключены, включить
			if ( !sOpt.commonOpt )
			{
				sOpt.commonOpt = TRUE;
				ksSetSysOptions( SNAP_OPTIONS, &sOpt, sizeof(sOpt) );
			}

			// Указать точку привязки
			if ( CursorExT(&info, &x, &y, NULL, NULL) )
			{
				if ( baseObj )
					// Базовый объект
					rough->BaseObject = baseObj;
				// Точка привязки
				rough->BranchX0 = x;
				rough->BranchY0 = y;
				
				ksAPI7::IRoughParamsPtr roughPar( rough );

				if ( roughPar )
				{
					roughPar->ShelfDirection = ksLSRight;
					rough->Update();
					// Обработка по контуру включена
					roughPar->ProcessingByContour = TRUE;
					// Длина линии выноски
					roughPar->LeaderLength = 20;
					// Угол наклона линии выноски
					roughPar->LeaderAngle = 45;

					// Получить интерфейс текста параметров шероховатости
					ksAPI7::ITextPtr txt1( roughPar->RoughParamText );

					if ( txt1 )
						txt1->Str = _T("1");
					
					// Получить интерфейс текста способа обработки поверхности
					ksAPI7::ITextPtr txt2( roughPar->ProcessText );
					
					if ( txt2 )
						txt2->Str = _T("2");

					// Получить интерфейс текста базовой длины
					ksAPI7::ITextPtr txt3( roughPar->BaseLengthText );
					
					if ( txt3 )
						txt3->Str = _T("3");
				}

				// Применить параметры
				rough->Update();
				res = true;
			}
			else
				MessageT( (LPTSTR)(LPCTSTR)LoadStr(IDS_NOPOINT) );

			LightObj( pObj, 0/*выключить подсветку*/ );
		}
		else
			MessageT( (LPTSTR)(LPCTSTR)LoadStr(IDS_NOOBJ) );

		// Если привязки выключены, включить
		if ( !sOpt.commonOpt )
		{
			sOpt.commonOpt = TRUE;
			ksSetSysOptions( SNAP_OPTIONS, &sOpt, sizeof(sOpt) );
		}
	}
	return res;
}


//-------------------------------------------------------------------------------
// Редактирование обозначения шероховатости
// ---
void EditRough( ksAPI7::IRoughPtr & rough )
{
	if ( rough )
	{
		// Получить интерфейс параметров шероховатости
		ksAPI7::IRoughParamsPtr roughPar( rough );

		if ( roughPar )
		{
			// Убрать стрелку
			roughPar->ArrowType = ksWithoutArrow;
			// Обработка по контуру отключена
			roughPar->ProcessingByContour = FALSE;
		}
		// Применить изменения
		rough->Update();
	}
}


//-------------------------------------------------------------------------------
// Создание и редактирование обозначения шероховатости
// ---
void RoughWork( ksAPI7::IKompasDocument2DPtr & doc )
{
	// Получить контейнер условных обозначений
	ksAPI7::ISymbols2DContainerPtr symbCont( GetSymbols2DContainer(doc) );
	
	if ( symbCont )
	{
		// Получить коллекцию обозначений шероховатости
		ksAPI7::IRoughsPtr roughsCol( symbCont->GetRoughs() );
		
		if ( roughsCol )
		{
			// Добавить обозначение шероховатости
			ksAPI7::IRoughPtr newRough( roughsCol->Add() );
			
			if ( newRough )
			{
				// Создать обозначение шероховатости
				if ( CreateRough(newRough) )
				{				
					// Получить референс объекта
					reference objRef = newRough->Reference;
					// Подсветить созданный объект
					LightObj( objRef, 1/*включить подсветку*/ );
					
					if ( YesNoT((LPTSTR)(LPCTSTR)LoadStr(IDS_EDIT)) )
					{
						_variant_t index = (long)objRef;
						// Получить объект из коллекции по референсу
						ksAPI7::IRoughPtr rough( roughsCol->GetRough( index ) );				
						// Редактировать обозначение шероховатости
						EditRough( rough );
					}
					LightObj( objRef, 0/*выключить подсветку*/ );
				}
			}
		}
	}
}


//-------------------------------------------------------------------------------
// Создание обозначения базы
// ---
bool CreateBase( ksAPI7::IBasePtr & base )
{
	bool res = false;

	if ( base )
	{
		// Структура параметров запроса к системе
		RequestInfoT info;
		memset( &info, 0, sizeof(info) );
		info.commands = MAKEINTRESOURCE( IDS_COMMAND1 );
		info.cursor   = MAKEINTRESOURCE( OCR_CATCH    );
		double x, y;

		// Отключить привязки
		SnapOptions sOpt;
		ksGetSysOptions( SNAP_OPTIONS, &sOpt, sizeof(sOpt) );
		sOpt.commonOpt = FALSE;
		ksSetSysOptions( SNAP_OPTIONS, &sOpt, sizeof(sOpt) );
		
		// Указать базовый объект
		if ( CursorExT(&info, &x, &y, NULL, NULL) )
		{
			// Найти объект по указанным координатам
			reference pObj = FindObj( x, y, ksGetCursorLimit() );
			// Подсветить объект
			LightObj( pObj, 1/*включить подсветку*/ );
			// Получить интерфейс графического объекта из референса
			ksAPI7::IDrawingObjectPtr baseObj( IUnknownPtr(ksTransferReference(pObj, ksGetCurrentDocument(0)), false/*AddRef*/) );
			info.commands = MAKEINTRESOURCE( IDS_COMMAND2 );
			info.cursor = 0;

			// Если привязки выключены, включить
			if ( !sOpt.commonOpt )
			{
				sOpt.commonOpt = TRUE;
				ksSetSysOptions( SNAP_OPTIONS, &sOpt, sizeof(sOpt) );
			}
			
			// Указать положение знака
			if ( CursorExT(&info, &x, &y, NULL, NULL) )
			{
				if ( baseObj )
					// Базовый объект
					base->BaseObject = baseObj;

				// Точка положения знака
				base->X0 = x;
				base->Y0 = y;
				// Способ отрисовки - перпендикулярно к объекту
				base->DrawType = TRUE;
				// Применить параметры
				base->Update();
				res = true;
			}
			else
				MessageT( (LPTSTR)(LPCTSTR)LoadStr(IDS_NOPOINT) );

			LightObj( pObj, 0/*выключить подсветку*/ );
		}
		else
			MessageT( (LPTSTR)(LPCTSTR)LoadStr(IDS_NOOBJ) );

		// Если привязки выключены, включить
		if ( !sOpt.commonOpt )
		{
			sOpt.commonOpt = TRUE;
			ksSetSysOptions( SNAP_OPTIONS, &sOpt, sizeof(sOpt) );
		}
	}
	return res;
}


//-------------------------------------------------------------------------------
// Редактирование обозначения базы
// ---
void EditBase( ksAPI7::IBasePtr & base )
{
	if ( base )
	{
		// Тип отрисовки - произвольно
		base->DrawType = FALSE;
		// Отключить автосортировку
		base->AutoSorted = FALSE;
		// Конечная точка выноски
		base->BranchX = base->X0 + 10;
		base->BranchY = base->Y0 + 10;

		// Получить интерфейс текста обозначения базы
		ksAPI7::ITextPtr txt( base->Text );

		if ( txt )
			// Изменить текст
			txt->Str = _T("B");

		// Применить параметры
		base->Update();
	}
}


//-------------------------------------------------------------------------------
// Создание и редактирование обозначения базы
// ---
void BaseWork( ksAPI7::IKompasDocument2DPtr & doc )
{
	// Получить контейнер условных обозначений
	ksAPI7::ISymbols2DContainerPtr symbCont( GetSymbols2DContainer(doc) );
	
	if ( symbCont )
	{
		// Получить коллекцию обозначений базы
		ksAPI7::IBasesPtr basesCol( symbCont->GetBases() );
		
		if ( basesCol )
		{
			// Добавить обозначение базы
			ksAPI7::IBasePtr newBase( basesCol->Add() );
			
			if ( newBase )
			{
				// Создать обозначение базы
				if ( CreateBase(newBase) )
				{			
					// Получить референс объекта
					reference objRef = newBase->Reference;
					// Подсветить созданный объект
					LightObj( objRef, 1/*включить подсветку*/ );
					
					if ( YesNoT((LPTSTR)(LPCTSTR)LoadStr(IDS_EDIT)) == 1 )
					{
						_variant_t index = (long)objRef;
						// Получить объект из коллекции по референсу
						ksAPI7::IBasePtr base( basesCol->GetBase( index ) );				
						// Редактировать обозначение базы
						EditBase( base );
					}
					LightObj( objRef, 0/*выключить подсветку*/ );
				}
			}
		}
	}
}


//-------------------------------------------------------------------------------
// Создать текст с заданным размером шрифта
// ---
void SetTextSmallFont( ksAPI7::ITextPtr & txt, _bstr_t str, double size )
{
	if ( txt )
	{
		// Получить интерфейс строки текста
		ksAPI7::ITextLinePtr line( txt->Add() );

		if ( line )
		{
			// Получить интерфейс компоненты текста
			ksAPI7::ITextItemPtr item( line->Add() );

			if ( item )
			{
				// Получить интерфейс шрифта
				ksAPI7::ITextFontPtr font( item );

				if ( font )
					// Задать высоту шрифта
					font->Height = size;

				// Задать значение строки
				item->Str = str;
				// Применить параметры
				item->Update();
			}
		}
	}
}


//-------------------------------------------------------------------------------
// Создание линии разреза/сечения
// ---
void CreateCutLine( ksAPI7::ICutLinePtr & cutLine )
{
	if ( cutLine )
	{
		// Координаты начального текста
		cutLine->X1 = 80;
		cutLine->Y1 = 165;
		// Координаты конечного текста
		cutLine->X2 = 120;
		cutLine->Y2 = 200;
		// Расположение стрелок - слева
		cutLine->ArrowPos = TRUE;
		// Размещение дополнительного текста - у первой стрелки
		cutLine->AdditionalTextPos = TRUE;

		// Создать массив точек линии разреза
		double points[4];
		points[0] = 80;
		points[1] = 165;
		points[2] = 120;
		points[3] = 200;
		_variant_t pointsArray;
		
		if ( NewSafeArray(points, 4, pointsArray) )
			// Задать массив точек линии разреза
			cutLine->Points = pointsArray;


		// Получить интерфейс дополнительного текста
		ksAPI7::ITextPtr adText( cutLine->AdditionalText );
		
		if ( adText )
			SetTextSmallFont( adText, _T("(1)"), 7 );

		// Применить параметры
		cutLine->Update();
	}
}


//-------------------------------------------------------------------------------
// Редактирование линии разреза/сечения
// ---
void EditCutLine( ksAPI7::ICutLinePtr & cutLine )
{
	if ( cutLine )
	{
		// Расположение стрелок - справа по направлению ломаной
		cutLine->ArrowPos = FALSE;
		// Расположение дополнительного текста - у второй стрелки
		cutLine->AdditionalTextPos = FALSE;
		// Отключить автосортировку
		cutLine->AutoSorted = FALSE;

		// Создать массив точек линии разреза
		double points[6];
		points[0] = 80;
		points[1] = 165;
		points[2] = 115;
		points[3] = 165;
		points[4] = 120;
		points[5] = 200;
		_variant_t pointsArray;

		if ( NewSafeArray(points, 6, pointsArray) )
			// Задать массив точек линии разреза
			cutLine->Points = pointsArray;

		// Применить изменения
		cutLine->Update();
	}
}


//-------------------------------------------------------------------------------
// Создание и редактирование линии разреза/сечения
// ---
void CutLineWork( ksAPI7::IKompasDocument2DPtr & doc )
{
	// Получить контейнер условных обозначений
	ksAPI7::ISymbols2DContainerPtr symbCont( GetSymbols2DContainer(doc) );
	
	if ( symbCont )
	{
		// Получить коллекцию линий разреза/сечения
		ksAPI7::ICutLinesPtr cutCol( symbCont->GetCutLines() );
		
		if ( cutCol )
		{
			// Добавить линию разреза/сечения
			ksAPI7::ICutLinePtr newCut( cutCol->Add() );
			
			if ( newCut )
			{
				// Создать линию разреза/сечения
				CreateCutLine( newCut );
				
				// Получить референс объекта
				reference objRef = newCut->Reference;
				// Подсветить созданный объект
				LightObj( objRef, 1/*включить подсветку*/ );
				
				if ( YesNoT((LPTSTR)(LPCTSTR)LoadStr(IDS_EDIT)) == 1 )
				{
					_variant_t index = (long)objRef;
					// Получить объект из коллекции по референсу
					ksAPI7::ICutLinePtr cutLine( cutCol->GetCutLine( index ) );				
					// Редактировать линию разреза/сечения
					EditCutLine( cutLine );
				}
				LightObj( objRef, 0/*выключить подсветку*/ );
			}
		}
	}
}


//-------------------------------------------------------------------------------
// Создание стрелки направления взгляда
// ---
void CreateViewPointer( ksAPI7::IViewPointerPtr & viewPointer )
{
	if ( viewPointer )
	{
		// Начальная точка стрелки
		viewPointer->X1 = 100;
		viewPointer->Y1 = 150;
		// Конечная точка стрелки
		viewPointer->X2 = 120;
		viewPointer->Y2 = 160;
		// Применить параметры
		viewPointer->Update();
	}
}


//-------------------------------------------------------------------------------
// Редактирование стрелки направления взгляда
// ---
void EditViewPointer( ksAPI7::IViewPointerPtr & viewPointer )
{
	if ( viewPointer )
	{
		// Конечная точка стрелки
		viewPointer->X2 = 90;
		viewPointer->Y2 = 140;
		// Включить автосортировку
		viewPointer->AutoSorted = TRUE;

		// Получить интерфейс текста обозначения направления взгляда
		ksAPI7::ITextPtr adText( viewPointer->AdditionalText );
		
		if ( adText )
			// Изменить текст
			SetTextSmallFont( adText, _T("(1)"), 7 );
		
		// Применить параметры
		viewPointer->Update();
	}
}


//-------------------------------------------------------------------------------
// Создание и редактирование стрелки направления взгляда
// ---
void ViewPointerWork( ksAPI7::IKompasDocument2DPtr & doc )
{
	// Получить контейнер условных обозначений
	ksAPI7::ISymbols2DContainerPtr symbCont( GetSymbols2DContainer(doc) );
	
	if ( symbCont )
	{
		// Получить коллекцию стрелок направления взгляда
		ksAPI7::IViewPointersPtr viewPointsCol( symbCont->GetViewPointers() );
		
		if ( viewPointsCol )
		{
			// Добавить стрелку направления взгляда
			ksAPI7::IViewPointerPtr newPointer( viewPointsCol->Add() );
			
			if ( newPointer )
			{
				// Создать стрелку направления взгляда
				CreateViewPointer( newPointer );
				
				// Получить референс объекта
				reference objRef = newPointer->Reference;
				// Подсветить созданный объект
				LightObj( objRef, 1/*включить подсветку*/ );
				
				if ( YesNoT((LPTSTR)(LPCTSTR)LoadStr(IDS_EDIT)) == 1 )
				{
					_variant_t index = (long)objRef;
					// Получить объект из коллекции по референсу
					ksAPI7::IViewPointerPtr viewPointer( viewPointsCol->GetViewPointer( index ) );				
					// Редактировать стрелку направления взгляда
					EditViewPointer( viewPointer );
				}
				LightObj( objRef, 0/*выключить подсветку*/ );
			}
		}
	}
}


//-------------------------------------------------------------------------------
// Задать текст в ячейках допуска формы
// ---
void SetToleranceText( ksAPI7::IToleranceParamPtr & tolPar )
{
	if ( tolPar )
	{
		// Получить интерфейс таблицы с текстом допуска формы
		ksAPI7::ITablePtr tolTable( tolPar->Table );
		
		if ( tolTable )
		{
			// Добавить 3 столбца (1 уже есть)
			tolTable->AddColumn( -1, TRUE/*справа*/ );
			tolTable->AddColumn( -1, TRUE/*справа*/ );
			tolTable->AddColumn( -1, TRUE/*справа*/ );
			
			// Записать текст в 1-ю ячейку
			ksAPI7::ITableCellPtr cell( tolTable->GetCell(0, 0) );
			ksAPI7::ITextLinePtr txt = NULL;
			
			if ( cell )
			{
				txt = cell->Text;
				
				if ( txt )
					txt->Str = _T("@22~");
			}
			
			// Записать текст во 2-ю ячейку
			cell = tolTable->GetCell( 0, 1 );
			
			if ( cell )
			{
				txt = cell->Text;
				
				if ( txt )
					txt->Str = "@2~";
			}

			// Записать текст в 3-ю ячейку
			cell = tolTable->GetCell( 0, 2 );
			
			if ( cell )
			{
				txt = cell->Text;
				
				if ( txt )
					txt->Str = "B";
			}

			// Записать текст в 4-ю ячейку
			cell = tolTable->GetCell( 0, 3 );
			
			if ( cell )
			{
				txt = cell->Text;
				
				if ( txt )
					txt->Str = "@30~";
			}
		}
	}
}


//-------------------------------------------------------------------------------
// Создание допуска формы
// ---
void CreateTolerance( ksAPI7::ITolerancePtr & tolerance )
{
	if ( tolerance )
	{
		// Получить интерфейс ответвления
		ksAPI7::IBranchsPtr branchs( tolerance );

		if ( branchs )
		{
			// Задать точку привязки
			branchs->X0 = 100;
			branchs->Y0 = 150;
			// Добавить 2 ответвления
			branchs->AddBranchByPoint( -1, 100, 120 );
			branchs->AddBranchByPoint( -1, 50, 155 );
		}

		// Получить интерфейс параметров допуска формы
		ksAPI7::IToleranceParamPtr tolPar( tolerance );
		
		if ( tolPar )
		{
			// Создать текст в ячейках
			SetToleranceText( tolPar );
			// Положение базовой точки относительно таблицы - внизу посередине
			tolPar->BasePointPos = ksTPBottomCenter;
		}
		// Тип стрелки 1-го ответвления - треугольник
		tolerance->PutArrowType( 0, FALSE );
		// Положение 1-го ответвления относительно таблицы - внизу посередине
		tolerance->PutBranchPos( 0, ksTPBottomCenter );
		// Тип стрелки 2-го ответвления - стрелка
		tolerance->PutArrowType( 1, TRUE );
		// Положение 2-го ответвления относительно таблицы - слева посередине
		tolerance->PutBranchPos( 1, ksTPLeftCenter );
		// Применить параметры
		tolerance->Update();
	}
}


//-------------------------------------------------------------------------------
// Редактирование допуска формы
// ---
void EditTolerance( ksAPI7::ITolerancePtr & tolerance )
{	
	if ( tolerance )
	{
		// Получитьинтерфейс параметров допуска формы
		ksAPI7::IToleranceParamPtr tolPar( tolerance );

		if ( tolPar )
		{
			// Получить интерфейс таблицы с текстом допуска формы
			ksAPI7::ITablePtr tolTable( tolPar->Table );
			
			if ( tolTable )
			{
				// Изменить текст во 2-й ячейке
				ksAPI7::ITableCellPtr cell( tolTable->GetCell(0, 1) );
				
				if ( cell )
				{
					ksAPI7::ITextLinePtr txt( cell->Text );
					
					if ( txt)
						txt->Str = _T("@2~15");
				}
			}
			// Задать признак вертикальности
			tolPar->Vertical = TRUE;
		}

		// Получить интерфейс ответвлений
		ksAPI7::IBranchsPtr branchs( tolerance );

		if ( branchs )
		{
			// Удалить ответвление
			branchs->DeleteBranch( 0 );
			// Добавить новое ответвление
			branchs->AddBranchByPoint( -1, 130, 120 );
		}
		tolerance->PutArrowType( 1, FALSE );
		tolerance->PutBranchPos( 1, ksTPBottomCenter );
		// Применить изменения
		tolerance->Update();
	}
}


//-------------------------------------------------------------------------------
// Создание и редактирование допуска формы
// ---
void ToleranceWork( ksAPI7::IKompasDocument2DPtr & doc )
{
	// Получить контейнер условных обозначений
	ksAPI7::ISymbols2DContainerPtr symbCont( GetSymbols2DContainer(doc) );
	
	if ( symbCont )
	{
		// Получить коллекцию допусков формы
		ksAPI7::ITolerancesPtr tolerancesCol( symbCont->GetTolerances() );
		
		if ( tolerancesCol )
		{
			// Добавить допуск формы
			ksAPI7::ITolerancePtr newTol( tolerancesCol->Add() );
			
			if ( newTol )
			{
				// Создать допуск формы
				CreateTolerance( newTol );
				
				// Получить референс объекта
				reference objRef = newTol->Reference;
				// Подсветить созданный объект
				LightObj( objRef, 1/*включить подсветку*/ );
				
				if ( YesNoT((LPTSTR)(LPCTSTR)LoadStr(IDS_EDIT)) == 1 )
				{
					_variant_t index = (long)objRef;
					// Получить объект из коллекции по референсу
					ksAPI7::ITolerancePtr tolerance( tolerancesCol->GetTolerance( index ) );				
					// Редактировать допуск формы
					EditTolerance( tolerance );
				}
				LightObj( objRef, 0/*выключить подсветку*/ );
			}
		}
	}
}


//-------------------------------------------------------------------------------
// Получить контейнер графических объектов
// ---
ksAPI7::IDrawingContainerPtr GetDrawingContainer( ksAPI7::IKompasDocument2DPtr & doc )
{
	if ( doc )
	{
		// Получить менеджер видов и слоев
		ksAPI7::IViewsAndLayersManagerPtr mng( doc->GetViewsAndLayersManager() );

		if ( mng )
		{
			// Получить коллекцию видов
			ksAPI7::IViewsPtr viewsCol( mng->GetViews() );

			if ( viewsCol )
			{
				// Получить активный вид
				ksAPI7::IViewPtr view = viewsCol->GetActiveView();

				if ( view )
				{
					// Получить контейнер графических объектов
					ksAPI7::IDrawingContainerPtr drawCont( view );
					return drawCont;
				}
			}
		}
	}
	return NULL;
}


//-------------------------------------------------------------------------------
// Выдать сообщение с параметрами простой линии выноски
// ---
void GetLeaderPar( ksAPI7::ILeaderPtr & leader )
{
	if ( leader )
	{
		double x0, y0;

		// Получить координаты точки привязки
		ksAPI7::IBranchsPtr branchs( leader );

		if ( branchs )
		{
			x0 = branchs->X0;
			y0 = branchs->Y0;
		}
		TCHAR buf[255];
		TCHAR buf2[255];

		// Сформировать сообщение для выдачи
		// "Простая линия выноски"
		_tcscpy_s( buf, (LPTSTR)(LPCTSTR)LoadStr(IDS_LEADER) );
		// "\nТочка привязки:\nX0 = %4.2f, Y0 = %4.2f"
		_stprintf_s( buf2, (LPTSTR)(LPCTSTR)LoadStr(IDS_POINT), x0, y0 );
		_tcscat_s( buf, buf2 );
		// "\nПризнак обработки по контуру: "
		_tcscat_s( buf, (LPTSTR)(LPCTSTR)LoadStr(IDS_ARROUND) );

		if ( leader->Arround )
			// "включен"
			_tcscat_s( buf, (LPTSTR)(LPCTSTR)LoadStr(IDS_ON) );
		else
			// "отключен"
			_tcscat_s( buf, (LPTSTR)(LPCTSTR)LoadStr(IDS_OFF) );

		// "\nНачало ответвления: "
		_tcscat_s( buf, (LPTSTR)(LPCTSTR)LoadStr(IDS_BRANCHBEGIN) );

		if ( leader->BranchBegin[0] )
			// "от начала полки"
			_tcscat_s( buf, (LPTSTR)(LPCTSTR)LoadStr(IDS_BEGINSHELF) );
		else
			// "от конца полки"
			_tcscat_s( buf, (LPTSTR)(LPCTSTR)LoadStr(IDS_ENDSHELF) );

		// "\nПризнак параллельности ответвлений: "
		_tcscat_s( buf, (LPTSTR)(LPCTSTR)LoadStr(IDS_PARALLEL) );

		if ( leader->ParallelBranch )
			// "включен"
			_tcscat_s( buf, (LPTSTR)(LPCTSTR)LoadStr(IDS_ON) );
		else
			// "отключен"
			_tcscat_s( buf, (LPTSTR)(LPCTSTR)LoadStr(IDS_OFF) );
		
		// Выдать сообщение 
		MessageT( buf );
	}
}


//-------------------------------------------------------------------------------
// Выдать сообщение с параметрами знака маркировки
// ---
void GetMarkLeaderPar( ksAPI7::IMarkLeaderPtr & markLeader )
{
	if ( markLeader )
	{
		double x0, y0;
		long count;
	
		ksAPI7::IBranchsPtr branchs( markLeader );
		
		if ( branchs )
		{
			// Получить координаты точки привязки
			x0 = branchs->X0;
			y0 = branchs->Y0;
			// Получить количество ответвлений
			count = branchs->BranchCount;
		}
		TCHAR buf[255];
		TCHAR buf2[255];

		// Сформировать сообщение для выдачи
		// "Знак маркировки"
		_tcscpy_s( buf, (LPTSTR)(LPCTSTR)LoadStr(IDS_MARKLEADER) );
		// "\nТочка привязки:\nX0 = %4.2f, Y0 = %4.2f"
		_stprintf_s( buf2, (LPTSTR)(LPCTSTR)LoadStr(IDS_POINT), x0, y0 );
		_tcscat_s( buf, buf2 );
		// "\nКоличество ответвлений: %d"
		_stprintf_s( buf2, (LPTSTR)(LPCTSTR)LoadStr(IDS_BRANCHCOUNT), count );
		_tcscat_s( buf, buf2 );

		// Выдать сообщение 
		MessageT( buf );
	}
}


//-------------------------------------------------------------------------------
// Выдать сообщение с параметрами знака клеймения
// ---
void GetBrandLeaderPar( ksAPI7::IBrandLeaderPtr & brandLeader )
{
	if ( brandLeader )
	{
		// Сформировать сообщение
		TCHAR buf[255];
		_tcscpy_s( buf, (LPTSTR)(LPCTSTR)LoadStr(IDS_BRANDLEADER) );
		// Выдать сообщение 
		MessageT( buf );
	}
}


//-------------------------------------------------------------------------------
// Выдать сообщение с параметрами знака изменения
// ---
void GetChangeLeaderPar( ksAPI7::IChangeLeaderPtr & changeLeader )
{
	if ( changeLeader )
	{
		// Сформировать сообщение
		TCHAR buf[255];
		_tcscpy_s( buf, (LPTSTR)(LPCTSTR)LoadStr(IDS_CHANLEADER) );
		// Выдать сообщение 
		MessageT( buf );
	}
}


//-------------------------------------------------------------------------------
// Выдать сообщение с параметрами обозначения шероховатости
// ---
void GetRoughPar( ksAPI7::IRoughPtr & rough )
{
	if ( rough )
	{
		// Сформировать сообщение
		TCHAR buf[255];
		_tcscpy_s( buf, (LPTSTR)(LPCTSTR)LoadStr(IDS_ROUGH) );
		// Выдать сообщение 
		MessageT( buf );
	}
}


//-------------------------------------------------------------------------------
// Выдать сообщение с параметрами обозначения базы
// ---
void GetBasePar( ksAPI7::IBasePtr & base )
{
	if ( base )
	{
		// Сформировать сообщение
		TCHAR buf[255];
		_tcscpy_s( buf, (LPTSTR)(LPCTSTR)LoadStr(IDS_BASE) );
		// Выдать сообщение 
		MessageT( buf );
	}
}


//-------------------------------------------------------------------------------
// Выдать сообщение с параметрами линии разреза/сечения
// ---
void GetCutLinePar( ksAPI7::ICutLinePtr & cutLine )
{
	if ( cutLine )
	{
		// Сформировать сообщение
		TCHAR buf[255];
		_tcscpy_s( buf, (LPTSTR)(LPCTSTR)LoadStr(IDS_CUTLINE) );
		// Выдать сообщение 
		MessageT( buf );
	}
}


//-------------------------------------------------------------------------------
// Выдать сообщение с параметрами стрелки направления взгляда
// ---
void GetViewPointerPar( ksAPI7::IViewPointerPtr & viewPointer )
{
	if ( viewPointer )
	{
		// Сформировать сообщение
		TCHAR buf[255];
		_tcscpy_s( buf, (LPTSTR)(LPCTSTR)LoadStr(IDS_VIEWPOINTER) );
		// Выдать сообщение 
		MessageT( buf );
	}
}


//-------------------------------------------------------------------------------
// Выдать сообщение с параметрами допуска формы
// ---
void GetTolerancePar( ksAPI7::ITolerancePtr & tolerance )
{
	if ( tolerance )
	{
		// Сформировать сообщение
		TCHAR buf[255];
		_tcscpy_s( buf, (LPTSTR)(LPCTSTR)LoadStr(IDS_TOLERANCE) );
		// Выдать сообщение 
		MessageT( buf );
	}
}


//-------------------------------------------------------------------------------
// Навигация по массиву объектов вида
// ---
void ObjectsNavigation( ksAPI7::IKompasDocument2DPtr & doc )
{
	// Получить контейнер графических объектов
	ksAPI7::IDrawingContainerPtr drawCont( GetDrawingContainer(doc) );

	if ( drawCont )
	{
		// Тип 0 - все объекты
		_variant_t objType = (long)0;
		// Получить массив SafeArray объектов
		_variant_t arr = drawCont->GetObjects( objType );
		LPDISPATCH pObj;
		
		// Если массив есть и он не пуст
		if ( V_VT(&arr) != VT_EMPTY && arr.parray )
		{
			// Определить количество элементов
			long arCount = arr.parray->rgsabound[0].cElements - arr.parray->rgsabound[0].lLbound;     
			
			for ( long j = 0; j < arCount; j++ )
			{
				// Получить элемент из массива
				HRESULT hr = ::SafeArrayGetElement( arr.parray, &j, &pObj );
				
				if ( pObj )
				{
					// Получить интерфейс графического объекта
					ksAPI7::IDrawingObjectPtr pDrawObj( pObj );
					
					if ( pDrawObj )
					{
						// Получить тип объекта
						long type = pDrawObj->GetDrawingObjectType();
						// Получить референс объекта
						reference objRef = pDrawObj->Reference;
						// Подсветить объект
						LightObj( objRef, 1/*включить*/ );

						// В зависимости от типа вывести сообщение для данного типа объектов
						switch( type )
						{
							// Простая линия выноски
							case ksDrLeader:
							{
								ksAPI7::ILeaderPtr leader( pDrawObj );
								GetLeaderPar( leader );
								break;
							}

							// Знак маркировки
							case ksDrMarkerLeader:
							{
								ksAPI7::IMarkLeaderPtr markLeader( pDrawObj );
								GetMarkLeaderPar( markLeader );
								break;
							}

							// Знак клеймения
							case ksDrBrandLeader:
							{
								ksAPI7::IBrandLeaderPtr brandLeader( pDrawObj );
								GetBrandLeaderPar( brandLeader );
								break;
							}

							// Знак изменения
							case ksDrChangeLeader:
							{
								ksAPI7::IChangeLeaderPtr changeLeader( pDrawObj );
								GetChangeLeaderPar( changeLeader );
								break;
							}

							// Обозначение шероховатости
							case ksDrRough:
							{
								ksAPI7::IRoughPtr rough( pDrawObj );
								GetRoughPar( rough );
								break;
							}

							// Обозначение базы
							case ksDrBase:
							{
								ksAPI7::IBasePtr base( pDrawObj );
								GetBasePar( base );
								break;
							}

							// Линия разреза/сечения
							case ksDrCut:
							{
								ksAPI7::ICutLinePtr cutLine( pDrawObj );
								GetCutLinePar( cutLine );
								break;
							}

							// Стрелка направления взгляда
							case ksDrWPointer:
							{
								ksAPI7::IViewPointerPtr viewPointer( pDrawObj );
								GetViewPointerPar( viewPointer );
								break;
							}

							// Допуск формы
							case ksDrTolerance:
							{
								ksAPI7::ITolerancePtr tolerance( pDrawObj );
								GetTolerancePar( tolerance );
								break;
							}
						}
						// Убрать подсветку
						LightObj( objRef, 0/*выключить*/ );
					} 
				}
				// SafeArrayGetElement делает AddRef. Освободить
				if ( pObj )
					pObj->Release();
				pObj = NULL;
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
	LoadString( Step3_API7_2DDLL.hModule, strID, temp, _MAX_PATH ); 
	return temp;
}


