# ksGetToleranceColumnText - Получить текст ячейки

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Работа с таблицей ](table_toler_fncts_common.html) |  Scroll [ [ [ ](ksopentable.html "К следующему разделу")](table_toler_fncts_common.html "На уровень выше")](ksgettableitemscount.html "К предыдущему разделу")  
---|---  
  
[Пример...](func_red_dop_formy_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksGetToleranceColumnText](ksdocument2d_ksgettolerancecolumntext.html).

Синтаксис:

int ksGetToleranceColumnText (unsigned int *numb, TextLineParam *par);

Выходные параметры:

numb | \- номер ячейки,  
---|---  
par | \- указатель на структуру параметров строки текста [TextLineParam](structtextlineparam.html).  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. Функция используется в режиме редактирования допуска формы.

2\. Нумерация ячеек начинается с единицы.

3\. Если не определен номер ячейки с помощью функции [ColumnNumber](columnnumber.html), функция начинает работу с первой ячейки.

4\. После выполнения функции происходит смещение на следующую ячейку.

5\. Если par=0, все графы пройдены.

6\. После использования массив par->pTextItem желательно удалить.

7\. Если numb = NULL, функция возвращает номер графы.

Подразделы:

(отсутствуют)
