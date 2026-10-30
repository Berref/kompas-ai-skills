# ksGetQualityDefects - Получить отклонения

[API интерфейсов. Версия 5](ag57940.html) > [KompasObject - Интерфейс API КОМПАС ](kompasobject.html) > [KompasObject - методы ](kompasobject_methods.html) |  Scroll [ [ [ ](kompasobject_ksgetqualitynames.html "К следующему разделу")](kompasobject_methods.html "На уровень выше")](kompasobject_ksgetobjectsfilter3d.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](kompasobject.html)

Аналог данного метода при использовании API экспортных функций - [ksGetQualityDefects](ksgetqualitydefects.html).

Синтаксис Automation:

long ksGetQualityDefects (BSTR name,

double dimValue,

double* high,

double* low,

short inMM);

Входные параметры:

name | \- поле допуска,  
---|---  
dimValue | \- значение размера,  
inMM | \- размерность параметров dimValue, high, low: 1 - миллиметры, 0 - единицы измерения текущего документа.  
  
Выходные параметры:

high | \- верхнее отклонение,  
---|---  
low | \- нижнее отклонение.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
