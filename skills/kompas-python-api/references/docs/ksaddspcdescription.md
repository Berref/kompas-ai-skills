# ksAddSpcDescription - Добавить описание спецификации в графический документ

[API экспортных функций](export_function.html) > [Функции работы с документом-спецификацией ](spc_fncts_common.html) |  Scroll [ [ [ ](ksaddspcdescriptionw.html "К следующему разделу")](spc_fncts_common.html "На уровень выше")](d3spcincludepart.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksspcdescription_example.html)

Аналог данной функции при использовании Automation - метод [ksSpecification::ksAddSpcDescription.](ksspecification_ksaddspcdescription.html)

Синтаксис:

int ksAddSpcDescription (reference pDoc,

SpcDescrParam* param);

Входной параметр:

pDoc | \- указатель на документ,  
---|---  
param | \- параметры описания спецификации.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
[Структура параметров описания спецификации...](structspcdescrparam.html).

Примечание.

При использовании Unicode следует использовать функцию [ksAddSpcDescriptionW](ksaddspcdescriptionw.html).

Подразделы:

(отсутствуют)
