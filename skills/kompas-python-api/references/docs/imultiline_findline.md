# FindLine - Найти индекс линии по смещению

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс IMultiline ](imultiline.html) > [IMultiline - методы ](imultiline_methods.html) |  Scroll [ [ [ ](inurbs.html "К следующему разделу")](imultiline_methods.html "На уровень выше")](imultiline_deleteline.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imultiline.html)

Синтаксис Automation:

long FindLine( double Offset );

Синтаксис COM:

HRESULT FindLine( [in]double Offset,

[out, retval] long * Result );

Входные параметры:

Offset | \- смещение линии относительно базового контура.  
---|---  
  
Возвращаемое значение:

| \- индекс линии, имеющей указанное смещение.  
---|---  
  
Подразделы:

(отсутствуют)
