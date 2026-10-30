# AddBranchByPoint - Добавить прямолинейное ответвление

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Элементы обозначений ](bb2348381.html) > [Интерфейс IBranchs ](ibranchs.html) > [IBranchs - методы ](ibranchs_methods.html) |  Scroll [ [ [ ](ibranchs_deletebranch.html "К следующему разделу")](ibranchs_methods.html "На уровень выше")](ibranchs_addbranch.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ibranchs.html)

Синтаксис Automation:

BOOL AddBranchByPoint( long Index,

double X,

double Y );

Синтаксис COM:

HRESULT AddBranchByPoint( long Index,

double X,

double Y,

BOOL * Result );

Входные параметры:

Index | \- индекс, с которым добавляется ответвление,  
---|---  
x, y | \- координаты точки целеуказания.  
  
Возвращаемое значение:

TRUE | \- ответвление добавлено.  
---|---  
  
Примечание:

Значения координат зависят от текущей системы координат для объекта, задаваемой параметром [IDrawingObject::DrawingObjectParamType](idrawingobject_drawingobjectparamtype.html).

Подразделы:

(отсутствуют)
