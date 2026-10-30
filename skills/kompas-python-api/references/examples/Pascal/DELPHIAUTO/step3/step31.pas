unit step31;

{$IFDEF CONDITIONALEXPRESSIONS}
{$IF CompilerVersion >= 14 }
  {$WARN SYMBOL_PLATFORM OFF}
{$IFEND}
{$ENDIF}


interface
  procedure  LIBRARYENTRY( command: WORD  ); Pascal;
  function   LIBRARYID   : Cardinal;      Pascal;

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
//  работа с документом
//-------------------------------------------------------------------------------
procedure WorkDocument;
var
  buf     : string;
  docPar  : ksDocumentParam;
  docPar1 : ksDocumentParam;
  shPar   : ksSheetPar;
  stPar   : ksStandartSheet;
  par     : ksViewParam;
  number  : Integer;
  shPar1  : ksSheetPar;
  stPar1  : ksStandartSheet;
  direct  : SmallInt;
begin
	doc     := ksDocument2D( kompas.Document2D );
	docPar  := ksDocumentParam( kompas.GetParamStruct(ko_DocumentParam) );
	docPar1 := ksDocumentParam( kompas.GetParamStruct(ko_DocumentParam) );
	if ( (docPar <> nil) And (docPar1 <> nil) ) then begin
		docPar.fileName := 'c:\2.cdw';
		docPar.comment  := 'create document';
		docPar.author   := 'user';
		docPar.regime   := 0;
		docPar.type_    := lt_DocSheetStandart;
		shPar           := ksSheetPar( docPar.GetLayoutParam() );
		if ( shPar <> nil ) then begin
			shPar.shtType    := 1;
			shPar.layoutName := '';
			stPar            := ksStandartSheet( shPar.GetSheetParam() );
			if ( stPar <> nil ) then begin
				stPar.format   := 3;
				stPar.multiply := 1;
				stPar.direct   := false;
			end;
		end;
		// создали документ: лист, формат А3, горизонтально расположенный
		// и с системным штампом 1
		doc.ksCreateDocument( docPar );

		par := ksViewParam( kompas.GetParamStruct(ko_ViewParam) );
		if ( par <> nil ) then begin
			number := 2;
			par.Init;
			par.x      := 10;
			par.y      := 20;
			par.scale_ := 0.5;
			par.Angle  := 45;
			par.Color  := RGB( 10, 20, 10 );
			par.state  := stACTIVE;
			par.name   := 'user view';
		  // у документа создадим вид с номером 2, масштабом 0.5, под углом 45 гр
			doc.ksCreateSheetView( par, number );

			// создадим слой с номером 5
			doc.ksLayer( 5 );

			doc.ksLineSeg( 20, 10, 40, 10, 1 );
			doc.ksLineSeg( 40, 10, 40, 30, 1 );
			doc.ksLineSeg( 40, 30, 20, 30, 1 );
			doc.ksLineSeg( 20, 30, 20, 10, 1 );

			kompas.ksMessage( 'нарисовали' );

		  // получить параметры документа
			doc.ksGetObjParam( doc.reference, docPar1, ALLPARAM );
			shPar1 := ksSheetPar( docPar1.GetLayoutParam() );
			if ( shPar1 <> nil ) then begin
				stPar1 := ksStandartSheet( shPar1.GetSheetParam );
				if ( stPar <> nil ) then begin
          if stPar1.direct then
            direct := 1
          else
            direct := 0;
          buf := Format('type = %d, f = %d, m = %d, d = %d ', [docPar1.type_, stPar1.format,
                         stPar1.multiply, direct] );
					kompas.ksMessage( buf );
				end;
			end;

		  kompas.ksMessage( docPar1.fileName );
			kompas.ksMessage( docPar1.comment  );
			kompas.ksMessage( docPar1.author   );

			// сохраним документ
			doc.ksSaveDocument( '' );
		end;
	end;
end;

//-------------------------------------------------------------------------------
// Создать вид
//-------------------------------------------------------------------------------
procedure DrawView;
var
  buf      : string;
  number   : Integer;
  gr, v, p : LongInt;
  par      : ksViewParam;
  vart     : ksLtVariant;
