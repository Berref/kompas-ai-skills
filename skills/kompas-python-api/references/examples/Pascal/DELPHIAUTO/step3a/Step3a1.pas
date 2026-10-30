unit Step3a1;

{$IFDEF CONDITIONALEXPRESSIONS}
{$IF CompilerVersion >= 14 }
  {$WARN SYMBOL_PLATFORM OFF}
{$IFEND}
{$ENDIF}

interface
  procedure  LIBRARYENTRY( command: WORD  ); Pascal;
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
  kompas : KompasObject;
  doc    : ksDocument2D;

//-------------------------------------------------------------------------------
// Построить контур
// ---
procedure WorkContour;
var
  _contour, g : reference;
begin
  if ( doc.ksContour(1) <> 0 ) then begin
    doc.ksLineSeg( 20, 30, 50, 30, 1 );
    doc.ksArcByPoint( 50, 20, 10, 50,30, 50, 10, -1, 1 );
    //вложенный контур
    doc.ksContour( 2 );
      doc.ksLineSeg( 50, 10, 20, 10, 1 );
      doc.ksArcByPoint( 20, 20, 10, 20,10, 20, 30, -1, 1 );
    doc.ksEndObj;
    _contour := doc.ksEndObj;

    doc.ksLightObj( _contour, 1 );
    kompas.ksMessage( 'контур' );
    doc.ksLightObj( _contour, 1 );
    g := doc.ksNewGroup( 0 );
    doc.ksEndGroup;
    doc.ksAddObjGroup( g, _contour );
    doc.ksMoveObj( g, 10, 10 );
    kompas.ksMessage( 'сдвинули группу' );
  end;
end;

//-------------------------------------------------------------------------------
// заполнение технических требований
// ---
procedure TDemWork;
var
  pGab      : ksDynamicArray;
  par       : ksRectParam;
  pBot      : ksMathPointParam;
  pTop      : ksMathPointParam;
  itemParam : ksTextItemParam;
  itemFont  : ksTextItemFont;
begin
	pGab := ksDynamicArray( kompas.GetDynamicArray(RECT_ARR) );
  //поместим техтребования в двух габаритных окнах
  par  := ksRectParam( kompas.GetParamStruct(ko_RectParam) );
	pBot := ksMathPointParam( kompas.GetParamStruct(ko_MathPointParam) );
	pTop := ksMathPointParam( kompas.GetParamStruct(ko_MathPointParam) );
	if ( (pGab <> nil) And (par <> nil) And (pBot <> nil) And (pTop <> nil) ) then begin
		pBot.Init;
		pTop.Init;

		pTop.x := 415;
		pTop.y := 80;
		par.SetpTop( pTop );
		pBot.x := 230;
		pBot.y := 65;
		par.SetpBot( pBot );
		pGab.ksAddArrayItem( -1, par );

		pTop.x := 230;
		pTop.y := 60;
		par.SetpTop( pTop );
		pBot.x := 45;
		pBot.y := 15;
		par.SetpBot( pBot );
		pGab.ksAddArrayItem( -1, par );

		if( doc.ksOpenTechnicalDemand(pGab, 0) <> 0 ) then begin
	    itemParam := ksTextItemParam( kompas.GetParamStruct(ko_TextItemParam) );
		  if ( itemParam <> nil ) then begin
			  itemParam.Init;

				itemFont := ksTextItemFont( itemParam.GetItemFont );
				if ( itemFont <> nil ) then begin
					itemFont.Init;
				 	itemFont.SetBitVectorValue( NEW_LINE, true );
					itemParam.s := '1111111';
					doc.ksTextLine( itemParam );

					itemFont.Init;
				 	itemFont.SetBitVectorValue( NEW_LINE, true );
					itemParam.s := '2222222';
					doc.ksTextLine( itemParam );

					itemFont.Init;
				 	itemFont.SetBitVectorValue( NEW_LINE, true );
					itemParam.s := '3333333';
					doc.ksTextLine( itemParam );

					itemFont.Init;
				 	itemFont.SetBitVectorValue( NEW_LINE, true );
					itemParam.s := '4444444';
					doc.ksTextLine( itemParam );

					itemFont.Init;
				 	itemFont.SetBitVectorValue( NEW_LINE, true );
					itemParam.s := '5555555';
					doc.ksTextLine( itemParam );

					itemFont.Init;
				 	itemFont.SetBitVectorValue( NEW_LINE, true );
					itemParam.s := '6666666';
					doc.ksTextLine( itemParam );
				end;
			end;

			doc.ksCloseTechnicalDemand;
		end;
	end;
