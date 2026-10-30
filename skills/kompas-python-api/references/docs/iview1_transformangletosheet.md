# TransformAngleToSheet - Перевод угла из CK вида в CK листа

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс IView1 ](iview1.html) > [IView1 - методы ](iview1_methods.html) |  Scroll [ [ [ ](iview1_transformanglefromsheet.html "К следующему разделу")](iview1_methods.html "На уровень выше")](iview1_selectobjects.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iview1.html)

Синтаксис Automation:

BOOL TransformAngleToSheet( double * Angle );

Синтаксис COM:

HRESULT TransformAngleToSheet( double * Angle, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Angle | \- угол в системе координат вида.  
---|---  
  
Выходные параметры:

Angle | \- угол в системе координат листа.  
---|---  
  
Подразделы:

(отсутствуют)
