# Интерфейс IStraightAxis

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения для строительства ](bb2362006.html) |  Scroll [ [ [ ](istraightaxis_props.html "К следующему разделу")](bb2362006.html "На уровень выше")](icircleaxis_yc.html "К предыдущему разделу")  
---|---  
  
Интерфейс прямой координационной оси.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[IDrawingObject](idrawingobject.html)

[IBuildingAxis](ibuildingaxis.html)

[IStraightAxis](istraightaxis.html)

Описание:

Интерфейс позволяет получать и изменять свойства прямой строительной оси.

Примечание:

1\. Получить интерфейс строительной оси можно, используя методы коллекции строительных осей [IBuildingAxes::BuildingAxis](ibuildingaxes_buildingaxis.html), [IBuildingAxes::Add](ibuildingaxes_add.html).

2\. При создании прямой оси можно использовать несколько типов построения:

2.1. по координатам (требуется задать координаты точек [X1](istraightaxis_x1.html); [Y1](istraightaxis_y1.html), [X2](istraightaxis_x2.html); [Y2](istraightaxis_y2.html)).

2.2. По точке 1 ([X1](istraightaxis_x1.html); [Y1](istraightaxis_y1.html)), длине [Length](istraightaxis_length.html) и углу [Angle](istraightaxis_angle.html),

2.3. По точке 2 ([X2](istraightaxis_x2.html); [Y2](istraightaxis_y2.html)), длине [Length](istraightaxis_length.html) и углу [Angle](istraightaxis_angle.html) относительно точки 1.

3\. После задания параметров оси требуется вызвать метод [IDrawingObject::Update](idrawingobject_update.html).

4\. При изменении параметров зависимые параметры пересчитываются после вызова метода [IDrawingObject::Update](idrawingobject_update.html).

Подразделы:

[IStraightAxis - свойства ](istraightaxis_props.html)
