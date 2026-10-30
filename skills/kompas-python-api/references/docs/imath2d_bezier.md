# Bezier - Временная математическая кривая Безье

[API интерфейсов. Версия 7](applicate.html) > [2D математика ](mathematick.html) > [Интерфейс IMath2D ](imath2d.html) > [IMath2D - методы ](imath2d_methods.html) |  Scroll [ [ [ ](imath2d_circle.html "К следующему разделу")](imath2d_methods.html "На уровень выше")](imath2d_arc.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imath2d.html)

Синтаксис Automation:

LPDISPATCH Bezier( BOOL Closed,

BOOL AllPoints,

VARIANT Points );

Синтаксис COM:

HRESULT Bezier( BOOL Closed,

BOOL AllPoints,

VARIANT Points,

ICurve2D ** Result );

Входные параметры:

Closed | \- признак замкнутости кривой,  
---|---  
AllPoints | \- TRUE - в массиве присутствуют все точки узла, \- FALSE - в массиве присутствуют только опорные точки,  
Points | \- массив SAFEARRAY | VT_R8 координат точек кривой.  
  
Возвращаемое значение:

| \- указатель на интерфейс математической кривой [ICurve2D](icurve2d.html).  
---|---  
  
Примечание:

Метод позволяет создать временную математическую кривую Безье.

Подразделы:

(отсутствуют)
