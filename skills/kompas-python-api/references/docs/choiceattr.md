# ChoiceAttr - Вывести диалог просмотра атрибутов объекта

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции работы с атрибутами ](attribs_fncts_common.html) |  Scroll [ [ [ ](choiceattrtypes.html "К следующему разделу")](attribs_fncts_common.html "На уровень выше")](attribs_fncts_common.html "К предыдущему разделу")  
---|---  
  
[Пример...](choiceattr_example.html)

Аналог данной функции при использовании Automation - метод [ksAttributeObject::ksChoiceAttr](ksattributeobject_kschoiceattr.html).

Синтаксис:

reference ChoiceAttr (reference pObj);

Входной параметр:

pObj | \- указатель на объект, к которому подключены атрибуты.  
---|---  
  
Возвращаемое значение:

указатель на атрибут | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Указатель на объект reference pObj может быть получен следующими способами:

– с помощью Итератора - методами [CreateIterator](createiterator.html), [MoveIterator](moveiterator.html).

– с помощью методов создания объектов, возвращающих указатель reference на созданный объект, например, reference LineSeg.

Подразделы:

(отсутствуют)
