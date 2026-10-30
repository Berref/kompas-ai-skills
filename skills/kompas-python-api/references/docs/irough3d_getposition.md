# GetPosition - Получить точку, задающую положение плоскости объекта

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Оформление ](bc2273863.html) > [Обозначения ](bc2275772.html) > [Интерфейс IRough3D ](irough3d.html) > [IRough3D - методы ](irough3d_methods.html) |  Scroll [ [ [ ](irough3d_getshelfposition.html "К следующему разделу")](irough3d_methods.html "На уровень выше")](irough3d_getbaseposition.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](irough3d.html)

Синтаксис Automation:

BOOL GetPosition ( double * x,

double * x,

double * z );

Синтаксис COM:

HRESULT GetPosition( double * x,

double * y

double * z

BOOL * Result);

Выходные параметры:

x, y, z | \- координаты точки, задающей положения объекта.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
