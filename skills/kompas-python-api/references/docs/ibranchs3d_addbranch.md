# AddBranch - Добавить ответвление

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Оформление ](bc2273863.html) > [Обозначения ](bc2275772.html) > [Интерфейс IBranchs3D ](ibranchs3d.html) > [IBranchs3D - методы ](ibranchs3d_methods.html) |  Scroll [ [ [ ](ibranchs3d_addbranchbypoint.html "К следующему разделу")](ibranchs3d_methods.html "На уровень выше")](ibranchs3d_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ibranchs3d.html)

Синтаксис Automation:

BOOL AddBranch( VARIANT Points,

LPDISPATCH Object );

Синтаксис COM:

HRESULT AddBranch( VARIANT Points,

IModelObject * Object,

BOOL * Result );

Входные параметры:

Object | \- объект, на который указывает ответвление,  
---|---  
Points | \- массив SafeArray типа VT_ARRAY | VT_R8 координат точек.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

1\. Координаты точек в массиве лежат в следующей последовательности: x0, y0, z0, x1, y1, z1 ...xi, yi, zi.

2\. При задании точек координаты будут спроецированы на плоскость объекта.

Подразделы:

(отсутствуют)
