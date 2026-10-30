# GetPoint - Получить параметры точки

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс INurbs ](inurbs.html) > [INurbs - методы ](inurbs_methods.html) |  Scroll [ [ [ ](inurbs_readfromfile.html "К следующему разделу")](inurbs_methods.html "На уровень выше")](inurbs_getnurbsparams.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](inurbs.html)

Синтаксис Automation:

BOOL GetPoint( long Index,

double * X,

double * Y,

double * Weight );

Синтаксис COM:

HRESULT GetPoint( long Index,

double * X,

double * Y,

double * Weight,

BOOL * Result );

Входные параметры:

Index | \- индекс точки.  
---|---  
  
Выходные параметры:

x, y | \- координаты точки,  
---|---  
Weight | \- массив SAFEARRAY | VT_R8 весов точек.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет получить параметры точки NURBS-кривой в виде массивов SAFEARRAY | VT_R8.

Подразделы:

(отсутствуют)
