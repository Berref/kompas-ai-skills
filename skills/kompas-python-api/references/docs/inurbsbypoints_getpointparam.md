# GetPointParam - Получить параметры точек сплайна

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс INurbsByPoints ](inurbsbypoints.html) > [INurbsByPoints - методы ](inurbsbypoints_methods.html) |  Scroll [ [ [ ](ipoint.html "К следующему разделу")](inurbsbypoints_methods.html "На уровень выше")](inurbsbypoints_addpointbyparam.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](inurbsbypoints.html)

Синтаксис Automation:

BOOL GetPointParam( long Index, double * X, double * Y,

ksNurbsByPointsPointConstraintsEnum * ConstraintsType, double * DerivativeLenght,

double * DerivativeAngle, double * Curvature );

Синтаксис COM:

HRESULT GetPointParam( long Index, double * X, double * Y,

ksNurbsByPointsPointConstraintsEnum * ConstraintsType, double * DerivativeLenght,

double * DerivativeAngle, double * Curvature, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

X | \- координата точки по X,  
---|---  
Y | \- координата точки по Y,  
ConstraintsType | \- вариант управления точкой сплайна,  
DerivativeLenght | \- длина вектора производной,  
DerivativeAngle | \- угол вектора производной,  
Curvature | \- величина кривизны.  
  
Подразделы:

(отсутствуют)
