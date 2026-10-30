# WithCheck - Наличие опции рядом с полем ввода

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl ](ipropertycontrol.html) > [IPropertyControl - свойства ](ipropertycontrol_props.html) > [Интерфейс IPropertyList ](ipropertylist.html) > [IPropertyList - свойства ](ipropertylist_props.html) |  Scroll [ [ [ ](ipropertylist_methods.html "К следующему разделу")](ipropertylist_props.html "На уровень выше")](ipropertylist_width.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertylist.html)

Тип данных: BOOL.

Синтаксис Automation:

WithCheck = iObject.WithCheck | Получить свойство ([* ](1.html))  
---|---  
iObject.WithCheck = WithCheck | Установить свойство ([* ](1.html))  
WithCheck = iObject.GetWithCheck() | Получить свойство([**](2.html))  
iObject.SetWithCheck (WithCheck) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_WithCheck (&WithCheck) | Получить свойство  
---|---  
iObject->put_WithCheck (WithCheck) | Установить свойство  
  
Значение свойства:

TRUE | \- рядом с элементом управления выводится опция,  
---|---  
FALSE | \- рядом с элементом управления не выводится опция.  
  
Примечание:

На текущий момент свойство не реализовано, его значение можно установить только равным FALSE.

Подразделы:

(отсутствуют)
