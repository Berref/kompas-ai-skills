# GetCenterPoint - Получить координаты центра

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Оформление ](bc2273863.html) > [Размеры ](bc2274179.html) > [Интерфейс IAngleDimension3D ](iangledimension3d.html) > [IAngleDimension3D - методы ](iangledimension3d_methods.html) |  Scroll [ [ [ ](iangledimension3d_inverse.html "К следующему разделу")](iangledimension3d_methods.html "На уровень выше")](iangledimension3d_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iangledimension3d.html)

Синтаксис Automation:

BOOL GetCenterPoint( double * X,

double * Y,

double * Z );

Синтаксис COM:

HRESULT GetCenterPoint( double * X,

double * Y,

double * Z,

BOOL * Result );

Выходные параметры:

X, Y, Z | \- координаты точки на оси поверхности или центр окружности или дуги.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
