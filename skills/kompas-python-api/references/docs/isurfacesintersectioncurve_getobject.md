# GetObject - Получить объект из указанного наборапо индексу

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс ISurfacesIntersectionCurve ](isurfacesintersectioncurve.html) > [ISurfacesIntersectionCurve - методы ](isurfacesintersectioncurve_methods.html) |  Scroll [ [ [ ](isurfacesintersectioncurve_getobjects.html "К следующему разделу")](isurfacesintersectioncurve_methods.html "На уровень выше")](isurfacesintersectioncurve_clear.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isurfacesintersectioncurve.html)

Синтаксис Automation:

LPDISPATCH GetObject( BOOL ForArray1, long Index );

Синтаксис COM:

HRESULT GetObject( BOOL ForArray1, long Index, IModelObject **Object );

Выходные параметры:

ForArray1 | \- TRUE - первый набор, \- FALSE - второй набор,  
---|---  
Index | \- индекс объекта в наборе.  
  
Возвращаемое значение:

| \- указатель на интерфейс [IModelObject.](imodelobject.html)  
---|---  
  
Подразделы:

(отсутствуют)
