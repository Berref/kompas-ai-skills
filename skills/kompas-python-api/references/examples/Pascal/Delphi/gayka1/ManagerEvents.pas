unit ManagerEvents;

{$IFDEF CONDITIONALEXPRESSIONS}
{$IF CompilerVersion >= 14 }
  {$WARN SYMBOL_PLATFORM OFF}
{$IFEND}
{$ENDIF}

interface

uses
  Windows,
  LDefin2D,
  ksAuto,
  contnrs,
  ComObj,
  classes,
  ActiveX,
  ksConstTLB,
  LibTool,
  forms,
  Sysutils,
  GaykaRC,
{$IFDEF __LIGHT_VERSION__}
  klAPI7;
{$ELSE}
  ksAPI7;
{$ENDIF}

//function LibMessage( str : PChar; flags : LongInt ) : Integer;

type

////////////////////////////////////////////////////////////////////////////////
//
// Базовый класс для обслуживания панели свойств
//
// ctrlID используется как идентивикатор контрола и как идентификатор для загрузки
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

_DVCHatch = dispinterface
    ['{3FFE9799-DF8D-4936-980C-BEA28964A3A7}']
    property Angle:  Double   dispid 1;
    property Step:   Double   dispid 2;
    property Enable: WordBool dispid 3;
  end;

////////////////////////////////////////////////////////////////////////////////
//
// Класс для обслуживания панели свойств
//
// ctrlID используется как идентивикатор контрола и как идентификатор для загрузки
// ресурсов контрола
//
////////////////////////////////////////////////////////////////////////////////
PPropertyManagerObject = ^PropertyManagerObject;
PropertyManagerObject = class
protected
  m_flagMode       : Boolean;               // Признак редактирования по дабл-клику
  m_changed        : Boolean;               // Признак изменения параметров
  procParam        : IProcessParam;     // Параметры процесса
  propTabs         : IPropertyTabs;     // Закладки
  curentCollection : IPropertyControls; // Контролы текущей закладки панели свойств
  hatchCtrl        : _DVCHatch;             // Контрол - параметры штриховки
  paramGrid        : IPropertyGrid;     // Грид для вывода дополнительных параметров элемента
  slideBox         : IPropertySlideBox; // Окно просмотра
  rowIndex         : Integer;               // Индекс строки
  posLiaderParam   : IProcessParam;     // Параметры процесса указания линии выноски
public
  constructor Create;
  destructor  Destroy; override;
// Менеджер свойств ############################################################
  // События
  // prButtonClick - Нажатие кнопки.
  procedure OnButtonClick( buttonID : LongInt );  virtual;

  // prChangeControlValue - Изменение значения контрола
  procedure OnChangeControlValue( {var cntrl : IPropertyControl,} ctrlID : LongInt; const Val: Variant ); virtual;

  // prControlCommand Нажатие кнопки контрола
//  procedure OnControlCommand( var ctrl : IUnknown ) : boolean; virtual;

//    //prButtonUpdate        - Установка состояния кнопки спецпанели.
//  procedure OnButtonUpdate(long buttonID, long* check, WordBool* _enable) { return true; }
// Событие создания ActiveX Control-a
  procedure OnCreateOCX( ctrlID : LongInt; var control : IDispatch ); virtual;

  // Событие удаления ActiveX Control-a
  procedure OnDestroyOCX( ctrlID : LongInt{; var control :IDispatch} ); virtual;

  // Признак изменения параметров
  property  Changed : Boolean  read m_changed  write m_changed;

protected
          // Инициализация параметров процесса
  function InitProcessParam( toolBarID, firstTabID : LongInt; toolBarType : SpecPropertyToolBarEnum ) : Boolean;
          // Инициализация параметров процесса указания позиционной линии выноски
  function InitPosLeaderParam : Boolean;
          // Добавление закладки
  function CreateTab( tabID : LongInt; {visible,} active : Boolean ) : Boolean;
//            // Добавление редактора вещественного значения
//    void    /*   IPropertyRealEdit* */ CreateRealEdit( long ctrlID, double value, double minVal = 0, double maxVal = 100, bool enable = true );

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

  // Скрыть - показать закладку