begin
	par := ksViewParam( kompas.GetParamStruct(ko_ViewParam) );
	if ( par <> nil ) then begin
		number := 5;
		par.Init;
		par.x      := 10;
		par.y      := 20;
		par.scale_ := 0.5;
		par.Angle  := 45;
		par.Color  := RGB( 10, 20, 10 );
		par.state  := stACTIVE;
		par.name   := 'user view';

		gr := doc.ksNewGroup( 0 );
		  doc.ksLineSeg( 20, 10, 20, 30, 1 );
			doc.ksLineSeg( 20, 30, 40, 30, 1 );
			doc.ksLineSeg( 40, 30, 40, 10, 1 );
			doc.ksLineSeg( 40, 10, 20, 10, 1 );
		doc.ksEndGroup;

	  // создали вид
		v := doc.ksCreateSheetView( par, number );
		number := doc.ksGetViewNumber( v );
		buf := Format( 'создали вид: ref = %d, number = %d', [v, number] );
		kompas.ksMessage( buf );

		doc.ksAddObjGroup( gr, v );
		kompas.ksMessage( 'добавили вид в группу' );
		kompas.ksMessageBoxResult;

		p := doc.ksLineSeg( 10, 10, 30, 30, 0 );
		doc.ksAddObjGroup( gr, p );

		kompas.ksMessage( 'добавили эл в группу' );
		kompas.ksMessageBoxResult;

		doc.ksRotateObj( gr, 0, 0, -45 );

		// взять параметры вида
		par.Init;
		doc.ksGetObjParam( v, par, ALLPARAM );

		buf := Format( 'x = %4.1f, y = %4.1f, angl = %4.1f, name = %s, st = %d', [par.x,
							 par.y, par.Angle, par.name, par.state] );
		kompas.ksMessage( buf );

	  // сделать текущим системный вид( номер 0 )
		doc.ksOpenView( 0 );
		// состояние  вида  : только чтение
		vart := ksLtVariant( kompas.GetParamStruct(ko_LtVariant) );
		if ( vart <> nil ) then begin
			vart.Init;
			vart.intVal := stREADONLY;
			doc.ksSetObjParam( v, vart, VIEW_LAYER_STATE );
		end;
	end;
end;

//-------------------------------------------------------------------------------
// Создать слой
//-------------------------------------------------------------------------------
procedure DrawLayer;
var
  buf       : string;
  n, lay, l : LongInt;
  n1        : Integer;
  par       : ksLayerParam;
  par1      : ksLayerParam;
  vart      : ksLtVariant;
begin
  if ( kompas.ksReadInt('Введите номер слоя', 1, 0, 255, n) <> 0 ) then begin
    // создаем слой, слой становится текущим
    lay := doc.ksLayer( n );
    doc.ksMtr( 20, 15, 0, 1, 1 );
      doc.ksLineSeg( -10, 0,  10,  0,  1 );
      doc.ksLineSeg( 10,  0,  10,  20, 1 );
      doc.ksLineSeg( 10,  20, -10, 20, 1 );
      doc.ksLineSeg( -10, 20, -10, 0,  1 );
    doc.ksDeleteMtr;

    // подсветить слой
    doc.ksLightObj( lay, 1 );

    // получить номер слоя по указателю и указатель по номеру
    n1 := doc.ksGetLayerNumber( lay );
    l := doc.ksGetLayerReference( n1 );

    buf := Format( 'n = %d, n1 = %d, layer = %d, l = %d', [n, n1, lay, l] );
    kompas.ksMessage( buf );

    //установить параметры слоя и считать их обратно
    par  := ksLayerParam( kompas.GetParamStruct(ko_LayerParam) );
    par1 := ksLayerParam( kompas.GetParamStruct(ko_LayerParam) );
    if ( (par <> nil) And (par1 <> nil) ) then begin
      par.Init;
      par1.Init;
      par.Color := RGB( 0, 255, 0 );
      par.state := stACTIVE;
      par.name  := 'зеленый';
      doc.ksLayer( 0 );

      if ( doc.ksSetObjParam(l, par, ALLPARAM) = 0 ) then
        kompas.ksMessageBoxResult
      else begin
        doc.ksGetObjParam( l, par1, ALLPARAM );
        buf := Format( 'col = %d, col1 = %d, name = %s, name1 = %s', [par.Color,
                   par1.Color, par.name, par1.name] );
        kompas.ksMessage( buf );
      end;
      doc.ksLightObj( lay, 0 );

      // изменить состояние слоя
      vart := ksLtVariant( kompas.GetParamStruct(ko_LtVariant) );
      if ( vart <> nil ) then begin
        vart.Init;
        vart.intVal := stACTIVE;
        doc.ksSetObjParam( l, vart, VIEW_LAYER_STATE );
      end;
    end;
  end;
