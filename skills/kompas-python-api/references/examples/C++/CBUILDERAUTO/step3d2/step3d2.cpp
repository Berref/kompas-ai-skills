//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <windows.h>
#include <stdio.h>

#include <ldefin2d.h>
#include <ldefin3d.h>
#include <ksConstants.h>

#ifdef __LIGHT_VERSION__
#include <Kl_TLB.h>
#else
#include <Ks_TLB.h>
#endif

#ifdef _WIN64
 #define __TODO__ " TODO: "
 #define __WARN__ " warning: "
#else
#define __ANYTOSTR__(x) #x
#define __DEFTOSTR__(x) __ANYTOSTR__(x)
#define __TODO__ __FILE__ "("__DEFTOSTR__(__LINE__)") : TODO: "
#define __WARN__ __FILE__ "("__DEFTOSTR__(__LINE__)") : warning: "
#endif

#ifdef VARIANT_COPIES_BSTR
  inline wchar_t * TO_OLE(wchar_t *x) { return x; }
  inline wchar_t * TO_OLE(char    *x) { return WideString(x).c_bstr(); }
  inline wchar_t * TO_OLE(WideString & x) { return x.c_bstr(); }
#else
#pragma message(  __TODO__ "Рекомендуется добавить в настройки проекта определение VARIANT_COPIES_BSTR\n" )
// подробнее см http://sites.google.com/site/akxsolutions/articles/borland-c-dicom
  inline wchar_t * TO_OLE(wchar_t *x) { return WideString(x).Copy(); }
  inline wchar_t * TO_OLE(char    *x) { return WideString(x).Copy(); }
  inline wchar_t * TO_OLE(WideString & x) { return x.Copy(); }
#endif



//---------------------------------------------------------------------------
//   Important note about DLL memory management when your DLL uses the
//   static version of the RunTime Library:
//
//   If your DLL exports any functions that pass String objects (or structs/
//   classes containing nested Strings) as parameter or function results,
//   you will need to add the library MEMMGR.LIB to both the DLL project and
//   any other projects that use the DLL.  You will also need to use MEMMGR.LIB
//   if any other projects which use the DLL will be performing new or delete
//   operations on any non-TObject-derived classes which are exported from the
//   DLL. Adding MEMMGR.LIB to your project will change the DLL and its calling
//   EXE's to use the BORLNDMM.DLL as their memory manager.  In these cases,
//   the file BORLNDMM.DLL should be deployed along with your DLL.
//
//   To avoid using BORLNDMM.DLL, pass string information using "char *" or
//   ShortString parameters.
//
//   If your DLL uses the dynamic version of the RTL, you do not need to
//   explicitly add MEMMGR.LIB as this will be done implicitly for you
//---------------------------------------------------------------------------

#pragma argsused
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void* lpReserved)
{
  return 1;
}
//---------------------------------------------------------------------------

//------------------------------------------------------------------------------
// в Win32 линкуется SDK/lib/kAPI5bc.lib
// в x64 линкуется SDK/lib64/kAPI5bc.a
// ---
#pragma comment(lib, "kAPI5bc")
extern "C" IDispatch* far __export WINAPI CreateKompasObject();

KompasObjectPtr kompas;

extern "C" unsigned int __export __stdcall LIBRARYID()
{
  return 100;
}


void GetSetPartName          ( ksDocument3DPtr & doc );
void FixAndStandartComponent ( ksDocument3DPtr & doc );
void GetSetColorProperty     ( ksDocument3DPtr & doc );
void GetSetArrayVariable     ( ksDocument3DPtr & doc );
void GetSetPlacmentComponent ( ksDocument3DPtr & doc );
void GetSetEntity            ( ksDocument3DPtr & doc );
void CreateSketch            ( ksDocument3DPtr & doc );
void GetArraySketch          ( ksDocument3DPtr & doc );
void GetSetUserParamComponent( ksDocument3DPtr & doc );
void CreateDocument3D();
void DocIterator();
void UseEntityCollection();

char buf[MAX_TEXT_LENGTH];

