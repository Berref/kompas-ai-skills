# SetObjects - Задать 1-й и 2-й наборы поверхностей

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс ISurfacesIntersectionCurve ](isurfacesintersectioncurve.html) > [ISurfacesIntersectionCurve - методы ](isurfacesintersectioncurve_methods.html) |  Scroll [ [ [ ](itrimmedcurve.html "К следующему разделу")](isurfacesintersectioncurve_methods.html "На уровень выше")](isurfacesintersectioncurve_getobjects.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isurfacesintersectioncurve.html)

Синтаксис Automation:

BOOL SetObjects( VARIANT ObjectsArray1, VARIANT ObjectsArray2 )

Синтаксис COM:

HRESULT SetObjects( VARIANT ObjectsArray1, VARIANT ObjectsArray2, BOOL * Res );

Входные параметры:

ObjectsArray1 | \- первый набор граней,  
---|---  
ObjectsArray2 | \- первый набор граней.  
  
Возвращаемое значение:

TRUE | \- в случае удачи.  
---|---  
  
Примечание:

Если требуется передать одну грань в наборе, ее можно передать как VT_DISPATCH.

Если требуется передать несколько граней в наборе, то нужно передать его как массив VT_ARRAY | VT_DISPATCH.

Подразделы:

(отсутствуют)
