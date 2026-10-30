# ksDivideTableItem - Разделить ячейку таблицы

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Работа с таблицей ](table_toler_fncts_common.html) |  Scroll [ [ [ ](ksgetpointontolerancetable.html "К следующему разделу")](table_toler_fncts_common.html "На уровень выше")](kscombinetwotableitems.html "К предыдущему разделу")  
---|---  
  
[Пример...](rab_with_tab_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksDivideTableItem](ksdocument2d_ksdividetableitem.html).

Синтаксис:

int ksDivideTableItem (unsigned int index, unsigned char vertical, unsigned short style);

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

1\. Нумерация ячеек начинается с 1.

2\. Функция используется в режиме редактирования таблицы или допуска формы.

Подразделы:

(отсутствуют)
