unit BaseEvents;

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
  events,
  ksConstTLB,
  forms,
  ksTLB;

function LibMessage( str : PChar; flags : LongInt ) : Integer;
function GetActiveDocumentReference( docType: Integer ) : Reference;
procedure ActivateDoc( pDoc :Reference );

type

PBaseEvent = ^BaseEvent;
BaseEvent = class (TInterfacedObject, IDispatch )
  private

  m_dwCookie  : LongInt;
  m_iidEvents : TGUID;
  m_pContainer: IDispatch;
  m_Obj       : LongInt;
  pDoc        : Reference;

public
  constructor Create( const pObject : IDispatch; iidEvents : TGUID; doc : Reference; obj : LongInt ); overload;
  destructor  Destroy(); override;
  function    Advise() : boolean; virtual; stdcall;
  procedure   Unadvise(); stdcall;

  class procedure TerminateEvents();
  class procedure TerminateEventsFromIID( const iid : TGUID; doc : Reference; objType : LongInt );
  class function  FindEvent( iid : TGUID; doc : Reference; objType : Integer  ) : boolean;

    function GetTypeInfo(Index, LocaleID: Integer; out TypeInfo): HResult; stdcall;
    function GetTypeInfoCount(out Count: Integer): HResult; stdcall;
    function GetIDsOfNames(const IID: TGUID; Names: Pointer; NameCount,
                           LocaleID: Integer; DispIDs: Pointer): HResult; stdcall;

    function Invoke(eventID: Integer; const IID: TGUID; LocaleID: Integer;
                    Flags: Word; var Params; VarResult, ExcepInfo, ArgErr: Pointer): HResult;
                    stdcall;
    function QueryInterface(const IID: TGUID; out Obj): HResult; stdcall;
private
    function OnEvent( commandID : Integer; var Params : tagDISPPARAMS; var eventRes : boolean  ) : boolean; virtual;
end;

////////////////////////////////////////////////////////////////////////////////
//
// ApplicationEvent  - обрабокчик событий от Компаса
//
////////////////////////////////////////////////////////////////////////////////
ApplicationEvent = class( BaseEvent )

public
	constructor Create( const pObject : IDispatch ); overload;
  destructor  Destroy(); override;

protected
  function OnEvent( commandID : Integer; var Params : tagDISPPARAMS; var eventRes : boolean  ) : boolean; override;
  // koCreateDocument - создание документа
  function OnCreateDocument( newDoc : IDispatch; docType : integer ) : boolean; virtual;
  // koOpenDocumenBegin - Начало открытия документа
  function OnBeginOpenDocument( var fileName: String ) : boolean;  virtual;
  // koOpenDocumen - Документ открыт
  function OnOpenDocument( newDoc : IDispatch; docType : integer ) : boolean;  virtual;
  // koActiveDocument - Переключение на другой активный документ
  function OnChangeActiveDocument( newDoc : IDispatch; docType : integer ) : boolean; virtual;
  // koApplicatinDestroy - Закрытие приложения
  function OnApplicationDestroy() : boolean;  virtual;
   // koBeginCreate - Начало создания документа(до диалога выбора типа)
  function OnBeginCreate( docType : integer ) : boolean;  virtual;
  // koBeginOpenFile - Начало открытия документа(до диалога выбора имени)
  function OnBeginOpenFile() : boolean;  virtual;
  // koBeginCloseAllDocument - Закрываются все документы
  function OnBeginCloseAllDocument(): boolean;  virtual;
end;

////////////////////////////////////////////////////////////////////////////////
//
// DocumentEvent  - обрабокчик событий от документа
//
////////////////////////////////////////////////////////////////////////////////
PDocumentEvent = ^DocumentEvent;
DocumentEvent = class ( BaseEvent )
  private
    pObject : IDispatch;
public
	constructor Create( refDoc : Reference ); overload;
  destructor  Destroy(); override;

protected
  function OnEvent( commandID : Integer; var Params : tagDISPPARAMS; var eventRes : boolean  ) : boolean; override;

  //kdBeginCloseDocument - Начало закрытия документа.
  function OnBeginCloseDocument() : boolean; virtual;
  //kdCloseDocument - Документ закрыт.
  function OnCloseDocument() : boolean; virtual;
  //kdBeginSaveDocument - Начало сохранения документа.
  function OnBeginSaveDocument( fileName : string ) : boolean;  virtual;
  //kdSaveDocument - Документ сохранен.
  function OnSaveDocument()  : boolean; virtual;
  //kdActiveDocument - Документ активизирован.
  function OnActivate()      : boolean; virtual;
  //kdDeactiveDocument - Документ деактивизирован.
  function OnDeactivate()    : boolean; virtual;
  // kdBeginSaveAsDocument - Начало сохранения документа c другим именем (до диалога выбора имени)
  function OnBeginSaveAsDocument() : boolean; virtual;

end;

////////////////////////////////////////////////////////////////////////////////
//
// Object2DEvent  - обрабокчик событий от 2D документа
//
////////////////////////////////////////////////////////////////////////////////
PObj2DEvent = ^Obj2DEvent;
Obj2DEvent = class ( BaseEvent )
private
  objNotify : Object2DNotify;

// Attributes
public
	constructor Create( objType : LongInt; refDoc : Reference ); overload;
  destructor  Destroy(); override;

protected
  function OnEvent( commandID : Integer; var Params : tagDISPPARAMS; var eventRes : boolean  ) : boolean; override;

//  koChangeActive = $00000001;           // Переключение активности объекта( вид, слой)
  function OnChangeActive( obj : Reference ): boolean;  virtual;
//  koBeginDelete = $00000002;            // Начало удаления объекта
  function OnBeginDelete( obj : Reference  ): boolean;  virtual;
//  koDelete = $00000003;                 // Удаление объекта
  function OnDelete( obj : Reference ): boolean;  virtual;
//  koBeginMove = $00000004;              // Начало сдвига объекта
  function OnBeginMove( obj : Reference ): boolean;  virtual;
