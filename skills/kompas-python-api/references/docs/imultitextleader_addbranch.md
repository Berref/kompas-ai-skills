# AddBranch - Добавить ответвление

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения для строительства ](bb2362006.html) > [Интерфейс IMultiTextLeader ](imultitextleader.html) > [IMultiTextLeader - методы ](imultitextleader_methods.html) |  Scroll [ [ [ ](imultitextleader_addbranchbypoint.html "К следующему разделу")](imultitextleader_methods.html "На уровень выше")](imultitextleader_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imultitextleader.html)

Синтаксис Automation:

BOOL AddBranch( long index,

VARIANT Points );

Синтаксис COM:

HRESULT AddBranch( long index,

VARIANT Points,

BOOL * Result );

Входные параметры:

index | \- индекс, с которым добавляется ответвление,  
---|---  
Points | \- массив SafeArray координат точек.  
  
Возвращаемое значение:

TRUE | \- ответвление добавлено,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

1\. Координаты точек в массиве лежат в следующей последовательности: x0, y0, x1, y1, ...xi, yi.

2\. Значения координат пересчитываются в зависимости от текущей системы координат для объекта, задаваемой параметром [IDrawingObject::DrawingObjectParamType](idrawingobject_drawingobjectparamtype.html).

3\. Если index = -1, ответвление добавляется в конец массива ответвлений.

Подразделы:

(отсутствуют)
