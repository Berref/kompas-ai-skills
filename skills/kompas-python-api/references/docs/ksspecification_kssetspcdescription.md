# ksSetSpcDescription - Установить указатель на интерфейс параметров описания спецификации для указанного документа

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Интерфейсы спецификации ksSpecification, ISpecification ](cb1747230.html) > [Интерфейс спецификации ksSpecification ](ksspecification.html) > [ksSpecification - методы ](ksspecification_methods.html) |  Scroll [ [ [ ](ksspecification_kssetspcobjectattributenumber.html "К следующему разделу")](ksspecification_methods.html "На уровень выше")](ksspecification_kssetcurrentspcobject.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksspecification.html)

Аналог данного метода при использовании API экспортных функций - [ksSetSpcDescription](kssetspcdescription.html).

Синтаксис Automation:

long ksSetSpcDescription (long index,

LPDISPATCH param,

short state);

Входные параметры:

index | \- индекс (номер) описания спецификации в документе (-1 - текущее описание),  
---|---  
param | \- указатель на интерфейс параметров описания спецификации [ksSpcDescrParam](ksspcdescrparam.html),  
state | \- состояние описания спецификации: TRUE - текущее, FALSE - не текущее.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения.  
---|---  
  
Примечания:

1\. Метод изменяет параметры описания спецификации и/или делает его активным, если state = TRUE.

2\. Если param = NULL - меняется только состояние.

3\. Для документа-спецификации параметр index не используется.

Подразделы:

(отсутствуют)
