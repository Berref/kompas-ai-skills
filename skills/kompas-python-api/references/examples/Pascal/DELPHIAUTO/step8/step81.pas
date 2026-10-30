unit step81;

{$IFDEF CONDITIONALEXPRESSIONS}
{$IF CompilerVersion >= 14 }
  {$WARN SYMBOL_PLATFORM OFF}
{$IFEND}
{$ENDIF}


interface
  function  LIBRARYID: Cardinal; pascal;
  procedure LIBRARYENTRY( command: WORD ); pascal;

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
  attr   : ksAttributeObject;

//------------------------------------------------------------------------------
// LibraryId
//---
function LIBRARYID: Cardinal; pascal;
begin
  Result := 100;
end;

//-------------------------------------------------------------------------------
// создание типа аттрибута
// ---
procedure FuncAttrType();
var
  col      : ksColumnInfoParam;
  type_    : ksAttributeTypeParam;
  arr      : ksDynamicArray;
  nameFile : WideString;
  numbType : double;
begin
  col := ksColumnInfoParam( kompas.GetParamStruct(ko_ColumnInfoParam) );
  type_ := ksAttributeTypeParam( kompas.GetParamStruct(ko_AttributeType) );
  if col <> nil then begin
	  if ( type_ <> nil ) and ( col <> nil ) then begin
		  type_.Init();
		  col.Init();
		  type_.Header := 'double_str_long';  // заголовoк-комментарий типа
		  type_.RowsCount := 1;    		 			  // кол-во строк в таблице
		  type_.FlagVisible := true;          // видимый, невидимый   в таблице
		  type_.Password := '';               // пароль, если не пустая строка  - защищает от несанкционированного изменения типа
      type_.Key1 := 10;
		  type_.Key2 := 20;
		  type_.Key3 := 30;
		  type_.Key4 := 0;

      arr := ksDynamicArray( type_.GetColumns() );
  		if arr <> nil then begin
        // первая колонка  структуры
        col.Header := 'double';        // заголовoк-комментарий столбца
        col.type_ := DOUBLE_ATTR_TYPE; // тип данных в столбце - см.ниже
        col.Key := 0;                  // дополнительный признак, который позволит отличить две переменные с одинаковым типом
        col.Def := '123456789';        // значение по умолчанию
        col.FlagEnum := false;         // флаг включающий режим, когда значение поля атрибута
        arr.ksAddArrayItem( -1, col );

        // вторая колонка структуры
        col.Header := 'str';            // заголовoк-комментарий столбца
        col.type_ := STRING_ATTR_TYPE;  // тип данных в столбце - см.ниже
        col.Key := 0;                   // дополнительный признак, который позволит отличить две переменные с одинаковым типом
        col.Def := 'string';            // значение по умолчанию
        col.FlagEnum := false;          // флаг включающий режим, когда значение поля атрибута
        arr.ksAddArrayItem( -1, col );

        // третья колонка структуры
        col.Header := 'long';            // заголовoк-комментарий столбца
        col.type_ := LINT_ATTR_TYPE;     // тип данных в столбце - см.ниже
        col.Key := 0;                    // дополнительный признак, который позволит отличить две переменные с одинаковым типом
        col.Def := '1000000';            // значение по умолчанию
        col.FlagEnum := false;           // флаг включающий режим, когда значение поля атрибута
        arr.ksAddArrayItem( -1, col );
      end;

      nameFile := '';
      // запросить имя библиотеки
      nameFile := kompas.ksChoiceFile( '*.lat', '', false );
      // создать тип атрибута
      numbType := attr.ksCreateAttrType( type_,      // информация о типе атрибута
                                        nameFile ); // имя библиотеки типов атрибутов
      if numbType > 1 then
        kompas.ksMessage( Format('numbType = %f', [numbType]) )
      else
        kompas.ksMessageBoxResult();  // проверяем результат работы нашей функции

      // удалим  массив колонок
      arr.ksDeleteArray();
    end;
  end;