end;

//-------------------------------------------------------------------------------
// Создание таблицы
// ---
procedure TableWork;
begin
  doc.ksTable;
    doc.ksLineSeg( 50, 50, 90, 50, 1 );
    doc.ksLineSeg( 50, 40, 90, 40, 1 );
    doc.ksLineSeg( 50, 30, 90, 30, 1 );
    doc.ksLineSeg( 50, 50, 50, 30, 1 );
    doc.ksLineSeg( 70, 50, 70, 30, 1 );
    doc.ksLineSeg( 90, 50, 90, 30, 1 );

    doc.ksText( 52, 48, 0, 5, 1, 0, '1' );
    doc.ksText( 72, 48, 0, 5, 1, 0, '2' );
    doc.ksText( 52, 38, 0, 5, 1, 0, '3' );
    doc.ksText( 72, 38, 0, 5, 1, 0, '4' );
  doc.ksEndObj;
end;

//-------------------------------------------------------------------------------
// Создание стрелки вида
// ---
procedure DrawViewPointer;
var
  par : ksViewPointerParam;
  p   : reference;
begin
  par := ksViewPointerParam( kompas.GetParamStruct(ko_ViewPointerParam) );
	if ( par <> nil ) then begin
		par.Init;
		par.x1    := 55;
		par.y1    := 50;   // координаты вершины( острия) стрелки
		par.x2    := 40;
		par.y2    := 50;   // координаты конечной точки стрелки
		par.xt    := 40;
		par.yt    := 52;   // координаты текста
		par.type_ := 0;
		par.str   := 'A';  // надпись

		p := doc.ksViewPointer( par ); //параметры "стрелки вида"
		if ( doc.ksExistObj(p) <> 0 ) then
			doc.ksLightObj( p, 1 );
	end;
end;

//-------------------------------------------------------------------------------
// заполнение основной надписи
// ---
procedure WorkStamp;
var
  stamp     : ksStamp;
  itemParam : ksTextItemParam;
  itemFont  : ksTextItemFont;
begin
	stamp := ksStamp( doc.GetStamp );
	if ( stamp <> nil ) then begin
		if ( stamp.ksOpenStamp <> 0 ) then begin
			stamp.ksColumnNumber( 2 );

	    itemParam := ksTextItemParam( kompas.GetParamStruct(ko_TextItemParam) );
		  if ( itemParam <> nil ) then begin
			  itemParam.Init;

				itemFont := ksTextItemFont( itemParam.GetItemFont );
				if ( itemFont <> nil ) then begin
				 	itemFont.SetBitVectorValue( NEW_LINE, true );
					itemParam.s := '1111111';
					doc.ksTextLine( itemParam );
				end;
			end;

		  stamp.ksCloseStamp;
		end;
  end;
end;

//-------------------------------------------------------------------------------
// Допуск формы
// ---
procedure WorkTolerance;
var
  par       : ksToleranceParam;
  parPoint  : ksMathPointParam;
  branchArr : ksDynamicArray;
  tolBran   : ksToleranceBranch;
  arr       : ksDynamicArray;
  itemParam : ksTextItemParam;
  itemFont  : ksTextItemFont;
  p         : reference;
