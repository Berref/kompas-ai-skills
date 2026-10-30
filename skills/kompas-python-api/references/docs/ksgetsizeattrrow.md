# ksGetSizeAttrRow - Получить длину строки указанного табличного атрибута с указателем

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции работы с атрибутами ](attribs_fncts_common.html) |  Scroll [ [ [ ](ksgetsizeattrroww.html "К следующему разделу")](attribs_fncts_common.html "На уровень выше")](ksgetlibraryattrtypesarray.html "К предыдущему разделу")  
---|---  
  
[Пример...](getsizeattrrow_example.html)

Аналог данной функции при использовании Automation - метод [ksAttributeObject::ksGetSizeAttrRow](ksattributeobject_ksgetsizeattrrow.html).

Синтаксис:

int ksGetSizeAttrRow (reference pAttr, int * count);

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

– с помощью функций итератора [CreateAttrIterator](createattriterator.html), [MoveAttrIterator](moveattriterator.html),

– с помощью функций создания атрибутов [ksCreateAttr](kscreateattr.html) или выбора атрибутов [ChoiceAttr](choiceattr.html)..

2\. При использовании Unicode следует использовать функцию [ksGetSizeAttrRowW](ksgetsizeattrroww.html).

Подразделы:

(отсутствуют)