end;

//-------------------------------------------------------------------------------
//
// ---
procedure DelTypeAttr();
var
	numb     : double;
	j        : integer;
	password : WideString;
	// имя библиотеки
	nameFile : WideString;
begin
	nameFile := kompas.ksChoiceFile( '*.lat', '', false );
  j := 1;
  while j > 0 do begin
    j := kompas.ksReadDouble( 'Ввести номер типа атрибута', 1000., 0, 1e12, numb );
		if j > 0 then begin
			password := kompas.ksReadString( 'Ввести пароль типа атрибута', '' );
			if attr.ksDeleteAttrType(numb, nameFile, password) <= 0 then
				kompas.ksMessageBoxResult;  // проверяем результат работы нашей функции
		end;
	end;
end;

procedure ShowColumns( f1: bool; pCol: ksDynamicArray  ); forward;

//-------------------------------------------------------------------------------
//
// ---
procedure ShowCol( iCol: integer; f1: bool; par: ksColumnInfoParam );
var
  pCol : ksDynamicArray;
  s    : string;
begin
  if f1 then
    s := 'структура'
  else
    s := '';

  //выдадим поля колонки не указатели
  kompas.ksMessage( Format( '%s i = %d header = %s type = %d def = %s flagEnum = %d',
                            [s, iCol, par.header, integer(par.type_), par.def, integer(par.flagEnum)] ) );
  if par.type_ = RECORD_ATTR_TYPE then
    begin // структура
		pCol := ksDynamicArray( par.GetColumns() );
		if pCol <> nil then
    begin
			ShowColumns( true, pCol );
			pCol.ksDeleteArray();
    end;
  end;
end;

//-------------------------------------------------------------------------------
//
// ---
procedure ShowColumns( f1: bool; pCol: ksDynamicArray  );
var
  par : ksColumnInfoParam;
  i, n   : integer;
begin
  par := ksColumnInfoParam( kompas.GetParamStruct(ko_ColumnInfoParam) );
	if par <> nil then
    begin
		par.Init();
		n := pCol.ksGetArrayCount;

	  for i := 0 to n - 1 do
		  if pCol.ksGetArrayItem(i, par) = 0 then
			  kompas.ksMessageBoxResult  // проверяем результат работы нашей функции
			else
				ShowCol( i, f1, par )
  end;
end;

//--------------------------------------------------------------------------
// получить тип атрибута
//--------------------------------------------------------------------------
procedure ShowTypeAttr();
var
  numb     : double;
	nameFile : WideString; // имя библиотеки
  type_    : ksAttributeTypeParam;
  pCol     : ksDynamicArray;
begin
	nameFile := kompas.ksChoiceFile( '*.lat', '', false );

	type_ := ksAttributeTypeParam( kompas.GetParamStruct(ko_AttributeType) );
	if type_ <> nil then begin
		type_.Init();
    numb := 1;
		while numb > 0 do begin
			numb := attr.ksChoiceAttrTypes( nameFile );
			if numb > 0 then begin
				if attr.ksGetAttrType(numb, nameFile, type_) = 0 then
					kompas.ksMessageBoxResult  // проверяем результат работы нашей функции
				else
        begin
					kompas.ksMessage( Format( 'key1 = %d key2 =%d key3 = %d key4 =%d',
                            [type_.key1, type_.key2, type_.key3, type_.key4] ) );
					kompas.ksMessage( Format( 'header = %s rowsCount = %d flagVisible = %d password = %s',
                            [type_.header, type_.rowsCount, integer(type_.flagVisible), type_.password] ) );
					pCol := ksDynamicArray( type_.GetColumns() );
					if pCol <> nil then begin
						ShowColumns( false, pCol );
						pCol.ksDeleteArray();
					end;
        end;
      end;
    end;
	end;
end;

