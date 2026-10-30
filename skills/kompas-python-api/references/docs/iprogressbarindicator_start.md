# Start - Запустить индикатор прогресса

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Параметры процесса ](ap1803662.html) > [Интерфейс IProgressBarIndicator ](iprogressbarindicator.html) > [IProgressBarIndicator - методы ](iprogressbarindicator_methods.html) |  Scroll [ [ [ ](iprogressbarindicator_stop.html "К следующему разделу")](iprogressbarindicator_methods.html "На уровень выше")](iprogressbarindicator_settext.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iprogressbarindicator.html)

Аналог данного метода при использовании API экспортных функций - [ksStartProgressBar](ksstartprogressbar.html).

Синтаксис Automation:

void Start (long minVal, long maxVal, LPCTSTR newText, BOOL resetText);

Синтаксис COM:

HRESULT Start (long minVal, long maxVal, BSTR newText, VARIANT_BOOL resetText);

Входные параметры:

minVal | \- минимальное значение шкалы,  
---|---  
maxVal | \- максимальное значение шкалы,  
newText | \- текст в строке состояния,  
resetText | \- TRUE - обновить текст в строке состояния.  
  
Примечание:

После завершения работы индикатор прогресса должен быть остановлен командой [IProgressBarIndicator::Stop](iprogressbarindicator_stop.html).

Подразделы:

(отсутствуют)
