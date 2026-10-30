////////////////////////////////////////////////////////////////////////////////
//
// Step3_API7_3D.cpp - Библиотека на Visual C++
//
//	1: Rough3DWork( doc );				- Создание и редактирование шероховатости 3D
//	2: Base3DWork( doc );					- Создание и редактирование базы 3D
//	3: Leader3DWork( doc );				-	Создание и редактирование линии-выноски 3D
//	4: BrandLeader3DWork( doc );	- Создание и редактирование знака клеймения 3D
//	5: MarkLeader3DWork( doc );		- Создание и редактирование знака маркировки 3D
//	6: Tolerance3DWork( doc );		- Создание и редактирование допуска формы 3D
//
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include <afxdllx.h>
#include "Step3_API7_3D.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


//-------------------------------------------------------------------------------
// Специальная структура используемая в течении инициализации DLL
// ---
static AFX_EXTENSION_MODULE Step3_API7_3DDLL = { NULL, NULL };
HINSTANCE g_hInstance = NULL;
ksAPI7::IApplicationPtr newKompasAPI( NULL );               

void OnProcessDetach();                 // Отключение библиотеки

// Глобальные переменные
int oType = o3d_edge;										// Тип объектов для функции фильтрации


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
		TRACE0("STEP3_API7_3D.AWX Initializing!\n");

		AfxInitExtensionModule(Step3_API7_3DDLL, hInstance);

		new CDynLinkLibrary(Step3_API7_3DDLL);
	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		TRACE0("STEP3_API7_3D.AWX Terminating!\n");
    OnProcessDetach();
		AfxTermExtensionModule(Step3_API7_3DDLL);
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
ksAPI7::IKompasDocument3DPtr GetCurrentDocument()
{
	ksAPI7::IKompasDocument3DPtr doc = NULL;
	
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
void Rough3DWork( ksAPI7::IKompasDocument3DPtr & doc );
void Base3DWork( ksAPI7::IKompasDocument3DPtr & doc );
void Leader3DWork( ksAPI7::IKompasDocument3DPtr & doc );
void BrandLeader3DWork( ksAPI7::IKompasDocument3DPtr & doc );
void MarkLeader3DWork( ksAPI7::IKompasDocument3DPtr & doc );
void Tolerance3DWork( ksAPI7::IKompasDocument3DPtr & doc );


//-------------------------------------------------------------------------------
// Головная функция библиотеки
// ---
void WINAPI LIBRARYENTRY( unsigned int comm )
{
	// Получить текущий документ
	ksAPI7::IKompasDocument3DPtr doc( GetCurrentDocument() );
	
	if ( doc )
	{
		switch ( comm )
		{
			case 1: Rough3DWork( doc );					break;		// Создание и редактирование шероховатости 3D
			case 2:	Base3DWork( doc );					break;		// Создание и редактирование базы 3D
			case 3: Leader3DWork( doc );				break;		// Создание и редактирование линии-выноски 3D
			case 4: BrandLeader3DWork( doc );		break;		// Создание и редактирование знака клеймения 3D
			case 5: MarkLeader3DWork( doc );		break;		// Создание и редактирование знака маркировки 3D
			case 6: Tolerance3DWork( doc );			break;		// Создание и редактирование допуска формы 3D
		}
	}
	else
		MessageT( (LPTSTR)(LPCTSTR)LoadStr(IDS_NODOC) );
}

#pragma warning( disable : 4786 )
//-------------------------------------------------------------------------------
// Получить контейнер обозначений 3D
// ---
ksAPI7::ISymbols3DContainerPtr GetSymbols3DContainer( ksAPI7::IKompasDocument3DPtr & doc )
{
  if ( doc )
  {
     // Получаем контейнер обозначений 3D
    return doc->GetTopPart(); 
  }
  return NULL;
}


//-----------------------------------------------------------------------------
// Функция фильтрации
// ---
BOOL __stdcall  UserFilterProc( IEntity * e)
{
  if( e && (!oType || e->GetType() == oType) )
    return TRUE;
  else
    return FALSE;
}


//-------------------------------------------------------------------------------
// Установить параметры шероховатости
// ---
void SetRoughPars( ksAPI7::IRough3DPtr & rough )
{
	if ( rough )
	{
		// Получить интерфейс параметров шероховатости
		ksAPI7::IRoughParamsPtr roughPars( rough );
		
		if ( roughPars )
		{
			// Признак обработки по контуру
			roughPars->ProcessingByContour = TRUE;
			// Длина линии выноски
			roughPars->LeaderLength = 20;
			// Угол наклона линии выноски
			roughPars->LeaderAngle = 45;
			
			// Получить интерфейс текста параметров шероховатости
			ksAPI7::ITextPtr txt1( roughPars->RoughParamText );
			
			if ( txt1 )
				txt1->Str = _T("1");
			
			// Получить интерфейс текста способа обработки поверхности
			ksAPI7::ITextPtr txt2( roughPars->ProcessText );
			
			if ( txt2 )
				txt2->Str = _T("2");
			
			// Получить интерфейс текста базовой длины
			ksAPI7::ITextPtr txt3( roughPars->BaseLengthText );
			
			if ( txt3 )
				txt3->Str = _T("3");
		}
	}
}


//-------------------------------------------------------------------------------
// Создать шероховатость 3D
// ---
bool CreateRough3D( ksAPI7::IRough3DPtr & rough,
									  ksAPI7::IKompasDocument3DPtr & doc )
{
	bool res = false;

	if ( rough )
	{
		// Преобразовать интерфейс документа 3D из API7 в API5
		IDocument3DPtr doc3D( IUnknownPtr(ksTransferInterface( doc, ksAPI3DCom, 0/*любой документ*/ ), false/*AddRef*/) );
		
		if ( doc3D )
		{
			// Указать в документе опорный объект для построения шероховатости
			IEntityPtr baseObj( doc3D->UserSelectEntity(NULL, NULL, (LPTSTR)(LPCTSTR)LoadStr(IDS_OBJ)), false/*AddRef*/ );

			if ( baseObj )
			{
				double x, y, z;
				// Указать точку привязки
				doc3D->UserGetCursor( (LPTSTR)(LPCTSTR)LoadStr(IDS_POINT), &x, &y, &z );

				// Преобразовать интерфейс объекта из API5 в API7
				ksAPI7::IModelObjectPtr mObj( IUnknownPtr(ksTransferInterface(baseObj, ksAPI7Dual, 0), false/*AddRef*/) );

				if ( mObj )
					// Установить привязку шероховатости
					rough->SetBasePosition( x, y, z, mObj );

				// Задать базовую плоскость
				rough->BasePlane = o3d_planeXOZ;

				// Установить параметры шероховатости
				SetRoughPars( rough );

				// Применить параметры
				rough->Update();
				res = true;
			}
		}
	}
	return res;
}


//-------------------------------------------------------------------------------
// Задать плоскость обозначения по вершине базового объекта
// ---
void SetPosition( ksAPI7::IRough3DPtr & rough, 
								  ksAPI7::IModelObjectPtr & face )
{
	if ( (bool)rough && (bool)face )
	{
		// Преобразовать интерфейс объекта дерева из API7 в API5
		IEntityPtr faceEnt( IUnknownPtr(ksTransferInterface( face, ksAPI3DCom, o3d_entity ), false/*AddRef*/) );

		if ( faceEnt )
		{
			// Получить интерфейс параметров грани
			IFaceDefinitionPtr faceDef( IUnknownPtr(faceEnt->GetDefinition(), false/*AddRef*/) );

			if ( faceDef )
			{
				// Получить коллекцию ребер
				IEdgeCollectionPtr edgeCol( faceDef->EdgeCollection(), false/*AddRef*/ );

				if ( edgeCol )
				{
					// Получить интерфейс параметров ребра
					IEdgeDefinitionPtr edgeDef( edgeCol->First(), false/*AddRef*/ );

					if ( edgeDef )
					{
						// Получить интерфейс параметров вершины
						IVertexDefinitionPtr vertex( edgeDef->GetVertex(TRUE/*начальная вершина*/), false/*AddRef*/ );

						if ( vertex )
						{
							// Преобразовать интерфейс объекта из API5 в API7
							ksAPI7::IModelObjectPtr mObj( IUnknownPtr(ksTransferInterface(vertex, ksAPI7Dual, 0), false/*AddRef*/) );

							if ( mObj )
								// Установить положение плоскости обозначения по найденной вершине
								rough->PositionObject = mObj;
						}
					}
				}
			}
		}
	}
}


//-------------------------------------------------------------------------------
// Получить новое имя объекта
// ---
_bstr_t GetNewName( ksAPI7::IFeature7Ptr & featObj, int strID )
{
	_bstr_t res = _T("");

	if ( featObj )
	{
		// Сформировать новое имя объекта в дереве
		CString newName =	LoadStr( strID );
		CString name = (LPCTSTR)featObj->Name;
		
		int pos = name.Find( _T(':') );
		
		if ( pos > 0 )
			newName += name.Mid( pos + 1 );
		
		res = (LPTSTR)(LPCTSTR)newName;
	}
	return res;
}


//-------------------------------------------------------------------------------
// Редактировать шероховатость 3D
// ---
void EditRough3D( ksAPI7::IRough3DPtr & rough,
								  ksAPI7::IKompasDocument3DPtr & doc )
{
	if ( rough )
	{
		// Получить интерфейс параметров шероховатости
		ksAPI7::IRoughParamsPtr roughPars( rough );

		if ( roughPars )
			// Убрать признак обработки по контуру
			roughPars->ProcessingByContour = FALSE;

		// Получить интерфейс объекта дерева
		ksAPI7::IFeature7Ptr featObj( rough );

		if ( featObj )
		{	
			// Изменить имя объекта в дереве		
			rough->Name = GetNewName( featObj, IDS_ROUGH );
			// Получить базовый объект
			ksAPI7::IModelObjectPtr baseObj( rough->BaseObject );
			// Задать плоскость обозначения по вершине базового объекта
			SetPosition( rough, baseObj );
		}

		// Получить интерфейс свойств цвета объекта
		ksAPI7::IColorParam7Ptr colorPars( rough );

		// Изменить цвет на синий
		if ( colorPars )
			colorPars->Color = RGB( 0, 0, 255 );

		// Применить изменения
		rough->Update();
	}
}


//-------------------------------------------------------------------------------
// Создание и редактирование шероховатости 3D
// ---
void Rough3DWork( ksAPI7::IKompasDocument3DPtr & doc )
{
	// Получить контейнер обозначений 3D
	ksAPI7::ISymbols3DContainerPtr symbCont( GetSymbols3DContainer(doc) );
	
	if ( symbCont )
	{
		// Получить коллекцию шероховатостей 3D
		ksAPI7::IRoughs3DPtr roughsCol( symbCont->GetRoughs3D() );
		
		if ( roughsCol )
		{
			// Добавить новое обозначение шероховатости 3D
			ksAPI7::IRough3DPtr newRough( roughsCol->Add() );
			
			if ( newRough )
			{
				// Создать обозначение шероховатости 3D
				if ( CreateRough3D(newRough, doc) )
				{	
					_bstr_t name = _T("");
					// Получить интерфейс объекта дерева построения
					ksAPI7::IFeature7Ptr feature( newRough );
					
					// Получить имя объекта
					if ( feature )
						name = feature->Name;
					
					if ( YesNoT((LPTSTR)(LPCTSTR)LoadStr(IDS_EDIT)) == 1 )
					{
						// Получить объект из коллекции по имени
						ksAPI7::IRough3DPtr rough( roughsCol->GetRough3D(name) );
						// Редактировать шероховатость
						EditRough3D( rough, doc );
					}
				}
				else
					// Выдать сообщение "Объект не создан"
					MessageT( (LPTSTR)(LPCTSTR)LoadStr(IDS_NOCREATE) );
			}
		}
	}
}


//-------------------------------------------------------------------------------
// Создать обозначение базы
// ---
bool CreateBase3D( ksAPI7::IBase3DPtr & base, 
									 ksAPI7::IKompasDocument3DPtr & doc )
{
	bool res = false;

	if ( base )
	{
		// Преобразовать интерфейс документа 3D из API7 в API5
		IDocument3DPtr doc3D( IUnknownPtr(ksTransferInterface( doc, ksAPI3DCom, 0/*любой документ*/ ), false/*AddRef*/) );
		
		if ( doc3D )
		{
			// Указать в документе опорный объект для построения базы
			IEntityPtr baseObj( doc3D->UserSelectEntity(NULL, NULL, (LPTSTR)(LPCTSTR)LoadStr(IDS_OBJ)), false/*AddRef*/ );
			
			if ( baseObj )
			{
				double x, y, z;
				// Указать точку привязки
				doc3D->UserGetCursor( (LPTSTR)(LPCTSTR)LoadStr(IDS_POINT), &x, &y, &z );
				
				// Преобразовать интерфейс объекта из API5 в API7
				ksAPI7::IModelObjectPtr mObj( IUnknownPtr(ksTransferInterface(baseObj, ksAPI7Dual, 0), false/*AddRef*/) );
				
				if ( mObj )
					// Установить привязку базы
					base->SetBranchBeginPoint( x, y, z, mObj );
				
				// Задать базовую плоскость
				base->BasePlane = o3d_planeXOZ;
				
				// Применить параметры
				base->Update();
				res = true;
			}
		}
	}
	return res;
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
// Редактирование обозначения базы
// ---
void EditBase3D( ksAPI7::IBase3DPtr & base,
								 ksAPI7::IKompasDocument3DPtr & doc)
{
	if ( base )
	{
		// Отменить автосортировку
		base->AutoSorted = FALSE;

		// Получить интерфейс текста обозначения базы
		ksAPI7::ITextPtr txt( base->Text );
		
		if ( txt )
		{
			txt->Str = _T("");
			
			ksAPI7::ITextLinePtr line( txt->Add() );
			
			if ( line )
			{
				// Добавить строку
				AddTextItem( line, _T("A"), ksTItString );
				// Добавить выражение типа суммы (нижний индекс может существовать
				// только в таком выражении
				AddTextItem( line, _T(""), ksTItSBase );
				// Добавить нижний индекс
				AddTextItem( line, _T("1"), ksTItSLowerIndex );
				// Закончить выражение типа суммы
				AddTextItem( line, _T(""), ksTItSEnd );
			}
		}

		// Тип - произвольное положение
		base->DrawType = FALSE;
		double x, y, z;
		// Сместить конечную точку обозначения базы
		base->GetBranchEndPoint( &x, &y, &z );
		base->SetBranchEndPoint( x + 10, y + 10, z );

		// Получить интерфейс объекта дерева
		ksAPI7::IFeature7Ptr featObj( base );

		if ( featObj )
			// Изменить имя объекта в дереве
			base->Name = GetNewName( featObj, IDS_BASE );

		// Получить интерфейс свойств цвета объекта
		ksAPI7::IColorParam7Ptr colorPars( base );
		
		// Изменить цвет на черный
		if ( colorPars )
			colorPars->Color = RGB( 0, 0, 0 );


		base->Update();
	}
}


//-------------------------------------------------------------------------------
// Создание и редактирование обозначения базы
// ---
void Base3DWork( ksAPI7::IKompasDocument3DPtr & doc )
{
	// Получить контейнер обозначений 3D
	ksAPI7::ISymbols3DContainerPtr symbCont( GetSymbols3DContainer(doc) );
	
	if ( symbCont )
	{
		// Получить коллекцию обозначений базы 3D
		ksAPI7::IBases3DPtr basesCol( symbCont->GetBases3D() );
		
		if ( basesCol )
		{
			// Добавить новое обозначение базы 3D
			ksAPI7::IBase3DPtr newBase( basesCol->Add() );
			
			if ( newBase )
			{
				// Создать обозначение базы 3D
				if ( CreateBase3D(newBase, doc) )
				{	
					_bstr_t name = _T("");
					// Получить интерфейс объекта дерева построения
					ksAPI7::IFeature7Ptr feature( newBase );
					
					// Получить имя объекта
					if ( feature )
						name = feature->Name;
					
					if ( YesNoT((LPTSTR)(LPCTSTR)LoadStr(IDS_EDIT)) == 1 )
					{
						// Получить объект из коллекции по имени
						ksAPI7::IBase3DPtr base( basesCol->GetBase3D(name) );
						// Редактировать обозначение базы
						EditBase3D( base, doc );
					}
				}
				else
					// Выдать сообщение "Объект не создан"
					MessageT( (LPTSTR)(LPCTSTR)LoadStr(IDS_NOCREATE) );
			}
		}
	}
}


//-------------------------------------------------------------------------------
// Установить тексты линии-выноски
// ---
void SetLeader3DTexts( ksAPI7::IBaseLeader3DPtr & baseLeader )
{
	ksAPI7::ILeaderPtr leader( baseLeader );

	if ( leader )
	{
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
	}
}


//-------------------------------------------------------------------------------
// Создать ответвление линии-выноски
// ---
void CreateBranchsLeader( ksAPI7::IBaseLeader3DPtr & leader, 
													ksAPI7::IKompasDocument3DPtr & doc )
{
	if ( (bool)leader && (bool)doc )
	{
		// Преобразовать интерфейс документа 3D из API7 в API5
		IDocument3DPtr doc3D( IUnknownPtr(ksTransferInterface( doc, ksAPI3DCom, 0/*любой документ*/ ), false/*AddRef*/) );
		
		if ( doc3D )
		{
			// Указать в документе опорный объект
			IEntityPtr baseObj( doc3D->UserSelectEntity(NULL, NULL, (LPTSTR)(LPCTSTR)LoadStr(IDS_OBJ)), false/*AddRef*/ );
			
			double x, y, z, x1, y1, z1;
			// Указать точку начала ножки.
			// Точка должна лежать на опорном объекте
			doc3D->UserGetCursor( (LPTSTR)(LPCTSTR)LoadStr(IDS_BEGINBRANCH), &x, &y, &z );
			
			// Указать объект, задающий плоскость обозначения
			IEntityPtr posObj( doc3D->UserSelectEntity(NULL, NULL, (LPTSTR)(LPCTSTR)LoadStr(IDS_POSOBJ)), false/*AddRef*/ );
			
			if ( (bool)baseObj && (bool)posObj )
			{
				// Указать точку, задающую положние объектов
				// Точка должна лежать в плоскости обозначения
				doc3D->UserGetCursor( (LPTSTR)(LPCTSTR)LoadStr(IDS_BEGINSHELF), &x1, &y1, &z1 );
				// Преобразовать интерфейс объекта из API5 в API7
				ksAPI7::IModelObjectPtr mObj1( IUnknownPtr(ksTransferInterface(baseObj, ksAPI7Dual, 0), false/*AddRef*/) );
				ksAPI7::IModelObjectPtr mObj2( IUnknownPtr(ksTransferInterface(posObj, ksAPI7Dual, 0), false/*AddRef*/) );
				
				if ( (bool)mObj1 && (bool)mObj2 )
				{	
					// Получить интерфейс ответвлений
					ksAPI7::IBranchs3DPtr branchs3D( leader );
					
					// Добавить ответвление
					if ( branchs3D )
						branchs3D->AddBranchByPoint( x, y, z, mObj1 );
					
					// Установить объект, задающий плоскость обозначения
					leader->PositionObject = mObj2;
					leader->SetPosition( x1, y1, z1 );
				}
			}
		}
	}
}


//-------------------------------------------------------------------------------
// Создать линию-выноску
// ---
bool CreateLeader3D( ksAPI7::IBaseLeader3DPtr & leader, 
										 ksAPI7::IKompasDocument3DPtr & doc )
{
	bool res = false;

	if ( leader )
	{
		// Создать ответвления линии-выноски
		CreateBranchsLeader( leader, doc );
		// Установить тексты линии-выноски
		SetLeader3DTexts( leader );
		// Применить параметры
		leader->Update();
		res = true;
	}
	return res;
}


//-------------------------------------------------------------------------------
// Изменить параметры линии-выноски
// ---
void EditLeaderPars( ksAPI7::IBaseLeader3DPtr & baseLeader )
{
	if ( baseLeader )
	{
		ksAPI7::ILeaderPtr leader( baseLeader );

		if ( leader )
		{
			// Тип значка - знак склеивания
			leader->SignType = ksLGlueSign;
			// Включить признак обоработки по контуру
			leader->Arround = TRUE;
			
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
		}
	}
}


//-------------------------------------------------------------------------------
// Добавить прямолинейное ответвление
// ---
void LeaderAddBranch( ksAPI7::IBaseLeader3DPtr & leader, 
											ksAPI7::IKompasDocument3DPtr & doc )
{
	if ( (bool)leader && (bool)doc )
	{
		// Преобразовать интерфейс документа 3D из API7 в API5
		IDocument3DPtr doc3D( IUnknownPtr(ksTransferInterface( doc, ksAPI3DCom, 0/*любой документ*/ ), false/*AddRef*/) );
		
		if ( doc3D )
		{
			// Указать в документе опорный объект
			IEntityPtr baseObj( doc3D->UserSelectEntity(NULL, NULL, (LPTSTR)(LPCTSTR)LoadStr(IDS_OBJ)), false/*AddRef*/ );
			
			double x, y, z;
			// Указать точку начала ножки
			doc3D->UserGetCursor( (LPTSTR)(LPCTSTR)LoadStr(IDS_BEGINBRANCH), &x, &y, &z );
			
			if ( baseObj )
			{
				// Преобразовать интерфейс объекта из API5 в API7
				ksAPI7::IModelObjectPtr mObj( IUnknownPtr(ksTransferInterface(baseObj, ksAPI7Dual, 0), false/*AddRef*/) );
				
				if ( mObj )
				{	
					// Получить интерфейс ответвлений
					ksAPI7::IBranchs3DPtr branchs3D( leader );
					
					// Добавить ответвление
					if ( branchs3D )
						branchs3D->AddBranchByPoint( x, y, z, mObj );
				}
			}
		}
	}
}


//-------------------------------------------------------------------------------
// Редактировать линию-выноску
// ---
void EditLeader3D( ksAPI7::IBaseLeader3DPtr & leader, 
									 ksAPI7::IKompasDocument3DPtr & doc )
{
	if ( leader )
	{
		// Добавить прямолинейное ответвление
		LeaderAddBranch( leader, doc );
		// Изменить параметры линии-выноски
		EditLeaderPars( leader );

		// Получить интерфейс объекта дерева
		ksAPI7::IFeature7Ptr featObj( leader );
		
		if ( featObj )
			// Изменить имя объекта в дереве
			leader->Name = GetNewName( featObj, IDS_LEADER );
		
		// Получить интерфейс свойств цвета объекта
		ksAPI7::IColorParam7Ptr colorPars( leader );
		
		// Изменить цвет на коричневый
		if ( colorPars )
			colorPars->Color = RGB( 123, 40, 0 );

		// Применить изменения
		leader->Update();
	}
}


//-------------------------------------------------------------------------------
// Создание и редактирование линии-выноски 3D
// ---
void Leader3DWork( ksAPI7::IKompasDocument3DPtr & doc )
{
	// Получить контейнер обозначений 3D
	ksAPI7::ISymbols3DContainerPtr symbCont( GetSymbols3DContainer(doc) );
	
	if ( symbCont )
	{
		// Получить коллекцию линий-выносок 3D
		ksAPI7::ILeaders3DPtr leadsCol( symbCont->GetLeaders3D() );
		
		if ( leadsCol )
		{
			// Добавить новую линию-выноску 3D
			ksAPI7::IBaseLeader3DPtr newLeader( leadsCol->Add(o3d_leader3D) );
			
			if ( newLeader )
			{
				// Создать линию-выноску 3D
				if ( CreateLeader3D(newLeader, doc) )
				{	
					_bstr_t name = _T("");
					// Получить интерфейс объекта дерева построения
					ksAPI7::IFeature7Ptr feature( newLeader );
					
					// Получить имя объекта
					if ( feature )
						name = feature->Name;
					
					if ( YesNoT((LPTSTR)(LPCTSTR)LoadStr(IDS_EDIT)) == 1 )
					{
						// Получить объект из коллекции по имени
						ksAPI7::IBaseLeader3DPtr leader( leadsCol->GetLeader3D(name) );
						// Редактировать линию-выноску
						EditLeader3D( leader, doc );
					}
				}
				else
					// Выдать сообщение "Объект не создан"
					MessageT( (LPTSTR)(LPCTSTR)LoadStr(IDS_NOCREATE) );
			}
		}
	}
}


//-------------------------------------------------------------------------------
// Создать знак клеймения 3D
// ---
bool CreateBrandLeader3D( ksAPI7::IBaseLeader3DPtr & baseLeader,
													ksAPI7::IKompasDocument3DPtr & doc )
{
	bool res = false;
	
	if ( (bool)baseLeader && (bool)doc )
	{
		// Создать ответвления
		CreateBranchsLeader( baseLeader, doc );

		// Получить интерфейс знака клеймения
		ksAPI7::IBrandLeaderPtr brandLeader( baseLeader );

		if ( brandLeader )
			// Направление
			brandLeader->Direction = FALSE;
			
		// Применить параметры
		baseLeader->Update();
		res = true;
	}
	return res;
}
 

//-------------------------------------------------------------------------------
// Редактировать знак клеймения
// ---
void EditBrandLeader3D( ksAPI7::IBaseLeader3DPtr & leader, 
												ksAPI7::IKompasDocument3DPtr & doc )
{
	if ( (bool)leader && (bool)doc )
	{
		// Добавить прямолинейное ответвление
		LeaderAddBranch( leader, doc );

		// Установить параметры знака клеймения
		ksAPI7::IBrandLeaderPtr brandLeader( leader );
		
		if ( brandLeader )
		{
			// Получить интерфейс текста обозначения
			ksAPI7::ITextPtr des( brandLeader->Designation );
			
			if ( des )
				// Изменить текст
				des->Str = (LPTSTR)(LPCTSTR)LoadStr( IDS_MARK2 );
		}

		// Получить интерфейс объекта дерева
		ksAPI7::IFeature7Ptr featObj( leader );
		
		if ( featObj )
			// Изменить имя объекта в дереве
			leader->Name = GetNewName( featObj, IDS_BRAND );
		
		// Получить интерфейс свойств цвета объекта
		ksAPI7::IColorParam7Ptr colorPars( leader );
		
		// Изменить цвет на фиолетовый
		if ( colorPars )
			colorPars->Color = RGB( 128, 0, 128 );

		// Применить изменения
		leader->Update();
	}
}


//-------------------------------------------------------------------------------
// Создание и редактирование знака клеймения
// ---
void BrandLeader3DWork( ksAPI7::IKompasDocument3DPtr & doc )
{
	// Получить контейнер обозначений 3D
	ksAPI7::ISymbols3DContainerPtr symbCont( GetSymbols3DContainer(doc) );
	
	if ( symbCont )
	{
		// Получить коллекцию линий-выносок 3D
		ksAPI7::ILeaders3DPtr leadsCol( symbCont->GetLeaders3D() );
		
		if ( leadsCol )
		{
			// Добавить новый знак клеймения 3D
			ksAPI7::IBaseLeader3DPtr newBrand( leadsCol->Add(o3d_brandLeader3D) );
			
			if ( newBrand )
			{
				// Создать знак клеймения 3D
				if ( CreateBrandLeader3D(newBrand, doc) )
				{	
					_bstr_t name = _T("");
					// Получить интерфейс объекта дерева построения
					ksAPI7::IFeature7Ptr feature( newBrand );
					
					// Получить имя объекта
					if ( feature )
						name = feature->Name;
					
					if ( YesNoT((LPTSTR)(LPCTSTR)LoadStr(IDS_EDIT)) == 1 )
					{
						// Получить объект из коллекции по имени
						ksAPI7::IBaseLeader3DPtr brandLeader( leadsCol->GetLeader3D(name) );
						// Редактировать знак клеймения
						EditBrandLeader3D( brandLeader, doc );
					}
				}
				else
					// Выдать сообщение "Объект не создан"
					MessageT( (LPTSTR)(LPCTSTR)LoadStr(IDS_NOCREATE) );
			}
		}
	}
}


//-------------------------------------------------------------------------------
// Создать знак маркировки
// ---
bool CreateMarkLeader3D( ksAPI7::IBaseLeader3DPtr & baseLeader,
												 ksAPI7::IKompasDocument3DPtr & doc )
{
	bool res = false;

	if ( (bool)baseLeader && (bool)doc )
	{
		// Создать ответвление
		CreateBranchsLeader( baseLeader, doc );

		// Получить интерфейс знака маркировки
		ksAPI7::IMarkLeaderPtr markLeader( baseLeader );

		if ( markLeader )
		{	
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
		}
		// Применить параметры
		baseLeader->Update();
		res = true;
	}
	return res;
}


//-------------------------------------------------------------------------------
// Редактировать знак маркировки
// ---
void EditMarkLeader3D( ksAPI7::IBaseLeader3DPtr & baseLeader,
											 ksAPI7::IKompasDocument3DPtr & doc )
{
	if ( (bool)baseLeader && (bool)doc )
	{
		// Добавить прямолинейное ответвление
		LeaderAddBranch( baseLeader, doc );

		// Получить интерфейс знака маркировки
		ksAPI7::IMarkLeaderPtr markLeader( baseLeader );
		
		if ( markLeader )
		{
			// Получить интерфейс текста обозначения
			ksAPI7::ITextPtr des( markLeader->Designation );
			
			if ( des )
				// Изменить текст
				des->Str = _T("10");
		}

		// Получить интерфейс объекта дерева
		ksAPI7::IFeature7Ptr featObj( baseLeader );
		
		if ( featObj )
			// Изменить имя объекта в дереве
			baseLeader->Name = GetNewName( featObj, IDS_MARK );
		
		// Получить интерфейс свойств цвета объекта
		ksAPI7::IColorParam7Ptr colorPars( baseLeader );
		
		// Изменить цвет на сиреневый
		if ( colorPars )
			colorPars->Color = RGB( 204, 153, 255 );
		
		// Применить изменения
		baseLeader->Update();
	}
}


//-------------------------------------------------------------------------------
// Создание и редактирование знака маркировки 3D
// ---
void MarkLeader3DWork( ksAPI7::IKompasDocument3DPtr & doc )
{
	// Получить контейнер обозначений 3D
	ksAPI7::ISymbols3DContainerPtr symbCont( GetSymbols3DContainer(doc) );
	
	if ( symbCont )
	{
		// Получить коллекцию линий-выносок 3D
		ksAPI7::ILeaders3DPtr leadsCol( symbCont->GetLeaders3D() );
		
		if ( leadsCol )
		{
			// Добавить новый знак маркировки 3D
			ksAPI7::IBaseLeader3DPtr newMark( leadsCol->Add(o3d_markLeader3D) );
			
			if ( newMark )
			{
				// Создать знак маркировки 3D
				if ( CreateMarkLeader3D(newMark, doc) )
				{	
					_bstr_t name = _T("");
					// Получить интерфейс объекта дерева построения
					ksAPI7::IFeature7Ptr feature( newMark );
					
					// Получить имя объекта
					if ( feature )
						name = feature->Name;
					
					if ( YesNoT((LPTSTR)(LPCTSTR)LoadStr(IDS_EDIT)) == 1 )
					{
						// Получить объект из коллекции по имени
						ksAPI7::IBaseLeader3DPtr markLeader( leadsCol->GetLeader3D(name) );
						// Редактировать знак маркировки
						EditMarkLeader3D( markLeader, doc );
					}
				}
				else
					// Выдать сообщение "Объект не создан"
					MessageT( (LPTSTR)(LPCTSTR)LoadStr(IDS_NOCREATE) );
			}
		}
	}
}


//-------------------------------------------------------------------------------
// Создать ответвление для доопуска формы
// ---
void CreateToleranceBranch( ksAPI7::ITolerance3DPtr & tolerance, 
														ksAPI7::IKompasDocument3DPtr & doc )
{
	if ( (bool)tolerance && (bool)doc )
	{
		// Преобразовать интерфейс документа 3D из API7 в API5
		IDocument3DPtr doc3D( IUnknownPtr(ksTransferInterface( doc, ksAPI3DCom, 0/*любой документ*/ ), false/*AddRef*/) );
		
		if ( doc3D )
		{
			// Указать в документе объект, на который будет указывать ножка
			IEntityPtr baseObj( doc3D->UserSelectEntity(NULL, NULL, (LPTSTR)(LPCTSTR)LoadStr(IDS_OBJ)), false/*AddRef*/ );
			
			double x, y, z, x1, y1, z1;
			// Указать точку конца ножки
			// Точка должна лежать на опорном объекте
			doc3D->UserGetCursor( (LPTSTR)(LPCTSTR)LoadStr(IDS_ENDPOINT), &x, &y, &z );
			
			// Указать объект, задающий плоскость обозначения
			IEntityPtr posObj( doc3D->UserSelectEntity(NULL, NULL, (LPTSTR)(LPCTSTR)LoadStr(IDS_POSOBJ)), false/*AddRef*/ );
			
			if ( (bool)baseObj && (bool)posObj )
			{
				// Указать точку вставки таблицы
				doc3D->UserGetCursor( (LPTSTR)(LPCTSTR)LoadStr(IDS_TABLE), &x1, &y1, &z1 );
				// Преобразовать интерфейс объекта из API5 в API7
				ksAPI7::IModelObjectPtr mObj1( IUnknownPtr(ksTransferInterface(baseObj, ksAPI7Dual, 0), false/*AddRef*/) );
				ksAPI7::IModelObjectPtr mObj2( IUnknownPtr(ksTransferInterface(posObj, ksAPI7Dual, 0), false/*AddRef*/) );
				
				if ( (bool)mObj1 && (bool)mObj2 )
				{	
					// Получить интерфейс ответвлений
					ksAPI7::IBranchs3DPtr branchs3D( tolerance );
					
					// Добавить ответвление
					if ( branchs3D )
						branchs3D->AddBranchByPoint( x, y, z, mObj1 );
					
					// Установить объект, задающий плоскость обозначения
					tolerance->PositionObject = mObj2;
					// Установить точку, задающую положение объекта
					tolerance->SetPosition( x1, y1, z1 );
				}
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
// Создать допуск формы
// ---
bool CreateTolerance3D( ksAPI7::ITolerance3DPtr & tolerance, 
											  ksAPI7::IKompasDocument3DPtr & doc )
{
	bool res = false;

	if ( (bool)tolerance && (bool)doc )
	{
		// Создать ответвление
		CreateToleranceBranch( tolerance, doc );
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
		// Применить параметры
		tolerance->Update();
		res = true;
	}
	return res;
}


//-------------------------------------------------------------------------------
// Добавить ответвление для допуска формы
// ---
void ToleranceAddBranch( ksAPI7::ITolerance3DPtr & tolerance, 
												 ksAPI7::IKompasDocument3DPtr & doc )
{
	if ( (bool)tolerance && (bool)doc )
	{
		// Преобразовать интерфейс документа 3D из API7 в API5
		IDocument3DPtr doc3D( IUnknownPtr(ksTransferInterface( doc, ksAPI3DCom, 0/*любой документ*/ ), false/*AddRef*/) );
		
		if ( doc3D )
		{
			// Указать в документе объект, на который будет указывать ножка линии-выноски
			IEntityPtr baseObj( doc3D->UserSelectEntity(NULL, NULL, (LPTSTR)(LPCTSTR)LoadStr(IDS_OBJ)), false/*AddRef*/ );
			
			double x, y, z;
			// Указать точку конца ответвления
      // Точка должна лежать на опорном объекте
			doc3D->UserGetCursor( (LPTSTR)(LPCTSTR)LoadStr(IDS_ENDPOINT), &x, &y, &z );
			
			if ( baseObj )
			{
				// Преобразовать интерфейс объекта из API5 в API7
				ksAPI7::IModelObjectPtr mObj( IUnknownPtr(ksTransferInterface(baseObj, ksAPI7Dual, 0), false/*AddRef*/) );
				
				if ( mObj )
				{	
					// Получить интерфейс ответвлений
					ksAPI7::IBranchs3DPtr branchs3D( tolerance );
					
					// Добавить ответвление
					if ( branchs3D )
						branchs3D->AddBranchByPoint( x, y, z, mObj );

					// Ответвление со стрелкой
					tolerance->PutArrowType( 1, TRUE );
				}
			}
		}
	}
}


//-------------------------------------------------------------------------------
// Редактировать допуск формы
// ---
void EditTolerance3D( ksAPI7::ITolerance3DPtr & tolerance, 
											ksAPI7::IKompasDocument3DPtr & doc )
{
	if ( (bool)tolerance && (bool)doc )
	{
		ToleranceAddBranch( tolerance, doc );

		// Получитьинтерфейс параметров допуска формы
		ksAPI7::IToleranceParamPtr tolPar( tolerance );

		if ( tolPar )
		{
			// Задать признак вертикальности
			tolPar->Vertical = TRUE;
			// Положение базовой точки относительно таблицы - слева посередине
			tolPar->BasePointPos = ksTPLeftBottom;
		}

		// Получить интерфейс объекта дерева
		ksAPI7::IFeature7Ptr featObj( tolerance );
		
		if ( featObj )
			// Изменить имя объекта в дереве
			tolerance->Name = GetNewName( featObj, IDS_TOLERANCE );
		
		// Получить интерфейс свойств цвета объекта
		ksAPI7::IColorParam7Ptr colorPars( tolerance );
		
		// Изменить цвет на темно-красный
		if ( colorPars )
			colorPars->Color = RGB( 186, 12, 34 );

		// Применить изменения
		tolerance->Update();
	}
}


//-------------------------------------------------------------------------------
// Создание и редактирование допуска формы 3D
// ---
void Tolerance3DWork( ksAPI7::IKompasDocument3DPtr & doc )
{
	// Получить контейнер обозначений 3D
	ksAPI7::ISymbols3DContainerPtr symbCont( GetSymbols3DContainer(doc) );
	
	if ( symbCont )
	{
		// Получить коллекцию допусков формы 3D
		ksAPI7::ITolerances3DPtr tolerCol( symbCont->GetTolerances3D() );
		
		if ( tolerCol )
		{
			// Добавить новый допуск формы 3D
			ksAPI7::ITolerance3DPtr newTolerance( tolerCol->Add() );
			
			if ( newTolerance )
			{
				// Создать допуск формы 3D
				if ( CreateTolerance3D(newTolerance, doc) )
				{	
					_bstr_t name = _T("");
					// Получить интерфейс объекта дерева построения
					ksAPI7::IFeature7Ptr feature( newTolerance );
					
					// Получить имя объекта
					if ( feature )
						name = feature->Name;
					
					if ( YesNoT((LPTSTR)(LPCTSTR)LoadStr(IDS_EDIT)) == 1 )
					{
						// Получить объект из коллекции по имени
						ksAPI7::ITolerance3DPtr tolerance( tolerCol->GetTolerance3D(name) );
						// Редактировать допуск формы
						EditTolerance3D( tolerance, doc );
					}
				}
				else
					// Выдать сообщение "Объект не создан"
					MessageT( (LPTSTR)(LPCTSTR)LoadStr(IDS_NOCREATE) );
			}
		}
	}
}

#pragma warning( once : 4786 ) 
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
	LoadString( Step3_API7_3DDLL.hModule, strID, temp, _MAX_PATH ); 
	return temp;
}


