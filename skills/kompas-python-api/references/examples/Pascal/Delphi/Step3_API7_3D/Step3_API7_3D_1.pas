////////////////////////////////////////////////////////////////////////////////
//
// Пример библиотеки построения обозначений СПДС
//
////////////////////////////////////////////////////////////////////////////////
unit Step3_API7_3D_1;

interface
uses
  Sysutils, LDefin2D, ksAuto, Libtool, ks3DCOM_TLB, LDefin3D, LTool3D, Windows;

////////////////////////////////////////////////////////////////////////////////

  procedure  LIBRARYENTRY( command: WORD  ); Pascal;
  function   LIBRARYID   : Cardinal;         Pascal;
  function   LoadStr( ID : Integer ) : string;                     // Загрузка строки из ресурсов
  function   LibMessage( str : string; flags : integer ) : Integer;// Выдача сообщения библиотеки
  function   LibMessageByID( strId, flags : Integer ) : Integer;   // Выдача сообщения библиотеки
  procedure  GetNewKompasAPI;
  procedure  Rough3DWork;
  procedure  Base3DWork;
  procedure  Leader3DWork;
  procedure  BrandLeader3DWork;
  procedure  MarkLeader3DWork;
  procedure  Tolerance3DWork;


implementation

uses
  LtDefine,
  ksApi7,
  ksConstTLB,
  forms;

const
  IDS_NODOC       = 200;
  IDS_OBJ         = 201;
  IDS_POINT       = 202;
  IDS_ROUGH       = 203;
  IDS_EDIT        = 204;
  IDS_NOCREATE    = 205;
  IDS_BASE        = 206;
  IDS_BEGINBRANCH = 207;
  IDS_POSOBJ      = 208;
  IDS_BEGINSHELF  = 209;
  IDS_LEADER      = 210;
  IDS_MARK2       = 211;
  IDS_BRAND       = 212;
  IDS_MARK        = 213;
  IDS_ENDPOINT    = 214;
  IDS_TABLE       = 215;
  IDS_TOLERANCE   = 216;

var
  newKompasAPI  : IApplication;                                // Компас Application 7
  doc           : IKompasDocument3D;
  oType         : integer;

//------------------------------------------------------------------------------
// LibraryId
//---
function LIBRARYID: UINT; pascal;
begin
  Result := 100;  // IDR_LIB
end;


//-------------------------------------------------------------------------------
// Получить текущий документ
// ---
function GetCurrentDocument : IKompasDocument3D;

var
  kDoc : IKompasDocument;
  doc3D : IKompasDocument3D;
begin
  Result := nil;

  if ( newKompasAPI <> nil ) then
     // Получить активный документ
     kDoc := newKompasAPI.ActiveDocument;
  doc3D := kDoc As IKompasDocument3D;

  Result := doc3D;
end;


//-------------------------------------------------------------------------------
// Получить контейнер обозначений 3D
// ---
function GetSymbols3DContainer : ISymbols3DContainer;

var
  part7 : IPart7;
begin
  Result := nil;

  if ( doc <> nil ) then
  begin
    // Получаем верхний компонент
    part7 := doc.TopPart;
		
    if ( part7 <> nil ) then
      // Получаем контейнер обозначений 3D
      Result := part7 As ISymbols3DContainer;

  end;
end;


//------------------------------------------------------------------------------
// LibraryEntry
//---
procedure LIBRARYENTRY( command: WORD ); pascal;

var
  mes : WideString;
begin
  Application.Handle := GetHWindow;
  GetNewKompasAPI;
  doc := GetCurrentDocument;

  if ( doc <> nil ) then
  begin
    case command of
       1: Rough3DWork;
       2: Base3DWork;
       3: Leader3DWork;
       4: BrandLeader3DWork;
       5: MarkLeader3DWork;
       6: Tolerance3DWork;
    end;
    newKompasAPI := nil;
  end
  else
  begin
    mes := LoadStr( IDS_NODOC );
    ksMessageW( PWideChar(mes) );
  end;
end;


//-------------------------------------------------------------------------------
// Получить доступ к новому API
// ---
procedure GetNewKompasAPI;
var
  disp : IDispatch;
begin
	if newKompasAPI = nil then
  begin
    disp := IDispatch(CreateKompasApplication);
    newKompasAPI := disp As IApplication;
  end;
end;


//-----------------------------------------------------------------------------
// Функция фильтрации
// ---
function UserFilterProc( e : PIEntity ) : Integer; pascal;
 var
   e1 : IEntity;
begin
  e1 := IEntity(e);
  if ( (e1 <> nil) And ((oType = 0) Or (e1.GetType() = oType)) ) then
    Result := 1
  else
    Result := 0;
end;


//-------------------------------------------------------------------------------
// Установить параметры шероховатости
// ---
procedure SetRoughPars( rough : IRough3D  );

var
  roughPars : IRoughParams;
  txt1,
  txt2,
  txt3      : IText;
begin
	if ( rough <> nil ) then
	begin
		// Получить интерфейс параметров шероховатости
		roughPars := rough As IRoughParams;

		if ( roughPars <> nil ) then
		begin
			// Признак обработки по контуру
			roughPars.ProcessingByContour := TRUE;
			// Длина линии выноски
			roughPars.LeaderLength := 20;
			// Угол наклона линии выноски
			roughPars.LeaderAngle := 45;
			
			// Получить интерфейс текста параметров шероховатости
			txt1 := roughPars.RoughParamText;

			if ( txt1 <> nil ) then
				txt1.Str := '1';

			// Получить интерфейс текста способа обработки поверхности
			txt2 := roughPars.ProcessText;

			if ( txt2 <> nil ) then
				txt2.Str := '2';

			// Получить интерфейс текста базовой длины
			txt3 := roughPars.BaseLengthText;
			
			if ( txt3 <> nil ) then
				txt3.Str := '3';
		end;
	end;
end;


