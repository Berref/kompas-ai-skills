unit Step22a;
//********************************************************************/
//*                (c)Акционерное общество АСКОН                     */
//*                Санкт-Петербург, 1991, 1996                       */
//*                 Компас-Мастер  версия 5.x                        */
//********************************************************************/
//*                    Библиотека примеров                           */
//*          использования динамических массивов                     */
//*                                                                  */
//* 1. Массив строк                           - StrIndefiniteArray   */
//* 2. Массив математических точек            - PointIndefiniteArray */
//* 3. Массив строк объекта "текст"           - TextIndefiniteArray  */
//* 4. Массив колонок типа атрибута           - AttrIndefiniteArray  */
//* 5. Массив полилиний                       - PolyLineArray        */
//* 6. Массив габаритных прямоугольников      - RectArray            */
//* 7. Массив структур пользователя           - UserDataArray        */
//* 8. Массив экземпляров класса пользователя - UserClassArray       */
//*                                                                  */
//********************************************************************/

interface

//-------------------------------------------------------------------------------
// Описания используемых функций
// ---
  procedure  LIBRARYENTRY(comm: Word); pascal;
  function   LIBRARYID: Cardinal; pascal;

  procedure  StrIndefiniteArray;
  procedure  PointIndefiniteArray;
  procedure  TextIndefiniteArray;
  procedure  AttrIndefiniteArray;
  procedure  PolyLineArray;
  procedure  RectArray;


implementation

uses Windows, SysUtils, LtDefine, LibTool, LDefin2D;

//----------------------------------------------------------------------------------------
// Задать идентификатор ресурсов
// ---
function LIBRARYID: Cardinal; pascal;
begin
  LIBRARYID := 100;
end;

//----------------------------------------------------------------------------------------
// Головная функция библиотеки
// ---
procedure LIBRARYENTRY(comm: Word); pascal;
begin
  case Comm of
    1: StrIndefiniteArray;   //массив строк
    2: PointIndefiniteArray; //массив точек
    3: TextIndefiniteArray;  //массив строк объекта "текст"
    4: AttrIndefiniteArray;  //массив колонок типа атрибута
    5: PolyLineArray;        //массив полилиний
    6: RectArray;            //массив габаритных прямоугольников
  end;
end;

//--------------------------------------------------------------------------
//  массив предназначен для хранения строк
//--------------------------------------------------------------------------
procedure StrIndefiniteArray;
var
  rArString : Reference;    //массив строк
  buf       : array [0..128] of AnsiChar;

  //--------------------------------------------------------------------------
  //  вывод массива строк
  procedure ShowArray;
  var
    i : Integer;
    s : AnsiString;
    n : Integer;
  begin
    // Количество элементов
    n := GetArrayCount( rArString );
    s := Format( 'count=%d', [n] );
    ksMessage( PAnsiChar(s) );
    // Вывод строк
    for i:= 0 to n - 1 do
    begin
      // Получить значение элемента массива
      GetArrayItem( rArString, i, @buf, SizeOf(buf) );
      ksMessage( buf );
    end;
  end;

begin
  // Создать массив для хранения строк
  rArString := CreateArray( CHAR_STR_ARR, nil );

  //наполним массив
  // Добавим 1-ю строку, элемент добавляется в конец массива
  StrCopy( buf, '12345' );
  AddArrayItem( rArString, -1, @buf, StrLen(buf) + 1 );

  // Добавим 2-ю строку, элемент добавляется в конец массива
  StrCopy( buf, '67890' );
  AddArrayItem( rArString, -1, @buf, StrLen(buf) + 1 );

  // Добавим 3-ю строку, элемент добавляется в конец массива
  StrCopy( buf, 'qwerty' );
  AddArrayItem( rArString, -1, @buf, StrLen(buf) + 1 );

  MessageBoxResult;
  //просмотрим массив
  ShowArray;
  ksMessage( 'Удалим 1-й элемент' );
  //исключить из массива эл 1
  ExcludeArrayItem( rArString, 1 );
  //просмотрим массив
  ShowArray;
  MessageBoxResult;
  //удалим  массив
  DeleteArray( rArString );
