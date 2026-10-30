# ksCouplingCircleCircle - Получить параметры сопрягающих окружностей определенного радиуса и точки сопряжения для двух окружностей

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейс математических функций (Интерфейс ksMathematic2D) ](ksmathematic2d.html) > [ksMathematic2D - методы ](ksmathematic2d_methods.html) |  Scroll [ [ [ ](ksmathematic2d_kscouplinglinecircle.html "К следующему разделу")](ksmathematic2d_methods.html "На уровень выше")](ksmathematic2d_kscosd.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmathematic2d.html)

Аналог данного метода при использовании API экспортных функций - [ksCouplingCircleCircle](kscouplingcirclecircle.html).

Синтаксис Automation:

BOOL ksCouplingCircleCircle (double xc1,

double yc1,

double radc1,

double xc2,

double yc2,

double radc2,

double rad,

LPDISPATCH param);

Входные параметры:

xc1, yc1 | \- координаты центра первой окружности,  
---|---  
rad1 | \- радиус первой окружности,  
xc2, yc2 | \- координаты центра второй окружности,  
Rad | \- радиус второй окружности.  
  
Выходной параметр:

param | \- указатель на интерфейс массива координат точек сопряжения [ksCON](kscon.html).  
---|---  
  
Возвращаемое значение:

TRUE | \- точки касания обнаружены,  
---|---  
FALSE | \- точки касания не обнаружены.  
  
Подразделы:

(отсутствуют)
