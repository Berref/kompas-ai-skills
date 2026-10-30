////////////////////////////////////////////////////////////////////////////////
//
// Пример библиотеки построения обозначений СПДС
//
////////////////////////////////////////////////////////////////////////////////
unit Step3_API7_2D_1;

interface
uses
  Sysutils, LDefin2D, ksAuto, Libtool, Windows, ActiveX
{$IFDEF CONDITIONALEXPRESSIONS}
{$IF CompilerVersion >= 14 }
  , Variants
{$IFEND}
{$ENDIF CONDITIONALEXPRESSIONS}
  ;

////////////////////////////////////////////////////////////////////////////////

  procedure  LIBRARYENTRY( command: WORD  ); Pascal;
  function   LIBRARYID   : Cardinal;         Pascal;
  function   LoadStr( ID : Integer ) : string;                     // Загрузка строки из ресурсов
  function   LibMessage( str : string; flags : integer ) : Integer;// Выдача сообщения библиотеки
  function   LibMessageByID( strId, flags : Integer ) : Integer;   // Выдача сообщения библиотеки
  procedure  GetNewKompasAPI;
  procedure  LeaderWork;
  procedure  MarkLeaderWork;
  procedure  ChangeLeaderWork;
  procedure  BrandLeaderWork;
  procedure  RoughWork;
  procedure  BaseWork;
  procedure  CutLineWork;
  procedure  ViewPointerWork;
  procedure  ToleranceWork;
  procedure  ObjectsNavigation;

implementation

uses
  LtDefine,
  ksAPI7,
  ksConstTLB,
  forms;

const
  IDS_NODOC       = 200;
  IDS_EDIT        = 201;
  IDS_MARK        = 202;
  IDS_MARK2       = 203;
  IDS_MARK3       = 204;
  IDS_COMMAND1    = 205;
  IDS_COMMAND2    = 206;
  IDS_NOOBJ       = 207;
  IDS_NOPOINT     = 208;
  IDS_LEADER      = 209;
  IDS_POINT       = 210;
  IDS_ARROUND     = 211;
  IDS_ON          = 212;
  IDS_OFF         = 213;
  IDS_BRANCHBEGIN = 214;
  IDS_BEGINSHELF  = 215;
  IDS_ENDSHELF    = 216;
  IDS_PARALLEL    = 217;
  IDS_MARKLEADER  = 218;
  IDS_BRANCHCOUNT = 219;
  IDS_BRANDLEADER = 220;
  IDS_CHANLEADER  = 221;
  IDS_ROUGH       = 222;
  IDS_BASE        = 223;
  IDS_CUTLINE     = 224;
  IDS_VIEWPOINTER = 225;
  IDS_TOLERANCE   = 226;

var
  newKompasAPI : IApplication;                                // Компас Application 7
  doc : IKompasDocument2D;

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
function GetCurrentDocument : IKompasDocument2D;

var
  kDoc : IKompasDocument;
begin
  Result := nil;

  if ( newKompasAPI <> nil ) then
     // Получить активный документ
     kDoc := newKompasAPI.ActiveDocument;
  Result := kDoc As IKompasDocument2D;

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
      1   : LeaderWork;
      2   : MarkLeaderWork;
      3   : ChangeLeaderWork;
      4   : BrandLeaderWork;
      5   : RoughWork;
      6   : BaseWork;
      7   : CutLineWork;
      8   : ViewPointerWork;
      9   : ToleranceWork;
      10  : ObjectsNavigation;
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
//  Получить контейнер обозначений 2D
// ---
function GetSymbols2DContainer : ISymbols2DContainer;

var
  viewsMng  : IViewsAndLayersManager;
  views     : IViews;
  view      : IView;
begin
  Result := nil;

  if ( doc <> nil ) then
  begin
    // Получить менеджер для работы с видами и слоями
    viewsMng := doc.ViewsAndLayersManager;

    if ( viewsMng <> nil ) then
    begin
      // Получить коллекцию видов
      views := viewsMng.Views;

      if ( views <> nil ) then
      begin
        // Получить активный вид
        view := views.ActiveView;
        // Получить контейнер
        Result := view As ISymbols2DContainer;
      end;
    end
  end
end;


//-------------------------------------------------------------------------------
// Создание простой линии выноски
// ---
procedure CreateLeader( leader : ILeader );

var
  branchs     : IBranchs;
  baseLeader  : IBaseLeader;
  txtOnSh, txtUnderSh, txtOnBr, txtUnderBr, txtAfterSh  : IText;
begin
	if ( leader <> nil ) then
	begin
		// Направление полки - вправо
		leader.ShelfDirection := ksLSRight;

		// Получаем интерфейс ответвлений
		branchs := leader As IBranchs;

		if ( branchs <> nil ) then
		begin
			// Координаты начала полки или точка привязки
			branchs.X0 := 100;
			branchs.Y0 := 150;
			// Добавить прямолинейные ответвления
			branchs.AddBranchByPoint( -1, 60, 120 );
			branchs.AddBranchByPoint( -1, 65, 105 );
		end;

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

		baseLeader := leader As IBaseLeader;

		if ( baseLeader <> nil ) then
			// Применить параметры
			baseLeader.Update();
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
// Редактирование линии выноски
// ---
procedure EditLeader( leader : ILeader  );

var
  txt         : IText;
  branchs     : IBranchs;
  line        : ITextLine;
  baseLeader  : IBaseLeader;
begin
	if ( leader <> nil ) then
	begin
		// Тип значка - знак склеивания
		leader.SignType := ksLGlueSign;
		// Включить признак обоработки по контуру
		leader.Arround := true;

    // Получаем интерфейс ответвлений
		branchs := leader As IBranchs;
		
		if ( branchs <> nil ) then
			// Добавить прямолинейное ответвление
			branchs.AddBranchByPoint( -1, 140, 120 );

		// Начало созданного ответвления - от конца полки
		leader.BranchBegin[2] := false;

		// Получить текст над полкой
		txt := leader.TextOnShelf;

		if ( txt <> nil ) then
		begin
      txt.Str := '';
			line := txt.Add();

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

		baseLeader := leader As IBaseLeader;

		if ( baseLeader <> nil ) then
			// Применить параметры
			baseLeader.Update();
	end;
end;


//-------------------------------------------------------------------------------
// Создание и редактирование простой линии выноски
// ---
procedure LeaderWork;

