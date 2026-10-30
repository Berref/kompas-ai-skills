unit step91;

{$IFDEF CONDITIONALEXPRESSIONS}
{$IF CompilerVersion >= 14 }
  {$WARN SYMBOL_PLATFORM OFF}
{$IFEND}
{$ENDIF}


interface
  procedure LIBRARYENTRY( command: WORD ); Pascal;
  function  LIBRARYID: Cardinal; Pascal;

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
  kompas : KompasObject;
  doc    : ksDocument2D;

//-------------------------------------------------------------------------------
//
// ---
procedure DrawLinDim;
var
  param   : ksLDimParam;
  dPar    : ksDimDrawingParam;
  sPar    : ksLDimSourceParam;
  tPar    : ksDimTextParam;
  str     : ksChar255;
  arrText : ksDynamicArray;
  obj     : Reference;
begin
  param := ksLDimParam( kompas.GetParamStruct(ko_LDimParam) );
	if param = nil then
		Exit;

	dPar := ksDimDrawingParam( param.GetDPar );
	sPar := ksLDimSourceParam( param.GetSPar );
  tPar := ksDimTextParam   ( param.GetTPar );

	if ( (dPar = nil) Or (sPar = nil) Or (tPar = nil) ) then
		Exit;

	dPar.Init;
	dPar.pt2      := 10;
	dPar.textBase := 2;
	dPar.pt1      := 2;
	dPar.pt2      := 2;
	dPar.ang      := -30;
	dPar.lenght   := 20;

 	sPar.Init;
	sPar.x1 := 50;
  sPar.y1 := 50;
  sPar.x2 := 70;
  sPar.y2 := 60;
 	sPar.dx := 0;
  sPar.dy := -20;
	sPar.basePoint := 1;

 	tPar.Init( False );
  tPar.SetBitFlagValue( _AUTONOMINAL, true );
  tPar.SetBitFlagValue( _PREFIX,      true );
  tPar.SetBitFlagValue( _DEVIATION,   true );
  tPar.SetBitFlagValue( _UNIT,        true );
  tPar.SetBitFlagValue( _SUFFIX,      true );
	tPar.sign := 0;

  str     := ksChar255( kompas.GetParamStruct(ko_Char255) );
  arrText := ksDynamicArray( tPar.GetTextArr );

	if ( (str = nil) Or (arrText = nil) ) then
    Exit;

  str.str := 'prefix';
 	arrText.ksAddArrayItem( -1, str );

	str.str := '+0,5';
 	arrText.ksAddArrayItem( -1, str );

	str.str := '-0,5';
 	arrText.ksAddArrayItem( -1, str );

  str.str := 'mm';
 	arrText.ksAddArrayItem( -1, str );

  str.str := 'pp&04ww&01oo';
 	arrText.ksAddArrayItem( -1, str );

	obj := doc.ksLinDimension( param );

	if ( obj <> 0 ) then begin
		doc.ksGetObjParam( obj, param, ALLPARAM );
	  sPar.x2 := 50;
	  sPar.y2 := 60;
  	kompas.ksMessage( 'Поменяем параметры' );
    doc.ksSetObjParam( obj, param, ALLPARAM );
	end;
end;

//-------------------------------------------------------------------------------
//
// ---
procedure DrawAngDim;
var
  aDim     : ksADimParam;
  textLine : ksTextLineParam;
  textItem : ksTextItemParam;
  font     : ksTextItemFont;
  tPar     : ksDimTextParam;
  sPar     : ksADimSourceParam;
  dPar     : ksDimDrawingParam;
  arr      : ksDynamicArray;
  arr1     : ksDynamicArray;
  obj      : Reference;
