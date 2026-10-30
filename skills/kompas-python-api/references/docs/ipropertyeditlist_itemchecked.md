# ItemChecked - Состояние элемента списка

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl ](ipropertycontrol.html) > [IPropertyControl - свойства ](ipropertycontrol_props.html) > [Интерфейс IPropertyEditList ](ipropertyeditlist.html) > [IPropertyEditList - свойства ](ipropertyeditlist_props.html) |  Scroll [ [ [ ](ipropertyeditlist_itemscount.html "К следующему разделу")](ipropertyeditlist_props.html "На уровень выше")](ipropertyeditlist_itemmissing.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertyeditlist.html)

Тип данных: BOOL.

Синтаксис Automation:

BOOL ItemChecked = iObject.ItemChecked(index) | Получить свойство ([* ](1.html))  
---|---  
iObject.ItemChecked(index) = ItemChecked | Установить свойство ([* ](1.html))  
BOOL ItemChecked = iObject.GetItemChecked(index) | Получить свойство([**](2.html))  
iObject.SetItemChecked( index, ItemChecked ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_ItemChecked( index, &ItemChecked ) | Получить свойство  
---|---  
iObject->put_ItemChecked( index, ItemChecked ) | Установить свойство  
  
Входные параметры:

index | \- индекс элемента списка.  
---|---  
  
Подразделы:

(отсутствуют)
