# GetPagesMapGabarites - Получить размеры карты страниц

[API интерфейсов. Версия 7](applicate.html) > [Печать ](bh1473974.html) > [Интерфейс IPrintJob ](iprintjob.html) > [IPrintJob - методы ](iprintjob_methods.html) |  Scroll [ [ [ ](iprintjob_removesheets.html "К следующему разделу")](iprintjob_methods.html "На уровень выше")](iprintjob_getpagegabarites.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iprintjob.html)

Синтаксис Automation:

BOOL GetPagesMapGabarites( long * WPageCount,

long * HPageCount );

Синтаксис COM:

HRESULT GetPagesMapGabarites( long * WPageCount,

long * HPageCount,

BOOL * Result );;

Выходные параметры:

WPageCount | \- количество страниц по горизонтали,  
---|---  
HPageCount | \- количество страниц по вертикали.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет получить размеры карты страниц - количество страниц по вертикали и горизонтали.

Подразделы:

(отсутствуют)
