unit Step99;
//******************************************************************/
//                (c)Акционерное общество АСКОН                   */
//*                Санкт-Петербург, 1991, 1996                     */
//*                 Компас-Мастер  версия 5.x                      */
//******************************************************************/
//*                    Библиотека примеров                         */
//*        работа с размерами и технологическими объектами         */
//*                                                                */
//******************************************************************/

interface
 procedure  LIBRARYENTRY( comm: WORD  ); Pascal;
 function   LIBRARYID   : Cardinal;      Pascal;
 procedure  ShowDimD(str : PAnsiChar; param : pointer; t : integer);
 procedure  DrawLinDim;
 procedure  DrawAngDim;
 procedure  DrawRough;
 procedure  DrawLeader;
 procedure  DrawPosLeader;
 procedure  DrawBrandLeader;
 procedure  DrawMarkerLeader;
 procedure  DrawBase;
 procedure  DrawCutLine;
 procedure  DrawDiamDimt;
 procedure  DrawRadDimt;
 procedure  DrawRadBreakDimt;
 procedure  DrawViewPointer;

 implementation

 uses  Sysutils, LtDefine, LibTool, LDefin2D;

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
  Case ( Comm ) of
    1: begin//линейный размер
       DrawLinDim();
       end;
    2: begin//угловой размер
       DrawAngDim();
       end;
    3: begin//шероховатость
       DrawRough();
       end;
    5: begin//линия выноски
       DrawLeader();
       end;
    6: begin//позиционная линия выноски
       DrawPosLeader();
       end;
    7: begin//клеймение
       DrawBrandLeader();
       end;
    8: begin//маркирование
       DrawMarkerLeader();
       end;
    9: begin//обозначение базы
       DrawBase();
       end;
    10:begin //маркирование
       DrawCutLine();
       end;
    11:begin //диаметральный размер
       DrawDiamDimt();
       end;
    12:begin //радиальный размер
       DrawRadDimt();
       end;
    13:begin //радиальный размер
       DrawRadBreakDimt();
       end;
    14:begin //cтрелка вида
       DrawViewPointer();
       end;
  end;

end;

//-------------------------------------------------------------------------------------
// линейный размер
//---------------------------------------------------------------------------------------
procedure DrawLinDim;
var
  p : reference;
  linPar :LDimParam;
  t      :integer;
  buf    : AnsiString;
  ss     : array[0..128] of AnsiChar;
//--------------------------------------------------------------------------------
// просмотреть параметры линейного размера
//--------------------------------------------------------------------------------
procedure  ShowDimL( str : PAnsiChar; param : pointer; t : integer );
var
  pTPar   : PDimText;
  pSPar   : PLDimSource ;
  pDPar   : PDimDrawing ;
  lDimPar : PLDimParam;
  count   : integer ;
  i       : integer;
  s1 : array [0..128] of AnsiChar;

begin
  pTPar := nil;
  pSPar := nil;
  pDPar := nil;
  case ( t ) of
    ALLPARAM :  begin
      lDimPar :=  PLDimParam (param);
      pTPar := Addr(lDimPar^.tPar);
      pSPar := Addr(lDimPar^.sPar);
      pDPar := Addr(lDimPar^.dPar);
    end;
    DIM_TEXT_PARAM   :  begin
      pTPar := PDimText (param);
      end;
    DIM_SOURSE_PARAM : begin
      pSPar := PLDimSource(param);
      end;
    DIM_DRAW_PARAM   : begin
      pDPar :=  PDimDrawing(param);
      end;
  end;
  if ( pSPar <> nil ) then
  Begin
// параметры привязки линейного размера   1
    buf := Format( '%s параметры привязки  x1=%3.2f y1=%3.2f x2=%3.2f y2=%3.2f',
                    [str,pSPar^.x1,pSPar^.y1,pSPar^.x2,pSPar^.y2]);
    ksMessage( PAnsiChar(buf) );
    buf := Format( 'dx= %3.2f dy= %3.2f  basePoint = %d ps=%d',
                   [ pSPar^.dx,pSPar^.dy, pSPar^.basePoint,pSPar^.ps ] );
    ksMessage( PAnsiChar(buf) );
  end;
  if( pDPar <> nil ) then
  Begin
// параметры изображения размера          2
    buf :=Format( '%s параметры отрисовки pl1=%d pl2=%d t1=%d  t2=%d',
                   [str,pDPar^.pl1, pDPar^.pl2, pDPar^.pt1, pDPar^.pt2] );
    ksMessage( PAnsiChar(buf) );
    buf :=Format( 'textPos=%d textBase=%d \n psh =%d ang=%3.2f length = %d',
             [pDPar^.textPos,pDPar^.textBase,
             pDPar^.shelfDir, pDPar^.ang, pDPar^.length] );
    ksMessage( PAnsiChar(buf) );
  end;
  if( pTPar<>nil ) then
  begin
// размерная надпись                      3
    buf :='параметры размерной надписи';
    if( pTPar^.pText <> 0 ) then
    begin
      count:=GetArrayCount( pTPar^.pText );
      for  i:=0 to count-1 do
      begin
        GetArrayItem( pTPar^.pText, i, Addr(s1), 128);   // индекс в массиве
        buf := buf + s1;
        buf := buf + ' ';
      end;
    end;

    ksMessage( PAnsiChar(buf) );
    buf := Format( '%s параметры размерной надписи sign=%d  bitFlag = %d ',
             [str, pTPar^.sign, pTPar^.bitFlag] );
    ksMessage( PAnsiChar(buf) );
  end;
end;
//------------------------------------------------------------------------------
begin
  FillChar( linPar, SizeOf(linPar), 0 );
//параметры текста
  linPar.dPar.textPos    := 10; //автоматическая простановка
  linPar.dPar.textBase   := 2; //над серединой размерной линии
  //должны быть строки PREFIX, номинал ставится auto- не нужно,TOLERANCE,
  //отклонения ставятся auto-ставить не нужно,UNIT,SUFFIX  - 4 строки
  linPar.tPar.bitFlag := _AUTONOMINAL or _PREFIX or _DEVIATION or _UNIT or _SUFFIX;
//  linPar.tPar.bitFlag = _AUTONOMINAL;
  linPar.tPar.sign := 0;
  linPar.tPar.pText := CreateArray(CHAR_STR_ARR ,nil);

  StrCopy( ss, 'prefix');
  AddArrayItem( linPar.tPar.pText, -1, Addr(ss), 8);
  StrCopy( ss, '+0,5');
  AddArrayItem( linPar.tPar.pText, -1, Addr(ss), 5);
  StrCopy( ss, '-0,5');
  AddArrayItem( linPar.tPar.pText, -1, Addr(ss), 5);
  StrCopy( ss, 'mm');
  AddArrayItem( linPar.tPar.pText, -1, Addr(ss), 5);
  StrCopy( ss, 'pp&04ww&01');
  AddArrayItem( linPar.tPar.pText, -1, Addr(ss), 13);

  //привязка линейного  размера
  linPar.sPar.ps := 0;            // признак 0-горизонтальный, 1-вертикальный 2- под углом
  linPar.sPar.x1 := 50; linPar.sPar.y1 := 50; //координаты   1 -ой точки привязки
  linPar.sPar.x2 := 70; linPar.sPar.y2 := 60; //координаты   2 -ой точки привязки
  linPar.sPar.dy := -20;
  linPar.sPar.dx := 0;
  linPar.sPar.basePoint := 1;

//размерная линия  линейного  размера
  linPar.dPar.pl1 := 0;                      //признак вкл./выкл.  отрисовки 1 выносной линии  0/1
  linPar.dPar.pl2 := 0;                      //признак вкл./выкл.  отрисовки 2 выносной линии  0/1
  linPar.dPar.pt1 := 2;            // тип стрелки у 1-ой выносной линии 0-стрелки нет 1- внутри 2 снаружи 3 -засечка 4 - точка
  linPar.dPar.pt2 := 2;            // тип стрелки у 2-ой выносной линии

//параметры выносной полки
  linPar.dPar.shelfDir   := 0; //полки нет
  linPar.dPar.ang   := -30;     //угол наклона ножки
  linPar.dPar.length:= 20;      //длина ножки

  p := LinDimension( Addr(linPar) ); //параметры линейного размера

 ShowDimL('создание размера', Addr(linPar), ALLPARAM  );

 //параметры текста
  linPar.dPar.textPos   := 1; //над серединой размерной линии
  //должны быть строки PREFIX, номинал ставится auto- не нужно,TOLERANCE,
  //отклонения ставятся auto-ставить не нужно,UNIT,SUFFIX  - 4 строки
  linPar.tPar.bitFlag := _AUTONOMINAL;
  linPar.tPar.sign := 0;
  linPar.tPar.pText := 0;

