# ksSetProgressBar - Установить текущее значение индикатора прогресса

[API экспортных функций](export_function.html) > [Функции работы с документами ](docum_fncts_common.html) > [Сервисные функции ](serv_fncts_common.html) |  Scroll [ [ [ ](kssetprogressbarw.html "К следующему разделу")](serv_fncts_common.html "На уровень выше")](kssetlookstyle.html "К предыдущему разделу")  
---|---  
  
Аналог данного метода при использовании Automation – [IProgressBarIndicator::SetProgress](iprogressbarindicator_setprogress.html).

Синтаксис:

void LIB_FUNC ksSetProgressBar (long currentVal, char * newText, int resetText);

Входные параметры:

currentVal | \- текущее значение значение индикатора,  
---|---  
newText | \- текст в строке состояния,  
resetText | 1 - обновить текст в строке состояния, 0 - не обновлять.  
  
Примечание:

1\. Метод выполняется, если индикатор прогресса запущен командой [ksStartProgressBar](ksstartprogressbar.html).

2\. При использовании Unicode следует использовать функцию [ksSetProgressBarW](kssetprogressbarw.html).

Подразделы:

(отсутствуют)
