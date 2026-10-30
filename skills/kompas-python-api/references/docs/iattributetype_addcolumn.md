# AddColumn - Добавить колонку

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Атрибуты ](attribute.html) > [Интерфейс IAttributeType ](iattributetype.html) > [IAttributeType - методы ](iattributetype_methods.html) |  Scroll [ [ [ ](iattributetype_delete.html "К следующему разделу")](iattributetype_methods.html "На уровень выше")](iattributetype_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iattributetype.html)

Синтаксис Automation:

LPDISPATCH AddColumn( long Index,

long Type,

BSTR Name );

Синтаксис COM:

HRESULT AddColumn( long Index,

ksValueTypeEnum Type,

BSTR Name,

IColumnInfo** Result );

Входные параметры:

Index | \- индекс колонки, после которой нужно добавить колонку,  
---|---  
Type | \- тип значений колонки,  
Name | \- название колонки.  
  
Возвращаемое значение:

| Указатель на интерфейс [IColumnInfo](icolumninfo.html).  
---|---  
  
Примечание:

Метод позволяет добавить колонку к типу атрибута.

Подразделы:

(отсутствуют)
