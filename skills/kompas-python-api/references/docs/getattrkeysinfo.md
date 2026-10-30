# GetAttrKeysInfo - Получить информацию для поиска

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции работы с атрибутами ](attribs_fncts_common.html) |  Scroll [ [ [ ](getattrrow.html "К следующему разделу")](attribs_fncts_common.html "На уровень выше")](getattrcolumninfo.html "К предыдущему разделу")  
---|---  
  
[Пример...](getattrkeysinfo_example.html)

Аналог данной функции при использовании Automation - метод [ksAttributeObject::ksGetAttrKeysInfo](ksattributeobject_ksgetattrkeysinfo.html).

Синтаксис:

int GetAttrKeysInfo (reference pAttr,

unsigned int *key1,

unsigned int *key2,

unsigned int *key3,

unsigned int *key4,

double attrID);

Входной параметр:

pAttr | \- указатель на атрибут,  
---|---  
  
Выходные параметры:

key1, key2, key3, key4 | \- ключи атрибута для поиска по значению,  
---|---  
attrID | \- уникальный номер типа атрибута.  
  
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
