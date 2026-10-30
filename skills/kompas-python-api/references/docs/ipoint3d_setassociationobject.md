# SetAssociationObject - Установить опорный объект

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Точки ](bc2284065.html) > [Интерфейс IPoint3D ](ipoint3d.html) > [IPoint3D - методы ](ipoint3d_methods.html) |  Scroll [ [ [ ](bc2284488.html "К следующему разделу")](ipoint3d_methods.html "На уровень выше")](ipoint3d_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ipoint3d.html)

Синтаксис Automation:

BOOL SetAssociationObject( LPDISPATCH obj );

Синтаксис COM:

HRESULT SetAssociationObject([in] IModelObject* obj, [out, retval] VARIANT_BOOL * Result );

Входные параметры:

obj | \- указатель на опорный объект.  
---|---  
  
Возвращаемое значение:

TRUE | \- в случае успешного завершения,  
---|---  
FALSE | \- в случае неудачи.  
  
Примечание:

Метод позволяет установить опорный объект только для типа точки по координатам ([IPoint3D::ParameterType](ipoint3d_parametertype.html)).

Подразделы:

(отсутствуют)
