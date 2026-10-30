unit Step88;
//******************************************************************/
//                (c)Акционерное общество АСКОН                   */
//*                Санкт-Петербург, 1991, 1996                     */
//*                 Компас-Мастер  версия 5.x                      */
//******************************************************************/
//*                    Библиотека примеров                         */
//*                    работа с атрибутами
//*                                                                */
//******************************************************************/

interface
 uses  Windows, SysUtils, LtDefine, LibTool, LDefin2D;

 procedure  LIBRARYENTRY( comm: WORD  ); Pascal;
 function   LIBRARYID   : Cardinal;      Pascal;
 procedure FuncTypeAttr;
 procedure DelTypeAttr;
 procedure ShowTypeAttr;
 procedure ChangeType;
 procedure NewAttr;
 procedure DelObjAttr;
 procedure ReadObjAttr;
 procedure ShowObjAttr;
 procedure ShowLib;
 procedure ShowType;
 procedure WalkFromObjWithAttr;
 procedure ShowCol(par : ColumnInfo; iCol : integer; fl:boolean );
 procedure ShowColumns( pCol : reference; fl : boolean );

 implementation

// uses  Sysutils, LtDefine, LibTool;

//----------------------------------------------------------------------------------------
//
//---
function   LIBRARYID : Cardinal;  pascal;
begin
  LIBRARYID:=100;
end;


//----------------------------------------------------------------------------------------
//
//---
procedure  LIBRARYENTRY( comm : Word  );  pascal;
begin
  case  ( comm ) of
   1:begin //создать тип атрибута
     FuncTypeAttr();
     end;
  2:begin //удалить  тип атрибута
     DelTypeAttr();
     end;
  3:begin //получить  тип атрибута
     ShowTypeAttr();
     end;
  4:begin //заменить  тип атрибута
     ChangeType();
     end;
  5:begin //создать атрибут определенного типа
     NewAttr();
     end;
  6:begin //удалить атрибут
     DelObjAttr();
     end;
  7:begin //считать атрибут
     ReadObjAttr();
     end;
  8:begin //просмотреть атрибут
     ShowObjAttr();
     end;
  9:begin //просмотреть библиотеку
     ShowLib();
     end;
  10:begin //просмотреть тип
     ShowType();
     end;
  11:begin //просмотреть атрибут
     WalkFromObjWithAttr();
     end;
  end;
end;


//-------------------------------------------------------------------------
//  создадим  тип атрибута
// соответствует структуре
// struct {
//   double       ;// умолчательное значение 123456789
//   char[MAX_TEXT_LENGTH]   ;// умолчательное значение "string"
//   long        ;// умолчательное значение 1000000
// }
//-------------------------------------------------------------------------
procedure FuncTypeAttr;
var
  pCol      : reference ; //указатели  на массив колонок, на массив колонок записи
  parStruct : ColumnInfo;
  attrType  : ksAttributeType ;
  nameFile  : array [0..260] of AnsiChar;
  numbType  : double;
  buf       : AnsiString;
