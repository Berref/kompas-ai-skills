////////////////////////////////////////////////////////////////////////////////
//
// step3D2.cpp - Работа с компонентой
// 
// 1.  Создание документа                                            - CreateDocument3D 
// 2.  Итератор по документам                                        - DocIterator 
// 3.  Использование массива элементов                               - UseEntityCollection 
// 4.  Взять/изменить имя компоненты                                 - GetSetPartName 
// 5.  Фиксирование и установка стандартного объекта                 - FixAndStandartComponent 
// 6.  Получить и заменить параметры цвета компоненты                - GetSetColorProperty 
// 7.  Взять и поменять внешние переменные компоненты                - GetSetArrayVariable 
// 8.  Получить и изменить место расположения детали в сборке        - GetSetPlacmentComponent 
// 9.  Получить интерфейс ksEntity объекта создаваемого системой 
//     по умолчанию и поменять параметры                             - GetSetEntity 
// 10. Создать эскиз                                                 - CreateSketch 
// 11. Формирует массив объектов( здесь эскизов ) и возвращает его 
//     интерфейс ksEntityCollection( IEntityCollection )             - GetArraySketch 
// 12. Установить и получить параметры пользователя в компоненте     - GetSetUserParamComponent 
//
////////////////////////////////////////////////////////////////////////////////
#include <vcl.h>
#pragma hdrstop

#include <tchar.h>

#include <stdio.h>

#include <objbase.h>
#include <initguid.h>

#include "step3D2.rh"
#include "step3D2.h"

#include "ksConstants.h"

#if !defined(_IFUNC)
# define _IFUNC STDMETHODCALLTYPE
#endif

HINSTANCE _hinst;

//------------------------------------------------------------------------------
// в Win32 линкуется SDK/lib/kAPI2D5bc.lib и kAPI3D5bc.lib
// в x64 линкуется SDK/lib64/kAPI2D5bc.a и kAPI3D5bc.a
// ---
#pragma comment(lib, "kAPI2D5bc")
#pragma comment(lib, "kAPI3D5bc")

//------------------------------------------------------------------------------
// Загрузить строку из ресурса
// ---
LPTSTR _LoadStr( int id )
{
	static TCHAR buf[512];
	// Конвертировать строку в соответствии с текущим словарем
	ksConvertLangStrExT( _hinst, id, buf, 512 );
  return buf;
}


//-------------------------------------------------------------------------------
// Задать идентификатор ресурсов
// ---
extern "C" unsigned int far __export __stdcall LIBRARYID()
{
	return IDR_LIBID;
}


//-------------------------------------------------------------------------------
// Описания используемых функций
// ---
void CreateDocument3D        ();
void DocIterator             ();
void UseEntityCollection     ();
void GetSetPartName          ( Kompas6api3d5com_tlb::IDocument3DPtr & pDocument3d );
void FixAndStandartComponent ( Kompas6api3d5com_tlb::IDocument3DPtr & pDocument3d );
void GetSetColorProperty     ( Kompas6api3d5com_tlb::IDocument3DPtr & pDocument3d );
void GetSetArrayVariable     ( Kompas6api3d5com_tlb::IDocument3DPtr & pDocument3d );
void GetSetPlacmentComponent ( Kompas6api3d5com_tlb::IDocument3DPtr & pDocument3d );
void GetSetEntity            ( Kompas6api3d5com_tlb::IDocument3DPtr & pDocument3d );
void CreateSketch            ( Kompas6api3d5com_tlb::IDocument3DPtr & pDocument3d );
void GetArraySketch          ( Kompas6api3d5com_tlb::IDocument3DPtr & pDocument3d );
void GetSetUserParamComponent( Kompas6api3d5com_tlb::IDocument3DPtr & pDocument3d );


