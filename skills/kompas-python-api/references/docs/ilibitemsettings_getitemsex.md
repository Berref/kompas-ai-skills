# GetItemsEx - Получить массив всех элементов библиотек и признаков использования

[API интерфейсов. Версия 7](applicate.html) > [Работа с настройками ](adjstment.html) > [Интерфейс ILibItemSettings ](ilibitemsettings.html) > [ILibItemSettings - методы ](ilibitemsettings_methods.html) |  Scroll [ [ [ ](ilibitemsettings_setitem.html "К следующему разделу")](ilibitemsettings_methods.html "На уровень выше")](ilibitemsettings_getitems.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilibitemsettings.html)

Синтаксис Automation:

BOOL GetItemsEx( VARIANT * UniqIds, VARIANT * Uses, VARIANT * ItemNames, VARIANT * FileNames );

Синтаксис COM:

HRESULT GetItemsEx( VARIANT * UniqIds, VARIANT * Uses, VARIANT * ItemNames, VARIANT * FileNames, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Выходные параметры:

UniqIds | \- массив уникальных номеров библиотек VT_ARRAY|VT_R8,  
---|---  
Uses | \- массив признаков использования VT_ARRAY|VT_BOOL,  
ItemNames | \- массив имен элементов VT_ARRAY|VT_BSTR,  
FileNames | \- массив имен файлов библиотек VT_ARRAY|VT_BSTR.  
  
Подразделы:

(отсутствуют)