begin
// создадим массив из 3 колонок

  pCol := CreateArray( ATTR_COLUMN_ARR, nil );

   // первая колонка  структуры
    StrCopy(parStruct.header, 'double');   // заголовoк-комментарий столбца
    parStruct._type := DOUBLE_ATTR_TYPE;    // тип данных в столбце - см.ниже
    parStruct.key   := 0;                    // дополнительный признак, который позволит отличить две переменные с одинаковым типом
    StrCopy(parStruct.def,'123456789');    // значение по умолчанию
    parStruct.flagEnum  :=0;                 // флаг включающий режим, когда значение поля атрибута
                                          // будет заполнятся из массива перечисленных значений 1 и 0 отключон
    parStruct.fieldEnum := 0;              // массив неопределенной длины перечислений (строки)
    parStruct.columns   := 0;                // массив неопределенной длины информации о колонках для записи

    AddArrayItem( pCol, -1, Addr(parStruct), SizeOf(parStruct) );

   // вторая колонка структуры
    StrCopy(parStruct.header, 'str');   // заголовoк-комментарий столбца
    parStruct._type :=STRING_ATTR_TYPE;      // тип данных в столбце - см.ниже
    parStruct.key   := 0;                   // дополнительный признак, который позволит отличить две переменные с одинаковым типом
    StrCopy(parStruct.def,'string');     // значение по умолчанию
    parStruct.flagEnum  :=0;                // флаг включающий режим, когда значение поля атрибута
                                         // будет заполнятся из массива перечисленных значений 1 и 0 отключон
    parStruct.fieldEnum := 0;             // массив неопределенной длины перечислений (строки)
    parStruct.columns   := 0;               // массив неопределенной длины информации о колонках для записи

    AddArrayItem( pCol, -1, Addr(parStruct), SizeOf(parStruct) );

   // третья колонка структуры
    StrCopy(parStruct.header, 'long');   // заголовoк-комментарий столбца
    parStruct._type := LINT_ATTR_TYPE;;     // тип данных в столбце - см.ниже
    parStruct.key   := 0;                   // дополнительный признак, который позволит отличить две переменные с одинаковым типом
    StrCopy(parStruct.def,'1000000');     // значение по умолчанию
    parStruct.flagEnum  :=0;                // флаг включающий режим, когда значение поля атрибута
                                         // будет заполнятся из массива перечисленных значений 1 и 0 отключон
    parStruct.fieldEnum := 0;             // массив неопределенной длины перечислений (строки)
    parStruct.columns   := 0;               // массив неопределенной длины информации о колонках для записи

    AddArrayItem( pCol, -1, Addr(parStruct), SizeOf(parStruct) );

  MessageBoxResult();  // проверяем результат работы нашей функции

//заполним структуру типа атрибута
  StrCopy(attrType.header,'double_str_long');   // заголовoк-комментарий типа
  attrType.rowsCount        := 1;                // кол-во строк в таблице
  attrType.flagVisible      := 1;                // видимый, невидимый   в таблице
  StrCopy(attrType.password,'');            // пароль, если не пустая строка  - защищает от несанкционированного изменения типа
  attrType.columns          := pCol;             // массив неопределенной длины информации о колонках
  attrType.key1 := 10;
  attrType.key2 := 20;
  attrType.key3 := 30;
  attrType.key4 := 0;
//запросить имя библиотеки
 if( ksChoiceFile( '*.lat',nil, nameFile, 260, 0 ) = 0 )then
   strCopy(nameFile,'');  //будем создавать в документе
//создать тип атрибута
 numbType :=  ksCreateAttrType( Addr(attrType),   // информация о типе атрибута
                                     nameFile ); // имя библиотеки типов атрибутов
  if ( numbType > 1 )  then
  begin
    buf := Format( 'numbType=%f', [numbType] );
    ksMessage(PAnsiChar(buf));
  end else
    MessageBoxResult();  // проверяем результат работы нашей функции

 //удалим  массив колонок
 DeleteArray( pCol );

end;


//--------------------------------------------------------------------------
// удалить тип атрибута
//--------------------------------------------------------------------------
procedure DelTypeAttr;
var
 numb : double;
 j : integer;
 nameFile : array [0..260] of AnsiChar;
 password : array [0..11] of AnsiChar;

begin
 //запросить имя библиотеки
 if( ksChoiceFile( '*.lat',nil, nameFile,260,0 ) = 0 ) then
   strCopy(nameFile,''); //будем искать в документе
 repeat
   j := ReadDouble( 'Ввести номер типа атрибута', 1000.,0, 1e12, numb);
   if( j > 0) then
   begin
     j := ReadString( 'Ввести пароль типа атрибута', password, 10 );
     if ( j>0 )  then
     begin
       if( DeleteAttrType( numb, nameFile, password ) = 0) then
         MessageBoxResult  // проверяем результат работы нашей функции
       else
         ksMessage(' тип атрибута удален ');
     end;
   end;
 until( j=0 );
end;

//----------------------------------------------------------------------------
//
procedure  ShowCol(par : ColumnInfo; iCol : integer; fl:boolean );
var
  s : array [0..10] of AnsiChar;
  n1, i1 : integer;
  s1 : array[0..128] of AnsiChar;
  buf : AnsiString;