//-------------------------------------------------------------------------------
// Создать шероховатость 3D
// ---
function CreateRough3D( rough : IRough3D ) : boolean;

var
  doc3D   : IDocument3D;
  baseObj : IEntity;
  mObj    : IModelObject;
  mes     : WideString;
  x, y, z : double;
begin
	Result := false;

	if ( rough <> nil ) then
	begin
		// Преобразовать интерфейс документа 3D из API7 в API5
    doc3D := IUnknown( ksTransferInterface(PIUnknown(doc), ksAPI3DCom, 0{любой документ}) ) As IDocument3D;

	 	if ( doc3D <> nil ) then
		begin
      mes := LoadStr( IDS_OBJ );
			// Указать в документе опорный объект для построения шероховатости
      baseObj := IEntity( doc3D.UserSelectEntity(nil, nil, PWideChar(mes)) );

			if ( baseObj <> nil ) then
			begin
        mes := LoadStr( IDS_POINT );
				// Указать точку привязки
				doc3D.UserGetCursor( PWideChar(mes), x, y, z );

				// Преобразовать интерфейс объекта из API5 в API7
        mObj := IUnknown( ksTransferInterface( PIUnknown(baseObj), ksAPI7Dual, 0) ) As IModelObject;

				if ( mObj <> nil ) then
					// Установить привязку шероховатости
					rough.SetBasePosition( x, y, z, mObj );

				// Задать базовую плоскость
				rough.BasePlane := o3d_planeXOZ;

				// Установить параметры шероховатости
				SetRoughPars( rough );
				// Применить параметры
				rough.Update;
				Result := true;
        baseObj._Release;
			end;
      doc3D._Release;
	 	end;
	end;
end;


//-------------------------------------------------------------------------------
// Задать плоскость обозначения по вершине базового объекта
// ---
procedure SetPosition( rough : IRough3D; face : IModelObject );

var
  faceEnt : IEntity;
  faceDef : IFaceDefinition;
  edgeCol : IEdgeCollection;
  edgeDef : IEdgeDefinition;
  vertex  : IVertexDefinition;
  mObj    : IModelObject;
begin
	if ( (rough <> nil) And (face <> nil) ) then
	begin
		// Преобразовать интерфейс объекта дерева из API7 в API5
    faceEnt := IUnknown( ksTransferInterface(PIUnknown(face), ksAPI3DCom, o3d_entity) ) As IEntity;

		if ( faceEnt <> nil ) then
		begin
			// Получить интерфейс параметров грани
			faceDef := IUnknown( faceEnt.GetDefinition ) As IFaceDefinition;

			if ( faceDef <> nil ) then
			begin
				// Получить коллекцию ребер
				edgeCol := IEdgeCollection( faceDef.EdgeCollection );

				if ( edgeCol <> nil ) then
				begin
					// Получить интерфейс параметров ребра
					edgeDef := IEdgeDefinition( edgeCol.First );

					if ( edgeDef <> nil ) then
					begin
						// Получить интерфейс параметров вершины
						vertex := IVertexDefinition( edgeDef.GetVertex(1{начальная вершина*}) );

						if ( vertex <> nil ) then
						begin
							// Преобразовать интерфейс объекта из API5 в API7
              mObj := IUnknown( ksTransferInterface( PIUnknown(vertex), ksAPI7Dual, 0) ) As IModelObject;

							if ( mObj <> nil ) then
								// Установить положение плоскости обозначения по найденной вершине
								rough.PositionObject := mObj;

              vertex._Release;
						end;
            edgeDef._Release;
					end;
          edgeCol._Release;
				end;
        faceDef._Release;
			end;
      faceEnt._Release;
		end;
	end;
end;


//-------------------------------------------------------------------------------
// Получить новое имя объекта
// ---
function GetNewName( featObj : IFeature7; strID : integer ) : WideString;

var
  newName,
  name    : WideString;
  p       : integer;
begin
	Result := '';

	if ( featObj <> nil ) then
	begin
		// Сформировать новое имя объекта в дереве
		newName :=	LoadStr( strID );
		name := featObj.Name;
    p := Pos( ':', name );

		if ( p > 0 ) then
			newName := newName + Copy( name, p + 1, Length(name) - p );

		Result := newName;
	end;
end;


//-------------------------------------------------------------------------------
// Редактировать шероховатость 3D
// ---
procedure EditRough3D( rough : IRough3D  );

var
  roughPars : IRoughParams;
  featObj   : IFeature7;
  baseObj   : IModelObject;
  colorPars : IColorParam7;
begin
	if ( rough <> nil ) then
	begin
		// Получить интерфейс параметров шероховатости
		roughPars := rough As IRoughParams;

		if ( roughPars <> nil ) then
			// Убрать признак обработки по контуру
			roughPars.ProcessingByContour := FALSE;

		// Получить интерфейс объекта дерева
		featObj := rough As IFeature7;

		if ( featObj <> nil ) then
		begin
			// Изменить имя объекта в дереве		
			rough.Name := GetNewName( featObj, IDS_ROUGH );
			// Получить базовый объект
			baseObj := rough.BaseObject;
			// Задать плоскость обозначения по вершине базового объекта
			SetPosition( rough, baseObj );
		end;

		// Получить интерфейс свойств цвета объекта
		colorPars := rough As IColorParam7;

		// Изменить цвет на синий
		if ( colorPars <> nil ) then
			colorPars.Color := RGB( 0, 0, 255 );

		// Применить изменения
		rough.Update;
	end;
end;


//-------------------------------------------------------------------------------
// Создание и редактирование шероховатости 3D
// ---
procedure Rough3DWork;

var
  symbCont  : ISymbols3DContainer;
  roughsCol : IRoughs3D;
  newRough,
  rough     : IRough3D;
  feature   : IFeature7;
  name,
  mes       : WideString;
