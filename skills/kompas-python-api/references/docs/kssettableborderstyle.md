# ksSetTableBorderStyle - Изменить стиль границы ячейки

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Работа с таблицей ](table_toler_fncts_common.html) |  Scroll [ [ [ ](kssettolerancecolumntext.html "К следующему разделу")](table_toler_fncts_common.html "На уровень выше")](ksrebuildtablevirtualgrid.html "К предыдущему разделу")  
---|---  
  
[Пример...](rab_with_tab_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksSetTableBorderStyle](ksdocument2d_kssettableborderstyle.html).

Синтаксис:

int ksSetTableBorderStyle (unsigned int index, unsigned char typeBorder, unsigned short style);

Входные параметры:

index | \- номер ячейки,  
---|---  
typeBorder | \- тип границы: 0 - левая, 1 - правая, 2 - верхняя, 3 - нижняя,  
style | \- стиль линии границы: 0 - невидимая, 1 - основная, 2 - тонкая, 7 - утолщенная.  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. Нумерация ячеек начинается с 1.

2\. Функция используется в режиме редактирования таблицы или допуска формы.

Подразделы:

(отсутствуют)
