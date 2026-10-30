# GetBranchBeginPoint - Получить точку привязки обозначения базы на поверхности

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Оформление ](bc2273863.html) > [Обозначения ](bc2275772.html) > [Интерфейс IBase3D ](ibase3d.html) > [IBase3D - методы ](ibase3d_methods.html) |  Scroll [ [ [ ](ibase3d_getbranchendpoint.html "К следующему разделу")](ibase3d_methods.html "На уровень выше")](ibase3d_getposition.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ibase3d.html)

Синтаксис Automation:

BOOL GetBranchBeginPoint( double * x,

double * x,

double * z );

Синтаксис COM:

HRESULT GetBranchBeginPoint( double * x,

double * y,

double * z,

BOOL * Result);

Выходные параметры:

x, y, z | \- координаты точки привязки обозначения базы на поверхности.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
