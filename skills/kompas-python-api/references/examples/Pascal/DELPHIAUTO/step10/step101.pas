unit step101;

{$IFDEF CONDITIONALEXPRESSIONS}
{$IF CompilerVersion >= 14 }
  {$WARN SYMBOL_PLATFORM OFF}
{$IFEND}
{$ENDIF}


interface
  procedure LIBRARYENTRY( command: WORD ); Pascal;
  function  LIBRARYID: Cardinal; Pascal;
  function  LIBRARYNAME: PAnsiChar; pascal;
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
  docActive: ksDocument2D;
  doc: ksDocument2D;
  spc: ksSpecification;

const SPC_NAME = 5;     //наименование

//-----------------------------------------------------------------------------------------------
//  создадим объект спецификации для раздела "Детали"
//-----------------------------------------------------------------------------------------------
function EditSpcObjDet( geom: Reference ) : Reference;
var
  spcObj: Reference;
  par: ksUserParam;
  item: ksLtVariant;
  arr: ksDynamicArray;
begin
  spcObj := 0;
  //если редактируем макро объект , то ввойдем в режим редактирования объекта
  if docActive.ksEditMacroMode() <> 0 then
  begin
    //найдем объкт спецификации по геометрии
    spcObj := spc.ksGetSpcObjForGeom( 'graphic.lyt' , //имя библиотеки типов
                                   1,         //   номер типа спецификации
                                   0,         //для макро редактирования
                                   1, 1 );
    //ввойдем в режим редактирования
    if spc.ksSpcObjectEdit( spcObj ) = 0 then
      spcObj := 0;
  end;

  //если объекта нет, ввойдем в режим создания объекта спецификации
  if ( spcObj <> 0 )  or ( spc.ksSpcObjectCreate( 'graphic.lyt', //имя библиотеки типов
                                   1,         //   номер типа спецификации
                                   20,  0,    //номер раздела и подраздела
                                   0,0 ) <> 0 ) then    //тип атрибута
  begin
    par := ksUserParam( kompas.GetParamStruct(ko_UserParam) );
 	  item := ksLtVariant( kompas.GetParamStruct(ko_LtVariant) );
		arr := ksDynamicArray( kompas.GetDynamicArray(LTVARIANT_ARR) );
		if ( par = nil ) or ( item = nil ) or ( arr = nil ) then
    begin
			Result := 0; exit;
    end;
		par.Init();
		par.SetUserArray( arr );
  	item.Init();
		item.strVal := 'Втулка';
		arr.ksAddArrayItem( -1, item );
    //наименование
    spc.ksSpcChangeValue( 5, 1, par, STRING_ATTR_TYPE  );

    //подключим геометрию
    if geom <> 0 then
      spc.ksSpcIncludeReference( geom, 1 );

    spcObj := spc.ksSpcObjectEnd( );
    //если объект спецификации создан дадим возможность пользователю на него посмотреть и
    //отредактировать  функцию нужно запускать вне Cursor и Placement
    if ( spcObj <> 0 ) and ( spc.ksEditWindowSpcObject( spcObj ) <> 0 ) then
    begin
      Result := spcObj;
      exit;
    end;
  end;
  Result := 0;
end;

//----------------------------------------------------------------------------------------------
// отрисовать позиционную линию выноски
// уже проверено , что объект спецификации есть
// Функцию нужно запускать вне Cursor и Placement
//----------------------------------------------------------------------------------------------
procedure DrawPosLeader( spcObj: Reference );
var
  info: ksRequestInfo;
  flag: boolean;
  posLeater: Reference;
  x1, y1: Double;
  j1: Integer;