//  procedure   SetTabVisible( long tabID, bool visible );
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
  procedure AddStringToGrig( paramID : LongInt; value : WideString ); // Добавление строкового значения
  procedure AddDoubleToGrig( paramID : LongInt; value : Double ); // Добавление числового  значения

  // Признак наличия штриховки у объекта
  function  IsHatchObject : Boolean; virtual;

  // Функции для вывода контрола параметров штриховки
  procedure ShowHatchControl;        virtual;

  // Завершить процесс редактирования
  procedure EndProcess();
  // Менеджер свойств ##########################################################
  function  GetPreviewGroup : Reference; virtual;

// Свойства:
  // Количество параметров
  property  ParamCount : Integer read GetParamCount;

end;

////////////////////////////////////////////////////////////////////////////////
//
// PropertyManagerEvent - обрабокчик событий от менеджера панели свойств
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
  // function OnButtonUpdate ( buttonID : LongInt; var check : LongInt; var _enable : WordBool ) : Boolean; virtual;

  // prProcessActivate    - Начало процесса
  // function OnProcessActivate : Boolean; virtual;

  // prProcessDeactivate  - Завершение процесса
  // function OnProcessDeactivate : Boolean; virtual;
end;

EventList = class ( TObjectList ) // (TInterfaceList)
public
  constructor Create; overload;
  procedure Notify(Ptr: Pointer; Action: TListNotification); override;
end;

procedure MyDLLProc(Reason: Integer);

var
  newKompasAPI : IApplication;

implementation
uses
  Base,
  UserControlEvent;

var
  m_BaseEventList : EventList; // static BaseEvent

// Удаление листа из списка
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
// Диструктор
//---
destructor BaseEvent.Destroy();
//var
//  index : integer;
begin
  if ( m_BaseEventList <> nil ) then begin
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

//  if not find then begin
//    Result  := S_OK;
//    fResult := true;
//  end;

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
  Count:=0; Result:=S_OK;
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

procedure OpenHelp( id : Integer );
  var
    gaykaHlp : array [0..260] of AnsiChar;
begin
  if ( GetFullName( 'gayka.hlp', gaykaHlp ) > 0 ) then
      ksOpenHelpFile( gaykaHlp, HELP_CONTEXT, id );
end;

//------------------------------------------------------------------------------
// prButtonClick - Нажатие кнопки.
//---
function PropertyManagerEvent.OnButtonClick( buttonID : LongInt ) : Boolean;
begin
  if buttonID = pbHelp then
    OpenHelp( 1 );
//  else
//    if ( obj.OnButtonClick( buttonID ) )
//      obj.RedrawPhantom();
  Result := true;
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
      if obj.Changed then
        obj.RedrawPhantom();
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
  if obj.Changed then
     obj.RedrawPhantom();
  Result := true;
end;

//------------------------------------------------------------------------------
// prButtonUpdate        - Установка состояния кнопки спецпанели.
//---
//function PropertyManagerEvent.OnButtonUpdate( buttonID : LongInt; var check : LongInt; var _enable : WordBool ) : Boolean; virtual;
//begin
//  Result := true;
//end;

//------------------------------------------------------------------------------
// prProcessActivate    - Начало процесса
//---
//function PropertyManagerEvent.ProcessActivate : Boolean;
//begin
//  Result := true;
//end;

//------------------------------------------------------------------------------
//prProcessDeactivate  - Завершение процесса
//---
//  function PropertyManagerEvent.ProcessDeactivate : Boolean;
//begin
//  Result := true;
//end;


//------------------------------------------------------------------------------
// Диструктор событий
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

//    prButtonUpdate:                     // Переключение на другой активный документ
//      eventRes := OnButtonUpdate( Params.rgvarg^[2].intVal, Params.rgvarg^[1].pIntVal^, Params.rgvarg^[0].pbool^ );

//    prProcessActivate:                  // Начало процесса
//      eventRes := OnProcessActivate;

