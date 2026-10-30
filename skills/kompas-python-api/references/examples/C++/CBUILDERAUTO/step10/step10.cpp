//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <windows.h>
#include <stdio.h>

#include <ldefin2d.h>
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

#define SPC_NAME  5

void TypeAttrBolt  ();
void CreateDet     ( ksDocument2DPtr & doc );
void CreateStandart( ksDocument2DPtr & doc );
void DecomposeSpc  ();
void ShowSpc       ();

reference  EditSpcObjDet( reference geom, ksDocument2DPtr & doc );
void DrawPosLeader( reference spcObj, ksDocument2DPtr & doc );
reference EditStandartSpcObj ( reference geom, ksDocument2DPtr & doc, reference spcObj );

char buf[128];

//------------------------------------------------------------------------------
//
// ---
extern "C" void far __export __stdcall  LIBRARYENTRY( unsigned int comm )
{
  kompas.Bind( (KompasObject*)::CreateKompasObject(), false/*AddRef*/ );
  if ( kompas ) {

		if ( comm == 2 || comm == 3 || comm == 5 ) {
      ksDocument2DPtr docActive( (ksDocument2D*)kompas->ActiveDocument2D(), false/*AddRef*/ );
      if ( docActive ) {
        switch ( comm ) {
          case 2 : ::CreateDet     ( docActive ); break; //создать объект спецификации деталь
          case 3 : ::CreateStandart( docActive ); break; //создать стандартный объект
        }
      }
      else
        kompas->ksError( TO_OLE(L"Документ не активизирован или \nне является листом/фрагментом") );
    }
    else
    {
      switch ( comm ) {
        case 1  : ::TypeAttrBolt(); break; //создадим  тип атрибута болта
        case 4  : ::DecomposeSpc(); break; //kонвертировать спецификацию во фрагмент
        case 5 : ::ShowSpc      (); break; //просмотреть спецификацию
      }
    }
    kompas.Unbind();
  }
}

//-------------------------------------------------------------------------------
// Находит интерфейс для работы со спецификацией
// doc - указатель на документ
// ---
ksSpecificationPtr GetSpecification()
{
  ksSpecificationPtr specification;

  long docType = kompas->ksGetDocumentType( 0 );

  switch ( docType )
  {
    case lt_DocSheetStandart :
    case lt_DocSheetUser     :
    {
      ksDocument2DPtr doc2D( (ksDocument2D*)kompas->ActiveDocument2D() ); // Интерфейс документа

      if ( doc2D )
        specification.Bind( (ksSpecification*)doc2D->GetSpecification(), false/*AddRef*/ );
      break;
    } // case

    case lt_DocAssemble3D :
    {
      ksDocument3DPtr doc3D( (ksDocument3D*)kompas->ActiveDocument3D() ); // Интерфейс документа

      if ( doc3D )
      {
        specification.Bind( (ksSpecification*)doc3D->GetSpecification(), false/*AddRef*/ );
      } // if ( docTxt )
      break;
    } // case

    case lt_DocSpc           :
    case lt_DocSpcUser       :
    {
      ksSpcDocumentPtr spcDoc( (ksSpcDocument*)kompas->SpcActiveDocument() ); // Интерфейс документа

      if ( spcDoc )
      {
        specification.Bind( (ksSpecification*)spcDoc->GetSpecification(), false/*AddRef*/ );
      } // if ( spcDoc )
      break;
    } // case

  } // switch ( docType )
  return specification;
}

