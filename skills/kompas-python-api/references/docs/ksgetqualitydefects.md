# ksGetQualityDefects - Получить отклонения

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Размеры и технологические обозначения ](cm1742473.html) > [Функции построения размеров /обозначений ](dims_signs_fncts_common.html) |  Scroll [ [ [ ](ksgetqualitydefectsw.html "К следующему разделу")](dims_signs_fncts_common.html "На уровень выше")](ksgetqualitycontensparamw.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksgetqualitydefects_example.html)

Аналог данной функции при использовании Automation - метод [KompasObject::ksGetQualityDefects](kompasobject_ksgetqualitydefects.html).

Синтаксис:

int ksGetQualityDefects (const char *name,

double dimValue,

double *high,

double *low,

unsigned char inMM);

Входные параметры:

dimValue | \- значение размера,  
---|---  
inMM | \- размерность параметров dimValue, high, low: 1 - миллиметры, 0 - единицы измерения текущего документа.  
  
Выходные параметры:

name | \- поле допуска, (например, "H7"),  
---|---  
high | \- верхнее отклонение,  
low | \- нижнее отклонение.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание.

При использовании Unicode следует использовать функцию [ksGetQualityDefectsW](ksgetqualitydefectsw.html).

Подразделы:

(отсутствуют)
