# Интерфейс IPropertyAggregateControl

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyToolBar ](ipropertytoolbar.html) |  Scroll [ [ [ ](ipropertyaggregatecontrol_propers.html "К следующему разделу")](ipropertytoolbar.html "На уровень выше")](ipropertytoolbar_addbutton.html "К предыдущему разделу")  
---|---  
  
Интерфейс составного контрола.

Иерархия:

IDispatch

[IKompasAPIObject](ikompasapiobject.html)

[IPropertyControl](ipropertycontrol.html)

[IPropertyAggregateControl](ipropertyaggregatecontrol.html)

Примечания:

1\. Интерфейс позволяет добавить элемент Панели свойств - составной контрол.

2\. Данный интерфейс может быть получен от интерфейса коллекции элементов управления [IPropertyControls](ipropertycontrols.html) с помощью свойства [IPropertyControls::Item](ipropertycontrols_item.html) или метода [IPropertyControls::Add](ipropertycontrols_add.html) с последующим приведением интерфейса [IPropertyControl](ipropertycontrol.html) к данному интерфейсу с помощью метода [IUnknown::QueryInterface](recomendation.html).

Подразделы:

[IPropertyAggregateControl - свойства ](ipropertyaggregatecontrol_propers.html)

[IPropertyAggregateControl - методы ](ipropertyaggregatecontrol_methods.html)
