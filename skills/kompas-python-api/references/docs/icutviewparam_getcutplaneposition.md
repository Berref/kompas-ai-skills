# GetCutPlanePosition - Получить координаты точки, через которую пройдет секущая плоскость

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Параметры ](bb2370796.html) > [Интерфейс ICutViewParam ](icutviewparam.html) > [ICutViewParam - методы ](icutviewparam_methods.html) |  Scroll [ [ [ ](icutviewparam_setcutparams.html "К следующему разделу")](icutviewparam_methods.html "На уровень выше")](icutviewparam_getcutparams.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icutviewparam.html)

Синтаксис Automation:

BOOL GetCutPlanePosition( long Index,

double * X,

double * Y )

Синтаксис COM:

HRESULT GetCutPlanePosition( long Index,

double * X,

double * Y,

BOOL * Result );

Входные параметры:

Index | \- индекс разреза.  
---|---  
  
Выходные параметры:

X, Y | \- координаты точки, через которую пройдет секущая плоскость.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет получить координаты точки, через которую пройдет секущая плоскость.

Подразделы:

(отсутствуют)
