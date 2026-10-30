# GetInsertionPoints - Получить координаты точек для вставки дополнительных элементов

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения для строительства ](bb2362006.html) > [Интерфейс IMarkNode ](imarknode.html) > [IMarkNode - методы ](imarknode_methods.html) |  Scroll [ [ [ ](bb2391397.html "К следующему разделу")](imarknode_methods.html "На уровень выше")](imarknode_delete.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imarknode.html)

Синтаксис Automation:

BOOL GetInsertionPoints( BOOL LeftJut,

VARIANT * Points,

VARIANT * Directions );

Синтаксис COM:

HRESULT GetInsertionPoints( BOOL LeftJut,

VARIANT * Points,

VARIANT * Directions, BOOL * RetVal );

Входные параметры:

LeftJut | \- TRUE координаты точек для левого ответвления, \- FALSE - для правого. Для круглой оси нужно передавать LeftJut = TRUE.  
---|---  
  
Выходные параметры:

Points | \- массив SafeArray типа VT_ARRAY | VT_R8 координат точек для подключения дополнительных узлов марок,  
---|---  
Directions | \- массив SafeArray типа VT_ARRAY | VT_R8 направлений (углы относительно центра родительского узла).  
  
Возвращаемое значение:

TRUE | \- координаты получены,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

1\. Параметры Points, Directions не являются обязательными.

2\. В функцию достаточно передать один из указателей на VARIANT.

3\. Массивы являются согласованными.

4\. Координаты точек в массиве Points лежат в следующей последовательности:  
x0, y0, x1, y1, ...xi, yi.

5\. Направления в массиве Directions лежат в последовательности:  
angle0, angle1, ...anglei.

6\. Значения координат и направлений пересчитываются в зависимости от текущей системы координат для объекта, задаваемой параметром [IDrawingObject::DrawingObjectParamType](idrawingobject_drawingobjectparamtype.html)

Подразделы:

(отсутствуют)