begin
  if ( fl ) then
    StrCopy(s, 'структура' )
  else
    StrCopy(s,'');

  //выдадим поля колонки не указатели
   buf := Format( '%s i=%d header=%s type=%d def=%s flagEnum=%d',[s,iCol,par.header,
                           par._type, par.def, par.flagEnum]);
  ksMessage( PAnsiChar(buf) );
  if( par._type = RECORD_ATTR_TYPE ) then //структура
    ShowColumns( par.columns,TRUE )
  else begin
    if ( par.flagEnum >0 ) then //выдадим массив перечислений
    begin
      n1 := GetArrayCount( par.fieldEnum );
      ksMessage( 'массив перечислений' );
      for i1:=0 to n1-1 do
      begin
       if(GetArrayItem( par.fieldEnum , i1, Addr(s1), 128) =0) then
          MessageBoxResult()  // проверяем результат работы нашей функции
        else
          ksMessage( s1 );
      end;
    end;
  end;
end;

//----------------------------------------------------------------------------
//
procedure ShowColumns( pCol : reference; fl : boolean );
var
  par : ColumnInfo;
  n, i : integer;
begin
  par.columns := CreateArray( ATTR_COLUMN_ARR, nil );
  par.fieldEnum := CreateArray( CHAR_STR_ARR, nil );
  n := GetArrayCount( pCol );

  for i := 0 to n-1 do
  begin
    if( GetArrayItem( pCol, i, Addr(par), SizeOf(par) ) = 0 ) then
      MessageBoxResult  // проверяем результат работы нашей функции
    else
      ShowCol(par,i, fl );
  end;
  DeleteArray( par.columns );
  DeleteArray( par.fieldEnum );

end;

//--------------------------------------------------------------------------
// получить тип атрибута
//--------------------------------------------------------------------------
procedure ShowTypeAttr;
var
 numb : double ;
 buf : AnsiString;
 nameFile : array [0..128] of AnsiChar;
 attrType : ksAttributeType ;

begin
 attrType.columns := CreateArray( ATTR_COLUMN_ARR, nil );

 //запросить имя библиотеки
 if( ksChoiceFile( '*.lat', nil, nameFile,128, 0 )=0 ) then
   strcopy(nameFile,'');//будем искать в документе
 repeat
   numb := ChoiceAttrTypes ( nameFile );
   if( numb > 0 ) then
   begin
     if ( ksGetAttrType( numb, nameFile, Addr(attrType) ) = 0 )then
       MessageBoxResult()  // проверяем результат работы нашей функции
     else begin
       buf := Format( 'key1 = %d key2 =%d key3 = %d key4 =%d',
                [attrType.key1,attrType.key2,attrType.key3,attrType.key4]);
       ksMessage( PAnsiChar(buf) );
       buf := Format( 'header=%s rowsCount=%d flagVisible=%d password=%s',
                [attrType.header,attrType.rowsCount,attrType.flagVisible,attrType.password]);
       ksMessage( PAnsiChar(buf) );
       ShowColumns( attrType.columns, FALSE ); //пользовательская функция
     end;
   end;
 until( numb = 0);

 //удалим  массив колонок
 DeleteArray( attrType.columns );

end;
//--------------------------------------------------------------------------
// заменить тип атрибута
//--------------------------------------------------------------------------
procedure ChangeType;
var
  numb : double ;
  j : integer;
  nameFile : array [0..128] of AnsiChar;
  password : array [0..11] of AnsiChar;
  attrType : ksAttributeType ;
  par1 : ColumnInfo ;  //структура для первой колонки
  parN : ColumnInfo ;   //структура для последней колонки
  n : integer;
  numbType : double;
  buf : AnsiString;