//  koMove = $00000005;                   // Сдвиг объекта
  function OnMove( obj : Reference ): boolean;  virtual;
//  koBeginRotate = $00000006;            // Начало поворота объекта
  function OnBeginRotate( obj : Reference ): boolean;  virtual;
//  koRotate = $00000007;                 // Поворот объекта
  function OnRotate( obj : Reference ): boolean;  virtual;
//  koBeginScale = $00000008;             // Начало масштабирования объекта
  function OnBeginScale( obj : Reference ): boolean;  virtual;
//  koScale = $00000009;                  // Масштабирования объекта
  function OnScale( obj : Reference ): boolean;  virtual;
//  koBeginTransform = $0000000A;         // Начало трансформации объекта
  function OnBeginTransform( obj : Reference ): boolean;  virtual;
//  koTransform = $0000000B;              // Трансформация объекта
  function OnTransform( obj : Reference ): boolean; virtual;
//  koBeginCopy = $0000000C;              // Начало копирования объекта
  function OnBeginCopy( obj : Reference ): boolean; virtual;
//  koCopy = $0000000D;                   // Копирование объекта
  function OnCopy( obj : Reference ): boolean; virtual;
//  koBeginSymmetry = $0000000E;          // Начало симметрии  объекта
  function OnBeginSymmetry( obj : Reference ): boolean; virtual;
//  koSymmetry = $0000000F;               // Симметрия  объекта
  function OnSymmetry( obj : Reference ): boolean;  virtual;
// koBeginProcess = $00000010;
  function OnBeginProcess( _type : LongInt; obj : Reference ): boolean;  virtual;
// koBeginProcess = $00000011;
  function OnEndProcess( _type : LongInt ): boolean;  virtual;
// koCreateObject = $00000012;
  function OnCreateObject( obj : Reference ): boolean;  virtual;
// koUpdateObject = $00000013;
  function OnUpdateObject( obj : Reference ): boolean;  virtual;

end;

////////////////////////////////////////////////////////////////////////////////
//
// SelectMngEvent  - обрабокчик событий менеджера селектирования
//
////////////////////////////////////////////////////////////////////////////////
SelectMngEvent = class ( BaseEvent )
private
  selNotify : SelectionMngNotify;
// Attributes
public
	constructor Create( doc : Reference ); overload;
  destructor  Destroy(); override;

protected
  function OnEvent( commandID : Integer; var Params : tagDISPPARAMS; var eventRes : boolean  ) : boolean; override;

//  ksmSelect = $00000001;           // Переключение активности объекта( вид, слой)
  function OnSelect( var obj : OleVariant ): boolean;  virtual;
//  ksmUnselect = $00000002;         // Начало удаления объекта
  function OnUnselect( var obj : OleVariant  ): boolean;  virtual;
//  ksmUnselectAll = $00000003;         // Начало удаления объекта
  function OnUnselectAll(): boolean;  virtual;

end;

////////////////////////////////////////////////////////////////////////////////
//
// StampEvents - обрабокчик событий редактирования штампа
//
////////////////////////////////////////////////////////////////////////////////
PStampEvents = ^StampEvents;
StampEvents = class ( BaseEvent )
private
  stamp     : ksStamp;
// Attributes
public
	constructor Create( doc : Reference ); overload;
  destructor  Destroy(); override;

protected
  function OnEvent( commandID : Integer; var Params : tagDISPPARAMS; var eventRes : boolean  ) : boolean; override;

//  kdBeginEditStamp = $00000001;           // Переключение активности объекта( вид, слой)
  function OnBeginEdit(): boolean;  virtual;
//  kdEndEditStamp = $00000002;         // Начало удаления объекта
  function OnEndEdit( editResult : boolean ): boolean;  virtual;
//  kdStampCellDblClick = $00000003;         // Начало удаления объекта
  function OnCellDblClick( number : integer ): boolean;  virtual;
//  kdStampCellBeginEdit
  function OnCellBeginEdit( number : integer ): boolean;  virtual;

end;


EventList = class ( TObjectList )
public
  constructor Create; overload;
  procedure Notify(Ptr: Pointer; Action: TListNotification); override;
end;

function NewObj2DEvent( pDoc : reference; objType : LongInt ) : Obj2DEvent;
function NewStampEvents( pDoc : reference ) : StampEvents;
function NewDocumentEvent( pDoc : reference ) : DocumentEvent;
function NewSelectMngEvent( pDoc : reference ) : SelectMngEvent;

implementation
var
  m_BaseEventList : EventList; // static BaseEvent

function LibMessage( str : PChar; flags : LongInt ) : Integer;
begin
  Result := Application.MessageBox( str, PChar(string(LIBRARYNAME)), flags );
end;

procedure EventList.Notify(Ptr: Pointer; Action: TListNotification);
begin
  if OwnsObjects then
    if Action = lnDeleted then begin
//      BaseEvent(Ptr).Free;
      BaseEvent(Ptr).UnAdvise;
      exit;
    end;
  inherited Notify(Ptr, Action);
end;

constructor EventList.Create();
begin
  inherited Create;
end;

{------------------------------------------------------------------------------}
{                               Конструктор                                    }
{------------------------------------------------------------------------------}
constructor BaseEvent.Create( const pObject : IDispatch; iidEvents : TGUID; doc : Reference; obj : LongInt );
begin
  if  m_BaseEventList = nil then
    m_BaseEventList := EventList.Create;
  m_pContainer := pObject;
  if ( m_pContainer <> nil ) then
    m_pContainer._AddRef;
  pDoc := doc;
  m_iidEvents  := iidEvents;
  m_dwCookie   := 0;
  m_Obj        := obj;
  m_BaseEventList.Add( Pointer(Self) );
end;
{------------------------------------------------------------------------------}

{------------------------------------------------------------------------------}
{                               Конструктор                                    }
{------------------------------------------------------------------------------}
destructor BaseEvent.Destroy();
var
  index : integer;
