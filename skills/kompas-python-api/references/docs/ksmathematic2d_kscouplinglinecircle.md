# ksCouplingLineCircle - Получить параметры сопрягающих окружностей определенного радиуса и точки касания при сопряжении окружности и прямой

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейс математических функций (Интерфейс ksMathematic2D) ](ksmathematic2d.html) > [ksMathematic2D - методы ](ksmathematic2d_methods.html) |  Scroll [ [ [ ](ksmathematic2d_kscouplinglineline.html "К следующему разделу")](ksmathematic2d_methods.html "На уровень выше")](ksmathematic2d_kscouplingcirclecircle.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmathematic2d.html)

Аналог данного метода при использовании API экспортных функций - [ksCouplingLineCircle](kscouplinglinecircle.html).

Синтаксис Automation:

BOOL ksCouplingLineCircle (double xc,

double yc,

double radc,

double x1,

double y1,

double angle1,

double rad,

LPDISPATCH param);

Входные параметры:

xc, yc | \- координаты центра окружности,  
---|---  
radc | \- радиус окружности,  
x1, y1 | \- координаты точки на прямой,  
angle1 | \- угол наклона прямой,  
rad | \- радиус окружности сопряжения.  
  
Выходной параметр:

param | \- указатель на интерфейс массива координат точек сопряжения [ksCON](kscon.html).  
---|---  
  
Возвращаемое значение:

TRUE | \- точки касания обнаружены,  
---|---  
FALSE | \- точки касания не обнаружены.  
  
Подразделы:

(отсутствуют)
