# GetOrientationEx - Получить тип ориентации линейного размера с учетом системы координат

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Размеры ](bb2356896.html) > [Интерфейс ILineDimension ](ilinedimension.html) > [ILineDimension - методы](ilinedimension_methods.html) |  Scroll [ [ [ ](ilinedimension_setorientationex.html "К следующему разделу")](ilinedimension_methods.html "На уровень выше")](ilinedimension_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilinedimension.html)

Синтаксис Automation:

ksLineDimensionOrientationEnum GetOrientationEx( ILocalCoordinateSystem2D * CoordinateSystem );

Синтаксис COM :

HRESULT GetOrientationEx( ILocalCoordinateSystem2D * CoordinateSystem, ksLineDimensionOrientationEnum * Result );

Возвращаемое значение:

| \- Тип ориентации линейного размера из перечисления [ksLineDimensionOrientationEnum](kslinedimensionorientationenum.html).  
---|---  
  
Входные параметры:

CoordinateSystem | \- система координат [ILocalCoordinateSystem2D](ilocalcoordinatesystem2d.html).  
---|---  
  
Версия КОМПАС v22

Подразделы:

(отсутствуют)
