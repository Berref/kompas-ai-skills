# Интерфейс IPropertyTree

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) |  Scroll [ [ [ ](ipropertytree_propers.html "К следующему разделу")](ap2037561.html "На уровень выше")](ipropertyparamgrid_updateparam.html "К предыдущему разделу")  
---|---  
  
Интерфейс элемента панели свойств - Дерево.

Иерархия:

IDispatch

[IKompasAPIObject](ikompasapiobject.html)

[IPropertyControl](ipropertycontrol.html)

[IPropertyTree](ipropertytree.html)

Примечания:

Данный интерфейс можно получить через коллекцию элементов управления Панели свойств [IPropertyControls](ipropertycontrols.html). 

Для IPropertyTree можно создавать панели команд.

Для создания команд в IPropertyTree добавлена поддержка интерфейса [IPropertyToolBar](ipropertytoolbar.html).

Этот дополнительный интерфейс вида можно получить у интерфейса IPropertyTree посредством вызова метода [IUnknown::QueryInterface(const GUID far& iid, void** pif)](recomendation.html).

Версия Компас v23

Подразделы:

[IPropertyTree - свойства](ipropertytree_propers.html)

[IPropertyTree - методы](ipropertytree_metods.html)
