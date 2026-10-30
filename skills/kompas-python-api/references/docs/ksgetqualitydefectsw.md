# ksGetQualityDefectsW - Получить отклонения (Unicode)

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Размеры и технологические обозначения ](cm1742473.html) > [Функции построения размеров /обозначений ](dims_signs_fncts_common.html) |  Scroll [ [ [ ](ksmovequalityiterator.html "К следующему разделу")](dims_signs_fncts_common.html "На уровень выше")](ksgetqualitydefects.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [KompasObject::ksGetQualityDefects](kompasobject_ksgetqualitydefects.html).

Синтаксис:

int LIB_FUNC ksGetQualityDefectsW (const LPWSTRname,

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

При использовании ANSI следует использовать функцию [ksGetQualityDefects](ksgetqualitydefects.html).

Подразделы:

(отсутствуют)
