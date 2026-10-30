# Интерфейс IPropertyUserControl

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl ](ipropertycontrol.html) > [IPropertyControl - свойства ](ipropertycontrol_props.html) |  Scroll [ [ [ ](ipropertyusercontrol_props.html "К следующему разделу")](ipropertycontrol_props.html "На уровень выше")](ipropertytextbutton.html "К предыдущему разделу")  
---|---  
  
[События...](kspropertyusercontrolnotify.html)

Интерфейс элемента управления Панели свойств Пользовательский элемент управления.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[IPropertyControl](ipropertycontrol.html)

[IPropertyUserControl](ipropertyusercontrol.html)

Данный элемент управления позволяет отображать на Панели свойств нестандартные элементы управления и их наборы. В качестве вложенного нестандартного элемента управления используется элемент управления OCX. Используемый элемент управления OCX должен быть зарегистрирован в реестре Windows.

После создания элемента управления OCX библиотеке посылается событие [ksPropertyUserControlNotify::CreateOCX](kspropertyusercontrolnotify_createocx.html). В этом событии передается Dispatch-интерфейс элемента управления OCX и библиотека может подписаться на события от этого элемента управления.

Перед удалением элемента управления OCX библиотеке посылается событие [ksPropertyUserControlNotify::DestroyOCX](kspropertyusercontrolnotify_destroyocx.html). При обработке этого события библиотека должна отписаться от событий этого элемента управления.

Примечание:

Данный интерфейс можно получить через коллекцию элементов управления Панели свойств [IPropertyControls](ipropertycontrols.html).

Подразделы:

[IPropertyUserControl - свойства ](ipropertyusercontrol_props.html)

[IPropertyUserControl - методы ](ipropertyusercontrol_methods.html)
