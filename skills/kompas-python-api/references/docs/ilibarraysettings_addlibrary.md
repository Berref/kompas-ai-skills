# AddLibrary - Добавить библиотеку и признак использования

[API интерфейсов. Версия 7](applicate.html) > [Работа с настройками ](adjstment.html) > [Интерфейс ILibArraySettings ](ilibarraysettings.html) > [ILibArraySettings - методы ](ilibarraysettings_methods.html) |  Scroll [ [ [ ](ilibarraysettings_getlibrary.html "К следующему разделу")](ilibarraysettings_methods.html "На уровень выше")](ilibarraysettings_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilibarraysettings.html)

Синтаксис Automation:

BOOL AddLibrary( LPCTSTR fileName, BOOL use );

Синтаксис COM:

HRESULT AddLibrary( BSTR FileName, BOOL Use, BOOL* Result );

Входные параметры:

fileName | \- полный путь к библиотеке на диске VT_BSTR,  
---|---  
use | \- признак использования.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
