unit DocumentEvents;

interface
uses
  Windows,
  cBaseEvents,
  ks2DCOM_TLB,
  ksConstTLB,
  ActiveX,
  Libtool,
  LtDefine;


type
////////////////////////////////////////////////////////////////////////////////
// DocumentEvent  - обрабокчик событий от документа
//
DocumentEvent = class ( cBaseEvent, IDocumentFileNotify )
public
  constructor Create( docRef : Reference ); overload;
  destructor  Destroy(); override;
  function    Advise(): boolean; override;

protected
  // Функция должна возвращать true если метод notifyType обрабатывается интерфейсом
  function IsNotifyProcess(notifyType: SYSINT): WORDBOOL; virtual; stdcall;
  //kdBeginCloseDocument - Начало закрытия документа.
  function BeginCloseDocument() : WORDBOOL; virtual; stdcall;
  //kdCloseDocument - Документ закрыт.
  function CloseDocument() : WORDBOOL; virtual; stdcall;
  //kdBeginSaveDocument - Начало сохранения документа.
  function BeginSaveDocument( fileName : PAnsiChar ) : WORDBOOL; virtual; stdcall;
  //kdSaveDocument - Документ сохранен.
  function SaveDocument() : WORDBOOL; virtual; stdcall;
  //kdActiveDocument - Документ активизирован.
  function Activate() : WORDBOOL; virtual; stdcall;
  //kdDeactiveDocument - Документ деактивизирован.
  function Deactivate() : WORDBOOL; virtual; stdcall;
  //kdBeginSaveAsDocument - Процесс сохранения файла.
  function BeginSaveAsDocument() : WORDBOOL; virtual; stdcall;
  //kdDocumentFrameOpen - Открытие окна документа.
  function DocumentFrameOpen(const v: IUnknown): WORDBOOL; virtual; stdcall;
  //kdProcessActivate - активизация процесса
  function ProcessActivate(Id: Integer): WORDBOOL; virtual; stdcall;
  //kdProcessActivate - деактивизация процесса
  function ProcessDeactivate(Id: Integer): WORDBOOL; virtual; stdcall;

  function  BeginProcess(Id: Integer): WORDBOOL;  virtual; stdcall;
  function  EndProcess(Id: Integer; Success: WORDBOOL): WORDBOOL;  virtual; stdcall;

  function BeginAutoSaveDocument(docName: PAnsiChar): WORDBOOL; virtual; stdcall;
  function AutoSaveDocument: WORDBOOL; virtual; stdcall;
  function ActivateToolbarSet(oldToolbarSetId: PAnsiChar; newToolbarSetId: PAnsiChar): WordBool; virtual; stdcall;
end;

////////////////////////////////////////////////////////////////////////////////
//
// Object2DEvent  - обрабокчик событий от 2D документа
//
////////////////////////////////////////////////////////////////////////////////
Object2DEvent = class ( cBaseEvent, IObject2DNotify )

public
	constructor Create( doc : LongInt; obj : LongInt ); overload;
  destructor  Destroy(); override;
  function    Advise(): boolean; override;

