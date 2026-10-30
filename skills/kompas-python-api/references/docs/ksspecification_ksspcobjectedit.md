# ksSpcObjectEdit - Запустить режим редактирования объекта спецификации

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Интерфейсы спецификации ksSpecification, ISpecification ](cb1747230.html) > [Интерфейс спецификации ksSpecification ](ksspecification.html) > [ksSpecification - методы ](ksspecification_methods.html) |  Scroll [ [ [ ](ksspecification_ksspcobjectend.html "К следующему разделу")](ksspecification_methods.html "На уровень выше")](ksspecification_ksspcobjectcreate.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksspecification.html)

Аналог данного метода при использовании API экспортных функций - [ksSpcObjectEdit](ksspcobjectedit.html).

Синтаксис Automation:

long ksSpcObjectEdit (long spcObj);

Входной параметр:

spcObj | \- указатель на объект спецификации.  
---|---  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечания:

1\. После вызова данного метода у объекта можно изменить атрибуты, геометрию, линии выноски, позицию, массу.

2\. Редактирование объекта завершится вызовом метода [ksSpecification::ksSpcObjectEnd](ksspecification_ksspcobjectend.html).

Подразделы:

(отсутствуют)