//-------------------------------------------------------------------------------
// Головная функция библиотеки
// ---
extern "C" void far __export __stdcall LIBRARYENTRY( unsigned int comm )
{
  switch ( comm )
  {
    case 10 :  CreateDocument3D();     break;  // Создание документа
    case 11 :  DocIterator();          break;  // Итератор по документам
    case 12 :  UseEntityCollection();  break;  // Использование массива элементов
    default :
    {
      Kompas6api3d5com_tlb::IDocument3DPtr document3d( ksGetActive3dDocument(), false/*AddRef*/ ); // Получить указатель на активный документ трехмерной модели
      if ( document3d  )
      {
        switch ( comm )
        {
          case 1  : GetSetPartName          ( document3d ); break; // Взять/изменить имя компоненты
          case 2  : FixAndStandartComponent ( document3d ); break; // Фиксирование и установка стандартного объекта
          case 3  : GetSetColorProperty     ( document3d ); break; // Получить и заменить параметры цвета компоненты
          case 4  : GetSetArrayVariable     ( document3d ); break; // Взять и поменять внешние переменные компоненты
          case 5  : GetSetPlacmentComponent ( document3d ); break; // Получить и изменить место расположения детали в сборке
          case 6  : GetSetEntity            ( document3d ); break; // Получить интерфейс ksEntity объекта создаваемого системой по умолчанию и поменять параметры
          case 7  : CreateSketch            ( document3d ); break; // Создать эскиз
          case 8  : GetArraySketch          ( document3d ); break; // Формирует массив объектов( здесь эскизов ) и возвращает его интерфейс ksEntityCollection( IEntityCollection )
          case 9  : GetSetUserParamComponent( document3d ); break; // Установить и получить параметры пользователя в компоненте
        }
      }
      else
      {
				ErrorT( _LoadStr( STR_3DDOCERROR ) ); // Документ не активизирован или не является 3D-моделью
      }
      if ( ReturnResult() == etError10 ) // Ошибка! Вырожденный объект
        ResultNULL(); // Обнулить ошибки
    }    
  }
}


//-------------------------------------------------------------------------------
// Создание документа 3D
// ---
void CreateDocument3D()
{
  // Получить указатель на объект документа трехмерной модели
  Kompas6api3d5com_tlb::IDocument3DPtr pDocument3d( ksGet3dDocument(), false/*AddRef*/ );
  if ( pDocument3d ) 
  {
    if ( pDocument3d->Create( false,   // Признак режима редактирования документа ( TRUE - невидимый режим, FALSE - видимый режим )
                              true ) ) // Тип документа ( TRUE - деталь, FALSE - сборка ) 
    {
			pDocument3d->SetAuthor( L"Автор" );                // Автор документа
			pDocument3d->SetComment( L"Пример документа 3D" ); // Комментарии к документу
			pDocument3d->SetFileName( L"C:\\Example.m3d" );    // Имя файла документа
			pDocument3d->UpdateDocumentParam();                // Обновить параметры документа
			pDocument3d->Save();                               // Сохранить документ
			MessageT( _T("Сохраним документ под другим именем") );
			pDocument3d->SaveAs( L"C:\\Example2.m3d" );        // Сохранить документ под другим именем

			TCHAR buf[255];

			// Автор документа
			WideString author = pDocument3d->GetAuthor();
			_stprintf( buf, _T("Автор документа: %s"), author.c_bstr() );
			MessageT( buf );

			// Комментарий к документу
			WideString comment = pDocument3d->GetComment();
			_stprintf( buf, _T("Комментарий к документу: %s"), comment.c_bstr() );
      MessageT( buf );
      
      // Имя файла
      WideString fileName = pDocument3d->GetFileName();
      _stprintf( buf, _T("Имя файла: %s"), fileName.c_bstr() );
      MessageT( buf );

      pDocument3d->Close(); // Закроем документ
    }
  }
}


