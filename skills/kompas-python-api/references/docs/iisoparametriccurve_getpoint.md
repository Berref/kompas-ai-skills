# GetPoint - Получить координату точки на поверхности

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс IIsoparametricCurve ](iisoparametriccurve.html) > [IIsoparametricCurve - методы ](iisoparametriccurve_methods.html) |  Scroll [ [ [ ](iisoparametriccurve_setpoint.html "К следующему разделу")](iisoparametriccurve_methods.html "На уровень выше")](iisoparametriccurve_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iisoparametriccurve.html)

Синтаксис Automation:

BOOL GetPoint( double * X, double * Y, double * Z );

Синтаксис COM:

HRESULT GetPoint( double * X, double * Y, double * Z, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Выходные параметры:

X | \- координата точки по X,  
---|---  
Y | \- координата точки по Y,  
Z | \- координата точки по Z.  
  
Подразделы:

(отсутствуют)