begin
  Unadvise();              // отпишемся от получения событий
  if ( m_BaseEventList <> nil ) then begin
    index := m_BaseEventList.IndexOf( Self );
    if index >= 0 then  begin
      m_BaseEventList.Items[index] :=nil;
      m_BaseEventList.Delete(index);
    end;
    m_pContainer := nil;
  end
end;

{------------------------------------------------------------------------------}
{                     Реализация метода Invoke IDispatch                       }
{------------------------------------------------------------------------------}
function BaseEvent.Invoke( eventID: Integer; const IID: TGUID; LocaleID: Integer;
                           Flags: Word; var Params; VarResult, ExcepInfo,
                           ArgErr: Pointer): HResult;
var
  ProcParams: tagDISPPARAMS;
  Res: ^OleVariant;
  fResult, find : boolean;
begin
  Result     := S_OK;
  Res        := VarResult;
  ProcParams := TDispParams(Params);
  fResult    := true;

  find := OnEvent( eventID, ProcParams, fResult );

  if not find then begin
    Result  := DISP_E_MEMBERNOTFOUND;
    fResult := true;
  end;

  if Res <> nil then begin
    Res^ := fResult;
  end;
end;

{------------------------------------------------------------------------------}

{------------------------------------------------------------------------------}
{                  Реализация метода GetTypeInfo IDispatch                     }
{------------------------------------------------------------------------------}
function BaseEvent.GetTypeInfo(Index, LocaleID: Integer; out TypeInfo): HResult;
begin
  Result:=E_NOTIMPL;
end;
{------------------------------------------------------------------------------}

{------------------------------------------------------------------------------}
{                Реализация метода GetTypeInfoCount IDispatch                  }
{------------------------------------------------------------------------------}
function BaseEvent.GetTypeInfoCount(out Count: Integer): HResult;
begin
  Count:=0; Result:=S_OK;
end;

{------------------------------------------------------------------------------}
{                 Реализация метода GetIDsOfNames IDispatch                    }
{------------------------------------------------------------------------------}
function BaseEvent.GetIDsOfNames(const IID: TGUID; Names: Pointer; NameCount,
                                  LocaleID: Integer; DispIDs: Pointer): HResult;
begin
  Result := S_OK;
end;

function  BaseEvent.Advise() : boolean; stdcall;
begin
  if ( m_dwCookie = 0) And  (m_pContainer <> nil) then
    InterfaceConnect( m_pContainer, m_iidEvents, IDispatch( self ), m_dwCookie );
	Result := m_dwCookie <> 0;
end;

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

class procedure BaseEvent.TerminateEvents();
begin
  if  m_BaseEventList <> nil then begin
    m_BaseEventList.Free;
    m_BaseEventList := nil;
  end
end;

class procedure BaseEvent.TerminateEventsFromIID( const iid : TGUID; doc: Reference; objType : Integer );
var
  i     : Integer;
//  p     : Pointer;
  p : BaseEvent;
begin
  if  m_BaseEventList <> nil then begin
    i := m_BaseEventList.Count - 1;
    while i >= 0 do
    begin
      p := BaseEvent( m_BaseEventList.Items[i] );
      if ( ( doc = 0 ) or ( doc = BaseEvent(p).pDoc ) ) and
         ( IsEqualGuid( iid, GUID_NULL ) or IsEqualGuid( iid , BaseEvent(p).m_iidEvents ) ) and
         ( ( objType = -1 ) or ( objType = BaseEvent(p).m_Obj ) ) then
      begin
        m_BaseEventList.Remove( p );
      end;
      Dec(i);
    end
  end
end;

class function BaseEvent.FindEvent( iid : TGUID; doc: Reference; objType : Integer  ): boolean;
  var
    i, count : Integer;
    p        : Pointer;
    find     : Boolean;
begin
  find := false;
	i := 0;
  if m_BaseEventList <> nil then begin
    count := m_BaseEventList.Count;
    while (i < count) and not find do
    begin
      p := m_BaseEventList.Items[i];
      if ( p <> nil ) and  ( ( doc = 0 ) or  ( BaseEvent(p).pDoc = doc ) ) and
        ( IsEqualIID( iid, GUID_NULL ) or IsEqualIID( BaseEvent(p).m_iidEvents, iid ) ) and
        ( ( objType = -1 ) or ( objType = BaseEvent(p).m_Obj ) )
          then
      begin
        find := true;
      end;
      Inc(i);
    end;
  end;
  Result := find;
end;

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

function BaseEvent.OnEvent( commandID : Integer; var Params : tagDISPPARAMS; var eventRes : boolean ) : boolean;
begin
  eventRes := true;
  Result := true;
end;

constructor ApplicationEvent.Create( const pObject : IDispatch );
begin
  inherited Create( pObject, DIID_ksKompasObjectNotify, 0, 0 );
end;


function ApplicationEvent.OnCreateDocument( newDoc : IDispatch; docType : integer ) : boolean;
begin
  LibMessage( 'Был создан новый документ', MB_OK );
  Result := true;
end;
  // koOpenDocumenBegin - Начало открытия документа
function ApplicationEvent.OnBeginOpenDocument( var fileName: String ) : boolean;
  var
    mes : string;
begin
  mes := 'Открывается документ ' + fileName + #13#10 + 'Продолжить?';
  Result := LibMessage( PChar( mes ), MB_YESNO ) = ID_YES;
end;

  // koOpenDocumen - Документ открыт
function ApplicationEvent.OnOpenDocument( newDoc : IDispatch; docType : integer ) : boolean;
begin
  LibMessage( 'Был открыт документ', MB_OK );
  Result := true;
end;

// koActiveDocument - Переключение на другой активный документ
function ApplicationEvent.OnChangeActiveDocument( newDoc : IDispatch; docType : integer ) : boolean;
begin
  LibMessage( 'Был активизирован документ', MB_OK );
  Result := true;
