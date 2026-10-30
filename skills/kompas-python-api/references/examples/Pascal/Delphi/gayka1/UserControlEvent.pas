unit UserControlEvent;

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
  base,
  ManagerEvents,
{$IFDEF __LIGHT_VERSION__}
  klAPI7;
{$ELSE}
  ksAPI7;
{$ENDIF}

const
// LIBID_VCHATCHLib: TGUID = '{2AFD2EAF-A5DE-4A3D-95BA-D2C1E43C1088}';

//  DIID__DVCHatch: TGUID = '{3FFE9799-DF8D-4936-980C-BEA28964A3A7}';
  DIID__DVCHatchEvents: TGUID = '{26776524-F601-42CE-A49E-90CF804111A5}';
//  CLASS_VCHatch: TGUID = '{FFED03F1-481A-4ACD-A39E-C5D4A8828236}';
type

// *********************************************************************//
// DispIntf:  _DVCHatch
// Flags:     (4112) Hidden Dispatchable
// GUID:      {3FFE9799-DF8D-4936-980C-BEA28964A3A7}
// *********************************************************************//
  _DVCHatch = dispinterface
    ['{3FFE9799-DF8D-4936-980C-BEA28964A3A7}']
    property Angle:  Double   dispid 1;
    property Step:   Double   dispid 2;
    property Enable: WordBool dispid 3;
  end;

// *********************************************************************//
// DispIntf:  _DVCHatchEvents
// Flags:     (4096) Dispatchable
// GUID:      {26776524-F601-42CE-A49E-90CF804111A5}
// *********************************************************************//
//  _DVCHatchEvents = dispinterface
//    ['{26776524-F601-42CE-A49E-90CF804111A5}']
//    procedure ChangeAngle; dispid 1;
//    procedure ChangeStep;  dispid 2;
//  end;

//-----------------------------------------------------------------------------
// AHatchCtrlEvent  - обрабокчик событий от ocx
// ---
HatchCtrlEvent = class( BaseEvent )
protected
  obj : CPar;        // Указатель на подписанный объект
public
	constructor Create( var ctrl: IDispatch; var _obj : CPar );
  destructor  Destroy; override;

  function OnEvent( commandID : Integer; var Params : tagDISPPARAMS; var eventRes : boolean  ) : Boolean; override;

  // Изменение угла
  function OnChangeAngle() : Boolean; virtual;

  // Изменение значения
  function OnChangeStep()  : Boolean; virtual;

end;

////////////////////////////////////////////////////////////////////////////////
//
// APropertyUserControlEvent  - обрабокчик событий от пользоваиельского контрола
//
////////////////////////////////////////////////////////////////////////////////
PropertyUserControlEvent = class( BaseEvent )
protected
  obj        : PropertyManagerObject; // Указатель на подписанный объект
  controlID  : LongInt;               // Идентификатор контрола
  hatchEvent : HatchCtrlEvent;       // Интерфейс событий от контрола параметров штриховки
public
  // Конструктор
  constructor Create( var procparam : IDispatch; _controlID : LongInt; var _obj : PropertyManagerObject );
  // Диструктор
  destructor  Destroy; override;

protected

  function OnEvent( commandID : Integer; var Params : tagDISPPARAMS; var eventRes : boolean  ) : Boolean; override;

  //puCreateOCX  "Создался OCX контрол."
  function OnCreateOCX( var iOcx : IDispatch )  : Boolean; virtual;

  //puDestroyOCX "Удаляется OCX контрол."
  function OnDestroyOCX() : Boolean; virtual;

end;

implementation

////////////////////////////////////////////////////////////////////////////////
//
// AHatchCtrlEvent  - обрабокчик событий от ocx
//
////////////////////////////////////////////////////////////////////////////////
//DIID_DVCHatchEvents :           TGUID = '{26776524-f601-42ce-a49e-90cf804111a5}';

