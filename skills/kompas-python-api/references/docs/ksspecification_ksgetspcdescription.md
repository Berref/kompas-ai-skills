# ksGetSpcDescription - Получить указатель на интерфейс параметров описания спецификации для указанного документа

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Интерфейсы спецификации ksSpecification, ISpecification ](cb1747230.html) > [Интерфейс спецификации ksSpecification ](ksspecification.html) > [ksSpecification - методы ](ksspecification_methods.html) |  Scroll [ [ [ ](ksspecification_ksgetspcobjforgeom.html "К следующему разделу")](ksspecification_methods.html "На уровень выше")](ksspecification_ksgetspccolumntype.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksspecification.html)

Аналог данного метода при использовании API экспортных функций - [ksGetSpcDescription](ksgetspcdescription.html).

Синтаксис Automation:

long ksGetSpcDescription (long index,

LPDISPATCH param,

BOOL* state);

Входной параметр:

index | \- индекс (номер) описания спецификации в документе (-1 - текущее описание).  
---|---  
  
Выходные параметры:

param | \- указатель на интерфейс [ksSpcDescrParam](ksspcdescrparam.html) параметров описания спецификации,  
---|---  
state | \- состояние описания спецификации: TRUE - текущее, FALSE - не текущее.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Для документа-спецификации параметр index не используется.

Подразделы:

(отсутствуют)
