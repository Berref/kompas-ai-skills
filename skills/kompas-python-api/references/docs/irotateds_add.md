# Add - Создает новую операцию вращения и добавляет ее в коллекцию

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Операции, массивы, эскизы, точки ](bc2278808.html) > [Операции ](bc2279073.html) > [Интерфейс IRotateds ](irotateds.html) > [IRotateds - методы ](irotateds_methods.html) |  Scroll [ [ [ ](iscalings3d.html "К следующему разделу")](irotateds_methods.html "На уровень выше")](irotateds_methods.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](irotateds.html)

Синтаксис Automation:

LPDISPATCH Add( ksObj3dTypeEnum RotatedType );

Синтаксис COM:

HRESULT Add( ksObj3dTypeEnum RotatedType, IRotated ** Result );

Возвращаемое значение:

Указатель на интерфейс операции вращения IRotatedIRotated.htm.

Входные параметры:

RotatedType - тип операции

Примечание:

Для создания операций вращения и вырезания вращением надо получать коллекцию у контейнера трехмерных объектов с помощью свойства [IModelContainer::Rotateds](imodelcontainer_rotateds.html), для создания поверхности вращения - у контейнера поверхностей с помощью свойства [ISurfaceContainer::RotatedSurfaces](isurfacecontainer_rotatedsurfaces.html).

Подразделы:

(отсутствуют)
