# SetObjects - Задать объекты

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс IUserFolder ](iuserfolder.html) > [IUserFolder - методы ](iuserfolder_methods.html) |  Scroll [ [ [ ](iuserobject3d.html "К следующему разделу")](iuserfolder_methods.html "На уровень выше")](iuserfolder_getobjects.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iuserfolder.html)

Синтаксис Automation:

BOOL SetObjects( VARIANT Objects );

Синтаксис COM:

HRESULT SetObjects( VARIANT Objects, BOOL * Result );

Возвращаемое значение:

TRUE | \- в случае успешного завершения.  
---|---  
  
Входные параметры:

Objects | \- набор объектов.  
---|---  
  
Примечание:

•Если требуется передать один объект в наборе, его можно передать как VT_DISPATCH.

•Если требуется передать несколько объектов в наборе, то нужно передать их как массив VT_ARRAY | VT_DISPATCH.

Подразделы:

(отсутствуют)
