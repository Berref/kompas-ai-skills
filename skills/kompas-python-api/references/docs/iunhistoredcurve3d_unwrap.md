# Unwrap - Построить развертку

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс IUnhistoredCurve3D ](iunhistoredcurve3d.html) > [IUnhistoredCurve3D - методы ](iunhistoredcurve3d_methods.html) |  Scroll [ [ [ ](iuserfolder.html "К следующему разделу")](iunhistoredcurve3d_methods.html "На уровень выше")](iunhistoredcurve3d_replace.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iunhistoredcurve3d.html)

Синтаксис Automation:

BOOL Unwrap( VARIANT Placement, double X, double Y, double Z, double Accuracy );

Синтаксис COM:

HRESULT Unwrap( VARIANT Placement, double X, double Y, double Z, double Accuracy, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае удачного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Placement | \- положение плоскости, на которой требуется построить развертку,  
---|---  
X, Y, Z | \- координаты начала построения развертки,  
Accuracy | \- точность.  
  
Подразделы:

(отсутствуют)
