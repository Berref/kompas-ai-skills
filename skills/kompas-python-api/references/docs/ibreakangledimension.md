# Интерфейс IBreakAngleDimension

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Размеры ](bb2356896.html) > [Интерфейс IAngleDimension ](iangledimension.html) > [IAngleDimension - свойства ](iangledimension_props.html) |  Scroll [ [ [ ](iarcdimension.html "К следующему разделу")](iangledimension_props.html "На уровень выше")](iangledimension_y3.html "К предыдущему разделу")  
---|---  
  
Интерфейс параметров углового размера c обрывом.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[IDrawingObject](idrawingobject.html)

[IAngleDimension](iangledimension.html)

[IBreakAngleDimension](ibreakangledimension.html)

[IDimensionText](idimensiontext.html)

[IDimensionParams](idimensionparams.html)

Описание:

Интерфейс позволяет получить и задать свойства углового размера c обрывом.

Интерфейс можно получить у коллекции угловых размеров, используя свойство [IAngleDimensions::AngleDimension](iangledimensions_angledimension.html) или метод [IAngleDimensions::Add](iangledimensions_add.html).

После задания параметров размера требуется вызвать метод [IDrawingObject::Update](idrawingobject_update.html).

Интерфейсы [IDimensionText](idimensiontext.html) и [IDimensionParams](idimensionparams.html) являются дополнительными. Их можно получить с помощью метода [IUnknown::QueryInterface](recomendation.html).

Подразделы:

(отсутствуют)
