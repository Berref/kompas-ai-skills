# GetAttrTabInfo - Получить информацию по табличному атрибуту

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции работы с атрибутами ](attribs_fncts_common.html) |  Scroll [ [ [ ](getattrtype.html "К следующему разделу")](attribs_fncts_common.html "На уровень выше")](getattrrow.html "К предыдущему разделу")  
---|---  
  
[Пример...](getsizeattrrow_example.html)

Аналог данной функции при использовании Automation - метод [ksAttributeObject::ksGetAttrTabInfo](ksattributeobject_ksgetattrtabinfo.html).

Синтаксис:

int GetAttrTabInfo (reference pAttr, unsigned int * rowsCount, unsigned int * columnsCount);

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
  
Указатель на атрибут reference pAttr может быть получен следующими способами:

– с помощью функций итератора [CreateAttrIterator](createattriterator.html), [MoveAttrIterator](moveattriterator.html),

– с помощью функций создания атрибутов [ksCreateAttr](kscreateattr.html) или выбора атрибутов [ChoiceAttr](choiceattr.html).

Подразделы:

(отсутствуют)
