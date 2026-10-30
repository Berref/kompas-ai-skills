# BranchX - Координата конечной точки ответвления по оси X

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения для строительства ](bb2362006.html) > [Интерфейс IMultiTextLeader ](imultitextleader.html) > [IMultiTextLeader - свойства ](imultitextleader_props.html) |  Scroll [ [ [ ](imultitextleader_branchy.html "К следующему разделу")](imultitextleader_props.html "На уровень выше")](imultitextleader_branchpointscount.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imultitextleader.html)

Тип данных: double

Синтаксис Automation:

BranchX = iObject.BranchX( Index ) | Получить свойство ([* ](1.html))  
---|---  
iObject.BranchX = BranchX( Index ) | Установить свойство ([* ](1.html))  
BranchX = iObject.GetBranchX( Index ) | Получить свойство ([**](2.html))  
iObject.SetBranchX( Index, BranchX ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_BranchX( Index, &BranchX ) | Получить свойство  
---|---  
iObject->put_BranchX( Index, BranchX ) | Установить свойство  
  
Входные параметры:

Index | \- индекс объекта ( long ).  
---|---  
  
Примечание:

1\. Свойство позволяет установить и получить координату конечной точки ответвления по оси Х.

2\. Значения координат пересчитываются в зависимости от текущей системы координат для объекта, задаваемой параметром [IDrawingObject::DrawingObjectParamType](idrawingobject_drawingobjectparamtype.html).

Подразделы:

(отсутствуют)
