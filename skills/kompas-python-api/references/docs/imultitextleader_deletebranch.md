# DeleteBranch - Удалить ответвление

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения для строительства ](bb2362006.html) > [Интерфейс IMultiTextLeader ](imultitextleader.html) > [IMultiTextLeader - методы ](imultitextleader_methods.html) |  Scroll [ [ [ ](iunitmarking.html "К следующему разделу")](imultitextleader_methods.html "На уровень выше")](imultitextleader_addbranchbypoint.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imultitextleader.html)

Синтаксис Automation:

BOOL DeleteBranch( long index );

Синтаксис COM:

HRESULT DeleteBranch( long Index,

VARIANT_BOOL * Result );

Входные параметры:

index | \- индекс удаляемого ответвления.  
---|---  
  
Возвращаемое значение:

TRUE | \- ответвление удалено,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

1\. Значения координат пересчитываются в зависимости от текущей системы координат для объекта, задаваемой параметром [IDrawingObject::DrawingObjectParamType](idrawingobject_drawingobjectparamtype.html).

2\. Если index = -1, ответвление добавляется в конец массива ответвлений.

Подразделы:

(отсутствуют)
