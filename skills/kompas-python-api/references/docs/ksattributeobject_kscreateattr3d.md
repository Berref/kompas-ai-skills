# ksCreateAttr3D - Cоздать атрибут по номеру типа атрибута из библиотеки

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы работы с атрибутами ](ck1761772.html) > [Интерфейс работы с атрибутами (ksAttributeObject) ](ksattributeobject.html) > [ksAttributeObject - методы ](ksattributeobject_methods.html) |  Scroll [ [ [ ](ksattributeobject_kscreateattr3dex.html "К следующему разделу")](ksattributeobject_methods.html "На уровень выше")](ksattributeobject_kscreateattr.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksattributeobject.html)

Аналог данного метода при использовании API экспортных функций - [ksCreateAttr3D](kscreateattr3d.html).

Синтаксис Automation:

ksAttribute3D* ksCreateAttr3D (LPDISPATCH pObj,

LPDISPATCH attr,

double attrID,

BSTR libname);

Входные параметры:

[pObj](pobj.html) | \- указатель на объект для которого создается атрибут,  
---|---  
attr | \- указатель на интерфейс параметров атрибута [ksAttributeParam](ksattributeparam.html),  
attrID | \- уникальный номер типа атрибута,  
libname | \- имя библиотеки атрибутов если libname = NULL - тип атрибута берется в документе.  
  
Возвращаемое значение:

Указатель на интерфейс атрибута [ksAttribute3D](ksattribute3d.html) | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. Атрибут можно добавить ко всем объектам дерева построений, кроме компонентов, сопряжений, группы сопряжений.

2\. Параметры атрибута должны быть заданы с помощью метода [KompasObject::GetParamStruct](kompasobject_getparamstruct.html) с параметром ko_Attribute с последующим наполнением массива с помощью свойств и методов интерфейса [ksAttributeParam](ksattributeparam.html).

3\. Уникальный номер типа атрибута attrID может быть получен от интерфейса [ksLibraryAttrTypeParam](kslibraryattrtypeparam.html) с помощью свойства [ksLibraryAttrTypeParam::typeid](kslibraryattrtypeparam_typeid.html). Тип атрибута должен быть предварительно создан, например, с помощью метода [ksAttributeObject::ksCreateAttrType](ksattributeobject_kscreateattrtype.html).

Подразделы:

(отсутствуют)
