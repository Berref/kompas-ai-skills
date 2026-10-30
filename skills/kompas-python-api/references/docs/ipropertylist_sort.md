# Sort - Сортировать список

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl ](ipropertycontrol.html) > [IPropertyControl - свойства ](ipropertycontrol_props.html) > [Интерфейс IPropertyList ](ipropertylist.html) > [IPropertyList - свойства ](ipropertylist_props.html) |  Scroll [ [ [ ](ipropertylist_width.html "К следующему разделу")](ipropertylist_props.html "На уровень выше")](ipropertylist_readonly.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertylist.html)

Тип данных BOOL.

Синтаксис Automation:

Sort = iObject.Sort | Получить свойство ([* ](1.html))  
---|---  
iObject.Sort = Sort | Установить свойство ([* ](1.html))  
Sort = iObject.GetSort() | Получить свойство([**](2.html))  
iObject.SetSort (Sort) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_Sort (&Sort) | Получить свойство  
---|---  
iObject->put_Sort (Sort) | Установить свойство  
  
Значение свойства:

TRUE | \- значения в списке будут сортироваться при добавлении новых,  
---|---  
FALSE | \- значения в списке будут в той последовательности, в какой они были добавлены.  
  
Подразделы:

(отсутствуют)
