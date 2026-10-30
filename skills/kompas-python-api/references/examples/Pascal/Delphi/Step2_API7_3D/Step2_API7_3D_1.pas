////////////////////////////////////////////////////////////////////////////////
//
// Пример библиотеки построения обозначений СПДС
//
////////////////////////////////////////////////////////////////////////////////
unit Step2_API7_3D_1;

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
  procedure  CreateLineDimension3D;
  procedure  LineDimension3DNavigation;
  procedure  EditLineDimension3D;
  procedure  RadialDimension3DWork;
  procedure  DiametralDimension3DWork;
  procedure  AngleDimension3DWork;

implementation

uses
  LtDefine,
  ksApi7,
  ksConstTLB,
  forms;

const
  IDS_NODOC       = 200;
  IDS_OBJ1        = 201;
  IDS_PLANE       = 202;
  IDS_NOCREATE    = 203;
  IDS_LINEDIM3D   = 204;
  IDS_LENGTH      = 205;
  IDS_DIMVAL      = 206;
  IDS_NEWPLANE    = 207;
  IDS_DIM         = 208;
  IDS_NOTSETPLANE = 209;
  IDS_NOTDIM      = 210;
  IDS_NOTCIRCLE   = 211;
  IDS_EDIT        = 212;
  IDS_DIMTEXT     = 213;
  IDS_OBJECT1     = 214;
  IDS_OBJECT2     = 215;

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
begin
  Result := nil;

  if ( newKompasAPI <> nil ) then
     // Получить активный документ
     kDoc := newKompasAPI.ActiveDocument;
  Result := kDoc As IKompasDocument3D;

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
       1: CreateLineDimension3D;
       2: LineDimension3DNavigation;
       3: EditLineDimension3D;
       4: RadialDimension3DWork;
       5: DiametralDimension3DWork;
       6: AngleDimension3DWork;
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
// Установить объект привязки и базовую плоскость
// ---
function SetLineDimObjectPlane( dim : ILineDimension3D ) : boolean;

var
  doc3D   : IDocument3D;
  obj1,
  plane   : IEntity;
  mObj1,
  mPlane  : IModelObject;
  mes     : WideString;
begin
	Result := false;
	// Фильтрация объектов - ребра
	oType := o3d_edge;

	// Преобразовать интерфейс документа 3D из API7 в API5
	doc3D := IUnknown( ksTransferInterface(PIUnknown(doc), ksAPI3DCom, 0{любой документ}) ) As IDocument3D;

	if ( doc3D <> nil ) then
	begin
    mes := LoadStr( IDS_OBJ1 );
		// Указать в документе объект - ребро
		obj1 := IEntity( doc3D.UserSelectEntity(nil, @UserFilterProc, PWideChar(mes)) );

		if ( obj1 <> nil ) then
		begin
			// Тип фильтрации - грани
			oType := o3d_face;
      mes := LoadStr( IDS_PLANE );
			// Указать в документе объект - грань
			plane := IEntity( doc3D.UserSelectEntity(nil, @UserFilterProc, PWideChar(mes)) );

			if ( plane <> nil ) then
			begin
				// Преобразовать интерфейсы ребра и грани из API5 в API7
				mObj1 := IUnknown( ksTransferInterface( PIUnknown(obj1), ksAPI7Dual, 0) ) As IModelObject;
				mPlane :=  IUnknown( ksTransferInterface( PIUnknown(plane), ksAPI7Dual, 0) ) As IModelObject;

				if ( (mObj1 <> nil) And (mPlane <> nil) ) then
				begin
					// Установить первый объект размера (Второй объект устанавливается
					// только в том случае, если измеряется расстояние между точками)
					dim.Object1 := mObj1;
					// Установить базовую плоскость размера
					dim.Plane := mPlane;
					Result := true;
          mObj1._Release;
          mPlane._Release;
				end;
        plane._Release;
			end;
      obj1._Release;
		end;
    doc3D._Release;
	end;
end;


//-------------------------------------------------------------------------------
// Создание линейного размера 3D
// ---
procedure CreateLineDimension3D;

var
  symbCont  : ISymbols3DContainer;
  dimsCol   : ILineDimensions3D;
  newDim    : ILineDimension3D;
  obj       : IFeature7;
  create    : boolean;
  mes       : WideString;
