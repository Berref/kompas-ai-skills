unit events;

interface
uses
  Windows;

/////////////////////////////////////////////////////////////////////////////
// ApplicationEvent command target

  procedure  LIBRARYENTRY( command: WORD  ); Pascal;
  function   LIBRARYNAME : PAnsiChar;         Pascal;
  function   LIBRARYID   : Cardinal;      Pascal;
  procedure  MyDLLProc(Reason: Integer);

implementation

uses
  LtDefine,
  LibTool,
  cBaseEvents,
  ApplicationEvents,
  DocumentEvents,
  ksConstTLB;

procedure MyDLLProc(Reason: Integer);

begin
  if Reason = DLL_PROCESS_DETACH then begin
    cBaseEvent.TerminateEvents;
  end;
end;


//------------------------------------------------------------------------------
// LibraryName
//---
function LIBRARYNAME: PAnsiChar; pascal;
begin
  Result := 'Пример обработки событий Компаса (Delphi COM)';
end;

//------------------------------------------------------------------------------
// LibraryId
//---
function LIBRARYID: UINT; pascal;
begin
  Result := 100;
end;

//------------------------------------------------------------------------------
// LibraryEntry
//---
procedure LIBRARYENTRY(command: WORD); pascal;
var
  doc : reference;
begin
//  ksMessage( 'Привет' );
  case command of
    10 : begin                                      // Комманда 1
      if cBaseEvent.FindEvents( ntKompasObjectNotify, 0, -1, nil ) = nil then begin
        if NewApplicationEvent <> nil then               // подписка на события приложения КОМПАС
          ksMessage( 'Подписались' )
        else
          ksMessage( 'Не подписались' );
      end
      else
        ksMessage( 'Уже подписались' );
    end;
    11 : begin                                      // Комманда 2
      cBaseEvent.TerminateEventsByParam( ntKompasObjectNotify, 0, -1, nil );
      ksMessage( 'Отписались' );
    end;
    20 : begin
      doc := ksGetCurrentDocument( 0 );
      if doc <> 0 then begin
        if  NewDocumentEvent( doc ) <> nil  then
          ksMessage( 'Подписались' )
        else
          ksMessage( 'Не подписались' );
      end
      else
        ksMessage( 'Нет активного документа' );
    end;
    21 : begin
      doc := ksGetCurrentDocument( 0 );
      if doc <> 0 then begin
        cBaseEvent.TerminateEventsByParam( ntDocumentFileNotify, doc, -1, nil );
        if cBaseEvent.FindEvents( ntDocumentFileNotify, doc, -1, nil ) = nil then
          ksMessage( 'Отписались' )
        else
          ksMessage( 'Не отписались' );
      end
      else
        ksMessage( 'Нет активного документа' );
    end;

  end;
end;

end.

