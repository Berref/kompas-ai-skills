# Rotate - Повернуть точку относительно центра

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Вспомогательные построения ](cm1726712.html) > [Математические функции ](math_fncts_common.html) |  Scroll [ [ [ ](sheettoview.html "К следующему разделу")](math_fncts_common.html "На уровень выше")](movepoint.html "К предыдущему разделу")  
---|---  
  
[Пример...](rotate_example.html)

Аналог данной функции при использовании Automation - метод [ksMathematic2D::ksRotate](ksmathematic2d_ksrotate.html).

Синтаксис:

void Rotate (double x, double y, double xc, double yc, double ang, double *xr, double *yr);

Входные параметры:

x, y | \- координаты базовой точки,  
---|---  
xс, yс | \- координаты центра поворота,  
ang | \- угол поворота.  
  
Выходные параметры:

xr, yr | \- координаты точки после поворота.  
---|---  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
