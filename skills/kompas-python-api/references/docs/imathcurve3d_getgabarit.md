# GetGabarit - Выдать габарит кривой

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelCurve3D ](imodelcurve3d.html) > [Интерфейс IMathCurve3D ](imathcurve3d.html) > [IMathCurve3D - методы ](imathcurve3d_metods.html) |  Scroll [ [ [ ](imathcurve3d_getellipseparam.html "К следующему разделу")](imathcurve3d_metods.html "На уровень выше")](imathcurve3d_getderivativettt.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imathcurve3d.html)

Синтаксис Automation:

BOOL GetGabarit( double * X1, double * Y1, double * Z1, double * X2, double * Y2, double * Z2 ) ;

Синтаксис COM:

HRESULT GetGabarit( double * X1, double * Y1, double * Z1, double * X2, double * Y2, double * Z2, BOOL * Result ) ;

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

X1, Y1, Z1, X2, Y2, Z2 | \- координаты вершин габаритного параллелепипеда.  
---|---  
  
Примечание:

Координаты вершин параллелепипеда возвращаются в системе координат компонента.

Подразделы:

(отсутствуют)
