# Интерфейс ITolerance

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Обозначения ](bb3219840.html) |  Scroll [ [ [ ](itolerance_props.html "К следующему разделу")](bb3219840.html "На уровень выше")](irough_brancharrowinside.html "К предыдущему разделу")  
---|---  
  
Интерфейс обозначения допуска формы 2D.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[IDrawingObject](idrawingobject.html)

[ITolerance](itolerance.html)

[IToleranceParam](itoleranceparam.html)

[IBranchs](ibranchs.html)

[ITable](itable.html)

Примечание:

1\. Получить интерфейс можно, используя свойство интерфейса коллекции [ITolerances::Tolerance](itolerances_tolerance.html) или метод [ITolerances::Add](itolerances_add.html).

2\. Посредством вызова метода [IUnknown::QueryInterface (const GUID far& iid, void** pif)](recomendation.html) интерфейс позволяет получить следующие дополнительные интерфейсы:

•[IToleranceParam](itoleranceparam.html) \- интерфейс параметров допуска формы,

•[IBranchs](ibranchs.html) \- интерфейс для работы с ответвлениями,

•[ITable](itable.html) \- интерфейс таблицы.

3\. После задания параметров объекта требуется вызвать метод [IDrawingObject::Update](idrawingobject_update.html).

Подразделы:

[ITolerance - свойства ](itolerance_props.html)

[ITolerance - методы ](itolerance_methods.html)
