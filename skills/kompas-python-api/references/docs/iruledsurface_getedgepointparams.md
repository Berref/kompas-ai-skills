# GetEdgePointParams - Получение параметров ребер линейчатой поверхности

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Поверхности ](bc2288197.html) > [Интерфейс ISurfaceContainer ](isurfacecontainer.html) > [ISurfaceContainer - свойства ](isurfacecontainer_props.html) > [Интерфейс IRuledSurface ](iruledsurface.html) > [IRuledSurface - методы ](iruledsurface_methods.html) |  Scroll [ [ [ ](iruledsurface_setedgepointparam.html "К следующему разделу")](iruledsurface_methods.html "На уровень выше")](iruledsurface_getedgepointparam.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iruledsurface.html)

Синтаксис Automation:

BOOL GetEdgePointParams( VARIANT * Points1,

VARIANT * T1,

VARIANT * Segments1,

VARIANT * AssociateVertexes1,

VARIANT * Points2,

VARIANT * T2, V

ARIANT * Segments2,

VARIANT * AssociateVertexes2 );

Синтаксис COM:

HRESULT GetEdgePointParams( VARIANT * Points1,

VARIANT * T1,

VARIANT * Segments1,

VARIANT * AssociateVertexes1,

VARIANT * Points2,

VARIANT * T2,

VARIANT * Segments2,

VARIANT * AssociateVertexes2,

BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры

Points1 | \- массив SAFEARRAY VT_R8 - VT_ARRAY | VT_R8 координат вершин ребер на первой направляющей,  
---|---  
T1 | \- массив SAFEARRAY VT_R8 - VT_ARRAY | VT_R8 параметров вершин ребер на первой направляющей,  
Segments1 | \- массив SAFEARRAY DISPATCH - VT_ARRAY | VT_DISPATCH сегментов первой направляющей,  
AssociateVertexes1 | \- массив SAFEARRAY DISPATCH - VT_ARRAY | VT_DISPATCH вершин первой направляющей, связанных с вершинами,  
Points2 | \- массив SAFEARRAY VT_R8 - VT_ARRAY | VT_R8 координат вершин ребер на второй направляющей,  
T2 | \- массив SAFEARRAY VT_R8 - VT_ARRAY | VT_R8 параметров вершин ребер на второй направляющей,  
Segments2 | \- массив SAFEARRAY DISPATCH - VT_ARRAY | VT_DISPATCH сегментов второй направляющей,  
AssociateVertexes2 | \- массив SAFEARRAY DISPATCH - VT_ARRAY | VT_DISPATCH вершин второй направляющей, связанных с вершинами.  
  
Метод позволяет получать параметры ребер линейчатой поверхности.

Подразделы:

(отсутствуют)