begin
	// Получить контейнер обозначений 3D
	symbCont := GetSymbols3DContainer;

	if ( symbCont <> nil ) then
	begin
		// Получить коллекцию линейных размеров 3D
		dimsCol := symbCont.LineDimensions3D;

		if ( dimsCol <> nil ) then
		begin
			// Добавить новый линейный размер 3D
			newDim := dimsCol.Add( o3d_lineDimension3D ) As ILineDimension3D;

			if ( newDim <> nil ) then
			begin
				create := false;

				// Если удалось установить объект привязки и базовую плоскость
				if ( SetLineDimObjectPlane(newDim) ) then
				begin
					// Установить длину размера
					newDim.Length := 30;
					// Применить параметры
					create := newDim.Update;
				end

				else
        begin
					// Выдать сообщение "Объект не создан"
          mes := LoadStr( IDS_NOCREATE );
					ksMessageW( PWideChar(mes) );
        end;

				// Если объект не создался, удалить
				if ( Not(create) ) then
				begin
					obj := newDim As IFeature7;
					
					if ( obj <> nil ) then
						obj.Delete;
				end;
			end;
		end;
	end;
end;


//-------------------------------------------------------------------------------
// Выдать сообщение с параметрами линейного размера 3D
// ---
procedure GetLineDimensionPar( dim : ILineDimension3D );

var
  dimText : IDimensionText;
  lenght  : double;
  val     : double;
  mes     : WideString;
begin
	if ( dim <> nil ) then
	begin
		// Получить длину размера
		lenght := dim.Length;
		val := 0;

		// Получить значение размера
		dimText := dim As IDimensionText;

		if ( dimText <> nil ) then
			val := dimText.NominalValue;

		// Сформировать сообщение
    mes := LoadStr( IDS_LINEDIM3D );
    mes := mes + #13#10 + LoadStr( IDS_LENGTH ) + FormatFloat( '#.##', lenght );
    mes := mes + #13#10 + LoadStr( IDS_DIMVAL ) + FormatFloat( '#.##', val );
		ksMessageW( PWideChar(mes) );
	end;
end;


//-------------------------------------------------------------------------------
// Навигация по коллекции линейных размеров 3D
// ---
procedure LineDimension3DNavigation;

var
  symbCont  : ISymbols3DContainer;
  doc3D     : IDocument3D;
  selectMng : ISelectionMng;
  dimsCol   : ILineDimensions3D;
  lineDim   : ILineDimension3D;
  dimObj    : IEntity;
  i         : integer;
begin
	if ( doc <> nil ) then
	begin
		// Получить контейнер обозначений 3D
		symbCont := GetSymbols3DContainer;

		if ( symbCont <> nil ) then
		begin
			// Получить коллекцию линейных размеров 3D
			dimsCol := symbCont.LineDimensions3D;
			// Преобразовать интерфейс документа 3D из API7 в API5
			doc3D := IUnknown( ksTransferInterface(PIUnknown(doc), ksAPI3DCom, 0{любой документ}) ) As IDocument3D;

			if ( doc3D <> nil ) then
			begin
				// Получить менеджер селектирования
				selectMng := ISelectionMng( doc3D.GetSelectionMng );

				if ( (dimsCol <> nil) And (selectMng <> nil) ) then
				begin
					// Цикл по коллекции
					for i := 0 to dimsCol.Count-1 do
					begin
						// Получить размер из коллекции по индексу
						lineDim := dimsCol.LineDimension3D[i] As ILineDimension3D;

						if ( lineDim <> nil ) then
						begin
							// Преобразовать интерфейс объекта 3D из API7 в API5
              dimObj := IUnknown( ksTransferInterface(PIUnknown(lineDim), ksAPI3DCom, o3d_entity) ) As IEntity;

							if ( dimObj <> nil ) then
							begin
								// Подсветить объект
								selectMng.Select( dimObj );
								// Выдать сообщение с параметрами размера
								GetLineDimensionPar( lineDim );
								// Убрать подсветку
								selectMng.Unselect( dimObj );
							end;
						end;
					end;
				end;
			end;
		end;
	end;
end;


//-------------------------------------------------------------------------------
// Установить новую базовую плоскость
// ---
function SetNewPlane( dim : ILineDimension3D; doc3D : IDocument3D ) : boolean;

var
  obj1  : IEntity;
  plane : IModelObject;
  mes   : WideString;
