# ksStopProgressBar - Остановить индикатор прогресса

[API экспортных функций](export_function.html) > [Функции работы с документами ](docum_fncts_common.html) > [Сервисные функции ](serv_fncts_common.html) |  Scroll [ [ [ ](ksstopprogressbar.html "К следующему разделу")](serv_fncts_common.html "На уровень выше")](ksstartprogressbarw.html "К предыдущему разделу")  
---|---  
  
Аналог данного метода при использовании Automation – [IProgressBarIndicator::Stop](iprogressbarindicator_stop.html).

Синтаксис:

void LIB_FUNC ksStopProgressBar (char * newText, int resetTxt);

Входные параметры:

newText | \- текст в строке состояния,  
---|---  
resetText | 1 - обновить текст в строке состояния, 0 - не обновлять.  
  
Примечание:

Метод выполняется, если индикатор прогресса запущен командой [ksStartProgressBar](ksstartprogressbar.html).

Подразделы:

(отсутствуют)