end;

//--------------------------------------------------------------------------
//  массив предназначен для хранения математических точек типа  MathPointParam
//--------------------------------------------------------------------------
procedure PointIndefiniteArray;
var
  rArMathPoint : Reference;
  par          : MathPointParam;

  //--------------------------------------------------------------------------
  //  вывод массива точек
  procedure ShowPointArray;
  var
    s   : AnsiString;
    n, i: Integer;
  begin
    n := GetArrayCount(rArMathPoint);
    s := Format('count=%d ', [n]);
    ksMessage(PAnsiChar(s));

    for i := 0 to n - 1 do
    begin
      GetArrayItem(rArMathPoint, i, @par, SizeOf(MathPointParam));
      s := Format('i=%d  x=%5.1f y=%5.1f',[i, par.x, par.y]);
      ksMessage(PAnsiChar(s));
    end;
  end;

  //--------------------------------------------------------------------------
  // заменитькомпонент по индексу
  procedure SetPointItem(index: Integer; x, y: Double);
  begin
    par.x := x;
    par.y := y;
    SetArrayItem(rArMathPoint, index, @par, SizeOf(MathPointParam));
  end;

  //--------------------------------------------------------------------------
  // добавить компонент в конец массива
  procedure AddPointItem(x, y: Double);
  begin
    par.x := x;
    par.y := y;
    AddArrayItem(rArMathPoint, -1, @par, SizeOf(MathPointParam));
  end;

begin
  //создать массив
  rArMathPoint := CreateArray(POINT_ARR, nil);
  //наполнить массив
  AddPointItem(10, 10);
  AddPointItem(20, 20);
  AddPointItem(30, 30);
  //убедимся, что нет ошибок
  MessageBoxResult;
  //просмотрим массив
  ShowPointArray;

  ksMessage('заменим параметры 1-го элемента');
  SetPointItem(1, 50, 50);

  ksMessage('заменим параметры 0-го элемента');
  SetPointItem(0, 50, 50);
  //просмотрим массив
  ShowPointArray;
  //убедимся, что нет ошибок
  MessageBoxResult;
  //удалим массив
  DeleteArray(rArMathPoint);
end;