var
  symbCont      : ISymbols2DContainer;
  leadersCol    : ILeaders;
  leader, lead  : ILeader;
  bLeader       : IBaseLeader;
  refr          : reference;
  mes           : WideString;
begin
	// Получить контейнер условных обозначений
	symbCont := GetSymbols2DContainer;

	if ( symbCont <> nil ) then
	begin
		// Получить коллекцию линий выноски
		leadersCol := symbCont.Leaders;

		if ( leadersCol <> nil ) then
		begin
			// Добавить простую линию выноски
			leader := leadersCol.Add( ksDrLeader ) As ILeader;

			if ( leader <> nil ) then
			begin
				// Создать линию выноски
				CreateLeader( leader );

				// Получить референс объекта
				bLeader := leader As IBaseLeader;
				refr := 0;

				if ( bLeader <> nil ) then
					refr := bLeader.Reference;

        // Подсветить созданный объект
				LightObj( refr, 1{включить подсветку} );
        mes := LoadStr( IDS_EDIT );

				if ( YesNoW(PWideChar(mes)) = 1 ) then
				begin
					// Получить объект из коллекции по референсу
					lead := leadersCol.Leader[ refr ] As ILeader;
					// Редактировать линию выноски
					EditLeader( lead );
				end;
        LightObj( refr, 0{выключить подсветку} );
			end;
		end;
	end;
end;


//-------------------------------------------------------------------------------
// Создание знака маркировки
// ---
procedure CreateMarkLeader( markLeader : IMarkLeader );

var
  branchs     : IBranchs;
  mes         : WideString;
  baseLeader  : IBaseLeader;
  des, textOnBranch, textUnderBranch : IText;
begin
	if ( markLeader <> nil ) then
	begin
		// Получить интерфейс ответвлений
		branchs := markLeader As IBranchs;

		if ( branchs <> nil ) then
		begin
			// Точка привязки 
			branchs.X0 := 100;
			branchs.Y0 := 190;
			// Добавить прямолинейное ответвление
			branchs.AddBranchByPoint( -1, 60, 120 );
		end;

		// Получить интерфейс текста обозначения
		des := markLeader.Designation;
    mes := LoadStr( IDS_MARK );

		if ( des <> nil ) then
			// Изменить текст
			des.Str := PWideChar( mes );

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

		// Получить базовый интерфейс линии выноски
		baseLeader := markLeader As IBaseLeader;

		if ( baseLeader <> nil ) then
			// Применить параметры
			baseLeader.Update;
	end;
end;


//-------------------------------------------------------------------------------
// Редактирование знака маркировки
// ---
procedure EditMarkLeader( markLeader : IMarkLeader );

var
  branchs     : IBranchs;
  baseLeader  : IBaseLeader;
begin
	if ( markLeader <> nil ) then
	begin
		// Получить интерфейс ответвлений
		branchs := markLeader As IBranchs;

		if ( branchs <> nil ) then
			// Добавить прямолинейное ответвление
			branchs.AddBranchByPoint( -1, 70, 110 );

		// Получить базовый интерфейс линии выноски
		baseLeader := markLeader As IBaseLeader;

		if ( baseLeader <> nil ) then
		begin
			// Тип стрелки
			baseLeader.ArrowType := ksLeaderArrow;
			// Применить изменения
			baseLeader.Update();
		end;
	end;
end;


//-------------------------------------------------------------------------------
// Создание и редактирование знака маркировки
// ---
procedure MarkLeaderWork;

var
  symbCont          : ISymbols2DContainer;
  leadersCol        : ILeaders;
  mLeader, markLead : IMarkLeader;
  bLeader           : IBaseLeader;
  refr              : reference;
  mes               : WideString;
begin
	// Получить контейнер условных обозначений
	symbCont := GetSymbols2DContainer;
	
	if ( symbCont <> nil ) then
	begin
		// Получить коллекцию линий выноски
		leadersCol := symbCont.Leaders;

		if ( leadersCol <> nil ) then
		begin
			// Добавить знак маркировки
			mLeader := leadersCol.Add( ksDrMarkerLeader ) As IMarkLeader;
			
			if ( mLeader <> nil ) then
			begin
				// Создать знак маркировки
				CreateMarkLeader( mLeader );
				
				// Получить референс объекта
				bLeader := mLeader As IBaseLeader;
				refr := 0;

				if ( bLeader <> nil ) then
					refr := bLeader.Reference;

        // Подсветить созданный объект
				LightObj( refr, 1{включить подсветку} );
        mes := LoadStr( IDS_EDIT );

				if ( YesNoW(PWideChar(mes)) = 1 ) then
				begin
					// Получить объект из коллекции по референсу
					markLead := leadersCol.Leader[refr] As IMarkLeader;
					// Редактировать знак маркировки
					EditMarkLeader( markLead );
				end;

        LightObj( refr, 0{выключить подсветку} )
			end;
		end;
	end;
end;


//-------------------------------------------------------------------------------
// Создание знака изменения
// ---
procedure CreateChangeLeader( changeLeader : IChangeLeader );

var
  branchs     : IBranchs;
  des         : IText;
  baseLeader  : IBaseLeader;
begin
	if ( changeLeader <> nil ) then
	begin
		// Тип значка - квадрат
		changeLeader.SignType := ksCLSSquare;

		// Получить интерфейс ответвлений
		branchs := changeLeader As IBranchs;

		if ( branchs <> nil ) then
		begin
			// Точка привязки
			branchs.X0 := 70;
			branchs.Y0 := 150;
			// Добавить ответвление
			branchs.AddBranchByPoint( -1, 40, 130 );
		end;

		// Получить интерфейс текста обозначения
		des := changeLeader.Designation;
		
		if ( des <> nil ) then
			// Изменить текст
			des.Str := '1';

		// Получить базовый интерфейс линии выноски
		baseLeader := changeLeader As IBaseLeader;

		if ( baseLeader <> nil ) then
			// Применить параметры
			baseLeader.Update;
	end;
end;


//-------------------------------------------------------------------------------
// Редактирование знака изменения
// ---
procedure EditChangeLeader( changeLeader : IChangeLeader );

var
  baseLeader  : IBaseLeader;
