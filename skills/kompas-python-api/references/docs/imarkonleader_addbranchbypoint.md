# AddBranchByPoint - Добавить прямолинейное ответвление

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения для строительства ](bb2362006.html) > [Интерфейс IMark ](imark.html) > [IMark - свойства ](imark_props.html) > [Y - Координата точки привязки марки по Y ](imark_y.html) > [Интерфейс IMarkOnLeader ](imarkonleader.html) > [IMarkOnLeader - методы ](imarkonleader_methods.html) |  Scroll [ [ [ ](imarkonleader_deletebranch.html "К следующему разделу")](imarkonleader_methods.html "На уровень выше")](imarkonleader_addbranch.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imarkonleader.html)

Синтаксис Automation:

BOOL AddBranchByPoint( long Index,

BOOL Begin,

double x, double y );

Синтаксис COM:

HRESULT AddBranchByPoint( long Index,

BOOL Begin,

double x,

double y,

BOOL * Result );

Входные параметры:

index | \- индекс, с которым добавляется ответвление,  
---|---  
Begin | \- признак начала ответвления TRUE - от начала полки, FALSE - от конца полки,  
x, y | \- координаты конца ответвления.  
  
Возвращаемое значение:

TRUE | \- ответвление добавлено,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Значения координат пересчитываются в зависимости от текущей системы координат для объекта, задаваемой параметром [IDrawingObject::DrawingObjectParamType](idrawingobject_drawingobjectparamtype.html)

Подразделы:

(отсутствуют)
