# Hooking - Диапазон привязки к узлам страниц

[API интерфейсов. Версия 7](applicate.html) > [Печать ](bh1473974.html) > [Интерфейс IPrintJob_OutputParameters ](iprintjob_outputparameters.html) > [IPrintJob_OutputParameters - свойства ](iprintjob_outputparameters_props.html) |  Scroll [ [ [ ](iprintjob_outputparameters_numberofcopies.html "К следующему разделу")](iprintjob_outputparameters_props.html "На уровень выше")](iprintjob_outputparameters_defaultscale.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iprintjob_outputparameters.html)

Тип данных: long

Синтаксис Automation:

Hooking = Object.Hooking | Получить свойство ([* ](1.html))  
---|---  
Object.Hooking = Hooking | Установить свойство ([* ](1.html))  
Hooking = Object.GetHooking() | Получить свойство ([**](2.html))  
Object.SetHooking( Hooking ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_Hooking( &Hooking ) | Получить свойство  
---|---  
Object.put_Hooking( Hooking ) | Установить свойство  
  
Примечание:

1\. Свойство позволяет устанавливать и получать диапазон привязки к узлам страниц.

2\. Если задаваемое значение находится вне диапазона (1: 50), то его значение корректируется к ближайшему (минимальному или максимальному) значению.

Подразделы:

(отсутствуют)
