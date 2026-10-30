# Интерфейс IArcDimension3D

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Оформление ](bc2273863.html) > [Размеры ](bc2274179.html) |  Scroll [ [ [ ](iarcdimension3d_props.html "К следующему разделу")](bc2274179.html "На уровень выше")](iangledimension3d_setcenterpoint.html "К предыдущему разделу")  
---|---  
  
Интерфейс размера дуги окружности 3D

Иерархия:

IDispatch

[IKompasAPIObject](ikompasapiobject.html)

[IModelObject](imodelobject.html)

[IArcDimension3D](iarcdimension3d.html)

[IDimensionText](idimensiontext.html)

[IDimensionParams](idimensionparams.html)

Описание:

Интерфейс позволяет получить и задать свойства размера размера дуги окружности в 3D документе.

Интерфейс можно получить у коллекции размеров дуг окружностей в 3D документе, используя свойство[ IArcDimensions3D::ArcDimension3D](iarcdimensions3d_arcdimension3d.html) или метод [IArcDimensions3D::Add](iarcdimensions3d_add.html).

После задания параметров размера требуется вызвать метод [IModelObject::Update](imodelobject_update.html).

Интерфейсы [IDimensionText](idimensiontext.html) и [IDimensionParams](idimensionparams.html) являются дополнительными. Их можно получить с помощью метода [IUnknown::QueryInterface](recomendation.html).

Версия: Компас v20

Подразделы:

[IArcDimension3D - свойства ](iarcdimension3d_props.html)