begin
	par      := ksToleranceParam( kompas.GetParamStruct(ko_ToleranceParam) );
	parPoint := ksMathPointParam( kompas.GetParamStruct(ko_MathPointParam) );
	if ( (par <> nil) And (parPoint <> nil) ) then begin
		par.Init;
		parPoint.Init;

		branchArr := ksDynamicArray( par.GetBranchArr );
		tolBran   := ksToleranceBranch( kompas.GetParamStruct(ko_ToleranceBranch) );
		if ( (branchArr <> nil) And (tolBran <> nil) ) then begin
  		tolBran.Init;

			arr := ksDynamicArray( tolBran.GetpMathPoint );
			if ( arr <> nil ) then begin
				// заполняем параметры 1-ой ноги
				parPoint.x := 40;
				parPoint.Y := 10;
				arr.ksAddArrayItem( -1, parPoint );
				tolBran.arrowType := 2;
				tolBran.tCorner   := 1;
				branchArr.ksAddArrayItem( -1, tolBran );

				// заполняем параметры 2-ой ноги
				arr.ksClearArray;
				parPoint.x := 100;
				parPoint.y := 50;
				arr.ksAddArrayItem( -1, parPoint );
				parPoint.x := 100;
				parPoint.y := 10;
				arr.ksAddArrayItem( -1, parPoint );
				tolBran.arrowType := 1;
				tolBran.tCorner   := 5;
				branchArr.ksAddArrayItem( -1, tolBran );

				par.x     := 40;
				par.y     := 40;
				par.type_ := 0;

				// допуск формы составной объект
				if ( doc.ksTolerance(par) <> 0) then begin
					itemParam := ksTextItemParam( kompas.GetParamStruct(ko_TextItemParam) );
					if ( itemParam <> nil ) then begin
						itemParam.Init;

						itemFont := ksTextItemFont( itemParam.GetItemFont );
						if ( itemFont <> nil ) then begin
							doc.ksColumnNumber( 1 );
			 				itemFont.SetBitVectorValue( SPECIAL_SYMBOL, true );
							itemParam.type_  := SPECIAL;
							itemParam.iSNumb := 26;
							doc.ksTextLine( itemParam );

							itemParam.Init;
							doc.ksColumnNumber( 2 );
					 		itemFont.SetBitVectorValue( NEW_LINE, true );
							itemParam.s := '2222';
							doc.ksTextLine( itemParam );

							doc.ksColumnNumber( 3 );
					 		itemFont.SetBitVectorValue( NEW_LINE, true );
							itemParam.s := '2222';
							doc.ksTextLine( itemParam );

							itemParam.Init;
							doc.ksColumnNumber( 11 );
			 				itemFont.SetBitVectorValue( SPECIAL_SYMBOL, true );
							itemParam.type_  := SPECIAL;
							itemParam.iSNumb := 23;
							doc.ksTextLine( itemParam );

							itemParam.Init;
							doc.ksColumnNumber( 12 );
					 		itemFont.SetBitVectorValue( NEW_LINE, true );
							itemParam.s := '444';
							doc.ksTextLine( itemParam );
					 		itemFont.SetBitVectorValue( NEW_LINE, true );
							itemParam.s := '555';
							doc.ksTextLine( itemParam );
						end;
					end;
				end;

				p := doc.ksEndObj; //вернется указатель на допуск формы
				doc.ksLightObj( p, 1 );
			end;
			arr.ksDeleteArray;
			branchArr.ksDeleteArray;
		end;
	end;
end;

//-------------------------------------------------------------------------------
// Построить эквидистанту
// ---
procedure DrawEquidistant;
var
  par   : ksEquidistantParam;
  info  : ksRequestInfo;
  x, y  : Double;
  j     : Integer;
  p1    : reference;
begin
  par  := ksEquidistantParam( kompas.GetParamStruct(ko_EquidParam) );
	info := ksRequestInfo( kompas.GetParamStruct(ko_RequestInfo) );
	if ( (par <> nil) And (info <> nil) ) then begin
		par.side     := 2;     // признак, с какой стороны строить эквидистанту
			                     // 0-слева по направлению, 1-справа по направлению, 2-с двух сторон
		par.cutMode  := False; // тип обхода углов контура
			                     // 0-обход срезом, 1- обход дугой
		par.degState := False; // флаг разрешения вырожденных сегментов эквидистанты
			                     // 0-вырожденные сегменты запрещены, 1-вырожденные сегменты разрешены
		par.radRight := 5;     // радиус эквидистанты
		par.radLeft  := 3;     // радиус эквидистанты
		par.style    := 1;     // тип линии
		info.commandsString := 'Укажите объект';
		// найдем объект
		repeat
			j := doc.ksCursor( info, x, y, Nil );
	    if ( j <> 0 ) then begin
				par.geoObj := doc.ksFindObj( x, y, 1e6 );
		    if ( doc.ksExistObj(par.geoObj) <> 0 ) then begin
          p1 := doc.ksEquidistant( par );
			    if ( p1 <> 0 ) then begin // параметры эквидистанты
					  doc.ksLightObj( p1, 1 );
						kompas.ksMessage( 'эквидистанта' );
			      doc.ksLightObj( p1, 0 );
		      end
			    else
				    kompas.ksMessageBoxResult;
				end
				else
					kompas.ksError( 'объект не найден' );
			end;
		until j = 0;
	end;
