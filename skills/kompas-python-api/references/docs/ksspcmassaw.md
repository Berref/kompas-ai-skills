# ksSpcMassaW - Установить массу детали (Unicode)

[API экспортных функций](export_function.html) > [Функции работы с документом-спецификацией ](spc_fncts_common.html) |  Scroll [ [ [ ](ksspcobjectcreate.html "К следующему разделу")](spc_fncts_common.html "На уровень выше")](ksspcmassa.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksSpecification::ksSpcMassa](ksspecification_ksspcmassa.html).

Синтаксис:

int ksSpcMassaW ( LPWSTR sMassa );

Выходной параметр:

sMassa | \- строка с массой детали.  
---|---  
  
Возвращаемое значение:

1 | \- в случае удачного завершения (если в объекте существует колонка типа Масса),  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. Функция работает в режиме создания нового или редактирования существующего объекта спецификации.

[ksSpcObjectCreate](ksspcobjectcreate.html) или [ksSpcObjectEdit](ksspcobjectedit.html);

.....

ksSpcMassaW(...);

.....

reference spsObj = ksSpcObjectEnd();

2\. При использовании ANSI следует использовать функцию [ksSpcMassa](ksspcmassa.html).

Подразделы:

(отсутствуют)
