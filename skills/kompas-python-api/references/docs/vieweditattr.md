# ViewEditAttr - Вывести диалог для просмотра или редактирования атрибута

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции работы с атрибутами ](attribs_fncts_common.html) |  Scroll [ [ [ ](vieweditattrtype.html "К следующему разделу")](attribs_fncts_common.html "На уровень выше")](setattrvalue.html "К предыдущему разделу")  
---|---  
  
[Пример...](vieweditattr_example.html)

Аналог данной функции при использовании Automation - метод [ksAttributeObject::ksViewEditAttr](ksattributeobject_ksvieweditattr.html).

Синтаксис:

int ViewEditAttr (reference pAttr, unsigned int type, char * password);

Входные параметры:

pAttr | \- указатель на атрибут,  
---|---  
type | \- режим работы: 1 - режим просмотра, 2 - режим редактирования,  
password | \- пароль типа атрибута.  
  
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