//------------------------------------------------------------------------------
// создадим объект спецификации для раздела "Детали"
// ---
reference  EditSpcObjDet( reference geom, ksDocument2DPtr & doc ) {
  reference spcObj = 0;
  //если редактируем макро объект , то ввойдем в режим редактирования объекта
  ksSpecificationPtr specification( (ksSpecification *)doc->GetSpecification(), false/*AddRef*/ );

  if (!specification)
    return 0;

  if ( (bool)doc && doc->ksEditMacroMode( ) ) {
    //найдем объкт спецификации по геометрии
    spcObj = specification->ksGetSpcObjForGeom( TO_OLE(L"graphic.lyt"), //имя библиотеки типов
                                   1,         //   номер типа спецификации
                                   0,         //для макро редактирования
                                   1, 1 );
    //ввойдем в режим редактирования
    if ( !specification->ksSpcObjectEdit( spcObj ) )
      spcObj  = 0;
  }

  //если объекта нет, ввойдем в режим создания объекта спецификации
  if( spcObj || specification->ksSpcObjectCreate( TO_OLE(L"graphic.lyt"), //имя библиотеки типов
                                   1,         //   номер типа спецификации
                                   20,  0,    //номер раздела и подраздела
                                   0,0 )) {    //тип атрибута

    ksUserParamPtr par( (ksUserParam*)kompas->GetParamStruct(ko_UserParam), false/*AddRef*/ );
    ksLtVariantPtr item( (ksLtVariant*)kompas->GetParamStruct(ko_LtVariant), false/*AddRef*/ );
    ksDynamicArrayPtr arr( (ksDynamicArray*)kompas->GetDynamicArray(LTVARIANT_ARR), false/*AddRef*/ );
    if ( !(bool)par || !(bool)item || !(bool)arr )
      return 0;
    par->Init();
    par->SetUserArray( arr );
    item->Init();
    item->strVal = TO_OLE(L"Втулка");
    arr->ksAddArrayItem( -1, item );
    //наименование
    specification->ksSpcChangeValue( 5/*номер колонки*/ , 1, par, STRING_ATTR_TYPE  );

    //подключим геометрию
    if ( geom )
      specification->ksSpcIncludeReference( geom, 1 );

    spcObj = specification->ksSpcObjectEnd( );
    //если объект спецификации создан дадим возможность пользователю на него посмотреть и
    //отредактировать  функцию нужно запускать вне Cursor и Placement
    if ( spcObj && specification->ksEditWindowSpcObject( spcObj ) )
      return spcObj;
  }
  return 0;
}

//------------------------------------------------------------------------------
// отрисовать позиционную линию выноски
// уже проверено , что объект спецификации есть
// Функцию нужно запускать вне Cursor и Placement
// ---
void DrawPosLeader( reference spcObj, ksDocument2DPtr & doc ) {
  if ( !doc )
    return;

  ksRequestInfoPtr info( (ksRequestInfo*)kompas->GetParamStruct(ko_RequestInfo), false/*AddRef*/ );
  if ( !info )
    return;

  ksSpecificationPtr specification( (ksSpecification *)doc->GetSpecification(), false/*AddRef*/ );
  if (!specification)
    return ;

  info->Init();
  bool flag = false;
  reference posLeater = 0;
  double x1, y1;
  do {
    info->commandsString = TO_OLE(L"!Создать новую линию выноски !Подключить существующую ");
    info->prompt         = TO_OLE(L"Укажите позиционную линию выноски");
    int j1 = doc->ksCursor( info, &x1, &y1, 0 );
    switch ( j1 ) {
      case 1: //Создать новую линию выноски
        posLeater = doc->ksCreateViewObject( POSLEADER_OBJ );
        flag = false;
        break;
      case 2: //Подключить существующую
        info->prompt = TO_OLE(L"Укажите линию выноски");
        if( doc->ksCursor( info, &x1, &y1, 0 ) ) {
          posLeater = doc->ksFindObj( x1, y1, 100 );      // величина стороны окошка-ловушки с центром x,y
          if ( !(posLeater && doc->ksGetObjParam( posLeater, 0, 0) == POSLEADER_OBJ )) {
             posLeater = 0;
             flag = true;
          }
          else
            flag = false;
          break;
        }
        else
          flag = false;
        break;
      case -1:
        posLeater = doc->ksFindObj( x1, y1, 100 );      // величина стороны окошка-ловушки с центром x,y
        if ( !(posLeater && doc->ksGetObjParam( posLeater, 0, 0) == POSLEADER_OBJ )) {
           kompas->ksError( TO_OLE(L"Ошибка! Объект не позиционная линия выноски!") );
           posLeater = 0;
           flag = true;
        }
        else
          flag = false;
      break;
    }
  }  while( flag );

  //линия выноски есть, подключим ее к объекту спецификации
  if ( posLeater  ) {
    //ввойдем в режим редактирования объекта спецификации
    if ( specification->ksSpcObjectEdit( spcObj ) ) {
      //подключим линию выноски
      specification->ksSpcIncludeReference( posLeater, true );
      //закроем объект спецификации
      specification->ksSpcObjectEnd();
    }
  }
}