//-------------------------------------------------------------------------------
// Открытие группы документов и создание итератора по ним
// ---
void DocIterator()
{
  // Динамический массив строк для имен файлов 
  reference rArDocFileName = CreateArray( CHAR_STR_ARR, 0 );
  
	if ( ksChoiceFilesT( _T("*.m3d"), _T("Документы ( *.m3d )|*.m3d|Сборки ( *.a3d )|*a3d|Все файлы ( *.* )|*.*|"), rArDocFileName, 1 ) )
	{
    TCHAR buf[255];
    
    // Откроем все файлы указанные пользователем
    int docCount = GetArrayCount( rArDocFileName );
    for ( int i = 0; i < docCount; i++ ) 
    {
      if ( GetArrayItem( rArDocFileName, i, buf, 255 ) )
      {
        // Получить указатель на объект документа трехмерной модели
        Kompas6api3d5com_tlb::IDocument3DPtr pDocument3d( ksGet3dDocument(), false/*AddRef*/ );
        if ( pDocument3d )
          // Открыть на редактирование документ-модель ( деталь или сборку )
          pDocument3d->Open( WideString( buf ).c_bstr(), // Имя файла открываемого документа
                             false );           // Признак режима редактирования документа
                                                // ( TRUE – невидимый режим, FALSE - видимый режим )
      }
    }

    // Сообщаем количество открытых файлов
    _stprintf( buf, _T("Открыто %d файлов"), docCount );
    MessageT( buf );
    
    // Итератор по 3D документам
    reference rIterator = CreateIterator( D3_DOCUMENT_OBJ, 0 );
    if ( rIterator ) 
    { 
      reference rDocument = MoveIterator( rIterator, 'F' ); // Смещаем итератор на первый элемент
      while ( rDocument > 0 )
      {
        Kompas6api3d5com_tlb::IDocument3DPtr pDocument3d( ksGet3dDocumentFromReference( rDocument ), false/*AddRef*/ );
        if ( pDocument3d )
        {
          // Автор документа
          WideString author = pDocument3d->GetAuthor();
          _stprintf( buf, _T("Автор документа: %s"), author.c_bstr() );
          MessageT( buf );

          // Комментарий к документу
          WideString comment = pDocument3d->GetComment();
					_stprintf( buf, _T("Комментарий к документу: %s"), comment.c_bstr() );
          MessageT( buf );

          // Имя файла
          WideString fileName = pDocument3d->GetFileName();
          _stprintf( buf, _T("Имя файла: %s"), fileName.c_bstr() );
          MessageT( buf );

          // Тип документа
					_stprintf( buf, _T("Тип документа: %s"), pDocument3d->IsDetail() ? _T("Деталь") : _T("Сборка") );
          MessageT( buf );

        }
        rDocument = MoveIterator( rIterator, 'N' ); // Смещаем итератор на следующую позицию
      }
      DeleteIterator( rIterator ); // Удалить итератор
    }
  }
}


