# SelectByPoint - Выделить объекты, содержащие точку

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IPart7 ](ipart7.html) > [IPart7 - методы ](ipart7_methods.html) |  Scroll [ [ [ ](ipart7_selectbypointex.html "К следующему разделу")](ipart7_methods.html "На уровень выше")](ipart7_saveas.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipart7.html)

Синтаксис Automation:

VARIANT SelectByPoint( VARIANT Objects,

double X,

double Y,

double Z );

Синтаксис COM:

HRESULT SelectByPoint( VARIANT Objects,

double X,

double Y,

double Z,

VARIANT * Result );

Входные параметры:

Objects | \- массив SafeArray объектов типа VT_ARRAY | VT_DISPATCH,  
---|---  
x, y, z | \- координаты точки.  
  
Возвращаемое значение:

Массив SafeArray объектов типа VT_ARRAY | VT_DISPATCH.  
---  
  
Примечание

Если возвращается один объект, то тип VARIANT-а будет VT_DISPATCH, если возвращается несколько объектов, то тип VARIANT-а будет VT_ARRAY | VT_DISPATCH.

Подразделы:

(отсутствуют)
