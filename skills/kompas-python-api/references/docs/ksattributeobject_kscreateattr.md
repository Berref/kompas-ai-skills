# ksCreateAttr - Создать атрибут по номеру типа атрибута

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы работы с атрибутами ](ck1761772.html) > [Интерфейс работы с атрибутами (ksAttributeObject) ](ksattributeobject.html) > [ksAttributeObject - методы ](ksattributeobject_methods.html) |  Scroll [ [ [ ](ksattributeobject_kscreateattr3d.html "К следующему разделу")](ksattributeobject_methods.html "На уровень выше")](ksattributeobject_kschoiceattrtypes.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksattributeobject.html)

Аналог данного метода при использовании API экспортных функций - [ksCreateAttr](kscreateattr.html).

Синтаксис Automation:

long ksCreateAttr (reference pObj,

LPDISPATCH attr,

double attrID,

BSTR libName);

Входные параметры:

pObj | \- указатель на объект (группа, вид, отдельный объект), атрибут которого создается. Если pObj = 0, то создается атрибут документа,  
---|---  
attr | \- указатель на интерфейс параметров атрибута [ksAttributeParam](ksattributeparam.html),  
attrID | \- уникальный номер типа атрибута,  
libName | \- имя библиотеки типов атрибутов, если libname = NULL, то тип атрибута берется из текущего документа.  
  
Возвращаемое значение:

указатель на атрибут | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание.

1\. Указатель на объект reference pObj может быть получен следующими способами:

•с помощью свойства reference интерфейса соответствующего объекта,

•с помощью интерфейса итератора [ksIterator](ksiterator.html) и методов [ksIterator::ksCreateAttrIterator](ksiterator_kscreateattriterator.html), [ksIterator::ksMoveAttrIterator](ksiterator_ksmoveattriterator.html),

2\. Параметры атрибута должны быть заданы с помощью метода [KompasObject::GetParamStruct](kompasobject_getparamstruct.html) с параметром ko_Attribute с последующим наполнением массива с помощью свойств и методов интерфейса [ksAttributeParam](ksattributeparam.html).

3\. Уникальный номер типа атрибута attrID может быть получен от интерфейса [ksLibraryAttrTypeParam](kslibraryattrtypeparam.html) с помощью свойства [ksLibraryAttrTypeParam::typeid](kslibraryattrtypeparam_typeid.html). Тип атрибута должен быть предварительно создан, например, с помощью метода [ksAttributeObject::ksCreateAttrType](ksattributeobject_kscreateattrtype.html).

Подразделы:

(отсутствуют)
