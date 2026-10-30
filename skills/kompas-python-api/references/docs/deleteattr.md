# DeleteAttr - Удалить атрибут объекта

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции работы с атрибутами ](attribs_fncts_common.html) |  Scroll [ [ [ ](deleteattrtype.html "К следующему разделу")](attribs_fncts_common.html "На уровень выше")](createattrtype.html "К предыдущему разделу")  
---|---  
  
[Пример...](deleteattr_example.html)

Аналог данной функции при использовании Automation - метод [ksAttributeObject::ksDeleteAttr](ksattributeobject_ksdeleteattr.html).

Синтаксис:

int DeleteAttr (reference pObj, reference PAttr, char * password);

Входные параметры:

pObj | \- указатель на объект, к которому подключен атрибут. Если pObj = 0 - атрибут текущего документа,  
---|---  
pAttr | \- указатель на удаляемый атрибут,  
password | \- пароль атрибута.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. Указатель на объект reference pObj может быть получен следующими способами:

– с помощью функций Итератора [CreateIterator](createiterator.html), [MoveIterator](moveiterator.html).

– с помощью методов создания объектов, возвращающих указатель reference на созданный объект, например, reference LineSeg.

2\. Указатель на атрибут reference pAttr может быть получен:

– с помощью функций итератора [CreateAttrIterator](createattriterator.html), [MoveAttrIterator](moveattriterator.html),

– с помощью функций создания атрибутов [ksCreateAttr](kscreateattr.html), или выбора атрибутов [ChoiceAttr](choiceattr.html).

Подразделы:

(отсутствуют)
