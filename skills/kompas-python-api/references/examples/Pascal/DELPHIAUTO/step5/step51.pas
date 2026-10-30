unit step51;

{$IFDEF CONDITIONALEXPRESSIONS}
{$IF CompilerVersion >= 14 }
  {$WARN SYMBOL_PLATFORM OFF}
{$IFEND}
{$ENDIF}


interface
  procedure LIBRARYENTRY( command: WORD  ); Pascal;
  function  LIBRARYID : Cardinal; Pascal;
  function  LIBRARYNAME : PAnsiChar; Pascal;
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
  kompas: KompasObject;
  doc: ksDocument2D;

//------------------------------------------------------------------------------
//трансформация объекта по матрице
//---
procedure DrawTransform;
var
  ref: Reference;
begin
  //трансформация  рабочей группы
	doc.ksMtr( -30, -30, 0, 1, 1 );
  ref := doc.ksNewGroup(0);
  doc.ksLineSeg( 30, 30, 60, 30, 1);
  doc.ksLineSeg( 60, 30, 60, 60, 1);
  doc.ksLineSeg( 60, 60, 30, 60, 1);
  doc.ksLineSeg( 30, 60, 30, 30, 1);
  doc.ksHatch( 0, 45, 2, 0, 0, 0 );
    doc.ksLineSeg( 30, 30, 60, 30, 1);
    doc.ksLineSeg( 60, 30, 60, 60, 1);
    doc.ksLineSeg( 60, 60, 30, 60, 1);
    doc.ksLineSeg( 30, 60, 30, 30, 1);
  doc.ksEndObj();
  doc.ksEndGroup();
  doc.ksDeleteMtr();

	kompas.ksMessage('создали матрицу 20, 20, 45, 2');

  doc.ksMtr(20, 20, 45, 2, 2 );
  doc.ksTransformObj( ref );
  doc.ksDeleteMtr();

  kompas.ksMessageBoxResult();
  kompas.ksMessage('вернем обратно');

  doc.ksMtr(-20, -20, 0, 1, 1 );
  doc.ksTransformObj( ref );
  doc.ksDeleteMtr();

  doc.ksMtr(0, 0, 0, 0.5, 0.5 );
  doc.ksTransformObj( ref );
  doc.ksDeleteMtr();

  doc.ksMtr(0, 0, -45, 1, 1 );
  doc.ksTransformObj( ref );
  doc.ksDeleteMtr();

  kompas.ksMessageBoxResult();
end;

//------------------------------------------------------------------------------
//копирование объекта
//---
procedure DrawCopy;
var
  par: ksViewParam;
  number: Longint;
  v: Reference;
begin
  par := ksViewParam( kompas.GetParamStruct( ko_ViewParam ) );
  if par <> nil then
  begin
	  par.Init();
    par.x := 20;
	  par.y := 60;
	  par.scale_ :=  1;
		par.state := stACTIVE;
		par.name := 'user view';

    number := 5;
    //создали вид
    v := doc.ksCreateSheetView( par, number);
    //создали слой
    doc.ksLayer( 5 );

		doc.ksLineSeg( 20, 10, 20, 30, 1 );
    doc.ksLineSeg( 20, 30, 40, 30, 1 );
    doc.ksLineSeg( 40, 30, 40, 10, 1 );
    doc.ksLineSeg( 40, 10, 20, 10, 1 );

    //копируем вид ( для вида точки задаются в листовых координатах )
    doc.ksCopyObj( v, 20, 60, 40, 80, 1, 0  );
	end;
end;

//------------------------------------------------------------------------------
//симметрия объекта
//---
procedure DrawSymmetry;
var
  grp: Reference;
begin
  grp := doc.ksNewGroup( 0 );
    doc.ksLineSeg( 20, 10, 20, 30, 1 );
    doc.ksLineSeg( 20, 30, 40, 30, 1 );
    doc.ksLineSeg( 40, 30, 40, 10, 1 );
    doc.ksLineSeg( 40, 10, 20, 10, 1 );
  doc.ksEndGroup();

  doc.ksSymmetryObj(grp, 40, 10, 40, 20, '1'  );
end;

