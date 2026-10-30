unit step3D21;

{$IFDEF CONDITIONALEXPRESSIONS}
{$IF CompilerVersion >= 14 }
  {$WARN SYMBOL_PLATFORM OFF}
{$IFEND}
{$ENDIF}

interface
  procedure  LIBRARYENTRY( command: WORD  ); Pascal;
  function   LIBRARYID   : Cardinal;         Pascal;
  function   LIBRARYNAME : PAnsiChar;        Pascal;

implementation
uses
  Windows,
  SysUtils,
  LDefin2D,
  LDefin3D,
  ksConstTLB,
  ksAuto,
{$IFDEF __LIGHT_VERSION__}
  klTLB;
{$ELSE}
  ksTLB;
{$ENDIF}
var
  iKompasObject: KompasObject;
  iDocument3D: ksDocument3D;

//------------------------------------------------------------------------------
// взять/изменить имя компоненты
//-
procedure GetSetPartName;
var
  iPart: ksPart;
begin
  iPart := ksPart(iDocument3D.GetPart( pTop_Part )); // Верхний компонент
  if iPart <> nil then
  begin
		iKompasObject.ksMessage( Format( 'Имя компоненты %s', [iPart.name] ) );
		iPart.name := 'Втулка'; //part.SetName( "Втулка" );
		iPart.Update();
	end;
end;

//------------------------------------------------------------------------------
// фиксирование и установка стандартного объекта
//-
procedure FixAndStandartComponent;
var
  part: ksPart;
  fix: boolean;
  stand: boolean;
begin
	if iDocument3D.IsDetail then
  begin
		iKompasObject.ksError('Текущий документ должен быть сборкой');
		exit;
  end;
  part := ksPart( iDocument3D.GetPart(0) ); // первая деталь в сборке
	if part <> nil then
  begin
		// Получить состояние фиксации компонента - в системе поддерживающей работу со свойствами - fixedComponent
		fix := part.fixedComponent;
		// Получить состояние стандартного компонента - в системе поддерживающей работу со свойствами - standardComponent
    stand := part.standardComponent;
		// Изменить состояние фиксации компонента - в системе поддерживающей работу со свойствами - fixedComponent
    if fix then
    begin
  		iKompasObject.ksMessage( 'Компонент зафиксирован' );
      part.fixedComponent := false;
    end else
    begin
  		iKompasObject.ksMessage( 'Компонент не зафиксирован' );
      part.fixedComponent := true;
    end;
		// Изменить состояние стандартного компонента - в системе поддерживающей работу со свойствами - standardComponent
    if stand then
    begin
	  	iKompasObject.ksMessage( 'Компонент стандартный' );
  		part.standardComponent := false;
    end else
    begin
  		iKompasObject.ksMessage( 'Компонент нестандартный' );
  		part.standardComponent := true;
    end;
	end;
end;


//------------------------------------------------------------------------------
// получить и заменить параметры цвета компоненты
//-
procedure GetSetColorProperty;
var
  part: ksPart;
  colorPr: ksColorParam;
begin
  part := ksPart( iDocument3D.GetPart(pTop_Part) ); // верхний компонент
  if part <> nil then
  begin
		colorPr := ksColorParam( part.ColorParam() );
		if colorPr <> nil then
    begin
			iKompasObject.ksMessage( Format('Номер цвета = %d  Общий цвет = %g   Диффузия = %g   Зеркальность  = %g   Блеск = %g   Прозрачность = %g   Излучение = %g',
				[ colorPr.Color, colorPr.Ambient, colorPr.Diffuse, colorPr.Specularity, colorPr.Shininess, colorPr.Transparency, colorPr.Emission ] ) );
			colorPr.Color := 5421504;
			colorPr.Transparency := 0.5;
			colorPr.Ambient := 0.1;
			colorPr.Diffuse := 0.1;
			part.Update();
			iKompasObject.ksMessage( Format('Номер цвета = %d   Общий цвет = %g   Диффузия = %g   Зеркальность  = %g   Блеск = %g   Прозрачность = %g   Излучение = %g',
				[ colorPr.Color, colorPr.Ambient, colorPr.Diffuse, colorPr.Specularity, colorPr.Shininess, colorPr.Transparency, colorPr.Emission ] ) );
		end;
  end;
end;

