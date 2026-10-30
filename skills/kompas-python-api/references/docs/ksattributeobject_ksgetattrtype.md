# ksGetAttrType - Получить описание типа табличного атрибута из библиотеки или текущего документа

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы работы с атрибутами ](ck1761772.html) > [Интерфейс работы с атрибутами (ksAttributeObject) ](ksattributeobject.html) > [ksAttributeObject - методы ](ksattributeobject_methods.html) |  Scroll [ [ [ ](ksattributeobject_ksgetattrvalue.html "К следующему разделу")](ksattributeobject_methods.html "На уровень выше")](ksattributeobject_ksgetattrtabinfo.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksattributeobject.html)

Аналог данного метода при использовании API экспортных функций - [ksGetAttrType](ksgetattrtype.html).

Синтаксис Automation:

long ksGetAttrType (double attrID,

BSTR libName,

LPDISPATCH attrType);

Входной параметр:

attrID | \- уникальный номер типа атрибута,  
---|---  
libName | \- имя библиотеки типов атрибутов, если libname = NULL, то тип атрибута из текущего документа.  
  
Выходной параметр:

attrType | \- указатель на интерфейс параметров типа табличного атрибута [ksAttributeTypeParam](ksattributetypeparam.html).  
---|---  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. Уникальный номер типа атрибута attrID может быть получен от интерфейса [ksLibraryAttrTypeParam](kslibraryattrtypeparam.html) с помощью свойства [ksLibraryAttrTypeParam::typeid](kslibraryattrtypeparam_typeid.html) или с помощью метода [ksAttributeObject::ksGetAttrKeysInfo](ksattributeobject_ksgetattrkeysinfo.html). Тип атрибута должен быть предварительно создан, например, с помощью метода [ksAttributeObject::ksCreateAttrType](ksattributeobject_kscreateattrtype.html).

2\. Перед использованием указатель attrType должен быть получен с помощью метода [KompasObject::GetParamStruct](kompasobject_getparamstruct.html) с параметром ko_AttributeType.

Подразделы:

(отсутствуют)
