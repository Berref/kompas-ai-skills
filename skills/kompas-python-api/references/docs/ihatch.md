# Интерфейс IHatch

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) |  Scroll [ [ [ ](ihatch_props.html "К следующему разделу")](bb2333035.html "На уровень выше")](iequidistant_setcorner.html "К предыдущему разделу")  
---|---  
  
Интерфейс штриховки.

Иерархия:

IDispatch

[IKompasAPIObject](ikompasapiobject.html)

[IDrawingObject](idrawingobject.html)

[IHatch](ihatch.html)

[IHatchParam](ihatchparam.html)

[IBoundariesObject](iboundariesobject.html)

Описание:

Интерфейс позволяет задавать параметры штриховки.

Примечание:

1\. Интерфейс можно получить у коллекции штриховок, используя свойство [IHatches::Hatch](ihatches_hatch.html) или метод [IHatches::Add](ihatches_add.html).

2\. После задания параметров штриховки требуется вызвать метод [IDrawingObject::Update](idrawingobject_update.html).

3\. Посредством вызова метода [IUnknown::QueryInterface (const GUID far& iid, void** pif)](recomendation.html) у данного интерфейса можно получить дополнительные интерфейсы:

•[IHatchParam](ihatchparam.html),

•[IBoundariesObject](iboundariesobject.html).

Подразделы:

[IHatch - свойства ](ihatch_props.html)