//------------------------------------------------------------------------------
// взять и поменять внешние переменные компоненты
//-
procedure GetSetArrayVariable;
var
  part: ksPart;
  varCol: ksVariableCollection;
  variable: ksVariable;
  count: integer;
  i: integer;
  d: double;
begin
	if iDocument3D.IsDetail then
  begin
		iKompasObject.ksError('Текущий документ должен быть сборкой');
		exit;
  end;
  part := ksPart( iDocument3D.GetPart(0) ); // первая деталь в сборке
  if part <> nil then
  begin
		// работа с массивом внешних переменных
		varCol := ksVariableCollection(part.VariableCollection() );
		if varCol <> nil then
    begin
      variable := ksVariable( iKompasObject.GetParamStruct(ko_VariableParam) );
			if variable = nil then
				exit;
      count := varCol.GetCount();
			for i := 0 to count - 1 do
      begin
				variable := ksVariable( varCol.GetByIndex(i) );
				iKompasObject.ksMessage( Format( 'Номер переменной %d   Имя переменной %s   Значение переменной %g   Комментарий %s',
                     [ i, variable.Name, variable.Value, variable.Note ] ) );
				if i = 0 then
        begin
					variable.Note := 'qwerty';
					d := 0;
					iKompasObject.ksReadDouble( 'Введи переменную', 10, 0, 100, d );
					variable.Value := d;
				end;
				variable := nil;
			end;

      count := varCol.GetCount();
			for i := 0 to count - 1 do // просмотр изменненных переменных
      begin
				variable := ksVariable( varCol.GetByIndex(i) );
				iKompasObject.ksMessage( Format( 'Номер переменной %d   Имя переменной %s   Значение переменной %g   Комментарий %s',
                     [ i, variable.Name, variable.Value, variable.Note ] ) );
				variable := nil;
			end;
			part.RebuildModel();  // перестроение модели
		end;
	end;
end;

//------------------------------------------------------------------------------
// получить и изменить место расположения детали в сборке
//-
procedure GetSetPlacmentComponent;
var
  part: ksPart;
  plac: ksPlacement;
  x: double;
  y: double;
  z: double;
begin
	if iDocument3D.IsDetail then
  begin
		iKompasObject.ksError('Текущий документ должен быть сборкой');
		exit;
  end;
  part := ksPart( iDocument3D.GetPart(0) ); // первая деталь в сборке
  if part <> nil then
  begin
		plac := ksPlacement( part.GetPlacement() );
		if plac <> nil then
    begin
			plac.GetOrigin( x, y, z );
			iKompasObject.ksMessage( Format( 'x = %g   y = %g   z = %g', [ x, y, z ] ) );
			plac.SetOrigin( 20, 20, 20 );
			part.UpdatePlacement();
			part.Update();
		end;
	end;
end;

//------------------------------------------------------------------------------
// Получить интерфейс ksEntity объекта создаваемого системой по умолчанию и поменять параметры
//-
procedure GetSetEntity;
var
  part: ksPart;
  planeXOY: ksEntity;
begin
  part := ksPart( iDocument3D.GetPart(pTop_Part) ); // верхний компонент
  if part <> nil then
  begin
		planeXOY := ksEntity( part.GetDefaultEntity(o3d_planeXOY) ); // 1-интерфейс на плоскость XOY
		if planeXOY <> nil then
    begin
			iKompasObject.ksMessage( planeXOY.Name );
			planeXOY.Name :='plane';
			planeXOY.Update();
		end;
	end;
end;

//------------------------------------------------------------------------------
// создание эскиза
//-
procedure CreateSketch;
var
  part: ksPart;
  planeXOY: ksEntity;
  entity: ksEntity;
  sketch: ksSketchDefinition;
  sketchDoc: ksDocument2D;
begin
  part := ksPart( iDocument3D.GetPart(pTop_Part) ); // верхний компонент
	if part <> nil then
  begin
		planeXOY := ksEntity( part.GetDefaultEntity(o3d_planeXOY) ); // 1-интерфейс на плоскость XOY
		entity := ksEntity( part.NewEntity(o3d_sketch) );
		if ( planeXOY <> nil ) and ( entity <> nil ) then
    begin
			sketch := ksSketchDefinition( entity.GetDefinition() );
			if sketch <> nil then
      begin
				sketch.SetPlane( planeXOY );
				entity.Create();
				sketchDoc := ksDocument2D( sketch.BeginEdit() );//GetSketchEditor() );
  				sketchDoc.ksLineSeg( 0, 0, 100, 100, 1 );
				sketch.EndEdit();
			end;
		end;
	end;
