# ksDeleteAttrType - Удалить тип атрибута из библиотеки

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы работы с атрибутами ](ck1761772.html) > [Интерфейс работы с атрибутами (ksAttributeObject) ](ksattributeobject.html) > [ksAttributeObject - методы ](ksattributeobject_methods.html) |  Scroll [ [ [ ](ksattributeobject_ksdeleteattr3d.html "К следующему разделу")](ksattributeobject_methods.html "На уровень выше")](ksattributeobject_ksdeleteattrrow.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksattributeobject.html)

Аналог данного метода при использовании API экспортных функций - [DeleteAttrType](deleteattrtype.html).

Синтаксис Automation:

long ksDeleteAttrType (double attrID,

BSTR libName,

BSTR password);

Входные параметры:

attrID | \- уникальный номер типа,  
---|---  
libName | \- имя библиотеки типов атрибутов, если libname = NULL, то тип атрибута удаляется из текущего документа,  
password | \- пароль типа атрибута.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Уникальный номер типа атрибута attrID может быть получен от интерфейса [ksLibraryAttrTypeParam](kslibraryattrtypeparam.html) с помощью свойства [ksLibraryAttrTypeParam::typeid](kslibraryattrtypeparam_typeid.html) или с помощью метода [ksAttributeObject::ksGetAttrKeysInfo](ksattributeobject_ksgetattrkeysinfo.html).

Подразделы:

(отсутствуют)
