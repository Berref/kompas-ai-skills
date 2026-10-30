# Интерфейс IPropertySlideBox

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl ](ipropertycontrol.html) > [IPropertyControl - свойства ](ipropertycontrol_props.html) |  Scroll [ [ [ ](ipropertyslidebox_props.html "К следующему разделу")](ipropertycontrol_props.html "На уровень выше")](ipropertyseparator_setimage.html "К предыдущему разделу")  
---|---  
  
Интерфейс элемента управления Панели свойств типа Окно отображения слайда, растрового изображения, файла документа КОМПАС или группы файлов.

![IPropertySlideBox](./images/ipropertyslidebox.jpg)  
---  
  
Элемент панели свойств

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[IPropertyControl](ipropertycontrol.html)

[IPropertySlideBox](ipropertyslidebox.html)

Примечание:

1\. Данный интерфейс можно получить через коллекцию элементов управления Панели свойств [IPropertyControls](ipropertycontrols.html).

2\. После создания элемента управления и вывода его на экран все изменения, вносимые с помощью свойств и методов данного интерфейса, вступят в силу только после вызова метода [UpdateParam](ipropertyslidebox_updateparam.html).

3\. Для обновления изображения в окне, например после изменения геометрии в отображаемом документе, можно использовать метод UpdateParam.

Подразделы:

[IPropertySlideBox - свойства ](ipropertyslidebox_props.html)

[IPropertySlideBox - методы ](ipropertyslidebox_methods.html)
