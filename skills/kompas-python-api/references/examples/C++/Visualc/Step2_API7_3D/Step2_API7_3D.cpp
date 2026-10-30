////////////////////////////////////////////////////////////////////////////////
//
// Step2_API7_3D.cpp - Размеры 3D
//
//	1: CreateLineDimension3D( doc );				- Создание линейного размера 3D 
//	2: LineDimension3DNavigation( doc );		- Навигация по коллекции линейных размеров 3D
//	3: EditLineDimension3D( doc );					- Редактирование линейного размера 3D
//	4: RadialDimension3DWork( doc );				- Создание и редактирование радиального размера 3D
//	5: DiametralDimension3DWork( doc );			- Создание и редактирование диаметрального размера 3D
//	6: AngleDimension3DWork( doc );					- Создание и редактирование углового размера 3D
//
////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include <afxdllx.h>
#include "Step2_API7_3D.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


//-------------------------------------------------------------------------------
// Специальная структура используемая в течении инициализации DLL
// ---
static AFX_EXTENSION_MODULE Step2_API7_3DDLL = { NULL, NULL };
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
		TRACE0("STEP2_API7_3D.AWX Initializing!\n");

		AfxInitExtensionModule(Step2_API7_3DDLL, hInstance);

		new CDynLinkLibrary(Step2_API7_3DDLL);
	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		TRACE0("STEP2_API7_3D.AWX Terminating!\n");
    OnProcessDetach();
		AfxTermExtensionModule(Step2_API7_3DDLL);
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
void CreateLineDimension3D( ksAPI7::IKompasDocument3DPtr & doc );
void LineDimension3DNavigation( ksAPI7::IKompasDocument3DPtr & doc );
void EditLineDimension3D( ksAPI7::IKompasDocument3DPtr & doc );
void RadialDimension3DWork( ksAPI7::IKompasDocument3DPtr & doc );
void DiametralDimension3DWork( ksAPI7::IKompasDocument3DPtr & doc );
void AngleDimension3DWork( ksAPI7::IKompasDocument3DPtr & doc );


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
			case 1: CreateLineDimension3D( doc );				break;		// Создание линейного размера 3D 
			case 2: LineDimension3DNavigation( doc );		break;		// Навигация по коллекции линейных размеров 3D
			case 3: EditLineDimension3D( doc );					break;		// Редактирование линейного размера 3D
			case 4: RadialDimension3DWork( doc );				break;		// Создание и редактирование радиального размера 3D
			case 5: DiametralDimension3DWork( doc );		break;		// Создание и редактирование диаметрального размера 3D
			case 6: AngleDimension3DWork( doc );				break;		// Создание и редактирование углового размера 3D
		}
	}
	else
		MessageT( (LPTSTR)(LPCTSTR)LoadStr(IDS_NODOC) );
}


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
// Установить объект привязки и базовую плоскость
// ---
bool SetLineDimObjectPlane( ksAPI7::ILineDimension3DPtr & dim, 
														ksAPI7::IKompasDocument3DPtr & doc )
{
	bool res = false;
	// Фильтрация объектов - ребра
	oType = o3d_edge;

	// Преобразовать интерфейс документа 3D из API7 в API5
	IDocument3DPtr doc3D( IUnknownPtr(ksTransferInterface( doc, ksAPI3DCom, 0/*любой документ*/ ), false/*AddRef*/) );
	
	if ( doc3D )
	{
		// Указать в документе объект - ребро
		IEntityPtr obj1( doc3D->UserSelectEntity(NULL, UserFilterProc, (LPTSTR)(LPCTSTR)LoadStr(IDS_OBJ1)), false/*AddRef*/ );

		if ( obj1 )
		{
			// Тип фильтрации - грани
			oType = o3d_face;
			// Указать в документе объект - грань
			IEntityPtr plane( doc3D->UserSelectEntity(NULL, UserFilterProc, (LPTSTR)(LPCTSTR)LoadStr(IDS_PLANE)), false/*AddRef*/ );

			if ( plane )
			{
				// Преобразовать интерфейсы ребра и грани из API5 в API7
				ksAPI7::IModelObjectPtr mObj1( IUnknownPtr(ksTransferInterface( obj1, ksAPI7Dual, 0 ), false/*AddRef*/) );
				ksAPI7::IModelObjectPtr mPlane( IUnknownPtr(ksTransferInterface( plane, ksAPI7Dual, 0 ), false/*AddRef*/) );
				
				if ( (bool)mObj1 && (bool)mPlane && (bool)dim )
				{
					// Установить первый объект размера (Второй объект устанавливается 
					// только в том случае, если измеряется расстояние между точками)
					dim->Object1 = mObj1;
					// Установить базовую плоскость размера
					dim->Plane = mPlane;
					res = TRUE;
				}
			}
		}
	}
	return res;
}