end;

//-------------------------------------------------------------------------------
// работа с группой
//-------------------------------------------------------------------------------
procedure DrawGroup;
var
  p1, p2, gr1, gr2  : LongInt;
begin
	p1 := doc.ksLineSeg( 10, 10, 20, 10, 0 );
	p2 := doc.ksLineSeg( 10, 10, 10, 20, 0 );

	// создать модельную группу   1
	gr1 := doc.ksNewGroup( 0 );
	doc.ksEndGroup;

	// создать модельную группу   2
	gr2 := doc.ksNewGroup( 0 );
	doc.ksEndGroup;

	doc.ksAddObjGroup( gr1, p1 );
	doc.ksAddObjGroup( gr1, p2 );

	doc.ksAddObjGroup( gr2, p1 );
	doc.ksAddObjGroup( gr2, p2 );

	kompas.ksMessage( 'создали группы' );

	doc.ksMoveObj( gr1, 10, 0 );
  kompas.ksMessage( 'сдвинули группу на 10 ММ' );

  doc.ksRotateObj( gr2, 20, 10, 45 );
  kompas.ksMessage( 'повернули группу на 45 гр' );

  doc.ksRotateObj( gr2, 20, 10, -45 );
  kompas.ksMessage( 'повернули группу на -45 гр' );

  doc.ksMoveObj( gr1, -10, 0 );
  kompas.ksMessage( 'сдвинули группу на -10 ММ' );

  // очистили группу 2 ( объекты исключаются из группы )
  doc.ksClearGroup( gr2, false );
  // удалим  группу 2
  doc.ksDeleteObj( gr2 );

	kompas.ksMessage( 'подсветили gr' );
	doc.ksLightObj( gr1, 1 );

	kompas.ksMessage( 'выключили gr' );
	doc.ksLightObj( gr1, 0 );

	kompas.ksMessage( 'подсветили el' );
	doc.ksLightObj( p1, 1 );
	kompas.ksMessage( 'выключили el' );
	doc.ksLightObj( p1, 0 );

	//удалим  группу 1( объекты удалятся тоже )
	doc.ksDeleteObj( gr1 );
end;

//-------------------------------------------------------------------------------
//  работа с именнованной группой
//-------------------------------------------------------------------------------
procedure WorkNameGroup;
var
  gr, p, c, gr1 : LongInt;
begin
  //рабочая группа сущестует  до конца работы  функции
  gr := doc.ksNewGroup( 0 );
    p := doc.ksLineSeg( 20, 20, 40, 20, 1 );
    doc.ksLineSeg( 40, 20, 40, 40, 1 );
    doc.ksLineSeg( 40, 40, 20, 40, 1 );
    doc.ksLineSeg( 20, 40, 20, 20, 1 );
  doc.ksEndGroup;

  //рабочую группу сохраняем в именной
  //именная группа хранится в документе и
  if ( doc.ksSaveGroup(gr, 'group1') = 0 ) then
    Exit;
  gr1 := doc.ksGetGroup( 'group1' );
  if ( gr1 = 0 ) then
    Exit;

  c := doc.ksCircle( 30, 30, 10, 1 );
  doc.ksAddObjGroup( gr1, c );

  doc.ksLightObj( gr1, 1 );
  kompas.ksMessage( 'добавили объект в именную группу' );
  doc.ksLightObj( gr1, 0 );

  doc.ksExcludeObjGroup( gr1, p );

  doc.ksLightObj( gr1, 1 );
  kompas.ksMessage( 'исключили объект из именной группы' );
  doc.ksLightObj( gr1, 0 );
end;

//-------------------------------------------------------------------------------
// создать отрезок
//--------------------------------------------------------------------------------
procedure DrawLineSeg;
var
  buf : string;
  p   : LongInt;
  t   : Integer;
  par : ksLineSegParam;
