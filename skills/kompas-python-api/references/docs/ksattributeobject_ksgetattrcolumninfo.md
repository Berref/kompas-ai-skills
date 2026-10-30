# ksGetAttrColumnInfo - Получить информацию о столбце атрибута

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы работы с атрибутами ](ck1761772.html) > [Интерфейс работы с атрибутами (ksAttributeObject) ](ksattributeobject.html) > [ksAttributeObject - методы ](ksattributeobject_methods.html) |  Scroll [ [ [ ](ksattributeobject_ksgetattrkeysinfo.html "К следующему разделу")](ksattributeobject_methods.html "На уровень выше")](ksattributeobject_ksdeleteattr3d.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksattributeobject.html)

Аналог данного метода при использовании API экспортных функций - [GetAttrColumnInfo](getattrcolumninfo.html).

Синтаксис Automation:

long ksGetAttrColumnInfo (reference pAttr,

long columnNumb,

LPDISPATCH columnInfo);

Входные параметры:

pAttr | \- указатель на атрибут,  
---|---  
columnNumb | \- номер колонки.  
  
Выходной параметр:

columnInfo | \- указатель на интерфейс параметров столбца табличного атрибута [ksColumnInfoParam](kscolumninfoparam.html).  
---|---  
  
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
