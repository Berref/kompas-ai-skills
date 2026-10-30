# Интерфейс ICircleAxis

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения для строительства ](bb2362006.html) |  Scroll [ [ [ ](icircleaxis_props.html "К следующему разделу")](bb2362006.html "На уровень выше")](iarcaxis_y3.html "К предыдущему разделу")  
---|---  
  
Интерфейс круговой координационной оси.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[IDrawingObject](idrawingobject.html)

[IBuildingAxis](ibuildingaxis.html)

[ICircleAxis](icircleaxis.html)

Описание:

Интерфейс позволяет получать и изменять свойства круговой строительной оси.

Примечание:

1\. Получить интерфейс строительной оси можно, используя методы коллекции строительных осей [IBuildingAxes::BuildingAxis](ibuildingaxes_buildingaxis.html), [IBuildingAxes::Add](ibuildingaxes_add.html).

2\. При создании дуговой оси необходимо задать следующие параметры:

•координаты центра [XC](icircleaxis_xc.html); [YC](icircleaxis_yc.html),

•радиус [Radius](icircleaxis_radius.html).

3\. После задания параметров оси требуется вызвать метод [IDrawingObject::Update](idrawingobject_update.html).

4\. При изменении параметров зависимые параметры пересчитываются после вызова метода [IDrawingObject::Update](idrawingobject_update.html).

Подразделы:

[ICircleAxis - свойства ](icircleaxis_props.html)
