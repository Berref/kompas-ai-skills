# GetSpcObjectColumnTextEx - Получить текст объекта спецификации для определенного типа колонки и исполнения в виде динамического массива TEXT_LINE_ARR

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Интерфейсы спецификации ksSpecification, ISpecification ](cb1747230.html) > [Интерфейс спецификации ksSpecification ](ksspecification.html) > [ksSpecification - методы ](ksspecification_methods.html) |  Scroll [ [ [ ](ksspecification_getspcobjectnotify.html "К следующему разделу")](ksspecification_methods.html "На уровень выше")](ksspecification_d3spcincludepart.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksspecification.html)

Аналог данного метода при использовании API экспортных функций - [ksGetSpcObjectColumnTextEx](ksgetspcobjectcolumntextex.html).

Синтаксис Automation:

LPDISPATCH ksGetSpcObjectColumnTextEx (long spcObj, long columnType, long ispoln, long block);

Входные параметры:

spcObj | \- указатель на объект спецификации,  
---|---  
columnType | \- [тип колонки](ctypes.html), SPC_CLM_FORMAT...SPC_CLM_USER,  
ispoln | \- номер колонки данного типа начиная с 1,  
block | \- номер блока, если block = 0, то количество исполнений меньше количества исполнений в бланке спецификации (для групповой спецификации 2.113-75 количество исполнений меньше 10).  
  
Возвращаемое значение:

указатель на интерфейс [ksDynamicArray](ksdynamicarray.html) | \- в случае успеха,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
