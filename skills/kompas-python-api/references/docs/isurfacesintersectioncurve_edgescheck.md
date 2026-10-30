# EdgesCheck - Признак выбора указанного по индексу массива ребер

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс ISurfacesIntersectionCurve ](isurfacesintersectioncurve.html) > [ISurfacesIntersectionCurve - свойства ](isurfacesintersectioncurve_props.html) |  Scroll [ [ [ ](isurfacesintersectioncurve_edgeschecks.html "К следующему разделу")](isurfacesintersectioncurve_props.html "На уровень выше")](isurfacesintersectioncurve_edges.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isurfacesintersectioncurve.html)

Тип данных: BOOL

Синтаксис Automation:

EdgesCheck = Object.EdgesCheck( EdgesArrayIndex ) | Получить свойство ([* ](1.html))  
---|---  
Object.EdgesCheck( EdgesArrayIndex ) = EdgesCheck | Установить свойство ([* ](1.html))  
EdgesCheck = Object.GetEdgesCheck( EdgesArrayIndex ) | Получить свойство ([**](2.html))  
Object.SetEdgesCheck( EdgesArrayIndex, EdgesCheck) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_EdgesCheck( EdgesArrayIndex, &EdgesCheck ) | Получить свойство  
---|---  
Object.put_EdgesCheck( EdgesArrayIndex, EdgesCheck ) | Установить свойство  
  
Входные параметры:

EdgesArrayIndex | \- индекс массива ребер.  
---|---  
  
Примечание:

Индекс должен быть в диапазоне 0...[ISurfacesIntersectionCurve::EdgesArraysCount](isurfacesintersectioncurve_edgesarrayscount.html)-1.

Подразделы:

(отсутствуют)