//--------------------------------------------------------------------------
// заменить тип атрибута
//--------------------------------------------------------------------------
procedure ChangeType();
var
  numb, numbType : double;
	password : WideString;
	// имя библиотеки
	nameFile   : WideString;
  j, n       : integer;
  type_      : ksAttributeTypeParam;
  arr        : ksDynamicArray;
  par1, parN : ksColumnInfoParam;
begin
	nameFile := kompas.ksChoiceFile( '*.lat', '', false );
	type_ := ksAttributeTypeParam( kompas.GetParamStruct(ko_AttributeType) );
	if type_ <> nil then begin
		type_.Init();
    j := 1;
	  while j > 0 do begin
	    j := kompas.ksReadDouble( 'Ввести номер типа атрибута', 1000., 0, 1e12, numb );
			if j > 0 then begin
				password := kompas.ksReadString( 'Ввести пароль типа атрибута', '' );
				// считаем тип атрибута
				if attr.ksGetAttrType(numb, StringToOleStr(nameFile), type_) = 0 then
					kompas.ksMessageBoxResult()  // проверяем результат работы нашей функции
				else begin
					type_.password := password;
					arr := ksDynamicArray( type_.GetColumns() );
					par1 := ksColumnInfoParam(kompas.GetParamStruct(ko_ColumnInfoParam) );
					parN := ksColumnInfoParam(kompas.GetParamStruct(ko_ColumnInfoParam) );
					if ( arr <> nil ) and ( par1 <> nil ) and ( parN <> nil ) then begin
						par1.Init();
						parN.Init();
						// число колонок
						n := arr.ksGetArrayCount();
						// считаем первую колонку
						arr.ksGetArrayItem( 0, par1 );
						// считаем последнюю колонку
						arr.ksGetArrayItem( n-1, parN );
						// заменим первую колонку
						arr.ksSetArrayItem( 0, parN );
						// заменим последнюю колонку
						arr.ksSetArrayItem( n-1, par1 );

						// заменим  тип атрибута  на новый
						numbType := attr.ksSetAttrType( numb, nameFile, type_, password );
						if numbType > 1 then
							kompas.ksMessage( Format('numbType = %f', [numbType]) )
						else
							kompas.ksMessageBoxResult;  // неудачное завершение - выдадим результат работы нашей функции

						arr.ksDeleteArray();
					end;
        end;
      end;
		end;
  end;
end;


//----------------------------------------------------------------------------
//создадим атрибут типа,полученного из функции FuncTypeAttr
//----------------------------------------------------------------------------
procedure NewAttr();
var
 attrPar : ksAttributeParam;
 usPar   : ksUserParam;
 fVisibl, colKeys, arr : ksDynamicArray;
 item    : ksLtVariant;
 info    : ksRequestInfo;
 x, y, numb  : double;
 j       : integer;
 pObj, pAttr : reference;
 fileName    : WideString;
