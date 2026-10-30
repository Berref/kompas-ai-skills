# GetWorkAreaRect - Размеры свободной рабочей области (за вычетом быстрой панели)

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Окна документа ](ba1782194.html) > [Интерфейс IDocumentFrame ](idocumentframe.html) > [IDocumentFrame - методы ](idocumentframe_methods.html) |  Scroll [ [ [ ](idocumentframe_getzoomscale.html "К следующему разделу")](idocumentframe_methods.html "На уровень выше")](idocumentframe_getpickray.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](idocumentframe.html)

Синтаксис Automation:

BOOL GetWorkAreaRect( long * Left, long * Top, long * Right, long * Bottom );

Синтаксис COM:

HRESULT GetWorkAreaRect( long * Left, long * Top, long * Right, long * Bottom, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Выходные параметры:

Left, Top, Right, Bottom | \- Экранные координаты габаритов окна.  
---|---  
  
Версия: Компас v20

Подразделы:

(отсутствуют)
