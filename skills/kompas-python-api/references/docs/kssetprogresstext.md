# ksSetProgressText - Установить текст в строке состояния индикатора прогресса

[API экспортных функций](export_function.html) > [Функции работы с документами ](docum_fncts_common.html) > [Сервисные функции ](serv_fncts_common.html) |  Scroll [ [ [ ](kssetprogresstextw.html "К следующему разделу")](serv_fncts_common.html "На уровень выше")](kssetprogressbarw.html "К предыдущему разделу")  
---|---  
  
Аналог данного метода при использовании Automation – [IProgressBarIndicator::SetText](iprogressbarindicator_settext.html).

Синтаксис:

void LIB_FUNC ksSetProgressText (char * newText);

Входные параметры:

newText | \- текст в строке состояния.  
---|---  
  
Примечание:

1\. Метод выполняется как при запущенном индикаторе прогресса командой [ksStartProgressBar](ksstartprogressbar.html), так и при остановленном.

2\. Если команда выполняется при запущенном индикаторе прогресса, устанавливаемый текст запоминается как последний текст перед запуском индикатора, и после остановки индикатора командой [ksStopProgressBar](ksstopprogressbar.html) в строке состояния будет отображаться текст newText.

3\. При использовании Unicode следует использовать функцию [ksSetProgressTextW](kssetprogresstextw.html).

Подразделы:

(отсутствуют)
