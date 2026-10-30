# GetNodeByPoint - Получить узел марки по координатам

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения для строительства ](bb2362006.html) > [Интерфейс IBuildingAxis ](ibuildingaxis.html) > [IBuildingAxis - методы ](ibuildingaxis_methods.html) |  Scroll [ [ [ ](iarcaxis.html "К следующему разделу")](ibuildingaxis_methods.html "На уровень выше")](ibuildingaxis_getinsertionpoints.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ibuildingaxis.html)

Синтаксис Automation:

LPDISPATCH GetNodeByPoint( double X, double Y, double Limit );

Синтаксис COM:

HRESULT GetNodeByPoint( double X, double Y, double Limit, IMarkNode ** PVal );

Входные параметры:

X, Y | \- координаты точки,  
---|---  
Limit | \- максимальное расстояние от точки до узла при поиске.  
  
Возвращаемое значение:

Указатель на интерфейс [IMarkNode](imarknode.html) | \- если узел найден,  
---|---  
NULL | \- в случае неудачи.  
  
Примечание:

1\. Значения координат и направлений пересчитываются в зависимости от текущей системы координат для объекта, задаваемой параметром [IDrawingObject::DrawingObjectParamType](idrawingobject_drawingobjectparamtype.html)

2\. Подключить узел можно только к точкам подключения, координаты которых возвращаются функциями [IBuildingAxis::GetInsertionPoints](ibuildingaxis_getinsertionpoints.html) и [IMarkNode::GetInsertionPoints](imarknode_getinsertionpoints.html).

3\. После добавления узла координаты и список доступных точек для подключения новых узлов может измениться.

Подразделы:

(отсутствуют)
