# ksGetSpcObjectSummaryCount - Получить суммарное количество для одинаковых объектов

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Интерфейсы спецификации ksSpecification, ISpecification ](cb1747230.html) > [Интерфейс спецификации ksSpecification ](ksspecification.html) > [ksSpecification - методы ](ksspecification_methods.html) |  Scroll [ [ [ ](ksspecification_ksgetspcperformancename.html "К следующему разделу")](ksspecification_methods.html "На уровень выше")](ksspecification_ksgetspcobjectnumber.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksspecification.html)

Аналог данного метода при использовании API экспортных функций - [ksGetSpcObjectSummaryCount](ksgetspcobjectsummarycount.html).

Синтаксис Automation:

double ksGetSpcObjectSummaryCount(long spcObj,

long ispoln,

long blockNumber );

Входные параметры:

spcObj | \- объект спецификации,  
---|---  
ispoln | \- номер колонки типа "количество", начиная с 1 (актуально для СП типа Б ),  
blockNumber | \- номер блока, начиная с 0 ( актуально для СП типа A).  
  
Возвращаемое значение:

| \- cуммарное количество.  
---|---  
  
Подразделы:

(отсутствуют)