//------------------------------------------------------------------------------
//просмотр допуска формы
//---
procedure EditTolerance;
var
  pObj: Reference;
  info: ksRequestInfo;
  x: double;
  y: double;
  tipe: integer;
  numb: Longint;
  par: ksToleranceParam;
  j: integer;
  par1: ksTextLineParam;
  arrpTextItem: ksDynamicArray;
  item: ksTextItemParam;
  count: integer;
  textItemFont: ksTextItemFont;
begin
 	info := ksRequestInfo( kompas.GetParamStruct(ko_RequestInfo) );
	if info = nil then
		exit;
  info.Prompt := 'Укажите допуск формы';
  j := doc.ksCursor( info, x ,y, nil );
  if j <> 0 then
  begin
    pObj := doc.ksFindObj( x, y, 1000000. );
    if doc.ksExistObj( pObj ) <> 0 then
    begin
      //узнаем тип объекта
      tipe := doc.ksGetObjParam( pObj,nil,0);   //указатель на графический объект
      if tipe = TOLERANCE_OBJ then
      begin
        //открыть допуск формы для редактирования
        doc.ksOpenTolerance( pObj );

        par := ksToleranceParam( kompas.GetParamStruct(ko_ToleranceParam) );
        //параметры допуска формы
        doc.ksGetObjParam(  pObj,   //указатель на графический объект
                    par,  //указатель на структуру параметров
                    ALLPARAM ); //тип считывания параметров

        if par.type_ <> 0 then
          kompas.ksMessage( Format( 'базовая точка=%d   стиль=%d   расположение-%s   x=%5.1f   y=%5.1f  ',
                          [ par.TBase, par.Style, 'вертикальное', par.X, par.Y ] ) )
        else
          kompas.ksMessage( Format( 'базовая точка=%d   стиль=%d   расположение-%s   x=%5.1f   y=%5.1f  ',
                          [ par.TBase, par.Style, 'горизонтальное', par.X, par.Y ] ) );

        par1 := ksTextLineParam( kompas.GetParamStruct(ko_TextLineParam) );

				if par1 = nil then
					exit;

				par1.Init();

        //в цикле будем брать все существующие ячейки
        while doc.ksGetToleranceColumnText( numb, par1 ) <> 0 do
        begin
          kompas.ksMessage( Format( 'numb =%d   style=%d', [ numb, par1.Style ] ) );

  				arrpTextItem := ksDynamicArray( par1.GetTextItemArr() );
					item := ksTextItemParam( kompas.GetParamStruct(ko_TextItemParam) );

					if ( item = nil ) or ( arrpTextItem = nil ) then
  					exit;

					item.Init();

          count := arrpTextItem.ksGetArrayCount();
					for j := 0 to count - 1 do
          begin
            arrpTextItem.ksGetArrayItem( j, item );
  					textItemFont := ksTextItemFont( item.GetItemFont() );
            if bool(item.type_) then
              kompas.ksMessage( Format( 'компонента=%d   h=%5.1f   s=%s   fontName=%s   битвектор =%d ', [ j, textItemFont.Height,
    						         item.S, textItemFont.FontName, textItemFont.BitVector ] ) )
            else
              kompas.ksMessage( Format( 'компонента=%d тип = %d номер спецзнака=%d ', [ j, item.Type_, item.ISNumb ] ) );
						item.s := 'Допуск формы';
          end;
					arrpTextItem.ksClearArray();
					arrpTextItem.ksAddArrayItem( -1, item );
					doc.ksSetToleranceColumnText( numb, par1 );
          arrpTextItem.ksDeleteArray();  //очистим массив компонент
        end;
        //заменим параметры
				par.X := par.X+10;
				par.Y := par.Y+10;
        doc.ksSetObjParam(  pObj,   //указатель на графический объект
                      par,  //указатель на структуру параметров
                      ALLPARAM ); //тип считывания параметров
        doc.ksEndObj();//закрыли объект "допуск формы"
      end else
        kompas.ksError( 'Это не допуск формы' );
    end else
      kompas.ksError( 'Нет объекта' );
  end;
end;

//------------------------------------------------------------------------------
//просмотр таблицы
//---
procedure EditTable;
var
  pObj: Reference;
  info: ksRequestInfo;
  x: double;
  y: double;
  j: integer;
  type_: integer;
  numb: Longint;
  par: ksTextParam;
  arrpLineText: ksDynamicArray;
  itemLineText: ksTextLineParam;
  count: integer;
  arrpTextItem: ksDynamicArray;
  item: ksTextItemParam;
  textItemFont: ksTextItemFont;
  i: integer;
  count2: integer;
