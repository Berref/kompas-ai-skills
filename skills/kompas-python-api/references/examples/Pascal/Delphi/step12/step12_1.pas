////////////////////////////////////////////////////////////////////////////////
//
// Пример библиотеки с пользовательской панелью
//
////////////////////////////////////////////////////////////////////////////////
unit step12_1;

interface
uses
  LDefin2D, ksAuto, Libtool, Windows, ksApi7;

var
  newKompasAPI : IApplication;                                // Компас Application 7
////////////////////////////////////////////////////////////////////////////////

  procedure  LIBRARYENTRY( command: WORD  ); Pascal;
  function   LIBRARYNAME : PAnsiChar;        Pascal;
  function   LIBRARYID   : Cardinal;         Pascal;
  procedure  MyDLLProc(Reason: Integer);
  function   LibIsOnApplication7 : Integer;  stdcall;
  function   LibToolBarId( barType,                                // Тип запрашиваемой панелей ( 0 - компактная панель, 1 - простая инструментальная панель )
                           index : Integer ) : Integer; stdcall;   // Индекс панели

  function   LibInterfaceNotifyEntry( kApp : PIDispatch ) : Integer; stdcall;

  procedure  ClosePropertyManager( mes : boolean );                // Удаление панели свойств
  procedure  CreateAndSubscriptionPropertyManager( mes : boolean );// Создание панели свойств
  procedure  UpdateSlideBox;                                       // Обновить слайд
  procedure  UpdateSlideBox1( docRef : Reference );                // Обновить слайд
  procedure  AdviseDoc( pDoc : Reference );                      // Подписать документ

  function   LoadStr( ID : Integer ) : string;                     // Загрузка строки из ресурсов
  function   LibMessage( str : string; flags : integer ) : Integer;// Выдача сообщения библиотеки
  function   LibMessageByID( strId, flags : Integer ) : Integer;   // Выдача сообщения библиотеки
  procedure  GetNewKompasAPI;

implementation

uses
  LtDefine,

  cBaseEvents,
  PropMen,
  ApplicationEvents,
  DocumentEvents, ksConstTLB,
  forms;

var
  propMng      : IPropertyManager;                            // Менежер панели свойств
  slideBox     : IPropertySlideBox;                           // Окно в котором будет отрисовываться текущий документ

  g_Rect   : TRect = ( Left : 20; Top : 20; Right : 270; Bottom : 320 );  // Размер панели


const

  g_Layout : PropertyManagerLayout = pmAlignRight; //pmFloating           // Положение панели

//------------------------------------------------------------------------------
// LibraryName
//---
procedure MyDLLProc(Reason: Integer);
begin
  if Reason = DLL_PROCESS_DETACH then begin
    cBaseEvent.TerminateEvents;
    ClosePropertyManager( false );
    newKompasAPI       := nil;
    Application.Handle := 0;
  end;
end;


//------------------------------------------------------------------------------
// LibraryName
//---
function LIBRARYNAME: PAnsiChar; pascal;
begin
  Result := 'Пример библиотечной панели свойств (Delphi)';
end;

//------------------------------------------------------------------------------
// LibraryId
//---
function LIBRARYID: UINT; pascal;
begin
  Result := 100;  // IDR_LIB
end;

//------------------------------------------------------------------------------
// LibraryEntry
//---
procedure LIBRARYENTRY(command: WORD); pascal;
begin
  Application.Handle := GetHWindow;

  case command of
    1 : begin                                      // Комманда 1
          CreateAndSubscriptionPropertyManager( true );
        end;
    2 : begin                                      // Комманда 2
          ClosePropertyManager( true );
        end
  end;
end;

//-----------------------------------------------------------------------------
// Провести подписку библиотеки на сообщения системы
// ---
function LibInterfaceNotifyEntry( kApp : PIDispatch ) : Integer; stdcall;
begin
  Application.Handle := GetHWindow;
  newKompasAPI := IDispatch(kApp) As IApplication;        // Получаем интерфейс Компаса
  if newKompasAPI <> nil then
    CreateAndSubscriptionPropertyManager( false ); // Создание панели библиотеки
  Result := 0;
end;

//-------------------------------------------------------------------------------
// Использовать новое API
// ---
function LibIsOnApplication7 : Integer; stdcall;
begin
  Result := 1;
end;

//-------------------------------------------------------------------------------
// Получить идентификаторы инструментальных и компактных панелей
// ---
function LibToolBarId( barType,                               // Тип запрашиваемой панелей ( 0 - компактная панель, 1 - простая инструментальная панель )
                       index : Integer ) : Integer; stdcall;  // Индекс панели
