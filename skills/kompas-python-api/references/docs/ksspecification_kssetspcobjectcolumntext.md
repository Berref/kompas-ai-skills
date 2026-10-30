# ksSetSpcObjectColumnText - Установить текст в колонке определенного типа

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Интерфейсы спецификации ksSpecification, ISpecification ](cb1747230.html) > [Интерфейс спецификации ksSpecification ](ksspecification.html) > [ksSpecification - методы ](ksspecification_methods.html) |  Scroll [ [ [ ](ksspecification_kssetspcobjectcolumntextex.html "К следующему разделу")](ksspecification_methods.html "На уровень выше")](ksspecification_kssetspcobjectattributenumber.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksspecification.html)

Аналог данного метода при использовании API экспортных функций - [ksSetSpcObjectColumnText](kssetspcobjectcolumntext.html).

Синтаксис Automation:

long ksSetSpcObjectColumnText (long columnType,

long ispoln,

long block,

BSTR str);

Входные параметры:

columnType | \- [тип колонки](ctypes.html)[,](ctypes.html)  
---|---  
ispoln | \- номер колонки данного типа,  
block | \- номер блока исполнений, начиная с 0 (если количество исполнений больше числа колонок типа Количество),  
str | \- строка, из которой нужно взять текст.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения.  
---|---  
  
Подразделы:

(отсутствуют)