begin
 	info := ksRequestInfo( kompas.GetParamStruct(ko_RequestInfo) );
	if info = nil then
		exit;
  info.Prompt := 'Укажите таблицу';
  // взять таблицу на чертеже
  j := doc.ksCursor( info, x ,y, nil );
  if j <> 0 then
  begin
    pObj := doc.ksFindObj( x, y, 100000 );
    if doc.ksExistObj( pObj ) <> 0 then
    begin
      //узнаем тип объекта
      type_ := doc.ksGetObjParam( pObj, nil, 0 );   //указатель на графический объект
      //проверить полученный объкет  - таблица
      if type_ = TABLE_OBJ then
      begin
        //открыть таблицу для редактирования
        doc.ksOpenTable( pObj );

        par := ksTextParam( kompas.GetParamStruct(ko_TextParam) );

				if par = nil then
					exit;

				par.Init();

        //в цикле будем брать все существующие ячейки
        while (( doc.ksGetTableColumnText( numb, par ))<> 0) do
        begin
          kompas.ksMessage( Format( 'numb =%d ', [ numb ] ) );

  				arrpLineText := ksDynamicArray( par.GetTextLineArr() );
					itemLineText := ksTextLineParam( kompas.GetParamStruct(ko_TextLineParam) );
		  		if itemLineText = nil then
			  		exit;
					itemLineText.Init();

          count := arrpLineText.ksGetArrayCount();
          for i := 0 to count - 1 do
          begin
						arrpLineText.ksGetArrayItem( i, itemLineText );
            kompas.ksMessage( Format( 'i =%d style=%d', [ i, itemLineText.Style ] ) );

    				arrpTextItem := ksDynamicArray( itemLineText.GetTextItemArr() );
	  				item := ksTextItemParam ( kompas.GetParamStruct(ko_TextItemParam) );

			  		if ( item = nil ) or ( arrpTextItem = nil ) then
  			  		exit;
		  			item.Init();

            count2 := arrpTextItem.ksGetArrayCount();
					  for j := 0 to count2 - 1 do
            begin
              arrpTextItem.ksGetArrayItem( j, item );
    					textItemFont := ksTextItemFont( item.GetItemFont() );

							if item.Type_ = 0 then
                kompas.ksMessage( Format( 'компонента=%d   h=%5.1f   s=%s   fontName=%s   битвектор =%d', [ j, textItemFont.Height,
								         item.S, textItemFont.FontName, textItemFont.BitVector ] ) )
 							else
                kompas.ksMessage( Format( 'компонента=%d тип = %d номер спецзнака=%d ', [ j, item.Type_, item.ISNumb ] ) );
            end;
            arrpTextItem.ksDeleteArray();  //очистим массив компонент
          end;
          //очистим массив текстовых строк
          arrpLineText.ksDeleteArray();
        end; // while ((ksGetTableColumnText( &numb, &par ))!=0) {

        //берем ячейку 2
        doc.ksColumnNumber( 2 );
        doc.ksText( 0, 0, 0, 5, 1 ,0,'вторая ячейка' );

        doc.ksDivideTableItem( 3, true, 2 );
        doc.ksColumnNumber( 4 );
        doc.ksText( 0, 0, 0, 5, 1 ,0,'4' );

        doc.ksEndObj();//закрыли объект "таблица"
      end else
        kompas.ksError( 'Это не таблица' );
    end else
      kompas.ksError( 'Нет объекта' );
  end;
end;

//------------------------------------------------------------------------------
//взять тексты граф и редактировать штамп
//---
procedure EditStamp;
var
  stamp: ksStamp;
  numb: integer;
  arr: ksDynamicArray;
  arrpLineText: ksDynamicArray;
  itemLineText: ksTextLineParam;
  arrpTextItem: ksDynamicArray;
  item: ksTextItemParam;
  count: integer;
  count2: integer;
  i: integer;
  j: integer;
  textItemFont: ksTextItemFont;
//  item: ksTextItemParam;
  itemFont: ksTextItemFont;
