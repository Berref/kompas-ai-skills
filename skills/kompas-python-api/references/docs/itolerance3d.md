# Интерфейс ITolerance3D

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Оформление ](bc2273863.html) > [Обозначения ](bc2275772.html) |  Scroll [ [ [ ](itolerance3d_props.html "К следующему разделу")](bc2275772.html "На уровень выше")](irough3d_setshelfposition.html "К предыдущему разделу")  
---|---  
  
Интерфейс обозначения допуска формы 3D.

Иерархия:

IDispatch

[IKompasAPIObject](ikompasapiobject.html)

[IModelObject](imodelobject.html)

[ITolerance3D](itolerance3d.html)

[IToleranceParam](itoleranceparam.html)

[IBranchs3D](ibranchs3d.html)

[ITable](itable.html)

Примечание:

1\. Интерфейс можно получить у коллекции обозначений допуска формы 3D, используя свойство [ITolerances3D::Tolerance3D](itolerances3d_tolerance3d.html) или метод [ITolerances3D::Add](itolerances3d_add.html).

2\. Посредством вызова метода [IUnknown::QueryInterface (const GUID far& iid, void** pif) ](recomendation.html)интерфейс позволяет получить следующие дополнительные интерфейсы:

•[IToleranceParam](itoleranceparam.html) \- интерфейс параметров допуска формы,

•[IBranchs3D](ibranchs3d.html) \- интерфейс для работы с ответвлениями в 3D,

•[ITable](itable.html) \- интерфейс таблицы.

3\. После задания параметров обозначения требуется вызвать метод [IModelObject::Update](imodelobject_update.html).

Подразделы:

[ITolerance3D - свойства ](itolerance3d_props.html)

[ITolerance3D - методы ](itolerance3d_methods.html)
