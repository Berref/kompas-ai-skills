# OpenStamp - Открыть штамп чертежа/текстового документа

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Оформление чертежа ](cm1738404.html) > [Функции оформления чертежа ](draft_design_fncts_common.html) |  Scroll [ [ [ ](openstampex.html "К следующему разделу")](draft_design_fncts_common.html "На уровень выше")](ksrebuilddocument.html "К предыдущему разделу")  
---|---  
  
[Пример...](open_close_clear_stamp_columnnumber_example.html)

Аналог данной функции при использовании Automation - метод [ksStamp::ksOpenStamp](ksstamp_ksopenstamp.html).

Синтаксис:

int OpenStamp();

Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. Следующие далее функции до вызова [CloseStamp ](closestamp.html)определяют текст граф основной надписи штампа.

2\. Функция устарела, рекомендуется вместо нее использовать функцию [OpenStampEx](openstampex.html).

Подразделы:

(отсутствуют)
