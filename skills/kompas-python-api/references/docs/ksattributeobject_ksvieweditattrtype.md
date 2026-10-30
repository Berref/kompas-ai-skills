# ksViewEditAttrType - Вывести диалог для просмотра или редактирования типа атрибута

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы работы с атрибутами ](ck1761772.html) > [Интерфейс работы с атрибутами (ksAttributeObject) ](ksattributeobject.html) > [ksAttributeObject - методы ](ksattributeobject_methods.html) |  Scroll [ [ [ ](ck1769035.html "К следующему разделу")](ksattributeobject_methods.html "На уровень выше")](ksattributeobject_ksvieweditattr.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksattributeobject.html)

Аналог данного метода при использовании API экспортных функций - [ViewEditAttrType](vieweditattrtype.html).

Синтаксис Automation:

long ksViewEditAttrType (BSTR libName,

long type,

double attrID,

BSTR password);

Входные параметры:

libName | \- имя библиотеки типов атрибутов. Если libname = NULL, типы атрибутов берутся из текущего документа,  
---|---  
type | \- режим работы: 1 - режим просмотра, 2 - режим редактирования,  
attrId | \- уникальный номер типа атрибута,  
password | \- пароль типа атрибута.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения.  
---|---  
  
Примечание:

Уникальный номер типа атрибута attrID может быть получен от интерфейса [ksLibraryAttrTypeParam](kslibraryattrtypeparam.html) с помощью свойства [ksLibraryAttrTypeParam::typeid](kslibraryattrtypeparam_typeid.html) или от интерфейса [ksAttributeObject](ksattributeobject.html) с помощью метода [ksAttributeObject::ksGetAttrKeysInfo](ksattributeobject_ksgetattrkeysinfo.html). Тип атрибута должен быть предварительно создан, например, с помощью метода [ksAttributeObject::ksCreateAttrType](ksattributeobject_kscreateattrtype.html).

Подразделы:

(отсутствуют)
