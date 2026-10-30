# GetAreaEx - Получить площадь грани

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Поверхности ](bc2288197.html) > [Интерфейс IMathSurface3D ](imathsurface3d.html) > [IMathSurface3D - методы ](imathsurface3d_methods.html) |  Scroll [ [ [ ](imathsurface3d_getboundaryuvnurbs.html "К следующему разделу")](imathsurface3d_methods.html "На уровень выше")](imathsurface3d_getarea.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imathsurface3d.html)

Синтаксис Automation:

double GetAreaEx( ksLengthUnitsEnum Unit, double AngleTolerance );

Синтаксис COM:

HRESULT GetAreaEx( ksLengthUnitsEnum Unit, double AngleTolerance, double * Result );

Входные параметры:

Unit | \- единицы измерения длины из перечисления [ksLengthUnitsEnum](kslengthunitsenum.html),  
---|---  
AngleTolerance | \- ограничение углового отклонения при аппроксимации оболочки треугольными пластинами.  
  
Версия Компас v21

Подразделы:

(отсутствуют)
