# ksPoint3DToAssociationView - Преобразовать координаты 3D точки в координаты ассоциативного вида

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Работа с видами ](cm1826821.html) > [Функции работы с видами ](views_fncts_common.html) |  Scroll [ [ [ ](newviewnumber.html "К следующему разделу")](views_fncts_common.html "На уровень выше")](ksgetqualitynames.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksDocument2D::ksPoint3DToAssociationView](ksdocument2d_kspoint3dtoassociationview.html).

Синтаксис:

int ksPoint3DToAssociationView (reference view,

double x3D, double y3D, double z3D,

double * x2D, double * y2D);

Входные параметры:

view | \- указатель на ассоциативный вид,  
---|---  
x3D, y3D, z3D | \- координаты 3D точки.  
  
Выходные параметры:

x2D, y2D | \- координаты 3D точки в ассоциативном виде.  
---|---  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Если указатель на вид не задан (view = 0), то функция будет выполняться для текущего вида.

Подразделы:

(отсутствуют)
