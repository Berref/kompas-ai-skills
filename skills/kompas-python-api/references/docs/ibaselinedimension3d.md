# Интерфейс IBaseLineDimension3D

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Оформление ](bc2273863.html) > [Размеры ](bc2274179.html) |  Scroll [ [ [ ](ibaselinedimension3d_props.html "К следующему разделу")](bc2274179.html "На уровень выше")](iarcdimension3d_object.html "К предыдущему разделу")  
---|---  
  
Интерфейс параметров линейного размера от отрезка до точки 3D.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[IModelObject](imodelobject.html)

[IBaseLineDimension3D](ibaselinedimension3d.html)

[IDimensionText](idimensiontext.html)

[IDimensionParams](idimensionparams.html)

Описание:

Интерфейс позволяет получить и задать свойства линейного размера от отрезка до точки в 3D документе.

Интерфейс можно получить у коллекции линейных размеров в 3D документе, используя свойство [ILineDimensions3D::LineDimension3D](ilinedimensions3d_linedimension3d.html) или метод [ILineDimensions3D::Add](ilinedimensions3d_add.html).

После задания параметров размера требуется вызвать метод [IModelObject::Update](imodelobject_update.html).

Интерфейсы [IDimensionText](idimensiontext.html) и [IDimensionParams](idimensionparams.html) являются дополнительными. Их можно получить с помощью метода [IUnknown::QueryInterface](recomendation.html).

Примечание:

1\. Интерфейс позволяет проставить линейный размер между прямолинейным и точечным объектами. При простановке линейного размера расстояния от ребра до точки в качестве первого объекта можно использовать только прямолинейные объекты, в качестве второго объекта можно использовать только точечные объекты. При простановке линейного размера на плоскости можно использовать и прямолинейные и точечные объекты.

Прямолинейные объекты:

•отрезок в эскизе,

•сегмент ломаной,

•координатная ось,

•вспомогательная ось,

•ребро тела или поверхности.

Точечные объекты:

•точка в эскизе,

•пространственная точка,

•начало координат,

•вершина пространственной кривой,

•вершина тела или поверхности.

2\. Свойство [IDimensionText::NominalValue](idimensiontext_nominalvalue.html) возвращает расстояние.

Подразделы:

[IBaseLineDimension3D - свойства ](ibaselinedimension3d_props.html)
