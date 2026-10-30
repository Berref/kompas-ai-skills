# BasePosition - Установить точку начала выносной линии или привязки знака

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Оформление ](bc2273863.html) > [Обозначения ](bc2275772.html) > [Интерфейс IRough3D ](irough3d.html) > [IRough3D - методы ](irough3d_methods.html) |  Scroll [ [ [ ](irough3d_getbaseposition.html "К следующему разделу")](irough3d_methods.html "На уровень выше")](irough3d_baseobject.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](irough3d.html)

Синтаксис Automation:

BOOL SetBasePosition( double * x,

double * x,

double * z );

Синтаксис COM:

HRESULT SetBasePosition( double * x,

double * y,

double * z,

IModelObject * Object,

BOOL * Result);

Входные параметры:

x, y, z | \- координаты точки начала выносной линии или привязки знака.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
