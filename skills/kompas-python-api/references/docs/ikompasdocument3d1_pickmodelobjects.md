# PickModelObjects - Собрать объекты по лучу

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument3D1 ](ikompasdocument3d1.html) > [IKompasDocument3D1 - методы ](ikompasdocument3d1_methods.html) |  Scroll [ [ [ ](ikompasdocument3d1_sethiddenobjects.html "К следующему разделу")](ikompasdocument3d1_methods.html "На уровень выше")](ikompasdocument3d1_findobjectbyassociationgeometry.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument3d1.html)

Синтаксис Automation:

VARIANT PickModelObjects( VARIANT PickRay, LPDISPATCH FilterParam );

Синтаксис COM:

HRESULT PickModelObjects( VARIANT PickRay, IFindObject3DParameters * FilterParam, VARIANT * Result );

Возвращаемое значение:

| \- Массив SafeAray VT_ARRAY | VT_DISPATCH найденных объектов.  
---|---  
  
Входные параметры:

PickRay | \- Параметры вектора взгляда, полученные из функции [IDocumentFrame::GetPickRay](idocumentframe_getpickray.html),  
---|---  
FilterParam | \- Интерфейс дополнительных параметров фильтрации [IFindObject3DParameters](ifindobject3dparameters.html).  
  
Примечание

Параметры фильтрации передавать в функцию не обязательно. Если параметры не заданы, то вернутся все найденные объекты, которые можно самостоятельно обработать.

Параметры фильтрации позволяют отфильтровывать объекты по типу объекта.

Также есть возможность подписаться на события [ksFindObject3DParametersNotify](ksfindobject3dparametersnotify.html), что позволяет делать дополнительные проверки подходящих объектов.

Версия: Компас v20

Подразделы:

(отсутствуют)
