unit step111;

{$IFDEF CONDITIONALEXPRESSIONS}
{$IF CompilerVersion >= 14 }
  {$WARN SYMBOL_PLATFORM OFF}
{$IFEND}
{$ENDIF}


interface
uses
  Windows,
  SysUtils,
  LDefin2D,
  ksConstTLB,
  ksAuto,
{$IFDEF __LIGHT_VERSION__}
  klTLB;
{$ELSE}
  ksTLB;
{$ENDIF}

  function  LIBRARYNAME: PAnsiChar; pascal;
  procedure LIBRARYENTRY( command: WORD  ); Pascal;
  function  LIBRARYID: Cardinal; Pascal;
  function  CallBackProcCommandWindow( comm : Integer; rInfo : PIDispatch ) : Integer; stdcall;

implementation

var
  kompas : KompasObject;
  doc    : ksDocument2D;
//------------------------------------------------------------------------------
// LibraryId
//---
function LIBRARYID: UINT; pascal;
begin
  Result := 100;
end;


//------------------------------------------------------------------------------
// функция обратной связи
// 0 - плоскость, 1 - цилиндр, 2 - ось - состав collection
// ---
function CallBackProcCommandWindow( comm : Integer; rInfo : PIDispatch ) : Integer; stdcall; Export;
var
  info : ksRequestInfo;
begin
//  char buf[10];
//  ::itoa( comm, buf, 10 );
  kompas.ksMessage( 'Выполняется команда' );
  // заменяем заголовок окна в зависимости от выполненной команды
  // аналогично можно заменить и состав дерева команд
	info := ksRequestInfo( rInfo );
	if ( info <> nil ) then begin
		case comm of
			1 {ID_COMMAND_1} : info.title := '1';
      else info.title := '2';
		end;
	end;
  // возвращаемый результат определяет, должна ли система продолжать
  // запрашивать команду :
  // TRUE - продолжать
  // FALSE - завержить работу с окном
  if ( comm = 14{ID_COMMAND_2_2_1_3} ) then
    Result := 0
  else
    Result := 1;
end;

//------------------------------------------------------------------------------
// LibraryEntry
//---
procedure LIBRARYENTRY( command: WORD ); pascal;
var
 info    : ksRequestInfo;
// comm    : integer;
begin
  kompas := KompasObject( CreateKompasObject );
  if kompas <> nil then begin
    doc  := ksDocument2D( kompas.Document2D() );
    info := ksRequestInfo( kompas.GetParamStruct(ko_RequestInfo) );
    if ( doc <> nil ) and ( info <> nil ) then begin
	    info.Init();
      info.MenuId := 100; // ID_TREE_CONTENTS;
      info.Title := 'Дерево команд';
  	  info.SetCallBackCm( 'CALLBACKPROCCOMMANDWINDOW', HInstance, nil );
      {comm := }doc.ksCommandWindow( info );
//    char buf[10];
//    ::itoa( command, buf, 10 );
      kompas.ksMessage( 'Выбрана команда' );
    end;
    kompas := nil;
	end;
end;

//------------------------------------------------------------------------------
// LibraryName
//---
function LIBRARYNAME: PAnsiChar; pascal;
begin
  Result := 'Пример запроса командного окна';
end;

end.