begin
	if ( changeLeader <> nil ) then
	begin
		// Тип значка - круг
		changeLeader.SignType := ksCLSCircle;
		// Полная длина выноски отключена
		changeLeader.FullLeaderLength := false;
		// Длина выноски
		changeLeader.LeaderLength := 5;

		// Получить базовый интерфейс линии выноски
		baseLeader := changeLeader As IBaseLeader;
		
		if ( baseLeader <> nil ) then
			// Применить изменения
			baseLeader.Update;
	end;
end;


//-------------------------------------------------------------------------------
// Создание и редактирование знака изменения
// ---
procedure ChangeLeaderWork;

var
  symbCont              : ISymbols2DContainer;
  leadersCol            : ILeaders;
  chLeader, changeLead  : IChangeLeader;
  bLeader               : IBaseLeader;
  refr                  : reference;
  mes                   : WideString;
begin
	// Получить контейнер условных обозначений
	symbCont := GetSymbols2DContainer;
	
	if ( symbCont <> nil ) then
	begin
		// Получить коллекцию линий выноски
		leadersCol := symbCont.Leaders;;
		
		if ( leadersCol <> nil ) then
		begin
			// Добавить знак изменения
			chLeader := leadersCol.Add( ksDrChangeLeader ) As IChangeLeader;
			
			if ( chLeader <> nil ) then
			begin
				// Создать знак изменения
				CreateChangeLeader( chLeader );
				
				// Получить референс объекта
				bLeader := chLeader As IBaseLeader;
				refr := 0;

				if ( bLeader <> nil ) then
					refr := bLeader.Reference;

        // Подсветить созданный объект
				LightObj( refr, 1{включить подсветку} );
				mes := LoadStr(IDS_EDIT);

        if ( YesNoW(PWideChar(mes)) = 1 ) then
				begin
					// Получить объект из коллекции по референсу
					changeLead := leadersCol.Leader[refr] As IChangeLeader;
					// Редактировать знак изменения
					EditChangeLeader( changeLead );
				end;

        LightObj( refr, 0{выключить подсветку} );
			end;
		end;
	end;
end;


//-------------------------------------------------------------------------------
// Создание знака клеймения
// ---
procedure CreateBrandLeader( brandLeader : IBrandLeader );

var
  des         : IText;
  mes         : WideString;
  branchs     : IBranchs;
  baseLeader  : IBaseLeader;
begin
	if ( brandLeader <> nil ) then
	begin
		// Направление
		brandLeader.Direction := FALSE;

		// Получить интерфейс текста обозначения
		des := brandLeader.Designation;
    mes := LoadStr( IDS_MARK2 );

		if ( des <> nil ) then
			// Изменить текст
			des.Str := PWideChar( mes );

		// Получить интерфейс ответвлений
		branchs := brandLeader As IBranchs;

		if ( branchs <> nil ) then
		begin
			// Точка привязки
			branchs.X0 := 100;
			branchs.Y0 := 150;
			// Добавить ответвление
			branchs.AddBranchByPoint( -1, 60, 110 );
		end;

		// Получить базовый интерфейс линии выноски
		baseLeader := brandLeader As IBaseLeader;

		if ( baseLeader <> nil ) then
			// Применить параметры
			baseLeader.Update;
	end;
end;


//-------------------------------------------------------------------------------
// Редактирование знака изменения
// ---
procedure EditBrandLeader( brandLeader : IBrandLeader );

var
  mes         : WideString;
  baseLeader  : IBaseLeader;
  textOn, textUnder, des : IText;
begin
	if ( brandLeader <> nil ) then
	begin
		// Направление
		brandLeader.Direction := true;

		// Получить интерфейс текста над ножкой
		textOn := brandLeader.TextOnBranch;

		if ( textOn <> nil ) then
			// Изменить текст
			textOn.Str := '2';
		
		// Получить интерфейс текста под ножкой
		textUnder := brandLeader.TextUnderBranch;

		if ( textUnder <> nil ) then
			// Изменить текст
			textUnder.Str := '3';

		// Получить интерфейс текста обозначения
		des := brandLeader.Designation;
    mes := LoadStr( IDS_MARK3 );

		if ( des <> nil ) then
			// Изменить текст
			des.Str := PWideChar( mes );

		// Получить базовый интерфейс линии выноски
		baseLeader := brandLeader As IBaseLeader;

		if ( baseLeader <> nil ) then
			// Применить параметры
			baseLeader.Update;
	end;
end;


//-------------------------------------------------------------------------------
// Создание и редактирование знака клеймения
// ---
procedure BrandLeaderWork;

var
  symbCont              : ISymbols2DContainer;
  leadersCol            : ILeaders;
  brLeader, brandLead   : IBrandLeader;
  bLeader               : IBaseLeader;
  refObj                : reference;
  mes                   : WideString;
begin
	// Получить контейнер условных обозначений
	symbCont := GetSymbols2DContainer;
	
	if ( symbCont <> nil ) then
	begin
		// Получить коллекцию линий выноски
		leadersCol := symbCont.Leaders;
		
		if ( leadersCol <> nil ) then
		begin
			// Добавить знак клеймения
			brLeader := leadersCol.Add( ksDrBrandLeader ) As IBrandLeader;
			
			if ( brLeader <> nil ) then
			begin
				// Создать знак клеймения
				CreateBrandLeader( brLeader );
				
				// Получить референс объекта
				bLeader := brLeader As IBaseLeader;
				refObj := 0;

				if ( bLeader <> nil ) then
					refObj := bLeader.Reference;

        // Подсветить созданный объект
				LightObj( refObj, 1{включить подсветку} );
				mes := LoadStr(IDS_EDIT);

        if ( YesNoW(PWideChar(mes)) = 1 ) then
				begin
					// Получить объект из коллекции по референсу
					brandLead := leadersCol.Leader[refObj] As IBrandLeader;
					// Редактировать знак клеймения
					EditBrandLeader( brandLead );
				end;

        LightObj( refObj, 0{выключить подсветку} );
			end;
		end;
	end;
end;


//-------------------------------------------------------------------------------
// Создание обозначения шероховатости
// ---
function CreateRough( rough : IRough ) : boolean;

var
  info      : RequestInfoW;
  sOpt      : SnapOptions;
  x, y      : double;
  pObj      : reference;
  baseObj   : IDrawingObject;
  roughPar  : IRoughParams;
  mes       : WideString;
  txt1, txt2, txt3 : IText;
