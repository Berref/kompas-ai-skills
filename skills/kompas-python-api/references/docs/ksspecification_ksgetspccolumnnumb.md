# ksGetSpcColumnNumb - Получить номер колонки для данного объекта спецификации

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Интерфейсы спецификации ksSpecification, ISpecification ](cb1747230.html) > [Интерфейс спецификации ksSpecification ](ksspecification.html) > [ksSpecification - методы ](ksspecification_methods.html) |  Scroll [ [ [ ](ksspecification_ksgetspccolumntype.html "К следующему разделу")](ksspecification_methods.html "На уровень выше")](ksspecification_kssetspcpropertyfill.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksspecification.html)

Аналог данного метода при использовании API экспортных функций - [ksGetSpcColumnNumb](ksgetspccolumnnumb.html).

Синтаксис Automation:

long ksGetSpcColumnNumb (long spcObj,

long columnType,

long ispoln,

long block);

Входные параметры:

spcObj | \- указатель на объект спецификации,  
---|---  
columnType | \- [тип колонки](ctypes.html),  
ispoln | \- номер колонки данного типа, начиная с 1,  
block | \- номер блока исполнений.  
  
Возвращаемое значение:

| \- номер колонки спецификации.  
---|---  
  
[Типы колонок спецификации...](ctypes.html)

Подразделы:

(отсутствуют)
