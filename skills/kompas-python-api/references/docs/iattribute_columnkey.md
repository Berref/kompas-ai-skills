# ColumnKey - Получить ключи колонок

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Атрибуты ](attribute.html) > [Интерфейс IAttribute ](iattribute.html) > [IAttribute - свойства ](iattribute_props.html) |  Scroll [ [ [ ](iattribute_flagvisible.html "К следующему разделу")](iattribute_props.html "На уровень выше")](iattribute_columnscount.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iattribute.html)

Тип данных: VARIANT типа VT_ARRAY | VT_I4

Синтаксис Automation:

ColumnKey = Object.ColumnKey | Получить свойство ([* ](1.html))  
---|---  
ColumnKey = Object.GetColumnKey() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_ColumnKey( &ColumnKey ) | Получить свойство  
---|---  
  
Примечание:

1\. Свойство позволяет получать значения ключей колонок атрибута.

2\. Для задания значений ключей колонок следует использовать метод [IAttribute::SetColumnKey](iattribute_setcolumnkey.html).

3\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