//привязка линейного  размера
  linPar.sPar.ps := 1;            // признак 0-горизонтальный, 1-вертикальный 2- под углом
  linPar.sPar.x1 := 50; linPar.sPar.y1 := 50; //координаты   1 -ой точки привязки
  linPar.sPar.x2 := 50; linPar.sPar.y2 := 60; //координаты   2 -ой точки привязки
  linPar.sPar.dx := -20;
  linPar.sPar.dy := 0;

//размерная линия  линейного  размера
  linPar.dPar.pl1 := 1;                      //признак вкл./выкл.  отрисовки 1 выносной линии  0/1
  linPar.dPar.pl2 := 1;                      //признак вкл./выкл.  отрисовки 2 выносной линии  0/1
  linPar.dPar.pt1 := 1;            // тип стрелки у 1-ой выносной линии 0-стрелки нет 1- внутри 2 снаружи 3 -засечка 4 - точка
  linPar.dPar.pt2 := 1;            // тип стрелки у 2-ой выносной линии

//параметры выносной полки
  linPar.dPar.shelfDir   := 0; //полки нет
  linPar.dPar.ang   := -30; //угол наклона ножки
  linPar.dPar.length:= 20; //длина ножки

//  DIM_SOURSE_PARAM DIM_DRAW_PARAM DIM_TEXT_PARAM
//////////////////////////////////////////////////
 ShowDimL('редактирование размера' ,Addr(linPar.dPar), DIM_DRAW_PARAM );

   SetObjParam(  p,   //указатель на графический объект
                 Addr(linPar.dPar),  //указатель на структуру параметров
                 SizeOf(linPar.dPar),   //размер структуры параметров
                 DIM_DRAW_PARAM ); //тип считывания параметров



 if( ExistObj(p)>0 ) then
 begin
   FillChar( linPar, SizeOf(linPar), 0 );
   t := GetObjParam(  p,   //указатель на графический объект
                      Addr(linPar),  //указатель на структуру параметров
                      sizeof(LDimParam),   //размер структуры параметров
                      SHEET_ALLPARAM ); //тип считывания параметров
   buf := Format('результирующие параметры tip= %d',[t] );

   ShowDimL('параметры размера', Addr(linPar), ALLPARAM );

 end;
end;

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
procedure DrawAngDim;
var
  p      : reference;
  angPar : ADimParam ;
  ss     : array[0..128] of AnsiChar;
  t      : integer;
  buf : AnsiString;
//--------------------------------------------------------------------------------
procedure  ShowDimA( str : PAnsiChar; param : pointer; t : integer);
var
  pTPar : PDimText;
  pSPar : PADimSource ;
  pDPar : PDimDrawing ;
  aDimPar : PADimParam;
  count,i : Cardinal;
  s1 : array [0..128] of AnsiChar;

begin
  pTPar := nil;
  pSPar := nil;
  pDPar := nil;
  case  ( t ) of
    ALLPARAM :  begin
      aDimPar :=  PADimParam(param);
      pTPar := Addr(aDimPar^.tPar);
      pSPar := Addr(aDimPar^.sPar);
      pDPar := Addr(aDimPar^.dPar);
      end;
    DIM_TEXT_PARAM : begin
      pTPar := PDimText(param);
      end;
    DIM_SOURSE_PARAM : begin
      pSPar := PADimSource (param);
      end;
    DIM_DRAW_PARAM : begin
      pDPar :=  PDimDrawing(param);
      end;
  end;
  if ( pSPar <> nil ) then
  begin
  // параметры привязки углового размера   1
    buf := Format('%s параметры привязки xс=%3.2f yс=%3.2f rad =%3.2f',
                   [str,pSPar^.xc,pSPar^.yc,pSPar^.rad] );
    ksMessage( PAnsiChar(buf) );
    buf := Format('x1=%3.2f y1=%3.2f\nx2=%3.2f y2=%3.2f dir =%d',
                  [pSPar^.x1,pSPar^.y1,pSPar^.x2,pSPar^.y2, pSPar^.dir] );
    ksMessage( PAnsiChar(buf) );

  end;
  if( pDPar<>nil ) then
  begin
// параметры изображения размера          2
    buf := Format('%s параметры отрисовки  pl1=%d pl2=%d t1=%d  t2=%d',
             [str,pDPar^.pl1, pDPar^.pl2, pDPar^.pt1, pDPar^.pt2] );
    ksMessage( PAnsiChar(buf) );
    buf := Format('textPos=%d textBase=%d \n psh =%d ang=%3.2f length = %d',
             [pDPar^.textPos,pDPar^.textBase,
             pDPar^.shelfDir, pDPar^.ang, pDPar^.length] );
    ksMessage( PAnsiChar(buf) );
  end;
  if( pTPar<>nil ) then
  begin
// размерная надпись                      3
    buf :='параметры размерной надписи';
    if( pTPar^.pText <> 0 ) then
    begin
      count:=GetArrayCount( pTPar^.pText );
      for  i:=0 to count-1 do
      begin
        GetArrayItem( pTPar^.pText, i, Addr(s1), 128);   // индекс в массиве
        buf := buf + s1;
        buf := buf + ' ';
      end;
    end;

    ksMessage( PAnsiChar(buf) );
    buf := Format( '%s параметры размерной надписи sign=%d  bitFlag = %d ',
             [str, pTPar^.sign, pTPar^.bitFlag] );
    ksMessage( PAnsiChar(buf) );
  end;
end;

begin
  FillChar( angPar, sizeof(angPar), 0 );

 LineSeg( 40, 0, 40, 40, 1 );
 LineSeg( 40, 0, 60, 20, 1 );
//параметры текста
  angPar.dPar.textPos   := -10; //автоматическая простановка
  angPar.dPar.textBase  := 0; //над серединой размерной линии
  //должны быть строки PREFIX, номинал ставится auto- не нужно,
  //отклонения ставятся auto-ставить не нужно,UNIT,SUFFIX  - 4 строки
  angPar.tPar.bitFlag := _AUTONOMINAL or _PREFIX or _DEVIATION or _UNIT or _SUFFIX;
//  angPar.tPar.bitFlag = _AUTONOMINAL;
  angPar.tPar.sign := 0;

  angPar.tPar.pText := CreateArray(CHAR_STR_ARR ,nil);

  StrCopy( ss, 'prefix');
  AddArrayItem( angPar.tPar.pText, -1, Addr(ss), 7);
  StrCopy( ss, '+0.3');
  AddArrayItem( angPar.tPar.pText, -1, Addr(ss), 5);
  StrCopy( ss, '-0.3');
  AddArrayItem( angPar.tPar.pText, -1, Addr(ss), 5);
  StrCopy( ss, 'гр');
  AddArrayItem( angPar.tPar.pText, -1, Addr(ss), 3);
  StrCopy( ss, 'suffics');
  AddArrayItem( angPar.tPar.pText, -1, Addr(ss), 8);

//привязка углового размера
  angPar.sPar.xc := 40; angPar.sPar.yc := 0;       // центр
  angPar.sPar.x1 := 40; angPar.sPar.y1 := 40;      // 1 - точка выхода выносной линии
  angPar.sPar.x2 := 60; angPar.sPar.y2 := 20;      // 2 - точка выхода выносной линии

  angPar.sPar.rad := 50;          //радиус размерной дуги
  angPar.sPar.dir := -1;          //направление 1 - размерная линия против часовой стрелки; -1 - по часовой стрелке

//отображение    размера
  angPar.dPar.pl1 := 0;       //признак вкл./выкл.  отрисовки 1 выносной линии  1/0
  angPar.dPar.pl2 := 0;       //признак вкл./выкл.  отрисовки 2 выносной линии  1/0
  angPar.dPar.pt1 := 1;       // тип стрелки у 1-ой выносной линии 0-стрелки нет 1- внутри 2 снаружи 3 -засечка 4 - точка
  angPar.dPar.pt2 := 1;       // тип стрелки у 2-ой выносной линии

  //параметры выносной полки
  angPar.dPar.shelfDir     := 0; //полки нет
  angPar.dPar.ang   := 30; //угол наклона ножки
  angPar.dPar.length:= 20; //длина ножки

 p := AngDimension( Addr(angPar) );//параметры углового размера
 ShowDimA('создание размера', Addr(angPar), ALLPARAM );