begin

	attrPar := ksAttributeParam( kompas.GetParamStruct(ko_Attribute) );
	usPar := ksUserParam( kompas.GetParamStruct(ko_UserParam) );
	fVisibl := ksDynamicArray( kompas.GetDynamicArray(23) );
	colKeys := ksDynamicArray( kompas.GetDynamicArray(23) );
	if ( attrPar <> nil ) and ( usPar <> nil ) and ( fVisibl <> nil ) and ( colKeys <> nil ) then begin
		attrPar.Init();
		usPar.Init();
		attrPar.SetValues( usPar );
		attrPar.SetColumnKeys( colKeys );
		attrPar.SetFlagVisible( fVisibl );
		attrPar.Key1 := 1;
		attrPar.Key2 := 10;
		attrPar.Key3 := 100;
		attrPar.Password := '111';

		item := ksLtVariant( kompas.GetParamStruct(ko_LtVariant) );
		arr := ksDynamicArray( kompas.GetDynamicArray(23) );
		if ( item <> nil ) and ( arr <> nil ) then begin
			usPar.SetUserArray( arr );
			item.Init();
			item.DoubleVal := 987654321.0;
			arr.ksAddArrayItem( -1, item );
			item.Init();
			item.StrVal := 'qwerty';
			arr.ksAddArrayItem( -1, item );
			item.Init();
			item.LongVal := 999991;
			arr.ksAddArrayItem( -1, item );

			item.Init();
			item.UCharVal := 1;
			fVisibl.ksAddArrayItem( -1, item );
			fVisibl.ksAddArrayItem( -1, item );
			fVisibl.ksAddArrayItem( -1, item );
		end;

		info := ksRequestInfo( kompas.GetParamStruct(ko_RequestInfo) );
		if info <> nil then begin
			info.Init();
			info.Prompt := 'Укажите объект';
			j := doc.ksCursor( info, x, y, nil );
			if j <> 0 then begin
				pObj := doc.ksFindObj( x, y, 1e6 );
				if doc.ksExistObj(pObj) > 0 then begin
					doc.ksLightObj( pObj, 1 );
					// запросить имя библиотеки
					fileName := kompas.ksChoiceFile( '*.lat', '', false );
				  j := kompas.ksReadDouble( 'Ввести номер типа атрибута', 1000., 0, 1e12, numb );
					if j > 0 then begin
						pAttr := attr.ksCreateAttr( pObj, attrPar, numb, fileName );
		        if pAttr = 0 then
			        kompas.ksMessageBoxResult();  // неудачное завершение - выдадим результат работы нашей функции
				  end;
					doc.ksLightObj( pObj, 0 );
        end;
	    end;
		end;
	end;
end;

//--------------------------------------------------------------------------
// удалить первый атрибут  у данного объекта
//---------------------------------------------------------------------------
procedure DelObjAttr();
var
 info : ksRequestInfo;
 x, y : double;
 j    : integer;
 pObj, pAttr, obj : reference;
 iter : ksIterator;
 password : WideString;
begin
	info := ksRequestInfo( kompas.GetParamStruct(ko_RequestInfo) );
	if info <> nil then begin
		info.Init();
		info.Prompt := 'Укажите объект';
    j := 1;
    while j > 0 do begin
			j := doc.ksCursor( info, x, y, nil );
			if j <> 0 then begin
				pObj := doc.ksFindObj( x, y, 1e6 );
				if doc.ksExistObj(pObj) > 0 then begin
					doc.ksLightObj( pObj, 1 );
	        // создадим итератор для хождения по атрибутам объекта
					iter := ksIterator( kompas.GetIterator() );
					if ( iter <> nil ) and iter.ksCreateAttrIterator(pObj, 0, 0, 0, 0, 0) then begin
		        // встали на первый атрибут
						pAttr := iter.ksMoveAttrIterator( 'F', obj );
						if pAttr > 0 then begin
							password := kompas.ksReadString('Ввести пароль типа атрибута', '');
							if attr.ksDeleteAttr(pObj, pAttr, password) = 0 then
								kompas.ksMessageBoxResult();
            end
						else
							kompas.ksMessage( 'атрибут не найден' );

						doc.ksLightObj( pObj, 0 );
					end;
        end;
      end;
    end;
  end;
end;


//--------------------------------------------------------------------------
// считать атрибут типа double_str_long
//---------------------------------------------------------------------------
procedure ReadObjAttr();
var
  res   : bool;
  usPar : ksUserParam;
  item  : ksLtVariant;
  arr   : ksDynamicArray;
  info  : ksRequestInfo;
  x, y, numb : double;
  j     : integer;
  pObj, pAttr, obj : reference;
  iter  : ksIterator;
  k1, k2, k3, k4 : integer;
