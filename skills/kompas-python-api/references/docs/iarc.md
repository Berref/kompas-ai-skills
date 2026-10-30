# Интерфейс IArc

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) |  Scroll [ [ [ ](iarc_props.html "К следующему разделу")](bb2333035.html "На уровень выше")](istraightslots_add.html "К предыдущему разделу")  
---|---  
  
Интерфейс дуги.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[IDrawingObject](idrawingobject.html)

[IArc](iarc.html)

Описание:

Интерфейс позволяет получить дугу.

Примечание:

1\. Интерфейс можно получить у коллекции дуг, используя свойство [IArcs::Arc](iarcs_arc.html) или метод [IArcs::Add](iarcs_add.html).

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

[IArc - свойства ](iarc_props.html)