begin
	// Получить контейнер обозначений 3D
	symbCont := GetSymbols3DContainer;
	
	if ( symbCont <> nil ) then
	begin
		// Получить коллекцию шероховатостей 3D
		roughsCol := symbCont.Roughs3D;
		
		if ( roughsCol <> nil ) then
		begin
			// Добавить новое обозначение шероховатости 3D
			newRough := roughsCol.Add;
			
			if ( newRough <> nil ) then
			begin
				// Создать обозначение шероховатости 3D
				if ( CreateRough3D(newRough) ) then
				begin
					name := '';
					// Получить интерфейс объекта дерева построения
					feature := newRough As IFeature7;
					
					// Получить имя объекта
					if ( feature <> nil ) then
						name := feature.Name;

					mes := LoadStr( IDS_EDIT );
					if ( YesNoW(PWideChar(mes)) = 1 ) then
					begin
						// Получить объект из коллекции по имени
						rough := roughsCol.Rough3D[name];
						// Редактировать шероховатость
						EditRough3D( rough );
					end;
				end
				else
        begin
					// Выдать сообщение "Объект не создан"
          mes := LoadStr( IDS_NOCREATE );
					ksMessageW( PWideChar(mes) );
        end;
			end;
		end;
	end;
end;


//-------------------------------------------------------------------------------
// Создать обозначение базы
// ---
function CreateBase3D( base : IBase3D ) : boolean;

var
  doc3D   : IDocument3D;
  baseObj : IEntity;
  mObj    : IModelObject;
  x, y, z : double;
  mes     : WideString;
begin
	Result := false;

	if ( base <> nil ) then
	begin
		// Преобразовать интерфейс документа 3D из API7 в API5
    doc3D := IUnknown( ksTransferInterface(PIUnknown(doc), ksAPI3DCom, 0{любой документ}) ) As IDocument3D;

		if ( doc3D <> nil ) then
		begin
      mes := LoadStr( IDS_OBJ );
			// Указать в документе опорный объект для построения базы
      baseObj := IEntity( doc3D.UserSelectEntity(nil, nil, PWideChar(mes)) );

			if ( baseObj <> nil ) then
			begin
        mes := LoadStr( IDS_POINT );
				// Указать точку привязки
        doc3D.UserGetCursor( PWideChar(mes), x, y, z );

				// Преобразовать интерфейс объекта из API5 в API7
        mObj := IUnknown( ksTransferInterface( PIUnknown(baseObj), ksAPI7Dual, 0) ) As IModelObject;

				if ( mObj <> nil ) then
					// Установить привязку базы
					base.SetBranchBeginPoint( x, y, z, mObj );

				// Задать базовую плоскость
				base.BasePlane := o3d_planeXOZ;

				// Применить параметры
				base.Update;
				Result := true;
        baseObj._Release;
			end;
      doc3D._Release;
		end;
	end;
end;


//-------------------------------------------------------------------------------
// Задать компоненту текста
// ---
procedure AddTextItem( line : ITextLine; str : WideString; tType : ksTextItemEnum  );

var
  item  : ITextItem;
begin
	if ( line <> nil ) then
	begin
		// Получить интерфейс компоненты текста
		item := line.Add();
		
		if ( item <> nil ) then
		begin
			// Задать строковое значение
			item.Str := str;
			// Задать тип
			item.ItemType := tType;
      // Применить параметры
			item.Update;
		end;
	end;
end;


//-------------------------------------------------------------------------------
// Редактирование обозначения базы
// ---
procedure EditBase3D( base : IBase3D );

var
  txt       : IText;
  line      : ITextLine;
  featObj   : IFeature7;
  colorPars : IColorParam7;
  x, y, z   : double;
begin
	if ( base <> nil ) then
	begin
		// Отменить автосортировку
		base.AutoSorted := FALSE;

		// Получить интерфейс текста обозначения базы
		txt := base.Text;
		
		if ( txt <> nil ) then
		begin
			txt.Str := '';
			
			line := txt.Add;

			if ( line <> nil ) then
			begin
				// Добавить строку
				AddTextItem( line, 'A', ksTItString );
				// Добавить выражение типа суммы (нижний индекс может существовать
				// только в таком выражении
				AddTextItem( line, '', ksTItSBase );
				// Добавить нижний индекс
				AddTextItem( line, '1', ksTItSLowerIndex );
				// Закончить выражение типа суммы
				AddTextItem( line, '', ksTItSEnd );
			end;
		end;

		// Тип - произвольное положение
		base.DrawType := FALSE;
		// Сместить конечную точку обозначения базы
		base.GetBranchEndPoint( x, y, z );
		base.SetBranchEndPoint( x + 10, y + 10, z );

		// Получить интерфейс объекта дерева
		featObj := base As IFeature7;

		if ( featObj <> nil ) then
			// Изменить имя объекта в дереве
			base.Name := GetNewName( featObj, IDS_BASE );

		// Получить интерфейс свойств цвета объекта
		colorPars := base As IColorParam7;
		
		// Изменить цвет на черный
		if ( colorPars <> nil ) then
			colorPars.Color := RGB( 0, 0, 0 );

		base.Update;
	end;
end;


//-------------------------------------------------------------------------------
// Создание и редактирование обозначения базы
// ---
procedure Base3DWork;

var
  symbCont  : ISymbols3DContainer;
  basesCol  : IBases3D;
  newBase,
  base      : IBase3D;
  feature   : IFeature7;
  name,
  mes       : WideString;