begin
	if ( barType = 0 ) then
  begin
    if ( index = 0 ) then
      Result := 2000
    else
      Result := -1;
  end
	else
		Result := -1;
end;

//------------------------------------------------------------------------------
// Создание панели свойств
//---
procedure  CreateAndSubscriptionPropertyManager( mes : boolean );
var
 tab        : IPropertyTab;
 tabs       : IPropertyTabs;
 control    : IPropertyControl;
 collection : IPropertyControls;
 docRef     : Reference;
begin
  GetNewKompasAPI;
  if ( newKompasAPI <> nil ) and ( propMng = nil ) then
    propMng := newKompasAPI.CreatePropertyManager( true ); 
  if ( propMng <> nil ) then
  begin
    NewApplicationEvent();
    propMng.Layout := g_Layout;
    propMng.Caption := 'Панель из библиотеки на Delphi';
    propMng.SetGabaritRect( g_Rect.left, g_Rect.top, g_Rect.right, g_Rect.bottom );
    propMng.SpecToolbar := pnEnterEscCreateSaveSearchHelp;
    NewPropertyManagerEvent( IDispatch(propMng) );
    tabs := propMng.PropertyTabs;
    tab  := tabs.Add('Закладка из библиотеки');

    // Получаем коллекцию контролов
    collection := tab.PropertyControls;
    docRef     := ksGetCurrentDocument(0);
    AdviseDoc( docRef );
    // Добавсляем окно просмотра
    control    := collection.Add( ksControlSlideBox );
    slideBox   := control As IPropertySlideBox;
    if slideBox <> nil then
    begin
      with slideBox do
      begin
        SlideType          := ksKompasDocument;             // Отрисовываем группу
        DrawingSlide       := docRef;                       // Передаем reference группы
        Value              := docRef <> 0;
        CheckBoxVisibility := docRef <> 0;
        Hint               := 'Hint для слайда';
        Tips               := 'Tips для слайда';
        Id                 := 10000;
        Name               := 'Окно просмотра';
        NameVisibility     := ksNameHorizontalVisible;
      end
    end;
    propMng.ShowTabs();
    collection := nil;
    tab := nil;
    tabs := nil;
  end
  else begin
    propMng.Visible := true;    // Если панель была скрыта пользователем по крестику востановим ее
    if  mes then
      LibMessage( 'Панель уже загружена', MB_OK );
  end
end;

//------------------------------------------------------------------------------
// Удаление панели свойств
//---
procedure ClosePropertyManager( mes : boolean );                          // Удаление панели свойств
begin
  if propMng <> nil then
  begin
    g_Layout := propMng.Layout;
    propMng.GetGabaritRect( g_Rect.Left, g_Rect.Top, g_Rect.Right, g_Rect.Bottom );
    cBaseEvent.TerminateEventsByParam( ntPropertyManagerNotify, 0, 0, nil );
    slideBox := nil;
    propMng.HideTabs();
    propMng := nil;
  end
  else
    if mes then
      LibMessage( 'Панель уже выгружена', MB_OK );
end;

//------------------------------------------------------------------------------
// Обновление изображения
//---
procedure  UpdateSlideBox;                                                 // Обновить слайд
begin
  if slideBox <> nil then
    slideBox.UpdateParam;
end;

//------------------------------------------------------------------------------
// Обновление изображения
//---
procedure  UpdateSlideBox1( docRef : Reference );                          // Обновить слайд
begin
  if slideBox <> nil then
  begin
    slideBox.DrawingSlide       := docRef;
    slideBox.Value              := docRef <> 0;
    slideBox.CheckBoxVisibility := docRef <> 0;
    slideBox.UpdateParam();
  end
end;

// Подписать документ
procedure  AdviseDoc( pDoc : Reference );
var
  docType : Integer;
begin
	if pDoc = 0 then
		pDoc := ksGetCurrentDocument( 0 )
	else
    SetObjParam(pDoc, nil, 0, DOCUMENT_STATE);

	if pDoc <> 0 then
  begin
		docType := ksGetDocumentType( pDoc );
		if NewDocumentEvent( pDoc ) <> nil then
    begin
			case docType of
		  	lt_DocSheetStandart ,
			  lt_DocSheetUser     ,
			  lt_DocFragment      :
				  NewObj2DEvent( pDoc, ALL_OBJ );
      end
		end
	end
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
  end
end;

//----------------------------------------------------------------------------------------------
// Зогрузить строку из ресурсов
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