begin
	Result := false;

	if ( (dim <> nil) And (doc3D <> nil) ) then
	begin
		oType := o3d_face;
    mes := LoadStr( IDS_NEWPLANE );
		// Указать в документе объект
    obj1 := IEntity( doc3D.UserSelectEntity(nil, @UserFilterProc, PWideChar(mes)) );

		if ( obj1 <> nil ) then
		begin
			// Преобразовать интерфейс объекта из API5 в API7
      plane := IUnknown( ksTransferInterface( PIUnknown(obj1), ksAPI7Dual, 0) ) As IModelObject;

			if ( plane <> nil ) then
			begin
				// Установить базовую плоскость
				dim.Plane := plane;
				Result := true;
        plane._Release;
			end;
      obj1._Release;
		end;
	end;
end;


//-------------------------------------------------------------------------------
// Изменить параметры линейного размера 3D
// ---
procedure ChangeLineDimensionPar( dim : ILineDimension3D );

var
  dimPars : IDimensionParams;
begin
	if ( dim <> nil ) then
	begin
		// Получить интерфейс параметров размера
		dimPars := dim As IDimensionParams;

		if ( dimPars <> nil ) then
		begin
			// Тип стрелок - засечка
			dimPars.ArrowType1 := ksNotch;
			dimPars.ArrowType2 := ksNotch;
			// Расположение стрелок - снаружи
			dimPars.ArrowPos := ksDimArrowOutside;
			// Направление полки - вправо
			dimPars.ShelfDirection := ksLSRight;
			// Длина полки
			dimPars.ShelfLength := 10;
			// Угол наклона полки
			dimPars.ShelfAngle := 45;
		end;
	end;
end;


//-------------------------------------------------------------------------------
// Редактирование линейного размера 3D
// ---
procedure EditLineDimension3D;

var
  doc3D   : IDocument3D;
  obj1    : IEntity;
  mObj1   : IModelObject;
  lineDim : ILineDimension3D;
  mes     : WideString;
begin
	if ( doc <> nil ) then
	begin
		// Преобразовать интерфейс документа 3D из API7 в API5
    doc3D := IUnknown( ksTransferInterface(PIUnknown(doc), ksAPI3DCom, 0{любой документ}) ) As IDocument3D;

		if ( doc3D <> nil ) then
		begin
			oType := o3d_entity;
      mes := LoadStr( IDS_DIM );
			// Указать в документе объект
      obj1 := IEntity( doc3D.UserSelectEntity(nil, nil, PWideChar(mes)) );

			if ( obj1 <> nil ) then
			begin
				// Преобразовать интерфейс объекта из API5 в API7
        mObj1 := IUnknown( ksTransferInterface( PIUnknown(obj1), ksAPI7Dual, 0) ) As IModelObject;

				if ( (mObj1 <> nil) And ( mObj1.ModelObjectType = o3d_lineDimension3D) ) then
				begin
					// Получить интерфейс линейного размера 3D
					lineDim := mObj1 As ILineDimension3D;

					if ( lineDim <> nil ) then
					begin
						// Установить новую базовую плоскость
						if ( Not(SetNewPlane(lineDim, doc3D)) ) then
            begin
							// Выдать сообщение "Не удалось установить новую базовую плоскость"
              mes := LoadStr( IDS_NOTSETPLANE );
							ksMessageW( PWideChar(mes) );
            end;

						// Изменить параметры размера
						ChangeLineDimensionPar( lineDim );
						// Уменьшить длину размера
						lineDim.Length := lineDim.Length - 10;
						// Применить изменения
						lineDim.Update;
					end;
          mObj1._Release;
				end
				else
        begin
					// Выдать сообщение "Объект не является линейным размером"
          mes := LoadStr( IDS_NOTDIM );
					ksMessageW( PWideChar(mes) );
        end;
        obj1._Release;
			end;
      doc3D._Release;
		end;
	end;
end;


//-------------------------------------------------------------------------------
// Создать радиальный размер 3D
// ---
function CreateRadDimension3D( dim : IRadialDimension3D ) : boolean;

var
  doc3D   : IDocument3D;
  edge    : IEntity;
  edgeDef : IEdgeDefinition;
  mObj1   : IModelObject;
  dimPars : IDimensionParams;
  mes     : WideString;
