unit step2a1;

{$IFDEF CONDITIONALEXPRESSIONS}
{$IF CompilerVersion >= 14 }
  {$WARN SYMBOL_PLATFORM OFF}
{$IFEND}
{$ENDIF}


interface
  procedure  LIBRARYENTRY( command: WORD  ); Pascal;
  function   LIBRARYNAME : PAnsiChar;        Pascal;
  function   LIBRARYID   : Cardinal;         Pascal;
implementation
uses
  Windows,
  SysUtils,
  LDefin2D,
  ksConstTLB,
  ksAuto,
{$IFDEF __LIGHT_VERSION__}
  klTLB;
{$ELSE}
  ksTLB;
{$ENDIF}

var
  iKompasObject: KompasObject;

//------------------------------------------------------------------------------
// Массив строк
//---
procedure StrIndefiniteArray;
var
  iDynamicArray: ksDynamicArray;
  iChar255: ksChar255;

  // просмотреть массив
  procedure ShowArray;
  var
    i, count: Integer;

  begin
    count := iDynamicArray.ksGetArrayCount;

    iKompasObject.ksMessage( PChar('count = ' + IntToStr(count)) );

    for i := 0 to count - 1 do
    begin
      iDynamicArray.ksGetArrayItem( i, iChar255 );
      iKompasObject.ksMessage( iChar255.str );
    end;
  end;

begin
  // создадим массив
  iDynamicArray := ksDynamicArray(iKompasObject.GetDynamicArray( CHAR_STR_ARR ));
  iChar255 := ksChar255(iKompasObject.GetParamStruct( ko_Char255 ));

  if (iDynamicArray <> nil) and (iChar255 <> nil) then
  begin
    iKompasObject.ksMessage('наполним массив');

    iChar255.str := '12345';
    iDynamicArray.ksAddArrayItem( -1, iChar255 );

    iChar255.str := '67890';
    iDynamicArray.ksAddArrayItem( -1, iChar255 );

    iChar255.str := 'qwerty';
    iDynamicArray.ksAddArrayItem( -1, iChar255 );

    iKompasObject.ksMessageBoxResult;

    // просмотрим массив
    ShowArray;

    iKompasObject.ksMessage('удалим 1-й элемент');

    iDynamicArray.ksExcludeArrayItem( 1 );

    // просмотрим массив
    ShowArray;

    // удалим массив
    iDynamicArray.ksDeleteArray;
  end;
end;

//------------------------------------------------------------------------------
// Массив точек
//---
procedure PointIndefiniteArray;
var
  iDynamicArray: ksDynamicArray;
  iMathPointParam: ksMathPointParam;
  buf: string;

  // просмотреть массив
  procedure ShowArray;
  var
    i, count: Integer;

  begin
    count := iDynamicArray.ksGetArrayCount;

    iKompasObject.ksMessage( PChar('count = ' + IntToStr(count)) );

    for i := 0 to count - 1 do
    begin
      iDynamicArray.ksGetArrayItem( i, iMathPointParam );
      buf := Format( '%d:  x = %5.1f  y = %5.1f', [i, iMathPointParam.x, iMathPointParam.y] );
      iKompasObject.ksMessage( buf );
    end;
  end;

  // добавить элемент в конец массива
  procedure AddPointItem( x, y: Double );
  begin
    iMathPointParam.x := x;
    iMathPointParam.y := y;
    iDynamicArray.ksAddArrayItem( -1, iMathPointParam );
  end;

  // заменить элемент по индексу
  procedure SetPointItem( i: Integer; x, y: Double );
  begin
    iMathPointParam.x := x;
    iMathPointParam.y := y;
    iDynamicArray.ksSetArrayItem( i, iMathPointParam );
  end;