begin
  Result := false;

	if ( rough <> nil ) then
	begin
		// Обнулить структуру параметров запроса к системе
    FillChar( info, SizeOf(info), 0 );
    // Строка состава команд
    mes := LoadStr( IDS_COMMAND1 );
    info.commands := PWideChar( mes );
    info.cursor := PWideChar( OCR_CATCH );

    // Отключить привязки
		ksGetSysOptions( SNAP_OPTIONS, @sOpt, SizeOf(sOpt) );
		sOpt.commonOpt := 0;
		ksSetSysOptions( SNAP_OPTIONS, @sOpt, SizeOf(sOpt) );

		// Указать базовый объект
		if ( ksCursorExW(@info, x, y, nil, nil) <> 0 ) then
		begin
			// Найти объект по указанным координатам
			pObj := FindObj( x, y, ksGetCursorLimit() );
      // Подсветить объект
			LightObj( pObj, 1{включить подсветку} );
			// Получить интерфейс графического объекта из референса
      baseObj := IUnknown(ksTransferReference( pObj, ksGetCurrentDocument(0{любой документ}))) As IDrawingObject;
			mes := LoadStr( IDS_COMMAND2 );
      info.commands := PWideChar( mes );
      info.cursor := PWideChar( OCR_SELECT );

      // Если привязки выключены, включить
		  if ( sOpt.commonOpt = 0 ) then
	  	begin
			  sOpt.commonOpt := 1;
			  ksSetSysOptions( SNAP_OPTIONS, @sOpt, SizeOf(sOpt) );
		  end;

			// Указать точку привязки
			if ( ksCursorExW(@info, x, y, nil, nil) <> 0 ) then
			begin
				if ( baseObj <> nil ) then
					// Базовый объект
					rough.BaseObject := baseObj;
				// Точка привязки
				rough.BranchX0 := x;
				rough.BranchY0 := y;

				roughPar := rough As IRoughParams;

				if ( roughPar <> nil ) then
				begin
					roughPar.ShelfDirection := ksLSRight;
					rough.Update;
					// Обработка по контуру включена
					roughPar.ProcessingByContour := true;
					// Длина линии выноски
					roughPar.LeaderLength := 20;
					// Угол наклона линии выноски
					roughPar.LeaderAngle := 45;

					// Получить интерфейс текста параметров шероховатости
					txt1 := roughPar.RoughParamText;

					if ( txt1 <> nil ) then
						txt1.Str := '1';
					
					// Получить интерфейс текста способа обработки поверхности
					txt2 := roughPar.ProcessText;
					
					if ( txt2 <> nil ) then
						txt2.Str := '2';

					// Получить интерфейс текста базовой длины
					txt3 := roughPar.TrendText;
					
					if ( txt3 <> nil ) then
						txt3.Str := '3';
				end;

				// Применить параметры
				rough.Update;
        Result := true;
			end

			else
      begin
        mes := LoadStr( IDS_NOPOINT );
        ksMessageW( PWideChar(mes) );
      end;

      LightObj( pObj, 0{выключить подсветку} );
     end

		else
    begin
      mes := LoadStr( IDS_NOOBJ );
      ksMessageW( PWideChar(mes) );
    end;

    // Если привязки выключены, включить
    if ( sOpt.commonOpt = 0 ) then
    begin
      sOpt.commonOpt := 1;
      ksSetSysOptions( SNAP_OPTIONS, @sOpt, SizeOf(sOpt) );
    end;
	end;
end;


//-------------------------------------------------------------------------------
// Редактирование обозначения шероховатости
// ---
procedure EditRough( rough : IRough );

var
  roughPar : IRoughParams;
begin
	if ( rough <> nil ) then
	begin
		// Получить интерфейс параметров шероховатости
		roughPar := rough As IRoughParams;

		if ( roughPar <> nil ) then
		begin
			// Убрать стрелку
			roughPar.ArrowType := ksWithoutArrow;
			// Обработка по контуру отключена
			roughPar.ProcessingByContour := false;
		end;
		// Применить изменения
		rough.Update();
	end;
end;


//-------------------------------------------------------------------------------
// Создание и редактирование обозначения шероховатости
// ---
procedure RoughWork;

var
  symbCont              : ISymbols2DContainer;
  roughsCol             : IRoughs;
  newRough, rough       : IRough;
  objRef                : reference;
  mes                   : WideString;
begin
	// Получить контейнер условных обозначений
	symbCont := GetSymbols2DContainer;
	
	if ( symbCont <> nil ) then
	begin
		// Получить коллекцию обозначений шероховатости
		roughsCol := symbCont.Roughs;
		
		if ( roughsCol <> nil ) then
		begin
			// Добавить обозначение шероховатости
			newRough := roughsCol.Add();

			if ( newRough <> nil ) then
			begin
				// Создать обозначение шероховатости
				if ( CreateRough(newRough) )then
				begin
				  // Получить референс объекта
				  objRef := newRough.Reference;

          // Подсветить созданный объект
					LightObj( objRef, 1{включить подсветку} );
				  mes := LoadStr(IDS_EDIT);

          if ( YesNoW(PWideChar(mes)) = 1 ) then
				  begin
					  // Получить объект из коллекции по референсу
					  rough := roughsCol.Rough[objRef];
					  // Редактировать обозначение шероховатости
					  EditRough( rough );
				  end;

          LightObj( objRef, 0{выключить подсветку} );
        end;
			end;
		end;
	end;
end;


//-------------------------------------------------------------------------------
// Создание обозначения базы
// ---
function CreateBase( base : IBase ) : boolean;

var
  info      : RequestInfoW;
  sOpt      : SnapOptions;
  x, y      : double;
  pObj      : reference;
  baseObj   : IDrawingObject;
  mes       : WideString;
