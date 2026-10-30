# ksSetSpcDescription - Установить параметры описания спецификации по индексу для указанного документа

[API экспортных функций](export_function.html) > [Функции работы с документом-спецификацией ](spc_fncts_common.html) |  Scroll [ [ [ ](kssetspcdescriptionw.html "К следующему разделу")](spc_fncts_common.html "На уровень выше")](kssetcurrentspcobject.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksspcdescription_example.html)

Аналог данной функции при использовании Automation - метод [ksSpecification::ksSetSpcDescription](ksspecification_kssetspcdescription.html).

Синтаксис:

int ksSetSpcDescription (reference pDoc,

int index,

SpcDescrParam* param,

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

4\. При использовании Unicode следует использовать функцию [ksSetSpcDescriptionW](kssetspcdescriptionw.html).

Подразделы:

(отсутствуют)
