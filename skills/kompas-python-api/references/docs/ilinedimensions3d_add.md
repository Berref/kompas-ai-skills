# Add - Добавить линейный размер в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Оформление ](bc2273863.html) > [Размеры ](bc2274179.html) > [Интерфейс ILineDimensions3D ](ilinedimensions3d.html) > [ILineDimensions3D - методы ](ilinedimensions3d_methods.html) |  Scroll [ [ [ ](iradialdimensions3d.html "К следующему разделу")](ilinedimensions3d_methods.html "На уровень выше")](ilinedimensions3d_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilinedimensions3d.html)

Синтаксис Automation:

LPDISPATH Add( );

Синтаксис COM:

HRESULT Add( ksObj3dTypeEnum DimType, [out, retval] IBaseLineDimension3D** Result);

Входной параметр:

DimType | \- тип объекта из перечисления [ksObj3dTypeEnum](obj3dtype.html).  
---|---  
  
Возвращаемое значение:

| \- указатель на интерфейс линейного размера [IBaseLineDimension3D](ibaselinedimension3d.html).  
---|---  
  
Примечание:

Для создания линейного размера от отрезка до точки нужно задать значение параметра DimType, равное o3d_baselineDimension3D.

Для создания линейного размера на плоскости нужно задать значение параметра DimType, равное o3d_lineDimension3D.

Подразделы:

(отсутствуют)
