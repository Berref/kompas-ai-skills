# AddCut - Добавить разрез

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Параметры ](bb2370796.html) > [Интерфейс ICutViewParam ](icutviewparam.html) > [ICutViewParam - методы ](icutviewparam_methods.html) |  Scroll [ [ [ ](icutviewparam_deletecut.html "К следующему разделу")](icutviewparam_methods.html "На уровень выше")](icutviewparam_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icutviewparam.html)

Синтаксис Automation:

long AddCut( BSTR Name,

long Number,

double X,

double Y,

BOOL ModelCut,

LPDISPATCH * Contour,

LPDISPATCH * View )

Синтаксис COM:

HRESULT AddCut( BSTR Name,

long umber,

double X,

double Y,

BOOL ModelCut,

IDrawingObject * Contour,

IView * View,

long * Index );

Входные параметры:

Name | \- имя разреза,  
---|---  
Number | \- номер разреза,  
X, Y | \- координаты точки, через которую пройдет секущая плоскость,  
ModelCut | \- признак разреза, TRUE - разрез, FALSE - сечение,  
Contour | \- контур, ограничивающий разрез,  
View | \- опорный вид для разреза (проекционный вид для базового вида, в котором создается вырез).  
  
Возвращаемое значение:

| \- Индекс разреза.  
---|---  
  
Примечание:

Метод позволяет добавить разрез.

Подразделы:

(отсутствуют)
