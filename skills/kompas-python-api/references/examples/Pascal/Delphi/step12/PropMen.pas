unit PropMen;

interface
uses
  Windows,
  Libtool,
  LDefin2D,
  classes,
  cBaseEvents,
  ks2DCOM_TLB,
  ksConstTLB,
  ComObj,
  ActiveX,
  LtDefine,
  step12_1,
{$IFDEF __LIGHT_VERSION__}
  klAPI7;
{$ELSE}
  ksApi7;
{$ENDIF}

type
////////////////////////////////////////////////////////////////////////////////
//
// PropertyManagerEvent - обрабокчик событий от менеджера панели свойств
//
////////////////////////////////////////////////////////////////////////////////
PPropertyManagerEvent = ^PropertyManagerEvent;
PropertyManagerEvent = class( cBaseEvent, IPropertyManagerNotify )

public
	constructor Create( var manager: IDispatch );
  destructor  Destroy; override;
  function    Advise(): boolean; override;

  protected
  // Функция должна возвращать true если метод notifyType обрабатывается интерфейсом
  function IsNotifyProcess(notifyType: SYSINT): WORDBOOL; virtual; stdcall;

  // prButtonClick        - Нажатие кнопки.  "Создался OCX контрол."
  function ButtonClick( buttonID : Integer ) : WORDBOOL; virtual; stdcall;
  // prChangeControlValue - "Удаляется OCX контрол."
  function ChangeControlValue( const ctrl : IUnknown ) : WORDBOOL; virtual; stdcall;
  // prControlCommand     - Нажатие кнопки контрола
  function ControlCommand( const ctrl : IUnknown; buttonID : Integer ) : WORDBOOL; virtual; stdcall;
  //prButtonUpdate        - Установка состояния кнопки спецпанели.
  function ButtonUpdate ( buttonID : Integer; var check : Integer; var _enable : WordBool ) : WORDBOOL; virtual; stdcall;
  //prProcessActivate    - Начало процесса
  function ProcessActivate : WORDBOOL; virtual; stdcall;
  // prProcessDeactivate  - Завершение процесса
  function ProcessDeactivate : WORDBOOL; virtual; stdcall;
  // prCommandHelp - Вызов справки для контрола
  function CommandHelp(Id: Integer): WORDBOOL; virtual; stdcall;
  // prSelectItem - Селектирование элемента списка
  function  SelectItem(const Control: IUnknown; Index: Integer; Select: WordBool): WordBool; virtual; stdcall;
  // prCheckItem - Выбор элемента списка
  function  CheckItem(const Control: IUnknown; Index: Integer; check: WordBool): WordBool; virtual; stdcall;
  // prChangeActiveTab - Смена активной закладки
  function  ChangeActiveTab(TabIndex: Integer): WordBool; virtual; stdcall;
  // prEditFocus - установка \ снятие фокуса
  function  EditFocus(const ctrl: IUnknown; Set_: WordBool): WordBool; virtual; stdcall;
  // prUserMenuCommand - Выбор команды из меню
  function  UserMenuCommand(const ctrl: IUnknown; menuID: Integer): WordBool; virtual; stdcall;
  // prLayoutChanged - Изменение положения панели
  function LayoutChanged: WordBool; virtual; stdcall;

  function GetContextMenuType(LX: Integer; LY: Integer; var ContextMenuType: Integer): WordBool; virtual; stdcall;
  function FillContextPanel(const ContextPanel: IUnknown): WordBool; virtual; stdcall;
  function FillContextIconMenu(const menu: IUnknown): WordBool; virtual; stdcall;
  function EndEditItem(const ctrl: IUnknown; Index: Integer): WordBool; virtual; stdcall;
  function ChangeTabExpanded(TabIndex: Integer): WordBool; virtual; stdcall;
  function DoubleClickItem(const Control: IUnknown; Index: Integer): WordBool; stdcall;
end;


function NewPropertyManagerEvent( var manager: IDispatch ) : PropertyManagerEvent;

implementation



////////////////////////////////////////////////////////////////////////////////
//
// PropertyManagerEvent - обрабокчик событий от менеджера панели свойств
//
////////////////////////////////////////////////////////////////////////////////
constructor PropertyManagerEvent.Create( var manager: IDispatch );
begin
  inherited CreateByObj( ntPropertyManagerNotify, IUnknown(manager) );
end;

destructor PropertyManagerEvent.Destroy;
begin
  inherited Destroy;
