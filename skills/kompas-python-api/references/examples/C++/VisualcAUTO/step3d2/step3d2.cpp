  // step3d2.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "step3d2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//
//  Note!
//
//    If this DLL is dynamically linked against the MFC
//    DLLs, any functions exported from this DLL which
//    call into MFC must have the AFX_MANAGE_STATE macro
//    added at the very beginning of the function.
//
//    For example:
//
//    extern "C" BOOL PASCAL EXPORT ExportedFunction()
//    {
//      AFX_MANAGE_STATE(AfxGetStaticModuleState());
//      // normal function body here
//    }
//
//    It is very important that this macro appear in each
//    function, prior to any calls into MFC.  This means that
//    it must appear as the first statement within the 
//    function, even before any object variable declarations
//    as their constructors may generate calls into the MFC
//    DLL.
//
//    Please see MFC Technical Notes 33 and 58 for additional
//    details.
//

/////////////////////////////////////////////////////////////////////////////
// CStep3d2App

BEGIN_MESSAGE_MAP(CStep3d2App, CWinApp)
  //{{AFX_MSG_MAP(CStep3d2App)
    // NOTE - the ClassWizard will add and remove mapping macros here.
    //    DO NOT EDIT what you see in these blocks of generated code!
  //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStep3d2App construction

