# GetPosition - Получить точку, задающую положение объекта

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Оформление ](bc2273863.html) > [Обозначения ](bc2275772.html) > [Интерфейс ITolerance3D ](itolerance3d.html) > [ITolerance3D - методы ](itolerance3d_methods.html) |  Scroll [ [ [ ](itolerance3d_setposition.html "К следующему разделу")](itolerance3d_methods.html "На уровень выше")](itolerance3d_formattolerance.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](itolerance3d.html)

Синтаксис Automation:

BOOL GetPosition ( double * x,

double * y,

double * z );

Синтаксис COM:

HRESULT GetPosition( double * x,

double * y

double * z

BOOL * Result);

Выходные параметры:

x, y, z | \- координаты точки, задающей положение объекта.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
