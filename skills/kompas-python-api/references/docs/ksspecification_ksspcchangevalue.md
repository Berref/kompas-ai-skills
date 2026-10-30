# ksSpcChangeValue - Изменить значение компоненты с указанным номером в указанной колонке

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Интерфейсы спецификации ksSpecification, ISpecification ](cb1747230.html) > [Интерфейс спецификации ksSpecification ](ksspecification.html) > [ksSpecification - методы ](ksspecification_methods.html) |  Scroll [ [ [ ](ksspecification_ksspccount.html "К следующему разделу")](ksspecification_methods.html "На уровень выше")](ksspecification_kssettuningspcstyleparam.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksspecification.html)

Аналог данного метода при использовании API экспортных функций - [ksSpcChangeValue](ksspcchangevalue.html).

Синтаксис Automation:

long ksSpcChangeValue (long colNumb,

long itemNumb,

LPDISPATCH userPars,

short typeVal);

Входные параметры:

colNumb | \- номер колонки, начиная с единицы,  
---|---  
itemNumb | \- номер компоненты, начиная с единицы,  
userPars | \- указатель на интерфейс [ksUserParam](ksuserparam.html),  
typeVal | \- тип данных.  
  
[Типы данных..](attypes.html)

Возвращаемое значение:

1 | \- в случае удачного завершения.  
---|---  
  
Примечания:

1\. Метод работает в режиме создания нового или редактирования существующего объекта спецификации.

2\. Если typeVal - запись (RECORD_ATTR_TYPE), в колонке может быть несколько компонент и itemNumb может быть не равен 1.

Подразделы:

(отсутствуют)
