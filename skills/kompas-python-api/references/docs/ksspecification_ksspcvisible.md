# ksSpcVisible - Установить признак видимости компонента

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Интерфейсы спецификации ksSpecification, ISpecification ](cb1747230.html) > [Интерфейс спецификации ksSpecification ](ksspecification.html) > [ksSpecification - методы ](ksspecification_methods.html) |  Scroll [ [ [ ](ispecification3d.html "К следующему разделу")](ksspecification_methods.html "На уровень выше")](ksspecification_ksspcposition.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksspecification.html)

Аналог данного метода при использовании API экспортных функций - [ksSpcVisible](ksspcvisible.html).

Синтаксис Automation:

long ksSpcVisible (long colNumb,

long itemNumb,

short flagOn);

Входные параметры:

colNumb | \- номер колонки, начиная с единицы,  
---|---  
itemNumb | \- номер компоненты, начиная с единицы,  
flagOn | \- признак видимости компонента: 1 -включить, 0- выключить.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечания:

1\. Метод работает в режиме создания нового или редактирования существующего объекта спецификации.

2\. В случае записи в колонке может быть несколько компонент и itemNumb может быть не равен 1.

Подразделы:

(отсутствуют)