//------------------------------------------------------------------------------
// создадим объект спецификации для раздела "Стандартные изделия"
// ---
reference EditStandartSpcObj ( reference geom, ksDocument2DPtr & doc, reference spcObj ) {
  //если редактируем макро объект , то ввойдем в режим редактирования объекта
  ksSpecificationPtr specification( (ksSpecification *)doc->GetSpecification(), false/*AddRef*/ );

  if (!specification)
    return 0;


  if ( doc->ksEditMacroMode( ) ) {
    //найдем объкт спецификации по геометрии
    spcObj = specification->ksGetSpcObjForGeom( TO_OLE(L"graphic.lyt"), //имя библиотеки типов
                                   1,         //   номер типа спецификации
                                   0,         //для макро редактирования
                                   1, 1 );
    //ввойдем в режим редактирования
    if ( !specification->ksSpcObjectEdit( spcObj ) )
      spcObj  = 0;
  }

  if( spcObj || specification->ksSpcObjectCreate( TO_OLE(L"graphic.lyt"), //имя библиотеки типов
                                   1,         //   номер типа спецификации
                                   25,  0,    //номер раздела и подраздела определены в стиле спецификации
                                   313277777065.0 , 0 )) { //тип атрибута определен в библиотеке типов атрибутов spc.lat

    int uBuf;
    ksUserParamPtr par( (ksUserParam*)kompas->GetParamStruct(ko_UserParam), false/*AddRef*/ );
    ksLtVariantPtr item( (ksLtVariant*)kompas->GetParamStruct(ko_LtVariant), false/*AddRef*/ );
    ksDynamicArrayPtr arr( (ksDynamicArray*)kompas->GetDynamicArray(LTVARIANT_ARR), false/*AddRef*/ );
    if ( !par || !item || !arr )
      return 0;
    par->Init();
    par->SetUserArray( arr );
    item->Init();
    item->strVal = TO_OLE(L"Болт111");
    arr->ksAddArrayItem( -1, item );

    specification->ksSpcChangeValue( 5/*номер колонки*/ , 1, par, STRING_ATTR_TYPE  );
    //исполнение
    uBuf = 2;
    specification->ksSpcVisible( SPC_NAME, 2, 1 );
    arr->ksClearArray();
    item->Init();
    item->intVal = uBuf;
    arr->ksAddArrayItem( -1, item );
    specification->ksSpcChangeValue( SPC_NAME , 2, par, UINT_ATTR_TYPE  );

    //изменим диаметр
    arr->ksClearArray();
    item->Init();
    item->doubleVal = 40;
    arr->ksAddArrayItem( -1, item );
    specification->ksSpcChangeValue( SPC_NAME , 4, par, DOUBLE_ATTR_TYPE  );

   //отследим мелкий шаг
   specification->ksSpcVisible( SPC_NAME, 5, 1 );
   specification->ksSpcVisible( SPC_NAME, 6, 1 );   //шаг
   arr->ksClearArray();
   item->Init();
   item->floatVal = 1;
   arr->ksAddArrayItem( -1, item );
   specification->ksSpcChangeValue( SPC_NAME , 6, par, FLOAT_ATTR_TYPE  );

   // выключим поле допуска
   specification->ksSpcVisible( SPC_NAME, 7, 0 );

   //изменим длину
   arr->ksClearArray();
   item->Init();
   item->intVal = 55;
   arr->ksAddArrayItem( -1, item );
   specification->ksSpcChangeValue( SPC_NAME , 9, par, UINT_ATTR_TYPE );

   // выключим класс прочности
   specification->ksSpcVisible( SPC_NAME, 10, 0 );

   // выключим материал
   specification->ksSpcVisible( SPC_NAME, 11, 0 );

   // выключим покрытие
   specification->ksSpcVisible( SPC_NAME, 12, 0 );

   //изменим ГОСТ
   arr->ksClearArray();
   item->Init();
   item->floatVal = 7808;
   arr->ksAddArrayItem( -1, item );
   specification->ksSpcChangeValue( SPC_NAME , 14, par, UINT_ATTR_TYPE );

   //подключим геометрию
   if ( geom )
     specification->ksSpcIncludeReference( geom, 1 );

   spcObj = specification->ksSpcObjectEnd( );
   //если объект спецификации создан дадим возможность пользователю на него посмотреть и
   //отредактировать.  Функцию нужно запускать вне Cursor и Placement
   if ( spcObj )
     if ( specification->ksEditWindowSpcObject( spcObj ) )
       return spcObj;
 }
 return 0;
}

