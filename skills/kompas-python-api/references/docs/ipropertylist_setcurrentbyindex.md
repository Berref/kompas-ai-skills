# SetCurrentByIndex - Установить текущую строку по индексу

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl ](ipropertycontrol.html) > [IPropertyControl - свойства ](ipropertycontrol_props.html) > [Интерфейс IPropertyList ](ipropertylist.html) > [IPropertyList - методы ](ipropertylist_methods.html) |  Scroll [ [ [ ](ipropertylist_setvaluerange.html "К следующему разделу")](ipropertylist_methods.html "На уровень выше")](ipropertylist_find.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertylist.html)

Синтаксис Automation:

BOOL SetCurrentByIndex( long index );

Синтаксис COM:

HRESULT SetCurrentByIndex([in] long Index, [out, retval] VARIANT_BOOL * PVal);

Входные параметры:

index | \- номер строки в раскрывающемся списке.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод работает только на несортированном списке, см. [IPropertyList::Sort](ipropertylist_sort.html).

Подразделы:

(отсутствуют)