begin
  //построить отрезок
  //введем локальную систему ккординат
  doc.ksMtr( 30, 20, 45, 1, 1 );
  p := doc.ksLineSeg( 30, 20, 60, 20, 1 );

  //взять параметры отрезка
  par := ksLineSegParam( kompas.GetParamStruct(ko_LineSegParam) );
	if ( par <> nil ) then begin
	  t := doc.ksGetObjParam( p, par, ALLPARAM );

		buf := Format( 't = %d, x1 = %4.1f, y1 = %4.1f, x2 = %4.1f, y2 = %4.1f, tl = %d', [t,
               par.x1, par.y1, par.x2, par.y2, par.style] );

	  kompas.ksMessage( buf );

		// заменить параметры отрезка
		par.x2    := 30;
		par.y2    := 60;
		par.style := 2;

		if ( doc.ksSetObjParam(p, par, ALLPARAM) <> 0 ) then
			kompas.ksMessage( 'Изменили объект' )
		else
			kompas.ksMessageBoxResult;
	end;
	// отключить локальную систему координат
  doc.ksDeleteMtr;
end;

//-------------------------------------------------------------------------------
// создать дугу
//--------------------------------------------------------------------------------
procedure DrawArc;
var
  buf  : string;
  p    : LongInt;
  t    : Integer;
  par  : ksArcByAngleParam;
  par1 : ksArcByPointParam;
begin
  //построить дугу
  doc.ksMtr( 10, 10, 0, 1, 1 );
  p := doc.ksArcByAngle( 30, 20, 20, 45, 135, 1, 1 );

  //взять параметры дуги  по углам
  par  := ksArcByAngleParam( kompas.GetParamStruct(ko_ArcByAngleParam) );
  par1 := ksArcByPointParam( kompas.GetParamStruct(ko_ArcByPointParam) );
	if ( (par <> nil) And (par1 <> nil) ) then begin
		t := doc.ksGetObjParam( p, par, ALLPARAM );

		buf := Format( 't = %d, xc = %4.1f, yc = %4.1f, rad = %4.1f, \n\n a1 = %4.1f, a2 = %4.1f, napr = %d , tl = %d',
               [t, par.xc, par.yc, par.rad, par.ang1, par.ang2,
							 par.dir, par.style] );
		kompas.ksMessage( buf );

		// заменить параметры дуги по точкам
		par1.xc    := 40;
		par1.yc    := 30;
		par1.rad   := 10;
		par1.dir   := 1;
		par1.style := 2;
		par1.x1    := 50;
		par1.y1    := 30;
		par1.x2    := 40;
		par1.y2    := 20;

		if( doc.ksSetObjParam(p, par1, 1) <> 0 ) then
			kompas.ksMessage( 'Изменили объект' )
		else
			kompas.ksMessageBoxResult;
	end;
  doc.ksDeleteMtr;
end;

//-------------------------------------------------------------------------------
// создать вспомогательную линию
//--------------------------------------------------------------------------------
procedure DrawLine;
var
  buf  : string;
  p    : LongInt;
  t    : Integer;
  par  : ksLineParam;
begin
  doc.ksMtr( 0, 0, 45, 1, 1 );
  //построить вспомогательную линию
  p := doc.ksLine( 30, 20, 0 );

  //взять параметры вспомогательной линии
  par := ksLineParam( kompas.GetParamStruct(ko_LineParam) );
	if ( par <> nil ) then begin
		par.Init;
		t := doc.ksGetObjParam( p, par, ALLPARAM );
		buf := Format( 't = %d, x = %4.1f, y = %4.1f, alf = %4.1f', [t,
			         par.x, par.y, par.angle] );
		kompas.ksMessage( buf );

		// заменить параметры вспомогательной линии
		par.angle := 90;

		if ( doc.ksSetObjParam(p, par, ALLPARAM) <> 0 ) then
	    kompas.ksMessage( 'Изменили объект' )
		else
			kompas.ksMessageBoxResult;
	end;
  doc.ksDeleteMtr;
end;

