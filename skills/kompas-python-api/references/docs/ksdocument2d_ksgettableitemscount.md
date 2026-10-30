# ksGetTableItemsCount - Получить количество ячеек в таблице (для виртуальной сетки)

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Работа с таблицей и с допуском формы ](bt1731193.html) |  Scroll [ [ [ ](ksdocument2d_ksgettolerancecolumntext.html "К следующему разделу")](bt1731193.html "На уровень выше")](ksdocument2d_ksgettablecolumntext.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [ksGetTableItemsCount](ksgettableitemscount.html).

Синтаксис Automation:

long ksGetTableItemsCount (short type);

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
