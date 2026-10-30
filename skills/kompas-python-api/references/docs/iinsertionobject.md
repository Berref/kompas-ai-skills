# Интерфейс IInsertionObject

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Вставки видов, фрагментов, OLE объектов ](bb2331024.html) |  Scroll [ [ [ ](iinsertionobject_props.html "К следующему разделу")](bb2331024.html "На уровень выше")](ioledrawingobjects_add.html "К предыдущему разделу")  
---|---  
  
Базовый интерфейс для вставки фрагментов и видов другого чертежа.

Иерархия:

IDispatch

[IKompasAPIObject](ikompasapiobject.html)

[IDrawingObject](idrawingobject.html)

[IInsertionObject](iinsertionobject.html)

[IInsertionFragment](iinsertionfragment.html)

[IInsertionView](iinsertionview.html)

[IPropertyKeeper](ipropertykeeper.html)

Описание:

Интерфейс позволяет задавать и получать параметры вставки фрагментов и видов другого чертежа.

Примечание:

1\. Интерфейс можно получить у коллекции вставок фрагментов и видов, используя свойство [IInsertionObjects::InsertionObject](iinsertionobjects_insertionobject.html) или метод [IInsertionObjects::Add](iinsertionobjects_add.html).

2\. После задания параметров объекта требуется вызвать метод [IDrawingObject::Update](idrawingobject_update.html).

3\. Посредством вызова метода [IUnknown::QueryInterface (const GUID far& iid, void** pif)](recomendation.html) у данного интерфейса можно получить дополнительные интерфейсы:

•[IInsertionFragment](iinsertionfragment.html),

•[IInsertionView](iinsertionview.html),

•[IPropertyKeeper](ipropertykeeper.html).

Подразделы:

[IInsertionObject - свойства ](iinsertionobject_props.html)

[IInsertionObject - методы ](iinsertionobject_methods.html)

[Интерфейс IInsertionFragment ](iinsertionfragment.html)

[Интерфейс IInsertionView ](iinsertionview.html)
