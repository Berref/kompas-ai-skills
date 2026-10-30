# Интерфейс IPropertyMultiButton

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl ](ipropertycontrol.html) > [IPropertyControl - свойства ](ipropertycontrol_props.html) |  Scroll [ [ [ ](ipropertymultibutton_props.html "К следующему разделу")](ipropertycontrol_props.html "На уровень выше")](ipropertylist_setvaluerange.html "К предыдущему разделу")  
---|---  
  
Интерфейс элемента управления Панели свойств Набор кнопок.

![IPropertyMultiButton](./images/ipropertymultibutton.jpg)  
---  
  
Элемент панели свойств

[IKompasAPIObject](ikompasapiobject.html)

[IPropertyControl](ipropertycontrol.html)

[IPropertyMultiButton](ipropertymultibutton.html)

Примечание:

1\. Элемент управления состоит из набора кнопок определенного типа из перечисления [ButtonTypeEnum](buttontypeenum.html).

2\. Данный интерфейс можно получить через интерфейс коллекции элементов управления панели свойств [IPropertyControls](ipropertycontrols.html).

3\. При нажатии на одну из кнопок набора вызывается событие [ksPropertyManagerNotify::ControlCommand](kspropertymanagernotify_controlcommand.html).

4\. Для корректного отображения строки подсказки конкретной кнопки, задаваемой при помощи свойств [ButtonHint](ipropertymultibutton_buttonhint.html) или [ButtonTips](ipropertymultibutton_buttontips.html), необходимо задать строку подсказки для набора кнопок. Если текст подсказки набора не нужен или не имеет значения, эта строка может состоять, например, из одного пробела.

Подразделы:

[IPropertyMultiButton - свойства ](ipropertymultibutton_props.html)

[IPropertyMultiButton - методы ](ipropertymultibutton_methods.html)
