# AddPoint - Добавить узел

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс IBezier ](ibezier.html) > [IBezier - методы ](ibezier_methods.html) |  Scroll [ [ [ ](ibezier_clear.html "К следующему разделу")](ibezier_methods.html "На уровень выше")](ibezier_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс..](ibezier.html)

Синтаксис Automation:

BOOL AddPoint( long Index,

double XBase,

double YBase,

double * XLeft,

double * YLeft,

double * XRight,

double * YRight )

Синтаксис COM:

HRESULT AddPoint( long Index,

double XBase,

double YBase,

double * XLeft,

double * YLeft,

double * XRight,

double * YRight,

BOOL * Result )

Входные параметры:

Index | \- индекс добавляемого узла,  
---|---  
XBase, YBase | \- координаты опорной точки узла,  
XLeft, YLeft | \- координаты левой точки узла,  
XRight, YRight | \- координаты правой точки узла.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет добавить узел в кривую Безье.

Подразделы:

(отсутствуют)
