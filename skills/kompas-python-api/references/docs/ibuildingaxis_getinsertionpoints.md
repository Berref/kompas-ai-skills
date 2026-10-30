# GetInsertionPoints - Получить координаты точек для вставки дополнительных элементов

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения для строительства ](bb2362006.html) > [Интерфейс IBuildingAxis ](ibuildingaxis.html) > [IBuildingAxis - методы ](ibuildingaxis_methods.html) |  Scroll [ [ [ ](ibuildingaxis_getnodebypoint.html "К следующему разделу")](ibuildingaxis_methods.html "На уровень выше")](ibuildingaxis_addnodebypoint.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ibuildingaxis.html)

Синтаксис Automation:

BOOL GetInsertionPoints( BOOL First,

VARIANT * Points,

VARIANT * Directions,

VARIANT * Nodes,

BOOL * RetVal );

Синтаксис COM:

HRESULT GetInsertionPoints( BOOL First,

VARIANT * Points,

VARIANT * Directions,

VARIANT * Nodes,

BOOL * RetVal );

Входные параметры:

First | \- вернуть координаты точек TRUE - для первого ответвления, FALSE - для второго ответвления.  
---|---  
  
Выходные параметры:

Points | \- массив SafeArray типа VT_ARRAY | VT_R8 координат точек для подключения дополнительных узлов марок,  
---|---  
Directions | \- массив SafeArray типа VT_ARRAY | VT_R8 направлений (углы относительно центра родительского узла),  
Nodes | \- массив SafeArray типа VT_ARRAY | VT_DISPATCH родительские узлы для точек подключения.  
  
Возвращаемое значение:

TRUE | \- координаты получены,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

1\. Параметры Points, Directions и Nodes не являются обязательными. В функцию достаточно передать один из указателей на VARIANT.

2\. Массивы являются согласованными.

Координаты точек в массиве Points лежат в следующей последовательности:  
x0, y0, x1, y1, ...xi, yi

Направления в масиве Directions лежат в последовательности:  
angle0, angle1, ...anglei

В массиве Nodes лежат указатели на интерфейсы узлов для вставок марок [IMarkNode](imarknode.html).

3\. У узла может быть от 1 до 3 точек для подключения дополнительных узлов в зависимости от типа узла и его расположения. Так как массивы координат и узлов должны быть согласованы, то один и тот же указатель на интерфейс может встречаться в массиве более одного раза.

4\. Значения координат и направлений пересчитываются в зависимости от текущей системы координат для объекта, задаваемой параметром [IDrawingObject::DrawingObjectParamType](idrawingobject_drawingobjectparamtype.html).

5\. Если возвращается один объект, то тип VARIANT-а будет VT_DISPATCH, если возвращается несколько объектов, то тип VARIANT-а будет VT_ARRAY | VT_DISPATCH.

Подразделы:

(отсутствуют)
