# GetItems - Получить массив всех элементов библиотек и признаков использования

[API интерфейсов. Версия 7](applicate.html) > [Работа с настройками ](adjstment.html) > [Интерфейс ILibItemSettings ](ilibitemsettings.html) > [ILibItemSettings - методы ](ilibitemsettings_methods.html) |  Scroll [ [ [ ](ilibitemsettings_getitemsex.html "К следующему разделу")](ilibitemsettings_methods.html "На уровень выше")](ilibitemsettings_getitem.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilibitemsettings.html)

Синтаксис Automation:

BOOL GetItems( VARIANT * uniqIds, VARIANT * uses );

Синтаксис COM:

HRESULT GetItems( VARIANT * UniqIds, VARIANT * Uses, BOOL * Result );

Входные параметры:

UniqIds | \- массив уникальных номеров библиотек VT_ARRAY|VT_R8,  
---|---  
uses | \- массив признаков использования VT_ARRAY|VT_BOOL.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
