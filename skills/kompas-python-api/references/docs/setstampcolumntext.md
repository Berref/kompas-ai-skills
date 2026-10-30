# SetStampColumnText - Задать текст графы штампа

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Оформление чертежа ](cm1738404.html) > [Функции оформления чертежа ](draft_design_fncts_common.html) |  Scroll [ [ [ ](cm1740643.html "К следующему разделу")](draft_design_fncts_common.html "На уровень выше")](openstampex.html "К предыдущему разделу")  
---|---  
  
[Пример...](setstampcolumntext_example.html)

Аналог данной функции при использовании Automation - метод [ksStamp::ksSetStampColumnText](ksstamp_kssetstampcolumntext.html).

Синтаксис:

int SetStampColumnText (unsigned int numb,

reference textArr);

Входные параметры:

numb | \- номер ячейки основной надписи,  
---|---  
textArr | \- указатель на динамический массив строк текста - TEXT_LINE_ARR.  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Метод используется в режиме редактирования штампа.

Подразделы:

(отсутствуют)
