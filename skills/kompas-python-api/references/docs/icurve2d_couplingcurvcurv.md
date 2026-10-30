# CouplingCurvCurv - Расчет скруглений для двух кривых

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс ICurve2D ](icurve2d.html) > [ICurve2D - методы ](icurve2d_methods.html) |  Scroll [ [ [ ](icurve2d_getdistancepointpoint.html "К следующему разделу")](icurve2d_methods.html "На уровень выше")](icurve2d_calculatepolygonbystep.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icurve2d.html)

Синтаксис Automation:

VARIANT CouplingCurvCurv( LPDISPATCH * Curve2,

double Radius );

Синтаксис COM:

HRESULT CouplingCurvCurv( ICurve2D * Curve2,

double Radius,

VARIANT * Result );

Входные параметры:

Curve2 | \- указатель на интерфейс второй кривой,  
---|---  
Radius | \- радиус скругления.  
  
Возвращаемое значение:

| \- Массив SAFEARRAY структуры сопряжения VT_ARRAY | VT_R8. Данные возвращаются в следующей последовательности: • double xc, yc - координаты центра сопрягающей окружности, • double x1, y1 - координаты первой точки сопряжения, • double x2, y2 - координаты второй точки сопряжения.  
---|---  
  
Примечание:

Метод позволяет рассчитать скругления для двух кривых.

Подразделы:

(отсутствуют)
