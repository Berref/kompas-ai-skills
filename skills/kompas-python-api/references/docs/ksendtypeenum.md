# ksEndTypeEnum - Типы операций выдавливания

[API интерфейсов. Версия 7](applicate.html) > [Константы API версии 7 ](cj1473974.html) |  Scroll [ [ [ ](ksevolutionshiftsketchtypeenum.html "К следующему разделу")](cj1473974.html "На уровень выше")](ksendfacetypeenum.html "К предыдущему разделу")  
---|---  
  
etBlind | 0 | строго на глубину  
---|---|---  
etThroughAll | 1 | через всю деталь  
etUpToVertexTo | 2 | на расстояние до вершины  
etUpToVertexFrom | 3 | на расстояние за вершину  
etUpToSurfaceTo | 4 | на расстояние до поверхности  
etUpToSurfaceFrom | 5 | на расстояние за поверхность  
etUpToNearSurface | 6 | до ближайшей поверхности  
  
Примечание:

1\. При типах выдавливания etUpToVertexTo, etUpToVertexFrom, etUpToSurfaceTo и etUpToSurfaceFrom в методах SetSideParam и GetSideParam параметр depth интерпретируется как глубина, вычитаемая или добавляемая к расстоянию до указанного объекта. Объект, определяющий глубину, задается с помощью метода SetDepthObject.

2\. В API5 соответствует перечислению [End_Type](end_type.html).

Подразделы:

(отсутствуют)
