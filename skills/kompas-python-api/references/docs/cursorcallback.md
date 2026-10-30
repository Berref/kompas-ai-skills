# CursorCallBack - Прототип функции обратной связи для запроса точки

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции вывода на экран ](screen_output_fncts_common.html) |  Scroll [ [ [ ](cursorcallbackw.html "К следующему разделу")](screen_output_fncts_common.html "На уровень выше")](commandwindowcallbackw.html "К предыдущему разделу")  
---|---  
  
Синтаксис:

typedef int ( WINAPI *CursorCallBack )( int com,

double * x,

double * y,

RequestInfo * info,

void *phantom,

int dynamic );

Входные параметры:

com | \- идентификатор команды из окна команд,  
---|---  
x, y | \- координаты точки привязки,  
info | \- указатель на область памяти для замены состава команд,  
phantom | \- указатель на фантомную группу,  
dynamic | \- признак динамического вызова.  
  
Возвращаемое значение:

1 | \- если нужно продолжить запрос,  
---|---  
0 | \- если нужно прекратить запрос.  
  
Примечание.

При использовании Unicode следует использовать функцию [CursorCallBackW](cursorcallbackw.html).

Подразделы:

(отсутствуют)