//------------------------------------------------------------------------------
//  массив предназначен для создания и получения параетров параграфа текста,
//  состоящего из   нескольких строк, которые в свою очередь
//  состоят из компонент, с разными параметрами
//  (с наклоном, с утолщением, спецзнаки и т. д.)
//------------------------------------------------------------------------------
procedure TextIndefiniteArray;
var
  pLine, p1: reference;
  par : TextLineParam;
  par1: TextItemParam;
  s: Ansistring;

  //--------------------------------------------------------------------------
  // просмотрим массив компонент
  procedure ShowItemtArray(arr: reference);
  var
    n1, j: Integer;
    s: AnsiString;
  begin
    n1 := GetArrayCount(arr);
    s  := Format('число компонент = %d', [n1]);
    ksMessage(PAnsiChar(s));
    //цикл по компонентам строки текста
    for  j := 0 to n1 - 1 do
    begin
      GetArrayItem(arr, j, @par1, SizeOf(TextItemParam));
      s := Format('j=%d h=%5.1f  s=%s ', [j, par1.font.height, par1.s]);
      ksMessage(PAnsiChar(s));
    end;
  end;

  //--------------------------------------------------------------------------
  // просмотрим массив текста
  procedure ShowTextArray;
  var
    n, i: Integer;
    s: AnsiString;
  begin
    //количество строк
    n := GetArrayCount(pLine);
    s := Format('число строк=%d', [n]);
    ksMessage(PAnsiChar(s));
    // просмотрим массив строк текста
    for i :=0 to n - 1 do //цикл по строкам текста
    begin
      GetArrayItem(pLine, i, @par, SizeOf(TextLineParam));
      s := Format('i=%d style=%d', [i, par.style]);
      ksMessage(PAnsiChar(s));
      ShowItemtArray(par.pTextItem);
    end;
  end;

  //--------------------------------------------------------------------------
  // добавим компонент в массив компонент текста, в конец
  procedure AddTextItem(h, ksu: Double; color: DWord; bitvector: Cardinal; s: PAnsiChar);
  begin
    par1.font.height    := h;         //высота текста
    par1.font.ksu       := ksu;       //сужение текста
    par1.font.color     := color;     //цвет
    par1.font.bitVector := bitvector; //битовый вектор (наклон, толщина, подчеркивание, тип составной части(дробь, отклонение, выражение типа суммы))
    StrCopy(par1.s, s);
    //добавили компоненту  в конец
    AddArrayItem(p1, -1, @par1, SizeOf(TextItemParam));
  end;

  //--------------------------------------------------------------------------
  // заменим компонент в массив компонент текста, в конец
  procedure SetTextItem(index: Integer; h, ksu: Double; color: DWord; bitvector: Cardinal; s: PAnsiChar);
  begin
    par1.font.height    := h;         //высота текста
    par1.font.ksu       := ksu;       //сужение текста
    par1.font.color     := color;     //цвет
    par1.font.bitVector := bitvector; //битовый вектор (наклон, толщина, подчеркивание, тип составной части(дробь, отклонение, выражение типа суммы))
    StrCopy(par1.s, s);
    //добавили компоненту  в конец
    SetArrayItem(par.pTextItem, index, @par1, SizeOf(TextItemParam));
  end;

begin
  //создали массив строк текста
  pLine := CreateArray(TEXT_LINE_ARR, nil);
  s := Format( 'pLine=%d', [pLine] );
  ksMessage( PAnsiChar(s) );
  //массив компонент строки текста
  p1 := CreateArray(TEXT_ITEM_ARR, nil);
  s:=Format('p1=%d', [p1]);
  ksMessage(PAnsiChar(s));
  //создаем первую строку текста
  //добавили 1-ю компоненту  в массив компонент
  AddTextItem(10{h}, 1{ksu}, 1000{color}, 1{bitvector}, '1 компонента 1 строка'{ s });
  //добавили 2-ю компоненту  в массив компонент
  AddTextItem(20{h}, 2{ksu}, 2000{color}, 2{bitvector}, '2 компонента 1 строка'{ s });
  par.style := 1;
  par.pTextItem := p1;
  s := Format('par.pTextItem=%d', [par.pTextItem]);
  ksMessage(PAnsiChar(s));
  // 1-я строка текста состоит из двух компонент добавим строку текста в
  // массив строк текста
  AddArrayItem(pLine, -1, @par, SizeOf(TextLineParam));
  // очистили массив компонент, чтобы использовать для создания второй
  // строки текста
  ClearArray(p1);
  //создаем вторую строку текста
  //добавили 1-ю компоненту  в массив компонент
  AddTextItem(30{h}, 3{ksu}, 3000{color}, 3{bitvector}, '1 компонента 2 строка'{ s });
  //добавили 2-ю компоненту  в массив компонент
  AddTextItem(40{h}, 4{ksu}, 4000{color}, 4{bitvector}, '2 компонента 2 строка'{ s });
  par.style := 2;
  par.pTextItem := p1;
  // 2-я строка текста состоит из двух компонент добавим строку текста в
  // массив строк текста
  AddArrayItem(pLine, -1, @par, SizeOf(TextLineParam));
  MessageBoxResult; // проверяем результат работы нашей функции
  // просмотрим массив строк текста
  ShowTextArray;
  // ShowItemtArray(p1);
  ksMessage('заменим вторую компоненту у первой строки');
  //возьмем параметры строки
  GetArrayItem(pLine, 0, @par, SizeOf(TextLineParam));
  //заменим компонент
  SetTextItem(1{index}, 50{h}, 1{ksu}, 1000{color}, 1{bitvector}, 'замена 2 комп. 1 стр.'{ s });
  par.style := 3;
  //заменим строку
  SetArrayItem(pLine, 0, @par, SizeOf(TextLineParam));

  ksMessage('заменим первую компоненту у второй строки');
  //возьмем параметры строки
  GetArrayItem(pLine, 1, Addr(par), SizeOf(TextLineParam));
  //заменим компонент
  SetTextItem(0{index}, 60{h}, 1{ksu}, 1000{color}, 1{bitvector}, 'замена 1 комп. 2 стр.'{ s });
  par.style := 4;
  //заменим строку
  SetArrayItem(pLine, 1, @par, SizeOf(TextLineParam));
  // просмотрим массив строк текста
  ShowTextArray;
  // проверяем результат работы нашей функции
  MessageBoxResult;
  //удаляем массив компонент
  DeleteArray(p1);
  //удаляем массив строк
  DeleteArray(pLine);
