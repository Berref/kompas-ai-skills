unit ManagerEvents;

interface

uses
  Windows,
  Contnrs,
  ComObj,
  Classes,
  LDefin2D,
  ksAuto,
  ActiveX,
  ksConstTLB,
  ksAPI7,
  SysUtils,
  Forms;

type

////////////////////////////////////////////////////////////////////////////////
//
// Базовый класс для обслуживания панели свойств
//
// ctrlID используется как идентификатор контрола и как идентификатор для загрузки
// ресурсов контрола
//
////////////////////////////////////////////////////////////////////////////////
PBaseEvent = ^BaseEvent;
BaseEvent = class( TInterfacedObject, IDispatch )

private
  m_dwCookie  : LongInt;
  m_iidEvents : TGUID;

protected
  m_pContainer: IDispatch;

public
  constructor Create( const pObject : IDispatch; iidEvents : TGUID ); overload;
  destructor  Destroy(); override;
  function    Advise() : boolean; virtual; stdcall;
  procedure   Unadvise(); stdcall;

  class procedure TerminateEvents();

  function GetTypeInfo(Index, LocaleID: Integer; out TypeInfo): HResult; stdcall;
  function GetTypeInfoCount(out Count: Integer): HResult; stdcall;
  function GetIDsOfNames(const IID: TGUID; Names: Pointer; NameCount,
                           LocaleID: Integer; DispIDs: Pointer): HResult; stdcall;

  function Invoke(eventID: Integer; const IID: TGUID; LocaleID: Integer;
                  Flags: Word; var Params; VarResult, ExcepInfo, ArgErr: Pointer): HResult;
                  stdcall;
  function QueryInterface(const IID: TGUID; out Obj): HResult; stdcall;
protected
  function OnEvent( commandID : Integer; var Params : tagDISPPARAMS; var eventRes : boolean  ) : boolean; virtual;

end;

////////////////////////////////////////////////////////////////////////////////
//
// Класс для обслуживания панели свойств
//
// ctrlID используется как идентификатор контрола и как идентификатор для загрузки
// ресурсов контрола
//
////////////////////////////////////////////////////////////////////////////////
PPropertyManagerObject = ^PropertyManagerObject;
PropertyManagerObject = class
protected
  m_flagMode       : Boolean;           // Признак редактирования по дабл-клику
  procParam        : IProcessParam;     // Параметры процесса
  propTabs         : IPropertyTabs;     // Закладки
  curentCollection : IPropertyControls; // Контролы текущей закладки панели свойств
  paramGrid        : IPropertyGrid;     // Грид для вывода дополнительных параметров элемента
  slideBox         : IPropertySlideBox; // Окно просмотра
  rowIndex         : Integer;           // Индекс строки
  posLiaderParam   : IProcessParam;     // Параметры процесса указания линии выноски
public
  constructor Create;
  destructor  Destroy; override;
  // События
  // prButtonClick - Нажатие кнопки.
  function OnButtonClick( buttonID : LongInt ) : Boolean;  virtual;

  // prChangeControlValue - Изменение значения контрола
  procedure OnChangeControlValue( {var cntrl : IPropertyControl,} ctrlID : LongInt; const Val: Variant ); virtual;

  // Событие создания ActiveX Control-a
  procedure OnCreateOCX( ctrlID : LongInt; var control : IDispatch ); virtual;

  // Событие удаления ActiveX Control-a
  procedure OnDestroyOCX( ctrlID : LongInt{; var control :IDispatch} ); virtual;

  // prButtonUpdate        - Установка состояния кнопки спецпанели.
  function OnButtonUpdate ( buttonID : LongInt; var check : LongInt; var _enable : WordBool ) : Boolean; virtual;
