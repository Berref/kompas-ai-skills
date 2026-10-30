# GetDerivativeU - Получить первую производную по U

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Математическая поверхность в трехмерном пространстве ](bz1748754.html) > [Интерфейсы ksSurface, ISurface ](kssurface.html) > [ISurface - методы ](kssurface_methods.html) |  Scroll [ [ [ ](kssurface_getderivativev.html "К следующему разделу")](kssurface_methods.html "На уровень выше")](kssurface_getboundaryuvnurbs.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kssurface.html)

Синтаксис Automation:

BOOL GetDerivativeU (double paramU, double paramV, double * x, double *y, double *z);

Синтаксис COM:

BOOL GetDerivativeU (double paramU, double paramV, double * x, double *y, double *z);

Входные параметры:

paramU, paramV | \- значения параметров U и V в параметрическом представлении поверхности.  
---|---  
  
Выходные параметры:

x, y, z | \- первая производная по U.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Граничные значения параметров U и V получаются при помощи методов [GetParamUMin](kssurface_getparamumin.html) и [GetParamUMax](kssurface_getparamumax.html) и [GetParamVMin](kssurface_getparamvmin.html) и [GetParamVMax](kssurface_getparamvmax.html). Координаты точки возвращаются в системе координат компонента.

Подразделы:

(отсутствуют)
