# CommandWindowCallBack - Прототип функции обратной связи для запроса окна с деревом команд

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции вывода на экран ](screen_output_fncts_common.html) |  Scroll [ [ [ ](commandwindowcallbackw.html "К следующему разделу")](screen_output_fncts_common.html "На уровень выше")](screen_output_fncts_common.html "К предыдущему разделу")  
---|---  
  
Синтаксис:

typedef int ( WINAPI *CommandWindowCallBack )( int com,

RequestInfo * info );

Входные параметры:

com | \- идентификатор команды из окна команд,  
---|---  
info | \- указатель на область памяти для замены состава команд.  
  
Возвращаемое значение:

1 | \- если нужно продолжить запрос,  
---|---  
0 | \- если нужно прекратить запрос.  
  
Примечание.

При использовании Unicode следует использовать функцию [CommandWindowCallBackW](commandwindowcallbackw.html).

Подразделы:

(отсутствуют)
