# Интерфейс IProgressBarIndicator

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Параметры процесса ](ap1803662.html) |  Scroll [ [ [ ](iprogressbarindicator_methods.html "К следующему разделу")](ap1803662.html "На уровень выше")](iprocess3d_runtakecreateobjectprocess.html "К предыдущему разделу")  
---|---  
  
Интерфейс индикатора прогресса.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[IProgressBarIndicator](iprogressbarindicator.html)

Описание:

Позволяет запускать, устанавливать текущее значение, останавливать индикатор прогресса, устанавливать текст в строке состояния.

Примечание:

1\. Данный интерфейс можно получить от интерфейса IApplication с помощью метода [IApplication::ProgressBarIndicator](iapplication_progressbarindicator.html).

2\. Для работы с индикатором прогресса необходимо, получив указатель на интерфейс индикатора, запустить его командой [IProgressBarIndicator::Start](iprogressbarindicator_start.html). Текущие значения и текст устанавливать командой [IProgressBarIndicator::SetProgress](iprogressbarindicator_setprogress.html). По завершении отображаемого процесса завершить работу с индикатором командой [IProgressBarIndicator::Stop](iprogressbarindicator_stop.html). Для отображения следующего процесса необходимо повторно запустить индикатор (при необходимости с новыми параметрами) от ранее полученного указателя на интерфейс.

3\. Команда [IProgressBarIndicator::SetText](iprogressbarindicator_settext.html) выполняется независимо от того, запущен индикатор прогресса или нет.

4\. Если получены несколько указателей на интерфейс [IProgressBarIndicator](iprogressbarindicator.html), и по одному из указателей индикатор запущен командой [IProgressBarIndicator::Start](iprogressbarindicator_start.html), по любому другому указателю может быть выполнена команда [IProgressBarIndicator::SetProgress](iprogressbarindicator_setprogress.html) или [IProgressBarIndicator::Stop](iprogressbarindicator_stop.html). Команда [IProgressBarIndicator::Start](iprogressbarindicator_start.html) повторно не выполняется до остановки индикатора.

Подразделы:

[IProgressBarIndicator - методы ](iprogressbarindicator_methods.html)
