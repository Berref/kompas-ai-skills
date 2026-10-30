# SetParamByVertex - Установить параметры вершины по указателю на вершину

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс ICurveVertexParam ](icurvevertexparam.html) > [ICurveVertexParam - методы ](icurvevertexparam_methods.html) |  Scroll [ [ [ ](icurvevertexparam_setparamvertex.html "К следующему разделу")](icurvevertexparam_methods.html "На уровень выше")](icurvevertexparam_setparambydistance.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icurvevertexparam.html)

Синтаксис Automation:

BOOL SetParamByVertex( LPDISPATCH Obj,

double Value );

Синтаксис Automation:

HRESULT SetParamByVertex( [in] IModelObject * Obj,

[in] double Value,

[out, retval] VARIANT_BOOL * PVal );

Входные параметры:

obj | \- указатель на вершину,  
---|---  
value | \- радиус для точки ломаной и вес для сплайна.  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения.  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
