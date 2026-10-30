unit events;

{$IFDEF CONDITIONALEXPRESSIONS}
{$IF CompilerVersion >= 14 }
  {$WARN SYMBOL_PLATFORM OFF}
{$IFEND}
{$ENDIF}

interface
uses
  Windows,
  ksAuto,
  ksTLB;

var
  iKompasObject: KompasObject;
/////////////////////////////////////////////////////////////////////////////
// ApplicationEvent command target

  procedure  LIBRARYENTRY( command: WORD  );         Pascal;
  function   LIBRARYNAME                 : PAnsiChar;    Pascal;
  function   LIBRARYID                   : Cardinal; Pascal;
  function   LibInterfaceNotifyEntry ( app : PIDispatch) : boolean;  Pascal;
  procedure  MyDLLProc(Reason: Integer);
procedure AdviseDocuments;
//procedure DocumentEvents();
procedure AdviseDocumentEvents();
procedure UnAdviseDocumentEvents();
procedure AdviseDoc( pDoc : LongInt );

implementation

uses
  LDefin2D,
  ActiveX,
  forms,
  BaseEvents;

var
  aplEvent  : ApplicationEvent;

procedure MyDLLProc(Reason: Integer);

begin
  case Reason of
    DLL_PROCESS_DETACH: begin
      BaseEvent.TerminateEvents;
//      if aplEvent <> nil then begin
//        aplEvent.Unadvise;
      aplEvent := nil;
//      end;
//      doc       := nil;
      Application.Handle := 0;
      iKompasObject := nil;
    end;
    DLL_PROCESS_ATTACH: begin
      if  iKompasObject = nil  then
        iKompasObject := KompasObject(CreateKompasObject);
      Application.Handle := iKompasObject.ksGetHWindow;
    end;
  end;
end;


//------------------------------------------------------------------------------
// LibraryName
//---
function LIBRARYNAME: PAnsiChar; pascal;
begin
  Result := 'Пример обработки событий Компаса (Delphi AUTO)';
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
begin
  if  iKompasObject = nil  then
    iKompasObject := KompasObject(CreateKompasObject);
  if iKompasObject <> nil then
  begin
    Application.Handle := iKompasObject.ksGetHWindow;
    case command of
      10 : begin  // Подписаться на события Компаса
            if not BaseEvent.FindEvent( DIID_ksKompasObjectNotify, 0, -1 ) then
            begin
              aplEvent := ApplicationEvent.Create( iKompasObject  );  // обработчик событий приложения КОМПАС
              aplEvent.Advise;                         // подписка на события приложения КОМПАС
            end
            else
              LibMessage( 'Уже подписались', MB_OK );
          end;

      11 : begin
          if not BaseEvent.FindEvent( DIID_ksKompasObjectNotify, 0, -1 ) then
          begin
            if aplEvent <> nil then  begin
              aplEvent.Unadvise;
              aplEvent := nil;                            // отписаться от получения событий
            end
          end
        end;
			20: AdviseDocumentEvents(); // Подписаться на события документа
      21: UnAdviseDocumentEvents();
    end;
  end;
end;

procedure AdviseDocumentEvents();
var
  doc : Reference;
begin
  doc := GetActiveDocumentReference( 0 );
  if doc <> 0 then begin
    if not BaseEvent.FindEvent( DIID_ksDocumentFileNotify, doc, -1 ) then
      if NewDocumentEvent( doc ) <> nil then
        LibMessage( 'Подписались', MB_OK )
      else
        LibMessage( 'Подписаться не удалось', MB_OK )
		else
  		LibMessage( 'Уже подписались', MB_OK );
  end
	else
		LibMessage( 'Нет активного документа', MB_OK );
end;

procedure UnAdviseDocumentEvents();
var
  doc : Reference;
begin
	if iKompasObject <> nil then
  begin
    doc := GetActiveDocumentReference( 0 );
		if doc <> 0 then
			BaseEvent.TerminateEventsFromIID( GUID_NULL, doc, -1 );
  end;
end;

procedure AdviseObj2DEvents();
var
  doc : Reference;
begin
  doc := GetActiveDocumentReference( 1 );
  if doc <> 0 then begin
//		if  not BaseEvent.FindEvent( DIID_ksObject2DNotify, doc, -1 ) then
//  	  AdviseDoc( doc, false, true, false )
//		else
// 			LibMessage( 'Уже подписались', MB_OK )
  end
  else
		LibMessage( 'Нет активного документа', MB_OK );
end;

procedure UnAdviseObj2DEvents();
var
  doc : Reference;
