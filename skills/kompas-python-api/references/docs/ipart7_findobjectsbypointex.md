# FindObjectsByPointEx - Найти объекты по точке

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IPart7 ](ipart7.html) > [IPart7 - методы ](ipart7_methods.html) |  Scroll [ [ [ ](ipart7_findobjectsbypointwithparam.html "К следующему разделу")](ipart7_methods.html "На уровень выше")](ipart7_findobjectsbypoint.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipart7.html)

Синтаксис Automation:

VARIANT FindObjectsByPointEx( double X, double Y, double Z, BOOL FirstLevel, double Epsilon );

Синтаксис COM:

HRESULT FindObjectsByPointEx( double X, double Y, double Z, BOOL FirstLevel, double Epsilon, VARIANT * Result );

Входные параметры:

X,Y, Z | \- координаты точки,  
---|---  
FirstLevel | •TRUE - возвращать объекты только первого уровня, •FALSE - возвращать объекты из вставок,  
Epsilon | \- погрешность.  
  
Версия КОМПАС v22

Подразделы:

(отсутствуют)