begin
  // создадим массив
  iDynamicArray := ksDynamicArray(iKompasObject.GetDynamicArray( POINT_ARR ));
  iMathPointParam := ksMathPointParam(iKompasObject.GetParamStruct( ko_MathPointParam ));

  if (iDynamicArray <> nil) and (iMathPointParam <> nil) then
  begin
    iKompasObject.ksMessage('наполним массив');

    AddPointItem( 10, 10 );
    AddPointItem( 20, 20 );
    AddPointItem( 30, 30 );

    iKompasObject.ksMessageBoxResult;

    // просмотрим массив
    ShowArray;

    iKompasObject.ksMessage( 'заменим параметры 1-го элемента' );
    SetPointItem( 1, 50, 50 );

    iKompasObject.ksMessage( 'заменим параметры 0-го элемента' );
    SetPointItem( 0, 50, 50 );

    // просмотрим массив
    ShowArray;

    // удалим массив
    iDynamicArray.ksDeleteArray;
  end;
end;

//------------------------------------------------------------------------------
// Массив строк объекта "текст"
//---
procedure TextIndefiniteArray;
var
  iDynamicArrayLine: ksDynamicArray;
  iDynamicArrayItem: ksDynamicArray;
  iTextItemParam: ksTextItemParam;
  iTextLineParam: ksTextLineParam;
  iTextItemFont: ksTextItemFont;
  buf: string;

  // просмотрим массив текста
  procedure ShowTextArray;
  var
    i, count: Integer;

    // просмотрим массив компонент
    procedure ShowItemtArray( iDynamicArray: ksDynamicArray );
    var
      i, count: Integer;

    begin
      if iDynamicArray <> nil then
      begin
        count := iDynamicArray.ksGetArrayCount;

        iKompasObject.ksMessage( PChar('число компонент = ' + IntToStr(count)) );

        // цикл по компонентам строки текста
        for  i := 0 to count - 1 do
        begin
          iDynamicArray.ksGetArrayItem( i, iTextItemParam );
          iTextItemFont := ksTextItemFont( iTextItemParam.GetItemFont );
          buf := Format( '%d:  h = %5.1f  s = %s ', [i, iTextItemFont.height, iTextItemParam.s] );
          iKompasObject.ksMessage( buf );
        end;
      end;
    end;

  begin
    // количество строк
    count := iDynamicArrayLine.ksGetArrayCount;

    iKompasObject.ksMessage( PChar('число строк = ' + IntToStr(count)) );

    // цикл по строкам текста
    for  i := 0 to count - 1 do
    begin
      iDynamicArrayLine.ksGetArrayItem( i, iTextLineParam );
      buf := Format( '%d:  style = %d', [i, iTextLineParam.style] );
      iKompasObject.ksMessage( buf );
      ShowItemtArray( ksDynamicArray(iTextLineParam.GetTextItemArr) );
    end;
  end;

  // добавим компонент в массив компонент текста, в конец
  procedure AddOrSetTextItem( h, ksu: Double; color: DWORD; bitvector: UINT; s: string; i: Integer );
  begin
    iTextItemFont := ksTextItemFont( iTextItemParam.GetItemFont );
    iTextItemFont.height := h;    // высота текста
    iTextItemFont.ksu := ksu;     // сужение текста
    iTextItemFont.color := color; // цвет
    iTextItemFont.bitVector := bitvector; // битовый вектор (наклон, толщина, подчеркивание, тип составной части(дробь, отклонение, выражение типа суммы))
    iTextItemParam.SetItemFont( iTextItemFont );
    iTextItemParam.s := s;
    //добавили компоненту
    if i = -1 then
       iDynamicArrayItem.ksAddArrayItem( -1, iTextItemParam )
    else
       iDynamicArrayItem.ksSetArrayItem( i, iTextItemParam );
  end;

