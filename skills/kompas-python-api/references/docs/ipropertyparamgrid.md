# Интерфейс IPropertyParamGrid

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) |  Scroll [ [ [ ](ipropertyparamgrid_propers.html "К следующему разделу")](ap2037561.html "На уровень выше")](ipropertytabs_delete.html "К предыдущему разделу")  
---|---  
  
Интерфейс элемента панели свойств - Сетка c разнотипными ячейками.

Иерархия:

IDispatch

[IKompasAPIObject](ikompasapiobject.html)

[IPropertyControl](ipropertycontrol.html)

[IPropertyParamGrid](ipropertyparamgrid.html)

Примечания:

Данный интерфейс можно получить через коллекцию элементов управления Панели свойств [IPropertyControls](ipropertycontrols.html). 

Для IPropertyParamGrid можно создавать панели команд.

Для создания команд в IPropertyParamGrid добавлена поддержка интерфейса [IPropertyToolBar](ipropertytoolbar.html).

Этот дополнительный интерфейс вида можно получить у интерфейса IPropertyParamGrid посредством вызова метода [IUnknown::QueryInterface(const GUID far& iid, void** pif)](recomendation.html).

Версия Компас v23

Подразделы:

[IPropertyParamGrid - свойства](ipropertyparamgrid_propers.html)

[IPropertyParamGrid - методы](ipropertyparamgrid_methods.html)
