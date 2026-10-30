# AddBranch - Добавить ответвление

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Элементы обозначений ](bb2348381.html) > [Интерфейс IBranchs ](ibranchs.html) > [IBranchs - методы ](ibranchs_methods.html) |  Scroll [ [ [ ](ibranchs_addbranchbypoint.html "К следующему разделу")](ibranchs_methods.html "На уровень выше")](ibranchs_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ibranchs.html)

Синтаксис Automation:

BOOL AddBranch( long Index,

VARIANT Points );

Синтаксис COM:

HRESULT AddBranch( long Index,

VARIANT Points,

BOOL * Result );

Входные параметры:

Index | \- индекс, с которым добавляется ответвление,  
---|---  
Points | \- массив SafeArray координат точек.  
  
Возвращаемое значение:

TRUE | \- ответвление добавлено.  
---|---  
  
Примечание:

1\. Координаты точек в массиве лежат в следующей последовательности: x0, y0, x1, y1, ...xi, yi.

2\. Значения координат зависят от текущей системы координат для объекта, задаваемой параметром [IDrawingObject::DrawingObjectParamType](idrawingobject_drawingobjectparamtype.html).

Подразделы:

(отсутствуют)