begin
	// Получить контейнер обозначений 3D
	symbCont := GetSymbols3DContainer;
	
	if ( symbCont <> nil ) then
	begin
		// Получить коллекцию обозначений базы 3D
		basesCol := symbCont.Bases3D;
		
		if ( basesCol <> nil ) then
		begin
			// Добавить новое обозначение базы 3D
			newBase := basesCol.Add;
			
			if ( newBase <> nil ) then
			begin
				// Создать обозначение базы 3D
				if ( CreateBase3D(newBase) ) then
				begin
					name := '';
					// Получить интерфейс объекта дерева построения
					feature := newBase As IFeature7;

					// Получить имя объекта
					if ( feature <> nil ) then
						name := feature.Name;

          mes := LoadStr( IDS_EDIT );
					if ( YesNoW(PWideChar(mes)) = 1 ) then
					begin
						// Получить объект из коллекции по имени
						base := basesCol.Base3D[name];
						// Редактировать обозначение базы
						EditBase3D( base );
					end;
				end
				else
        begin
					// Выдать сообщение "Объект не создан"
          mes := LoadStr( IDS_NOCREATE );
					ksMessageW( PWideChar(mes) );
        end;
			end;
		end;
	end;
end;


//-------------------------------------------------------------------------------
// Установить тексты линии-выноски
// ---
procedure SetLeader3DTexts( baseLeader : IBaseLeader3D );

var
  leader      : ILeader;
  txtOnSh,
  txtUnderSh,
  txtOnBr,
  txtUnderBr,
  txtAfterSh  : IText;
begin
	leader := baseLeader As ILeader;

	if ( leader <> nil ) then
	begin
		// Получить интерфейс текста над полкой
		txtOnSh := leader.TextOnShelf;

		if ( txtOnSh <> nil ) then
			// Изменить текст
			txtOnSh.Str := '1';
		
		// Получить интерфейс текста под полкой
		txtUnderSh := leader.TextUnderShelf;

		if ( txtUnderSh <> nil ) then
			// Изменить текст
			txtUnderSh.Str := '2';
		
		// Получить интерфейс текста над ножкой
		txtOnBr := leader.TextOnBranch;
		
		if ( txtOnBr <> nil ) then
			// Изменить текст
			txtOnBr.Str := '3';

		// Получить интерфейс текста под ножкой
		txtUnderBr := leader.TextUnderBranch;
		
		if ( txtUnderBr <> nil ) then
			// Изменить текст
			txtUnderBr.Str := '4';
		
		// Получить интерфейс текста за полкой
		txtAfterSh := leader.TextAfterShelf;
		
		if ( txtAfterSh <> nil ) then
			// Изменить текст
			txtAfterSh.Str := '5';
	end;
end;


//-------------------------------------------------------------------------------
// Создать ответвление линии-выноски
// ---
procedure CreateBranchsLeader( leader : IBaseLeader3D );

var
  doc3D       : IDocument3D;
  baseObj,
  posObj      : IEntity;
  mObj1,
  mObj2       : IModelObject;
  branchs3D   : IBranchs3D;
  x, y, z,
  x1, y1, z1  : double;
  mes         : WideString;
begin
	if ( leader <> nil ) then
	begin
		// Преобразовать интерфейс документа 3D из API7 в API5
		doc3D := IUnknown( ksTransferInterface(PIUnknown(doc), ksAPI3DCom, 0{любой документ}) ) As IDocument3D;

		if ( doc3D <> nil ) then
		begin
      mes := LoadStr( IDS_OBJ );
			// Указать в документе опорный объект
      baseObj := IEntity( doc3D.UserSelectEntity(nil, nil, PWideChar(mes)) );

      mes := LoadStr( IDS_BEGINBRANCH );
			// Указать точку начала ножки
      // Точка должна лежать на опорном объекте
      doc3D.UserGetCursor( PWideChar(mes), x, y, z );

			mes := LoadStr( IDS_POSOBJ );
			// Указать объект, задающий плоскость обозначения
      posObj := IEntity( doc3D.UserSelectEntity(nil, nil, PWideChar(mes)) );

			if ( (baseObj <> nil) And (posObj <> nil) ) then
			begin
        mes := LoadStr( IDS_BEGINSHELF );
				// Указать точку, задающую положние объектов
        // Точка должна лежать в плоскости обозначения
        doc3D.UserGetCursor( PWideChar(mes), x1, y1, z1 );
				// Преобразовать интерфейс объекта из API5 в API7
        mObj1 := IUnknown( ksTransferInterface( PIUnknown(baseObj), ksAPI7Dual, 0) ) As IModelObject;
        mObj2 := IUnknown( ksTransferInterface( PIUnknown(posObj), ksAPI7Dual, 0) ) As IModelObject;

				if ( (mObj1 <> nil) And (mObj2 <> nil) ) then
				begin
					// Получить интерфейс ответвлений
					branchs3D := leader As IBranchs3D;

					// Добавить ответвление
					if ( branchs3D <> nil ) then
						branchs3D.AddBranchByPoint( x, y, z, mObj1 );

					// Установить объект, задающий плоскость обозначения
					leader.PositionObject := mObj2;
					leader.SetPosition( x1, y1, z1 );
				end;
        baseObj._Release;
        posObj._Release;
			end;
      doc3D._Release;
		end;
	end;
end;


//-------------------------------------------------------------------------------
// Создать линию-выноску
// ---
function CreateLeader3D( leader : IBaseLeader3D ) : boolean;
begin
	Result := false;

	if ( leader <> nil ) then
	begin
		// Создать ответвления линии-выноски
		CreateBranchsLeader( leader );
		// Установить тексты линии-выноски
		SetLeader3DTexts( leader );
		// Применить параметры
		leader.Update;
		Result := true;
	end;
end;


//-------------------------------------------------------------------------------
// Изменить параметры линии-выноски
// ---
procedure EditLeaderPars( baseLeader : IBaseLeader3D );

var
  leader  : ILeader;
  txt     : IText;
  line    : ITextLine;
