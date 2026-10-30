# BranchEndPoints - Массив SAFEARRAY координат точек целеуказания

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Оформление ](bc2273863.html) > [Обозначения ](bc2275772.html) > [Интерфейс IBranchs3D ](ibranchs3d.html) > [IBranchs3D - свойства ](ibranchs3d_props.html) |  Scroll [ [ [ ](ibranchs3d_branchobject.html "К следующему разделу")](ibranchs3d_props.html "На уровень выше")](ibranchs3d_branchcount.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ibranchs3d.html)

Тип данных: VARIANT типа VT_ARRAY | VT_R8

Синтаксис Automation:

BranchEndPoints = Object.BranchEndPoints | Получить свойство ([* ](1.html))  
---|---  
BranchEndPoints = Object.GetBranchEndPoints() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_BranchEndPoints( &BranchEndPoints ) | Получить свойство  
---|---  
  
Свойство позволяет получить массив координат конечных точек ответвлений.

Примечание:

1\. Свойство доступно только для чтения.

2\. Координаты точек в массиве лежат в следующей последовательности: x0, y0, z0, x1, y1, z1,...xi, yi, zi.

Подразделы:

(отсутствуют)
