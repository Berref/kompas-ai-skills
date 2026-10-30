# GetVertexParams - Массив параметров UV и весов вершин в виде SAFEARRAY double - VT_ARRAY | VT_R8

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс ISplineOnSurface ](isplineonsurface.html) > [ISplineOnSurface - методы ](isplineonsurface_methods.html) |  Scroll [ [ [ ](isplineonsurface_invert.html "К следующему разделу")](isplineonsurface_methods.html "На уровень выше")](isplineonsurface_getvertex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isplineonsurface.html)

Синтаксис Automation:

BOOL GetVertexParams( VARIANT * UV, VARIANT * Points, VARIANT * Weights );

Синтаксис COM:

HRESULT GetVertexParams( VARIANT * UV, VARIANT * Points, VARIANT * Weights, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Выходные параметры:

UV | \- массив VT_ARRAY | VT_R8 параметров UV,  
---|---  
Points | \- массив VT_ARRAY | VT_R8 координат вершин,  
Weights | \- массив VT_ARRAY | VT_R8 весов вершин.  
  
Подразделы:

(отсутствуют)
