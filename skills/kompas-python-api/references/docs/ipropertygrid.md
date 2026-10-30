# Интерфейс IPropertyGrid

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl ](ipropertycontrol.html) > [IPropertyControl - свойства ](ipropertycontrol_props.html) |  Scroll [ [ [ ](ipropertygrid_props.html "К следующему разделу")](ipropertycontrol_props.html "На уровень выше")](ipropertyfilename_width.html "К предыдущему разделу")  
---|---  
  
Интерфейс элемента управления Панели свойств типа Сетка.

![IPropertyGrid](./images/ipropertygrid.jpg)  
---  
  
Элемент панели свойств

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[IPropertyControl](ipropertycontrol.html)

[IPropertyGrid](ipropertygrid.html)

[IPropertyToolBar](ipropertytoolbar.html)

Примечание:

1\. Данный интерфейс можно получить через коллекцию элементов управления Панели свойств [IPropertyControls](ipropertycontrols.html).

2\. После создания элемента управления и вывода его на экран все изменения вносимые с помощью свойств и методов данного интерфейса вступят в силу только после вызова метода [UpdateParam](ipropertygrid_updateparam.html).

3\. Для IPropertyGrid можно создавать панели команд. Для создания команд в IPropertyGrid добавлена поддержка интерфейса [IPropertyToolBar](ipropertytoolbar.html). Этот дополнительный интерфейс вида можно получить у интерфейса IPropertyGrid посредством вызова метода [IUnknown::QueryInterface (const GUID far& iid, void** pif)](recomendation.html).

4\. Для IPropertyGrid поддерживаются события менеджера панели свойств [ChangeControlValue](kspropertymanagernotify_changecontrolvalue.html), [ControlCommand](kspropertymanagernotify_controlcommand.html), [SelectItem](kspropertymanagernotify_selectitem.html).

Подразделы:

[IPropertyGrid - свойства ](ipropertygrid_props.html)

[IPropertyGrid - методы ](ipropertygrid_methods.html)
