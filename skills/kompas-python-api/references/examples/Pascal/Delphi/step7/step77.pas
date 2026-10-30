unit Step77;
//******************************************************************/
//                (c)Акционерное общество АСКОН                   */
//*                Санкт-Петербург, 1991, 1996                     */
//*                 Компас-Мастер  версия 5.x                      */
//******************************************************************/
//*                    Библиотека примеров                         */
//*                   навигация по модели                          */
//*                                                                */
//******************************************************************/

interface
 procedure  LIBRARYENTRY( comm: WORD  ); Pascal;
 function   LIBRARYID   : Cardinal;      Pascal;
 procedure  WalkFromDoc;
 procedure  WalkViewDoc;
 procedure  WalkGroup;
 procedure  WalkLayer;
 procedure  WalkFromView;
 procedure  WalkFromMacro;
 procedure  WalkFromGroup;
 procedure  WalkFromDocWithAttr;
 procedure  WalkFromObjWithAttr;

 implementation

 uses Windows,  Sysutils, LtDefine, LibTool, LDefin2D;

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
  case comm of
    3: begin//хождение по документам
       WalkFromDoc();
       end;
    4: begin//хождение по видам
       WalkViewDoc();
       end;
    5: begin//хождение по  именнованным и рабочим группам
       WalkGroup();
       end;
    6: begin//хождение по слоям
       WalkLayer();
       end;
    1: begin//хождение по виду
       WalkFromView();
       end;
    2: begin//хождение по макроэлементу
       WalkFromMacro();
       end;
    7: begin//хождение по группе
       WalkFromGroup();
       end;
    8: begin//хождение по элементам документа с определенным атрибутом
       WalkFromDocWithAttr();
       end;
    9: begin//хождение по атрибутам объекта
       WalkFromObjWithAttr();
       end;
  end;

end;

//-------------------------------------------------------------------------------
//хождение по документам
//----
procedure WalkFromDoc;
var
  doc   : DocumentParam;
  iDoc  : reference ;
  pDoc  : reference ;
  buf   : AnsiString;
  count : integer;
  par   : ViewParam ;
  number: integer;
begin

 StrCopy( doc.comment ,'create document' );
 StrCopy( doc.author ,'Vova' );
 doc.regim :=0;        //видимывй режим
 doc._type :=1;
 doc.stPar.format:=3;
 doc.stPar.multiply:=1;
 doc.stPar.direct:=0;
 doc.shtType:=1;
 doc.layoutName[0]:='0';

 StrCopy( doc.fileName,'a.cdw' );
 CreateDocument ( Addr(doc) );
 StrCopy( doc.fileName,'b.cdw' );
 CreateDocument ( Addr(doc) );
 StrCopy( doc.fileName,'c.cdw' );
 CreateDocument ( Addr(doc) );
 count := 0;
 //создаем итератор для хождения по документам
 iDoc := CreateIterator( DOCUMENT_OBJ , 0 );
 if ( iDoc > 0 ) then
 begin
   pDoc := MoveIterator( iDoc, 'F' );
   if ( pDoc > 0 ) then
   begin
     repeat
       //активизируем документ pDoc
       if ( SetObjParam( pDoc, nil, 0, DOCUMENT_STATE ) > 0 ) then
       begin
         iNc(count );
         number := count;
         par.x := 10;
         par.y := 20;
         par.scale := 1;
         par.ang := 0;
         par.color := RGB(10,20,10);
         par.state := stACTIVE;
         StrCopy(par.name, 'user view');

         //создадим вид в документе
         CreateSheetView( Addr(par), number);
         // откроем слой
         Layer( count );
         case ( count ) of
           1:begin //в первом документе создадим отрезок
             LineSeg( 20, 10, 40, 10, 1 );
             end;
           2:begin // во втором документе создадим окружность
             Circle ( 50, 50, 20, 1 );
             end;
           3:begin //в третьем документе создадим  дугу
             ArcByAngle( 50, 50, 20, 45, 135, 1, 1 );
             end;
         end;
         buf := Format('документ %d ', [count] );
         ksMessage( PAnsiChar(buf) );

       end;
       pDoc := MoveIterator(iDoc, 'N');
     until ( pDoc = 0 );
   end;
 end;
