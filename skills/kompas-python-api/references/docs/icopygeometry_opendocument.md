# OpenDocument - Открывает документ-источник на редактирование

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс ICopyGeometry ](icopygeometry.html) > [ICopyGeometry - методы ](icopygeometry_methods.html) |  Scroll [ [ [ ](icopygeometry_synhronise.html "К следующему разделу")](icopygeometry_methods.html "На уровень выше")](icopygeometry_issuitableobject.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icopygeometry.html)

Синтаксис Automation:

LPDISPATCH OpenDocument( BOOL Visible, BOOL ReadOnly );

Синтаксис COM:

HRESULT OpenDocument( BOOL Visible, BOOL ReadOnly, IKompasDocument3D ** Result );

Возвращаемое значение:

| \- указатель на интерфейс док\источника [IKompasDocument3D](ikompasdocument3d.html).  
---|---  
  
Входные параметры:

Visible | \- открыть в видимом режиме,  
---|---  
ReadOnly | \- открыть только для чтения.  
  
Подразделы:

(отсутствуют)