//-------------------------------------------------------------------------------
// создать окружность
//--------------------------------------------------------------------------------
procedure DrawCircle;
var
  buf  : string;
  p    : LongInt;
  t    : Integer;
  par  : ksCircleParam;
begin
  doc.ksMtr( 0, 0, 0, 2, 2 );
  //построить окружность
  p := doc.ksCircle( 30, 20, 10, 1 );

  //взять параметры олружности
  par := ksCircleParam( kompas.GetParamStruct(ko_CircleParam) );
	if ( par <> nil ) then begin
	  t := doc.ksGetObjParam( p, par, ALLPARAM );
		buf := Format( 't = %d, xc = %4.1f, yc = %4.1f, rad = %4.1f, tl = %d', [t,
               par.xc, par.yc, par.rad, par.style] );
		kompas.ksMessage( buf );

		//заменить параметры окружности
		par.rad   := 20;
		par.style := 2;
		if ( doc.ksSetObjParam(p, par, ALLPARAM) <> 0 ) then
			kompas.ksMessage( 'Изменили объект' )
		else
			kompas.ksMessageBoxResult;
	end;
  doc.ksDeleteMtr;
end;

//-------------------------------------------------------------------------------
// создать точку
//--------------------------------------------------------------------------------
procedure DrawPoint;
var
  buf  : string;
  p    : LongInt;
  t    : Integer;
  par  : ksPointParam;
begin
  // 0-точка, 1-крестик, 2-х-точка, 3-квадрат, 4-треугольник, 5-окружность, 6-звезда,
	// 7-перечеркнутый квадрат
	doc.ksMtr( 10, 10, 0, 1, 1 );
	//построить точку
	p := doc.ksPoint( 30, 40, 0 );
	doc.ksPoint( 40,  40, 1 );
	doc.ksPoint( 50,  40, 2 );
	doc.ksPoint( 60,  40, 3 );
	doc.ksPoint( 70,  40, 4 );
	doc.ksPoint( 80,  40, 5 );
  doc.ksPoint( 90,  40, 6 );
  doc.ksPoint( 100, 40, 7 );

  //взять параметры точки
	par := ksPointParam( kompas.GetParamStruct(ko_PointParam) );
	if ( par <> nil ) then begin
		t := doc.ksGetObjParam( p, par, ALLPARAM );
		buf := Format( 't = %d, x = %4.1f, y = %4.1f, style = %d', [t,
							 par.x, par.y, par.style] );
		kompas.ksMessage( buf );

		//заменить параметры точки
		par.x     := 20;
		par.y     := 30;
		par.style := 7;

		if ( doc.ksSetObjParam(p, par, ALLPARAM) <> 0 ) then
			kompas.ksMessage( 'Изменили объект' )
		else
			kompas.ksMessageBoxResult;
	end;
	doc.ksDeleteMtr;
end;

//-------------------------------------------------------------------------------
// создать Bezier сплайн
//--------------------------------------------------------------------------------
procedure DrawBezier;
type
  double6 = array [0..6] of double;
var
  buf   : string;
  p     : reference;
  t, i  : integer;
  pPar  : ksMathPointParam;
  par   : ksBezierParam;
  arr   : ksDynamicArray;
  count : integer;
  x, y  : double6;

begin
  x[0] := 0; x[1] := 20; x[2] := 50; x[3] := 70; x[4] := 100; x[5] := 50;
  y[0] := 0; y[1] := 20; y[2] := 10; y[3] := 20; y[4] := 0; y[5] := -50;

  //построить Bezier сплайн
  doc.ksBezier( 0, 1 );
    for i := 0 to 4 do
      doc.ksPoint( x[i], y[i], 0 );
  p := doc.ksEndObj;

	//взять параметры Bezier сплайна
  pPar := ksMathPointParam( kompas.GetParamStruct(ko_MathPointParam) );
  par  := ksBezierParam( kompas.GetParamStruct(ko_BezierParam)       );
	if ( (pPar <> nil) And (par <> nil) ) then begin
		par.Init;
		arr := ksDynamicArray( par.GetMathPointArr );
		if ( arr <> nil ) then begin
			t := doc.ksGetObjParam( p, par, ALLPARAM );

			count := arr.ksGetArrayCount;
			buf   := Format( 't = %d, count = %d, close = %d, tl = %d', [t,
							         count, par.closed, par.style] );
			kompas.ksMessage( buf );

			for i := 0 to count - 1 do begin
				arr.ksGetArrayItem( i, pPar );
				buf := Format( 'x[%d] = %4.1f, y[%d] = %4.1f',
									     [i, pPar.x, i, pPar.y] );
				kompas.ksMessage( buf );
			end;

			//	заменить параметры Bezier сплайна
			arr.ksClearArray;
			// подставим свою память
			for i := 0 to 5 do begin
				pPar.x := x[i];
				pPar.y := y[i];
				arr.ksAddArrayItem( -1, pPar );
		  end;

			par.style  := 2;
			par.closed := 1;

			if ( doc.ksSetObjParam(p, par, ALLPARAM) <> 0 ) then
				kompas.ksMessage( 'Изменили объект' )
			else
				kompas.ksMessageBoxResult;
			arr.ksDeleteArray;
		end;
	end;