begin
	Result := false;

	if ( dim <> nil ) then
	begin
		// Преобразовать интерфейс документа 3D из API7 в API5
		doc3D := IUnknown( ksTransferInterface(PIUnknown(doc), ksAPI3DCom, 0{любой документ}) ) As IDocument3D;

		if ( doc3D <> nil ) then
		begin
			oType := o3d_edge;
      mes := LoadStr( IDS_OBJ1 );
			// Указать в документе объект - ребро
      edge := IEntity( doc3D.UserSelectEntity(nil, @UserFilterProc, PWideChar(mes)) );

			if ( edge <> nil ) then
			begin
				// Получить интерфейс свойств ребра
				edgeDef := IEdgeDefinition( edge.GetDefinition() );

				// Проверить, является ли ребро круговым
				if ( (edgeDef <> nil) And (edgeDef.IsCircle <> 0) ) then
				begin
					// Преобразовать интерфейс объекта из API5 в API7
          mObj1 := IUnknown( ksTransferInterface( PIUnknown(edge), ksAPI7Dual, 0) ) As IModelObject;

					if ( mObj1 <> nil ) then
						// Установить объект
						dim.Object1 := mObj1;

					// Получить интерфейс параметров объекта
					dimPars := dim As IDimensionParams;

					if ( dimPars <> nil ) then
					begin
						// Направление полки - влево
						dimPars.ShelfDirection := ksLSLeft;
						// Длина полки
						dimPars.ShelfLength := 15;
						// Угол наклона полки
						dimPars.ShelfAngle := 30;
					end;

					// Тип размера - не от центра
					dim.DimensionType := FALSE;
					// Применить параметры
					dim.Update;
					Result := true;
          edgeDef._Release;
				end
				else
        begin
					// Выдать сообщение "Ребро не является круговым"
          mes := LoadStr( IDS_NOTCIRCLE );
					ksMessageW( PWideChar(mes) );
        end;
        edge._Release;
			end;
      doc3D._Release;
		end;
	end;
end;


//-------------------------------------------------------------------------------
// Редактировать радиальный размер 3D
// ---
procedure EditRadDimension3D( dim : IRadialDimension3D );

var
  dimPars : IDimensionParams;
  dimText : IDimensionText;
  lowDev  : ITextLine;
begin
	if ( dim <> nil ) then
	begin
		// Тип размера - от центра
		dim.DimensionType := TRUE;

		// Получить интерфейс параметров размера
		dimPars := dim As IDimensionParams;

		if ( dimPars <> nil ) then
			// Отключить полку
			dimPars.ShelfDirection := ksLSNone;

		// Получить интерфейс текстов размера
		dimText := dim As IDimensionText;

		if ( dimText <> nil ) then
		begin
			// Задать квалитет
			dimText.Tolerance := 'h6';

			// Включить квалитет
			dimText.ToleranceOn := true;

			// Получить интерфейс текста нижнего отклонения
			lowDev := dimText.LowDeviation;

			// Задать текстовую строку
			if ( lowDev <> nil ) then
				lowDev.Str := '+0.021';
		end;
		// Применить изменения
		dim.Update;
	end;
end;


//-------------------------------------------------------------------------------
// Создание и редактирование радиального размера 3D
// ---
procedure RadialDimension3DWork;

var
  symbCont  : ISymbols3DContainer;
  dimsCol   : IRadialDimensions3D;
  newDim,
  radDim    : IRadialDimension3D;
  feature   : IFeature7;
  name,
  mes       : WideString;
begin
	// Получить контейнер обозначений 3D
	symbCont := GetSymbols3DContainer;

	if ( symbCont <> nil ) then
	begin
		// Получить коллекцию радиальных размеров 3D
		dimsCol := symbCont.RadialDimensions3D;

		if ( dimsCol <> nil ) then
		begin
			// Добавить новый радиальный размер 3D
			newDim := dimsCol.Add;

			if ( newDim <> nil ) then
			begin
				// Создать радиальный размер 3D
				if ( CreateRadDimension3D(newDim) ) then
				begin
					name := '';
					// Получить интерфейс объекта дерева построения
					feature := newDim As IFeature7;

					// Получить имя объекта
					if ( feature <> nil ) then
						name := feature.Name;

          mes := LoadStr( IDS_EDIT );
					if ( YesNoW(PWideChar(mes)) = 1 ) then
					begin
						// Получить объект из коллекции по имени
						radDim := dimsCol.RadialDimension3D[name];
						// Редактировать размер
						EditRadDimension3D( radDim );
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
// Создать димаметральный размер
// ---
function CreateDiamDimension3D( dim : IDiametralDimension3D ) : boolean;

