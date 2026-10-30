unit Step101;
//******************************************************************/
//                (c)Акционерное общество АСКОН                   */
//*                Санкт-Петербург, 1991, 1996                     */
//*                 Компас-Мастер  версия 5.x                      */
//******************************************************************/
//*                    Библиотека примеров                         */
//*                  Работа с объектами спецификации                 */                                                       */
//******************************************************************/

interface
type
  //структура соответствует типу атрибута болт из библиотеки spc.lat
BOLT = record
  dr    : single   ;  //диаметр резьбы
  p     : single   ;  //шаг резьбы
  s     : single   ;  // размер под ключ
  h     : single   ;  // высота головки
  D     : single   ;  //  диаметр описанной окружности
  d3    : single   ;  // диаметр отв. в стержне
  h2    : single   ;  // высота подголовка
  L     : cardinal ;  // длина стержня
  l1    : single   ;  // расстояние до отверстия в стержне
  b     : single   ;  // длина резьбовой части
  d2    : single   ;  // диаметр под головкой
  z4    : single   ;  // величина фаски конца
  k     : smallInt ;  // 1 длина резьбы ниже ломманной(резьба только на b) ; 2 - выше ломанной (резьба до головки и  на в )
  f     : word     ;  //     битовые маски
  klass : smallInt ;  //класс точности
  gost  : word     ;  //номер госта
end;

 procedure  LIBRARYENTRY( comm: WORD  ); Pascal;
 function   LIBRARYID   : Cardinal;      Pascal;
 procedure  TypeAttrBolt;
 procedure  CreateDet;
 procedure  CreateStandart;
 procedure DecomposeSpc;
 procedure  ShowSpc;

 implementation

 uses  Sysutils, LtDefine, LibTool, LDefin2D;

 const
 STR225   = 200;
 STR226   = 201;
 STR227   = 202;
 STR228   = 203;
 MENU_POS_LEADER= 204;
 ISPOLN      = $80;   // исполнение 1 >0 исполнение 2
 PITCH       = $2;    // крупный шаг >0 мелкий шаг
SPC_NAME                =  5;     //наименование

//----------------------------------------------------------------------------------------
//
//---
function   LIBRARYID : Cardinal;  pascal;
begin
  Result:=100;
end;

//----------------------------------------------------------------------------------------
//
//---
procedure  LIBRARYENTRY( comm : Word  );  pascal;
begin
  case ( Comm ) of
    1 : begin //создать шаблон обозначения  для болта
        TypeAttrBolt();
        end;
    2 : begin //создать объект спецификации деталь
        CreateDet();
        end;
    3 : begin //создать стандартный объект
        CreateStandart();
        end;
    4 : begin //Конвертировать спецификацию во фрагмент
        DecomposeSpc;
        end;
    5 : begin //Просмотреть спецификацию
        ShowSpc();
        end;
  end;
end;
{
Пример создания шаблона обозначения для стандартного изделия "болт":

Шаблон обозначения можно создать визуальными средствами, предоставленными графиком для
создания типа атрибута. Этот способ не требует непосредственного программирования,
но влечет к затратам времени на создание шалона, а при потере данных в библиотеке
потребует повторного создания утраченного шаблона.
Можно создать шаблон обозначения средствами apptool из библиотеки.

Полное обозначение болта :
  Болт 1 М12 х 1.25 -6g x 60.58.35X.16 ГОСТ 7808 - 70

Представим это обозначение в виде компонент :

Номер  Имя компоненты   Умолчательное значение    Тип      Очередность сортировки

1      Имя элем.        Болт                     строка    1
2      Исполнение       1                        uint      3
3      Резьба           М                        строка    0 ( не сортируется )
4      Диаметр          12                       uint      4 или 3 ( сортирует подряд )
5      Разделитель      х                        строка    0 ( не сортируется )
6      Шаг              1.25                     float     5 или 3 ( сортирует подряд )
7      Поле допуска     -6g                      строка    6 или 3 ( сортирует подряд )
8      Разделитель      х                        строка    0 ( не сортируется )
9      Длина            60                       uint      7 или 3 ( сортирует подряд )
10     Кл. прочности    .58                      строка    0 ( не сортируется )
11     Материал         .35Х                     строка    0 ( не сортируется )
12     Покрытие         .16                      строка    0 ( не сортируется )
13     ГОСТ             ГОСТ                     строка    0 ( не сортируется )
14     Номер            7808                     uint      2
15     Разделитель      -                        строка    0 ( не сортируется )
16     Год              70                       строка    0 ( не сортируется )
}

