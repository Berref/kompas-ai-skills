# ksSetSpcObjectColumnText - Установить текст колонки определенного типа заданного исполнения объекта спецификации

[API экспортных функций](export_function.html) > [Функции работы с документом-спецификацией ](spc_fncts_common.html) |  Scroll [ [ [ ](kssetspcobjectcolumntextex.html "К следующему разделу")](spc_fncts_common.html "На уровень выше")](kssetspcobjectattributenumber.html "К предыдущему разделу")  
---|---  
  
[Пример...](createspciterator_example.html)

Аналог данной функции при использовании Automation - метод [ksSpecification::ksSetSpcObjectColumnText](ksspecification_kssetspcobjectcolumntext.html).

Синтаксис:

int ksSetSpcObjectColumnText (unsigned int columnType,

unsigned int ispoln,

unsigned int block,

char *s);

Входные параметры:

columnType | \- тип колонки SPC_CLM_FORMAT...SPC_CLM_USER,  
---|---  
ispoln | \- номер исполнения данного типа,  
block | \- номер блока исполнений, начиная с 0 (если количество исполнений меньше количества исполнений в бланке спецификации),  
s | \- строка, из которой нужно взять текст.  
  
[Типы колонок спецификации...](ctypes.html)

Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. Для групповой спецификации 2.113-75 число исполнений меньше 10.

2\. Функция работает в режиме создания нового или редактирования существующего объекта спецификации [ksSpcObjectCreate](ksspcobjectcreate.html) или [ksSpcObjectEdit](ksspcobjectedit.html);

//...

// ksSetSpcObjectColumnText(...);

//...

// reference spsObj = ksSpcObjectEnd();

3\. При использовании Unicode следует использовать функцию [ksSetSpcObjectColumnTextW](kssetspcobjectcolumntextw.html).

Подразделы:

(отсутствуют)
