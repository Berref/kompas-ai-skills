# SetSurfaceObject - Установить поверхность

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Точки ](bc2284065.html) > [Интерфейс IPoint3DParamSurface ](ipoint3dparamsurface.html) > [IPoint3DParamSurface - методы ](ipoint3dparamsurface_methods.html) |  Scroll [ [ [ ](ipoint3dparambycylinder.html "К следующему разделу")](ipoint3dparamsurface_methods.html "На уровень выше")](ipoint3dparamsurface_setobject2.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipoint3dparamsurface.html)

Синтаксис Automation:

BOOL SetSurfaceObject( LPDISPATCH obj );

Синтаксис COM:

HRESULT SetSurfaceObject([in] IModelObject* obj, [out, retval] VARIANT_BOOL * Result );

Входные параметры:

obj | \- поверхность.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