end;

//-------------------------------------------------------------------------------
// Создать эллипс
// ---
procedure DrawEllipse;
var
  par : ksEllipseParam;
  p   : reference;
begin
  par := ksEllipseParam( kompas.GetParamStruct(ko_EllipseParam) );
	if ( par <> nil ) then begin
		par.Init;
		par.xc    := 50;
		par.yc    := 40;
		par.a     := 20;
		par.B     := 10;
		par.style := 1;
		p := doc.ksEllipse( par );
		doc.ksLightObj( p, 1 );
		kompas.ksMessage( 'эллипс' );
		doc.ksLightObj( p, 0 );
	end;
end;

//-------------------------------------------------------------------------------
// Создание полилинии
// ---
procedure DrawPolyline;
var
  par : ksPolylineParam;
  pr  : ksMathPointParam;
  arr : ksDynamicArray;
  p   : reference;
begin
  //пример создания полилинии одной функцией
  par := ksPolylineParam( kompas.GetParamStruct(ko_PolylineParam) );
	pr  := ksMathPointParam( kompas.GetParamStruct(ko_MathPointParam) );
	if ( (par <> nil) And (pr <> nil) ) then begin
		par.Init;
		pr.Init;

		arr := ksDynamicArray( par.GetpMathPoint );
		if ( arr <> nil ) then begin
			pr.x := 10;
			pr.y := 10;
			arr.ksAddArrayItem( -1, pr );
			pr.x := 20;
			pr.y := 20;
			arr.ksAddArrayItem( -1, pr );
			pr.x := 30;
			pr.y := 10;
			arr.ksAddArrayItem( -1, pr );
			pr.x := 40;
			pr.y := 20;
			arr.ksAddArrayItem( -1, pr );

			par.style := 2;
			p := doc.ksPolylineByParam( par );
			doc.ksLightObj( p, 1 );
			kompas.ksMessage( 'Полилиния' );
			doc.ksLightObj( p, 0 );

			arr.ksDeleteArray;
		end;
	end;
end;

//-------------------------------------------------------------------------------
// Создать  Nurbs - сплайн
// ---
procedure DrawNurbs;
var
  par : ksNurbsPointParam;
  p   : reference;
begin
	par := ksNurbsPointParam( kompas.GetParamStruct(ko_NurbsPointParam) );
	if ( par <> nil ) then begin
		par.Init;
		//построить Nurbs сплайн  как составной объект
		doc.ksNurbs( 3, False, 1 );
			par.x      := 0;
			par.y      := 0;
			par.weight := 1;
			doc.ksNurbsPoint( par );
			par.x      := 20;
			par.y      := 20;
			par.weight := 1;
			doc.ksNurbsPoint( par );
			par.x      := 50;
			par.y      := 10;
			par.weight := 1;
			doc.ksNurbsPoint( par );
			par.x      := 70;
			par.y      := 20;
			par.weight := 1;
			doc.ksNurbsPoint( par );
			par.x      := 100;
			par.y      := 0;
			par.weight := 1;
			doc.ksNurbsPoint( par );
			par.x      := 50;
			par.y      := -50;
			par.weight := 1;
			doc.ksNurbsPoint( par );
		p := doc.ksEndObj;
		doc.ksLightObj( p, 1 );
		kompas.ksMessage( 'NURBS' );
		doc.ksLightObj( p, 0 );
	end;
