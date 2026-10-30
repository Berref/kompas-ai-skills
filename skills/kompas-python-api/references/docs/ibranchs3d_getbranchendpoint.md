# GetBranchEndPoint - Получить координаты конечной точки ответвления

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Оформление ](bc2273863.html) > [Обозначения ](bc2275772.html) > [Интерфейс IBranchs3D ](ibranchs3d.html) > [IBranchs3D - методы ](ibranchs3d_methods.html) |  Scroll [ [ [ ](ibranchs3d_setbranchbeginpoint.html "К следующему разделу")](ibranchs3d_methods.html "На уровень выше")](ibranchs3d_getbranchbeginpoint.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ibranchs3d.html)

Синтаксис Automation:

BOOL GetBranchBeginPoint( long Index,

double * X,

double * Y,

double * Z );

Синтаксис COM:

HRESULT GetBranchBeginPoint( long Index,

double * X,

double * Y,

double * Z,

BOOL * Result );

Входные параметры:

Index | \- индекс ответвления.  
---|---  
  
Выходные параметры:

x, y, z | \- координаты точки.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Метод позволяет получить координаты конечной точки ответвления.

Подразделы:

(отсутствуют)
