# ksCombineTwoTableItems - Объединить две ячейки таблицы, если они имеют общее ребро

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Работа с таблицей ](table_toler_fncts_common.html) |  Scroll [ [ [ ](ksdividetableitem.html "К следующему разделу")](table_toler_fncts_common.html "На уровень выше")](kscleartablecolumntext.html "К предыдущему разделу")  
---|---  
  
[Пример...](rab_with_tab_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksCombineTwoTableItems](ksdocument2d_kscombinetwotableitems.html).

Синтаксис:

int ksCombineTwoTableItems (unsigned int index1, unsigned int index2);

Входные параметры:

index1 | \- номер первой ячейки,  
---|---  
index2 | \- номер второй ячейки.  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. Нумерация ячеек начинается с 1.

2\. Функция используется в режиме редактирования таблицы или допуска формы.

Подразделы:

(отсутствуют)
