# GetBasePosition - Получить точку начала выносной линии или привязки знака

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Оформление ](bc2273863.html) > [Обозначения ](bc2275772.html) > [Интерфейс IRough3D ](irough3d.html) > [IRough3D - методы ](irough3d_methods.html) |  Scroll [ [ [ ](irough3d_getposition.html "К следующему разделу")](irough3d_methods.html "На уровень выше")](irough3d_setbaseposition.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](irough3d.html)

Синтаксис Automation:

BOOL GetBasePosition( double * x,

double * x,

double * z );

Синтаксис COM:

HRESULT GetBasePosition( double * x,

double * y,

double * z,

BOOL * Result);

Выходные параметры:

x, y, z | \- координаты точки начала выносной линии или привязки знака.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