//-------------------------------------------------------------------------------
// Создание линейного размера 3D
// ---
void CreateLineDimension3D( ksAPI7::IKompasDocument3DPtr & doc )
{
	// Получить контейнер обозначений 3D
	ksAPI7::ISymbols3DContainerPtr symbCont( GetSymbols3DContainer(doc) );

	if ( symbCont )
	{
		// Получить коллекцию линейных размеров 3D
		ksAPI7::ILineDimensions3DPtr dimsCol( symbCont->GetLineDimensions3D() );

		if ( dimsCol )
		{
			// Добавить новый линейный размер 3D
			ksAPI7::ILineDimension3DPtr newDim( dimsCol->Add(o3d_lineDimension3D) );

			if ( newDim )
			{
				bool create = false;

				// Если удалось установить объект привязки и базовую плоскость
				if ( SetLineDimObjectPlane(newDim, doc) )
				{
					// Установить длину размера
					newDim->Length = 30;
					// Применить параметры
					create = (bool)!!newDim->Update();		
					
				}
				else
					// Выдать сообщение "Объект не создан"
					MessageT( (LPTSTR)(LPCTSTR)LoadStr(IDS_NOCREATE) );
				// Если объект не создался, удалить
				if ( !create )
				{
					ksAPI7::IFeature7Ptr obj( newDim );
					
					if ( obj )
						obj->Delete();
				}
			}
		}
	}
}


//-------------------------------------------------------------------------------
// Выдать сообщение с параметрами линейного размера 3D
// ---
void GetLineDimensionPar( ksAPI7::ILineDimension3DPtr & dim )
{
	if ( dim )
	{
		// Получить длину размера
		double lenght = dim->Length;
		double val = 0;

		// Получить значение размера
		ksAPI7::IDimensionTextPtr dimText( dim );

		if ( dimText )
			val = dimText->NominalValue;

		// Сформировать сообщение
		TCHAR buf[255], buf2[255];
		_tcscpy_s( buf, (LPTSTR)(LPCTSTR)LoadStr(IDS_LINEDIM3D) );	
		_stprintf_s( buf2, (LPTSTR)(LPCTSTR)LoadStr(IDS_LENGTH), lenght );
		_tcscat_s( buf, buf2 );
		_stprintf_s( buf2, (LPTSTR)(LPCTSTR)LoadStr(IDS_DIMVAL), val );
		_tcscat_s( buf, buf2 );
		MessageT( buf );
	}
}


//-------------------------------------------------------------------------------
// Навигация по коллекции линейных размеров 3D
// ---
void LineDimension3DNavigation( ksAPI7::IKompasDocument3DPtr & doc )
{
	if ( doc )
	{
		// Получить контейнер обозначений 3D
		ksAPI7::ISymbols3DContainerPtr symbCont( GetSymbols3DContainer(doc) );
		
		if ( symbCont )
		{
			// Получить коллекцию линейных размеров 3D
			ksAPI7::ILineDimensions3DPtr dimsCol( symbCont->GetLineDimensions3D() );
			// Преобразовать интерфейс документа 3D из API7 в API5
			IDocument3DPtr doc3D( IUnknownPtr(ksTransferInterface( doc, ksAPI3DCom, 0/*любой документ*/ ), false/*AddRef*/) );
			
			if ( doc3D )
			{
				// Получить менеджер селектирования
				ISelectionMngPtr selectMng( doc3D->GetSelectionMng() );

				if ( (bool)dimsCol && (bool)selectMng )
				{
					// Цикл по коллекции 
					for ( long i = 0; i < dimsCol->Count; i++ )
					{	
						// Получить размер из коллекции по индексу
						ksAPI7::ILineDimension3DPtr lineDim( dimsCol->GetLineDimension3D(i) );

						if ( lineDim )
						{
							// Преобразовать интерфейс объекта 3D из API7 в API5
							IEntityPtr dimObj( IUnknownPtr(ksTransferInterface( lineDim, ksAPI3DCom, o3d_entity ), false/*AddRef*/) );

							if ( dimObj )
							{
								// Подсветить объект
								selectMng->Select( dimObj );
								// Выдать сообщение с параметрами размера
								GetLineDimensionPar( lineDim );
								// Убрать подсветку
								selectMng->Unselect( dimObj );
							}
						}
					}
				}
			}
		}
	}
}


