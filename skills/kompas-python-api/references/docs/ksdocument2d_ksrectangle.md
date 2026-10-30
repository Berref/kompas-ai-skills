# ksRectangle - Создать прямоугольник

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Графические примитивы ](bt1730616.html) |  Scroll [ [ [ ](ksdocument2d_ksregularpolygon.html "К следующему разделу")](bt1730616.html "На уровень выше")](ksdocument2d_kspointarraw.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [ksRectangle](ksrectangle.html).

Синтаксис Automation:

long ksRectangle (LPDISPATCH param,

short centre);

Входные параметры:

param | \- указатель на интерфейс параметров прямоугольника [ksRectangleParam](ksrectangleparam.html),  
---|---  
centre | \- признак построения обозначения центра: 0 - нет осей, 1 - значок осей (маленький "крестик"), 2 - горизонтальная ось, 3 - обе оси.  
  
Возвращаемое значение:

указатель на прямоугольник | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
