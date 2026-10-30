# GetObjects - Получить 1-й и 2-й наборы поверхностей

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс ISurfacesIntersectionCurve ](isurfacesintersectioncurve.html) > [ISurfacesIntersectionCurve - методы ](isurfacesintersectioncurve_methods.html) |  Scroll [ [ [ ](isurfacesintersectioncurve_setobjects.html "К следующему разделу")](isurfacesintersectioncurve_methods.html "На уровень выше")](isurfacesintersectioncurve_getobject.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isurfacesintersectioncurve.html)

Синтаксис Automation:

BOOL GetObjects( VARIANT * ObjectsArray1, VARIANT * ObjectsArray2 );

Синтаксис COM:

HRESULT GetObjects( VARIANT * ObjectsArray1, VARIANT * ObjectsArray2, BOOL * Res );

Выходные параметры:

ObjectsArray1 | \- первый набор граней,  
---|---  
ObjectsArray2 | \- первый набор граней.  
  
Возвращаемое значение:

TRUE | \- в случае удачи.  
---|---  
  
Примечание:

Если в наборе одна грань, то она возвращается как VT_DISPATCH.

Если в наборе несколько граней, то возвращается массив VT_ARRAY | VT_DISPATCH.

Подразделы:

(отсутствуют)