begin
	res := false;
	usPar := ksUserParam( kompas.GetParamStruct(ko_UserParam) );
	if usPar <> nil then begin
		usPar.Init();
		item := ksLtVariant( kompas.GetParamStruct(ko_LtVariant) );
		arr := ksDynamicArray( kompas.GetDynamicArray(23) );
		if ( item <> nil ) and ( arr <> nil ) then begin
			usPar.SetUserArray( arr );
			item.Init();
			item.DoubleVal := 987654321.0;
			arr.ksAddArrayItem( -1, item );
			item.Init();
			item.StrVal := 'qwerty';
			arr.ksAddArrayItem( -1, item );
			item.Init();
			item.LongVal := 999991;
			arr.ksAddArrayItem( -1, item );
			res := true;
		end;
	end;

	if res then begin
    info := ksRequestInfo( kompas.GetParamStruct(ko_RequestInfo) );
		if info <> nil then begin
			info.Init();
			info.Prompt := 'Укажите объект';
      j := 1;
      while j > 0 do begin
				j := doc.ksCursor( info, x, y, nil );
				if j <> 0 then begin
					pObj := doc.ksFindObj( x, y, 1e6 );
					if doc.ksExistObj( pObj ) > 0 then begin
						doc.ksLightObj( pObj, 1 );
		        // создадим итератор для хождения по атрибутам объекта
						iter := ksIterator( kompas.GetIterator() );
						if ( iter <> nil ) and iter.ksCreateAttrIterator(pObj, 0, 0, 0, 0, 0) then begin
				      // встали на первый атрибут
							pAttr := iter.ksMoveAttrIterator( 'F', obj );
							if pAttr > 0 then begin
				        kompas.ksMessage( 'тип и ключи атрибута' );
						    attr.ksGetAttrKeysInfo( pAttr, k1, k2, k3, k4, numb );
							  kompas.ksMessage( Format('k1 = %d k2 = %d k3 = %d k4 = %d numb = %f',
                                  [k1, k2, k3, k4, numb] ) );

								kompas.ksMessage( 'строка атрибута' );
								attr.ksGetAttrRow( pAttr, 0, nil, nil, usPar );

								kompas.ksMessage( 'заменим строку атрибута' );
								item := ksLtVariant( kompas.GetParamStruct(ko_LtVariant) );
								arr := ksDynamicArray( usPar.GetUserArray() );
								if ( item <> nil ) and ( arr <> nil ) then begin
									item.Init();
									item.DoubleVal := numb;
									arr.ksSetArrayItem( 0, item );
									item.Init();
									item.StrVal := '1234567\nasdfgh\nzxcvb';
									arr.ksSetArrayItem( 1, item );
									item.Init();
									item.LongVal := 888881;
									arr.ksSetArrayItem( 2, item );
									attr.ksSetAttrRow( pAttr, 0, nil, nil, usPar, '111' );
								end;
							end
							else
								kompas.ksMessage( 'атрибут не найден' );
						end;
						doc.ksLightObj( pObj, 0 );
					end;
				end;
      end;
		end;
	end;
end;

//--------------------------------------------------------------------------
// просмотреть  атрибут
//---------------------------------------------------------------------------
procedure ShowObjAttr();
var
 info : ksRequestInfo;
 x, y : double;
 j    : integer;
 pObj : reference;
begin
	info := ksRequestInfo( kompas.GetParamStruct(ko_RequestInfo) );
	if info <> nil then begin
		info.Init();
		info.Prompt := 'Укажите объект';
		j := 1;
		while j > 0 do begin
			j := doc.ksCursor( info, x, y, nil );
			if j <> 0 then begin
				pObj := doc.ksFindObj( x, y, 1e6 );
				if doc.ksExistObj(pObj) > 0 then begin
					doc.ksLightObj( pObj, 1 );
	        attr.ksChoiceAttr( pObj );
					doc.ksLightObj( pObj, 0 );
				end;
			end;
		end;
	end;
end;

