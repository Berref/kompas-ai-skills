# ksSymmetry - Получить координаты точки, симметричной относительно заданной оси

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [Интерфейс математических функций (Интерфейс ksMathematic2D) ](ksmathematic2d.html) > [ksMathematic2D - методы ](ksmathematic2d_methods.html) |  Scroll [ [ [ ](ksmathematic2d_kstand.html "К следующему разделу")](ksmathematic2d_methods.html "На уровень выше")](ksmathematic2d_kssind.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksmathematic2d.html)

Аналог данного метода при использовании API экспортных функций - [Symmetry](symmetry.html).

Синтаксис Automation:

BOOL ksSymmetry (double x,

double y,

double x1,

double y1,

double x2,

double y2,

double* xc,

double* yc);

Входные параметры:

x, y | \- координаты базовой точки,  
---|---  
x1, y1 | \- координаты первой точки на оси симметрии,  
x2, y2 | \- координаты второй точки на оси симметрии.  
  
Выходные параметры:

xc, yc | \- координаты симметричной точки.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения.  
---|---  
  
Подразделы:

(отсутствуют)
