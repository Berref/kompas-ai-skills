# PageOutputOrder - Порядок вывода страниц на печать

[API интерфейсов. Версия 7](applicate.html) > [Печать ](bh1473974.html) > [Интерфейс IPrintJob_OutputParameters ](iprintjob_outputparameters.html) > [IPrintJob_OutputParameters - свойства ](iprintjob_outputparameters_props.html) |  Scroll [ [ [ ](iprintjob_outputparameters_plottofile.html "К следующему разделу")](iprintjob_outputparameters_props.html "На уровень выше")](iprintjob_outputparameters_onlythinlines.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iprintjob_outputparameters.html)

Тип данных: long

Синтаксис Automation:

PageOutputOrder = Object.PageOutputOrder | Получить свойство ([* ](1.html))  
---|---  
Object.PageOutputOrder = PageOutputOrder | Установить свойство ([* ](1.html))  
PageOutputOrder = Object.GetPageOutputOrder() | Получить свойство ([**](2.html))  
Object.SetPageOutputOrder( PageOutputOrder ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_PageOutputOrder( &PageOutputOrder ) | Получить свойство  
---|---  
Object.put_PageOutputOrder( PageOutputOrder ) | Установить свойство  
  
Примечание:

1\. Свойство позволяет устанавливать и получать порядок вывода страниц на печать.

2\. Если задаваемое значение вне диапазона (1:8), то его значение корректируется к ближайшему (минимальному или максимальному) значению.

Подразделы:

(отсутствуют)