//-------------------------------------------------------------------------------
// Использование массива элементов
// ---
void UseEntityCollection()
{
  Kompas6api3d5com_tlb::IDocument3DPtr pDocument3d( ksGetActive3dDocument(), false/*AddRef*/ ); // Получить указатель на активный документ трехмерной модели
  if ( pDocument3d )
  {
    // Получить указатель на интерфейс компонента в соответствии с заданным типом ( pNew_Part - новая деталь,
    // pEdit_Part - редактируемая деталь, pTop_Part - верхний компонент ) либо номером компонента
    Kompas6api3d5com_tlb::IPartPtr part( pDocument3d->GetPart( pTop_Part ), false/*AddRef*/ );
    if ( part )
    {
      TCHAR buf[255];

      // Формирует массив объектов и возвращает указатель на его интерфейс - массив поверхностей компонента
      Kompas6api3d5com_tlb::IEntityCollectionPtr entityCollection( part->EntityCollection( o3d_face ), false/*AddRef*/ );
      if ( entityCollection )
      {
        int countAllFace  = entityCollection->GetCount(); // Объщее количество поверхностей
        int countPlane = 0;                               // Количество плоских поверхностей
        int countCone  = 0;                               // Количество конических поверхностей
        for ( int i = 0; i < countAllFace; i++ )
        {
          Kompas6api3d5com_tlb::IEntityPtr entityFace( entityCollection->GetByIndex( i ), false/*AddRef*/ ); // Получить поверхность
          Kompas6api3d5com_tlb::IColorParamPtr colorParam( entityFace->ColorParam(), false/*AddRef*/ );       // Цвет поверхности

          // Получить указатель на интерфейс параметров объектов и элементов
          IUnknownPtr pDefinitionFace( entityFace->GetDefinition(), false/*AddRef*/ );
          Kompas6api3d5com_tlb::IFaceDefinitionPtr faceDefinition( pDefinitionFace );
          // Интерфейс свойств поверхности
          if ( faceDefinition )
          {
            if ( faceDefinition->IsCone() ||    // Коническая плоскость
                 faceDefinition->IsCylinder() ) // Цилиндрическая плоскость
            {
              colorParam->SetColor( RGB( 255, 255, 0 ) );
              countCone++; // Считаем количество конических поверхностей
            }

            if ( faceDefinition->IsPlanar() ) // Плоская плоскость
            {
              colorParam->SetColor( RGB( 0, 255, 255 ) );
              countPlane++; // Считаем количество плоских поверхностей
            }
            entityFace->_Update(); // Обновить параметры поверхности
          }
        }

        if ( countAllFace == 0 )
          MessageT( _T("Не найдено ни одной поверхности") );
        else
        {
          _stprintf( buf, _T("Найдено %i коничечких и %i плоских объектов"), countCone, countPlane );
          MessageT( buf );
        }
      }

      // Формирует массив объектов и возвращает указатель на его интерфейс - массив граней компонента
      Kompas6api3d5com_tlb::IEntityCollectionPtr entityCollection2( part->EntityCollection( o3d_edge ), false/*AddRef*/ );
      if ( entityCollection2 )
      {
        int countAllEdge     = entityCollection2->GetCount(); // Объщее количество ребер
        int countRectilinear = 0;                             // Количество прямых ребер
        int countCurvilinear = 0;                             // Количество криволинейных ребер
        for ( int i = 0; i < countAllEdge; i++ )
        {
          Kompas6api3d5com_tlb::IEntityPtr entityEdge( entityCollection->GetByIndex( i ), false/*AddRef*/ ); // Получить ребро

          // Получить указатель на интерфейс параметров объектов и элементов
          IUnknownPtr pDefinitionEdge( entityEdge ? entityEdge->GetDefinition() : NULL, false/*AddRef*/ );
          // Интерфейс свойств ребера
          Kompas6api3d5com_tlb::IEdgeDefinitionPtr edgeDefinition( pDefinitionEdge );
          if ( edgeDefinition )
          {
            if ( edgeDefinition->IsStraight() )
              countRectilinear++; // Количество прямых ребер
            else
              countCurvilinear++; // Количество криволинейных ребер
          }
        }

        if ( countAllEdge == 0 )
          MessageT( _T("Не найдено ни одного ребра") );
        else
        {
          _stprintf( buf, _T("Найдено %i прямых и %i криволинейных ребер"), countRectilinear, countCurvilinear );
          MessageT( buf );
        }
      }
    }
  }
}


//-------------------------------------------------------------------------------
// Взять/изменить имя детали или подсборки в составе сборки
// ---
void GetSetPartName( Kompas6api3d5com_tlb::IDocument3DPtr & pDocument3d )
{
  // Получить указатель на интерфейс компонента в соответствии с заданным типом ( pNew_Part - новая деталь,
  // pEdit_Part - редактируемая деталь, pTop_Part - верхний компонент ) либо номером компонента 
  Kompas6api3d5com_tlb::IPartPtr part( pDocument3d->GetPart( pTop_Part ), false/*AddRef*/ );
  if ( part )
  {
    TCHAR buf[255];
   
    // Получить имя детали или подсборки в составе сборки
    WideString name = part->GetName();
    _stprintf( buf, _T("Имя компоненты %s"), name.c_bstr() );
    MessageT( buf );
   
    // Сменить имя детали или подсборки в составе сборки
    part->SetName( L"Новое имя компоненты" );
    part->_Update(); // Обновить параметры компоненты
  }
}


