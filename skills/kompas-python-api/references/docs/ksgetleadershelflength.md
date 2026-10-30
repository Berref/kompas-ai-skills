# ksGetLeaderShelfLength - Получить длину полки линии-выноски и координаты ее конечной точки в системе координат вида

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Размеры и технологические обозначения ](cm1742473.html) > [Функции построения размеров /обозначений ](dims_signs_fncts_common.html) |  Scroll [ [ [ ](ksgetshelfpoint.html "К следующему разделу")](dims_signs_fncts_common.html "На уровень выше")](ksexecqualitydialogw.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksDocument2D::ksGetLeaderShelfLength](ksdocument2d_ksgetleadershelflength.html).

Синтаксис:

double ksGetLeaderShelfLength (long leader, double *x, double *y);

Входные параметры:

leader | \- указатель на линию-выноску.  
---|---  
  
Выходные параметры:

x | \- координата конечной точки полки линии-выноски по оси X,  
---|---  
y | \- координата конечной точки полки линии-выноски по оси Y.  
  
Подразделы:

(отсутствуют)
