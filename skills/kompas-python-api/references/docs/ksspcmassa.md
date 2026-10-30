# ksSpcMassa - Установить массу детали

[API экспортных функций](export_function.html) > [Функции работы с документом-спецификацией ](spc_fncts_common.html) |  Scroll [ [ [ ](ksspcmassaw.html "К следующему разделу")](spc_fncts_common.html "На уровень выше")](ksspcincludereference.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksspcobjectcreate_example.html)

Аналог данной функции при использовании Automation - метод [ksSpecification::ksSpcMassa](ksspecification_ksspcmassa.html).

Синтаксис:

int ksSpcMassa (char * sMassa);

Выходной параметр:

sMassa | \- строка с массой детали.  
---|---  
  
Возвращаемое значение:

1 | \- в случае удачного завершения (если в объекте существует колонка с типом Масса),  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. Функция работает в режиме создания нового или редактирования существующего объекта спецификации.

[ksSpcObjectCreate](ksspcobjectcreate.html) или [ksSpcObjectEdit](ksspcobjectedit.html);

.....

ksSpcMassa(...);

.....

reference spsObj = ksSpcObjectEnd();

2\. При использовании Unicode следует использовать функцию [ksSpcMassaW](ksspcmassaw.html).

Подразделы:

(отсутствуют)
