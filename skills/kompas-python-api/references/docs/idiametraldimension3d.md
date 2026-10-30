# Интерфейс IDiametralDimension3D

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Оформление ](bc2273863.html) > [Размеры ](bc2274179.html) |  Scroll [ [ [ ](idiametraldimension3d_props.html "К следующему разделу")](bc2274179.html "На уровень выше")](ilinedimension3d_plane.html "К предыдущему разделу")  
---|---  
  
Интерфейс параметров диаметрального размера 3D.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[IModelObject](imodelobject.html)

[IDiametralDimension3D](idiametraldimension3d.html)

[IDimensionText](idimensiontext.html)

[IDimensionParams](idimensionparams.html)

Описание:

Интерфейс позволяет получить и задать свойства диаметрального размера в 3D документе.

Интерфейс можно получить у коллекции диаметральных размеров, используя свойство [IDiametralDimensions3D::DiametralDimension3D](idiametraldimensions3d_diametraldimension3d.html) или метод [IDiametralDimensions3D::Add](idiametraldimensions3d_add.html).

После задания параметров размера требуется вызвать метод [IModelObject::Update](imodelobject_update.html).

Интерфейсы [IDimensionText](idimensiontext.html) и [IDimensionParams](idimensionparams.html) являются дополнительными. Их можно получить с помощью метода [IUnknown::QueryInterface](recomendation.html).

Примечание:

1\. При создании радиального и диаметрального размеров используются следующие объекты:

•окружность (дуга окружности) в эскизе,

•ребро тела или поверхности, имеющее форму окружности (дуги окружности),

•грань тела или поверхности, имеющая цилиндрическую, коническую, сферическую или тороидальную форму.

При выборе в качестве базового объекта окружности в эскизе размер проставляется в плоскости эскиза.

При выборе в качестве базового объекта ребра тела или поверхности размер проставляется в плоскости, в которой находится выбранное ребро.

Положение размера можно задавать произвольно или фиксировать.

Способы задания произвольного положения размера:

•установите координаты центра с помощью функции [SetCenterPoint](idiametraldimension3d_setcenterpoint.html). Координаты будут спроецированы на ось грани.

•укажите точку на поверхности или ребре с помощью функции [SetSurfacePoint](idiametraldimension3d_setsurfacepoint.html).

Для фиксации положения размера укажите точечный объект или плоский объект, параллельный плоскости простановки размера. Размер будет проставлен в плоскости, проходящей через объект фиксации. Между размером и объектом фиксации формируется ассоциативная связь. Благодаря этой связи размер следует за объектом фиксации при изменении положения последнего.

2\. Свойство [IDimensionText::NominalValue](idimensiontext_nominalvalue.html) возвращает диаметр.

Подразделы:

[IDiametralDimension3D - свойства ](idiametraldimension3d_props.html)

[IDiametralDimension3D - методы ](idiametraldimension3d_methods.html)