//-------------------------------------------------------------------------------
// // просмотреть библиотеку
// ---
procedure ShowLib();
var
  nameFile : WideString;
  numb     : double;
begin
	// запросить имя библиотеки
	nameFile := kompas.ksChoiceFile( '*.lat', '', false );

  numb := attr.ksChoiceAttrTypes( nameFile );
  if ( numb > 1 ) then
    kompas.ksMessage( Format('numbType = %f', [numb]) );
end;


//-------------------------------------------------------------------------------
// // просмотреть тип
// ---
procedure ShowType();
var
  nameFile, password : WideString;
  numb : double;
  j : integer;
begin
	// запросить имя библиотеки
	nameFile := kompas.ksChoiceFile( '*.lat', '', false );
  j := kompas.ksReadDouble( 'Ввести номер типа атрибута', 1000., 0, 1e12, numb );
	if j > 0 then begin
		password := kompas.ksReadString( 'Ввести пароль типа атрибута', '' );
    attr.ksViewEditAttrType( nameFile, 2, numb, password );
  end;
end;


//---------------------------------------------------------------------------
// пройтись у объекта, по атрибутам  с ключом
// key1=10 и выдать количество  колонок и строк для данного атрибута
//---------------------------------------------------------------------------
procedure WalkFromObjWithAttr();
var
  info : ksRequestInfo;
  j : integer;
  x, y : double;
  pObj, pAttr, obj : reference;
  iter : ksIterator;
begin

	info := ksRequestInfo( kompas.GetParamStruct(ko_RequestInfo) );
	if info <> nil then begin
		info.Init();
		info.Prompt := 'Укажите объект';
		j := 1;
		while j > 0 do begin
			j := doc.ksCursor( info, x, y, nil );
			if j <> 0 then begin
				pObj := doc.ksFindObj( x, y, 1e6 );
				if doc.ksExistObj( pObj ) > 0 then begin
		      // создадим итератор для движения по атрибутам с ключом 10
          iter := ksIterator( kompas.GetIterator() );
					if ( iter <> nil ) and iter.ksCreateAttrIterator(pObj, 0, 0, 0, 0, 0) then begin
						doc.ksLightObj( pObj, 1 );
			      // встали на первый атрибут
						pAttr := iter.ksMoveAttrIterator( 'F', obj );
						if pAttr > 0 then
		          while pAttr > 0 do begin
				        attr.ksViewEditAttr( pAttr, 1, '' );
						    pAttr := iter.ksMoveAttrIterator( 'N', obj );
							end;

						doc.ksLightObj( pObj, 0 );
					end;
				end;
			end;
		end;
	end;
end;


//------------------------------------------------------------------------------
// LibraryEntry
//---
procedure LIBRARYENTRY( command: WORD ); pascal;
begin
  kompas := KompasObject( CreateKompasObject );

  if kompas <> nil then begin
    doc := ksDocument2D( kompas.ActiveDocument2D );
    attr := ksAttributeObject( kompas.GetAttributeObject );
    if ( doc <> nil ) and ( attr <> nil ) then begin
      case command of
        1  : FuncAttrType; // создать тип атрибута
        2  : DelTypeAttr;  // удалить тип атрибута
        3  : ShowTypeAttr; // получить тип атрибута
        4  : ChangeType;   // заменить тип атрибута
        5  : NewAttr;      // создадим атрибут типа,полученного из функции FuncTypeAttr
        6  : DelObjAttr;   // удалить первый атрибут  у данного объекта
        7  : ReadObjAttr;  // считать атрибут типа double_str_long
        8  : ShowObjAttr;  // просмотреть  атрибут
        9  : ShowLib;      // просмотреть библиотеку
        10 : ShowType;     // просмотреть тип
        11 : WalkFromObjWithAttr; // просмотреть атрибут
      end;

      kompas.ksMessageBoxResult;
      doc := nil;
    end;
    kompas := nil;
  end;
end;


end.
