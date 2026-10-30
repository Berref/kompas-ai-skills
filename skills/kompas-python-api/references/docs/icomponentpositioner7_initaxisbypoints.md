# InitAxisByPoints - Установить ось по точкам

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IComponentPositioner7](icomponentpositioner7.html) > [IComponentPositioner7 - методы](icomponentpositioner7_methods.html) |  Scroll [ [ [ ](icomponentpositioner7_initplane.html "К следующему разделу")](icomponentpositioner7_methods.html "На уровень выше")](icomponentpositioner7_initaxis.html "К предыдущему разделу")  
---|---  
  
[Интерфейс](icomponentpositioner7.html)

Синтаксис Automation:

BOOL InitAxisByPoints( double X1, double Y1, double Z1, double X2, double Y2, double Z2 );

Синтаксис COM:

HRESULT InitAxisByPoints( double X1, double Y1, double Z1, double X2, double Y2, double Z2, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

X1, Y1, Z1 | \- координаты первой точки оси,  
---|---  
X2, Y2, Z2 | \- координаты второй точки оси.  
  
Подразделы:

(отсутствуют)
