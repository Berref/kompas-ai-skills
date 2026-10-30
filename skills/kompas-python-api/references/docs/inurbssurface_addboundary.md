# AddBoundary - Добавить границу для NURBS-поверхности

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Поверхности ](bc2288197.html) > [Интерфейс ISurfaceContainer ](isurfacecontainer.html) > [ISurfaceContainer - свойства ](isurfacecontainer_props.html) > [Интерфейс INurbsSurface ](inurbssurface.html) > [INurbsSurface - методы ](inurbssurface_methods.html) |  Scroll [ [ [ ](inurbssurface_deleteboundary.html "К следующему разделу")](inurbssurface_methods.html "На уровень выше")](inurbssurface_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](inurbssurface.html)

Синтаксис Automation:

BOOL AddBoundary( BOOL UV, BOOL Closed, long Degree, VARIANT Points, VARIANT Weights, VARIANT Knots, double TMin, double TMax );

Синтаксис COM:

HRESULT AddBoundary( BOOL UV, BOOL Closed, long Degree, VARIANT Points, VARIANT Weights, VARIANT Knots, double TMin, double TMax, BOOL * Res );

Выходные параметры:

UV | \- TRUE параметры кривой заданы в UV координатах поверхности (2D-Nurbs), \- FALSE параметры заданы 3D координатами (3D-Nurbs). При создании границы выполняется проецирование 3D кривой на поверхность,  
---|---  
Closed | \- TRUE замкнутое представление \- FALSE - разомкнутое представление,  
Degree | \- порядок NURBS (степень полинома + 1), от 3 до 10,  
Points | \- массив SafeArray точек VT_ARRAY | VT_R8,  
Weights | \- веса,  
Knots | \- массив SafeArray узлов точек VT_ARRAY | VT_R8,  
TMin, TMax | \- минимальный и максимальный параметры кривой.  
  
Возвращаемое значение:

TRUE | \- в случае удачи.  
---|---  
  
Примечание:

Позволяет добавить границу для поверхности.

Граница не должна пересекаться с другими границами данной поверхности.

Подразделы:

(отсутствуют)