//-------------------------------------------------------------------------------
// Установить новую базовую плоскость
// ---
bool SetNewPlane( ksAPI7::ILineDimension3DPtr & dim, IDocument3DPtr & doc3D )
{
	bool res = false;

	if ( (bool)dim && (bool)doc3D )
	{
		oType = o3d_face;
		// Указать в документе объект
		IEntityPtr obj1( doc3D->UserSelectEntity(NULL, UserFilterProc, (LPTSTR)(LPCTSTR)LoadStr(IDS_NEWPLANE)), false/*AddRef*/ );

		if ( obj1 )
		{
			// Преобразовать интерфейс объекта из API5 в API7
			ksAPI7::IModelObjectPtr plane( IUnknownPtr(ksTransferInterface( obj1, ksAPI7Dual, 0 ), false/*AddRef*/) );

			if ( plane )
			{
				// Установить базовую плоскость
				dim->Plane = plane;
				res = true;
			}
		}
	}
	return res;
}


//-------------------------------------------------------------------------------
// Изменить параметры линейного размера 3D
// ---
void ChangeLineDimensionPar( ksAPI7::ILineDimension3DPtr & dim )
{
	if ( dim )
	{
		// Получить интерфейс параметров размера
		ksAPI7::IDimensionParamsPtr dimPars( dim );

		if ( dimPars )
		{
			// Тип стрелок - засечка
			dimPars->ArrowType1 = ksNotch;
			dimPars->ArrowType2 = ksNotch;
			// Расположение стрелок - снаружи
			dimPars->ArrowPos = ksDimArrowOutside;
			// Направление полки - вправо
			dimPars->ShelfDirection = ksLSRight;
			// Длина полки
			dimPars->ShelfLength = 10;
			// Угол наклона полки
			dimPars->ShelfAngle = 45;
		}
	}
}


//-------------------------------------------------------------------------------
// Редактирование линейного размера 3D
// ---
void EditLineDimension3D( ksAPI7::IKompasDocument3DPtr & doc )
{
	if ( doc )
	{
		// Преобразовать интерфейс документа 3D из API7 в API5
		IDocument3DPtr doc3D( IUnknownPtr(ksTransferInterface( doc, ksAPI3DCom, 0/*любой документ*/ ), false/*AddRef*/) );

		if ( doc3D )
		{
			oType = o3d_entity;
			// Указать в документе объект
			IEntityPtr obj1( doc3D->UserSelectEntity(NULL, NULL, (LPTSTR)(LPCTSTR)LoadStr(IDS_DIM)), false/*AddRef*/ );

			if ( obj1 )
			{
				// Преобразовать интерфейс объекта из API5 в API7
				ksAPI7::IModelObjectPtr mObj1( IUnknownPtr(ksTransferInterface( obj1, ksAPI7Dual, 0 ), false/*AddRef*/) );

				if ( (bool)mObj1 && mObj1->ModelObjectType == o3d_lineDimension3D )
				{
					// Получить интерфейс линейного размера 3D
					ksAPI7::ILineDimension3DPtr lineDim( mObj1 );

					if ( lineDim )
					{
						// Установить новую базовую плоскость
						if ( !SetNewPlane(lineDim, doc3D) )
							// Выдать сообщение "Не удалось установить новую базовую плоскость"
							MessageT( (LPTSTR)(LPCTSTR)LoadStr(IDS_NOTSETPLANE) );

						// Изменить параметры размера
						ChangeLineDimensionPar( lineDim );
						// Уменьшить длину размера
						lineDim->Length = lineDim->Length - 10;
						// Применить изменения
						lineDim->Update();
					}
				}
				else
					// Выдать сообщение "Объект не является линейным размером"
					MessageT( (LPTSTR)(LPCTSTR)LoadStr(IDS_NOTDIM) );
			}
		}
	}
}


