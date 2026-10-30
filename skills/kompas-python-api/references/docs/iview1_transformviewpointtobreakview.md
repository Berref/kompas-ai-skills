# TransformViewPointToBreakView - Перевод координат точки вида без разрывов в CK вида с разрывами

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс IView1 ](iview1.html) > [IView1 - методы ](iview1_methods.html) |  Scroll [ [ [ ](iview1_transformpointfromsheet.html "К следующему разделу")](iview1_methods.html "На уровень выше")](iview1_transformbreakviewpointtoview.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iview1.html)

Синтаксис Automation:

BOOL TransformViewPointToBreakView( double * X, double * Y );

Синтаксис COM:

HRESULT TransformViewPointToBreakView( double * X, double * Y, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

X, Y | \- координаты точки.  
---|---  
  
Версия КОМПАС v22

Подразделы:

(отсутствуют)
