# Интерфейс IArcAxis

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения для строительства ](bb2362006.html) |  Scroll [ [ [ ](iarcaxis_props.html "К следующему разделу")](bb2362006.html "На уровень выше")](ibuildingaxis_getnodebypoint.html "К предыдущему разделу")  
---|---  
  
Интерфейс дуговой координационной оси.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[IDrawingObject](idrawingobject.html)

[IBuildingAxis](ibuildingaxis.html)

[IArcAxis](iarcaxis.html)

Описание:

Интерфейс позволяет получать и изменять свойства дуговой строительной оси.

Примечание:

1\. Получить интерфейс строительной оси можно, используя методы коллекции строительных осей [IBuildingAxes::BuildingAxis](ibuildingaxes_buildingaxis.html), [IBuildingAxes::Add](ibuildingaxes_add.html).

2\. При создании дуговой оси можно использовать несколько способов построения.

•[По координатам](arcvar1.html),

•[По трем точкам](arcvar2.html),

•[По углам](arcvar3.html),

•[По точке и углу](arcvar4.html),

•[По углу, точке и радиусу](arcvar5.html),

•[По конечным точкам и углу](arcvar6.html),

•[Плавающий центр, вариант 1](arcvar7.html),

•[Плавающий центр, вариант 2](arcvar8.html).

3\. После задания параметров оси требуется вызвать метод [IDrawingObject::Update](idrawingobject_update.html).

4\. При изменении параметров зависимые параметры пересчитываются после вызова метода [IDrawingObject::Update](idrawingobject_update.html).

Подразделы:

[IArcAxis - свойства ](iarcaxis_props.html)
