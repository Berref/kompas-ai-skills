# ksMoveAttrIterator - Перемещаться по атрибутам

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Итератор (Интерфейс ksIterator) ](ksiterator.html) > [ksIterator - методы ](ksiterator_methods.html) |  Scroll [ [ [ ](ksiterator_ksmoveiterator.html "К следующему разделу")](ksiterator_methods.html "На уровень выше")](ksiterator_ksdeleteiterator.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksiterator.html)

Аналог данного метода при использовании API экспортных функций - [MoveAttrIterator](moveattriterator.html).

Синтаксис Automation:

long ksMoveAttrIterator (BSTR ch,

long* pObj);

Входные параметры:

ch | \- направление перемещения итератора: F - первый атрибут, N - следующий атрибут,  
---|---  
pObj | \- указатель на группу.  
  
Возвращаемое значение:

указатель на атрибут | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Если итератор создан для движения по элементам с определенным атрибутом, то pObj - указатель на объект с данным атрибутом.

Подразделы:

(отсутствуют)
