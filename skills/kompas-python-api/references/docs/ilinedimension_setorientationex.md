# SetOrientationEx - Установить тип ориентации линейного размера с учетом системы координат

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Обозначения и размеры ](obozn_razm.html) > [Размеры ](bb2356896.html) > [Интерфейс ILineDimension ](ilinedimension.html) > [ILineDimension - методы](ilinedimension_methods.html) |  Scroll [ [ [ ](ilinesegmentandpointdimension.html "К следующему разделу")](ilinedimension_methods.html "На уровень выше")](ilinedimension_getorientationex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilinedimension.html)

Синтаксис Automation:

BOOL SetOrientationEx( ILocalCoordinateSystem2D * CoordinateSystem, ksLineDimensionOrientationEnum Value );

Синтаксис COM :

HRESULT SetOrientationEx( ILocalCoordinateSystem2D * CoordinateSystem, ksLineDimensionOrientationEnum Value, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

CoordinateSystem | \- система координат [ILocalCoordinateSystem2D](ilocalcoordinatesystem2d.html).  
---|---  
Value | \- тип ориентации линейного размера из перечисления [ksLineDimensionOrientationEnum](kslinedimensionorientationenum.html).  
  
Версия КОМПАС v22

Подразделы:

(отсутствуют)
