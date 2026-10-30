# BranchPoints - Массив SAFEARRAY координат точек ответвления

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Элементы обозначений ](bb2348381.html) > [Интерфейс IBranchs ](ibranchs.html) > [IBranchs - свойства ](ibranchs_props.html) |  Scroll [ [ [ ](ibranchs_branchpointscount.html "К следующему разделу")](ibranchs_props.html "На уровень выше")](ibranchs_branchcount.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ibranchs.html)

Тип данных: VARIANT типа VT_ARRAY | VT_R8

Синтаксис Automation:

BranchPoints = Object.BranchPoints( Index ) | Получить свойство([* ](1.html))  
---|---  
Object.BranchPoints( Index ) = BranchPoints | Установить свойство ([* ](1.html))  
BranchPoints = Object.GetBranchPoints( Index ) | Получить свойство ([**](2.html))  
Object.SetBranchPoints( Index, BranchPoints ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_BranchPoints( Index, &BranchPoints ) | Получить свойство  
---|---  
Object.put_BranchPoints( Index, BranchPoints ) | Установить свойство  
  
Примечание:

1\. Координаты точек в массиве лежат в следующей последовательности: x0, y0, x1, y1, ...xi, yi.

2\. Значения координат зависят от текущей системы координат для объекта, задаваемой параметром [IDrawingObject::DrawingObjectParamType](idrawingobject_drawingobjectparamtype.html).

Подразделы:

(отсутствуют)
