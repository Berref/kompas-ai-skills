# ksSetSpcObjectColumnTextEx - Задать текст объекта спецификации для определенного типа колонки и исполнения

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Интерфейсы спецификации ksSpecification, ISpecification ](cb1747230.html) > [Интерфейс спецификации ksSpecification ](ksspecification.html) > [ksSpecification - методы ](ksspecification_methods.html) |  Scroll [ [ [ ](ksspecification_kssetspcobjectcolumntextalign.html "К следующему разделу")](ksspecification_methods.html "На уровень выше")](ksspecification_kssetspcobjectcolumntext.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksspecification.html)

Аналог данного метода при использовании API экспортных функций - [ksSetSpcObjectColumnTextEx](kssetspcobjectcolumntextex.html).

Синтаксис Automation:

long ksSetSpcObjectColumnTextEx (long columnType, long ispoln, long block, LPDISPATCH arr);

Входные параметры:

columnType | \- [тип колонки](ctypes.html), SPC_CLM_FORMAT...SPC_CLM_USER,  
---|---  
ispoln | \- номер колонки данного типа, начиная с 1,  
block | \- номер блока. если block = 0, то количество исполнений меньше количества исполнений в бланке спецификации (для групповой спецификации 2.113-75 количество исполнений меньше 10),  
arr | \- указатель на интерфейс [ksDynamicArray](ksdynamicarray.html) массива строк, тип массива - TEXT_LINE_ARR.  
  
Возвращаемое значение:

1 | \- в случае успеха,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Функция работает в режиме создания нового или редактирования существующего объекта спецификации ksSpcObjectCreate(...); или ksSpcObjectEdit(...);. ksSetSpcObjectColumnTextEx(...);...reference spsObj = ksSpcObjectEnd();

Подразделы:

(отсутствуют)
