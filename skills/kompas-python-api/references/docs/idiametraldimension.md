# Интерфейс IDiametralDimension

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Размеры ](bb2356896.html) |  Scroll [ [ [ ](idiametraldimension_props.html "К следующему разделу")](bb2356896.html "На уровень выше")](ibreaklinedimension_y3.html "К предыдущему разделу")  
---|---  
  
Интерфейс параметров диаметрального размера.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[IDrawingObject](idrawingobject.html)

[IDiametralDimension](idiametraldimension.html)

[IDimensionText](idimensiontext.html)

[IDimensionParams](idimensionparams.html)

Описание:

Интерфейс позволяет получить и задать свойства диаметрального размера.

Интерфейс можно получить у коллекции диаметральных размеров, используя свойство [IDiametralDimensions::DiametralDimension](idiametraldimensions_diametraldimension.html) или метод [IDiametralDimensions::Add](idiametraldimensions_add.html).

После задания параметров размера требуется вызвать метод [IDrawingObject::Update](idrawingobject_update.html).

Интерфейсы [IDimensionText](idimensiontext.html) и [IDimensionParams](idimensionparams.html) являются дополнительными. Их можно получить с помощью метода [IUnknown::QueryInterface](recomendation.html).

Примечание:

Если при создании размера задать опорный объект [IDiametralDimension::BaseObject](idiametraldimension_baseobject.html), то координаты центра [IDiametralDimension::Xc](idiametraldimension_xc.html), [IDiametralDimension::Yc](idiametraldimension_yc.html) и радиус [IDiametralDimension::Radius](idiametraldimension_radius.html) задавать не нужно. Данные свойства будут получены с опорного объекта. Свойство [IDimensionText::NominalValue](idimensiontext_nominalvalue.html) возвращает диаметр.

В качестве опорного объекта может быть использована окружность или дуга окружности.

Подразделы:

[IDiametralDimension - свойства ](idiametraldimension_props.html)