//    prProcessDeactivate:                // Завершение процесса
//      eventRes := OnProcessDeactivate
    prCommandHelp :
    begin
      OpenHelp( 1 ); // Params.rgvarg^[0].lVal );
      eventRes := true;
    end;
  end;

end;

//------------------------------------------------------------------------------
// Вспомогательная функция, возвращающая информацию об ошибке
// ---
//procedure DumpError( var e : TOleError );
//begin
//end;

//------------------------------------------------------------------------------
// Вспомогательная функция, возвращающая информацию об ошибке
// ---
//procedure ShowError()
//begin
//  IErrorInfoPtr ef;
//  GetErrorInfo( NULL, &ef );
//  BSTR                bstrDescription;
//  ef->GetDescription( &bstrDescription );
//  USES_CONVERSION;
//  LibMessage( OLE2T(bstrDescription), MB_OK | MB_ICONERROR );
//end;


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
  hatchCtrl        := nil;  // Контрол - параметры штриховки
  paramGrid        := nil;  // Грид для вывода дополнительных параметров элемента
  slideBox         := nil;  // Окно просмотра
  rowIndex         := 0;    // Индекс строки
  posLiaderParam   := nil;  //
  m_flagMode       := False;//
end;

//------------------------------------------------------------------------------
// Диструктор
// ---
destructor PropertyManagerObject.Destroy;
begin
  BaseEvent.TerminateEvents;
  hatchCtrl        := nil;  // Контрол - параметры штриховки
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
function PropertyManagerObject.InitProcessParam( toolBarID, firstTabID: LongInt; toolBarType : SpecPropertyToolBarEnum ) : Boolean;
var
  gr       : reference;
  parCount : Integer;
begin
  Result := false;
  GetNewKompasAPI();                                                            // Захватываем Компас Api
  if newKompasAPI <> nil then
  begin
    procParam := newKompasAPI.CreateProcessParam;          // newKompasAPI->CreateProcessParam();                 // Получаем параметры процессы
    if procParam <> nil then
    begin
      PropertyManagerEvent.Create( IDispatch(procParam), Self );                // Подписываемся на события процесса
      with procParam do
      begin
        // Получаем интерфейс панели свойств
        SpecToolbar := toolBarType;                                 // Тип кнопок на панели свойств
        Caption     := WideString( LoadStr_(toolBarID) );           // Устанавливаем заголовок панели свойств
        AutoReduce  := not m_flagMode;                              // Автосоздание объекта

        if m_flagMode then
          DefaultControlFix := ksAllFix;

        // Получаем коллекцию закладок панели свойств
        propTabs := PropertyTabs;

        // Создаем закладку параметров элемента
        if firstTabID <> 0 then
          CreateTab( firstTabID, {true,} true );
        // Наполнение закладки контролами для вывода параметров элемента
        ShowControls();
        // Создать окно просмотра
        // Отрисовка группы в окне просмотра
        gr := GetPreviewGroup();
        if gr <> 0 then
        begin
          slideBox := curentCollection.Add( ksControlSlideBox ) As IPropertySlideBox;
          if slideBox <> nil then
          begin
            with slideBox do
            begin
              SlideType    := ksGroup;           // Отрисовываем группу
              DrawingSlide := gr;                // Передаем reference группы
              Hint         := 'Hint для слайда';
              Tips         := 'Tips для слайда';
              Id           := 10000;
              Name         := 'Окно просмотра';
              height       := 100;
              width        := 150;
            end
          end
        end;
        parCount := ParamCount;                               // Нужно ли выводить грид ?
        if ( parCount <> 0 ) or IsHatchObject then
        begin
          CreateTab( IDP_ELEMENT_PARAM, false );              // Грид будем создавать на новой закладке
          if IsHatchObject then
            ShowHatchControl();

          if paramCount <> 0 then
          begin
            // Создание грида
            paramGrid := curentCollection.Add( ksControlGrid ) as IPropertyGrid;
            if paramGrid <> nil then
            begin
              with paramGrid do
              begin
                ColumnCount      := 2;                        // Количество колонок грида
                FixedColumnCount := 1;                        // Первая колонка редактироваться не будет
                FixedRowCount    := 1;                        // Заголовок таблицы
                RowCount         := paramCount + 1;           // Количество отображаемых строк в гриде
                AutoSizeColumns  := true;                     // Автоматически изменять ширину колонок
                Hint             := 'Hint для грида';
                Tips             := 'Tips для грида';
                Id               := 10001;
                rowIndex := 0;                                           // Индекс строки

                AddStringToGrig( IDS_PARAM_CAPTION, LoadStrW(IDS_VALUE_CAPTION) );
                ShowParam();                                            // Вывод параметров в гриде
                RowCount         := rowIndex;
                Height           := rowIndex * 20;
                Name             := 'Параметры элемента';
              end;
              // Выводим надписи

            end
          end
        end;

      Result := true;
      end
    end
  end;
