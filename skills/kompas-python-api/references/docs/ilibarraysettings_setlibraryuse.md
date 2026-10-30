# SetLibraryUse - Установить флаг использования по индексу

[API интерфейсов. Версия 7](applicate.html) > [Работа с настройками ](adjstment.html) > [Интерфейс ILibArraySettings ](ilibarraysettings.html) > [ILibArraySettings - методы ](ilibarraysettings_methods.html) |  Scroll [ [ [ ](isystemsettings.html "К следующему разделу")](ilibarraysettings_methods.html "На уровень выше")](ilibarraysettings_removelibrary.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilibarraysettings.html)

Синтаксис Automation:

BOOL SetLibraryUse( VARIANT index, BOOL use );

Синтаксис COM:

HRESULT SetLibraryUse( VARIANT Index, BOOL Use, BOOL * Result );

Входные параметры:

Index | \- Полный путь к библиотеке на диске VT_BSTR, либо индекс в массиве VT_I4,  
---|---  
use | \- признак использования.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
