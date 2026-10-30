# ksSetSpcPerformanceName - Установить отображаемое имя исполнения

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Интерфейсы спецификации ksSpecification, ISpecification ](cb1747230.html) > [Интерфейс спецификации ksSpecification ](ksspecification.html) > [ksSpecification - методы ](ksspecification_methods.html) |  Scroll [ [ [ ](ksspecification_kssettuningspcstyleparam.html "К следующему разделу")](ksspecification_methods.html "На уровень выше")](ksspecification_kssetspcobjectcolumntextalign.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksspecification.html)

Аналог данного метода при использовании API экспортных функций - [ksSetSpcPerformanceName](kssetspcperformancename.html).

Синтаксис Automation:

BOOL ksSetSpcPerformanceName( long index,

long ispoln,

long block,

BSTR name );

Входные параметры:

Index | \- индекс описания СП в документе,  
---|---  
Ispoln | \- номер колонки типа Количество, начиная с 1(актуально для СП типа Б),  
blockNumber | \- номер блока, начиная с 0 (актуально для СП типа A),  
Name | \- имя исполнения.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае, если геометрия не подключена или в случае ошибки.  
  
Подразделы:

(отсутствуют)
