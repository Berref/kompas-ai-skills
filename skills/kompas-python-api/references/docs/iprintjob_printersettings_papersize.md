# PaperSize - Размер бумаги

[API интерфейсов. Версия 7](applicate.html) > [Печать ](bh1473974.html) > [Интерфейс IPrintJob_PrinterSettings ](iprintjob_printersettings.html) > [IPrintJob_PrinterSettings - свойства ](iprintjob_printersettings_props.html) |  Scroll [ [ [ ](iprintjob_printersettings_papersource.html "К следующему разделу")](iprintjob_printersettings_props.html "На уровень выше")](iprintjob_printersettings_paperlength.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iprintjob_printersettings.html)

Тип данных: long

Синтаксис Automation:

PaperSize = Object.PaperSize | Получить свойство ([* ](1.html))  
---|---  
Object.PaperSize = PaperSize | Установить свойство ([* ](1.html))  
PaperSize = Object.GetPaperSize() | Получить свойство ([**](2.html))  
Object.SetPaperSize( PaperSize ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_PaperSize( &PaperSize ) | Получить свойство  
---|---  
Object.put_PaperSize( PaperSize ) | Установить свойство  
  
Примечание:

1\. Значение свойства задается из списка предопределенных констант (подробнее см. описание переменной dmPaperSize из структуры DEVMODE в MSDN).

2\. Используется, если не заданы длина и ширина.

Подразделы:

(отсутствуют)
