# Интерфейс IPropertyEditList

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl ](ipropertycontrol.html) > [IPropertyControl - свойства ](ipropertycontrol_props.html) |  Scroll [ [ [ ](ipropertyeditlist_props.html "К следующему разделу")](ipropertycontrol_props.html "На уровень выше")](ipropertyedit_setvaluerange.html "К предыдущему разделу")  
---|---  
  
Интерфейс элемента управления Панели свойств Список.

![IPropertyEditList](./images/ipropertyeditlist.jpg)  
---  
  
Элемент панели свойств

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[IPropertyControl](ipropertycontrol.html)

[IPropertyEditList](ipropertyeditlist.html)

[IPropertyToolBar](ipropertytoolbar.html)

Описание:

Позволяет управлять списком из Панели свойств.

Примечание:

1\. Данный интерфейс может быть получен от интерфейса коллекции элементов управления [IPropertyControls](ipropertycontrols.html) с помощью свойства [IPropertyControls::Item](ipropertycontrols_item.html) или метода [IPropertyControls::Add](ipropertycontrols_add.html) с последующим приведением интерфейса [IPropertyControl](ipropertycontrol.html) к данному интерфейсу с помощью метода [IUnknown::QueryInterface](recomendation.html).

2\. Посредством вызова метода [IUnknown::QueryInterface (const GUID far& iid, void** pif) ](recomendation.html)у данного интерфейса можно получить дополнительный интерфейс вида [IPropertyToolBar](ipropertytoolbar.html).

Подразделы:

[IPropertyEditList - свойства ](ipropertyeditlist_props.html)

[IPropertyEditList - методы ](ipropertyeditlist_methods.html)
