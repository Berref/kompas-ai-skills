# Интерфейс IAxisLine

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Обозначения ](bb3219840.html) |  Scroll [ [ [ ](iaxisline_props.html "К следующему разделу")](bb3219840.html "На уровень выше")](iassociationtable_rebuild.html "К предыдущему разделу")  
---|---  
  
Интерфейс осевой линии.

Иерархия:

IDispatch

[IKompasAPIObject](ikompasapiobject.html)

[IDrawingObject](idrawingobject.html)

[IAxisLine](iaxisline.html)

[IAxisLineParam](iaxislineparam.html)

Описание:

Интерфейс позволяет задавать параметры осевой линии.

Примечание:

1\. Интерфейс можно получить у коллекции осевых линий, используя свойство [IAxisLines::AxisLine](iaxislines_axisline.html) или метод [IAxisLines::Add](iaxislines_add.html).

2\. После задания параметров осевой линии требуется вызвать метод [IDrawingObject::Update](idrawingobject_update.html).

3\. Посредством вызова метода [IUnknown::QueryInterface (const GUID far& iid, void** pif)](recomendation.html) у данного интерфейса можно получить дополнительный интерфейс [IAxisLineParam](iaxislineparam.html).

Подразделы:

[IAxisLine - свойства ](iaxisline_props.html)
