# Интерфейс IPropertyStyleList

[API интерфейсов. Версия 7](applicate.html) > [Приложение](ap1782828.html) > [Работа с Панелью свойств ](ap2037561.html) > [Интерфейс IPropertyControl ](ipropertycontrol.html) > [IPropertyControl - свойства ](ipropertycontrol_props.html) |  Scroll [ [ [ ](ipropertystylelist_props.html "К следующему разделу")](ipropertycontrol_props.html "На уровень выше")](ipropertyspinedit_setvaluerange.html "К предыдущему разделу")  
---|---  
  
Элемент Панели свойств - Комбобокс со стилем.

![IPropertyStyleList](./images/ipropertystylelist.jpg)  
---  
  
Элемент панели свойств

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[IPropertyControl](ipropertycontrol.html)

[IPropertyStyleList](ipropertystylelist.html)

Описание:

Интерфейс списка, из которого можно выбрать текущий стиль линии.

Примечания:

Данный интерфейс может быть получен от интерфейса коллекции элементов управления IPropertyControls с помощью свойства [IPropertyControls::Item](ipropertycontrols_item.html) или метода [IPropertyControls::Add](ipropertycontrols_add.html) с последующим приведением интерфейса [IPropertyContro](ipropertycontrol.html)l к данному интерфейсу с помощью метода [IUnknown::QueryInterface](recomendation.html).

Перечень линий, доступных для выбора, а также порядок следования линий в списке определяется настройкой фильтра линий, сделанной для текущего документа.

Кнопка Другой стиль позволяет выбрать стиль из внешней библиотеки, или из сформированного пользователем набора, или один из стилей, хранящихся в документе. Ее наличием можно управлять с помощью свойства [AnotherStyleBtnEnable](ipropertystylelist_anotherstylebtnenable.html).

Можно наполнить комбобокс только нужными стилями.

Подразделы:

[IPropertyStyleList - свойства ](ipropertystylelist_props.html)

[IPropertyStyleList - методы ](ipropertystylelist_methods.html)
