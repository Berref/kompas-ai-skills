# DrawType - Способ отрисовки обозначения базы

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Оформление ](bc2273863.html) > [Обозначения ](bc2275772.html) > [Интерфейс IBase3D ](ibase3d.html) > [IBase3D - свойства ](ibase3d_props.html) |  Scroll [ [ [ ](ibase3d_positionobject.html "К следующему разделу")](ibase3d_props.html "На уровень выше")](ibase3d_baseobject.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ibase3d.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- перпендикулярно к объекту,  
---|---  
FALSE | \- произвольное расположение.  
  
Синтаксис Automation:

DrawType = Object.DrawType | Получить свойство ([* ](1.html))  
---|---  
Object.DrawType = DrawType | Установить свойство ([* ](1.html))  
DrawType = Object.GetDrawType() | Получить свойство ([**](2.html))  
Object.SetDrawType( DrawType ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_DrawType( &DrawType ) | Получить свойство  
---|---  
Object.put_DrawType( DrawType ) | Установить свойство  
  
Примечание.

По умолчанию значение свойства равно TRUE.

Подразделы:

(отсутствуют)
