# GetEdgePointParams - Получение параметров ребер

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Поверхности ](bc2288197.html) > [Интерфейс ISurfaceContainer ](isurfacecontainer.html) > [ISurfaceContainer - свойства ](isurfacecontainer_props.html) > [Интерфейс IRuledSurfaceParametersByCurves](iruledsurfaceparametersbycurves.html) > [IRuledSurfaceParametersByCurves - методы](iruledsurfaceparametersbycurves_methods.html) |  Scroll [ [ [ ](iruledsurfaceparametersbycurves_setedgepointparam.html "К следующему разделу")](iruledsurfaceparametersbycurves_methods.html "На уровень выше")](iruledsurfaceparametersbycurves_getedgepointparam.html "К предыдущему разделу")  
---|---  
  
[Интерфейс](iruledsurfaceparametersbycurves.html)

Синтаксис Automation:

BOOL GetEdgePointParams( VARIANT * Points1, VARIANT * T1, VARIANT * Segments1, VARIANT * AssociateVertexes1, VARIANT * Points2, VARIANT * T2, VARIANT * Segments2, VARIANT * AssociateVertexes2 );

Синтаксис COM:

HRESULT GetEdgePointParams( VARIANT * Points1, VARIANT * T1, VARIANT * Segments1, VARIANT * AssociateVertexes1, VARIANT * Points2, VARIANT * T2, VARIANT * Segments2, VARIANT * AssociateVertexes2, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Выходные параметры

Points1 | \- точки на первой цепочке кривых,  
---|---  
T1 | \- параметры кривых первой цепочки,  
Segments1 | \- сегменты первой цепочки,  
AssociateVertexes1 | \- ассоциативные вершины первой цепочки,  
Points2 | \- точки на второй цепочке кривых,  
T2 | \- параметры кривых второй цепочки,  
Segments2 | \- сегменты второй цепочки,  
AssociateVertexes2 | \- ассоциативные вершины второй цепочки.  
  
Подразделы:

(отсутствуют)
