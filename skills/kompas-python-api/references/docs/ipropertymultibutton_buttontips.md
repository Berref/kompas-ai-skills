# ButtonTips - Строка подсказки для кнопки

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl ](ipropertycontrol.html) > [IPropertyControl - свойства ](ipropertycontrol_props.html) > [Интерфейс IPropertyMultiButton ](ipropertymultibutton.html) > [IPropertyMultiButton - свойства ](ipropertymultibutton_props.html) |  Scroll [ [ [ ](ipropertymultibutton_buttonstype.html "К следующему разделу")](ipropertymultibutton_props.html "На уровень выше")](ipropertymultibutton_buttoniconfont.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertymultibutton.html)

Тип данных BSTR

Синтаксис Automation:

ButtonTips = iObject.ButtonTips (btnID) | Получить свойство ([* ](1.html))  
---|---  
iObject.ButtonTips (btnID) = ButtonTips | Установить свойство ([* ](1.html))  
ButtonTips = iObject.GetButtonTips (btnID) | Получить свойство([**](2.html))  
iObject.SetButtonTips (btnID, ButtonTips) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_ButtonTips (btnID, &ButtonTips) | Получить свойство  
---|---  
iObject->put_ButtonTips (btnID, ButtonTips) | Установить свойство  
  
Входные параметры:

btnID | \- идентификатор кнопки.  
---|---  
  
Примечание:

1\. Данное свойство позволяет установить или получить строку подсказки для кнопки с идентификатором btnID.

2\. Для корректного отображения строки подсказки конкретной кнопки необходимо задать строку подсказки для набора кнопок. Если текст подсказки набора не нужен или не имеет значения, эта строка может состоять, например, из одного пробела.

Подразделы:

(отсутствуют)
