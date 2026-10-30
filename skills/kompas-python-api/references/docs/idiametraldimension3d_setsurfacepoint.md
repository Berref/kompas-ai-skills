# SetSurfacePoint - Установить точку пересечения размера с поверхностью или ребром

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Оформление ](bc2273863.html) > [Размеры ](bc2274179.html) > [Интерфейс IDiametralDimension3D ](idiametraldimension3d.html) > [IDiametralDimension3D - методы ](idiametraldimension3d_methods.html) |  Scroll [ [ [ ](iradialdimension3d.html "К следующему разделу")](idiametraldimension3d_methods.html "На уровень выше")](idiametraldimension3d_setcenterpoint.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imodelobject.html)

Синтаксис Automation:

BOOL SetSurfacePoint( double X,

double Y,

double Z );

Синтаксис COM:

HRESULT SetSurfacePoint( double X,

double Y,

double Z,

BOOL * Result );

Входные параметры:

X, Y, Z | \- координаты точки.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Функция позволяет задавать новое положение размера относительно грани или ребра. При указании точки на поверхности точка центра пересчитается.

Подразделы:

(отсутствуют)
