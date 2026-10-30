# ksCreateAttrType - Создать тип атрибута в библиотеке

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы работы с атрибутами ](ck1761772.html) > [Интерфейс работы с атрибутами (ksAttributeObject) ](ksattributeobject.html) > [ksAttributeObject - методы ](ksattributeobject_methods.html) |  Scroll [ [ [ ](ksattributeobject_ksdeleteattr.html "К следующему разделу")](ksattributeobject_methods.html "На уровень выше")](ksattributeobject_kscreateattr3dex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksattributeobject.html)

Аналог данного метода при использовании API экспортных функций - [ksCreateAttrType](kscreateattrtype.html).

Синтаксис Automation:

double ksCreateAttrType (LPDISPATCH attrType,

BSTR libName);

Входные параметры:

attrType | \- указатель на интерфейс параметров типа табличного атрибута [ksAttributeTypeParam](ksattributetypeparam.html),  
---|---  
libName | \- имя библиотеки типов атрибутов, если libname = NULL, то тип атрибута создается в текущем документе.  
  
Возвращаемое значение:

уникальный номер типа атрибута | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Параметры атрибута должны быть заданы с помощью метода [KompasObject::GetParamStruct](kompasobject_getparamstruct.html) с параметром ko_AttributeType с последующим наполнением массива с помощью свойств и методов интерфейса [ksAttributeTypeParam](ksattributetypeparam.html).

Подразделы:

(отсутствуют)
