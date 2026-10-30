# ksGetTableColumnText - Получить текст ячейки

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Работа с таблицей и с допуском формы ](bt1731193.html) |  Scroll [ [ [ ](ksdocument2d_ksgettableitemscount.html "К следующему разделу")](bt1731193.html "На уровень выше")](ksdocument2d_ksgettableborderstyle.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [ksGetTableColumnText](ksgettablecolumntext.html).

Синтаксис Automation:

long ksGetTableColumnText (long* numb, LPDISPATCH param);

Выходные параметры:

numb | \- номер ячейки,  
---|---  
param | \- указатель на интерфейс [ksTextParam](kstextparam.html).  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Функция используется в режиме редактирования таблицы.

Нумерация ячеек начинается с единицы.

Если не определен номер ячейки с помощью функции [ksColumnNumber](ksdocument2d_kscolumnnumber.html), метод начинает работу с первой ячейки.

После выполнения метода происходит смещение на следующую ячейку.

Если param=0, все графы пройдены.

Подразделы:

(отсутствуют)