begin
	if ( baseLeader <> nil ) then
	begin
		leader := baseLeader As ILeader;

		if ( leader <> nil ) then
		begin
			// Тип значка - знак склеивания
			leader.SignType := ksLGlueSign;
			// Включить признак обоработки по контуру
			leader.Arround := TRUE;

			// Начало созданного ответвления - от конца полки
			leader.BranchBegin[2] := FALSE;

			// Получить текст над полкой
			txt := leader.TextOnShelf;
			
			if ( txt <> nil ) then
			begin
				txt.Str := '';

				line := txt.Add;

				if ( line <> nil ) then
				begin
					// Добавить строку
					AddTextItem( line, '1', ksTItString );
					// Добавить числитель дроби
					AddTextItem( line, '1', ksTItNumerator );
					// Добавить знаментатель дроби
					AddTextItem( line, '1', ksTItDenominator );
					// Закончить дробь
					AddTextItem( line, '1', ksTItFractionEnd );
				end;
			end;
		end;
	end;
end;


//-------------------------------------------------------------------------------
// Добавить прямолинейное ответвление
// ---
procedure LeaderAddBranch( leader : IBaseLeader3D );

var
  doc3D     : IDocument3D;
  baseObj   : IEntity;
  mObj      : IModelObject;
  branchs3D : IBranchs3D;
  x, y, z   : double;
  mes       : WideString;
begin
	if ( leader <> nil ) then
	begin
		// Преобразовать интерфейс документа 3D из API7 в API5
    doc3D := IUnknown( ksTransferInterface(PIUnknown(doc), ksAPI3DCom, 0{любой документ}) ) As IDocument3D;

		if ( doc3D <> nil ) then
		begin
      mes := LoadStr( IDS_OBJ );
			// Указать в документе опорный объект
      baseObj := IEntity( doc3D.UserSelectEntity(nil, nil, PWideChar(mes)) );

      mes := LoadStr( IDS_BEGINBRANCH );
      // Указать точку начала ножки
      // Точка должна лежать на опорном объекте
      doc3D.UserGetCursor( PWideChar(mes), x, y, z );

			if ( baseObj <> nil ) then
			begin
				// Преобразовать интерфейс объекта из API5 в API7
        mObj := IUnknown( ksTransferInterface( PIUnknown(baseObj), ksAPI7Dual, 0) ) As IModelObject;

				if ( mObj <> nil ) then
				begin
					// Получить интерфейс ответвлений
					branchs3D := leader As IBranchs3D;

					// Добавить ответвление
					if ( branchs3D <> nil ) then
						branchs3D.AddBranchByPoint( x, y, z, mObj );
				end;
        baseObj._Release;
			end;
      doc3D._Release;
		end;
	end;
end;


//-------------------------------------------------------------------------------
// Редактировать линию-выноску
// ---
procedure EditLeader3D( leader : IBaseLeader3D );

var
  featObj   : IFeature7;
  colorPars : IColorParam7;
begin
	if ( leader <> nil ) then
	begin
		// Добавить прямолинейное ответвление
		LeaderAddBranch( leader );
		// Изменить параметры линии-выноски
		EditLeaderPars( leader );

		// Получить интерфейс объекта дерева
		featObj := leader As IFeature7;
		
		if ( featObj <> nil ) then
			// Изменить имя объекта в дереве
			leader.Name := GetNewName( featObj, IDS_LEADER );
		
		// Получить интерфейс свойств цвета объекта
		colorPars := leader As IColorParam7;
		
		// Изменить цвет на коричневый
		if ( colorPars <> nil ) then
			colorPars.Color := RGB( 123, 40, 0 );

		// Применить изменения
		leader.Update;
	end;
end;


//-------------------------------------------------------------------------------
// Создание и редактирование линии-выноски 3D
// ---
procedure Leader3DWork;

var
  symbCont  : ISymbols3DContainer;
  leadsCol  : ILeaders3D;
  newLeader,
  leader    : IBaseLeader3D;
  feature   : IFeature7;
  name,
  mes       : WideString;
begin
	// Получить контейнер обозначений 3D
	symbCont := GetSymbols3DContainer;

	if ( symbCont <> nil ) then
	begin
		// Получить коллекцию линий-выносок 3D
		leadsCol := symbCont.Leaders3D;

		if ( leadsCol <> nil ) then
		begin
			// Добавить новую линию-выноску 3D
			newLeader := leadsCol.Add( o3d_leader3D );

			if ( newLeader <> nil ) then
			begin
				// Создать линию-выноску 3D
				if ( CreateLeader3D(newLeader) ) then
				begin
					name := '';
					// Получить интерфейс объекта дерева построения
					feature := newLeader As IFeature7;

					// Получить имя объекта
					if ( feature <> nil ) then
						name := feature.Name;

					mes := LoadStr( IDS_EDIT );
					if ( YesNoW(PWideChar(mes)) = 1 ) then
					begin
						// Получить объект из коллекции по имени
						leader := leadsCol.Leader3D[name];
						// Редактировать линию-выноску
						EditLeader3D( leader );
					end;
				end
				else
        begin
					// Выдать сообщение "Объект не создан"
          mes := LoadStr( IDS_NOCREATE );
					ksMessageW( PWideChar(mes) );
        end;
			end;
		end;
	end;
end;


//-------------------------------------------------------------------------------
// Создать знак клеймения 3D
// ---
function CreateBrandLeader3D( baseLeader : IBaseLeader3D  ) : boolean;

var
  brandLeader : IBrandLeader;
begin
	Result := false;
	
	if ( baseLeader <> nil ) then
	begin
		// Создать ответвления
		CreateBranchsLeader( baseLeader );

		// Получить интерфейс знака клеймения
		brandLeader := baseLeader As IBrandLeader;

		if ( brandLeader <> nil ) then
			// Направление
			brandLeader.Direction := false;
			
		// Применить параметры
		baseLeader.Update;
		Result := true;
	end;
end;


//-------------------------------------------------------------------------------
// Редактировать знак клеймения
// ---
procedure EditBrandLeader3D( leader : IBaseLeader3D );

var
  brandLeader : IBrandLeader;
  des         : IText;
  featObj     : IFeature7;
  colorPars   : IColorParam7;
  str         : WideString;
