# AddInitialObjects - Добавить объекты в массив копируемых объектов

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс ICopyGeometry ](icopygeometry.html) > [ICopyGeometry - методы ](icopygeometry_methods.html) |  Scroll [ [ [ ](icopygeometry_addinitialobjectsfromexternaldocument.html "К следующему разделу")](icopygeometry_methods.html "На уровень выше")](icopygeometry_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](icopygeometry.html)

Синтаксис Automation:

BOOL AddInitialObjects( VARIANT Objects );

Синтаксис COM:

HRESULT AddInitialObjects( VARIANT Objects, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Objects | \- массив SafeArray VT_ARRAY | VT_DISPATCH копируемых объектов.  
---|---  
  
Подразделы:

(отсутствуют)