begin
  Result := false;
	if ( base <> nil ) then
	begin
		// Обнулить структуру параметров запроса к системе
    FillChar( info, SizeOf(info), 0 );
    // Строка состава команд
    mes := LoadStr( IDS_COMMAND1 );
    info.commands := PWideChar( mes );
    info.cursor := PWideChar( OCR_CATCH );

    // Отключить привязки
		ksGetSysOptions( SNAP_OPTIONS, @sOpt, SizeOf(sOpt) );
		sOpt.commonOpt := 0;
		ksSetSysOptions( SNAP_OPTIONS, @sOpt, SizeOf(sOpt) );
		
		// Указать базовый объект
		if ( ksCursorExW(@info, x, y, nil, nil) <> 0 ) then
		begin
			// Найти объект по указанным координатам
			pObj := FindObj( x, y, ksGetCursorLimit() );
      // Подсветить объект
			LightObj( pObj, 1{включить подсветку} );
			// Получить интерфейс графического объекта из референса
      baseObj := IUnknown(ksTransferReference( pObj, ksGetCurrentDocument(0{любой документ}))) As IDrawingObject;
			// Строка состава команд
      mes := LoadStr( IDS_COMMAND2 );
      info.commands := PWideChar( mes );
      info.cursor := PWideChar( OCR_SELECT );

      // Если привязки выключены, включить
		  if ( sOpt.commonOpt = 0 ) then
	  	begin
			  sOpt.commonOpt := 1;
			  ksSetSysOptions( SNAP_OPTIONS, @sOpt, SizeOf(sOpt) );
		  end;

			// Указать положение знака
			if ( ksCursorExW(@info, x, y, nil, nil) <> 0 ) then
			begin

				if ( baseObj <> nil ) then
					// Базовый объект
					base.BaseObject := baseObj;

				// Точка положения знака
				base.X0 := x;
				base.Y0 := y;
				// Способ отрисовки - перпендикулярно к объекту
				base.DrawType := true;
				// Применить параметры
				base.Update;
        Result := true;
			end

			else
      begin
        mes := LoadStr( IDS_NOPOINT );
        ksMessageW( PWideChar(mes) );
      end;

      LightObj( pObj, 0{выключить подсветку} );
		end

		else
    begin
      mes := LoadStr( IDS_NOOBJ );
      ksMessageW( PWideChar(mes) );
    end;

    // Если привязки выключены, включить
    if ( sOpt.commonOpt = 0 ) then
    begin
      sOpt.commonOpt := 1;
			ksSetSysOptions( SNAP_OPTIONS, @sOpt, SizeOf(sOpt) );
    end;
  end;
end;


//-------------------------------------------------------------------------------
// Редактирование обозначения базы
// ---
procedure EditBase( base : IBase );

var
  txt : IText;
begin
	if ( base <> nil ) then
	begin
		// Тип отрисовки - произвольно
		base.DrawType := false;
		// Отключить автосортировку
		base.AutoSorted := false;
		// Конечная точка выноски
		base.BranchX := base.X0 + 10;
		base.BranchY := base.Y0 + 10;

		// Получить интерфейс текста обозначения базы
		txt := base.Text;

		if ( txt <> nil ) then
			// Изменить текст
			txt.Str := 'B';

		// Применить параметры
		base.Update;
	end;
end;


//-------------------------------------------------------------------------------
// Создание и редактирование обозначения базы
// ---
procedure BaseWork;

var
  symbCont      : ISymbols2DContainer;
  basesCol      : IBases;
  newBase, base : IBase;
  objRef        : reference;
  mes           : WideString;
begin
	// Получить контейнер условных обозначений
	symbCont := GetSymbols2DContainer;

	if ( symbCont <> nil ) then
	begin
		// Получить коллекцию обозначений базы
		basesCol := symbCont.Bases;
		
		if ( basesCol <> nil ) then
		begin
			// Добавить обозначение базы
			newBase := basesCol.Add;
			
			if ( newBase <> nil ) then
			begin
				// Создать обозначение базы
				if ( CreateBase(newBase) ) then
				begin
				  // Получить референс объекта
				  objRef := newBase.Reference;

          // Подсветить созданный объект
					LightObj( objRef, 1{включить подсветку} );
				  mes := LoadStr(IDS_EDIT);

          if ( YesNoW(PWideChar(mes)) = 1 ) then
				  begin
					  // Получить объект из коллекции по референсу
					  base:= basesCol.Base[objRef];
					  // Редактировать обозначение базы
					  EditBase( base );
				  end;

          LightObj( objRef, 0{выключить подсветку} );
        end;
			end;
		end;
	end;
end;


//-------------------------------------------------------------------------------
// Создать текст с заданным размером шрифта
// ---
procedure SetTextSmallFont( txt : IText; str : WideString; size : double  );

var
  line  : ITextLine;
  item  : ITextItem;
  font  : ITextFont;
begin
	if ( txt <> nil ) then
	begin
		// Получить интерфейс строки текста
		line := txt.Add;

		if ( line <> nil ) then
		begin
			// Получить интерфейс компоненты текста
			item := line.Add;

			if ( item <> nil ) then
			begin
				// Получить интерфейс шрифта
				font := item As ITextFont;

				if ( font <> nil ) then
					// Задать высоту шрифта
					font.Height := size;

				// Задать значение строки
				item.Str := str;
				// Применить параметры
				item.Update();
			end;
		end;
	end;
end;


//-------------------------------------------------------------------------------
// Создать массив SAFEARRAY типа double
// ---
function NewSafeArray( dv : array of double; count : integer ) : OleVariant;

var
  res : OleVariant;
  i   : integer;
begin
  res := VarArrayCreate( [0, count-1], varDouble );

  for i := 0 to count - 1 do
    res[i] := dv[i];

  Result := res;
end;


//-------------------------------------------------------------------------------
// Создание линии разреза/сечения
// ---
procedure CreateCutLine( cutLine : ICutLine );

var
  adText : IText;
  points : array [0..3] of double;
begin
	if ( cutLine <> nil ) then
	begin
		// Координаты начального текста
		cutLine.X1 := 80;
		cutLine.Y1 := 165;
		// Координаты конечного текста
		cutLine.X2 := 120;
		cutLine.Y2 := 200;
		// Расположение стрелок - слева
		cutLine.ArrowPos := true;
		// Размещение дополнительного текста - у первой стрелки
		cutLine.AdditionalTextPos := true;

		// Создать массив точек линии разреза
		points[0] := 80;
		points[1] := 165;
		points[2] := 120;
		points[3] := 200;

		// Задать массив точек линии разреза
    cutLine.Points := NewSafeArray(points, 4 );

		// Получить интерфейс дополнительного текста
		adText := cutLine.AdditionalText;
		
		if ( adText <> nil ) then
			SetTextSmallFont( adText, '(1)', 7 );

		// Применить параметры
		cutLine.Update();
	end;
end;


//-------------------------------------------------------------------------------
// Редактирование линии разреза/сечения
// ---
procedure EditCutLine( cutLine : ICutLine );

var
  points : array [0..5] of double;