//-----------------------------------------------------------------------------
// AHatchCtrlEvent  - обрабокчик событий от ocx
// ---
constructor HatchCtrlEvent.Create( var ctrl: IDispatch; var _obj : CPar );
begin
  inherited Create( ctrl, DIID__DVCHatchEvents );
  obj := _obj;
  Advise;
end;

//-----------------------------------------------------------------------------
//
// ---
destructor HatchCtrlEvent.Destroy;
begin
  inherited Destroy;
end;

//-----------------------------------------------------------------------------
// AHatchCtrlEvent  - обрабокчик событий от ocx
// ---
function HatchCtrlEvent.OnEvent( commandID : Integer; var Params : tagDISPPARAMS; var eventRes : boolean  ) : Boolean;
begin
  Result := boolean( commandID >= 1 ) and boolean( commandID <= 2 );
  case commandID of
    1:            // Изменение угла
      eventRes := OnChangeAngle();
    2:            // Изменение шага штриховки
      eventRes := OnChangeStep();
  end;
end;


//-----------------------------------------------------------------------------
// Изменение угла
// ---
function HatchCtrlEvent.OnChangeAngle : Boolean;
  var
    hachControl : _DVCHatch;
begin
  hachControl := m_pContainer As _DVCHatch;
  if hachControl <> nil then
  begin
    obj.HatchAngle := hachControl.Angle;
    obj.Changed    := true;
    obj.RedrawPhantom();
  end;
  Result := true;
end;

//-----------------------------------------------------------------------------
// Изменение шага
// ---
function HatchCtrlEvent.OnChangeStep : Boolean;
  var
    hachControl : _DVCHatch;
begin
  hachControl := m_pContainer As _DVCHatch;
  if hachControl <> nil then
  begin
    obj.HatchStep := hachControl.Step;
    obj.Changed    := true;
    obj.RedrawPhantom();
  end;
  Result := true;
end;

////////////////////////////////////////////////////////////////////////////////
//
// APropertyUserControlEvent  - обрабокчик событий от пользоваиельского контрола
//
////////////////////////////////////////////////////////////////////////////////
//protected
//  obj        : PropertyManagerObject; // Указатель на подписанный объект
//  controlID  : LongInt;               // Идентификатор контрола
//  hatchEvent : HatchCtrlEvent;       // Интерфейс событий от контрола параметров штриховки
//public

// Конструктор
constructor PropertyUserControlEvent.Create( var procparam : IDispatch; _controlID : LongInt; var _obj : PropertyManagerObject );
begin
  inherited Create( procparam, DIID_ksPropertyUserControlNotify );
  controlID := _controlID;
  obj := _obj;
  Advise;
end;

// Диструктор
destructor PropertyUserControlEvent.Destroy;
begin
  inherited Destroy;
end;

// обработка событий
function PropertyUserControlEvent.OnEvent( commandID : Integer; var Params : tagDISPPARAMS; var eventRes : boolean  ) : Boolean;
begin

  Result := ( commandID = puCreateOCX ) or ( commandID = puDestroyOCX );

  case commandID of
    // Событие создания пользовательского контрола
    puCreateOCX :
      OnCreateOCX( IDispatch( Params.rgvarg^[0].dispVal ) );

    // Событие удаления пользовательского контрола
    puDestroyOCX :
      OnDestroyOCX();
  end;

end;

//puCreateOCX  "Создался OCX контрол."
function PropertyUserControlEvent.OnCreateOCX( var iOcx : IDispatch )  : Boolean;
begin
  if iOcx <> nil then
  begin
    obj.OnCreateOCX( controlID, iOcx );
    hatchEvent := HatchCtrlEvent.Create( iOcx, CPar(obj) );
  end;
  Result := true;
end;

//puDestroyOCX "Удаляется OCX контрол."
function PropertyUserControlEvent.OnDestroyOCX() : Boolean;
begin
  if hatchEvent <> nil then
  begin
    obj.OnDestroyOCX( controlID{, m_pContainer} );
    hatchEvent := nil;
  end;
  Result := true;
end;

end.
