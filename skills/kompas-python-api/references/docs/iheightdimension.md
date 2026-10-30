# Интерфейс IHeightDimension

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Размеры ](bb2356896.html) |  Scroll [ [ [ ](iheightdimension_props.html "К следующему разделу")](bb2356896.html "На уровень выше")](idiametraldimension_yc.html "К предыдущему разделу")  
---|---  
  
Интерфейс параметров размера высоты.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[IDrawingObject](idrawingobject.html)

[IHeightDimension](iheightdimension.html)

[IDimensionParams](idimensionparams.html)

[IDimensionText](idimensiontext.html)

Описание:

Интерфейс позволяет получить и задать свойства размера высоты.

Интерфейс можно получить у коллекции размеров высоты, используя свойство [IHeightDimensions::HeightDimension](iheightdimensions_heightdimension.html) или метод [IHeightDimensions::Add](iheightdimensions_add.html).

После задания параметров размера требуется вызвать метод [IDrawingObject::Update](idrawingobject_update.html).

Интерфейсы [IDimensionText](idimensiontext.html) и [IDimensionParams](idimensionparams.html) являются дополнительными. Их можно получить с помощью метода [IUnknown::QueryInterface](recomendation.html).

Примечание:

Свойство [IDimensionText::NominalValue](idimensiontext_nominalvalue.html) возвращает значение высоты (Y1 - Y).

Подразделы:

[IHeightDimension - свойства ](iheightdimension_props.html)
