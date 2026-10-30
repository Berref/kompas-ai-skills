# Интерфейс IMultiline

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) |  Scroll [ [ [ ](imultiline_props.html "К следующему разделу")](bb2333035.html "На уровень выше")](ilinesegment_y2.html "К предыдущему разделу")  
---|---  
  
Интерфейс мультилинии.

Иерархия:

IDispatch

[IKompasAPIObject](ikompasapiobject.html)

[IDrawingObject](idrawingobject.html)

[IMultiline](imultiline.html)

Примечание:

1\. Интерфейс позволяет получить и задать свойства объекта "мультилиния". Для создания объекта должен быть задан базовый контур и хотя бы одна линия.

2\. Получить интерфейс можно, используя свойство [IMultilines::MultiLine](imultilines_multiline.html) или метод [IMultilines::Add](imultilines_add.html) интерфейса коллекции мультилиний.

3\. После задания параметров объекта требуется вызвать метод [IDrawingObject::Update](idrawingobject_update.html).

Подразделы:

[IMultiline - свойства ](imultiline_props.html)

[IMultiline - методы ](imultiline_methods.html)
