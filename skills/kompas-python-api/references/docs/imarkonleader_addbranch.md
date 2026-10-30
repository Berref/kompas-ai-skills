# AddBranch - Добавить ответвление

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения для строительства ](bb2362006.html) > [Интерфейс IMark ](imark.html) > [IMark - свойства ](imark_props.html) > [Y - Координата точки привязки марки по Y ](imark_y.html) > [Интерфейс IMarkOnLeader ](imarkonleader.html) > [IMarkOnLeader - методы ](imarkonleader_methods.html) |  Scroll [ [ [ ](imarkonleader_addbranchbypoint.html "К следующему разделу")](imarkonleader_methods.html "На уровень выше")](imarkonleader_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imarkonleader.html)

Синтаксис Automation:

BOOL AddBranch( long Index,

BOOL Begin,

VARIANT Points );

Синтаксис COM:

HRESULT AddBranch( long Index,

BOOL Begin,

VARIANT Points,

BOOL * Result );

Входные параметры:

index | \- индекс, с которым добавляется ответвление,  
---|---  
Begin | \- признак начала ответвления TRUE - от начала полки, FALSE - от конца полки,  
Points | \- массив SafeArray координат точек.  
  
Возвращаемое значение:

TRUE | \- ответвление добавлено,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

1\. Координаты точек в массиве лежат в следующей последовательности: x0, y0, x1, y1, ...xi, yi.

2\. Значения координат зависят от текущей системы координат для объекта, задаваемой параметром [IDrawingObject::DrawingObjectParamType](idrawingobject_drawingobjectparamtype.html)

Подразделы:

(отсутствуют)
