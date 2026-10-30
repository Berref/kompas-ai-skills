# PlacementCallBackW - Прототип функции обратной связи для запроса точки и угла (Unicode)

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции вывода на экран ](screen_output_fncts_common.html) |  Scroll [ [ [ ](returnresult.html "К следующему разделу")](screen_output_fncts_common.html "На уровень выше")](placementcallback.html "К предыдущему разделу")  
---|---  
  
Синтаксис:

typedef int ( WINAPI *PlacementCallBackW )( int com,

double * x,

double * y,

double * angle,

RequestInfoW * info,

void *phantom,

int dynamic );

Входные параметры:

com | \- идентификатор команды из окна команд,  
---|---  
x, y | \- координаты точки привязки,  
angle | \- угол наклона,  
info | \- указатель на область памяти для замены состава команд,  
phantom | \- указатель на фантомную группу,  
dynamic | \- признак динамического вызова.  
  
Возвращаемое значение:

1 | \- если нужно продолжить запрос,  
---|---  
0 | \- если нужно прекратить запрос.  
  
Примечание.

При использовании ANSI следует использовать функцию [PlacementCallBack](placementcallback.html).

Подразделы:

(отсутствуют)
