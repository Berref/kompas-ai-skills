# Интерфейс IPropertyTwinSwitcher

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl ](ipropertycontrol.html) > [IPropertyControl - свойства ](ipropertycontrol_props.html) |  Scroll [ [ [ ](ipropertytwinswitcher_propers.html "К следующему разделу")](ipropertycontrol_props.html "На уровень выше")](ipropertylinkbutton_addbutton.html "К предыдущему разделу")  
---|---  
  
Интерфейс элемента Панели свойств - переключателя.

Иерархия:

IDispatch

[IKompasAPIObject](ikompasapiobject.html)

[IPropertyControl](ipropertycontrol.html)

[IPropertyTwinSwitcher](ipropertytwinswitcher.html)

Примечание:

1\. Интерфейс позволяет добавить элемент панели свойств - переключатель.

Для обозначения состояния контрола имеются две текстовых метки.

Первая метка задается свойством [IPropertyControl::Name](ipropertycontrol_name.html).

Вторая метка задается свойством [IPropertyTwinSwitcher::Label2](ipropertytwinswitcher_label2.html).

2\. Данный интерфейс может быть получен от интерфейса коллекции элементов управления [IPropertyControls](ipropertycontrols.html) с помощью свойства [IPropertyControls::Item](ipropertycontrols_item.html) или метода [IPropertyControls::Add](ipropertycontrols_add.html) с последующим приведением интерфейса [IPropertyControl](ipropertycontrol.html) к данному интерфейсу с помощью метода [IUnknown::QueryInterface](recomendation.html).

Подразделы:

[IPropertyTwinSwitcher - cвойства ](ipropertytwinswitcher_propers.html)