//------------------------------------------------------------------------------
//
// ---
extern "C" void far __export __stdcall  LIBRARYENTRY( unsigned int comm )
{
  kompas.Bind( (KompasObject*)::CreateKompasObject(), false/*AddRef*/ );
  if ( kompas ) {
		switch ( comm ) {
      case 1 :  ::CreateDocument3D();     break;  // Создание документа
      case 2 :  ::DocIterator();          break;  // итератор по документам
      case 3 :  ::UseEntityCollection();  break;  // использование массива элементов

      default : {
        ksDocument3DPtr doc( (ksDocument3D*)kompas->ActiveDocument3D(), false/*AddRef*/ );
        if ( doc ) {
          switch ( comm ) {
            case 4  : ::GetSetPartName( doc );           break; // взять/изменить имя компоненты
            case 5  : ::FixAndStandartComponent( doc );  break; // фиксирование и установка стандартного объекта
            case 6  : ::GetSetColorProperty( doc );      break; // получить и заменить параметры цвета компоненты
            case 7  : ::GetSetArrayVariable( doc );      break; // взять и поменять внешние переменные компоненты
            case 8  : ::GetSetPlacmentComponent( doc );  break; // получить и изменить место расположения детали в сборке
            case 9  : ::GetSetEntity( doc );             break; // Получить интерфейс ksEntity объекта создаваемого системой по умолчанию и поменять параметры
            case 10 : ::CreateSketch( doc );             break; // создать эскиз
            case 11 : ::GetArraySketch( doc );           break; // Формирует массив объектов(здесь эскизов) и возвращает его интерфейс ksEntityCollection ( IEntityCollection )
            case 12 : ::GetSetUserParamComponent( doc ); break; // Установить и получить параметры пользователя в компоненте
          }
        }
        else
          kompas->ksError( TO_OLE(L"3D документ не активизирован") );
      }
    }
    kompas.Unbind();
  }
}

//------------------------------------------------------------------------------
// Взять и поменять имя компоненты
// ---
void GetSetPartName( ksDocument3DPtr & doc ) {
  ksPartPtr part( (ksPart*)doc->GetPart(pTop_Part), false/*AddRef*/ ); // верхний компонент
  if ( part ) {
		::sprintf( buf, "Имя компоненты %s", WideToAnsi(part->name) );
    kompas->ksMessage( TO_OLE(buf) );
    part->name = TO_OLE(L"Втулка");
    part->_Update();
  }
}

//------------------------------------------------------------------------------
// Фиксирование и установка стандартного объекта
// ---
void FixAndStandartComponent( ksDocument3DPtr & doc ) {
  if ( doc->IsDetail() ) {
    kompas->ksError( TO_OLE(L"Текущий документ должен быть сборкой") );
    return;
  }
  ksPartPtr part( (ksPart*)doc->GetPart(0), false/*AddRef*/ ); // первая деталь в сборке
  if ( part ) {
    // Получить состояние фиксации компонента - в системе поддерживающей работу со свойствами - fixedComponent
    int fix = part->fixedComponent;
    // Получить состояние стандартного компонента - в системе поддерживающей работу со свойствами - standardComponent
    int stand = part->standardComponent;
    kompas->ksMessage( fix ? TO_OLE(L"Компонент зафиксирован") : TO_OLE(L"Компонент не зафиксирован") );
    // Изменить состояние фиксации компонента - в системе поддерживающей работу со свойствами - fixedComponent
    part->fixedComponent = !fix;
    kompas->ksMessage( stand ? TO_OLE(L"Компонент стандартный") : TO_OLE(L"Компонент нестандартный") );
    // Изменить состояние стандартного компонента - в системе поддерживающей работу со свойствами - standardComponent
    part->standardComponent = !stand;
    part->_Update();
  }
}

