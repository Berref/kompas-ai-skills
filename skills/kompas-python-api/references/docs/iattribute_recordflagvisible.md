# RecordFlagVisible - Получить значения видимости колонок внутри записи в виде массива SAFEARRAY VT_ARRAY | VT_BOOL

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Атрибуты ](attribute.html) > [Интерфейс IAttribute ](iattribute.html) > [IAttribute - свойства ](iattribute_props.html) |  Scroll [ [ [ ](iattribute_rowscount.html "К следующему разделу")](iattribute_props.html "На уровень выше")](iattribute_objects.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iattribute.html)

Тип данных: VARIANT типа VT_ARRAY | VT_BOOL

Синтаксис Automation:

RecordFlagVisible = Object.RecordFlagVisible( ColumnNumb ) | Получить свойство ([* ](1.html))  
---|---  
RecordFlagVisible = Object.GetRecordFlagVisible( ColumnNumb ) | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_ColumnsCount( ColumnNumb, &ColumnsCount ) | Получить свойство  
---|---  
  
Входные параметры:

ColumnNumb | \- номер колонки записи.  
---|---  
  
Примечание:

1\. Свойство позволяет получить значения видимости колонок внутри записи.

2\. Установить значения видимости колонок записи можно с помощью метода [IAttribute::SetRecordFlagVisible](iattribute_setrecordflagvisible.html).

3\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
