# AddSegment - Добавить сегмент

[API интерфейсов. Версия 7](applicate.html) > [Документ 2D ](bb2325661.html) > [Геометрия ](bb2333035.html) > [Интерфейс IContour ](icontour.html) > [IContour - методы ](icontour_methods.html) |  Scroll [ [ [ ](icontour_clear.html "К следующему разделу")](icontour_methods.html "На уровень выше")](icontour_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icontour.html)

Синтаксис Automation:

LPDISPATCH Add( long type );

Синтаксис COM:

HRESULT Add( [in]ksContourSegmentEnum Type,

IMultiline ** Result);

Входные параметры:

type | \- тип сегмента.  
---|---  
  
Возвращаемое значение:

| \- указатель на интерфейс сегмента контура [IContourSegment](icontoursegment.html).  
---|---  
  
Примечание:

Метод позволяет добавить сегмент в контур.

Подразделы:

(отсутствуют)
