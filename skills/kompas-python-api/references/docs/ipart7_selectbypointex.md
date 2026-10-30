# SelectByPointEx - Выделить объекты, содержащие точку

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IPart7 ](ipart7.html) > [IPart7 - методы ](ipart7_methods.html) |  Scroll [ [ [ ](ipart7_setdummyembodiment.html "К следующему разделу")](ipart7_methods.html "На уровень выше")](ipart7_selectbypoint.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipart7.html)

Синтаксис Automation:

VARIANT SelectByPointEx( VARIANT Objects, double X, double Y, double Z, double Epsilon );

Синтаксис COM:

HRESULT SelectByPointEx( VARIANT Objects, double X, double Y, double Z, double Epsilon, VARIANT * Result );

Входные параметры:

Objects | \- cписок объектов VT_ARRAY | VT_DISPATCH,  
---|---  
X,Y, Z | \- координаты точки,  
Epsilon | \- погрешность.  
  
Версия КОМПАС v22

Подразделы:

(отсутствуют)