begin
	if ( cutLine <> nil ) then
	begin
		// Расположение стрелок - справа по направлению ломаной
		cutLine.ArrowPos := false;
		// Расположение дополнительного текста - у второй стрелки
		cutLine.AdditionalTextPos := false;
		// Отключить автосортировку
		cutLine.AutoSorted := false;

		// Создать массив точек линии разреза
		points[0] := 80;
		points[1] := 165;
		points[2] := 115;
		points[3] := 165;
		points[4] := 120;
		points[5] := 200;

    // Задать массив точек линии разреза
		cutLine.Points := NewSafeArray(points, 6 );

		// Применить изменения
		cutLine.Update();
	end;
end;


//-------------------------------------------------------------------------------
// Создание и редактирование линии разреза/сечения
// ---
procedure CutLineWork;

var
  symbCont        : ISymbols2DContainer;
  cutCol          : ICutLines;
  newCut, cutLine : ICutLine;
  objRef          : reference;
  mes             : WideString;
begin
	// Получить контейнер условных обозначений
	symbCont := GetSymbols2DContainer;
	
	if ( symbCont <> nil ) then
	begin
		// Получить коллекцию линий разреза/сечения
		cutCol := symbCont.CutLines;
		
		if ( cutCol <> nil ) then
		begin
			// Добавить линию разреза/сечения
			newCut := cutCol.Add;
			
			if ( newCut <> nil ) then
			begin
				// Создать линию разреза/сечения
				CreateCutLine( newCut );

				// Получить референс объекта
				objRef := newCut.Reference;

        // Подсветить созданный объект
        LightObj( objRef, 1{включить подсветку} );
				mes := LoadStr(IDS_EDIT);

        if ( YesNoW(PWideChar(mes)) = 1 ) then
				begin
					// Получить объект из коллекции по референсу
					cutLine := cutCol.CutLine[objRef];
					// Редактировать линию разреза/сечения
					EditCutLine( cutLine );
				end;

        LightObj( objRef, 0{выключить подсветку} );
			end;
		end;
	end;
end;


//-------------------------------------------------------------------------------
// Создание стрелки направления взгляда
// ---
procedure CreateViewPointer( viewPointer : IViewPointer );
begin
	if ( viewPointer <> nil ) then
	begin
		// Начальная точка стрелки
		viewPointer.X1 := 100;
		viewPointer.Y1 := 150;
		// Конечная точка стрелки
		viewPointer.X2 := 120;
		viewPointer.Y2 := 160;
		// Применить параметры
		viewPointer.Update();
	end;
end;


//-------------------------------------------------------------------------------
// Редактирование стрелки направления взгляда
// ---
procedure EditViewPointer( viewPointer : IViewPointer );

var
  adText : IText;
begin
	if ( viewPointer <> nil ) then
	begin
		// Конечная точка стрелки
		viewPointer.X2 := 90;
		viewPointer.Y2 := 140;
		// Включить автосортировку
		viewPointer.AutoSorted := true;

		// Получить интерфейс текста обозначения направления взгляда
		adText := viewPointer.AdditionalText;
		
		if ( adText <> nil ) then
			// Изменить текст
			SetTextSmallFont( adText, '(1)', 7 );
		
		// Применить параметры
		viewPointer.Update;
	end;
end;


//-------------------------------------------------------------------------------
// Создание и редактирование стрелки направления взгляда
// ---
procedure ViewPointerWork;

var
  symbCont                : ISymbols2DContainer;
  viewPointsCol           : IViewPointers;
  newPointer, viewPointer : IViewPointer;
  objRef                  : reference;
  mes                     : WideString;
begin
	// Получить контейнер условных обозначений
	symbCont := GetSymbols2DContainer;
	
	if ( symbCont <> nil ) then
	begin
		// Получить коллекцию стрелок направления взгляда
		viewPointsCol := symbCont.ViewPointers;

		if ( viewPointsCol <> nil ) then
		begin
			// Добавить стрелку направления взгляда
			newPointer := viewPointsCol.Add;
			
			if ( newPointer <> nil ) then
			begin
				// Создать стрелку направления взгляда
				CreateViewPointer( newPointer );

				// Получить референс объекта
				objRef := newPointer.Reference;

				// Подсветить созданный объект
        LightObj( objRef, 1{включить подсветку} );
				mes := LoadStr(IDS_EDIT);

        if ( YesNoW(PWideChar(mes)) = 1 ) then
				begin
					// Получить объект из коллекции по референсу
					viewPointer := viewPointsCol.ViewPointer[objRef];
					// Редактировать стрелку направления взгляда
					EditViewPointer( viewPointer );
				end;

        LightObj( objRef, 0{выключить подсветку} );
			end;
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
// Создание допуска формы
// ---
procedure CreateTolerance( tolerance : ITolerance );

var
  branchs : IBranchs;
  tolPar  : IToleranceParam;
begin
	if ( tolerance <> nil ) then
	begin
		// Получить интерфейс ответвления
		branchs := tolerance As IBranchs;

		if ( branchs <> nil ) then
		begin
			// Задать точку привязки
			branchs.X0 := 100;
			branchs.Y0 := 150;
			// Добавить 2 ответвления
			branchs.AddBranchByPoint( -1, 100, 120 );
			branchs.AddBranchByPoint( -1, 50, 155 );
		end;

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
		tolerance.Set_ArrowType( 0, FALSE );
		// Положение 1-го ответвления относительно таблицы - внизу посередине
		tolerance.Set_BranchPos( 0, ksTPBottomCenter );
		// Тип стрелки 2-го ответвления - стрелка
		tolerance.Set_ArrowType( 1, TRUE );
		// Положение 2-го ответвления относительно таблицы - слева посередине
		tolerance.Set_BranchPos( 1, ksTPLeftCenter );
		// Применить параметры
		tolerance.Update();
	end;
end;


//-------------------------------------------------------------------------------
// Редактирование допуска формы
// ---
procedure EditTolerance( tolerance : ITolerance );

var
  tolPar    : IToleranceParam;
  tolTable  : ITable;
  txt       : ITextLine;
  branchs   : IBranchs;
  cell      : ITableCell;
