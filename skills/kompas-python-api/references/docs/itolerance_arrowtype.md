# ArrowType - Тип стрелки ответвления

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Обозначения ](bb3219840.html) > [Интерфейс ITolerance ](itolerance.html) > [ITolerance - свойства ](itolerance_props.html) |  Scroll [ [ [ ](itolerance_branchpos.html "К следующему разделу")](itolerance_props.html "На уровень выше")](itolerance_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](itolerance.html)

Тип данных: BOOL

Значения свойства:

TRUE | \- стрелка,  
---|---  
FALSE | \- треугольник.  
  
Синтаксис Automation:

ArrowType = Object.ArrowType( Index ) | Получить свойство([* ](1.html))  
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
  
Примечание:

Свойство позволяет устанавливать и получать тип стрелки ответвления.

Подразделы:

(отсутствуют)
