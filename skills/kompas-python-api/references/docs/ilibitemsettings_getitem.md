# GetItem - Получить элемент библиотеки и признак использования по индексу

[API интерфейсов. Версия 7](applicate.html) > [Работа с настройками ](adjstment.html) > [Интерфейс ILibItemSettings ](ilibitemsettings.html) > [ILibItemSettings - методы ](ilibitemsettings_methods.html) |  Scroll [ [ [ ](ilibitemsettings_getitems.html "К следующему разделу")](ilibitemsettings_methods.html "На уровень выше")](ilibitemsettings_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilibitemsettings.html)

Синтаксис Automation:

double GetItem( VARIANT index, BOOL * use );

Синтаксис COM:

HRESULT GetItem( VARIANT Index, BOOL * Use, double * Result );

Входные параметры:

Index | \- индекс в массиве VT_I4, либо уникальный номер элемента VT_R8,  
---|---  
use | \- признак использования.  
  
Возвращаемое значение:

Уникальный номер элемента | \- в случае успешного завершения,  
---|---  
-1 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
