# SetObject - Установить объект

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Точки ](bc2284065.html) > [Интерфейс IPoint3DParamCenter ](ipoint3dparamcenter.html) > [IPoint3DParamCenter - методы ](ipoint3dparamcenter_methods.html) |  Scroll [ [ [ ](ipoint3dparamcurve.html "К следующему разделу")](ipoint3dparamcenter_methods.html "На уровень выше")](ipoint3dparamcenter_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipoint3dparamcenter.html)

Синтаксис Automation:

LPDISPATCH obj );

Синтаксис COM:

HRESULT SetObject([in] IModelObject* obj, [out, retval] VARIANT_BOOL * Result );

Входные параметры:

obj | \- объект, имеющий центр.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Объект должен иметь центр.

Подразделы:

(отсутствуют)
