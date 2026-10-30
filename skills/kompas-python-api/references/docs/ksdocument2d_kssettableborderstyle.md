# ksSetTableBorderStyle - Изменить стиль границы ячейки

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Работа с таблицей и с допуском формы ](bt1731193.html) |  Scroll [ [ [ ](ksdocument2d_kssettolerancecolumntext.html "К следующему разделу")](bt1731193.html "На уровень выше")](ksdocument2d_ksrebuildtablevirtualgrid.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [ksSetTableBorderStyle](kssettableborderstyle.html).

Синтаксис Automation:

long ksSetTableBorderStyle (long index,

short typeBorder,

long style);

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

Нумерация ячеек начинается с 1.

Функция используется в режиме редактирования таблицы или допуска формы.

Подразделы:

(отсутствуют)
