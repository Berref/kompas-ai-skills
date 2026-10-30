# GetCentre - Получить центр кривой

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelCurve3D ](imodelcurve3d.html) > [Интерфейс IMathCurve3D ](imathcurve3d.html) > [IMathCurve3D - методы ](imathcurve3d_metods.html) |  Scroll [ [ [ ](imathcurve3d_getweightcentre.html "К следующему разделу")](imathcurve3d_metods.html "На уровень выше")](imathcurve3d_calculatepolygon.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imathcurve3d.html)

Синтаксис Automation:

BOOL GetCentre( double * X, double * Y, double * Z );

Синтаксис COM:

HRESULT GetCentre( double * X, double * Y, double * Z, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Выходные параметры:

X, Y, Z | \- координаты центра кривой.  
---|---  
  
Подразделы:

(отсутствуют)
