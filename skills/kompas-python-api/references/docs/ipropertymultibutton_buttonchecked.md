# ButtonChecked - Нажатие кнопки

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl ](ipropertycontrol.html) > [IPropertyControl - свойства ](ipropertycontrol_props.html) > [Интерфейс IPropertyMultiButton ](ipropertymultibutton.html) > [IPropertyMultiButton - свойства ](ipropertymultibutton_props.html) |  Scroll [ [ [ ](ipropertymultibutton_buttonenable.html "К следующему разделу")](ipropertymultibutton_props.html "На уровень выше")](ipropertymultibutton_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertymultibutton.html)

Тип данных: BOOL.

Синтаксис Automation:

ButtonChecked = iObject.ButtonChecked (btnID) | Получить свойство ([* ](1.html))  
---|---  
iObject.ButtonChecked (btnID) = ButtonChecked | Установить свойство ([* ](1.html))  
ButtonChecked = iObject.GetButtonChecked (btnID) | Получить свойство([**](2.html))  
iObject.SetButtonChecked (btnID, ButtonChecked) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_ButtonChecked (btnID, &ButtonChecked) | Получить свойство  
---|---  
iObject->put_ButtonChecked (btnID, ButtonChecked) | Установить свойство  
  
Входные параметры:

btnID | \- идентификатор кнопки.  
---|---  
  
Значение свойства:

TRUE | \- кнопка нажата,  
---|---  
FALSE | \- кнопка не нажата.  
  
Примечание:

Доступно только для кнопок типа ksCheckButton и ksRadioButton из перечисления [ButtonTypeEnum](buttontypeenum.html).

Подразделы:

(отсутствуют)