end;

function CreateDocument2D( docType : integer ) : reference;
var
  docParam : ksDocumentParam;
  doc2D    : ksDocument2D;
begin
  docParam := ksDocumentParam( iKompasObject.GetParamStruct( ko_DocumentParam ) );
  docParam.Init;
	docParam.type_ := docType;
  doc2D  := ksDocument2D( iKompasObject.Document2D );
  doc2D.ksCreateDocument( docParam );
  Result := doc2D.reference;
end;

function CreateDocument3D( docType : integer ) : reference;
var
  doc3D  : ksDocument3D;
begin
  doc3D  := ksDocument3D( iKompasObject.Document3D );
  doc3D.Create( true, docType = lt_DocPart3D );
  Result := doc3D.reference;
end;

function CreateDocumentTxt( docType : integer ) : reference;
var
  docParam : ksTextDocumentParam;
  docTxt   : ksDocumentTxt;
begin
  docParam := ksTextDocumentParam( iKompasObject.GetParamStruct( ko_TextDocumentParam ) );
  docParam.Init;
	docParam.type_ := docType;
  docTxt := ksDocumentTxt( iKompasObject.DocumentTxt );
  docTxt.ksCreateDocument( docParam );
  Result := docTxt.reference;
end;

function CreateDocumentSpc( docType : integer ) : reference;
var
  docParam : ksDocumentParam;
  spcDoc   : ksSpcDocument;
begin
  docParam := ksDocumentParam( iKompasObject.GetParamStruct( ko_DocumentParam ) );
  docParam.Init;
	docParam.type_ := docType;
  spcDoc := ksSpcDocument( iKompasObject.SpcDocument );
  spcDoc.ksCreateDocument( docParam );
  Result := spcDoc.reference;
end;

function CreateDocumentByType( docType : integer ) : reference;
begin
  if docType = 0 then
    docType := lt_DocSheetStandart;
  case docType of
    lt_DocTxtStandart,
    lt_DocTxtUser:
      Result := CreateDocumentTxt( docType );
    lt_DocPart3D,
    lt_DocAssemble3D:
      Result := CreateDocument3D( docType );
    lt_DocSpc,
    lt_DocSpcUser:
      Result := CreateDocumentSpc( docType )
    else
      Result := CreateDocument2D( docType );
  end
end;

// koApplicatinDestroy - Закрытие приложения
function ApplicationEvent.OnApplicationDestroy() : boolean;
begin
  LibMessage( 'Pавершается работа в Компасе', MB_OK );
  TerminateEvents;
  iKompasObject := nil;
  Result := true;
end;

// koBeginCreate - Процесс создания документа
function ApplicationEvent.OnBeginCreate( docType : integer ) : boolean;
var
  mes : string;
  res : Integer;
begin
  mes := 'ApplicationEvent::BeginCreate'                     + #13#10 +
         'Да - Создать документ'                             + #13#10 +
  	     'Нет - запустить стандартный диалог создания файла' + #13#10 +
				 'Отмена - не создавать файл';
  Result := true;
  res := LibMessage( PChar( mes ), MB_YESNOCANCEL );
  case res of
    ID_YES:
			Result := not boolean( CreateDocumentByType(docType) ); // Если документ создан стандартный диалог не нужен
		ID_CANCEL:
			Result := false;
    ID_NO:
      Result := true;
  end;
end;

// koBeginOpenFile - Процесс открытия документа
function ApplicationEvent.OnBeginOpenFile() : boolean;
var
  mes : string;
  res : Integer;
begin
  mes := 'ApplicationEvent::BeginOpenFile'                   + #13#10 +
         'Да - Создать документ'                             + #13#10 +
  	     'Нет - запустить стандартный диалог открытия файла' + #13#10 +
				 'Отмена - не открывать файл';
  Result := true;
  res := LibMessage( PChar( mes ), MB_YESNOCANCEL );
  case res of
    ID_YES:
			Result := not boolean( CreateDocument2D( 0 ) ); // Если документ создан стандартный диалог не нужен
		ID_CANCEL:
			Result := false;
    ID_NO:
      Result := true;
  end;
end;