//-------------------------------------------------------------------------------
// Создать радиальный размер 3D
// ---
bool CreateRadDimension3D( ksAPI7::IRadialDimension3DPtr & dim,
													 ksAPI7::IKompasDocument3DPtr & doc )
{
	bool res = false;

	if ( dim )
	{
		// Преобразовать интерфейс документа 3D из API7 в API5
		IDocument3DPtr doc3D( IUnknownPtr(ksTransferInterface( doc, ksAPI3DCom, 0/*любой документ*/ ), false/*AddRef*/) );

		if ( doc3D )
		{
			oType = o3d_edge;
			// Указать в документе объект - ребро
			IEntityPtr edge( doc3D->UserSelectEntity(NULL, UserFilterProc, (LPTSTR)(LPCTSTR)LoadStr(IDS_OBJ1)), false/*AddRef*/ );

			if ( edge )
			{
				// Получить интерфейс свойств ребра
				IEdgeDefinitionPtr edgeDef( edge->GetDefinition() );

				// Проверить, является ли ребро круговым
				if ( (bool)edgeDef && edgeDef->IsCircle() )
				{
					// Преобразовать интерфейс объекта из API5 в API7
					ksAPI7::IModelObjectPtr mObj1( IUnknownPtr(ksTransferInterface( edge, ksAPI7Dual, 0 ), false/*AddRef*/) );

					if ( mObj1 )
						// Установить объект
						dim->Object1 = mObj1;

					// Получить интерфейс параметров объекта
					ksAPI7::IDimensionParamsPtr dimPars( dim );

					if ( dimPars )
					{
						// Направление полки - влево
						dimPars->ShelfDirection = ksLSLeft;
						// Длина полки
						dimPars->ShelfLength = 15;
						// Угол наклона полки
						dimPars->ShelfAngle = 30;
					}

					// Тип размера - не от центра
					dim->DimensionType = FALSE;
					// Применить параметры
					dim->Update();
					res = true;
				}
				else
					// Выдать сообщение "Ребро не является круговым"
					MessageT( (LPTSTR)(LPCTSTR)LoadStr(IDS_NOTCIRCLE) );
			}
		}
	}
	return res;
} 


//-------------------------------------------------------------------------------
// Редактировать радиальный размер 3D
// ---
void EditRadDimension3D( ksAPI7::IRadialDimension3DPtr & dim )
{
	if ( dim )
	{
		// Тип размера - от центра
		dim->DimensionType = TRUE;

		// Получить интерфейс параметров размера
		ksAPI7::IDimensionParamsPtr dimPars( dim );

		if ( dimPars )
			// Отключить полку
			dimPars->ShelfDirection = ksLSNone;

		// Получить интерфейс текстов размера
		ksAPI7::IDimensionTextPtr dimText( dim );

		if ( dimText )
		{
			// Задать квалитет
			dimText->Tolerance = _T("h6");

			// Включить квалитет
			dimText->ToleranceOn = TRUE;

			// Получить интерфейс текста нижнего отклонения
			ksAPI7::ITextLinePtr lowDev( dimText->LowDeviation );
			
			// Задать текстовую строку
			if ( lowDev )
				lowDev->Str = _T("+0.021");
		}
		// Применить изменения
		dim->Update();
	}
}