///////////////////////////////////////////////////////////////////////////////

//параметры текста
  angPar.dPar.textPos   := 0; //автоматическая простановка
  angPar.dPar.textBase  := 0; //над серединой размерной линии
  //должны быть строки PREFIX, номинал ставится auto- не нужно,
  //отклонения ставятся auto-ставить не нужно,UNIT,SUFFIX  - 4 строки
  angPar.tPar.bitFlag := _AUTONOMINAL or _PREFIX or _DEVIATION or _UNIT or _SUFFIX;
//  angPar.tPar.bitFlag = _AUTONOMINAL;
  angPar.tPar.sign := 0;

  angPar.tPar.pText := 0;//CreateArray(CHAR_STR_ARR ,0);

//привязка углового размера

  angPar.sPar.xc := 40; angPar.sPar.yc := 60;       // центр
  angPar.sPar.x1 := 10; angPar.sPar.y1 := 60;      // 1 - точка выхода выносной линии
  angPar.sPar.x2 := 20; angPar.sPar.y2 := 80;      // 2 - точка выхода выносной линии

  angPar.sPar.rad := 50;          //радиус размерной дуги
  angPar.sPar.dir := -1;          //направление 1 - размерная линия против часовой стрелки; -1 - по часовой стрелке


//отображение    размера
  angPar.dPar.pl1 := 0;       //признак вкл./выкл.  отрисовки 1 выносной линии  1/0
  angPar.dPar.pl2 := 0;       //признак вкл./выкл.  отрисовки 2 выносной линии  1/0
  angPar.dPar.pt1 := 1;       // тип стрелки у 1-ой выносной линии 0-стрелки нет 1- внутри 2 снаружи 3 -засечка 4 - точка
  angPar.dPar.pt2 := 1;       // тип стрелки у 2-ой выносной линии

  //параметры выносной полки
  angPar.dPar.shelfDir     := 1; //полки нет
  angPar.dPar.ang   := 30; //угол наклона ножки
  angPar.dPar.length:= 20; //длина ножки

// DIM_SOURSE_PARAM DIM_DRAW_PARAM DIM_TEXT_PARAM SHEET_ALLPARAM ALLPARAM
///////////////////////////////////////////////////////////////////////////////
 ShowDimA('редактирование размера' ,Addr(angPar.dPar), DIM_DRAW_PARAM );

  SetObjParam(  p,   //указатель на графический объект
                Addr(angPar.dPar),  //указатель на структуру параметров
                SizeOf(angPar),   //размер структуры параметров
                DIM_DRAW_PARAM ); //тип считывания параметров

  FillChar( angPar, sizeof(angPar), 0 );
  if( ExistObj(p)>0 ) then
  begin
    t := GetObjParam(  p,   //указатель на графический объект
                       Addr( angPar),  //указатель на структуру параметров
                       SizeOf(ADimParam),   //размер структуры параметров
                       SHEET_ALLPARAM ); //тип считывания параметров
   buf := Format('результирующие параметры tip= %d',[t] );
   ksmessage(PAnsiChar(buf));
   ShowDimA('', Addr(angPar), ALLPARAM );
  end;
end;
//--------------------------------------------------------------------------------
//
//--------------------------------------------------------------------------------
procedure DrawRough;
var
 p        : reference;
 roughPar : RoughParam ;
 tLinePar : TextLineParam ;
 tFont    : TextItemFont  ;      // параметры фонта компоненты строки текста
 ItemPar  : TextItemParam  ;    // параметры компоненты строки текста
  ss      : array[0..128] of AnsiChar;

begin
FillChar( roughPar, SizeOf(roughPar),0 );

//заполним параметры шероховатости
  roughPar.rPar._type:=0;                 // тип шероховатости  0-вид обр-ки не уст-ся 1- обр-ка удалением слоя материала
                                   // 2 -обр-ка без удаления слоя материала
  roughPar.rPar.around:=0;              // =1 - шероховатость "по контуру"
  roughPar.rPar.x:=50; roughPar.rPar.y:= 50;          // координаты точки привязкиопараметры первого отрезка    1 точка
  roughPar.rPar.ang:=90;           // угол наклона оси значка шероховатости с осью X
  roughPar.rPar.cText0:=2; // количество строк в тексте над знаком (параметры шер-ти по ГОСТ 2789-73)
  roughPar.rPar.cText1:=2; // количество строк в тексте над полкой (вид обр-ки и доп,указания)
  roughPar.rPar.cText2:=2; // количество строк в тексте под полкой (базовая длина по ГОСТ 2789-73)
                        // не более 2 строк
  roughPar.rPar.cText3:=1; // количество строк в тексте под полкой (усл.обозн.направления неровностей)
                        // не более 1 строк
//  roughPar.rPar.style = INDICATIN_TEXT_LINE_ARR;
  roughPar.rPar.style := 0;
  //текст можно задавать двумя способами
  if ( roughPar.rPar.style = INDICATIN_TEXT_LINE_ARR ) then
  begin
    //режим, когда тексты задаются массивом модельных строк текста

    tLinePar.style:=0;    //номер стиля строки текста
    tLinePar.pTextItem := CreateArray( TEXT_ITEM_ARR, nil );   //указатель на массив неопределенной длины компонент строки текста


    FillChar( tFont, sizeof( tFont ), 0 );

    ItemPar.tip:=0;            // tip = SPECIAL_SYMBOL , FONT_SYMBOL, FRACTION_TYPE, SUM_TYPE  или 0
    ItemPar.font := tFont;     // параметры фонта для компоненты текста
    ItemPar.iSNumb:=0;        // номер спецсимвола, символа из произвольного фонта или тип отрисовки дроби или выражения типа суммы или  0


    roughPar.rPar.pText := CreateArray(TEXT_LINE_ARR,nil);     // TEXT_LINE_ARR - массив неопределенной длины строк текста
                          // различают 4 разных текста для шероховатости;
                          // строки текстов лежат в следующей последовательности
                          // -текст над знаком (параметры шер-ти по ГОСТ 2789-73) - cText0=0 - текст отсутствует
                          // -текст над полкой (вид обр-ки и доп,указания)        - cText1=0 - текст отсутствует
                          // -текст под полкой (базовая длина по ГОСТ 2789-73)    - cText2=0 - текст отсутствует
                          // -текст под полкой (усл.обозн.направления неровностей)- cText3=0 - текст отсутствует

    StrCopy(ItemPar.s,'00_1');   // массив символов  для компоненты текста
    AddArrayItem( tLinePar.pTextItem, -1, Addr(ItemPar), sizeof(ItemPar));
    AddArrayItem( roughPar.rPar.pText, -1, Addr(tLinePar), sizeof(tLinePar));
    ClearArray(tLinePar.pTextItem);
    StrCopy(ItemPar.s,'00_2');   // массив символов  для компоненты текста
    AddArrayItem( tLinePar.pTextItem, -1, Addr(ItemPar), sizeof(ItemPar));
    AddArrayItem( roughPar.rPar.pText, -1, Addr(tLinePar), sizeof(tLinePar));
    ClearArray(tLinePar.pTextItem);
    StrCopy(ItemPar.s,'11_1');   // массив символов  для компоненты текста
    AddArrayItem( tLinePar.pTextItem, -1, Addr(ItemPar), sizeof(ItemPar));
    AddArrayItem( roughPar.rPar.pText, -1, Addr(tLinePar), sizeof(tLinePar));
    ClearArray(tLinePar.pTextItem);
    StrCopy(ItemPar.s,'11_2');   // массив символов  для компоненты текста
    AddArrayItem( tLinePar.pTextItem, -1, Addr(ItemPar), sizeof(ItemPar));
    AddArrayItem( roughPar.rPar.pText, -1, Addr(tLinePar), sizeof(tLinePar));
    ClearArray(tLinePar.pTextItem);
    StrCopy(ItemPar.s,'22_1');   // массив символов  для компоненты текста
    AddArrayItem( tLinePar.pTextItem, -1, Addr(ItemPar), sizeof(ItemPar));
    AddArrayItem( roughPar.rPar.pText, -1, Addr(tLinePar), sizeof(tLinePar));
    ClearArray(tLinePar.pTextItem);
    StrCopy(ItemPar.s,'22_2');   // массив символов  для компоненты текста
    AddArrayItem( tLinePar.pTextItem, -1, Addr(ItemPar), sizeof(ItemPar));
    AddArrayItem( roughPar.rPar.pText, -1, Addr(tLinePar), sizeof(tLinePar));
    ClearArray(tLinePar.pTextItem);
    StrCopy(ItemPar.s,'33_1');   // массив символов  для компоненты текста
    AddArrayItem( tLinePar.pTextItem, -1, Addr(ItemPar), sizeof(ItemPar));
    AddArrayItem( roughPar.rPar.pText, -1, Addr(tLinePar), sizeof(tLinePar));
  end
  else  begin
    //режим, когда тексты задаются массивом строк символов
    roughPar.rPar.pText :=CreateArray(CHAR_STR_ARR ,nil);     // массив неопределенной длины на строки текста шероховатости
                          // различают 4 разных текста для шероховатости;
                          // строки текстов лежат в следующей последовательности
                          // -текст над знаком (параметры шер-ти по ГОСТ 2789-73) - cText0=0 - текст отсутствует
                          // -текст над полкой (вид обр-ки и доп,указания)        - cText1=0 - текст отсутствует
                          // -текст под полкой (базовая длина по ГОСТ 2789-73)    - cText2=0 - текст отсутствует
                          // -текст под полкой (усл.обозн.направления неровностей)- cText3=0 - текст отсутствует

    StrCopy( ss, '00_1');
    AddArrayItem( roughPar.rPar.pText, -1, Addr(ss), 5);
    StrCopy( ss, '00_2');
    AddArrayItem( roughPar.rPar.pText, -1, Addr(ss), 5);
    StrCopy( ss, '11_1');
    AddArrayItem( roughPar.rPar.pText, -1, Addr(ss), 5);
    StrCopy( ss, '11_2');
    AddArrayItem( roughPar.rPar.pText, -1, Addr(ss), 5);
    StrCopy( ss, '22_1');
    AddArrayItem( roughPar.rPar.pText, -1, Addr(ss), 5);
    StrCopy( ss, '22_2');
    AddArrayItem( roughPar.rPar.pText, -1, Addr(ss), 5);
    StrCopy( ss, '33_1');
    AddArrayItem( roughPar.rPar.pText, -1, Addr(ss), 5);
  end;
  //параметры выносной полки
  roughPar.shPar.psh   := 0; //полки нет
  roughPar.shPar.ang   := 130; //угол наклона ножки
  roughPar.shPar.length:= 20; //длина ножки


 p := Rough( Addr(roughPar) );    //параметры шероховатости

 ksMessage( 'шероховатость');
 LightObj(p,1);

