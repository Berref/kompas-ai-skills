# ksGetSizeAttrRow - Получить размер данных строки атрибутов

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы работы с атрибутами ](ck1761772.html) > [Интерфейс работы с атрибутами (ksAttributeObject) ](ksattributeobject.html) > [ksAttributeObject - методы ](ksattributeobject_methods.html) |  Scroll [ [ [ ](ksattributeobject_ksgetsizeattrroww.html "К следующему разделу")](ksattributeobject_methods.html "На уровень выше")](ksattributeobject_ksgetlibraryattrtypesarray.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksattributeobject.html)

Аналог данного метода при использовании API экспортных функций - [ksGetSizeAttrRow](ksgetsizeattrrow.html).

Синтаксис Automation:

long ksGetSizeAttrRow (reference pAttr,

long* count);

Входной параметр:

pAttr | \- указатель на атрибут.  
---|---  
  
Выходной параметр:

count | \- число ячеек с учетом записей.  
---|---  
  
Возвращаемое значение:

длина строки атрибута | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. Указатель на атрибут reference pAttr может быть получен следующими способами:

•с помощью интерфейса итератора [ksIterator](ksiterator.html) и методов [ksIterator::ksCreateAttrIterator](ksiterator_kscreateattriterator.html), [ksIterator::ksMoveAttrIterator](ksiterator_ksmoveattriterator.html),

•с помощью методов создания атрибутов [ksAttributeObject::ksCreateAttr](ksattributeobject_kscreateattr.html) или выбора атрибутов [ksAttributeObject::ksChoiceAttr](ksattributeobject_kschoiceattr.html).

2\. При использовании данного метода, не использующего Unicode, размер данных строкового типа будет рассчитываться для unicode строк, как для ANSI строк.

Подразделы:

(отсутствуют)