//------------------------------------------------------------------------------
// Получить и заменить параметры цвета компоненты
// ---
void GetSetColorProperty( ksDocument3DPtr & doc ) {
  ksPartPtr part( (ksPart*)doc->GetPart(pTop_Part), false/*AddRef*/ ); // верхний компонент
  if ( part ) {
    ksColorParamPtr colorPr( (ksColorParam*)part->ColorParam(), false/*AddRef*/ );
    if ( colorPr ) {
      ::sprintf( buf, "Номер цвета = %d\nОбщий цвет = %g\nДиффузия = %g\nЗеркальность  = %g\nБлеск = %g\nПрозрачность = %g\nИзлучение = %g",
        colorPr->color, colorPr->ambient, colorPr->diffuse,
        colorPr->specularity, colorPr->shininess,
        colorPr->transparency, colorPr->emission );
      kompas->ksMessage( TO_OLE(buf) );
      colorPr->color        = 5421504;
      colorPr->transparency = 0.5;
      colorPr->ambient      = 0.1;
      colorPr->diffuse      = 0.1;
      part->_Update();
      ::sprintf( buf, "Номер цвета = %d\nОбщий цвет = %g\nДиффузия = %g\nЗеркальность  = %g\nБлеск = %g\nПрозрачность = %g\nИзлучение = %g",
        colorPr->color, colorPr->ambient, colorPr->diffuse,
        colorPr->specularity, colorPr->shininess,
        colorPr->transparency, colorPr->emission );
      kompas->ksMessage( TO_OLE(buf) );
    }
  }
/*
// Взять и поменять параметры цвета компонента
  double ambient, diffuse, specularity, shininess, transparency, emission;
  long color;
  part->GetAdvancedColor( &color, &ambient, &diffuse, &specularity, &shininess, &transparency, &emission );
  ::sprintf( buf, "Номер цвета = %d\nОбщий цвет = %g\nДиффузия = %g\nЗеркальность  = %g\nБлеск = %g\nПрозрачность = %g\nИзлучение = %g", //"color = %d\nambient = %g\ndiffuse = %g\nspecularity = %g\nshininess = %g\ntransparency = %g\nemission = %g",
             color, ambient, diffuse, specularity, shininess, transparency, emission );
  kompas->ksMessage(TO_OLE(buf));
  color = 9421504; transparency = 0.5; ambient = 0.1; diffuse = 0.1;
  part->SetAdvancedColor( color, ambient, diffuse, specularity, shininess, transparency, emission );
  part->GetAdvancedColor( &color, &ambient, &diffuse, &specularity, &shininess, &transparency, &emission );
  ::sprintf( buf, "Номер цвета = %d\nОбщий цвет = %g\nДиффузия = %g\nЗеркальность  = %g\nБлеск = %g\nПрозрачность = %g\nИзлучение = %g", //"color = %d\nambient = %g\ndiffuse = %g\nspecularity = %g\nshininess = %g\ntransparency = %g\nemission = %g",
             color, ambient, diffuse, specularity, shininess, transparency, emission );
  kompas->ksMessage(TO_OLE(buf));
  part->Update();
*/
}

//------------------------------------------------------------------------------
// Получить и изменить внешние переменные компоненты
// ---
void GetSetArrayVariable( ksDocument3DPtr & doc ) {
  if ( doc->IsDetail() ) {
    kompas->ksError(L"Текущий документ должен быть сборкой");
    return;
  }
  ksPartPtr part( (ksPart*)doc->GetPart(0), false/*AddRef*/ ); // первая деталь в сборке
  if ( part ) {
    // работа с массивом внешних переменных
    ksVariableCollectionPtr varCol( (ksVariableCollection*)part->VariableCollection(), false/*AddRef*/ );
    if ( varCol ) {
      ksVariablePtr var( (ksVariable*)kompas->GetParamStruct(ko_VariableParam), false/*AddRef*/ );
      if ( !var )
        return;
      for ( int i = 0, count = varCol->GetCount(); i < count; i++ ) {
        var.Bind( (ksVariable*)varCol->GetByIndex(i), false/*AddRef*/ );
				::sprintf( buf, "Номер переменной      %d\nИмя переменной          %s\nЗначение переменной  %g\nКомментарий       %s", i, WideToAnsi(var->get_name()), var->get_value(), WideToAnsi(var->get_note()) );
        kompas->ksMessage( TO_OLE(buf) );
        var->note = TO_OLE(L"qwerty");
        double d = 0;
        kompas->ksReadDouble( TO_OLE(L"Введи переменную"), 10, 0, 100, &d );
        var->value = d;
        var.Unbind();
      }

      for ( int j = 0, count2 = varCol->GetCount(); j < count2; j++ ) { // просмотр изменненных переменных
        var = (ksVariable*)varCol->GetByIndex(j);
				::sprintf( buf, "Номер переменной      %d\nИмя переменной          %s\nЗначение переменной  %g\nКомментарий       %s", j, WideToAnsi(var->get_name()), var->get_value(), WideToAnsi(var->get_note()) );
        kompas->ksMessage( TO_OLE(buf) );
        var.Unbind();
			}
      part->RebuildModel();  // перестроение модели
    }
  }
}

