# GetNurbsParams - Получить параметры NURBS-кривой

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс INurbs ](inurbs.html) > [INurbs - методы ](inurbs_methods.html) |  Scroll [ [ [ ](inurbs_getpoint.html "К следующему разделу")](inurbs_methods.html "На уровень выше")](inurbs_deletepoint.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](inurbs.html)

Синтаксис Automation:

BOOL GetNurbsParams( VARIANT * Points,

VARIANT * Weight,

VARIANT * Knots );

Синтаксис COM:

HRESULT GetNurbsParams( VARIANT * Points,

VARIANT * Weight,

VARIANT * Knots,

BOOL * Result );

Выходные параметры:

Points | \- массив SAFEARRAY | VT_R8 координат точек кривой,  
---|---  
Weight | \- массив SAFEARRAY | VT_R8 весов точек,  
Knots | \- массив SAFEARRAY | VT_R8 узлов сплайна.  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет получить параметры NURBS-кривой в виде массивов SAFEARRAY | VT_R8.

Подразделы:

(отсутствуют)
