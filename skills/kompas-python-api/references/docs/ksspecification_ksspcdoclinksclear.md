# ksSpcDocLinksClear - Создать объект спецификации в графическом документе

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Интерфейсы спецификации ksSpecification, ISpecification ](cb1747230.html) > [Интерфейс спецификации ksSpecification ](ksspecification.html) > [ksSpecification - методы ](ksspecification_methods.html) |  Scroll [ [ [ ](ksspecification_ksspcincludereference.html "К следующему разделу")](ksspecification_methods.html "На уровень выше")](ksspecification_ksspccount.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksspecification.html)

Аналог данного метода при использовании API экспортных функций - [ksSpcObjectCreate](ksspcobjectcreate.html).

Синтаксис Automation:

BOOL ksSpcDocLinksClear( long doc )

Входные параметры:

doc | \- указатель на документ-источник объекта спецификации (графический, 3D, спецификация).  
---|---  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечания:

Функция удаляет связки документа-источника объекта спецификации (графический, 3D, спецификация) с документом-владельцем объекта спецификации;

Если doc = 0, то документом-источником объекта спецификации считается текущий документ.

Подразделы:

(отсутствуют)
