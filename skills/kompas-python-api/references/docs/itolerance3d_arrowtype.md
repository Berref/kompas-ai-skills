# ArrowType - Тип стрелки ответвления

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Оформление ](bc2273863.html) > [Обозначения ](bc2275772.html) > [Интерфейс ITolerance3D ](itolerance3d.html) > [ITolerance3D - свойства ](itolerance3d_props.html) |  Scroll [ [ [ ](itolerance3d_baseplane.html "К следующему разделу")](itolerance3d_props.html "На уровень выше")](itolerance3d_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](itolerance3d.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- стрелка,  
---|---  
FALSE | \- треугольник.  
  
Синтаксис Automation:

ArrowType = Object.ArrowType( Index ) | Получить свойство ([* ](1.html))  
---|---  
Object.ArrowType( Index ) = ArrowType | Установить свойство ([* ](1.html))  
ArrowType = Object.GetArrowType( Index ) | Получить свойство ([**](2.html))  
Object.SetArrowType( Index, ArrowType ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_ArrowType( Index, &ArrowType ) | Получить свойство  
---|---  
Object.put_ArrowType( Index, ArrowType ) | Установить свойство  
  
Входные параметры:

Index | \- индекс ответвления ( long ).  
---|---  
  
Примечание.

Свойство позволяет устанавливать и получать тип стрелки ответвления.

Подразделы:

(отсутствуют)
