# ksGetSpcObjectColumnText - Получить строку с текстом из определенной колонки объекта спецификации

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Интерфейсы спецификации ksSpecification, ISpecification ](cb1747230.html) > [Интерфейс спецификации ksSpecification ](ksspecification.html) > [ksSpecification - методы ](ksspecification_methods.html) |  Scroll [ [ [ ](ksspecification_ksgetspcobjectcolumntextalign.html "К следующему разделу")](ksspecification_methods.html "На уровень выше")](ksspecification_ksgetspcobjectattributenumber.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksspecification.html)

Аналог данного метода при использовании API экспортных функций - [ksGetSpcObjectColumnText](ksgetspcobjectcolumntext.html).

Синтаксис Automation:

BSTR ksGetSpcObjectColumnText (long spcObj,

long columnType,

long ispoln,

long block);

Входные параметры:

spcObj | \- указатель на объект спецификации,  
---|---  
columnType | \- [тип колонки](ctypes.html),  
ispoln | \- номер колонки данного типа, начиная с 1,  
block | \- номер блока исполнений, начиная с 0 (если количество исполнений больше числа колонок типа Количество).  
  
[Типы колонок спецификации...](ctypes.html)

Возвращаемое значение:

| \- строка с текстом из колонки.  
---|---  
  
Подразделы:

(отсутствуют)