//-------------------------------------------------------------------------
//  создадим  тип атрибута болта
//-------------------------------------------------------------------------
procedure TypeAttrBolt;
const
//ключи определены в стиле спецификации
ST_KEY1                 = 100;    //ключи для стандапртных изделий
ST_KEY2_GOST            =  5;      //для стандартных изделий
ST_KEY3                 =  1;
SPC_NAME                =  5;     //наименование

var
  attrType   : ksAttributeType ;
  parStruct1 : ColumnInfo ;
  name :array [0..255] of AnsiChar;
//-------------------------------------------------------------------------------
procedure AddColumn( header: PAnsiChar; _type, key : Integer; def : PAnsiChar );
begin
  StrCopy(parStruct1.header, header);// заголовoк-комментарий столбца
  parStruct1._type := _type;    // тип данных в столбце - см.ниже
  parStruct1.key := key;                    // дополнительный признак,  очередность сортировки
  StrCopy(parStruct1.def,def);         // значение по умолчанию
  //добавим компоненту в массив компонент
  AddArrayItem( attrType.columns, -1, Addr(parStruct1), sizeof(parStruct1) );
end;
//-------------------------------------------------------------------------------
begin
//Инициализация данных для создания шаблона
  if ( ksChoiceFile( '*.lat','Типы атрибутов(*.lat)|*.lat|Все файлы (*.*)|*.*|', name, 255, 0) = 0) then
    exit;

