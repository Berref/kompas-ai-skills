# AddBranchByPoint - Добавить прямолинейное ответвление

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Оформление ](bc2273863.html) > [Обозначения ](bc2275772.html) > [Интерфейс IBranchs3D ](ibranchs3d.html) > [IBranchs3D - методы ](ibranchs3d_methods.html) |  Scroll [ [ [ ](ibranchs3d_deletebranch.html "К следующему разделу")](ibranchs3d_methods.html "На уровень выше")](ibranchs3d_addbranch.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ibranchs3d.html)

Синтаксис Automation:

BOOL AddBranchByPoint( double X,

double Y,

double Z,

IModelObject * Object);

Синтаксис COM:

HRESULT AddBranchByPoint( double X,

double Y,

double Z,

IModelObject * Object,

BOOL * Result );

Входные параметры:

Object | \- объект целеуказания,  
---|---  
x, y, z | \- координаты точки целеуказания.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
