# Интерфейс IArcDimension

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Размеры ](bb2356896.html) |  Scroll [ [ [ ](iarcdimension_props.html "К следующему разделу")](bb2356896.html "На уровень выше")](ibreakangledimension.html "К предыдущему разделу")  
---|---  
  
Интерфейс параметров размера дуги окружности.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[IDrawingObject](idrawingobject.html)

[IArcDimension](iarcdimension.html)

[IDimensionText](idimensiontext.html)

[IDimensionParams](idimensionparams.html)

Описание:

Интерфейс позволяет получить и задать свойства размера дуги окружности.

Интерфейс можно получить у коллекции размеров дуг окружностей, используя свойство [IArcDimensions::ArcDimension](iarcdimensions_arcdimension.html) или метод [IArcDimensions::Add](iarcdimensions_add.html).

После задания параметров размера требуется вызвать метод [IDrawingObject::Update](idrawingobject_update.html).

Интерфейсы [IDimensionText](idimensiontext.html) и [IDimensionParams](idimensionparams.html) являются дополнительными. Их можно получить с помощью метода [IUnknown::QueryInterface](recomendation.html).

Примечание:

1\. Свойство [IDimensionText::NominalValue](idimensiontext_nominalvalue.html) возвращает длину дуги.

2\. Если при создании размера задать опорный объект [IArcDimension::BaseObject](iarcdimension_baseobject.html), то значения свойств [IArcDimension::Xc](iarcdimension_xc.html), [IArcDimension::Yc](iarcdimension_yc.html), [IArcDimension::X1](iarcdimension_x1.html), [IArcDimension::Y1](iarcdimension_y1.html), [IArcDimension::X2](iarcdimension_x2.html), [IArcDimension::Y2](iarcdimension_y2.html), [IArcDimension::Direction](iarcdimension_direction.html) задавать не нужно. Данные свойства будут получены с исходных объектов. В качестве базового объекта может использоваться дуга окружности.

Подразделы:

[IArcDimension - свойства ](iarcdimension_props.html)