end;

//-------------------------------------------------------------------------------
// создать штриховку
//--------------------------------------------------------------------------------
procedure DrawHatch;
var
  buf : string;
  p   : reference;
  t   : integer;
  par : ksHatchParam;
begin
	doc.ksMtr( 30, 20, 0, 0.5, 0.5 );

	//построить заштрихованный квадрат
	doc.ksLineSeg( 20, 30, 70, 30, 2 );
	doc.ksLineSeg( 70, 30, 70, 80, 2 );
	doc.ksLineSeg( 70, 80, 20, 80, 2 );
	doc.ksLineSeg( 20, 80, 20, 30, 2 );

  if( doc.ksHatch(0, 45, 2, 0, 0, 0) <> 0 ) then begin
		doc.ksLineSeg( 20, 30, 70, 30, 2 );
		doc.ksLineSeg( 70, 30, 70, 80, 2 );
		doc.ksLineSeg( 70, 80, 20, 80, 2 );
		doc.ksLineSeg( 20, 80, 20, 30, 2 );
    p := doc.ksEndObj;

    //взять параметры штриховки
    par := ksHatchParam( kompas.GetParamStruct(ko_HatchParam) );
		if ( par <> nil ) then begin
			par.Init;
			t := doc.ksGetObjParam( p, par, ALLPARAM );
			buf := Format( 't = %d, tip = %d, angl = %4.1f, shag = %4.1f, \n\n width = %4.1f, x0 = %4.1f, y0 = %4.1f',
						         [t, par.style, par.ang, par.step, par.width, par.x, par.y] );
			kompas.ksMessage( buf );
			doc.ksDeleteMtr;

	    doc.ksMtr( 0, 0, 0, 2, 2 );

			//заменить параметры штриховки
			par.x := 0.8;

			if	( doc.ksSetObjParam(p, par, ALLPARAM) <> 0 ) then
				kompas.ksMessage( 'Изменили объект' )
			else
				kompas.ksMessageBoxResult;
	    doc.ksDeleteMtr;
		end;
  end
  else
    kompas.ksMessageBoxResult;
end;

//-------------------------------------------------------------------------------
//
// ---
procedure DrawText;
var
  buf       : string;
  par       : ksParagraphParam;
  par1      : ksTextParam;
  par2      : ksTextLineParam;
  par3      : ksTextItemParam;
  itemParam : ksTextItemParam;
  itemFont  : ksTextItemFont;
  arr1      : ksDynamicArray;
  arr2      : ksDynamicArray;
  font      : ksTextItemFont;
  p         : reference;

//-------------------------------------------------------------------------------
//
// ---
procedure PrintPar1;
var
  count, j : Integer;
  fontP    : ksTextItemFont;
begin
	buf := Format( 'style = %d', [par2.style] );
	kompas.ksMessage( buf );

	count := arr2.ksGetArrayCount;
	for j := 0 to count - 1 do begin
	  arr2.ksGetArrayItem( j, par3 );
  	fontP := ksTextItemFont( par3.GetItemFont );
		if ( fontP <> nil ) then begin
			buf := Format( 'j = %d, h = %5.1f, s = %s \n fontName = %s', [j, fontP.height, par3.s,
							   fontP.fontName] );
			kompas.ksMessage( buf );
		end;
	end;
	kompas.ksMessageBoxResult;
