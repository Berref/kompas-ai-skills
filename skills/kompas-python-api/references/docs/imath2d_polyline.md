# PolyLine - Временная математическая полилиния

[API интерфейсов. Версия 7](applicate.html) > [2D математика ](mathematick.html) > [Интерфейс IMath2D ](imath2d.html) > [IMath2D - методы ](imath2d_methods.html) |  Scroll [ [ [ ](imath2d_rotate.html "К следующему разделу")](imath2d_methods.html "На уровень выше")](imath2d_nurbs.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imath2d.html)

Синтаксис Automation:

LPDISPATCH PolyLine( VARIANT Points,

BOOL Closed );

Синтаксис COM:

HRESULT PolyLine( VARIANT Points,

BOOL Closed,

ICurve2D ** Result );

Входные параметры:

Points | \- массив SAFEARRAY | VT_R8 координат точек полилинии,  
---|---  
Closed | \- признак замкнутости кривой.  
  
Возвращаемое значение:

| \- указатель на интерфейс математической кривой [ICurve2D](icurve2d.html).  
---|---  
  
Примечание:

Метод позволяет создать временную математическую полилинию.

Подразделы:

(отсутствуют)