begin
	info := ksRequestInfo( kompas.GetParamStruct(ko_RequestInfo) );
	info.Init();
  flag := true;
  posLeater := 0;
  while flag do
  begin
    info.commandsString := '!Создать !Подключить ';
    info.prompt := 'Укажите позиционную линию выноски';
    j1 := docActive.ksCursor( info, x1, y1, nil );
    case j1 of
      1 :
      begin //Создать новую линию выноски
        posLeater := docActive.ksCreateViewObject( POSLEADER_OBJ );
        flag := false;
      end;
      2 : //Подключить существующую
      begin
        info.prompt := 'Укажите линию выноски';
        if docActive.ksCursor( info, x1, y1, nil ) <> 0 then
        begin
          posLeater := docActive.ksFindObj( x1, y1, 100 );      // величина стороны окошка-ловушки с центром x,y
          if ( posLeater <> 0 ) and ( docActive.ksGetObjParam( posLeater, nil, 0) = POSLEADER_OBJ ) then
            flag := false
          else
          begin
            posLeater := 0;
            flag := true;
          end;
        end else
          flag := false;
      end;
      -1 :
      begin
        posLeater := docActive.ksFindObj( x1, y1, 100 );      // величина стороны окошка-ловушки с центром x,y
        if ( posLeater <> 0 ) and ( docActive.ksGetObjParam( posLeater, nil, 0) = POSLEADER_OBJ ) then
          flag := false
        else begin
          kompas.ksError( 'Ошибка! Объект не позиционная линия выноски!' );
          posLeater := 0;
          flag := true;
        end;
      end;
    end;
  end;
  //линия выноски есть, подключим ее к объекту спецификации
  if posLeater <> 0 then
  begin
    //ввойдем в режим редактирования объекта спецификации
    if spc.ksSpcObjectEdit( spcObj ) <> 0 then
    begin
      //подключим линию выноски
      spc.ksSpcIncludeReference( posLeater, 1 );
      //закроем объект спецификации
      spc.ksSpcObjectEnd();
    end;
  end;
end;

//------------------------------------------------------------------------------
//создадим  тип атрибута болта
//---
procedure TypeAttrBolt;
var
  attr: ksAttributeObject;
  typeAttr: ksAttributeTypeParam;
  col: ksColumnInfoParam;
  arr: ksDynamicArray;
  nameFile: string;
  numbType: Double;
