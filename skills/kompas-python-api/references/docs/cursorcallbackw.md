# CursorCallBackW - Прототип функции обратной связи для запроса точки (Unicode)

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции вывода на экран ](screen_output_fncts_common.html) |  Scroll [ [ [ ](drawbitmap.html "К следующему разделу")](screen_output_fncts_common.html "На уровень выше")](cursorcallback.html "К предыдущему разделу")  
---|---  
  
Синтаксис:

typedef int ( WINAPI *CursorCallBackW )( int com,

double * x,

double * y,

RequestInfoW * info,

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

При использовании ANSI следует использовать функцию [CursorCallBack](cursorcallback.html).

Подразделы:

(отсутствуют)
