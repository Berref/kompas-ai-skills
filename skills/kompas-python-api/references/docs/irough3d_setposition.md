# SetPosition - Установить точку, задающую положение плоскости объекта

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Оформление ](bc2273863.html) > [Обозначения ](bc2275772.html) > [Интерфейс IRough3D ](irough3d.html) > [IRough3D - методы ](irough3d_methods.html) |  Scroll [ [ [ ](irough3d_setshelfposition.html "К следующему разделу")](irough3d_methods.html "На уровень выше")](irough3d_getshelfposition.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](irough3d.html)

Синтаксис Automation:

BOOL SetPosition ( double x,

double x,

double z );

Синтаксис COM:

HRESULT SetPosition( double * x,

double * y

double * z

BOOL * Result);

Входные параметры:

x, y, z | \- координаты точки, задающей положения объекта.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