begin
	attr := ksAttributeObject( kompas.GetAttributeObject() );
	typeAttr := ksAttributeTypeParam( kompas.GetParamStruct(ko_AttributeType) );
	col := ksColumnInfoParam( kompas.GetParamStruct(ko_ColumnInfoParam) );
	if ( typeAttr <> nil ) and ( col <> nil ) and ( attr <> nil ) then
  begin
		typeAttr.Init();
		col.Init();
		typeAttr.header := 'Болт111';    // заголовoк-комментарий типа
		typeAttr.rowsCount := 1;									 // кол-во строк в таблице
		typeAttr.flagVisible := true;             // видимый, невидимый   в таблице
		typeAttr.password := '';         // пароль, если не пустая строка  - защищает от несанкционированного изменения типа
		typeAttr.key1 := 10;
		typeAttr.key2 := 20;
		typeAttr.key3 := 30;
		typeAttr.key4 := 0;
		arr := ksDynamicArray( typeAttr.GetColumns() );
		if arr <> nil then
    begin
    	//  колонка 1 "Имя элем."
			col.header := 'Имя элем.'; // заголовoк-комментарий столбца
			col.type_ := STRING_ATTR_TYPE;       // тип данных в столбце - см.ниже
			col.key := 1;                       // дополнительный признак, который позволит отличить две переменные с одинаковым типом
			col.def := 'Болт';         // значение по умолчанию
			col.flagEnum := false;              // флаг включающий режим, когда значение поля атрибута
			arr.ksAddArrayItem( -1, col );

      //  колонка 2 "Исполнение"
			col.header := 'Исполнение';// заголовoк-комментарий столбца
			col.type_ := UINT_ATTR_TYPE;         // тип данных в столбце - см.ниже
			col.key := 3;                       // дополнительный признак, который позволит отличить две переменные с одинаковым типом
			col.def := '1';            // значение по умолчанию
			col.flagEnum := false;              // флаг включающий режим, когда значение поля атрибута
			arr.ksAddArrayItem( -1, col );

      // колонка 3 "Резьба"
			col.header := 'Резьба';    // заголовoк-комментарий столбца
			col.type_ := STRING_ATTR_TYPE;       // тип данных в столбце - см.ниже
			col.key := 0;                       // дополнительный признак, который позволит отличить две переменные с одинаковым типом
			col.def := 'M';            // значение по умолчанию
			col.flagEnum := false;              // флаг включающий режим, когда значение поля атрибута
			arr.ksAddArrayItem( -1, col );

      // колонка 4 "Диаметр"
			col.header := 'Диаметр';   // заголовoк-комментарий столбца
			col.type_ := UINT_ATTR_TYPE;         // тип данных в столбце - см.ниже
			col.key := 3;                       // дополнительный признак, который позволит отличить две переменные с одинаковым типом
			col.def := '12';           // значение по умолчанию
			col.flagEnum := false;              // флаг включающий режим, когда значение поля атрибута
			arr.ksAddArrayItem( -1, col );

      // колонка 5 "разделитель"
			col.header := '';          // заголовoк-комментарий столбца
			col.type_ := STRING_ATTR_TYPE;       // тип данных в столбце - см.ниже
			col.key := 0;                       // дополнительный признак, который позволит отличить две переменные с одинаковым типом
			col.def := 'x';            // значение по умолчанию
			col.flagEnum := false;              // флаг включающий режим, когда значение поля атрибута
			arr.ksAddArrayItem( -1, col );

      // колонка 6 "Шаг"
			col.header := 'Шаг';       // заголовoк-комментарий столбца
			col.type_ := FLOAT_ATTR_TYPE;        // тип данных в столбце - см.ниже
			col.key := 3;                       // дополнительный признак, который позволит отличить две переменные с одинаковым типом
			col.def := '1.25';         // значение по умолчанию
			col.flagEnum := false;              // флаг включающий режим, когда значение поля атрибута
			arr.ksAddArrayItem( -1, col );

      // колонка 7 "Поле допуска"
			col.header := 'Поле допуска';// заголовoк-комментарий столбца
			col.type_ := STRING_ATTR_TYPE;       // тип данных в столбце - см.ниже
			col.key := 3;                       // дополнительный признак, который позволит отличить две переменные с одинаковым типом
			col.def := '-6g';          // значение по умолчанию
			col.flagEnum := false;              // флаг включающий режим, когда значение поля атрибута
			arr.ksAddArrayItem( -1, col );

      // колонка 8 "разделитель"
			col.header := '';          // заголовoк-комментарий столбца
			col.type_ := STRING_ATTR_TYPE;       // тип данных в столбце - см.ниже
			col.key := 0;                       // дополнительный признак, который позволит отличить две переменные с одинаковым типом
			col.def := 'x';            // значение по умолчанию
			col.flagEnum := false;              // флаг включающий режим, когда значение поля атрибута
			arr.ksAddArrayItem( -1, col );

			// колонка 9 "Длина"
			col.header := 'Длина';     // заголовoк-комментарий столбца
			col.type_ := UINT_ATTR_TYPE;         // тип данных в столбце - см.ниже
			col.key := 3;                       // дополнительный признак, который позволит отличить две переменные с одинаковым типом
			col.def := '60';           // значение по умолчанию
			col.flagEnum := false;              // флаг включающий режим, когда значение поля атрибута
			arr.ksAddArrayItem( -1, col );

			// колонка 10 "Кл. прочности"
			col.header := 'Кл. прочности';// заголовoк-комментарий столбца
			col.type_ := STRING_ATTR_TYPE;       // тип данных в столбце - см.ниже
			col.key := 0;                       // дополнительный признак, который позволит отличить две переменные с одинаковым типом
			col.def := '58';           // значение по умолчанию
			col.flagEnum := false;              // флаг включающий режим, когда значение поля атрибута
			arr.ksAddArrayItem( -1, col );

			// колонка 11 "Материал"
			col.header := 'Материал';  // заголовoк-комментарий столбца
			col.type_ := STRING_ATTR_TYPE;       // тип данных в столбце - см.ниже
			col.key := 0;                       // дополнительный признак, который позволит отличить две переменные с одинаковым типом
			col.def := '.35Х';         // значение по умолчанию
			col.flagEnum := false;              // флаг включающий режим, когда значение поля атрибута
			arr.ksAddArrayItem( -1, col );

			// колонка 12 "Покрытие"
			col.header := 'Покрытие';  // заголовoк-комментарий столбца
			col.type_ := STRING_ATTR_TYPE;       // тип данных в столбце - см.ниже
			col.key := 0;                       // дополнительный признак, который позволит отличить две переменные с одинаковым типом
			col.def := '.16';          // значение по умолчанию
			col.flagEnum := false;              // флаг включающий режим, когда значение поля атрибута
			arr.ksAddArrayItem( -1, col );

			// колонка 13 "ГОСТ"
			col.header := 'ГОСТ';      // заголовoк-комментарий столбца
			col.type_ := STRING_ATTR_TYPE;       // тип данных в столбце - см.ниже
			col.key := 0;                       // дополнительный признак, который позволит отличить две переменные с одинаковым типом
			col.def := 'ГОСТ';         // значение по умолчанию
			col.flagEnum := false;              // флаг включающий режим, когда значение поля атрибута
			arr.ksAddArrayItem( -1, col );

			// колонка 14 "Номер"
			col.header := 'Номер';     // заголовoк-комментарий столбца
			col.type_ := UINT_ATTR_TYPE;         // тип данных в столбце - см.ниже
			col.key := 2;                       // дополнительный признак, который позволит отличить две переменные с одинаковым типом
			col.def := '7808';         // значение по умолчанию
			col.flagEnum := false;              // флаг включающий режим, когда значение поля атрибута
			arr.ksAddArrayItem( -1, col );

			// колонка 15 "разделитель"
			col.header := '';          // заголовoк-комментарий столбца
			col.type_ := STRING_ATTR_TYPE;       // тип данных в столбце - см.ниже
			col.key := 0;                       // дополнительный признак, который позволит отличить две переменные с одинаковым типом
			col.def := '-';            // значение по умолчанию
			col.flagEnum := false;              // флаг включающий режим, когда значение поля атрибута
			arr.ksAddArrayItem( -1, col );

			// колонка 16 "Год"
			col.header := 'Год';       // заголовoк-комментарий столбца
			col.type_ := STRING_ATTR_TYPE;       // тип данных в столбце - см.ниже
			col.key := 0;                       // дополнительный признак, который позволит отличить две переменные с одинаковым типом
			col.def := '70';           // значение по умолчанию
			col.flagEnum := false;              // флаг включающий режим, когда значение поля атрибута
			arr.ksAddArrayItem( -1, col );
    end;
		//запросить имя библиотеки
		nameFile := kompas.ksChoiceFile( '*.lat', '', false );
		if nameFile <> '' then
    begin
			//создать тип атрибута
			numbType := attr.ksCreateAttrType( typeAttr,       // информация о типе атрибута
			  																	nameFile ); // имя библиотеки типов атрибутов
			if numbType > 1 then
				kompas.ksMessage( Format( 'numbType = %f', [ numbType ] ) )
			else
				kompas.ksMessageBoxResult(); // проверяем результат работы нашей функции
		end;
		arr.ksDeleteArray(); //удалим  массив колонок
	end;
