# ksSetSpcObjectColumnTextW - Установить текст колонки определенного типа заданного исполнения объекта спецификации (Unicode)

[API экспортных функций](export_function.html) > [Функции работы с документом-спецификацией ](spc_fncts_common.html) |  Scroll [ [ [ ](kssetspcobjectcolumntextalign.html "К следующему разделу")](spc_fncts_common.html "На уровень выше")](kssetspcobjectcolumntextex.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksSpecification::ksSetSpcObjectColumnText](ksspecification_kssetspcobjectcolumntext.html).

Синтаксис:

int ksSetSpcObjectColumnTextW (unsigned int columnType,

unsigned int ispoln,

unsigned int block,

LPWSTR s);

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

2\. Функция работает в режиме создания нового или редактирования существующего объекта спецификации

[ksSpcObjectCreate](ksspcobjectcreate.html) или [ksSpcObjectEdit](ksspcobjectedit.html) (Unicode)

//...

//ksSetSpcObjectColumnTextW(...);

//...

// reference spsObj = ksSpcObjectEnd();

3\. При использовании ANSI следует использовать функцию [ksSetSpcObjectColumnText](kssetspcobjectcolumntext.html).

Подразделы:

(отсутствуют)
