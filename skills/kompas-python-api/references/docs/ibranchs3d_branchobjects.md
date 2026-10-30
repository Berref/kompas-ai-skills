# BranchObjects - Массив SAFEARRAY объектов, на которые указывают «ножки»

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Оформление ](bc2273863.html) > [Обозначения ](bc2275772.html) > [Интерфейс IBranchs3D ](ibranchs3d.html) > [IBranchs3D - свойства ](ibranchs3d_props.html) |  Scroll [ [ [ ](ibranchs3d_branchpoints.html "К следующему разделу")](ibranchs3d_props.html "На уровень выше")](ibranchs3d_branchobject.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ibranchs3d.html)

Тип данных: VARIANT типа VT_ARRAY | VT_DISPATCH

Синтаксис Automation:

BranchObjects = Object.BranchObjects | Получить свойство ([* ](1.html))  
---|---  
BranchObjects = Object.GetBranchObjects() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_BranchObjects( &BranchObjects ) | Получить свойство  
---|---  
  
Примечание:

1\. Если возвращается один объект, то тип VARIANT-а будет VT_DISPATCH, если возвращается несколько объектов, то тип VARIANT-а будет VT_ARRAY | VT_DISPATCH.

2\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