end;

//------------------------------------------------------------------------------
// Создать закладку параметров создания
// Позиционной линии выноски
// ---
function PropertyManagerObject.InitPosLeaderParam : Boolean;
var
  liaderPropTabs : IPropertyTabs;
  propTab        : IPropertyTab;
  ctrlCollection : IPropertyControls;
  buttons        : IPropertyMultiButton;
begin
  Result := posLiaderParam <> nil;
  // Если для объекта есть возможность создания объекта спецификации
  if (newKompasAPI <> nil) and ( posLiaderParam = nil ) then
  begin
    posLiaderParam := newKompasAPI.CreateProcessParam;                 // newKompasAPI->CreateProcessParam();                 // Получаем параметры процессы
    if posLiaderParam <> nil then
    begin
      PropertyManagerEvent.Create( IDispatch(posLiaderParam), Self );                 // Подписываемся на события процесса

      // Получаем коллекцию закладок панели свойств
      liaderPropTabs := posLiaderParam.PropertyTabs;
      if liaderPropTabs <> nil then
      begin
        propTab := liaderPropTabs.Add( WideString( LoadStr_(IDP_POS_LEADER) ) );
        if propTab <> nil then
        begin

          ctrlCollection := propTab.PropertyControls;
          if ctrlCollection <> nil then
          begin
            buttons := ctrlCollection.Add(ksControlMultiButton) as IPropertyMultiButton;
            if buttons <> nil then
            begin
              InitPropertyControl( IPropertyControl(buttons), ID_LEADER_CREATE, IDS_LEADER_HINT, IDS_LEADER_TIPS,  ksNameAlwaysVisible, true, true );
              buttons.ButtonsType := ksPushButton;
              buttons.ResModule   := OleVariant( LONG_PTR(hInstance) );
            end
          end
        end;

        Result := true;
      end
    end
  end
end;


//------------------------------------------------------------------------------
// Добавить параметр в грид
// ---
procedure PropertyManagerObject.AddStringToGrig( paramID : LongInt; value : WideString );
begin
  if paramGrid <> nil then
  begin
    paramGrid.CellText[ rowIndex, 1 ] := value;
    paramGrid.CellText[ rowIndex, 0 ] := LoadStrW(paramID); // Не переставлять так задумано
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
//      if not visible then
//        propTab.Visible := visible;
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
        PropertyUserControlEvent.Create( IDispatch(Result), ctrlID, self );
      end;
    end;
  end
end;

//------------------------------------------------------------------------------
// Контрол удаляется нужно освободить указатель
// ---
procedure PropertyManagerObject.OnDestroyOCX( ctrlID : LongInt{; var control : IDispatch} );
begin
  if ctrlID = IDP_HATCH_PARAM then
    hatchCtrl := nil;
end;

//------------------------------------------------------------------------------
// Заглушки на виртуальные функции которые можно перегоружать
//---
procedure PropertyManagerObject.OnButtonClick( buttonID : LongInt );
begin
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

// Признак наличия штриховки у объекта
function PropertyManagerObject.IsHatchObject : Boolean;
begin
  Result:= false;
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

// prControlCommand Нажатие кнопки контрола
//function PropertyManagerObject.OnControlCommand( var ctrl : IUnknown ) : boolean;
//begin
//  Result := true;
//end;
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



