# ksOpenTable - Открыть таблицу для редактирования

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Работа с таблицей и с допуском формы ](bt1731193.html) |  Scroll [ [ [ ](ksdocument2d_ksopentolerance.html "К следующему разделу")](bt1731193.html "На уровень выше")](ksdocument2d_ksgettolerancecolumntext.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [ksOpenTable](ksopentable.html).

Синтаксис Automation:

long ksOpenTable (long table);

Входной параметр:

table | \- указатель на таблицу.  
---|---  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Чтобы закрыть редактирование таблицы, нужно вызвать функцию [ksDocument2D::ksEndObj](ksdocument2d_ksendobj.html).

Подразделы:

(отсутствуют)
