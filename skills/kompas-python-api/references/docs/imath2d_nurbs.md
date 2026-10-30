# Nurbs - Временная математическая Nurbs-кривая

[API интерфейсов. Версия 7](applicate.html) > [2D математика ](mathematick.html) > [Интерфейс IMath2D ](imath2d.html) > [IMath2D - методы ](imath2d_methods.html) |  Scroll [ [ [ ](imath2d_polyline.html "К следующему разделу")](imath2d_methods.html "На уровень выше")](imath2d_movepoint.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imath2d.html)

Синтаксис Automation:

LPDISPATCH Nurbs( BOOL Closed,

long Degree,

VARIANT Points,

VARIANT Weights,

VARIANT Knots );

Синтаксис COM:

HRESULT Nurbs( BOOL Closed,

long Degree,

VARIANT Points,

VARIANT Weights,

VARIANT Knots,

ICurve2D ** Result );

Входные параметры:

Closed | \- признак замкнутости кривой,  
---|---  
Degree | \- порядок кривой,  
Points | \- массив SAFEARRAY | VT_R8 координат точек кривой,  
Weight | \- массив SAFEARRAY | VT_R8 весов точек,  
Knots | \- массив SAFEARRAY | VT_R8 узлов сплайна.  
  
Возвращаемое значение:

| \- указатель на интерфейс математической кривой [ICurve2D](icurve2d.html).  
---|---  
  
Примечание:

Метод позволяет создать временную математическую Nurbs-кривую.

Подразделы:

(отсутствуют)
