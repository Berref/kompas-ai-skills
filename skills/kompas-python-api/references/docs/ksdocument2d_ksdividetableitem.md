# ksDivideTableItem - Разделить ячейку таблицы

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Работа с таблицей и с допуском формы ](bt1731193.html) |  Scroll [ [ [ ](ksdocument2d_ksgetpointontolerancetable.html "К следующему разделу")](bt1731193.html "На уровень выше")](ksdocument2d_kscombinetwotableitems.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [ksDivideTableItem](ksdividetableitem.html).

Синтаксис Automation:

long ksDivideTableItem (long index,

BOOL vertical,

long style);

Входные параметры:

index | \- номер ячейки,  
---|---  
vertical | \- направление разделения ячейки: 1 - вертикально, 0 - горизонтально,  
style | \- стиль линии получившейся границы: 0 - невидимая, 1 - основная, 2 - тонкая, 7 - утолщенная.  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Нумерация ячеек начинается с 1.

Функция используется в режиме редактирования таблицы или допуска формы.

Подразделы:

(отсутствуют)
