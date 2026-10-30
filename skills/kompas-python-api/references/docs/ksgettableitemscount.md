# ksGetTableItemsCount - Получить количество ячеек в таблице

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Работа с таблицей ](table_toler_fncts_common.html) |  Scroll [ [ [ ](ksgettolerancecolumntext.html "К следующему разделу")](table_toler_fncts_common.html "На уровень выше")](ksgettablecolumntext.html "К предыдущему разделу")  
---|---  
  
[Пример...](rab_with_tab_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksGetTableItemsCount](ksdocument2d_ksgettableitemscount.html).

Синтаксис:

int ksGetTableItemsCount (unsigned char type);

Входной параметр:

type | \- признак, какое число требуется получить: 0 - общее число ячеек, 1 - число ячеек в строке, 2 - число ячеек в колонке.  
---|---  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Функция используется в режиме редактирования таблицы или допуска формы.

Подразделы:

(отсутствуют)
