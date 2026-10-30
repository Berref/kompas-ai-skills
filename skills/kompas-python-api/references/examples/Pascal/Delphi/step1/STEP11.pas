////////////////////////////////////////////////////////////////////////////////
//
// step11.pas - Самая простая библиотека на Delphi
//
////////////////////////////////////////////////////////////////////////////////
unit Step11;

interface
 procedure  LIBRARYENTRY( comm: WORD  ); Pascal;
 function   LIBRARYNAME : PAnsiChar;     Pascal;

 implementation

 uses  LibTool, Sysutils;

//----------------------------------------------------------------------------------------
// Головная функция библиотеки
//---
procedure  LIBRARYENTRY( comm : Word  );  Pascal;
begin
  // Выдача сообщения пользователю
  ksMessage( 'Привет' );
end;

//----------------------------------------------------------------------------------------
// Имя библиотеки
//---
function LIBRARYNAME : PAnsiChar;  Pascal;
begin
  Result:='Самая простая библиотека (Delphi)';
end;

end.
