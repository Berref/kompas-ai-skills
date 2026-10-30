# AddObjects - Добавить объекты

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс IMultiSpline3D](imultispline3d.html) > [IMultiSpline3D - методы](imultispline3d_methods.html) |  Scroll [ [ [ ](imultispline3d_destroy.html "К следующему разделу")](imultispline3d_methods.html "На уровень выше")](imultispline3d_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](imultispline3d.html)

Синтаксис Automation:

BOOL AddObjects( VARIANT Objects, BOOL AddTangentObjects );

Синтаксис COM:

HRESULT AddObjects( VARIANT Objects, BOOL AddTangentObjects, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Входные параметры:

Objects | \- добавляемые объекты,  
---|---  
AddTangentObjects  | \- = TRUE - выбрать касательные объекты  
= FALSE - добавить объекты.  
  
Подразделы:

(отсутствуют)