protected
  // Функция должна возвращать true если метод notifyType обрабатывается интерфейсом
  function IsNotifyProcess(notifyType: SYSINT): WORDBOOL; virtual; stdcall;
  //koChangeActive    // Переключение активности объекта( вид, слой)
  function ChangeActive( objRef : Reference ) : WORDBOOL; virtual; stdcall;
  //koBeginDelete     // Начало удаления сдвига, false - запрещает удаление
  function BeginDelete( objRef : Reference ) : WORDBOOL; virtual; stdcall;
  //koDelete          // Удаление объекта
  function Delete( objRef : Reference ) : WORDBOOL; virtual; stdcall;
  //koCreate          // Создание объекта
  function CreateObject( objRef : Reference ) : WORDBOOL; virtual; stdcall;
  //koBeginEdit       // Начало редактирования объекта, false - запрещает редактирование
  function BeginEdit( objRef : Reference ) : WORDBOOL; virtual; stdcall;
  //koEditObject      // Объект отредактирован
  function EditObject( objRef : Reference ) : WORDBOOL; virtual; stdcall;
  //koBeginMove       // Начало сдвига объекта, false - запрещает сдвиг
  function BeginMove( objRef : Reference ) : WORDBOOL; virtual; stdcall;
  //koMove            // Сдвиг объекта
  function Move( objRef : Reference ) : WORDBOOL; virtual; stdcall;
  //koBeginRotate     // Начало поворота объекта, false - запрещает поворот
  function BeginRotate( objRef : Reference ) : WORDBOOL; virtual; stdcall;
  //koRotate          // Поворот объекта
  function Rotate( objRef : Reference ) : WORDBOOL; virtual; stdcall;
  //koBeginScale     // Начало масштабирования объекта, false - запрещает поворот
  function BeginScale( objRef : Reference ) : WORDBOOL; virtual; stdcall;
  //koScale          // Масштабирование объекта
  function Scale( objRef : Reference ) : WORDBOOL; virtual; stdcall;
  //koBeginTransform  // Начало трансформации объекта, false - запрещает трансформацию
  function BeginTransform( objRef : Reference ) : WORDBOOL; virtual; stdcall;
  //koTransform       // Трансформация объекта
  function Transform( objRef : Reference ) : WORDBOOL; virtual; stdcall;
  //koBeginCopy       // Начало копирования объекта, false - запрещает копирование
  function BeginCopy( objRef : Reference ) : WORDBOOL; virtual; stdcall;
  //koCopy            // Копирование объекта
  function Copy( objRef : Reference ) : WORDBOOL; virtual; stdcall;
  //koBeginSymmetry   // Начало симметрии  объекта, false - запрещает симметрию
  function BeginSymmetry( objRef : Reference ) : WORDBOOL; virtual; stdcall;
  //koSymmetry        // Симметрия  объекта
  function Symmetry( objRef : Reference ) : WORDBOOL; virtual; stdcall;

  function BeginProcess(pType: Integer; objRef: Integer): WORDBOOL; virtual; stdcall;

  function EndProcess(pType: Integer): WORDBOOL; virtual; stdcall;

  function UpdateObject(objRef: Integer): WORDBOOL; virtual; stdcall;
  function  BeginDestroyObject(objRef: Integer): WordBool; virtual; stdcall;
  function  DestroyObject(objRef: Integer): WordBool; virtual; stdcall;
  function BeginPropertyChanged(objRef: Integer): WordBool; virtual; stdcall;
  function PropertyChanged(objRef: Integer): WordBool; virtual; stdcall;

end;

  function NewDocumentEvent( doc : reference ) : DocumentEvent;
  function NewObj2DEvent( doc : Reference; objType : Integer ) : Object2DEvent;

implementation

uses
  step12_1;

constructor DocumentEvent.Create( docRef : Reference );
begin
  inherited Create( ntDocumentFileNotify, docRef, docRef, 0 );
end;

destructor DocumentEvent.Destroy();
begin
  inherited Destroy;
end;

//------------------------------------------------------------------------------
// Advise
//---
function DocumentEvent.Advise() : boolean;
begin
  if not m_advise and ( m_params.ifType <> 0 ) then
    m_advise := boolean( ksConnectionAdvise( @m_params, PIUnknown(IDocumentFileNotify(self)) ) );
	Result := m_advise;
end;

function DocumentEvent.IsNotifyProcess( notifyType: SYSINT ) : WORDBOOL;
begin
  Result := ( notifyType >= kdBeginCloseDocument ) And ( notifyType <= kdBeginSaveAsDocument )
end;

//kdCloseDocument - Начало закрытия документа.
function DocumentEvent.BeginCloseDocument() : WORDBOOL;
begin
  Result := true;
end;

//kdCloseDocument - Документ закрыт.
function DocumentEvent.CloseDocument() : WORDBOOL;
begin
  TerminateEventsByParam( 0, refDoc, -1, nil );
  UpdateSlideBox1( 0 );
  Result := true;
end;

  //kdBeginSaveDocument - Начало сохранения документа.