begin
  aDim     := ksADimParam    ( kompas.GetParamStruct(ko_ADimParam)      );
  textLine := ksTextLineParam( kompas.GetParamStruct( ko_TextLineParam) );
  textItem := ksTextItemParam( kompas.GetParamStruct(ko_TextItemParam)  );
	if ( (aDim = nil) Or (textLine = nil) Or (textItem = nil) ) then
		Exit;

	textLine.Init;

	textItem.Init;
	textItem.s := 'Угловой размер';

	font := ksTextItemFont( textItem.GetItemFont );
	tPar := ksDimTextParam   ( aDim.GetTPar );
	sPar := ksADimSourceParam( aDim.GetSPar );
	dPar := ksDimDrawingParam( aDim.GetDPar );
	
	if ( (font = nil) Or (tPar = nil) Or (sPar = nil) Or (dPar = nil) ) then
		Exit;

  dPar.Init;
	sPar.Init;
	sPar.rad := 50;

	tPar.Init( true );

	font.Init;
  font.height   := 5;
	font.ksu      := 1;
	font.fontName := 'GOST type A';
	font.SetBitVectorValue( NEW_LINE, true );

  arr := ksDynamicArray( textLine.GetTextItemArr );
	if ( arr = nil ) then
		Exit;

	arr.ksAddArrayItem( -1, textItem );

  arr1 := ksDynamicArray( tPar.GetTextArr );
	if ( arr1 = nil ) then
		Exit;

	arr1.ksAddArrayItem( -1, textLine );

  obj := doc.ksAngDimension( aDim );
	if obj <> 0 then begin
	  doc.ksGetObjParam( obj, aDim, ALLPARAM );
	  sPar.Init;
	  sPar.rad := 100;
  	kompas.ksMessage( 'Поменяем параметры' );
    doc.ksSetObjParam( obj, aDim, ALLPARAM );
	end;
end;

//-------------------------------------------------------------------------------
//
// ---
procedure DrawRough;
var
  roughPar : ksRoughParam;
  rPar     : ksRoughPar;
  shPar    : ksShelfPar;
  str      : ksChar255;
  ptext    : ksDynamicArray;
  obj      : Reference;
begin
  roughPar := ksRoughParam( kompas.GetParamStruct(ko_RoughParam) );  //
  if roughPar = nil then
    Exit;
  rPar  := ksRoughPar( roughPar.GetrPar  );   //
  shPar := ksShelfPar( roughPar.GetshPar );   //
  str   := ksChar255( kompas.GetParamStruct(ko_Char255) );
  if ( (rPar <> nil) And (shPar <> nil) And (str <> nil) ) then begin
    rPar.Init;
		shPar.Init;
		str.Init;

    //заполним параметры текста шероховатости
		rPar.style  := 0;
    rPar.type_  := 0;
		rPar.around := 0;
		rPar.x      := 50;
		rPar.y      := 50;
		rPar.ang    := 90;
		rPar.cText0 := 2;
		rPar.cText1 := 2;
		rPar.cText2 := 2;
		rPar.cText3 := 1;

    // режим, когда тексты задаются массивом строк символов
    ptext := ksDynamicArray( rPar.GetpText );
		if ptext = nil then
			Exit;
		str.str := '1';
		ptext.ksAddArrayItem( -1, str );
		str.str := '2';
		ptext.ksAddArrayItem( -1, str );
		str.str := '3';
		ptext.ksAddArrayItem( -1, str );
		str.str := '4';
		ptext.ksAddArrayItem( -1, str );
		str.str := '5';
		ptext.ksAddArrayItem( -1, str );
		str.str := '6';
		ptext.ksAddArrayItem( -1, str );
		str.str := '7';
		ptext.ksAddArrayItem( -1, str );

    // параметры выносной полки
    shPar.psh    := 0;   // полки нет
		shPar.ang    := 130; // угол наклона ножки
		shPar.length := 20;  // длина ножки

    obj := doc.ksRough( roughPar );
		if obj <> 0 then begin
		  doc.ksGetObjParam( obj, roughPar, ALLPARAM );
		  rPar.ang := 100;
    	kompas.ksMessage( 'Поменяем параметры' );
		  doc.ksSetObjParam( obj, roughPar, ALLPARAM );
    end;
  end;
end;

//-------------------------------------------------------------------------------
//
// ---
procedure DrawLeader;
var
  lead        : ksLeaderParam;
  tLinePar    : ksTextLineParam;
  ItemPar     : ksTextItemParam;
  tMathPoint  : ksMathPointParam;
  tFont       : ksTextItemFont;
  pText       : ksDynamicArray;
  TextItemArr : ksDynamicArray;
  pPolyLin    : ksDynamicArray;
  pMathPoint  : ksDynamicArray;
  obj         : Reference;
