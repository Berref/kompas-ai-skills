# ksTanCircleCircle - Получить координаты точек касания прямых к двум окружностям

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейс математических функций (Интерфейс ksMathematic2D) ](ksmathematic2d.html) > [ksMathematic2D - методы ](ksmathematic2d_methods.html) |  Scroll [ [ [ ](ksmathematic2d_kstancurvcurv.html "К следующему разделу")](ksmathematic2d_methods.html "На уровень выше")](ksmathematic2d_kstand.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmathematic2d.html)

Аналог данного метода при использовании API экспортных функций - [TanCircleCircle](tancirclecircle.html).

Синтаксис Automation:

BOOL ksTanCircleCircle (double xc1,

double yc1,

double radius1,

double xc2,

double yc2,

double radius2,

LPDISPATCH param);

Входные параметры:

xc1, yc1 | \- координаты центра первой окружности,  
---|---  
radius1 | \- радиус первой окружности,  
xc2, yc2 | \- координаты центра второй окружности,  
radius2 | \- радиус второй окружности.  
  
Выходной параметр:

param | \- указатель на интерфейс массива координат точек касания [ksTAN](kstan.html).  
---|---  
  
Возвращаемое значение:

TRUE | \- точки касания обнаружены,  
---|---  
FALSE | \- точки касания не обнаружены.  
  
Подразделы:

(отсутствуют)
