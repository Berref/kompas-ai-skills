# CreateAttrEx - Создать атрибут по номеру типа атрибута из библиотеки libname

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument ](ikompasdocument.html) > [IKompasDocument - методы ](ikompasdocument_methods.html) > [Интерфейс IKompasDocument3D ](ikompasdocument3d.html) > [IKompasDocument3D - методы ](ikompasdocument3d_methods.html) |  Scroll [ [ [ ](ikompasdocument3d_deletehistory.html "К следующему разделу")](ikompasdocument3d_methods.html "На уровень выше")](ikompasdocument3d_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument3d.html)

Синтаксис Automation:

LPDISPATCH CreateAttrEx( double AttrID, BSTR Libname, VARIANT Objects, IPart7 * SourcePart );

Синтаксис COM:

HRESULT CreateAttrEx( double AttrID, BSTR Libname, VARIANT Objects, IPart7 * SourcePart, IAttribute ** Result );

Возвращаемое значение:

| \- указатель на интерфейс [IAttribute](iattribute.html)  
---|---  
  
Входные параметры:

AttrID | \- уникальный номер типа атрибута,  
---|---  
Libname | \- имя библиотеки типов атрибутов, если libname = NULL, то тип атрибута берется из текущего документа,  
Objects | \- массив VT_ARRAY | VT_DISPATCH объектов, для которых назначается атрибут,  
SourcePart | \- указатель на интерфейс вставки детали [IPart](kspart.html).  
  
Подразделы:

(отсутствуют)
