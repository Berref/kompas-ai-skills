# NextCommand - Переключать кнопки по VK_TAB

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl ](ipropertycontrol.html) > [IPropertyControl - свойства ](ipropertycontrol_props.html) > [Интерфейс IPropertyMultiButton ](ipropertymultibutton.html) > [IPropertyMultiButton - методы ](ipropertymultibutton_methods.html) |  Scroll [ [ [ ](ipropertyopticalprops.html "К следующему разделу")](ipropertymultibutton_methods.html "На уровень выше")](ipropertymultibutton_addbutton.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipropertymultibutton.html)

Тип данных: BOOL.

Синтаксис Automation:

nextCommand = iKompasObject.NextCommand | Получить свойство ([* ](1.html))  
---|---  
iKompasObject.NextCommand = nextCommand | Установить свойство ([* ](1.html))  
nextCommand = iKompasObject.GetNextCommand() | Получить свойство([**](2.html))  
iKompasObject.SetNextCommand( nextCommand ) | Установить свойство ([**](2.html))  
  
Примечание:

1\. Доступно только для кнопок типа и ksRadioButton из перечисления [ButtonTypeEnum](buttontypeenum.html).

2\. Позволяет получить и установить свойство переключения кнопок комбинацией CTLRTAB.

Подразделы:

(отсутствуют)