begin

  attrType.columns := CreateArray( ATTR_COLUMN_ARR,nil );

  //поменяем местами первую колонку и последнюю

  par1.columns := CreateArray( ATTR_COLUMN_ARR,nil );
  par1.fieldEnum := CreateArray( CHAR_STR_ARR,nil );

  parN.columns := CreateArray( ATTR_COLUMN_ARR,nil );
  parN.fieldEnum := CreateArray( CHAR_STR_ARR,nil );


  //запросить имя библиотеки
  if( ksChoiceFile( '*.lat',nil, nameFile,128,0 ) =0 ) then
    strcopy(nameFile,''); //будем искать в документе
  repeat
    j := ReadDouble( 'Ввести номер типа атрибута', 1000.,0, 1e12, numb);
    if( j <> 0 ) then
    begin
      j := ReadString( 'Ввести пароль типа атрибута', password, 10 );
      if ( j <> 0 )  then
      begin
        //считаем тип атрибута
        if ( ksGetAttrType( numb, nameFile, Addr(attrType) )=0 ) then
          MessageBoxResult  // проверяем результат работы нашей функции
        else begin
          StrCopy(attrType.password,password);
          // число колонок
          n := GetArrayCount( attrType.columns );
          //считаем первую колонку
          GetArrayItem( attrType.columns, 0, Addr(par1), SizeOf(par1) );
          //считаем последнюю колонку
          GetArrayItem( attrType.columns, n-1, Addr(parN), SizeOf(parN) );
          //заменим первую колонку
          SetArrayItem( attrType.columns, 0, Addr(parN), sizeof(parN) );
          //заменим последнюю колонку
          SetArrayItem( attrType.columns, n-1, Addr(par1), sizeof(par1) );

          //заменим  тип атрибута  на новый
          numbType := ksSetAttrType( numb, nameFile, Addr(attrType), password );
          if ( numbType > 1 )  then
          begin
            buf := Format( 'numbType=%f ',[numbType] );
            ksMessage(PAnsiChar(buf));
          end else
            MessageBoxResult();  // неудачное завершение - выдадим результат работы нашей функции
        end;
      end;
    end;
  until( j=0 );
  //удалим все созданные массивы
  DeleteArray( par1.columns );
  DeleteArray( par1.fieldEnum );

  DeleteArray( parN.columns );
  DeleteArray( parN.fieldEnum );

  DeleteArray( attrType.columns );
end;

//----------------------------------------------------------------------------
//создадим атрибут типа,полученного из функции FuncTypeAttr
//----------------------------------------------------------------------------
procedure NewAttr;
type
BufSRec = record
  a : double ;
  c : array [0..MAX_TEXT_LENGTH-1] of AnsiChar;
  b : longint;
end;

var
 attrPar : Attribute;
 bufS    : BufSRec;
 fV      : array[0..3] of AnsiChar;
 x, y    : double;
 pObj    : reference;
 info    : RequestInfo;
 j       : integer;
 nameFile: array [0..128] of AnsiChar;
 numb    : double ;
 attr    : reference;


begin
bufS.a := 987654321.0;
bufS.b := 99999;
StrCopy(bufS.c,'qwerty');

  fV[0]:= '1'; fV[1]:= '1'; fV[2]:= '1';
  attrPar.key1 := 1;                          // рекоменд. как код разработчика
  attrPar.key2 := 10;                         // рекоменд. как код атрибута
  attrPar.key3 := 100;                        // рекоменд. как код разработчика
  attrPar.key4 := 0;                          // системный код атрибута
                                             // значения от 0 до 1000 зарезервированы
                                             // за АО "АСКОН"
  attrPar.flagVisible := fV;                  //массив, определяющий для каждой колонки
                                             // атрибута видимость-невидимость
                                             //0 -видимое поле 1- невидимое поле
  attrPar.values := Addr(bufS);                    // массив значений ячеек таблицы атрибутов
                                             // сначала все значения для 1-ой строки,
                                             // затем все значения для 2-ой строки и т.д.
  attrPar.valSize := SizeOf(bufS);
  StrCopy(attrPar.password,'111');            //пароль, если не пустая строка  - защищает от несанкционированного изменения информации в атрибуте


   FillChar(info, sizeof(info), 0);
   info.prompt := 'Укажите объект';

  j := ksCursor( Addr(info), x ,y, nil );
  if ( j <>0 ) then
  begin
    pObj := FindObj( x, y, 1e6 );
    if( ExistObj(pObj)>0 )then
    begin
      LightObj( pObj, 1 );
      //запросить имя библиотеки
      if(ksChoiceFile( '*.lat',nil, nameFile, 128,0 ) = 0) then
        strcopy(nameFile,''); //будем искать в документе
      j := ReadDouble( 'Ввести номер типа атрибута', 1000.,0, 1e12,numb);
      if( j>0 ) then
      begin

        attr := CreateAttr( pObj, Addr(attrPar), numb, nameFile );
        if( attr=0 ) then
          MessageBoxResult  // неудачное завершение - выдадим результат работы нашей функции
      end;
      LightObj( pObj, 0 );

    end;
  end;
end;