//-------------------------------------------------------------------------------
// Фиксирование и установка стандартного объекта
// ---
void FixAndStandartComponent( Kompas6api3d5com_tlb::IDocument3DPtr & pDocument3d )
{
  if ( pDocument3d->IsDetail() ) // Определить, является ли модель деталью
  {
    ErrorT( _T("Текущий документ должен быть сборкой") );
    return;
  }
  
  // Получить указатель на интерфейс компонента в соответствии с заданным типом ( pNew_Part - новая деталь,
  // pEdit_Part - редактируемая деталь, pTop_Part - верхний компонент ) либо номером компонента 
  Kompas6api3d5com_tlb::IPartPtr part( pDocument3d->GetPart( 0 ), false/*AddRef*/ ); // Первая деталь в сборке
  if ( part )
  {
    // Получить состояние фиксации компонента ( Если компонент зафиксирован, то нельзя изменить его местоположение )
    int fixedComponent = part->GetFixedComponent();
		if (fixedComponent)
			MessageT( _T("Компонент зафиксирован") );
		else
			MessageT( _T("Компонент не зафиксирован") );

		// Получить состояние стандартного компонента ( Не имеет Дерева построения )
		int standardComponent = part->GetStandardComponent();
		if (standardComponent)
			MessageT( _T("Компонент стандартный") );
		else
			MessageT( _T("Компонент нестандартный") );
    
    // Изменить состояние фиксации компонента ( Если компонент зафиксирован, то нельзя изменить его местоположение )
    part->SetFixedComponent( !fixedComponent );    
    // Изменить состояние стандартного компонента ( Не имеет Дерева построения )
    part->SetStandardComponent( !standardComponent );
  }
}


//-------------------------------------------------------------------------------
// Взять/изменить параметры цвета компоненты
// ---
void GetSetColorProperty( Kompas6api3d5com_tlb::IDocument3DPtr & pDocument3d )
{
  // Получить указатель на интерфейс компонента в соответствии с заданным типом ( pNew_Part - новая деталь,
  // pEdit_Part - редактируемая деталь, pTop_Part - верхний компонент ) либо номером компонента 
  Kompas6api3d5com_tlb::IPartPtr part( pDocument3d->GetPart( pTop_Part ), false/*AddRef*/ );
  if ( part )
  {
    TCHAR buf[255];

    // Первый вариант
    // Параметры цвета компонента
    Kompas6api3d5com_tlb::IColorParamPtr colorParam( part->ColorParam(), false/*AddRef*/ );
    if ( colorParam )
    {
      _stprintf( buf, _T("Цвет = %d, общий цвет = %g,\nдиффузия = %g, зеркальность = %g,\nблеск = %g, прозрачность = %g,\nизлучение = %g"),
               colorParam->GetColor(), colorParam->GetAmbient(), 
               colorParam->GetDiffuse(), colorParam->GetSpecularity(), 
               colorParam->GetShininess(), colorParam->GetTransparency(), 
               colorParam->GetEmission() );
      MessageT( buf );
      
      // Изменение параметров цвета компонента
      colorParam->SetColor( 5421504 );
      colorParam->SetTransparency( 0.5 );
      colorParam->SetAmbient( 0.1 );
      colorParam->SetDiffuse( 0.1 );
      
      part->_Update(); // Обновить параметры компоненты
      
      _stprintf( buf, _T("Цвет = %d, общий цвет = %g,\nдиффузия = %g, зеркальность = %g,\nблеск = %g, прозрачность = %g,\nизлучение = %g"),
               colorParam->GetColor(), colorParam->GetAmbient(), 
               colorParam->GetDiffuse(), colorParam->GetSpecularity(), 
               colorParam->GetShininess(), colorParam->GetTransparency(), 
               colorParam->GetEmission() );
      MessageT( buf );
    }
    
    // Второй вариант
    COLORREF color;      // Цвет
    double ambient,      // Общий цвет
           diffuse,      // Диффузия
           specularity,  // Зеркальность  
           shininess,    // Блеск
           transparency, // Прозрачность
           emission;     // Излучение  
    
    // Возвращает параметры цвета и визуальных свойств компонента 
    part->GetAdvancedColor( &color, &ambient, &diffuse, &specularity, &shininess, &transparency, &emission );
    _stprintf( buf, _T("Цвет = %d, общий цвет = %g,\nдиффузия = %g, зеркальность = %g,\nблеск = %g, прозрачность = %g,\nизлучение = %g"),
             color, ambient, 
             diffuse, specularity, 
             shininess, transparency, 
             emission );
    MessageT( buf );
    
    // Изменение параметров цвета компонента
    color = 9421504; 
    transparency = 0.5; 
    ambient = 0.1; 
    diffuse = 0.1;
    
    // Устанавливает параметры цвета и визуальных свойств компонента
    part->SetAdvancedColor( color, ambient, diffuse, specularity, shininess, transparency, emission );
   
    part->_Update(); // Обновить параметры компоненты
    
    // Возвращает параметры цвета и визуальных свойств компонента 
    part->GetAdvancedColor( &color, &ambient, &diffuse, &specularity, &shininess, &transparency, &emission );
    _stprintf( buf, _T("Цвет = %d, общий цвет = %g,\nдиффузия = %g, зеркальность = %g,\nблеск = %g, прозрачность = %g,\nизлучение = %g"),
             color, ambient, 
             diffuse, specularity, 
             shininess, transparency, 
             emission );
    MessageT( buf );
  }
}


