# NurbsForConicCurve - Создать NURBS по характеристическим точкам конического сечения

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Создание графических объектов ](cm1732355.html) > [Кривые Безье, Nurbs, ломаные ](nurbs_fncts_common.html) |  Scroll [ [ [ ](nurbspoint.html "К следующему разделу")](nurbs_fncts_common.html "На уровень выше")](nurbs.html "К предыдущему разделу")  
---|---  
  
[Пример...](nurbsforconiccurve_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksNurbsForConicCurve](ksdocument2d_ksnurbsforconiccurve.html).

Синтаксис:

reference NurbsForConicCurve (double x[4],

double y[4],

unsigned short style);

Входные параметры:

x[4], y[4] | \- массивы координат характеристических точек конического сечения; точки не должны совпадать, а касательные к кривой в этих точках не должны быть параллельными,  
---|---  
style | \- стиль линии.  
  
[Системные стили линий...](lstyles.html)

Возвращаемое значение:

указатель на NURBS | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
