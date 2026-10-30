# Sheet - Интерфейс листа документа

[API интерфейсов. Версия 7](applicate.html) > [Печать ](bh1473974.html) > [Интерфейс IPrintJob ](iprintjob.html) > [IPrintJob - свойства ](iprintjob_props.html) |  Scroll [ [ [ ](iprintjob_methods.html "К следующему разделу")](iprintjob_props.html "На уровень выше")](iprintjob_sheetscount.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iprintjob.html)

Тип данных: указатель на интерфейс листа документа [IPrintJob_Sheet](iprintjob_sheet_.html)

Синтаксис Automation:

Sheet = Object.Sheet ( Index )  | Получить свойство ([* ](1.html))  
---|---  
Sheet = Object.GetSheet( Index ) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_Sheet( Index, &Sheet ) | Получить свойство  
---|---  
  
Входные параметры:

long Index | \- индекс листа, нумерация с единицы.  
---|---  
  
Примечание:

1\. Свойство позволяет получать интерфейс листа документа.

2\. Свойство доступно только для чтения.
