# GetExternalLocalCooordinateSystem - Система координат из внешнего документа

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс ICopyGeometry ](icopygeometry.html) > [ICopyGeometry - методы ](icopygeometry_methods.html) |  Scroll [ [ [ ](icopygeometry_isinitialobject.html "К следующему разделу")](icopygeometry_methods.html "На уровень выше")](icopygeometry_destroy.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icopygeometry.html)

Синтаксис Automation:

LPDISPATCH GetExternalLocalCooordinateSystem( IKompasDocument3D * ExternalDocument3D );

Синтаксис COM:

HRESULT GetExternalLocalCooordinateSystem( IKompasDocument3D * ExternalDocument3D, ILocalCoordinateSystem * * Result );

Возвращаемое значение:

| \- Указатель на интерфейс [ILocalCoordinateSystem](ilocalcoordinatesystem.html).  
---|---  
  
Входные параметры:

ExternalDocument3D | \- указатель на интерфейс 3D документа, из которого выполнялось копирование, [IKompasDocument3D](ikompasdocument3d.html).  
---|---  
  
Версия КОМПАС v22

Подразделы:

(отсутствуют)
