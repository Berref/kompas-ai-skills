# GetParamByDistance - Получить расстояние и радиус (для ломаной) или вес (для сплайна)

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс ICurveVertexParam ](icurvevertexparam.html) > [ICurveVertexParam - методы ](icurvevertexparam_methods.html) |  Scroll [ [ [ ](icurvevertexparam_getparamvertex.html "К следующему разделу")](icurvevertexparam_methods.html "На уровень выше")](icurvevertexparam_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icurvevertexparam.html)

Синтаксис Automation:

BOOL GetParamByDistance( double * Distance,

double * Value );

Синтаксис Automation:

HRESULT GetParamByDistance( [out] double * Distance,

[out] double * Value,

[out, retval] VARIANT_BOOL * PVal );

Выходные параметры:

Distance | \- расстояние до предыдущей вершины,  
---|---  
value | \- радиус для точки ломаной и вес для сплайна.  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

1\. Для вершины с индексом 0 расстояние выдается до вершины с индексом 1. Для остальных вершин расстояние выдается до вершины с индексом на 1 меньше, чем у данной вершины.

2\. Получить расстояние можно для любого типа построения.

3\. Установить расстояние можно, если тип построения ksLineBuildingType не равен ksLBTByPoint и не равен ksLBTByPoint3DParams.

Подразделы:

(отсутствуют)