end;

//------------------------------------------------------------------------------
// Формирует массив объектов(здесь эскизов) и возвращает его интерфейс ksEntityCollection ( IEntityCollection )
//-
procedure GetArraySketch;
var
  part: ksPart;
  entityCollection: ksEntityCollection;
  currentEntity: ksEntity;
  k: integer;
begin
  part := ksPart( iDocument3D.GetPart(pTop_Part) ); // верхний компонент
  if part <> nil then
  begin
		entityCollection := ksEntityCollection( part.EntityCollection( o3d_sketch ) );
//		currentEntity := ksEntity( nil );//( part.NewEntity(o3d_sketch) );
		if entityCollection <> nil then
    begin
			for k := 0 to entityCollection.GetCount() - 1 do
      begin
				currentEntity := ksEntity( entityCollection.GetByIndex(k) );
				iKompasObject.ksMessage( currentEntity.Name );
				currentEntity := nil;
			end;
		end;
	end;
end;

//------------------------------------------------------------------------------
// Установить и получить параметры пользователя в компоненте
//-
procedure GetSetUserParamComponent;
var
  part: ksPart;
  par: ksUserParam;
  item: ksLtVariant;
  arr: ksDynamicArray;
  par2: ksUserParam;
  item2: ksLtVariant;
  arr2: ksDynamicArray;
  a: double;
  b: double;
  c: integer;
  d: integer;
begin
	if iDocument3D.IsDetail then
  begin
		iKompasObject.ksError('Текущий документ должен быть сборкой');
		exit;
  end;

  part := ksPart( iDocument3D.GetPart(0) ); // первая деталь в сборке
	par := ksUserParam( iKompasObject.GetParamStruct(ko_UserParam) );
  item := ksLtVariant( iKompasObject.GetParamStruct(ko_LtVariant) );
	arr := ksDynamicArray( iKompasObject.GetDynamicArray(LTVARIANT_ARR) );
	if ( par = nil ) or ( item = nil ) or ( arr = nil ) or ( part = nil ) then
		exit;

	par.Init();
	par.SetUserArray( arr );
	item.Init();
	  item.doubleVal := 12.12;
	  arr.ksAddArrayItem( -1, item );
	item.Init();
  	item.DoubleVal := 21.21;
		arr.ksAddArrayItem( -1, item );
  item.Init();
	  item.IntVal := 666;
	  arr.ksAddArrayItem( -1, item );
  item.Init();
	  item.IntVal := 999;
	  arr.ksAddArrayItem( -1, item );

	part.SetUserParam(par); // установка пользовательской структуры
	part.Update();

  // размер пользовательской структуры
	iKompasObject.ksMessage( Format('Размер пользовательской структуры %d', [ part.GetUserParamSize() ] ) );

	par2 := ksUserParam( iKompasObject.GetParamStruct(ko_UserParam) );
  item2 := ksLtVariant( iKompasObject.GetParamStruct(ko_LtVariant) );
	arr2 := ksDynamicArray( iKompasObject.GetDynamicArray(LTVARIANT_ARR) );
	if ( par2 = nil ) or ( item2 = nil ) or ( arr2 = nil ) then
		exit;

	par2.Init();
	par2.SetUserArray( arr2 );
	item2.Init();
	  item2.DoubleVal := 0;
	  arr2.ksAddArrayItem( -1, item2 );
	item2.Init();
  	item2.DoubleVal := 0;
		arr2.ksAddArrayItem( -1, item2 );
  item2.Init();
	  item2.IntVal := 0;
	  arr2.ksAddArrayItem( -1, item2 );
  item2.Init();
	  item2.IntVal := 0;
	  arr2.ksAddArrayItem( -1, item2 );

	part.GetUserParam( par2 ); // берем пользовательскeую структуру

