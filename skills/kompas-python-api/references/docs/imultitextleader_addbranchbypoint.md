# AddBranchByPoint - Добавить прямолинейное ответвление

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения для строительства ](bb2362006.html) > [Интерфейс IMultiTextLeader ](imultitextleader.html) > [IMultiTextLeader - методы ](imultitextleader_methods.html) |  Scroll [ [ [ ](imultitextleader_deletebranch.html "К следующему разделу")](imultitextleader_methods.html "На уровень выше")](imultitextleader_addbranch.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imultitextleader.html)

Синтаксис Automation:

BOOL AddBranchByPoint( long index,

double x, double y );

Синтаксис COM:

HRESULT AddBranchByPoint( long index,

double x,

double y,

BOOL * Result );

Входные параметры:

index | \- индекс, с которым добавляется ответвление,  
---|---  
x, y | \- координаты конца ответвления.  
  
Возвращаемое значение:

TRUE | \- ответвление добавлено,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

1\. Значения координат пересчитываются в зависимости от текущей системы координат для объекта, задаваемой параметром [IDrawingObject::DrawingObjectParamType](idrawingobject_drawingobjectparamtype.html).

2\. Если index = -1, ответвление добавляется в конец массива ответвлений.

Подразделы:

(отсутствуют)
