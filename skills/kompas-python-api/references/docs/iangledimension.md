# Интерфейс IAngleDimension

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Размеры ](bb2356896.html) |  Scroll [ [ [ ](iangledimension_props.html "К следующему разделу")](bb2356896.html "На уровень выше")](iradialdimensions_add.html "К предыдущему разделу")  
---|---  
  
Интерфейс параметров углового размера.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[IDrawingObject](idrawingobject.html)

[IAngleDimension](iangledimension.html)

[IDimensionText](idimensiontext.html)

[IDimensionParams](idimensionparams.html)

Описание:

Интерфейс позволяет получить и задать свойства углового размера.

Интерфейс можно получить у коллекции угловых размеров, используя свойство [IAngleDimensions::AngleDimension](iangledimensions_angledimension.html) или метод [IAngleDimensions::Add](iangledimensions_add.html).

После задания параметров размера требуется вызвать метод [IDrawingObject::Update](idrawingobject_update.html).

Интерфейсы [IDimensionText](idimensiontext.html) и [IDimensionParams](idimensionparams.html) являются дополнительными. Их можно получить с помощью метода [IUnknown::QueryInterface](recomendation.html).

Примечание:

Если при создании размера задать опорные объекты [IAngleDimension::BaseObject1](iangledimension_baseobject1.html), [IAngleDimension::BaseObject2](iangledimension_baseobject2.html), то координаты центра [IAngleDimension::Xc](iangledimension_xc.html), [IAngleDimension::Yc](iangledimension_yc.html), радиус [IAngleDimension::Radius](iangledimension_radius.html), [IAngleDimension::X1](iangledimension_x1.html), [IAngleDimension::Y1](iangledimension_y1.html), [IAngleDimension::X2](iangledimension_x2.html), [IAngleDimension::Y2](iangledimension_y2.html), задавать не нужно. Данные свойства будут получены с опорного объекта.

В качестве базовых объектов могут использоваться отрезки. Для углового размера второй опорный объект задает направление второй выносной линии. Для углового размера с обрывом второй опорный объект задает ось симметрии (биссектрису угла).

Свойство [IDimensionText::NominalValue](idimensiontext_nominalvalue.html) возвращает угол.

Подразделы:

[IAngleDimension - свойства ](iangledimension_props.html)
