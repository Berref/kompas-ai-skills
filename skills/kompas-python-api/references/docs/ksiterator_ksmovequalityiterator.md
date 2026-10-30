# ksMoveQualityIterator - Перемещаться по квалитетам

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Итератор (Интерфейс ksIterator) ](ksiterator.html) > [ksIterator - методы ](ksiterator_methods.html) |  Scroll [ [ [ ](ksltvariant.html "К следующему разделу")](ksiterator_methods.html "На уровень выше")](ksiterator_ksmoveiterator.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksiterator.html)

Аналог данного метода при использовании API экспортных функций - [ksMoveQualityIterator](ksmovequalityiterator.html).

Синтаксис Automation:

BOOL ksMoveQualityIterator (LPDISPATCH param,

short inMM,

BSTR ch);

Входные параметры:

param | \- указатель на интерфейс параметров квалитета [ksQualityContensParam](ksqualitycontensparam.html),  
---|---  
inMM | \- размерность параметров интервала квалитета minLimit, maxLimit, high, low: 1 - миллиметры, 0 - единицы измерения текущего документа.  
ch | \- направление перемещения итератора: F - предыдущий квалитет, N - следующий квалитет.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
