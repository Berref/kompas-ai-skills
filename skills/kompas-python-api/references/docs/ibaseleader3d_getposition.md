# GetPosition - Получить точку, задающую положение объекта

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Оформление ](bc2273863.html) > [Обозначения ](bc2275772.html) > [Интерфейс IBaseLeader3D ](ibaseleader3d.html) > [IBaseLeader3D - методы ](ibaseleader3d_methods.html) |  Scroll [ [ [ ](ibaseleader3d_setposition.html "К следующему разделу")](ibaseleader3d_methods.html "На уровень выше")](ibaseleader3d_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ibaseleader3d.html)

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