{	struct
		double a, b;
		int c, d;
	 d;   }
  arr2.ksGetArrayItem( 0, item2 );
	a := item2.DoubleVal;
  arr2.ksGetArrayItem( 1, item2 );
	b := item2.DoubleVal;
  arr2.ksGetArrayItem( 2, item2 );
	c := item2.IntVal;
  arr2.ksGetArrayItem( 3, item2 );
	d := item2.IntVal;
  // просмотрим переменные из пользовательского массива
	iKompasObject.ksMessage( Format('Переменные пользовательского масства   a = %g   b = %g   c = %d   d = %d', [ a, b, c, d ] ) );
end;

//------------------------------------------------------------------------------
// создание документа
//-
procedure CreateDocument3D;
begin
	iDocument3D := ksDocument3D( iKompasObject.Document3D() );
  if iDocument3D.Create(false, true) then
  begin
    iDocument3D.author := 'Автор';                // Автор документа
    iDocument3D.comment := 'Пример документа 3D'; // Комментарии к документу
		iDocument3D.fileName := 'c:\example.m3d';    // Имя файла Документа
    iDocument3D.UpdateDocumentParam();             // Обновить параметры Документа
		iDocument3D.Save();                            // Сохранить документ
		iKompasObject.ksMessage( 'Сохраним документ под другим именем' );
    iDocument3D.SaveAs( 'c:\example_1.m3d' );     // сохранить документ под другим именем

		// Автор документа
		iKompasObject.ksMessage ('Автор документа: ' + iDocument3D.author);
		// Комментарий к документу
		iKompasObject.ksMessage( 'Комментарий к документу: ' + iDocument3D.comment );
    // Имя файла
		iKompasObject.ksMessage( 'Имя файла: ' + iDocument3D.fileName );

		iDocument3D.close(); // закроем документ
  end;

end;

//------------------------------------------------------------------------------
//
//-
procedure UseEntityCollection;
var
  part: ksPart;
  count1: Longint;
  count2: Longint;
  count: Longint;
  collect: ksEntityCollection;
  colorPr: ksColorParam;
  ent: ksEntity;
  faceDef: ksFaceDefinition;
  i : integer;
  collect2: ksEntityCollection;
  edgeDef: ksEdgeDefinition;
begin
  part := ksPart( iDocument3D.GetPart(pTop_Part) );       // новый компонент
  if part <> nil then
  begin
    count := 0;
    count1 := 0; // количество плоских поверхностей
    count2 := 0; // количество конических поверхностей
    // массив поверхностей
    collect := ksEntityCollection( part.EntityCollection(o3d_face) );
    if collect <> nil then
    begin
      count := collect.GetCount();
      for i := 0 to count - 1 do begin
        ent := ksEntity( collect.GetByIndex(i) );
        colorPr := ksColorParam( ent.ColorParam );
        // интерфейс свойств поверхности
        faceDef := ksFaceDefinition( ent.GetDefinition() );
        if faceDef <> nil then
        begin
          if ( faceDef.IsCone() ) or ( faceDef.IsCylinder() ) then // если коническая пов-ть
          begin
            count2 := count2 + 1;   // считаем количество объектов
          end;

          if faceDef.IsPlanar() then // если плоская пов-ть
          begin
            count1 := count1 + 1;   // считаем количество объектов
          end;

          colorPr := nil;
          ent.Update(); // обновить параметры
        end;
      end;
    end;

    // сообщяем о результатах работы
    if count = 0 then
      iKompasObject.ksMessage( 'Не найдено ни одной поверхности' )
    else
      iKompasObject.ksMessage(Format('Найдено %d коничечких и %d плоских объектов', [count2, count1] ));

    count1 := 0;
    count2 := 0;
    // массив ребер
    collect2 := ksEntityCollection( part.EntityCollection(o3d_edge) );
    count := collect2.GetCount();
    if ( collect2 <> nil ) and ( count <> 0 ) then
    begin
      for i := 0 to count - 1 do
      begin
        ent := ksEntity( collect2.GetByIndex(i) );
        edgeDef := ksEdgeDefinition( ent.GetDefinition() );
        if edgeDef <> nil then
          if edgeDef.IsStraight() then
            count1 := count1 + 1 // количество прямых ребер
          else
            count2 := count2 + 1; // количество криволинейных ребер
      end;
    end;

    // сообщяем о результатах работы
    if count = 0 then
      iKompasObject.ksMessage( 'Не найдено ни одного ребра' )
    else
      iKompasObject.ksMessage( Format( 'Найдено %d прямых и %d криволинейных ребер', [ count1, count2 ] ) );
  end;
end;

