# BranchY - Координата конечной точки ответвления по оси Y

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения для строительства ](bb2362006.html) > [Интерфейс IMultiTextLeader ](imultitextleader.html) > [IMultiTextLeader - свойства ](imultitextleader_props.html) |  Scroll [ [ [ ](imultitextleader_form.html "К следующему разделу")](imultitextleader_props.html "На уровень выше")](imultitextleader_branchx.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imultitextleader.html)

Тип данных: double

Синтаксис Automation:

BranchY = iObject.BranchY( Index ) | Получить свойство ([* ](1.html))  
---|---  
iObject.BranchY = BranchY( Index ) | Установить свойство ([* ](1.html))  
BranchY = iObject.GetBranchY( Index ) | Получить свойство ([**](2.html))  
iObject.SetBranchY( Index, BranchY ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_BranchY( Index, &BranchY ) | Получить свойство  
---|---  
iObject->put_BranchY( Index, BranchY ) | Установить свойство  
  
Входные параметры:

Index | \- индекс объекта (long ).  
---|---  
  
Примечание:

1\. Свойство позволяет установить и получить координату конечной точки ответвления по оси Y.

2\. Значения координат пересчитываются в зависимости от текущей системы координат для объекта, задаваемой параметром [IDrawingObject::DrawingObjectParamType](idrawingobject_drawingobjectparamtype.html).

Подразделы:

(отсутствуют)
