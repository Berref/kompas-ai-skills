# FixHeight - Зафиксировать высоту элемента управления

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl ](ipropertycontrol.html) > [IPropertyControl - свойства ](ipropertycontrol_props.html) > [Интерфейс IPropertyUserControl ](ipropertyusercontrol.html) > [IPropertyUserControl - свойства ](ipropertyusercontrol_props.html) |  Scroll [ [ [ ](ipropertyusercontrol_fixwidth.html "К следующему разделу")](ipropertyusercontrol_props.html "На уровень выше")](ipropertyusercontrol_autosize.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertyusercontrol.html)

Тип данных: BOOL

Синтаксис Automation:

FixHeight = iObject.FixHeight | Получить свойство ([* ](1.html))  
---|---  
iObject.FixHeight = FixHeight | Установить свойство ([* ](1.html))  
FixHeight = iObject.GetFixHeight() | Получить свойство([**](2.html))  
iObject.SetFixHeight(FixHeight) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_FixHeight(&FixHeight) | Получить свойство  
---|---  
iObject->put_FixHeight(FixHeight) | Установить свойство  
  
Значение свойства:

TRUE - размер элемента управления по высоте зафиксирован и равен значению, установленному в свойстве [Height](ipropertyusercontrol_height.html) \- Высота элемента управления.

Примечание:

По умолчанию свойство имеет значение FALSE - размер элемента управления по высоте не зафиксирован.

Подразделы:

(отсутствуют)