//заполним структуру типа атрибута
  StrCopy(attrType.header,'Болт111');   // заголовoк-комментарий типа
  attrType.rowsCount        := 1;    // кол-во строк в таблице
  attrType.flagVisible      := 1;    // видимый, невидимый   в таблице
  StrCopy(attrType.password,'');     // пароль, если не пустая строка  - защищает от несанкционированного изменения типа
  attrType.columns          := CreateArray( ATTR_COLUMN_ARR, nil ); // динамический массив компонент записи
  attrType.key1 := ST_KEY1;
  attrType.key2 := ST_KEY2_GOST;
  attrType.key3 := ST_KEY3;
  attrType.key4 := 0;


   //массив полей записи
   FillChar( parStruct1, sizeof(parStruct1), 0 );
   //  колонка 1 "Имя элем."
   AddColumn( 'Имя элем.'{header},STRING_ATTR_TYPE{ _type}, 1{key}, 'Болт'{def} );

   //  колонка 2 "Исполнение"
   AddColumn( 'Исполнение'{header}, UINT_ATTR_TYPE{ _type}, 3{key}, '1'{def} );

   // колонка 3 "Резьба"
   AddColumn( 'Резьба'{header}, STRING_ATTR_TYPE{ _type}, 0{key}, 'М'{def} );

   // колонка 4 "Диаметр"
   AddColumn( 'Диаметр'{header}, UINT_ATTR_TYPE{ _type}, 3{key}, '12'{def} );

   // колонка 5 "разделитель"
   AddColumn( ''{header}, STRING_ATTR_TYPE{ _type}, 0{key}, 'x'{def} );

   // колонка 6 "Шаг"
   AddColumn( 'Шаг'{header}, FLOAT_ATTR_TYPE{ _type}, 3{key}, '1.25'{def} );

   // колонка 7 "Поле допуска"
   AddColumn( 'Поле допуска'{header}, STRING_ATTR_TYPE{ _type}, 3{key}, '-6g'{def} );

   // колонка 8 "разделитель"
   AddColumn( ''{header}, STRING_ATTR_TYPE{ _type}, 0{key}, 'x'{def} );

   // колонка 9 "Длина"
   AddColumn( 'Длина'{header}, UINT_ATTR_TYPE{ _type}, 3{key}, '60'{def} );

   // колонка 10 "Кл. прочности"
   AddColumn( 'Кл. прочности'{header}, STRING_ATTR_TYPE{ _type}, 0{key}, '.58'{def} );

   // колонка 11 "Материал"
   AddColumn( 'Материал'{header}, STRING_ATTR_TYPE{ _type}, 0{key}, '.35X'{def} );

   // колонка 12 "Покрытие"
   AddColumn( 'Покрытие'{header}, STRING_ATTR_TYPE{ _type}, 0{key}, '.16'{def} );

   // колонка 13 "ГОСТ"
   AddColumn( 'ГОСТ'{header}, STRING_ATTR_TYPE{ _type}, 0{key}, 'ГОСТ'{def} );

    // колонка 14 "Номер"
   AddColumn( 'Номер'{header}, UINT_ATTR_TYPE{ _type}, 2{key}, '7808'{def} );

    // колонка 15 "разделитель"
   AddColumn( ''{header}, STRING_ATTR_TYPE{ _type}, 0{key}, '-'{def} );

   // колонка 16 "Год"
   AddColumn( 'Год'{header}, STRING_ATTR_TYPE{ _type}, 0{key}, '70'{def} );

    // создать  шаблон  обозначения

  ksCreateAttrType( Addr(attrType),   // информация о типе атрибута
                                           name ); // имя библиотеки типов атрибутов

 MessageBoxResult();  // проверяем результат работы нашей функции

 //удалим  массив колонок
 DeleteArray( attrType.columns );

end;
//-----------------------------------------------------------------------------------------------
//  создадим объект спецификации для раздела "Детали"
//-----------------------------------------------------------------------------------------------
function EditSpcObjDet( geom : reference  ): reference ;
var
  spcObj : reference;
  ss : array[0..128] of AnsiChar;
  j : integer;
begin
  spcObj := 0;
  //если редактируем макро объект , то ввойдем в режим редактирования объекта
  if ( EditMacroMode<>0 ) then
  begin
    //найдем объкт спецификации по геометрии
    spcObj := ksGetSpcObjForGeom( 'graphic.lyt' , //имя библиотеки типов
                                   1,         //   номер типа спецификации
                                   0,         //для макро редактирования
                                   1, 1 );
    //ввойдем в режим редактирования
    if ( ksSpcObjectEdit( spcObj )=0 ) then
      spcObj  := 0;
  end;

 //если объекта нет, ввойдем в режим создания объекта спецификации
 if ( spcObj<>0) Or  (ksSpcObjectCreate( 'graphic.lyt', //имя библиотеки типов
                                   1,         //   номер типа спецификации
                                   20,  0,    //номер раздела и подраздела
                                   0,0 )<>0) then    //тип атрибута
 begin
   StrCopy(ss, 'Втулка' );
   //наименование
   ksSpcChangeValue( SPC_NAME{номер колонки} , 1, Addr(ss), STRING_ATTR_TYPE  );

   //подключим геометрию
   if ( geom <>0) then
     ksSpcIncludeReference( geom, 1 );

   spcObj := ksSpcObjectEnd( );
   //если объект спецификации создан дадим возможность пользователю на него посмотреть и
   //отредактировать  функцию нужно запускать вне Cursor и Placement
   if ( spcObj<>0 ) then
   begin
     j := ksEditWindowSpcObject(spcObj);
     if ( j=0 )then
       spcObj := 0;
   end;
 end;
 EditSpcObjDet := spcObj;

end;


