# ksStartProgressBarW - Запустить индикатор прогресса (Unicode)

[API экспортных функций](export_function.html) > [Функции работы с документами ](docum_fncts_common.html) > [Сервисные функции ](serv_fncts_common.html) |  Scroll [ [ [ ](ksstopprogressbarw.html "К следующему разделу")](serv_fncts_common.html "На уровень выше")](ksstartprogressbar.html "К предыдущему разделу")  
---|---  
  
Аналог данного метода при использовании Automation – [IProgressBarIndicator::Start](iprogressbarindicator_start.html).

Синтаксис:

void LIB_FUNC ksStartProgressBar (long minVal, long maxVal, LPWSTR newText, int resetText);

Входные параметры:

minVal | \- минимальное значение шкалы,  
---|---  
maxVal | \- максимальное значение шкалы,  
newText | \- текст в строке состояния,  
resetText | 1 - обновить текст в строке состояния, 0 - не обновлять.  
  
Примечание:

1\. После завершения работы индикатор процесса должен быть остановлен командой [ksStopProgressBar](ksstopprogressbar.html).

2\. При использовании ANSI следует использовать функцию [ksStartProgressBar](ksstartprogressbar.html).

Подразделы:

(отсутствуют)
