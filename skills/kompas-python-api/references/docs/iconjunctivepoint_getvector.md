# GetVector - Получить вектора направлений главных осей

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Точки ](bc2284065.html) > [Интерфейс IPoint3D ](ipoint3d.html) > [Наследники - вспомогательные объекты ](bc2284488.html) > [Интерфейс IConjunctivePoint ](iconjunctivepoint.html) > [IConjunctivePoint - методы ](iconjunctivepoint_methods.html) |  Scroll [ [ [ ](iconjunctivepoint_initbymatrix3d.html "К следующему разделу")](iconjunctivepoint_methods.html "На уровень выше")](iconjunctivepoint_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iconjunctivepoint.html)

Синтаксис Automation:

BOOL GetVector( ksObj3dTypeEnum Axis, double * X, double * Y, double * Z );

Синтаксис COM:

HRESULT GetVector( ksObj3dTypeEnum Axis, double * X, double * Y, double * Z, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Axis | \- ось.  
---|---  
  
Выходные параметры:

X | \- координата по X,  
---|---  
Y | \- координата по Y,  
Z | \- координата по Z.  
  
Подразделы:

(отсутствуют)
