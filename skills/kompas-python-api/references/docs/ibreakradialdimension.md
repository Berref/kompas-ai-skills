# Интерфейс IBreakRadialDimension

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Размеры ](bb2356896.html) |  Scroll [ [ [ ](ibreakradialdimension_props.html "К следующему разделу")](bb2356896.html "На уровень выше")](iradialdimension_setbranchparam.html "К предыдущему разделу")  
---|---  
  
Интерфейс параметров радиального размера с изломом.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[IDrawingObject](idrawingobject.html)

[IBreakRadialDimension](ibreakradialdimension.html)

[IDimensionText](idimensiontext.html)

Описание:

Интерфейс позволяет получить и задать свойства радиального размера с изломом.

Интерфейс можно получить у коллекции радиальных размеров с изломом, используя свойство [IBreakRadialDimensions::BreakRadialDimension](ibreakradialdimensions_breakradialdimension.html) или метод [IBreakRadialDimensions::Add](ibreakradialdimensions_add.html).

После задания параметров размера требуется вызвать метод [IDrawingObject::Update](idrawingobject_update.html).

Интерфейс [IDimensionText](idimensiontext.html) является дополнительным. Его можно получить с помощью метода [IUnknown::QueryInterface](recomendation.html). Интерфейс [IDimensionParams](idimensionparams.html) для радиального размер с изломом не поддерживается.

Примечание:

Если при создании размера задать опорный объект [IBreakRadialDimension::BaseObject](ibreakradialdimension_baseobject.html), то координаты центра [IBreakRadialDimension::Xc](ibreakradialdimension_xc.html), [IBreakRadialDimension::Yc](ibreakradialdimension_yc.html) и радиус [IBreakRadialDimension::Radius](ibreakradialdimension_radius.html) задавать не нужно. Данные свойства будут получены с опорного объекта. Свойство [IDimensionText::NominalValue](idimensiontext_nominalvalue.html) возвращает радиус.

В качестве опорного объекта может быть использована окружность или дуга окружности.

Подразделы:

[IBreakRadialDimension - свойства ](ibreakradialdimension_props.html)
