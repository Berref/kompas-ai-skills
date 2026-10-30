# GetMetricLength - Получить метрическую длину кривой

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Компонент сборки (деталь или подсборка). Интерфейсы ksPart и IPart ](kspart.html) > [Математическая кривая в трехмерном пространстве (Интерфейсы ksCurve3D, ICurve3D) ](kscurve3d.html) > [ICurve3D - методы ](kscurve3d_methods.html) |  Scroll [ [ [ ](kscurve3d_getnormal.html "К следующему разделу")](kscurve3d_methods.html "На уровень выше")](kscurve3d_getlength.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kscurve3d.html)

Синтаксис Automation:

double GetMetricLength (double startParam, double endParam);

Синтаксис COM:

double GetMetricLength (double startParam, double endParam);

Входные параметры:

startParam | \- начальное значение параметра T в параметрическом представлении кривой,  
---|---  
endParam | \- конечное значение параметра T в параметрическом представлении кривой.  
  
Возвращаемое значение:

метрическая длина кривой | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Граничные значения параметра T получаются при помощи методов [GetParamMin](kscurve3d_getparammin.html) и [GetParamMax](kscurve3d_getparammax.html).

Подразделы:

(отсутствуют)
