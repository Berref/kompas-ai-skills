# ksGetTableColumnText - Получить текст ячейки

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Работа с таблицей ](table_toler_fncts_common.html) |  Scroll [ [ [ ](ksgettableitemscount.html "К следующему разделу")](table_toler_fncts_common.html "На уровень выше")](ksgettableborderstyle.html "К предыдущему разделу")  
---|---  
  
[Пример...](rab_with_tab_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksGetTableColumnText](ksdocument2d_ksgettablecolumntext.html).

Синтаксис:

int ksGetTableColumnText (unsigned int *numb, TextParam *par);

Выходные параметры:

numb | \- номер ячейки,  
---|---  
par | \- указатель на структуру параметров текста [TextParam](structtextparam.html).  
  
Возвращаемое значение:

указатель на динамический массив строк текста - TEXT_LINE_ARR | \- в случае успешного завершения,  
---|---  
0 | \- все графы пройдены,  
номер графы | \- в случае ошибки.  
  
Примечание:

1\. Функция используется в режиме редактирования таблицы.

2\. Нумерация ячеек начинается с единицы.

3\. Если не определен номер ячейки с помощью функции [ColumnNumber](columnnumber.html), функция начинает работу с первой ячейки.

4\. После выполнения метода происходит смещение на следующую ячейку.

Подразделы:

(отсутствуют)