begin
	if ( leader <> nil ) then
	begin
		// Добавить прямолинейное ответвление
		LeaderAddBranch( leader );

		// Установить параметры знака клеймения
		brandLeader := leader As IBrandLeader;
		
		if ( brandLeader <> nil ) then
		begin
			// Получить интерфейс текста обозначения
			des := brandLeader.Designation;
			
			if ( des <> nil ) then
      begin
				// Изменить текст
        str := LoadStr( IDS_MARK2 );
				des.Str := str;
      end;
		end;

		// Получить интерфейс объекта дерева
		featObj := leader As IFeature7;

		if ( featObj <> nil ) then
			// Изменить имя объекта в дереве
			leader.Name := GetNewName( featObj, IDS_BRAND );
		
		// Получить интерфейс свойств цвета объекта
		colorPars := leader As IColorParam7;
		
		// Изменить цвет на фиолетовый
		if ( colorPars <> nil ) then
			colorPars.Color := RGB( 128, 0, 128 );

		// Применить изменения
		leader.Update;
	end;
end;


//-------------------------------------------------------------------------------
// Создание и редактирование знака клеймения
// ---
procedure BrandLeader3DWork;

var
  symbCont    : ISymbols3DContainer;
  leadsCol    : ILeaders3D;
  newBrand,
  brandLeader : IBaseLeader3D;
  feature     : IFeature7;
  name,
  mes         : WideString;
begin
	// Получить контейнер обозначений 3D
	symbCont := GetSymbols3DContainer;

	if ( symbCont <> nil ) then
	begin
		// Получить коллекцию линий-выносок 3D
		leadsCol := symbCont.Leaders3D;

		if ( leadsCol <> nil ) then
		begin
			// Добавить новый знак клеймения 3D
			newBrand := leadsCol.Add( o3d_brandLeader3D );

			if ( newBrand <> nil ) then
			begin
				// Создать знак клеймения 3D
				if ( CreateBrandLeader3D(newBrand) ) then
				begin
					name := '';
					// Получить интерфейс объекта дерева построения
					feature := newBrand As IFeature7;

					// Получить имя объекта
					if ( feature <> nil ) then
						name := feature.Name;

					mes := LoadStr( IDS_EDIT );
					if ( YesNoW(PWideChar(mes)) = 1 ) then
					begin
						// Получить объект из коллекции по имени
						brandLeader := leadsCol.Leader3D[name];
						// Редактировать знак клеймения 3D
						EditBrandLeader3D( brandLeader );
					end;
				end
				else
        begin
					// Выдать сообщение "Объект не создан"
          mes := LoadStr( IDS_NOCREATE );
					ksMessageW( PWideChar(mes) );
        end;
			end;
		end;
	end;
end;


//-------------------------------------------------------------------------------
// Создать знак маркировки
// ---
function CreateMarkLeader3D( baseLeader : IBaseLeader3D ) : boolean;

var
  markLeader      : IMarkLeader;
  textOnBranch,
  textUnderBranch : IText;
begin
	Result := false;

	if ( baseLeader <> nil ) then
	begin
		// Создать ответвление
		CreateBranchsLeader( baseLeader );

		// Получить интерфейс знака маркировки
		markLeader := baseLeader As IMarkLeader;

		if ( markLeader <> nil ) then
		begin
			// Получить интерфейс текста над ножкой
			textOnBranch := markLeader.TextOnBranch;

			if ( textOnBranch <> nil ) then
				// Изменить текст
				textOnBranch.Str := '2';

			// Получить интерфейс текста под ножкой
			textUnderBranch := markLeader.TextUnderBranch;

			if ( textUnderBranch <> nil ) then
				// Изменить текст
				textUnderBranch.Str := '3';
		end;
		// Применить параметры
		baseLeader.Update;
		Result := true;
	end;
end;


//-------------------------------------------------------------------------------
// Редактировать знак маркировки
// ---
procedure EditMarkLeader3D( baseLeader : IBaseLeader3D );

var
  markLeader  : IMarkLeader;
  des         : IText;
  featObj     : IFeature7;
  colorPars   : IColorParam7;
begin
	if ( baseLeader <> nil ) then
	begin
		// Добавить прямолинейное ответвление
		LeaderAddBranch( baseLeader );

		// Получить интерфейс знака маркировки
		markLeader := baseLeader As IMarkLeader;

		if ( markLeader <> nil ) then
		begin
			// Получить интерфейс текста обозначения
			des := markLeader.Designation;

			if ( des <> nil ) then
				// Изменить текст
				des.Str := '10';
		end;

		// Получить интерфейс объекта дерева
		featObj := baseLeader As IFeature7;

		if ( featObj <> nil ) then
			// Изменить имя объекта в дереве
			baseLeader.Name := GetNewName( featObj, IDS_MARK );
		
		// Получить интерфейс свойств цвета объекта
		colorPars := baseLeader As IColorParam7;
		
		// Изменить цвет на сиреневый
		if ( colorPars <> nil ) then
			colorPars.Color := RGB( 204, 153, 255 );
		
		// Применить изменения
		baseLeader.Update;
	end;
end;


//-------------------------------------------------------------------------------
// Создание и редактирование знака маркировки 3D
// ---
procedure MarkLeader3DWork;
var
  symbCont    : ISymbols3DContainer;
  leadsCol    : ILeaders3D;
  newMark,
  markLeader  : IBaseLeader3D;
  feature     : IFeature7;
  name,
  mes         : WideString;
