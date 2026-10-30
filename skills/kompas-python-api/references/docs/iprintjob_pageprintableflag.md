# PagePrintableFlag - Признак печатаемости страницы по ее индексам

[API интерфейсов. Версия 7](applicate.html) > [Печать ](bh1473974.html) > [Интерфейс IPrintJob ](iprintjob.html) > [IPrintJob - свойства ](iprintjob_props.html) |  Scroll [ [ [ ](iprintjob_sheetscount.html "К следующему разделу")](iprintjob_props.html "На уровень выше")](iprintjob_pagescount.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iprintjob.html)

Тип данных: BOOL

Синтаксис Automation:

PagePrintableFlag = Object.PagePrintableFlag( WPage, HPage ) | Получить свойство ([* ](1.html))  
---|---  
Object.PagePrintableFlag( WPage, HPage ) = PagePrintableFlag | Установить свойство ([* ](1.html))  
PagePrintableFlag = Object.GetPagePrintableFlag( WPage, HPage ) | Получить свойство ([**](2.html))  
Object.SetPagePrintableFlag( WPage, HPage, DimensionLineScale ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_PagePrintableFlag( WPage, HPage, &PagePrintableFlag ) | Получить свойство  
---|---  
Object.put_PagePrintableFlag( WPage, HPage, PagePrintableFlag ) | Установить свойство  
  
Входные параметры:

long WPage | \- индекс страницы по горизонтали,  
---|---  
long HPage | \- индекс страницы по вертикали.  
  
Примечание:

1\. Свойство позволяет включить/отключить печать страницы по ее индексам (по горизонтали и вертикали). Если индексы заданы вне диапазона, возвращается FALSE.

2\. Состояние страницы сбросится, если в результате перемещения листов какой-либо из ее индексов станет не действительным.

Подразделы:

(отсутствуют)
