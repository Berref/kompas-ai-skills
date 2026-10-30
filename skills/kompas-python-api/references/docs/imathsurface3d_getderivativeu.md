# GetDerivativeU - Получить первую производную по U

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Поверхности ](bc2288197.html) > [Интерфейс IMathSurface3D ](imathsurface3d.html) > [IMathSurface3D - методы ](imathsurface3d_methods.html) |  Scroll [ [ [ ](imathsurface3d_getderivativev.html "К следующему разделу")](imathsurface3d_methods.html "На уровень выше")](imathsurface3d_getconeparam.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imathsurface3d.html)

Синтаксис Automation:

BOOL GetDerivativeU( double ParamU, double ParamV, double * X, double * Y, double * Z );

Синтаксис COM:

HRESULT GetDerivativeU( double ParamU, double ParamV, double * X, double * Y, double * Z, BOOL * Result ) ;

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

ParamU, ParamV | \- значения параметров U и V в параметрическом представлении поверхности.  
---|---  
  
Выходные параметры:

X, Y, Z | \- первая производная по U.  
---|---  
  
Подразделы:

(отсутствуют)