begin
  lead       := ksLeaderParam   ( kompas.GetParamStruct(ko_LeaderParam)    );
  tLinePar   := ksTextLineParam ( kompas.GetParamStruct(ko_TextLineParam)  );
  tMathPoint := ksMathPointParam( kompas.GetParamStruct(ko_MathPointParam) );
  ItemPar    := ksTextItemParam ( kompas.GetParamStruct(ko_TextItemParam)  );
  if ItemPar = nil then
    Exit;
  ItemPar.Init;
  tFont := ksTextItemFont( ItemPar.GetItemFont );
  if ( (lead <> nil) And (tLinePar <> nil) And (tFont <> nil) And (tMathPoint <> nil) ) then begin
    lead.Init;
    tLinePar.Init;
    tFont.Init;
    tMathPoint.Init;

    tFont.SetBitVectorValue( NEW_LINE, true );
		tLinePar.style := 0;

		pText       := ksDynamicArray( lead.GetpTextline       );
    TextItemArr := ksDynamicArray( tLinePar.GetTextItemArr );
		if ( (TextItemArr = nil) Or (pText = nil) ) then
			Exit;

    ItemPar.s := '1';
		TextItemArr.ksAddArrayItem( -1, ItemPar );
		pText.ksAddArrayItem( -1, tLinePar );

		TextItemArr.ksClearArray;
    ItemPar.s := '2';
		TextItemArr.ksAddArrayItem( -1, ItemPar );
		pText.ksAddArrayItem( -1, tLinePar );

		TextItemArr.ksClearArray;
    ItemPar.s := '3';
		TextItemArr.ksAddArrayItem( -1, ItemPar );
		pText.ksAddArrayItem( -1, tLinePar );

		pPolyLin   := ksDynamicArray( lead.GetpPolyline );
		pMathPoint := ksDynamicArray( kompas.GetDynamicArray(POINT_ARR) );
    if ( (pPolyLin = nil) Or (pMathPoint = nil) ) then
			Exit;

		tMathPoint.x := 10;
		tMathPoint.y := 10;
		pMathPoint.ksAddArrayItem( -1, tMathPoint );
		pPolyLin.ksAddArrayItem( -1, pMathPoint );

		tMathPoint.x := 30;
		tMathPoint.y := 10;
    pMathPoint.ksClearArray;
		pMathPoint.ksAddArrayItem( -1, tMathPoint );
		pPolyLin.ksAddArrayItem( -1, pMathPoint );

		lead.SetpPolyline( pPolyLin );

		//заполним параметры
		lead.x         := 50; // координаты базовой точки ( начало полки )
		lead.y         := 50;
		lead.arrowType := 1;  // тип стрелки
		lead.dirX      := 1;  // направление полки по X (1 -вправо -1-влево)
    lead.signType  := 0;  // тип знака
		lead.around    := 0;  // знак обработки по контуру 0-выключен 1- включен
		lead.cText0    := 1;  // количество строк текста над полкой 0- текст отсутствует
		lead.cText1    := 1;  // количество строк текста под полкой 0- текст отсутствует
		lead.cText2    := 0;  // количество строк текста над ножкой (не более 1 строки)0- текст отсутствует
		lead.cText3    := 1;  // количество строк текста под ножкой (не более 1 строки)0- текст отсутствует

    obj := doc.ksLeader( lead );
		if obj <> 0 then begin
		  doc.ksGetObjParam( obj, lead, ALLPARAM );
		  lead.x := 100;
    	kompas.ksMessage( 'Поменяем параметры' );
		  doc.ksSetObjParam( obj, lead, ALLPARAM );
    end;
  end;
end;

//-------------------------------------------------------------------------------
//
// ---
procedure DrawPosLeader;
var
  obj         : Reference;
  lead        : ksPosLeaderParam;
  ItemPar     : ksTextItemParam;
  tLinePar    : ksTextLineParam;
  tMathPoint  : ksMathPointParam;
  tFont       : ksTextItemFont;
  pText       : ksDynamicArray;
  TextItemArr : ksDynamicArray;
  pPolyLin    : ksDynamicArray;
  pMathPoint  : ksDynamicArray;
