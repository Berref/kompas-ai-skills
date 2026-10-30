# Интерфейс ILineDimension3D

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Оформление ](bc2273863.html) > [Размеры ](bc2274179.html) |  Scroll [ [ [ ](ilinedimension3d_props.html "К следующему разделу")](bc2274179.html "На уровень выше")](ibaselinedimension3d_object2.html "К предыдущему разделу")  
---|---  
  
Интерфейс параметров линейного размера на плоскости 3D.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[IModelObject](imodelobject.html)

[ILineDimension3D](ilinedimension3d.html)

[IDimensionText](idimensiontext.html)

[IDimensionParams](idimensionparams.html)

Описание:

Интерфейс позволяет получить и задать свойства линейного размера в 3D документе.

Интерфейс можно получить у коллекции линейных размеров в 3D документе, используя свойство [ILineDimensions3D::LineDimension3D](ilinedimensions3d_linedimension3d.html) или метод [ILineDimensions3D::Add](ilinedimensions3d_add.html).

После задания парамеров размера требуется вызвать метод [IModelObject::Update](imodelobject_update.html).

Интерфейсы [IDimensionText](idimensiontext.html) и [IDimensionParams](idimensionparams.html) являются дополнительными. Их можно получить с помощью метода [IUnknown::QueryInterface](recomendation.html).

Примечание:

В качестве направляющей плоскости можно использовать:

•координатную плоскость,

•вспомогательную плоскость,

•грань тела или поверхности.

Подразделы:

[ILineDimension3D - свойства ](ilinedimension3d_props.html)