protected
  // Инициализация параметров процесса
  function InitProcessParam() : Boolean;
  // Добавление закладки
  function CreateTab( tabID : LongInt; {visible,} active : Boolean ) : Boolean;

  // Добавление комбобокса вещественных значений
  function CreateList( minVal, maxVal : Double )                : IPropertyList;
  // Добавление сепаратора
  function CreateSeparator( _type : SeparatorTypeEnum )         : IPropertySeparator;
  // Добавление CheckBox-а
  function CreateCheckBox( checked : Boolean )                  : IPropertyCheckBox;
  // Добавление группы кнопок
  function CreateMultiButton( _type : ButtonTypeEnum )          : IPropertyMultiButton;
  // Создать ActiveX Control пользователя
  function CreateUserControl( ctrlID, height, width : LongInt ) : IPropertyUserControl;

  // Добавление кнопоки в группу
  procedure AddButton( var buttons : IPropertyMultiButton; btnID : LongInt; cheched, enable : Boolean );
  // Добавление кнопоки в группу
  procedure AddButton2( var buttons : IPropertyMultiButton; btnID, bmpID : LongInt; cheched, enable : Boolean );

  // Получить указатель на Control по его идентификатору (для изменения параметров контрола)
  function GetPropertyControl( ctrlID : LongInt ) : IPropertyControl;
  // Изменить состояние контрола
  procedure SetControlEnable( ctrlID : LongInt; enabled : Boolean );

  // Накачка контрола общими параметрами
  procedure InitPropertyControl( var control : IPropertyControl; _ctrlID, _hintID, _tipsID : LongInt;
                             _name_Visibility  : PropertyControlNameVisibility;
                             _enable, _visible : Boolean );

  // Виртуальная функция наполнения контролов элемента
  procedure ShowControls;          virtual;
  // Перерисовать фантом
  procedure RedrawPhantom;         virtual;

  // Количество параметров выводимых в гриде
  function GetParamCount: Integer; virtual;
  // Заполнение грида параметров
  procedure ShowParam;             virtual;
  // Функции для заполнения грида параметров
  procedure AddStringToGrig( paramID : LongInt; value : string ); // Добавление строкового значения
  procedure AddDoubleToGrig( paramID : LongInt; value : Double ); // Добавление числового  значения

  // Функции для вывода контрола параметров штриховки
  procedure ShowHatchControl;        virtual;

  // Завершить процесс редактирования
  procedure EndProcess();
  // Менеджер свойств
  function  GetPreviewGroup : Reference; virtual;

  // Количество параметров
  property  ParamCount : Integer read GetParamCount;

end;


////////////////////////////////////////////////////////////////////////////////
//
// PropertyManagerEvent - обработчик событий от менеджера панели свойств
//
////////////////////////////////////////////////////////////////////////////////
PropertyManagerEvent = class( BaseEvent )

protected
  obj : PropertyManagerObject;           // Указатель на подписанный объект
  // Attributes
public
	constructor Create( const manager: IDispatch; const _obj: PropertyManagerObject );
  destructor  Destroy; override;

// Operations

protected
  function OnEvent( commandID : Integer; var Params : tagDISPPARAMS; var eventRes : boolean  ) : Boolean; override;

  // prButtonClick        - Нажатие кнопки.  "Создался OCX контрол."
  function OnButtonClick( buttonID : LongInt ) : Boolean; virtual;

  // prChangeControlValue - "Удаляется OCX контрол."
  function OnChangeControlValue( var ctrl : IDispatch ) : Boolean; virtual;

  // prControlCommand     - Нажатие кнопки контрола
  function OnControlCommand( var ctrl : IDispatch; buttonID : LongInt ) : Boolean; virtual;

  // prButtonUpdate        - Установка состояния кнопки спецпанели.
  function OnButtonUpdate ( buttonID : LongInt; var check : LongInt; var _enable : WordBool ) : Boolean; virtual;
end;

EventList = class ( TObjectList ) // (TInterfaceList)
public
  constructor Create; overload;
  procedure Notify(Ptr: Pointer; Action: TListNotification); override;
end;

procedure MyDLLProc(Reason: Integer);

const
  ITB_SPEC_TOOLBAR = 3000;