begin
	stamp := ksStamp( doc.GetStamp() );
	if ( stamp <> nil ) and ( stamp.ksOpenStamp() <> 0 ) then
  begin
    //в цикле будем брать все существующие графы
		arr := ksDynamicArray( stamp.ksGetStampColumnText( numb ) );
		while ( numb <> 0 ) and ( arr <> nil ) do
    begin
      kompas.ksMessage( Format( 'numb =%d', [ numb ] ) );

 		  arrpLineText := ksDynamicArray( kompas.GetDynamicArray(TEXT_LINE_ARR) );
			itemLineText := ksTextLineParam( kompas.GetParamStruct(ko_TextLineParam) );
		  if itemLineText = nil then
			 	exit;
			itemLineText.Init();

      count := arr.ksGetArrayCount(); 
      for i := 0 to count - 1 do
      begin
			  arr.ksGetArrayItem( i, itemLineText );
        kompas.ksMessage( Format( 'i =%d style=%d', [ i, itemLineText.Style ] ) );

				arrpTextItem := ksDynamicArray( itemLineText.GetTextItemArr() );
	  		item := ksTextItemParam( kompas.GetParamStruct(ko_TextItemParam) );

				if ( item = nil ) or ( arrpTextItem = nil ) then
  			  exit;
		  	item.Init();

        count2 := arrpTextItem.ksGetArrayCount();
				for j := 0 to count2 - 1 do
        begin
          arrpTextItem.ksGetArrayItem( j, item );
					textItemFont := ksTextItemFont( item.GetItemFont() );
          kompas.ksMessage( Format( 'компонента=%d   h=%5.1f   s=%s   fontName=%s', [ j, textItemFont.Height, item.S,
						         textItemFont.FontName ] ) );
        end;
        arrpTextItem.ksDeleteArray();  //очистим массив компонент
      end;
      //очистим массив текстовых строк
      arrpLineText.ksDeleteArray();

		  arr.ksDeleteArray();
			arr := ksDynamicArray(stamp.ksGetStampColumnText( numb ));
    end;
    //заменим  графу 2
    doc.ksColumnNumber( 2 );
		item := ksTextItemParam( kompas.GetParamStruct(ko_TextItemParam) );
		if item = nil then
    begin
			stamp.ksCloseStamp();
			exit;
		end;
		item.Init();
		itemFont := ksTextItemFont( item.GetItemFont() );
		if ( item <> nil ) and ( itemFont <> nil ) then
    begin
		 	itemFont.bitVector := NEW_LINE;
			item.S := 'графа 2';
			doc.ksTextLine( item );
		end;
    stamp.ksCloseStamp();
  end else
    kompas.ksError ( 'Штамп не найден' );
end;

//------------------------------------------------------------------------------
//получить текст ТТ
//---
procedure GetTextTT;
var
  pTT: Reference;
  technicalDemandParam: ksTechnicalDemandParam;
  pGab: ksDynamicArray;
  pTextLine: ksDynamicArray;
  i: integer;
  itemLineText: ksTextLineParam;
  count: integer;
  count1: integer;
  count2: integer;
  arrpTextItem: ksDynamicArray;
  item: ksTextItemParam;
  textItemFont: ksTextItemFont;
  i1: integer;
  j: integer;
begin
  //получим указатель на технические трбования
  pTT := doc.ksGetReferenceDocumentPart( 1 );
	technicalDemandParam := ksTechnicalDemandParam( kompas.GetParamStruct(ko_TechnicalDemandParam) );
  if ( pTT <> 0 ) and ( technicalDemandParam <> nil ) then
  begin
  	technicalDemandParam.Init();
    //получим параметры описания ТТ
    doc.ksGetObjParam( pTT, technicalDemandParam, TECHNICAL_DEMAND_PAR );
	  pGab := ksDynamicArray( technicalDemandParam.GetPGab() );
    count := pGab.ksGetArrayCount();
    kompas.ksMessage( Format( 'стиль =%d число страниц  TT =%d', [ technicalDemandParam.Style, count ] ) );

    // создадим массив текстовых строк
	  pTextLine := ksDynamicArray( kompas.GetDynamicArray(TEXT_LINE_ARR) );
    //пройдемся по листам ТТ и получим текст
    for i := 0 to count - 1 do
    begin
      doc.ksGetObjParam( pTT, pTextLine, i );
			itemLineText := ksTextLineParam( kompas.GetParamStruct(ko_TextLineParam) );
      if itemLineText = nil then
				exit;
			itemLineText.Init();

      count1 := pTextLine.ksGetArrayCount();
      for i1 := 0 to count1 - 1 do
      begin
				pTextLine.ksGetArrayItem( i1, itemLineText );
        kompas.ksMessage( Format( 'компонента =%d style=%d', [ i1, itemLineText.Style ] ) );

				arrpTextItem := ksDynamicArray( itemLineText.GetTextItemArr() );
	  		item := ksTextItemParam( kompas.GetParamStruct(ko_TextItemParam) );

				if ( item = nil ) or ( arrpTextItem = nil ) then
  			  exit;
		  	item.Init();

        count2 := arrpTextItem.ksGetArrayCount();
        for j := 0 to count2 - 1 do
        begin
					arrpTextItem.ksGetArrayItem( j, item );
					textItemFont := ksTextItemFont( item.GetItemFont() );
          kompas.ksMessage( Format( 'компонента=%d h=%5.1f s=%s fontName=%s', [ j, textItemFont.Height,
						         item.S, textItemFont.FontName ] ) );
        end;
        arrpTextItem.ksDeleteArray(); //очистим массив компонент
      end;
    end;
    pTextLine.ksDeleteArray(); //очистим массив текстовых строк
  end;