function DocumentEvent.BeginSaveDocument( fileName : PAnsiChar ) : WORDBOOL;
begin
  Result := true;
end;

  //kdSaveDocument - Документ сохранен.
function DocumentEvent.SaveDocument() : WORDBOOL;
begin
  Result := true;
end;

//kdActiveDocument - Документ активизирован.
function DocumentEvent.Activate() : WORDBOOL;
begin
  UpdateSlideBox();
  Result := true;
end;

  //kdDeactiveDocument - Документ деактивизирован.
function DocumentEvent.Deactivate() : WORDBOOL;
begin
  Result := true;
end;

  //kdBeginSaveAsDocument - Начало сохранения документа.
function DocumentEvent.BeginSaveAsDocument() : WORDBOOL;
begin
  Result := true;
end;

//kdProcessActivate - Документ активизирован.
function DocumentEvent.ProcessActivate( Id: Integer ) : WORDBOOL;
begin
  Result := true;
end;

//kdProcessActivate - Документ деактивизирован.
function DocumentEvent.ProcessDeactivate( Id: Integer ) : WORDBOOL;
begin
  Result := true;
end;

//kdDocumentFrameOpen - Начало сохранения документа.
function DocumentEvent.DocumentFrameOpen( const v: IUnknown ) : WORDBOOL;
begin
  Result := true;
end;

function DocumentEvent.BeginProcess(Id: Integer): WORDBOOL;
begin
  Result := true;
end;

function DocumentEvent.EndProcess(Id: Integer; Success: WORDBOOL): WORDBOOL;
begin
  Result := true;
end;

function DocumentEvent.BeginAutoSaveDocument(docName: PAnsiChar): WORDBOOL;
begin
  Result := true;
end;

function DocumentEvent.AutoSaveDocument: WORDBOOL;
begin
  Result := true;
end;

function DocumentEvent.ActivateToolbarSet(oldToolbarSetId: PAnsiChar; newToolbarSetId: PAnsiChar): WordBool;
begin
  Result := true;
end;

constructor Object2DEvent.Create( doc : LongInt; obj : LongInt );
begin
  inherited Create( ntObject2DNotify, doc, doc, obj );
end;

destructor Object2DEvent.Destroy();
begin
  inherited Destroy;
end;

//------------------------------------------------------------------------------
// Advise
//---
function Object2DEvent.Advise() : boolean;
begin
  if not m_advise and ( m_params.ifType <> 0 ) then
    m_advise := boolean( ksConnectionAdvise( @m_params, PIUnknown(IObject2DNotify(self)) ) );
	Result := m_advise;
end;

function Object2DEvent.IsNotifyProcess( notifyType: SYSINT ) : WORDBOOL;
begin
  Result := ( notifyType >= koChangeActive ) And ( notifyType <= koUpdateObject )
end;

//koChangeActive    // Переключение активности объекта( вид, слой)
function Object2DEvent.ChangeActive( objRef : Reference ) : WORDBOOL;
begin
  UpdateSlideBox();
  Result := true;
end;

  //koBeginDelete     // Начало удаления сдвига, false - запрещает удаление
function Object2DEvent.BeginDelete( objRef : Reference ) : WORDBOOL;
begin
  Result := true;
end;

  //koDelete          // Удаление объекта
function Object2DEvent.Delete( objRef : Reference ) : WORDBOOL;
begin
  UpdateSlideBox();
  Result := true;
end;

  //koCreate          // Создание объекта
function Object2DEvent.CreateObject( objRef : Reference ) : WORDBOOL;
begin
  UpdateSlideBox();
  Result := true;
end;

  //koBeginEdit       // Начало редактирования объекта, false - запрещает редактирование
function Object2DEvent.BeginEdit( objRef : Reference ) : WORDBOOL;
begin
  Result := true;
end;

  //koEditObject      // Объект отредактирован
function Object2DEvent.EditObject( objRef : Reference ) : WORDBOOL;
begin
  UpdateSlideBox();
  Result := true;
end;

  //koBeginMove       // Начало сдвига объекта, false - запрещает сдвиг
function Object2DEvent.BeginMove( objRef : Reference ) : WORDBOOL;
begin
  Result := true;
