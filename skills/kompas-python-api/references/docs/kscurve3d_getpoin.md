# GetPoint - Получить координаты точки на кривой

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Математическая кривая в трехмерном пространстве (Интерфейсы ksCurve3D, ICurve3D) ](kscurve3d.html) > [ICurve3D - методы ](kscurve3d_methods.html) |  Scroll [ [ [ ](kscurve3d_gettangentvecto.html "К следующему разделу")](kscurve3d_methods.html "На уровень выше")](kscurve3d_getparammax.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kscurve3d.html)

Синтаксис Automation:

BOOL GetPoint (double paramT, double * x, double *y, double *z);

Синтаксис COM:

BOOL GetPoint (double paramT, double * x, double *y, double *z);

Входной параметр:

paramT | \- значение параметра T в параметрическом представлении кривой.  
---|---  
  
Выходные параметры:

x, y, z | \- координаты точки на кривой.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Граничные значения параметра T получаются при помощи методов [GetParamMin](kscurve3d_getparammin.html) и [GetParamMax](kscurve3d_getparammax.html). Координаты точки возвращаются в системе координат компонента.

Подразделы:

(отсутствуют)
