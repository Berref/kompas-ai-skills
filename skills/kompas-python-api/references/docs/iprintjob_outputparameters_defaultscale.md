# DefaultScale - Масштаб листов по умолчанию

[API интерфейсов. Версия 7](applicate.html) > [Печать ](bh1473974.html) > [Интерфейс IPrintJob_OutputParameters ](iprintjob_outputparameters.html) > [IPrintJob_OutputParameters - свойства ](iprintjob_outputparameters_props.html) |  Scroll [ [ [ ](iprintjob_outputparameters_hooking.html "К следующему разделу")](iprintjob_outputparameters_props.html "На уровень выше")](iprintjob_outputparameters_color.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iprintjob_outputparameters.html)

Тип данных: double

Синтаксис Automation:

DefaultScale = Object.DefaultScale | Получить свойство ([* ](1.html))  
---|---  
Object.DefaultScale = DefaultScale | Установить свойство ([* ](1.html))  
DefaultScale = Object.GetDefaultScale() | Получить свойство ([**](2.html))  
Object.SetDefaultScale( DefaultScale ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_DefaultScale( &DefaultScale ) | Получить свойство  
---|---  
Object.put_DefaultScale( DefaultScale ) | Установить свойство  
  
Примечание:

1\. Свойство позволяет устанавливать и получать масштаб листов по умолчанию.

2\. Если задаваемое значение находится вне диапазона (1e-006 : 1e+006), то его значение корректируется к ближайшему (минимальному или максимальному) значению.

Подразделы:

(отсутствуют)
