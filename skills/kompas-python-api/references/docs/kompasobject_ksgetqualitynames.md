# ksGetQualityNames - Получить указатель на динамический массив полей допусков ksDynamicArray, которые поддерживают размер dimValue и не превышают указанных отклонений

[API интерфейсов. Версия 5](ag57940.html) > [KompasObject - Интерфейс API КОМПАС ](kompasobject.html) > [KompasObject - методы ](kompasobject_methods.html) |  Scroll [ [ [ ](kompasobject_ksgetqualitycontensparam.html "К следующему разделу")](kompasobject_methods.html "На уровень выше")](kompasobject_ksgetqualitydefects.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](kompasobject.html)

Аналог данного метода при использовании API экспортных функций - [ksGetQualityNames](ksgetqualitynames.html).

Синтаксис Automation:

long ksGetQualityNames (LPDISPATCH names,

double dimValue,

double high,

double low,

short system,

short withLimitation);

Входные параметры:

names | \- указатель на динамический массив [ksDynamicArray](ksdynamicarray.html) типа CHAR_STR_ARR,  
---|---  
dimValue | \- номинал,  
high | \- верхнее отклонение,  
low | \- нижнее отклонение,  
system | \- система: 1 - отверстия, 0 - вала,  
withLimitation | \- признак учета ограничений: 0 - без учёта ограничений, 1 - с учётом ограничений, наложенных в системе.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
