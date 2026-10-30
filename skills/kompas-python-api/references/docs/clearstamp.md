# ClearStamp - Очистить графу штампа чертежа/текстового документа

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Оформление чертежа ](cm1738404.html) > [Функции оформления чертежа ](draft_design_fncts_common.html) |  Scroll [ [ [ ](clearstampex.html "К следующему разделу")](draft_design_fncts_common.html "На уровень выше")](draft_design_fncts_common.html "К предыдущему разделу")  
---|---  
  
[Пример...](open_close_clear_stamp_columnnumber_example.html)

Аналог данной функции при использовании Automation - метод [ksStamp::ksClearStamp](ksstamp_ksclearstamp.html).

Синтаксис:

int ClearStamp (unsigned int numb);

Входной параметр:

numb | \- номер очищаемой ячейки основной надписи (0 - очищается вся основная надпись).  
---|---  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. Метод действителен для чертежа и спецификации.

2\. Функция устарела, рекомендуется вместо нее использовать функцию [ClearStampEx](clearstampex.html).

Подразделы:

(отсутствуют)