begin
  // создадим массив строк текста
  iDynamicArrayLine := ksDynamicArray(iKompasObject.GetDynamicArray( TEXT_LINE_ARR ));
  // создадим массив компонент строки текста
  iDynamicArrayItem := ksDynamicArray(iKompasObject.GetDynamicArray( TEXT_ITEM_ARR ));

  iTextLineParam := ksTextLineParam(iKompasObject.GetParamStruct( ko_TextLineParam ));
  iTextItemParam := ksTextItemParam(iKompasObject.GetParamStruct( ko_TextItemParam ));

  if (iDynamicArrayLine <> nil) and (iDynamicArrayItem <> nil) and
     (iTextLineParam <> nil) and (iTextItemParam <> nil) then
  begin
    iKompasObject.ksMessage( 'создаем первую строку текста' );
    // добавили 1-ю компоненту в массив компонент
    AddOrSetTextItem( 10{h}, 1{ksu}, 1000{color}, 1{bitvector}, '1 компонента 1 строка'{s}, -1 );
    // добавили 2-ю компоненту в массив компонент
    AddOrSetTextItem( 20{h}, 2{ksu}, 2000{color}, 2{bitvector}, '2 компонента 1 строка'{s}, -1 );

    iTextLineParam.style := 1;
    iTextLineParam.SetTextItemArr( iDynamicArrayItem );
    // 1-я строка текста состоит из двух компонент добавим строку текста в массив строк текста
    iDynamicArrayLine.ksAddArrayItem( -1, iTextLineParam );
    iKompasObject.ksMessageBoxResult;
    // очистили массив компонент, чтобы использовать для создания второй строки текста
    iDynamicArrayItem.ksClearArray;

    iKompasObject.ksMessage( 'создаем вторую строку текста' );
    // добавили 1-ю компоненту в массив компонент
    AddOrSetTextItem( 30{h}, 3{ksu}, 3000{color}, 3{bitvector}, '1 компонента 2 строка'{s}, -1 );
    // добавили 2-ю компоненту в массив компонент
    AddOrSetTextItem( 40{h}, 4{ksu}, 4000{color}, 4{bitvector}, '2 компонента 2 строка'{s}, -1 );

    iTextLineParam.style := 2;
    // 2-я строка текста состоит из двух компонент добавим строку текста в массив строк текста
    iDynamicArrayLine.ksAddArrayItem( -1, iTextLineParam );
    iKompasObject.ksMessageBoxResult;

    // просмотрим массив строк текста
    ShowTextArray;

    iKompasObject.ksMessage( 'заменим вторую компоненту у первой строки' );
    // возьмем параметры строки
    iDynamicArrayLine.ksGetArrayItem( 0, iTextLineParam );
    // заменим компонент
    AddOrSetTextItem( 50{h}, 1{ksu}, 1000{color}, 1{bitvector}, '(замена) 2 компонента 1 строка'{s}, 1 );
    iTextLineParam.style := 3;
    // заменим строку
    iDynamicArrayLine.ksSetArrayItem( 0, iTextLineParam );

    iKompasObject.ksMessage('заменим первую компоненту у второй строки');
    // возьмем параметры строки
    iDynamicArrayLine.ksGetArrayItem( 1, iTextLineParam );
    // заменим компонент
    AddOrSetTextItem( 60{h}, 1{ksu}, 1000{color}, 1{bitvector}, '(замена) 1 компонента 2 строка'{s}, 0 );
    iTextLineParam.style := 4;
    // заменим строку
    iDynamicArrayLine.ksSetArrayItem( 1, iTextLineParam );
    // просмотрим массив строк текста
    ShowTextArray;

    // удаляем массив компонент строки текста
    iDynamicArrayItem.ksDeleteArray;
    // удаляем массив строк текста
    iDynamicArrayLine.ksDeleteArray;
  end;
end;

