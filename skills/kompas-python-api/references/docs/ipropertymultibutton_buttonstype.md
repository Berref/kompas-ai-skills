# ButtonsType - Тип кнопок

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl ](ipropertycontrol.html) > [IPropertyControl - свойства ](ipropertycontrol_props.html) > [Интерфейс IPropertyMultiButton ](ipropertymultibutton.html) > [IPropertyMultiButton - свойства ](ipropertymultibutton_props.html) |  Scroll [ [ [ ](ipropertymultibutton_buttonvisible.html "К следующему разделу")](ipropertymultibutton_props.html "На уровень выше")](ipropertymultibutton_buttontips.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertymultibutton.html)

Тип данных: тип кнопок из перечисления [ButtonTypeEnum](buttontypeenum.html).

Синтаксис Automation:

ButtonsType = iObject.ButtonsType | Получить свойство ([* ](1.html))  
---|---  
iObject.ButtonsType = ButtonsType | Установить свойство ([* ](1.html))  
ButtonsType = iObject.GetButtonsType() | Получить свойство([**](2.html))  
iObject.SetButtonsType (ButtonsType) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_ButtonsType (&ButtonsType) | Получить свойство  
---|---  
iObject->put_ButtonsType (ButtonsType) | Установить свойство  
  
Примечание:

Изменить тип кнопок можно только до создания элемента управления, то есть до запуска процесса у процессных параметров или до вызова метода [IPropertyManager::ShowTabs](ipropertymanager_showtabs.html).

Подразделы:

(отсутствуют)