end;

//----------------------------------------------------------------------------------------
//хождение по видам
//---
procedure WalkViewDoc;
var
  doc    : DocumentParam;
  i      : integer;
  par    : ViewParam ;
  number : integer;
  iView, pView : reference;
  count :  integer;
  state :  integer;
begin

  StrCopy( doc.comment ,'create document' );
  StrCopy( doc.author ,'Vova' );
  doc.regim:=0;        //видимывй режим
  doc._type:=1;
  doc.stPar.format:=3;
  doc.stPar.multiply:=1;
  doc.stPar.direct:=0;
  doc.shtType:=1;
  doc.layoutName[0]:='0';

  StrCopy( doc.fileName,'.cdw' );
  CreateDocument ( Addr(doc) );
  //создадим 5 видов
  for i := 0 to 4 do
  begin
    number := 0;
    par.x := 10;
    par.y := 20;
    par.scale := 1;
    par.ang := 0;
    par.color := RGB(10,20,10);
    par.state := stACTIVE;
    StrCopy(par.name, 'user view');

    //создадим вид в документе
    CreateSheetView( Addr(par), number);
  end;
  //создадим итератор для навигации по видам в документе
  iView := CreateIterator( VIEW_OBJ , 0 );
  count :=0;
  if ( iView > 0) then
  begin
    pView := MoveIterator ( iView, 'F'); //первым будет системный вид с номером 0
    if ( pView > 0 ) then
    begin
      repeat
        state := stCURRENT;
        if ( SetObjParam( pView, Addr(state), SizeOf( integer ), VIEW_LAYER_STATE ) > 0 ) then
        begin
          case (count) of
            1: begin
              LineSeg( 20, 20, 40, 20, 1 );
              end;
            2: begin
              Circle( 40, 20, 30, 1 );
              end;
            3: begin
              ArcByAngle( 50, 50, 20, 45, 135, 1, 1 );
              end;
            4:begin
              Mtr(40,0,0,1);
              LineSeg( 10, 10, 30, 30, 1 );
              LineSeg( 30, 30, 60, 10, 1 );
              LineSeg( 60, 10, 10, 10, 1 );
              DeleteMtr();
            end;
            5:begin
              Circle( 30, 30, 20, 1 );
              Circle( 30, 30, 10, 1 );
              Hatch( 0, 45, 2, 0, 0, 0);
                Circle( 30, 30, 20, 1 );
                Circle( 30, 30, 10, 1 );
              EndObj();
            end;
          end;
        end;
        Inc(count);
        pView := MoveIterator ( iView, 'N');
      until ( pView = 0 );
    end;
  end;
end;
//----------------------------------------------------------------------------------------
//хождение по  именнованным и рабочим группам
//---
procedure WalkGroup;
var
  iNameGrp : reference;
  pNameGrp : reference ;
  count    : integer;
  buf : AnsiString;
  iWorkGrp : reference;
  pWorkGrp : reference;
begin
  //создадим итератор для движения по именнованным группам в документе
  iNameGrp := CreateIterator ( NAME_GROUP_OBJ , 0 );

  count := 0;
  if ( iNameGrp>0 ) then
  begin
    pNameGrp := MoveIterator( iNameGrp, 'F' );
    if ( pNameGrp > 0 ) then
    begin
      repeat
        LightObj( pNameGrp, 1 );   //подсветим группу
        Inc(count);
        buf := Format('номер = %d', [count] );
        ksMessage( PAnsiChar(buf) );
        LightObj( pNameGrp, 0 );   //снимем подсветку
        pNameGrp:= MoveIterator( iNameGrp, 'N' );
      until  pNameGrp = 0;
    end;
  end;
  DeleteIterator( iNameGrp );