begin
  lead       := ksPosLeaderParam( kompas.GetParamStruct(ko_PosLeaderParam) );
  tLinePar   := ksTextLineParam ( kompas.GetParamStruct(ko_TextLineParam)  );
  tMathPoint := ksMathPointParam( kompas.GetParamStruct(ko_MathPointParam) );
  ItemPar    := ksTextItemParam ( kompas.GetParamStruct(ko_TextItemParam)  );
  if ItemPar = nil then
    Exit;
  ItemPar.Init;
  tFont := ksTextItemFont( ItemPar.GetItemFont );
  if ( (lead <> nil) And (tLinePar <> nil) And (tFont <> nil) And (tMathPoint <> nil) ) then begin
    lead.Init;
    tLinePar.Init;
    tFont.Init;
    tMathPoint.Init;

  	lead.style := INDICATIN_TEXT_LINE_ARR;
	  tFont.SetBitVectorValue( NEW_LINE, true );
		tLinePar.style := 0;

		pText       := ksDynamicArray( lead.GetpTextline       );
    TextItemArr := ksDynamicArray( tLinePar.GetTextItemArr );
		if ( (TextItemArr = nil) Or (pText = nil) ) then
			Exit;

		ItemPar.s := '1';
		TextItemArr.ksAddArrayItem( -1, ItemPar );
		pText.ksAddArrayItem( -1, tLinePar );

		TextItemArr.ksClearArray;
	  ItemPar.s := '4';
		TextItemArr.ksAddArrayItem( -1, ItemPar );
		pText.ksAddArrayItem( -1, tLinePar );

		pPolyLin   := ksDynamicArray( lead.GetpPolyline );
		pMathPoint := ksDynamicArray( kompas.GetDynamicArray(POINT_ARR) );
    if ( (pPolyLin = nil) Or (pMathPoint = nil) ) then
			Exit;

		tMathPoint.x := 10;
		tMathPoint.y := 10;
		pMathPoint.ksAddArrayItem( -1, tMathPoint );
		pPolyLin.ksAddArrayItem( -1, pMathPoint );

		tMathPoint.x := 30;
		tMathPoint.y := 10;
    pMathPoint.ksClearArray;
		pMathPoint.ksAddArrayItem( -1, tMathPoint );
		pPolyLin.ksAddArrayItem( -1, pMathPoint );

		lead.SetpPolyline( pPolyLin );

		//заполним параметры
		lead.x := 50;// координаты базовой точки ( начало полки )
		lead.y := 50;
		lead.arrowType := 1;
		lead.dirX := -1;

    obj := doc.ksPositionLeader( lead );
		if obj <> 0 then begin
		  doc.ksGetObjParam( obj, lead, ALLPARAM );
		  lead.x := 100;
    	kompas.ksMessage( 'Поменяем параметры' );
		  doc.ksSetObjParam( obj, lead, ALLPARAM );
    end;
  end;
end;

//-------------------------------------------------------------------------------
//
// ---
procedure DrawBrandLeader;
var
  lead       : ksBrandLeaderParam;
  tLinePar   : ksTextLineParam;
  ItemPar    : ksTextItemParam;
  str        : ksChar255;
  tMathPoint : ksMathPointParam;
  pMathPoint : ksDynamicArray;
  tFont      : ksTextItemFont;
  ptext      : ksDynamicArray;
  pPolyLin   : ksDynamicArray;
  obj        : Reference;
begin
  lead       := ksBrandLeaderParam( kompas.GetParamStruct(ko_BrandLeaderParam) );
  tLinePar   := ksTextLineParam   ( kompas.GetParamStruct(ko_TextLineParam)    );
  ItemPar    := ksTextItemParam   ( kompas.GetParamStruct(ko_TextItemParam)    );
  str        := ksChar255         ( kompas.GetParamStruct(ko_Char255)          );
  tMathPoint := ksMathPointParam  ( kompas.GetParamStruct(ko_MathPointParam)   );
  pMathPoint := ksDynamicArray    ( kompas.GetDynamicArray(POINT_ARR)          );
  if ( (lead <> nil) And (tLinePar <> nil) And (ItemPar <> nil) And (tMathPoint <> nil) And (str <> nil)
        And (pMathPoint <> nil) ) then begin
    lead.Init;
    tLinePar.Init;
    ItemPar.Init;
    str.Init;
    tMathPoint.Init;

		tFont    := ksTextItemFont( ItemPar.GetItemFont );
    ptext    := ksDynamicArray( lead.GetpTextline   );
		pPolyLin := ksDynamicArray( lead.GetpPolyline   );
		if ( (ptext = nil) Or (tFont = nil) Or (pPolyLin = nil) ) then
			Exit;
		tFont.Init;

		lead.cText0 := 1;

		str.str := '1';
		ptext.ksAddArrayItem( -1, str );
		str.str := '2';
		ptext.ksAddArrayItem( -1, str );
		str.str := '3';
		ptext.ksAddArrayItem( -1, str );

		tMathPoint.x := 10;
		tMathPoint.y := 10;
		pMathPoint.ksAddArrayItem( -1, tMathPoint );
		pPolyLin.ksAddArrayItem( -1, pMathPoint );

		tMathPoint.x := 30;
		tMathPoint.y := 10;
    pMathPoint.ksClearArray;
		pMathPoint.ksAddArrayItem( -1, tMathPoint );
		pPolyLin.ksAddArrayItem( -1, pMathPoint );

		// заполним параметры
		lead.x         := 50; // координаты базовой точки ( начало полки )
		lead.y         := 50;
		lead.arrowType := 1;
		lead.dirX      := -1;
		lead.cText0    := 1;
		lead.cText1    := 1;
		lead.cText2    := 1;

    obj := doc.ksBrandLeader( lead );
		if obj <> 0 then begin
		  doc.ksGetObjParam( obj, lead, ALLPARAM );
		  lead.x := 100;
    	kompas.ksMessage( 'Поменяем параметры' );
		  doc.ksSetObjParam( obj, lead, ALLPARAM );
    end;
  end;