end;

//--------------------------------------------------------------------------
//  массив предназначен для создания и получения типа атрибута,
//  который может состоять из нескольких колонок
//---------------------------------------------------------------------------
procedure AttrIndefiniteArray;
var
  pCol, pStruct: reference ; //указатели  на массив колонок, на массив колонок записи
  pEnum: reference ;         // указатель на массив перечисленных значений
  parCol1, parCol2, parCol3, parStruct: ColumnInfo;
  buf : array[0..128] of AnsiChar;

  //--------------------------------------------------------------------------
  // просмотреть массив колонок
  procedure ShowColumns(pCol : reference; fl : Integer);
  var
    par: ColumnInfo;
    mes: AnsiString;
    s: array [0..10] of AnsiChar;
    i, n, n1, i1: Integer;
  begin
    if  fl>0 then
      StrCopy(s, 'структура')
    else
      StrCopy(s, ' ');

    par.columns := CreateArray(ATTR_COLUMN_ARR, nil);
    par.fieldEnum := CreateArray(CHAR_STR_ARR, nil);
    n := GetArrayCount(pCol);

    for  i := 0 to n - 1 do
    begin
      if GetArrayItem(pCol, i, @par, SizeOf(par)) = 0 then
      MessageBoxResult  // проверяем результат работы нашей функции
      else
      begin
        //выдадим поля колонки не указатели
        mes := Format('%s i=%d header=%s type=%d def=%s flagEnum=%d',
                      [s,i,par.header, par._type, par.def, par.flagEnum ]);
        ksMessage(PAnsiChar(mes));
        if par._type = RECORD_ATTR_TYPE then  //структура
          ShowColumns(par.columns, 1)
        else
        begin
          if par.flagEnum > 0 then //выдадим массив перечислений
          begin
            n1 := GetArrayCount(par.fieldEnum);
            ksMessage('массив перечислений');
            for i1 := 0 to n1 - 1 do
              if GetArrayItem(par.fieldEnum, i1, @buf, SizeOf(buf)) = 0 then
                MessageBoxResult  // проверяем результат работы нашей функции
              else
                ksMessage(buf);
          end;
        end;
      end;
    end;
    DeleteArray(par.columns);
    DeleteArray(par.fieldEnum);
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

  pCol    := CreateArray(ATTR_COLUMN_ARR, nil);
  pStruct := CreateArray(ATTR_COLUMN_ARR, nil);
  pEnum   := CreateArray(CHAR_STR_ARR,    nil);
  // первая колонка
  StrCopy(parCol1.header, 'int');    // заголовoк-комментарий столбца
  parCol1._type := INT_ATTR_TYPE;    // тип данных в столбце - см.ниже
  parCol1.key := 0;                  // дополнительный признак, который позволит отличить две переменные с одинаковым типом
  StrCopy(parCol1.def, '100');       // значение по умолчанию
  parCol1.flagEnum :=1;              // флаг включающий режим, когда значение поля атрибута
                                     // будет заполнятся из массива перечисленных значений 1 и 0 отключон
  parCol1.fieldEnum := pEnum;        // массив неопределенной длины перечислений (строки)
  parCol1.columns := 0;              // массив неопределенной длины информации о колонках для записи
  //заполним массив перечисленных значений для первой колонки
  StrCopy(buf, '100');
  AddArrayItem(pEnum, -1, @buf, StrLen(buf) + 1);
  StrCopy(buf, '200');
  AddArrayItem(pEnum, -1, @buf, StrLen(buf) + 1);
  StrCopy(buf, '300');
  AddArrayItem(pEnum, -1, @buf, StrLen(buf) + 1);
  MessageBoxResult;  // проверяем результат работы нашей функции

  AddArrayItem(pCol, -1, @parCol1, SizeOf(parCol1));
  MessageBoxResult;  // проверяем результат работы нашей функции
  // вторая колонка
  StrCopy(parCol2.header, 'struct'); // заголовoк-комментарий столбца
  parCol2._type := RECORD_ATTR_TYPE; // тип данных в столбце - см.ниже
  parCol2.key := 0;                  // дополнительный признак, который позволит отличить две переменные с одинаковым типом
  StrCopy(parCol2.def,' ');          // значение по умолчанию
  parCol2.flagEnum := 0;             // флаг включающий режим, когда значение поля атрибута
                                     // будет заполнятся из массива перечисленных значений 1 и 0 отключон
  parCol2.fieldEnum := 0;            // массив неопределенной длины перечислений (строки)
  parCol2.columns := pStruct;        // массив неопределенной длины информации о колонках для записи

  //заполним массив солонок для структуры
  // первая колонка  структуры
  StrCopy(parStruct.header, 'Double');  // заголовoк-комментарий столбца
  parStruct._type := Double_ATTR_TYPE;  // тип данных в столбце - см.ниже
  parStruct.key := 0;                   // дополнительный признак, который позволит отличить две переменные с одинаковым типом
  StrCopy(parStruct.def,'123456789');   // значение по умолчанию
  parStruct.flagEnum :=0;               // флаг включающий режим, когда значение поля атрибута
                                        // будет заполнятся из массива перечисленных значений 1 и 0 отключон
  parStruct.fieldEnum := 0;             // массив неопределенной длины перечислений (строки)
  parStruct.columns := 0;               // массив неопределенной длины информации о колонках для записи

  AddArrayItem(pStruct, -1, @parStruct, SizeOf(parStruct));
  MessageBoxResult;  // проверяем результат работы нашей функции

  // вторая колонка структуры
  StrCopy(parStruct.header, 'long');   // заголовoк-комментарий столбца
  parStruct._type := LINT_ATTR_TYPE;   // тип данных в столбце - см.ниже
  parStruct.key := 0;                  // дополнительный признак, который позволит отличить две переменные с одинаковым типом
  StrCopy(parStruct.def, '1000000');   // значение по умолчанию
  parStruct.flagEnum :=0;              // флаг включающий режим, когда значение поля атрибута
                                       // будет заполнятся из массива перечисленных значений 1 и 0 отключон
  parStruct.fieldEnum := 0;            // массив неопределенной длины перечислений (строки)
  parStruct.columns := 0;              // массив неопределенной длины информации о колонках для записи

  AddArrayItem(pStruct, -1, @parStruct, SizeOf(parStruct));
  MessageBoxResult;  // проверяем результат работы нашей функции

  // третья колонка структуры
  StrCopy(parStruct.header, 'Char');   // заголовoк-комментарий столбца
  parStruct._type := Char_ATTR_TYPE;   // тип данных в столбце - см.ниже
  parStruct.key := 0;                  // дополнительный признак, который позволит отличить две переменные с одинаковым типом
  StrCopy(parStruct.def, '10');        // значение по умолчанию
  parStruct.flagEnum := 0;             // флаг включающий режим, когда значение поля атрибута
                                       // будет заполнятся из массива перечисленных значений 1 и 0 отключон
  parStruct.fieldEnum := 0;            // массив неопределенной длины перечислений (строки)
  parStruct.columns := 0;              // массив неопределенной длины информации о колонках для записи

  AddArrayItem(pStruct, -1, @parStruct, SizeOf(parStruct));
  MessageBoxResult;  // проверяем результат работы нашей функции

  AddArrayItem(pCol, -1, @parCol2, SizeOf(parCol2));
  MessageBoxResult;  // проверяем результат работы нашей функции

  // третья  колонка
  StrCopy(parCol3.header, 'string');   // заголовoк-комментарий столбца
  parCol3._type := STRING_ATTR_TYPE;   // тип данных в столбце - см.ниже
  parCol3.key := 0;                    // дополнительный признак, который позволит отличить две переменные с одинаковым типом
  StrCopy(parCol3.def, 'text');        // значение по умолчанию
  parCol3.flagEnum :=0;                // флаг включающий режим, когда значение поля атрибута
                                       // будет заполнятся из массива перечисленных значений 1 и 0 отключон
  parCol3.fieldEnum := 0;              // массив неопределенной длины перечислений (строки)
  parCol3.columns := 0;                // массив неопределенной длины информации о колонках для записи
  AddArrayItem(pCol, -1, @parCol3, SizeOf(parCol3));

  MessageBoxResult;  // проверяем результат работы нашей функции
  //просмотрим массив колонок
  ShowColumns(pCol, 0); // функция пользователя

  MessageBoxResult;  // проверяем результат работы нашей функции
  //поменяем  колонки местами 2->1 1->3 3->2
  SetArrayItem(pCol, 0, @parCol2, SizeOf(parCol2));
  SetArrayItem(pCol, 2, @parCol1, SizeOf(parCol2));
  SetArrayItem(pCol, 1, @parCol3, SizeOf(parCol2));
  //просмотрим массив колонок
  ShowColumns(pCol, 0); // функция пользователя

  MessageBoxResult;  // проверяем результат работы нашей функции

  DeleteArray(pCol);
  DeleteArray(pStruct);
  DeleteArray(pEnum);
