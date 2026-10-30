# ksMoveQualityIteratorW - Двигаться по квалитетам (Unicode)

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Размеры и технологические обозначения ](cm1742473.html) > [Функции построения размеров /обозначений ](dims_signs_fncts_common.html) |  Scroll [ [ [ ](ksordinateddimension.html "К следующему разделу")](dims_signs_fncts_common.html "На уровень выше")](ksmovequalityiterator.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksIterator::ksMoveQualityIterator](ksiterator_ksmovequalityiterator.html).

Синтаксис:

int LIB_FUNC ksMoveQualityIteratorW (reference iterator,

QualityContensParamW* param,

unsigned char inMM,

unsigned char ch);

Входные параметры:

inMM | \- размерность параметров minLimit, maxLimit, high, low: 1 - миллиметры, 0 - единицы измерения текущего документа.  
---|---  
ch | \- направление перемещения итератора: F - первый квалитет, N - следующий квалитет.  
  
Выходные параметры:

param | \- указатель на структуру параметров квалитета [StructQualityContensParam](structqualitycontensparam.html).  
---|---  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
