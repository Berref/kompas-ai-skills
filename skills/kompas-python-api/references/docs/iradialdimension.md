# Интерфейс IRadialDimension

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Размеры ](bb2356896.html) |  Scroll [ [ [ ](iradialdimension_props.html "К следующему разделу")](bb2356896.html "На уровень выше")](ilinesegmentandpointdimension_setbaseobjectpoint.html "К предыдущему разделу")  
---|---  
  
Интерфейс параметров радиального размера.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[IDrawingObject](idrawingobject.html)

[IRadialDimension](iradialdimension.html)

[IDimensionText](idimensiontext.html)

[IDimensionParams](idimensionparams.html)

Описание:

Интерфейс позволяет получить и задать свойства радиального размера.

Интерфейс можно получить у коллекции радиальных размеров, используя свойство [IRadialDimensions::RadialDimension](iradialdimensions_radialdimension.html) или метод [IRadialDimensions::Add](iradialdimensions_add.html).

После задания параметров размера требуется вызвать метод [IDrawingObject::Update](idrawingobject_update.html).

Интерфейсы [IDimensionText](idimensiontext.html) и [IDimensionParams](idimensionparams.html) являются дополнительными. Их можно получить с помощью метода [IUnknown::QueryInterface](recomendation.html)

Примечание:

Если при создании размера задать опорный объект [IRadialDimension::BaseObject](iradialdimension_baseobject.html), то координаты центра [IRadialDimension::Xc](iradialdimension_xc.html)[IRadialDimension::Yc](iradialdimension_yc.html) и радиус [IRadialDimension::Radius](iradialdimension_radius.html) задавать не нужно. Данные свойства будут получены с опорного объекта. Свойство [IDimensionText::NominalValue](idimensiontext_nominalvalue.html) возвращает диаметр.

В качестве опорного объекта может быть использована окружность или дуга окружности.

Подразделы:

[IRadialDimension - свойства ](iradialdimension_props.html)

[IRadialDimension - методы ](iradialdimension_methods.html)