//------------------------------------------------------------------------------
// Получить и изменить расположение детали в сборке
// ---
void GetSetPlacmentComponent( ksDocument3DPtr & doc ) {
  if ( doc->IsDetail() ) {
    kompas->ksError( TO_OLE(L"Текущий документ должен быть сборкой") );
    return;
  }
  ksPartPtr part((ksPart*)doc->GetPart(0), false/*AddRef*/ ); // первая деталь в сборке
  if ( part ) {
    ksPlacementPtr plac( (ksPlacement*)part->GetPlacement(), false/*AddRef*/ );
    if ( plac ) {
      double x = 0, y = 0, z = 0;
      plac->GetOrigin( &x, &y, &z );
      ::sprintf( buf, "x = %g\ny = %g\nz = %g", x, y, z );
      kompas->ksMessage( TO_OLE(buf) );
      plac->SetOrigin( 20, 20, 20 );
      part->UpdatePlacement();
      part->_Update();
    }
  }
}

//------------------------------------------------------------------------------
// Получить и изменить парметры базовой плоскости
// ---
void GetSetEntity( ksDocument3DPtr & doc ) {
  ksPartPtr part( (ksPart*)doc->GetPart(pTop_Part), false/*AddRef*/ ); // верхний компонент
  if ( part ) {
    ksEntityPtr planeXOY( (ksEntity*)part->GetDefaultEntity(o3d_planeXOY), false/*AddRef*/ ); // 1-интерфейс на плоскость XOY
    if ( planeXOY ) {
      kompas->ksMessage( planeXOY->name );
      planeXOY->name = TO_OLE(L"plane");
      planeXOY->_Update();
    }
  }
}

//------------------------------------------------------------------------------
// Создать эскиз
// ---
void CreateSketch( ksDocument3DPtr & doc ) {
  ksPartPtr part( (ksPart*)doc->GetPart(pTop_Part), false/*AddRef*/ ); // верхний компонент
  if ( part ) {
    ksEntityPtr planeXOY( (ksEntity*)part->GetDefaultEntity(o3d_planeXOY), false/*AddRef*/ ); // 1-интерфейс на плоскость XOY
    ksEntityPtr entity( (ksEntity*)part->NewEntity(o3d_sketch), false/*AddRef*/ );
    if ( (bool)planeXOY && (bool)entity ) {
      ksSketchDefinitionPtr sketch( (ksSketchDefinition*)entity->GetDefinition(), false/*AddRef*/ );
      if ( sketch ) {
        sketch->SetPlane( planeXOY );
        entity->Create();
        ksDocument2DPtr sketchDoc( (ksDocument2D*)sketch->BeginEdit(), false/*AddRef*/ );
          sketchDoc->ksLineSeg( 0, 0, 100, 100, 1 );
        sketch->EndEdit();
      }
    }
  }
}

//------------------------------------------------------------------------------
// Вернуть массив эскизов
// ---
void GetArraySketch( ksDocument3DPtr & doc ) {
  ksPartPtr part( (ksPart*)doc->GetPart(pTop_Part), false/*AddRef*/ ); // верхний компонент
  if ( part ) {
    ksEntityCollectionPtr entityCollection( (ksEntityCollection*)part->EntityCollection( o3d_sketch ), false/*AddRef*/ );
    ksEntityPtr currentEntity;
    if ( entityCollection ) {
      for ( int i = 0, count = entityCollection->GetCount(); i < count; i++ ) {
        currentEntity.Bind( (ksEntity*)entityCollection->GetByIndex(i), false/*AddRef*/ );
        kompas->ksMessage( currentEntity->name );
//        currentEntity.Unbind();
      }
    }
  }
}

