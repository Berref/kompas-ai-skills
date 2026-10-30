# AddStroke - Добавить штрих

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения для строительства ](bb2362006.html) > [Интерфейс ICutUnitMarking ](icutunitmarking.html) > [ICutUnitMarking - методы ](icutunitmarking_methods.html) |  Scroll [ [ [ ](icutunitmarking_deletestroke.html "К следующему разделу")](icutunitmarking_methods.html "На уровень выше")](icutunitmarking_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icutunitmarking.html)

Синтаксис Automation:

BOOL AddStoke( double X,

double Y,

double Length );

Синтаксис COM:

HRESULT AddStoke( double X,

double Y,

double Length,

BOOL * Result );

Входные параметры:

X, Y | \- координаты точки привязки штриха,  
---|---  
Length | \- длина.  
  
Возвращаемое значение:

TRUE | \- штрих добавлен,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Значения координат зависят от текущей системы координат для объекта, задаваемой параметром [IDrawingObject::DrawingObjectParamType](idrawingobject_drawingobjectparamtype.html)

Подразделы:

(отсутствуют)
