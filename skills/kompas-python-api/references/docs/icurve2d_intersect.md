# Intersect - Пересечение двух кривых

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс ICurve2D ](icurve2d.html) > [ICurve2D - методы ](icurve2d_methods.html) |  Scroll [ [ [ ](icurve2d_intersectex.html "К следующему разделу")](icurve2d_methods.html "На уровень выше")](icurve2d_getselfintersectpointsex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icurve2d.html)

Синтаксис Automation:

VARIANT Intersect( LPDISPATCH * Curve2 );

Синтаксис COM:

HRESULT Intersect( ICurve2D * Curve2,

VARIANT * Result );

Входные параметры:

Curve2 | \- указатель на интерфейс кривой, которая пересекает данную кривую.  
---|---  
  
Возвращаемое значение:

| \- Массив SAFEARRAY точек пересечений VT_ARRAY | VT_R8  
---|---  
  
Примечание:

Метод позволяет получить координаты точек пересечения двух кривых.

Подразделы:

(отсутствуют)