//все именнованные группы ложатся в массив рабочих групп
  NewGroup(0);
    Circle( 30, 30, 20, 1 );
    Circle( 30, 30, 10, 1 );
    Hatch( 0, 45, 2, 0, 0, 0);
      Circle( 30, 30, 20, 1 );
      Circle( 30, 30, 10, 1 );
    EndObj();
  EndGroup();

  //создать итератор по рабочим группам
  count := 0;
  iWorkGrp := CreateIterator( WORK_GROUP_OBJ, 0 );
  if ( iWorkGrp > 0 ) then
  begin
    pWorkGrp := MoveIterator( iWorkGrp, 'F' );
    if (  pWorkGrp <> 0 ) then
    begin
      repeat
        LightObj( pWorkGrp, 1 );   //подсветим группу
        Inc(count);
        buf := Format('номер = %d', [count] );
        ksMessage( PAnsiChar(buf) );
        LightObj( pWorkGrp, 0 );   //снимем подсветку
        pWorkGrp := MoveIterator( iWorkGrp, 'N' );
      until( pWorkGrp = 0  );
    end;
  end;
end;

//----------------------------------------------------------------------------------------
//хождение по слоям
//---
procedure WalkLayer;
var
  doc    : DocumentParam;
  buf    : AnsiString;
  i      : integer;
  iLayer : reference;
  pLayer : reference;
  count  : integer;

begin


  StrCopy( doc.comment ,'create document' );
  StrCopy( doc.author ,'Vova' );
  doc.regim:=0;        //видимывй режим
  doc._type:=1;
  doc.stPar.format:=3;
  doc.stPar.multiply:=1;
  doc.stPar.direct:=0;
  doc.shtType:=1;
  doc.layoutName[0]:='0';

  StrCopy( doc.fileName,'b.cdw' );
  CreateDocument ( Addr(doc) );

  //создадим 5 слоев

  for i := 0 to 4 do
  begin
    Layer( i );
    Circle( 30, 30, 5 + i * 10, 1 );
  end;
  //создаем итератор по слоям

  iLayer := CreateIterator ( LAYER_OBJ, 0 );
  if ( iLayer>0 ) then
  begin
    count := 0;
    pLayer := MoveIterator ( iLayer, 'F' );
    if ( pLayer  <> 0 ) then
    begin
      repeat
        LightObj( pLayer, 1 );   //подсветим группу
        buf := Format('слой = %d', [count] );
        ksMessage( PAnsiChar(buf) );
        LightObj( pLayer, 0 );   //снимем подсветку
        Inc(count);
        pLayer := MoveIterator ( iLayer, 'N' );
      until  (pLayer=0 );
    end;
  end;
end;

//----------------------------------------------------------------------------------------
//хождение по виду
//---
procedure WalkFromView;
var
 obj   : reference ;
 count : integer;
 buf   : AnsiString;
 itAllObj : reference ;
begin

//в текущем документе и виде создадим итератор для хождения по всем элементам
 count  := 0;
 itAllObj := CreateIterator( {ALL_OBJ}CIRCLE_OBJ  ,    //тип поиска объекта
                            0  ); //указатель на объект(для движения по группе и внутри макро)
 if ( itAllObj > 0) then
 begin
   obj := MoveIterator( itAllObj, 'F' );
   if ( ExistObj( obj )>0 )then
   begin
     repeat
       LightObj( obj, 1 );
       inc(count);
       buf := Format('номер = %d', [count] );
       ksMessage( PAnsiChar(buf) );
       LightObj( obj, 0 );
       obj := MoveIterator( itAllObj, 'N' );
     until( obj=0 );
   end;
 end;
end;
//----------------------------------------------------------------------------------------
//хождение по макроэлементу
//---
procedure WalkFromMacro;
var
 itMacro, itMacroObj : reference ;
 obj   : reference ;
 macro : reference ;
 s,s1 : AnsiString;
 count, count1 : integer;
procedure UserLightObj( obj : reference; c : AnsiString; count : integer);
var
  buf : AnsiString;

begin
   LightObj( obj, 1 );
   buf := Format( c, [count] );
   ksMessage( PAnsiChar(buf) );
   LightObj( obj, 0 );
end;