//------------------------------------------------------------------------------
// создадим  тип атрибута болта
// ---
void TypeAttrBolt() {
  ksAttributeObjectPtr attr( (ksAttributeObject*)kompas->GetAttributeObject(), false/*AddRef*/ );
  ksAttributeTypeParamPtr type( (ksAttributeTypeParam*)kompas->GetParamStruct(ko_AttributeType), false/*AddRef*/ );
  ksColumnInfoParamPtr col( (ksColumnInfoParam*)kompas->GetParamStruct(ko_ColumnInfoParam), false/*AddRef*/ );
  if ( (bool)type && (bool)col && (bool)attr ) {
    type->Init();
    col->Init();
    type->header      = TO_OLE(L"Болт111"); // заголовoк-комментарий типа
    type->rowsCount   = 1;          // кол-во строк в таблице
    type->flagVisible = true;       // видимый, невидимый   в таблице
    type->password    = TO_OLE(L"");        // пароль, если не пустая строка  - защищает от несанкционированного изменения типа
    type->key1        = 10;
    type->key2        = 20;
    type->key3        = 30;
    type->key4        = 0;
    ksDynamicArrayPtr arr( (ksDynamicArray*)type->GetColumns(), false/*AddRef*/ );
    if ( arr ) {
      //  колонка 1 "Имя элем."
      col->header   = TO_OLE(L"Имя элем.");       // заголовoк-комментарий столбца
      col->type     = STRING_ATTR_TYPE;   // тип данных в столбце - см.ниже
      col->key      = 1;                  // дополнительный признак, который позволит отличить две переменные с одинаковым типом
      col->def      = TO_OLE(L"Болт");            // значение по умолчанию
      col->flagEnum = false;              // флаг включающий режим, когда значение поля атрибута
      arr->ksAddArrayItem( -1, col );

      //  колонка 2 "Исполнение"
      col->header   = TO_OLE(L"Исполнение");   // заголовoк-комментарий столбца
      col->type     = UINT_ATTR_TYPE;  // тип данных в столбце - см.ниже
      col->key      = 3;               // дополнительный признак, который позволит отличить две переменные с одинаковым типом
      col->def      = TO_OLE(L"1");            // значение по умолчанию
      col->flagEnum = false;           // флаг включающий режим, когда значение поля атрибута
      arr->ksAddArrayItem( -1, col );

      // колонка 3 "Резьба"
      col->header   = TO_OLE(L"Резьба");        // заголовoк-комментарий столбца
      col->type     = STRING_ATTR_TYPE; // тип данных в столбце - см.ниже
      col->key      = 0;                // дополнительный признак, который позволит отличить две переменные с одинаковым типом
      col->def      = TO_OLE(L"M");             // значение по умолчанию
      col->flagEnum = false;            // флаг включающий режим, когда значение поля атрибута
      arr->ksAddArrayItem( -1, col );

      // колонка 4 "Диаметр"
      col->header   = TO_OLE(L"Диаметр");       // заголовoк-комментарий столбца
      col->type     = UINT_ATTR_TYPE;   // тип данных в столбце - см.ниже
      col->key      = 3;                // дополнительный признак, который позволит отличить две переменные с одинаковым типом
      col->def      = TO_OLE(L"12");            // значение по умолчанию
      col->flagEnum = false;            // флаг включающий режим, когда значение поля атрибута
      arr->ksAddArrayItem( -1, col );

      // колонка 5 "разделитель"
      col->header   = TO_OLE(L"");              // заголовoк-комментарий столбца
      col->type     = STRING_ATTR_TYPE; // тип данных в столбце - см.ниже
      col->key      = 0;                // дополнительный признак, который позволит отличить две переменные с одинаковым типом
      col->def      = TO_OLE(L"x");             // значение по умолчанию
      col->flagEnum = false;            // флаг включающий режим, когда значение поля атрибута
      arr->ksAddArrayItem( -1, col );

      // колонка 6 "Шаг"
      col->header   = TO_OLE(L"Шаг");           // заголовoк-комментарий столбца
      col->type     = FLOAT_ATTR_TYPE;  // тип данных в столбце - см.ниже
      col->key      = 3;                // дополнительный признак, который позволит отличить две переменные с одинаковым типом
      col->def      = TO_OLE(L"1.25");          // значение по умолчанию
      col->flagEnum = false;            // флаг включающий режим, когда значение поля атрибута
      arr->ksAddArrayItem( -1, col );

      // колонка 7 "Поле допуска"
      col->header   = TO_OLE(L"Поле допуска");  // заголовoк-комментарий столбца
      col->type     = STRING_ATTR_TYPE; // тип данных в столбце - см.ниже
      col->key      = 3;                // дополнительный признак, который позволит отличить две переменные с одинаковым типом
      col->def      = TO_OLE(L"-6g");           // значение по умолчанию
      col->flagEnum = false;            // флаг включающий режим, когда значение поля атрибута
      arr->ksAddArrayItem( -1, col );

      // колонка 8 "разделитель"
      col->header   = TO_OLE(L"");              // заголовoк-комментарий столбца
      col->type     = STRING_ATTR_TYPE; // тип данных в столбце - см.ниже
      col->key      = 0;                // дополнительный признак, который позволит отличить две переменные с одинаковым типом
      col->def      = TO_OLE(L"x");             // значение по умолчанию
      col->flagEnum = false;            // флаг включающий режим, когда значение поля атрибута
      arr->ksAddArrayItem( -1, col );

      // колонка 9 "Длина"
      col->header   = TO_OLE(L"Длина");         // заголовoк-комментарий столбца
      col->type     = UINT_ATTR_TYPE;   // тип данных в столбце - см.ниже
      col->key      = 3;                // дополнительный признак, который позволит отличить две переменные с одинаковым типом
      col->def      = TO_OLE(L"60");            // значение по умолчанию
      col->flagEnum = false;            // флаг включающий режим, когда значение поля атрибута
      arr->ksAddArrayItem( -1, col );

      // колонка 10 "Кл. прочности"
      col->header   = TO_OLE(L"Кл. прочности"); // заголовoк-комментарий столбца
      col->type     = STRING_ATTR_TYPE; // тип данных в столбце - см.ниже
      col->key      = 0;                // дополнительный признак, который позволит отличить две переменные с одинаковым типом
      col->def      = TO_OLE(L"58");            // значение по умолчанию
      col->flagEnum = false;            // флаг включающий режим, когда значение поля атрибута
      arr->ksAddArrayItem( -1, col );

      // колонка 11 "Материал"
      col->header   = TO_OLE(L"Материал");      // заголовoк-комментарий столбца
      col->type     = STRING_ATTR_TYPE; // тип данных в столбце - см.ниже
      col->key      = 0;                // дополнительный признак, который позволит отличить две переменные с одинаковым типом
      col->def      = TO_OLE(L".35Х");          // значение по умолчанию
      col->flagEnum = false;            // флаг включающий режим, когда значение поля атрибута
      arr->ksAddArrayItem( -1, col );

      // колонка 12 "Покрытие"
      col->header   = TO_OLE(L"Покрытие");      // заголовoк-комментарий столбца
      col->type     = STRING_ATTR_TYPE; // тип данных в столбце - см.ниже
      col->key      = 0;                // дополнительный признак, который позволит отличить две переменные с одинаковым типом
      col->def      = TO_OLE(L".16");           // значение по умолчанию
      col->flagEnum = false;            // флаг включающий режим, когда значение поля атрибута
      arr->ksAddArrayItem( -1, col );

      // колонка 13 "ГОСТ"
      col->header   = TO_OLE(L"ГОСТ");          // заголовoк-комментарий столбца
      col->type     = STRING_ATTR_TYPE; // тип данных в столбце - см.ниже
      col->key      = 0;                // дополнительный признак, который позволит отличить две переменные с одинаковым типом
      col->def      = TO_OLE(L"ГОСТ");          // значение по умолчанию
      col->flagEnum = false;            // флаг включающий режим, когда значение поля атрибута
      arr->ksAddArrayItem( -1, col );

      // колонка 14 "Номер"
      col->header   = TO_OLE(L"Номер");         // заголовoк-комментарий столбца
      col->type     = UINT_ATTR_TYPE;   // тип данных в столбце - см.ниже
      col->key      = 2;                // дополнительный признак, который позволит отличить две переменные с одинаковым типом
      col->def      = TO_OLE(L"7808");          // значение по умолчанию
      col->flagEnum = false;            // флаг включающий режим, когда значение поля атрибута
      arr->ksAddArrayItem( -1, col );

      // колонка 15 "разделитель"
      col->header   = TO_OLE(L"");              // заголовoк-комментарий столбца
      col->type     = STRING_ATTR_TYPE; // тип данных в столбце - см.ниже
      col->key      = 0;                // дополнительный признак, который позволит отличить две переменные с одинаковым типом
      col->def      = TO_OLE(L"-");             // значение по умолчанию
      col->flagEnum = false;            // флаг включающий режим, когда значение поля атрибута
      arr->ksAddArrayItem( -1, col );

      // колонка 16 "Год"
      col->header   = TO_OLE(L"Год");           // заголовoк-комментарий столбца
      col->type     = STRING_ATTR_TYPE; // тип данных в столбце - см.ниже
      col->key      = 0;                // дополнительный признак, который позволит отличить две переменные с одинаковым типом
      col->def      = TO_OLE(L"70");            // значение по умолчанию
      col->flagEnum = false;            // флаг включающий режим, когда значение поля атрибута
      arr->ksAddArrayItem( -1, col );
    }
    WideString nameFile = kompas->ksChoiceFile( TO_OLE(L"*.lat"), NULL, false );
    if ( nameFile.IsEmpty() ) {
      //создать тип атрибута
      double  numbType = attr->ksCreateAttrType( type,       // информация о типе атрибута
                                                 TO_OLE(nameFile) ); // имя библиотеки типов атрибутов
      if ( numbType > 1 )  {
        char buf[128];
        ::sprintf( buf, "numbType=%f ",numbType );
        kompas->ksMessage( TO_OLE(buf) );
      }
      else
        kompas->ksMessageBoxResult(); // проверяем результат работы нашей функции
    }
    arr->ksDeleteArray(); //удалим  массив колонок
  }
}

