# ksDeleteAttr - Удалить атрибут

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы работы с атрибутами ](ck1761772.html) > [Интерфейс работы с атрибутами (ksAttributeObject) ](ksattributeobject.html) > [ksAttributeObject - методы ](ksattributeobject_methods.html) |  Scroll [ [ [ ](ksattributeobject_ksdeleteattrrow.html "К следующему разделу")](ksattributeobject_methods.html "На уровень выше")](ksattributeobject_kscreateattrtype.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksattributeobject.html)

Аналог данного метода при использовании API экспортных функций - [DeleteAttr](deleteattr.html).

Синтаксис Automation:

long ksDeleteAttr (reference pObj,

reference pAttr,

BSTR password);

Входные параметры:

pObj | \- указатель на объект, к которому подключен атрибут. Если pObj = 0 - атрибут текущего документа,  
---|---  
pAttr | \- указатель на удаляемый атрибут,  
password | \- пароль атрибута.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения.  
---|---  
  
Примечание:

1\. Указатель на объект reference pObj может быть получен следующими способами:

•с помощью свойства reference интерфейса соответствующего объекта,

•с помощью интерфейса итератора [ksIterator](ksiterator.html) и методов [ksIterator::ksCreateIterator](ksiterator_kscreateiterator.html), [ksIterator::ksMoveIterator](ksiterator_ksmoveiterator.html).

2\. Указатель на атрибут reference pAttr может быть получен следующими способами:

•с помощью интерфейса итератора [ksIterator](ksiterator.html) и методов [ksIterator::ksCreateAttrIterator](ksiterator_kscreateattriterator.html), [ksIterator::ksMoveAttrIterator](ksiterator_ksmoveattriterator.html),

•с помощью методов создания атрибутов [ksAttributeObject::ksCreateAttr](ksattributeobject_kscreateattr.html) или выбора атрибутов [ksAttributeObject::ksChoiceAttr](ksattributeobject_kschoiceattr.html).

Подразделы:

(отсутствуют)