//------------------------------------------------------------------------------
// Массив колонок типа атрибута
//---
procedure AttrIndefiniteArray;
var
  iDynamicArrayAttrColumn1: ksDynamicArray;
  iDynamicArrayAttrColumn2: ksDynamicArray;
  iColumnInfoParam1,
  iColumnInfoParam2,
  iColumnInfoParam3,
  iColumnInfoParamStruct: ksColumnInfoParam;
  iDynamicArrayCharStr: ksDynamicArray;
  iChar255: ksChar255;
  buf: string;

  // просмотреть массив колонок
  procedure ShowColumns( iDynamicArray: ksDynamicArray; r: Boolean );
  var
    iColumnInfoParam: ksColumnInfoParam;
    iDynamicArrayColumn: ksDynamicArray;
    iDynamicArrayFieldEnum: ksDynamicArray;
    iChar255: ksChar255;
    s: string;
    i, j, f: Integer;

  begin
    if iDynamicArray <> nil then
    begin
      iColumnInfoParam := ksColumnInfoParam(iKompasObject.GetParamStruct( ko_ColumnInfoParam ));
      iChar255 := ksChar255(iKompasObject.GetParamStruct( ko_Char255 ));

      if (iColumnInfoParam <> nil) and (iChar255 <> nil) then
      begin
        iDynamicArrayColumn := ksDynamicArray(iColumnInfoParam.GetColumns);
        iDynamicArrayFieldEnum := ksDynamicArray(iColumnInfoParam.GetFieldEnum);

        if (iDynamicArrayColumn <> nil) and (iDynamicArrayFieldEnum <> nil) then
        begin
          if r then
            s := 'структура'
          else
            s := '';

          for i := 0 to iDynamicArray.ksGetArrayCount - 1 do
          begin
            if iDynamicArray.ksGetArrayItem(i, iColumnInfoParam) = 1 then
            begin
              // выдадим поля колонки не указатели
              if iColumnInfoParam.flagEnum then
                f := 1
              else
                f := 0;

              buf := Format( '%s %d  header = %s  type = %d  def = %s  flagEnum = %d',
                             [s, i, iColumnInfoParam.header, iColumnInfoParam.type_, iColumnInfoParam.def, f] );

              iKompasObject.ksMessage( buf );

              if iColumnInfoParam.type_ = RECORD_ATTR_TYPE then // структура
                ShowColumns( ksDynamicArray(iColumnInfoParam.GetColumns), true )
              else
              begin
                if iColumnInfoParam.flagEnum then // выдадим массив перечислений
                begin
                  iDynamicArrayFieldEnum := ksDynamicArray(iColumnInfoParam.GetFieldEnum);
                  iKompasObject.ksMessage( 'массив перечислений' );

                  for j := 0 to iDynamicArrayFieldEnum.ksGetArrayCount - 1 do
                  begin
                    if( iDynamicArrayFieldEnum.ksGetArrayItem(j, iChar255) = 1 ) then
                      iKompasObject.ksMessage( iChar255.str )
                    else
                      iKompasObject.ksMessageBoxResult();
                  end;
                end;
              end;
            end
            else
              iKompasObject.ksMessageBoxResult;
          end;
        end;
      end;
    end;
  end;