//--------------------------------------------------------------------------
// удалить первый атрибут  у данного объекта
//---------------------------------------------------------------------------
procedure DelObjAttr;
var
  x, y : double ;
  pObj : reference ;
  password :array [0..11] of AnsiChar;
  j : integer;
  info : RequestInfo ;
  iter,p : reference;
  attr : reference;

begin
  FillChar( info, sizeof(info),0); 
  info.prompt := 'Укажите объект';
  repeat
    j := ksCursor( Addr(info), x ,y, nil );
    if ( j<>0 ) then
    begin
      pObj := FindObj( x, y, 1e6 );
      if( ExistObj(pObj)>0 ) then
      begin
        LightObj( pObj, 1 );
        //создадим итератор для хождения по атрибутам объекта

        iter := CreateAttrIterator( pObj, 0,0,0,0,0 );
        //встали на первый атрибут
        attr := MoveAttrIterator( iter, 'F', p );
        if ( attr > 0) then
        begin
          j := ReadString( 'Ввести пароль типа атрибута', password, 10 );
          if ( j>0 )  then
          begin
            //удалить атрибут
            if( DeleteAttr (pObj, attr, password)=0 ) then
              MessageBoxResult();  // неудачное завершение - выдадим результат работы нашей функции
          end;
        end else
          Error( 'атрибут не найден' );
        LightObj( pObj, 0 );
      end;
    end;
  until ( j=0 );
end;
//--------------------------------------------------------------------------
// считать  атрибут  типа double_str_long
//---------------------------------------------------------------------------
procedure ReadObjAttr;
type
BufSRec = record
  d : double ;
  s : array [0..MAX_TEXT_LENGTH-1] of AnsiChar;
  l : longint;
end;

var
  sBuf : BufSRec;
  x, y : double ;
  pObj : reference ;
  j,i : integer;
  buf : AnsiString;
  info :RequestInfo;
  iter,p, attr : reference;
  k1,k2,k3,k4  : Cardinal;
  numb : double;
  col, row : Cardinal;
  par : ColumnInfo ;  //структура для первой колонки


begin
  FillChar( info, sizeof(info),0);
  info.prompt := 'Укажите объект';

  repeat
    j := ksCursor( Addr(info), x ,y, nil );
    if ( j<>0 ) then
    begin
      pObj := FindObj( x, y, 1e6 );
      if( ExistObj(pObj)>0 ) then
      begin
        LightObj( pObj, 1 );
        //создадим итератор для хождения по атрибутам объекта

        iter := CreateAttrIterator( pObj, 0,0,0,0,0 );
        //встали на первый атрибут
        attr := MoveAttrIterator( iter, 'F', p );
        if ( attr>0 ) then
        begin

          ksMessage('тип и ключи атрибута');
          GetAttrKeysInfo( attr,k1,k2,k3,k4,numb );
          buf :=Format( 'k1=%d k2=%d k3=%d k4=%d numb=%f',[k1,k2,k3,k4,numb] );
          ksMessage( PAnsiChar(buf) );

          ksMessage('количество колонок');
          GetAttrTabInfo( attr, row, col );
          buf := Format ( 'column=%d row =%d',[col, row] );
          ksMessage( PAnsiChar(buf) );

          ksMessage('информация о колонках');
          par.columns := CreateArray( ATTR_COLUMN_ARR, nil );
          par.fieldEnum := CreateArray( CHAR_STR_ARR,nil );
          for  i:=0 to col-1 do
          begin
            GetAttrColumnInfo ( attr, i, Addr(par) );
            ShowCol(par,i, FALSE );
          end;
          DeleteArray(par.columns);
          DeleteArray(par.fieldEnum);

          ksMessage('строка атрибута');
          GetAttrRow ( attr, 0, nil, Addr(sBuf), sizeof(sBuf));
          buf := Format ('d=%f s=%s l=%d',[sBuf.d, sBuf.s, sBuf.l] );
          ksMessage( PAnsiChar(buf) );

          ksMessage('заменим строку атрибута');
          sBuf.d := numb;
          StrCopy(sBuf.s,'1234567\nasdfgh\nzxcvb');
          sBuf.l := 88888;
          SetAttrRow( attr, 0, nil, Addr(sBuf), sizeof(sBuf), '111');
          GetAttrRow ( attr, 0, nil, Addr(sBuf), sizeof(sBuf));
          buf := Format ( 'd=%f s=%s l=%d',[sBuf.d, sBuf.s, sBuf.l] );
          ksMessage( PAnsiChar(buf) );


        end else
          Error( 'атрибут не найден' );
        LightObj( pObj, 0 );
      end;
    end;
  until ( j=0 );