//------------------------------------------------------------------------------
// создать объект спецификации деталь
// ---
void CreateDet( ksDocument2DPtr & doc ) {
  //создать модельную группу   1
  reference gr = 0;
  if ( doc )
  {
    gr = doc->ksNewGroup(0);
      doc->ksLineSeg ( 20, 30, 70, 30, 2 );
      doc->ksLineSeg ( 70, 30, 70, 80, 2 );
      doc->ksLineSeg ( 70, 80, 20, 80, 2 );
      doc->ksLineSeg ( 20, 80, 20, 30, 2 );
    doc->ksEndGroup();
  }
  //создать  объект спецификации
  reference spcObj = EditSpcObjDet( gr, doc );
  if ( spcObj )
    DrawPosLeader( spcObj, doc );
}

//------------------------------------------------------------------------------
// создать стандартный объект
// ---
void CreateStandart( ksDocument2DPtr & doc ) {
  reference spcObj = EditStandartSpcObj( 0, doc, 0 );
  if ( spcObj )
    DrawPosLeader( spcObj, doc );
}

//------------------------------------------------------------------------------
// kонвертировать спецификацию во фрагмент
// ---
void DecomposeSpc() {
  ksSpcDocumentPtr spc( (ksSpcDocument*)kompas->SpcActiveDocument(), false/*AddRef*/ );
  if ( spc ) {
    //берем текущий документ спецификацию
    reference pDoc = spc->reference;
    if ( pDoc == 0 )
      return;
    //найдем количество листов спецификации
    int pageCount = spc->ksGetSpcDocumentPagesCount();
    //найдем габариры одного листа спецификации
    ksRectParamPtr spcGabarit( (ksRectParam*)kompas->GetParamStruct(ko_RectParam) );
    if ( !spcGabarit )
      return;
    //создадим фрагмент
    ksDocument2DPtr    doc2D( (ksDocument2D*)kompas->Document2D(), false/*AddRef*/ );
    ksDocumentParamPtr docPar( (ksDocumentParam*)kompas->GetParamStruct(ko_DocumentParam), false/*AddRef*/ );
    if ( !(bool)doc2D || !(bool)docPar )
      return;

    doc2D->ksGetObjGabaritRect( pDoc, spcGabarit );

    docPar->Init();
    docPar->regime = 0;
    docPar->type   = 3;
    doc2D->ksCreateDocument( docPar );
    for ( int i = 0; i < pageCount; i++ ) {
      //получили временную группу i-го листа спецификации
      reference group = doc2D->ksDecomposeObj( pDoc,    // указатель на объект
                                               0,       // уровень разбиения 0- отрезки,дуги,тексты,точки; 1-отрезки,тексты,точки; 2-отрезки, дуги, тексты
                                               0.4,     // стрелка прогиба
                                               i + 1 ); // 0 - разбиение объекта в СК вида 1- в СК листа
      if ( group ) {
        int column = i % 3;
        ksMathPointParamPtr mathBop( (ksMathPointParam*)spcGabarit->GetpBot(), false/*AddRef*/ );
        ksMathPointParamPtr mathTop( (ksMathPointParam*)spcGabarit->GetpTop(), false/*AddRef*/ );
        if ( !(bool)mathBop || !(bool)mathTop )
          return;
        double x = ( mathTop->x - mathBop->x + 5) * column;
        int row = i / 3;
        double y = ( mathTop->y - mathBop->y + 5) * row;
        //сдвинули группу
        doc2D->ksMoveObj( group, x, -y );
        //поставили в модель
        doc2D->ksStoreTmpGroup( group );  //указатель группы
        doc2D->ksClearGroup( group, 1 );
        doc2D->ksDeleteObj( group );
      }
    }
    char buf[128];
    ::sprintf( buf, "Декомпозировано %d листов СП", pageCount );
    kompas->ksMessage( TO_OLE(buf) );
  }
  else
    kompas->ksError( TO_OLE(L"Спецификация должна быть текущей") );
}

