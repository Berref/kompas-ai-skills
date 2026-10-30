# Интерфейс IPropertyControl

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) |  Scroll [ [ [ ](ipropertycontrol_props.html "К следующему разделу")](ap2037561.html "На уровень выше")](ap2037561.html "К предыдущему разделу")  
---|---  
  
Базовый интерфейс элемента управления Панели свойств.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[IPropertyControl](ipropertycontrol.html)

[IPropertyControl1](ipropertycontrol1.html)

Описание:

При изменении библиотечных элементов управления система передает управление библиотеке посредством вызовов соответствующих событий. Данный интерфейс является базовым для всех элементов управления Панели свойств. Все элементы управления из [СontrolTypeEnum](controltypeenum.html) являются наследниками от IPropertyControl.

Примечание:

1\. Имя выводится рядом с элементом управления (в зависимости от настроек Панели свойств). Если имя не задано или задана пустая строка, имя выводиться не будет.

2\. Подсказки для элемента управления устанавливаются функциями [Hint](ipropertycontrol_hint.html) и [Tips](ipropertycontrol_tips.html).

3\. Идентификатор элемента управления, установленный методом [Id](ipropertycontrol_id.html), будет приходить в событиях от данного элемента управления, как параметр.

4\. Данный интерфейс может быть получен от интерфейса коллекции элементов управления [IPropertyControls](ipropertycontrols.html) с помощью свойства [IPropertyControls::Item](ipropertycontrols_item.html) или метода [IPropertyControls::Add](ipropertycontrols_add.html).

5\. Посредством вызова метода [IUnknown::QueryInterface (const GUID far& iid, void** pif)](recomendation.html) интерфейс позволяет получить дополнительный интерфейс [IPropertyControl1](ipropertycontrol1.html).

Подразделы:

[IPropertyControl - свойства ](ipropertycontrol_props.html)