end;

//-------------------------------------------------------------------------------
//
// ---
procedure DrawSpecRough;
var
  par : ksSpecRoughParam;
begin
	par := ksSpecRoughParam( kompas.GetParamStruct(ko_SpecRoughParam) );
	if ( par <> nil ) then begin
		par.Init;
		par.t     := True;
		par.s     := 'Rz40';
		par.sign  := 2;
		par.style := 1;
		doc.ksSpecRough( par );
	end;
end;

//-------------------------------------------------------------------------------
// Вставка внешнего фрагмента
// ---
procedure DrawInsFragment1;
var
  frg        : ksFragment;
  par        : ksPlacementParam;
  pDefFrg, p : reference;
begin
	frg := ksFragment( doc.GetFragment );
	if ( frg <> nil ) then begin
		// определим фрагмент для вставки
		pDefFrg := frg.ksFragmentDefinition( 'c:\1.frw', // имя файла фрагмента
																				'frw1',      // имя вставки
																				1 );         // тип вставки 1 - внешней ссылкой
		if ( pDefFrg <> 0 ) then begin
			par := ksPlacementParam( kompas.GetParamStruct(ko_PlacementParam) );
			if ( par <> nil ) then begin
				par.Angle  := 45;
				par.scale_ := 2;
				par.xBase  := 30;
				par.yBase  := 40;
		    // создаем объект "вставка фрагмента"
				p := frg.ksInsertFragment( pDefFrg,     // Указатель определения  фрагмента
											             false,       // тип размещения по слоям false - на свои слои
															     par );       // параметры привязки
		    doc.ksLightObj( p, 1 );
			  kompas.ksMessage( 'вставка внешнего фрагмента' );
				doc.ksLightObj( p, 0 );
			end;
		end;
	end;
end;

//-------------------------------------------------------------------------------
// Вставка локального фрагмента
// ---
procedure DrawInsFragment2;
var
  frg        : ksFragment;
  par        : ksPlacementParam;
  pDefFrg, p : reference;
begin
	// определим фрагмент для вставки
	frg := ksFragment( doc.GetFragment );
	if ( frg <> nil ) then begin
		// определим локальный фрагмент
	  if ( frg.ksLocalFragmentDefinition('local') <> 0 ) then begin
	    doc.ksLineSeg( 0, 0, 10, 0,  1 );
		  doc.ksLineSeg( 0, 0,  0, 10, 1 );
			doc.ksArcByPoint( 0, 0, 10, 10, 0, 0, 10, -1, 1 );
			pDefFrg := frg.ksCloseLocalFragmentDefinition;
		  if ( pDefFrg <> 0 ) then begin
				par := ksPlacementParam( kompas.GetParamStruct(ko_PlacementParam) );
				if ( par <> nil ) then begin
					par.Angle  := 45;
					par.scale_ := 2;
					par.xBase  := 30;
					par.yBase  := 40;
			    // создаем объект "вставка фрагмента"
					p := frg.ksInsertFragment( pDefFrg,     // Указатель определения  фрагмента
												             false,       // тип размещения по слоям false - на свои слои
																     par );       // параметры привязки
			    doc.ksLightObj( p, 1 );
				  kompas.ksMessage( 'вставка локального фрагмента' );
					doc.ksLightObj( p, 0 );
				end;
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
				1  : WorkContour;       // контур
				2  : TDemWork;				  // технические требования
				3  : DrawViewPointer;   // стрелка вида
				4  : WorkStamp;				  // работа со штампом
				5  : TableWork;				  // таблица
				6  : DrawEquidistant;   // эквидистанта
				7  : DrawEllipse;       // эллипс
				8  : DrawPolyline;      // полилиния
				9  : DrawNurbs;				  // nurbs
				10 : WorkTolerance;		  // допуск формы
				11 : DrawSpecRough;     // одинаковая шероховатость
				12 : DrawInsFragment1;  // вставка фрагмента внешней ссылкой
				13 : DrawInsFragment2;  // вставка локального фрагмента
      end;

      kompas.ksMessageBoxResult;

      doc := nil;
    end;
    kompas := nil;
  end;
end;

end.