// koBeginCloseAllDocument - Закрываются все документы
function ApplicationEvent.OnBeginCloseAllDocument(): boolean;
begin
  Result := LibMessage( 'ApplicationEvent.OnBeginCloseAllDocument'#13#10'Закрыть все?', MB_YESNO ) = ID_YES;
end;

destructor ApplicationEvent.Destroy();
begin
  inherited Destroy;
end;

function ApplicationEvent.OnEvent( commandID : Integer; var Params : tagDISPPARAMS; var eventRes : boolean ) : boolean;
  var
    s : string;
begin
  Result := boolean( commandID >= koCreateDocument ) and boolean( commandID <= koBeginCloseAllDocument );
  case commandID of

    koCreateDocument:                    // Документ создан
      eventRes := OnCreateDocument( IDispatch(Params.rgvarg^[1].dispVal), Params.rgvarg^[0].intVal );

    koBeginOpenDocument : begin          // Начало открытия документа
      s := Params.rgvarg^[0].bstrVal;
      eventRes := OnBeginOpenDocument( s );
    end;

    koOpenDocument:                      // Документ открыт
      eventRes := OnOpenDocument( IDispatch(Params.rgvarg^[1].dispVal), Params.rgvarg^[0].intVal );

    koChangeActiveDocument:              // Переключение на другой активный документ
      eventRes := OnChangeActiveDocument( IDispatch(Params.rgvarg^[1].dispVal), Params.rgvarg^[0].intVal );

    koApplicatinDestroy:                 // Закрытие приложения
      eventRes := OnApplicationDestroy;

    koBeginCreate:                       // Процесс создания файла
      eventRes := OnBeginCreate( Params.rgvarg^[0].intVal );

    koBeginOpenFile:                     // Процесс открытия файла
      eventRes := OnBeginOpenFile;

    koBeginCloseAllDocument:             // Закрываются все файлы
      eventRes := OnBeginCloseAllDocument;
  end;
end;

constructor DocumentEvent.Create(  refDoc : Reference );
begin
  pObject := IDispatch( iKompasObject.ksGetDocumentByReference(refDoc) );
  inherited Create( pObject, DIID_ksDocumentFileNotify, refDoc, 0 );
end;

destructor DocumentEvent.Destroy();
begin
  pObject := nil;
  inherited Destroy();
end;

//kdCloseDocument - Начало закрытия документа.
function DocumentEvent.OnBeginCloseDocument() : boolean;
begin
  Result := LibMessage( 'Закрывается документ.'#13#10'Продолжить?', MB_YESNO ) = ID_YES;
end;

//kdCloseDocument - Документ закрыт.
function DocumentEvent.OnCloseDocument() : boolean;
begin
  LibMessage( 'Документ закрыт.', MB_OK );
  TerminateEventsFromIID( GUID_NULL, pDoc, -1 );
  Result := true;
end;

  //kdBeginSaveDocument - Начало сохранения документа.
function DocumentEvent.OnBeginSaveDocument( fileName : string ) : boolean;
begin
  Result := LibMessage( 'Сохранить документ?', MB_YESNO ) = ID_YES;
end;

  //kdSaveDocument - Документ сохранен.
function DocumentEvent.OnSaveDocument() : boolean;
begin
  LibMessage( 'Документ сохранен', MB_OK );
  Result := true;
end;

//kdActiveDocument - Документ активизирован.
function DocumentEvent.OnActivate() : boolean;
begin
  LibMessage( 'Документ активизирован', MB_OK );
  Result := true;
end;

//kdDeactiveDocument - Документ деактивизирован.
function DocumentEvent.OnDeactivate() : boolean;
begin
  LibMessage( 'Документ деактивизирован', MB_OK );
  Result := true;
end;

//kdDeactiveDocument - Документ деактивизирован.
function DocumentEvent.OnBeginSaveAsDocument() : boolean;
var
  res     : Integer;
  docType : Integer;
  iDoc    : IDispatch;
  dParam  : ksDocumentParam;
  tParam  : ksTextDocumentParam;
begin
  res := LibMessage( 'DocumentEvent::BeginSaveAsDocument'                  + #13#10 +
			               'Да - Сохранить чертеж'                               + #13#10 +
			               'Нет - Запустить стандартный диалог сохранения файла' + #13#10 +
				             'Отмена - Не сохранять файл', MB_YESNOCANCEL );
  Result := true;
  case res of
    ID_NO    : Result := true;
    ID_CANCEL: Result := false;
    ID_YES   : begin
      iDoc := iKompasObject.ksGetDocumentByReference(pDoc);
      if iDoc <> nil then
      begin
        docType := iKompasObject.ksGetDocumentType( pDoc );
        case docType of
          lt_DocTxtStandart,
          lt_DocTxtUser: begin
            ksDocumentTxt(iDoc).ksGetObjParam( pDoc, tParam, ALLPARAM );
            if tParam.filename = '' then
              Result := ksDocumentTxt(iDoc).ksSaveDocument( 'c\:1.txt' )
            else
              Result := ksDocumentTxt(iDoc).ksSaveDocument( '' );
          end;
          lt_DocSheetStandart,
          lt_DocSheetUser: begin
            ksDocument2D(iDoc).ksGetObjParam( pDoc, dParam, ALLPARAM );
            if dParam.filename = '' then
              Result := ksDocument2D(iDoc).ksSaveDocument( 'c\:1.cdw' )
            else
              Result := ksDocument2D(iDoc).ksSaveDocument( '' );
          end;
          lt_DocFragment: begin
            ksDocument2D(iDoc).ksGetObjParam( pDoc, dParam, ALLPARAM );
            if dParam.filename = '' then
              Result := ksDocument2D(iDoc).ksSaveDocument( 'c\:1.frw' )
            else
              Result := ksDocument2D(iDoc).ksSaveDocument( '' );
          end;
          lt_DocSpc,
          lt_DocSpcUser: begin
            ksSpcDocument(iDoc).ksGetObjParam( pDoc, dParam, ALLPARAM );
            if dParam.filename = '' then
              Result := ksSpcDocument(iDoc).ksSaveDocument( 'c\:1.spc' )
            else
              Result := ksSpcDocument(iDoc).ksSaveDocument( '' );
          end;
          lt_DocPart3D: begin
            ksDocument3D(iDoc).ksGetObjParam( pDoc, dParam, ALLPARAM );
            if dParam.filename = '' then
              Result := ksDocument3D(iDoc).SaveAs( 'c\:1.m3d' )
            else
              Result := ksDocument3D(iDoc).Save;
          end;
          lt_DocAssemble3D: begin
            ksDocument3D(iDoc).ksGetObjParam( pDoc, dParam, ALLPARAM );
            if dParam.filename = '' then
              Result := ksDocument3D(iDoc).SaveAs( 'c\:1.a3d' )
            else
              Result := ksDocument3D(iDoc).Save();
          end;
        end
      end;
    end
  end
end;

// События для документов : Работа с файлом.
function DocumentEvent.OnEvent( commandID : Integer; var Params : tagDISPPARAMS; var eventRes : boolean ) : boolean;
  var
    s : string;
begin
  Result := boolean( commandID >= kdBeginCloseDocument ) and boolean( commandID <= kdBeginSaveAsDocument );
  case commandID of
    kdBeginCloseDocument:                    // Начало закрытия документа
      eventRes := OnBeginCloseDocument();
    kdCloseDocument :                        // Документ закрыт
      eventRes := OnCloseDocument();
    kdBeginSaveDocument: begin               // Начало сохранения документа
      s := Params.rgvarg^[0].bstrVal;
      eventRes := OnBeginSaveDocument( s );
    end;
    kdSaveDocument:                          // Документ сохранен
      eventRes := OnSaveDocument();
    kdActiveDocument:                        // Документ активизировался
      eventRes := OnActivate();
    kdDeactiveDocument:                      // Документ деактивизировался
      eventRes := OnDeactivate();
    kdBeginSaveAsDocument:
      eventRes := OnBeginSaveAsDocument();
  end;
end;

constructor Obj2DEvent.Create( objType : LongInt; refDoc : Reference );
var
 doc2d : ksDocument2D;
begin
  objNotify := nil;
  doc2d := ksDocument2D( iKompasObject.ActiveDocument2D );
  if  doc2d <> nil then
    objNotify := doc2d.GetObject2DNotify(objType);
  inherited Create( IDispatch(objNotify), DIID_ksObject2DNotify, refDoc, objType );
end;

destructor Obj2DEvent.Destroy();
begin
  inherited Destroy();
  objNotify := nil;
end;

function Obj2DEvent.OnEvent( commandID : Integer; var Params : tagDISPPARAMS; var eventRes : boolean  ) : boolean;
var
  arg : integer;
begin
  arg := 0;
  Result := boolean( commandID >= koChangeActive ) and boolean( commandID <= koSymmetry );
  if Result then
    arg := Params.rgvarg^[0].intVal;
  case commandID of
    koChangeActive:           // Переключение активности объекта( вид, слой)
      eventRes := OnChangeActive( arg );
    koBeginDelete:            // Начало удаления объекта
      eventRes := OnBeginDelete( arg );
    koDelete:                 // Удаление объекта
      eventRes := OnDelete( arg );
    koBeginMove:              // Начало сдвига объекта
      eventRes := OnBeginMove( arg );
    koMove:                   // Сдвиг объекта
      eventRes := OnMove( arg );
    koBeginRotate:            // Начало поворота объекта
      eventRes := OnBeginRotate( arg );
    koRotate:                 // Поворот объекта
      eventRes := OnRotate( arg );
    koBeginScale:             // Начало масштабирования объекта
      eventRes := OnBeginScale( arg );
    koScale:                  // Масштабирования объекта
      eventRes := OnScale( arg );
    koBeginTransform:         // Начало трансформации объекта
      eventRes := OnBeginTransform( arg );
    koTransform:              // Трансформация объекта
      eventRes := OnTransform( arg );
    koBeginCopy:              // Начало копирования объекта
      eventRes := OnBeginCopy( arg );
    koCopy:                   // Копирование объекта
      eventRes := OnCopy( arg );
    koBeginSymmetry:          // Начало симметрии  объекта
      eventRes := OnBeginSymmetry( arg );
    koSymmetry:               // Симметрия  объекта
      eventRes := OnSymmetry( arg );
    koBeginProcess:           // Начало редактирования\создания объекта.
      eventRes := OnBeginProcess( arg, Params.rgvarg^[1].intVal );
    koEndProcess:             // Конец редактирования\создания объекта.
      eventRes := OnEndProcess( arg );
    koCreateObject:
      eventRes := OnCreateObject( arg );
    koUpdateObject:
      eventRes := OnUpdateObject( arg );

  end;

end;


// koChangeActive           // Переключение активности объекта( вид, слой)
function Obj2DEvent.OnChangeActive( obj : Reference ): boolean;
begin
  LibMessage( 'Obj2DEvent.OnChangeActive', MB_OK );
  Result := true;
end;

// koBeginDelete            // Начало удаления объекта
function Obj2DEvent.OnBeginDelete( obj : Reference ): boolean;
begin
  Result := LibMessage( 'Удалить объект?', MB_YESNO ) = ID_YES;
end;

// koDelete                 // Удаление объекта
function Obj2DEvent.OnDelete( obj : Reference ): boolean;
begin
  LibMessage( 'Obj2DEvent.OnDelete', MB_OK );
  if ( obj <> 0 ) and ( obj = m_Obj ) then
    TerminateEventsFromIID( GUID_NULL, pDoc, obj );
  Result := true;
end;

// koBeginMove              // Начало сдвига объекта
function Obj2DEvent.OnBeginMove( obj : Reference ): boolean;
begin
  Result := LibMessage( 'Сдвинуть объект?', MB_YESNO ) = ID_YES;
end;

// koMove                   // Сдвиг объекта
function Obj2DEvent.OnMove( obj : Reference ): boolean;
begin
  LibMessage( 'Obj2DEvent.OnMove', MB_OK );
  Result := true;
end;

// koBeginRotate            // Начало поворота объекта
function Obj2DEvent.OnBeginRotate( obj : Reference ): boolean;
begin
  Result :=LibMessage( 'Повернуть объект?', MB_YESNO ) = ID_YES;
end;

// koRotate                 // Поворот объекта
function Obj2DEvent.OnRotate( obj : Reference ): boolean;
begin
  LibMessage( 'Obj2DEvent.OnRotate', MB_OK );
  Result := true;
end;

// koBeginScale             // Начало масштабирования объекта
function Obj2DEvent.OnBeginScale( obj : Reference ): boolean;
begin
  Result := LibMessage( 'Отмаштобировать объект?', MB_YESNO ) = ID_YES;
end;

// koScale                  // Масштабирования объекта
function Obj2DEvent.OnScale( obj : Reference ): boolean;
begin
  LibMessage( 'Obj2DEvent.OnScale', MB_OK );
  Result := true;
end;

// koBeginTransform         // Начало трансформации объекта
function Obj2DEvent.OnBeginTransform( obj : Reference ): boolean;
begin
  LibMessage( 'Obj2DEvent.OnBeginTransform', MB_OK );
  Result := true;
end;

// koTransform              // Трансформация объекта
function Obj2DEvent.OnTransform( obj : Reference ): boolean;
begin
  LibMessage( 'Obj2DEvent.OnTransform', MB_OK );
  Result := true;
end;

// koBeginCopy              // Начало копирования объекта
function Obj2DEvent.OnBeginCopy( obj : Reference ): boolean;
begin
  Result := LibMessage( 'Копировать объект?', MB_YESNO ) = ID_YES;
end;

// koCopy                   // Копирование объекта
function Obj2DEvent.OnCopy( obj : Reference ): boolean;
begin
  LibMessage( 'Obj2DEvent.OnCopy', MB_OK );
  Result := true;
end;

// koBeginSymmetry          // Начало симметрии  объекта
function Obj2DEvent.OnBeginSymmetry( obj : Reference ): boolean;
begin
  Result := LibMessage( 'Создать симметрию объекта?', MB_YESNO ) = ID_YES;
end;

// koSymmetry               // Симметрия  объекта
function Obj2DEvent.OnSymmetry( obj : Reference ): boolean;
begin
  LibMessage( 'Obj2DEvent.OnSymmetry', MB_OK );
  Result := true;
end;

// koBeginProcess = $00000010;
function Obj2DEvent.OnBeginProcess( _type : LongInt; obj : Reference ): boolean;
begin
  LibMessage( 'Obj2DEvent.OnBeginProcess', MB_OK );
  Result := true;
end;

// koBeginProcess = $00000011;
function Obj2DEvent.OnEndProcess( _type : LongInt ): boolean;
begin
  LibMessage( 'Obj2DEvent.OnEndProcess', MB_OK );
  Result := true;
end;

// koCreateObject = $00000012;
function Obj2DEvent.OnCreateObject( obj : Reference ): boolean;
begin
  LibMessage( 'Obj2DEvent.OnCreateObject', MB_OK );
  Result := true;
end;

// koUpdateObject = $00000013;
function Obj2DEvent.OnUpdateObject( obj : Reference ): boolean;
begin
  LibMessage( 'Obj2DEvent.OnUpdateObject', MB_OK );
  Result := true;
end;


constructor SelectMngEvent.Create( doc : Reference );
var
  docType : Integer;
  iDoc    : IDispatch;
begin
  iDoc    := iKompasObject.ksGetDocumentByReference( doc );
  docType := iKompasObject.ksGetDocumentType( doc );
  selNotify := nil;
  if iDoc <> nil then begin
    case docType of
      lt_DocSheetStandart ,  // чертеж стандартный
      lt_DocSheetUser     ,  // чертеж нестандартный
      lt_DocFragment      :  // фрагмент
      begin
        selNotify := ksDocument2D(iDoc).GetSelectionMngNotify();
      end;
      lt_DocPart3D        ,  // 3d-документ модель
      lt_DocAssemble3D    :  // 3d-документ сборка
      begin
        selNotify := ksDocument3D(iDoc).GetSelectionMng();
      end
    end
  end;
  inherited Create( IDispatch(selNotify), DIID_ksSelectionMngNotify, doc, 0 );
end;

destructor SelectMngEvent.Destroy();
begin
  inherited Destroy;
  selNotify := nil;
end;

function SelectMngEvent.OnEvent( commandID : Integer; var Params : tagDISPPARAMS; var eventRes : boolean  ) : boolean;
begin
  Result := ( commandID >= ksmSelect ) and ( commandID <= ksmUnselectAll );
  case commandID of
    ksmSelect :
      eventRes := OnSelect( OleVariant( Params.rgvarg^[0] ) );
    ksmUnselect:
      eventRes := OnUnSelect( OleVariant( Params.rgvarg^[0] ) );
    ksmUnselectAll:
      eventRes := OnUnSelectAll();
  end;
end;

//  ksmSelect = $00000001;           // Переключение активности объекта( вид, слой)
function SelectMngEvent.OnSelect( var obj : OleVariant ): boolean;
begin
//  LibMessage( 'SelectMngEvent.OnSelect', MB_OK );
  Result := true;
end;

//  ksmUnselect = $00000002;         // Начало удаления объекта
function SelectMngEvent.OnUnselect( var obj : OleVariant  ): boolean;
begin
  LibMessage( 'SelectMngEvent.OnUnselect', MB_OK );
  Result := true;
end;

//  ksmUnselectAll = $00000003;         // Начало удаления объекта
function SelectMngEvent.OnUnselectAll(): boolean;
begin
  LibMessage( 'SelectMngEvent.OnUnselectAll', MB_OK );
  Result := true;
end;

constructor StampEvents.Create( doc : Reference );
var
  docType : Integer;
  iDoc    : IDispatch;
begin
  iDoc    := iKompasObject.ksGetDocumentByReference( doc );
  docType := iKompasObject.ksGetDocumentType( doc );
  stamp   := nil;
  if iDoc <> nil then begin
    case docType of
      lt_DocSheetStandart,  // чертеж стандартный
      lt_DocSheetUser    :  // чертеж нестандартный
        stamp := ksStamp( ksDocument2D(iDoc).GetStamp() );
      lt_DocSpc          ,  // спецификация
      lt_DocSpcUser      :  // спецификация нестандартный формат
        stamp := ksStamp( ksSpcDocument(iDoc).GetStamp() );
      lt_DocTxtStandart   ,  // текстовый документ стандартный
      lt_DocTxtUser       :  // текстовый документ нестандартный
        stamp := ksStamp( ksDocumentTxt(iDoc).GetStamp() );
    end
  end;
  inherited Create( IDispatch(stamp), DIID_ksStampNotify, doc, 0 );
end;

destructor StampEvents.Destroy();
begin
  inherited Destroy;
  stamp := nil;
end;

function StampEvents.OnEvent( commandID : Integer; var Params : tagDISPPARAMS; var eventRes : boolean  ) : boolean;
begin
  Result := ( commandID >= ksmSelect ) and ( commandID <= ksmUnselectAll );
  case commandID of
    kdBeginEditStamp :
      eventRes := OnBeginEdit();
    kdEndEditStamp:
      eventRes := OnEndEdit( boolean ( Params.rgvarg^[0].puintVal ) );
    kdStampCellDblClick:
      eventRes := OnCellDblClick( Params.rgvarg^[0].intVal );
    kdStampCellBeginEdit:
      eventRes := OnCellBeginEdit( Params.rgvarg^[0].intVal );
  end;
end;

//  kdBeginEditStamp = $00000001;           // Переключение активности объекта( вид, слой)
function StampEvents.OnBeginEdit(): boolean;
begin
  LibMessage( 'StampEvents.OnBeginEdit', MB_OK );
  Result := true;
end;

//  kdEndEditStamp = $00000002;         // Начало удаления объекта
function StampEvents.OnEndEdit( editResult : boolean ): boolean;
begin
  LibMessage( 'StampEvents.OnEndEdit', MB_OK );
  Result := true;
end;

//  kdStampCellDblClick = $00000003;         // Начало удаления объекта
function StampEvents.OnCellDblClick( number : integer ): boolean;
begin
  LibMessage( 'StampEvents.OnCellDblClick', MB_OK );
  Result := true;
end;
//  kdStampCellBeginEdit = $00000004;
function StampEvents.OnCellBeginEdit( number : integer ): boolean;
begin
  LibMessage( 'StampEvents.OnCellBeginEdit', MB_OK );
  Result := true;
end;

function GetActiveDocumentReference( docType : Integer ) : Reference;
var
  iDoc    : IDispatch;
  documType : Integer;
begin
  iDoc      := iKompasObject.ksGetDocumentByReference( 0 );
  documType := iKompasObject.ksGetDocumentType( 0 );
  Result := 0;
  if iDoc <> nil then begin
    case documType of
      lt_DocSheetStandart,  // чертеж стандартный
      lt_DocSheetUser    :  // чертеж нестандартный
        if ( docType = 0 ) or ( docType = 1 ) then
          Result := ksDocument2D(iDoc).Reference;
      lt_DocSpc          ,  // спецификация
      lt_DocSpcUser      :  // спецификация нестандартный формат
        if ( docType = 0 ) or ( docType = 2 ) then
          Result := ksSpcDocument(iDoc).Reference;
      lt_DocPart3D        ,  // 3d-документ модель
      lt_DocAssemble3D    :  // 3d-документ сборка
        if ( docType = 0 ) or ( docType = 3 ) then
          Result := ksDocument3D(iDoc).Reference;
      lt_DocTxtStandart   ,  // текстовый документ стандартный
      lt_DocTxtUser       :  // текстовый документ нестандартный
        if ( docType = 0 ) or ( docType = 4 ) then
          Result := ksDocumentTxt(iDoc).Reference;
    end
  end;
end;

procedure ActivateDoc( pDoc :Reference );
var
  iDoc      : IDispatch;
  documType : Integer;
begin
  iDoc      := iKompasObject.ksGetDocumentByReference( pDoc );
  documType := iKompasObject.ksGetDocumentType( pDoc );
  if iDoc <> nil then begin
    case documType of
      lt_DocSheetStandart,  // чертеж стандартный
      lt_DocSheetUser    :  // чертеж нестандартный
        ksDocument2D(iDoc).ksSetObjParam( pDoc, nil, DOCUMENT_STATE );
      lt_DocSpc          ,  // спецификация
      lt_DocSpcUser      :  // спецификация нестандартный формат
        ksSpcDocument(iDoc).ksSetObjParam( pDoc, nil, DOCUMENT_STATE );
      lt_DocPart3D        ,  // 3d-документ модель
      lt_DocAssemble3D    :  // 3d-документ сборка
        ksDocument3D(iDoc).ksSetObjParam( pDoc, nil, DOCUMENT_STATE );
      lt_DocTxtStandart   ,  // текстовый документ стандартный
      lt_DocTxtUser       :  // текстовый документ нестандартный
        ksDocumentTxt(iDoc).ksSetObjParam( pDoc, nil, DOCUMENT_STATE );
    end
  end;
end;


function NewDocumentEvent( pDoc : reference ) : DocumentEvent;
var
  docEvent : DocumentEvent;
begin
  docEvent := nil;
  if pDoc <> 0 then begin
    if not BaseEvent.FindEvent( DIID_ksDocumentFileNotify, pDoc, -1 ) then begin
      docEvent := DocumentEvent.Create(pDoc);
      if not docEvent.Advise then begin
        docEvent.Free;
        docEvent := nil;
      end;
    end
  end;
  Result := docEvent;
end;

function NewObj2DEvent( pDoc : reference; objType : LongInt ) : Obj2DEvent;
var
  ObjEvent : Obj2DEvent;
begin
  ObjEvent := nil;
  if pDoc <> 0 then begin
    if not BaseEvent.FindEvent( DIID_ksObject2DNotify, pDoc, objType ) then begin
      ObjEvent := Obj2DEvent.Create( objType, pDoc );
      if not ObjEvent.Advise then begin
        ObjEvent.Free;
        ObjEvent := nil;
      end;
    end
  end;
  Result := ObjEvent;
end;

function NewStampEvents( pDoc : reference ) : StampEvents;
var
  shEvent : StampEvents;
begin
  shEvent := nil;
  if pDoc <> 0 then begin
    if not BaseEvent.FindEvent( DIID_ksStampNotify, pDoc, 0 ) then begin
      shEvent := StampEvents.Create( pDoc );
      if not shEvent.Advise then begin
        shEvent.Free;
        shEvent := nil;
      end;
    end
  end;
  Result := shEvent;
end;

function NewSelectMngEvent( pDoc : reference ) : SelectMngEvent;
var
  selEvent : SelectMngEvent;
begin
  selEvent := nil;
  if pDoc <> 0 then begin
    if not BaseEvent.FindEvent( DIID_ksSelectionMngNotify, pDoc, 0 ) then begin
      selEvent := SelectMngEvent.Create( pDoc );
      if not selEvent.Advise then begin
        selEvent.Free;
        selEvent := nil;
      end;
    end;
  end;
  Result := selEvent;
end;

end.