end;

//-------------------------------------------------------------------------------
//
// ---
procedure DrawMarkerLeader;
var
  lead       : ksMarkerLeaderParam;
  tLinePar   : ksTextLineParam;
  ItemPar    : ksTextItemParam;
  tMathPoint : ksMathPointParam;
  str        : ksChar255;
  tFont      : ksTextItemFont;
  obj        : Reference;
  pCharArr, pPolyLin, pMathPoint : ksDynamicArray;
begin
  lead       := ksMarkerLeaderParam( kompas.GetParamStruct(ko_MarkerLeaderParam) );
  tLinePar   := ksTextLineParam    ( kompas.GetParamStruct(ko_TextLineParam)     );
  ItemPar    := ksTextItemParam    ( kompas.GetParamStruct(ko_TextItemParam)     );
  tMathPoint := ksMathPointParam   ( kompas.GetParamStruct(ko_MathPointParam)    );
  str        := ksChar255          ( kompas.GetParamStruct(ko_Char255)           );
  if ( (lead <> nil) And (tLinePar <> nil) And (ItemPar <> nil) And (tMathPoint <> nil) And (str <> nil) ) then begin
    lead.Init;
    tLinePar.Init;
    ItemPar.Init;
    tMathPoint.Init;
    str.Init;

		// заполним параметры
		lead.x         := 50; // координаты базовой точки ( начало полки )
		lead.y         := 50;
		lead.arrowType := 1;
		lead.cText0    := 1;
		lead.cText1    := 1;
		lead.cText2    := 1;
		lead.style1    := 0;

		pCharArr   := ksDynamicArray( lead.GetpTextline );
		pPolyLin   := ksDynamicArray( lead.GetpPolyline );
		pMathPoint := ksDynamicArray( kompas.GetDynamicArray(POINT_ARR) );
    tFont      := ksTextItemFont( ItemPar.GetItemFont );
		if ( (tFont = nil) Or (pCharArr = nil) Or (pPolyLin = nil) ) then
			Exit;
		tFont.Init;

		str.str := '1';
		pCharArr.ksAddArrayItem( -1, str );
		str.str := '2';
		pCharArr.ksAddArrayItem( -1, str );
		str.str := '3';
		pCharArr.ksAddArrayItem( -1, str );

		tMathPoint.x := 10;
		tMathPoint.y := 10;
		pMathPoint.ksAddArrayItem( -1, tMathPoint );
		pPolyLin.ksAddArrayItem( -1, pMathPoint );

		tMathPoint.x := 30;
		tMathPoint.y := 10;
    pMathPoint.ksClearArray;
		pMathPoint.ksAddArrayItem( -1, tMathPoint );
		pPolyLin.ksAddArrayItem( -1, pMathPoint );

    obj := doc.ksMarkerLeader( lead );
		if obj <> 0 then begin
		  doc.ksGetObjParam( obj, lead, ALLPARAM );
		  lead.x := 100;
    	kompas.ksMessage( 'Поменяем параметры' );
		  doc.ksSetObjParam( obj, lead, ALLPARAM );
    end;
  end;
end;

//-------------------------------------------------------------------------------
//
// ---
procedure DrawBase;
var
  par : ksBaseParam;
  bas : reference;
begin
  par := ksBaseParam( kompas.GetParamStruct(ko_BaseParam) );
	if ( par <> nil ) then begin
		par.style := 0;
		par.type_ := false; // строка
		par.x1    := 10;
		par.y1    := 10;
		par.x2    := 30;
		par.y2    := 40;
		par.str   := 'Это база';
		bas       := doc.ksBase( par );
		par.Init;
		if bas <> 0 then begin
		  doc.ksGetObjParam( bas, par, ALLPARAM );
		  par.x2 := -30;
    	kompas.ksMessage( 'Поменяем параметры' );
	  	doc.ksSetObjParam( bas, par, ALLPARAM );
		end;
	end;
