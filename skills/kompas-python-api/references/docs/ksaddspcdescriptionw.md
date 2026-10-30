# ksAddSpcDescriptionW - Добавить описание спецификации в графический документ (Unicode

[API экспортных функций](export_function.html) > [Функции работы с документом-спецификацией ](spc_fncts_common.html) |  Scroll [ [ [ ](ksd3getspcobjgeometry.html "К следующему разделу")](spc_fncts_common.html "На уровень выше")](ksaddspcdescription.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksSpecification::ksAddSpcDescription](ksspecification_ksaddspcdescription.html).

Синтаксис:

int ksAddSpcDescriptionW (reference pDoc,

SpcDescrParamW* param);

Входной параметр:

pDoc | \- указатель на документ,  
---|---  
param | \- параметры описания спецификации.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
[Структура параметров описания спецификации...](structspcdescrparamw.html).

Примечание.

При использовании ANSI следует использовать функцию [ksAddSpcDescription](ksaddspcdescription.html).

Подразделы:

(отсутствуют)
