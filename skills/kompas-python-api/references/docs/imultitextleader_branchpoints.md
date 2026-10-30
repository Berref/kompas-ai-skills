# BranchPoints - Массив SAFEARRAY координат точек ответвления

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения для строительства ](bb2362006.html) > [Интерфейс IMultiTextLeader ](imultitextleader.html) > [IMultiTextLeader - свойства ](imultitextleader_props.html) |  Scroll [ [ [ ](imultitextleader_branchpointscount.html "К следующему разделу")](imultitextleader_props.html "На уровень выше")](imultitextleader_branchcount.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imultitextleader.html)

Тип данных: VARIANT ( VT_ARRAY | VT_R8 )

Синтаксис Automation:

BranchPoints = iObject.BranchPoints | Получить свойство ([* ](1.html))  
---|---  
BranchPoints = iObject.GetBranchPoints( ) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_BranchPoints( &BranchPoints ) | Получить свойство  
---|---  
  
Примечание:

1\. Свойство доступно только для чтения.

2\. Свойство позволяет получить SAFEARRAY координат точек ответвления. В массиве последовательно собраны координаты X и Y для каждой точки ответвления: x0, y0, x1, y1, ...xi, yi.

Подразделы:

(отсутствуют)
