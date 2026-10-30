# ksGetShelfPoint - Получить координаты начала и конца выносной полки и ножки

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Размеры и технологические обозначения ](cm1742473.html) > [Функции построения размеров /обозначений ](dims_signs_fncts_common.html) |  Scroll [ [ [ ](ksgetqualitycontensparam.html "К следующему разделу")](dims_signs_fncts_common.html "На уровень выше")](ksgetleadershelflength.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksDocument2D::ksGetShelfPoint](ksdocument2d_ksgetshelfpoint.html).

Синтаксис:

int LIB_FUNC ksGetShelfPoint( reference p, int index, double *x, double *y, int paramType );

double ksGetLeaderShelfLength (long leader, double *x, double *y);

Входные параметры:

p | \- указатель на объект (размер или линию-выноску),  
---|---  
index | \- индекс точки. Значения индекса: Для линии с ножкой: 1 __ 2 / 0 / Для линии без ножки (с выносной полкой на продолжении выносной линии): 0 __ 1 Точка 0 примыкает к выносной линии;  
paramType | \- тип параметров, задает систему координат: ALLPARAM - в системе координат владельца; SHEET_ALLPARAM - в системе координат листа; VIEW_ALLPARAM - в системе координат вида.  
  
Выходные параметры:

x, y | \- координаты точки.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
