# End_Type - Типы операций выдавливания

[Структуры параметров и константы](3d_define.html) > [Константы ](bk1803360.html) > [Константы моделей ](bk1853230.html) |  Scroll [ [ [ ](bk1806623.html "К следующему разделу")](bk1853230.html "На уровень выше")](ksbooleantype.html "К предыдущему разделу")  
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

2\. В API7 соответствуют перечислению [ksEndTypeEnum](ksendtypeenum.html).

Подразделы:

(отсутствуют)
