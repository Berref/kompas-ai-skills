# ColType - Тип данных столбца

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Атрибуты ](attribute.html) > [Интерфейс IColumnInfo ](icolumninfo.html) > [IColumnInfo - свойства ](icolumninfo_props.html) |  Scroll [ [ [ ](icolumninfo_defvalue.html "К следующему разделу")](icolumninfo_props.html "На уровень выше")](icolumninfo_caption.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icolumninfo.html)

Тип данных: из перечисления [ksValueTypeEnum](ksvaluetypeenum.html)

Синтаксис Automation:

ColType = Object.ColType | Получить свойство ([* ](1.html))  
---|---  
Object.ColType = ColType | Установить свойство ([* ](1.html))  
ColType = Object.GetColType() | Получить свойство ([**](2.html))  
Object.SetColType( ColType ) | Установить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_ColType( &ColType ) | Получить свойство,  
---|---  
Object.put_ColType( ColType ) | Установить свойство.  
  
Примечание:

1\. Свойство позволяет устанавливать и получать тип данных столбца атрибута.

2\. При выборе типа ksValueTypeString длина строки задается свойством [IColumnInfo::Range](icolumninfo_range.html) (1…4000).

Подразделы:

(отсутствуют)
