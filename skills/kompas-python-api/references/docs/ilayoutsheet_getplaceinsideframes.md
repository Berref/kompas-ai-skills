# GetPlaceInsideFrames - Выдать свободное место внутри рамок

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Листы и оформление ](bb2345331.html) > [Интерфейс ILayoutSheet ](ilayoutsheet.html) > [ILayoutSheet - методы ](ilayoutsheet_methods.html) |  Scroll [ [ [ ](ilayoutsheet_update.html "К следующему разделу")](ilayoutsheet_methods.html "На уровень выше")](ilayoutsheet_delete.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ilayoutsheet.html)

Синтаксис Automation:

BOOL GetPlaceInsideFrames( double* Left, double* Top, double* Right, double* Bottom);

Синтаксис COM:

HRESULT GetPlaceInsideFrames([out] double* Left, [out] double* Top, [out] double* Right, [out] double* Bottom, [out, retval] VARIANT_BOOL * Val);

Возвращаемое значение:

TRUE | \- в случае успеха,  
---|---  
FALSE | \- в случае неудачи.  
  
Выходные параметры:

Left, Top | \- координата верхней левой точки,  
---|---  
Right, Bottom | \- координата нижней правой точки.  
  
Подразделы:

(отсутствуют)
