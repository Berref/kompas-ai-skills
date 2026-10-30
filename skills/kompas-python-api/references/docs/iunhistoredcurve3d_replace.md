# Replace - Изменить кривую

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс IUnhistoredCurve3D ](iunhistoredcurve3d.html) > [IUnhistoredCurve3D - методы ](iunhistoredcurve3d_methods.html) |  Scroll [ [ [ ](iunhistoredcurve3d_unwrap.html "К следующему разделу")](iunhistoredcurve3d_methods.html "На уровень выше")](iunhistoredcurve3d_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iunhistoredcurve3d.html)

Синтаксис Automation:

BOOL Replace( IModelObject * Curve, BOOL DeleteSource );

Синтаксис COM:

HRESULT Replace( IModelObject * Curve, BOOL DeleteSource, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Curve | \- указатель на кривую,  
---|---  
DeleteSource | \- удалить исходную кривую.  
  
Метод заменяет математику в кривой без истории на математику с переданной кривой.

Подразделы:

(отсутствуют)
