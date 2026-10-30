# ksGetAttrKeysInfo - Получить информацию о ключах атрибута

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы работы с атрибутами ](ck1761772.html) > [Интерфейс работы с атрибутами (ksAttributeObject) ](ksattributeobject.html) > [ksAttributeObject - методы ](ksattributeobject_methods.html) |  Scroll [ [ [ ](ksattributeobject_ksgetattrrow.html "К следующему разделу")](ksattributeobject_methods.html "На уровень выше")](ksattributeobject_ksgetattrcolumninfo.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksattributeobject.html)

Аналог данного метода при использовании API экспортных функций - [GetAttrKeysInfo](getattrkeysinfo.html).

Синтаксис Automation:

long ksGetAttrKeysInfo (reference pAttr,

long* key1,

long* key2,

long* key3,

long* key4,

double* attrID);

Входной параметр:

pAttr | \- указатель на атрибут.  
---|---  
  
Выходные параметры:

key1, key2, key3, key4 | \- ключи атрибута,  
---|---  
attrID | \- уникальный номер типа атрибута.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Указатель на атрибут reference pAttr может быть получен следующими способами:

•с помощью интерфейса итератора [ksIterator](ksiterator.html) и методов [ksIterator::ksCreateAttrIterator](ksiterator_kscreateattriterator.html), [ksIterator::ksMoveAttrIterator](ksiterator_ksmoveattriterator.html),

•с помощью методов создания атрибутов [ksAttributeObject::ksCreateAttr](ksattributeobject_kscreateattr.html) или выбора атрибутов [ksAttributeObject::ksChoiceAttr](ksattributeobject_kschoiceattr.html).

Подразделы:

(отсутствуют)
