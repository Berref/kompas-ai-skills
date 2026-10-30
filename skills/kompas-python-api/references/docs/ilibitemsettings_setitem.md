# SetItem - Установить признак использования

[API интерфейсов. Версия 7](applicate.html) > [Работа с настройками ](adjstment.html) > [Интерфейс ILibItemSettings ](ilibitemsettings.html) > [ILibItemSettings - методы ](ilibitemsettings_methods.html) |  Scroll [ [ [ ](ilibitemsettings_setitems.html "К следующему разделу")](ilibitemsettings_methods.html "На уровень выше")](ilibitemsettings_getitemsex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilibitemsettings.html)

Синтаксис Automation:

BOOL SetItem( VARIANT index, BOOL use );

Синтаксис COM:

HRESULT SetItem( VARIANT Index, BOOL Use, BOOL * Result );

Входные параметры:

Index | \- индекс в массиве VT_I4, либо уникальный номер элемента VT_R8,  
---|---  
use | \- признак использования.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