end;

//------------------------------------------------------------------------------
//создать объект спецификации деталь
//---
procedure CreateDet;
var
  gr, spcObj: Reference;
begin
  //создать модельную группу   1
  gr := docActive.ksNewGroup(0);
    docActive.ksLineSeg ( 20, 30, 70, 30, 2 );
    docActive.ksLineSeg ( 70, 30, 70, 80, 2 );
    docActive.ksLineSeg ( 70, 80, 20, 80, 2 );
    docActive.ksLineSeg ( 20, 80, 20, 30, 2 );
  docActive.ksEndGroup();
  //создать  объект спецификации
  spc := ksSpecification(docActive.GetSpecification);
  if spc = nil then  exit;

  spcObj := EditSpcObjDet( gr );
  if spcObj <> 0 then
    DrawPosLeader( spcObj );
end;

//------------------------------------------------------------------------------
//создать стандартный объект
//---
procedure CreateStandart;
var
  spcObj: Reference;
  par: ksUserParam;
  item: ksLtVariant;
  arr: ksDynamicArray;
  uBuf, resultat: Integer;
begin
  spc := ksSpecification(docActive.GetSpecification);
  if spc = nil then  exit;

  if docActive.ksEditMacroMode() <> 0 then
  begin
    //найдем объкт спецификации по геометрии
    spcObj := spc.ksGetSpcObjForGeom( 'graphic.lyt' , //имя библиотеки типов
                                   1,         //   номер типа спецификации
                                   0,         //для макро редактирования
                                   1, 1 );
    //ввойдем в режим редактирования
    if spc.ksSpcObjectEdit( spcObj ) = 0 then
      exit;
  end;

  resultat := spc.ksSpcObjectCreate( 'graphic.lyt' , //имя библиотеки типов
                                   1,         //   номер типа спецификации
                                   25,  0,    //номер раздела и подраздела определены в стиле спецификации
                                   313277777065.0 , 0 );
  if resultat <> 0 then //тип атрибута определен в библиотеке типов атрибутов spc.lat
  begin
    par := ksUserParam( kompas.GetParamStruct(ko_UserParam) );
 	  item := ksLtVariant( kompas.GetParamStruct(ko_LtVariant) );
		arr := ksDynamicArray( kompas.GetDynamicArray(LTVARIANT_ARR) );
		if ( par = nil ) or ( item = nil ) or ( arr = nil ) then
			exit;
		par.Init();
		par.SetUserArray( arr );
  	item.Init();
		item.strVal := 'Болт222';
		arr.ksAddArrayItem( -1, item );

    spc.ksSpcChangeValue( SPC_NAME , 1, par, STRING_ATTR_TYPE  );
    //исполнение
    uBuf := 2;
    spc.ksSpcVisible( SPC_NAME, 2, 1 );
    arr.ksClearArray();
    item.Init();
    item.intVal := uBuf;
    arr.ksAddArrayItem( -1, item );
    spc.ksSpcChangeValue( SPC_NAME , 2, par, UINT_ATTR_TYPE  );

    //изменим диаметр
  	arr.ksClearArray();
   	item.Init();
	 	item.doubleVal := 40;
	  arr.ksAddArrayItem( -1, item );
    spc.ksSpcChangeValue( SPC_NAME , 4, par, DOUBLE_ATTR_TYPE  );

    //отследим мелкий шаг
    spc.ksSpcVisible( SPC_NAME, 5, 1 );
    spc.ksSpcVisible( SPC_NAME, 6, 1 );   //шаг
    arr.ksClearArray();
    item.Init();
    item.floatVal := 1;
    arr.ksAddArrayItem( -1, item );
    spc.ksSpcChangeValue( SPC_NAME , 6, par, FLOAT_ATTR_TYPE  );

    // выключим поле допуска
    spc.ksSpcVisible( SPC_NAME, 7, 0 );

    //изменим длину
 	  arr.ksClearArray();
	  item.Init();
	  item.intVal := 55;
	  arr.ksAddArrayItem( -1, item );
	  spc.ksSpcChangeValue( SPC_NAME , 9, par, UINT_ATTR_TYPE );

    // выключим класс прочности
    spc.ksSpcVisible( SPC_NAME, 10, 0 );

    // выключим материал
    spc.ksSpcVisible( SPC_NAME, 11, 0 );

    // выключим покрытие
    spc.ksSpcVisible( SPC_NAME, 12, 0 );

    //изменим ГОСТ
 	  arr.ksClearArray();
	  item.Init();
	  item.floatVal := 7808;
	  arr.ksAddArrayItem( -1, item );
	  spc.ksSpcChangeValue( SPC_NAME , 14, par, UINT_ATTR_TYPE );

    //подключим геометрию
