# ksSpcCount - Установить количество деталей для определенного исполнения

[API экспортных функций](export_function.html) > [Функции работы с документом-спецификацией ](spc_fncts_common.html) |  Scroll [ [ [ ](ksspccountw.html "К следующему разделу")](spc_fncts_common.html "На уровень выше")](ksspcchangevaluew.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksspcobjectcreate_example.html)

Аналог данной функции при использовании Automation - метод [ksSpecification::ksSpcCount](ksspecification_ksspccount.html).

Синтаксис:

int ksSpcCount (unsigned char ispoln, char * sCount);

Входные параметры:

ispoln | \- номер исполнения, начиная с 1,  
---|---  
sCount | \- количество деталей.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения (если в объекте существует колонка с типом Количество),  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. Функция работает в режиме создания нового или редактирования существующего объекта спецификации.

[ksSpcObjectCreate](ksspcobjectcreate.html) или [ksSpcObjectEdit](ksspcobjectedit.html);

.....

ksSpcCount(...);

.....

reference spsObj = ksSpcObjectEnd();

2\. При использовании Unicode следует использовать функцию [ksSpcCountW](ksspccountw.html).

Подразделы:

(отсутствуют)