begin
// создадим массив из 3 колонок
// первая колонка описывает  int с перечисленными значениями (100, 200, 300)
// вторая колонка - запись соответствует структуре
// struct
//   Double  умолчательное значение 123456789
//   long    умолчательное значение 1000000
//   Char    умолчательное значение 10
// третья колонка строка символов умолчательное значение "text"

  // создадим массивы и структуры
  iDynamicArrayAttrColumn1 := ksDynamicArray(iKompasObject.GetDynamicArray( ATTR_COLUMN_ARR ));
  iDynamicArrayAttrColumn2 := ksDynamicArray(iKompasObject.GetDynamicArray( ATTR_COLUMN_ARR ));
  iColumnInfoParam1 := ksColumnInfoParam(iKompasObject.GetParamStruct( ko_ColumnInfoParam ));
  iColumnInfoParam2 := ksColumnInfoParam(iKompasObject.GetParamStruct( ko_ColumnInfoParam ));
  iColumnInfoParam3 := ksColumnInfoParam(iKompasObject.GetParamStruct( ko_ColumnInfoParam ));
  iColumnInfoParamStruct := ksColumnInfoParam(iKompasObject.GetParamStruct( ko_ColumnInfoParam ));
  iDynamicArrayCharStr := ksDynamicArray(iKompasObject.GetDynamicArray( CHAR_STR_ARR ));
  iChar255 := ksChar255(iKompasObject.GetParamStruct( ko_Char255 ));

  if (iDynamicArrayAttrColumn1 <> nil) and (iDynamicArrayAttrColumn2 <> nil) and
     (iColumnInfoParam1 <> nil) and (iColumnInfoParam2 <> nil) and (iColumnInfoParam3 <> nil) and
     (iColumnInfoParamStruct <> nil) and ( iDynamicArrayCharStr <> nil) and (iChar255 <> nil) then
  begin
    iColumnInfoParam1.Init();

    iKompasObject.ksMessage( 'заполним первую колонку' );

    iColumnInfoParam1.header := 'int';           // заголовoк-комментарий столбца
    iColumnInfoParam1.type_ := INT_ATTR_TYPE;    // тип данных в столбце - см.ниже
    iColumnInfoParam1.key := 0;                  // дополнительный признак, который позволит отличить две переменные с одинаковым типом
    iColumnInfoParam1.def := '100';              // значение по умолчанию
    iColumnInfoParam1.flagEnum := true;          // флаг включающий режим, когда значение поля атрибута будет заполнятся из массива перечисленных значений
    iColumnInfoParam1.SetFieldEnum( iDynamicArrayCharStr ); // массив неопределенной длины перечислений (строки)
    iColumnInfoParam1.SetColumns( nil );         // массив неопределенной длины информации о колонках для записи

    iChar255.str := '100';
    iDynamicArrayCharStr.ksAddArrayItem( -1, iChar255 );

    iChar255.str := '200';
    iDynamicArrayCharStr.ksAddArrayItem( -1, iChar255 );

    iChar255.str := '300';
    iDynamicArrayCharStr.ksAddArrayItem( -1, iChar255 );

    iDynamicArrayAttrColumn1.ksAddArrayItem( -1, iColumnInfoParam1 );

    iKompasObject.ksMessageBoxResult;

    iKompasObject.ksMessage( 'заполним вторую колонку' );
    iColumnInfoParam2.header := 'struct';        // заголовoк-комментарий столбца
    iColumnInfoParam2.type_ := RECORD_ATTR_TYPE; // тип данных в столбце - см.ниже
    iColumnInfoParam2.key := 0;                  // дополнительный признак, который позволит отличить две переменные с одинаковым типом
    iColumnInfoParam2.def := '';                 // значение по умолчанию
    iColumnInfoParam2.flagEnum := false;         // флаг включающий режим, когда значение поля атрибута будет заполнятся из массива перечисленных значений
    iColumnInfoParam2.SetFieldEnum( nil );       // массив неопределенной длины перечислений (строки)
    iColumnInfoParam2.SetColumns( iDynamicArrayAttrColumn2 );  // массив неопределенной длины информации о колонках для записи

    iKompasObject.ksMessageBoxResult;

    iKompasObject.ksMessage( 'заполним массив колонок для структуры' );
    iKompasObject.ksMessage( 'первая колонка структуры' );

    iColumnInfoParamStruct.header := 'double';   // заголовoк-комментарий столбца
    iColumnInfoParamStruct.type_ := DOUBLE_ATTR_TYPE; // тип данных в столбце - см.ниже
    iColumnInfoParamStruct.key := 0;             // дополнительный признак, который позволит отличить две переменные с одинаковым типом
    iColumnInfoParamStruct.def := '123456789';   // значение по умолчанию
    iColumnInfoParamStruct.flagEnum := false;    // флаг включающий режим, когда значение поля атрибута будет заполнятся из массива перечисленных значений
    iColumnInfoParamStruct.SetFieldEnum( nil );  // массив неопределенной длины перечислений (строки)
    iColumnInfoParamStruct.SetColumns( nil );    // массив неопределенной длины информации о колонках для записи

    iDynamicArrayAttrColumn2.ksAddArrayItem( -1, iColumnInfoParamStruct );

    iKompasObject.ksMessageBoxResult;

    iKompasObject.ksMessage( 'вторая колонка структуры' );
    iColumnInfoParamStruct.header := 'long';     // заголовoк-комментарий столбца
    iColumnInfoParamStruct.type_ := LINT_ATTR_TYPE; // тип данных в столбце - см.ниже
    iColumnInfoParamStruct.key := 0;             // дополнительный признак, который позволит отличить две переменные с одинаковым типом
    iColumnInfoParamStruct.def := '1000000';     // значение по умолчанию
    iColumnInfoParamStruct.flagEnum := false;    // флаг включающий режим, когда значение поля атрибута будет заполнятся из массива перечисленных значений
    iColumnInfoParamStruct.SetFieldEnum( nil );  // массив неопределенной длины перечислений (строки)
    iColumnInfoParamStruct.SetColumns( nil );    // массив неопределенной длины информации о колонках для записи

    iDynamicArrayAttrColumn2.ksAddArrayItem( -1, iColumnInfoParamStruct );

    iKompasObject.ksMessageBoxResult;

    iKompasObject.ksMessage( 'третья колонка структуры' );
    iColumnInfoParamStruct.header := 'char';      // заголовoк-комментарий столбца
    iColumnInfoParamStruct.type_ := CHAR_ATTR_TYPE; // тип данных в столбце - см.ниже
    iColumnInfoParamStruct.key := 0;              // дополнительный признак, который позволит отличить две переменные с одинаковым типом
    iColumnInfoParamStruct.def := '10';           // значение по умолчанию
    iColumnInfoParamStruct.flagEnum := false;     // флаг включающий режим, когда значение поля атрибута будет заполнятся из массива перечисленных значений
    iColumnInfoParamStruct.SetFieldEnum( nil );   // массив неопределенной длины перечислений (строки)
    iColumnInfoParamStruct.SetColumns( nil );     // массив неопределенной длины информации о колонках для записи

    iDynamicArrayAttrColumn2.ksAddArrayItem( -1, iColumnInfoParamStruct );

    iDynamicArrayAttrColumn1.ksAddArrayItem( -1, iColumnInfoParam2 );

    iKompasObject.ksMessageBoxResult;

    iKompasObject.ksMessage( 'третья колонка' );
    iColumnInfoParam3.header := 'string';        // заголовoк-комментарий столбца
    iColumnInfoParam3.type_ := STRING_ATTR_TYPE; // тип данных в столбце - см.ниже
    iColumnInfoParam3.key := 0;                  // дополнительный признак, который позволит отличить две переменные с одинаковым типом
    iColumnInfoParam3.def := 'text';             // значение по умолчанию
    iColumnInfoParam3.flagEnum := false;         // флаг включающий режим, когда значение поля атрибута будет заполнятся из массива перечисленных значений
    iColumnInfoParamStruct.SetFieldEnum( nil );  // массив неопределенной длины перечислений (строки)
    iColumnInfoParamStruct.SetColumns( nil );    // массив неопределенной длины информации о колонках для записи

    iDynamicArrayAttrColumn1.ksAddArrayItem( -1, iColumnInfoParam3 );

    iKompasObject.ksMessageBoxResult;

    iKompasObject.ksMessage( 'просмотрим массив колонок' );

    ShowColumns( iDynamicArrayAttrColumn1, false );

    iKompasObject.ksMessageBoxResult;

    iKompasObject.ksMessage( 'поменяем колонки местами 2->1 1->3 3->2' );
    iDynamicArrayAttrColumn1.ksSetArrayItem( 0, iColumnInfoParam2 );
    iDynamicArrayAttrColumn1.ksSetArrayItem( 2, iColumnInfoParam1 );
    iDynamicArrayAttrColumn1.ksSetArrayItem( 1, iColumnInfoParam3 );

    iKompasObject.ksMessage( 'просмотрим массив колонок' );

    ShowColumns( iDynamicArrayAttrColumn1, false );

    // удалим массивы
    iDynamicArrayAttrColumn1.ksDeleteArray();
    iDynamicArrayAttrColumn2.ksDeleteArray();
    iDynamicArrayCharStr.ksDeleteArray();
  end;