begin
  doc := GetActiveDocumentReference( 1 );
  if doc <> 0 then begin
 		BaseEvent.TerminateEventsFromIID( DIID_ksObject2DNotify, doc, -1 );
    LibMessage( 'Отписалис', MB_OK );
  end
  else
		LibMessage( 'Нет активного документа', MB_OK );
end;

procedure AdviseSelectionEvents();
var
  doc : Reference;
begin
  doc := GetActiveDocumentReference( 0 );
  if doc <> 0 then begin
//    if not BaseEvent.FindEvent( DIID_ksSelectionMngNotify, doc, -1 ) then
//      AdviseDoc( doc, true, false, false )
//    else
// 		  LibMessage( 'Уже подписались', MB_OK );
  end
	else
		LibMessage( 'Нет активного документа', MB_OK );
end;

procedure UnAdviseSelectionEvents();
var
  doc : Reference;
begin
  doc := GetActiveDocumentReference( 0 );
  if doc <> 0 then begin
		BaseEvent.TerminateEventsFromIID( DIID_ksSelectionMngNotify, doc, -1 );
    LibMessage( 'Отписалис', MB_OK );
  end
	else
		LibMessage( 'Нет активного документа', MB_OK );
end;

procedure AdviseStampEvents();
var
  doc : Reference;
begin
  doc := GetActiveDocumentReference( 0 );
  if doc <> 0 then begin
//		if not BaseEvent.FindEvent( DIID_ksStampNotify, doc, -1 ) then
//      AdviseDoc( 0, false, false, true )
//		else
//			LibMessage( 'Уже подписались', MB_OK );
  end
  else
    LibMessage( 'Нет активного документа', MB_OK + MB_ICONERROR );
end;

procedure UnAdviseStampEvents();
var
  doc : Reference;
begin
  doc := GetActiveDocumentReference( 0 );
	if doc <> 0 then
		BaseEvent.TerminateEventsFromIID( DIID_ksStampNotify, doc, -1 );
end;


procedure AdviseDocuments();
var
  pDoc : LongInt;
  iter : ksIterator;
begin
	if iKompasObject <> nil then
  begin
		iter := ksIterator( iKompasObject.GetIterator );       // интерфейс итератора
    // создаем итератор для хождения по документам
		if ( iter <> nil ) and iter.ksCreateIterator( ALL_DOCUMENTS, 0 ) then
    begin
  		pDoc := iter.ksMoveIterator( 'F' );   // первый документ
      while pDoc <> 0 do
      begin
        AdviseDoc( pDoc );
        pDoc := iter.ksMoveIterator( 'N' );           // следующий документ
			end;
      iter.ksDeleteIterator;                       // удалить итератор
		end;
  end;
end;


//-----------------------------------------------------------------------------
// Провести подписку библиотеки на сообщения системы
// ---
function LibInterfaceNotifyEntry( app : PIDispatch ) : boolean;
begin
  if ( iKompasObject = nil ) and  ( app <> nil ) then               // захват интерфейса приложения КОМПАС
    iKompasObject := KompasObject( app );


  if iKompasObject <> nil then
  begin
    Application.Handle := iKompasObject.ksGetHWindow;
    aplEvent := ApplicationEvent.Create( iKompasObject );        // обработчик событий приложения КОМПАС
    aplEvent.Advise;                               // подписка на события приложения КОМПАС
    AdviseDocuments;
	end;

  Result := false;
end;

//-----------------------------------------------------------------------------
// подписка на события документа
// ---
procedure AdviseDoc( pDoc : Reference );
var
  docType   : Integer;
begin
  if pDoc = 0 then
    pDoc := GetActiveDocumentReference( 0 )
  else
    ActivateDoc( pDoc );
  if  pDoc <> 0 then begin
		docType := iKompasObject.ksGetDocumentType( pDoc );
    if ( NewDocumentEvent( pDoc ) <> nil ) then begin
      case docType of

        lt_DocSheetStandart ,                        // 1- чертеж стандартный
        lt_DocSheetUser     :                        // 2- чертеж нестандартный
        begin
          NewStampEvents(pDoc);
          NewSelectMngEvent( pDoc );
          NewObj2DEvent(pDoc, ALL_OBJ );
        end;
        lt_DocFragment      :                        // 3- фрагмент
        begin
          NewSelectMngEvent( pDoc );
          NewObj2DEvent(pDoc, ALL_OBJ );
        end;
        lt_DocSpc           ,                       // спецификация
        lt_DocSpcUser       :                       // спецификация нестандартный формат
          NewStampEvents(pDoc);
        lt_DocPart3D        ,                       // 3d-документ модель
        lt_DocAssemble3D    :                       // 3d-документ сборка

          NewSelectMngEvent( pDoc );
      end
    end
  end;
end;

end.