end;

//--------------------------------------------------------------------------
// просмотреть  атрибут
//---------------------------------------------------------------------------
procedure ShowObjAttr;
var
  x, y : double ;
  pObj : reference ;
  j    : integer;
  info :RequestInfo;
Begin
  FillChar( info, sizeof(info),0);
  info.prompt := 'Укажите объект';
  repeat
    j := ksCursor( Addr(info), x ,y, nil );
    if ( j<>0 ) then
    Begin
      pObj := FindObj( x, y, 1e6 );
      if( ExistObj(pObj)>0 ) then
      begin
        LightObj( pObj, 1 );
        ChoiceAttr ( pObj );
        LightObj( pObj, 0 );
      end;
    end;
  until( j=0 );
end;

//--------------------------------------------------------------------------
// просмотреть  библиотеку типов атрибутов
//---------------------------------------------------------------------------
procedure ShowLib;
var
  nameFile : array [0..128]of AnsiChar;
  numb : double;
  buf : AnsiString;
begin
  if( ksChoiceFile( '*.lat',nil, nameFile,128,0 )=0 )then
    strCopy(nameFile,''); //будем искать в документе

  numb := ChoiceAttrTypes ( nameFile);

  if ( numb > 1 )  then
  begin
    buf := Format( 'numbType=%f ',[numb] );
    ksMessage(PAnsiChar(buf));
  end;
end;

//----------------------------------------------------------------------------------------
//   запустить диалог просмотра и редактирования типа атрибута
//---
procedure ShowType;
var
  nameFile : array [0..128] of AnsiChar;
  password : array [0..10] of AnsiChar;
  j : integer;
  numb : double ;
begin
  if( ksChoiceFile( '*.lat',nil, nameFile,128,0 )=0 ) then
    StrCopy(nameFile,''); //будем искать в документе
  j := ReadDouble( 'Ввести номер типа атрибута', 1000.,0, 1e12, numb);
  if ( j>0 )  then
  Begin
    password := '0';
    j := ReadString( 'Ввести пароль типа атрибута', password, 10 );
    if ( j >0 )  then
      ViewEditAttrType ( nameFile, 2, numb, password );
  end;
end;

//---------------------------------------------------------------------------
// пройтись по атрибутам  объекта,   с ключом
// key1=10 и выдать количество  колонок и строк для данного атрибута
//---------------------------------------------------------------------------
procedure WalkFromObjWithAttr;
var
 x, y  : double;
 j     : integer;
 pObj  : reference ;
 info  : RequestInfo ;
 iter  : reference;
 count : integer;
 buf : AnsiString;
 rowsCount, columnsCount : Cardinal;
 pAttr,p : reference;

begin
 //найдем объект
  FillChar( info, sizeof(info),0);
  info.prompt := 'Укажите объект';
  repeat
    j := ksCursor( Addr(info), x ,y, nil );
    if ( j<>0 ) then
    begin
      pObj := FindObj( x, y, 1e6 );
      if( ExistObj(pObj)>0 ) then
      begin
      //создадим итератор для движения по атрибутам с ключом 10
        iter := CreateAttrIterator( pObj, 10, 0,0,0,0 );
        count := 0;
        LightObj( pObj, 1 );

        pAttr :=  MoveAttrIterator(  iter, 'F', p );
        if ( pAttr>0 ) then
        begin
          repeat
            Inc(count);
            //узнаем количество строк и колонок
            if( GetAttrTabInfo ( pAttr, rowsCount, columnsCount )>0 ) then
            begin
              buf := Format('номер = %d rowsCount=%d columnsCount=%d', [count,rowsCount,columnsCount] );
              ksMessage( PAnsiChar(buf) );
            end else
              MessageBoxResult();  // неудачное завершение - выдадим результат работы нашей функции
            pAttr := MoveAttrIterator(  iter, 'N', p );
          until( pAttr=0 );
        end;
        LightObj( pObj, 0 );
      end;
    end;
  until(j=0);
end;


end.