//------------------------------------------------------------------------------
// Установить и получить параметры пользователя в компоненте
// ---
void GetSetUserParamComponent( ksDocument3DPtr & doc ) {
  if ( doc->IsDetail() ) {
    kompas->ksError( TO_OLE(L"Текущий документ должен быть сборкой") );
    return;
  }
  ksPartPtr part( (ksPart*)doc->GetPart(0), false/*AddRef*/ ); // первая деталь в сборке
  ksUserParamPtr par( (ksUserParam*)kompas->GetParamStruct(ko_UserParam), false/*AddRef*/ );
  ksLtVariantPtr item( (ksLtVariant*)kompas->GetParamStruct(ko_LtVariant), false/*AddRef*/ );
  ksDynamicArrayPtr arr( (ksDynamicArray *)kompas->GetDynamicArray(LTVARIANT_ARR), false/*AddRef*/ );
  if ( !(bool)par || !(bool)item || !(bool)arr || !(bool)part )
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
    item->intVal = 676;
    arr->ksAddArrayItem( -1, item );
  item->Init();
    item->intVal = 999;
    arr->ksAddArrayItem( -1, item );

  part->SetUserParam(par); // установка пользовательской структуры
  part->_Update();

  ::sprintf( buf, "Размер пользовательской структуры %d", part->GetUserParamSize() ); // размер пользовательской структуры
  kompas->ksMessage( TO_OLE(buf) );

  ksUserParamPtr par2( (ksUserParam*)kompas->GetParamStruct(ko_UserParam), false/*AddRef*/ );
  ksLtVariantPtr item2( (ksLtVariant*)kompas->GetParamStruct(ko_LtVariant), false/*AddRef*/ );
  ksDynamicArrayPtr arr2( (ksDynamicArray*)kompas->GetDynamicArray(LTVARIANT_ARR), false/*AddRef*/ );
  if ( !(bool)par2 || !(bool)item2 || !(bool)arr2 )
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
  ::sprintf( buf, "Переменные пользовательского масства\na = %g\nb = %g\nc = %d\nd = %d", d.a, d.b, d.c, d.d );
  kompas->ksMessage( TO_OLE(buf) ); // просмотрим переменные из пользовательского массива
}

//------------------------------------------------------------------------------
// Создание 3D документа
// ---
void CreateDocument3D() {
  ksDocument3DPtr doc( (ksDocument3D*)kompas->Document3D(), false/*AddRef*/ );
  if ( doc->Create(false/*видимый*/, true/*деталь*/) ) {
    doc->author   = TO_OLE(L"Автор");               // Автор документа
    doc->comment  = TO_OLE(L"Пример документа 3D"); // Комментарии к документу
    doc->fileName = TO_OLE(L"c:\\example.m3d");     // Имя файла Документа
    doc->UpdateDocumentParam();             // Обновить параметры Документа
    doc->Save();                            // Сохранить документ
    kompas->ksMessage( TO_OLE(L"Сохраним документ под другим именем") );
    doc->SaveAs( TO_OLE(L"c:\\example_1.m3d") );     // сохранить документ под другим именем

		// Автор документа
		::sprintf( buf, "Автор документа: %s", WideToAnsi(doc->author) );
		kompas->ksMessage( TO_OLE(buf) );
		// Комментарий к документу
		::sprintf( buf, "Комментарий к документу: %s", WideToAnsi(doc->comment) );
		kompas->ksMessage(TO_OLE(buf));
		// Имя файла
		::sprintf( buf, "Имя файла: %s", WideToAnsi(doc->fileName) );
    kompas->ksMessage( TO_OLE(buf) );

		doc->close(); // закроем документ
  }
}

//------------------------------------------------------------------------------
// Итератор по документам
// ---
void DocIterator() {
  ksDocument3DPtr doc;
  ksDynamicArrayPtr arrDoc( (ksDynamicArray*)kompas->GetDynamicArray(CHAR_STR_ARR), false/*AddRef*/ ); // динамический массив указателей на строки символов
  // если массив создан запускаем диалог выбора файлов
  if ( (bool)arrDoc && kompas->ksChoiceFiles( TO_OLE(L"*.m3d"), TO_OLE(L"Документы (*.m3d)|*.m3d|Все файлы (*.*)|*.*|"), arrDoc, false) ) {
    ksChar255Ptr item( (ksChar255*)kompas->GetParamStruct(ko_Char255), false/*AddRef*/ );
    if ( item ) {
      // откроем все файлы указанные пользователем
      for ( int i = 0, count = arrDoc->ksGetArrayCount(); i < count; i++ ) {
        if ( arrDoc->ksGetArrayItem(i, item) ) {
          // захватываем интерфейс документа
          doc.Bind( (ksDocument3D*)kompas->Document3D(), false/*AddRef*/ );
          doc->Open( item->str, false ); // открываем файл с заданным именем
//          doc.Unbind();                  // освобождаем интерфейс
        }
      }
    }

    // сообщаем количество открытых файлов
    ::sprintf( buf, "Открыто %i файлов", arrDoc->ksGetArrayCount() );
    kompas->ksMessage( TO_OLE(buf) );

    // создаем итератор по документам
    ksIteratorPtr iter( (ksIterator*)kompas->GetIterator(), false/*AddRef*/ );
    if ( iter ) {
      if ( iter->ksCreateIterator(D3_DOCUMENT_OBJ/*тип объекта*/, 0) ) {
        reference ref = iter->ksMoveIterator( TO_OLE(L"F") ); // референс документа
        while ( ref ) { // смещаем итератор на первый элемент
          // захватываем интерфейс документа
          doc.Bind( (ksDocument3D*)kompas->ksGet3dDocumentFromRef(ref), false/*AddRef*/ );
          if ( doc ) {
            // автор документа
						::sprintf( buf, "Автор документа: %s", WideToAnsi(doc->author) );
						kompas->ksMessage( TO_OLE(buf) );
						// комментарии к документу
						::sprintf( buf, "Комментарий к документу: %s", WideToAnsi(doc->comment) );
						kompas->ksMessage( TO_OLE(buf));
						// имя файла документа
						::sprintf( buf, "Имя файла: %s", WideToAnsi(doc->fileName) );
						kompas->ksMessage(TO_OLE(buf));
            // тип документа
            ::sprintf( buf, "Тип документа: %s", doc->IsDetail() ? "Деталь" : "Сборка" );
            kompas->ksMessage(TO_OLE(buf));
            // освободить интерфейс
//             doc.Unbind();
          }
          ref == iter->ksMoveIterator(L"N");
        }
        iter->ksDeleteIterator(); // удалить итератор
      }
    }
  }
}

