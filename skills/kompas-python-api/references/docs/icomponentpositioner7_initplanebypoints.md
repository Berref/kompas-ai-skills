# InitPlaneByPoints - Установить плоскость по точкам

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IComponentPositioner7](icomponentpositioner7.html) > [IComponentPositioner7 - методы](icomponentpositioner7_methods.html) |  Scroll [ [ [ ](icomponentpositioner7_movecomponent.html "К следующему разделу")](icomponentpositioner7_methods.html "На уровень выше")](icomponentpositioner7_initplanebyplacement.html "К предыдущему разделу")  
---|---  
  
[Интерфейс](icomponentpositioner7.html)

Синтаксис Automation:

BOOL InitPlaneByPoints( double X1, double Y1, double Z1, double X2, double Y2, double Z2, double X3, double Y3, double Z3 );

Синтаксис COM:

HRESULT InitPlaneByPoints( double X1, double Y1, double Z1, double X2, double Y2, double Z2, double X3, double Y3, double Z3, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

X1, Y1, Z1 | \- координаты первой точки на плоскости,  
---|---  
X2, Y2, Z2 | \- координаты второй точки на плоскости,  
X3, Y3, Z3 | \- координаты третьей точки на плоскости.  
  
.

Подразделы:

(отсутствуют)