end;

begin
	par  := ksParagraphParam( kompas.GetParamStruct(ko_ParagraphParam) );
	par1 := ksTextParam( kompas.GetParamStruct(ko_TextParam)           );
	par2 := ksTextLineParam( kompas.GetParamStruct(ko_TextLineParam)   );
	par3 := ksTextItemParam( kompas.GetParamStruct(ko_TextItemParam)   );
	if ( (par <> nil) And (par1 <> nil) And (par2 <> nil) And (par3 <> nil) ) then begin
		par1.Init;
		par2.Init;
		par3.Init;
		par.Init;
		par.x      := 30;
		par.y      := 30;
		par.height := 25;
		par.width  := 20;

		doc.ksParagraph( par );

		// 4 пример задания дроби и нижнего и верхнего отклонений
    itemParam := ksTextItemParam( kompas.GetParamStruct(ko_TextItemParam) );
    if ( itemParam <> nil ) then begin
		  itemParam.Init;

		  itemFont := ksTextItemFont( itemParam.GetItemFont );
			if ( itemFont <> nil ) then begin
				itemFont.Init;
			 	itemFont.SetBitVectorValue( NEW_LINE, true );
				itemParam.s := '111';
				doc.ksTextLine( itemParam );

				itemFont.Init;
			 	itemFont.SetBitVectorValue( NUMERATOR, true );
				itemFont.SetBitVectorValue( ITALIC_ON, true );
				itemParam.s := '55';
				doc.ksTextLine( itemParam );

				itemFont.Init;
			 	itemFont.SetBitVectorValue( DENOMINATOR, true );
				itemParam.s := '77';
				doc.ksTextLine( itemParam );

				itemFont.Init;
			 	itemFont.SetBitVectorValue( END_FRACTION, true );
				itemFont.SetBitVectorValue( BOLD_OFF, true );
				itemFont.SetBitVectorValue( ITALIC_OFF, true );
				itemParam.s := '4444';
				doc.ksTextLine( itemParam );
			end;
		end;

		p := doc.ksEndObj;

		// в параметрах текста задействованы два массива неопределенной длины :
		arr1 := ksDynamicArray( par1.GetTextLineArr );   // массив по строкам
		arr2 := ksDynamicArray( par2.GetTextItemArr );   // массив по компонентам строки
		if ( (arr1 <> nil) And (arr2 <> nil) ) then begin
			// возьмем параметры 1 -ой строки ( индекс 0 )
			doc.ksGetObjParam( p, par2, 0 );

			PrintPar1;

			if ( kompas.ksYesNo('Изменять параметры текста ?') <> 0 ) then begin
				// у первой строки отключаем ITALIC и BOLD и меняем цвет
				arr2.ksGetArrayItem( 0, par3 );
			  font := ksTextItemFont( par3.GetItemFont );
				if ( font <> nil ) then begin
					font.SetBitVectorValue( BOLD_OFF, true );
					font.SetBitVectorValue( ITALIC_OFF, true );
					font.color := RGB( 0, 255, 0 );
					arr2.ksSetArrayItem( 0, par3 );
					// заменим у тексиа первую строку
					doc.ksSetObjParam( p, par2, 0 );
					//возьмем параметры 1 -ой строки ( индекс 0 )  для проверки
  				doc.ksGetObjParam( p, par2, 0 );
					PrintPar1;
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
    if ( command = 1 ) then
      WorkDocument             // создать документ
    else begin
      doc := ksDocument2D( kompas.ActiveDocument2D );
      if ( doc <> nil ) then begin
        case command of
					2 : DrawView;       // виды
					3  : DrawLayer;      // слои
					4  : DrawGroup;      // группы
					5  : WorkNameGroup;  // именная группа
					6  : DrawLineSeg;    // отрезки
					7  : DrawArc;        // дуги
					8  : DrawLine;       // линии
					9  : DrawCircle;     // окружности
					10 : DrawPoint;			 // точки
					11 : DrawBezier;     // Bezier-сплайны
					12 : DrawHatch;      // штриховка
					13 : DrawText;			 // текст
        end;

        kompas.ksMessageBoxResult;

        doc := nil;
      end;
    end;
    kompas := nil;
  end;
end;


end.
