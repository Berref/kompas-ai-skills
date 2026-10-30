# SetBaseObject - Установить базовый объект

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Размеры ](bb2356896.html) > [Интерфейс ILineSegmentAndPointDimension ](ilinesegmentandpointdimension.html) > [ILineSegmentAndPointDimension - методы ](ilinesegmentandpointdimension_methods.html) |  Scroll [ [ [ ](ilinesegmentandpointdimension_setbaseobjectpoint.html "К следующему разделу")](ilinesegmentandpointdimension_methods.html "На уровень выше")](ilinesegmentandpointdimension_getbaseobjectpoint.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilinesegmentandpointdimension.html)

Синтаксис Automation:

BOOL SetBaseObject( long Index, IDrawingObject * NewObject, long SegmentIndex );

Синтаксис COM:

HRESULT SetBaseObject( long Index, IDrawingObject * NewObject, long SegmentIndex, BOOL * Result );

Входные параметры:

Index | \- индекс базового объекта,  
---|---  
NewObject | \- базовыйй объект,  
SegmentIndex | \- индекс-идентификатор примитива в составных объектах.  
  
Подразделы:

(отсутствуют)