//-------------------------------------------------------------------------------
// Взять/изменить внешние переменные компоненты
// ---
void GetSetArrayVariable( Kompas6api3d5com_tlb::IDocument3DPtr & pDocument3d )
{
  if ( pDocument3d->IsDetail() ) // Определить, является ли модель деталью
  {
		ErrorT( _T("Текущий документ должен быть сборкой") );
    return;
  }
  
  // Получить указатель на интерфейс компонента в соответствии с заданным типом ( pNew_Part - новая деталь,
  // pEdit_Part - редактируемая деталь, pTop_Part - верхний компонент ) либо номером компонента 
  Kompas6api3d5com_tlb::IPartPtr part( pDocument3d->GetPart( 0 ), false/*false*/ ); // Первая деталь в сборке
  if ( part )
  {
    // Работа с массивом внешних переменных
    Kompas6api3d5com_tlb::IVariableCollectionPtr variableCollection( part->VariableCollection(), false/*false*/ );
    if ( variableCollection )
    {
      // Количество внешних переменных в массиве
      int count = variableCollection->GetCount();
      for ( int i = 0; i < count; i++ )
      {
        // Получить переменную
        Kompas6api3d5com_tlb::IVariablePtr variable( variableCollection->GetByIndex( i ), false/*false*/ );
        if ( variable )
        {
          if ( i == 0 )
          {
            // Сменить комментарий переменной
						variable->SetNote( L"Новое значение" );
						double d = 0;
						// Ввод переменной пользователем
						ReadDoubleT( _T("Введи переменную"), 10, 0, 100, &d );
            // Сменить значение переменной 
            variable->SetValue( d );
          }
        
          TCHAR buf[255];
          WideString name = variable->GetName(); // Имя переменной
          WideString note = variable->GetNote(); // Комментарий переменной
					_stprintf( buf, _T("Номер переменной : %d\nИмя переменной : %s\nЗначение переменной : %g\nКомментарий : %s"),
									 i, name.c_bstr(), variable->GetValue(), note.c_bstr() );
          MessageT( buf );
        }
      }
      // Перестраивает модель в соответствии с новыми значениями внешних переменных
      part->RebuildModel();
    }
  }
}