//----------------------------------------------------------------------------------------------
// отрисовать позиционную линию выноски
// уже проверено , что объект спецификации есть
// Функцию нужно запускать вне Cursor и Placement
//----------------------------------------------------------------------------------------------
procedure DrawPosLeader( _spcObj : reference );
var
  info      : RequestInfo ;
  flag      : boolean;
  posLeater : reference;
  x1, y1    : double ;
  j1        : integer;
//-------------------------------------------------------------------------------
procedure FindPosLeadir;
begin
  posLeater := FindObj( x1, y1, 100 );      // величина стороны окошка-ловушки с центром x,y
  if ( posLeater<>0 ) And (GetObjParam( posLeater, nil, 0, 0) <> POSLEADER_OBJ ) then
  begin
     Error('Ошибка! Объект не позиционная линия выноски!' );
     posLeater := 0;
     flag := true;
  end else
    flag := false;
end;
//-------------------------------------------------------------------------------
Begin
  flag := false;
  posLeater := 0;


  repeat
    FillChar(info,  sizeof(info), 0 );
    info.commands := PAnsiChar(MENU_POS_LEADER);

    info.prompt := 'Укажите позиционную линию выноски';
    j1 := ksCursor( Addr(info), x1, y1, nil );
    case ( j1 ) of
      1:begin //Создать новую линию выноски
        posLeater := ksCreateViewObject( POSLEADER_OBJ );
        flag := false;
        end;
      2:begin //Подключить существующую
        FillChar(info,  sizeof(info), 0 );
        info.commands :='Укажите линию выноски.';
        if( ksCursor( Addr(info), x1, y1, nil )<>0 ) then
          FindPosLeadir
        else
          flag := false;
        end;
      -1:begin
        FindPosLeadir;
        end;
    end;
  until( flag = false );

  //линия выноски есть, подключим ее к объекту спецификации
  if ( posLeater<>0  ) then
  begin
    //ввойдем в режим редактирования объекта спецификации
    if ( ksSpcObjectEdit( _spcObj )<>0 ) then
    begin
      //подключим линию выноски
      ksSpcIncludeReference( posLeater, 1 );
      //закроем объект спецификации
      ksSpcObjectEnd;
    end;
  end;
end;
//------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------
procedure  CreateDet;
var
  gr : reference;
  spcObj : reference;
begin
 //создать модельную группу   1
 gr :=  NewGroup(0);
      LineSeg ( 20, 30, 70, 30, 2 );
      LineSeg ( 70, 30, 70, 80, 2 );
      LineSeg ( 70, 80, 20, 80, 2 );
      LineSeg ( 20, 80, 20, 30, 2 );
 EndGroup();
 //создать  объект спецификации
 spcObj := EditSpcObjDet( gr );
 if ( spcObj<>0 ) then
   DrawPosLeader( spcObj  );

end;

//-----------------------------------------------------------------------------------------------
//  создадим объект спецификации для раздела "Стандартные изделия"
//-----------------------------------------------------------------------------------------------
function EditStandartSpcObj (tmp : BOLT;  geom : reference  ): reference ;
var
  spcObj : reference;
  uBuf   : Cardinal;
