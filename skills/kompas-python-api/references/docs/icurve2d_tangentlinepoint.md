# TangentLinePoint - Точки касания кривой и прямой из заданной точки

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс ICurve2D ](icurve2d.html) > [ICurve2D - методы ](icurve2d_methods.html) |  Scroll [ [ [ ](bb2344629.html "К следующему разделу")](icurve2d_methods.html "На уровень выше")](icurve2d_tangent.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icurve2d.html)

Синтаксис Automation:

VARIANT TangentLinePoint( double X,

double Y );

Синтаксис COM:

HRESULT TangentLinePoint( double X,

double Y,

VARIANT * Result );

Входные параметры:

X, Y | \- координаты точки.  
---|---  
  
Возвращаемое значение:

| \- Массив SAFEARRAY точек на кривой VT_ARRAY | VT_R8.  
---|---  
  
Примечание:

Метод позволяет получить координаты точек касания кривой и прямой из заданной точки.

Подразделы:

(отсутствуют)
