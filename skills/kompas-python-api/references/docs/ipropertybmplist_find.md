# Find - Найти индекс в списке по значению

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl ](ipropertycontrol.html) > [IPropertyControl - свойства ](ipropertycontrol_props.html) > [Интерфейс IPropertyBmpList ](ipropertybmplist.html) > [IPropertyBmpList - методы ](ipropertybmplist_methods.html) |  Scroll [ [ [ ](ipropertycheckbox.html "К следующему разделу")](ipropertybmplist_methods.html "На уровень выше")](ipropertybmplist_clearlist.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertybmplist.html)

Синтаксис Automation:

long Find( BSTR val );

Синтаксис COM:

HRESULT Find( BSTR Val, long * PVal );

Входные параметры:

Val | \- значение в раскрывающемся списке.  
---|---  
  
Возвращаемое значение:

Индекс строки со значением Val в списке | \- в случае успеха,  
---|---  
-1 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
