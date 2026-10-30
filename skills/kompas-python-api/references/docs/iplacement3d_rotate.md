# Rotate - Повернуть систему координат на угол вокруг оси

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [Вспомогательные объекты ](bc1712124.html) > [Интерфейс IPlacement3D ](iplacement3d.html) > [IPlacement3D - методы ](iplacement3d_methods.html) |  Scroll [ [ [ ](iplacement3d_setorigin.html "К следующему разделу")](iplacement3d_methods.html "На уровень выше")](iplacement3d_initbymatrix3d.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iplacement3d.html)

Синтаксис Automation:

BOOL Rotate( double X0, double Y0, double Z0, double AxisZX, double AxisZXY, double AxisZZ, double Angle );

Синтаксис COM :

HRESULT Rotate( double X0, double Y0, double Z0, double AxisZX, double AxisZXY, double AxisZZ, double Angle, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае удачного завершения.  
---|---  
  
Входные параметры:

X0 | \- первая координата точки,  
---|---  
Y0 | \- вторая координата точки,  
Z0 | \- третья координата точки,  
AxisZX | \- вектор "X" стандартного базиса,  
AxisZXY | \- вектор "Y" стандартного базиса,  
AxisZZ | \- вектор "Z" стандартного базиса,  
Angle | \- угол поворота.  
  
Подразделы:

(отсутствуют)
