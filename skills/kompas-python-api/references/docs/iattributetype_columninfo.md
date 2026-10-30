# ColumnInfo - Получить информацию о столбце атрибута

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Атрибуты ](attribute.html) > [Интерфейс IAttributeType ](iattributetype.html) > [IAttributeType - свойства ](iattributetype_props.html) |  Scroll [ [ [ ](iattributetype_filename.html "К следующему разделу")](iattributetype_props.html "На уровень выше")](iattributetype_columnscount.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iattributetype.html)

Тип данных: указатель на интерфейс параметров столбца атрибута [IColumnInfo](icolumninfo.html)

Синтаксис Automation:

ColumnInfo = Object.ColumnInfo ( Index ) | Получить свойство ([* ](1.html))  
---|---  
ColumnInfo = Object.GetColumnInfo( Index ) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_ColumnInfo( Index, &ColumnInfo ) | Получить свойство  
---|---  
  
Входные параметры:

Index (VARIANT) | \- индекс столбца.  
---|---  
  
Примечание:

1\. Свойство позволяет получать интерфейс параметров столбца атрибута.

2\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