end;

//------------------------------------------------------------------------------
//редактирование TT
//---
procedure ChangeTechnicalDemand;
var
  ref: Longint;
  par: ksTechnicalDemandParam;
  parLine: ksTextLineParam;
  i: integer;
  parItem: ksTextItemParam;
  arr: ksDynamicArray;
  count: integer;
  count1: integer;
  j: integer;
begin
  ref := doc.ksGetReferenceDocumentPart( 1 );
  par := ksTechnicalDemandParam( kompas.GetParamStruct(ko_TechnicalDemandParam) );
	if doc.ksGetObjParam( ref, par, TECHNICAL_DEMAND_PAR ) <> 0 then
  begin
    kompas.ksMessage( Format( 'число строк TT =%d', [ par.StrCount ] ) );

		doc.ksOpenTechnicalDemand( par.GetPGab(), par.Style );

		parLine := ksTextLineParam( kompas.GetParamStruct(ko_TextLineParam) );
		if parLine <> nil then
    begin
  		parLine.Init();
      count := par.StrCount;
	    for i := 0 to count - 1 do
      begin
	      doc.ksGetObjParam( ref, parLine, TT_FIRST_STR+i );
		    parItem := ksTextItemParam( kompas.GetParamStruct(ko_TextItemParam) );
				arr := ksDynamicArray( parLine.GetTextItemArr() );
				if ( parItem <> nil ) and ( arr <> nil ) then
        begin
  				parItem.Init();
          count1 := arr.ksGetArrayCount(); 
					for j := 0 to count1 - 1 do
          begin
	  				arr.ksGetArrayItem( j, parItem );
						parItem.S := parItem.S + '!!!';
						arr.ksSetArrayItem( j, parItem );
						kompas.ksMessage( parItem.S );
					end;
        end;
  		  doc.ksSetObjParam( ref, parLine, TT_FIRST_STR+i );
			end;
		end;
		doc.ksCloseTechnicalDemand();
	end;
end;

//------------------------------------------------------------------------------
//вставка фрагмента
//---
procedure ShowInsertFragment;
var
  libName: WideString;
  buf: string;
  res: Longint;
  frLib: ksFragmentLibrary;
  fr: ksFragment;
  x: double;
  y: double;
  rub: ksPhantom;
  type1: ksType1;
  pDefFrg: Reference;
  par: ksPlacementParam;
  p: Reference;
  j: integer;
  ang: double;
