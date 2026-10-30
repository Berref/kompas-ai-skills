# ksGetPointOnToleranceTable - Получить координаты точки на таблице допуска формы

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Работа с таблицей и с допуском формы ](bt1731193.html) |  Scroll [ [ [ ](ksdocument2d_ksgettableborderstyle.html "К следующему разделу")](bt1731193.html "На уровень выше")](ksdocument2d_ksdividetableitem.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [ksGetPointOnToleranceTable](ksgetpointontolerancetable.html).

Синтаксис Automation:

long ksGetPointOnToleranceTable (long tolerance,

short entry,

LPDISPATCH point);

Входные параметры:

tolerance | \- указатель на допуск формы,  
---|---  
entry | \- [положение базовой точки](tbaseparam.html).  
  
Выходной параметр:

point | \- указатель на интерфейс параметров математической точки [ksMathPointParam](ksmathpointparam.html).  
---|---  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