//    if geom <> 0 then
  //    spc.ksSpcIncludeReference( geom, 1 );

    spcObj := spc.ksSpcObjectEnd( );
    //если объект спецификации создан дадим возможность пользователю на него посмотреть и
    //отредактировать.  Функцию нужно запускать вне Cursor и Placement
    if ( spcObj <> 0  ) and ( spc.ksEditWindowSpcObject( spcObj ) <> 0 ) then
      DrawPosLeader( spcObj );
  end;
end;

//------------------------------------------------------------------------------
//kонвертировать спецификацию во фрагмент
//---
procedure DecomposeSpc;
var
  spec: ksSpcDocument;
  pDoc, group: Reference;
  pageCount: Integer;
  spcGabarit: ksRectParam;
  docPar: ksDocumentParam;
  i, column: Integer;
  mathBop: ksMathPointParam;
  mathTop: ksMathPointParam;
  x, y, row: Double;
begin
  doc  := ksDocument2D(kompas.Document2D);
	spec := ksSpcDocument( kompas.SpcActiveDocument() );
  if ( doc <> nil ) and ( spec <> nil ) then
  begin
		//берем текущий документ спецификацию
		pDoc := spec.reference;
		if pDoc = 0 then	exit;

    //найдем количество листов спецификации
    pageCount := spec.ksGetSpcDocumentPagesCount();
    //найдем габариры одного листа спецификации
	  spcGabarit := ksRectParam( kompas.GetParamStruct(ko_RectParam) );
		if spcGabarit = nil then exit;

    doc.ksGetObjGabaritRect( pDoc, spcGabarit );

    //создадим фрагмент
	  docPar := ksDocumentParam( kompas.GetParamStruct(ko_DocumentParam) );
		if docPar = nil then exit;

		docPar.Init();
    docPar.regime := 0;
    docPar.type_ := 3;
    doc.ksCreateDocument ( docPar );
    for i := 0 to pageCount - 1 do
    begin
      //получили временную группу i-го листа спецификации
      group := doc.ksDecomposeObj( pDoc,        //указатель на объект
                                              0,  //уровень разбиения 0- отрезки,дуги,тексты,точки:1-отрезки,тексты,точки; 2-отрезки, дуги, тексты
                                              0.4, //стрелка прогиба
                                              i+1);  // 0 - разбиение объекта в СК вида 1- в СК листа
      if group <> 0 then
      begin
        column := i mod 3;
				mathBop := ksMathPointParam( spcGabarit.GetpBot() );
				mathTop := ksMathPointParam( spcGabarit.GetpTop() );
				if ( mathBop = nil ) and ( mathTop = nil ) then
					exit;
        x := ( mathTop.X - mathBop.X + 5)*column;
        row := i div 3;
        y := ( mathTop.Y - mathBop.Y + 5)*row;
        //сдвинули группу
        doc.ksMoveObj( group, x, -y );
        //поставили в модель
        doc.ksStoreTmpGroup( group );  //указатель группы
        doc.ksClearGroup( group, true );
        doc.ksDeleteObj( group );
      end;
    end;
    kompas.ksMessage( Format( 'Декомпозировано %d листов СП', [ pageCount ] ) );
  end else
    kompas.ksError( 'Спецификация должна быть текущей' );
