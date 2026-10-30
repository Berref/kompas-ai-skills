# ksSetToleranceColumnText - Задать текст ячейки допуска формы

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Работа с таблицей ](table_toler_fncts_common.html) |  Scroll [ [ [ ](table.html "К следующему разделу")](table_toler_fncts_common.html "На уровень выше")](kssettableborderstyle.html "К предыдущему разделу")  
---|---  
  
[Пример...](kssettolerancecolumntext_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksSetToleranceColumnText](ksdocument2d_kssettolerancecolumntext.html).

Синтаксис:

int ksSetToleranceColumnText (unsigned int numb, TextLineParam *par);

Входные параметры:

numb | \- номер ячейки,  
---|---  
  
Выходные параметры:

par | \- указатель на структуру параметров строки текста [TextLineParam](structtextlineparam.html).  
---|---  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Функция используется в режиме редактирования допуска формы.

Подразделы:

(отсутствуют)