var
  doc3D   : IDocument3D;
  edge    : IEntity;
  edgeDef : IEdgeDefinition;
  mObj1   : IModelObject;
  mes     : WideString;
begin
	Result := false;

	if ( dim <> nil ) then
	begin
		// Преобразовать интерфейс документа 3D из API7 в API5
		doc3D := IUnknown( ksTransferInterface(PIUnknown(doc), ksAPI3DCom, 0{любой документ}) ) As IDocument3D;

		if ( doc3D <> nil ) then
		begin
			oType := o3d_edge;
      mes := LoadStr( IDS_OBJ1 );
			// Указать в документе объект - ребро
      edge := IEntity( doc3D.UserSelectEntity(nil, @UserFilterProc, PWideChar(mes)) );

			if ( edge <> nil ) then
			begin
				// Получить интерфейс свойств ребра
				edgeDef := IEdgeDefinition( edge.GetDefinition() );

				// Проверить, является ли ребро круговым
				if ( (edgeDef <> nil) And (edgeDef.IsCircle <> 0) ) then
				begin
					// Преобразовать интерфейс объекта из API5 в API7
          mObj1 := IUnknown( ksTransferInterface( PIUnknown(edge), ksAPI7Dual, 0) ) As IModelObject;

					if ( mObj1 <> nil ) then
						// Установить объект
						dim.Object1 := mObj1;

					// Применить параметры
					dim.Update;
					Result := true;
          edgeDef._Release;
				end
				else
        begin
					// Выдать сообщение "Ребро не является круговым"
          mes := LoadStr( IDS_NOTCIRCLE );
					ksMessageW( PWideChar(mes) );
        end;
        edge._Release;
			end;
      doc3D._Release;
		end;
	end;
end;


//-------------------------------------------------------------------------------
// Редактировать диаметральный размер
// ---
procedure EditDiamDimension3D( dim : IDiametralDimension3D );

var
  dimText   : IDimensionText;
  txtUnder  : IText;
begin
	if ( dim <> nil ) then
	begin
		// Тип размера - с обрывом
		dim.DimensionType := True;

		// Получить интерфейс текстов размера
		dimText := dim As IDimensionText;

		if ( dimText <> nil ) then
		begin
			// Получить интерфейс текста под размерной надписью
			txtUnder := dimText.TextUnder;

			// Задать текстовую строку
			if ( txtUnder <> nil ) then
				txtUnder.Str := LoadStr( IDS_DIMTEXT );

			// Подчеркнутый текст
			dimText.Underline := TRUE;
		end;
		// Применить изменения
		dim.Update;
	end;
end;


//-------------------------------------------------------------------------------
// Создание и редактирование диаметрального размера 3D
// ---
procedure DiametralDimension3DWork;
var
  symbCont  : ISymbols3DContainer;
  dimsCol   : IDiametralDimensions3D;
  newDim,
  diamDim   : IDiametralDimension3D;
  feature   : IFeature7;
  name,
  mes       : WideString;
begin
	// Получить контейнер обозначений 3D
	symbCont := GetSymbols3DContainer;

	if ( symbCont <> nil ) then
	begin
		// Получить коллекцию диаметральных размеров 3D
		dimsCol := symbCont.DiametralDimensions3D;

		if ( dimsCol <> nil ) then
		begin
			// Добавить новый диаметральный размер 3D
			newDim := dimsCol.Add;

			if ( newDim <> nil ) then
			begin
				// Создать диаметральный размер 3D
				if ( CreateDiamDimension3D(newDim) ) then
				begin
					name := '';
					// Получить интерфейс объекта дерева построения
					feature := newDim As IFeature7;

					// Получить имя объекта
					if ( feature <> nil ) then
						name := feature.Name;

          mes := LoadStr( IDS_EDIT );
					if ( YesNoW(PWideChar(mes)) = 1 ) then
					begin
						// Получить объект из коллекции по имени
						diamDim := dimsCol.DiametralDimension3D[name];
						// Редактировать размер
						EditDiamDimension3D( diamDim );
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
// Создать угловой размер 3D
// ---
function CreateAngleDimension3D( dim : IAngleDimension3D ) : boolean;