end;

//------------------------------------------------------------------------------
//просмотреть спецификацию
//---
procedure ShowSpc;
var
  spec: ksSpcDocument;
  iter: ksIterator;
  obj, columnType, ispoln, blok: LongInt;
  count, i, colNumb: Integer;
  spcColPar: ksSpcColumnParam;
  buf: string;
begin
  spec := ksSpcDocument( kompas.SpcActiveDocument() );
	if ( spec <> nil ) and ( spec.Reference <> 0 ) then
  begin
    spc := ksSpecification(spec.GetSpecification);
    if spc = nil then  exit;

		iter := ksIterator( kompas.GetIterator() );
		iter.ksCreateSpcIterator( '', 0, 0 );
		if iter.Reference <> 0 then
    begin
			obj := iter.ksMoveIterator( 'F' );
      while spec.ksExistObj(obj) <> 0 do
      begin
        //узнаем количество колонок у базового объекта спецификации
        count := spc.ksGetSpcTableColumn( '', 0, 0 );
        kompas.ksMessage( Format( 'Кол-во колонок = %d', [ count ] ) );

        // пройдем по всем колонкам
        for i := 1 to count do
        begin
          //для текущего номера определим тип колонки, номер исполнения и блок
          spcColPar := ksSpcColumnParam( kompas.GetParamStruct(ko_SpcColumnParam) );
          if spc.ksGetSpcColumnType( obj,          //объект спецификации
                                i,      // номер колонки, начиная с 1
                                spcColPar ) <> 0 then
          begin
            //возьмем текст
            columnType := spcColPar.columnType;
            ispoln := spcColPar.ispoln;
            blok := spcColPar.block;
            buf := spc.ksGetSpcObjectColumnText( obj, columnType, ispoln, blok );
            kompas.ksMessage( buf );
            //по типу колонки, номеру исполнения и блоку определим номер колонки
            colNumb := spc.ksGetSpcColumnNumb(  obj,         //объект спецификации
              spcColPar.columnType, spcColPar.ispoln, spcColPar.block );
            kompas.ksMessage( Format( 'i = %d colNumb =%d', [ i, colNumb ] ) );
          end;
        end;
        obj := iter.ksMoveIterator( 'N' );
      end;
//      } while ( obj = iter.ksMoveIterator( CString("N") ) );
    end;
  end	else
    kompas.ksError( 'Спецификация должна быть текущей' );
end;


//------------------------------------------------------------------------------
// LibraryName
//---
function LIBRARYNAME: PAnsiChar; pascal;
begin
  Result := 'Работа с объектами спецификации';
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
//    doc := ksDocument2D(kompas.Document2D);
//    spc := ksSpcDocument(doc.GetSpecification);

//    if (doc = nil ) or ( spc = nil ) then  exit;

    if ( command = 2 ) or ( command = 3 ) then
    begin
      docActive := ksDocument2D(kompas.ActiveDocument2D);
      if ( docActive <> nil ) then
      begin
        case command of
          2  : CreateDet;      //создать объект спецификации деталь
          3  : CreateStandart; //создать стандартный объект
        end;
      end else
        kompas.ksError( 'Документ должен быть текущим' );
    end
    else begin
      case command of
        1  : TypeAttrBolt;   //создадим  тип атрибута болта
        4  : DecomposeSpc;   //kонвертировать спецификацию во фрагмент
        5  : ShowSpc;        //просмотреть спецификацию
      end;
    end;

    doc := nil;
    kompas := nil;
    docActive := nil;
  end;
end;

end.