end;

//----------------------------------------------------------------------------------------
//  линия выноски
//---
procedure DrawLeader;
var
 p        : reference ;
 tLinePar : TextLineParam ;
 tFont    : TextItemFont  ;      // параметры фонта компоненты строки текста
 ItemPar  : TextItemParam  ;    // параметры компоненты строки текста
 leaderPar: LeaderParam ;
 mPar     : MathPointParam ;
 pPoly    : reference;
begin
  tLinePar.style:=0;    //номер стиля строки текста
  tLinePar.pTextItem := CreateArray( TEXT_ITEM_ARR, nil );   //указатель на массив неопределенной длины компонент строки текста

  FillChar( tFont, SizeOf( tFont ), 0 );


  ItemPar.tip    :=0;            // tip = SPECIAL_SYMBOL , FONT_SYMBOL, FRACTION_TYPE, SUM_TYPE  или 0
  ItemPar.font   := tFont;     // параметры фонта для компоненты текста
  ItemPar.iSNumb :=0;        // номер спецсимвола, символа из произвольного фонта или тип отрисовки дроби или выражения типа суммы или  0


  FillChar( leaderPar,  sizeof(leaderPar), 0 );
  leaderPar.x:=50; leaderPar.y:=50;             // координаты базовой точки ( начало полки )
  leaderPar.arrowType := 1; // тип стрелки
  leaderPar.dirX      :=1;      // направление полки по X (1 -вправо -1-влево)
  leaderPar.signType  :=0;  // тип знака
  leaderPar.around    :=0;    // знак обработки по контуру 0-выключен 1- включен
  leaderPar.cText0    :=1;    // количество строк текста над полкой 0- текст отсутствует
  leaderPar.cText1    :=1;    // количество строк текста под полкой 0- текст отсутствует
  leaderPar.cText2    :=1;    // количество строк текста над ножкой (не более 1 строки)0- текст отсутствует
  leaderPar.cText3    :=1;    // количество строк текста под ножкой (не более 1 строки)0- текст отсутствует

  leaderPar.pTextline := CreateArray( TEXT_LINE_ARR, nil );     // TEXT_LINE_ARR - массив неопределенной длины строк текста
  StrCopy(ItemPar.s,'00_1');   // массив символов  для компоненты текста
  AddArrayItem( tLinePar.pTextItem, -1, Addr(ItemPar), sizeof(ItemPar));
  AddArrayItem( leaderPar.pTextline, -1, Addr(tLinePar), sizeof(tLinePar));
  ClearArray(tLinePar.pTextItem);
  StrCopy(ItemPar.s,'11_1');   // массив символов  для компоненты текста
  AddArrayItem( tLinePar.pTextItem, -1, Addr(ItemPar), sizeof(ItemPar));
  AddArrayItem( leaderPar.pTextline, -1, Addr(tLinePar), sizeof(tLinePar));
  ClearArray(tLinePar.pTextItem);
  StrCopy(ItemPar.s,'22_1');   // массив символов  для компоненты текста
  AddArrayItem( tLinePar.pTextItem, -1, Addr(ItemPar), sizeof(ItemPar));
  AddArrayItem( leaderPar.pTextline, -1, Addr(tLinePar), sizeof(tLinePar));
  StrCopy(ItemPar.s,'33_1');   // массив символов  для компоненты текста
  AddArrayItem( tLinePar.pTextItem, -1, Addr(ItemPar), sizeof(ItemPar));
  AddArrayItem( leaderPar.pTextline, -1, Addr(tLinePar), sizeof(tLinePar));
  ClearArray(tLinePar.pTextItem);


  leaderPar.pPolyline  := CreateArray( POLYLINE_ARR, nil ); // POLYLINE_ARR - массив неопределенной длины ответвлений линии выноски
  pPoly                := CreateArray( POINT_ARR , nil );

  mPar.x := 10;
  mPar.y := 10;
  AddArrayItem( pPoly , -1, Addr(mPar), sizeof(mPar));
  AddArrayItem( leaderPar.pPolyline , -1, Addr(pPoly), sizeof(pPoly));

  mPar.x := 30;
  mPar.y := 10;
  ClearArray(pPoly);
  AddArrayItem( pPoly , -1, Addr(mPar), sizeof(mPar));
  AddArrayItem( leaderPar.pPolyline , -1, Addr(pPoly), sizeof(pPoly));


  p := Leader( Addr(leaderPar) );
  ksMessage( 'линия выноски' );
  LightObj(p,1);
end;

//--------------------------------------------------------------------------------
// позиционная линия выноски
//--------------------------------------------------------------------------------
procedure DrawPosLeader;
var
  p : reference ;
  leaderPar : PosLeaderParam  ;
  tLinePar  : TextLineParam ;
  tFont     : TextItemFont;        // параметры фонта компоненты строки текста
  ItemPar   : TextItemParam  ;    // параметры компоненты строки текста
  ss        : array[0..128] of AnsiChar;
  pPoly     : reference;
  mPar      : MathPointParam ;

begin
  FillChar( leaderPar, sizeof(leaderPar), 0 );

  leaderPar.x:=50; leaderPar.y:=50;             // координаты базовой точки ( начало полки )
  leaderPar.arrowType := 1; // тип стрелки
  leaderPar.dirX:=-1;      // направление полки по X (1 -вправо -1-влево)
  leaderPar.style := INDICATIN_TEXT_LINE_ARR;//текст задан массивом модельных строк текста
