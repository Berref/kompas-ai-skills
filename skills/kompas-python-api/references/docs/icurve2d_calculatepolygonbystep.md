# CalculatePolygonByStep - Выдать массив отрисовочных точек с заданной стрелкой прогиба

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс ICurve2D ](icurve2d.html) > [ICurve2D - методы ](icurve2d_methods.html) |  Scroll [ [ [ ](icurve2d_couplingcurvcurv.html "К следующему разделу")](icurve2d_methods.html "На уровень выше")](icurve2d_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icurve2d.html)

Синтаксис Automation:

VARIANT CalculatePolygonByStep( double sag );

Синтаксис COM:

HRESULT CalculatePolygonByStep( double sag,VARIANT * Result );

Входные параметры:

Sag | \- максимальная величина прогиба.  
---|---  
  
Возвращаемое значение:

| Массив SAFEARRAY точек VT_ARRAY | VT_R8.  
---|---  
  
Примечание:

Метод позволяет получить массив отрисовочных точек с заданной стрелкой прогиба.

Подразделы:

(отсутствуют)
