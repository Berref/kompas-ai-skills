# ColumnNumber - Определить номер графы штампа

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Оформление чертежа ](cm1738404.html) > [Функции оформления чертежа ](draft_design_fncts_common.html) |  Scroll [ [ [ ](getstampcolumntext.html "К следующему разделу")](draft_design_fncts_common.html "На уровень выше")](closestamp.html "К предыдущему разделу")  
---|---  
  
[Пример...](open_close_clear_stamp_columnnumber_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksColumnNumber](ksdocument2d_kscolumnnumber.html).

Синтаксис:

int ColumnNumber (unsigned int numb);

Входной параметр:

numb | \- номер ячейки.  
---|---  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Функция используется в режиме редактирования штампа, таблицы, допуска формы, в режиме создания допуска формы.

Подразделы:

(отсутствуют)