//  leaderPar.style := 1;                    //текст задан массивом строк символов текста
  //текст можно задавать двумя способами

  if ( leaderPar.style = INDICATIN_TEXT_LINE_ARR ) then
  begin
    tLinePar.style :=0;    //номер стиля строки текста
    tLinePar.pTextItem := CreateArray( TEXT_ITEM_ARR, nil );   //указатель на массив неопределенной длины компонент строки текста

    FillChar( tFont, sizeof( tFont ),0 );

    ItemPar.tip   := 0;            // tip = SPECIAL_SYMBOL , FONT_SYMBOL, FRACTION_TYPE, SUM_TYPE  или 0
    ItemPar.font  := tFont;     // параметры фонта для компоненты текста
    ItemPar.iSNumb:= 0;        // номер спецсимвола, символа из произвольного фонта или тип отрисовки дроби или выражения типа суммы или  0

    leaderPar.pText := CreateArray( TEXT_LINE_ARR, nil );     // TEXT_LINE_ARR - массив неопределенной длины строк текста

    StrCopy(ItemPar.s, '1');   // массив символов  для компоненты текста
    AddArrayItem( tLinePar.pTextItem, -1, Addr(ItemPar), sizeof(ItemPar));
    AddArrayItem( leaderPar.pText, -1, Addr(tLinePar), sizeof(tLinePar));
    ClearArray(tLinePar.pTextItem);

    StrCopy(ItemPar.s, '2');   // массив символов  для компоненты текста
    AddArrayItem( tLinePar.pTextItem, -1, Addr(ItemPar), sizeof(ItemPar));
    AddArrayItem( leaderPar.pText, -1, Addr(tLinePar), sizeof(tLinePar));

  end  else
  begin
    leaderPar.pText := CreateArray( CHAR_STR_ARR, nil );     // TEXT_LINE_ARR - массив неопределенной длины строк текста

    StrCopy( ss, '00_1');
    AddArrayItem( leaderPar.pText, -1, Addr(ss), 5);
    StrCopy( ss, '00_2');
    AddArrayItem( leaderPar.pText, -1, Addr(ss), 5);
  end;

  leaderPar.pPolyline  :=CreateArray(POLYLINE_ARR,nil); // POLYLINE_ARR - массив неопределенной длины ответвлений линии выноски
  pPoly := CreateArray( POINT_ARR , nil);

  mPar.x := 10;
  mPar.y := 10;
  AddArrayItem( pPoly , -1, Addr(mPar), sizeof(mPar));
  AddArrayItem( leaderPar.pPolyline , -1, Addr(pPoly), sizeof(pPoly));

  mPar.x := 30;
  mPar.y := 10;
  ClearArray(pPoly);
  AddArrayItem( pPoly , -1, Addr(mPar), sizeof(mPar));
  AddArrayItem( leaderPar.pPolyline , -1, Addr(pPoly), sizeof(pPoly));


  p := PositionLeader( Addr(leaderPar) );
  ksMessage( 'позиционная линия выноски ' );
  LightObj(p,1);
end;

//--------------------------------------------------------------------------------
//
//--------------------------------------------------------------------------------
procedure DrawBrandLeader;
var
  p: reference;
  leaderPar :BrandLeaderParam  ;
  tLinePar  : TextLineParam ;
  tFont     : TextItemFont;        // параметры фонта компоненты строки текста
  ItemPar   : TextItemParam  ;    // параметры компоненты строки текста
  ss        : array[0..128] of AnsiChar;
  pPoly     : reference;
  mPar      : MathPointParam ;

begin
  FillChar( leaderPar,  sizeof(leaderPar),0 );
  leaderPar.cText0:=1;    // количество строк текста в знаке (не более 1 строки)0- текст отсутствует
  leaderPar.cText1:=1;    // количество строк текста над ножкой (не более 1 строки)0- текст отсутствует
  leaderPar.cText2:=1;    // количество строк текста под ножкой (не более 1 строки)0- текст отсутствует

  leaderPar.x:=50; leaderPar.y:=50;             // координаты базовой точки ( начало полки )
  leaderPar.arrowType := 1; // тип стрелки
  leaderPar.dirX:=-1;      // направление полки по X (1 -вправо -1-влево)
  leaderPar.style1 := INDICATIN_TEXT_LINE_ARR;//текст задан массивом модельных строк текста
//  leaderPar.style1 := 0;                    //текст задан массивом строк символов текста

  if ( leaderPar.style1 = INDICATIN_TEXT_LINE_ARR ) then
  begin
    tLinePar.style:=0;    //номер стиля строки текста
    tLinePar.pTextItem := CreateArray( TEXT_ITEM_ARR, nil );   //указатель на массив неопределенной длины компонент строки текста

    FillChar( tFont, sizeof( tFont ),0 );

    ItemPar.tip   := 0;            // tip = SPECIAL_SYMBOL , FONT_SYMBOL, FRACTION_TYPE, SUM_TYPE  или 0
    ItemPar.font  := tFont;     // параметры фонта для компоненты текста
    ItemPar.iSNumb:= 0;        // номер спецсимвола, символа из произвольного фонта или тип отрисовки дроби или выражения типа суммы или  0

    leaderPar.pText := CreateArray( TEXT_LINE_ARR, nil );     // TEXT_LINE_ARR - массив неопределенной длины строк текста

    StrCopy(ItemPar.s, 'п.11');   // массив символов  для компоненты текста
    AddArrayItem( tLinePar.pTextItem, -1, Addr(ItemPar), sizeof(ItemPar));
    AddArrayItem( leaderPar.pText, -1, Addr(tLinePar), sizeof(tLinePar));
    ClearArray(tLinePar.pTextItem);

    StrCopy(ItemPar.s, 'Ну');   // массив символов  для компоненты текста
    AddArrayItem( tLinePar.pTextItem, -1, Addr(ItemPar), sizeof(ItemPar));
    AddArrayItem( leaderPar.pText, -1, Addr(tLinePar), sizeof(tLinePar));
    ClearArray(tLinePar.pTextItem);

    StrCopy(ItemPar.s, 'Ту');   // массив символов  для компоненты текста
    AddArrayItem( tLinePar.pTextItem, -1, Addr(ItemPar), sizeof(ItemPar));
    AddArrayItem( leaderPar.pText, -1, Addr(tLinePar), sizeof(tLinePar));

  end
  else begin
    leaderPar.pText := CreateArray(CHAR_STR_ARR, nil );     // TEXT_LINE_ARR - массив неопределенной длины строк текста

    StrCopy( ss, 'п.11');
    AddArrayItem( leaderPar.pText, -1, Addr(ss), 5);
    StrCopy( ss, 'Ну');
    AddArrayItem( leaderPar.pText, -1, Addr(ss), 3);
    StrCopy( ss, 'Ту');
    AddArrayItem( leaderPar.pText, -1, Addr(ss), 3);
  end;

  leaderPar.pPolyline  :=CreateArray(POLYLINE_ARR, nil); // POLYLINE_ARR - массив неопределенной длины ответвлений линии выноски
  pPoly := CreateArray( POINT_ARR , nil);

  leaderPar.pPolyline  :=CreateArray(POLYLINE_ARR,nil); // POLYLINE_ARR - массив неопределенной длины ответвлений линии выноски
  pPoly := CreateArray( POINT_ARR , nil);

  mPar.x := 10;
  mPar.y := 10;
  AddArrayItem( pPoly , -1, Addr(mPar), sizeof(mPar));
  AddArrayItem( leaderPar.pPolyline , -1, Addr(pPoly), sizeof(pPoly));

  mPar.x := 30;
  mPar.y := 10;
  ClearArray(pPoly);
  AddArrayItem( pPoly , -1, Addr(mPar), sizeof(mPar));
  AddArrayItem( leaderPar.pPolyline , -1, Addr(pPoly), sizeof(pPoly));



  p := BrandLeader( Addr(leaderPar) );
  ksMessage( 'клеймение' );
  LightObj(p,1);
end;

//--------------------------------------------------------------------------------
//
//--------------------------------------------------------------------------------
procedure DrawMarkerLeader;
var
  p         : reference ;
  leaderPar : MarkerLeaderParam  ;
  tLinePar  : TextLineParam ;
  tFont     : TextItemFont  ;      // параметры фонта компоненты строки текста
  ItemPar   : TextItemParam  ;    // параметры компоненты строки текста
  ss        : array[0..128] of AnsiChar;
  pPoly     : reference ;
  mPar      : MathPointParam ;
begin

  FillChar(leaderPar,  sizeof(leaderPar), 0 );
  leaderPar.cText0:=1;    // количество строк текста в знаке (не более 1 строки)0- текст отсутствует
  leaderPar.cText1:=1;    // количество строк текста над ножкой (не более 1 строки)0- текст отсутствует
  leaderPar.cText2:=1;    // количество строк текста под ножкой (не более 1 строки)0- текст отсутствует

  leaderPar.x:=50; leaderPar.y:=50;             // координаты базовой точки ( начало полки )
  leaderPar.arrowType := 2; // тип стрелки
