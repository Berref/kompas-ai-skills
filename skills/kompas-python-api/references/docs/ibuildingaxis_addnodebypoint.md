# AddNodeByPoint - Добавить узел марки по координатам

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения для строительства ](bb2362006.html) > [Интерфейс IBuildingAxis ](ibuildingaxis.html) > [IBuildingAxis - методы ](ibuildingaxis_methods.html) |  Scroll [ [ [ ](ibuildingaxis_getinsertionpoints.html "К следующему разделу")](ibuildingaxis_methods.html "На уровень выше")](ibuildingaxis_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ibuildingaxis.html)

Синтаксис Automation:

LPDISPATCH AddNodeByPoint( ksMarkNodeEnum Type,

double X,

double Y );

Синтаксис COM:

HRESULT AddNodeByPoint( ksMarkNodeEnum Type,

double X,

double Y,

IMarkNode ** PVal );

Входные параметры:

Type | \- тип узла для марки из [ksMarkNodeEnum](ksmarknodeenum.html),  
---|---  
X, Y | \- координаты для подключения узла.  
  
Возвращаемое значение:

Указатель на интерфейс [IMarkNode](imarknode.html) | \- если узел подключен,  
---|---  
NULL | \- в случае неудачи.  
  
Примечание:

Значения координат и направлений пересчитываются в зависимости от текущей системы координат для объекта, задаваемой параметром [IDrawingObject::DrawingObjectParamType](idrawingobject_drawingobjectparamtype.html).

Подразделы:

(отсутствуют)
