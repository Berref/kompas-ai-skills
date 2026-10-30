# ksSetProgressBarW - Установить текущее значение индикатора прогресса (Unicode)

[API экспортных функций](export_function.html) > [Функции работы с документами ](docum_fncts_common.html) > [Сервисные функции ](serv_fncts_common.html) |  Scroll [ [ [ ](kssetprogresstext.html "К следующему разделу")](serv_fncts_common.html "На уровень выше")](kssetprogressbar.html "К предыдущему разделу")  
---|---  
  
Аналог данного метода при использовании Automation – [IProgressBarIndicator::SetProgress](iprogressbarindicator_setprogress.html).

Синтаксис:

void LIB_FUNC ksSetProgressBarW (long currentVal, LPWSTR newText, int resetText);

Входные параметры:

currentVal | \- текущее значение значение индикатора,  
---|---  
newText | \- текст в строке состояния,  
resetText | 1 - обновить текст в строке состояния, 0 - не обновлять.  
  
Примечание:

1\. Метод выполняется, если индикатор прогресса запущен командой [ksStartProgressBarW](ksstartprogressbarw.html).

2\. При использовании ANSI следует использовать функцию [ksSetProgressBar](kssetprogressbar.html).

Подразделы:

(отсутствуют)
