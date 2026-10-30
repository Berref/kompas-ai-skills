# ChoiceAttrTypes - Выдать диалог для просмотра в библиотеке атрибутов списка типов атрибутов и выбора нужного типа

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции работы с атрибутами ](attribs_fncts_common.html) |  Scroll [ [ [ ](createattr.html "К следующему разделу")](attribs_fncts_common.html "На уровень выше")](choiceattr.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksgetattrtype_example.html)

Аналог данной функции при использовании Automation - метод [ksAttributeObject::ksChoiceAttrTypes](ksattributeobject_kschoiceattrtypes.html).

Синтаксис:

double ChoiceAttrTypes (char * libname);

Входной параметр:

libName | \- имя библиотеки типов атрибутов, если libname = NULL, то тип атрибута берется из текущего документа.  
---|---  
  
Возвращаемое значение:

уникальный номер типа атрибута | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Диалог "привязан" к главному окну.

Подразделы:

(отсутствуют)
