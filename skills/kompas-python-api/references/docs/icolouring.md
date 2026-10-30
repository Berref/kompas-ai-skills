# Интерфейс IColouring

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) |  Scroll [ [ [ ](icolouring_props.html "К следующему разделу")](bb2333035.html "На уровень выше")](icircle_yc.html "К предыдущему разделу")  
---|---  
  
Интерфейс заливки.

Иерархия:

IDispatch

[IKompasAPIObject](ikompasapiobject.html)

[IDrawingObject](idrawingobject.html)

[IColouring](icolouring.html)

[IBoundariesObject](iboundariesobject.html)

Описание:

Интерфейс позволяет задавать параметры заливки.

Примечание:

1\. Интерфейс можно получить у коллекции заливок, используя свойство [IColourings::Colouring](icolourings_colouring.html) или метод [IColourings::Add](icolourings_add.html).

2\. После задания параметров штриховки требуется вызвать метод [IDrawingObject::Update](idrawingobject_update.html).

3\. Посредством вызова метода I[Unknown::QueryInterface (const GUID far& iid, void** pif) ](recomendation.html)у данного интерфейса можно получить дополнительный интерфейс [IBoundariesObject](iboundariesobject.html).

Подразделы:

[IColouring - свойства ](icolouring_props.html)

[IColouring - методы ](icolouring_methods.html)
