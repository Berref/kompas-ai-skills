# FindObjectsByPoint - Найти объекты по точке

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IPart7 ](ipart7.html) > [IPart7 - методы ](ipart7_methods.html) |  Scroll [ [ [ ](ipart7_findobjectsbypointex.html "К следующему разделу")](ipart7_methods.html "На уровень выше")](ipart7_findobject.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipart7.html)

Синтаксис Automation:

VARIANT FindObjectsByPoint( double X, double Y, double Z, BOOL FirstLevel );

Синтаксис COM:

HRESULT FindObjectsByPoint( double X, double Y, double Z, BOOL FirstLevel, VARIANT * Result );

Возвращаемое значение:

| \- массив объектов, содержащих заданную точку, в виде SAFEARRAY DISPATCH - VT_ARRAY | VT_DISPATCH.  
---|---  
  
Входные параметры:

X,Y, Z | \- координаты точки,  
---|---  
FirstLevel | \- искать только в текущей модели.  
  
Подразделы:

(отсутствуют)