end;

//-------------------------------------------------------------------------------
//
// ---
procedure DrawCutLine;
var
  cut        : ksCutLineParam;
  tLinePar   : ksTextLineParam;
  ItemPar    : ksTextItemParam;
  tFont      : ksTextItemFont;
  tMathPoint : ksMathPointParam;
  pMathPoint : ksDynamicArray;
  obj        : Reference;
begin
  cut        := ksCutLineParam( kompas.GetParamStruct(ko_CutLineParam) );
  tLinePar   := ksTextLineParam( kompas.GetParamStruct(ko_TextLineParam) );
  ItemPar    := ksTextItemParam( kompas.GetParamStruct(ko_TextItemParam) );
  tMathPoint := ksMathPointParam( kompas.GetParamStruct(ko_MathPointParam) );
  if ItemPar = nil then
    Exit;
  ItemPar.Init;
  tFont := ksTextItemFont( ItemPar.GetItemFont );
  if ( (cut <> nil) And (tLinePar <> nil) And (tFont <> nil) And (tMathPoint <> nil) ) then begin
    cut.Init;
    tLinePar.Init;
    tFont.Init;
    tMathPoint.Init;

    cut.type_ := 0;
		cut.x1    := 30;
		cut.y1    := 65;
		cut.x2    := 95;
		cut.y2    := 15;
		cut.right := 1;
		cut.str   := 'A$;1$';
 		pMathPoint := ksDynamicArray( cut.GetpMathPoint );

  	tMathPoint.x := 50;
	  tMathPoint.y := 50;
	  pMathPoint.ksAddArrayItem( -1, tMathPoint );

 		tMathPoint.x := 50;
  	tMathPoint.y := 30;
	  pMathPoint.ksAddArrayItem( -1, tMathPoint );

	  tMathPoint.x := 80;
	  tMathPoint.y := 30;
	  pMathPoint.ksAddArrayItem( -1, tMathPoint );

    obj := doc.ksCutLine( cut );
    if obj <> 0 then begin
		  doc.ksGetObjParam( obj, cut, ALLPARAM );

			pMathPoint.ksClearArray;

  	  tMathPoint.x := 30;
	    tMathPoint.y := 50;
	    pMathPoint.ksAddArrayItem( -1, tMathPoint );

 		  tMathPoint.x := 30;
  	  tMathPoint.y := 30;
	    pMathPoint.ksAddArrayItem( -1, tMathPoint );

	    tMathPoint.x := 80;
	    tMathPoint.y := 30;
	    pMathPoint.ksAddArrayItem( -1, tMathPoint );

			kompas.ksMessage( 'Поменяем параметры' );
	  	doc.ksSetObjParam( obj, cut, ALLPARAM );
    end;
	end;
end;

//-------------------------------------------------------------------------------
//
// ---
procedure DrawDiamDim;
var
  cir, obj  : Reference;
  aDim      : ksRDimParam;
  textLine  : ksTextLineParam;
  textItem  : ksTextItemParam;
  tPar      : ksDimTextParam;
  font      : ksTextItemFont;
  arr, arr1 : ksDynamicArray;
  sPar      : ksRDimSourceParam;
  dPar      : ksRDimDrawingParam;
begin
	cir      := doc.ksCircle( 100, 100, 50, 1 );
  aDim     := ksRDimParam    ( kompas.GetParamStruct(ko_RDimParam)      );
  textLine := ksTextLineParam( kompas.GetParamStruct( ko_TextLineParam) );
  textItem := ksTextItemParam( kompas.GetParamStruct(ko_TextItemParam)  );
  if ( (aDim = nil) Or (textLine = nil) Or (textItem = nil) ) then
		Exit;

	textLine.Init;
	textItem.Init;

	tPar := ksDimTextParam( aDim.GetTPar            );
	font := ksTextItemFont( textItem.GetItemFont    );
  arr  := ksDynamicArray( textLine.GetTextItemArr );
	sPar := ksRDimSourceParam( aDim.GetSPar );
	dPar := ksRDimDrawingParam( aDim.GetDPar );
	if ( (tPar = nil) Or (font = nil) Or (sPar = nil) Or (dPar = nil) ) then
		Exit;

	tPar.Init( true );
	tPar.SetBitFlagValue( _AUTONOMINAL, true );
  tPar.sign := 1;

	font.Init;
	font.height   := 5;
	font.ksu      := 1;
	font.fontName := 'GOST type A';
	font.SetBitVectorValue( NEW_LINE, true );
	arr.ksAddArrayItem( -1, textItem );

  arr1 := ksDynamicArray( tPar.GetTextArr );
	if arr1 = nil then
		Exit;
	arr1.ksAddArrayItem( -1, textLine );

	sPar.Init;
	sPar.xc  := 100;
	sPar.yc  := 100;
	sPar.rad := 50;

  dPar.Init;
  obj := doc.ksDiamDimension( aDim );
	if obj <> 0 then begin
	  doc.ksGetObjParam( obj, aDim, ALLPARAM );
	  sPar.rad := 100;
  	kompas.ksMessage( 'Поменяем параметры' );
		doc.ksDeleteObj( cir );
 	  doc.ksCircle( 100, 100, 100, 1 );
    doc.ksSetObjParam( obj, aDim, ALLPARAM );
	end;