end;


//-------------------------------------------------------------------------------
// массив полилиний это массив массивов математических точек
//-------------------------------------------------------------------------------
procedure PolyLineArray;
var
  p, pPoly: reference;
  buf: AnsiString;
  par: PointParam;

  //--------------------------------------------------------------------------
  // показать массив точек
  procedure ShowArrPoint(p: reference);
  var
    n, i : Integer;
  begin
    n := GetArrayCount(p);
    buf := Format('количество точек = %d', [n]);
    ksMessage(PAnsiChar(buf));
    for i := 0 to n - 1 do
    begin
      GetArrayItem(p, i, @par, SizeOf(PointParam));
      buf := Format('i=%d x=%5.1f y=%5.1f', [i, par.x, par.y]);
      ksMessage(PAnsiChar(buf));
    end;
  end;

  //--------------------------------------------------------------------------
  // показать массив полилиний
  procedure ShowArrPolyline;
  var
    n, i: Integer;
  begin
    n := GetArrayCount(pPoly);
    buf := Format('количество полилиний = %d',[n]);
    ksMessage(PAnsiChar(buf));

    for i := 0 to n - 1 do
    begin
      GetArrayItem(pPoly, i, @p, SizeOf(p));
      //просмоьрим i-ый элемент массива полилиний
      ShowArrPoint(p);
    end;
  end;

  //--------------------------------------------------------------------------
  // заполнение массива полилиний
  procedure FillArrPoint(x1, y1, x2, y2, x3, y3: Double; index: Integer);
  begin
    ClearArray(p);
    //наполним массив точек
    par.x := x1;
    par.y := y1;
    AddArrayItem(p, -1, @par, SizeOf(PointParam));
    par.x := x2;
    par.y := y2;
    AddArrayItem(p, -1, @par, SizeOf(PointParam));
    par.x := x3;
    par.y := y3;
    AddArrayItem(p, -1, @par, SizeOf(PointParam));
    //добавим массив точек в массив полилиний
    if index = -1 then
      AddArrayItem(pPoly, index, @p, SizeOf(p))
    else
      SetArrayItem(pPoly, index, @p, SizeOf(p));
