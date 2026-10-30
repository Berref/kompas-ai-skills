# ksGetSpcDescriptionW - Получить параметры описания спецификации для заданного документа (Unicode)

[API экспортных функций](export_function.html) > [Функции работы с документом-спецификацией ](spc_fncts_common.html) |  Scroll [ [ [ ](ksgetspcdocumentpagescount.html "К следующему разделу")](spc_fncts_common.html "На уровень выше")](ksgetspcdescription.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksSpecification::ksGetSpcDescription](ksspecification_ksgetspcdescription.html).

Синтаксис:

int ksGetSpcDescriptionW (reference pDoc,

int index,

SpcDescrParamW * param,

unsigned char* state);

Входной параметр:

pDoc | \- указатель на документ,  
---|---  
index | \- индекс (номер) описания спецификации в документе.  
  
Выходные параметры:

param | \- структура параметров описания спецификации,  
---|---  
state | \- состояние описания спецификации: TRUE - текущее, FALSE - не текущее.  
  
[Структура параметров описания спецификации...](structspcdescrparamw.html).

Описание:

Функция возвращает параметры описания спецификации для указанного документа.

Примечание:

1\. Если index = -1, берется текущее описание. Для документа-спецификации параметр index не используется.

2\. При использовании ANSI следует использовать функцию [ksGetSpcDescription](ksgetspcdescription.html).

Подразделы:

(отсутствуют)
