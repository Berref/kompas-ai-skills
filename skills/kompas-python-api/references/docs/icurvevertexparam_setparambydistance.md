# SetParamByDistance - Установить расстояние, радиус (ломаная) или вес (сплайн)

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс ICurveVertexParam ](icurvevertexparam.html) > [ICurveVertexParam - методы ](icurvevertexparam_methods.html) |  Scroll [ [ [ ](icurvevertexparam_setparambyvertex.html "К следующему разделу")](icurvevertexparam_methods.html "На уровень выше")](icurvevertexparam_getparamvertex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icurvevertexparam.html)

Синтаксис Automation:

double Distance,

double Value );

HRESULT SetParamByDistance( [in] double Distance,

double Value,

[out, retval] VARIANT_BOOL * PVal );

Distance | \- расстояние до предыдущей вершины,  
---|---  
value | \- радиус для точки ломаной и вес для сплайна.  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание.

1\. Нельзя установить расстояние для вершины с индексом 0.

2\. Установить расстояние можно, если тип построения ksLineBuildingType не равен ksLBTByPoint и не равен ksLBTByPoint3DParams.

Подразделы:

(отсутствуют)
