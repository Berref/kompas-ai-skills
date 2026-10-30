# ItemValue - Значение элемента списка по индексу

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl ](ipropertycontrol.html) > [IPropertyControl - свойства ](ipropertycontrol_props.html) > [Интерфейс IPropertyEditList ](ipropertyeditlist.html) > [IPropertyEditList - свойства ](ipropertyeditlist_props.html) |  Scroll [ [ [ ](ipropertyeditlist_listtype.html "К следующему разделу")](ipropertyeditlist_props.html "На уровень выше")](ipropertyeditlist_itemselected.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertyeditlist.html)

Синтаксис Automation:

Тип данных: LPSTR.

ItemValue = iObject.ItemValue( Index ) | Получить свойство ([* ](1.html))  
---|---  
iObject.ItemValue( Index ) = ItemValue | Установить свойство ([* ](1.html))  
ItemValue = iObject.GetItemValue( Index ) | Получить свойство([**](2.html))  
iObject.SetItemValue( Index ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Тип данных:BSTR.

iObject->get_Name ( Index ) | Получить свойство  
---|---  
iObject->put_Name ( Index ) | Установить свойство  
  
Входные параметры:

Index | \- индекс элемента.  
---|---  
  
Подразделы:

(отсутствуют)
