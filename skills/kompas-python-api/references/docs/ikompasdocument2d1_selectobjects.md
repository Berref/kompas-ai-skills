# SelectObjects - Отобрать объекты рамкой

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument2D1 ](ikompasdocument2d1.html) > [IKompasDocument2D1 - методы ](ikompasdocument2d1_methods.html) |  Scroll [ [ [ ](ikompasdocument2d1_symmetryobjects.html "К следующему разделу")](ikompasdocument2d1_methods.html "На уровень выше")](ikompasdocument2d1_runcreateobjectprocess.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument2d1.html)

Синтаксис Automation:

VARIANT SelectObjects( ksRegionTypeEnum RegionType, double XMin, double YMin, double XMax, double YMax );

Синтаксис COM :

HRESULT SelectObjects( ksRegionTypeEnum RegionType, double XMin, double YMin, double XMax, double YMax, VARIANT * Result );

Возвращаемое значение:

VARIANT | \- объект типа VARIANT на безопасный массив SAFEARRAY: VT_ARRAY|VT_DISPATCH.  
---|---  
  
Входные параметры:

RegionType | \- тип региона,  
---|---  
XMin | \- минимальная граница поиска по x  
YMin | \- минимальная граница поиска по y,  
XMax | \- максимальная граница поиска по x,  
YMax | \- максимальная граница поиска по y.  
  
Подразделы:

(отсутствуют)