//    MessageBoxResult;
//    ShowArrPoint(p);
  end;

begin
  //создадим массив точек
  p := CreateArray(POINT_ARR, nil);
  //создадим массив полилиний
  pPoly := CreateArray(POLYLINE_ARR, nil);
  //наполним массив точек
  FillArrPoint(10, 10, 100, 100, 1000, 1000, -1);
  //наполним массив точек
  FillArrPoint(20, 20, 200, 200, 2000, 2000, -1);
  //наполним массив точек
  FillArrPoint(30, 30, 300, 300, 3000, 3000, -1);
  //просмотрим полилилнию
  ShowArrPolyline;

  ksMessage('заменим у массива полилиний 2-ой элемент');
  //наполним массив точек
  FillArrPoint(50, 50, 500, 500, 5000, 5000, 1);
  //просмотрим полилилнию
  ShowArrPolyline;

  MessageBoxResult;
  //удалим массивы
  DeleteArray(p);
  DeleteArray(pPoly);
end;

//--------------------------------------------------------------------------------
// массив неопределенной длины габаритных прямоугольников-(структура RectParam)
//--------------------------------------------------------------------------------
procedure RectArray;
var
  p: reference;
  buf: AnsiString;
  par: RectParam;

  //--------------------------------------------------------------------------
  // показать массив
  procedure ShowArrRect;
  var
    n, i: Integer;
  begin
    n := GetArrayCount(p);
    buf := Format('количество прямоугольников = %d',[n]);
    ksMessage(PAnsiChar(buf));
    for i := 0 to n - 1 do
    begin
      GetArrayItem(p, i, @par, SizeOf(RectParam));
      buf := Format('i=%d  xTop=%5.1f yTop=%5.1f, xBot=%5.1f yBot=%5.1f',
                    [i,par.pTop.x, par.pTop.y,par.pBot.x, par.pBot.y]);
      ksMessage(PAnsiChar(buf));
    end;
  end;

  //--------------------------------------------------------------------------
  // добавить или заменить член массива
  procedure AddOrSetItem(xTop, yTop,xBot,yBot : Double; index : Integer);
  begin
    //наполнить массив
    par.pTop.x := xTop;
    par.pTop.y := yTop;
    par.pBot.x := xBot;
    par.pBot.y := yBot;
    if index = -1 then
      AddArrayItem(p, -1, @par, SizeOf(RectParam))
    else
      SetArrayItem(p, index, @par, SizeOf(RectParam));
  end;

begin
  //создать массив
  p := CreateArray(RECT_ARR, nil);
  //наполнить массив
  AddOrSetItem(10, 10, 20, -10, -1);
  AddOrSetItem(20, 50, 50, 10, -1);
  AddOrSetItem(20, 150, 50, 110, -1);

  MessageBoxResult;
  //просмотреть массив
  ShowArrRect;
  //редактируем массив
  AddOrSetItem(-20, -50, 20, -10, 1);
  AddOrSetItem(0, 0, 10, -20, 0);
  AddOrSetItem(5, 5, 25, 0, -1);
  //просмотрим массив
  ShowArrRect;

  MessageBoxResult;
  //удалить массив
  DeleteArray(p);
end;

end.
