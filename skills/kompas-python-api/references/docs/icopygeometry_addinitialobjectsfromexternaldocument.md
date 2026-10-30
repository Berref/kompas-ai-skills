# AddInitialObjectsFromExternalDocument - Добавить объекты из файла в массив копируемых объектов

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс ICopyGeometry ](icopygeometry.html) > [ICopyGeometry - методы ](icopygeometry_methods.html) |  Scroll [ [ [ ](icopygeometry_clear.html "К следующему разделу")](icopygeometry_methods.html "На уровень выше")](icopygeometry_addinitialobjects.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icopygeometry.html)

Синтаксис Automation:

BOOL AddInitialObjectsFromExternalDocument( IKompasDocument3D * ExternalDocument, ILocalCoordinateSystem * ExternalLocalCS, VARIANT Objects );

Синтаксис COM:

HRESULT AddInitialObjectsFromExternalDocument( IKompasDocument3D * ExternalDocument, ILocalCoordinateSystem * ExternalLocalCS, VARIANT Objects, BOOL * Result );

Входные параметры:

ExternalDocument | \- указатель на внешний документ,  
---|---  
ExternalLocalCS | \- указатель на систему координат внешнего документа,  
Objects | \- массив SafeArray VT_ARRAY | VT_DISPATCH копируемых объектов.  
  
Подразделы:

(отсутствуют)
