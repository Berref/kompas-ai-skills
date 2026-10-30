# ksGetSpcStyleParamW - Получить параметры указанного стиля спецификации из заданной библиотеки (Unicode)

[API экспортных функций](export_function.html) > [Функции работы с документом-спецификацией ](spc_fncts_common.html) |  Scroll [ [ [ ](ksgetspctablecolumn.html "К следующему разделу")](spc_fncts_common.html "На уровень выше")](ksgetspcstyleparam.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksSpecification::ksGetSpcStyleParam](ksspecification_ksgetspcstyleparam.html).

Синтаксис:

int LIB_FUNK ksGetSpcStyleParamW (LPWSTR nameLib,

unsigned int numb,

void * par,

unsigned int size,

int tPar);

Входные параметры:

nameLib | \- имя библиотеки стилей спецификаций (NULL - параметры берутся у текущего документа),  
---|---  
numb | \- номер стиля спецификации в библиотеке,  
tPar | \- тип возвращаемых параметров.  
  
Выходной параметр:

par | \- структура параметров стиля спецификации,  
---|---  
size | \- размер структуры параметров.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. Если tPar =ALLPARAM, то заполняется структура параметров стиля спецификации [SpcStyleParam...](structspcstyleparam.html).

2\. Если tPar = SPC_TUNING_PARAM, то заполняется заполняется структура параметров настроек спецификации [SpcTuningStyleParam...](structspctuningstyleparam.html).

3\. При использовании ANSI следует использовать функцию [ksGetSpcStyleParam](ksgetspcstyleparam.html).

Подразделы:

(отсутствуют)
