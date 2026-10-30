# ksGetSpcObjectSummaryCountText - Выдать отображаемый текст объекта СП для колонки количество и исполнения в виде динамического массива

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Интерфейсы спецификации ksSpecification, ISpecification ](cb1747230.html) > [Интерфейс спецификации ksSpecification ](ksspecification.html) > [ksSpecification - методы ](ksspecification_methods.html) |  Scroll [ [ [ ](ksspecification_ksgetspcpropertyfill.html "К следующему разделу")](ksspecification_methods.html "На уровень выше")](ksspecification_ksgetcurrentspcobject.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksspecification.html)

Аналог данного метода при использовании API экспортных функций - [ksGetSpcObjectSummaryCountText](ksgetspcobjectsummarycounttext.html).

Синтаксис Automation:

LPDISPATCH ksGetSpcObjectSummaryCountText( long spcObj, long ispoln, long block, LPDISPATCH arr );

Входные параметры:

spcObj | \- объект спецификации,  
---|---  
ispoln | \- номер колонки типа "количество", начиная с 1 (актуально для СП типа Б ),  
blockNumber | \- номер блока, начиная с 0 ( актуально для СП типа A).  
  
Возвращаемое значение:

Указатель на на интерфейс [ksDynamicArray](ksdynamicarray.html) | \- в случае успеха,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

•В разных разделах количество может иметь различный тип.

•В разделе Детали стандартные изделия, например, количество имеет целочисленное значение. При объединении нескольких объектов спецификации в этом случае количество суммируется.

•В разделе Материал количество строковое, и текст возвращается с объекта, у которого задано не пустое значение.

•В разделе Документация также формируется объединенное значение.

•В отличии от [ksSpecification::ksGetSpcObjectSummaryCount](ksspecification_ksgetspcobjectsummarycount.html) метод может вернуть не пустое значение для строковых колонок.

Подразделы:

(отсутствуют)
