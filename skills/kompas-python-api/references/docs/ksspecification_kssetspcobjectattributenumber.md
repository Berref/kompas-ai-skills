# ksSetSpcObjectAttributeNumber - Установить номер атрибута объекта спецификации

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Интерфейсы спецификации ksSpecification, ISpecification ](cb1747230.html) > [Интерфейс спецификации ksSpecification ](ksspecification.html) > [ksSpecification - методы ](ksspecification_methods.html) |  Scroll [ [ [ ](ksspecification_kssetspcobjectcolumntext.html "К следующему разделу")](ksspecification_methods.html "На уровень выше")](ksspecification_kssetspcdescription.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksspecification.html)

Аналог данного метода при использовании API экспортных функций - [ksSetSpcObjectAttributeNumber](kssetspcobjectattributenumber.html).

Синтаксис Automation:

BOOL ksSetSpcObjectAttributeNumber (long spcObj, double attrNumber );

Входные параметры:

spcObj | \- объект спецификации,  
---|---  
attrNumber | \- номер атрибута.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.- в случае неудачи.  
  
Примечания:

Если spcObj = 0, то возвращается номер редактируемого в текущий момент объекта спецификации, т.е. внутри блока:

ksSpcObjectEdit(...);

ksGetSpcObjectAttributeNumber(...);

ksSpcObjectEnd();

Подразделы:

(отсутствуют)