begin
	// Получить контейнер обозначений 3D
	symbCont := GetSymbols3DContainer;

	if ( symbCont <> nil ) then
	begin
		// Получить коллекцию линий-выносок 3D
		leadsCol := symbCont.Leaders3D;

		if ( leadsCol <> nil ) then
		begin
			// Добавить новый знак маркировки 3D
			newMark := leadsCol.Add( o3d_markLeader3D );

			if ( newMark <> nil ) then
			begin
				// Создать знак маркировки 3D
				if ( CreateMarkLeader3D(newMark) ) then
				begin
					name := '';
					// Получить интерфейс объекта дерева построения
					feature := newMark As IFeature7;

					// Получить имя объекта
					if ( feature <> nil ) then
						name := feature.Name;

					mes := LoadStr( IDS_EDIT );
					if ( YesNoW(PWideChar(mes)) = 1 ) then
					begin
						// Получить объект из коллекции по имени
						markLeader := leadsCol.Leader3D[name];
						// Редактировать знак маркировки 3D
						EditMarkLeader3D( markLeader );
					end;
				end
				else
        begin
					// Выдать сообщение "Объект не создан"
          mes := LoadStr( IDS_NOCREATE );
					ksMessageW( PWideChar(mes) );
        end;
			end;
		end;
	end;
end;


//-------------------------------------------------------------------------------
// Создать ответвление для доопуска формы
// ---
procedure CreateToleranceBranch( tolerance : ITolerance3D );
var
  doc3D       : IDocument3D;
  baseObj,
  posObj      : IEntity;
  mObj1,
  mObj2       : IModelObject;
  branchs3D   : IBranchs3D;
  x, y, z,
  x1, y1, z1  : double;
  mes         : WideString;
begin
	if ( tolerance <> nil ) then
	begin
		// Преобразовать интерфейс документа 3D из API7 в API5
		doc3D := IUnknown( ksTransferInterface(PIUnknown(doc), ksAPI3DCom, 0{любой документ}) ) As IDocument3D;

		if ( doc3D <> nil ) then
		begin
      mes := LoadStr( IDS_OBJ );
			// Указать в документе опорный объект
      baseObj := IEntity( doc3D.UserSelectEntity(nil, nil, PWideChar(mes)) );

      mes := LoadStr( IDS_ENDPOINT );
			// Указать точку начала ножки
      // Точка должна лежать на опорном объекте
      doc3D.UserGetCursor( PWideChar(mes), x, y, z );

			mes := LoadStr( IDS_POSOBJ );
			// Указать объект, задающий плоскость обозначения
      posObj := IEntity( doc3D.UserSelectEntity(nil, nil, PWideChar(mes)) );

			if ( (baseObj <> nil) And (posObj <> nil) ) then
			begin
        mes := LoadStr( IDS_TABLE );
				// Указать точку вставки таблицы
        doc3D.UserGetCursor( PWideChar(mes), x1, y1, z1 );
				// Преобразовать интерфейс объекта из API5 в API7
        mObj1 := IUnknown( ksTransferInterface( PIUnknown(baseObj), ksAPI7Dual, 0) ) As IModelObject;
        mObj2 := IUnknown( ksTransferInterface( PIUnknown(posObj), ksAPI7Dual, 0) ) As IModelObject;

				if ( (mObj1 <> nil) And (mObj2 <> nil) ) then
				begin
					// Получить интерфейс ответвлений
					branchs3D := tolerance As IBranchs3D;

					// Добавить ответвление
					if ( branchs3D <> nil ) then
						branchs3D.AddBranchByPoint( x, y, z, mObj1 );

					// Установить объект, задающий плоскость обозначения
					tolerance.PositionObject := mObj2;
					tolerance.SetPosition( x1, y1, z1 );
				end;
        baseObj._Release;
        posObj._Release;
			end;
      doc3D._Release;
		end;
	end;
end;


//-------------------------------------------------------------------------------
// Задать текст в ячейках допуска формы
// ---
procedure SetToleranceText( tolPar : IToleranceParam );

var
  tolTable  : ITable;
  txt       : ITextLine;
  cell      : ITableCell;
begin
	if ( tolPar <> nil ) then
	begin
		// Получить интерфейс таблицы с текстом допуска формы
		tolTable := tolPar.Table;
		
		if ( tolTable <> nil ) then
		begin
			// Добавить 3 столбца (1 уже есть)
			tolTable.AddColumn( -1, TRUE {справа} );
			tolTable.AddColumn( -1, TRUE {справа} );
			tolTable.AddColumn( -1, TRUE {справа} );
			
			// Записать текст в 1-ю ячейку
			cell := tolTable.Cell[ 0, 0 ];

			if ( cell <> nil ) then
			begin
				txt:= cell.Text As ITextLine;
				
				if ( txt <> nil ) then
					txt.Str := '@22~';
			end;
			
			// Записать текст во 2-ю ячейку
			cell := tolTable.Cell[ 0, 1 ];
			
			if ( cell <> nil ) then
			begin
				txt := cell.Text As ITextLine;
				
				if ( txt <> nil ) then
					txt.Str := '@2~';
			end;

			// Записать текст в 3-ю ячейку
			cell := tolTable.Cell[ 0, 2 ];
			
			if ( cell <> nil ) then
			begin
				txt := cell.Text As ITextLine;

				if ( txt <> nil ) then
					txt.Str := 'B';
			end;

			// Записать текст в 4-ю ячейку
			cell := tolTable.Cell[ 0, 3 ];

			if ( cell <> nil ) then
			begin
				txt := cell.Text As ITextLine;

				if ( txt <> nil ) then
					txt.Str := '@30~';
			end;
		end;
	end;
end;


//-------------------------------------------------------------------------------
// Создать допуск формы
// ---
function CreateTolerance3D( tolerance : ITolerance3D ) : boolean;

var
  tolPar  : IToleranceParam;
begin
	Result := false;

	if ( tolerance <> nil ) then
	begin
		// Создать ответвление
		CreateToleranceBranch( tolerance );
		// Получить интерфейс параметров допуска формы
		tolPar := tolerance As IToleranceParam;
		
		if ( tolPar <> nil ) then
		begin
			// Создать текст в ячейках
			SetToleranceText( tolPar );
			// Положение базовой точки относительно таблицы - внизу посередине
			tolPar.BasePointPos := ksTPBottomCenter;
		end;
		// Тип стрелки 1-го ответвления - треугольник
		tolerance.Set_ArrowType( 0, false );
		// Применить параметры
		tolerance.Update;
		Result := true;
	end;
