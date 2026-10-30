# GetPoint - Получить параметры узла

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс IBezier ](ibezier.html) > [IBezier - методы ](ibezier_methods.html) |  Scroll [ [ [ ](ibezier_readfromfile.html "К следующему разделу")](ibezier_methods.html "На уровень выше")](ibezier_deletepoint.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ibezier.html)

Синтаксис Automation:

BOOL GetPoint( long Index,

double XBase,

double YBase,

double * XLeft,

double * YLeft,

double * XRight,

double * YRight )

Синтаксис COM:

HRESULT GetPoint( long Index,

double XBase,

double YBase,

double * XLeft,

double * YLeft,

double * XRight,

double * YRight,

BOOL * Result )

Входные параметры:

Index | \- индекс узла,  
---|---  
  
Выходные параметры:

XBase, YBase | \- координаты опорной точки узла,  
---|---  
XLeft, YLeft | \- координаты левой точки узла,  
XRight, YRight | \- координаты правой точки узла.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет получить параметры узла кривой Безье.

Подразделы:

(отсутствуют)
