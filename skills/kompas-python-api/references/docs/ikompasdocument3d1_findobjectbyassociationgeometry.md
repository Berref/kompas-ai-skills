# FindObjectByAssociationGeometry - Получить 3D объект по геометрии ассоциативного вида

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument3D1 ](ikompasdocument3d1.html) > [IKompasDocument3D1 - методы ](ikompasdocument3d1_methods.html) |  Scroll [ [ [ ](ikompasdocument3d1_pickmodelobjects.html "К следующему разделу")](ikompasdocument3d1_methods.html "На уровень выше")](ikompasdocument3d1_findnearestobject.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument3d1.html)

Синтаксис Automation:

LPDISPATCH FindObjectByAssociationGeometry( LPDISPATCH Geometry );

Синтаксис COM:

HRESULT FindObjectByAssociationGeometry( IKompasAPIObject * Geometry, IKompasAPIObject * * Result );

Возвращаемое значение:

| \- Указатель на интерфейс [IKompasAPIObject](ikompasapiobject.html).  
---|---  
  
Входные параметры:

Geometry | \- Указатель на ассоциативный объект [IKompasAPIObject](ikompasapiobject.html),  
---|---  
  
Версия: Компас v20

Подразделы:

(отсутствуют)
