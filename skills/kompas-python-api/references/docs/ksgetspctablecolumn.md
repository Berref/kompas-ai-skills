# ksGetSpcTableColumn - Получить количество колонок для стиля спецификации в текущем документе

[API экспортных функций](export_function.html) > [Функции работы с документом-спецификацией ](spc_fncts_common.html) |  Scroll [ [ [ ](ksgettuningspcstyleparam.html "К следующему разделу")](spc_fncts_common.html "На уровень выше")](ksgetspcstyleparamw.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksgetspctablecolumn_example.html)

Аналог данной функции при использовании Automation - метод [ksSpecification::ksGetSpcTableColumn](ksspecification_ksgetspctablecolumn.html).

Синтаксис:

int ksGetSpcTableColumn (char * nameLib,

unsigned int numb,

unsigned char additioanalCol);

Входные параметры:

nameLib | \- имя библиотеки стилей спецификаций,  
---|---  
numb | \- номер стиля в библиотеке,  
additioanalCol | \- признак колонок: 0 - колонки таблицы спецификации, 1 - дополнительные колонки.  
  
Возвращаемое значение:

количество колонок для стиля спецификации в текущем документе. | \- в случае успеха,  
---|---  
0 | \- в случае неудачи.  
  
Примечания:

1\. Если документ - спецификация, то параметры nameLib и numb не используются.

2\. Если количество исполнений больше числа колонок "количество" в бланке спецификации, то количество колонок выдается с учетом всех исполнений.

Подразделы:

(отсутствуют)
