# SetGuidingObject - Установить направляющий объект

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Точки ](bc2284065.html) > [Интерфейс IPoint3DParamProjection ](ipoint3dparamprojection.html) > [IPoint3DParamProjection - методы ](ipoint3dparamprojection_methods.html) |  Scroll [ [ [ ](ipoint3dparamprojection_setsurfaceobject.html "К следующему разделу")](ipoint3dparamprojection_methods.html "На уровень выше")](ipoint3dparamprojection_setassociationvertex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipoint3dparamprojection.html)

Синтаксис Automation:

BOOL SetGuidingObject( LPDISPATCH obj );

Синтаксис COM:

HRESULT SetGuidingObject([in] IModelObject* obj, [out, retval] VARIANT_BOOL * Result );

Входные параметры:

obj | \- опорная точка.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
