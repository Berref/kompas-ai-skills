# GetNurbs3DParams - Параметры Nurbs-представления кривой

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelCurve3D ](imodelcurve3d.html) > [Интерфейс IMathCurve3D ](imathcurve3d.html) > [IMathCurve3D - методы ](imathcurve3d_metods.html) |  Scroll [ [ [ ](imathcurve3d_getpoint.html "К следующему разделу")](imathcurve3d_metods.html "На уровень выше")](imathcurve3d_getnormal.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imathcurve3d.html)

Синтаксис Automation:

BOOL GetNurbs3DParams( BOOL Closed, long * Degree, double * ParamMin, double * ParamMax, VARIANT * Points, VARIANT * Weights, VARIANT * Knots ) ;

Синтаксис COM:

HRESULT GetNurbs3DParams( BOOL Closed, long * Degree, double * ParamMin, double * ParamMax, VARIANT * Points, VARIANT * Weights, VARIANT * Knots, BOOL * Result ) ;

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Closed | \- TRUE - Вернуть параметры для замкнутого представления  
\- FALSE - Вернуть параметры для разомкнутого представления.  
---|---  
  
Выходные параметры:

Degree | \- степень,  
---|---  
ParamMin | \- минимальный параметр кривой,  
ParamMax | \- максимальный параметр кривой,  
Points | \- координаты точек в виде массива VT_ARRAY | VT_R8,  
Weights | \- веса в точках в виде массива VT_ARRAY | VT_R8,  
Knots | \- массив VT_ARRAY | VT_R8 узлов сплайна.  
  
Версия КОМПАС v22

Подразделы:

(отсутствуют)