//-------------------------------------------------------------------------------
// Получить и изменить место расположения детали в сборке
// ---
void GetSetPlacmentComponent( Kompas6api3d5com_tlb::IDocument3DPtr & pDocument3d )
{
  if ( pDocument3d->IsDetail() ) // Определить, является ли модель деталью
  {
    ErrorT( _T("Текущий документ должен быть сборкой") );
    return;
  }
  
  // Получить указатель на интерфейс компонента в соответствии с заданным типом ( pNew_Part - новая деталь,
  // pEdit_Part - редактируемая деталь, pTop_Part - верхний компонент ) либо номером компонента 
  Kompas6api3d5com_tlb::IPartPtr part( pDocument3d->GetPart( 0 ), false/*AddRef*/ ); // Первая деталь в сборке
  if ( part )
  {
    Kompas6api3d5com_tlb::IPlacementPtr placement( part->GetPlacement(), false/*AddRef*/ ); // Получить указатель на интерфейс местоположения компонента
    if ( placement )
    {
      double x, y, z;  
      placement->GetOrigin( &x, &y, &z ); // Получить координаты начала локальной системы координат
      
      TCHAR buf[255];
      _stprintf( buf, _T("x = %g\ny = %g\nz = %g"), x, y, z );
      MessageT( buf );
      
      placement->SetOrigin( 20, 20, 20 ); // Изменить координаты начала локальной системы координат
      
      part->SetPlacement( placement ); // Установить новое местоположение компонента
      part->UpdatePlacement(); // Изменяет местоположение компонента, заданное методом SetPlacement
      part->_Update(); // Изменить свойства компонента (используя ранее установленные свойства)
    }
  }
}


//-------------------------------------------------------------------------------
// Получить интерфейс ksEntity объекта создаваемого системой по умолчанию и поменять параметры
// ---
void GetSetEntity( Kompas6api3d5com_tlb::IDocument3DPtr & pDocument3d )
{
  // Получить указатель на интерфейс компонента в соответствии с заданным типом ( pNew_Part - новая деталь,
  // pEdit_Part - редактируемая деталь, pTop_Part - верхний компонент ) либо номером компонента 
  Kompas6api3d5com_tlb::IPartPtr part( pDocument3d->GetPart( pTop_Part ), false/*AddRef*/ );
  if ( part )
  {
    Kompas6api3d5com_tlb::IEntityPtr entityPlane( part->GetDefaultEntity( o3d_planeXOY ), false/*AddRef*/ ); // Получить указатель на интерфейс объекта,
                                                                           // создаваемого системой по умолчанию - плоскость XOY
    if ( entityPlane )
    {
      TCHAR buf[255];
      WideString name = entityPlane->GetName(); // Имя элемента трехмерной модели
      _stprintf( buf, _T("Имя элемента: %s"), name.c_bstr() );
      MessageT( buf );

      entityPlane->SetName( L"Plane" ); // Установить новое имя элемента трехмерной модели
      entityPlane->_Update(); // Изменить свойства объекта (используя ранее установленные свойства)
    }
  }
}


//-------------------------------------------------------------------------------
// Создание эскиза
// ---
void CreateSketch( Kompas6api3d5com_tlb::IDocument3DPtr & pDocument3d )
{
  // Получить указатель на интерфейс компонента в соответствии с заданным типом ( pNew_Part - новая деталь,
  // pEdit_Part - редактируемая деталь, pTop_Part - верхний компонент ) либо номером компонента 
  Kompas6api3d5com_tlb::IPartPtr part( pDocument3d->GetPart( pTop_Part ), false/*AddRef*/ );
  if ( part )
  {
    // Создадим новый эскиз
    Kompas6api3d5com_tlb::IEntityPtr entitySketch( part->NewEntity( o3d_sketch ), false/*AddRef*/ );
    if ( entitySketch )
    {
      // Получить указатель на интерфейс параметров объектов и элементов
      IUnknownPtr pDefinitionSketch( entitySketch->GetDefinition(), false /*AddRef*/ );
      // Интерфейс свойств эскиза
      Kompas6api3d5com_tlb::ISketchDefinitionPtr sketchDefinition( pDefinitionSketch );
      if ( sketchDefinition )
      {
        // Получим интерфейс базовой плоскости XOY
        Kompas6api3d5com_tlb::IEntityPtr basePlane( part->GetDefaultEntity( o3d_planeXOY ), false/*AddRef*/ );

        // Установка параметров эскиза
        sketchDefinition->SetPlane( basePlane ); // Установим плоскость XOY базовой для эскиза
        sketchDefinition->SetAngle( 45 );        // Угол поворота эскиза

        // Создадим эскиз
        entitySketch->Create();

        // Войти в режим редактирования эскиза
        if ( sketchDefinition->BeginEdit() )
        {
          // Введем новый эскиз - квадрат
          LineSeg(  50,  50, -50,  50, 1 );
          LineSeg(  50, -50, -50, -50, 1 );
          LineSeg(  50, -50,  50,  50, 1 );
          LineSeg( -50, -50, -50,  50, 1 );
          // Выйти из режима редактирования эскиза
          sketchDefinition->EndEdit();
        }
      }
    }
  }
}


