# Delphi

[Компиляция библиотек](compiling_libraries.html) |  Scroll [ [ [ ](compiling_delphi_automation.html "К следующему разделу")](compiling_libraries.html "На уровень выше")](compiling_builder_c_automation.html "К предыдущему разделу")  
---|---  
  
Замените файлы LibTool.pas, LIBdb.pas, LDefin.pas, LDefin2D.pas, LDefin3D.pas на новые.   
Возможность компиляции 64-разрядных библиотек есть в Embarcadero RAD Studio XE2 и выше.   
При компиляции под x64 не работает директива __pascal.   
Требуется изменение функций. Критично для функций, имеющих более одного параметра.  
Требуется разворот параметров функций.

Старый вариант:

function CallBackP( _dynamic : Integer; // Признак динамического процесса  
phantom : Pointer; // Фантом  
info : PRequestInfo; // Параметры запроса  
var angl, y, x : Double; // Параметры запроса  
com : integer ) : Integer; pascal ; // Номер команды

Новый вариант:

function CallBackP( com : integer;  
var x, y, angl : Double; // Координаты курсора  
info : PRequestInfo; // Параметры запроса  
phantom : Pointer; // Фантом  
_dynamic : Integer // Признак динамического процесса  
) : Integer; stdcall; // Номер команды

Классы string и TString стали Unicod-ными, указатель PChar также стал Unicod-ным.   
Требуется замена на использование AnsiString и PАnsiChar.  
Рекомендуется выполнить перевод библиотеки на использование Unicod-ных аналогов структур и функций. При выполнении перевода рекомендуется использование Unicod-ных классов строк WideString и указателя на строку PWideChar.
