# CreateAttr - Создать атрибут по номеру типа атрибута из библиотеки libname

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument1 ](ikompasdocument1.html) > [IKompasDocument1 - методы ](ikompasdocument1_methods.html) |  Scroll [ [ [ ](ikompasdocument1_delete.html "К следующему разделу")](ikompasdocument1_methods.html "На уровень выше")](ikompasdocument1_applymetadatafromfile.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument1.html)

Синтаксис Automation:

LPDISPATCH CreateAttr( double AttrID,

BSTR Libname,

VARIANT Objects );

Синтаксис COM:

HRESULT CreateAttr( AttrID,

Libname,

VARIANT Objects,

IAttribute ** Result );

Входные параметры:

AttrID | \- уникальный номер типа атрибута,  
---|---  
Libname | \- имя библиотеки типов атрибутов,  
Objects | \- объект или массив объектов, к которым нужно добавить атрибут ( VARIANT типа VT_DISPATCH или VT_ARRAY | VT_DISPATCH ).  
  
Возвращаемое значение:

| указатель на интерфейс атрибута [IAttribute](iattribute.html).  
---|---  
  
Примечание:

Метод позволяет создать атрибут по номеру типа из заданной библиотеки.

Подразделы:

(отсутствуют)
