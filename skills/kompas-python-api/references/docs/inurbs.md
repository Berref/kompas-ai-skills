# Интерфейс INurbs

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) |  Scroll [ [ [ ](inurbs_props.html "К следующему разделу")](bb2333035.html "На уровень выше")](imultiline_findline.html "К предыдущему разделу")  
---|---  
  
Интерфейс NURBS-кривой.

Иерархия:

IDispatch

[IKompasAPIObject](ikompasapiobject.html)

[IDrawingObject](idrawingobject.html)

[INurbs](inurbs.html)

Описание:

Интерфейс позволяет задавать параметры NURBS-кривой.

Примечание:

1\. Интерфейс можно получить у коллекции NURBS-кривых, используя свойство [INurbses::Nurbs](inurbses_nurbs.html) или метод [INurbses::Add](inurbses_add.html).

2\. После задания параметров NURBS-кривой требуется вызвать метод [IDrawingObject::Update](idrawingobject_update.html).

Подразделы:

[INurbs - свойства ](inurbs_props.html)

[INurbs - методы ](inurbs_methods.html)