end;

  //koMove            // Сдвиг объекта
function Object2DEvent.Move( objRef : Reference ) : WORDBOOL;
begin
  UpdateSlideBox();
  Result := true;
end;

  //koBeginRotate     // Начало поворота объекта, false - запрещает поворот
function Object2DEvent.BeginRotate( objRef : Reference ) : WORDBOOL;
begin
  Result := true;
end;

  //koRotate          // Поворот объекта
function Object2DEvent.Rotate( objRef : Reference) : WORDBOOL;
begin
  UpdateSlideBox();
  Result := true;
end;

  //koBeginScale     // Начало масштабирования объекта, false - запрещает поворот
function Object2DEvent.BeginScale( objRef : Reference ) : WORDBOOL;
begin
  Result := true;
end;

  //koScale          // Масштабирование объекта
function Object2DEvent.Scale( objRef : Reference ) : WORDBOOL;
begin
  UpdateSlideBox();
  Result := true;
end;

  //koBeginTransform  // Начало трансформации объекта, false - запрещает трансформацию
function Object2DEvent.BeginTransform( objRef : Reference ) : WORDBOOL;
begin
  Result := true;
end;

  //koTransform       // Трансформация объекта
function Object2DEvent.Transform( objRef : Reference ) : WORDBOOL;
begin
  UpdateSlideBox();
  Result := true;
end;

  //koBeginCopy       // Начало копирования объекта, false - запрещает копирование
function Object2DEvent.BeginCopy( objRef : Reference ) : WORDBOOL;
begin
  Result := true;
end;

  //koCopy            // Копирование объекта
function Object2DEvent.Copy( objRef : Reference ) : WORDBOOL;
begin
  UpdateSlideBox();
  Result := true;
end;

  //koBeginSymmetry   // Начало симметрии  объекта, false - запрещает симметрию
function Object2DEvent.BeginSymmetry( objRef : Reference ) : WORDBOOL;
begin
  Result := true;
end;

  //koSymmetry        // Симметрия  объекта
function Object2DEvent.Symmetry( objRef : Reference ) : WORDBOOL;
begin
  UpdateSlideBox();
  Result := true;
end;

function Object2DEvent.BeginProcess(pType: Integer; objRef: Integer): WORDBOOL;
begin
  Result := true;
end;

function Object2DEvent.EndProcess(pType: Integer): WORDBOOL;
begin
  UpdateSlideBox();
  Result := true;
end;

function Object2DEvent.UpdateObject(objRef: Integer): WORDBOOL;
begin
  UpdateSlideBox();
  Result := true;
end;

function  Object2DEvent.BeginDestroyObject(objRef: Integer): WordBool;
begin
  Result := true;
end;

function  Object2DEvent.DestroyObject(objRef: Integer): WordBool;
begin
  Result := true;
end;

function Object2DEvent.BeginPropertyChanged(objRef: Integer): WordBool;
begin
  Result := true;
end;


function Object2DEvent.PropertyChanged(objRef: Integer): WordBool;
begin
  Result := true;
end;


function NewDocumentEvent( doc : reference ) : DocumentEvent;
begin
  Result := nil;
  if doc <> 0 then begin
		if cBaseEvent.FindEvents( ntDocumentFileNotify, doc, 0, nil ) = nil then begin
			Result := DocumentEvent.Create( doc );
			if not Result.Advise() then begin
        Result.Free;
				Result := nil;
			end
		end
	end
end;

//-------------------------------------------------------------------------------
// Создать обработчик событий документа
// ---
function NewObj2DEvent( doc : Reference; objType : Integer ) : Object2DEvent;
begin
	Result := nil;
	if doc <> 0 then
	begin
  	if cBaseEvent.FindEvents( ntObject2DNotify, doc, objType, nil ) = nil then
    begin
			NewDocumentEvent( doc ); // чтобы при закрытии документа отписаться
			Result := Object2DEvent.Create( doc, objType );
			if not Result.Advise then
			begin
      	Result.Free;
				Result := nil;
			end;
		end;
	end;
end;

end.
