# GetObjects - Получить набор объектов в виде SAFEARRAY DISPATCH - VT_ARRAY | VT_DISPATCH

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Вспомогательные объекты, 3D-кривые и элементы тела ](bc1711351.html) > [3D-кривые и элементы тела ](bc2014000.html) > [Интерфейс IModelObjects ](imodelobjects.html) > [IModelObjects - свойства ](imodelobjects_props.html) > [Интерфейс IUserFolder ](iuserfolder.html) > [IUserFolder - методы ](iuserfolder_methods.html) |  Scroll [ [ [ ](iuserfolder_setobjects.html "К следующему разделу")](iuserfolder_methods.html "На уровень выше")](iuserfolder_add.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iuserfolder.html)

Синтаксис Automation:

VARIANT GetObjects();

Синтаксис COM:

HRESULT GetObjects( VARIANT * Result );

Возвращаемое значение:

Коллекция объектов возвращается в виде массива SAFEARRAY объектов LPDISPATCH (VT_ARRAY | VT_DISPATCH).

Если возвращается один объект, то тип VARIANT-а будет VT_DISPATCH, если возвращается несколько объектов, то тип VARIANT-а будет VT_ARRAY | VT_DISPATCH.

Подразделы:

(отсутствуют)
