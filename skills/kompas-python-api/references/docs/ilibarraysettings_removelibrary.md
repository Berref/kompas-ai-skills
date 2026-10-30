# RemoveLibrary - Удалить библиотеку и признак использования

[API интерфейсов. Версия 7](applicate.html) > [Работа с настройками ](adjstment.html) > [Интерфейс ILibArraySettings ](ilibarraysettings.html) > [ILibArraySettings - методы ](ilibarraysettings_methods.html) |  Scroll [ [ [ ](ilibarraysettings_setlibraryuse.html "К следующему разделу")](ilibarraysettings_methods.html "На уровень выше")](ilibarraysettings_getlibrarys.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilibarraysettings.html)

Синтаксис Automation:

BOOL RemoveLibrary( VARIANT index );

Синтаксис COM:

HRESULT RemoveLibrary( VARIANT Index, BOOL * Result );

Входные параметры:

Index | \- полный путь к библиотеке на диске VT_BSTR, либо индекс в массиве VT_I4.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
