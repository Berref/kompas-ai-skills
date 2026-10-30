# ksClearTableColumnText - Очистить ячейку таблицы или допуска формы

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Работа с таблицей и с допуском формы ](bt1731193.html) |  Scroll [ [ [ ](ksdocument2d_kscolumnnumber.html "К следующему разделу")](bt1731193.html "На уровень выше")](bt1731193.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [ksClearTableColumnText](kscleartablecolumntext.html).

Синтаксис Automation:

long ksClearTableColumnText (long numb);

Входной параметр:

numb | \- номер ячейки,  
---|---  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Если numb = 0, очищается вся таблица.

Нумерация ячеек начинается с 1.

Функция используется в режиме редактирования таблицы или допуска формы.

Подразделы:

(отсутствуют)
