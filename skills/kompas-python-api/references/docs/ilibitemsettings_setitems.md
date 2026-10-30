# SetItems - Установить массив всех элементов библиотек и признаков использования

[API интерфейсов. Версия 7](applicate.html) > [Работа с настройками ](adjstment.html) > [Интерфейс ILibItemSettings ](ilibitemsettings.html) > [ILibItemSettings - методы ](ilibitemsettings_methods.html) |  Scroll [ [ [ ](ikompasdictionary.html "К следующему разделу")](ilibitemsettings_methods.html "На уровень выше")](ilibitemsettings_setitem.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilibitemsettings.html)

Синтаксис Automation:

BOOL SetItem( VARIANT index, BOOL use );

Синтаксис COM:

HRESULT SetItems( VARIANT UniqIds, VARIANT Uses, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

UniqIds | \- список идентификаторов в виде массива VT_ARRAY | VT_R8,  
---|---  
Uses | \- признаки использования свойств в виде массива VT_ARRAY | VT_BOOL.  
  
Версия КОМПАС v22

Подразделы:

(отсутствуют)
