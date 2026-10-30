# ksGetSpcObjectColumnTextW - Получить текст из колонки определенного типа заданного исполнения объекта спецификации (Unicode)

[API экспортных функций](export_function.html) > [Функции работы с документом-спецификацией ](spc_fncts_common.html) |  Scroll [ [ [ ](ksgetspcobjectcolumntextalign.html "К следующему разделу")](spc_fncts_common.html "На уровень выше")](ksgetspcobjectcolumntextex.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksSpecification::ksGetSpcObjectColumnText](ksspecification_ksgetspcobjectcolumntext.html).

Синтаксис:

int ksGetSpcObjectColumnTextW (reference spcObj,

unsigned int columnType

unsigned int ispoln,

unsigned int block,

LPWSTR s,

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

2\. При использовании ANSI следует использовать функцию [ksGetSpcObjectColumnText](ksgetspcobjectcolumntext.html).

Подразделы:

(отсутствуют)