//  leaderPar.style1 := INDICATIN_TEXT_LINE_ARR;//текст задан массивом модельных строк текста
  leaderPar.style1 := 0;                    //текст задан массивом строк символов текста
  if ( leaderPar.style1 = INDICATIN_TEXT_LINE_ARR ) then
  begin
    tLinePar.style:=0;    //номер стиля строки текста
    tLinePar.pTextItem := CreateArray( TEXT_ITEM_ARR, nil );   //указатель на массив неопределенной длины компонент строки текста

    FillChar( tFont, sizeof( tFont ), 0 );

    ItemPar.tip    :=0;        // tip = SPECIAL_SYMBOL , FONT_SYMBOL, FRACTION_TYPE, SUM_TYPE  или 0
    ItemPar.font   := tFont;   // параметры фонта для компоненты текста
    ItemPar.iSNumb :=0;        // номер спецсимвола, символа из произвольного фонта или тип отрисовки дроби или выражения типа суммы или  0


    leaderPar.pText := CreateArray( TEXT_LINE_ARR, nil );     // TEXT_LINE_ARR - массив неопределенной длины строк текста

    StrCopy(ItemPar.s, 'п.11');   // массив символов  для компоненты текста
    AddArrayItem( tLinePar.pTextItem, -1, Addr(ItemPar), sizeof(ItemPar));
    AddArrayItem( leaderPar.pText, -1, Addr(tLinePar), sizeof(tLinePar));
    ClearArray(tLinePar.pTextItem);

    StrCopy(ItemPar.s, 'Ну');   // массив символов  для компоненты текста
    AddArrayItem( tLinePar.pTextItem, -1, Addr(ItemPar), sizeof(ItemPar));
    AddArrayItem( leaderPar.pText, -1, Addr(tLinePar), sizeof(tLinePar));
    ClearArray(tLinePar.pTextItem);

    StrCopy(ItemPar.s, 'Ту');   // массив символов  для компоненты текста
    AddArrayItem( tLinePar.pTextItem, -1, Addr(ItemPar), sizeof(ItemPar));
    AddArrayItem( leaderPar.pText, -1, Addr(tLinePar), sizeof(tLinePar));

  end
  else begin
    leaderPar.pText := CreateArray(CHAR_STR_ARR, nil );     // TEXT_LINE_ARR - массив неопределенной длины строк текста

    StrCopy( ss, 'п.11');
    AddArrayItem( leaderPar.pText, -1, Addr(ss), 5);
    StrCopy( ss, 'Ну');
    AddArrayItem( leaderPar.pText, -1, Addr(ss), 3);
    StrCopy( ss, 'Ту');
    AddArrayItem( leaderPar.pText, -1, Addr(ss), 3);
  end;

  leaderPar.pPolyline  :=CreateArray(POLYLINE_ARR, nil); // POLYLINE_ARR - массив неопределенной длины ответвлений линии выноски
  pPoly := CreateArray( POINT_ARR , nil);

  leaderPar.pPolyline  :=CreateArray(POLYLINE_ARR,nil); // POLYLINE_ARR - массив неопределенной длины ответвлений линии выноски
  pPoly := CreateArray( POINT_ARR , nil);

  mPar.x := 10;
  mPar.y := 10;
  AddArrayItem( pPoly , -1, Addr(mPar), sizeof(mPar));
  AddArrayItem( leaderPar.pPolyline , -1, Addr(pPoly), sizeof(pPoly));

  mPar.x := 30;
  mPar.y := 10;
  ClearArray(pPoly);
  AddArrayItem( pPoly , -1, Addr(mPar), sizeof(mPar));
  AddArrayItem( leaderPar.pPolyline , -1, Addr(pPoly), sizeof(pPoly));


  p := MarkerLeader( Addr(leaderPar) );
  ksMessage( 'маркирование' );
  LightObj(p,1);
end;

//--------------------------------------------------------------------------------
//
//---------------------------------------------------------------------------------
procedure DrawBase;
var
  p : reference;
  basePar : BaseParam;//структура параметров обозначение базы
begin
  FillChar( basePar, sizeof(basePar), 0 );
  basePar.x1 := 50; basePar.y1 :=50;        // координаты базовой точки ( начало ножки )
  basePar.x2 := 50; basePar.y2 :=30;        // координаты конечной точки ножки
  StrCopy( basePar.str, 'ABC');             // надпись

  p := Base( Addr(basePar) );
  ksMessage( 'обозначение базы' );
  LightObj(p,1);
end;

//--------------------------------------------------------------------------------
//
//---------------------------------------------------------------------------------
procedure DrawCutLine;
var
 p      : reference;
 cutPar :CutLineParam;//структура параметров обозначение базы
 par    : MathPointParam ;

begin

  FillChar( cutPar, sizeof(cutPar), 0 );
  cutPar.right :=1;       // признак стрелок 0 слева/ 1 справа по направлению ломаной
  StrCopy (cutPar.str, 'A$;1$' );             // надпись
  cutPar.x1 := 30;
  cutPar.y1 := 65;
  cutPar.x2 := 95;
  cutPar.y2 := 15;
  cutPar.pMathPoint := CreateArray(POINT_ARR, nil );      // POINT_ARR массив неопределенной длины нач.точка, точки перегибов, кон.точка
  // первая точка
  par.x:=50; par.y:=50;
  AddArrayItem( cutPar.pMathPoint, -1, Addr(par), sizeof(par));

  // вторая  точка
  par.x:=50; par.y:=30;
  AddArrayItem( cutPar.pMathPoint, -1, Addr(par), sizeof(par));

  // третья точка
  par.x:=80; par.y:=30;
  AddArrayItem( cutPar.pMathPoint, -1, Addr(par), sizeof(par));


  p := CutLine( Addr(cutPar) );
  LightObj(p,1);
  ksMessage( 'линия разреза\сечения' );
  LightObj(p,0);
end;

//------------------------------------------------------------------------------
//
// ---
procedure ShowDimD(str : PAnsiChar; param : pointer; t : integer);
var
  pTPar   : PDimText     ;
  pSPar   : PRDimSource  ;
  pDPar   : PRDimDrawing ;
  lDimPar : PRDimParam   ;
  buf     : AnsiString;
  count,i : Cardinal;
  s1 : array [0..128] of AnsiChar;

begin
  pTPar := nil;
  pSPar := nil;
  pDPar := nil;

  case ( t ) of
    ALLPARAM : begin
      lDimPar :=  PRDimParam (param);
      pTPar := Addr(lDimPar^.tPar);
      pSPar := Addr(lDimPar^.sPar);
      pDPar := Addr(lDimPar^.dPar);
      end;
    DIM_TEXT_PARAM  : begin
      pTPar := PDimText(param);
      end;
    DIM_SOURSE_PARAM : begin
      pSPar := PRDimSource (param);
      end;
    DIM_DRAW_PARAM   : begin
      pDPar :=  PRDimDrawing (param);
      end;
  end;
  if ( pSPar <> nil) then
  begin
// параметры привязки линейного размера   1
    buf := Format( '%s параметры привязки xc=%3.2f yc=%3.2f\n rad=%3.2f',
                  [str, pSPar^.xc, pSPar^.yc, pSPar^.rad] );
    ksMessage( PAnsiChar(buf) );
  end;
  if( pDPar <> nil ) then
  begin
// параметры изображения размера          2
    buf := Format( '%s параметры отрисовки pt1=%d pt2=%d textPos=%d psh =%d ang=%3.2f',
             [str, pDPar^.pt1, pDPar^.pt2, pDPar^.textPos, pDPar^.shelfDir, pDPar^.ang] );
    ksMessage( PAnsiChar(buf) );
  end;

  if( pTPar<>nil ) then
  begin
// размерная надпись                      3
    buf :='параметры размерной надписи';
    if( pTPar^.pText <> 0 ) then
    begin
      count:=GetArrayCount( pTPar^.pText );
      for  i:=0 to count-1 do
      begin
        GetArrayItem( pTPar^.pText, i, Addr(s1), 128);   // индекс в массиве
        buf := buf + s1;
        buf := buf + ' ';
      end;
    end;

    ksMessage( PAnsiChar(buf) );
    buf := Format( '%s параметры размерной надписи sign=%d  bitFlag = %d ',
             [str, pTPar^.sign, pTPar^.bitFlag] );
    ksMessage( PAnsiChar(buf) );
  end;
end;

//-------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------
procedure DrawDiamDimt;
var
 p      : reference;
 linPar : RDimParam ;
 s      : array[0..128] of AnsiChar;
 t      : integer;
 buf    : AnsiString;

