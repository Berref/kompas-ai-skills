# Value - Значение ячейки из таблицы атрибута

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Атрибуты ](attribute.html) > [Интерфейс IAttribute ](iattribute.html) > [IAttribute - свойства ](iattribute_props.html) |  Scroll [ [ [ ](iattribute_values.html "К следующему разделу")](iattribute_props.html "На уровень выше")](iattribute_rowscount.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iattribute.html)

Тип данных: VARIANT

Синтаксис Automation:

Value = Object.Value( RowNumb, ColumnNumb ) | Получить свойство ([* ](1.html))  
---|---  
Value = Object.GetValue( RowNumb, ColumnNumb ) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_Value( RowNumb, ColumnNumb, &Value ) | Получить свойство  
---|---  
  
Входные параметры:

RowNumb (long) | \- номер строки атрибута,  
---|---  
ColumnNumb (long) | \- номер столбца атрибута.  
  
Примечание:

1\. Свойство позволяет получать значение ячейки атрибута.

2\. Для задания значения ячейки следует использовать метод [IAttribute::SetValue](iattribute_setvalue.html).

3\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
