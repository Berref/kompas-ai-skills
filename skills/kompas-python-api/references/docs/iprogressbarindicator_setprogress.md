# SetProgress - Установить текущее значение индикатора

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Параметры процесса ](ap1803662.html) > [Интерфейс IProgressBarIndicator ](iprogressbarindicator.html) > [IProgressBarIndicator - методы ](iprogressbarindicator_methods.html) |  Scroll [ [ [ ](iprogressbarindicator_settext.html "К следующему разделу")](iprogressbarindicator_methods.html "На уровень выше")](iprogressbarindicator_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iprogressbarindicator.html)

Аналог данного метода при использовании API экспортных функций - [ksSetProgressBar](kssetprogressbar.html)

Синтаксис Automation:

void SetProgress (long currentVal, LPCTSTR newText, BOOL resetText);

Синтаксис COM:

HRESULT SetProgress (long currentVal, BSTR newText, VARIANT_BOOL resetText);

Входные параметры:

currentVal | \- текущее значение значение индикатора,  
---|---  
newText | \- текст в строке состояния,  
resetText | \- TRUE - обновить текст в строке состояния.  
  
Примечание:

Метод выполняется, если индикатор прогресса запущен командой [IProgressBarIndicator::Start](iprogressbarindicator_start.html).

Подразделы:

(отсутствуют)