begin
  Circle(50,50,70,1);
  Circle(30,30,20,1);

  FillChar( linPar, sizeof(linPar), 0 );
//параметры текста
  linPar.dPar.textPos   := 75; //над серединой размерной линии
  //должны быть строки PREFIX, номинал ставится auto- не нужно,TOLERANCE,
  //отклонения ставятся auto-ставить не нужно,UNIT,SUFFIX  - 4 строки
  linPar.tPar.bitFlag := _AUTONOMINAL or _PREFIX or _TOLERANCE or _DEVIATION or _UNIT or _SUFFIX;
//  linPar.tPar.bitFlag = _AUTONOMINAL;

  linPar.tPar.pText := CreateArray( CHAR_STR_ARR , nil);
  StrCopy( s, 'prefix' );
  AddArrayItem( linPar.tPar.pText, -1, Addr(s), 8);
  StrCopy( s, 'h12' );
  AddArrayItem( linPar.tPar.pText, -1, Addr(s), 8);
  StrCopy( s, 'mm' );
  AddArrayItem( linPar.tPar.pText, -1, Addr(s), 5);
  StrCopy( s, 'sufix' );
  AddArrayItem( linPar.tPar.pText, -1, Addr(s), 6);
  linPar.tPar.sign := 0;

//привязка диаметрального  размера
  linPar.sPar.xc := 50; linPar.sPar.yc := 50; //центр
  linPar.sPar.rad := 70;

//размерная линия  линейного  размера
  linPar.dPar.pt1 := 2;            // тип стрелки у 1-ой выносной линии 0-стрелки нет 1- внутри 2 снаружи 3 -засечка 4 - точка
  linPar.dPar.pt2 := 2;            // тип стрелки у 2-ой выносной линии

//параметры выносной полки
  linPar.dPar.shelfDir   := 1; //полки нет
  linPar.dPar.ang        := -30; //угол наклона ножки

 p := DiamDimension( Addr(linPar) );//параметры линейного размера
 ShowDimD('создание размера', Addr(linPar), ALLPARAM );

 //параметры текста
  linPar.dPar.textPos   := 0; //над серединой размерной линии
  //должны быть строки PREFIX, номинал ставится auto- не нужно,TOLERANCE,
  //отклонения ставятся auto-ставить не нужно,UNIT,SUFFIX  - 4 строки
  linPar.tPar.bitFlag := _AUTONOMINAL or _PREFIX or _TOLERANCE or _UNIT or _SUFFIX;
//  linPar.tPar.bitFlag := _AUTONOMINAL;

  linPar.tPar.pText := CreateArray( CHAR_STR_ARR , nil);
  StrCopy( s, 'prefix' );
  AddArrayItem( linPar.tPar.pText, -1, Addr(s), 8);
  StrCopy( s, 'h12' );
  AddArrayItem( linPar.tPar.pText, -1, Addr(s), 8);
  StrCopy( s, 'mm' );
  AddArrayItem( linPar.tPar.pText, -1, Addr(s), 5);
  StrCopy( s, 'sufix' );
  AddArrayItem( linPar.tPar.pText, -1, Addr(s), 6);
  linPar.tPar.sign := 0;

//привязка диаметрального  размера
  linPar.sPar.xc := 30; linPar.sPar.yc := 30; //центр
  linPar.sPar.rad := 20;

//размерная линия  линейного  размера
  linPar.dPar.pt1 := 1;            // тип стрелки у 1-ой выносной линии 0-стрелки нет 1- внутри 2 снаружи 3 -засечка 4 - точка
  linPar.dPar.pt2 := 1;            // тип стрелки у 2-ой выносной линии

//параметры выносной полки
  linPar.dPar.shelfDir   := 0; //полки нет
  linPar.dPar.ang        := 30; //угол наклона ножки


 //////////////////////////////////////////////////
  ShowDimD('редактирование размера' ,Addr(linPar), ALLPARAM );

  SetObjParam(  p,   //указатель на графический объект
                Addr(linPar),  //указатель на структуру параметров
                sizeof(linPar),   //размер структуры параметров
                ALLPARAM ); //тип считывания параметров



 FillChar( linPar, sizeof(linPar), 0 );
 if( ExistObj(p)>0 ) then
 begin
   t := GetObjParam(  p,   //указатель на графический объект
                      Addr(linPar),  //указатель на структуру параметров
                      sizeof(RDimParam),   //размер структуры параметров
                      SHEET_ALLPARAM ); //тип считывания параметров
   buf := Format('результирующие параметры tip= %d',[t] );
   ksMessage( PAnsiChar(buf) );
   ShowDimD('', Addr(linPar), ALLPARAM );
 end;
end;

//-------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------
procedure			DrawRadDimt;
var
  p      : reference ;
  linPar : RDimParam ;
  s      : array[0..128] of AnsiChar;
  t      : integer;
  buf    : AnsiString;

begin
  Circle(50,50,70,1);
  Circle(30,30,30,1);

  FillChar(linPar, sizeof(linPar), 0 );
  //параметры текста
  //должны быть строки PREFIX, номинал ставится auto- не нужно,TOLERANCE,
  //отклонения ставятся auto-ставить не нужно,UNIT,SUFFIX  - 4 строки
  linPar.tPar.bitFlag := _AUTONOMINAL or _PREFIX or _TOLERANCE or _DEVIATION or _UNIT or _SUFFIX;
//  linPar.tPar.bitFlag = _AUTONOMINAL;

  linPar.tPar.pText := CreateArray( CHAR_STR_ARR , nil);
  StrCopy( s, 'prefix' );
  AddArrayItem( linPar.tPar.pText, -1, Addr(s), 8);
  StrCopy( s, 'h12' );
  AddArrayItem( linPar.tPar.pText, -1, Addr(s), 8);
  StrCopy( s, 'mm' );
  AddArrayItem( linPar.tPar.pText, -1, Addr(s), 5);
  StrCopy( s, 'sufix' );
  AddArrayItem( linPar.tPar.pText, -1, Addr(s), 6);
  linPar.tPar.sign := 0;

//параметры привязки диаметрального  размера
  linPar.sPar.xc := 50; linPar.sPar.yc := 50; //центр
  linPar.sPar.rad := 70;
//параметры отрисовки диаметрального  размера
  linPar.dPar.textPos   := 75; //над серединой размерной линии
  linPar.dPar.pt1       := 2;            // тип стрелки  0-стрелки нет 1- внутри 2 снаружи 3 -засечка 4 - точка
  linPar.dPar.pt2       := 1;            // признак отмены размерной линии 0- рисуется

  linPar.dPar.shelfDir  := 1;  //полка направлена вправо
  linPar.dPar.ang       := 30; //угол наклона ножки

  p := RadDimension( Addr(linPar) );//параметры линейного размера
  ShowDimD('создание размера', Addr(linPar), ALLPARAM );
///////////////////////////////////////////////////////////////////////////////

//параметры текста
  linPar.dPar.textPos   := 0; //над серединой размерной линии
  //должны быть строки PREFIX, номинал ставится auto- не нужно,TOLERANCE,
  //отклонения ставятся auto-ставить не нужно,UNIT,SUFFIX  - 4 строки
  linPar.tPar.bitFlag := _AUTONOMINAL;

  linPar.tPar.pText := 0;//CreateArray(CHAR_STR_ARR ,0);
  linPar.tPar.sign  := 0;

//привязка диаметрального  размера
  linPar.sPar.xc  := 30; linPar.sPar.yc := 30; //координаты   1 -ой точки привязки
  linPar.sPar.rad := 30;
//размерная линия  линейного  размера
  linPar.dPar.pt1 := 1;            // тип стрелки у 1-ой выносной линии 0-стрелки нет 1- внутри 2 снаружи 3 -засечка 4 - точка
  linPar.dPar.pt2 := 0;            // признак отмены размерной линии 0- рисуется

//параметры выносной полки
  linPar.dPar.shelfDir   := 0;  //полки нет
  linPar.dPar.ang   := 30; //угол наклона ножки