end;

//------------------------------------------------------------------------------
// Массив полилиний
//---
procedure PolyLineArray;
var
  iDynamicArrayPoint: ksDynamicArray;
  iDynamicArrayPolyline: ksDynamicArray;
  iMathPointParam: ksMathPointParam;
  buf: string;

  // просмотреть массив точек
  procedure ShowArrayPoint();
  var
    i, count: Integer;

  begin
    count := iDynamicArrayPoint.ksGetArrayCount;

    iKompasObject.ksMessage( PChar('количество точек = ' + IntToStr(count)) );

    for i := 0 to count - 1 do
    begin
      iDynamicArrayPoint.ksGetArrayItem( i, iMathPointParam );
      buf := Format( '%d:  x = %5.1f  y = %5.1f', [i, iMathPointParam.x, iMathPointParam.y] );
      iKompasObject.ksMessage( buf );
    end;
  end;

  // просмотреть массив полилиний
  procedure ShowArrayPolyline;
  var
    i, count: Integer;

  begin
    count := iDynamicArrayPolyline.ksGetArrayCount;

    iKompasObject.ksMessage( PChar('количество полилиний = ' + IntToStr(count)) );

    for i := 0 to count - 1 do
    begin
      iDynamicArrayPolyline.ksGetArrayItem( i, iDynamicArrayPoint );
      //просмотрим i-ый элемент массива полилиний
      ShowArrayPoint;
    end;
  end;

  // добавить или заменить элемент массива
  procedure AddOrSetArrayItem( x1, y1, x2, y2, x3, y3: Double; i: Integer );
  begin
    iDynamicArrayPoint.ksClearArray;
    // наполним массив точек
    iMathPointParam.x := x1;
    iMathPointParam.y := y1;
    iDynamicArrayPoint.ksAddArrayItem( -1, iMathPointParam );

    iMathPointParam.x := x2;
    iMathPointParam.y := y2;
    iDynamicArrayPoint.ksAddArrayItem( -1, iMathPointParam );

    iMathPointParam.x := x3;
    iMathPointParam.y := y3;
    iDynamicArrayPoint.ksAddArrayItem( -1, iMathPointParam );

    // добавим массив точек в массив полилиний
    if i = -1 then
       iDynamicArrayPolyline.ksAddArrayItem( -1, iDynamicArrayPoint )
    else
       iDynamicArrayPolyline.ksSetArrayItem( i, iDynamicArrayPoint );
  end;