end;

//-------------------------------------------------------------------------------
//
// ---
procedure DrawRadDimt;
var
  cir, obj  : Reference;
  aDim      : ksRDimParam;
  textLine  : ksTextLineParam;
  textItem  : ksTextItemParam;
  tPar      : ksDimTextParam;
  font      : ksTextItemFont;
  arr, arr1 : ksDynamicArray;
  sPar      : ksRDimSourceParam;
  dPar      : ksRDimDrawingParam;
begin
	cir      := doc.ksCircle( 100, 100, 50, 1 );
  aDim     := ksRDimParam    ( kompas.GetParamStruct(ko_RDimParam)       );
  textLine := ksTextLineParam( kompas.GetParamStruct( ko_TextLineParam ) );
  textItem := ksTextItemParam( kompas.GetParamStruct(ko_TextItemParam)   );
  if ( (aDim = nil) Or (textLine = nil) Or (textItem = nil) ) then
		Exit;

	textLine.Init;
	textItem.Init;

	tPar := ksDimTextParam( aDim.GetTPar );
	font := ksTextItemFont( textItem.GetItemFont );
  arr  := ksDynamicArray( textLine.GetTextItemArr );
	sPar := ksRDimSourceParam( aDim.GetSPar );
	dPar := ksRDimDrawingParam( aDim.GetDPar );
	if ( (tPar = nil) Or (font = nil) Or (sPar = nil) Or (dPar = nil) ) then
		Exit;

	tPar.Init( true );
 	tPar.SetBitFlagValue( _AUTONOMINAL, true );
  tPar.sign := 1;


	font.Init;
	font.height   := 5;
	font.ksu      := 1;
	font.fontName := 'GOST type A';
	font.SetBitVectorValue( NEW_LINE, true );
	arr.ksAddArrayItem( -1, textItem );

  arr1 := ksDynamicArray( tPar.GetTextArr );
	if ( arr1 = nil ) then
		Exit;

	arr1.ksAddArrayItem( -1, textLine );

	sPar.Init;
	sPar.xc  := 100;
	sPar.yc  := 100;
	sPar.rad := 50;

  dPar.Init;
  obj := doc.ksRadDimension( aDim );
	if obj <> 0 then begin
	  doc.ksGetObjParam( obj, aDim, ALLPARAM );
	  sPar.rad := 100;
  	kompas.ksMessage( 'Поменяем параметры' );
		doc.ksDeleteObj( cir );
 	  doc.ksCircle( 100, 100, 100, 1 );
    doc.ksSetObjParam( obj, aDim, ALLPARAM );
	end;
end;

//-------------------------------------------------------------------------------
//
// ---
procedure DrawRadBreakDimt;
var
  cir, obj  : Reference;
  aDim      : ksRBreakDimParam;
  textLine  : ksTextLineParam;
  textItem  : ksTextItemParam;
  tPar      : ksDimTextParam;
  font      : ksTextItemFont;
  arr, arr1 : ksDynamicArray;
  sPar      : ksRDimSourceParam;
  dPar      : ksRBreakDrawingParam;
