# ksSpcCountW - Установить количество деталей для определенного исполнения (Unicode)

[API экспортных функций](export_function.html) > [Функции работы с документом-спецификацией ](spc_fncts_common.html) |  Scroll [ [ [ ](ksspcdoclinksclear.html "К следующему разделу")](spc_fncts_common.html "На уровень выше")](ksspccount.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksSpecification::ksSpcCount](ksspecification_ksspccount.html).

Синтаксис:

int ksSpcCountW (unsigned char ispoln, LPWSTR sCount);

Входные параметры:

ispoln | \- номер исполнения, начиная с 1,  
---|---  
sCount | \- количество деталей.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения (если в объекте существует колонка с типом Количество).  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. Функция работает в режиме создания нового или редактирования существующего объекта спецификации.

[ksSpcObjectCreatek](ksspcobjectcreate.html) или [ksSpcObjectEdit](ksspcobjectedit.html);

.....

ksSpcCountW(...);

.....

reference spsObj = ksSpcObjectEnd();

2\. При использовании ANSI следует использовать функцию [ksSpcCount](ksspccount.html).

Подразделы:

(отсутствуют)
