# GetIntersectParameters - Получить массивы точек пересечения кривой с секущими объектами

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс ITrimmedCurve ](itrimmedcurve.html) > [ITrimmedCurve - методы ](itrimmedcurve_methods.html) |  Scroll [ [ [ ](iunhistoredcurve3d.html "К следующему разделу")](itrimmedcurve_methods.html "На уровень выше")](itrimmedcurve_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](itrimmedcurve.html)

Синтаксис Automation:

BOOL GetIntersectParameters( VARIANT * CutPoints1, VARIANT * CutPoints2 );

Синтаксис COM:

HRESULT GetIntersectParameters( VARIANT * CutPoints1, VARIANT * CutPoints2, BOOL * Result );

Выходные параметры

CutPoints1 - Массив VT_ARRAY | VT_R8 параметров в точках пересечения с первым секущим объектом.

CutPoints2 - Массив VT_ARRAY | VT_R8 параметров в точках пересечения со вторым секущим объектом.

Подразделы:

(отсутствуют)
