# Cells - Массив ячеек в виде SAFEARRAY DISPATCH - VT_ARRAY | VT_DISPATCH

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Таблица ](bb3106514.html) > [Интерфейс ITableRange ](itablerange.html) > [ITableRange - свойства ](itablerange_props.html) |  Scroll [ [ [ ](itablerange_cellsboundaries.html "К следующему разделу")](itablerange_props.html "На уровень выше")](itablerange_props.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](itablerange.html)

Тип данных: VARIANT

Значения свойства:

| \- Массив SafeArray типа VT_ARRAY | VT_DISPATCH.  
---|---  
  
Синтаксис Automation:

Cells = Object.Cells | Получить свойство([* ](1.html))  
---|---  
Cells = Object.GetCells | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_Cells( &Cells ) | Получить свойство  
---|---  
  
Примечание:

1\. Свойство позволяет получить массив ячеек SAFEARRAY. Это массив VT_DISPATCH, которые можно преобразовать в интерфейсы [ITableCell](itablecell.html). Если возвращается один объект, то тип VARIANT-а будет VT_DISPATCH, если возвращается несколько объектов, то тип VARIANT-а будет VT_ARRAY | VT_DISPATCH.

2\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
