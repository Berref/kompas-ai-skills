# ksGetSizeAttrValueW - Получить размер данных ячейки атрибута (Unicode)

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции работы с атрибутами ](attribs_fncts_common.html) |  Scroll [ [ [ ](kssetattrrow.html "К следующему разделу")](attribs_fncts_common.html "На уровень выше")](ksgetsizeattrvalue.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksAttributeObject::ksGetSizeAttrValueW](ksattributeobject_ksgetsizeattrvaluew.html).

Синтаксис:

int ksGetSizeAttrValueW (reference pAttr, unsigned int columnNumb, int *count);

Входные параметры:

pAttr | \- указатель на атрибут,  
---|---  
columnNumb | \- номер колонки.  
  
Выходной параметр:

count | \- число ячеек с учетом записей.  
---|---  
  
Возвращаемое значение:

длина строки ячейки атрибута | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. Указатель на атрибут reference pAttr может быть получен следующими способами:

– с помощью функций итератора [CreateAttrIterator](createattriterator.html), [MoveAttrIterator](moveattriterator.html),

– с помощью функций создания атрибутов [ksCreateAttr](kscreateattr.html) или выбора атрибутов [ChoiceAttr](choiceattr.html)..

2\. При использовании ANSI следует использовать функцию [ksGetSizeAttrValue](ksgetsizeattrvalue.html).

Подразделы:

(отсутствуют)
