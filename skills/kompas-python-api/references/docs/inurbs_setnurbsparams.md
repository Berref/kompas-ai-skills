# SetNurbsParams - Установить параметры NURBS-кривой

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс INurbs ](inurbs.html) > [INurbs - методы ](inurbs_methods.html) |  Scroll [ [ [ ](inurbs_writetofile.html "К следующему разделу")](inurbs_methods.html "На уровень выше")](inurbs_readfromfile.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](inurbs.html)

Синтаксис Automation:

BOOL SetNurbsParams( VARIANT Points,

VARIANT Weight,

VARIANT Knots,

long Degree,

BOOL Closed );

Синтаксис COM:

HRESULT SetNurbsParams( VARIANT Points,

VARIANT Weight,

VARIANT Knots,

long Degree,

BOOL Closed,

BOOL * Result );

Входные параметры:

Points | \- массив SAFEARRAY | VT_R8 координат точек кривой,  
---|---  
Weight | \- массив SAFEARRAY | VT_R8 весов точек,  
Knots | \- массив SAFEARRAY | VT_R8 узлов сплайна,  
Degree | \- порядок кривой,  
Closed | \- признак замкнутости (нужно задавать после задания точек).  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет установить параметры NURBS-кривой в виде массивов SAFEARRAY | VT_R8.

Подразделы:

(отсутствуют)
