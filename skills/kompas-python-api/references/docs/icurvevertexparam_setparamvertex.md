# SetParamVertex - Установить параметры вершины

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс ICurveVertexParam ](icurvevertexparam.html) > [ICurveVertexParam - методы ](icurvevertexparam_methods.html) |  Scroll [ [ [ ](icurvevertexparam_update.html "К следующему разделу")](icurvevertexparam_methods.html "На уровень выше")](icurvevertexparam_setparambyvertex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icurvevertexparam.html)

Синтаксис Automation:

BOOL SetParamVertex( double x,

double y,

double z,

double value );

Синтаксис Automation:

HRESULT SetParamVertex( [in] double x,

[in] double y,

[in] double z,

[in] double value,

[out, retval] VARIANT_BOOL * PVal );

Входные параметры:

x, y, z | \- пространственные координаты вершины,  
---|---  
value | \- радиус для точки ломаной и вес для сплайна.  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения.  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