end;


//-------------------------------------------------------------------------------
// Добавить ответвление для допуска формы
// ---
procedure ToleranceAddBranch( tolerance : ITolerance3D );
var
  doc3D     : IDocument3D;
  baseObj   : IEntity;
  mObj      : IModelObject;
  branchs3D : IBranchs3D;
  x, y, z   : double;
  mes       : WideString;
begin
	if ( tolerance <> nil ) then
	begin
		// Преобразовать интерфейс документа 3D из API7 в API5
    doc3D := IUnknown( ksTransferInterface(PIUnknown(doc), ksAPI3DCom, 0{любой документ}) ) As IDocument3D;

		if ( doc3D <> nil ) then
		begin
      mes := LoadStr( IDS_OBJ );
			// Указать в документе опорный объект
      baseObj := IEntity( doc3D.UserSelectEntity(nil, nil, PWideChar(mes)) );

      mes := LoadStr( IDS_BEGINBRANCH );
      // Указать точку конца ответвления
      // Точка должна лежать на опорном объекте
      doc3D.UserGetCursor( PWideChar(mes), x, y, z );

			if ( baseObj <> nil ) then
			begin
				// Преобразовать интерфейс объекта из API5 в API7
        mObj := IUnknown( ksTransferInterface( PIUnknown(baseObj), ksAPI7Dual, 0) ) As IModelObject;

				if ( mObj <> nil ) then
				begin
					// Получить интерфейс ответвлений
					branchs3D := tolerance As IBranchs3D;

					// Добавить ответвление
					if ( branchs3D <> nil ) then
						branchs3D.AddBranchByPoint( x, y, z, mObj );

          // Ответвление со стрелкой
					tolerance.Set_ArrowType( 1, TRUE );
				end;
        baseObj._Release;
			end;
      doc3D._Release;
		end;
	end;
end;


//-------------------------------------------------------------------------------
// Редактировать допуск формы
// ---
procedure EditTolerance3D( tolerance : ITolerance3D );

var
  tolPar    : IToleranceParam;
  featObj   : IFeature7;
  colorPars : IColorParam7;
begin
	if ( tolerance <> nil ) then
	begin
		ToleranceAddBranch( tolerance );

		// Получитьинтерфейс параметров допуска формы
		tolPar := tolerance As IToleranceParam;

		if ( tolPar <> nil ) then
		begin
			// Задать признак вертикальности
			tolPar.Vertical := TRUE;
			// Положение базовой точки относительно таблицы - слева посередине
			tolPar.BasePointPos := ksTPLeftBottom;
		end;

		// Получить интерфейс объекта дерева
		featObj := tolerance As IFeature7;
		
		if ( featObj <> nil ) then
			// Изменить имя объекта в дереве
			tolerance.Name := GetNewName( featObj, IDS_TOLERANCE );

		// Получить интерфейс свойств цвета объекта
		colorPars := tolerance As IColorParam7;
		
		// Изменить цвет на темно-красный
		if ( colorPars <> nil ) then
			colorPars.Color := RGB( 186, 12, 34 );

		// Применить изменения
		tolerance.Update;
	end;
end;


//-------------------------------------------------------------------------------
// Создание и редактирование допуска формы 3D
// ---
procedure Tolerance3DWork;

var
  symbCont    : ISymbols3DContainer;
  tolerCol    : ITolerances3D;
  newTolerance,
  tolerance   : ITolerance3D;
  feature     : IFeature7;
  name,
  mes         : WideString;
begin
	// Получить контейнер обозначений 3D
	symbCont := GetSymbols3DContainer;

	if ( symbCont <> nil ) then
	begin
		// Получить коллекцию допусков формы 3D
		tolerCol := symbCont.Tolerances3D;
		
		if ( tolerCol <> nil ) then
		begin
			// Добавить новый допуск формы 3D
			newTolerance := tolerCol.Add;

			if ( newTolerance <> nil ) then
			begin
				// Создать допуск формы 3D
				if ( CreateTolerance3D(newTolerance) ) then
				begin
					name := '';
					// Получить интерфейс объекта дерева построения
					feature := newTolerance As IFeature7;

					// Получить имя объекта
					if ( feature <> nil ) then
						name := feature.Name;

					mes := LoadStr( IDS_EDIT );
					if ( YesNoW(PWideChar(mes)) = 1 ) then
					begin
						// Получить объект из коллекции по имени
						tolerance := tolerCol.Tolerance3D[name];
						// Редактировать допуск формы
						EditTolerance3D( tolerance );
					end;
				end
				else
        begin
					// Выдать сообщение "Объект не создан"
          mes := LoadStr( IDS_NOCREATE );
					ksMessageW( PWideChar(mes) );
        end;
			end;
		end;
	end;
end;


//----------------------------------------------------------------------------------------------
// Загрузить строку из ресурсов
//---
function LoadStr( ID : Integer ) : string;
var
  buf : array [0..255] of WideChar;
begin
  ksConvertLangStrExW( hInstance, ID, buf, 255 );
  Result := buf;
end;


//------------------------------------------------------------------------------
// Вывод сообщения
// ---
function LibMessage( str : string; flags : integer ) : Integer;
var
 enabse : Integer;
begin
  enabse := IsEnableTaskAccess();  // проверка доступа
  if enabse <> 0 then             // если доступ к задаче разрешен
    EnableTaskAccess(0);          // запрещаем доступ

    //                         текст сообщения  заголовок          параметры
  Result := Application.MessageBox( PChar(str), PChar(LoadStr(LIBRARYID)), flags );

  if enabse <> 0 then                         // если доступ к задаче был запрещен
    EnableTaskAccess(1);              // разрешаем доступ к задаче

end;


//------------------------------------------------------------------------------
// Вывод сообщения
// ---
function LibMessageByID( strId, flags : Integer ) : Integer;
begin
  Result := LibMessage( LoadStr(strId), flags );
end;

end.


