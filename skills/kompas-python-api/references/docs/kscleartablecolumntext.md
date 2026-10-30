# ksClearTableColumnText - Очистить ячейку таблицы или допуска формы

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Работа с таблицей ](table_toler_fncts_common.html) |  Scroll [ [ [ ](kscombinetwotableitems.html "К следующему разделу")](table_toler_fncts_common.html "На уровень выше")](table_toler_fncts_common.html "К предыдущему разделу")  
---|---  
  
[Пример...](rab_with_tab_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksClearTableColumnText](ksdocument2d_kscleartablecolumntext.html).

Синтаксис:

int ksClearTableColumnText (unsigned int numb);

Входной параметр:

numb | \- номер ячейки,  
---|---  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. Если numb = 0, очищается вся таблица.

2\. Нумерация ячеек начинается с 1.

3\. Функция используется в режиме редактирования таблицы или допуска формы.

Подразделы:

(отсутствуют)
