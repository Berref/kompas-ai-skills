# Stop - Остановить индикатор прогресса

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Параметры процесса ](ap1803662.html) > [Интерфейс IProgressBarIndicator ](iprogressbarindicator.html) > [IProgressBarIndicator - методы ](iprogressbarindicator_methods.html) |  Scroll [ [ [ ](iprocessinfowindow.html "К следующему разделу")](iprogressbarindicator_methods.html "На уровень выше")](iprogressbarindicator_start.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iprogressbarindicator.html)

Аналог данного метода при использовании API экспортных функций - [ksStopProgressBar](ksstopprogressbar.html).

Синтаксис Automation:

void Stop (LPCTSTR newText, BOOL resetTxt);

Синтаксис COM:

HRESULT Stop (BSTR newText, VARIANT_BOOL resetTxt);

Входные параметры:

newText | \- текст в строке состояния,  
---|---  
resetText | \- TRUE - обновить текст в строке состояния.  
  
Примечание:

Метод выполняется, если индикатор прогресса запущен командой [IProgressBarIndicator::Start](iprogressbarindicator_start.html).

Подразделы:

(отсутствуют)
