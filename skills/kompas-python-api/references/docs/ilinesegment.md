# Интерфейс ILineSegment

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) |  Scroll [ [ [ ](ilinesegment_props.html "К следующему разделу")](bb2333035.html "На уровень выше")](iline_y2.html "К предыдущему разделу")  
---|---  
  
Интерфейс отрезка.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[IDrawingObject](idrawingobject.html)

[ILineSegment](ilinesegment.html)

Описание:

Примечание:

1\. Интерфейс можно получить у коллекции отрезков, используя свойство [ILineSegments::LineSegment](ilinesegments_linesegment.html) или метод [ILineSegments::Add](ilinesegments_add.html).

2\. При создании отрезка можно использовать несколько типов построения:

2.1. по координатам (требуется задать координаты точек ([X1](ilinesegment_x1.html); [Y1](ilinesegment_y1.html)), ([X2](ilinesegment_x2.html); [Y2](ilinesegment_y2.html)).

2.2. По точке 1 ([X1](ilinesegment_x1.html); [Y1](ilinesegment_y1.html)), длине [Length](ilinesegment_length.html) и углу [Angle](ilinesegment_angle.html),-

По точке 2 ([X2](ilinesegment_x2.html); [Y2](ilinesegment_y2.html)), длине [Length](ilinesegment_length.html) и углу [Angle](ilinesegment_angle.html) относительно точки 1.

3\. После задания параметров отрезка требуется вызвать метод [IDrawingObject::Update](idrawingobject_update.html).

4\. При изменении параметров зависимые параметры пересчитываются после вызова метода [IDrawingObject::Update](idrawingobject_update.html).

Подразделы:

[ILineSegment - свойства ](ilinesegment_props.html)
