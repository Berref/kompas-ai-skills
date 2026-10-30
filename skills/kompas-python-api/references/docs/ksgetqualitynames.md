# ksGetQualityNames - Получить массив полей допусков, которые поддерживают размер dimValue и не превышают указанных отклонений

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Работа с видами ](cm1826821.html) > [Функции работы с видами ](views_fncts_common.html) |  Scroll [ [ [ ](kspoint3dtoassociationview.html "К следующему разделу")](views_fncts_common.html "На уровень выше")](kscreatesheetremotevieww.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksgetqualitynames_example.html)

Аналог данной функции при использовании Automation - метод [KompasObject::ksGetQualityNames](kompasobject_ksgetqualitynames.html).

Синтаксис:

int ksGetQualityNames (reference names,

double dimValue,

double high,

double low,

unsigned char system,

unsigned char withLimitation);

Входные параметры:

names | \- указатель на динамический массив полей допусков,  
---|---  
dimValue | \- номинальное значение размера (в мм),  
high | \- верхнее отклонение,  
low | \- нижнее отклонение,  
system | \- система: 1 - отверстия, 0 - вала.  
withLimitation | \- признак учета ограничений: 0 - без учёта ограничений, 1 - с учётом ограничений, наложенных в системе.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