begin
	cir      := doc.ksCircle( 100, 100, 50, 1 );
  aDim     := ksRBreakDimParam( kompas.GetParamStruct(ko_RBreakDimParam) );
  textLine := ksTextLineParam( kompas.GetParamStruct( ko_TextLineParam ) );
  textItem := ksTextItemParam( kompas.GetParamStruct(ko_TextItemParam) );
  if ( (textItem = nil) Or (aDim = nil) ) then
    Exit;
	textItem.Init;
	font := ksTextItemFont( textItem.GetItemFont );
	tPar := ksDimTextParam( aDim.GetTPar         );
	if ( (tPar <> nil) And (textLine <> nil) And (font <> nil) ) then begin
		tPar.Init( true );
		textLine.Init;
		font.Init;
  	tPar.SetBitFlagValue( _AUTONOMINAL, true );
		tPar.sign := 1;

    font.height   := 5;
    font.ksu      := 1;
    font.fontName := 'GOST type A';
		font.SetBitVectorValue( NEW_LINE, true );

		arr  := ksDynamicArray      ( textLine.GetTextItemArr );
		arr1 := ksDynamicArray      ( tPar.GetTextArr         );
		sPar := ksRDimSourceParam   ( aDim.GetSPar            );
		dPar := ksRBreakDrawingParam( aDim.GetDPar            );
    if ( (sPar <> nil) And (dPar <> nil) And (arr <> nil) And (arr1 <> nil) ) then begin
			sPar.Init;
			dPar.Init;
			arr.ksAddArrayItem( -1, textItem );
			arr1.ksAddArrayItem( -1, textLine );

			sPar.xc  := 100;
			sPar.yc  := 100;
			sPar.rad := 50;

			dPar.ang := 0;
			dPar.pb  := 30;
			dPar.pt  := 1;

			obj := doc.ksRadBreakDimension( aDim );
			if obj <> 0 then begin
				doc.ksGetObjParam( obj, aDim, ALLPARAM );
				sPar.rad := 100;
  			kompas.ksMessage( 'Поменяем параметры' );
				doc.ksDeleteObj( cir );
 				doc.ksCircle( 100, 100, 100, 1 );
				doc.ksSetObjParam( obj, aDim, ALLPARAM );
			end;
		end;
	end;
end;

//-------------------------------------------------------------------------------
//
// ---
procedure DrawViewPointer;
var
  viewPoint : ksViewPointerParam;
  ItemPar   : ksTextItemParam;
  tFont     : ksTextItemFont;
  p         : reference;
begin
  viewPoint := ksViewPointerParam( kompas.GetParamStruct(ko_ViewPointerParam) );
  ItemPar   := ksTextItemParam   ( kompas.GetParamStruct(ko_TextItemParam)    );
  if ( (viewPoint <> nil) And (ItemPar <> nil) ) then begin
		ItemPar.Init;
	  viewPoint.Init;
		tFont := ksTextItemFont( ItemPar.GetItemFont );
		if tFont <> nil then begin
			tFont.Init;

			viewPoint.x1    := 55;
			viewPoint.y1    := 50;
			viewPoint.x2    := 40;
			viewPoint.y2    := 50;
			viewPoint.xt    := 40;
			viewPoint.yt    := 52;
			viewPoint.type_ := 0;
			viewPoint.str   := 'стрелка';

			p := doc.ksViewPointer( viewPoint );
			if p <> 0 then begin
				doc.ksGetObjParam( p, viewPoint, ALLPARAM);
   			viewPoint.type_ := 0;
				viewPoint.str   := 'стрелка вида';
    		kompas.ksMessage( 'Поменяем параметры' );
				doc.ksSetObjParam( p, viewPoint, ALLPARAM );
			end;
		end;
	end;
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
procedure LIBRARYENTRY( command: WORD ); pascal;
begin
  kompas := KompasObject( CreateKompasObject );

  if kompas <> nil then begin
    doc := ksDocument2D( kompas.ActiveDocument2D );
    if ( doc <> nil ) then begin
      case command of
        1  : DrawLinDim      ; //линейный размер
        2  : DrawAngDim      ; //угловой размер
        3  : DrawRough       ; //шероховатость
        4  : DrawLeader      ; //линия выноски
        5  : DrawPosLeader   ; //позиционная линия выноски
        6  : DrawBrandLeader ; //клеймение
        7  : DrawMarkerLeader; //маркирование
        8  : DrawBase        ; //обозначение базы
        9  : DrawCutLine     ; //маркирование
        10 : DrawDiamDim     ; //диаметральный размер
        11 : DrawRadDimt     ; //радиальный размер
        12 : DrawRadBreakDimt; //радиальный размер c изломом
        13 : DrawViewPointer ; //cтрелка вида
      end;

      kompas.ksMessageBoxResult;

      doc := nil;
    end;
    kompas := nil;
  end;
end;

end.
