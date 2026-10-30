# Find - Найти индекс строки в списке по значению

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl ](ipropertycontrol.html) > [IPropertyControl - свойства ](ipropertycontrol_props.html) > [Интерфейс IPropertyList ](ipropertylist.html) > [IPropertyList - методы ](ipropertylist_methods.html) |  Scroll [ [ [ ](ipropertylist_setcurrentbyindex.html "К следующему разделу")](ipropertylist_methods.html "На уровень выше")](ipropertylist_clearlist.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertylist.html)

Синтаксис Automation:

long Find (const VARIANT FAR& val);

Синтаксис COM:

HRESULT Find([in] VARIANT Val, [out, retval] long * PVal);

Входные параметры:

val | \- значение в раскрывающемся списке.  
---|---  
  
Возвращаемое значение:

Индекс строки со значением val в списке | \- в случае успеха,  
---|---  
-1 | \- в случае неудачи.  
  
Примечание:

Метод работает только на несортированном списке, см. [IPropertyList::Sort](ipropertylist_sort.html).

Подразделы:

(отсутствуют)
