# ksCombineTwoTableItems - Объединить две ячейки таблицы, если они имеют общую границу

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Работа с таблицей и с допуском формы ](bt1731193.html) |  Scroll [ [ [ ](ksdocument2d_ksdividetableitem.html "К следующему разделу")](bt1731193.html "На уровень выше")](ksdocument2d_kscolumnnumber.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [ksCombineTwoTableItems](kscombinetwotableitems.html).

Синтаксис Automation:

long ksCombineTwoTableItems (long index1, long index2);

Входные параметры:

index1 | \- номер первой ячейки,  
---|---  
index2 | \- номер второй ячейки.  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Нумерация ячеек начинается с 1.

Функция используется в режиме редактирования таблицы или допуска формы.

Подразделы:

(отсутствуют)