begin
	if ( tolerance <> nil ) then
	begin
		// Получитьинтерфейс параметров допуска формы
		tolPar := tolerance As IToleranceParam;

		if ( tolPar <> nil ) then
		begin
			// Получить интерфейс таблицы с текстом допуска формы
			tolTable := tolPar.Table;
			
			if ( tolTable <> nil ) then
			begin
				// Изменить текст во 2-й ячейке
				cell := tolTable.Cell[ 0, 1 ];

				if ( cell <> nil ) then
				begin
					txt := cell.Text As ITextLine;

					if ( txt <> nil ) then
						txt.Str := '@2~15';
				end;
			end;
			// Задать признак вертикальности
			tolPar.Vertical := true;
		end;

		// Получить интерфейс ответвлений
	  branchs := tolerance As IBranchs;

		if ( branchs <> nil ) then
		begin
			// Удалить ответвление
			branchs.DeleteBranch( 0 );
			// Добавить новое ответвление
			branchs.AddBranchByPoint( -1, 130, 120 );
		end;

		tolerance.Set_ArrowType( 1, FALSE );
		tolerance.Set_BranchPos( 1, ksTPBottomCenter );
		// Применить изменения
		tolerance.Update();
	end;
end;


//-------------------------------------------------------------------------------
// Создание и редактирование допуска формы
// ---
procedure ToleranceWork;

var
  symbCont          : ISymbols2DContainer;
  tolerancesCol     : ITolerances;
  newTol, tolerance : ITolerance;
  objRef            : reference;
  mes               : WideString;
begin
	// Получить контейнер условных обозначений
	symbCont := GetSymbols2DContainer;

	if ( symbCont <> nil ) then
	begin
		// Получить коллекцию допусков формы
		tolerancesCol := symbCont.Tolerances;
		
		if ( tolerancesCol <> nil ) then
		begin
			// Добавить допуск формы
			newTol := tolerancesCol.Add;

			if ( newTol <> nil ) then
			begin
				// Создать допуск формы
				CreateTolerance( newTol );
				
				// Получить референс объекта
				objRef := newTol.Reference;

				// Подсветить созданный объект
        LightObj( objRef, 1{включить подсветку} );
				mes := LoadStr(IDS_EDIT);

        if ( YesNoW(PWideChar(mes)) = 1 ) then
				begin
					// Получить объект из коллекции по референсу
					tolerance := tolerancesCol.Tolerance[objRef];
					// Редактировать допуск формы
					EditTolerance( tolerance );
				end;

        LightObj( objRef, 0{выключить подсветку} );
			end;
		end;
	end;
end;


//-------------------------------------------------------------------------------
// Получить контейнер графических объектов
// ---
function GetDrawingContainer : IDrawingContainer;

var
  mng       : IViewsAndLayersManager;
  viewsCol  : IViews;
  view      : IView;
begin
	if ( doc <> nil ) then
	begin
    Result := nil;
		// Получить менеджер видов и слоев
		mng := doc.ViewsAndLayersManager;

		if ( mng <> nil ) then
		begin
			// Получить коллекцию видов
			viewsCol := mng.Views;

			if ( viewsCol <> nil ) then
			begin
				// Получить активный вид
				view := viewsCol.ActiveView;

				if ( view <> nil ) then
          Result := view As IDrawingContainer;
			end;
		end;
	end;
end;


//-------------------------------------------------------------------------------
// Выдать сообщение с параметрами простой линии выноски
// ---
procedure GetLeaderPar( leader : ILeader );

var
  x0, y0  : double;
  branchs : IBranchs;
  mes     : WideString;
begin
	if ( leader <> nil ) then
	begin
    x0 := 0;
    y0 := 0;
		// Получить координаты точки привязки
		branchs := leader As IBranchs;

		if ( branchs <> nil ) then
		begin
			x0 := branchs.X0;
			y0 := branchs.Y0;
		end;

		// Сформировать сообщение для выдачи
		// "Простая линия выноски"
    mes := LoadStr( IDS_LEADER );
		// "Точка привязки: X0 = , Y0 = "
    mes := mes + #13#10 + LoadStr( IDS_POINT ) + #13#10 + 'X0 = ' + FormatFloat( '#.##', x0 ) + ', Y0 = ' + FormatFloat( '#.##', y0 );
		// "Признак обработки по контуру: "
    mes := mes + #13#10 + LoadStr( IDS_ARROUND );

		if ( leader.Arround ) then
			// "включен"
			mes := mes + LoadStr( IDS_ON )
		else
			// "отключен"
			mes := mes + LoadStr( IDS_OFF );

		// "Начало ответвления: "
		mes := mes + #13#10 + LoadStr( IDS_BRANCHBEGIN );

		if ( leader.BranchBegin[0] ) then
			// "от начала полки"
			mes := mes + LoadStr( IDS_BEGINSHELF )
		else
			// "от конца полки"
			mes := mes + LoadStr( IDS_ENDSHELF );

		// "\nПризнак параллельности ответвлений: "
		mes := mes + #13#10 + LoadStr( IDS_PARALLEL );

		if ( leader.ParallelBranch ) then
			// "включен"
			mes := mes + LoadStr( IDS_ON )
		else
			// "отключен"
			mes := mes + LoadStr( IDS_OFF );
		
		// Выдать сообщение
		ksMessageW( PWideChar(mes) );
	end;
end;


//-------------------------------------------------------------------------------
// Выдать сообщение с параметрами знака маркировки
// ---
procedure GetMarkLeaderPar( markLeader : IMarkLeader );

var
  x0, y0  : double;
  count   : integer;
  branchs : IBranchs;
  mes     : WideString;
begin
	if ( markLeader <> nil ) then
	begin
    x0 := 0;
    y0 := 0;
		count := 0;

		branchs := markLeader As IBranchs;
		
		if ( branchs <> nil ) then
		begin
			// Получить координаты точки привязки
			x0 := branchs.X0;
			y0 := branchs.Y0;
			// Получить количество ответвлений
			count := branchs.BranchCount;
		end;

		// Сформировать сообщение для выдачи
		// "Знак маркировки"
		mes := LoadStr( IDS_MARKLEADER );
    // "Точка привязки: X0 = , Y0 = "
    mes := mes + #13#10 + LoadStr( IDS_POINT ) + #13#10 + 'X0 = ' + FormatFloat( '#.##', x0 ) + ',Y0 = ' + FormatFloat( '#.##', y0 );
		// "Количество ответвлений: "
		mes := mes + #13#10 + LoadStr( IDS_BRANCHCOUNT ) + IntToStr( count );

		// Выдать сообщение 
		ksMessageW( PWideChar(mes) );
	end;
end;


