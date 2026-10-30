# ksGetSpcObjectColumnText - Получить текст из колонки определенного типа заданного исполнения объекта спецификации

[API экспортных функций](export_function.html) > [Функции работы с документом-спецификацией ](spc_fncts_common.html) |  Scroll [ [ [ ](ksgetspcobjectcolumntextex.html "К следующему разделу")](spc_fncts_common.html "На уровень выше")](ksgetspcobjectattributenumber.html "К предыдущему разделу")  
---|---  
  
[Пример...](createspciterator_example.html)

Аналог данной функции при использовании Automation - метод [ksSpecification::ksGetSpcObjectColumnText](ksspecification_ksgetspcobjectcolumntext.html)

Синтаксис:

int ksGetSpcObjectColumnText (reference spcObj,

unsigned int columnType

unsigned int ispoln,

unsigned int block,

char *s,

unsigned int size_s); // длина строки s

Входные параметры:

spcObj | \- указатель на объект спецификации,  
---|---  
columnType | \- тип колонки SPC_CLM_FORMAT...SPC_CLM_USER,  
ispoln | \- номер исполнения данного типа,  
block | \- номер блока исполнений, начиная с 0 (если количество исполнений меньше количества исполнений в бланке спецификации),  
s | \- указатель на строку, в которую требуется положить полученный текст,  
size_s | длина строки s.  
  
[Типы колонок спецификации...](ctypes.html)

Выходные параметры:

| строка с текстом из колонки.  
---|---  
  
Возвращаемое значение:

0 | \- в случае успешного завершения,  
---|---  
количество символов | \- если длина строки оказалась меньше требуемой size_s,  
-1 | в случае ошибки.  
  
Примечание:

1\. Для групповой спецификации 2.113-75 число исполнений меньше 10.

2\. При использовании Unicode следует использовать функцию [ksGetSpcObjectColumnTextW](ksgetspcobjectcolumntextw.html).

Подразделы:

(отсутствуют)
