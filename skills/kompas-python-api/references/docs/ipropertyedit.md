# Интерфейс IPropertyEdit

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl ](ipropertycontrol.html) > [IPropertyControl - свойства ](ipropertycontrol_props.html) |  Scroll [ [ [ ](ipropertyedit_props.html "К следующему разделу")](ipropertycontrol_props.html "На уровень выше")](ipropertytwinswitcher_label2.html "К предыдущему разделу")  
---|---  
  
Интерфейс элемента управления Панели свойств типа Поле ввода.

![IPropertyEdit](./images/ipropertyedit.jpg)  
---  
  
Элемент панели свойств

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[IPropertyControl](ipropertycontrol.html)

[IPropertyEdit](ipropertyedit.html)

Примечание:

1\. Данный интерфейс позволяет получить и установить параметры поля ввода.

2\. Данный интерфейс может быть получен от интерфейса коллекции элементов управления [IPropertyControls](ipropertycontrols.html) с помощью свойства [IPropertyControls::Item](ipropertycontrols_item.html) или метода [IPropertyControls::Add](ipropertycontrols_add.html) с последующим приведением интерфейса [IPropertyControl](ipropertycontrol.html) к данному интерфейсу с помощью метода [IUnknown::QueryInterface](recomendation.html).

Подразделы:

[IPropertyEdit - свойства ](ipropertyedit_props.html)

[IPropertyEdit - методы ](ipropertyedit_methods.html)
