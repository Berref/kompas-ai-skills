# Convert - Создает кривую без истории по кривой

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс IUnhistoredCurves3D ](iunhistoredcurves3d.html) > [IUnhistoredCurves3D - методы ](iunhistoredcurves3d_methods.html) |  Scroll [ [ [ ](iunhistoredcurves3d_load.html "К следующему разделу")](iunhistoredcurves3d_methods.html "На уровень выше")](iunhistoredcurves3d_add.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iunhistoredcurves3d.html)

Синтаксис Automation:

LPDISPATCH Convert( IModelObject * Curve, BOOL DeleteSource );

Синтаксис COM:

HRESULT Convert( IModelObject * Curve, BOOL DeleteSource, IUnhistoredCurve3D ** Result );

Возвращаемое значение:

| указатель на интерфейс кривой без истории [IUnhistoredCurve3D](iunhistoredcurve3d.html)  
---|---  
  
Входные параметры:

Curve | \- указатель на исходную кривую,  
---|---  
DeleteSource | \- удалить исходную кривую.  
  
Подразделы:

(отсутствуют)
