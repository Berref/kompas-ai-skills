# ksGetQualityContensParam - Получить параметры квалитета

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Размеры и технологические обозначения ](cm1742473.html) > [Функции построения размеров /обозначений ](dims_signs_fncts_common.html) |  Scroll [ [ [ ](ksgetqualitycontensparamw.html "К следующему разделу")](dims_signs_fncts_common.html "На уровень выше")](ksgetshelfpoint.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksgetqualitycontensparam_example.html)

Аналог данной функции при использовании Automation - метод [KompasObject::ksGetQualityContensParam](kompasobject_ksgetqualitycontensparam.html).

Синтаксис:

int ksGetQualityContensParam (const char* name,

QualityContensParam* param,

unsigned char inMM);

Входные параметры:

inMM | \- размерность параметров minLimit, maxLimit, high, low: 1 - миллиметры, 0 - единицы измерения текущего документа.  
---|---  
  
Выходной параметр:

param | \- указатель на структуру параметров квалитета [QualityContensParam](structqualitycontensparam.html).  
---|---  
name | \- поле допуска.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание.

При использовании Unicode следует использовать функцию [ksGetQualityContensParamW](ksgetqualitycontensparamw.html).

Подразделы:

(отсутствуют)
