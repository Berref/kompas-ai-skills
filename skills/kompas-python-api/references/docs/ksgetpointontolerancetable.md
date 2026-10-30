# ksGetPointOnToleranceTable - Получить координаты точки на таблице допуска формы

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Работа с таблицей ](table_toler_fncts_common.html) |  Scroll [ [ [ ](ksgettableborderstyle.html "К следующему разделу")](table_toler_fncts_common.html "На уровень выше")](ksdividetableitem.html "К предыдущему разделу")  
---|---  
  
[Пример](ksgetpointontolerancetable_example.html)...

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksGetPointOnToleranceTable](ksdocument2d_ksgetpointontolerancetable.html).

Синтаксис:

int ksGetPointOnToleranceTable (reference tolerance, unsigned char entry, MathPointParam * point);

Входные параметры:

tolerance | \- указатель на допуск формы,  
---|---  
entry | \- [положение базовой точки](tbaseparam.html).  
  
Выходной параметр:

point | \- указатель на структуру параметров математической точки [MathPointParam](structmathpointparam.html).  
---|---  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