end;

//------------------------------------------------------------------------------
// Advise
//---
function PropertyManagerEvent.Advise() : boolean;
begin
  if not m_advise and ( m_params.ifType <> 0 ) then
    m_advise := boolean( ksConnectionAdvise( @m_params, PIUnknown(IPropertyManagerNotify(self)) ) );
	Result := m_advise;
end;

// prButtonClick        - Нажатие кнопки.  
function PropertyManagerEvent.ButtonClick( buttonID : Integer ) : WORDBOOL;
begin
//  if ( buttonID = pbHelp )
//    OpenHelp( 1 );
  if ( buttonID = pbEnter ) Or ( buttonID = pbEsc ) then
    ClosePropertyManager( false );

  Result := true;
end;


function PropertyManagerEvent.ChangeControlValue( const ctrl : IUnknown ) : WORDBOOL;
begin
  Result := true;
end;


function PropertyManagerEvent.ControlCommand( const ctrl : IUnknown; buttonID : Integer ) : WORDBOOL;
begin
  Result := true;
end;

//prButtonUpdate        - Установка состояния кнопки спецпанели.
function PropertyManagerEvent.ButtonUpdate ( buttonID : Integer; var check : Integer; var _enable : WORDBOOL ) : WORDBOOL;
begin
  _enable := true;
  Result := true;
end;

//prProcessActivate    - Начало процесса
function PropertyManagerEvent.ProcessActivate : WORDBOOL;
begin
  Result := true;
end;

// prProcessDeactivate  - Завершение процесса
function PropertyManagerEvent.ProcessDeactivate : WORDBOOL;
begin
  Result := true;
end;

// prCommandHelp - Вызов справки для контрола
function PropertyManagerEvent.CommandHelp(Id: Integer): WORDBOOL;
begin
  Result := true;
end;

// prSelectItem - Селектирование элемента списка
function PropertyManagerEvent.SelectItem(const Control: IUnknown; Index: Integer; Select: WordBool): WordBool; stdcall;
begin
  Result := true;
end;

// prCheckItem - Выбор элемента списка
function PropertyManagerEvent.CheckItem(const Control: IUnknown; Index: Integer; check: WordBool): WordBool; stdcall;
begin
  Result := true;
end;

// prChangeActiveTab - Смена активной закладки
function  PropertyManagerEvent.ChangeActiveTab(TabIndex: Integer): WordBool; stdcall;
begin
  Result := true;
end;

// prEditFocus - установка \ снятие фокуса
function PropertyManagerEvent.EditFocus(const ctrl: IUnknown; Set_: WordBool): WordBool; stdcall;
begin
  Result := true;
end;

// prUserMenuCommand - Выбор команды из меню
function PropertyManagerEvent.UserMenuCommand(const ctrl: IUnknown; menuID: Integer): WordBool; stdcall;
begin
  Result := true;
end;

// prProcessDeactivate  - Завершение процесса
function PropertyManagerEvent.LayoutChanged : WORDBOOL;
begin
  Result := true;
end;

function PropertyManagerEvent.GetContextMenuType(LX: Integer; LY: Integer; var ContextMenuType: Integer): WordBool; stdcall;
begin
  Result := true;
end;

function PropertyManagerEvent.FillContextPanel(const ContextPanel: IUnknown): WordBool; stdcall;
begin
  Result := true;
end;

function PropertyManagerEvent.FillContextIconMenu(const menu: IUnknown): WordBool; stdcall;
begin
  Result := true;
end;

function PropertyManagerEvent.EndEditItem(const ctrl: IUnknown; Index: Integer): WordBool; stdcall;
begin
  Result := true;
end;

function PropertyManagerEvent.ChangeTabExpanded(TabIndex: Integer): WordBool; stdcall;
begin
  Result := true;
end;

function PropertyManagerEvent.DoubleClickItem(const Control: IUnknown; Index: Integer): WordBool; stdcall;
begin
  Result := true;
end;

function PropertyManagerEvent.IsNotifyProcess( notifyType: SYSINT ) : WORDBOOL;
begin
  Result := ( notifyType >= prButtonClick ) And ( notifyType <= prCommandHelp )
end;

function NewPropertyManagerEvent( var manager: IDispatch ) : PropertyManagerEvent;
begin
	Result := PropertyManagerEvent.Create( manager );
	if not Result.Advise() then begin
    Result.Free;
		Result := nil;
	end
end;

end.
