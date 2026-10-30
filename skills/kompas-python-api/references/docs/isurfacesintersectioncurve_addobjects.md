# AddObjects - Добавить элемент(ы) в указанный набор

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс ISurfacesIntersectionCurve ](isurfacesintersectioncurve.html) > [ISurfacesIntersectionCurve - методы ](isurfacesintersectioncurve_methods.html) |  Scroll [ [ [ ](isurfacesintersectioncurve_clear.html "К следующему разделу")](isurfacesintersectioncurve_methods.html "На уровень выше")](isurfacesintersectioncurve_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isurfacesintersectioncurve.html)

Синтаксис Automation:

BOOL AddObjects( BOOL ForArray1, VARIANT * Objects );

Синтаксис COM:

HRESULT AddObjects( BOOL ForArray1, VARIANT * Objects, BOOL * Res );

Выходные параметры:

ForArray1 | \- TRUE - первый набор, \- FALSE - второй набор,  
---|---  
Objects | \- набор граней.  
  
Возвращаемое значение:

TRUE | \- в случае удачи.  
---|---  
  
Примечание:

Если в набор добавляется одна грань, то ее можно передать как VT_DISPATCH.

Если в набор добавляется несколько граней, то нужно передать массив VT_ARRAY | VT_DISPATCH.

Подразделы:

(отсутствуют)
