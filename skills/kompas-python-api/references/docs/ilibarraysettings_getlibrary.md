# GetLibrary - Получить имя библиотеки и признак использования по индексу

[API интерфейсов. Версия 7](applicate.html) > [Работа с настройками ](adjstment.html) > [Интерфейс ILibArraySettings ](ilibarraysettings.html) > [ILibArraySettings - методы ](ilibarraysettings_methods.html) |  Scroll [ [ [ ](ilibarraysettings_getlibrarys.html "К следующему разделу")](ilibarraysettings_methods.html "На уровень выше")](ilibarraysettings_addlibrary.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilibarraysettings.html)

Синтаксис Automation:

BSTR GetLibrary( long index, BOOL * use );

Синтаксис COM:

HRESULT GetLibrary( long Index, BOOL * Use, BSTR * Result );

Входные параметры:

index | \- индекс в массиве,  
---|---  
use | \- признак использования.  
  
Возвращаемое значение:

| \- Полный путь к библиотеке на диске.  
---|---  
  
Подразделы:

(отсутствуют)