//-------------------------------------------------------------------------------
// Формирует массив объектов ( эскизов ) и возвращает его интерфейс IEntityCollection
// ---
void GetArraySketch( Kompas6api3d5com_tlb::IDocument3DPtr & pDocument3d )
{
  // Получить указатель на интерфейс компонента в соответствии с заданным типом ( pNew_Part - новая деталь,
  // pEdit_Part - редактируемая деталь, pTop_Part - верхний компонент ) либо номером компонента
  Kompas6api3d5com_tlb::IPartPtr part( pDocument3d->GetPart( pTop_Part ), false/*AddRef*/ );
  if ( part )
  {
    // Формирует массив объектов и возвращает указатель на его интерфейс - массив эскизов компонента
    Kompas6api3d5com_tlb::IEntityCollectionPtr entityCollection( part->EntityCollection( o3d_sketch ), false/*AddRef*/ );
    if ( entityCollection )
    {
      // Получить количество элементов в массиве
      int count = entityCollection->GetCount();
      for ( int i = 0; i < count; i++ )
      {
        Kompas6api3d5com_tlb::IEntityPtr currentEntity( entityCollection->GetByIndex( i ), false/*AddRef*/ ); // Получить эскиз
        TCHAR buf[255];
				WideString name = currentEntity->GetName(); // Имя эскиза
        _stprintf( buf, _T("Имя эскиза: %s"), name.c_bstr() );
        MessageT( buf );
      }
    }
  }
}


//-------------------------------------------------------------------------------
// Установить и получить параметры пользователя в компоненте
// ---
void GetSetUserParamComponent( Kompas6api3d5com_tlb::IDocument3DPtr & pDocument3d  )
{
  if ( pDocument3d->IsDetail() ) // Определить, является ли модель деталью
  {
    ErrorT( _T("Текущий документ должен быть сборкой") );
    return;
  }

  // Получить указатель на интерфейс компонента в соответствии с заданным типом ( pNew_Part - новая деталь,
  // pEdit_Part - редактируемая деталь, pTop_Part - верхний компонент ) либо номером компонента
  Kompas6api3d5com_tlb::IPartPtr part( pDocument3d->GetPart( 0 ), false/*AddRef*/ ); // Первая деталь в сборке
  if ( part )
  {
    // Пользовательская структура
    struct UserParam
    {
      double d1;
      double d2;
      int    i1;
      int    i2;
    } param;
    
    param.d1 = 12.12;
    param.d2 = 21.21;
		param.i1 = 667;
    param.i2 = 999;

    // Установить параметры компонента, указанные пользователем
    part->SetUserParam( &param, sizeof( param ), 0, 0, -1 );
    part->_Update(); // Изменить свойства компонента (используя ранее установленные свойства)

    TCHAR buf[255];
    _stprintf( buf, _T("Размер пользовательской структуры %d"), part->GetUserParamSize() ); // Размер пользовательской структуры
    MessageT( buf );

    part->GetUserParam( &param, sizeof( param ) ); // Возвращает пользовательские параметры, записанные в компоненте
		_stprintf( buf, _T("Переменные пользовательского массива\nd1 = %g\nd2 = %g\ni1 = %d\ni2 = %d"),
             param.d1, param.d2, param.i1, param.i2 );
		MessageT( buf );
  }
} 