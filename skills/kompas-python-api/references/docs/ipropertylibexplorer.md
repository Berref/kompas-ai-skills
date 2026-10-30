# Интерфейс IPropertyLibExplorer

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl ](ipropertycontrol.html) > [IPropertyControl - свойства ](ipropertycontrol_props.html) |  Scroll [ [ [ ](ipropertylibexplorer_props.html "К следующему разделу")](ipropertycontrol_props.html "На уровень выше")](ipropertygrid_updateparam.html "К предыдущему разделу")  
---|---  
  
Элемент Панели свойств Отображение библиотеки документов.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[IPropertyControl](ipropertycontrol.html)

[IPropertyLibExplorer](ipropertylibexplorer.html)

Примечание:

1\. Интерфейс позволяет просматривать библиотеки фрагментов(*.lfr) и библиотеки моделей (*.l3d). Путь к выбранному элементу можно получить через [IPropertyControl::Value](ipropertycontrol_value.html). Для установки активного элемента также используется IPropertyControl::Value.

2\. Данный интерфейс может быть получен от интерфейса коллекции элементов управления [IPropertyControls](ipropertycontrols.html) с помощью свойства [IPropertyControls::Item](ipropertycontrols_item.html) или метода [IPropertyControls::Add](ipropertycontrols_add.html) с последующим приведением интерфейса [IPropertyControl](ipropertycontrol.html) к данному интерфейсу с помощью метода [IUnknown::QueryInterface](recomendation.html).

Подразделы:

[IPropertyLibExplorer - свойства ](ipropertylibexplorer_props.html)