//------------------------------------------------------------------------------
// Массивы элементов
// ---
void UseEntityCollection() {
  ksDocument3DPtr doc( (ksDocument3D*)kompas->ActiveDocument3D(), false/*AddRef*/ ); // привязываемся к активному документу
  if ( doc ) {
    ksPartPtr part( (ksPart*)doc->GetPart(pTop_Part), false/*AddRef*/ );       // новый компонент
    if ( part ) {
      long count1;
      long count2;
      long count;

      // массив поверхностей
      ksEntityCollectionPtr collect( (ksEntityCollection*)part->EntityCollection(o3d_face), false/*AddRef*/ );
      if ( collect ) {
        count = collect->GetCount();
        count1 = 0; // количество плоских поверхностей
        count2 = 0; // количество конических поверхностей
        ksColorParamPtr colorPr; // интерфейс свойств цвета
        if ( (bool)collect && count ) {
          for ( int i = 0; i < count; i++ ) {
            ksEntityPtr ent( (ksEntity*)collect->GetByIndex(i), false/*AddRef*/ );
            colorPr.Bind( (ksColorParam*)ent->ColorParam(), false/*AddRef*/ );
            // интерфейс свойств поверхности
            ksFaceDefinitionPtr faceDef( (ksFaceDefinition *)ent->GetDefinition(), false/*AddRef*/ );
            if ( faceDef ) {
              if ( faceDef->IsCone()/*коническая по-ть*/ ) {
                colorPr->color = RGB(255, 255, 0);
                count2++;   // считаем количество объектов
              }

              if ( faceDef->IsPlanar()/*плоская по-ть*/ ) {
                colorPr->color = RGB(0, 255, 255);
                count1++;   // считаем количество объектов
              }

              colorPr.Unbind();
              ent->_Update(); // обновить параметры
            }
          }
        }
      }

      // сообщяем о результатах работы
      if ( count == 0 )
        kompas->ksMessage( TO_OLE(L"Не найдено ни одной поверхности") );
      else {
        ::sprintf( buf, "Найдено %i коничечких и %i плоских объектов", count2, count1 );
        kompas->ksMessage( TO_OLE(buf) );
      }

      count1 = 0;
      count2 = 0;
      // массив ребер
      ksEntityCollectionPtr collect2( (ksEntityCollection*)part->EntityCollection(o3d_edge), false/*AddRef*/ );
      count = collect2->GetCount();
      if ( (bool)collect2 && count ) {
        for ( int i = 0; i < count; i++ ) {
          ksEntityPtr ent( (ksEntity*)collect2->GetByIndex(i), false/*AddRef*/ );
          ksEdgeDefinitionPtr edgeDef( (ksEdgeDefinition *)ent->GetDefinition(), false/*AddRef*/ );
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
        kompas->ksMessage( TO_OLE(L"Не найдено ни одного ребра") );
      else {
        ::sprintf( buf, "Найдено %i прямых и %i криволинейных ребер", count1, count2 );
        kompas->ksMessage( TO_OLE(buf) );
      }
    }
  }
}

