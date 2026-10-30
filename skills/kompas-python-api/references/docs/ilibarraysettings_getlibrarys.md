# GetLibrarys - Получить массив всех библиотек и флагов использования

[API интерфейсов. Версия 7](applicate.html) > [Работа с настройками ](adjstment.html) > [Интерфейс ILibArraySettings ](ilibarraysettings.html) > [ILibArraySettings - методы ](ilibarraysettings_methods.html) |  Scroll [ [ [ ](ilibarraysettings_removelibrary.html "К следующему разделу")](ilibarraysettings_methods.html "На уровень выше")](ilibarraysettings_getlibrary.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilibarraysettings.html)

Синтаксис Automation:

BOOL GetLibrarys( VARIANT * fileNames, VARIANT * uses );

Синтаксис COM:

HRESULT GetLibrarys( VARIANT * FileNames, VARIANT * Uses, BOOL * Result );

Входные параметры:

fileNames | \- массив имён файлов на диске VT_ARRAY|VT_BSTR,  
---|---  
uses | \- массив признаков использования VT_ARRAY|VT_BOOL.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
