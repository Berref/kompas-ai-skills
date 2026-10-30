unit Step111;
//******************************************************************/
//                (c)Акционерное общество АСКОН                    */
//*                Санкт-Петербург, 1991, 1996                     */
//*                 Компас-Мастер  версия 5.x                      */
//******************************************************************/
//*                    Библиотека примеров                         */
//*             Пример запроса командного окна                     */
//*                                                                */
//******************************************************************/

interface
 uses  Sysutils, LtDefine, LibTool, step110, LDefin2D;

 procedure  LIBRARYENTRY( comm: WORD  ); Pascal;
// function   LIBRARYID   : Cardinal;      Pascal;
 function   LIBRARYNAME : PAnsiChar;  pascal;
 function CallBackCommand( info : PRequestInfo; command : integer ): Integer;  pascal;

 implementation


//----------------------------------------------------------------------------------------
//
//---
//function   LIBRARYID : Cardinal;  pascal;
//begin
//  Result:=100;
//end;

//----------------------------------------------------------------------------------------
//
//---
function LIBRARYNAME : PAnsiChar;  pascal;
begin
  Result:='Пример запроса командного окна';
end;

//----------------------------------------------------------------------------------------
//
//---
procedure  LIBRARYENTRY( comm : Word  );  pascal;
var
 info    : RequestInfo  ;
 command : integer;
 buf : AnsiString;
begin
// Обращаемся к системе с запросом на создание окна с деревом команд.
// Если в качестве функции обратного вызова задан NULL,
// то управление из CommandWindow возвращается немедленно,
// как только пользователь выберет команду в дереве команд.
// Прт этом возвращается идентификатор выбранной команды.
// В противном случае управление вернется, если пользователь закроет окно
// или функция обратного вызова вернет FALSE.
// При этом возвращается -1.
 FillChar( info, sizeof(info), 0 );
 info.commands := PAnsiChar(ID_TREE_CONTENTS);  //идентификатор меню с составом дерева команд
 info.title :=  PAnsiChar(ID_WINDOW_TITLE_1); //идентификатор строки заголовка окна
 info.callBack := Addr(CallBackCommand);
  command := CommandWindow( Addr(info) );
  buf := Format ( 'выбрана команда = %d', [command] );
  ksMessage( PAnsiChar(buf));

end;

//----------------------------------------------------------------------------------------
//
//---
function CallBackCommand( info : PRequestInfo; command : integer ): Integer;  pascal;
var
  buf : AnsiString;

begin
  buf := Format ( 'command = %d', [command] );
  ksMessage( PAnsiChar(buf));
// заменяем заголовок окна в зависимости от выполненной команды
// аналогично можно заменить и состав дерева команд
  if ( command = ID_COMMAND_1 )  then
    info^.title := PAnsiChar(ID_WINDOW_TITLE_2)
  else
    info^.title := PAnsiChar(ID_WINDOW_TITLE_3);

// возвращаемый результат определяет, должна ли система продолжать
// запрашивать команду :
// TRUE - продолжать
// FALSE - завержить работу с окном
   CallBackCommand := Integer(command=ID_COMMAND_2_2_1_3);
end;

end.
