# ksSetSpcDescriptionW - Установить параметры описания спецификации по индексу для указанного документа (Unicode)

[API экспортных функций](export_function.html) > [Функции работы с документом-спецификацией ](spc_fncts_common.html) |  Scroll [ [ [ ](kssetspcobjectattributenumber.html "К следующему разделу")](spc_fncts_common.html "На уровень выше")](kssetspcdescription.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksSpecification::ksSetSpcDescription](ksspecification_kssetspcdescription.html).

Синтаксис:

int ksSetSpcDescriptionW (reference pDoc,

int index,

SpcDescrParamW* param,

unsigned char state);

Входные параметры:

pDoc | \- указатель на документ,  
---|---  
index | \- индекс (номер) описания спецификации в документе (-1 - текущее описание),  
param | \- указатель на параметры описания спецификации,  
state | \- состояние описания спецификации: TRUE - текущее, FALSE - не текущее.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
[Структура параметров описания спецификации...](structspcdescrparam.html).

Примечания:

1\. Метод изменяет параметры описания спецификации и/или делает его активным, если state = TRUE.

2\. Если param = NULL - меняется только состояние.

3\. Для документа-спецификации параметр index не используется.

4\. При использовании ANSI следует использовать функцию [ksSetSpcDescription](kssetspcdescription.html).

Подразделы:

(отсутствуют)