//------------------------------------------------------------------------------
// просмотреть спецификацию
// ---
void ShowSpc( ) {
  ksSpecificationPtr specification( GetSpecification() );
  if (!specification)
    return ;
  ksIteratorPtr iter( (ksIterator*)kompas->GetIterator(), false/*AddRef*/ );
  if ( !iter )
    return;

  iter->ksCreateSpcIterator( 0, 0, 0 );
  if ( iter->reference ) {
    long obj = iter->ksMoveIterator( TO_OLE(L"F") );
    while ( obj )
    {
      //узнаем количество колонок у базового объекта спецификации
      int count = specification->ksGetSpcTableColumn( 0, 0, 0 );

      char buf[128];
      ::sprintf( buf, "Кол-во колонок = %i", count );
      kompas->ksMessage( TO_OLE(buf) );

      // пройдем по всем колонкам
      for ( int i = 1; i <= count; i++ )
      {
        //для текущего номера определим тип колонки, номер исполнения и блок
        ksSpcColumnParamPtr spcColPar( (ksSpcColumnParam*)kompas->GetParamStruct(ko_SpcColumnParam), false/*AddRef*/ );
        if ( !spcColPar ) {
          iter->ksDeleteIterator();
          return;
        }
        if ( specification->ksGetSpcColumnType( obj,          //объект спецификации
                              i,      // номер колонки, начиная с 1
                              spcColPar ))
        {
          //возьмем текст
          long columnType = spcColPar->columnType;
          long ispoln = spcColPar->ispoln;
          long block = spcColPar->block;
          char buf[255];
          long res;
					::sprintf( buf, "%s", WideToAnsi(specification->ksGetSpcObjectColumnText( obj, columnType, ispoln, block )) );
          if ( res != -1 )
            kompas->ksMessage( TO_OLE(buf) );
          //по типу колонки, номеру исполнения и блоку определим номер колонки
          int colNumb = specification->ksGetSpcColumnNumb( obj,         //объект спецификации
                                                           columnType,
                                                           ispoln,
                                                           block );
          ::sprintf ( buf, "i = %d colNumb =%d", i, colNumb );
          kompas->ksMessage( TO_OLE(buf) );
        }
      }
      obj = iter->ksMoveIterator( TO_OLE(L"N") );
    }
    iter->ksDeleteIterator();
  }
  else
    kompas->ksError( TO_OLE(L"Спецификация должна быть текущей") );
}

