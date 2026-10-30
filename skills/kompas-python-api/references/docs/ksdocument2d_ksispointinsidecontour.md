# ksIsPointInsideContour - Проверить положение точки относительно кривой

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) |  Scroll [ [ [ ](ksdocument2d_ksisslavespcopened.html "К следующему разделу")](ksdocument2d_methods.html "На уровень выше")](ksdocument2d_ksiscurveclosed.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [ksIsPointInsideContour](ksispointinsidecontour.html).

Синтаксис Automation:

long ksIsPointInsideContour (long Reference,

double x,

double y,

double precision);

Входные параметры:

Reference | \- указатель на контур,  
---|---  
x, y | \- координаты точки,  
precision | \- точность проверки (от 1 до 1E-6).  
  
Возвращаемое значение:

0 | \- в случае неудачи,  
---|---  
1 | \- точка вне контура,  
2 | \- точка на контуре,  
3 | \- точка внутри контура.  
  
Подразделы:

(отсутствуют)