begin

  spcObj := 0;
  //если редактируем макро объект , то ввойдем в режим редактирования объекта
  if ( EditMacroMode<> 0 ) then
  begin
    //найдем объкт спецификации по геометрии
    spcObj := ksGetSpcObjForGeom( 'graphic.lyt' , //имя библиотеки типов
                                   1,         //   номер типа спецификации
                                   0,         //для макро редактирования
                                   1, 1 );
    //ввойдем в режим редактирования
    if ( ksSpcObjectEdit( spcObj )=0 )then
      spcObj  := 0;
  end;

 if ( spcObj<>0 ) Or  (ksSpcObjectCreate( 'graphic.lyt' , //имя библиотеки типов
                                   1,         //   номер типа спецификации
                                   25,  0,    //номер раздела и подраздела определены в стиле спецификации
                                   313277777065.0 , 0 ) <> 0) then //тип атрибута определен в библиотеке типов атрибутов spc.lat
 begin
   //исполнение
   if( (tmp.f And ISPOLN)=0 ) then//если исполнения нет
     ksSpcVisible( SPC_NAME, 2, 0 ) //выключим исполнение
   else begin
     uBuf :=  2;
     ksSpcVisible( SPC_NAME, 2, 1 );
     ksSpcChangeValue( SPC_NAME , 2, Addr(uBuf), UINT_ATTR_TYPE  );
   end;

   //изменим диаметр
   ksSpcChangeValue( SPC_NAME , 4, Addr(tmp.dr), FLOAT_ATTR_TYPE  );

   //отследим мелкий шаг
   if( (tmp.f And PITCH)=0 )then//выключить шаг и его разделитель
   begin
     ksSpcVisible( SPC_NAME, 5, 0 );
     ksSpcVisible( SPC_NAME, 6, 0 );   //щаг
   end
   else begin
     ksSpcVisible( SPC_NAME, 5, 1 );
     ksSpcVisible( SPC_NAME, 6, 1 );   //щаг
     ksSpcChangeValue( SPC_NAME , 6, Addr(tmp.p), FLOAT_ATTR_TYPE );
   end;

   // выключим поле допуска
   ksSpcVisible( SPC_NAME, 7, 0 );

   //изменим длину
   ksSpcChangeValue( SPC_NAME , 9, Addr(tmp.L), UINT_ATTR_TYPE  );

   // выключим класс прочности
   ksSpcVisible( SPC_NAME, 10, 0 );

   // выключим материал
   ksSpcVisible( SPC_NAME, 11, 0 );

   // выключим покрытие
   ksSpcVisible( SPC_NAME, 12, 0 );

   //изменим ГОСТ
   uBuf := Cardinal(tmp.gost);
   ksSpcChangeValue( SPC_NAME , 14, Addr(uBuf), UINT_ATTR_TYPE  );

   //подключим геометрию
   if ( geom<>0 ) then
     ksSpcIncludeReference( geom, 1 );

   spcObj := ksSpcObjectEnd( );
   //если объект спецификации создан дадим возможность пользователю на него посмотреть и
   //отредактировать.  Функцию нужно запускать вне Cursor и Placement
   if ( spcObj <>0 ) then
     if ( ksEditWindowSpcObject( spcObj )=0 ) then
       spcObj :=0;
 end;
 EditStandartSpcObj :=spcObj;
end;

//-------------------------------------------------------------------------------
//
//--------------------------------------------------------------------------------
procedure  CreateStandart;
var
  tmp : BOLT;
  spcObj :reference;
begin

 tmp.gost := 7809;
 tmp.f:=0;
 tmp.s:=27; tmp.h:=11; tmp.D:=30.1;
 tmp.L:=55; tmp.l1:=49; tmp.b:=46;  tmp.h2:=10;  tmp.klass:=1; {klass=B}
 tmp.d2:=22.5;  tmp.k    := 2;
 tmp.dr := 20;
 //создать  объект спецификации
 spcObj := EditStandartSpcObj( tmp, 0 );
 if ( spcObj<>0 ) then
   DrawPosLeader( spcObj  );

end;
//-----------------------------------------------------------------------------------------------
//Конвертировать спецификацию во фрагмент
//-----------------------------------------------------------------------------------------------
procedure DecomposeSpc;
var
  pDoc : reference;
  pageCount,i,row : integer;
  spcGabarit : RectParam ;
  doc : DocumentParam   ;
  buf : AnsiString;
  group : reference;
  column : integer;
  x,y : double;
