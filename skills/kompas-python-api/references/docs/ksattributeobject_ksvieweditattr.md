# ksViewEditAttr - Вывести диалог для просмотра или редактирования атрибута

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы работы с атрибутами ](ck1761772.html) > [Интерфейс работы с атрибутами (ksAttributeObject) ](ksattributeobject.html) > [ksAttributeObject - методы ](ksattributeobject_methods.html) |  Scroll [ [ [ ](ksattributeobject_ksvieweditattrtype.html "К следующему разделу")](ksattributeobject_methods.html "На уровень выше")](ksattributeobject_kssetattrvalue.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksattributeobject.html)

Аналог данного метода при использовании API экспортных функций - [ViewEditAttr](vieweditattr.html).

Синтаксис Automation:

long ksViewEditAttr (reference pAttr,

long type,

BSTR password);

Входные параметры:

pAttr | \- указатель на атрибут,  
---|---  
type | \- режим работы: \- 1 - режим просмотра, 2 - режим редактирования  
password | \- пароль типа атрибута.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения.  
---|---  
  
Примечание:

1\. Диалог "привязан" к главному окну.

2\. Указатель на атрибут reference pAttr может быть получен следующими способами:

•с помощью интерфейса итератора [ksIterator](ksiterator.html) и методов [ksIterator::ksCreateAttrIterator](ksiterator_kscreateattriterator.html), [ksIterator::ksMoveAttrIterator](ksiterator_ksmoveattriterator.html),

•с помощью методов создания атрибутов [ksAttributeObject::ksCreateAttr](ksattributeobject_kscreateattr.html) или выбора атрибутов [ksAttributeObject::ksChoiceAttr](ksattributeobject_kschoiceattr.html).

Подразделы:

(отсутствуют)