//var
//  newKompasAPI : IApplication;

implementation

uses
  UserSymbol1,
  Entry;

var
  m_BaseEventList : EventList; // static BaseEvent

//------------------------------------------------------------------------------
// Удаление листа из списка
// ---
procedure EventList.Notify(Ptr: Pointer; Action: TListNotification);
begin
  if OwnsObjects then
    if Action = lnDeleted then begin
      BaseEvent(Ptr).UnAdvise;
      exit;
    end;
  inherited Notify(Ptr, Action);
end;

//------------------------------------------------------------------------------
// Создание списка
// ---
constructor EventList.Create();
begin
  inherited Create;
end;

//------------------------------------------------------------------------------
// Конструктор
//---
constructor BaseEvent.Create( const pObject : IDispatch; iidEvents : TGUID );
begin
  if  m_BaseEventList = nil then
    m_BaseEventList := EventList.Create;
  m_pContainer := pObject;
  m_pContainer._AddRef;
  m_iidEvents  := iidEvents;
  m_dwCookie   := 0;
  m_BaseEventList.Add( Self );
end;

//------------------------------------------------------------------------------
// Деструктор
//---
destructor BaseEvent.Destroy();
begin
  if ( m_BaseEventList <> nil ) then
  begin
    m_BaseEventList.Remove( Self );
    Unadvise;              // отпишемся от получения событий
    m_pContainer := nil;
  end
end;

//------------------------------------------------------------------------------
// Реализация метода Invoke IDispatch
//---
function BaseEvent.Invoke( eventID: Integer; const IID: TGUID; LocaleID: Integer;
                           Flags: Word; var Params; VarResult, ExcepInfo,
                           ArgErr: Pointer): HResult;
var
  ProcParams: tagDISPPARAMS;
  Res: ^OleVariant;
  fResult : boolean;
begin
  Result     := S_OK;
  Res        := VarResult;
  ProcParams := TDispParams(Params);
  fResult    := true;

  OnEvent( eventID, ProcParams, fResult );

  if Res <> nil then begin
    Res^ := fResult;
  end;
end;

//------------------------------------------------------------------------------
// Реализация метода GetTypeInfo IDispatch
//---
function BaseEvent.GetTypeInfo(Index, LocaleID: Integer; out TypeInfo): HResult;
begin
  Result := E_NOTIMPL;
end;

//------------------------------------------------------------------------------
// Реализация метода GetTypeInfoCount IDispatch
//---
function BaseEvent.GetTypeInfoCount(out Count: Integer): HResult;
begin
  Count:=0;
  Result:=S_OK;
end;

//------------------------------------------------------------------------------
// Реализация метода GetIDsOfNames IDispatch
//---
function BaseEvent.GetIDsOfNames(const IID: TGUID; Names: Pointer; NameCount,
                                  LocaleID: Integer; DispIDs: Pointer): HResult;
begin
  Result := S_OK;
end;

//------------------------------------------------------------------------------
// Соединение с источником сообщений
//---
function  BaseEvent.Advise() : boolean; stdcall;
begin
  if ( m_dwCookie = 0) And  (m_pContainer <> nil) then
    InterfaceConnect( m_pContainer, m_iidEvents, IDispatch( self ), m_dwCookie );
	Result := m_dwCookie <> 0;
end;

//------------------------------------------------------------------------------
// Отсоединение от источника сообщений
//---
procedure BaseEvent.Unadvise(); stdcall;
var
  cock : integer;
begin
  if ( m_pContainer <> nil ) and ( m_dwCookie <> 0 ) then begin
    cock := m_dwCookie;
    m_dwCookie := 0;  // нужно обнулить до InterfaceDisconnect
    InterfaceDisconnect( m_pContainer, m_iidEvents, cock );
  end;
end;

//------------------------------------------------------------------------------
// Отписка сообщений
//---
class procedure BaseEvent.TerminateEvents();
begin
  if  m_BaseEventList <> nil then begin
    m_BaseEventList.Free;
    m_BaseEventList := nil;
  end
