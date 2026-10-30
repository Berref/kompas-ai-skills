# GetAttrColumnInfo - Получить информацию по столбцу

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции работы с атрибутами ](attribs_fncts_common.html) |  Scroll [ [ [ ](getattrkeysinfo.html "К следующему разделу")](attribs_fncts_common.html "На уровень выше")](deleteattrtype.html "К предыдущему разделу")  
---|---  
  
[Пример...](getattrcolumninfo_example.html)

Аналог данной функции при использовании Automation - метод [ksAttributeObject::ksGetAttrColumnInfo](ksattributeobject_ksgetattrcolumninfo.html).

Синтаксис:

int GetAttrColumnInfo (reference pAttr, unsigned int columnNumb, ColumnInfo *columnInfo);

Входные параметры:

pAttr | \- указатель на атрибут,  
---|---  
columnNumb | \- номер колонки.  
  
Выходной параметр:

columnInfo | \- адрес структуры для записи результата.  
---|---  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Указатель на атрибут reference pAttr может быть получен следующими способами:

– с помощью функций итератора [CreateAttrIterator](createattriterator.html), [MoveAttrIterator](moveattriterator.html),

– с помощью функций создания атрибутов [ksCreateAttr](kscreateattr.html) или выбора атрибутов [ChoiceAttr](choiceattr.html).

Подразделы:

(отсутствуют)
