# Интерфейс ILineDimension

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Размеры ](bb2356896.html) |  Scroll [ [ [ ](ilinedimension_props.html "К следующему разделу")](bb2356896.html "На уровень выше")](iheightdimension_y2.html "К предыдущему разделу")  
---|---  
  
Интерфейс параметров линейного размера.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[IDrawingObject](idrawingobject.html)

[ILineDimension](ilinedimension.html)

[IDimensionText](idimensiontext.html)

[IDimensionParams](idimensionparams.html)

Описание:

Интерфейс позволяет получить и задать свойства линейного размера.

Интерфейс можно получить у коллекции линейных размеров, используя свойство [ILineDimensions::LineDimension](ilinedimensions_linedimension.html) или метод [ILineDimensions::Add](ilinedimensions_add.html).

После задания параметров размера требуется вызвать метод [IModelObject::Update](imodelobject_update.html).

Интерфейсы [IDimensionText](idimensiontext.html) и [IDimensionParams](idimensionparams.html) являются дополнительными. Их можно получить с помощью метода [IUnknown::QueryInterface](recomendation.html).

Примечание:

Свойство [IDimensionText::NominalValue](idimensiontext_nominalvalue.html) возвращает расстояние между точками (X1, Y1) и (X2, Y2).

Подразделы:

[ILineDimension - свойства ](ilinedimension_props.html)

[ILineDimension - методы](ilinedimension_methods.html)