CStep3d2App::CStep3d2App()
{
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CStep3d2App object

CStep3d2App theApp;

//-------------------------------------------------------------------------------
//
// ---
unsigned int WINAPI LIBRARYID(){
  return IDR_LIB3D2;
}

KompasObjectPtr kompas;

TCHAR buf[MAX_TEXT_LENGTH];
void GetSetPartName( ksDocument3DPtr& doc );
void FixAndStandartComponent( ksDocument3DPtr& doc );
void GetSetColorProperty( ksDocument3DPtr& doc );
void GetSetArrayVariable( ksDocument3DPtr& doc );
void GetSetPlacmentComponent( ksDocument3DPtr& doc );
void GetSetEntity( ksDocument3DPtr& doc );
void CreateSketch( ksDocument3DPtr& doc );
void GetArraySketch( ksDocument3DPtr& doc );
void GetSetUserParamComponent( ksDocument3DPtr& doc );
void UseEntityCollection();
void CreateDocument3D();
void DocIterator();

//-------------------------------------------------------------------------------
//
// ---
void GetKompas() {
  if ( !kompas ) {
    CString filename;
    if( ::GetModuleFileName(NULL, filename.GetBuffer(255), 255) ) {
      filename.ReleaseBuffer( 255 );
      CString libname;

      #ifdef __LIGHT_VERSION__
        libname.LoadString( IDS_STRING5 );  //klAPI5.dll
      #else
        libname.LoadString( IDS_STRING4 );  //kAPI5.dll
      #endif
      
      filename.Replace( filename.Right(filename.GetLength() - (filename.ReverseFind('\\') + 1)), 
                        libname );

      HINSTANCE hAppAuto = LoadLibrary( filename ); // идентификатор kAPI5.dll
      if(  hAppAuto ) {
        typedef LPDISPATCH ( WINAPI *FCreateKompasObject )(); 
        FCreateKompasObject pCreateKompasObject = 
          (FCreateKompasObject)GetProcAddress( hAppAuto, "CreateKompasObject" );  
        if ( pCreateKompasObject ) 
          kompas = IDispatchPtr(pCreateKompasObject(), false);
        FreeLibrary( hAppAuto );
      }
    }
  }
}

//-------------------------------------------------------------------------------
//
// ---
void WINAPI LIBRARYENTRY( unsigned int comm ) {
  // по умолчанию ресурсы берутся из .exe файла, для того чтобы их достать
  // из нашей dll вызовем этот define
  AFX_MANAGE_STATE(AfxGetStaticModuleState());

  GetKompas();
  if ( kompas ) {
    switch ( comm ) {
      case 10 :  ::CreateDocument3D();     break;  // Создание документа
      case 11 :  ::DocIterator();          break;  // итератор по документам
      case 12 :  ::UseEntityCollection();  break;  // использование массива элементов
      default : {
        ksDocument3DPtr doc( kompas->ActiveDocument3D() );
        if ( doc  ) {
          switch ( comm ) {
            case 1  : ::GetSetPartName( doc );           break; // взять/изменить имя компоненты
            case 2  : ::FixAndStandartComponent( doc );   break; // фиксирование и установка стандартного объекта
            case 3  : ::GetSetColorProperty( doc );      break; // получить и заменить параметры цвета компоненты
            case 4  : ::GetSetArrayVariable( doc );       break; // взять и поменять внешние переменные компоненты
            case 5  : ::GetSetPlacmentComponent( doc );   break; // получить и изменить место расположения детали в сборке
            case 6  : ::GetSetEntity( doc );             break; // Получить интерфейс ksEntityPtr объекта создаваемого системой по умолчанию и поменять параметры
            case 7  : ::CreateSketch( doc );             break; // создать эскиз
            case 8  : ::GetArraySketch( doc );           break; // Формирует массив объектов(здесь эскизов) и возвращает его интерфейс ksEntityCollectionPtr ( IEntityCollection )
            case 9  : ::GetSetUserParamComponent( doc ); break; // Установить и получить параметры пользователя в компоненте
          }
        }
      }
    }
  }
}

//-------------------------------------------------------------------------------
// взять/изменить имя компоненты
// ---
void GetSetPartName( ksDocument3DPtr& doc ) {
  ksPartPtr part( doc->GetPart(pTop_Part) ); // верхний компонент
  if ( part ) {
    ::_stprintf_s( buf, _T("Имя компоненты %s"), (LPCTSTR)part->name );
    kompas->ksMessage( buf );
    part->name = _T("Втулка");
    part->Update();
  }   
}


//-------------------------------------------------------------------------------
// фиксирование и установка стандартного объекта
// ---
void FixAndStandartComponent( ksDocument3DPtr& doc ) {
  if ( doc->IsDetail() ) {
    kompas->ksError(_T("Текущий документ должен быть сборкой"));
    return;
  }
  ksPartPtr part( doc->GetPart(0) ); // первая деталь в сборке
  if ( part ) {
    // Получить состояние фиксации компонента - в системе поддерживающей работу со свойствами - fixedComponent
    bool fix = !!part->fixedComponent;
    // Получить состояние стандартного компонента - в системе поддерживающей работу со свойствами - standardComponent
    bool stand = !!part->standardComponent;
    kompas->ksMessage( fix ? _T("Компонент зафиксирован") : _T("Компонент не зафиксирован") );
    // Изменить состояние фиксации компонента - в системе поддерживающей работу со свойствами - fixedComponent
    part->fixedComponent = !fix;
    kompas->ksMessage( stand ? _T("Компонент стандартный") : _T("Компонент нестандартный") );
    // Изменить состояние стандартного компонента - в системе поддерживающей работу со свойствами - standardComponent
    part->standardComponent = !stand;
  }
}

//-------------------------------------------------------------------------------
// получить и заменить параметры цвета компоненты
// ---
void GetSetColorProperty( ksDocument3DPtr& doc ) {
  ksPartPtr part( doc->GetPart(pTop_Part) ); // верхний компонент
  if ( part ) {
    ksColorParamPtr colorPr( part->ColorParam() );
    if ( colorPr ) {
      ::_stprintf_s( buf, _T("Номер цвета = %d\nОбщий цвет = %g\nДиффузия = %g\nЗеркальность  = %g\nБлеск = %g\nПрозрачность = %g\nИзлучение = %g"), 
        colorPr->color, colorPr->ambient, colorPr->diffuse, 
        colorPr->specularity, colorPr->shininess, 
        colorPr->transparency, colorPr->emission );
      kompas->ksMessage( buf );
      colorPr->color = 5421504;
      colorPr->transparency = 0.5;
      colorPr->ambient = 0.1;
      colorPr->diffuse = 0.1;
      part->Update();
      ::_stprintf_s( buf, _T("Номер цвета = %d\nОбщий цвет = %g\nДиффузия = %g\nЗеркальность  = %g\nБлеск = %g\nПрозрачность = %g\nИзлучение = %g"), 
        colorPr->color, colorPr->ambient, colorPr->diffuse, 
        colorPr->specularity, colorPr->shininess, 
        colorPr->transparency, colorPr->emission );
      kompas->ksMessage( buf );
    }
  }
//    // Взять и поменять параметры цвета компонента
//    double ambient, diffuse, specularity, shininess, transparency, emission;
//    long color;
//    part->GetAdvancedColor( &color, &ambient, &diffuse, &specularity, &shininess, &transparency, &emission );
//    ::sprintf( buf, "Номер цвета = %d\nОбщий цвет = %g\nДиффузия = %g\nЗеркальность  = %g\nБлеск = %g\nПрозрачность = %g\nИзлучение = %g", //"color = %d\nambient = %g\ndiffuse = %g\nspecularity = %g\nshininess = %g\ntransparency = %g\nemission = %g", 
//               color, ambient, diffuse, specularity, shininess, transparency, emission );
//    kompas->ksMessage(buf);
//    color = 9421504; transparency = 0.5; ambient = 0.1; diffuse = 0.1;
//    part->SetAdvancedColor( color, ambient, diffuse, specularity, shininess, transparency, emission );
//    part->GetAdvancedColor( &color, &ambient, &diffuse, &specularity, &shininess, &transparency, &emission );
//    ::sprintf( buf, "Номер цвета = %d\nОбщий цвет = %g\nДиффузия = %g\nЗеркальность  = %g\nБлеск = %g\nПрозрачность = %g\nИзлучение = %g", //"color = %d\nambient = %g\ndiffuse = %g\nspecularity = %g\nshininess = %g\ntransparency = %g\nemission = %g", 
//               color, ambient, diffuse, specularity, shininess, transparency, emission );
//    kompas->ksMessage(buf);
//    part->Update();
}


//-------------------------------------------------------------------------------
// взять и поменять внешние переменные компоненты
// ---
void GetSetArrayVariable( ksDocument3DPtr& doc ) {
  if ( doc->IsDetail() ) {
    kompas->ksError( _T("Текущий документ должен быть сборкой") );
    return;
  }
  ksPartPtr part( doc->GetPart(0) ); // первая деталь в сборке
  if ( part ) {
    // работа с массивом внешних переменных
    ksVariableCollectionPtr varCol(part->VariableCollection() );
    if ( varCol ) {
      ksVariablePtr var;
      for ( int i = 0, count = varCol->GetCount(); i < count; i++ ) {
        var = varCol->GetByIndex(i);
        ::_stprintf_s( buf, _T("Номер переменной      %d\nИмя переменной          %s\nЗначение переменной  %g\nКомментарий       %s"), i, (LPCTSTR)var->name, var->value, (LPCTSTR)var->note );
        kompas->ksMessage( buf );
        if ( i==0 ) {
          var->note = _T("qwerty");
          double d = 0;
          kompas->ksReadDouble( _T("Введи переменную"), 10, 0, 100, &d );
          var->value = d;
        }
      }
      
      for ( int j = 0, count2 = varCol->GetCount(); j < count2; j++ ) { // просмотр изменненных переменных
        var = varCol->GetByIndex(j);
        ::_stprintf_s( buf, _T("Номер переменной      %d\nИмя переменной          %s\nЗначение переменной  %g\nКомментарий       %s"), j, (LPCTSTR)var->name, var->value, (LPCTSTR)var->note );
        kompas->ksMessage( buf );
      }
      part->RebuildModel();  // перестроение модели
    }
  }
}


//-------------------------------------------------------------------------------
// получить и изменить место расположения детали в сборке
// ---
void GetSetPlacmentComponent( ksDocument3DPtr& doc ) {
  if ( doc->IsDetail() ) {
    kompas->ksError(_T("Текущий документ должен быть сборкой"));
    return;
  }
  ksPartPtr part( doc->GetPart(0) ); // первая деталь в сборке
  if ( part ) {
    ksPlacementPtr plac( part->GetPlacement() );
    if ( plac ) {
      double x, y, z;
      plac->GetOrigin( &x, &y, &z );
      ::_stprintf_s( buf, _T("x = %g\ny = %g\nz = %g"), x, y, z );
      kompas->ksMessage( buf );
      plac->SetOrigin( 20, 20, 20 );
      part->UpdatePlacement();
      part->Update();
    }
  }
}

//-------------------------------------------------------------------------------
// Получить интерфейс ksEntityPtr объекта создаваемого системой по умолчанию и поменять параметры
// ---
void GetSetEntity( ksDocument3DPtr& doc ) {
  ksPartPtr part( doc->GetPart(pTop_Part) ); // верхний компонент
  if ( part ) {
    ksEntityPtr planeXOY( part->GetDefaultEntity(o3d_planeXOY) ); // 1-интерфейс на плоскость XOY
    if ( planeXOY ) {
      kompas->ksMessage( planeXOY->name );
      planeXOY->name = _T("plane");
      planeXOY->Update();
    }
  }
}

//-------------------------------------------------------------------------------
// создание эскиза
// ---
void CreateSketch( ksDocument3DPtr& doc ) {
  ksPartPtr part( doc->GetPart(pTop_Part) ); // верхний компонент
  if ( part ) {
    ksEntityPtr planeXOY( part->GetDefaultEntity(o3d_planeXOY) ); // 1-интерфейс на плоскость XOY
//    ASSERT(part);  
    ksEntityPtr entity( part->NewEntity(o3d_sketch) );
    if ( planeXOY && entity ) {
      ksSketchDefinitionPtr sketch( entity->GetDefinition() );
      if ( sketch ) {
        sketch->SetPlane( planeXOY );
        entity->Create();
        ksDocument2DPtr sketchDoc( sketch->BeginEdit() );
          sketchDoc->ksLineSeg( 0, 0, 100, 100, 1 );
        sketch->EndEdit();
      }
    }
  }
}

//-------------------------------------------------------------------------------
// Формирует массив объектов(здесь эскизов) и возвращает его интерфейс ksEntityCollectionPtr ( IEntityCollection )
// ---
void GetArraySketch( ksDocument3DPtr& doc ) {
  ksPartPtr part( doc->GetPart(pTop_Part) ); // верхний компонент
  if ( part ) {
    ksEntityCollectionPtr entityCollection( part->EntityCollection( o3d_sketch ) );
    ksEntityPtr currentEntity;
    if ( entityCollection ) {
      for ( int k = 0; k < entityCollection->GetCount(); k++ ) {
        currentEntity= entityCollection->GetByIndex(k);
        kompas->ksMessage( currentEntity->name );
      }
    }
  }
}

//-------------------------------------------------------------------------------
// Установить и получить параметры пользователя в компоненте
// ---
void GetSetUserParamComponent( ksDocument3DPtr& doc ) {
  if ( doc->IsDetail() ) {
    kompas->ksError(_T("Текущий документ должен быть сборкой"));
    return;
  }
  ksPartPtr part( doc->GetPart(0) ); // первая деталь в сборке
  ksUserParamPtr par( kompas->GetParamStruct(ko_UserParam) );
  ksLtVariantPtr item( kompas->GetParamStruct(ko_LtVariant) );
  ksDynamicArrayPtr arr( kompas->GetDynamicArray(LTVARIANT_ARR) );
  if ( !par || !item || !arr || !part )
    return;

  par->Init();
  par->SetUserArray( arr );
  item->Init();
    item->doubleVal = 12.12;
    arr->ksAddArrayItem( -1, item );
  item->Init();
    item->doubleVal = 21.21;
    arr->ksAddArrayItem( -1, item );
  item->Init();
    item->intVal = 6666;
    arr->ksAddArrayItem( -1, item );
  item->Init();
    item->intVal = 9999;
    arr->ksAddArrayItem( -1, item );

  part->SetUserParam( par ); // установка пользовательской структуры
  part->Update();

  ::_stprintf_s( buf, _T("Размер пользовательской структуры %d"), part->GetUserParamSize() ); // размер пользовательской структуры
  kompas->ksMessage( buf );

  ksUserParamPtr par2( kompas->GetParamStruct(ko_UserParam) );
  ksLtVariantPtr item2( kompas->GetParamStruct(ko_LtVariant) );
  ksDynamicArrayPtr arr2( kompas->GetDynamicArray(LTVARIANT_ARR) );
  if ( !par2 || !item2 || !arr2 )
    return;

  par2->Init();
  par2->SetUserArray( arr2 );
  item2->Init();
    item2->doubleVal = 0;
    arr2->ksAddArrayItem( -1, item2 );
  item2->Init();
    item2->doubleVal = 0;
    arr2->ksAddArrayItem( -1, item2 );
  item2->Init();
    item2->intVal = 0;
    arr2->ksAddArrayItem( -1, item2 );
  item2->Init();
    item2->intVal = 0;
    arr2->ksAddArrayItem( -1, item2 );

  part->GetUserParam( par2 ); // берем пользовательскeую структуру
  
  struct {
    double a, b;
    int c, d;
  } d;
  arr2->ksGetArrayItem( 0, item2 );
  d.a = item2->doubleVal;
  arr2->ksGetArrayItem( 1, item2 );
  d.b = item2->doubleVal;
  arr2->ksGetArrayItem( 2, item2 );
  d.c = item2->intVal;
  arr2->ksGetArrayItem( 3, item2 );
  d.d = item2->intVal;
  ::_stprintf_s( buf, _T("Переменные пользовательского масства\na = %g\nb = %g\nc = %d\nd = %d"), d.a, d.b, d.c, d.d );
  kompas->ksMessage( buf ); // просмотрим переменные из пользовательского массива
}

//-------------------------------------------------------------------------------
// создание документа 
// ---
void CreateDocument3D() {
  ksDocument3DPtr doc( kompas->Document3D() );
  if ( doc->Create(false/*видимый*/, true/*деталь*/) ) {
    doc->author = _T("Автор");                // Автор документа
    doc->comment = _T("Пример документа 3D"); // Комментарии к документу
    doc->fileName = _T("c:\\example.m3d");    // Имя файла Документа
    doc->UpdateDocumentParam();               // Обновить параметры Документа
    doc->Save();                              // Сохранить документ
    kompas->ksMessage( _T("Сохраним документ под другим именем") );
    doc->SaveAs( _T("c:\\example_1.m3d") );   // сохранить документ под другим именем

    TCHAR buf[256];
    // Автор документа
    _stprintf_s( buf, _T("Автор документа: %s"), (LPCTSTR)doc->author );
    kompas->ksMessage( buf);
    // Комментарий к документу
    _stprintf_s( buf, _T("Комментарий к документу: %s"), (LPCTSTR)doc->comment );
    kompas->ksMessage( buf);
    // Имя файла
    _stprintf_s( buf, _T("Имя файла: %s"), (LPCTSTR)doc->fileName );
    kompas->ksMessage( buf);

    doc->close(); // закроем документ
  }
}

//-------------------------------------------------------------------------------
// открытие группы документов и создание итератора по ним
// ---
void DocIterator() {
  TCHAR buf[256];
  ksDocument3DPtr doc;
  ksDynamicArrayPtr arrDoc( kompas->GetDynamicArray(CHAR_STR_ARR) ); // динамический массив указателей на строки символов
  // если массив создан запускаем диалог выбора файлов 
  if ( arrDoc && kompas->ksChoiceFiles( _T("*.m3d"), _T("Документы (*.m3d)|*.m3d|Все файлы (*.*)|*.*|"), arrDoc, false) ) {
    ksChar255Ptr item( kompas->GetParamStruct(ko_Char255) ); 
    if ( item ) {
      // откроем все файлы указанные пользователем
      for ( int i = 0, count = arrDoc->ksGetArrayCount(); i < count; i++ ) {
        if ( arrDoc->ksGetArrayItem(i, item) ) { 
          // захватываем интерфейс документа       //не владеет
          doc = kompas->Document3D();
          doc->Open( item->str, false ); // открываем файл с заданным именем 
        }
      }
    }

    // сообщаем количество открытых файлов
    ::_stprintf_s( buf, _T("Открыто %i файлов"), arrDoc->ksGetArrayCount() );
    kompas->ksMessage( buf ); 

    // создаем итератор по документам
    ksIteratorPtr iter( kompas->GetIterator() );
    if ( iter ) {   //тип объекта             
      if ( iter->ksCreateIterator(D3_DOCUMENT_OBJ, 0) ) {
        reference ref; // референс документа
        if ( ref = iter->ksMoveIterator(_T("F")) ) { // смещаем итератор на первый элемент
          do { // смещаем итератор на следующую позицию
            // захватываем интерфейс документа
            doc= kompas->ksGet3dDocumentFromRef(ref);
            if ( doc ) {
              // автор документа
              _stprintf_s( buf, _T("Автор документа: %s"), (LPCTSTR)doc->author );
              kompas->ksMessage( buf );
              // комментарии к документу
              _stprintf_s( buf, _T("Комментарий к документу: %s"), (LPCTSTR)doc->comment );
              kompas->ksMessage( buf );
              // имя файла документа 
              _stprintf_s( buf, _T("Имя файла: %s"), (LPCTSTR)doc->fileName );
              kompas->ksMessage( buf);
              // тип документа
              _stprintf_s( buf, _T("Тип документа: %s"), doc->IsDetail() ? _T("Деталь") : _T("Сборка") );
              kompas->ksMessage( buf );
            }
          } while ( ref = iter->ksMoveIterator(_T("N")) );

          iter->ksDeleteIterator(); // удалить итератор
        }
      }
    }
  }
}


//-------------------------------------------------------------------------------
// использование массива элементов
// ---
void UseEntityCollection() {
  ksDocument3DPtr doc( kompas->ActiveDocument3D() ); // привязываемся к активному документу
  if ( doc ) {
    ksPartPtr part( doc->GetPart(pTop_Part) );       // новый компонент
    if ( part ) {
      long count1 = 0;
      long count2 = 0; // количество плоских поверхностей
      long count = 0;  // количество конических поверхностей

      // массив поверхностей
      ksEntityCollectionPtr collect( part->EntityCollection(o3d_face) );      
      if ( collect ) {
        count = collect->GetCount();
        count1 = 0; 
        count2 = 0; 
        ksColorParamPtr colorPr; // интерфейс свойств цвета
        if ( collect && count ) {
          for ( int i = 0; i < count; i++ ) {
            ksEntityPtr ent( collect->GetByIndex(i) );
            colorPr = ent->ColorParam();
            // интерфейс свойств поверхности
            ksFaceDefinitionPtr faceDef( ent->GetDefinition() );
            if ( faceDef ) {
              //коническая по-ть       //цилиндрическая по-ть
              if ( faceDef->IsCone() || faceDef->IsCylinder() ) {      
                colorPr->color = RGB(255, 255, 0);  
                count2++;   // считаем количество объектов
              }
              //плоская по-ть  
              if ( faceDef->IsPlanar() ) {
                colorPr->color = RGB(0, 255, 255); 
                count1++;   // считаем количество объектов
              }

              ent->Update(); // обновить параметры
            }
          }
        }
      }

      // сообщяем о результатах работы
      if ( count == 0 ) 
        kompas->ksMessage( _T("Не найдено ни одной поверхности") );
      else {
        TCHAR buf[128];
        _stprintf_s( buf, _T("Найдено %i коничечких и %i плоских объектов"), count2, count1 );
        kompas->ksMessage( buf );
      }

      count1 = 0;
      count2 = 0;
      // массив ребер
      ksEntityCollectionPtr collect2( part->EntityCollection(o3d_edge) );      
      count = collect2->GetCount();
      if ( collect2 && count ) {
        for ( int i = 0; i < count; i++ ) {
          ksEntityPtr ent( collect2->GetByIndex(i) );
          ksEdgeDefinitionPtr edgeDef( ent->GetDefinition() );
          if ( edgeDef ) {
            if ( edgeDef->IsStraight() ) 
              count1++; // количество прямых ребер
            else
              count2++; // количество криволинейных ребер
          }
        }
      }

      // сообщяем о результатах работы
      if ( count == 0 ) 
        kompas->ksMessage( _T("Не найдено ни одного ребра") );
      else {
        TCHAR buf[128];
        _stprintf_s( buf, _T("Найдено %i прямых и %i криволинейных ребер"), count1, count2 );
        kompas->ksMessage( buf );
      }

    }
  }
}

