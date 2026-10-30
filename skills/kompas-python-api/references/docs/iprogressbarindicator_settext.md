# SetText - Установить текст в строке состояния индикатора

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Параметры процесса ](ap1803662.html) > [Интерфейс IProgressBarIndicator ](iprogressbarindicator.html) > [IProgressBarIndicator - методы ](iprogressbarindicator_methods.html) |  Scroll [ [ [ ](iprogressbarindicator_start.html "К следующему разделу")](iprogressbarindicator_methods.html "На уровень выше")](iprogressbarindicator_setprogress.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iprogressbarindicator.html)

Аналог данного метода при использовании API экспортных функций - [ksSetProgressText](kssetprogresstext.html).

Синтаксис Automation:

void SetText (LPCTSTR newText);

Синтаксис COM:

HRESULT SetText (BSTR newText);

Входные параметры:

newText | \- текст в строке состояния,  
---|---  
  
Примечание:

1\. Метод выполняется как при запущенном индикаторе прогресса командой [IProgressBarIndicator::Start](iprogressbarindicator_start.html), так и при остановленном.

2\. Если команда выполняется при запущенном индикаторе прогресса, устанавливаемый текст запоминается как последний текст перед запуском индикатора, и после остановки индикатора командой [IProgressBarIndicator::Stop](iprogressbarindicator_stop.html) в строке состояния будет отображаться текст newText.

Подразделы:

(отсутствуют)
