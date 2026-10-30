# TransformPointFromSheet - Перевод координат точки из CK листа в CK вида

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс IView1 ](iview1.html) > [IView1 - методы ](iview1_methods.html) |  Scroll [ [ [ ](iview1_transformpointtosheet.html "К следующему разделу")](iview1_methods.html "На уровень выше")](iview1_transformviewpointtobreakview.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iview1.html)

Синтаксис Automation:

BOOL TransformPointFromSheet( double * X, double * Y );

Синтаксис COM:

HRESULT TransformPointFromSheet( double * X, double * Y, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

X, Y | \- координаты точек в системе координат листа.  
---|---  
  
Выходные параметры:

X, Y | \- координаты точек в системе координат вида.  
---|---  
  
Подразделы:

(отсутствуют)
