# GetVector - Получить вектора направлений главных осей

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Точки ](bc2284065.html) > [Интерфейс IPoint3D ](ipoint3d.html) > [Наследники - вспомогательные объекты ](bc2284488.html) > [Интерфейс ILocalCoordinateSystem ](ilocalcoordinatesystem.html) > [ILocalCoordinateSystem - методы ](ilocalcoordinatesystem_methods.html) |  Scroll [ [ [ ](ilocalcoordinatesystem_initbymatrix3d.html "К следующему разделу")](ilocalcoordinatesystem_methods.html "На уровень выше")](ilocalcoordinatesystem_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilocalcoordinatesystem.html)

Синтаксис Automation:

BOOL GetVector( ksObj3dTypeEnum axis,

double * x,

double * y,

double * z );

Синтаксис COM:

HRESULT GetVector( [in] ksObj3dTypeEnum axis,

[out] double * x,

[out] double * y,

[out] double * z,

[out, retval] * Result );

Входные параметры:

axis | \- тип оси из перечисления [ksObj3dTypeEnum](obj3dtype.html); допустимые типы: \- o3d_axisOX, \- o3d_axisOY \- o3d_axisOZ.  
---|---  
  
Выходные параметры:

x | \- координата X вектора направления оси,  
---|---  
y | \- координата Y вектора направления оси,  
z | \- координата Z вектора направления оси.  
  
Возвращаемое значение:

TRUE | \- в случае успеха;  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
