# SelectObjects - Отобрать объекты рамкой

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Виды и слои ](view_layers.html) > [Интерфейс IView1 ](iview1.html) > [IView1 - методы ](iview1_methods.html) |  Scroll [ [ [ ](iview1_transformangletosheet.html "К следующему разделу")](iview1_methods.html "На уровень выше")](iview1_isviewpointinbreakview.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iview1.html)

Синтаксис Automation:

VARIANT SelectObjects( ksRegionTypeEnum RegionType, double XMin, double YMin, double XMax, double YMax );

Синтаксис COM:

HRESULT SelectObjects( ksRegionTypeEnum RegionType, double XMin, double YMin, double XMax, double YMax, VARIANT * Result );

Возвращаемое значение:

VARIANT | \- объект типа VARIANT на безопасный массив SAFEARRAY: VT_ARRAY|VT_DISPATCH.  
---|---  
  
RegionType | \- тип региона,  
---|---  
XMin | \- минимальная граница поиска по x,  
YMin | \- минимальная граница поиска по y,  
XMax | \- максимальная граница поиска по x,  
YMax | \- максимальная граница поиска по y.  
  
Подразделы:

(отсутствуют)