//------------------------------------------------------------------------------
// открытие группы документов и создание итератора по ним
//-
procedure DocIterator;
var
  doc: ksDocument3D;
  arrDoc: ksDynamicArray;
  item: ksChar255;
  i: integer;
  iter: ksIterator;
  ref: Reference;
  count: Integer;
begin
	doc := ksDocument3D( iKompasObject.Document3D() );
	arrDoc := ksDynamicArray( iKompasObject.GetDynamicArray(CHAR_STR_ARR) ); // динамический массив указателей на строки символов
	// если массив создан запускаем диалог выбора файлов
  if arrDoc <> nil then
  begin
    iKompasObject.ksChoiceFiles( '*.m3d','Документы (*.m3d)|*.m3d|Все файлы (*.*)|*.*|', arrDoc, false);
    count := arrDoc.ksGetArrayCount();
    if count = 0 then
      exit;
    item := ksChar255( iKompasObject.GetParamStruct(ko_Char255) );
		if item <> nil then
    begin
			// откроем все файлы указанные пользователем
      for i := 0 to count - 1 do
				if arrDoc.ksGetArrayItem(i, item) <> 0 then
        begin
					doc := ksDocument3D(iKompasObject.Document3D()); // захватываем интерфейс документа
					doc.Open( item.str, false ); // открываем файл с заданным именем
					doc := nil; // освобождаем интерфейс
				end;
		end;

		// сообщаем количество открытых файлов
    iKompasObject.ksMessage( 'Открыто ' + IntToStr(arrDoc.ksGetArrayCount()) + ' файлов' );

		// создаем итератор по документам
		iter := ksIterator( iKompasObject.GetIterator() );
		if iter <> nil then
    begin
      iter.ksCreateIterator(D3_DOCUMENT_OBJ, 0);
      ref := iter.ksMoveIterator('F');  // смещаем итератор на первый элемент
      while bool(ref) do  // смещаем итератор на следующую позицию
      begin
        // захватываем интерфейс документа
        doc := nil; // освободить интерфейс
        doc := ksDocument3D( iKompasObject.ksGet3dDocumentFromRef(ref) );
        if doc <> nil then
        begin
          iKompasObject.ksMessage( 'Автор документа: ' + doc.author ); // автор документа
          iKompasObject.ksMessage( 'Комментарий к документу: ' + doc.comment ); // комментарии к документу
          iKompasObject.ksMessage( 'Имя файла: ' + doc.filename ); // имя файла документа
        end;
        ref := iter.ksMoveIterator('N');
      end;
      iter.ksDeleteIterator(); // удалить итератор
		end;
	end;
end;

//------------------------------------------------------------------------------
// LibraryName
//---
function LIBRARYNAME: PAnsiChar; pascal;
begin
  Result := 'Работа с компонентой (деталь или сборка)';
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
  iKompasObject := KompasObject(CreateKompasObject);

  if iKompasObject <> nil then
  begin
    iDocument3D := ksDocument3D(iKompasObject.ActiveDocument3D);

    if ( ( command = 1 ) or ( command = 2 ) ) then
    begin
      case command of
        1 : CreateDocument3D;
        2 : DocIterator;
      end;
    end else
      if (iDocument3D <> nil) then
      begin
        case command of
          3  : UseEntityCollection;       // массив ребер и плоскостей
   				4  : GetSetPartName;	          // взять/изменить имя компоненты
          5  : FixAndStandartComponent;   // фиксирование и установка стандартного объекта
          6  : GetSetColorProperty;       // получить и заменить параметры цвета компоненты
          7  : GetSetArrayVariable;    	  // взять и поменять внешние переменные компоненты
          8  : GetSetPlacmentComponent;   // получить и изменить место расположения детали в сборке
          9  : GetSetEntity;              // Получить интерфейс ksEntity объекта создаваемого системой по умолчанию и поменять параметры
          10 : CreateSketch;              // создать эскиз
          11 : GetArraySketch;            // Формирует массив объектов(здесь эскизов) и возвращает его интерфейс ksEntityCollection ( IEntityCollection )
          12 : GetSetUserParamComponent;  // Установить и получить параметры пользователя в компоненте
        end;

        iKompasObject.ksMessageBoxResult;

        iDocument3D := nil;
      end;
    //end;

    iKompasObject := nil;
  end;
end;

end.