end;

//------------------------------------------------------------------------------
// QueryInterface
//---
function BaseEvent.QueryInterface(const IID: TGUID; out Obj): HResult; stdcall;
begin
  if GetInterface(IID, Obj) then
    Result := S_OK
  else
    if IsEqualGUID(IID, m_iidEvents) then
    begin
      IDispatch(Obj) := Self;
      Result := S_OK;
    end
    else
      Result := E_NOINTERFACE;
end;

//------------------------------------------------------------------------------
// Событие
//---
function BaseEvent.OnEvent( commandID : Integer; var Params : tagDISPPARAMS; var eventRes : boolean ) : boolean;
begin
  eventRes := true;
  Result   := true;
end;

//------------------------------------------------------------------------------
// Конструктор
//---
constructor PropertyManagerEvent.Create( const manager: IDispatch; const _obj: PropertyManagerObject );
begin
  inherited Create( manager, DIID_ksPropertyManagerNotify );
  obj := _obj;
  Advise;
end;

//------------------------------------------------------------------------------
// prButtonClick - Нажатие кнопки.
//---
function PropertyManagerEvent.OnButtonClick( buttonID : LongInt ) : Boolean;
begin
  Result := obj.OnButtonClick( buttonID );
end;

//------------------------------------------------------------------------------
// prChangeControlValue - Изменение значения контрола
//---
function PropertyManagerEvent.OnChangeControlValue( var ctrl : IDispatch ) : boolean;
var
  control : IPropertyControl;
  ctrlID  : LongInt;
begin
  if ( ctrl <> nil ) then begin
    control := ctrl As IPropertyControl;
    if control <> nil then begin
      ctrlID := control.Id;
      obj.OnChangeControlValue(ctrlID, control.Value );
    end;
  end;
  Result := true;
end;

//------------------------------------------------------------------------------
// koOpenDocumen - Документ открыт
//---
function PropertyManagerEvent.OnControlCommand( var ctrl : IDispatch; buttonID : LongInt ) : Boolean;
begin
  obj.OnButtonClick( buttonID );
  Result := true;
end;

//------------------------------------------------------------------------------
// prButtonUpdate        - Установка состояния кнопки спецпанели.
//---
function PropertyManagerEvent.OnButtonUpdate( buttonID : LongInt; var check : LongInt; var _enable : WordBool ) : Boolean; 
begin
  Result := obj.OnButtonUpdate( buttonID, check, _enable );
end;

//------------------------------------------------------------------------------
// Деструктор событий
//---
destructor PropertyManagerEvent.Destroy();
begin
  inherited Destroy;
end;

//------------------------------------------------------------------------------
// Трансляция событий
//---
function PropertyManagerEvent.OnEvent( commandID : Integer; var Params : tagDISPPARAMS; var eventRes : boolean ) : boolean;
begin
  Result := (boolean( commandID >= prButtonClick ) and boolean( commandID <= prControlCommand )) or ( commandID = prCommandHelp);
  case commandID of

    prButtonClick:                       // Нажатие кнопки панели
      eventRes := OnButtonClick( Params.rgvarg^[0].lVal );

    prChangeControlValue :              // Начало открытия документа
      eventRes := OnChangeControlValue( IDispatch(Params.rgvarg^[0].dispVal ) );

    prControlCommand:                   // Нажатие кнопки контрола
      eventRes := OnControlCommand( IDispatch(Params.rgvarg^[1].dispVal), LongInt(Params.rgvarg^[0].lVal) );

    prButtonUpdate:                     // Переключение на другой активный документ
      eventRes := OnButtonUpdate( Params.rgvarg^[2].intVal, Params.rgvarg^[1].pIntVal^, Params.rgvarg^[0].pbool^ );
  end;
end;

//------------------------------------------------------------------------------
// Получить доступ к новому API
// ---
procedure GetNewKompasAPI;
 var
    disp : IDispatch;
