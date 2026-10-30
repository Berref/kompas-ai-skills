# ksGetSpcPerformanceName - Получить отображаемое имя исполнения

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Интерфейсы спецификации ksSpecification, ISpecification ](cb1747230.html) > [Интерфейс спецификации ksSpecification ](ksspecification.html) > [ksSpecification - методы ](ksspecification_methods.html) |  Scroll [ [ [ ](ksspecification_ksgetspcsectionname.html "К следующему разделу")](ksspecification_methods.html "На уровень выше")](ksspecification_ksgetspcobjectsummarycount.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksspecification.html)

Аналог данного метода при использовании API экспортных функций - [ksGetSpcPerformanceName](ksgetspcperformancename.html).

Синтаксис Automation:

BSTR ksGetSpcPerformanceName( long index,

long ispoln,

long block );

Входные параметры:

index | \- индекс описания СП в документе,  
---|---  
ispoln | \- номер колонки типа "количество", начиная с 1 (актуально для СП типа Б),  
blockNumber | \- номер блока, начиная с 0 (актуально для СП типа A).  
  
Возвращаемое значение:

имя исполнения | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае, если геометрия не подключена или в случае ошибки.  
  
Подразделы:

(отсутствуют)
