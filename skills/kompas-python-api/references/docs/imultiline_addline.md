# AddLine - Добавить линию

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс IMultiline ](imultiline.html) > [IMultiline - методы ](imultiline_methods.html) |  Scroll [ [ [ ](imultiline_deleteline.html "К следующему разделу")](imultiline_methods.html "На уровень выше")](imultiline_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imultiline.html)

Синтаксис Automation:

BOOL AddLine( double Offset, long Style );

Синтаксис COM:

HRESULT AddLine( [in]double Offset,

[in]long Style,

[out, retval] VARIANT_BOOL * PVal );

Входные параметры:

Offset | \- смещение линии относительно базового контура,  
---|---  
Style | \- стиль линии из перечисления [ksCurveStyleEnum](kscurvestyleenum.html).  
  
Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