begin
	if newKompasAPI = nil then
  begin
    disp := IDispatch( CreateKompasApplication );
    newKompasAPI := disp As IApplication;
  end
end;

//------------------------------------------------------------------------------
// Конструктор
// ---
constructor PropertyManagerObject.Create;
begin
  procParam        := nil;  // Параметры процесса
  propTabs         := nil;  // Коллекция закладок
  curentCollection := nil;  // Коллекция контролов
  paramGrid        := nil;  // Грид для вывода дополнительных параметров элемента
  slideBox         := nil;  // Окно просмотра
  rowIndex         := 0;    // Индекс строки
  posLiaderParam   := nil;  //
  m_flagMode       := False;//
end;

//------------------------------------------------------------------------------
// Деструктор
// ---
destructor PropertyManagerObject.Destroy;
begin
  BaseEvent.TerminateEvents;
  paramGrid        := nil;  // Грид для вывода дополнительных параметров элемента
  slideBox         := nil;  // Окно просмотра
  curentCollection := nil;  // Коллекция контролов
  propTabs         := nil;  // Коллекция закладок
  procParam        := nil;  // Параметры процесса
  posLiaderParam   := nil;  //
  rowIndex         := 0;    // Индекс строки
  m_flagMode       := False;//
end;

//------------------------------------------------------------------------------
// Инициализация параметров процесса
// ---
function PropertyManagerObject.InitProcessParam() : Boolean;
begin

  Result := false;
  if (newKompasAPI <> nil) And (procParam = nil ) then
  begin
    procParam := newKompasAPI.CreateProcessParam;

    if procParam <> nil then
    begin
      PropertyManagerEvent.Create( IDispatch(procParam), Self );
      with procParam do
      begin
        Caption := 'Панель';
        AutoReduce := true;
        SpecToolbarEx := ITB_SPEC_TOOLBAR;
        ResModule := OleVariant( LONG_PTR(hInstance) );
        Result := true;
      end;
    end;
  end;
end;

//------------------------------------------------------------------------------
// Добавить параметр в грид
// ---
procedure PropertyManagerObject.AddStringToGrig( paramID : LongInt; value : string );
begin
  if paramGrid <> nil then
  begin
    paramGrid.CellText[ rowIndex, 1 ] := value;
    paramGrid.CellText[ rowIndex, 0 ] := LoadStr(paramID); // Не переставлять так задумано
    Inc(rowIndex);
  end
end;

//------------------------------------------------------------------------------
// Перевод числа в строку
// ---
function DoubleToStr( value : double ) : string;
  var
    str  : string;
    dSep : Char;
begin
{$IFDEF CONDITIONALEXPRESSIONS}
{$IF CompilerVersion >= 17 }
   with  System.SysUtils.FormatSettings do
 {$IFEND}
{$IFEND}
   begin
    dSep := DecimalSeparator;
    DecimalSeparator := '.';
    str := Format('%0.3f',[value]);
    Result := Format('%g', [StrToFloat( str )] );
    DecimalSeparator := dSep;
   end;
end;

//------------------------------------------------------------------------------
// Добавить параметр в грид
// ---
procedure PropertyManagerObject.AddDoubleToGrig( paramID: LongInt; value : double );
begin
  if paramGrid <> nil then begin
    paramGrid.CellText[ rowIndex, 1 ] := DoubleToStr(value);  // Выводим значение
    paramGrid.CellText[ rowIndex, 0 ] := LoadStr(paramID);      // Имя параметра
    Inc(rowIndex);
  end
end;

//------------------------------------------------------------------------------
// Создать закладку
// ---
function PropertyManagerObject.CreateTab( tabID : LongInt; {visible,}active : Boolean ) : Boolean;
var
  propTab : IPropertyTab;