begin
  //берем текущий документ спецификацию
  pDoc := ksGetCurrentDocument( 2 );
  if ( pDoc <> 0 ) then
  begin
    //найдем количество листов спецификации
    pageCount := ksGetSpcDocumentPagesCount( pDoc );
    //найдем габариры одного листа спецификации

    GetObjGabaritRect( pDoc, Addr(spcGabarit) );

    //создадим фрагмент
    FillChar( doc,  sizeof(doc), 0 );
    doc.regim :=                0;
    doc._type :=                 3;
    CreateDocument ( Addr(doc) );
    for i := 0 to pageCount-1 do
    begin
      //получили временную группу i-го листа спецификации
      group :=  DecomposeObj( pDoc,        //указатель на объект

                              0,  //уровень разбиения 0- отрезки,дуги,тексты,точки;
                                             //                  1-отрезки,тексты,точки; 2-отрезки, дуги, тексты
                              0.4, //стрелка прогиба
                              Byte(i+1) );  // 0 - разбиение объекта в СК вида 1- в СК листа
      if ( group <> 0 ) then
      begin

        column := i Mod 3;
        x := (spcGabarit.pTop.x-spcGabarit.pBot.x + 5)*column;
        row := i Div 3;
        y := (spcGabarit.pTop.y-spcGabarit.pBot.y + 5)*row;
        //сдвинули группу
        MoveObj( group, x, -y );
        //поставили в модель
        StoreTmpGroup( group );  //указатель группы
        ClearGroup( group );
        DeleteObj( group );
      end;
    end;
    buf := Format( 'Декомпозировано %d листов СП', [pageCount] );
    ksMessage( PAnsiChar(buf) );
  end  else
    Error( 'Спецификация должна быть текущей' );
end;

//-----------------------------------------------------------------------------------------------
//Просмотреть текущую спецификацию
//-----------------------------------------------------------------------------------------------
procedure ShowSpc;
var
  iter : reference;
  spcObj : reference;
  count,i : integer;
  par : SpcColumnParam  ;
  buf1 : AnsiString;
  buf : array[0..255] of AnsiChar;
  colNumb : integer;
begin
  //создаем итератор для навигации по текущей спецификации
  iter := CreateSpcIterator( nil, 0, 0 );
  if ( iter<>0 ) then
  begin
    //встаем на первый объект спецификации
    spcObj := MoveIterator( iter, 'F' );
    if ( (spcObj<>0) And (ExistObj(spcObj)>0) ) then
    begin
      repeat
        //узнаем количество колонок у базового объекта спецификации
        count := ksGetSpcTableColumn( nil, 0, 0 );
        // пройдем по всем колонкам
        for i := 1 to count do
        begin
          //для текущего номера определим тип колонки, номер исполнения и блок

          if ( ksGetSpcColumnType( spcObj,          //объект спецификации
                                  i,      // номер колонки, начиная с 1
                                  Addr(par) )>0)then
          begin
            //возьмем текст
            ksGetSpcObjectColumnText  ( spcObj,       //объект спецификации
                                        par.columnType, //тип колонки SPC_CLM_FORMAT...SPC_CLM_USER
                                        par.ispoln,     //исполнение данного типа
                                        par.block,
                                        buf,          //указатель
                                        250 );        //длина строки s
            buf1 := Format ( 'type = %d номер =%d block = %d', [par.columnType,par.ispoln,par.block] );
            strcat ( buf, PAnsiChar(buf1) );
            ksMessage( buf );
            //по типу колонки, номеру исполнения и блоку определим номер колонки
            colNumb := ksGetSpcColumnNumb(  spcObj,         //объект спецификации
                                            par.columnType, //тип колонки SPC_CLM_FORMAT...SPC_CLM_USER
                                            par.ispoln,     //исполнение данного типа начиная
                                            par.block );    //номер блока
            buf1 := Format ( 'i = %d colNumb =%d', [i, colNumb] );
            ksMessage( PAnsiChar(buf1) );

          end;
        end;
        //встаем на следующий объект спецификации
        spcObj := MoveIterator( iter, 'N' );
      until( spcObj=0)  Or  (ExistObj(spcObj )=0 );
    end;
    DeleteIterator( iter );
  end;
end;

end.
