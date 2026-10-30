# BranchPoints - Массив SAFEARRAY координат точек ответвления

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Оформление ](bc2273863.html) > [Обозначения ](bc2275772.html) > [Интерфейс IBranchs3D ](ibranchs3d.html) > [IBranchs3D - свойства ](ibranchs3d_props.html) |  Scroll [ [ [ ](ibranchs3d_branchpointscount.html "К следующему разделу")](ibranchs3d_props.html "На уровень выше")](ibranchs3d_branchobjects.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ibranchs3d.html)

Тип данных: VARIANT типа VT_ARRAY | VT_R8

Синтаксис Automation:

BranchPoints = Object.BranchPoints( Index ) | Получить свойство ([* ](1.html))  
---|---  
Object.BranchPoints( Index ) = BranchPoints | Установить свойство ([* ](1.html))  
BranchPoints = Object.GetBranchPoints( Index ) | Получить свойство ([**](2.html))  
Object.SetBranchPoints( Index, BranchPoints ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_BranchPoints( Index, &BranchPoints ) | Получить свойство  
---|---  
Object.put_BranchPoints( Index, BranchPoints ) | Установить свойство  
  
Входные параметры

long Index | \- номер ответвления.  
---|---  
  
Свойство позволяет получить массив координат точек ответвления, заданного по номеру.

Примечание:

1\. Координаты точек в массиве лежат в следующей последовательности: x0, y0, z0, x1, y1, z1,...xi, yi, zi.

2\. При задании точек координаты будут спроецированы на плоскость объекта.

Подразделы:

(отсутствуют)
