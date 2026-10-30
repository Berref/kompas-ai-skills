# ksGetAttrTabInfo - Получить информацию о количестве строк и столбцов атрибута

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы работы с атрибутами ](ck1761772.html) > [Интерфейс работы с атрибутами (ksAttributeObject) ](ksattributeobject.html) > [ksAttributeObject - методы ](ksattributeobject_methods.html) |  Scroll [ [ [ ](ksattributeobject_ksgetattrtype.html "К следующему разделу")](ksattributeobject_methods.html "На уровень выше")](ksattributeobject_ksgetattrrow.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksattributeobject.html)

Аналог данного метода при использовании API экспортных функций - [GetAttrTabInfo](getattrtabinfo.html).

Синтаксис Automation:

long ksGetAttrTabInfo (long pAttr,

long* rowsCount,

long* columnsCount);

Входной параметр:

pAttr | \- указатель на атрибут.  
---|---  
  
Выходные параметры:

rowsCount | \- количество строк атрибута,  
---|---  
columnsCount | \- количество столбцов атрибута.  
  
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