//-------------------------------------------------------------------------------
// Создание и редактирование радиального размера 3D
// ---
void RadialDimension3DWork( ksAPI7::IKompasDocument3DPtr & doc )
{
	// Получить контейнер обозначений 3D
	ksAPI7::ISymbols3DContainerPtr symbCont( GetSymbols3DContainer(doc) );

	if ( symbCont )
	{
		// Получить коллекцию радиальных размеров 3D
		ksAPI7::IRadialDimensions3DPtr dimsCol( symbCont->GetRadialDimensions3D() );

		if ( dimsCol )
		{
			// Добавить новый радиальный размер 3D
			ksAPI7::IRadialDimension3DPtr newDim( dimsCol->Add() );

			if ( newDim )
			{
				// Создать радиальный размер 3D
				if ( CreateRadDimension3D(newDim, doc) )
				{	
					_bstr_t name = _T("");
					// Получить интерфейс объекта дерева построения
					ksAPI7::IFeature7Ptr feature( newDim );
          				
					// Получить имя объекта
					if ( feature )
						name = feature->Name;

					if ( YesNoT((LPTSTR)(LPCTSTR)LoadStr(IDS_EDIT)) == 1 )
					{
						// Получить объект из коллекции по имени
						ksAPI7::IRadialDimension3DPtr radDim( dimsCol->GetRadialDimension3D(name) );
						// Редактировать размер
						EditRadDimension3D( radDim );
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
// Создать димаметральный размер
// ---
bool CreateDiamDimension3D( ksAPI7::IDiametralDimension3DPtr & dim,
														ksAPI7::IKompasDocument3DPtr & doc )
{
	bool res = false;
	
	if ( dim )
	{
		// Преобразовать интерфейс документа 3D из API7 в API5
		IDocument3DPtr doc3D( IUnknownPtr(ksTransferInterface( doc, ksAPI3DCom, 0/*любой документ*/ ), false/*AddRef*/) );
		
		if ( doc3D )
		{
			oType = o3d_edge;
			// Указать в документе объект - ребро
			IEntityPtr edge( doc3D->UserSelectEntity(NULL, UserFilterProc, (LPTSTR)(LPCTSTR)LoadStr(IDS_OBJ1)), false/*AddRef*/ );
			
			if ( edge )
			{
				// Получить интерфейс свойств ребра
				IEdgeDefinitionPtr edgeDef( edge->GetDefinition() );
				
				// Проверить, является ли ребро круговым
				if ( (bool)edgeDef && edgeDef->IsCircle() )
				{
					// Преобразовать интерфейс объекта из API5 в API7
					ksAPI7::IModelObjectPtr mObj1( IUnknownPtr(ksTransferInterface( edge, ksAPI7Dual, 0 ), false/*AddRef*/) );
					
					if ( mObj1 )
						// Установить объект
						dim->Object1 = mObj1;
					
					// Применить параметры
					dim->Update();
					res = true;
				}
				else
					// Выдать сообщение "Ребро не является круговым"
					MessageT( (LPTSTR)(LPCTSTR)LoadStr(IDS_NOTCIRCLE) );
			}
		}
	}
	return res;
}


//-------------------------------------------------------------------------------
// Редактировать диаметральный размер
// ---
void EditDiamDimension3D( ksAPI7::IDiametralDimension3DPtr & dim )
{
	if ( dim )
	{
		// Тип размера - с обрывом
		dim->DimensionType = TRUE;

		// Получить интерфейс текстов размера
		ksAPI7::IDimensionTextPtr dimText( dim );

		if ( dimText )
		{
			// Получить интерфейс текста под размерной надписью
			ksAPI7::ITextPtr txtUnder( dimText->TextUnder );
			
			// Задать текстовую строку
			if ( txtUnder )
				txtUnder->Str = (LPTSTR)(LPCTSTR)LoadStr( IDS_DIMTEXT );

			// Подчеркнутый текст
			dimText->Underline = TRUE;
		}
		// Применить изменения
		dim->Update();
	}
}


//-------------------------------------------------------------------------------
// Создание и редактирование диаметрального размера 3D
// ---
void DiametralDimension3DWork( ksAPI7::IKompasDocument3DPtr & doc )
{
	// Получить контейнер обозначений 3D
	ksAPI7::ISymbols3DContainerPtr symbCont( GetSymbols3DContainer(doc) );
	
	if ( symbCont )
	{
		// Получить коллекцию диаметральных размеров 3D
		ksAPI7::IDiametralDimensions3DPtr dimsCol( symbCont->GetDiametralDimensions3D() );
		
		if ( dimsCol )
		{
			// Добавить новый диаметральный размер 3D
			ksAPI7::IDiametralDimension3DPtr newDim( dimsCol->Add() );
			
			if ( newDim )
			{
				// Создать диаметральный размер 3D
				if ( CreateDiamDimension3D(newDim, doc) )
				{	
					_bstr_t name = _T("");
					// Получить интерфейс объекта дерева построения
					ksAPI7::IFeature7Ptr feature( newDim );
					
					// Получить имя объекта
					if ( feature )
						name = feature->Name;
					
					if ( YesNoT((LPTSTR)(LPCTSTR)LoadStr(IDS_EDIT)) == 1 )
					{
						// Получить объект из коллекции по имени
						ksAPI7::IDiametralDimension3DPtr diamDim( dimsCol->GetDiametralDimension3D(name) );
						// Редактировать размер
						EditDiamDimension3D( diamDim );
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
// Создать угловой размер 3D
// ---
bool CreateAngleDimension3D( ksAPI7::IAngleDimension3DPtr & dim,
														 ksAPI7::IKompasDocument3DPtr & doc )
{
	bool res = false;

	if ( (bool)dim && (bool)doc )
	{
		// Преобразовать интерфейс документа 3D из API7 в API5
		IDocument3DPtr doc3D( IUnknownPtr(ksTransferInterface( doc, ksAPI3DCom, 0/*любой документ*/ ), false/*AddRef*/) );
		
		if ( doc3D )
		{
			// Указать в документе 1-й объект
			IEntityPtr obj1( doc3D->UserSelectEntity(NULL, NULL, (LPTSTR)(LPCTSTR)LoadStr(IDS_OBJECT1)), false/*AddRef*/ );
			// Указать в документе 2-й объект
			IEntityPtr obj2( doc3D->UserSelectEntity(NULL, NULL, (LPTSTR)(LPCTSTR)LoadStr(IDS_OBJECT2)), false/*AddRef*/ );

			if ( (bool)obj1 && (bool)obj2 )
			{
				// Преобразовать интерфейсы объектов из API5 в API7
				ksAPI7::IModelObjectPtr mObj1( IUnknownPtr(ksTransferInterface( obj1, ksAPI7Dual, 0 ), false/*AddRef*/) );
				ksAPI7::IModelObjectPtr mObj2( IUnknownPtr(ksTransferInterface( obj2, ksAPI7Dual, 0 ), false/*AddRef*/) );

				if ( (bool)mObj1 && (bool)mObj2 )
				{
					// 1-й объект
					dim->Object1 = mObj1;
					// 2-й объект
					dim->Object2 = mObj2;
					// Длина размерной линии
					dim->Length = 20;
					// Применить параметры
					dim->Update();
					res = true;
				}
			}
		}
	}
	return res;
}


//-------------------------------------------------------------------------------
// Редактировать угловой размер 3D
// ---
void EditAngleDimension3D( ksAPI7::IAngleDimension3DPtr & dim )
{
	if ( dim )
	{
		// Тип размера - на максимальный (тупой) угол
		dim->DimensionType = ksADMaxAngle;
		// Увеличить длину размерной линии
		dim->Length = dim->Length + 10;

		// Получить интерфейс параметров размера
		ksAPI7::IDimensionParamsPtr dimPars( dim );

		if ( dimPars )
			// Размещение размерной надписи - параллельно, в разрезе линии
			dimPars->TextOnLine = ksDimTextParallelInCut;

		// Получить интерфейс текстов размера
		ksAPI7::IDimensionTextPtr dimText( dim );

		if ( dimText )
			// Изменить формат отображения текста на десятичный
			dimText->TextFormat = ksDimTextFormatGDD;

		// Применить изменения
		dim->Update();
	}
}


//-------------------------------------------------------------------------------
// Создание и редактирование углового размера 3D
// ---
void AngleDimension3DWork( ksAPI7::IKompasDocument3DPtr & doc )
{
	// Получить контейнер обозначений 3D
	ksAPI7::ISymbols3DContainerPtr symbCont( GetSymbols3DContainer(doc) );
	
	if ( symbCont )
	{
		// Получить коллекцию угловых размеров 3D
		ksAPI7::IAngleDimensions3DPtr dimsCol( symbCont->GetAngleDimensions3D() );
		
		if ( dimsCol )
		{
			// Добавить новый угловой размер 3D
			ksAPI7::IAngleDimension3DPtr newDim( dimsCol->Add() );
			
			if ( newDim )
			{
				// Создать угловой размер 3D
				if ( CreateAngleDimension3D(newDim, doc) )
				{	
					_bstr_t name = _T("");
					// Получить интерфейс объекта дерева построения
					ksAPI7::IFeature7Ptr feature( newDim );
					
					// Получить имя объекта
					if ( feature )
						name = feature->Name;
					
					if ( YesNoT((LPTSTR)(LPCTSTR)LoadStr(IDS_EDIT)) == 1 )
					{
						// Получить объект из коллекции по имени
						ksAPI7::IAngleDimension3DPtr angDim( dimsCol->GetAngleDimension3D(name) );
						// Редактировать размер
						EditAngleDimension3D( angDim );
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
	LoadString( Step2_API7_3DDLL.hModule, strID, temp, _MAX_PATH ); 
	return temp;
}