begin
  Result := false;
  if ( tabID <> 0 ) and ( propTabs <> nil ) then
  begin
    propTab := propTabs.Add( WideString( LoadStr(tabID) ) );
    if propTab <> nil then
    begin
      curentCollection := propTab.PropertyControls;
      propTab.Active  := active;
      Result          := true;
    end
  end
end;

//------------------------------------------------------------------------------
// Инициализация контрола
// ---
procedure PropertyManagerObject.InitPropertyControl( var control : IPropertyControl; _ctrlID, _hintID, _tipsID : LongInt;
                             _name_Visibility  : PropertyControlNameVisibility;
                             _enable, _visible : Boolean );
begin
  if control <> nil then
  begin
    with control do
    begin
      Id      := _ctrlID;
      if _ctrlID <> 0 then
        Name  := WideString( LoadStr(_ctrlID) );
      if _hintID <> 0 then
        Hint  := WideString( LoadStr(_hintID) );
      if _tipsID <> 0 then
        Tips  := WideString( LoadStr(_tipsID) );;
      Enable  := _enable;
      Visible := _visible;
      NameVisibility := _name_Visibility;
    end
  end
end;

//------------------------------------------------------------------------------
// Создать комбобокс
// ---
function PropertyManagerObject.CreateList( minVal, maxVal : Double ) : IPropertyList;
begin
  Result := nil;
  if curentCollection <> nil then
  begin
    Result := curentCollection.Add( ksControlListReal ) As IPropertyList;
    if ( minVal <> maxVal ) and ( Result <> nil ) then
    begin
      Result.SetValueRange( minVal, maxVal );
      Result.ReadOnly := true;
    end
  end
end;

//------------------------------------------------------------------------------
// Создать сепаратор
// ---
function PropertyManagerObject.CreateSeparator( _type : SeparatorTypeEnum ) : IPropertySeparator;
begin
  Result := nil;
  if curentCollection <> nil then
  begin
    Result := curentCollection.Add( ksControlSeparator ) As IPropertySeparator;
    if Result <> nil then
      Result.SeparatorType := _type;
  end;
end;

//------------------------------------------------------------------------------
// Добавление CheckBox-а
// ---
function PropertyManagerObject.CreateCheckBox( checked : Boolean ) : IPropertyCheckBox;
begin
  Result := nil;
  if curentCollection <> nil then
  begin
    Result := curentCollection.Add( ksControlCheckBox ) As IPropertyCheckBox;
    if Result <> nil then
      Result.Value := checked;
  end;
end;

//------------------------------------------------------------------------------
// Создать набор кнопок
// ---
function PropertyManagerObject.CreateMultiButton( _type : ButtonTypeEnum ) : IPropertyMultiButton;
begin
  Result := nil;
  if curentCollection <> nil then
  begin
    Result := curentCollection.Add( ksControlMultiButton ) As IPropertyMultiButton;
    if Result <> nil then
    begin
      Result.ButtonsType := _type;
      Result.ResModule   := LONG_PTR( hInstance );
    end
  end
end;

//------------------------------------------------------------------------------
// Добавить кнопку в набор
// ---
procedure PropertyManagerObject.AddButton( var buttons: IPropertyMultiButton; btnID : LongInt; cheched, enable : Boolean );
begin
  AddButton2( buttons, btnID, btnID, cheched, enable );
end;

//------------------------------------------------------------------------------
// Добавить кнопку в набор
// ---
procedure PropertyManagerObject.AddButton2( var buttons : IPropertyMultiButton; btnID, bmpID : LongInt; cheched, enable : Boolean );
begin
  if buttons <> nil then
  begin
    with buttons do
    begin
      AddButton    ( btnID, OleVariant(bmpID), -1 );
      ButtonEnable [ btnID ] := enable;
      ButtonChecked[ btnID ] := cheched;
      ButtonTips   [ btnID ] := LoadStr(btnID);
    end;
  end
end;


//------------------------------------------------------------------------------
// Добавить кнопку в набор
// ---
procedure PropertyManagerObject.EndProcess;
begin
  BaseEvent.TerminateEvents;
end;