begin
  //выберем  библиотеку фрагментов
	libName := kompas.ksChoiceFile( '*.lfr','Библиотки фрагментов(*.lfr)|*.lfr|Все файлы (*.*)|*.*|', true );
  if libName <> '' then
  begin
    res := 1;
    while res <> 0 do
    begin
      //выбрать фрагмент в библиотеке фрагментов
			frLib := ksFragmentLibrary( kompas.GetFragmentLibrary() );
			fr    := ksFragment( doc.GetFragment() );
			if  ( fr = nil ) or ( frLib = nil ) then
				exit;
			buf := frLib.ksChoiceFragmentFromLib( libName, res );
      if ( buf <> '' ) and ( res <> 0 ) then
      begin
        //подготовим структуры фанома и запросов для Placement
        rub := ksPhantom( kompas.GetParamStruct( ko_Phantom ) );
        type1 := ksType1( rub.GetPhantomParam() );
        if ( rub = nil ) or ( type1 = nil ) then
          exit;

        type1.Init(); rub.Init();

        type1.Scale_ := 1;
        rub.phantom := 1;

        // создадим описание  всавки фрагментов
        pDefFrg := fr.ksFragmentDefinition( buf,       //имя файла фрагмента
                                            'вставка', //имя вставки
                                            1 );       //тип вставки -действителен для внешнего фрагмента 0- взять в документ, 1-внешней ссылкой
        if pDefFrg <> 0 then
        begin
          //во временную группу положим вставку фрагмента, взятую из библиотеки фрагментов
          type1.Gr := doc.ksNewGroup(1) ;
            par := ksPlacementParam( kompas.GetParamStruct( ko_PlacementParam ) );
            if par = nil then
              exit;
            par.Init();
            par.Scale_ := 1;
            p := fr.ksInsertFragment( pDefFrg, // Указатель определения  фрагмента
                                      false,   //тип размещения по слоям 0 - на свои слои 1- в текущий слой
                                      par );   //параметры привязки
          doc.ksEndGroup();
          j := 1;
          while j <> 0 do
          begin
            type1.Angle := 0;
            ang := type1.Angle;
            j := doc.ksPlacement( nil, x, y, ang, rub );
            if j <> 0 then
              doc.ksCopyObj( p,                // указатель на графический объект
                             0,0,              // базовая точка объекта
                             x, y,             // точка куда копировать
                             1, type1.Angle ); // масштаб и угол поворота а градусах
          end;
          //doc.ksDeleteObj( type1.Gr );
        end else
          kompas.ksError ( 'Ошибка создания описания вставки фрагмента' );
      end;
    end;
  end;
end;

//------------------------------------------------------------------------------
//работа с библиотекой фрагментов
//---
procedure EditFragmentLibrary;
var
  libName: WideString;
  buf: WideString;
  info: ksRequestInfo;
  fr: ksFragmentLibrary;
  j: integer;
  typeEdit: integer;
  nameFrg: WideString;
  res: Longint;
begin
  //выберем  библиотеку фрагментов
	libName := kompas.ksChoiceFile( '*.lfr','Библиотки фрагментов(*.lfr)|*.lfr|Все файлы (*.*)|*.*|', true );
  if libName <> '' then
  begin
    info := ksRequestInfo( kompas.GetParamStruct( ko_RequestInfo ) );
		fr   := ksFragmentLibrary( kompas.GetFragmentLibrary() );
		if ( info = nil ) or ( fr = nil ) then
			exit;
		info.Init();

		info.commandsString := '!Новый_фрагмент !Редактировать_фрагмент !Удалить_фрагмент';
    j := 1;
    while j <> -1 do
    begin
      j := doc.ksCommandWindow( info );
      if j = 1 then
      begin // Новый_фрагмент
        buf := kompas.ksReadString( 'Введите имя нового фрагмента', '' );
        if buf <> '' then
        begin
          nameFrg := libName + '|' + buf;
          typeEdit := 2; //запустить на редактирование
        end else
          typeEdit := 0;
      end else
      begin  // Редактировать_фрагмент или Удалить_фрагмент
        //выберем имя файла фрагмента
        buf := fr.ksChoiceFragmentFromLib( libName, res );
        if ( res <> 0 ) and ( buf <> '' ) then
        begin
          nameFrg := buf;
          typeEdit := j; // 2- запустить на редактирование, 3-удалить ;
        end else
          typeEdit := 0;
      end;

      if ( j > 0 ) and ( typeEdit <> 0 ) then
        if ( fr.ksFragmentLibraryOperation( nameFrg, typeEdit ) <> 0 ) and ( typeEdit = 2 ) then
        begin
          fr.ksFragmentLibraryOperation( nameFrg, 4  );
          //редактируем фрагмент из библиотеки
          doc.ksText( 0, 100,     //точка привязки текста
                0,            //угол наклона текста
                5,            //высота текста
                1,            //сужение текста
                0,	          //свойства строки, которые задаются вкл.-выкл.
                'Редактируем фрагмент из библиотеки'      );   //строка символов

          doc.ksLineSeg ( 0, 100, 110, 100, 1 );
          //редактируем фрагмент в интерактивном режиме
          //после выбора в меню "Сервис" команды "Закончить редактирование фрагмента",
          //возвращаемся в библиотеку
          kompas.ksSystemControlStop();
