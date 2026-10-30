# MoveAttrIterator - Перебирать атрибуты по итератору

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции работы с атрибутами ](attribs_fncts_common.html) |  Scroll [ [ [ ](setattrrow.html "К следующему разделу")](attribs_fncts_common.html "На уровень выше")](kssetattrvaluew.html "К предыдущему разделу")  
---|---  
  
[Пример...](createattriterator_example.html)

Аналог данной функции при использовании Automation - метод [ksIterator::ksMoveAttrIterator](ksiterator_ksmoveattriterator.html).

Синтаксис:

reference MoveAttrIterator (reference iterator,

unsigned char ch,

reference * pObj);

Входные параметры:

iterator | \- указатель на итератор,  
---|---  
ch | \- направление перемещения итератора: F - первый атрибут, N - следующий атрибут,  
pObj | \- указатель на группу.  
  
Возвращаемое значение:

указатель на атрибут | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Если итератор создан для движения по элементам с определенным атрибутом, то pObj - указатель на объект с данным атрибутом. Если pObj = NULL, pObj не заполняется.

Подразделы:

(отсутствуют)
