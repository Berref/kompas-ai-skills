# Tangent - Касательные для двух кривых

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс ICurve2D ](icurve2d.html) > [ICurve2D - методы ](icurve2d_methods.html) |  Scroll [ [ [ ](icurve2d_tangentlinepoint.html "К следующему разделу")](icurve2d_methods.html "На уровень выше")](icurve2d_pointprojection.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icurve2d.html)

Синтаксис Automation:

BOOL Tangent( LPDISPATCH * Curve2,

VARIANT * Curve1Points,

VARIANT * Curve2Points );

Синтаксис COM:

HRESULT Tangent( ICurve2D * Curve2,

VARIANT * Curve1Points,

VARIANT * Curve2Points,

BOOL * Result );

Входные параметры:

Curve2 | \- указатель на интерфейс второй кривой.  
---|---  
  
Выходные параметры:

Curve1Points | \- массив SAFEARRAY точек на первой кривой VT_ARRAY | VT_R8,  
---|---  
Curve2Points | \- массив SAFEARRAY точек на второй кривой VT_ARRAY | VT_R8.  
  
Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет получить касательные для двух кривых.

Подразделы:

(отсутствуют)
