# Интерфейс IAngleDimension3D

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Оформление ](bc2273863.html) > [Размеры ](bc2274179.html) |  Scroll [ [ [ ](iangledimension3d_props.html "К следующему разделу")](bc2274179.html "На уровень выше")](iradialdimensions3d_add.html "К предыдущему разделу")  
---|---  
  
Интерфейс параметров углового размера 3D.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[IModelObject](imodelobject.html)

[IAngleDimension3D](iangledimension3d.html)

[IDimensionText](idimensiontext.html)

[IDimensionParams](idimensionparams.html)

Описание:

Интерфейс позволяет получить и задать свойства углового размера в 3D документе.

Интерфейс можно получить у коллекции угловых размеров в 3D документе, используя свойство [IAngleDimensions3D::AngleDimension3D](iangledimensions3d_angledimension3d.html) или метод [IAngleDimensions3D::Add](iangledimensions3d_add.html).

После задания параметров размера требуется вызвать метод [IModelObject::Update](imodelobject_update.html).

Интерфейсы [IDimensionText](idimensiontext.html) и [IDimensionParams](idimensionparams.html) являются дополнительными. Их можно получить с помощью метода [IUnknown::QueryInterface](recomendation.html).

Примечание:

1.При создании углового размера используются прямолинейные и плоские объекты, которые являются сторонами угла.

Прямолинейные объекты:

•отрезок в эскизе,

•сегмент ломаной,

•вспомогательная ось,

•ребро тела или поверхности.

Плоские объекты:

•координатная плоскость,

•вспомогательная плоскость,

•грань тела или поверхности.

2.Свойство [IDimensionText::NominalValue](idimensiontext_nominalvalue.html) возвращает угол.

Подразделы:

[IAngleDimension3D - свойства ](iangledimension3d_props.html)

[IAngleDimension3D - методы ](iangledimension3d_methods.html)
