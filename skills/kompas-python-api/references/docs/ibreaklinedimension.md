# Интерфейс IBreakLineDimension

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Размеры ](bb2356896.html) |  Scroll [ [ [ ](ibreaklinedimension_props.html "К следующему разделу")](bb2356896.html "На уровень выше")](iarcdimension_y3.html "К предыдущему разделу")  
---|---  
  
Интерфейс параметров линейного размера с обрывом.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[IDrawingObject](idrawingobject.html)

[IBreakLineDimension](ibreaklinedimension.html)

[IDimensionText](idimensiontext.html)

[IDimensionParams](idimensionparams.html)

Описание:

Интерфейс позволяет получить и задать свойства линейного размера с обрывом.

Интерфейс можно получить у коллекции линейных размеров с обрывом, используя свойство [IBreakLineDimensions::BreakLineDimension](ibreaklinedimensions_breaklinedimension.html) или метод [IBreakLineDimensions::Add](ibreaklinedimensions_add.html).

После задания параметров размера требуется вызвать метод [IDrawingObject::Update](idrawingobject_update.html).

Интерфейсы [IDimensionText](idimensiontext.html) и [IDimensionParams](idimensionparams.html) являются дополнительными. Их можно получить с помощью метода [IUnknown::QueryInterface](recomendation.html).

Подразделы:

[IBreakLineDimension - свойства ](ibreaklinedimension_props.html)