//ALLPARAM  DIM_SOURSE_PARAM  DIM_DRAW_PARAM  DIM_TEXT_PARAM
//////////////////////////////////////////////////
 ShowDimD('редактирование размера' ,Addr(linPar.sPar), DIM_SOURSE_PARAM );

   SetObjParam(  p,   //указатель на графический объект
                Addr(linPar.sPar),  //указатель на структуру параметров
                sizeof(linPar.sPar),   //размер структуры параметров
                DIM_SOURSE_PARAM  ); //тип считывания параметров


  FillChar( linPar, sizeof(linPar), 0 );
  if( ExistObj(p)>0 ) then
  begin
    t := GetObjParam(  p,   //указатель на графический объект
                       Addr(linPar),  //указатель на структуру параметров
                       sizeof(RDimParam),   //размер структуры параметров
                       SHEET_ALLPARAM ); //тип считывания параметров
    buf := Format('результирующие параметры tip= %d',[t] );
    ksMessage( PAnsiChar(buf) );
    ShowDimD('', Addr(linPar), ALLPARAM );
  end;
end;


//-------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------
procedure	DrawRadBreakDimt;
var
  p      : reference ;
  linPar : RBreakDimParam ;
  s      : array[0..128] of AnsiChar;
  t      : integer;
  buf    : AnsiString;
//------------------------------------------------------------------------------
procedure  ShowDimRBreak( str : PAnsiChar; param : pointer; t : integer);
var
  pTPar   : PDimText        ;
  pSPar   : PRDimSource     ;
  pDPar   : PRBreakDrawing  ;
  lDimPar : PRBreakDimParam;
  buf     : AnsiString;
  count,i : Cardinal;
  s1      : array [0..128] of AnsiChar;

begin

  pTPar := nil;
  pSPar := nil;
  pDPar := nil;

  case ( t ) of
    ALLPARAM : begin
      lDimPar :=  PRBreakDimParam (param);
      pTPar := Addr(lDimPar^.tPar);
      pSPar := Addr(lDimPar^.sPar);
      pDPar := Addr(lDimPar^.dPar);
    end;
    DIM_TEXT_PARAM : begin
      pTPar := PDimText (param);
      end;
    DIM_SOURSE_PARAM : begin
      pSPar := PRDimSource (param);
      end;
    DIM_DRAW_PARAM  : begin
      pDPar :=  PRBreakDrawing (param);
      end;
  end;
  if ( pSPar <> nil ) then
  begin
// параметры привязки линейного размера   1
    buf := Format( '%s параметры привязки xc=%3.2f yc=%3.2f rad=%3.2f',
                   [str, pSPar^.xc, pSPar^.yc, pSPar^.rad] );
    ksMessage( PAnsiChar(buf) );
  end;
  if( pDPar <> nil ) then
  begin
// параметры изображения размера          2
    buf := Format( '%s параметры отрисовки  pt=%d pb=%d ang=%3.2f',
                   [str, pDPar^.pt, pDPar^.pb, pDPar^.ang] );
    ksMessage( PAnsiChar(buf) );
  end;
  if( pTPar<>nil ) then
  begin
// размерная надпись                      3
    buf :='параметры размерной надписи';
    if( pTPar^.pText <> 0 ) then
    begin
      count:=GetArrayCount( pTPar^.pText );
      for  i:=0 to count-1 do
      begin
        GetArrayItem( pTPar^.pText, i, Addr(s1), 128);   // индекс в массиве
        buf := buf + s1;
        buf := buf + ' ';
      end;
    end;

    ksMessage( PAnsiChar(buf) );
    buf := Format( '%s параметры размерной надписи sign=%d  bitFlag = %d ',
             [str, pTPar^.sign, pTPar^.bitFlag] );
    ksMessage( PAnsiChar(buf) );
  end;
end;

begin
  Circle(50,50,70,1);
  Circle(30,30,30,1);

  FillChar( linPar, sizeof(linPar), 0 );
  //параметры текста
  //должны быть строки PREFIX, номинал ставится auto- не нужно,TOLERANCE,
  //отклонения ставятся auto-ставить не нужно,UNIT,SUFFIX  - 4 строки
  linPar.tPar.bitFlag := _AUTONOMINAL or _PREFIX or _TOLERANCE or _DEVIATION or _UNIT or _SUFFIX;
//  linPar.tPar.bitFlag = _AUTONOMINAL;

  linPar.tPar.pText := CreateArray( CHAR_STR_ARR , nil);
  StrCopy( s, 'prefix' );
  AddArrayItem( linPar.tPar.pText, -1, Addr(s), 8);
  StrCopy( s, 'h12' );
  AddArrayItem( linPar.tPar.pText, -1, Addr(s), 8);
  StrCopy( s, 'mm' );
  AddArrayItem( linPar.tPar.pText, -1, Addr(s), 5);
  StrCopy( s, 'sufix' );
  AddArrayItem( linPar.tPar.pText, -1, Addr(s), 6);
  linPar.tPar.sign := 0;


//параметры привязки
  linPar.sPar.xc := 50; linPar.sPar.yc := 50; //центр
  linPar.sPar.rad := 70;

//параметры отрисовки
  linPar.dPar.pt  := 2;          // тип стрелки  0-стрелки нет 1- внутри 2 снаружи 3 -засечка 4 - точка
  linPar.dPar.ang := 30;         // угол
  linPar.dPar.pb := 20;          // длина излома

  p := RadBreakDimension( Addr(linPar) );//параметры линейного размера
  ShowDimRBreak('создание размера', Addr(linPar), ALLPARAM );
//////////////////////////////////////////////////////////////////////////////
//параметры текста
  //должны быть строки PREFIX, номинал ставится auto- не нужно,TOLERANCE,
  //отклонения ставятся auto-ставить не нужно,UNIT,SUFFIX  - 4 строки
  linPar.tPar.bitFlag := _AUTONOMINAL;

  linPar.tPar.pText := 0;//CreateArray(CHAR_STR_ARR ,0);
  linPar.tPar.sign := 0;

//привязка диаметрального  размера
  linPar.sPar.xc  := 30; linPar.sPar.yc := 30; //координаты   1 -ой точки привязки
  linPar.sPar.rad := 30;
//размерная линия  линейного  размера
  linPar.dPar.pt  := 1;         // тип стрелки у 1-ой выносной линии 0-стрелки нет 1- внутри 2 снаружи 3 -засечка 4 - точка
  linPar.dPar.ang := 30;        // угол
  linPar.dPar.pb  := 10;        // длина излома
// ALLPARAM DIM_SOURSE_PARAM DIM_DRAW_PARAM DIM_TEXT_PARAM
//////////////////////////////////////////////////////////////////////////////
  ShowDimRBreak('редактирование размера' ,Addr(linPar.dPar), DIM_DRAW_PARAM);

  SetObjParam(  p,   //указатель на графический объект
                Addr(linPar.dPar),  //указатель на структуру параметров
                sizeof(linPar.dPar),   //размер структуры параметров
                DIM_DRAW_PARAM ); //тип считывания параметров


  FillChar( linPar, sizeof(linPar), 0 );
  if( ExistObj(p)>0 ) then
  begin
    t := GetObjParam(  p,   //указатель на графический объект
                       Addr(linPar),  //указатель на структуру параметров
                       sizeof(RDimParam),   //размер структуры параметров
                       SHEET_ALLPARAM ); //тип считывания параметров
    buf := Format('результирующие параметры tip= %d',[t] );
    ksMessage( PAnsiChar(buf) );
    ShowDimD('', Addr(linPar), ALLPARAM );
  end;


end;

//-------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------
procedure		DrawViewPointer;
var
  p       : reference;
  vpParam : ViewPointerParam;
  ItemPar : TextItemParam  ;    // параметры компоненты строки текста

begin

  FillChar( vpParam, sizeof(vpParam), 0 );
  vpParam.x1 := 50; vpParam.y1 := 50;             // координаты вершины( острия) стрелки
  vpParam.x2 := 20; vpParam.y2 := 50;             // координаты конечной точки стрелки
  vpParam.xt := 25; vpParam.yt := 55;             // координаты текста
  vpParam._type := 1;
  if ( vpParam._type = 0 ) then
// если vpParam.type = 0
    StrCopy( vpParam.str,'AAA')                    // надпись
  else begin
// если vpParam.type = 1
    vpParam.pTextItem := CreateArray( TEXT_ITEM_ARR, nil );
    FillChar( ItemPar,  sizeof( ItemPar ), 0 );
    StrCopy(ItemPar.s,'AAA');   // массив символов  для компоненты текста
    AddArrayItem( vpParam.pTextItem, -1, Addr(ItemPar), sizeof(ItemPar));
  end;
  p := ViewPointer( Addr(vpParam) );//параметры линейного размера
  ksMessage( 'стрелка вида' );
  LightObj(p,1);
end;

end.
