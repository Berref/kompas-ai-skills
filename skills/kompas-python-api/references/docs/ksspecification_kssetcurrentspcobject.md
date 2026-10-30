# ksSetCurrentSpcObject - Установить текущий объект спецификации либо по указателю на него, либо по его индексу

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Интерфейсы спецификации ksSpecification, ISpecification ](cb1747230.html) > [Интерфейс спецификации ksSpecification ](ksspecification.html) > [ksSpecification - методы ](ksspecification_methods.html) |  Scroll [ [ [ ](ksspecification_kssetspcdescription.html "К следующему разделу")](ksspecification_methods.html "На уровень выше")](ksspecification_ksgetwidthcolumnspc.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksspecification.html)

Аналог данного метода при использовании API экспортных функций - [ksSetCurrentSpcObject](kssetcurrentspcobject.html).

Синтаксис Automation:

long ksSetCurrentSpcObject (long spcObj,

long index);

Входные параметры:

spcObj | \- указатель на объект,  
---|---  
index | \- индекс объекта.  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Метод работает для видимых таблиц спецификации.

Подразделы:

(отсутствуют)
