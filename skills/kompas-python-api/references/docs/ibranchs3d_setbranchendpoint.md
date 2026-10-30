# SetBranchEndPoint - Установить координаты конечной точки ответвления

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Оформление ](bc2273863.html) > [Обозначения ](bc2275772.html) > [Интерфейс IBranchs3D ](ibranchs3d.html) > [IBranchs3D - методы ](ibranchs3d_methods.html) |  Scroll [ [ [ ](iuserdesignationcompobj.html "К следующему разделу")](ibranchs3d_methods.html "На уровень выше")](ibranchs3d_setbranchbeginpoint.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ibranchs3d.html)

Синтаксис Automation:

BOOL SetBranchEndPoint( long Index,

double X,

double Y,

double Z );

Синтаксис COM:

HRESULT SetBranchEndPoint( long Index,

double X,

double Y,

double Z,

BOOL * Result );

Входные параметры:

Index | \- индекс ответвления,  
---|---  
x, y, z | \- координаты точки.  
  
Возвращаемое значение:

TRUE | \- в случае успеха.  
---|---  
FALSE | \- в случае неудачи.  
  
Метод позволяет установить координаты конечной точки ответвления.

Подразделы:

(отсутствуют)
