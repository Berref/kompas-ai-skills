# DefaultColor - Цвет по умолчанию

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl ](ipropertycontrol.html) > [IPropertyControl - свойства ](ipropertycontrol_props.html) > [Интерфейс IPropertyColor ](ipropertycolor.html) > [IPropertyColor - свойства ](ipropertycolor_props.html) |  Scroll [ [ [ ](ipropertycolor_width.html "К следующему разделу")](ipropertycolor_props.html "На уровень выше")](ipropertycolor_defaultbuttonname.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertycolor.html)

Тип данных: long.

Синтаксис Automation:

DefaultColor = iObject.DefaultColor | Получить свойство ([* ](1.html))  
---|---  
iObject.DefaultColor = DefaultColor | Установить свойство ([* ](1.html))  
DefaultColor = iObject.GetDefaultColor() | Получить свойство([**](2.html))  
iObject.SetDefaultColor (DefaultColor) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_DefaultColor (&DefaultColor) | Получить свойство  
---|---  
iObject->put_DefaultColor (DefaultColor) | Установить свойство  
  
Примечание:

1\. Свойство позволяет получить или изменить значение цвета для кнопки Цвет по умолчанию.

2\. Цвет по умолчанию доступен только если свойство [EnableDefaultButton](ipropertycolor_enabledefaultbutton.html) имеет значение TRUE.

Подразделы:

(отсутствуют)
