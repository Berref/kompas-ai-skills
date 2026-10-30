# Интерфейс IRaster

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) |  Scroll [ [ [ ](iraster_props.html "К следующему разделу")](bb2333035.html "На уровень выше")](iregularpolygon_setcorner.html "К предыдущему разделу")  
---|---  
  
Интерфейс растрового объекта.

Иерархия:

IDispatch

[IKompasAPIObject](ikompasapiobject.html)

[IDrawingObject](idrawingobject.html)

[IRaster](iraster.html)

[IBoundariesObject](iboundariesobject.html)

Описание:

Интерфейс позволяет задавать параметры растрового объекта.

Примечание:

1\. Интерфейс можно получить у коллекции растровых объектов, используя свойство [IRasters::Raster](irasters_raster.html) или метод [IRasters::Add](irasters_add.html).

2\. После задания параметров растрового объекта требуется вызвать метод [IDrawingObject::Update](idrawingobject_update.html).

3\. Посредством вызова метода [IUnknown::QueryInterface (const GUID far& iid, void** pif)](recomendation.html) у данного интерфейса можно получить дополнительный интерфейс [IBoundariesObject](iboundariesobject.html).

4\. Для задания границы обрезки растра нужно использовать [IBoundariesObject::AddBoundaries](iboundariesobject_addboundaries.html). В качестве границы обрезки может быть задан только один замкнутый контур.

Подразделы:

[IRaster - свойства ](iraster_props.html)

[IRaster - методы ](iraster_methods.html)