//          kompas.ksSystemControlStart( 'Закончить редактирование фрагмента' );
          fr.ksFragmentLibraryOperation( nameFrg, 0  );
        end;
    end;
  end;
end;

//------------------------------------------------------------------------------
//вставка фрагмента россыпью
//---
procedure ShowInsertFragment1;
var
  frwName: string;
  fr: ksFragment;
  x: double;
  y: double;
  rub: ksPhantom;
  type1: ksType1;
  par: ksPlacementParam;
  j: integer;
  ang: double;
  gr: Reference;
begin
	fr := ksFragment ( doc.GetFragment() );
	if fr = nil then
		exit;
  //выберем  фрагмент
  frwName := kompas.ksChoiceFile( '*.frw','фрагменты(*.frw)|*.frw|Все файлы (*.*)|*.*|', true );
  if frwName <> '' then
  begin
    //подготовим структуры фанома и запросов для Placement
		rub := ksPhantom( kompas.GetParamStruct( ko_Phantom ) );
		if rub = nil then
			exit;

    rub.Init();
		rub.phantom := 1;

		type1 := ksType1( rub.GetPhantomParam() );
		if type1= nil then
			exit;

		type1.Init();
		type1.Scale_ := 1;

		//во временную группу положим вставку фрагмента, взятую из библиотеки фрагментов
    par := ksPlacementParam( kompas.GetParamStruct( ko_PlacementParam ) );
    if par = nil then
      exit;
    par.Init();
    par.Scale_ := 1;

    j := 1;
    while j <> 0 do
    begin
      //если нужно вставить несколько фрагментов, группу лучше порождать новую,
      //так как вместе с геометрией могут придти атрибуты, объекты спецификации, стили,
      //которые связаны с геометрией. При простом копировании группы эта связь будет
      //потеряна.
      type1.Gr := fr.ksReadFragmentToGroup( frwName,        // имя фрагмента
                                             false,          //тип размещения по слоям 0 - на свои слои 1- в текущий слой
                                             par );     //параметры привязки
      gr := fr.ksReadFragmentToGroup( frwName,        // имя фрагмента
                                             false,          //тип размещения по слоям 0 - на свои слои 1- в текущий слой
                                             par );     //параметры привязки
      if ( gr <> 0 ) and ( type1.Gr <> 0 ) then
      begin
  			ang := type1.Angle;
        j := doc.ksPlacement( nil, x, y, ang, rub );
  			if j <> 0 then
        begin
          //сдвигаем группу
          doc.ksMoveObj( gr(*type1.Gr*), x, y );
          //ставим группу в модель
          doc.ksStoreTmpGroup( gr );//type1.Gr );
          doc.ksClearGroup( gr(*type1.Gr*), true );
          doc.ksDeleteObj( gr );//type1.Gr );
        end;
      end else
      begin
        if type1.Gr <> 0 then
          doc.ksDeleteObj( type1.Gr );
        j := 0;
      end;
    end;
  end;
end;

//------------------------------------------------------------------------------
// LibraryName
//---
function LIBRARYNAME: PAnsiChar; pascal;
begin
  Result := 'Pедактирование';
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
  kompas := KompasObject(CreateKompasObject);

  if kompas <> nil then
  begin
    doc := ksDocument2D(kompas.ActiveDocument2D);
      if doc <> nil then
      begin
        case command of
          1  : DrawTransform;         //трансформация объекта по матрице
          2  : DrawCopy;              //копирование объекта
          3  : DrawSymmetry;          //симметрия объекта
          4  : EditTolerance;         //просмотр допуска формы
          5  : EditTable;             //просмотр таблицы
          6  : EditStamp;             //взять тексты граф и редактировать штамп
          7  : GetTextTT;             //получить текст ТТ
          8  : ChangeTechnicalDemand; //редактирование TT
          9  : ShowInsertFragment;    //вставка фрагмента
          10 : EditFragmentLibrary;   //работа с библиотекой фрагментов
          11 : ShowInsertFragment1;   //вставка фрагмента россыпью
        end;
        doc := nil;
      end else
  			kompas.ksError( 'Документ не активизирован или не является листом/фрагментом' );
    kompas := nil;
  end;
end;

end.