begin
  // создадим массив точек
  iDynamicArrayPoint := ksDynamicArray(iKompasObject.GetDynamicArray( POINT_ARR ));
  // создадим массив полилиний
  iDynamicArrayPolyline := ksDynamicArray(iKompasObject.GetDynamicArray( POLYLINE_ARR ));

  iMathPointParam := ksMathPointParam(iKompasObject.GetParamStruct( ko_MathPointParam ));

  if (iDynamicArrayPoint <> nil) and (iDynamicArrayPolyline <> nil) and (iMathPointParam <> nil) then
  begin
    iKompasObject.ksMessage('наполним массив полилиний');
    AddOrSetArrayItem( 10, 10, 100, 100, 1000, 1000, -1 );
    AddOrSetArrayItem( 20, 20, 200, 200, 2000, 2000, -1 );
    AddOrSetArrayItem( 30, 30, 300, 300, 3000, 3000, -1 );
    ShowArrayPolyline;

    iKompasObject.ksMessage('заменим у массива полилиний 2-ой элемент');
    AddOrSetArrayItem( 50, 50, 500, 500, 5000, 5000, 1 );
    ShowArrayPolyline;

    // удалим массивы
    iDynamicArrayPoint.ksDeleteArray;
    iDynamicArrayPolyline.ksDeleteArray;
  end;
end;

