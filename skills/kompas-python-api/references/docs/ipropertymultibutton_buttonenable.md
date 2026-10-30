# ButtonEnable - Доступность кнопки

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl ](ipropertycontrol.html) > [IPropertyControl - свойства ](ipropertycontrol_props.html) > [Интерфейс IPropertyMultiButton ](ipropertymultibutton.html) > [IPropertyMultiButton - свойства ](ipropertymultibutton_props.html) |  Scroll [ [ [ ](ipropertymultibutton_buttonhint.html "К следующему разделу")](ipropertymultibutton_props.html "На уровень выше")](ipropertymultibutton_buttonchecked.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertymultibutton.html)

Тип данных: BOOL.

Синтаксис Automation:

ButtonEnable = iObject.ButtonEnable (btnID) | Получить свойство ([* ](1.html))  
---|---  
iObject.ButtonEnable (btnID) = ButtonEnable | Установить свойство ([* ](1.html))  
ButtonEnable = iObject.GetButtonEnable (btnID) | Получить свойство([**](2.html))  
iObject.SetButtonEnable (btnID, ButtonEnable) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_ButtonEnable (btnID, &ButtonEnable) | Получить свойство  
---|---  
iObject->put_ButtonEnable (btnID, ButtonEnable) | Установить свойство  
  
Входные параметры:

btnID | \- идентификатор кнопки.  
---|---  
  
Значение свойства:

TRUE | \- кнопка доступна,  
---|---  
FALSE | \- кнопка недоступна.  
  
Примечание:

Данное свойство позволяет установить или получить доступ к кнопке.

Подразделы:

(отсутствуют)
