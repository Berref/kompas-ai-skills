# ksSpcIncludeReference - Добавить или изменить геометрию графического объекта или линию-выноску в объекте спецификации

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Интерфейсы спецификации ksSpecification, ISpecification ](cb1747230.html) > [Интерфейс спецификации ksSpecification ](ksspecification.html) > [ksSpecification - методы ](ksspecification_methods.html) |  Scroll [ [ [ ](ksspecification_ksspcmassa.html "К следующему разделу")](ksspecification_methods.html "На уровень выше")](ksspecification_ksspcdoclinksclear.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksspecification.html)

Аналог данного метода при использовании API экспортных функций - [ksSpcIncludeReference](ksspcincludereference.html).

Синтаксис Automation:

long ksSpcIncludeReference (long obj,

short clear);

Входные параметры:

obj | \- группа объектов или объект вида,  
---|---  
clear | \- признак обработки существующей геометрии объекта спецификации: 1 - удалить геометрию, 0 - добавить новые объекты к существующей геометрии.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
