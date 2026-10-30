# GetParamVertex - Получить параметры вершины

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс ICurveVertexParam ](icurvevertexparam.html) > [ICurveVertexParam - методы ](icurvevertexparam_methods.html) |  Scroll [ [ [ ](icurvevertexparam_setparambydistance.html "К следующему разделу")](icurvevertexparam_methods.html "На уровень выше")](icurvevertexparam_getparambydistance.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icurvevertexparam.html)

Синтаксис Automation:

BOOL GetParamVertex( double * x,

double * y,

double * z,

double * value );

Синтаксис Automation:

HRESULT GetParamVertex( [out] double * x,

[out] double * y,

[out] double * z,

[out] double * value,

[out, retval] VARIANT_BOOL * PVal );

Выходные параметры:

x, y, z | \- пространственные координаты вершины,  
---|---  
value | \- радиус для точки ломаной и вес для сплайна.  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