begin

  //в текущем документе и виде создадим итератор для хождения по макроэлементам
 count := 0; count1 := 0;
 s:= 'номер маскро=%d';
 s1:='номер объекта=%d';
 itMacro := CreateIterator( MACRO_OBJ ,    //тип поиска объекта
                            0  ); //указатель на объект(для движения по группе и внутри макро)
 if ( itMacro>0 )  then
 begin
   macro := MoveIterator( itMacro, 'F' );
   if ( ExistObj( macro )>0 )then
   begin
     repeat
       // подсветим макроэлемент
       Inc(count);
       UserLightObj( macro, s, count );
       // создаем итератор для хождения по макроэлементу
       itMacroObj := CreateIterator( ALL_OBJ, macro );
       if ( itMacroObj >0 ) then
       begin
         obj := MoveIterator( itMacroObj, 'F' );
         if ( ExistObj( obj )>0 )then
         begin
           repeat
             Inc(count1);
             //подсветим объект в макро
             UserLightObj( obj, s1, count1 );
             obj := MoveIterator( itMacroObj, 'N' );
           until ( ExistObj (obj )=0 );
         end;
         DeleteIterator( itMacroObj );
       end;
       macro := MoveIterator( itMacro, 'N' );
     until ExistObj (  macro) =0 ;
   end;
   DeleteIterator(itMacro);
 end;
end;

//----------------------------------------------------------------------------------------
//хождение по группе
//---
procedure WalkFromGroup;
var
 buf  : AnsiString;
 pGrp : reference;
 iGrp : reference;
 count: integer;
 obj  : reference;
begin
  Mtr( 20, 10, 0, 1 ) ;
  pGrp := NewGroup(0);
    LineSeg( 10, 50, 50, 50, 1 );
    LineSeg( 10, 10, 50, 10, 1 );
    LineSeg( 10, 10, 10, 50, 1 );
    LineSeg( 50, 10, 50, 50, 1 );
    Circle( 30, 30, 20, 1 );
    Circle( 30, 30, 10, 1 );
    Hatch( 0, 45, 2, 0, 0, 0);
      Circle( 30, 30, 20, 1 );
      Circle( 30, 30, 10, 1 );
    EndObj();
  EndGroup();
  DeleteMtr();
//создать итератор для хождения по группе
  iGrp := CreateIterator ( ALL_OBJ , pGrp );
  count := 0;
  if ( iGrp >0 ) then
  begin
    obj := MoveIterator ( iGrp, 'F' );
    if ( ExistObj(obj )>0 ) then
    begin
      repeat
        LightObj( obj, 1 );
        Inc(count);
        buf := Format('номер = %d', [count] );
        ksMessage( PAnsiChar(buf) );
        LightObj( obj, 0 );
        obj := MoveIterator( iGrp, 'N' );
      until ( ExistObj ( obj )=0 );
    end;
  end;
end;

//---------------------------------------------------------------------------
// пройтись по объектам документа , у которых есть атрибут с ключом
// key1=10 и выдать количество  колонок и строк для данного атрибута
//---------------------------------------------------------------------------
procedure WalkFromDocWithAttr;
var
  iter        : reference;
  pObj, pAttr :  reference ;
  count : integer;
  buf : AnsiString;
  rowsCount, columnsCount : Cardinal;

begin
//создадим итератор для поиска объектов по ключу 10
  iter := CreateAttrIterator( 0, 10, 0,0,0,0 );  // указатель на объект или 0
  if ( iter=0 ) then
  begin
    MessageBoxResult();  // неудачное завершение - выдадим результат работы нашей функции
    exit;
  end;

  pAttr := MoveAttrIterator(  iter, 'F', pObj );
  count := 0;

  if ( pAttr>0) And  (ExistObj(pObj)>0 ) then
  begin
    repeat
      LightObj( pObj, 1 );
      Inc(count);
      //узнаем количество строк и колонок
      if( GetAttrTabInfo ( pAttr, rowsCount, columnsCount ) >0 ) then
      Begin
        buf := Format('номер = %d rowsCount=%d columnsCount=%d', [count,rowsCount,columnsCount] );
        ksMessage( PAnsiChar(buf) );
      end else
        MessageBoxResult();  // неудачное завершение - выдадим результат работы нашей функции

      LightObj( pObj, 0 );

      pAttr := MoveAttrIterator(  iter, 'N', pObj );
    until ( pAttr=0) Or ( ExistObj(pObj)=0) ;
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
 buf   : AnsiString;
 rowsCount, columnsCount : Cardinal;
 pAttr,p : reference;

begin
 //найдем объект
  FillChar( info, sizeof(info), 0);
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
