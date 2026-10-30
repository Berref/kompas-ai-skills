# DefaultButtonName - Имя кнопки

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl ](ipropertycontrol.html) > [IPropertyControl - свойства ](ipropertycontrol_props.html) > [Интерфейс IPropertyColor ](ipropertycolor.html) > [IPropertyColor - свойства ](ipropertycolor_props.html) |  Scroll [ [ [ ](ipropertycolor_defaultcolor.html "К следующему разделу")](ipropertycolor_props.html "На уровень выше")](ipropertycolor_enabledefaultbutton.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertycolor.html)

Тип данных: long.

Синтаксис Automation:

DefaultButtonName = iObject.DefaultButtonName | Получить свойство ([* ](1.html))  
---|---  
iObject.DefaultButtonName = DefaultButtonName | Установить свойство ([* ](1.html))  
iObject.GetDefaultButtonName() | Получить свойство([**](2.html))  
iObject.SetDefaultButtonName (DefaultButtonName) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_DefaultButtonName (&DefaultButtonName) | Получить свойство  
---|---  
iObject->put_DefaultButtonName (DefaultButtonName) | Установить свойство  
  
Примечание:

1\. Свойство позволяет получить имя кнопки Цвет по умолчанию или изменить имя на произвольное.

2\. Свойство доступно только если свойство [EnableDefaultButton](ipropertycolor_enabledefaultbutton.html) имеет значение TRUE.

Подразделы:

(отсутствуют)