var
  doc3D : IDocument3D;
  obj1,
  obj2  : IEntity;
  mObj1,
  mObj2 : IModelObject;
  mes   : WideString;
begin
	Result := False;

	if ( (dim <> nil) And (doc <> nil) ) then
	begin
		// Преобразовать интерфейс документа 3D из API7 в API5
    doc3D := IUnknown( ksTransferInterface(PIUnknown(doc), ksAPI3DCom, 0{любой документ}) ) As IDocument3D;

		if ( doc3D <> nil ) then
		begin
      mes := LoadStr( IDS_OBJECT1 );
			// Указать в документе 1-й объект
      obj1 := IEntity( doc3D.UserSelectEntity(nil, nil, PWideChar(mes)) );
      mes := LoadStr( IDS_OBJECT2 );
			// Указать в документе 2-й объект
      obj2 := IEntity( doc3D.UserSelectEntity(nil, nil, PWideChar(mes)) );

			if ( (obj1 <> nil) And (obj2 <> nil) ) then
			begin
				// Преобразовать интерфейсы объектов из API5 в API7
        mObj1 := IUnknown( ksTransferInterface( PIUnknown(obj1), ksAPI7Dual, 0) ) As IModelObject;
        mObj2 := IUnknown( ksTransferInterface( PIUnknown(obj2), ksAPI7Dual, 0) ) As IModelObject;

				if ( (mObj1 <> nil) And (mObj2 <> nil) ) then
				begin
					// 1-й объект
					dim.Object1 := mObj1;
					// 2-й объект
					dim.Object2 := mObj2;
					// Длина размерной линии
					dim.Length := 20;
					// Применить параметры
					dim.Update;
					Result := True;
				end;
			end;
		end;
	end;
end;


//-------------------------------------------------------------------------------
// Редактировать угловой размер 3D
// ---
procedure EditAngleDimension3D( dim : IAngleDimension3D );

var
  dimPars : IDimensionParams;
  dimText : IDimensionText;
begin
	if ( dim <> nil ) then
	begin
		// Тип размера - на максимальный (тупой) угол
		dim.DimensionType := ksADMaxAngle;
		// Увеличить длину размерной линии
		dim.Length := dim.Length + 10;

		// Получить интерфейс параметров размера
		dimPars := dim As IDimensionParams;

		if ( dimPars <> nil ) then
			// Размещение размерной надписи - параллельно, в разрезе линии
			dimPars.TextOnLine := ksDimTextParallelInCut;

		// Получить интерфейс текстов размера
		dimText := dim As IDimensionText;

		if ( dimText <> nil ) then
			// Изменить формат отображения текста на десятичный
			dimText.TextFormat := ksDimTextFormatGDD;

		// Применить изменения
		dim.Update;
	end;
end;


//-------------------------------------------------------------------------------
// Создание и редактирование углового размера 3D
// ---
procedure AngleDimension3DWork;
var
  symbCont  : ISymbols3DContainer;
  dimsCol   : IAngleDimensions3D;
  newDim,
  angDim    : IAngleDimension3D;
  feature   : IFeature7;
  name,
  mes       : WideString;
begin
	// Получить контейнер обозначений 3D
	symbCont := GetSymbols3DContainer;

	if ( symbCont <> nil ) then
	begin
		// Получить коллекцию угловых размеров 3D
		dimsCol := symbCont.AngleDimensions3D;

		if ( dimsCol <> nil ) then
		begin
			// Добавить новый угловой размер 3D
			newDim := dimsCol.Add;

			if ( newDim <> nil ) then
			begin
				// Создать угловой размер 3D
				if ( CreateAngleDimension3D(newDim) ) then
				begin
					name := '';
					// Получить интерфейс объекта дерева построения
					feature := newDim As IFeature7;

					// Получить имя объекта
					if ( feature <> nil ) then
						name := feature.Name;

          mes := LoadStr( IDS_EDIT );
					if ( YesNoW(PWideChar(mes)) = 1 ) then
					begin
						// Получить объект из коллекции по имени
						angDim := dimsCol.AngleDimension3D[name];
						// Редактировать размер
						EditAngleDimension3D( angDim );
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
  buf : array [0..255] of AnsiChar;
begin
  ksConvertLangStrEx( hInstance, ID, buf, 255 );
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