//------------------------------------------------------------------------------
// Массив габаритных прямоугольников
//---
procedure RectArray;
var
  iDynamicArray: ksDynamicArray;
  iMathPointParam: ksMathPointParam;
  iRectParam: ksRectParam;
  buf: string;

  // просмотреть массив
  procedure ShowArray;
  var
    i, count: Integer;

  begin
    count := iDynamicArray.ksGetArrayCount;

    iKompasObject.ksMessage( PChar('количество прямоугольников = ' + IntToStr(count)) );

    for i := 0 to count - 1 do
    begin
      iDynamicArray.ksGetArrayItem( i, iRectParam );
      iMathPointParam := ksMathPointParam(iRectParam.GetpTop);
      buf := Format( '%d:  xTop = %5.1f  yTop = %5.1f',
                    [i, iMathPointParam.x, iMathPointParam.y] );
      iKompasObject.ksMessage( buf );

      iMathPointParam := ksMathPointParam(iRectParam.GetpBot);
      buf := Format( '%d:  xBot = %5.1f  yBot = %5.1f',
                     [i, iMathPointParam.x, iMathPointParam.y] );
      iKompasObject.ksMessage( buf );
    end;
  end;

  // добавить или заменить элемент массива
  procedure AddOrSetArrayItem( xTop, yTop, xBot, yBot: Double; i: Integer );
  begin
    iMathPointParam.x := xTop;
    iMathPointParam.y := yTop;
    iRectParam.SetpTop( iMathPointParam );

    iMathPointParam.x := xBot;
    iMathPointParam.y := yBot;
    iRectParam.SetpBot( iMathPointParam );

    if i = -1 then
      iDynamicArray.ksAddArrayItem( -1, iRectParam )
    else
      iDynamicArray.ksSetArrayItem( i, iRectParam );
  end;

begin
  // создадим массив
  iDynamicArray := ksDynamicArray(iKompasObject.GetDynamicArray( RECT_ARR ));

  iRectParam := ksRectParam(iKompasObject.GetParamStruct( ko_RectParam ));
  iMathPointParam := ksMathPointParam(iKompasObject.GetParamStruct( ko_MathPointParam ));

  if (iDynamicArray <> nil) and (iRectParam <> nil) and (iMathPointParam <> nil) then
  begin
    iKompasObject.ksMessage('наполним массив');
    AddOrSetArrayItem( 10,  10, 20,  -10, -1 );
    AddOrSetArrayItem( 20,  50, 50,   10, -1 );
    AddOrSetArrayItem( 20, 150, 50,  110, -1 );

    iKompasObject.ksMessageBoxResult;
    // просмотрим массив
    ShowArray;

    // редактируем массив
    AddOrSetArrayItem( -20, -50, 20, -10,  1 );
    AddOrSetArrayItem(   0,   0, 10, -20,  0 );
    AddOrSetArrayItem(   5,   5, 25,   0, -1 );

    // просмотрим массив
    ShowArray;

    // удалим массив
    iDynamicArray.ksDeleteArray;
  end;
end;


//------------------------------------------------------------------------------
// LibraryName
//---
function LIBRARYNAME: PAnsiChar; pascal;
begin
  Result := 'Использованиe динамических массивов';
end;

//------------------------------------------------------------------------------
// LibraryId
//---
function LIBRARYID: UINT; pascal;
begin
  Result := 100;
end;

//------------------------------------------------------------------------------
// LibraryEntry
//---
procedure LIBRARYENTRY(command: WORD); pascal;
begin
  iKompasObject := KompasObject(CreateKompasObject);

  if iKompasObject <> nil then
  begin
    case command of
      1: StrIndefiniteArray;   // массив строк
      2: PointIndefiniteArray; // массив точек
      3: TextIndefiniteArray;  // массив строк объекта "текст"
      4: AttrIndefiniteArray;  // массив колонок типа атрибута
      5: PolyLineArray;        // массив полилиний
      6: RectArray;            // массив габаритных прямоугольников
    end;

    iKompasObject.ksMessageBoxResult;

    iKompasObject := nil;
  end;
end;

end.
