# Интерфейс IPropertyGroupBegin

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl ](ipropertycontrol.html) > [IPropertyControl - свойства ](ipropertycontrol_props.html) |  Scroll [ [ [ ](ipropertygroupbegin_propers.html "К следующему разделу")](ipropertycontrol_props.html "На уровень выше")](ipropertycolor_width.html "К предыдущему разделу")  
---|---  
  
Элемент Панели свойств - Начало группы контролов.

Иерархия:

IDispatch

[IKompasAPIObject](ikompasapiobject.html)

[IPropertyControl](ipropertycontrol.html)

[IPropertyGroupBegin](ipropertygroupbegin.html)

Примечание:

1\. Данный интерфейс позволяет объединить несколько контролов Панели свойств в группу. Контролы, добавленные после IPropertyGroupBegin, будут объединены в группу.

2\. Для завершения группы нужно добавить контрол [IPropertyGroupEnd.](ipropertygroupend.html)

3\. Группа иметь возможность сворачивать и прятать контролы, входящие в нее, если у группы признак [IPropertyGroupBegin::Expanding](ipropertygroupbegin_expanding.html) выставлен равным true.

4\. Данный интерфейс может быть получен от интерфейса коллекции элементов управления [IPropertyControls](ipropertycontrols.html) с помощью свойства [IPropertyControls::Item](ipropertycontrols_item.html) или метода [IPropertyControls::Add](ipropertycontrols_add.html) с последующим приведением интерфейса [IPropertyControl](ipropertycontrol.html) к данному интерфейсу с помощью метода [IUnknown::QueryInterface](recomendation.html).

Подразделы:

[IPropertyGroupBegin - свойства ](ipropertygroupbegin_propers.html)
