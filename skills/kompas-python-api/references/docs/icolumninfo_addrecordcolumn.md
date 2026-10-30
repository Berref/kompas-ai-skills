# AddRecordColumn - Добавить колонку

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Атрибуты ](attribute.html) > [Интерфейс IColumnInfo ](icolumninfo.html) > [IColumnInfo - методы ](icolumninfo_methods.html) |  Scroll [ [ [ ](icolumninfo_delete.html "К следующему разделу")](icolumninfo_methods.html "На уровень выше")](icolumninfo_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icolumninfo.html)

Синтаксис Automation:

LPDISPATCH AddRecordColumn( long Index,

long Type,

BSTR Name );

Синтаксис COM:

HRESULT AddRecordColumn( long Index,

ksValueTypeEnum Type,

BSTR Name,

IColumnInfo** Result );

Входные параметры:

Index | \- индекс колонки, после которой нужно добавить колонку,  
---|---  
Type | \- тип значений колонки,  
Name | \- название колонки.  
  
Возвращаемое значение:

| указатель на интерфейс [IColumnInfo](icolumninfo.html).  
---|---  
  
Примечание:

Метод позволяет добавить колонку к записи.

Подразделы:

(отсутствуют)
