# ksGetSpcColumnType - Получить параметры колонки по ее номеру для данного объекта спецификации

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Интерфейсы спецификации ksSpecification, ISpecification ](cb1747230.html) > [Интерфейс спецификации ksSpecification ](ksspecification.html) > [ksSpecification - методы ](ksspecification_methods.html) |  Scroll [ [ [ ](ksspecification_ksgetspcdescription.html "К следующему разделу")](ksspecification_methods.html "На уровень выше")](ksspecification_ksgetspccolumnnumb.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksspecification.html)

Аналог данного метода при использовании API экспортных функций - [ksGetSpcColumnType](ksgetspccolumntype.html).

Синтаксис Automation:

long ksGetSpcColumnType (long spcObj,

long colNumb,

LPDISPATCH par);

Входные параметры:

spcObj | \- указатель на объект спецификации,  
---|---  
colNumb | \- номер колонки, начиная с 1.  
  
Выходной параметр:

par | \- указатель на интерфейс параметров колонки [ksSpcColumnParam](ksspccolumnparam.html).  
---|---  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
[Типы колонок спецификации...](ctypes.html)

Примечание:

Если количество исполнений больше числа колонок Количество в бланке спецификации, то недостающие колонки исполнений "пристыкованы" справа от видимых в таблице колонок, затем "пристыкованы" дополнительные колонки

Подразделы:

(отсутствуют)