//------------------------------------------------------------------------------
// Найти контрол
// ---
function PropertyManagerObject.GetPropertyControl( ctrlID : LongInt ) : IPropertyControl;
var
  i, count : Integer;
  tab      : IPropertyTab;
  ctrls    : IPropertyControls;
begin
  Result := nil;
  if propTabs <> nil then
  begin
    i     := 0;
    count := propTabs.Count;
    while ( i < count ) and ( Result <> nil ) do
    begin
      tab   := propTabs.Item[i];
      if tab <> nil then
      begin
        ctrls := tab.PropertyControls;
        if ctrls <> nil then
          Result := ctrls.Item[WideString(LoadStr(ctrlID))];
      end
    end
  end
end;

//------------------------------------------------------------------------------
// Установить доступность контрола
// ---
procedure PropertyManagerObject.SetControlEnable( ctrlID : Integer; enabled : Boolean );
var
  control : IPropertyControl;
begin
  control := GetPropertyControl(ctrlID);
  if control <> nil then
    control.Enable := enabled;
end;

//------------------------------------------------------------------------------
// Создание пользовательского контрола
// ---
function PropertyManagerObject.CreateUserControl( ctrlID, height, width : LongInt ) : IPropertyUserControl;
begin
  Result := nil;
  if curentCollection <> nil then
  begin
    Result := curentCollection.Add( ksControlUser ) As IPropertyUserControl;
    if Result <> nil then
    begin
      with Result do
      begin
        NameVisibility := ksNameHorizontalVisible;
        SetOCXControl( WideString( LoadStr(ctrlID+2000) ) );
        Name           := WideString( LoadStr(ctrlID+2001) );
        Height := height;
        Width  := width;
        Id     := ctrlID;
        //PropertyUserControlEvent.Create( IDispatch(Result), ctrlID, self );
      end;
    end;
  end
end;

//------------------------------------------------------------------------------
// Контрол удаляется нужно освободить указатель
// ---
procedure PropertyManagerObject.OnDestroyOCX( ctrlID : LongInt{; var control : IDispatch} );
begin
end;

//------------------------------------------------------------------------------
// Заглушки на виртуальные функции которые можно перегоружать
//---
function PropertyManagerObject.OnButtonClick( buttonID : LongInt ) : Boolean;
begin
  Result := true;
end;

//prChangeControlValue - Изменение значения контрола
procedure PropertyManagerObject.OnChangeControlValue( {var cntrl : IPropertyControl;} ctrlID : LongInt; const Val: Variant );
begin
end;

// Событие создания ActiveX Control-a
procedure PropertyManagerObject.OnCreateOCX( ctrlID : LongInt; var control : IDispatch );
begin
end;

// Виртуальная функция наполнения контролов элемента
procedure  PropertyManagerObject.ShowControls;
begin
end;

function PropertyManagerObject.OnButtonUpdate ( buttonID : LongInt; var check : LongInt; var _enable : WordBool ) : Boolean;
begin
  check := 0;
  _enable := true;
  Result := true;
end;

// Перерисовать фантом
procedure  PropertyManagerObject.RedrawPhantom;
begin
end;

// Количество параметров выводимых в гриде
function PropertyManagerObject.GetParamCount : Integer;
begin
  Result:= 0;
end;

// Заполнение грида параметров
procedure  PropertyManagerObject.ShowParam;
begin
end;

// Функции для вывода контрола параметров штриховки
procedure PropertyManagerObject.ShowHatchControl;
begin
end;

// Функции для вывода контрола параметров штриховки
function PropertyManagerObject.GetPreviewGroup : Reference;
begin
 Result := 0;
end;

//------------------------------------------------------------------------------
// LibraryName
//---
procedure MyDLLProc(Reason: Integer);
begin
  if Reason = DLL_PROCESS_DETACH then begin
    BaseEvent.TerminateEvents;
    newKompasAPI       := nil;
    Application.Handle := 0;
  end;
end;


end.