//-------------------------------------------------------------------------------
// Выдать сообщение с параметрами знака клеймения
// ---
procedure GetBrandLeaderPar( brandLeader : IBrandLeader );

var
  mes : WideString;
begin
	if ( brandLeader <> nil ) then
	begin
		// Сформировать сообщение
		mes := LoadStr( IDS_BRANDLEADER );
		// Выдать сообщение
		ksMessageW( PWideChar(mes) );
	end;
end;


//-------------------------------------------------------------------------------
// Выдать сообщение с параметрами знака изменения
// ---
procedure GetChangeLeaderPar( changeLeader : IChangeLeader );

var
  mes : WideString;
begin
	if ( changeLeader <> nil ) then
	begin
		// Сформировать сообщение
		mes := LoadStr( IDS_CHANLEADER );
		// Выдать сообщение
		ksMessageW( PWideChar(mes) );
	end;
end;


//-------------------------------------------------------------------------------
// Выдать сообщение с параметрами обозначения шероховатости
// ---
procedure GetRoughPar( rough : IRough );

var
  mes : WideString;
begin
	if ( rough <> nil ) then
	begin
		// Сформировать сообщение
		mes := LoadStr( IDS_ROUGH );
		// Выдать сообщение
		ksMessageW( PWideChar(mes) );
	end;
end;


//-------------------------------------------------------------------------------
// Выдать сообщение с параметрами обозначения базы
// ---
procedure GetBasePar( base : IBase );

var
  mes : WideString;
begin
	if ( base <> nil ) then
	begin
		// Сформировать сообщение
		mes := LoadStr( IDS_BASE );
		// Выдать сообщение
		ksMessageW( PWideChar(mes) );
	end;
end;


//-------------------------------------------------------------------------------
// Выдать сообщение с параметрами линии разреза/сечения
// ---
procedure GetCutLinePar( cutLine : ICutLine );

var
  mes : WideString;
begin
	if ( cutLine <> nil ) then
	begin
		// Сформировать сообщение
		mes := LoadStr( IDS_CUTLINE );
		// Выдать сообщение
		ksMessageW( PWideChar(mes) );
	end;
end;


//-------------------------------------------------------------------------------
// Выдать сообщение с параметрами стрелки направления взгляда
// ---
procedure GetViewPointerPar( viewPointer : IViewPointer );

var
  mes : WideString;
begin
	if ( viewPointer <> nil ) then
	begin
		// Сформировать сообщение
		mes := LoadStr( IDS_VIEWPOINTER );
		// Выдать сообщение
		ksMessageW( PWideChar(mes) );
	end;
end;


//-------------------------------------------------------------------------------
// Выдать сообщение с параметрами допуска формы
// ---
procedure GetTolerancePar( tolerance : ITolerance );

var
  mes : WideString;
begin
	if ( tolerance <> nil ) then
	begin
		// Сформировать сообщение
		mes := LoadStr( IDS_TOLERANCE );
		// Выдать сообщение
		ksMessageW( PWideChar(mes) );
	end;
end;


//-------------------------------------------------------------------------------
// Навигация по массиву объектов вида
// ---
procedure ObjectsNavigation;

var
  drawCont      : IDrawingContainer;
  arr           : OleVariant;
  pObj          : IDispatch;
  arrCount, j,
  objType       : integer;
  pDrawObj      : IDrawingObject;
  objRef        : reference;
  leader        : ILeader;
  markLeader    : IMarkLeader;
  brandLeader   : IBrandLeader;
  changeLeader  : IChangeLeader;
  rough         : IRough;
  base          : IBase;
  cutLine       : ICutLine;
  viewPointer   : IViewPointer;
  tolerance     : ITolerance;
begin
	// Получить контейнер графических объектов
	drawCont := GetDrawingContainer;

	if ( drawCont <> nil ) then
	begin
		// Тип 0 - все объекты
		//_variant_t objType = (long)0;
		// Получить массив SafeArray объектов
		arr := drawCont.Objects[ 0 {все объекты} ];
		
		// Если массив есть и он не пуст
		if ( VarType(arr) = (VT_ARRAY Or VT_DISPATCH) ) then
		begin
			// Определить количество элементов
			arrCount := ( VarArrayHighBound( arr,  1 ) + 1 );

			for j := 0 to arrCount - 1 do
			begin
				// Получить элемент из массива
				pObj := arr[j];
				
				if ( pObj <> nil ) then
				begin
					// Получить интерфейс графического объекта
					pDrawObj := pObj As IDrawingObject;
					
					if ( pDrawObj <> nil ) then
					begin
						// Получить тип объекта
						objType := pDrawObj.DrawingObjectType;
						// Получить референс объекта
						objRef := pDrawObj.Reference;
						// Подсветить объект
						LightObj( objRef, 1{включить} );

						// В зависимости от типа вывести сообщение для данного типа объектов
						case objType of

							// Простая линия выноски
							ksDrLeader:
							begin
								leader := pDrawObj As ILeader;
								GetLeaderPar( leader );
							end;

							// Знак маркировки
							ksDrMarkerLeader:
							begin
								markLeader := pDrawObj As IMarkLeader;
								GetMarkLeaderPar( markLeader );
							end;

							// Знак клеймения
							ksDrBrandLeader:
							begin
								brandLeader := pDrawObj As IBrandLeader;
								GetBrandLeaderPar( brandLeader );
							end;

							// Знак изменения
							ksDrChangeLeader:
							begin
								changeLeader := pDrawObj As IChangeLeader;
								GetChangeLeaderPar( changeLeader );
							end;

							// Обозначение шероховатости
							ksDrRough:
							begin
								rough := pDrawObj As IRough;
								GetRoughPar( rough );
							end;

							// Обозначение базы
							ksDrBase:
							begin
								base := pDrawObj As IBase;
								GetBasePar( base );
							end;

							// Линия разреза/сечения
							ksDrCut:
							begin
								cutLine := pDrawObj As ICutLine;
								GetCutLinePar( cutLine );
							end;

							// Стрелка направления взгляда
							ksDrWPointer:
							begin
								viewPointer := pDrawObj As IViewPointer;
								GetViewPointerPar( viewPointer );
							end;

							// Допуск формы
							ksDrTolerance:
							begin
								tolerance := pDrawObj As ITolerance;
								GetTolerancePar( tolerance );
							end;
						end;
						// Убрать подсветку
						LightObj( objRef, 0{выключить} );
					end;
				end;
			end;
		end;
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


