# Edges - Количество массивов ребер в кривой пересечения поверхностей

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс ISurfacesIntersectionCurve ](isurfacesintersectioncurve.html) > [ISurfacesIntersectionCurve - свойства ](isurfacesintersectioncurve_props.html) |  Scroll [ [ [ ](isurfacesintersectioncurve_edgescheck.html "К следующему разделу")](isurfacesintersectioncurve_props.html "На уровень выше")](isurfacesintersectioncurve_edgesarrayscount.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](isurfacesintersectioncurve.html)

Тип данных: VARIANT

Синтаксис Automation:

Edges = Object.Edges( EdgesArrayIndex ) | Получить свойство ([* ](1.html))  
---|---  
Edges = Object.GetEdges( EdgesArrayIndex ) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_Edges( EdgesArrayIndex, &Edges ) | Получить свойство  
---|---  
  
Входные параметры:

EdgesArrayIndex | \- индекс массива ребер  
---|---  
  
Примечание:

Свойство доступно только для чтения.

В зависимости от количества ребер возвращается:

•нет ребер - VT_EMPTY (если указан неправильный индекс или ребра не созданы),

•одно ребро - VT_DISPATCH,

•более одного ребра - VT_ARRAY | VT_DISPATCH.

Индекс должен быть в диапазоне 0...[ISurfacesIntersectionCurve::EdgesArraysCount](isurfacesintersectioncurve_edgesarrayscount.html)-1.

Подразделы:

(отсутствуют)
