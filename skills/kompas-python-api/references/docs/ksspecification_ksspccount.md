# ksSpcCount - Установить количество деталей для определенного исполнения

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Интерфейсы спецификации ksSpecification, ISpecification ](cb1747230.html) > [Интерфейс спецификации ksSpecification ](ksspecification.html) > [ksSpecification - методы ](ksspecification_methods.html) |  Scroll [ [ [ ](ksspecification_ksspcdoclinksclear.html "К следующему разделу")](ksspecification_methods.html "На уровень выше")](ksspecification_ksspcchangevalue.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksspecification.html)

Аналог данного метода при использовании API экспортных функций - [ksSpcCount](ksspccount.html).

Синтаксис Automation:

long ksSpcCount (short ispoln,

BSTR sCount);

Входные параметры:

ispoln | \- номер исполнения, начиная с 1,  
---|---  
sCount | \- количество деталей.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения (если в объекте существует колонка с типом Количество).  
---|---  
  
Подразделы:

(отсутствуют)
