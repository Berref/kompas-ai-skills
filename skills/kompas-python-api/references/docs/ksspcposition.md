# ksSpcPosition - Установить номер позиции

[API экспортных функций](export_function.html) > [Функции работы с документом-спецификацией ](spc_fncts_common.html) |  Scroll [ [ [ ](ksspcvisible.html "К следующему разделу")](spc_fncts_common.html "На уровень выше")](ksspcobjectend.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksSpecification::ksSpcPosition](ksspecification_ksspcposition.html).

Синтаксис:

int ksSpcPosition (unsigned short pos);

Входной параметр:

pos | \- номер позиции.  
---|---  
  
Возвращаемое значение:

1 | \- в случае удачного завершения (если в объекте существует колонка с типом Позиция),  
---|---  
0 | \- в случае неудачи.  
  
Примечания:

Функция работает в режиме создания нового или редактирования существующего объекта спецификации, например:

ksSpcObjectCreate(...); или ksSpcObjectEdit(...);

.....

ksSpcPosition(...);

.....

reference spsObj = ksSpcObjectEnd();

Подразделы:

(отсутствуют)
